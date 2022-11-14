#ifndef MELLOWS_COOKING_H
#define MELLOWS_COOKING_H

enum FoodName {
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


enum RecipeName {
    RECIPE_NULL,
    RECIPE_PASTA,
    RECIPE_BREAD,
    RECIPE_PIZZA,
    RECIPE_SIZEOF
};

void printFood(FoodName name);

FoodName cookRecipe(FoodName ingred_1, FoodName ingred_2, FoodName ingred_3);


#endif