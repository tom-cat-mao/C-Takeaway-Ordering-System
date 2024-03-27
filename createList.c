#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include<string.h>

//创建菜品列表
void creatList_recipe(recipe** head, char* n, int p, int num)
{
    recipe* newNode = (recipe*)malloc(sizeof(recipe));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->name, n);
    newNode->price = p;
    newNode->num = num;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        recipe* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//创建菜品类列表
void creatList_r_classify(r_classify** head, char* n)
{
    r_classify* newNode = (r_classify*)malloc(sizeof(r_classify));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->name, n);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        r_classify* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//创建订单列表
void creatList_order(order** head, char* o_id, char* merchant_name, char* merchant_address, char* merchant_phone,
    char* deliver_name, char* deliver_phone, char* user_name, char* user_adderss, char* user_phone)
{
    order* newNode = (order*)malloc(sizeof(order));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->order_id, o_id);
    strcpy(newNode->m_name, merchant_name);
    strcpy(newNode->m_address, merchant_address);
    strcpy(newNode->m_phone, merchant_phone);
    strcpy(newNode->u_name, user_name);
    strcpy(newNode->u_address, user_adderss);
    strcpy(newNode->u_phone, user_phone);
    strcpy(newNode->d_name, deliver_name);
    strcpy(newNode->d_phone, deliver_phone);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        order* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//创建商家链表
void creatList_merchant(Merchant** head, char* n, char* p, char* a, char* pn)
{
    Merchant* newNode = (Merchant*)malloc(sizeof(Merchant));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Merchant* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//创建用户链表
void creatList_user(User** head, char* n, char* p, char* a, char* pn)
{
    User* newNode = (User*)malloc(sizeof(User));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        User* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

//创建外卖员列表
void creatList_deliveryperson(DeliveryPerson** head, char* n, char* p, char* pn)
{
    DeliveryPerson* newNode = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));
    if (!newNode)
    {
        return;
    }
    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        DeliveryPerson* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}