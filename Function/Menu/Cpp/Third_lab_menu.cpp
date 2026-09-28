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
#include<Define_const.h>
#include <iostream>
#include <algorithm>

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
  if (tickets.empty()) {
    cout << "No tickets.\n";
    return;
  }
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";
    tickets[i]->print_ticket(cout);          
    cout << "-----------------\n";
  }
}

static void t4_show_biggest_discount(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  auto discount_of = [](const shared_ptr<Ticket>& t) {
    float base  = t->get_price();
    float final_price_val = t->final_price();
    if (base <= 0.0f) return 0.0f;
    return (1.0f - final_price_val / base) * 100.0f;
  };

  auto it = std::max_element(
      tickets.begin(), tickets.end(),
      [&](const shared_ptr<Ticket>& a, const shared_ptr<Ticket>& b) {
        return discount_of(a) < discount_of(b);
      });

  size_t idx = std::distance(tickets.begin(), it);
  const auto& best = **it;

  cout << "Ticket with the biggest discount:\n";
  cout << "Index : " << idx << "\n";
  cout << "Type  : " << best.type_name() << "\n";
  cout << "Info  : " << best.discount_info() << "\n";
  cout << "Base  : " << best.get_price()  << "$\n";
  cout << "Final : " << best.final_price() << "$\n";
  cout << "Effective discount: " << discount_of(*it) << "%\n";
  cout << "-----------------\n";
  best.print_ticket(cout);      
}

static void t4_add_5_percent_discount(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  const float factor = 1.0f - EXTRA_DISCOUNT / 100.0f;   

  cout << "Mass action: apply extra " << EXTRA_DISCOUNT << "% discount to all tickets\n";
  cout << "New base = old base * " << factor << "\n\n";

  int changed = 0;
  for (const auto& t : tickets) {
    float old_base  = t->get_price();
    float old_final = t->final_price();

    if (!t->in_price(old_base * factor)) {
      cout << "  skip " << t->type_name() << " (invalid price)\n";
      continue;
    }

    float new_final = t->final_price();

    cout << "[" << changed << "] " << t->type_name()
         << "  base " << old_base  << " -> " << t->get_price()
         << "  final " << old_final << " -> " << new_final << "$\n";
    ++changed;
  }
  cout << "Updated " << changed << " / " << tickets.size() << " tickets.\n";
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

static void t4_demo_polymorphism(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  cout << "=== Dynamic polymorphism demo ===\n";
  cout << "Calling Print(), Final_price(), Type_name() through\n"
          "pointer to abstract base class Ticket*.\n\n";

  for (size_t i = 0; i < tickets.size(); ++i) {
    const Ticket* base = tickets[i].get();    // указатель на абстрактный класс

    cout << "[" << i << "] Type_name() -> " << base->type_name() << "\n";
    cout << "    Final_price() -> " << base->final_price() << "$\n";
    cout << "    Print() ->\n";
    base->print_ticket(cout);
    cout << "-----------------\n";
  }

  cout << "Note: the same call base->Final_price() returned different\n"
          "values because the actual object type is different.\n";
}
static void t3_show_derived_fields(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "]\n";
    tickets[i]->print_ticket(cout);
    cout << "-----------------\n";
  }
}

static void t3_show_types(const vector<shared_ptr<Ticket>>& tickets) {
  if (tickets.empty()) { cout << "No tickets.\n"; return; }

  cout << "Polymorphic call of virtual (non-pure) methods:\n";
  for (size_t i = 0; i < tickets.size(); ++i) {
    cout << "[" << i << "] type = " << tickets[i]->type_name()
         << " | " << tickets[i]->discount_info() << "\n";
  }
}

static void t3_print_menu() {
  cout << "\n FOR THIRD / FOURTH LAB MENU \n";
  cout << "1.  Create ticket (Standard / VIP / Discount / Kids / Couple)\n";
  cout << "2.  Show all tickets (polymorphic operator<<)\n";
  cout << "3.  Show base vs final prices (virtual Final_price)\n";
  cout << "4.  Check if seat is free (operator== duplicate check)\n";
  cout << "5.  Sell ticket via system += (with duplicate check)\n";
  cout << "6.  Show specific fields via getters (dynamic_cast)\n";
  cout << "7.  Show derived-type fields\n";
  cout << "8.  Demo dynamic polymorphism (Lab 4)\n";
  cout << "9.  Show ticket types via virtual non-pure method\n";
  cout << "10. Show biggest discount (polymorphic search)\n";
  cout << "11. Apply 5%  /extra discount to ALL tickets (mass action)\n";
  cout << "0.  Back\n";
}

static void handle_third_lab_choice(int choice,
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
    case 7: t3_show_derived_fields(tickets); break;
    case 8: t4_demo_polymorphism(tickets); break;
    case 9: t3_show_types(tickets); break;
    case 10: t4_show_biggest_discount(tickets);        break;
    case 11: t4_add_5_percent_discount(tickets);       break;
    default: cout << "Invalid choice.\n";
  }
}

void menu_third_lab(vector<shared_ptr<Session>>& sessions,
                    vector<shared_ptr<Ticket>>& tickets,
                    Ticket_system& system) {
  while (true) {
    t3_print_menu();
    int choice = read_int("Choice: ");
    if (choice == 0) return;
    handle_third_lab_choice(choice, sessions, tickets, system);
  }
}