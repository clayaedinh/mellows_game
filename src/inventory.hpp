#ifndef MELLOWS_INVENTORY_H
#define MELLOWS_INVENTORY_H

#include <memory>
#include <string>

#include "cooking.hpp"

using namespace std;

enum ItemType{
    ITEMTYPE_NULL,
    ITEMTYPE_FOOD,
};

struct Item{
    const ItemType type;
    union{
        const int null;
        const FoodVariant food;
    };
};

enum ItemID {
    ITEM_NULL,
    ITEM_BREAD,
    ITEM_PASTA,
    ITEM_SIZEOF
};


void invAddItem(ItemID id, int amount);
void invAddItem(ItemID id);
int invRemoveItem(ItemID id, int amount);
int invRemoveItem(ItemID id);
bool invHasItem(ItemID id);
int invItemCount(ItemID id);
Item * invGetItem(ItemID id);
void printItem(ItemID id);
#endif