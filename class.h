#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include"classTree.h"

static double discount[3] = { 0.9,0.85,0.75 }; // Different cards corresponding discounts
enum card { SILVER, GOLD, PLATINUM }; // User membership type
enum state_o { WAY, DILLVERING, FINISH, CANCEL }; // Order status
enum state_d { FREE, BUSY }; // Delivery person status

// Menu structure
typedef struct recipe
{
    char name[100];          // Dish name
    float price;             // Dish price
    int num;                 // Dish quantity
    float sale_discount;     // Dish discount
    int star;                // Dish star 

    struct recipe* prev;
    struct recipe* next;
}recipe;

typedef struct r_classify
{
    char name[100];                 // Dish classification name
    int total_number;               // Total number of dishes

    struct recipe* r_head;          // Dish linked list head
    struct recipe* r_tail;          // Dish linked list tail

    struct r_classify* prev;
    struct r_classify* next;        // Next classification
}r_classify;

// Order structure
typedef struct order
{
    // Order ID
    char order_id[100];

    // Order creation time
    struct tm* localTime;

    // Merchant, delivery person, customer names
    char m_name[100];
    char d_name[100];
    char u_name[100];

    // Merchant, customer addresses
    char m_address[100];
    char u_address[100];

    // Merchant, delivery person, customer phone numbers
    char m_phone[20];
    char d_phone[20];
    char u_phone[20];

    // Order status
    enum state_o s;

    // Estimated arrival time
    struct tm* arrive_time;
    // Estimated delivery time
    struct tm* send_time;

    // Total time
    int total_time;

    // Order dishes
    struct recipe* r_head;
    struct recipe* r_tail;

    float sum_price;

    struct order* prev;
    struct order* next;
}order;

// Merchant structure
typedef struct Merchant
{
    char password[100]; // Password
    char name[100];
    char address[100];
    char phone[20];

    struct t_order* t_o_head;// Order tree head
    struct t_recipe* t_r_head;//Recipe tree head

    struct order* o_head; // Order linked list head
    struct order* o_tail; // Order linked list tail

    struct r_classify* r_head; // Dish classification linked list head
    struct r_classify* r_tail; // Dish classification linked list tail

    struct Merchant* prev;
    struct Merchant* next;

}Merchant;

// Delivery person structure
typedef struct DeliveryPerson
{
    struct order* o_head; // Order linked list head
    struct order* o_tail; // Order linked list tail

    enum state_d s; // Status

    char password[100];
    char name[100];
    char phone[20];

    struct DeliveryPerson* prev;
    struct DeliveryPerson* next;

}DeliveryPerson;

// User structure
typedef struct User
{
    char password[100]; // Password
    char name[100];
    char address[100];
    char phone[20];
    
    enum card c; // User membership

    struct t_order* t_o_head;// Order tree head

    // Order ID
    struct order* o_head;
    struct order* o_tail; // Order linked list tail

    struct User* prev;
    struct User* next;

}User;

// Password struct
typedef struct Password_m
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_m* next;
}Password_m;

typedef struct Password_u
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_u* next;
}Password_u;

typedef struct Password_d
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_d* next;
}Password_d;

// Create linked list

// Create order dish list
recipe* creatList_recipe_1(char* n, float p, int num);
// Create menu dish list
recipe* creatList_recipe_2(char* n, float p);
// Create dish classification list
r_classify* creatList_r_classify(char* n);
// Create order list
order* creatList_order(char* merchant_name, char* merchant_address, char* merchant_phone,
    char* deliver_name, char* deliver_phone, char* user_name, char* user_adderss, char* user_phone);
// Create merchant linked list
Merchant* creatList_merchant(char* n, char* p, char* a, char* pn);
// Create user linked list
User* creatList_user(char* n, char* p, char* a, char* pn);
// Create delivery person list
DeliveryPerson* creatList_deliveryperson(char* n, char* p, char* pn);

