#ifndef MELLOWS_ROOM_HPP
#define MELLOWS_ROOM_HPP

#include <string>
#include <unordered_map>

#include "thing.hpp"

using namespace std;

class Room{
    private:
    string name;
    string description;

    public:
    string getName();
    string view();
};

#endif