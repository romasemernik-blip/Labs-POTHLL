#include "Class/Header/Kids_ticket.h"
#include "Exception/Header/Invalid_data_exception.h"
#include "Class/Header/Session.h"
#include <Define_const.h>

using namespace std;

Kids_ticket::Kids_ticket(int row, int place, float price,
                       shared_ptr<Session> session,
                       const string& child_name,
                       int child_age)
    : Ticket(row, place, price, session),
      child_name(child_name), child_age(child_age) {
  if (this->child_name.empty()) {
    throw Invalid_Data_Exception("Child name cannot be empty");
  }
  if (this->child_age < MIN_KIDS_AGE || this->child_age > MAX_KIDS_AGE) {
    throw Invalid_Data_Exception("Child age " + std::to_string(this->child_age) + " out of range");
  }
}


float Kids_ticket::final_price() const { return get_price() * CHILD_DISCOUNT; }

bool Kids_ticket::set_child_name(const string_view& name) {
  if (name.empty()) {
    throw Invalid_Data_Exception("Child name cannot be empty");
  }
  child_name = name;
  return true;
}

bool Kids_ticket::set_child_age(int age) {
  if (age < MIN_KIDS_AGE || age > MAX_KIDS_AGE) {
    throw Invalid_Data_Exception("Child age " + std::to_string(age) + " out of range");
  }
  child_age = age;
  return true;
}


std::string Kids_ticket::type_name() const { return "Kids"; }

void Kids_ticket::print_ticket(ostream& os) const {
  Ticket::print_ticket(os);
  os << "Final price: " << final_price() << "$\n";
  os << "Child: " << child_name << ", age: " << child_age << "\n"
     << "Child discount:" << CHILD_DISCOUNT*PERCENT<< "%\n";
}

double  Kids_ticket::discount_info() const {
  return CHILD_DISCOUNT*PERCENT;
}