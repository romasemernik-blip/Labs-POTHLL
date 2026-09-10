#pragma once

struct Time {
  int hour;
  int minute;

  Time(int h, int m);
  void Print() const;
};