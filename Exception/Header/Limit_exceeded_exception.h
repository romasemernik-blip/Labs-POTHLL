#pragma once
#include "Exception/Header/Cinema_exception.h"

class Limit_Exceeded_Exception : public Cinema_Exception {
public:
    explicit Limit_Exceeded_Exception(const std::string& message)
        : Cinema_Exception("Limit exceeded: " + message) {}
};