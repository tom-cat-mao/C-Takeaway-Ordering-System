#pragma once
#ifndef _SEARCHFUZZYSALERECIPE_H
#define _SEARCHFUZZYSALERECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
//Fuzzy Search
// Search recipes in a recipe list
void FuzzySearchInRecipe(recipe* recipe_current, char* searchstr) 
{
    if (recipe_current == NULL)
    {
        return;
    }
    if (strstr(recipe_current->name, searchstr) != NULL)
    {
        printf("Found: %s\n", recipe_current->name);
    }

    FuzzySearchInRecipe(recipe_current->next, searchstr);
}
// Search recipes in different recipe lists of different classifies
void FuzzySearchInClassify(r_classify* classify_current, char* searchstr) 
{
    if (classify_current == NULL)
    {
        return;
    }
    printf("Classify: %s\n", classify_current->name);
    // Search recipes in current classify
    FuzzySearchInRecipe(classify_current->r_head, searchstr);

    //go tothe next classify to search recipe
    FuzzySearchInClassify(classify_current->next, searchstr);
}

//Sale Recipe Search
// Search sale recipes in a recipe list
void SaleRecipeSearchInRecipe(recipe* recipe_current)
{
    if (recipe_current == NULL)
    {
        return;
    }
    if (recipe_current->sale_discount != 1.0)
    {
        printf("Found: %s\n", recipe_current->name);
    }

    SaleRecipeSearchInRecipe(recipe_current->next);
}

// Search sale recipes in different recipe lists of different classifies
void SaleRecipeSearchInClassify(r_classify* classify_current)
{
    if (classify_current == NULL)
    {
        return;
    }
    printf("Classify: %s\n", classify_current->name);
    // Search recipes in current classify
    SaleRecipeSearchInRecipe(classify_current->r_head);

    //go tothe next classify to search recipe
    SaleRecipeSearchInClassify(classify_current->next);
}

#endif