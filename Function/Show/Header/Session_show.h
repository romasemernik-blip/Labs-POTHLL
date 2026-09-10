#pragma once
#include <memory>
#include <vector>

using namespace std;

class Session;

void Show_all_sessions(const vector<shared_ptr<Session>>& sessions);
void Show_session_films(const vector<shared_ptr<Session>>& sessions);