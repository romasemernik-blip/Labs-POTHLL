#include "Function/Change_attributes/Header/Session_change.h"
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Class/Header/Date.h"
#include "Class/Header/Time.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include <iostream>

using namespace std;

void Change_session_field(vector<shared_ptr<Session>>& sessions,
                          vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Film name\n";
  cout << "2. Hall\n";
  cout << "3. Date\n";
  cout << "4. Start time\n";

  int sub = Read_int("Choice: ");
  switch (sub) {
    case 1:
      sessions[idx]->In_film(Read_string("New film name: "));
      break;
    case 2: {
      Show_hall_names(halls);
      int h = Read_int("Hall index: ");
      sessions[idx]->In_hall(halls[h]);
      break;
    }
    case 3: {
      int y = Read_int("Year: ");
      int m = Read_int("Month: ");
      int d = Read_int("Day: ");
      sessions[idx]->In_date(make_shared<Date>(y, m, d));
      break;
    }
    case 4: {
      int h = Read_int("Hours: ");
      int m = Read_int("Minutes: ");
      sessions[idx]->In_time_start(make_shared<Time>(h, m));
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}