#pragma once
#include <memory>
#include <string>
#include <iostream>

#include "Class/Header/Hall.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"

class Session {
 private:
  std::string film;
  std::shared_ptr<Hall> hall;
  std::shared_ptr<Date> date;
  std::shared_ptr<Time> time_start;
  int sold_seats_ = 0;

 public:
  Session(const std::string& film,
          std::shared_ptr<Time> time_start,
          std::shared_ptr<Date> date,
          std::shared_ptr<Hall> hall);

  void in_film(const std::string_view& film_);
  void in_hall(std::shared_ptr<Hall> hall_);
  void in_time_start(std::shared_ptr<Time> time_start_);
  void in_date(std::shared_ptr<Date> date_);
  int seats_limit() const;
  int sold_seats() const;
  int free_seats() const;

  bool sell_seat(); 
  void return_seat();
  
  void out_s() const;
  void out_date() const;
  void out_time() const;
  void out_film() const;
  void out_hall() const;

  std::string get_film() const;
  std::shared_ptr<Hall> get_hall() const;
  std::shared_ptr<Date> get_date() const;
  std::shared_ptr<Time> get_time_start() const;

  bool can_change_hall(const std::shared_ptr<Hall>& new_hall) const;

  friend std::ostream& operator<<(std::ostream& os, const Session& s);

  bool operator< (const Session& other) const;
  bool operator> (const Session& other) const;
  bool operator==(const Session& other) const;
  bool operator!=(const Session& other) const;

  bool operator< (const Hall& h) const;  
  bool operator> (const Hall& h) const;
};