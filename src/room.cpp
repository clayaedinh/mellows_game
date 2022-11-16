#include "registry.hpp"
#include "room.hpp"


std::string Room::getName(){
    return name;
}

std::string Room::view(){
    return description;
}

std::string commandRoomView(std::string room_name){
    return registryFindRoom(room_name)->view();
}
