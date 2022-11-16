
#include <fstream>
#include <unordered_map>
#include "json.hpp"
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

Room * findRoom(string id) {return &registryRoom[id];}
