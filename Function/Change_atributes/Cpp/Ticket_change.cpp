#include "Function/Change_atributes/Header/Ticket_change.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Session_show.h"
#include <iostream>

using namespace std;

void change_ticket_field(Collection<shared_ptr<Ticket>>& tickets,
                         Collection<shared_ptr<Session>>& sessions, int idx) {
  cout << "What to change?\n";
  cout << "1. Row\n";
  cout << "2. Place\n";
  cout << "3. Price\n";
  cout << "4. Session\n";

  int sub = read_int("Choice: ");
  
  switch (sub) {
    case 1: {
      tickets.at(idx)->in_row(read_int("New row: "));
      cout << "Row changed.\n";
      break;
    }
    case 2: {
      tickets.at(idx)->in_place(read_int("New place: "));
      cout << "Place changed.\n";
      break;
    }
    case 3: {
      tickets.at(idx)->in_price(read_float("New price: "));
      cout << "Price changed.\n";
      break;
    }
    case 4: {
      show_session_films(sessions);
      int s = read_int("Session index: ");
      
      tickets.at(idx)->in_session(sessions.at(s));
      cout << "Session changed.\n";
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}