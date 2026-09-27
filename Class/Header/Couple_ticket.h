#pragma once
#include <string>
#include "Class/Header/Ticket.h"

class Couple_ticket : public Ticket {
public:
  Couple_ticket(int row, int place, float price,
               std::shared_ptr<Session> session,
               const std::string& person1,
               const std::string& person2,
               int second_place);

  float final_price() const override;
  void print_ticket(std::ostream& os) const override;

private:
  std::string person1;
  std::string person2;
  int second_place;
};