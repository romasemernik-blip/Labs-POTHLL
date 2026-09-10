#pragma once
#include <memory>

using namespace std;

class Session;  // forward declaration

class Ticket {
 private:
  int place;
  shared_ptr<Session> session;
  float price;
  int row;

 public:
  Ticket(int row, int place, float price, shared_ptr<Session> session);

  void In_place(int place);
  void In_session(shared_ptr<Session> session_);
  void In_price(float price);
  void In_row(int row);

  void Out_t() const;
  void Out_place_and_row() const;
  void Out_session() const;
  void Out_price() const;

  int Get_row() const;
  int Get_place() const;
  float Get_price() const;
  shared_ptr<Session> Get_session() const;
};