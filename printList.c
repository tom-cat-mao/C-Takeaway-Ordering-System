#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Print all products in the menu
void printList_recipe_1(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\tStars:%d\n", head->name, head->price, head->star);
        head = head->next;
    }
}

// Print all products in the order
void printList_recipe_2(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\tQuantity: %d\n", head->name, head->price, head->num);
        head = head->next;
    }
}

// Print product categories
void printList_r_classify(r_classify* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("Recipe class:%s\n", head->name);
        if (head->r_head == NULL)
        {
            printf("This product category has not added any products yet\n");
        }
        else
        {
            printList_recipe_1(head->r_head);
        }
        head = head->next;
    }
}

// Print orders
void print_order_list(order* tail)
{
    printf("Order List:\n");
    while (tail != NULL)
    {
        printf("%d-%02d-%02d %02d:%02d:%02d\n", tail->localTime->tm_year + 1900, tail->localTime->tm_mon + 1, tail->localTime->tm_mday,
            tail->localTime->tm_hour, tail->localTime->tm_min, tail->localTime->tm_sec);
        printf("Order ID: %s\n", tail->order_id);
        printf("Merchant: %s\tAddress: %s\tPhone: %s\n", tail->m_name, tail->m_address, tail->m_phone);
        printf("User: %s\tAddress: %s\tPhone: %s\n", tail->u_name, tail->u_address, tail->u_phone);
        printf("Delivery Person: %s\tPhone: %s\n", tail->d_name, tail->d_phone);
        printf("Total Price: %.2f\t", tail->sum_price);
        switch (tail->s) {
        case WAY:
            printf("Order State: Waiting\n");
            break;
        case DILLVERING:
            printf("Order State: Delivering\n");
            break;
        case FINISH:
            printf("Order State: Finished\n");
            break;
        default:
            printf("Order State: Canceled\n");
            break;
        }
        printList_recipe_2(tail->r_head); // Print the list of products in the order
        tail = tail->prev;
    }
}

// Print merchant list
void printList_merchant(Merchant* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tAddress: %s\n", head->name, head->address);
        head = head->next;
    }
}

// Print current order
void print_current_order(order* tail)
{
    printf("Order List:\n");
    printf("%d-%02d-%02d %02d:%02d:%02d\n", tail->localTime->tm_year + 1900, tail->localTime->tm_mon + 1, tail->localTime->tm_mday,
        tail->localTime->tm_hour, tail->localTime->tm_min, tail->localTime->tm_sec);
    printf("Order ID: %s\n", tail->order_id);
    printf("Merchant: %s\tAddress: %s\tPhone: %s\n", tail->m_name, tail->m_address, tail->m_phone);
    printf("User: %s\tAddress: %s\tPhone: %s\n", tail->u_name, tail->u_address, tail->u_phone);
    printf("Delivery Person: %s\tPhone: %s\n", tail->d_name, tail->d_phone);
    printList_recipe_2(tail->r_head); // Print the list of products in the order
    printf("Total Price: %.2f\t", tail->sum_price);
    switch (tail->s) 
    {
    case WAY:
        printf("Order State: Waiting\n");
        break;
    case DILLVERING:
        printf("Order State: Delivering\n");
        break;
    case FINISH:
        printf("Order State: Finished\n");
        break;
    default:
        printf("Order State: Canceled\n");
        break;
    }
}