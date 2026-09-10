#include "Function/Change_attributes/Header/Hall_change.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include <iostream>

using namespace std;

void Change_hall_field(vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Hall number\n";
  cout << "2. Number of seats\n";
  cout << "3. Name\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1: halls[idx]->In_num(Read_int("New number: ")); break;
    case 2: halls[idx]->In_num_seat(Read_int("New number of seats: ")); break;
    case 3: halls[idx]->In_name(Read_string("New name: ")); break;
    default: cout << "Invalid choice.\n";
  }
}