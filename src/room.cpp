#include "registry.hpp"
#include "room.hpp"


std::string Room::getName(){
    return name;
}

std::string Room::view(){
    return description;
}

std::string commandRoomView(std::string room_name){
    Room * room = registryFindRoom(room_name);
    if (room == NULL){
        return "Room not found.";
    }else{
        return room->view();
    }
}
