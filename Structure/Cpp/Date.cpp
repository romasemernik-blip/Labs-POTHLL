#include "Structure/Header/Date.h"
#include <iostream>

using namespace std;

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

void Date::Print() const {
  cout << day << "." << month << "." << year;
}