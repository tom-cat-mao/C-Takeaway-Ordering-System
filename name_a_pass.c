#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//write the password into the file

void m_writeIntoFile_p(struct Password_m* head)
{
    FILE* fp = fopen("Merchant_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    struct Password_m* current = head;
    while (current != NULL)
    {
        fprintf(fp, "%s\n", current->name);
        fprintf(fp, "%s\n", current->phone);
        fprintf(fp, "%s\n", current->password);
        current = current->next;
    }
    fclose(fp);
}

void u_writeIntoFile_p(struct Password_u* head)
{
    FILE* fp = fopen("User_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    struct Password_u* current = head;
    while (current != NULL)
    {
        fprintf(fp, "%s\n", current->name);
        fprintf(fp, "%s\n", current->phone);
        fprintf(fp, "%s\n", current->password);
        current = current->next;
    }
    fclose(fp);
}

void d_writeIntoFile_p(struct Password_d* head)
{
    FILE* fp = fopen("Deliveryperson_password.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    struct Password_d* current = head;
    while (current != NULL)
    {
        fprintf(fp, "%s\n", current->name);
        fprintf(fp, "%s\n", current->phone);
        fprintf(fp, "%s\n", current->password);
        current = current->next;
    }
    fclose(fp);
}

//read the password from the file

void m_readIntoList_p(struct Password_m** head, struct Password_m** tail)
{
    FILE* fp = fopen("Merchant_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct Password_m* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };
    char line[100] = { '\0' };

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        strcpy(name, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(phone, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(password, line);

        struct Password_m* newNode = (struct Password_m*)malloc(sizeof(struct Password_m));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (*head == NULL)
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
    *tail = current;
    fclose(fp);
}

void u_readIntoList_p(struct Password_u** head, struct Password_u** tail)
{
    FILE* fp = fopen("User_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct Password_u* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };
    char line[100] = { '\0' };

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        strcpy(name, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(phone, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(password, line);

        struct Password_u* newNode = (struct Password_u*)malloc(sizeof(struct Password_u));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (*head == NULL)
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
    *tail = current;
    fclose(fp);
}

void d_readIntoList_p(struct Password_d** head, struct Password_d** tail)
{
    FILE* fp = fopen("Deliveryperson_password.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct Password_d* current = NULL;

    char name[100] = { '\0' };
    char phone[100] = { '\0' };
    char password[100] = { '\0' };
    char line[100] = { '\0' };

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        strcpy(name, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(phone, line);
        fgets(line, sizeof(line), fp);
        line[strlen(line) - 1] = '\0';
        strcpy(password, line);

        struct Password_d* newNode = (struct Password_d*)malloc(sizeof(struct Password_d));

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        strcpy(newNode->password, password);
        newNode->next = NULL;

        if (*head == NULL)
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
    *tail = current;
    fclose(fp);
}

//register
// Create password list
struct Password_m* m_creatNode_p(char* n, char* p, char* pn)
{
    struct Password_m* newNode = (struct Password_m*)malloc(sizeof(struct Password_m));

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

void m_createList_p(struct Password_m** head, struct  Password_m** tail, struct  Password_m* newNode)
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

struct Password_u* u_creatNode_p(char* n, char* p, char* pn)
{
    struct Password_u* newNode = (struct Password_u*)malloc(sizeof(struct Password_u));

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

void u_createList_p(struct Password_u** head, struct Password_u** tail, struct Password_u* newNode)
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

struct Password_d* d_creatNode_p(char* n, char* p, char* pn)
{
    struct Password_d* newNode = (struct Password_d*)malloc(sizeof(struct Password_d));

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

void d_createList_p(struct Password_d** head, struct Password_d** tail, struct Password_d* newNode)
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
bool compare_m(struct Password_m* head, char* n, struct Password_m** p_current)
{
    struct  Password_m* current = head;

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
            fflush(stdout);
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

bool compare_u(struct Password_u* head, char* n, struct Password_u** p_current)
{
    struct Password_u* current = head;

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

bool compare_d(struct Password_d* head, char* n, struct Password_d** p_current)
{
    struct Password_d* current = head;

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
