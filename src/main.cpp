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
    InterpretResult result;
    while (result != INTERPRET_QUIT){
        result = interpretNextCommand();
    }
    
    /*Room * room = findRoom("ROOM1");
    cout << room->getName() << "\n" << room->view() << "\n";
    cout << "YO! gabbagabba\n";
    */
}