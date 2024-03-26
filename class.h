#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
#include <stdio.h>
#include <stdlib.h>

//菜单结构体
typedef struct recipe
{
    char name[100];          //菜品名称
    int price;               //菜品价格
    struct recipe* next = NULL;
    int num;                 //菜品数量
};

typedef struct r_classify
{
    char name[100];                 //菜品分类名称
    struct recipe* r_head = NULL;   //菜品链表
    struct r_classify* next = NULL;
};

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
    enum {WAY, DILLVERING, FINISH} state;

    // 订单的菜品
    struct r_classify* r_head = NULL;

    int price;               
    struct order* next = NULL;
};

// 商家结构体
typedef struct Merchant
{
    char password[100];//密码
    char name[100];
    char address[100];
    char phone[20];

    struct order* o_head = NULL;//订单链表
    struct r_classify* r_head = NULL;//菜品分类链表

    struct Merchant *next = NULL;

};

// 外卖员结构体
typedef struct DeliveryPerson
{
    struct order* o_head = NULL;//订单链表
    
    
    enum {FREE, BUSY} state;//状态
    char name[100];
    char phone[20];


    struct DeliveryPerson *next = NULL;
    
};

// 用户结构体
typedef struct User
{
    char password[100];//密码
    char name[100];
    char address[100];
    char phone[20];

    //订单号
    struct order* head = NULL;

    struct User *next = NULL;
    
};

#endif