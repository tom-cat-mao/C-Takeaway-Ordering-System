#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"mergeSortRecipe.h"
#include"interface.h"

void output_recipe_high_to_low(struct r_classify* r_classify_head, float min_price, float max_price)
{
    if (r_classify_head == NULL)
    {
        colour(12);
        printf("There's no classify yet.\n");
        colour(7);
        return;
    }

    struct r_classify* current_classify = r_classify_head;
    while (current_classify != NULL)
    {
        printf("Recipes in price range %.2f - %.2f:\n", max_price, min_price);
        colour(6);
        printf("Class: %s\n", current_classify->name);
        colour(7);

        //Create a new list to store the recipes within the price range
        struct recipe* new_recipe_ListHead = NULL;
        struct recipe* new_recipe_ListTail = NULL;

        // Traverse through each recipe within the current classification
        // to sort the recipe in that range and add into the new list
        struct recipe* current_recipe = current_classify->r_head;
        while (current_recipe != NULL)
        {
            if (current_recipe->price >= min_price && current_recipe->price <= max_price)
            {
                if (new_recipe_ListHead == NULL)
                {
                    new_recipe_ListHead = current_recipe;
                    new_recipe_ListTail = current_recipe;
                }
                else 
                {
                    new_recipe_ListTail->next = current_recipe;
                    current_recipe->prev = new_recipe_ListTail;
                    new_recipe_ListTail = current_recipe;
                }
            }
            current_recipe = current_recipe->next;
        }

        // Sort order of the new list by price from high to low
        new_recipe_ListHead = r_mergeSortUpper_p(new_recipe_ListHead, &new_recipe_ListTail);

        current_recipe = new_recipe_ListHead;
        while (current_recipe != NULL)
        {
            printf("        --------------------------------------------\n");
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

            struct recipe* temp = current_recipe;
            current_recipe = current_recipe->next;
            //free(temp);
            if (current_recipe != NULL)
            {
                printf("        --------------------------------------------\n");
            }
            
        }
        current_classify = current_classify->next;
    }
}
void output_recipe_low_to_high(struct r_classify* r_classify_head, float min_price, float max_price)
{
    if (r_classify_head == NULL)
    {
        colour(12);
        printf("There's no classify yet.\n");
        colour(7);
        return;
    }

    struct r_classify* current_classify = r_classify_head;
    while (current_classify != NULL)
    {
        printf("Recipes in price range %.2f - %.2f:\n", min_price, max_price);
        colour(6);
        printf("Class: %s\n", current_classify->name);
        colour(7);

        //Create a new list to store the recipes within the price range
        struct recipe* new_recipe_ListHead = NULL;
        struct recipe* new_recipe_ListTail = NULL;

        // Traverse through each recipe within the current classification
        // to sort the recipe in that range and add into the new list
        struct recipe* current_recipe = current_classify->r_head;
        while (current_recipe != NULL)
        {
            if (current_recipe->price >= min_price && current_recipe->price <= max_price)
            {
                if (new_recipe_ListHead == NULL)
                {
                    new_recipe_ListHead = current_recipe;
                    new_recipe_ListTail = current_recipe;
                }
                else
                {
                    new_recipe_ListTail->next = current_recipe;
                    current_recipe->prev = new_recipe_ListTail;
                    new_recipe_ListTail = current_recipe;
                }
            }
            current_recipe = current_recipe->next;
        }

        // Sort order of the new list by price from low to high
        new_recipe_ListHead = r_mergeSortLower_p(new_recipe_ListHead, &new_recipe_ListTail);

        current_recipe = new_recipe_ListHead;
        while (current_recipe != NULL)
        {
            printf("        --------------------------------------------\n");
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

            struct recipe* temp = current_recipe;
            current_recipe = current_recipe->next;
            //free(temp);
            if (current_recipe != NULL)
            {
                printf("        --------------------------------------------\n");
            }

        }
        current_classify = current_classify->next;
    }
}

