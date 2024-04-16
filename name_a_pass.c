#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//write the password into the file

void m_writeIntoFile_p(Password_m* head)
{
    FILE* fp = fopen("Merchant_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    Password_m* current = head;
    while (current != NULL)
    {
        fprintf("%s\t%s\t%s\n", current->name, current->phone, current->password);
        current = current->next;
    }
    fclose(fp);
}

void u_writeIntoFile_p(Password_u* head)
{
    FILE* fp = fopen("User_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    Password_u* current = head;
    while (current != NULL)
    {
        fprintf("%s\t%s\t%s\n", current->name, current->phone, current->password);
        current = current->next;
    }
    fclose(fp);
}

void d_writeIntoFile_p(Password_d* head)
{
    FILE* fp = fopen("Deliveryperson_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    Password_d* current = head;
    while (current != NULL)
    {
        fprintf("%s\t%s\t%s\n", current->name, current->phone, current->password);
        current = current->next;
    }
    fclose(fp);
}

//read the password from the file

void m_readIntoList_p(Password_m** head)
{
    FILE* fp = fopen("Merchant_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    Password_m* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };

    while (fscanf("%s\t%s\t%s", name, phone, password) != NULL)
    {
        Password_m* newNode = (Password_m*)malloc(sizeof(Password_m));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (head == NULL)
        {
            *head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
}

void u_readIntoList_p(Password_u** head)
{
    FILE* fp = fopen("User_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    Password_u* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };

    while (fscanf("%s\t%s\t%s", name, phone, password) != NULL)
    {
        Password_u* newNode = (Password_u*)malloc(sizeof(Password_u));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (head == NULL)
        {
            *head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
}

void d_readIntoList_p(Password_d** head)
{
    FILE* fp = fopen("Deliveryperson_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    Password_d* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };

    while (fscanf("%s\t%s\t%s", name, phone, password) != NULL)
    {
        Password_d* newNode = (Password_d*)malloc(sizeof(Password_d));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (head == NULL)
        {
            *head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
}

//register
// Create password list
Password_m* m_creatNode_p(char* n, char* p, char* pn)
{
    Password_m* newNode = (Password_m*)malloc(sizeof(Password_m));

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

void m_createList_p(Password_m** head, Password_m** tail, Password_m* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

Password_u* u_creatNode_p(char* n, char* p, char* pn)
{
    Password_u* newNode = (Password_u*)malloc(sizeof(Password_u));

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

void u_createList_p(Password_u** head, Password_u** tail, Password_u* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

Password_d* d_creatNode_p(char* n, char* p, char* pn)
{
    Password_d* newNode = (Password_d*)malloc(sizeof(Password_d));

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

void d_createList_p(Password_d** head, Password_d** tail, Password_d* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}


// Login
bool compare_m(Password_m* head, char* n, Password_m** p_current)
{
    Password_m* current = head;

    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->name, n) == 0)
        {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found == 0)
    {
        printf("You haven't create an account!\n");
        return false;
    }
    else
    {
        *p_current = current;
        // Input password
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { '\0' };
            scanf("%s", p);
            if (strcmp(current->password, p) == 0)
            {
                return true;
            }
        }
        if (i == 5)
        {
            printf("Password wrong!\n");
            return false;
        }
    }
}

bool compare_u(Password_u* head, char* n, Password_u** p_current)
{
    Password_u* current = head;

    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->name, n) == 0)
        {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found == 0)
    {
        printf("You haven't create an account!\n");
        return false;
    }
    else
    {
        *p_current = current;
        // Input password
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { '\0' };
            scanf("%s", p);
            if (strcmp(current->password, p) == 0)
            {
                return true;
            }
        }
        if (i == 5)
        {
            printf("Password wrong!\n");
            return false;
        }
    }
}

bool compare_d(Password_d* head, char* n, Password_d** p_current)
{
    Password_d* current = head;

    int found = 0;

    while (current != NULL)
    {
        if (strcmp(current->name, n) == 0)
        {
            found = 1;
            break;
        }
        current = current->next;
    }

    if (found == 0)
    {
        printf("You haven't create an account!\n");
        return false;
    }
    else
    {
        *p_current = current;
        // Input password
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { '\0' };
            scanf("%s", p);
            if (strcmp(current->password, p) == 0)
            {
                return true;
            }
        }
        if (i == 5)
        {
            printf("Password wrong!\n");
            return false;
        }
    }
}
