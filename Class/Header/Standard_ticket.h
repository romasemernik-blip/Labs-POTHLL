#pragma once
#include "Class/Header/Ticket.h"

class StandardTicket : public Ticket {
public:
  using Ticket::Ticket;
  void print_ticket(std::ostream& os) const ;
};