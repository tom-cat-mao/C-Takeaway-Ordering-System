#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include"classTree.h"
#include"setStar_recipe.h"

// Create a list of recipes for the order
recipe* creatList_recipe_1(char* n, float p, int num)
{
    recipe* newNode = (recipe*)malloc(sizeof(recipe)); 

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
recipe* creatList_recipe_2(char* n, float p)
{
    recipe* newNode = (recipe*)malloc(sizeof(recipe));   

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
void insertEnd_r(recipe** head, recipe** tail, recipe* newNode)
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
r_classify* creatList_r_classify(char* n)
{
    r_classify* newNode = (r_classify*)malloc(sizeof(r_classify));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->r_head = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_rc(r_classify** head, r_classify** tail, r_classify* newNode)
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
order* creatList_order(Merchant* m_current, User* u_current, DeliveryPerson* d_current)
{
    order* newNode = (order*)malloc(sizeof(order));

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
        newNode->d_name = { "need to be operate" };
        newNode->d_phone = { "need to be operate" };
    }
    else
    {
        strcpy(newNode->d_name, d_current->name);
        strcpy(newNode->d_phone, d_current->phone);
    }
    
    set_time(newNode->localTime);
    strftime(newNode->order_id, sizeof(newNode->order_id), "%Y%m%d %H%M%S", newNode->localTime);
    for (int i = 7, j = strlen(newNode->order_id); i < 11; i++,j++)
    {
        
        newNode->order_id[j] = newNode->u_phone[i];
        
    }
    memset(newNode->arrive_time, 0, sizeof(struct tm));
    memset(newNode->send_time, 0, sizeof(struct tm));
    newNode->s = WAY;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_o(order** head, order** tail, order* newNode)
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
Merchant* creatList_merchant(char* n, char* p, char* a, char* pn)
{
    Merchant* newNode = (Merchant*)malloc(sizeof(Merchant));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_m(Merchant** head, Merchant** tail, Merchant* newNode)
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
User* creatList_user(char* n, char* p, char* a, char* pn)
{
    User* newNode = (User*)malloc(sizeof(User));

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
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_u(User** head, User** tail, User* newNode)
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
DeliveryPerson* creatList_deliveryperson(char* n, char* p, char* pn)
{
    DeliveryPerson* newNode = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->phone, pn);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert the new node into the end of the list
void insertEnd_d(DeliveryPerson** head, DeliveryPerson** tail, DeliveryPerson* newNode)
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