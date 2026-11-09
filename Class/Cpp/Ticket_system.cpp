#include "Class/Header/Ticket_system.h"
#include "Class/Header/Ticket.h"    
#include "Class/Header/Session.h" 
#include "Exception/Header/DuplicateId_exception.h"
#include "Exception/Header/Object_not_found_exception.h"
#include "Exception/Header/Invalid_data_exception.h"
#include "Exception/Header/Relation_exception.h" 
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

void Ticket_system::out_shared_ticket() const {
  for (const auto& ticket_sh : reservation) ticket_sh->out_t();
}

void Ticket_system::out_unique_ticket() const {
  for (const auto& ticket_un : particle) ticket_un->out_t();
}

void Ticket_system::out_t_s() const {
  cout << "Ticket System Database" << endl;
  out_shared_ticket();
  out_unique_ticket();
  cout << endl;
}

size_t Ticket_system::shared_count() const { return reservation.size(); }
size_t Ticket_system::unique_count() const { return particle.size(); }

bool Ticket_system::in_shared_ticket(const shared_ptr<Ticket>& ticket_sh) {
  if (!ticket_sh) throw Invalid_Data_Exception("Ticket is null");
  auto s = ticket_sh->get_session();
  if (!s) throw Relation_Exception("Ticket has no session");

  if (contains(*ticket_sh)) {
    throw Duplicate_Id_Exception("Seat (row " + std::to_string(ticket_sh->get_row()) + 
                                 ", place " + std::to_string(ticket_sh->get_place()) + ") is already sold");
  }

  s->sell_seat(); 

  try {
    reservation.add(ticket_sh); 
  } catch (...) {
    s->return_seat(); 
    throw;            
  }
  
  cout << "Ticket sold. Seats: " << s->sold_seats() << "/" << s->seats_limit() << "\n";
  return true;
}

bool Ticket_system::in_unique_ticket(unique_ptr<Ticket> ticket_un) {
  if (!ticket_un) throw Invalid_Data_Exception("Ticket is null");
  auto s = ticket_un->get_session();
  if (!s) throw Relation_Exception("Ticket has no session");

  if (contains(*ticket_un)) {
    throw Duplicate_Id_Exception("Seat is already sold");
  }

  s->sell_seat(); 

  try {
    particle.add(move(ticket_un)); 
  } catch (...) {
    s->return_seat();
    throw;
  }
  
  cout << "Ticket sold. Seats: " << s->sold_seats() << "/" << s->seats_limit() << "\n";
  return true;
}

Ticket_system& Ticket_system::operator+=(const shared_ptr<Ticket>& ticket_sh) {
  if (!ticket_sh) {
    cout << "Null ticket.\n";
    return *this;
  }
  if (contains(*ticket_sh)) {
    cout << "Error: duplicate ticket — same seat for same session.\n";
    return *this;
  }
  in_shared_ticket(ticket_sh);
  return *this;
}

Ticket_system& Ticket_system::operator+=(unique_ptr<Ticket> ticket_un) {
  if (!ticket_un) {
    cout << "Null ticket.\n";
    return *this;
  }
  if (contains(*ticket_un)) {
    cout << "Error: duplicate ticket — same seat for same session.\n";
    return *this;
  }
  in_unique_ticket(move(ticket_un));
  return *this;
}

Ticket_system& Ticket_system::operator-=(const Ticket& ticket) {
    if (int idx_res = reservation.find_if([&ticket](const shared_ptr<Ticket>& t) { return *t == ticket; }); idx_res != -1) {
        if (reservation.get(idx_res)->get_session()) reservation.get(idx_res)->get_session()->return_seat();
        reservation.remove_at(idx_res);
        cout << "Ticket removed from shared.\n";
        return *this;
    }

    if (int idx_part = particle.find_if([&ticket](const unique_ptr<Ticket>& t) { return *t == ticket; }); idx_part != -1) {
        if (particle.get(idx_part)->get_session()) particle.get(idx_part)->get_session()->return_seat();
        particle.remove_at(idx_part);
        cout << "Ticket removed from unique.\n";
        return *this;
    }
    
    throw Object_Not_Found_Exception("Ticket to remove not found in system");
}

Ticket_system& Ticket_system::operator-=(const shared_ptr<Ticket>& ticket_sh) {
  if (!ticket_sh) {
    throw Invalid_Data_Exception("Ticket is null");
  }
  *this -= *ticket_sh;
  return *this;
}

ostream& operator<<(ostream& os, const Ticket_system& ts) {
  os << "Ticket System Database\n";
  for (const auto& t : ts.reservation) os << *t;
  for (const auto& t : ts.particle)    os << *t;
  return os;
}

bool Ticket_system::contains(const Ticket& ticket) const {
  auto matches = [&ticket](const auto& ptr) {
    return ptr && *ptr == ticket;
  };
  return std::any_of(reservation.begin(), reservation.end(), matches)
      || std::any_of(particle.begin(),    particle.end(),    matches);
}