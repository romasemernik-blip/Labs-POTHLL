#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"    
#include <iostream>

using namespace std;

void Ticket_system::In_shared_ticket(const shared_ptr<Ticket>& ticket_sh) {
  reservation.push_back(ticket_sh);
}

void Ticket_system::In_unique_ticket(unique_ptr<Ticket> ticket_un) {
  particle.push_back(move(ticket_un));
}

void Ticket_system::Out_shared_ticket() const {
  for (const auto& ticket_sh : reservation) ticket_sh->Out_t();
}

void Ticket_system::Out_unique_ticket() const {
  for (const auto& ticket_un : particle) ticket_un->Out_t();
}

void Ticket_system::Out_t_s() const {
  cout << "Ticket System Database" << endl;
  Out_shared_ticket();
  Out_unique_ticket();
  cout << endl;
}

size_t Ticket_system::Shared_count() const { return reservation.size(); }
size_t Ticket_system::Unique_count() const { return particle.size(); }