#ifndef MELLOWS_ROOM_HPP
#define MELLOWS_ROOM_HPP

#include <string>
#include <unordered_map>

#include "json.hpp"
using json = nlohmann::json;

#include "thing.hpp"

class Room{
    private:
    std::string name;
    std::string description;

    public:
    std::string getName();
    std::string view();
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Room, name, description)
};

#endif