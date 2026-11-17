#include "Class/File/Header/File_manager.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Hall.h"
#include "Class/Header/Session.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Vip_ticket.h"
#include "Class/Header/Discount_ticket.h"
#include "Class/Header/Kids_ticket.h"
#include "Class/Header/Couple_ticket.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"
#include "Exception/Header/All_exceptions.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;

static void save_halls(ofstream& out, const Collection<shared_ptr<Hall>>& halls) {
    for (const auto& h : halls) {
        out << "HALL " << h->get_num() << " " << h->get_num_seat() 
            << " " << quoted(h->get_name()) << "\n";
    }
}

static void save_sessions(ofstream& out, const Collection<shared_ptr<Session>>& sessions) {
    for (const auto& s : sessions) {
        out << "SESSION " << quoted(s->get_film()) << " "
            << s->get_time_start()->hour << " " << s->get_time_start()->minute << " "
            << s->get_date()->year << " " << s->get_date()->month << " " << s->get_date()->day << " "
            << s->get_hall()->get_num() << "\n";
    }
}

static void save_single_ticket(ofstream& out, const shared_ptr<Ticket>& t) {
    string type = t->type_name();
    auto sess = t->get_session();
    
    out << "TICKET_S " << type << " " << t->get_row() << " " << t->get_place() 
        << " " << t->get_price() << " "
        << quoted(sess->get_film()) << " "
        << sess->get_date()->year << " " << sess->get_date()->month << " " << sess->get_date()->day << " "
        << sess->get_time_start()->hour << " " << sess->get_time_start()->minute << " "
        << sess->get_hall()->get_num() << " ";

    if (auto st = dynamic_pointer_cast<Standard_ticket>(t)) {
        out << "ZONE " << quoted(st->get_zone()) << "\n";
    } else if (auto vt = dynamic_pointer_cast<Vip_ticket>(t)) {
        out << "LOUNGE " << vt->has_lounge() << " DRINKS " << vt->has_drinks() << "\n";
    } else if (auto dt = dynamic_pointer_cast<Discount_ticket>(t)) {
        out << "DISC " << dt->get_discount() << " HOLDER " << quoted(dt->get_holder()) << "\n";
    } else if (auto kt = dynamic_pointer_cast<Kids_ticket>(t)) {
        out << "CHILD " << quoted(kt->get_child_name()) << " AGE " << kt->get_child_age() << "\n";
    } else if (auto ct = dynamic_pointer_cast<Couple_ticket>(t)) {
        out << "P1 " << quoted(ct->get_person1()) << " P2 " << quoted(ct->get_person2()) 
            << " SECOND " << ct->get_second_place() << "\n";
    }
}

static void save_tickets(ofstream& out, const Ticket_system& system) {
    for (const auto& t : system.get_reservation()) {
        save_single_ticket(out, t);
    }
}

static void load_halls(ifstream& in, Collection<shared_ptr<Hall>>& halls) {
    int num, seats; string name;
    in >> num >> seats >> quoted(name);
    if (in.fail()) throw Invalid_Data_Exception("Corrupted HALL data");

    if (halls.find_if([num](const auto& h){ return h->get_num() == num; }) != -1) {
        throw Duplicate_Id_Exception("Duplicate Hall number: " + to_string(num));
    }
    halls.add(make_shared<Hall>(num, seats, name));
}

static void load_sessions(ifstream& in, Collection<shared_ptr<Session>>& sessions, const Collection<shared_ptr<Hall>>& halls) {
    string film; int h, m, y, mo, d, hall_num;
    in >> quoted(film) >> h >> m >> y >> mo >> d >> hall_num;
    if (in.fail()) throw Invalid_Data_Exception("Corrupted SESSION data");

    int hall_idx = halls.find_if([hall_num](const auto& h){ return h->get_num() == hall_num; });
    if (hall_idx == -1) throw Relation_Exception("Hall not found for session: " + film);

    auto t = make_shared<Time>(h, m);
    auto dt = make_shared<Date>(y, mo, d);
    sessions.add(make_shared<Session>(film, t, dt, halls.at(hall_idx)));
}

