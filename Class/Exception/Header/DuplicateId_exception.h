#pragma once
#include "Exception/Header/Cinema_exception.h"

class Duplicate_Id_Exception : public Cinema_Exception {
public:
    explicit Duplicate_Id_Exception(const std::string& message)
        : Cinema_Exception("Duplicate ID: " + message) {}
};