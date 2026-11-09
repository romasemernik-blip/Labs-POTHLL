#include "Function/Menu/Header/Ticket_menu.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Change_atributes/Header/Ticket_change.h"
#include <iostream>
#include "Exception/Header/All_exceptions.h"

using namespace std;

static void handle_ticket_choice(int choice, Collection<shared_ptr<Ticket>>& tickets, Collection<shared_ptr<Session>>& sessions) {
    if (choice == 1) {
        show_all_tickets(tickets);
    } else if (choice == 2) {
        show_ticket_short(tickets);
        int idx = read_int("Enter ticket index: ");
        tickets.at(idx);
        change_ticket_field(tickets, sessions, idx);
    } else {
        cout << "Invalid choice.\n";
    }
}

void menu_ticket(Collection<shared_ptr<Ticket>>& tickets, Collection<shared_ptr<Session>>& sessions) {
  while (true) {
    try {
      cout << "\nTICKET MENU\n";
      cout << "1. Show all tickets\n";
      cout << "2. Change ticket characteristics\n";
      cout << "0. Back\n";

      int choice = read_int("Choice: ");
      if (choice == 0) return;

      handle_ticket_choice(choice, tickets, sessions);
    }
    catch (const Out_Of_Range_Exception& e)      { cout << "[RANGE] " << e.what() << "\n"; }
    catch (const Invalid_Data_Exception& e)      { cout << "[DATA] " << e.what() << "\n"; }
    catch (const Cinema_Exception& e)            { cout << "[ERROR] " << e.what() << "\n"; }
  }
}