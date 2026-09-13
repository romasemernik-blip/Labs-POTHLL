#include "Function/Menu/Header/Ticket_system_menu.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Show/Header/Session_show.h"
#include <iostream>

using namespace std;

void Menu_ticket_system(Ticket_system& system,
                        vector<shared_ptr<Ticket>>& tickets,
                        vector<shared_ptr<Session>>& sessions) {
  while (true) {
    cout << "\nTICKET_SYSTEM MENU\n";
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