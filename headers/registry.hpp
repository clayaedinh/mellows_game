#ifndef MELLOWS_REGISTRY_HPP
#define MELLOWS_REGISTRY_HPP

#include <memory>
#include <string>


#include "room.hpp"

/*
REGISTRY loads objects from .json files, and then maps them to strings so
that they are easily accessible to the rest of the game.
*/


void loadRegistries();

Room * registryFindRoom(std::string id);

#endif