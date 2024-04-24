#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include"classTree.h"
#include"setStar_recipe.h"

// Create a list of recipes for the order
struct recipe* creatList_recipe_1(char* n, float p, int num)
{
    struct recipe* newNode = (struct recipe*)malloc(sizeof(struct recipe));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->price = p;
    newNode->num = num;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Create a list of recipes for the class
struct recipe* creatList_recipe_2(char* n, float p)
{
    struct recipe* newNode = (struct recipe*)malloc(sizeof(struct recipe));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->sale_discount = 1.0;
    newNode->price = p;
    newNode->star = generateRandomStar();
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_r(struct recipe** head, struct  recipe** tail, struct  recipe* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}

// Create a list of recipes
struct r_classify* creatList_r_classify(char* n)
{
    struct r_classify* newNode = (struct r_classify*)malloc(sizeof(struct r_classify));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->t_r_head = NULL;
    newNode->r_head = NULL;
    newNode->r_tail = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_rc(struct r_classify** head, struct r_classify** tail, struct r_classify* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}

// Create a list of orders
struct order* creatList_order(struct Merchant* m_current, struct  User* u_current, struct DeliveryPerson* d_current)
{
    struct order* newNode = (struct order*)malloc(sizeof(struct order));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    // Initialize order information
    strcpy(newNode->m_name, m_current->name);
    strcpy(newNode->m_address, m_current->address);
    strcpy(newNode->m_phone, m_current->phone);
    strcpy(newNode->u_name, u_current->name);
    strcpy(newNode->u_address, u_current->address);
    strcpy(newNode->u_phone, u_current->phone);
    if (d_current == NULL)
    {
        strcpy(newNode->d_name, "need to be operate");
        strcpy(newNode->d_phone, "need to be operate");
    }
    else
    {
        strcpy(newNode->d_name, d_current->name);
        strcpy(newNode->d_phone, d_current->phone);
    }

    set_time(newNode->localTime);
    strftime(newNode->order_id, sizeof(newNode->order_id), "%Y%m%d %H%M%S", newNode->localTime);
    for (int i = 7, j = strlen(newNode->order_id); i < 11; i++, j++)
    {

        newNode->order_id[j] = newNode->u_phone[i];

    }
    memset(newNode->arrive_time, 0, sizeof(struct tm));
    memset(newNode->send_time, 0, sizeof(struct tm));
    newNode->r_head = NULL;
    newNode->r_tail = NULL;
    newNode->t_r_head = NULL;
    newNode->s = WAY;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_o(struct order** head, struct order** tail, struct order* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}

// Create a list of merchants
struct Merchant* creatList_merchant(char* n, char* p, char* a, char* pn)
{
    struct Merchant* newNode = (struct Merchant*)malloc(sizeof(struct Merchant));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->o_head = NULL;
    newNode->o_tail = NULL;
    newNode->r_head = NULL;
    newNode->r_tail = NULL;
    newNode->t_o_head = NULL;
    newNode->t_r_head = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_m(struct Merchant** head, struct Merchant** tail, struct  Merchant* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}

// Create a list of users
struct User* creatList_user(char* n, char* p, char* a, char* pn)
{
    struct User* newNode = (struct User*)malloc(sizeof(struct User));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->c = SILVER;
    newNode->o_head = NULL;
    newNode->o_tail = NULL;
    newNode->t_o_head = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_u(struct User** head, struct User** tail, struct User* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}

// Create a list of delivery persons
struct DeliveryPerson* creatList_deliveryperson(char* n, char* p, char* pn)
{
    struct DeliveryPerson* newNode = (struct DeliveryPerson*)malloc(sizeof(struct DeliveryPerson));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->phone, pn);
    newNode->s = FREE;
    newNode->t_o_head = NULL;
    newNode->o_head = NULL;
    newNode->o_tail = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_d(struct DeliveryPerson** head, struct DeliveryPerson** tail, struct DeliveryPerson* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *(tail);
        *tail = newNode;
    }
}