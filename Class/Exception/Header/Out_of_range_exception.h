#pragma once
#include "Exception/Header/Cinema_exception.h"

class Out_Of_Range_Exception : public Cinema_Exception {
public:
    explicit Out_Of_Range_Exception(const std::string& message)
        : Cinema_Exception("Out of range: " + message) {}
};