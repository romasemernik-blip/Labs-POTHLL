#include "Class/Header/Session.h"
#include <iostream>

using namespace std;

Session::Session(const string& film, shared_ptr<Time> time_start,
                 shared_ptr<Date> date, shared_ptr<Hall> hall)
    : film(film), hall(hall), date(date), time_start(time_start) {}

void Session::In_film(const string_view& film_) { film = film_; }
void Session::In_hall(shared_ptr<Hall> hall_) { hall = hall_; }
void Session::In_time_start(shared_ptr<Time> time_start_) { time_start = time_start_; }
void Session::In_date(shared_ptr<Date> date_) { date = date_; }

int Session::Seats_limit() const {
  if (hall) return hall->Get_num_seat();
  return 0;
}
int Session::Sold_seats() const {
  return sold_seats;
}
int Session::Free_seats() const {
  int free = Seats_limit() - sold_seats;
  return free < 0 ? 0 : free;
}
bool Session::Sell_seat() {
  if (sold_seats >= Seats_limit()) {
    return false;  
    }
  ++sold_seats;
  return true;
}  
void Session::Return_seat() {
  if (sold_seats > 0) --sold_seats;
}

void Session::Out_s() const {
  cout << "Session info" << endl;
  Out_film();
  Out_hall();
  Out_date();
  Out_time();
  cout << endl;
}

void Session::Out_date() const {
  if (!date) return;
  cout << "Date:";
  date->Print();
  cout << endl;
}

void Session::Out_time() const {
  if (!time_start) return;
  cout << "Time:";
  time_start->Print();
  cout << endl;
}

void Session::Out_film() const {
  cout << "Name of session film: " << film << endl;
}

void Session::Out_hall() const {
  if (!hall) return;
  hall->Out_name();
  hall->Out_num();
}

string Session::Get_film() const { return film; }
shared_ptr<Hall> Session::Get_hall() const { return hall; }
shared_ptr<Date> Session::Get_date() const { return date; }
shared_ptr<Time> Session::Get_time_start() const { return time_start; }

bool Session::Can_change_hall(const shared_ptr<Hall>& new_hall) const {
  if (!new_hall) {
    cout << "Error: new hall is null.\n";
    return false;
  }
  if (!hall) {
    cout << "Error: current hall is null.\n";
    return false;
  }
  if (new_hall->Get_num_seat() < hall->Get_num_seat()) {
    cout << "Error: new hall has only " << new_hall->Get_num_seat()
         << " seats, but current hall has " << hall->Get_num_seat()
         << " seats. New hall must be at least as large.\n";
    return false;
  }
  return true;
}

bool Session::operator<(const Session& other) const {
  return Seats_limit() < other.Seats_limit();
}

bool Session::operator>(const Session& other) const {
  return other < *this;
}

bool Session::operator==(const Session& other) const {
  return Seats_limit() == other.Seats_limit();
}

bool Session::operator!=(const Session& other) const {
  return !(*this == other);
}

bool Session::operator<(const Hall& h) const {
  return Seats_limit() < h.Get_num_seat();
}

bool Session::operator>(const Hall& h) const {
  return Seats_limit() > h.Get_num_seat();
}

ostream& operator<<(ostream& os, const Session& s) {
  os << "Session info\n";
  os << "Name of session film: " << s.film << "\n";
  if (s.hall) {
    os << "Hall: " << s.hall->Get_name() << "\n";
    os << "Number of Hall: " << s.hall->Get_num() << "\n";
  }
  if (s.date) {
    os << "Date: ";
    s.date->Print();
    os << "\n";
  }
  if (s.time_start) {
    os << "Time: ";
    s.time_start->Print();
    os << "\n";
  }
  return os;
}