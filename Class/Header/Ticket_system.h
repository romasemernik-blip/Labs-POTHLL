#pragma once
#include <memory>
#include <vector>



class Ticket;  

class Ticket_system {
 private:
  std::vector<std::shared_ptr<Ticket>> reservation;
  std::vector<std::unique_ptr<Ticket>> particle;

 public:
   int Sold_for_session(const shared_ptr<Session>& s) const;
  bool In_shared_ticket(const shared_ptr<Ticket>& ticket_sh);
  bool In_unique_ticket(unique_ptr<Ticket> ticket_un);

  void Out_shared_ticket() const;
  void Out_unique_ticket() const;
  void Out_t_s() const;

  size_t Shared_count() const;
  size_t Unique_count() const;
};