#ifndef _MERGESORTORDER_H
#define _MERGESORTORDER_H
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Split the list
void splitOrder(order* source, order** front, order** back)
{
    order* fast;
    order* slow;

    if (source == NULL || source->next == NULL)
    {
        *front = source;
        *back = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

// Sort the products by price in ascending order

// Merge the two sorted lists
void o_mergeUpper_p(order** result, order* a, order* b)
{
    if (a == NULL)
    {
        *result = b;
        return;
    }
    if (b == NULL)
    {
        *result = a;
        return;
    }

    if (a->sum_price <= b->sum_price)
    {
        *result = a;
        o_mergeUpper_p((&(*result)->next), a->next, b);
    }
    else
    {
        *result = b;
        o_mergeUpper_p((&(*result)->next), a, b->next);
    }

}


// Use merge sort to sort the list in ascending order
void o_mergeSortUpper_p(order** head)
{
    order* current = *head;
    order* a;
    order* b;

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    splitOrder(current, &a, &b);

    o_mergeSortUpper_p(&a);
    o_mergeSortUpper_p(&b);

    o_mergeUpper_p(head, a, b);
}

// Sort the products by price in descending order

// Merge the two sorted lists
void o_mergeLower_p(order** result, order* a, order* b)
{
    if (a == NULL)
    {
        *result = b;
        return;
    }
    if (b == NULL)
    {
        *result = a;
        return;
    }

    if (a->sum_price >= b->sum_price)
    {
        *result = a;
        o_mergeLower_p((&(*result)->next), a->next, b);
    }
    else
    {
        *result = b;
        o_mergeLower_p((&(*result)->next), a, b->next);
    }

}

// Use merge sort to sort the list in descending order
void o_mergeSortLower_p(order** head)
{
    order* current = *head;
    order* a;
    order* b;

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    splitOrder(current, &a, &b);

    o_mergeSortLower_p(&a);
    o_mergeSortLower_p(&b);

    o_mergeLower_p(head, a, b);
}



// Sort the products by time in ascending order

// Merge the two sorted lists
void o_mergeUpper_t(order** result, order* a, order* b)
{
    if (a == NULL)
    {
        *result = b;
        return;
    }
    if (b == NULL)
    {
        *result = a;
        return;
    }

    if (mktime(a->localTime) <= mktime(b->localTime))
    {
        *result = a;
        o_mergeUpper_t((&(*result)->next), a->next, b);
    }
    else
    {
        *result = b;
        o_mergeUpper_t((&(*result)->next), a, b->next);
    }

}


// Use merge sort to sort the list in ascending order
void o_mergeSortUpper_t(order** head)
{
    order* current = *head;
    order* a;
    order* b;

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    splitOrder(current, &a, &b);

    o_mergeSortUpper_t(&a);
    o_mergeSortUpper_t(&b);

    o_mergeUpper_t(head, a, b);
}

// Sort the products by time in descending order

// Merge the two sorted lists
void o_mergeLower_t(order** result, order* a, order* b)
{
    if (a == NULL)
    {
        *result = b;
        return;
    }
    if (b == NULL)
    {
        *result = a;
        return;
    }

    if (mktime(a->localTime) >= mktime(b->localTime))
    {
        *result = a;
        o_mergeLower_t((&(*result)->next), a->next, b);
    }
    else
    {
        *result = b;
        o_mergeLower_t((&(*result)->next), a, b->next);
    }

}

// Use merge sort to sort the list in descending order
void o_mergeSortLower_t(order** head)
{
    order* current = *head;
    order* a;
    order* b;

    if (current == NULL || current->next == NULL)
    {
        return;
    }

    splitOrder(current, &a, &b);

    o_mergeSortLower_t(&a);
    o_mergeSortLower_t(&b);

    o_mergeLower_t(head, a, b);
}


#endif //_MERGESORTORDER_H
