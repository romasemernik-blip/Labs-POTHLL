#include "Class/Header/Ticket.h"
#include "Class/Header/Session.h"   
#include "Exception/Header/Invalid_data_exception.h"
#include "Exception/Header/Out_of_range_exception.h"
#include "Exception/Header/Relation_exception.h"
#include <iostream>

using namespace std;

Ticket::Ticket(int row, int place, float price, shared_ptr<Session> session)
    : place(place), session(session), price(price), row(row) {
  if (row < 1) throw Invalid_Data_Exception("Row cannot be less than 1");
  if (place < 1) throw Invalid_Data_Exception("Place cannot be less than 1");
  if (price <= 0) throw Invalid_Data_Exception("Price must be > 0");
  if (!session) throw Relation_Exception("Ticket cannot be created without a session");
}

bool Ticket::in_place(int place_) {
  if (place_ < 1) {
    throw Invalid_Data_Exception("Place must be >= 1");
  }
  if (session && session->get_hall() && place_ > session->get_hall()->get_num_seat()) {
    throw Out_Of_Range_Exception("Place " + std::to_string(place_) + 
                                 " exceeds number of seats in hall (" + 
                                 std::to_string(session->get_hall()->get_num_seat()) + ")");
  }
  this->place = place_;
  return true;
}

bool Ticket::in_session(shared_ptr<Session> session_) {
  if (!session_) {
    throw Relation_Exception("Session is null");
  }
  session = session_;
  return true;
}

bool Ticket::in_price(float price_) {
  if (price_ <= 0) {
    throw Invalid_Data_Exception("Price must be positive");
  }
  this->price = price_;
  return true;
}

bool Ticket::in_row(int row_) {
  if (row_ < 1) {
    throw Invalid_Data_Exception("Row must be >= 1");
  }
  this->row = row_;
  return true;
}

void Ticket::out_t() const {
  print_ticket(cout);       
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
    return a.row == b.row && a.place == b.place  && a.session == b.session;
  }
  bool operator!=(const Ticket& a, const Ticket& b) {
    return !(a == b);
  }

ostream& operator<<(ostream& os, const Ticket& t) {
  t.print_ticket(os);    
  return os;
}

double Ticket::discount_info() const {
  return 0;
}

 void Ticket::print_ticket(std::ostream& os ) const 
 {
    os << "[" << type_name() << " ticket]\n";
  os << "Row and place: " << get_row() << " " << get_place() << "\n";
  if (get_session()) os << *get_session();
  os << "Base price:  " << get_price() << "$\n";

 }