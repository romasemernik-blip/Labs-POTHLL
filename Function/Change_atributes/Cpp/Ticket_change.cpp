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
    case 1: {
  if (int v = Read_int("New row: "); tickets[idx]->In_row(v))
    cout << "Row changed.\n";
  break;
}
case 2: {
  if (int v = Read_int("New place: "); tickets[idx]->In_place(v))
    cout << "Place changed.\n";
  break;
}
case 3: {
  if (float v = Read_float("New price: "); tickets[idx]->In_price(v))
    cout << "Price changed.\n";
  break;
}
case 4: {
  Show_session_films(sessions);
  if (int s = Read_int("Session index: ");
      tickets[idx]->In_session(sessions[s]))
    cout << "Session changed.\n";
  break;
}
}