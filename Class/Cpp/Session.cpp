#include "Class/Header/Session.h"
#include <iostream>

using namespace std;

Session::Session(const string& film, shared_ptr<Time> time_start,
                 shared_ptr<Date> date, shared_ptr<Hall> hall)
    : film(film), hall(hall), date(date), time_start(time_start) {}

void Session::in_film(const string_view& film_) { film = film_; }
void Session::in_hall(shared_ptr<Hall> hall_) { hall = hall_; }
void Session::in_time_start(shared_ptr<Time> time_start_) { time_start = time_start_; }
void Session::in_date(shared_ptr<Date> date_) { date = date_; }

int Session::seats_limit() const {
  if (hall) return hall->get_num_seat();
  return 0;
}
int Session::sold_seats() const {
  return sold_seats_;
}
int Session::free_seats() const {
  int free = seats_limit() - sold_seats_;
  return free < 0 ? 0 : free;
}
bool Session::sell_seat() {
  if (sold_seats_ >= seats_limit()) {
    return false;  
    }
  ++sold_seats_;
  return true;
}  
void Session::return_seat() {
  if (sold_seats_ > 0) --sold_seats_;
}

void Session::out_s() const {
  cout << "Session info" << endl;
  out_film();
  out_hall();
  out_date();
  out_time();
  cout << endl;
}

void Session::out_date() const {
  if (!date) return;
  cout << "Date:";
  date->print();
  cout << endl;
}

void Session::out_time() const {
  if (!time_start) return;
  cout << "Time:";
  time_start->print();
  cout << endl;
}

void Session::out_film() const {
  cout << "Name of session film: " << film << endl;
}

void Session::out_hall() const {
  if (!hall) return;
  hall->out_name();
  hall->out_num();
}

string Session::get_film() const { return film; }
shared_ptr<Hall> Session::get_hall() const { return hall; }
shared_ptr<Date> Session::get_date() const { return date; }
shared_ptr<Time> Session::get_time_start() const { return time_start; }

bool Session::can_change_hall(const shared_ptr<Hall>& new_hall) const {
  if (!new_hall) {
    cout << "Error: new hall is null.\n";
    return false;
  }
  if (!hall) {
    cout << "Error: current hall is null.\n";
    return false;
  }
  if (new_hall->get_num_seat() < hall->get_num_seat()) {
    cout << "Error: new hall has only " << new_hall->get_num_seat()
         << " seats, but current hall has " << hall->get_num_seat()
         << " seats. New hall must be at least as large.\n";
    return false;
  }
  return true;
}

bool Session::operator<(const Session& other) const {
  return seats_limit() < other.seats_limit();
}

bool Session::operator>(const Session& other) const {
  return other < *this;
}

bool Session::operator==(const Session& other) const {
  return seats_limit() == other.seats_limit();
}

bool Session::operator!=(const Session& other) const {
  return !(*this == other);
}

bool Session::operator<(const Hall& h) const {
  return seats_limit() < h.get_num_seat();
}

bool Session::operator>(const Hall& h) const {
  return seats_limit() > h.get_num_seat();
}

ostream& operator<<(ostream& os, const Session& s) {
  os << "Session info\n";
  os << "Name of session film: " << s.film << "\n";
  if (s.hall) {
    os << "Hall: " << s.hall->get_name() << "\n";
    os << "Number of Hall: " << s.hall->get_num() << "\n";
  }
  if (s.date) {
    os << "Date: ";
    s.date->print();
    os << "\n";
  }
  if (s.time_start) {
    os << "Time: ";
    s.time_start->print();
    os << "\n";
  }
  return os;
}