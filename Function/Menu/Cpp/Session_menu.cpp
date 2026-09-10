#include "Function/Menu/Header/Session_menu.h"
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Session_show.h"
#include "Function/Change_atributes/Header/Session_change.h"
#include <iostream>

using namespace std;

void Menu_session(vector<shared_ptr<Session>>& sessions,
                  vector<shared_ptr<Hall>>& halls) {
  while (true) {
    cout << "\n=== SESSION MENU ===\n";
    cout << "1. Show all sessions\n";
    cout << "2. Change session characteristics\n";
    cout << "0. Back\n";

    int choice = Read_int("Choice: ");

    if (choice == 0) return;
    if (choice == 1) {
      Show_all_sessions(sessions);
    } else if (choice == 2) {
      Show_session_films(sessions);
      int idx = Read_int("Enter session index: ");
      Change_session_field(sessions, halls, idx);
    }
  }
}