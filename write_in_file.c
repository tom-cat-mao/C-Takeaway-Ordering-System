#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//商户密码存储
void m_writeIntoFile_p(char* n, char* p)
{
    FILE* fp = fopen("merchantpassword.txt", "a+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fprintf(fp, "%s\t%s", n, p);
    fclose(fp);
    printf("LinkedList data written to '%s'\n", "merchantpassword.txt");
}

//用户密码存储
void u_writeIntoFile_p(char* n, char* p)
{
    FILE* fp = fopen("userpassword.txt", "a+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fprintf(fp, "%s\t%s", n, p);
    fclose(fp);
    printf("LinkedList data written to '%s'\n", "userpassword.txt");
}

//外卖员密码存储
void d_writeIntoFile_p(char* n, char* p)
{
    FILE* fp = fopen("deliverpersonpassword.txt", "a+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fprintf(fp, "%s\t%s", n, p);
    fclose(fp);
    printf("LinkedList data written to '%s'\n", "deliverpersonpassword.txt");
}

//更改商家密码
void m_updatePassword(char* n, char* new_p)
{
    FILE* fp = fopen("merchantpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
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
            filePos = ftell(fp) - (strlen(line) + 1); //返回要修改密码的地址
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Merchant not found in file!\n");
        fclose(fp);
        return;
    }

    //将文件指针移动到所需位置
    fseek(fp, filePos, SEEK_SET);
    fprintf(fp, "%s\t%s\n", n, new_p); //更改密码
    fclose(fp);
    printf("Password updated for '%s'\n", n);
}

//更改用户密码
void u_updatePassword(char* n, char* new_p)
{
    FILE* fp = fopen("userpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
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
            filePos = ftell(fp) - (strlen(line) + 1); //返回要修改密码的地址
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("User not found in file!\n");
        fclose(fp);
        return;
    }

    //将文件指针移动到所需位置
    fseek(fp, filePos, SEEK_SET);
    fprintf(fp, "%s\t%s\n", n, new_p); //更改密码
    fclose(fp);
    printf("Password updated for '%s'\n", n);
}

//更改外卖员密码
void d_updatePassword(char* n, char* new_p)
{
    FILE* fp = fopen("deliverpersonpassword.txt", "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
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
            filePos = ftell(fp) - (strlen(line) + 1); //返回要修改密码的地址
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Deliverperson not found in file!\n");
        fclose(fp);
        return;
    }

    //将文件指针移动到所需位置
    fseek(fp, filePos, SEEK_SET);
    fprintf(fp, "%s\t%s\n", n, new_p); //更改密码
    fclose(fp);
    printf("Password updated for '%s'\n", n);
}