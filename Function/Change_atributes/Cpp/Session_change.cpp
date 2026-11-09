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

void change_session_field(Collection<shared_ptr<Session>>& sessions,
                          Collection<shared_ptr<Hall>>& halls, int idx) {
  cout << "What to change?\n";
  cout << "1. Film name\n";
  cout << "2. Hall\n";
  cout << "3. Date\n";
  cout << "4. Start time\n";

  int sub = read_int("Choice: ");
  
  switch (sub) {
    case 1:
      sessions.at(idx)->in_film(read_string("New film name: "));
      cout << "Film name changed.\n";
      break;
    case 2: {
      show_halls_bigger_than(*sessions.at(idx), halls);
      int h = read_int("Hall index (or -1 to cancel): ");
      if (h == -1) break;

      sessions.at(idx)->can_change_hall(halls.at(h)); 
      sessions.at(idx)->in_hall(halls.at(h));
      
      cout << "Hall changed.\n";
      break;
    }
    case 3: {
      int y = read_int("Year: ");
      int m = read_int("Month: ");
      int d = read_int("Day: ");
      sessions.at(idx)->in_date(make_shared<Date>(y, m, d));
      cout << "Date changed.\n";
      break;
    }
    case 4: {
      int h = read_int("Hours: ");
      int m = read_int("Minutes: ");
      sessions.at(idx)->in_time_start(make_shared<Time>(h, m));
      cout << "Time changed.\n";
      break;
    }
    default:
      cout << "Invalid choice.\n";
  }
}