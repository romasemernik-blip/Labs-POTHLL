#pragma once
#include <memory>
#include <iostream>

class Session;  

class Ticket {
 protected:
  int place;
  std::shared_ptr<Session> session;
  float price;
  int row;

 public:
  Ticket(int row, int place, float price, std::shared_ptr<Session> session);

  virtual ~Ticket() = default;

  bool in_place(int place);
  bool in_session(std::shared_ptr<Session> session_);
  bool in_price(float price);
  bool in_row(int row);

  virtual void print_ticket(std::ostream& os ) const;
  virtual float final_price() const;

  void out_t() const;
  void out_place_and_row() const;
  void out_session() const;
  void out_price() const;

  int get_row() const;
  int get_place() const;
  float get_price() const;
  std::shared_ptr<Session> get_session() const;

  friend std::ostream& operator<<(std::ostream& os, const Ticket& t);

   friend bool operator==(const Ticket& a, const Ticket& b) ;
  friend bool operator!=(const Ticket& a, const Ticket& b);
};