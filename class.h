#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

// 商家结构体
typedef struct {
    char name[100];
    char address[100];
    char phone[20];
} Merchant;

// 外卖员结构体
typedef struct {
    char name[100];
    int age;
    char phone[20];
} DeliveryPerson;

// 用户结构体
typedef struct {
    char name[100];
    char address[100];
    char phone[20];
} User;

#endif