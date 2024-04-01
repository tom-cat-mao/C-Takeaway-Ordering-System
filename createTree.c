#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 创建新的菜单树节点(已检验）
t_recipe* creatTree_recipe(recipe* example)
{
    t_recipe* newNode = (t_recipe*)malloc(sizeof(t_recipe));
    if (newNode == NULL) {
        printf("Recipe Tree error");
        return NULL;
    }
    newNode->r_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 创建新的订单树节点
t_order* creatTree_order(order* example)
{
    t_order* newNode = (t_order*)malloc(sizeof(t_order));
    if (newNode == NULL) {
        printf("Order Tree error");
        return NULL;
    }
    newNode->o_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 创建新的商家树节点
t_Merchant* creatTree_Merchant(Merchant* example)
{
    t_Merchant* newNode = (t_Merchant*)malloc(sizeof(t_Merchant));
    if (newNode == NULL) {
        printf("Merchant Tree error");
        return NULL;
    }
    newNode->M_node = example;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}