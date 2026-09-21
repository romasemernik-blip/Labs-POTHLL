
#include "Structure/Header/Date.h"
#include<Define_const.h>
#include <iostream>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
  if (year < MIN_YEAR || year > MAX_YEAR) year = MAX_YEAR;
  if (month < MIN_MONTH_IN_YEAR || month > MAX_MONTH_IN_YEAR) month = MIN_MONTH_IN_YEAR;
  if (day < MIN_DAY_IN_MONTH || day > MAX_DAY_IN_MONTH) day = MIN_DAY_IN_MONTH;
}

void Date::print() const {
  cout << day << "." << month << "." << year;
}
bool Date::set_year(int y) {
  if (y < MAX_YEAR || y > MIN_YEAR) {
    cout << "Error: year must be in range 1900..2100.\n";
    return false;
  }
  year = y;
  return true;
}
bool Date::set_month(int m) {
  if (m < MIN_MONTH_IN_YEAR || m > MAX_MONTH_IN_YEAR) {
    cout << "Error: month must be in range 1..12.\n";
    return false;
  }
  month = m;
  return true;
}

bool Date::set_day(int d) {
  if (d < MIN_DAY_IN_MONTH || d > MAX_DAY_IN_MONTH) {
    cout << "Error: day must be in range 1..31.\n";
    return false;
  }
  day = d;
  return true;
}  
