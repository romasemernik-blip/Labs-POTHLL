#include "Structure/Header/Time.h"
#include<Define_const.h>
#include <iostream>

using namespace std;

Time::Time(int h, int m) : hour(h), minute(m) {
  if (hour < MIN_HOUR_IN_DAY || hour > MAX_HOUR_IN_DAY) hour = MIN_HOUR_IN_DAY;
  if (minute < MIN_MINUTE_IN_HOUR || minute > MAX_MINUTE_IN_HOUR) minute = MIN_MINUTE_IN_HOUR;
}

void Time::Print() const {
  cout << hour << ":";
  if (minute < ADD_0_TO_MINUTE) cout << "0";
  cout << minute;
}
bool Time::Set_hour(int h) {
  if (h < MIN_HOUR_IN_DAY || h > MAX_HOUR_IN_DAY) {
    cout << "Error: hour must be in range 0..23.\n";
    return false;
  }
  hour = h;
  return true;
}
bool Time::Set_minute(int m) {
  if (m < MIN_MINUTE_IN_HOUR || m > MAX_MINUTE_IN_HOUR) {
    cout << "Error: minute must be in range 0..59.\n";
    return false;
  }
  minute = m;
  return true;
}
