#include "Function/Menu/Header/Hall_menu.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Change_atributes/Header/Hall_change.h"
#include <iostream>

using namespace std;

void menu_hall(vector<shared_ptr<Hall>>& halls) {
  while (true) {
    cout << "\n HALL MENU\n";
    cout << "1. Show all halls\n";
    cout << "2. Change hall characteristics\n";
    cout << "0. Back\n";

    int choice = read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      show_all_halls(halls);
    } else if (choice == 2) {
      show_all_halls(halls);
      int idx = read_int("Enter hall index: ");
      change_hall_field(halls, idx);
    }
  }
}