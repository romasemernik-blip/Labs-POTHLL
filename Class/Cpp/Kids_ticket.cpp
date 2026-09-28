#include "Class/Header/Kids_ticket.h"
#include "Class/Header/Session.h"
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

float Kids_ticket::final_price() const { return get_price() * CHILD_DISCOUNT; }

bool Kids_ticket::set_child_name(const string_view& name) {
  if (name.empty()) {
    cout << "Error: child name cannot be empty.\n";
    return false;
  }
  child_name = name;
  return true;
}

bool Kids_ticket::set_child_age(int age) {
  if (age < MIN_KIDS_AGE || age > MAX_KIDS_AGE) {
    cout << "Error: age must be in range "
         << MIN_KIDS_AGE << ".." << MAX_KIDS_AGE << ".\n";
    return false;
  }
  child_age = age;
  return true;
}

std::string Kids_ticket::type_name() const { return "Kids"; }

void Kids_ticket::print_ticket(ostream& os) const {
  os << "[" << type_name() << " ticket]\n";
  os << "Row and place: " << get_row() << " " << get_place() << "\n";
  if (get_session()) os << *get_session();
  os << "Base price:  " << get_price() << "$\n"
     << "Final price: " << final_price() << "$\n";
  os << "Child: " << child_name << ", age: " << child_age << "\n"
     << "Child discount: x0.5\n";
}

std::string Kids_ticket::discount_info() const {
  return "child discount 50%";
}