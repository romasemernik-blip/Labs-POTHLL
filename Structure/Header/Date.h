#pragma once

struct Date {
  int year;
  int month;
  int day;

  Date(int y, int m, int d);
  void Print() const;
};