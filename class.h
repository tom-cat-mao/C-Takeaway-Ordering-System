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
struct recipe
{
    char name[100];          // Dish name
    float price;             // Dish price
    int num;                 // Dish quantity
    float sale_discount;     // Dish discount
    int star;                // Dish star 

    struct recipe* prev;
    struct recipe* next;
};

struct r_classify
{
    char name[100];                 // Dish classification name
    int total_number;               // Total number of dishes

    struct recipe* r_head;          // Dish linked list head
    struct recipe* r_tail;          // Dish linked list tail

    struct r_classify* prev;
    struct r_classify* next;        // Next classification
};

// Order structure
struct order
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
};

// Merchant structure
struct Merchant
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

};

// Delivery person structure
struct DeliveryPerson
{
    struct order* o_head; // Order linked list head
    struct order* o_tail; // Order linked list tail

    enum state_d s; // Status

    char password[100];
    char name[100];
    char phone[20];

    struct DeliveryPerson* prev;
    struct DeliveryPerson* next;

};

// User structure
struct User
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

};

// Password struct
struct Password_m
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_m* next;
};

struct Password_u
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_u* next;
};

struct Password_d
{
    char name[100];
    char password[100];
    char phone[100];

    struct Password_d* next;
};

// Create linked list

// Create order dish list
struct recipe* creatList_recipe_1(char* n, float p, int num);
// Create menu dish list
struct recipe* creatList_recipe_2(char* n, float p);
// Create dish classification list
struct r_classify* creatList_r_classify(char* n);
// Create order list
struct order* creatList_order(struct Merchant* m_current, struct User* u_current, struct DeliveryPerson* d_current);
// Create merchant linked list
struct Merchant* creatList_merchant(char* n, char* p, char* a, char* pn);
// Create user linked list
struct User* creatList_user(char* n, char* p, char* a, char* pn);
// Create delivery person list
struct DeliveryPerson* creatList_deliveryperson(char* n, char* p, char* pn);

// Insert the new node into the end of the list
void insertEnd_r(struct recipe** head, struct recipe** tail, struct recipe* newNode);
void insertEnd_rc(struct r_classify** head, struct r_classify** tail, struct r_classify* newNode);
void insertEnd_o(struct order** head, struct order** tail, struct order* newNode);
void insertEnd_m(struct Merchant** head, struct Merchant** tail, struct Merchant* newNode);
void insertEnd_u(struct User** head, struct User** tail, struct User* newNode);
void insertEnd_d(struct DeliveryPerson** head, struct DeliveryPerson** tail, struct DeliveryPerson* newNode);

// Print linked list

// Print menu dishes
void printList_recipe_1(struct recipe* head);
// Print order dishes
void printList_recipe_2(struct recipe* head);
// Print dish classification
void printList_r_classify(struct r_classify* head);
// Print order list
void print_order_list(struct order* tail);
// Print merchant list
void printList_merchant(struct Merchant* head);
// Print current order
void print_current_order(struct order* tail);

// Calculate discounted price for a single order
bool sumPrice(struct order* head, struct recipe* head_r, int c, double* d);

// Delete data
bool delete_order(struct order* head, char* order_id); // Delete an order
bool delete_recipe(struct recipe* head, char* name); // Delete a dish
bool delete_r_class(struct r_classify* head, char* name); // Delete a dish class
bool delete_merchant(struct Merchant* head, char* m_name); // Delete a merchant
bool delete_user(struct User* head, char* u_name); // Delete a user
bool delete_delivery_person(struct DeliveryPerson* head, char* d_name); // Delete a delivery person

// Set time
void set_time(struct tm* localTime);

// Change merchant password
void merchant_change_p(struct Merchant* current, struct Password_m* p_current);
// Change user password
void user_change_p(struct User* current, struct Password_u* p_current);
// Change delivery person password
void deliveryPerson_change_p(struct DeliveryPerson* current, struct Password_d* p_current);

// Change user membership type
bool card_class_change(struct User* current, int c);

// Login and change password
bool compare_m(struct Password_m* head, char* n, struct Password_m** p_current);
bool compare_u(struct Password_u* head, char* n, struct Password_u** p_current);
bool compare_d(struct Password_d* head, char* n, struct Password_d** p_current);

//write the password into the file
void m_writeIntoFile_p(struct Password_m* head);
void u_writeIntoFile_p(struct Password_u* head);
void d_writeIntoFile_p(struct Password_d* head);
//read the password from the file
void u_readIntoList_p(struct Password_u** head, struct Password_u** tail);
void d_readIntoList_p(struct Password_d** head, struct Password_d** tail);
void m_readIntoList_p(struct Password_m** head, struct Password_m** tail);
//register
// Create password list
struct Password_m* m_creatNode_p(char* n, char* p, char* pn);
void m_createList_p(struct Password_m** head, struct Password_m** tail, struct Password_m* newNode);
struct Password_u* u_creatNode_p(char* n, char* p, char* pn);
void u_createList_p(struct Password_u** head, struct Password_u** tail, struct Password_u* newNode);
struct Password_d* d_creatNode_p(char* n, char* p, char* pn);
void d_createList_p(struct Password_d** head, struct Password_d** tail, struct Password_d* newNode);

// Find account in the list
struct Merchant* find_m(struct Merchant* head, char* n);
struct User* find_u(struct User* head, char* n);
struct DeliveryPerson* find_d(struct DeliveryPerson* head, char* n);

// Set the state of the order
void set_state_o(struct order* tail, int s);
// Synchronization order statement
void Synchronization_o_s_for_d(struct order* tail, struct Merchant* m_head, struct User* u_head);
void Synchronization_o_s_for_u(struct order* current, struct Merchant* m_head, struct DeliveryPerson* d_head);
// Synchronization order delivery person
void Synchronization_o_d_for_m(struct order* current, struct DeliveryPerson* d_head, struct User* u_head);
void Synchronization_o_d_for_u(struct order* current, struct DeliveryPerson* d_head, struct Merchant* m_head);

//to find a special r_classify in onre Merchant
struct r_classify* find_r_classify(struct Merchant* merchant, const char* classify_name);

//delete specific node in the list
bool delete_specific_r_class(struct r_classify** current, struct r_classify** head, struct r_classify** tail);
bool delete_specific_recipe(struct recipe** current, struct recipe** head, struct recipe** tail);
bool delete_specific_order(struct order** current, struct order** head, struct order** tail);
bool delete_specific_merchant(struct Merchant** current, struct Merchant** head, struct Merchant** tail);

//delete node by tree
bool delete_recipe_name(struct t_recipe** root, char* name, struct recipe** head, struct recipe** tail);
bool delete_order_id(struct t_order** root, char* order_id, struct  order** head, struct order** tail);
bool delete_Merchant_name(struct t_Merchant** root, char* name, struct Merchant** head, struct Merchant** tail);

// search for the free delivery preson
struct DeliveryPerson* find_free_d(struct DeliveryPerson* head);
//find recipe by list
struct recipe* find_recipe_by_list(struct r_classify* head, char* name);

//change discount
void change_discount_manager(char* card_level, double new_value);

//get back password
bool get_back_p_u(struct Password_u* head, char* name, char* phone);
bool get_back_p_d(struct Password_d* head, char* name, char* phone);
bool get_back_p_m(struct Password_m* head, char* name, char* phone);

//check duplicate name
bool duplicate_name_u(struct Password_u* head, char* name);
bool duplicate_name_m(struct Password_m* head, char* name);
bool duplicate_name_d(struct Password_d* head, char* name);

#endif
