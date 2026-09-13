#pragma once
#include <memory>
#include <string>

#include "Class/Header/Hall.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"

class Session {
 private:
  std::string film;
  std::shared_ptr<Hall> hall;
  std::shared_ptr<Date> date;
  std::shared_ptr<Time> time_start;

 public:
  Session(const std::string& film,
          std::shared_ptr<Time> time_start,
          std::shared_ptr<Date> date,
          std::shared_ptr<Hall> hall);

  void In_film(const std::string& film_);
  void In_hall(std::shared_ptr<Hall> hall_);
  void In_time_start(std::shared_ptr<Time> time_start_);
  void In_date(std::shared_ptr<Date> date_);

  void Out_s() const;
  void Out_date() const;
  void Out_time() const;
  void Out_film() const;
  void Out_hall() const;

  std::string Get_film() const;
  std::shared_ptr<Hall> Get_hall() const;
  std::shared_ptr<Date> Get_date() const;
  std::shared_ptr<Time> Get_time_start() const;
};