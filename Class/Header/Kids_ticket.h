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

  const std::string& get_child_name() const { return child_name; }
  int get_child_age() const { return child_age; }

  bool set_child_name(const std::string_view& name);
  bool set_child_age(int age);

  std::string type_name() const override ;

private:
  std::string child_name;
  int child_age;
};