#include <iostream>
#include <memory>
#include <vector>

#include "Class/Header/Hall.h"
#include "Class/Header/Session.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Vip_ticket.h"
#include "Class/Header/Discount_ticket.h"
#include "Class/Header/Kids_ticket.h"
#include "Class/Header/Couple_ticket.h"
#include "Class/Header/Ticket_system.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"
#include "Function/Read/Header/Read.h"
#include "Function/Menu/Header/Hall_menu.h"
#include "Function/Menu/Header/Session_menu.h"
#include "Function/Menu/Header/Ticket_menu.h"
#include "Function/Menu/Header/Ticket_system_menu.h"
#include "Function/Menu/Header/Second_lab_menu.h"
#include "Function/Menu/Header/Third_lab_menu.h"
#include "Function/Menu/Header/Fifth_lab_menu.h"
#include "Template/Collection.h"
#include<Define_const.h>

using namespace std;

int main() {
  auto hall1 = make_shared<Hall>(1, 10, "Moon");
  auto hall2 = make_shared<Hall>(2, 5, "Spartac");
  auto hall3 = make_shared<Hall>(3, 200, "October");
  auto hall4 = make_shared<Hall>(4, 420, "Queen");
  auto hall5 = make_shared<Hall>(5, 90, "Moon");

  Collection<shared_ptr<Hall>> halls;
  halls.add(hall1); 
  halls.add(hall2);
  halls.add(hall3); 
  halls.add(hall4); 
  halls.add(hall5);

  auto date1 = make_shared<Date>(2026, 2, 12);
  auto date2 = make_shared<Date>(2025, 12, 12);
  auto time1 = make_shared<Time>(13, 30);
  auto time2 = make_shared<Time>(18, 20);

  auto session1 = make_shared<Session>("Breaking Bad", time1, date1, hall5);
  auto session2 = make_shared<Session>("Stranger Things", time2, date2, hall2);
  auto session3 = make_shared<Session>("Stranger Things", time2, date2, hall2);


  auto ticket1 = make_shared<Standard_ticket>(2, 7, 12.3f, session1);
  auto ticket2 = make_shared<Vip_ticket>(3, 14, 10.3f, session2, true, true);
  auto ticket3 = make_shared<Discount_ticket>(1, 5, 10.0f, session1, 30, "Ivanov");
  auto ticket4 = make_shared<Kids_ticket>(4, 10, 8.0f, session1, "Petya", 8);
  auto ticket5 = make_shared<Couple_ticket>(5, 20, 12.0f, session2, "Anna", "Oleg", 21);

  Collection<shared_ptr<Ticket>> tickets;
  tickets.add(ticket1);
  tickets.add(ticket2);
  tickets.add(ticket3);
  tickets.add(ticket4);
  tickets.add(ticket5);

  Collection<shared_ptr<Session>> sessions;
  sessions.add(session1);
  sessions.add(session2);
  sessions.add(session3);



  Ticket_system system;
  system.in_shared_ticket(ticket1);

  while (true) {
    cout << "\nMAIN MENU\n";
    cout << "1. Hall\n";
    cout << "2. Session\n";
    cout << "3. Ticket\n";
    cout << "4. Ticket_system\n";
    cout << "5. For second lab\n";
    cout << "6. For third/fourth lab\n"; 
    cout << "7. For fifth lab (Templates)\n";
    cout << "67. Exit\n";

    int choice = read_int("Choice: ");

    if (choice == 1) {
      menu_hall(halls);
    } else if (choice == 2) {
      menu_session(sessions, halls);
    } else if (choice == 3) {
      menu_ticket(tickets, sessions);
    } else if (choice == 4) {
      menu_ticket_system(system, tickets, sessions);
    } else if (choice == EXIT_NUMBER) {
      return 0;
     } else if (choice == 5) {
      menu_second_lab(halls, sessions, tickets, system);
    } else if (choice == 6) {                                  
      menu_third_lab( sessions, tickets, system);
    } else if (choice == 7) {                                  
      menu_fifth_lab(tickets, sessions);
    } else {
      cout << "Invalid choice.\n";
    }
  }
}