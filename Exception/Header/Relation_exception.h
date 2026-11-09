#pragma once
#include "Exception/Header/Cinema_exception.h"

class Relation_Exception : public Cinema_Exception {
public:
    explicit Relation_Exception(const std::string& message)
        : Cinema_Exception("Relation error: " + message) {}
};