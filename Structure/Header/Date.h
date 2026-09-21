#pragma once

struct Date {
  int year;
  int month;
  int day;

  Date(int y, int m, int d);
  void print() const;

  bool set_year(int y);
  bool set_month(int m);
  bool set_day(int d);
};