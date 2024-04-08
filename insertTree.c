#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// insert a recipe name node into the tree
bool insertTree_recipe_name(t_recipe** root, recipe* insert) {
    if (*root == NULL) {
        *root = creatTree_recipe(insert);
        return true;
    }

    // create a new node for the tree
    t_recipe* current = *root;
    while (1) {
        if (strcmp((insert)->name, current->r_node->name) < 0) {
            if (current->left == NULL) {
                // when the left child is null, create a new node and link it to the left child
                current->left = creatTree_recipe(insert);
                return true;
            }
            else {
                current = current->left;
            }
        }
        else { // strcmp((*insert)->name, current->r_node->name) > 0
            // when the recipe name is greater than the current node's recipe name
            if (current->right == NULL) {
                // when the right child is null, create a new node and link it to the right child
                current->right = creatTree_recipe(insert);
                return true;
            }
            else {
                current = current->right;
            }
        }
    }
}

// use the custom order id as the standard to insert nodes into the tree
bool insertTree_order_id(t_order** root, order* insert) {
    if (*root == NULL) {
        *root = creatTree_order(insert);
        return true;
    }
    // recursively find the insertion location
    t_order* current = *root;
    while (1)
    {
        if (strcmp((insert)->order_id, current->o_node->order_id) < 0)
        {
            // when the order id is less than the current node's order id
            if (current->left == NULL)
            {
                // when the left child is null, create a new node and link it to the left child
                current->left = creatTree_order(insert);
                return true;
            }
            else
            {
                current = current->left;
            }
        }
        else // strcmp((insert)->order_id, current->o_node->order_id) > 0
        {
            // when the order id is greater than the current node's order id
            if (current->right == NULL) {
                // when the right child is null, create a new node and link it to the right child
                current->right = creatTree_order(insert);
                return true;
            }
            else {
                current = current->right;
            }
        }
    }
}

// use the merchant name as the standard to insert nodes into the tree
bool insertTree_Merchant_name(t_Merchant** root, Merchant* insert) {
    if (*root == NULL) {
        *root = creatTree_Merchant(insert);
        return true;
    }
    // recursively find the insertion location
    t_Merchant* current = *root;
    while (1)
    {
        if (strcmp((insert)->name, current->M_node->name) < 0)
        {
            // when the merchant name is less than the current node's merchant name
            if (current->left == NULL)
            {
                // when the left child is null, create a new node and link it to the left child
                current->left = creatTree_Merchant(insert);
                return true;
            }
            else
            {
                current = current->left;
            }
        }
        else // strcmp((insert)->name, current->M_node->name) > 0
        {
            // when the merchant name is greater than the current node's merchant name
            if (current->right == NULL) {
                // when the right child is null, create a new node and link it to the right child
                current->right = creatTree_Merchant(insert);
                return true;
            }
            else {
                current = current->right;
            }
        }
    }
}