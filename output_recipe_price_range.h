#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"mergeSortRecipe.h"

// Output products from high price to low within a certain price range
bool output_recipe_high_to_low(recipe* head, float minPrice, float maxPrice)
{
    // Use the bool value flag to judge whether the operation is successful
    // Return true if there are products in the price range, and return false if there are no products
    bool flag = false;
    // First sort the products from high to low
    r_mergeSortLower(&head);
    // Output the products within the price range in the sorted list
    recipe* current = head;
    while (current != NULL && current->price >= minPrice) 
    {
        if (current->price <= maxPrice)
        {
            printf("Product name: %s\tPrice: %.2f\n", current->name, current->price);
            flag = true;
        }
        current = current->next;
    }
    return flag;
}

// Output products from low price to high within a certain price range
bool output_recipe_low_to_high(recipe* head, float minPrice, float maxPrice) 
{
    // Use the bool value flag to judge whether the operation is successful
    // Return true if there are products in the price range, and return false if there are no products
    bool flag = false;
    // First sort the products from low to high
    r_mergeSortUpper(&head);
    // Output the products within the price range in the sorted list
    recipe* current = head;
    while (current != NULL && current->price <= maxPrice)
    {
        if (current->price >= minPrice)
        {
            printf("Product name: %s\tPrice: %.2f\n", current->name, current->price);
            flag = true;
        }
        current = current->next;
    }
    return flag;
}