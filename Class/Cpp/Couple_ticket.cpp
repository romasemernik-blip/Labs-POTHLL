#include "Class/Header/Couple_ticket.h"
#include <Define_const.h>

using namespace std;

Couple_ticket::Couple_ticket(int row, int place, float price,
                           shared_ptr<Session> session,
                           const string& person1,
                           const string& person2,
                           int second_place)
    : Ticket(row, place, price, session),
      person1(person1), person2(person2),
      second_place(second_place) {
  if (this->second_place < 1) this->second_place = place + 1;
}

float Couple_ticket::final_price() const { return price * COUPLE_DISCOUNT; }

void Couple_ticket::print_ticket(ostream& os) const {
  os << "[Couple ticket]\n";
  Ticket::print_ticket(os);
  os << "Person 1: " << person1 << "\n"
     << "Person 2: " << person2 << "\n"
     << "Second place: " << second_place << "\n";
}

bool Couple_ticket::set_person1(const string& n) {
  if (n.empty()) { cout << "Error: name cannot be empty.\n"; return false; }
  person1 = n; return true;
}

bool Couple_ticket::set_person2(const string& n) {
  if (n.empty()) { cout << "Error: name cannot be empty.\n"; return false; }
  person2 = n; return true;
}

bool Couple_ticket::set_second_place(int p) {
  if (p < 1) { cout << "Error: place must be >= 1.\n"; return false; }
  second_place = p; return true;
}