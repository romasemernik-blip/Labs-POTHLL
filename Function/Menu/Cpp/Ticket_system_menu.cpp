#include "Function/Menu/Header/Ticket_system_menu.h"
#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Ticket_show.h"
#include "Function/Show/Header/Session_show.h"
#include "Class/Header/Standard_ticket.h"
#include "Exception/Header/All_exceptions.h"
#include <iostream>

using namespace std;

void menu_ticket_system(Ticket_system& system,
                        Collection<shared_ptr<Ticket>>& tickets,
                        Collection<shared_ptr<Session>>& sessions) {
  while (true) {
    try {
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
      tickets.at(idx);
       system += tickets.at(idx);
     } else if (choice == 3) {
      int row = read_int("Row: ");
      int place = read_int("Place: ");
      float price = read_float("Price: ");

      show_session_films(sessions);
      int s = read_int("Session index: ");
      sessions.at(s);

      auto t = make_unique<Standard_ticket>(row, place, price, sessions[s]);
      system.in_unique_ticket(move(t));
    } else if (choice == 4) {
      cout << "Shared tickets: " << system.shared_count() << endl;
      cout << "Unique tickets: " << system.unique_count() << endl;
    }
  }
    catch (const Duplicate_Id_Exception& e)      { cout << "[SEAT BUSY] " << e.what() << "\n"; }
    catch (const Object_Not_Found_Exception& e)  { cout << "[NOT FOUND] " << e.what() << "\n"; }
    catch (const Limit_Exceeded_Exception& e)    { cout << "[LIMIT] " << e.what() << "\n"; }
    catch (const Out_Of_Range_Exception& e)      { cout << "[RANGE] " << e.what() << "\n"; }
    catch (const Invalid_Operation_Exception& e) { cout << "[BAD OP] " << e.what() << "\n"; }
    catch (const Relation_Exception& e)          { cout << "[RELATION] " << e.what() << "\n"; }
    catch (const Invalid_Data_Exception& e)      { cout << "[DATA] " << e.what() << "\n"; }
    catch (const Cinema_Exception& e)            { cout << "[ERROR] " << e.what() << "\n"; }
    catch (const std::exception& e)              { cout << "[STD] " << e.what() << "\n"; }
    catch (...)                                  { cout << "[UNKNOWN]\n"; }
}
}