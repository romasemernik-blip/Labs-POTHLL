#pragma once
#include <memory>      
#include <vector>
#include <iostream>
#include "Template/Collection.h" 
#include "Class/Header/Ticket.h"

class Ticket;
class Session;

class Ticket_system {
 private:
  Collection<std::shared_ptr<Ticket>> reservation;
  Collection<std::unique_ptr<Ticket>> particle; 

 public:
  bool in_shared_ticket(const std::shared_ptr<Ticket>& ticket_sh);
  bool in_unique_ticket(std::unique_ptr<Ticket> ticket_un);

  void out_shared_ticket() const;
  void out_unique_ticket() const;
  void out_t_s() const;

  std::size_t shared_count() const;
  std::size_t unique_count() const;

  friend std::ostream& operator<<(std::ostream& os, const Ticket_system& ts);

  Ticket_system& operator+=(const std::shared_ptr<Ticket>& ticket_sh);
  Ticket_system& operator+=(std::unique_ptr<Ticket> ticket_un);


  Ticket_system& operator-=(const Ticket& ticket);
  Ticket_system& operator-=(const std::shared_ptr<Ticket>& ticket_sh);
  
  bool contains(const Ticket& ticket) const;
};