// Insert the new node into the end of the list
void insertEnd_r(recipe** head, recipe** tail, recipe* newNode);
void insertEnd_rc(r_classify** head, r_classify** tail, r_classify* newNode);
void insertEnd_o(order** head, order** tail, order* newNode);
void insertEnd_m(Merchant** head, Merchant** tail, Merchant* newNode);
void insertEnd_u(User** head, User** tail, User* newNode);
void insertEnd_d(DeliveryPerson** head, DeliveryPerson** tail, DeliveryPerson* newNode);

// Print linked list

// Print menu dishes
void printList_recipe_1(recipe* head);
// Print order dishes
void printList_recipe_2(recipe* head);
// Print dish classification
void printList_r_classify(r_classify* head);
// Print order list
void print_order_list(order* tail);
// Print merchant list
void printList_merchant(Merchant* head);
// Print current order
void print_current_order(order* tail);

// Calculate discounted price for a single order
bool sumPrice(order* head, recipe* head_r, int c, double* d);

// Delete data
bool delete_order(order* head, char* order_id); // Delete an order
bool delete_recipe (recipe* head, char* name); // Delete a dish
bool delete_r_class(r_classify* head, char* name); // Delete a dish class
bool delete_merchant (Merchant* head, char* m_name); // Delete a merchant
bool delete_user (User* head, char* u_name); // Delete a user
bool delete_deliveryperson (DeliveryPerson* head, char* d_name); // Delete a delivery person

// Set time
void set_time(struct tm* localTime);

// Change merchant password
void merchant_change_p(Merchant* current, Password_m* p_current);
// Change user password
void user_change_p(User* current, Password_u* p_current);
// Change delivery person password
void deliveryPerson_change_p(DeliveryPerson* current, Password_d* p_current);

// Change membership discount
bool discount_change(double* d, int c);
// Change user membership type
bool card_class_change(User* head, int c);

// Login and change password
bool compare_m(Password_m* head, char* n, Password_m** p_current);
bool compare_u(Password_u* head, char* n, Password_u** p_current);
bool compare_d(Password_d* head, char* n, Password_d** p_current);

//write the password into the file
void m_writeIntoFile_p(Password_m* head);
void u_writeIntoFile_p(Password_u* head);
void d_writeIntoFile_p(Password_d* head);
//read the password from the file
void m_readIntoList_p(Password_m** head);
void u_readIntoList_p(Password_u** head);
void d_readIntoList_p(Password_d** head);
//register
// Create password list
Password_m* m_creatNode_p(char* n, char* p, char* pn);
void m_createList_p(Password_m** head, Password_m** tail, Password_m* newNode);
Password_u* u_creatNode_p(char* n, char* p, char* pn);
void u_createList_p(Password_u** head, Password_u** tail, Password_u* newNode);
Password_d* d_creatNode_p(char* n, char* p, char* pn);
void d_createList_p(Password_d** head, Password_d** tail, Password_d* newNode);

// Find account in the list
Merchant* find_m(Merchant* head, char* n);
User* find_u(User* head, char* n);
DeliveryPerson* find_d(DeliveryPerson* head, char* n);

// Set the state of the order
void set_state_o(order* tail, int s);
// Synchronization order statement
void Synchronization_o_s(order* tail, Merchant* m_head, User* u_head);

//to find a special r_classify in onre Merchant
r_classify* find_r_classify(Merchant* merchant, const char* classify_name);

//delete specific node in the list
bool delete_specific_r_class(r_classify** current, r_classify** head, r_classify** tail);
bool delete_specific_recipe(recipe** current, recipe** head, recipe** tail);
bool delete_specific_order(order** current, order** head, order** tail);
bool delete_specific_merchant(Merchant** current, Merchant** head, Merchant** tail);

//delete node by tree
bool delete_recipe_name(t_recipe** root, char* name, recipe** head, recipe** tail);
bool delete_order_id(t_order** root, char* order_id, order** head, order** tail);
bool delete_Merchant_name(t_Merchant** root, char* name, Merchant** head, Merchant** tail);

#endif
