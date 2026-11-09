#include "Structure/Header/Time.h"
#include<Define_const.h>
#include "Exception/Header/Invalid_data_exception.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m) : hour(h), minute(m) {
  if (h < MIN_HOUR_IN_DAY || h > MAX_HOUR_IN_DAY) throw Invalid_Data_Exception("Hour out of range");
  if (m < MIN_MINUTE_IN_HOUR || m > MAX_MINUTE_IN_HOUR) throw Invalid_Data_Exception("Minute out of range");
}

void Time::print() const {
  cout << hour << ":";
  if (minute < ADD_0_TO_MINUTE) cout << "0";
  cout << minute;
}
bool Time::set_hour(int h) {
  if (h < MIN_HOUR_IN_DAY || h > MAX_HOUR_IN_DAY) {
    throw Invalid_Data_Exception("Hour " + std::to_string(h) + " out of range 0..23");
  }
  hour = h;
  return true;
}
bool Time::set_minute(int m) {
  if (m < MIN_MINUTE_IN_HOUR || m > MAX_MINUTE_IN_HOUR) {
    throw Invalid_Data_Exception("Minute " + std::to_string(m) + " out of range 0..59");
  }
  minute = m;
  return true;
}
