#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Session;
class Hall;
class Ticket;
class Ticket_system;

struct Date {
  int year;
  int month;
  int day;

  Date(int y, int m, int d) : year(y), month(m), day(d) {}

  void Print() const {
    cout << day << "." << month << "." << year;
  }
};

struct Time {
  int hour;
  int minute;

  Time(int h, int m) : hour(h), minute(m) {}

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
  Hall(int num, int num_seat, const string& name)
      : num(num), num_seat(num_seat), name(name) {}

  void In_num(int num) { this->num = num; }
  void In_num_seat(int num_seat) { this->num_seat = num_seat; }
  void In_name(const string& name_) { name = name_; }

  void Out_num() const { cout << "Number of Hall: " << num << endl; }
  void Out_num_seat() const { cout << "Number of seats: " << num_seat << endl; }
  void Out_name() const { cout << "Name of Hall: " << name << endl; }

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
  Session(const string& film, shared_ptr<Time> time_start,
          shared_ptr<Date> date, shared_ptr<Hall> hall)
      : film(film), hall(hall), date(date), time_start(time_start) {}

  void In_film(const string& film_) { film = film_; }
  void In_hall(shared_ptr<Hall> hall_) { hall = hall_; }
  void In_time_start(shared_ptr<Time> time_start_) { time_start = time_start_; }
  void In_date(shared_ptr<Date> date_) { date = date_; }

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

  void In_place(int place) { this->place = place; }
  void In_session(shared_ptr<Session> session_) { session = session_; }
  void In_price(float price) { this->price = price; }
  void In_row(int row) { this->row = row; }

  void Out_place_and_row() const {
    cout << "Row and place of person: " << row << " " << place << endl;
  }

  void Out_session() const {
    if (session) session->Out_s();
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
    for (const auto& ticket_sh : reservation) ticket_sh->Out_t();
  }

  void Out_unique_ticket() const {
    for (const auto& ticket_un : particle) ticket_un->Out_t();
  }

  void Out_t_s() const {
    cout << "Ticket System Database" << endl;
    Out_shared_ticket();
    Out_unique_ticket();
    cout << endl;
  }

  size_t Shared_count() const { return reservation.size(); }
  size_t Unique_count() const { return particle.size(); }
};

// ---------- Read helpers ----------

int Read_int(const string& info) {
  int value;
  cout << info;
  cin >> value;
  return value;
}

float Read_float(const string& info) {
  float value;
  cout << info;
  cin >> value;
  return value;
}

string Read_string(const string& info) {
  cout << info;
  string s;
  cin >> s;
  return s;
}

// ---------- Show helpers ----------

void Show_all_halls(const vector<shared_ptr<Hall>>& halls) {
  for (size_t i = 0; i < halls.size(); ++i) {
    cout << "[" << i << "] ";
    halls[i]->Out_h();
  }
}

void Show_all_sessions(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "]\n";
    sessions[i]->Out_s();
  }
}

void Show_all_tickets(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";
    tickets[i]->Out_t();
  }
}

void Show_hall_names(const vector<shared_ptr<Hall>>& halls) {
  for (size_t i = 0; i < halls.size(); ++i) {
    cout << "[" << i << "] ";
    halls[i]->Out_name();
  }
}

void Show_session_films(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "] " << sessions[i]->Get_film() << endl;
  }
}

void Show_ticket_short(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->Get_row()
         << ", place " << tickets[i]->Get_place()
         << ", price " << tickets[i]->Get_price() << endl;
  }
}

void Show_ticket_short_no_price(const vector<shared_ptr<Ticket>>& tickets) {
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] Row " << tickets[i]->Get_row()
         << ", place " << tickets[i]->Get_place() << endl;
  }
}

// ---------- Change handlers ----------

void Change_hall_field(vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Hall number\n";
  cout << "2. Number of seats\n";
  cout << "3. Name\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1:
      halls[idx]->In_num(Read_int("New number: "));
      break;
    case 2:
      halls[idx]->In_num_seat(Read_int("New number of seats: "));
      break;
    case 3:
      halls[idx]->In_name(Read_string("New name: "));
      break;
    default:
      cout << "Invalid choice.\n";
  }
}

