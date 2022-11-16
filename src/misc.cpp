#include <algorithm>

#include "misc.hpp"

void toUpper(std::string *const str){
    std::transform(str->begin(), str->end(), str->begin(), ::toupper);
}