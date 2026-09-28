#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Ticket.h"

using namespace std;

Standard_ticket::Standard_ticket(int row, int place, float price,
                                 shared_ptr<Session> session,
                                 const string& zone)
    : Ticket(row, place, price, session), zone(zone) {
  if (this->zone.empty()) this->zone = "Standard";
}

void Standard_ticket::print_ticket(ostream& os) const {
  os << "[Standard ticket]\n";
  Ticket::print_ticket(os);
  os << "Zone: " << zone <<"\n";
}

float Standard_ticket::final_price() const { return get_price();}

bool Standard_ticket::set_zone(const string_view& z) {
  if (z.empty()) {
    cout << "Error: zone cannot be empty.\n";
    return false;
  }
  zone = z;
  return true;
}

std::string type_name() { return "Standard"; }