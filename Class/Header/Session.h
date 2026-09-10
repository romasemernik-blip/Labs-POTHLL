#pragma once
#include <memory>
#include <string>

#include "Class/Header/Hall.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"


using namespace std;

class Session {
 private:
  string film;
  shared_ptr<Hall> hall;
  shared_ptr<Date> date;
  shared_ptr<Time> time_start;

 public:
  Session(const string& film,
          shared_ptr<Time> time_start,
          shared_ptr<Date> date,
          shared_ptr<Hall> hall);

  void In_film(const string& film_);
  void In_hall(shared_ptr<Hall> hall_);
  void In_time_start(shared_ptr<Time> time_start_);
  void In_date(shared_ptr<Date> date_);

  void Out_s() const;
  void Out_date() const;
  void Out_time() const;
  void Out_film() const;
  void Out_hall() const;

  string Get_film() const;
  shared_ptr<Hall> Get_hall() const;
  shared_ptr<Date> Get_date() const;
  shared_ptr<Time> Get_time_start() const;
};