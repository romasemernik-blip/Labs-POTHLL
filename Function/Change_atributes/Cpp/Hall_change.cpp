#include "Function/Change_atributes/Header/Hall_change.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include <iostream>

using namespace std;

void change_hall_field(vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Hall number\n";
  cout << "2. Number of seats\n";
  cout << "3. Name\n";

  int sub = read_int("Choice: ");
  switch (sub) {
    case 1: halls[idx]->in_num(read_int("New number: ")); break;
    case 2: halls[idx]->in_num_seat(read_int("New number of seats: ")); break;
    case 3: halls[idx]->in_name(read_string("New name: ")); break;
    default: cout << "Invalid choice.\n";
  }
}