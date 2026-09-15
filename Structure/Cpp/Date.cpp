#include "Structure/Header/Date.h"
#include <iostream>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
  if (year < 1900 || year > 2100) year = 2000;
  if (month < 1 || month > 12) month = 1;
  if (day < 1 || day > 31) day = 1;
}

void Date::Print() const {
  cout << day << "." << month << "." << year;
}
bool Date::Set_year(int y) {
  if (y < 1900 || y > 2100) {
    cout << "Error: year must be in range 1900..2100.\n";
    return false;
  }
  year = y;
  return true;
}
bool Date::Set_month(int m) {
  if (m < 1 || m > 12) {
    cout << "Error: month must be in range 1..12.\n";
    return false;
  }
  month = m;
  return true;
}

bool Date::Set_day(int d) {
  if (d < 1 || d > 31) {
    cout << "Error: day must be in range 1..31.\n";
    return false;
  }
  day = d;
  return true;
}  
