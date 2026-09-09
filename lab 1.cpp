#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class Session;
class Hall;
class Ticket;
class Ticket_system;

struct Date {
    int year;
    int month;
    int day;
    Date (int y, int m, int d) : year(y), month(m), day(d) {}
    void Print() const {
        cout << day << "." << month << "." << year;
    }
};

struct Time {
    int hour;
    int minute;
    Time (int h, int m): hour(h), minute(m) {}
    void Print() const {
        cout << hour << ":";
        if (minute < 10) cout << "0";
        cout << minute;
    }
};

class Hall {
private:
    int num;
    int num_seat;
    string name;
public:
    Hall(int num, int num_seat, const string& name) : num(num), num_seat(num_seat), name(name) {}
    
    void In_num(int num) {
        this->num = num;
    }
    void In_num_seat(int num_seat) {
        this->num_seat = num_seat;
    }
    void In_name(const string_view& name_) {
        name = name_;
    }
    
    void Out_num() const {
        cout << "Number of Hall: " << num << endl;
    }   
    void Out_num_seat() const {
        cout << "Number of seats: " << num_seat << endl;
    }   
    void Out_name() const {
        cout << "Name of Hall: " << name << endl;
    }
    void Out_h() const {
        cout << "Hall:" << endl;
        Out_num();
        Out_num_seat();
        Out_name();
        cout << endl;
    }
    
    int Get_num() const { return num; }
    int Get_num_seat() const { return num_seat; }
    string Get_name() const { return name; }    
};

class Session {
private:
    string film;
    shared_ptr<Hall> hall;
    shared_ptr<Date> date;
    shared_ptr<Time> time_start;
public:
    Session(const string& film, shared_ptr<Time> time_start, shared_ptr<Date> date, shared_ptr<Hall> hall) 
        : film(film), hall(hall), date(date), time_start(time_start) {}
    
    void In_film(const string_view& film_) {
        film = film_;
    }
    void In_hall(shared_ptr<Hall> hall_) {
        hall = hall_;
    }
    void In_time_start(shared_ptr<Time> time_start_) {
        time_start = time_start_;
    }
    void In_date(shared_ptr<Date> date_) {
        date = date_;
    } 
    
    void Out_s() const {
        cout << "Session info" << endl;
        Out_film();
        Out_hall();
        Out_date();
        Out_time();
        cout << endl;
    }  
    
    void Out_date() const {
        if (date) {
            cout << "Date:";
            date->Print();
            cout << endl;
        }
    }
    void Out_time() const {
        if (time_start) {
            cout << "Time:";
            time_start->Print();
            cout << endl;
        }
    }
    void Out_film() const {
        cout << "Name of session film: " << film << endl;
    }
    void Out_hall() const {
        if (hall) {
            hall->Out_name();
            hall->Out_num(); 
        }
    }
    
    string Get_film() const { return film; }
    shared_ptr<Hall> Get_hall() const { return hall; }
    shared_ptr<Date> Get_date() const { return date; }
    shared_ptr<Time> Get_time_start() const { return time_start; }   
};

class Ticket {
private:
    int place;
    shared_ptr<Session> session;
    float price;
    int row;
public:
    Ticket(int row, int place, float price, shared_ptr<Session> session) 
        : place(place), session(session), price(price), row(row) {}
    
    void Out_t() const {
        cout << "Ticket:" << endl;
        Out_place_and_row();
        Out_session();
        Out_price();
        cout << endl;
    }
    
    void In_place(int place) {
        this->place = place;
    }
    void In_session(shared_ptr<Session> session_) {
        session = session_;
    }
    void In_price(float price) {
        this->price = price;
    }
    void In_row(int row) {
        this->row = row;
    }
    
    void Out_place_and_row() const {
        cout << "Row and place of person: " << row << " " << place << endl;
    }
    void Out_session() const {
        if (session) {
            session->Out_s();
        }
    }
    void Out_price() const {
        cout << "Price of ticket: " << price << "$" << endl;
    }
    
    int Get_row() const { return row; }
    int Get_place() const { return place; }
    float Get_price() const { return price; }
    shared_ptr<Session> Get_session() const { return session; }
};

class Ticket_system {
private: 
    vector<shared_ptr<Ticket>> reservation;
    vector<unique_ptr<Ticket>> particle;
public: 
    void In_shared_ticket(const shared_ptr<Ticket>& ticket_sh) {
        reservation.push_back(ticket_sh);
    }
    
    void In_unique_ticket(unique_ptr<Ticket> ticket_un) {
        particle.push_back(move(ticket_un));
    }
    
    void Out_shared_ticket() const {
        for (const auto& ticket_sh : reservation) {
            ticket_sh->Out_t();
        }
    }
    
    void Out_unique_ticket() const {
        for (const auto& ticket_un : particle) {
            ticket_un->Out_t();
        }
    }
    
    void Out_t_s() const {
        cout << "Ticket System Database" << endl;
        Out_shared_ticket();
        Out_unique_ticket();
        cout << endl;
    }
};

int main() {
    auto hall1 = make_shared<Hall>(1, 120, "Moon");
    auto hall2 = make_shared<Hall>(2, 240, "Spartac");
    auto hall3 = make_shared<Hall>(3, 200, "October");
    auto hall4 = make_shared<Hall>(4, 420, "Queen");
    auto hall5 = make_shared<Hall>(5, 90, "Moon");
    
    hall1->Out_h();
    hall2->Out_h();
    hall3->Out_h();
    hall4->Out_h();
    hall5->Out_h();
    
    auto date1 = make_shared<Date>(2026, 2, 12);
    auto date2 = make_shared<Date>(2025, 12, 12);
    auto time1 = make_shared<Time>(13, 30);
    auto time2 = make_shared<Time>(18, 20);
    
    auto session1 = make_shared<Session>("Breaking Bad", time1, date1, hall5);
    auto session2 = make_shared<Session>("Stranger Things", time2, date2, hall2);
    
    session1->Out_s();
    session2->Out_s();
    session1->In_hall(hall3);
    session1->Out_s();
    
    auto ticket1 = make_shared<Ticket>(2, 7, 12.3f, session1);
    auto ticket2 = make_unique<Ticket>(3, 14, 10.3f, session2);
    
    ticket1->Out_t();
    ticket2->Out_t();
    
    Ticket_system system;
    system.In_shared_ticket(ticket1);
    system.In_unique_ticket(move(ticket2));
    system.Out_shared_ticket();
    system.Out_unique_ticket();
    system.Out_t_s();
    
    return 0;
}