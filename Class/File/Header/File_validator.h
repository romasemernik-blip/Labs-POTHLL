#pragma once
#include <string>
#include <string_view>

class File_Validator {
public:
    static void validate_filename(std::string_view filename);
};