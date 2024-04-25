﻿#pragma once
#ifndef _SEARCHFUZZYSALERECIPE_H
#define _SEARCHFUZZYSALERECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"classTree.h"
#include "interface.h"
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
        if (recipe_current->sale_discount != 1.0)
        {
            printf("\tName: ");
            colour(3);
            printf("%s\n", recipe_current->name);
            colour(7);
        }
        else
        {
            printf("\tName: %s\n", recipe_current->name);
        }
        printf("\tStars: ");
        for (int i = 0; i < recipe_current->star; i++)
        {
            colour(6);
            printf("*");
            colour(7);
        }
        printf("\tPrice: %.2f\n", recipe_current->price);
        printf("        --------------------------------------------\n");
        
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
    printf("Class: %s\n", classify_current->name);
    printf("        --------------------------------------------\n");
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
        printf("\tName: ");
        colour(3);
        printf("%s\n", root->r_node->name);
        colour(7);
        printf("\tStars: ");
        for (int i = 0; i < root->r_node->star; i++)
        {
            colour(6);
            printf("*");
            colour(7);
        }
        printf("\tPrice: %.2f\n", root->r_node->price);
        printf("        --------------------------------------------\n");
    }

    //Recurve the right child Tree
    SaleRecipeSearch(root->right);
}

#endif
