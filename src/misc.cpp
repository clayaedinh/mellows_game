#include <algorithm>

#include "misc.hpp"

void toUpper(string *const str){
    transform(str->begin(), str->end(), str->begin(), ::toupper);
}