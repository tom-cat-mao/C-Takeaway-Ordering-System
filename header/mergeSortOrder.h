#ifndef _MERGESORTORDER_H
#define _MERGESORTORDER_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Split the list
struct order* splitOrder(struct order* head)
{
    struct order* fast = head;
    struct order* slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct order* temp = slow->next;
    slow->next = NULL;
    if (temp)
    {
        temp->prev = NULL; // Set the previous pointer of the new head to NULL
    }
        
    return temp;
}

// Merge the two sorted lists
struct order* o_mergeUpper_p(struct order* first, struct order* second, struct order** tail)
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
    if (first->sum_price <= second->sum_price)
    {
        first->next = o_mergeUpper_p(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
            
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeUpper_p(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
            
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in ascending order
struct order* o_mergeSortUpper_p(struct order* head, struct order** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct order* second = splitOrder(head);
    struct order* secondTail;

    // Recur for left and right halves
    head = o_mergeSortUpper_p(head, tail);
    second = o_mergeSortUpper_p(second, &secondTail);

    // Merge the two sorted halves
    return o_mergeUpper_p(head, second, tail);
}

// Sort the products by price in descending order

// Merge the two sorted lists in descending order of sum_price
struct order* o_mergeLower_p(struct order* first, struct order* second, struct order** tail)
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

    // Pick the larger value
    if (first->sum_price >= second->sum_price)
    {
        first->next = o_mergeLower_p(first->next, second, tail);
        if (first->next)
            first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeLower_p(first, second->next, tail);
        if (second->next)
            second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in descending order
struct order* o_mergeSortLower_p(struct order* head, struct  order** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct order* second = splitOrder(head);
    struct order* secondTail;

    // Recur for left and right halves
    head = o_mergeSortLower_p(head, tail);
    second = o_mergeSortLower_p(second, &secondTail);

    // Merge the two sorted halves
    return o_mergeLower_p(head, second, tail);
}


// Sort the products by time in ascending order

// Merge the two sorted lists
struct order* o_mergeUpper_t(struct order* first, struct  order* second, struct order** tail)
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
    if (mktime(first->localTime) <= mktime(second->localTime))
    {
        first->next = o_mergeUpper_t(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeUpper_t(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in ascending order
struct order* o_mergeSortUpper_t(struct order* head, struct order** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct order* second = splitOrder(head, tail);
    struct order* secondTail;

    // Recur for left and right halves
    head = o_mergeSortUpper_t(head, tail);
    second = o_mergeSortUpper_t(second, &secondTail);

    // Merge the two sorted halves
    return o_mergeUpper_t(head, second, tail);
}


// Sort the products by time in descending order

// Merge the two sorted lists in descending order
struct order* o_mergeLower_t(struct order* first, struct order* second, struct order** tail)
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

    // Pick the larger value
    if (mktime(first->localTime) >= mktime(second->localTime))
    {
        first->next = o_mergeLower_t(first->next, second, tail);
        if (first->next)
        {
            first->next->prev = first;
        }
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeLower_t(first, second->next, tail);
        if (second->next)
        {
            second->next->prev = second;
        }
        second->prev = NULL;
        return second;
    }
}

// Use merge sort to sort the list in descending order
struct order* o_mergeSortLower_t(struct order* head, struct  order** tail)
{
    if (!head || !head->next)
    {
        *tail = head;
        return head;
    }

    struct order* second = splitOrder(head, tail);
    struct order* secondTail;

    // Recur for left and right halves
    head = o_mergeSortLower_t(head, tail);
    second = o_mergeSortLower_t(second, &secondTail);

    // Merge the two sorted halves
    return o_mergeLower_t(head, second, tail);
}


#endif //_MERGESORTORDER_H
