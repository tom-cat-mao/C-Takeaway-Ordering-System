#include "class.h"

// 删除订单
bool delete_order (order** head, char* order_id)
{
    if (order_id == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    order* current = *head;
    order* previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->order_id, order_id) == 0)
        {
            
        }

        previous = current;
        current = current->next;
    }
}