#include "Class/File/Header/File_validator.h"
#include "Exception/Header/All_exceptions.h"


using namespace std;

void File_Validator::validate_filename(string_view filename) {
    if (filename.empty()) {
        throw Invalid_Data_Exception("Filename cannot be empty");
    }
    
   if (string forbidden = R"(\/:*?"<>|)"; filename.find_first_of(forbidden) != string::npos) {
    throw Invalid_Data_Exception("Filename contains forbidden characters");
   }
   
    if (filename.length() < 5) {
        throw Invalid_Data_Exception("Filename is too short");
    }

    if (filename.substr(filename.length() - 4) != ".txt") {
        throw Invalid_Data_Exception("File must have .txt extension");
    }
}