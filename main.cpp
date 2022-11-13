#include <iostream>

#include "cooking.hpp"

int main(){
    //printFood(FOOD_CHEESE); 
    //printRecipe(RECIPE_PIZZA);
    printFood(tryCookRecipe(FOOD_FLOUR, FOOD_TOMATO, FOOD_CHEESE));
}