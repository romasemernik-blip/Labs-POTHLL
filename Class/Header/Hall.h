#pragma once
#include <string>
#include <iostream>

class Hall {
 private:
  int num;
  int num_seat;
  std::string name;

 public:
  Hall(int num, int num_seat, const std::string& name);

  void in_num(int num);
  void in_num_seat(int num_seat);
  void in_name(const std::string_view& name_);

  void out_num() const;
  void out_num_seat() const;
  void out_name() const;
  void out_h() const;

  int get_num() const;
  int get_num_seat() const;
  std::string get_name() const;

  friend std::ostream& operator<<(std::ostream& os, const Hall& h);
  friend std::istream& operator>>(std::istream& is, Hall& h);
};