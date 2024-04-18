#pragma once
#ifndef _SEARCHFUZZYSALERECIPE_H
#define _SEARCHFUZZYSALERECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"classTree.h"
//Fuzzy Search(for user)(Use List to search)
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

    //go to the next classify to search recipe
    FuzzySearchInClassify(classify_current->next, searchstr);
}

//Sale Recipe Search(for User&Merchant)(Use Tree to search)
//Search Sale recipe in one Merchant
//To use this function,you should first create a recipe* discounted_recipes[100] and int num_SaleRecipe=0
void SaleRecipeSearch(t_recipe* root, recipe** SaleRecipeArray, int* num_SaleRecipe)
{
    if (root == NULL) 
    {
        return;
    }
    //Recurve the left child Tree
    SaleRecipeSearch(root->left, SaleRecipeArray, num_SaleRecipe);

    //if searched one, put it into the recipe** SaleRecipeArray
    if (root->r_node != NULL && root->r_node->sale_discount != 1.0) 
    {
        SaleRecipeArray[*num_SaleRecipe] = root->r_node;
        (*num_SaleRecipe)++;
    }

    //Recurve the right child Tree
    SaleRecipeSearch(root->right, SaleRecipeArray, num_SaleRecipe);
}

#endif