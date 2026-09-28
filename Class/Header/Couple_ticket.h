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

  bool set_person1(const std::string& n);
  bool set_person2(const std::string& n);
  bool set_second_place(int p);

  const std::string& get_person1() const { return person1; }
  const std::string& get_person2() const { return person2; }
  int get_second_place() const { return second_place; }

private:
  std::string person1;
  std::string person2;
  int second_place;
};