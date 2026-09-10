#include "Structure/Header/Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m) : hour(h), minute(m) {}

void Time::Print() const {
  cout << hour << ":";
  if (minute < 10) cout << "0";
  cout << minute;
}