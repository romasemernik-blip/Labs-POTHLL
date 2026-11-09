#include "Function/Menu/Header/Hall_menu.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Change_atributes/Header/Hall_change.h"
#include "Exception/Header/All_exceptions.h"
#include <iostream>

using namespace std;

void menu_hall(Collection<shared_ptr<Hall>>& halls) {
  while (true) {
    try {
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
      halls.at(idx); 
      change_hall_field(halls, idx);
    }
  }
  catch (const Duplicate_Id_Exception& e)      { cout << "[SEAT BUSY] " << e.what() << "\n"; }
    catch (const Object_Not_Found_Exception& e)  { cout << "[NOT FOUND] " << e.what() << "\n"; }
    catch (const Limit_Exceeded_Exception& e)    { cout << "[LIMIT] " << e.what() << "\n"; }
    catch (const Out_Of_Range_Exception& e)      { cout << "[RANGE] " << e.what() << "\n"; }
    catch (const Invalid_Operation_Exception& e) { cout << "[BAD OP] " << e.what() << "\n"; }
    catch (const Relation_Exception& e)          { cout << "[RELATION] " << e.what() << "\n"; }
    catch (const Invalid_Data_Exception& e)      { cout << "[DATA] " << e.what() << "\n"; }
    catch (const Cinema_Exception& e)            { cout << "[ERROR] " << e.what() << "\n"; }
    catch (const std::exception& e)              { cout << "[STD] " << e.what() << "\n"; }
    catch (...)                                  { cout << "[UNKNOWN]\n"; }
}
}