#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Delete a node from the menu tree (recipe) with the product name as the judgment standard
bool delete_recipe_name(struct t_recipe** root, char* name, struct recipe** head, struct  recipe** tail)
{
    if (*root == NULL)
    {
        return false;
    }

    if (strcmp(name, (*root)->r_node->name) < 0)
    {
        delete_recipe_name(&((*root)->left), name,head,tail);
    }
    else if (strcmp(name, (*root)->r_node->name) > 0) 
    {
        delete_recipe_name(&((*root)->right), name,head,tail);
    }
    else // Found the node to be deleted
    {
        struct t_recipe* temp;

        //delete the node in the list
        struct recipe* current = (*root)->r_node;
        delete_specific_recipe(&current, head, tail);

        // No child nodes or only one child node exists
        if ((*root)->left == NULL) 
        {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return true;
        }
        else if ((*root)->right == NULL) 
        {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return true;
        }
        else
        {
            // Both child nodes exist, find the smallest node of the right subtree to replace the current node
            struct  t_recipe* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->r_node->name, minValueNode->r_node->name);
            delete_recipe_name(&((*root)->right), minValueNode->r_node->name, head, tail);
        }
    }
}

// Delete a node from the order tree with the order number as the judgment standard
bool delete_order_id(struct t_order** root, char* order_id, struct order** head, struct order** tail)
{
    if (*root == NULL) 
    {
        return false;
    }

    if (strcmp(order_id, (*root)->o_node->order_id) < 0) 
    {
        delete_order_id(&((*root)->left), order_id,head, tail);
    }
    else if (strcmp(order_id, (*root)->o_node->order_id) > 0) 
    {
        delete_order_id(&((*root)->right), order_id, head, tail);
    }
    else // Found the node to be deleted
    {
        struct t_order* temp;

        //delete the node in the list
        struct order* current = (*root)->o_node;
        delete_specific_order(&current, head, tail);
        
        // No child nodes or only one child node exists
        if ((*root)->left == NULL) 
        {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return true;
        }
        else if ((*root)->right == NULL)
        {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return true;
        }
        else
        {
            // Both child nodes exist, find the smallest node of the right subtree to replace the current node
            struct t_order* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->o_node->order_id, minValueNode->o_node->order_id);
            delete_order_id(&((*root)->right), minValueNode->o_node->order_id, head, tail);
        }
    }
}

// Delete a node from the merchant tree with the merchant name as the judgment standard
bool delete_Merchant_name(struct t_Merchant** root, char* name, struct  Merchant** head, struct Merchant** tail)
{
    if (*root == NULL)
    {
        return false;
    }

    if (strcmp(name, (*root)->M_node->name) < 0) 
    {
        delete_Merchant_name(&((*root)->left), name, head, tail);
    }
    else if (strcmp(name, (*root)->M_node->name) > 0) 
    {
        delete_Merchant_name(&((*root)->right), name, head, tail);
    }
    else // Found the node to be deleted
    {
        struct  t_Merchant* temp;

        //delete the node in the list
        struct Merchant* current = (*root)->M_node;
        delete_specific_merchant(&current, head, tail);
        
        // No child nodes or only one child node exists
        if ((*root)->left == NULL) 
        {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return true;
        }
        else if ((*root)->right == NULL) 
        {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return true;
        }
        else
        {
            // Both child nodes exist, find the smallest node of the right subtree to replace the current node
            struct  t_Merchant* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->M_node->name, minValueNode->M_node->name);
            delete_Merchant_name(&((*root)->right), minValueNode->M_node->name, head, tail);
        }
    }
}