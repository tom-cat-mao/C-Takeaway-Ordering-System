#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

double discount[3] = { 0.9,0.85,0.75 }; // Different cards corresponding discounts
enum card { SILVER, GOLD, PLATINUM }; // User membership type
enum state_o { WAY, DILLVERING, FINISH }; // Order status
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

    // Order ID
    struct order* head;

    struct User* prev;
    struct User* next;

}User;

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

// Print linked list

// Print menu dishes
void printList_recipe_1(recipe* head);
// Print order dishes
void printList_recipe_2(recipe* head);
// Print dish classification
void printList_r_classify(r_classify* head);
// Print order list
void print_order_list(order* head);
// Print merchant list
void printList_merchant(Merchant* head);

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
void merchant_change_p(Merchant* head);
// Change user password
void user_change_p(User* head);
// Change delivery person password
void deliveryPerson_change_p(DeliveryPerson* head);

// Change membership discount
bool discount_change(double* d, int c);
// Change user membership type
bool card_class_change(User* head, int c);

// Login and change password
bool compare(char *f_name,char* n);
void writeIntoFile_p(char * f_name ,char* n, char* p);
void updatePassword(char * f_name ,char* n, char* new_p);

#endif