static shared_ptr<Ticket> create_ticket_from_file(ifstream& in, const string& type, 
                                                  int row, int place, float price, 
                                                  shared_ptr<Session> session) {
    string tag;
    shared_ptr<Ticket> t;

    if (type == "Standard") {
        string zone; in >> tag >> quoted(zone);
        t = make_shared<Standard_ticket>(row, place, price, session, zone);
    } else if (type == "VIP") {
        bool lounge, drinks; in >> tag >> lounge >> tag >> drinks;
        t = make_shared<Vip_ticket>(row, place, price, session, lounge, drinks);
    } else if (type == "Discount") {
        int disc; string holder; in >> tag >> disc >> tag >> quoted(holder);
        t = make_shared<Discount_ticket>(row, place, price, session, disc, holder);
    } else if (type == "Kids") {
        string child; int age; in >> tag >> quoted(child) >> tag >> age;
        t = make_shared<Kids_ticket>(row, place, price, session, child, age);
    } else if (type == "Couple") {
        string p1, p2; int second; in >> tag >> quoted(p1) >> tag >> quoted(p2) >> tag >> second;
        t = make_shared<Couple_ticket>(row, place, price, session, p1, p2, second);
    }

    return t;
}

static void load_tickets(ifstream& in, Ticket_system& system, const Collection<shared_ptr<Session>>& sessions) {
    string type; int row, place; float price;
    string film; int y, mo, d, h, m, hall_num;
    in >> type >> row >> place >> price >> quoted(film) >> y >> mo >> d >> h >> m >> hall_num;
    if (in.fail()) throw Invalid_Data_Exception("Corrupted TICKET data");

    int sess_idx = sessions.find_if([&](const auto& s){
        return s->get_film() == film && s->get_date()->year == y && 
               s->get_date()->month == mo && s->get_date()->day == d &&
               s->get_time_start()->hour == h && s->get_time_start()->minute == m &&
               s->get_hall()->get_num() == hall_num;
    });
    if (sess_idx == -1) throw Relation_Exception("Session not found for ticket");

    auto t = create_ticket_from_file(in, type, row, place, price, sessions.at(sess_idx));
    if (t) system.in_shared_ticket(t); 
}

void File_Manager::save_system(const string& filename,
                               const Collection<shared_ptr<Hall>>& halls,
                               const Collection<shared_ptr<Session>>& sessions,
                               const Ticket_system& system) {
    ofstream out(filename);
    if (!out.is_open()) {
        throw Invalid_Data_Exception("Cannot open file for writing: " + filename);
    }

    try {
        save_halls(out, halls);
        save_sessions(out, sessions);
        save_tickets(out, system);
    }
    catch (const exception& e) {
        throw Invalid_Data_Exception(string("Write error: ") + e.what());
    }
}

void File_Manager::load_system(const string& filename,
                               Collection<shared_ptr<Hall>>& halls,
                               Collection<shared_ptr<Session>>& sessions,
                               Ticket_system& system) {
    ifstream in(filename);
    if (!in.is_open()) {
        throw Invalid_Data_Exception("Cannot open file for reading: " + filename);
    }

    halls.clear();
    sessions.clear();
    system.clear_all();

    string tag;
    while (in >> tag) {
        try {
            if (tag == "HALL") {
                load_halls(in, halls);
            } else if (tag == "SESSION") {
                load_sessions(in, sessions, halls);
            } else if (tag == "TICKET_S") {
                load_tickets(in, system, sessions);
            }
        }
        catch (const Cinema_Exception& e) {
            throw Invalid_Data_Exception(string("Error loading data: ") + e.what());
        }
    }
}

void File_Manager::log_action(const string& message) {
    ofstream log("system_log.txt", ios::app);
    if (!log.is_open()) return;

    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    
    log << "[" << buffer << "] " << message << "\n";
}

void File_Manager::generate_report(const string& filename,
                                   const Collection<shared_ptr<Hall>>& halls,
                                   const Collection<shared_ptr<Session>>& sessions,
                                   const Ticket_system& system) {
    ofstream out(filename);
    if (!out.is_open()) throw Invalid_Data_Exception("Cannot open file for report");

    out << "SYSTEM REPORT\n\n";
    out << "HALLS\n";
    for (const auto& h : halls) out << h->get_num() << " | " << h->get_name() << " | Seats: " << h->get_num_seat() << "\n";
    
    out << "\nSESSIONS\n";
    for (const auto& s : sessions) {
        out << s->get_film() << " | Hall: " << s->get_hall()->get_name() << " | Sold: " << s->sold_seats() << "\n";
    }
    
    out << "\nTICKETS\n";
    for (const auto& t : system.get_reservation()) {
        out << t->type_name() << " | Row: " << t->get_row() << " | Place: " << t->get_place() << "\n";
    }
    out << "\n";
}