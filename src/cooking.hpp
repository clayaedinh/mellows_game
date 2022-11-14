#ifndef MELLOWS_COOKING_H
#define MELLOWS_COOKING_H

#include <string>

using namespace std;

enum FoodVariant {
    FOOD_NULL,
    FOOD_FLOUR,
    FOOD_PASTA,
    FOOD_YEAST,
    FOOD_BREAD,
    FOOD_TOMATO,
    FOOD_CHEESE,
    FOOD_PIZZA,
    FOOD_SIZEOF // always last!
};


enum RecipeVariant {
    RECIPE_NULL,
    RECIPE_PASTA,
    RECIPE_BREAD,
    RECIPE_PIZZA,
    RECIPE_SIZEOF
};

void printFood(FoodVariant variant);
string foodGetName(FoodVariant variant);

FoodVariant cookRecipe(FoodVariant ingred_1, FoodVariant ingred_2, FoodVariant ingred_3);


#endif