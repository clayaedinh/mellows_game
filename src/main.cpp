#include <iostream>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

#include "interpreter.hpp"
#include "room.hpp"
#include "registry.hpp"

using namespace std;

int main(){
    loadRegistries();
    InterpretResult result = INTERPRET_NULL;
    while (result != INTERPRET_QUIT){
        result = interpretNextCommand();
    }
}