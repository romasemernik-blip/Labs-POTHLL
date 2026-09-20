#include "Function/Menu/Header/Second_lab_menu.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Show/Header/Session_show.h"
#include "Function/Show/Header/Ticket_show.h"
#include <iostream>

using namespace std;

static void Lab_show_halls(const vector<shared_ptr<Hall>>& halls) {
  Show_all_halls(halls);
}

static void Lab_edit_hall(vector<shared_ptr<Hall>>& halls) {
  Show_all_halls(halls);
  int idx = Read_int("Hall index to edit: ");
  if (idx < 0 || idx >= (int)halls.size()) {
    cout << "Invalid index.\n";
    return;
  }
  cin >> *halls[idx];
  cout << "Updated:\n" << *halls[idx];
}

static void Lab_show_session(const vector<shared_ptr<Session>>& sessions) {
  Show_all_sessions(sessions);
  int idx = Read_int("Session index: ");
  if (idx < 0 || idx >= (int)sessions.size()) {
    cout << "Invalid index.\n";
    return;
  }
  cout << *sessions[idx];
}

static void Lab_show_ticket(const vector<shared_ptr<Ticket>>& tickets) {
  Show_all_tickets(tickets);
  int idx = Read_int("Ticket index: ");
  if (idx < 0 || idx >= (int)tickets.size()) {
    cout << "Invalid index.\n";
    return;
  }
  cout << *tickets[idx];
}

static void Lab_show_system(const Ticket_system& system) {
  cout << system;
}

static void Lab_compare_sessions(const vector<shared_ptr<Session>>& sessions) {
  if (sessions.size() < 2) {
    cout << "Need at least 2 sessions.\n";
    return;
  }
  Show_session_films(sessions);
  int a = Read_int("First session index: ");
  int b = Read_int("Second session index: ");
  if (a < 0 || b < 0 ||
      a >= (int)sessions.size() || b >= (int)sessions.size()) {
    cout << "Invalid index.\n";
    return;
  }

  const Session& sa = *sessions[a];
  const Session& sb = *sessions[b];

  cout << "Seats: A=" << sa.Seats_limit()
       << ", B=" << sb.Seats_limit() << "\n";

  if (sa == sb) cout << "Sessions have EQUAL seats.\n";
  if (sa <  sb) cout << "A has FEWER seats than B.\n";
  if (sa >  sb) cout << "A has MORE seats than B.\n";
}

static void Lab_show_bigger_halls(
    const vector<shared_ptr<Session>>& sessions,
    const vector<shared_ptr<Hall>>& halls) {
  Show_session_films(sessions);
  int idx = Read_int("Session index: ");
  if (idx < 0 || idx >= (int)sessions.size()) {
    cout << "Invalid index.\n";
    return;
  }
  Show_halls_bigger_than(*sessions[idx], halls);
}

static void Lab_add_shared(Ticket_system& system,
                           const vector<shared_ptr<Ticket>>& tickets) {
  Show_ticket_short_no_price(tickets);
  int idx = Read_int("Ticket index: ");
  if (idx < 0 || idx >= (int)tickets.size()) {
    cout << "Invalid index.\n";
    return;
  }
  system += tickets[idx];
}

static void Lab_add_unique(Ticket_system& system,
                           const vector<shared_ptr<Session>>& sessions) {
  int row   = Read_int("Row: ");
  int place = Read_int("Place: ");
  float pr  = Read_float("Price: ");
  Show_session_films(sessions);
  int s = Read_int("Session index: ");
  if (s < 0 || s >= (int)sessions.size()) {
    cout << "Invalid index.\n";
    return;
  }
  system += make_unique<Ticket>(row, place, pr, sessions[s]);
}

static void Lab_remove_by_value(Ticket_system& system,
                                const vector<shared_ptr<Ticket>>& tickets) {
  Show_ticket_short(tickets);
  int idx = Read_int("Ticket index to remove: ");
  if (idx < 0 || idx >= (int)tickets.size()) {
    cout << "Invalid index.\n";
    return;
  }
  system -= *tickets[idx];
}

static void Lab_remove_shared(Ticket_system& system,
                              const vector<shared_ptr<Ticket>>& tickets) {
  Show_ticket_short(tickets);
  int idx = Read_int("Ticket index to remove: ");
  if (idx < 0 || idx >= (int)tickets.size()) {
    cout << "Invalid index.\n";
    return;
  }
  system -= tickets[idx];
}

static void Print_second_lab_menu() {
  cout << "\nFOR SECOND LAB MENU\n";
  cout << "1.  cout << hall              (operator<< for Hall)\n";
  cout << "2.  cin  >> hall              (operator>> for Hall)\n";
  cout << "3.  cout << session           (operator<< for Session)\n";
  cout << "4.  cout << ticket            (operator<< for Ticket)\n";
  cout << "5.  cout << ticket_system     (operator<< for Ticket_system)\n";
  cout << "6.  Compare sessions by seats (operator<, >, ==)\n";
  cout << "7.  Show halls bigger than session (operator< with Hall)\n";
  cout << "8.  system += shared ticket   (operator+= shared)\n";
  cout << "9. system += unique ticket   (operator+= unique)\n";
  cout << "10. system -= ticket by value (operator-= by value)\n";
  cout << "11. system -= shared ticket   (operator-= shared)\n";
  cout << "0.  Back\n";
}

static void Handle_second_lab_choice(int choice,
                                     vector<shared_ptr<Hall>>& halls,
                                    const vector<shared_ptr<Session>>& sessions,
                                    const vector<shared_ptr<Ticket>>& tickets,
                                     Ticket_system& system) {
  switch (choice) {
    case 1:  Lab_show_halls(halls); break;
    case 2:  Lab_edit_hall(halls); break;
    case 3:  Lab_show_session(sessions); break;
    case 4:  Lab_show_ticket(tickets); break;
    case 5:  Lab_show_system(system); break;
    case 6:  Lab_compare_sessions(sessions); break;
    case 7:  Lab_show_bigger_halls(sessions, halls); break;
    case 8:  Lab_add_shared(system, tickets); break;
    case 9: Lab_add_unique(system, sessions); break;
    case 10: Lab_remove_by_value(system, tickets); break;
    case 11: Lab_remove_shared(system, tickets); break;
    default: cout << "Invalid choice.\n";
  }
}

void Menu_second_lab(vector<shared_ptr<Hall>>& halls,
                     const vector<shared_ptr<Session>>& sessions,
                     const vector<shared_ptr<Ticket>>& tickets,
                     Ticket_system& system) {
  while (true) {
    Print_second_lab_menu();
    int choice = Read_int("Choice: ");
    if (choice == 0) return;
    Handle_second_lab_choice(choice, halls, sessions, tickets, system);
  }
}