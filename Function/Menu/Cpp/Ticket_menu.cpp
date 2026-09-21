#include "Function/Menu/Header/Ticket_menu.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Change_atributes/Header/Ticket_change.h"
#include <iostream>

using namespace std;

void menu_ticket(vector<shared_ptr<Ticket>>& tickets,
                 vector<shared_ptr<Session>>& sessions) {
  while (true) {
    cout << "\nTICKET MENU\n";
    cout << "1. Show all tickets\n";
    cout << "2. Change ticket characteristics\n";
    cout << "0. Back\n";

    int choice = read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      show_all_tickets(tickets);
    } else if (choice == 2) {
      show_ticket_short(tickets);
      int idx = read_int("Enter ticket index: ");
      change_ticket_field(tickets, sessions, idx);
    }
  }
}