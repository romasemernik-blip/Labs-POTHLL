
#include "Structure/Header/Date.h"
#include<Define_const.h>
#include "Exception/Header/Invalid_data_exception.h"
#include <iostream>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
  if (y < MIN_YEAR || y > MAX_YEAR) throw Invalid_Data_Exception("Year out of range");
  if (m < MIN_MONTH_IN_YEAR || m > MAX_MONTH_IN_YEAR) throw Invalid_Data_Exception("Month out of range");
  if (d < MIN_DAY_IN_MONTH || d > MAX_DAY_IN_MONTH) throw Invalid_Data_Exception("Day out of range");
}

void Date::print() const {
  cout << day << "." << month << "." << year;
}
bool Date::set_year(int y) {
  if (y < MIN_YEAR || y > MAX_YEAR) throw Invalid_Data_Exception("Year out of range");
  year = y; return true;
}
bool Date::set_month(int m) {
  if (m < MIN_MONTH_IN_YEAR || m > MAX_MONTH_IN_YEAR) {
    throw Invalid_Data_Exception("Month " + std::to_string(m) + " out of range 1..12");
  }
  month = m;
  return true;
}
bool Date::set_day(int d) {
  if (d < MIN_DAY_IN_MONTH || d > MAX_DAY_IN_MONTH) {
    throw Invalid_Data_Exception("Day " + std::to_string(d) + " out of range 1..31");
  }
  day = d;
  return true;
}
