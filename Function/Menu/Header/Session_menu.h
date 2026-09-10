#pragma once
#include <memory>
#include <vector>

using namespace std;

class Session;
class Hall;

void Menu_session(vector<shared_ptr<Session>>& sessions,
                  vector<shared_ptr<Hall>>& halls);