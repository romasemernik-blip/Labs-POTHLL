#include "Function/Show/Header/Session_show.h"
#include "Class/Header/Hall.h" 
#include "Class/Header/Session.h"

#include <iostream>

using namespace std;

void show_all_sessions(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "]\n";
    sessions[i]->out_s();
     cout << "Seats: sold " << sessions[i]->sold_seats()
         << " / " << sessions[i]->seats_limit()
         << ", free " << sessions[i]->free_seats() << endl;
  }
}

void show_session_films(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "] " << sessions[i]->get_film()
         << " | seats: " << sessions[i]->sold_seats()
         << "/" << sessions[i]->seats_limit()
         << " (free " << sessions[i]->free_seats() << ")" << endl;
  }
}
void show_halls_bigger_than(const Session& s,
                            const vector<shared_ptr<Hall>>& halls) {
  int current = s.seats_limit();
  cout << "Current hall size: " << current << " seats\n";
  cout << "Halls with more seats:\n";

  bool any = false;
  for (size_t i = 0; i < halls.size(); ++i) {
    if (s < *halls[i]) {          
      cout << "[" << i << "] " << halls[i]->get_name()
           << " - " << halls[i]->get_num_seat() << " seats\n";
      any = true;
    }
  }
  if (!any) cout << "None.\n";
}