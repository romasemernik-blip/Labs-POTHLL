#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"    
#include "Class/Header/Session.h"  
#include <iostream>

using namespace std;

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


int Ticket_system::Sold_for_session(const shared_ptr<Session>& s) const {
  int count = 0;
  for (const auto& t : reservation) {
    if (t->Get_session() == s) ++count;
  }
  for (const auto& t : particle) {
    if (t->Get_session() == s) ++count;
  }
  return count;
}

bool Ticket_system::In_shared_ticket(const shared_ptr<Ticket>& ticket_sh) {
  auto s = ticket_sh->Get_session();
  if (s && Sold_for_session(s) >= s->Seats_limit()) {
    cout << "Limit reached: no more seats for this session.\n";
    return false;
  }
  reservation.push_back(ticket_sh);
  cout << "Ticket sold.\n";
  return true;
}
bool Ticket_system::In_unique_ticket(unique_ptr<Ticket> ticket_un) {
  auto s = ticket_un->Get_session();
  if (s && Sold_for_session(s) >= s->Seats_limit()) {
    cout << "Limit reached: no more seats for this session.\n";
    return false;
  }
  particle.push_back(move(ticket_un));
  cout << "Ticket sold.\n";
  return true;
}
