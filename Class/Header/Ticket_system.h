#pragma once
#include <memory>      
#include <vector>
#include <iostream>

class Ticket;
class Session;

class Ticket_system {
 private:
  std::vector<std::shared_ptr<Ticket>> reservation;
  std::vector<std::unique_ptr<Ticket>> particle;


 public:
  bool In_shared_ticket(const std::shared_ptr<Ticket>& ticket_sh);
  bool In_unique_ticket(std::unique_ptr<Ticket> ticket_un);

  void Out_shared_ticket() const;
  void Out_unique_ticket() const;
  void Out_t_s() const;

  std::size_t Shared_count() const;
  std::size_t Unique_count() const;

  friend std::ostream& operator<<(std::ostream& os, const Ticket_system& ts);

  Ticket_system& operator+=(const std::shared_ptr<Ticket>& ticket_sh);
  Ticket_system& operator+=(std::unique_ptr<Ticket> ticket_un);


  Ticket_system& operator-=(const Ticket& ticket);
  Ticket_system& operator-=(const std::shared_ptr<Ticket>& ticket_sh);
};