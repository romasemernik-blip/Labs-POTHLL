#include "Class/Header/Discount_ticket.h"
#include<Define_const.h>

using namespace std;

Discount_ticket::Discount_ticket(int row, int place, float price,
                               shared_ptr<Session> session,
                               int discount_percent,
                               const string& holder_name)
    : Ticket(row, place, price, session),
      discount_percent(discount_percent),
      holder_name(holder_name) {
  if (this->discount_percent < MIN_DISCOUNT)   this->discount_percent = MIN_DISCOUNT;
  if (this->discount_percent > MAX_DISCOUNT)  this->discount_percent = MAX_DISCOUNT;
}

float Discount_ticket::final_price() const {
  return price * (1.0f - discount_percent / 100.0f);
}

void Discount_ticket::print_ticket(ostream& os) const {
  os << "[Discount ticket]\n";
  Ticket::print_ticket(os);
  os << "Holder: " << holder_name << "\n"
     << "Discount: " << discount_percent << "%\n";
}

bool Discount_ticket::set_discount(int d) {
  if (d < MIN_DISCOUNT || d > MAX_DISCOUNT) {
    cout << "Error: discount must be in range "
         << MIN_DISCOUNT << ".." << MAX_DISCOUNT << ".\n";
    return false;
  }
  discount_percent = d;
  return true;
}

bool Discount_ticket::set_holder(const std::string& h) {
  if (h.empty()) { cout << "Error: holder cannot be empty.\n"; return false; }
  holder_name = h;
  return true;
}