#pragma once
#include <string>
#include "Class/Header/Ticket.h"

class Discount_ticket : public Ticket {
public:
  Discount_ticket(int row, int place, float price,
                 std::shared_ptr<Session> session,
                 int discount_percent,
                 const std::string& holder_name);

  float final_price() const override;
  void print_ticket(std::ostream& os) const override;

  int get_discount() const { return discount_percent; }
  std::string get_holder() const { return holder_name; }

  bool set_discount(int d);
  bool set_holder(const std::string_view& h);

  std::string type_name() const override ;

private:
  int discount_percent;
  std::string holder_name;
};