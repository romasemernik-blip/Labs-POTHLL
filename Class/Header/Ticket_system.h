#pragma once
#include <memory>
#include <vector>



class Ticket;  

class Ticket_system {
 private:
  std::vector<std::shared_ptr<Ticket>> reservation;
  std::vector<std::unique_ptr<Ticket>> particle;

 public:
  void In_shared_ticket(const std::shared_ptr<Ticket>& ticket_sh);
  void In_unique_ticket(std::unique_ptr<Ticket> ticket_un);

  void Out_shared_ticket() const;
  void Out_unique_ticket() const;
  void Out_t_s() const;

  size_t Shared_count() const;
  size_t Unique_count() const;
};