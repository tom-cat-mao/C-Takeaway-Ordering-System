#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"mergeSortRecipe.h"
#include"interface.h"
bool output_recipe_high_to_low(r_classify* r_classify_head, float min_price, float max_price)
{
    // Use the bool value flag to judge whether the operation is successful
    // Return true if there are products in the price range, and return false if there are no products
    bool flag = false;

    r_classify* current_classify = r_classify_head;
    while (current_classify != NULL)
    {
        printf("Class:%s\n", current_classify->name);
        // Sort recipes within the current classification from high to low price
        r_mergeSortLower(current_classify->r_head);
        // Traverse through each recipe within the current classification
        recipe* current_recipe = current_classify->r_head;
        if (current_recipe == NULL)
        {
            colour(12);
            printf("This product category has not added any products yet\n");
            colour(7);
        }
        while (current_recipe != NULL && current_recipe->price >= min_price)
        {
            if (current_recipe->price <= max_price)
            {
                if (current_recipe->sale_discount != 1.0)
                {
                    printf("\tName: ");
                    colour(3);
                    printf("%s\n", current_recipe->name);
                    colour(7);
                }
                else
                {
                    printf("\tName: %s\n", current_recipe->name);
                }
                printf("\tStars: ");
                for (int i = 0; i < current_recipe->star; i++)
                {
                    colour(6);
                    printf("*");
                    colour(7);
                }
                printf("\tPrice: %.2f\n", current_recipe->price);
                flag = true;
            }
            // Traverse all the recipes in one classify
            current_recipe = current_recipe->next;
            if (current_recipe != NULL)
            {
                printf("        --------------------------------------------\n");
            }
        }
        //Traverse all classifies
        current_classify = current_classify->next;
        printf("----------------------------------------------------\n");
    }

    return flag;
}
bool output_recipe_low_to_high(r_classify* r_classify_head, float min_price, float max_price)
{
    // Use the bool value flag to judge whether the operation is successful
    // Return true if there are products in the price range, and return false if there are no products
    bool flag = false;

    r_classify* current_classify = r_classify_head;
    while (current_classify != NULL)
    {
        printf("Classification: %s\n", current_classify->name);
        // Sort recipes within the current classification from low to high price
        r_mergeSortUpper(current_classify->r_head);
        // Traverse through each recipe within the current classification
        recipe* current_recipe = current_classify->r_head;
        if (current_recipe == NULL)
        {
            colour(12);
            printf("This product category has not added any products yet\n");
            colour(7);
        }
        while (current_recipe != NULL && current_recipe->price >= min_price)
        {
            if (current_recipe->price <= max_price)
            {
                if (current_recipe->sale_discount != 1.0)
                {
                    printf("\tName: ");
                    colour(3);
                    printf("%s\n", current_recipe->name);
                    colour(7);
                }
                else
                {
                    printf("\tName: %s\n", current_recipe->name);
                }
                printf("\tStars: ");
                for (int i = 0; i < current_recipe->star; i++)
                {
                    colour(6);
                    printf("*");
                    colour(7);
                }
                printf("\tPrice: %.2f\n", current_recipe->price);
                flag = true;
            }
            // Traverse all the recipes in one classify
            current_recipe = current_recipe->next;
            if (current_recipe != NULL)
            {
                printf("        --------------------------------------------\n");
            }
        }
        //Traverse all classifies
        current_classify = current_classify->next;
        printf("----------------------------------------------------\n");
    }

    return flag;
}
