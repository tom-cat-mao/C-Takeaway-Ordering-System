#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//delete specific node in the list
bool delete_specific_r_class(struct r_classify** current, struct  r_classify** head, struct  r_classify** tail)
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

bool delete_specific_recipe(struct recipe** current, struct recipe** head, struct recipe** tail)
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

bool delete_specific_order(struct order** current, struct  order** head, struct  order** tail)
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

bool delete_specific_merchant(struct Merchant** current, struct  Merchant** head, struct  Merchant** tail)
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