void Change_session_field(vector<shared_ptr<Session>>& sessions,
                          vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Film name\n";
  cout << "2. Hall\n";
  cout << "3. Date\n";
  cout << "4. Start time\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1:
      sessions[idx]->In_film(Read_string("New film name: "));
      break;
    case 2: {
      Show_hall_names(halls);
      int h = Read_int("Hall index: ");
      sessions[idx]->In_hall(halls[h]);
      break;
    }
    case 3: {
      int y = Read_int("Year: ");
      int m = Read_int("Month: ");
      int d = Read_int("Day: ");
      sessions[idx]->In_date(make_shared<Date>(y, m, d));
      break;
    }
    case 4: {
      int h = Read_int("Hours: ");
      int m = Read_int("Minutes: ");
      sessions[idx]->In_time_start(make_shared<Time>(h, m));
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}

void Change_ticket_field(vector<shared_ptr<Ticket>>& tickets,
                         vector<shared_ptr<Session>>& sessions, int idx) {
  cout << "What to change?\n";
  cout << "1. Row\n";
  cout << "2. Place\n";
  cout << "3. Price\n";
  cout << "4. Session\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1:
      tickets[idx]->In_row(Read_int("New row: "));
      break;
    case 2:
      tickets[idx]->In_place(Read_int("New place: "));
      break;
    case 3:
      tickets[idx]->In_price(Read_float("New price: "));
      break;
    case 4: {
      Show_session_films(sessions);
      int s = Read_int("Session index: ");
      tickets[idx]->In_session(sessions[s]);
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}

// ---------- Menus ----------

void Menu_hall(vector<shared_ptr<Hall>>& halls) {
  while (true) {
    cout << "\n=== HALL MENU ===\n";
    cout << "1. Show all halls\n";
    cout << "2. Change hall characteristics\n";
    cout << "0. Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      Show_all_halls(halls);
    } else if (choice == 2) {
      Show_all_halls(halls);
      int idx = Read_int("Enter hall index: ");
      Change_hall_field(halls, idx);
    }
  }
}

void Menu_session(vector<shared_ptr<Session>>& sessions,
                  vector<shared_ptr<Hall>>& halls) {
  while (true) {
    cout << "\n=== SESSION MENU ===\n";
    cout << "1. Show all sessions\n";
    cout << "2. Change session characteristics\n";
    cout << "0. Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      Show_all_sessions(sessions);
    } else if (choice == 2) {
      Show_session_films(sessions);
      int idx = Read_int("Enter session index: ");
      Change_session_field(sessions, halls, idx);
    }
  }
}

void Menu_ticket(vector<shared_ptr<Ticket>>& tickets,
                 vector<shared_ptr<Session>>& sessions) {
  while (true) {
    cout << "\n=== TICKET MENU ===\n";
    cout << "1. Show all tickets\n";
    cout << "2. Change ticket characteristics\n";
    cout << "0. Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      Show_all_tickets(tickets);
    } else if (choice == 2) {
      Show_ticket_short(tickets);
      int idx = Read_int("Enter ticket index: ");
      Change_ticket_field(tickets, sessions, idx);
    }
  }
}

void Menu_ticket_system(Ticket_system& system,
                        vector<shared_ptr<Ticket>>& tickets,
                        vector<shared_ptr<Session>>& sessions) {
  while (true) {
    cout << "\n=== TICKET_SYSTEM MENU ===\n";
    cout << "1. Show system contents\n";
    cout << "2. Add ticket (shared)\n";
    cout << "3. Add ticket (unique)\n";
    cout << "4. Show number of tickets\n";
    cout << "0. Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      system.Out_t_s();
    } else if (choice == 2) {
      Show_ticket_short_no_price(tickets);
      int idx = Read_int("Ticket index: ");
      system.In_shared_ticket(tickets[idx]);
    } else if (choice == 3) {
      int row = Read_int("Row: ");
      int place = Read_int("Place: ");
      float price = Read_float("Price: ");
      Show_session_films(sessions);
      int s = Read_int("Session index: ");
      auto t = make_unique<Ticket>(row, place, price, sessions[s]);
      system.In_unique_ticket(move(t));
    } else if (choice == 4) {
      cout << "Shared tickets: " << system.Shared_count() << endl;
      cout << "Unique tickets: " << system.Unique_count() << endl;
    }
  }
}

int main() {
  auto hall1 = make_shared<Hall>(1, 120, "Moon");
  auto hall2 = make_shared<Hall>(2, 240, "Spartac");
  auto hall3 = make_shared<Hall>(3, 200, "October");
  auto hall4 = make_shared<Hall>(4, 420, "Queen");
  auto hall5 = make_shared<Hall>(5, 90, "Moon");

  vector<shared_ptr<Hall>> halls = {hall1, hall2, hall3, hall4, hall5};

  auto date1 = make_shared<Date>(2026, 2, 12);
  auto date2 = make_shared<Date>(2025, 12, 12);
  auto time1 = make_shared<Time>(13, 30);
  auto time2 = make_shared<Time>(18, 20);

  auto session1 = make_shared<Session>("Breaking Bad", time1, date1, hall5);
  auto session2 = make_shared<Session>("Stranger Things", time2, date2, hall2);
  vector<shared_ptr<Session>> sessions = {session1, session2};

  auto ticket1 = make_shared<Ticket>(2, 7, 12.3f, session1);
  auto ticket2 = make_shared<Ticket>(3, 14, 10.3f, session2);
  vector<shared_ptr<Ticket>> tickets = {ticket1, ticket2};

  Ticket_system system;
  system.In_shared_ticket(ticket1);

  while (true) {
    cout << "\n===== MAIN MENU =====\n";
    cout << "1. Hall\n";
    cout << "2. Session\n";
    cout << "3. Ticket\n";
    cout << "4. Ticket_system\n";
    cout << "0. Exit\n";

    int choice = Read_int("Choice: ");

    if (choice == 1) {
      Menu_hall(halls);
    } else if (choice == 2) {
      Menu_session(sessions, halls);
    } else if (choice == 3) {
      Menu_ticket(tickets, sessions);
    } else if (choice == 4) {
      Menu_ticket_system(system, tickets, sessions);
    } else if (choice == 0) {
      return 0;
    } else {
      cout << "Invalid choice.\n";
    }
  }
}