#include "Class/Header/Session.h"
#include <iostream>

using namespace std;

Session::Session(const string& film, shared_ptr<Time> time_start,
                 shared_ptr<Date> date, shared_ptr<Hall> hall)
    : film(film), hall(hall), date(date), time_start(time_start) {}

void Session::In_film(const string& film_) { film = film_; }
void Session::In_hall(shared_ptr<Hall> hall_) { hall = hall_; }
void Session::In_time_start(shared_ptr<Time> time_start_) { time_start = time_start_; }
void Session::In_date(shared_ptr<Date> date_) { date = date_; }

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