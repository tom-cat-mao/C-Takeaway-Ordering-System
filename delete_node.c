#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//delete specific node in the list
bool delete_specific_r_class(r_classify** current, r_classify** head, r_classify** tail)
{
    if ((*current)->prev == NULL)
    {
        *head = (*current)->next;
        (*current)->next->prev = NULL;
        (*current)->next = NULL;
        (*current)->prev = NULL;
    }
    else if ((*current)->next == NULL)
    {
        (*current)->prev->next = NULL;
        *tail = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    else
    {
        (*current)->prev->next = (*current)->next;
        (*current)->next->prev = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    free(*current);
    return true;
}

bool delete_specific_recipe(recipe** current, recipe** head, recipe** tail)
{
    if ((*current)->prev == NULL)
    {
        *head = (*current)->next;
        (*current)->next->prev = NULL;
        (*current)->next = NULL;
        (*current)->prev = NULL;
    }
    else if ((*current)->next == NULL)
    {
        (*current)->prev->next = NULL;
        *tail = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    else
    {
        (*current)->prev->next = (*current)->next;
        (*current)->next->prev = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    free(*current);
    return true;
}

bool delete_specific_order(order** current, order** head, order** tail)
{
    if ((*current)->prev == NULL)
    {
        *head = (*current)->next;
        (*current)->next->prev = NULL;
        (*current)->next = NULL;
        (*current)->prev = NULL;
    }
    else if ((*current)->next == NULL)
    {
        (*current)->prev->next = NULL;
        *tail = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    else
    {
        (*current)->prev->next = (*current)->next;
        (*current)->next->prev = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    free(*current);
    return true;
}

bool delete_specific_merchant(Merchant** current, Merchant** head, Merchant** tail)
{
    if ((*current)->prev == NULL)
    {
        *head = (*current)->next;
        (*current)->next->prev = NULL;
        (*current)->next = NULL;
        (*current)->prev = NULL;
    }
    else if ((*current)->next == NULL)
    {
        (*current)->prev->next = NULL;
        *tail = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    else
    {
        (*current)->prev->next = (*current)->next;
        (*current)->next->prev = (*current)->prev;
        (*current)->prev = NULL;
        (*current)->next = NULL;
    }
    free(*current);
    return true;
}

