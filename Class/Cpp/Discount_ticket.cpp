#include "Class/Header/Discount_ticket.h"
#include "Class/Header/Session.h"
#include "Exception/Header/Invalid_data_exception.h"
#include<Define_const.h>

using namespace std;

Discount_ticket::Discount_ticket(int row, int place, float price,
                               shared_ptr<Session> session,
                               int discount_percent,
                               const string& holder_name)
    : Ticket(row, place, price, session),
      discount_percent(discount_percent),
      holder_name(holder_name) {
  if (this->discount_percent < MIN_DISCOUNT || this->discount_percent > MAX_DISCOUNT) {
    throw Invalid_Data_Exception("Discount " + std::to_string(this->discount_percent) + "% out of range");
  }
  if (this->holder_name.empty()) {
    throw Invalid_Data_Exception("Holder name cannot be empty");
  }
}

float Discount_ticket::final_price() const {
  return get_price() * (1.0f - discount_percent / 100.0f);
}

bool Discount_ticket::set_discount(int d) {
  if (d < MIN_DISCOUNT || d > MAX_DISCOUNT) {
    throw Invalid_Data_Exception("Discount " + std::to_string(d) + "% out of range");
  }
  discount_percent = d;
  return true;
}

bool Discount_ticket::set_holder(const std::string_view& h) {
  if (h.empty()) {
    throw Invalid_Data_Exception("Holder name cannot be empty");
  }
  holder_name = h;
  return true;
}

std::string Discount_ticket::type_name() const { return "Discount"; }

void Discount_ticket::print_ticket(ostream& os) const {
  Ticket::print_ticket(os);
  os << "Final price: " << final_price() << "$\n";
  os << "Holder: " << holder_name << "\n"
     << "Discount: " << discount_percent << "%\n";
}

double  Discount_ticket::discount_info() const {
  return discount_percent;
}