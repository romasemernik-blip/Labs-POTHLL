#include "Class/Header/Kids_ticket.h"
#include <Define_const.h>

using namespace std;

Kids_ticket::Kids_ticket(int row, int place, float price,
                       shared_ptr<Session> session,
                       const string& child_name,
                       int child_age)
    : Ticket(row, place, price, session),
      child_name(child_name), child_age(child_age) {
  if (this->child_age < MIN_KIDS_AGE)  this->child_age = MIN_KIDS_AGE;
  if (this->child_age > MAX_KIDS_AGE) this->child_age = MAX_KIDS_AGE;
}

float Kids_ticket::final_price() const { return price * CHILD_DISCOUNT; }

void Kids_ticket::print_ticket(ostream& os) const {
  os << "[Kids ticket]\n";
  Ticket::print_ticket(os);
  os << "Child: " << child_name << ", age: " << child_age << "\n";
}