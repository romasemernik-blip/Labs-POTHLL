#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"   
#include <iostream>

using namespace std;

Ticket::Ticket(int row, int place, float price, shared_ptr<Session> session)
    : place(place), session(session), price(price), row(row) {
      if (this->row < 1) this->row = 1;
      if (this->place < 1) this->place = 1;
      if (this->price <= 0) this->price = 1.0f;
    }

bool Ticket::in_place(int place_) {
  if (place_ < 1) {
    cout << "Error: place must be >= 1.\n";
    return false;
  }
 if (session && session->get_hall() &&
      place > session->get_hall()->get_num_seat()) {
    cout << "Error: place exceeds number of seats in hall ("
         << session->get_hall()->get_num_seat() << ").\n";
    return false;
  }
  this->place = place_;
  return true;
}

bool Ticket::in_session(shared_ptr<Session> session_) {
  if (!session_) {
    cout << "Error: session is null.\n";
    return false;
  }
  session = session_;
  return true;
}

bool Ticket::in_price(float price_) {
  if (price_ <= 0) {
    cout << "Error: price must be positive.\n";
    return false;
  }
  this->price = price_;
  return true;
}

bool Ticket::in_row(int row_) {
  if (row_ < 1) {
    cout << "Error: row must be >= 1.\n";
    return false;
  }
  this->row = row_;
  return true;
}
void Ticket::out_t() const {
  cout << "Ticket:" << endl;
  out_place_and_row();
  out_session();
  out_price();
  cout << endl;
}

void Ticket::out_place_and_row() const {
  cout << "Row and place of person: " << row << " " << place << endl;
}

void Ticket::out_session() const {
  if (session) session->out_s();
}

void Ticket::out_price() const {
  cout << "Price of ticket: " << price << "$" << endl;
}

int Ticket::get_row() const { return row; }
int Ticket::get_place() const { return place; }
float Ticket::get_price() const { return price; }
shared_ptr<Session> Ticket::get_session() const { return session; }

 bool operator==(const Ticket& a, const Ticket& b) {
    return a.row == b.row && a.place == b.place &&
           a.price == b.price && a.session == b.session;
  }
  bool operator!=(const Ticket& a, const Ticket& b) {
    return !(a == b);
  }

ostream& operator<<(ostream& os, const Ticket& t) {
  os << "Ticket:\n"
     << "Row and place of person: " << t.row << " " << t.place << "\n";
  if (t.session) os << *t.session;
  os << "Price of ticket: " << t.price << "$\n";
  return os;
}