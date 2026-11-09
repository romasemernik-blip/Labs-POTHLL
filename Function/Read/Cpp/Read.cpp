#include "Function/Read/Header/Read.h"
#include <iostream>
#include "Exception/Header/Invalid_data_exception.h"
#include <limits>

using namespace std;

int read_int(const string& info) {
  while (true) {
    try {
      int v;
      cout << info;
      if (cin >> v) return v;
      if (cin.eof()) throw Invalid_Data_Exception("End of input reached");
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      throw Invalid_Data_Exception("Expected an integer");
    } catch (const Invalid_Data_Exception& e) {
      cout << "[RETRY] " << e.what() << " - try again.\n";
    }
  }
}

float read_float(const string& info) {
  while (true) {
    try {
      float v;
      cout << info;
      if (cin >> v) return v;
      
     if (cin.eof()) throw Invalid_Data_Exception("End of input reached");
      
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      throw Invalid_Data_Exception("Expected a number");
    } 
    catch (const Invalid_Data_Exception& e) {
      cout << "[RETRY] " << e.what() << " - try again.\n";
    }
  }
}

string read_string(const string& info) {
  cout << info;
  string s;
  if (!std::getline(cin >> std::ws, s)) s.clear();
  return s;
}