#pragma once
#include "Exception/Header/Cinema_exception.h"

class Invalid_Operation_Exception : public Cinema_Exception {
public:
    explicit Invalid_Operation_Exception(const std::string& message)
        : Cinema_Exception("Invalid operation: " + message) {}
};