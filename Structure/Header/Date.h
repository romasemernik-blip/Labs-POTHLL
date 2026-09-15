#pragma once

struct Date {
  int year;
  int month;
  int day;

  Date(int y, int m, int d);
  void Print() const;

  bool Set_year(int y);
  bool Set_month(int m);
  bool Set_day(int d);
};