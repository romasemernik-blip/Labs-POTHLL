#pragma once
#include "Class/Header/Ticket.h"

class Vip_ticket : public Ticket {
public:
  Vip_ticket(int row, int place, float price,
            std::shared_ptr<Session> session,
            bool lounge_access, bool free_drinks);

  float final_price() const override;
  void print_ticket(std::ostream& os) const override;

  bool has_lounge() const { return has_lounge_access; }
  bool has_drinks() const { return has_free_drinks; }

  void set_lounge(bool v) { has_lounge_access = v; }
  void set_drinks(bool v) { has_free_drinks = v; }

  std::string type_name() const override ;

private:
  bool has_lounge_access;
  bool has_free_drinks;
};
