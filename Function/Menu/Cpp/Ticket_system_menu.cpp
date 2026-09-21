#include "Function/Menu/Header/Ticket_system_menu.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Show/Header/Session_show.h"
#include <iostream>

using namespace std;

void menu_ticket_system(Ticket_system& system,
                        vector<shared_ptr<Ticket>>& tickets,
                        vector<shared_ptr<Session>>& sessions) {
  while (true) {
    cout << "\nTICKET_SYSTEM MENU\n";
    cout << "1. Show system contents\n";
    cout << "2. Add ticket (shared)\n";
    cout << "3. Add ticket (unique)\n";
    cout << "4. Show number of tickets\n";
    cout << "0. Back\n";

    int choice = read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      system.out_t_s();
    } else if (choice == 2) {
      show_ticket_short_no_price(tickets);
      int idx = read_int("Ticket index: ");
      system.in_shared_ticket(tickets[idx]);
     } else if (choice == 3) {
      int row = read_int("Row: ");
      int place = read_int("Place: ");
      float price = read_float("Price: ");

      show_session_films(sessions);
      int s = read_int("Session index: ");

      if (s < 0 || s >= (int)sessions.size()) {
        cout << "Invalid session index.\n";
        continue;
      }

      auto t = make_unique<Ticket>(row, place, price, sessions[s]);
      system.in_unique_ticket(move(t));
    } else if (choice == 4) {
      cout << "Shared tickets: " << system.shared_count() << endl;
      cout << "Unique tickets: " << system.unique_count() << endl;
    }
  }
}