#include <unordered_map>
#include <iostream>

#include "inventory.hpp"

using namespace std;

Item items[] = {
    [ITEM_NULL] = {ITEMTYPE_NULL, 0},
    [ITEM_BREAD] = {ITEMTYPE_FOOD, FOOD_BREAD},
    [ITEM_PASTA] = {ITEMTYPE_FOOD, FOOD_PASTA}
};

static unordered_map<ItemID, int> inventory;

void invAddItem(ItemID id, int amount){
    if (inventory.count(id)){
        inventory[id] += amount;
    }else{
        inventory[id] = amount;
    }    
}

void invAddItem(ItemID id){
    invAddItem(id, 1);
}

// pls double check this code, it feels iffy
int invRemoveItem(ItemID id, int amount){
    if (inventory.count(id)){
        if (amount >= inventory[id]){
            int remaining = inventory[id];
            inventory[id] = 0;
            return remaining;
        }else{
            inventory[id] -= amount;
            return amount;
        }
    }else{
        return 0;
    }        
}

int invRemoveItem(ItemID id){
    return invRemoveItem(id, 1);
}

bool invHasItem(ItemID id){
    return inventory.count(id);
}

int invItemCount(ItemID id){
    if (inventory.count(id)){
        return inventory[id];
    }else{
        return 0;
    }
}

Item * invGetItem(ItemID id){
    return &items[id];
}

string itemGetName(Item const* item){
    switch (item->type){
        case ITEMTYPE_FOOD:
            return foodGetName(item->food);
        case ITEMTYPE_NULL:
        default:
            return "";
    }
}

void printItem(ItemID id){
    Item * item = invGetItem(id);
    cout << itemGetName(item) << "\n";
}