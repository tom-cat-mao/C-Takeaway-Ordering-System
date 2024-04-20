#pragma once
#ifndef CLASSTREE_H
#define CLASSTREE_H
#include "class.h"

// Menu node
typedef struct t_recipe
{
    struct recipe* r_node;

    struct t_recipe* left;
    struct t_recipe* right;
};

// Order node
typedef struct t_order
{
    struct  order* o_node;

    struct t_order* left;
    struct t_order* right;
};

// Merchant node
typedef struct t_Merchant
{
    struct Merchant* M_node;

    struct t_Merchant* left;
    struct t_Merchant* right;
};

// Create node
// Create a new menu node (recipe)
struct t_recipe* creatTree_recipe(struct recipe* example);
// Create a new order node
struct t_order* creatTree_order(struct order* example);
// Create a new merchant node
struct t_Merchant* creatTree_Merchant(struct Merchant* example);

// Insert node
// Insert a node into the menu tree (recipe) with the product name as the judgment standard
bool insertTree_recipe_name(struct t_recipe** root, struct recipe* insert);
// Insert a node into the order tree with the order number as the judgment standard
bool insertTree_order_id(struct t_order** root, struct order* insert);
// Insert a node into the merchant tree with the merchant name as the judgment standard
bool insertTree_Merchant_name(struct t_Merchant** root, struct Merchant* insert);

// Delete node
// Delete a node from the menu tree (recipe) with the product name as the judgment standard
bool delete_recipe_name(struct t_recipe** root, char* name, struct recipe** head, struct recipe** tail);
// Delete a node from the order tree with the order number as the judgment standard
bool delete_order_id(struct t_order** root, char* order_id, struct order** head, struct  order** tail);
// Delete a node from the merchant tree with the merchant name as the judgment standard
bool delete_Merchant_name(struct t_Merchant** root, char* name, struct Merchant** head, struct Merchant** tail);

// Standard query node
// Search for a node from the menu tree (recipe) with the product name as the judgment standard, and return the node containing the product name
struct recipe* search_recipe_name(struct t_recipe* root, const char* recipe_name);
// Search for a node from the order tree with the order number as the judgment standard, and return the node containing the order number
struct order* search_order_id(struct t_order* root, const char* order_id);
// Search for a node from the merchant tree with the merchant name as the judgment standard, and return the node containing the merchant name
struct Merchant* search_Merchant_name(struct t_Merchant* root, const char* Merchant_name);

#endif