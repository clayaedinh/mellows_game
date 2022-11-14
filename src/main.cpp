#include <iostream>

#include "cooking.hpp"
#include "inventory.hpp"

using namespace std;

int main(){
    //printFood(cookRecipe(FOOD_FLOUR, FOOD_YEAST, FOOD_NULL));
    //printFood(cookRecipe(FOOD_FLOUR, FOOD_NULL, FOOD_NULL));
    printItem(ITEM_BREAD);
    printItem(ITEM_PASTA);
}