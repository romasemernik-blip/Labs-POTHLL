#pragma once
#include <string>

using namespace std;

class Hall {
 private:
  int num;
  int num_seat;
  string name;

 public:
  Hall(int num, int num_seat, const string& name);

  void In_num(int num);
  void In_num_seat(int num_seat);
  void In_name(const string& name_);

  void Out_num() const;
  void Out_num_seat() const;
  void Out_name() const;
  void Out_h() const;

  int Get_num() const;
  int Get_num_seat() const;
  string Get_name() const;
};