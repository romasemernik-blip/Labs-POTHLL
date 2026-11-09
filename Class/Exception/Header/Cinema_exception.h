#pragma once
#include <stdexcept>
#include <string>

class Cinema_Exception : public std::runtime_error {
public:
    explicit Cinema_Exception(const std::string& message)
        : std::runtime_error(message) {}
};