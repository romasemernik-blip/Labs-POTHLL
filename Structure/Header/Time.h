#pragma once

struct Time {
  int hour;
  int minute;

  Time(int h, int m);
  void Print() const;

  bool Set_hour(int h);
  bool Set_minute(int m);
};