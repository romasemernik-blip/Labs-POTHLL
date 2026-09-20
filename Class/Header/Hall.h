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

  void In_num(int num);
  void In_num_seat(int num_seat);
  void In_name(const std::string_view& name_);

  void Out_num() const;
  void Out_num_seat() const;
  void Out_name() const;
  void Out_h() const;

  int Get_num() const;
  int Get_num_seat() const;
  std::string Get_name() const;

  friend std::ostream& operator<<(std::ostream& os, const Hall& h);
  friend std::istream& operator>>(std::istream& is, Hall& h);
};