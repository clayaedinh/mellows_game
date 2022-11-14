#include <iostream>

#include "cooking.hpp"


// ---------- FOODS ----------
struct Food{
    char name[16];
};

Food foods[] = {
    [FOOD_NULL] = {"NULL_FOOD"},
    [FOOD_FLOUR] = {"Flour"},
    [FOOD_PASTA] = {"Pasta"},
    [FOOD_YEAST] = {"Yeast"},
    [FOOD_BREAD] = {"Bread"},
    [FOOD_TOMATO] = {"Tomato"},
    [FOOD_CHEESE] = {"Cheese"},
    [FOOD_PIZZA] = {"Pizza"},
};

Food * getFood(FoodName name){
    return &foods[name];
}

void printFood(FoodName name){
    std::cout << (&foods[name])->name << "\n";
}

// ---------- FOOD TRIOS ----------
struct FoodTrio{
    FoodName one;
    FoodName two;
    FoodName three;
};

void printTrio(FoodTrio const* trio){
    std::cout   << getFood(trio->one)->name << " "
                << getFood(trio->two)->name << " "
                << getFood(trio->three)->name << "\n";
}

static bool trioEqual(FoodTrio * trio1, FoodTrio * trio2){
    return  (trio1->one == trio2->one) &&
            (trio1->two == trio2->two) &&
            (trio1->three == trio2->three);
}

// ---------- RECIPES ----------

struct Recipe {
    char name[16];
    FoodTrio ingredients;
    FoodName output;
};

Recipe recipes[] = {
    [RECIPE_NULL] = {"NULL_RECIPE", FOOD_NULL, FOOD_NULL, FOOD_NULL, FOOD_NULL},
    [RECIPE_PASTA] = {"Plain Pasta", FOOD_FLOUR, FOOD_NULL, FOOD_NULL, FOOD_PASTA},
    [RECIPE_BREAD] = {"Bread", FOOD_FLOUR, FOOD_YEAST, FOOD_NULL, FOOD_BREAD},
    [RECIPE_PIZZA] = {"Pizza", FOOD_CHEESE, FOOD_TOMATO, FOOD_BREAD, FOOD_PIZZA}
};


void printRecipe(Recipe const* recipe){
    std::cout << "Recipe " << recipe->name << "\n";
    printTrio(&recipe->ingredients);
}


// ---------- SORTING FOODS ----------
static void sortFoodTrio(FoodTrio * trio){
    FoodTrio temp;
    if (trio->one < trio->two){
        if (trio->one < trio->three){
            temp.one = trio->one;
            if (trio->two < trio->three){
                temp.two = trio->two;
                temp.three = trio->three;
            }else{
                temp.two = trio->three;
                temp.three = trio->two;
            }
        }else{
            temp.one = trio->three;
            temp.two = trio->one;
            temp.three = trio->two;
        }
    }else if (trio->two < trio->three){
        temp.one = trio->two;
        if (trio->one < trio->three){
            temp.two = trio->one;
            temp.three = trio->three;
        }else{
            temp.two = trio->three;
            temp.three = trio->one;
        }
    }else{
        temp.one = trio->three;
        temp.two = trio->two;
        temp.three = trio->one;
    }
    *trio = temp;
}

static bool recipeIngredientsSorted = false;

void sortRecipeIngredients(){
    if (recipeIngredientsSorted) return;
    for (int i = 1; i < RECIPE_SIZEOF; ++i){
        Recipe * recipe = &recipes[i];
        sortFoodTrio(&recipe->ingredients);
    }
    recipeIngredientsSorted = true;
}

// ---------- COOKING FOODS ----------

// Finds if a recipe if a permutation of the three provided ingredients
FoodName cookRecipe(FoodName ingred_1, FoodName ingred_2, FoodName ingred_3){
    sortRecipeIngredients();
    FoodTrio given_ingreds = {ingred_1, ingred_2, ingred_3};
    sortFoodTrio(&given_ingreds);

    for (int i = 1; i < RECIPE_SIZEOF; ++i){
            Recipe * recipe = &recipes[i];
            //printRecipe(recipe);
            if (trioEqual(&recipe->ingredients, &given_ingreds)) return recipe->output;            
    }
    
    return FOOD_NULL;
}