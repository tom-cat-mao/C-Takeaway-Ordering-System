#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// create a new recipe node for the tree
struct t_recipe* creatTree_recipe(struct recipe* example)
{
    struct t_recipe* newNode = (struct t_recipe*)malloc(sizeof(struct t_recipe));
    if (newNode == NULL) 
    {
        printf("Recipe Tree error");
        return NULL;
    }
    newNode->r_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// create a new order node for the tree
struct t_order* creatTree_order(struct order* example)
{
    struct t_order* newNode = (struct t_order*)malloc(sizeof(struct t_order));
    if (newNode == NULL) 
    {
        printf("Order Tree error");
        return NULL;
    }
    newNode->o_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// create a new merchant node for the tree
struct t_Merchant* creatTree_Merchant(struct Merchant* example)
{
    struct t_Merchant* newNode = (struct t_Merchant*)malloc(sizeof(struct t_Merchant));
    if (newNode == NULL) 
    {
        printf("Merchant Tree error");
        return NULL;
    }
    newNode->M_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}