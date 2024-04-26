/*
    this delete has to work with file delete, which has not been built.
*/

#include "class.h"

// delete orders
bool delete_order (struct order* head, char* order_id)
{
    struct order* current = head;

    while (current != NULL)
    {
        if (strcmp(current->order_id, order_id) == 0)
        {
            struct recipe* temp_slow_r = current->r_head;
            struct recipe* temp_fast_r = NULL;
            while (temp_slow_r != NULL)
            {
                temp_fast_r = temp_slow_r->next;
                if (!delete_recipe(temp_slow_r, temp_slow_r->name))
                {
                    return false;
                }
                temp_slow_r = temp_fast_r;
            }
            
            free(current);
            current = NULL;
            return true;
        }

        current = current->next;
    }
    printf("could not find the order\n");
    return false;
}

bool delete_recipe (struct recipe* head, char* name)
{
    struct recipe* current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            free(current);
            current = NULL;
            return true;
        }

        current = current->next;
    }

    printf("could not find the recipe\n");
    return false;
}

bool delete_r_class (struct r_classify* head, char* r_name)
{
    struct r_classify* current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, r_name) == 0)
        {
            struct recipe* temp_slow = current->r_head;
            struct recipe* temp_fast = NULL;
            while (temp_slow != NULL)
            {
                temp_fast = temp_slow->next;
                if (!delete_recipe(temp_slow, temp_slow->name))
                {
                    return false;
                }
                temp_slow = temp_fast;
            }
            free(current);
            return true;
        }

        current = current->next;
    }

    printf("Could not find the recipe\n");
    return false;
}

bool delete_merchant (struct Merchant* head, char* m_name)
{
    struct Merchant* current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, m_name) == 0)
        {
            struct r_classify* temp_slow_rc = current->r_head;
            struct r_classify* temp_fast_rc = NULL;
            while (temp_slow_rc != NULL)
            {
                temp_fast_rc = temp_slow_rc->next;
                if (!delete_r_class(temp_slow_rc, temp_slow_rc->name))
                {
                    return false;
                }
                temp_slow_rc = temp_fast_rc;
            }

            struct order* temp_slow_o = current->o_head;
            struct order* temp_fast_o = NULL;
            while (temp_slow_o != NULL)
            {
                temp_fast_o = temp_slow_o->next;
                if (!delete_order(temp_slow_o, temp_slow_o->order_id))
                {
                    return false;
                }
                temp_slow_o = temp_fast_o;
            }

            free(current);
            return true;
        }

        current = current->next;
    }

    printf("Could not find the merchant\n");
    return false;
}

bool delete_user (struct User* head, char* u_name)
{
    struct User* current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, u_name) == 0)
        {
            struct order* temp_slow_o = current->o_head;
            struct order* temp_fast_o = NULL;
            while (temp_slow_o != NULL)
            {
                temp_fast_o = temp_slow_o->next;
                if (!delete_order(temp_slow_o, temp_slow_o->order_id))
                {
                    return false;
                }
                temp_slow_o = temp_fast_o;
            }
            
            free(current);
            return true;
        }

        current = current->next;
    }

    printf("Could not find the user\n");
    return false;
}

bool delete_delivery_person (struct DeliveryPerson* head, char* d_name)
{
    struct DeliveryPerson* current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, d_name) == 0)
        {
            struct order* temp_slow_o = current->o_head;
            struct order* temp_fast_o = NULL;
            while (temp_slow_o != NULL)
            {
                temp_fast_o = temp_slow_o->next;
                if (!delete_order(temp_slow_o, temp_slow_o->order_id))
                {
                    return false;
                }
                temp_slow_o = temp_fast_o;
            }
            
            free(current);
            return true;
        }

        current = current->next;
    }

    printf("Could not find the delivery person\n");
    return false;
}