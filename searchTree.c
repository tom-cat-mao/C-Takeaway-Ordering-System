#define _CRT_SECURE_NO_WARNINGS
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//以菜品名称为判断标准从菜单树中查找节点,返回菜品链表中的节点
recipe* search_recipe_name(t_recipe* root, const char* recipe_name) {
    //如果根节点为空，或者菜品名称为空，返回空指针
    if (root == NULL || recipe_name == NULL) {
        return NULL;
    }
    //循环遍历菜单树节点
    while (root != NULL) {
        //如果找到匹配的菜品名称，返回菜品节点
        if (strcmp(recipe_name, root->r_node->name) == 0) {
            return root->r_node;
        }
        else if (strcmp(recipe_name, root->r_node->name) < 0) {
            root = root->left;
        }
        else //strcmp(recipe_name, root->r_node->name) > 0
        {
            root = root->right;
        }
    }
    // 如果未找到匹配的菜品名称，返回空指针
    return NULL;
}
//以订单号为判断标准从订单树中查找节点,返回订单链表中的节点
order* search_order_id(t_order* root, const char* order_id) {
    //如果根节点为空，或者订单号为空，返回空指针
    if (root == NULL || order_id == NULL) {
        return NULL;
    }
    //循环遍历树节点
    while (root != NULL) {
        //如果找到匹配的订单号，返回订单节点
        if (strcmp(order_id, root->o_node->order_id) == 0) {
            return root->o_node;
        }
        else if (strcmp(order_id, root->o_node->order_id) < 0) {
            root = root->left;
        }
        else //strcmp(order_id, root->o_node->order_id)>0
        {
            root = root->right;
        }
    }
    // 如果未找到匹配的订单号，返回空指针
    return NULL;
}
// 以商家名称为判断标准从商家树中查找节点,返回商家链表中的节点
Merchant* search_Merchant_name(t_Merchant* root, const char* Merchant_name)
{
    //如果根节点为空，或者商家名称为空，返回空指针
    if (root == NULL || Merchant_name == NULL) {
        return NULL;
    }
    //循环遍历树节点
    while (root != NULL) {
        //如果找到匹配的商家名称，返回商家节点
        if (strcmp(Merchant_name, root->M_node->name) == 0) {
            return root->M_node;
        }
        else if (strcmp(Merchant_name, root->M_node->name) < 0) {
            root = root->left;
        }
        else //strcmp(Merchant_name, root->M_node->name)>0
        {
            root = root->right;
        }
    }
    // 如果未找到匹配的商家名称，返回空指针
    return NULL;
}