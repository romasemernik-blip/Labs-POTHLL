#include "Function/Show/Header/Hall_show.h"
#include "Class/Header/Hall.h"
#include <iostream>

using namespace std;

void Show_all_halls(const vector<shared_ptr<Hall>>& halls) {
  for (size_t i = 0; i < halls.size(); ++i) {
    cout << "[" << i << "] ";
    halls[i]->Out_h();
  }
}

void Show_hall_names(const vector<shared_ptr<Hall>>& halls) {
  for (size_t i = 0; i < halls.size(); ++i) {
    cout << "[" << i << "] ";
    halls[i]->Out_name();
  }
}