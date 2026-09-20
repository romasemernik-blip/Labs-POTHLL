#pragma once
#include <memory>

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

  friend std::ostream& operator<<(std::ostream& os, const Ticket& t);
  friend std::istream& operator>>(std::istream& is, Ticket& t);
};