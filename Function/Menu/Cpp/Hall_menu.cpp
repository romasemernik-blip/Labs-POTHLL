#include "Function/Menu/Header/Hall_menu.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Change_atributes/Header/Hall_change.h"
#include "Exception/Header/All_exceptions.h"
#include <iostream>

using namespace std;

static void handle_hall_choice(int choice, Collection<shared_ptr<Hall>>& halls) {
    if (choice == 1) {
        show_all_halls(halls);
    } else if (choice == 2) {
        show_all_halls(halls);
        int idx = read_int("Enter hall index: ");
        halls.at(idx); 
        change_hall_field(halls, idx);
    } else {
        cout << "Invalid choice.\n";
    }
}

void menu_hall(Collection<shared_ptr<Hall>>& halls) {
  while (true) {
    try {
      cout << "\n HALL MENU\n1. Show all halls\n2. Change hall characteristics\n0. Back\n";
      int choice = read_int("Choice: ");
      if (choice == 0) return;
      
      handle_hall_choice(choice, halls); 
      
    }
    catch (const Out_Of_Range_Exception& e)      { cout << "[RANGE] " << e.what() << "\n"; }
    catch (const Invalid_Data_Exception& e)      { cout << "[DATA] " << e.what() << "\n"; }
    catch (const Cinema_Exception& e)            { cout << "[ERROR] " << e.what() << "\n"; }
  }
}