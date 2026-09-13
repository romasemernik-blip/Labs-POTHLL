#include "Function/Change_atributes/Header/Ticket_change.h"
#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Session_show.h"
#include <iostream>

using namespace std;

void Change_ticket_field(vector<shared_ptr<Ticket>>& tickets,
                         vector<shared_ptr<Session>>& sessions, int idx) {
  cout << "What to change?\n";
  cout << "1. Row\n";
  cout << "2. Place\n";
  cout << "3. Price\n";
  cout << "4. Session\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1: tickets[idx]->In_row(Read_int("New row: ")); break;
    case 2: tickets[idx]->In_place(Read_int("New place: ")); break;
    case 3: tickets[idx]->In_price(Read_float("New price: ")); break;
    case 4: {
      Show_session_films(sessions);
      int s = Read_int("Session index: ");
      tickets[idx]->In_session(sessions[s]);
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}