#pragma once

//菜单结构体
typedef struct recipe
{
    char name[100];          //菜品名称
    float price;               //菜品价格
    int num;                 //菜品数量

    struct recipe* next;
}recipe;






