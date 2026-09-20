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

bool Ticket::In_place(int place_) {
  if (place_ < 1) {
    cout << "Error: place must be >= 1.\n";
    return false;
  }
 if (session && session->Get_hall() &&
      place > session->Get_hall()->Get_num_seat()) {
    cout << "Error: place exceeds number of seats in hall ("
         << session->Get_hall()->Get_num_seat() << ").\n";
    return false;
  }
  this->place = place_;
  return true;
}

bool Ticket::In_session(shared_ptr<Session> session_) {
  if (!session_) {
    cout << "Error: session is null.\n";
    return false;
  }
  session = session_;
  return true;
}

bool Ticket::In_price(float price_) {
  if (price_ <= 0) {
    cout << "Error: price must be positive.\n";
    return false;
  }
  this->price = price_;
  return true;
}

bool Ticket::In_row(int row_) {
  if (row_ < 1) {
    cout << "Error: row must be >= 1.\n";
    return false;
  }
  this->row = row_;
  return true;
}
void Ticket::Out_t() const {
  cout << "Ticket:" << endl;
  Out_place_and_row();
  Out_session();
  Out_price();
  cout << endl;
}

void Ticket::Out_place_and_row() const {
  cout << "Row and place of person: " << row << " " << place << endl;
}

void Ticket::Out_session() const {
  if (session) session->Out_s();
}

void Ticket::Out_price() const {
  cout << "Price of ticket: " << price << "$" << endl;
}

int Ticket::Get_row() const { return row; }
int Ticket::Get_place() const { return place; }
float Ticket::Get_price() const { return price; }
shared_ptr<Session> Ticket::Get_session() const { return session; }

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