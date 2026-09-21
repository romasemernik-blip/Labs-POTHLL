#pragma once

struct Time {
  int hour;
  int minute;

  Time(int h, int m);
  void print() const;

  bool set_hour(int h);
  bool set_minute(int m);
};