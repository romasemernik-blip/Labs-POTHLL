#pragma once
#include <string>
#include "Class/Header/Ticket.h"

class Kids_ticket : public Ticket {
public:
  Kids_ticket(int row, int place, float price,
             std::shared_ptr<Session> session,
             const std::string& child_name,
             int child_age);

  float final_price() const override;
  void print_ticket(std::ostream& os) const override;

private:
  std::string child_name;
  int child_age;
};