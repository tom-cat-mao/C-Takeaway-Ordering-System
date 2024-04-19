#pragma once
#ifndef _SEARCHFUZZYSALERECIPE_H
#define _SEARCHFUZZYSALERECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"classTree.h"
//Fuzzy Search(for user)(Use List to search)
// Search recipes in a recipe list
void FuzzySearchInRecipe(recipe* recipe_current, char* searchname) 
{
    if (recipe_current == NULL)
    {
        return;
    }
    if (strstr(recipe_current->name, searchname) != NULL)
    {
        printf("Found: %s\n", recipe_current->name);
    }

    FuzzySearchInRecipe(recipe_current->next, searchname);
}
// Search recipes in different recipe lists of different classifies
void FuzzySearchInClassify(r_classify* classify_current, char* searchname)
{
    if (classify_current == NULL)
    {
        return;
    }
    printf("Classify: %s\n", classify_current->name);
    // Search recipes in current classify
    FuzzySearchInRecipe(classify_current->r_head, searchname);

    //go to the next classify to search recipe
    FuzzySearchInClassify(classify_current->next, searchname);
}

//Sale Recipe Search(for User&Merchant)
//Search Sale recipe in one Merchant
void SaleRecipeSearch(t_recipe* root)
{
    if (root == NULL) 
    {
        return;
    }
    //Recurve the left child Tree
    SaleRecipeSearch(root->left);

   
    if (root->r_node != NULL && root->r_node->sale_discount != 1.0) 
    {
        printf("%s\n", root->r_node->name);
    }

    //Recurve the right child Tree
    SaleRecipeSearch(root->right);
}

#endif