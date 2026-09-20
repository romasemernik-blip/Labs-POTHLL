#pragma once
#include <memory>
#include <iostream>

class Session;  

class Ticket {
 private:
  int place;
  std::shared_ptr<Session> session;
  float price;
  int row;

 public:
  Ticket(int row, int place, float price, std::shared_ptr<Session> session);

  bool In_place(int place);
  bool In_session(std::shared_ptr<Session> session_);
  bool In_price(float price);
  bool In_row(int row);

  void Out_t() const;
  void Out_place_and_row() const;
  void Out_session() const;
  void Out_price() const;

  int Get_row() const;
  int Get_place() const;
  float Get_price() const;
  std::shared_ptr<Session> Get_session() const;

friend std::ostream& operator<<(std::ostream& os, const Ticket& t) {
  os << "Ticket:\n"
     << "Row and place of person: " << t.row << " " << t.place << "\n";
  if (t.session) os << *t.session;
  os << "Price of ticket: " << t.price << "$\n";
  return os;
}

friend std::istream& operator>>(std::istream& is, Ticket& t) {
  cout << "Row: ";
  is >> t.row;
  cout << "Place: ";
  is >> t.place;
  cout << "Price: ";
  is >> t.price;
  if (t.row < 1) t.row = 1;
  if (t.place < 1) t.place = 1;
  if (t.price <= 0) t.price = 1.0f;
  return is;
}

  bool Ticket::operator==(const Ticket& other) const ;
};