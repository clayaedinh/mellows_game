
#include <fstream>
#include <unordered_map>
#include "json.hpp"
#include "misc.hpp"
#include "registry.hpp"

using namespace std;
using json = nlohmann::json;

template <typename T>
using Registry = unordered_map<string, T>;

const string json_path = "assets/json/";

// ------ REGISTRIES LIST ------

Registry<Room> registryRoom;

// ------ REGISTRY LOADING ------

template <typename T>
void loadRegistry(string fname, Registry<T> & registry){
    ifstream f(json_path + fname);
    json j = json::parse(f);

    for (auto& obj : j.items()){
        registry[obj.key()] = obj.value().get<T>();
    }
}

void loadRegistries(){
    loadRegistry<Room>("room.json", registryRoom);
}

// ------ REGISTRY ACCESS ------
template <typename T>
T * registryFind(string id, Registry<T> * registry){
    toUpper(&id);
    if (registry->count(id)){
        return &registry->at(id);
    }else{
        return NULL;
    }
}

Room * registryFindRoom(string id) {
    return registryFind<Room>(id, &registryRoom);
}
