#include "Class/Header/Hall.h"
#include "Exception/Header/Invalid_data_exception.h"
#include <iostream>

using namespace std;

Hall::Hall(int num, int num_seat, const string& name) : num(num), num_seat(num_seat), name(name) {
  if (num < 0) throw Invalid_Data_Exception("Hall number cannot be negative");
  if (num_seat < 1) throw Invalid_Data_Exception("Seats count must be >= 1");
  if (name.empty()) throw Invalid_Data_Exception("Hall name cannot be empty");
}

void Hall::in_num(int n) { 
    if (n < 0) throw Invalid_Data_Exception("Hall number cannot be negative"); 
    num = n; 
}

void Hall::in_num_seat(int n) { 
    if (n < 1) throw Invalid_Data_Exception("Seats count must be >= 1"); 
    num_seat = n; 
}

void Hall::in_name(const string_view& n) { 
    if (n.empty()) throw Invalid_Data_Exception("Hall name cannot be empty"); 
    name = n; 
}

void Hall::out_num() const { cout << "Number of Hall: " << num << endl; }
void Hall::out_num_seat() const { cout << "Number of seats: " << num_seat << endl; }
void Hall::out_name() const { cout << "Name of Hall: " << name << endl; }

void Hall::out_h() const {
  cout << "Hall:" << endl;
  out_num();
  out_num_seat();
  out_name();
  cout << endl;
}

int Hall::get_num() const { return num; }
int Hall::get_num_seat() const { return num_seat; }
string Hall::get_name() const { return name; }

ostream& operator<<(ostream& os, const Hall& h) {
  os << "Hall:\n"
     << "Number of Hall: " << h.num << "\n"
     << "Number of seats: " << h.num_seat << "\n"
     << "Name of Hall: " << h.name << "\n";
  return os;
}

istream& operator>>(istream& is, Hall& h) {
    cout << "Number of Hall: ";  is >> h.num;
    cout << "Number of seats: "; is >> h.num_seat;
    cout << "Name of Hall: ";    is >> h.name;
    
    if (is.fail()) throw Invalid_Data_Exception("Invalid input format for Hall");
    if (h.num < 0 || h.num_seat < 1 || h.name.empty()) 
        throw Invalid_Data_Exception("Invalid Hall data entered");
    return is;
}