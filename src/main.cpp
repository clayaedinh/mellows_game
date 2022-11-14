#include <iostream>

#include "cooking.hpp"

int main(){
    printFood(cookRecipe(FOOD_FLOUR, FOOD_YEAST, FOOD_NULL));
    printFood(cookRecipe(FOOD_FLOUR, FOOD_NULL, FOOD_NULL));
}