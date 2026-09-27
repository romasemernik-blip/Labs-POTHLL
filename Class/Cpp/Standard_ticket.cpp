#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Ticket.h"

using namespace std;

void Standard_ticket::print_ticket(ostream& os) const {
  os << "[Standard ticket]\n";
  Ticket::print_ticket(os);
}