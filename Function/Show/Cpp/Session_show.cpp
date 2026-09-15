#include "Function/Show/Header/Session_show.h"
#include "Class/Header/Session.h"
#include <iostream>

using namespace std;

void Show_all_sessions(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "]\n";
    sessions[i]->Out_s();
  }
}

void Show_session_films(const vector<shared_ptr<Session>>& sessions) {
  for (size_t i = 0; i < sessions.size(); ++i) {
    cout << "[" << i << "] " << sessions[i]->Get_film()
         << " (seats: " << sessions[i]->Seats_limit() << ")" << endl;
  }
}