
#include "Function/Read/Header/Read.h"
#include "Exception/Header/Invalid_data_exception.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int read_int(const string& info) {
    while (true) {
        try {
            cout << info;
            string input;
            if (!getline(cin >> ws, input)) {
                throw Invalid_Data_Exception("End of input reached");
            }
            if (input.empty()) {
                throw Invalid_Data_Exception("Input cannot be empty");
            }

            size_t pos = 0;
            int val = 0;
            try {
                val = stoi(input, &pos);
            } 
            catch (const invalid_argument&) {
                throw Invalid_Data_Exception("Expected an integer, but got text");
            } 
            catch (const out_of_range&) {
                throw Invalid_Data_Exception("Integer is out of allowed range");
            }
            if (pos != input.length()) {
                throw Invalid_Data_Exception("Input '" + input + "' contains invalid characters after number");
            }

            return val;
        }
        catch (const Invalid_Data_Exception& e) {
            cout << "[RETRY] " << e.what() << " - try again.\n";
        }
    }
}

float read_float(const string& info) {
    while (true) {
        try {
            cout << info;
            string input;
            if (!getline(cin >> ws, input)) {
                throw Invalid_Data_Exception("End of input reached");
            }
            if (input.empty()) {
                throw Invalid_Data_Exception("Input cannot be empty");
            }

            size_t pos = 0;
            float val = 0.0f;
            try {
                val = stof(input, &pos);
            } 
            catch (const invalid_argument&) {
                throw Invalid_Data_Exception("Expected a number, but got text");
            } 
            catch (const out_of_range&) {
                throw Invalid_Data_Exception("Number is out of allowed range");
            }

            if (pos != input.length()) {
                throw Invalid_Data_Exception("Input '" + input + "' contains invalid characters after number");
            }

            return val;
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