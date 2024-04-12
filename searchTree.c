#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "classTree.h"

// Search for a node from the menu tree (recipe) with the product name as the judgment standard, and return the node containing the product name
recipe* search_recipe_name(t_recipe* root, const char* recipe_name)
{
    // If the root node is null or the product name is null, return a null pointer
    if (root == NULL || recipe_name == NULL) 
    {
        return NULL;
    }
    // Loop to traverse the menu tree nodes
    while (root != NULL) 
    {
        // If the found product name matches, return the product node
        if (strcmp(recipe_name, root->r_node->name) == 0) 
        {
            return root->r_node;
        }
        else if (strcmp(recipe_name, root->r_node->name) < 0)
        {
            root = root->left;
        }
        else //strcmp(recipe_name, root->r_node->name) > 0
        {
            root = root->right;
        }
    }
    // If no matching product name is found, return a null pointer
    return NULL;
}

// Search for a node from the order tree with the order number as the judgment standard, and return the node containing the order number
order* search_order_id(t_order* root, const char* order_id) 
{
    // If the root node is null or the order number is null, return a null pointer
    if (root == NULL || order_id == NULL)
    {
        return NULL;
    }
    // Loop to traverse the order tree nodes
    while (root != NULL) 
    {
        // If the found order number matches, return the order node
        if (strcmp(order_id, root->o_node->order_id) == 0) 
        {
            return root->o_node;
        }
        else if (strcmp(order_id, root->o_node->order_id) < 0)
        {
            root = root->left;
        }
        else //strcmp(order_id, root->o_node->order_id)>0
        {
            root = root->right;
        }
    }
    // If no matching order number is found, return a null pointer
    return NULL;
}

// Search for a node from the merchant tree with the merchant name as the judgment standard, and return the node containing the merchant name
Merchant* search_Merchant_name(t_Merchant* root, const char* Merchant_name)
{
    // If the root node is null or the merchant name is null, return a null pointer
    if (root == NULL || Merchant_name == NULL) 
    {
        return NULL;
    }
    // Loop to traverse the merchant tree nodes
    while (root != NULL)
    {
        // If the found merchant name matches, return the merchant node
        if (strcmp(Merchant_name, root->M_node->name) == 0) 
        {
            return root->M_node;
        }
        else if (strcmp(Merchant_name, root->M_node->name) < 0) 
        {
            root = root->left;
        }
        else //strcmp(Merchant_name, root->M_node->name)>0
        {
            root = root->right;
        }
    }
    // If no matching merchant name is found, return a null pointer
    return NULL;
}