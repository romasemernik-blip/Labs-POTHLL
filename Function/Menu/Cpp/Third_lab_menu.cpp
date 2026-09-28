#include "Function/Menu/Header/Third_lab_menu.h"
#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Vip_ticket.h"
#include "Class/Header/Discount_ticket.h"
#include "Class/Header/Kids_ticket.h"
#include "Class/Header/Couple_ticket.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Show/Header/Session_show.h"
#include "Function/Show/Header/Ticket_show.h"
#include <iostream>

using namespace std;

static void t3_create_ticket(vector<shared_ptr<Ticket>>& tickets,
                             vector<shared_ptr<Session>>& sessions) {
  cout << "Ticket type:\n"
       << "1. Standard\n"
       << "2. VIP\n"
       << "3. Discount\n"
       << "4. Kids\n"
       << "5. Couple\n";
  int type = read_int("Choice: ");

  int row   = read_int("Row: ");
  int place = read_int("Place: ");
  float pr  = read_float("Base price: ");

  show_session_films(sessions);
  int s = read_int("Session index: ");
  if (s < 0 || s >= (int)sessions.size()) {
    cout << "Invalid session index.\n";
    return;
  }

  shared_ptr<Ticket> new_ticket;

  switch (type) {
    case 1:
      new_ticket = make_shared<Standard_ticket>(row, place, pr, sessions[s]);
      break;
    case 2:
      new_ticket = make_shared<Vip_ticket>(row, place, pr, sessions[s],
                                          true, true);
      break;
    case 3: {
      int disc = read_int("Discount percent (1..90): ");
      string holder = read_string("Holder name: ");
      new_ticket = make_shared<Discount_ticket>(row, place, pr, sessions[s],
                                               disc, holder);
      break;
    }
    case 4: {
      string child = read_string("Child name: ");
      int age = read_int("Child age (0..12): ");
      new_ticket = make_shared<Kids_ticket>(row, place, pr, sessions[s],
                                           child, age);
      break;
    }
    case 5: {
      string p1 = read_string("Person 1: ");
      string p2 = read_string("Person 2: ");
      int second = read_int("Second place: ");
      new_ticket = make_shared<Couple_ticket>(row, place, pr, sessions[s],
                                             p1, p2, second);
      break;
    }
    default:
      cout << "Invalid type.\n";
      return;
  }

  if (is_duplicate_ticket(tickets, *new_ticket)) {
    cout << "Error: a ticket for this seat and session already exists.\n";
    return;
  }

  tickets.push_back(new_ticket);
  cout << "Ticket created.\n";
}

static void t3_show_all_tickets(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n" << *tickets[i];
    cout << "-----------------\n";
  }
}

static void t3_show_final_prices(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }
  cout << "Base vs Final price (polymorphism via virtual Final_price):\n";
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] base = " << tickets[i]->get_price()
         << "$, final = " << tickets[i]->final_price() << "$\n";
  }
}

static void t3_check_duplicate(const vector<shared_ptr<Ticket>>& tickets,
                               const vector<shared_ptr<Session>>& sessions) {
  if (sessions.empty()) { cout << "No sessions.\n"; return; }
  int row   = read_int("Row: ");
  int place = read_int("Place: ");
  show_session_films(sessions);
  int s = read_int("Session index: ");
  if (s < 0 || s >= (int)sessions.size()) {
    cout << "Invalid session index.\n";
    return;
  }

  Standard_ticket probe(row, place, 1.0f, sessions[s]);
  if (is_duplicate_ticket(tickets, probe)) {
    cout << "Duplicate: seat already taken for this session.\n";
  } else {
    cout << "Free: you can create a ticket for this seat.\n";
  }
}

static void t3_show_specific(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";

    if (auto st = dynamic_pointer_cast<Standard_ticket>(tickets[i])) {
      cout << "  Standard, zone = " << st->get_zone() << "\n";
    }
    else if (auto vt = dynamic_pointer_cast<Vip_ticket>(tickets[i])) {
      cout << "  VIP, lounge = " << (vt->has_lounge() ? "yes" : "no")
           << ", drinks = "  << (vt->has_drinks()  ? "yes" : "no") << "\n";
    }
    else if (auto dt = dynamic_pointer_cast<Discount_ticket>(tickets[i])) {
      cout << "  Discount " << dt->get_discount()
           << "%, holder = " << dt->get_holder() << "\n";
    }
    else if (auto kt = dynamic_pointer_cast<Kids_ticket>(tickets[i])) {
      cout << "  Kids: " << kt->get_child_name()
           << ", age = " << kt->get_child_age() << "\n";
    }
    else if (auto ct = dynamic_pointer_cast<Couple_ticket>(tickets[i])) {
      cout << "  Couple: " << ct->get_person1() << " + " << ct->get_person2()
           << ", 2nd place = " << ct->get_second_place() << "\n";
    }
  }
}

static void t3_add_to_system(Ticket_system& system,
                             const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }
  show_ticket_short_no_price(tickets);
  int idx = read_int("Ticket index: ");
  if (idx < 0 || idx >= (int)tickets.size()) {
    cout << "Invalid index.\n";
    return;
  }
  system += tickets[idx];
}

static void t3_print_menu() {
  cout << "\n FOR THIRD / FOURTH LAB MENU \n";
  cout << "1.  Create ticket (Standard / VIP / Discount / Kids / Couple)\n";
  cout << "2.  Show all tickets (polymorphic operator<<)\n";
  cout << "3.  Show base vs final prices (virtual Final_price)\n";
  cout << "4.  Check if seat is free (operator== duplicate check)\n";
  cout << "5.  Sell ticket via system += (with duplicate check)\n";
  cout << "6.  Show specific fields via getters (dynamic_cast)\n";
  cout << "0.  Back\n";
}

static void handle_third_lab_choice(int choice,
                                    vector<shared_ptr<Hall>>& halls,
                                    vector<shared_ptr<Session>>& sessions,
                                    vector<shared_ptr<Ticket>>& tickets,
                                    Ticket_system& system) {
  switch (choice) {
    case 1: t3_create_ticket(tickets, sessions); break;
    case 2: t3_show_all_tickets(tickets); break;
    case 3: t3_show_final_prices(tickets); break;
    case 4: t3_check_duplicate(tickets, sessions); break;
    case 5: t3_add_to_system(system, tickets); break;
    case 6: t3_show_specific(tickets); break;
    default: cout << "Invalid choice.\n";
  }
}

void menu_third_lab(vector<shared_ptr<Hall>>& halls,
                    vector<shared_ptr<Session>>& sessions,
                    vector<shared_ptr<Ticket>>& tickets,
                    Ticket_system& system) {
  while (true) {
    t3_print_menu();
    int choice = read_int("Choice: ");
    if (choice == 0) return;
    handle_third_lab_choice(choice, halls, sessions, tickets, system);
  }
}