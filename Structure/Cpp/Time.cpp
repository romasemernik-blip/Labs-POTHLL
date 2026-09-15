#include "Structure/Header/Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m) : hour(h), minute(m) {
  if (hour < 0 || hour > 23) hour = 0;
  if (minute < 0 || minute > 59) minute = 0;
}

void Time::Print() const {
  cout << hour << ":";
  if (minute < 10) cout << "0";
  cout << minute;
}
bool Time::Set_hour(int h) {
  if (h < 0 || h > 23) {
    cout << "Error: hour must be in range 0..23.\n";
    return false;
  }
  hour = h;
  return true;
}
bool Time::Set_minute(int m) {
  if (m < 0 || m > 59) {
    cout << "Error: minute must be in range 0..59.\n";
    return false;
  }
  minute = m;
  return true;
}
