#include "Function/Menu/Header/Ticket_menu.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Change_attributes/Header/Ticket_change.h"
#include <iostream>

using namespace std;

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