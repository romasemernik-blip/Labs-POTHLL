#pragma once
#include "Class/Header/Ticket.h"

class Vip_ticket : public Ticket {
public:
  Vip_ticket(int row, int place, float price,
            std::shared_ptr<Session> session,
            bool lounge_access, bool free_drinks);

  float final_price() const ;
  void print_ticket(std::ostream& os) const ;

private:
  bool has_lounge_access;
  bool has_free_drinks;
};