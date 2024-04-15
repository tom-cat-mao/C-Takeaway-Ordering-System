#ifndef _MERGESORTORDER_H
#define _MERGESORTORDER_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Split the list
order* splitOrder(order* head)
{
    order* fast = head;
    order* slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    order* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Sort the products by price in ascending order

// Merge the two sorted lists
order* o_mergeUpper_p(order* first, order* second)
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
        first->next = o_mergeUpper_p(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeUpper_p(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

}

// Use merge sort to sort the list in ascending order
order* o_mergeSortUpper_p(order* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    order* second = splitOrder(head);

    // Recur for left and right halves
    head = o_mergeSortUpper_p(head);
    second = o_mergeSortUpper_p(second);

    // Merge the two sorted halves
    return o_mergeUpper_p(head, second);
}

// Sort the products by price in descending order

// Merge the two sorted lists
order* o_mergeLower_p(order* first, order* second)
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
        second->next = o_mergeLower_p(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;

    }
    else
    {
        first->next = o_mergeLower_p(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

}

// Use merge sort to sort the list in descending order
order* o_mergeSortLower_p(order* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    order* second = splitOrder(head);

    // Recur for left and right halves
    head = o_mergeSortLower_p(head);
    second = o_mergeSortLower_p(second);

    // Merge the two sorted halves
    return o_mergeLower_p(head, second);
}

// Sort the products by time in ascending order

// Merge the two sorted lists
order* o_mergeUpper_t(order* first, order* second)
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
    if (mktime(first->localTime) <= mktime(second->localTime))
    {
        first->next = o_mergeUpper_t(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = o_mergeUpper_t(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

}

// Use merge sort to sort the list in ascending order
order* o_mergeSortUpper_t(order* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    order* second = splitOrder(head);

    // Recur for left and right halves
    head = o_mergeSortUpper_t(head);
    second = o_mergeSortUpper_t(second);

    // Merge the two sorted halves
    return o_mergeUpper_t(head, second);
}

// Sort the products by time in descending order

// Merge the two sorted lists
order* o_mergeLower_t(order* first, order* second)
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
    if (mktime(first->localTime) >= mktime(second->localTime))
    {
        second->next = o_mergeLower_t(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;

    }
    else
    {
        first->next = o_mergeLower_t(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

}

// Use merge sort to sort the list in descending order
order* o_mergeSortLower_t(order* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    order* second = splitOrder(head);

    // Recur for left and right halves
    head = o_mergeSortLower_t(head);
    second = o_mergeSortLower_t(second);

    // Merge the two sorted halves
    return o_mergeLower_t(head, second);
}

#endif //_MERGESORTORDER_H
