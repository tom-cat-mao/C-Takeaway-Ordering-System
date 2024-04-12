#pragma once
#ifndef CLASSTREE_H
#define CLASSTREE_H
#include "class.h"

// Menu node
typedef struct t_recipe
{
    recipe* r_node;

    struct t_recipe* left;
    struct t_recipe* right;
} t_recipe;

// Order node
typedef struct t_order
{
    order* o_node;

    struct t_order* left;
    struct t_order* right;
}t_order;

// Merchant node
typedef struct t_Merchant
{
    Merchant* M_node;

    struct t_Merchant* left;
    struct t_Merchant* right;
}t_Merchant;

// Create node
// Create a new menu node (recipe)
t_recipe* creatTree_recipe(recipe* example);
// Create a new order node
t_order* creatTree_order(order* example);
// Create a new merchant node
t_Merchant* creatTree_Merchant(Merchant* example);

// Insert node
// Insert a node into the menu tree (recipe) with the product name as the judgment standard
bool insertTree_recipe_name(t_recipe** root, recipe* insert);
// Insert a node into the order tree with the order number as the judgment standard
bool insertTree_order_id(t_order** root, order* insert);
// Insert a node into the merchant tree with the merchant name as the judgment standard
bool insertTree_Merchant_name(t_Merchant** root, Merchant* insert);

// Delete node
// Delete a node from the menu tree (recipe) with the product name as the judgment standard
bool delete_recipe_name(t_recipe** root, char* name);
// Delete a node from the order tree with the order number as the judgment standard
bool delete_order_id(t_order** root, char* order_id);
// Delete a node from the merchant tree with the merchant name as the judgment standard
bool delete_Merchant_name(t_Merchant** root, char* name);

// Standard query node
// Search for a node from the menu tree (recipe) with the product name as the judgment standard, and return the node containing the product name
recipe* search_recipe_name(t_recipe* root, const char* recipe_name);
// Search for a node from the order tree with the order number as the judgment standard, and return the node containing the order number
order* search_order_id(t_order* root, const char* order_id);
// Search for a node from the merchant tree with the merchant name as the judgment standard, and return the node containing the merchant name
Merchant* search_Merchant_name(t_Merchant* root, const char* Merchant_name);

#endif