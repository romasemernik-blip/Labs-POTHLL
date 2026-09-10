#pragma once
#include <memory>
#include <vector>

using namespace std;

class Session;
class Hall;

void Change_session_field(vector<shared_ptr<Session>>& sessions,
                          vector<shared_ptr<Hall>>& halls,
                          int idx);