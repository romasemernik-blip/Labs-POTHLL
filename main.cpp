#include <iostream>
#include <memory>
#include <vector>

#include "Class/Header/Hall.h"
#include "Class/Header/Session.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Ticket_system.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"
#include "Function/Read/Header/Read.h"
#include "Function/Menu/Header/Hall_menu.h"
#include "Function/Menu/Header/Session_menu.h"
#include "Function/Menu/Header/Ticket_menu.h"
#include "Function/Menu/Header/Ticket_system_menu.h"

using namespace std;

int main() {
  auto hall1 = make_shared<Hall>(1, 10, "Moon");
  auto hall2 = make_shared<Hall>(2, 5, "Spartac");
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
    cout << "\nMAIN MENU\n";
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