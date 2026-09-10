#pragma once
#include <memory>
#include <vector>

using namespace std;

class Hall;

void Show_all_halls(const vector<shared_ptr<Hall>>& halls);
void Show_hall_names(const vector<shared_ptr<Hall>>& halls);