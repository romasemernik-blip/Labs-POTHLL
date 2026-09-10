#include "Function/Read/Header/Read.h"
#include <iostream>

using namespace std;

int Read_int(const string& info) {
  int value;
  cout << info;
  cin >> value;
  return value;
}

float Read_float(const string& info) {
  float value;
  cout << info;
  cin >> value;
  return value;
}

string Read_string(const string& info) {
  cout << info;
  string s;
  cin >> s;
  return s;
}