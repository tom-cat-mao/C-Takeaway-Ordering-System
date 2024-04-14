#pragma once
#ifndef _FUZZYSEARCH_H
#define _FUZZYSEARCH_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Search recipes in recipe list
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

// Search recipes in recipe list of different classifies
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




#endif