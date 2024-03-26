#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

// 商家结构体
typedef struct 
{
    char name[100];
    char address[100];
    char phone[20];

    typedef struct recipe
    {
        char name[100];
        int price;
        struct recipe *next;
    } Recipe;

    typedef struct order
    {
        char name[100];
        int price;
        struct order *next;
    } Order;

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