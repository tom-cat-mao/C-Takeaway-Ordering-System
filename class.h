#pragma once
#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
#include <stdio.h>
#include <stdlib.h>

//菜单结构体
typedef struct recipe
{
    char name[100];          //菜品名称
    float price;               //菜品价格
    int num;                 //菜品数量

    struct recipe* next;
}recipe;

typedef struct r_classify
{
    char name[100];                 //菜品分类名称
    int total_number;        //记录菜品的总数量
    struct recipe* r_head;   //菜品链表

    struct r_classify* next;
}r_classify;

//订单结构体
typedef struct order
{
    // 订单号
    char order_id[100];

    // 商家，配送员，顾客的名字
    char m_name[100];
    char d_name[100];
    char u_name[100];

    // 商家，顾客的地址
    char m_address[100];
    char u_address[100];

    // 商家，配送员，顾客的电话
    char m_phone[20];
    char d_phone[20];
    char u_phone[20];

    //预计到店时间
    int arrive_time;
    //预计送达时间
    int send_time;

    // 订单状态
    enum { WAY, DILLVERING, FINISH } state;

    // 订单的菜品
    struct recipe* r_head;

    float sum_price;

    struct order* next;
}order;

// 商家结构体
typedef struct Merchant
{
    char password[100];//密码
    char name[100];
    char address[100];
    char phone[20];

    struct order* o_head;//订单链表
    struct r_classify* r_head;//菜品分类链表

    struct Merchant* next;

}Merchant;

// 外卖员结构体
typedef struct DeliveryPerson
{
    struct order* o_head;//订单链表


    enum { FREE, BUSY } state;//状态

    char password[100];
    char name[100];
    char phone[20];


    struct DeliveryPerson* next;

}DeliveryPerson;

// 用户结构体
typedef struct User
{
    char password[100];//密码
    char name[100];
    char address[100];
    char phone[20];

    //订单号
    struct order* head;

    struct User* next;

}User;

//创建链表

//创建订单菜品列表
void creatList_recipe_1(recipe** head, char* n, float p, int num);
//创建菜单里的菜品列表
void creatList_recipe_2(recipe** head, char* n, float p);
//创建菜品类列表
void creatList_r_classify(r_classify** head, char* n);
//创建订单列表
void creatList_order(order** head, char* o_id, char* merchant_name, char* merchant_address, char* merchant_phone,
    char* deliver_name, char* deliver_phone, char* user_name, char* user_adderss, char* user_phone);
//创建商家链表
void creatList_merchant(Merchant** head, char* n, char* p, char* a, char* pn);
//创建用户链表
void creatList_user(User** head, char* n, char* p, char* a, char* pn);
// 创建外卖员列表
void creatList_deliveryperson(DeliveryPerson** head, char* n, char* p, char* pn);

//打印链表

//打印菜单中的菜品
void printList_recipe_1(recipe* head);
//打印订单中菜品
void printList_recipe_2(recipe* head);
//打印菜品分类
void printList_r_classify(r_classify* head);
// 打印订单
void print_order_list(order* head);
//打印商家列表
void printList_merchant(Merchant* head);

//求单个订单的折后价
void sumPrice(order* head, recipe* head_r, float discount);
#endif