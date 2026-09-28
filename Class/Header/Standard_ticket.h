#pragma once
#include "Class/Header/Ticket.h"

class Standard_ticket : public Ticket {
public:
  Standard_ticket(int row, int place, float price,
                  std::shared_ptr<Session> session,
                  const std::string& zone = "Standard");
  void print_ticket(std::ostream& os) const override;
  float final_price() const override;

  const std::string& get_zone() const { return zone; }
  bool set_zone(const std::string_view& z);
  
  std::string type_name() const override ;

private:
std::string zone;
};