#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include<string.h>

//打印菜单中的菜品
void printList_recipe_1(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\n", head->name, head->price);
        head = head->next;
    }
}

//打印订单中菜品
void printList_recipe_2(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\tQuantity: %d\n", head->name, head->price, head->num);
        head = head->next;
    }
}

//打印菜品分类
void printList_r_classify(r_classify* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("%s\n", head->name);
        printList_recipe_1(head->r_head);
        head = head->next;
    }
}

// 打印订单
void print_order_list(order* head)
{
    printf("Order List:\n");
    while (head != NULL)
    {
        printf("Order ID: %s\n", head->order_id);
        printf("Merchant: %s\tAddress: %s\tPhone: %s\n", head->m_name, head->m_address, head->m_phone);
        printf("User: %s\tAddress: %s\tPhone: %s\n", head->u_name, head->u_address, head->u_phone);
        printf("Delivery Person: %s\tPhone: %s\n", head->d_name, head->d_phone);
        printList_recipe_2(head->r_head); // 打印订单中的菜品列表
        printf("Total Price: %.2f\n", head->sum_price);
        switch (head->state) {
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
            printf("Order State: Unknown\n");
            break;
        }
        head = head->next;
    }
}

//打印商家列表
void printList_merchant(Merchant* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tAddress: %s\n", head->name, head->address);
        head = head->next;
    }
}