#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// 登录
bool compare(char *f_name, char* n)
{
    FILE* fp = fopen(f_name, "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return false;
    }

    char line[256] = { "\0" };
    char name[50] = { "\0" };
    char password[50] = { "\0" };
    int found = 0;

    // 寻找要登录的用户
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", name, password);
        if (strcmp(name, n) == 0)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Your name is not found in file!\n");
        fclose(fp);
        return false;
    }
    else
    {
        // 输入密码
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

// 注册
void writeIntoFile_p(char * f_name ,char* n, char* p)
{
    FILE* fp = fopen(f_name, "a+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }
    fprintf(fp, "%s\t%s", n, p);
    fclose(fp);
    printf("LinkedList data written to '%s'\n", "merchantpassword.txt");
}

// 修改密码
void updatePassword(char * f_name ,char* n, char* new_p)
{
    FILE* fp = fopen(f_name, "r+");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    char line[256] = { "\0" };
    char name[50] = { "\0" };
    char password[50] = { "\0" };
    long filePos;
    int found = 0;

    // 寻找要修改密码的用户
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%s\t%s", name, password);
        if (strcmp(name, n) == 0)
        {
            filePos = ftell(fp) - (strlen(line) + 1); //返回要修改密码的地址
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Your are not found in file!\n");
        fclose(fp);
        return;
    }

    // 寻找并修改密码
    fseek(fp, filePos, SEEK_SET);
    fprintf(fp, "%s\t%s\n", n, new_p); //修改密码
    fclose(fp);
    printf("Password updated for '%s'\n", n);
}
