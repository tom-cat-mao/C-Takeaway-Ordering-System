#pragma once
#ifndef _MERGESORTRECIPE_H
#define _MERGESORTRECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Split the list
recipe* splitRecipe(recipe* head)
{
    recipe* fast=head;
    recipe* slow=head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    recipe* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Sort the products by price in ascending order

// Merge the two sorted lists
recipe* r_mergeUpper_p(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if (first->price <= second->price)
    {
        first->next = r_mergeUpper_p(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_p(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

}

// Use merge sort to sort the list in ascending order
recipe* r_mergeSortUpper_p(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortUpper_p(head);
    second = r_mergeSortUpper_p(second);

    // Merge the two sorted halves
    return r_mergeUpper_p(head, second);
}

// Sort the products by price in descending order

// Merge the two sorted lists
recipe* r_mergeLower_p(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if (first->price >= second->price)
    {
        second->next = r_mergeLower_p(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
        
    }
    else
    {
        first->next = r_mergeLower_p(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

}

// Use merge sort to sort the list in descending order
recipe* r_mergeSortLower_p(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortLower_p(head);
    second = r_mergeSortLower_p(second);

    // Merge the two sorted halves
    return r_mergeLower_p(head, second);
}

// Sort the products by star in ascending order

// Merge the two sorted lists
recipe* r_mergeUpper_s(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if (first->star <= second->star)
    {
        first->next = r_mergeUpper_s(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_s(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

}

// Use merge sort to sort the list in ascending order
recipe* r_mergeSortUpper_s(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortUpper_s(head);
    second = r_mergeSortUpper_s(second);

    // Merge the two sorted halves
    return r_mergeUpper_s(head, second);
}

// Sort the products by star in descending order

// Merge the two sorted lists
recipe* r_mergeLower_s(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if (first->star >= b->star)
    {
        second->next = r_mergeLower_s(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;

    }
    else
    {
        first->next = r_mergeLower_s(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

}

// Use merge sort to sort the list in descending order
recipe* r_mergeSortLower_s(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortLower_s(head);
    second = r_mergeSortLower_s(second);

    // Merge the two sorted halves
    return r_mergeLower_s(head, second);
}

// Sort the products by comprehensive in ascending order

// Merge the two sorted lists
recipe* r_mergeUpper_c(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if ((first->price)*0.5+(first->star)*0.5 <= (second->price)*0.5+(first->star)*0.5)
    {
        first->next = r_mergeUpper_c(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_c(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

}

// Use merge sort to sort the list in ascending order
recipe* r_mergeSortUpper_c(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortUpper_c(head);
    second = r_mergeSortUpper_c(second);

    // Merge the two sorted halves
    return r_mergeUpper_c(head, second);
}

// Sort the products by comprehensive in descending order

// Merge the two sorted lists
recipe* r_mergeLower_c(recipe* first, recipe* second)
{
    // If first linked list is empty
    if (first == NULL)
    {
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    // Pick the smaller value
    if ((first->price) * 0.5 + (first->star) * 0.5 >= (second->price) * 0.5 + (first->star) * 0.5)
    {
        second->next = r_mergeLower_c(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;

    }
    else
    {
        first->next = r_mergeLower_c(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

}

// Use merge sort to sort the list in descending order
recipe* r_mergeSortLower_c(recipe* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    recipe* second = splitRecipe(head);

    // Recur for left and right halves
    head = r_mergeSortLower_c(head);
    second = r_mergeSortLower_c(second);

    // Merge the two sorted halves
    return r_mergeLower_c(head, second);
}


#endif //_MERGESORTRECIPE_H