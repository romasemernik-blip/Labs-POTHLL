#include "Class/Header/Hall.h"
#include <iostream>

using namespace std;

Hall::Hall(int num, int num_seat, const string& name)
    : num(num), num_seat(num_seat), name(name) {}

void Hall::In_num(int num) { this->num = num; }
void Hall::In_num_seat(int num_seat) { this->num_seat = num_seat; }
void Hall::In_name(const string_view& name_) { name = name_; }

void Hall::Out_num() const { cout << "Number of Hall: " << num << endl; }
void Hall::Out_num_seat() const { cout << "Number of seats: " << num_seat << endl; }
void Hall::Out_name() const { cout << "Name of Hall: " << name << endl; }

void Hall::Out_h() const {
  cout << "Hall:" << endl;
  Out_num();
  Out_num_seat();
  Out_name();
  cout << endl;
}

int Hall::Get_num() const { return num; }
int Hall::Get_num_seat() const { return num_seat; }
string Hall::Get_name() const { return name; }