#include "Function/Read/Header/Read.h"
#include <iostream>

using namespace std;

int read_int(const string& info) {
  int value;
  cout << info;
  cin >> value;
  return value;
}

float read_float(const string& info) {
  float value;
  cout << info;
  cin >> value;
  return value;
}

string read_string(const string& info) {
  cout << info;
  string s;
  cin >> s;
  return s;
}