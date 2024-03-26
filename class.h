#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

//菜单结构体
typedef struct recipe
{
    char name[100];          //菜品名称
    int price;               //菜品价格
    struct recipe* next;
} Recipe;

//订单结构体
typedef struct order
{
    char name[100];          
    int price;               
    struct order* next;
} Order;

// 商家结构体
typedef struct 
{
    char name[100];
    char address[100];
    char phone[20];

    struct Recipe* head;
    struct Order* head;

    struct Merchant *next;

} Merchant;

// 外卖员结构体
typedef struct 
{
    int state;
    char name[100];
    int age;
    char phone[20];

    struct DeliveryPerson *next;
    
} DeliveryPerson;

// 用户结构体
typedef struct {
    char name[100];
    char address[100];
    char phone[20];

    struct User *next;
} User;

#endif