#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Ticket.h"

using namespace std;

void StandardTicket::print_ticket(ostream& os) const {
  os << "[Standard ticket]\n";
  Ticket::print_ticket(os);
}