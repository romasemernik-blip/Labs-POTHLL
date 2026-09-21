#include "Function/Change_atributes/Header/Session_change.h"
#include "Class/Header/Session.h"
#include "Class/Header/Hall.h"
#include "Structure/Header/Date.h"
#include "Structure/Header/Time.h"
#include "Function/Read/Header/Read.h"
#include "Function/Show/Header/Hall_show.h"
#include "Function/Show/Header/Session_show.h"
#include <iostream>

using namespace std;

void change_session_field(vector<shared_ptr<Session>>& sessions,
                          vector<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Film name\n";
  cout << "2. Hall\n";
  cout << "3. Date\n";
  cout << "4. Start time\n";

  int sub = read_int("Choice: ");
  switch (sub) {
    case 1:
      sessions[idx]->in_film(read_string("New film name: "));
      break;
   case 2: {
  show_halls_bigger_than(*sessions[idx], halls);
  int h = read_int("Hall index (or -1 to cancel): ");
  if (h == -1) break;
  sessions[idx]->in_hall(halls[h]);
  cout << "Hall changed.\n";
  break;
}
    case 3: {
      int y = read_int("Year: ");
      int m = read_int("Month: ");
      int d = read_int("Day: ");
      sessions[idx]->in_date(make_shared<Date>(y, m, d));
      break;
    }
    case 4: {
      int h = read_int("Hours: ");
      int m = read_int("Minutes: ");
      sessions[idx]->in_time_start(make_shared<Time>(h, m));
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}