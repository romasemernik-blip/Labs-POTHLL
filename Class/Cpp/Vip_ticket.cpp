#include "Class/Header/Vip_ticket.h"
#include<Define_const.h>

using namespace std;

Vip_ticket::Vip_ticket(int row, int place, float price,
                     shared_ptr<Session> session,
                     bool lounge_access, bool free_drinks)
    : Ticket(row, place, price, session),
      has_lounge_access(lounge_access),
      has_free_drinks(free_drinks) {}

float Vip_ticket::final_price() const { return get_price() * VIP_EX_TICKET ; }

void Vip_ticket::print_ticket(ostream& os) const {
  os << "[VIP ticket]\n";
  Ticket::print_ticket(os);
  os << "Lounge access: " << (has_lounge_access ? "yes" : "no") << "\n"
     << "Free drinks: "   << (has_free_drinks  ? "yes" : "no") << "\n";
}

std::string type_name() { return "VIP"; }