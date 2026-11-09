#pragma once
#include "Exception/Header/Cinema_exception.h"

class Invalid_Data_Exception : public Cinema_Exception {
public:
    explicit Invalid_Data_Exception(const std::string& message)
        : Cinema_Exception("Invalid data: " + message) {}
};