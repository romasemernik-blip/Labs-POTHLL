#include "Function/Show/Header/Session_show.h"
#include "Class/Header/Hall.h" 
#include "Class/Header/Session.h"

#include <iostream>

using namespace std;

void Show_all_sessions(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "]\n";
    sessions[i]->Out_s();
     cout << "Seats: sold " << sessions[i]->Sold_seats()
         << " / " << sessions[i]->Seats_limit()
         << ", free " << sessions[i]->Free_seats() << endl;
  }
}

void Show_session_films(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "] " << sessions[i]->Get_film()
         << " | seats: " << sessions[i]->Sold_seats()
         << "/" << sessions[i]->Seats_limit()
         << " (free " << sessions[i]->Free_seats() << ")" << endl;
  }
}
void Show_halls_bigger_than(const Session& s,
                            const vector<shared_ptr<Hall>>& halls) {
  int current = s.Seats_limit();
  cout << "Current hall size: " << current << " seats\n";
  cout << "Halls with more seats:\n";

  bool any = false;
  for (size_t i = 0; i < halls.size(); ++i) {
    if (s < *halls[i]) {          
      cout << "[" << i << "] " << halls[i]->Get_name()
           << " - " << halls[i]->Get_num_seat() << " seats\n";
      any = true;
    }
  }
  if (!any) cout << "None.\n";
}