#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"    
#include "Class/Header/Session.h"  
#include <iostream>
#include <memory>

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

bool Ticket_system::In_shared_ticket(const shared_ptr<Ticket>& ticket_sh) {
  if (!ticket_sh) {
    cout << "Error: ticket is null.\n";
    return false;
  }
  auto s = ticket_sh->Get_session();
  if (!s) {
    cout << "Error: ticket has no session.\n";
    return false;
  }
  if (!s->Sell_seat()) {
    cout << "Limit reached: no free seats for this session ("
         << s->Sold_seats() << "/" << s->Seats_limit() << ").\n";
    return false;
  }
  reservation.push_back(ticket_sh);
  cout << "Ticket sold. Seats: " << s->Sold_seats()
       << "/" << s->Seats_limit() << "\n";
  return true;
}
bool Ticket_system::In_unique_ticket(unique_ptr<Ticket> ticket_un) {
  if (!ticket_un) {
    cout << "Error: ticket is null.\n";
    return false;
  }
  auto s = ticket_un->Get_session();
  if (!s) {
    cout << "Error: ticket has no session.\n";
    return false;
  }
  if (!s->Sell_seat()) {
    cout << "Limit reached: no free seats for this session ("
         << s->Sold_seats() << "/" << s->Seats_limit() << ").\n";
    return false;
  }
  particle.push_back(move(ticket_un));
  cout << "Ticket sold. Seats: " << s->Sold_seats()
       << "/" << s->Seats_limit() << "\n";
  return true;
}