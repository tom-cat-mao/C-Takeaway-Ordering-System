#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "interface.h"

// Print all products in the menu
void printList_recipe_1(struct recipe* head)
{
    printf("        --------------------------------------------\n");
    while (head != NULL)
    {
        if (head->sale_discount!=1.0)
        {
            printf("\tName: ");
            colour(3);
            printf("%s\n", head->name);
            colour(7);
        }
        else
        {
            printf("\tName: %s\n", head->name);
        }
        printf("\tStars: ");
        for (int i = 0; i < head->star; i++)
        {
            colour(6);
            printf("*");
            colour(7);
        }
        printf("\tPrice: %.2f\n", head->price);
        
        head = head->next;
        if (head != NULL)
        {
            printf("        --------------------------------------------\n");
        }
    }
}

// Print all products in the order
void printList_recipe_2(struct recipe* head)
{
    printf("        --------------------------------------------\n");
    while (head != NULL)
    {
        printf("\tName: %s\n", head->name);
        printf("\tPrice: %.2f\tQuantity: %d\n", head->price, head->num);
        head = head->next;
    }
    printf("        --------------------------------------------\n");
}

// Print product categories
void printList_r_classify(struct r_classify* head)
{
    while (head != NULL)
    {
        colour(6);
        printf("Class:%s\n", head->name);
        colour(7);
        if (head->r_head == NULL)
        {
            printf("        --------------------------------------------\n");
            colour(12);
            printf("This product category has not added any products yet\n");
            colour(7);
        }
        else
        {
            printList_recipe_1(head->r_head);
        }
        head = head->next;
        printf("----------------------------------------------------\n");
    }
}

// Print orders
void print_order_list(struct order* tail)
{
    printf("Order List:\n");
    if (tail == NULL)
    {
        colour(12);
        printf("There are no order yet!\n");
        colour(7);
    }
    while (tail != NULL)
    {
        printf("****************************************************\n");
        printf("setting time:%d", tail->send_time);
        printf("Order ID: %s\n", tail->order_id);
        printf("Merchant: %s\tAddress: %s\n", tail->m_name, tail->m_address);
        printf("Phone: %s\n", tail->m_phone);
        printf("User: %s\tAddress: %s\n", tail->u_name, tail->u_address);
        printf("Phone: %s\n", tail->u_phone);
        printf("Delivery Person: %s\n", tail->d_name);
        printf("Phone: %s\n", tail->d_phone);
        printList_recipe_2(tail->r_head); // Print the list of products in the order
        printf("Total Price: %.2f\n", tail->sum_price);
        printf("Order State:");
        switch (tail->s)
        {
        case WAY:
            printf("Waiting\n");
            break;
        case DILLVERING:
            printf("Delivering\n");
            break;
        case FINISH:
            colour(10);
            printf("Finished\n");
            colour(7);
            break;
        default:
            colour(12);
            printf("Unknown\n");
            colour(7);
            break;
        }
        printf("Sending time:%d\nArriving time:%d\n", tail->send_time, tail->arrive_time);
        tail = tail->prev;
    }
}

// Print merchant list
void printList_merchant(struct Merchant* head)
{
    while (head != NULL)
    {
        printf("----------------------------------------------------\n");
        printf("Name: %s\tAddress: %s\n", head->name, head->address);
        head = head->next;
        if (head == NULL)
        {
            printf("----------------------------------------------------\n");
        }
    }
}

// Print current order
void print_current_order(struct order* tail)
{
    if (tail != NULL)
    {
        printf("****************************************************\n");
        printf("setting time:%d", tail->send_time);
        printf("Order ID: %s\n", tail->order_id);
        printf("Merchant: %s\tAddress: %s\n", tail->m_name, tail->m_address);
        printf("Phone: %s\n", tail->m_phone);
        printf("User: %s\tAddress: %s\n", tail->u_name, tail->u_address);
        printf("Phone: %s\n", tail->u_phone);
        printf("Delivery Person: %s\n", tail->d_name);
        printf("Phone: %s\n", tail->d_phone);
        printList_recipe_2(tail->r_head); // Print the list of products in the order
        printf("Total Price: %.2f\n", tail->sum_price);
        printf("Order State:");
        switch (tail->s)
        {
        case WAY:
            printf("Waiting\n");
            break;
        case DILLVERING:
            printf("Delivering\n");
            break;
        case FINISH:
            colour(10);
            printf("Finished\n");
            colour(7);
            break;
        default:
            colour(12);
            printf("Unknown\n");
            colour(7);
            break;
        }
        printf("Sending time:%d\nArriving time:%d\n", tail->send_time, tail->arrive_time);
        printf("****************************************************\n");
    }
    else
    {
        colour(12);
        printf("The current order is empty!\n");
        colour(7);
    }
}

// Print current recipe
void print_current_recipe(struct recipe* tail)
{
    printf("        --------------------------------------------\n");
    if (tail != NULL)
    {
        if (tail->sale_discount != 1.0)
        {
            printf("\tName: ");
            colour(3);
            printf("%s\n", tail->name);
            colour(7);
        }
        else
        {
            printf("\tName: %s\n", tail->name);
        }
        printf("\tStars: ");
        for (int i = 0; i < tail->star; i++)
        {
            colour(6);
            printf("*");
            colour(7);
        }
        printf("\tPrice: %.2f\n", tail->price);
    }
    else
    {
        colour(12);
        printf("The current recipe is empty!\n");
        colour(7);
    }
    printf("        --------------------------------------------\n");
}