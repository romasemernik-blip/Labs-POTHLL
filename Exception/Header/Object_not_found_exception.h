#pragma once
#include "Exception/Header/Cinema_exception.h"

class Object_Not_Found_Exception : public Cinema_Exception {
public:
    explicit Object_Not_Found_Exception(const std::string& message)
        : Cinema_Exception("Object not found: " + message) {}
};