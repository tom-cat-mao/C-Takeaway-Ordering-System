#pragma once
#ifndef _MERGESORTRECIPE_H
#define _MERGESORTRECIPE_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Split the list
struct recipe* splitRecipe(struct recipe* head)
{
    struct recipe* fast = head;
    struct recipe* slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct recipe* temp = slow->next;
    slow->next = NULL;
    if (temp)
    {
        temp->prev = NULL; // Set the previous pointer of the new head to NULL
    }

    return temp;
}

// Sort the products by price in ascending order

// Merge the two sorted lists
struct recipe* r_mergeUpper_p(struct recipe* first, struct recipe* second, struct recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if (first->price <= second->price)
    {
        first->next = r_mergeUpper_p(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_p(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in ascending order
struct recipe* r_mergeSortUpper_p(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortUpper_p(head, tail);
    second = r_mergeSortUpper_p(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeUpper_p(head, second, tail);
}

// Sort the products by price in descending order

// Merge the two sorted lists
struct recipe* r_mergeLower_p(struct recipe* first, struct recipe* second, struct  recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if (first->price >= second->price)
    {
        second->next = r_mergeLower_p(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
    else
    {
        first->next = r_mergeLower_p(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
}

// Use merge sort to sort the list in descending order
struct recipe* r_mergeSortLower_p(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct  recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortLower_p(head, tail);
    second = r_mergeSortLower_p(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeLower_p(head, second, tail);
}

// Sort the products by star in ascending order

// Merge the two sorted lists
struct recipe* r_mergeUpper_s(struct recipe* first, struct recipe* second, struct recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if (first->star <= second->star)
    {
        first->next = r_mergeUpper_s(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_s(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in ascending order
struct recipe* r_mergeSortUpper_s(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortUpper_s(head, tail);
    second = r_mergeSortUpper_s(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeUpper_s(head, second, tail);
}


// Sort the products by star in descending order

// Merge the two sorted lists
struct recipe* r_mergeLower_s(struct recipe* first, struct recipe* second, struct recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if (first->star >= second->star)
    {
        second->next = r_mergeLower_s(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
    else
    {
        first->next = r_mergeLower_s(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
}

// Use merge sort to sort the list in descending order
struct recipe* r_mergeSortLower_s(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortLower_s(head, tail);
    second = r_mergeSortLower_s(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeLower_s(head, second, tail);
}

// Sort the products by comprehensive in ascending order

// Merge the two sorted lists
struct recipe* r_mergeUpper_c(struct recipe* first, struct recipe* second, struct recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if ((first->price) * 0.5 + (first->star) * 0.5 <= (second->price) * 0.5 + (first->star) * 0.5)
    {
        first->next = r_mergeUpper_c(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = r_mergeUpper_c(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in ascending order
struct recipe* r_mergeSortUpper_c(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortUpper_c(head, tail);
    second = r_mergeSortUpper_c(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeUpper_c(head, second, tail);
}

// Sort the products by comprehensive in descending order

// Merge the two sorted lists
struct recipe* r_mergeLower_c(struct recipe* first, struct recipe* second, struct recipe** tail)
{
    // If first linked list is empty
    if (first == NULL)
    {
        *tail = second;
        return second;
    }
    // If second linked list is empty
    if (second == NULL)
    {
        *tail = first;
        return first;
    }

    // Pick the smaller value
    if ((first->price) * 0.5 + (first->star) * 0.5 >= (second->price) * 0.5 + (first->star) * 0.5)
    {
        second->next = r_mergeLower_c(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
    else
    {
        first->next = r_mergeLower_c(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
}

// Use merge sort to sort the list in descending order
struct recipe* r_mergeSortLower_c(struct recipe* head, struct recipe** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct recipe* second = splitRecipe(head, tail);
    struct recipe* secondTail;

    // Recur for left and right halves
    head = r_mergeSortLower_c(head, tail);
    second = r_mergeSortLower_c(second, &secondTail);

    // Merge the two sorted halves
    return r_mergeLower_c(head, second, tail);
}

#endif //_MERGESORTRECIPE_H