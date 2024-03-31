#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//登录
bool compare_m(char* n)
{
    FILE* fp = fopen("merchantpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return false;
    }

    char line[256] = { "\0" };
    char merchantName[50] = { "\0" };
    char password[50] = { "\0" };
    long filePos;
    int found = 0;

    //每行遍历
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", merchantName, password);
        if (strcmp(merchantName, n) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Merchant not found in file!\n");
        fclose(fp);
        return false;
    }
    else
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { "\0" };
            scanf("%s", p);
            if (strcmp(password, p) == 0)
            {
                fclose(fp);
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

bool compare_u(char* n)
{
    FILE* fp = fopen("userpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return false;
    }

    char line[256] = { "\0" };
    char userName[50] = { "\0" };
    char password[50] = { "\0" };
    long filePos;
    int found = 0;

    //每行遍历
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", userName, password);
        if (strcmp(userName, n) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("User not found in file!\n");
        fclose(fp);
        return false;
    }
    else
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { "\0" };
            scanf("%s", p);
            if (strcmp(password, p) == 0)
            {
                fclose(fp);
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

bool compare_d(char* n)
{
    FILE* fp = fopen("deliverpersonpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return false;
    }

    char line[256] = { "\0" };
    char deliverpersonName[50] = { "\0" };
    char password[50] = { "\0" };
    long filePos;
    int found = 0;

    //每行遍历
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", deliverpersonName, password);
        if (strcmp(deliverpersonName, n) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Deliverperson not found in file!\n");
        fclose(fp);
        return false;
    }
    else
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            printf("Please input your password:");
            char p[100] = { "\0" };
            scanf("%s", p);
            if (strcmp(password, p) == 0)
            {
                fclose(fp);
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