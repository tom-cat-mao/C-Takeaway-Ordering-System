#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

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
    newNode->price = p;
    newNode->next = NULL;

    return newNode;
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

    // Ask whether to add recipe
    printf("Add recipes or not (Y/N):\t");
    char flag = getchar(); // Set a flag to determine whether to add recipe
    getchar();

    flag = toupper(flag); // Set a flag to determine whether to add recipe
    // Add product
    if (flag == 'Y')
    {
        int i;
        for (i = 1;; i++)
        {
            char name[100];
            float price;
            printf("\nPlease enter the name of the recipe(q to quit):\t");
            scanf("%s", name);
            if (name[0] == 'q')
            {
                break;
            }

            // Enter the price of the recipe
            printf("\nPlease enter the price of the recipe:\t");
            scanf("%f", &price);
            printf("\n");

            if (newNode->r_head == NULL)
            {
                newNode->r_head = creatList_recipe_2(name, price);
                newNode->r_tail = newNode->r_head;
            }
            else
            {
                newNode->r_tail->next = creatList_recipe_2(name, price);
            }
        }
        newNode->total_number = i;
    }
    else
    {
        newNode->total_number = 0;
        free(newNode);
        newNode = NULL;
        return NULL;
    }

    newNode->next = NULL;

    return newNode;
}

// Create a list of orders
order* creatList_order(char* merchant_name, char* merchant_address, char* merchant_phone,
    char* deliver_name, char* deliver_phone, char* user_name, char* user_adderss, char* user_phone)
{
    order* newNode = (order*)malloc(sizeof(order));

    // Check whether the node is created successfully
    if (!newNode)
    {
        return NULL;
    }

    // Initialize order information
    strcpy(newNode->m_name, merchant_name);
    strcpy(newNode->m_address, merchant_address);
    strcpy(newNode->m_phone, merchant_phone);
    strcpy(newNode->u_name, user_name);
    strcpy(newNode->u_address, user_adderss);
    strcpy(newNode->u_phone, user_phone);
    strcpy(newNode->d_name, deliver_name);
    strcpy(newNode->d_phone, deliver_phone);
    set_time(newNode->localTime);
    strftime(newNode->order_id, sizeof(newNode->order_id), "%Y%m%d %H%M%S", newNode->localTime);
    for (int i = 7, j = strlen(newNode->order_id); i < 11; i++,j++)
    {
        
        newNode->order_id[j] = newNode->u_phone[i];
        
    }
    newNode->next = NULL;

    return newNode;
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
    newNode->next = NULL;

    return newNode;
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
    newNode->next = NULL;

    return newNode;
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
    newNode->next = NULL;

    return newNode;
}