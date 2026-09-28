#include "Class/Header/Standard_ticket.h"
#include "Class/Header/Session.h"
#include "Class/Header/Ticket.h"

using namespace std;

Standard_ticket::Standard_ticket(int row, int place, float price,
                                 shared_ptr<Session> session,
                                 const string& zone)
    : Ticket(row, place, price, session), zone(zone) {
  if (this->zone.empty()) this->zone = "Standard";
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

std::string Standard_ticket::type_name() const  { return "Standard"; }

void Standard_ticket::print_ticket(ostream& os) const {
  os << "[" << type_name() << " ticket]\n";
  os << "Row and place: " << get_row() << " " << get_place() << "\n";
  if (get_session()) os << *get_session();
  os << "Base price:  " << get_price() << "$\n"
     << "Final price: " << final_price() << "$\n";
}