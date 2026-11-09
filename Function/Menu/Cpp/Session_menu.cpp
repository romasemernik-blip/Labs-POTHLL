#include "Function/Menu/Header/Session_menu.h"
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Session_show.h"
#include "Function/Change_atributes/Header/Session_change.h"
#include <iostream>
#include "Exception/Header/All_exceptions.h"

using namespace std;

static void handle_session_choice(int choice, Collection<shared_ptr<Session>>& sessions, Collection<shared_ptr<Hall>>& halls) {
    if (choice == 1) {
        show_all_sessions(sessions);
    } else if (choice == 2) {
        show_session_films(sessions);
        int idx = read_int("Enter session index: ");
        sessions.at(idx);
        change_session_field(sessions, halls, idx);
    } else {
        cout << "Invalid choice.\n";
    }
}

void menu_session(Collection<shared_ptr<Session>>& sessions, Collection<shared_ptr<Hall>>& halls) {
  while (true) {
    try {
      cout << "\nSESSION MENU\n1. Show all sessions\n2. Change session characteristics\n0. Back\n";
      int choice = read_int("Choice: ");
      if (choice == 0) return;

      handle_session_choice(choice, sessions, halls);

    }
    catch (const Out_Of_Range_Exception& e)      { cout << "[RANGE] " << e.what() << "\n"; }
    catch (const Invalid_Data_Exception& e)      { cout << "[DATA] " << e.what() << "\n"; }
    catch (const Limit_Exceeded_Exception& e)    { cout << "[LIMIT] " << e.what() << "\n"; }
    catch (const Relation_Exception& e)          { cout << "[RELATION] " << e.what() << "\n"; }
    catch (const Cinema_Exception& e)            { cout << "[ERROR] " << e.what() << "\n"; }
    catch (...)                                  { cout << "[UNKNOWN ERROR]\n"; }
  }
}