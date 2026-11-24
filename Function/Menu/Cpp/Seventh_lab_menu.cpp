#include "Function/Menu/Header/Seventh_lab_menu.h"
#include "Class/File/Header/File_manager.h"
#include "Class/File/Header/File_validator.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Hall.h"
#include "Class/Header/Session.h"
#include "Class/Header/Standard_ticket.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"
#include "Function/Read/Header/Read.h"
#include <iostream>
#include "Exception/Header/All_exceptions.h"

using namespace std;

static void create_new_hall(Collection<shared_ptr<Hall>>& halls) {
    int num = read_int("Hall number: ");
    int seats = read_int("Number of seats: ");
    string name = read_string("Hall name: ");
    
    if (halls.find_if([num](const auto& h){ return h->get_num() == num; }) != -1) {
        throw Duplicate_Id_Exception("Hall with this number already exists");
    }
    halls.add(make_shared<Hall>(num, seats, name));
    cout << "[OK] Hall added.\n";
}

static void create_new_session(Collection<shared_ptr<Session>>& sessions, const Collection<shared_ptr<Hall>>& halls) {
    string film = read_string("Film name: ");
    int h = read_int("Hour: ");
    int m = read_int("Minute: ");
    int y = read_int("Year: ");
    int mo = read_int("Month: ");
    int d = read_int("Day: ");
    int hall_num = read_int("Hall number: ");

    int hall_idx = halls.find_if([hall_num](const auto& h){ return h->get_num() == hall_num; });
    if (hall_idx == -1) throw Relation_Exception("Hall not found");

    auto t = make_shared<Time>(h, m);
    auto dt = make_shared<Date>(y, mo, d);
    sessions.add(make_shared<Session>(film, t, dt, halls.at(hall_idx)));
    cout << "[OK] Session added.\n";
}

static void create_new_ticket(Ticket_system& system, const Collection<shared_ptr<Session>>& sessions) {
    int row = read_int("Row: ");
    int place = read_int("Place: ");
    float price = read_float("Price: ");
    
    for (size_t i = 0; i < sessions.size(); ++i) {
        cout << "[" << i << "] " << sessions.at(i)->get_film() << "\n";
    }
    int s = read_int("Session index: ");

    auto t = make_shared<Standard_ticket>(row, place, price, sessions.at(s));
    system.in_shared_ticket(t);
    cout << "[OK] Ticket added to system.\n";
}
static void print_current_system_state(const Collection<shared_ptr<Hall>>& halls, 
                                       const Collection<shared_ptr<Session>>& sessions, 
                                       const Ticket_system& system) {
    cout << "\nCURRENT SYSTEM STATE\n";
    
    cout << "--- HALLS (" << halls.size() << ") ---\n";
    for (const auto& h : halls) {
        cout << "Hall #" << h->get_num() << " | Name: " << h->get_name() 
             << " | Seats: " << h->get_num_seat() << "\n";
    }
    
    cout << "\n--- SESSIONS (" << sessions.size() << ") ---\n";
    for (const auto& s : sessions) {
        cout << "Film: " << s->get_film() << " | Date: " << s->get_date()->day << "." 
             << s->get_date()->month << "." << s->get_date()->year 
             << " | Time: " << s->get_time_start()->hour << ":" << s->get_time_start()->minute
             << " | Hall: " << s->get_hall()->get_name() 
             << " | Sold seats: " << s->sold_seats() << "/" << s->seats_limit() << "\n";
    }
    
    cout << "\n--- TICKETS IN SYSTEM (" << system.shared_count() << ") ---\n";
    const auto& tickets = system.get_reservation();
    for (const auto& t : tickets) {
        cout << "[" << t->type_name() << "] Row: " << t->get_row() 
             << ", Place: " << t->get_place() << ", Price: " << t->get_price() 
             << " | Session: " << t->get_session()->get_film() << "\n";
    }
    cout << "\n";
}

void menu_seventh_lab(Ticket_system& system,
                      Collection<shared_ptr<Hall>>& halls,
                      Collection<shared_ptr<Session>>& sessions) {
    while (true) {
        try {
            cout << "\n--- LAB 7: FILE I/O & SYSTEM STATE ---\n";
            cout << "1. Save system to file\n";
            cout << "2. Load system from file\n";
            cout << "3. Generate text report\n";
            cout << "4. Clear system (Remove all data)\n";
            cout << "5. Show current system state\n"; 
            cout << "6. Add new Hall (Manual)\n";
            cout << "7. Add new Session (Manual)\n";
            cout << "8. Add new Ticket (Manual)\n";
            cout << "0. Back to Main Menu\n";

            int choice = read_int("Choice: ");
            if (choice == 0) return;

            string filename;

            switch (choice) {
                case 1:
                    filename = read_string("Enter filename to save (e.g., data.txt): ");
                    File_Validator::validate_filename(filename);
                    File_Manager::save_system(filename, halls, sessions, system);
                    File_Manager::log_action("System saved to " + filename);
                    cout << "[OK] System saved successfully to " << filename << "\n";
                    break;

                case 2:
                    filename = read_string("Enter filename to load (e.g., data.txt): ");
                    File_Validator::validate_filename(filename);
                    File_Manager::load_system(filename, halls, sessions, system);
                    File_Manager::log_action("System loaded from " + filename);
                    cout << "[OK] System loaded successfully from " << filename << "\n";
                    break;

                case 3:
                    filename = read_string("Enter filename for report (e.g., report.txt): ");
                    File_Validator::validate_filename(filename);
                    File_Manager::generate_report(filename, halls, sessions, system);
                    File_Manager::log_action("Report generated to " + filename);
                    cout << "[OK] Report generated to " << filename << "\n";
                    break;

                case 4:
                    halls.clear();
                    sessions.clear();
                    system.clear_all();
                    File_Manager::log_action("System completely cleared in memory");
                    cout << "[OK] System cleared. All collections are now empty.\n";
                    break;

                case 5:
                    print_current_system_state(halls, sessions, system);
                    break;

                case 6:
                    create_new_hall(halls);
                    break;

                case 7:
                    create_new_session(sessions, halls);
                    break;

                case 8:
                    create_new_ticket(system, sessions);
                    break;

                default:
                    cout << "Invalid choice.\n";
            }
        }
       catch (const Cinema_Exception& e) {
            cout << "[ERROR] " << e.what() << "\n";
    }
}
                      }