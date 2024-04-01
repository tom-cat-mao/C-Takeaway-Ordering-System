#define _CRT_SECURE_NO_WARNINGS
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 以菜品名称为判断标准向菜单树中插入节点（已检验）
bool insertTree_recipe_name(t_recipe** root, recipe* insert) {
    if (*root == NULL) {
        *root = creatTree_recipe(insert);
        return TRUE;
    }
    // 递归寻找插入位置
    t_recipe* current = *root;
    while (1) {
        if (strcmp((insert)->name, current->r_node->name) < 0) {
            // 插入菜品的名称小于当前节点菜品的名称
            if (current->left == NULL) {
                // 当左子树为空时，创建新节点并将其插入左子树
                current->left = creatTree_recipe(insert);
                return TRUE;
            }
            else {
                current = current->left;
            }
        }
        else { // strcmp((*insert)->name, current->r_node->name) > 0
            // 插入菜品的名称大于当前节点菜品的名称
            if (current->right == NULL) {
                // 当右子树为空时，创建新节点并将其插入右子树
                current->right = creatTree_recipe(insert);
                return TRUE;
            }
            else {
                current = current->right;
            }
        }
    }
}
// 以订单的订单号为判断标准向订单树中插入节点
bool insertTree_order_id(t_order** root, order* insert) {
    if (*root == NULL) {
        *root = creatTree_order(insert);
        return TRUE;
    }
    // 递归寻找插入位置
    t_order* current = *root;
    while (1)
    {
        if (strcmp((insert)->order_id, current->o_node->order_id) < 0)
        {
            // 插入订单的订单号小于当前节点订单的订单号
            if (current->left == NULL)
            {
                // 当左子树为空时，创建新节点并将其插入左子树
                current->left = creatTree_order(insert);
                return TRUE;
            }
            else
            {
                current = current->left;
            }
        }
        else // strcmp((insert)->order_id, current->o_node->order_id) > 0
        {
            // 插入订单的订单号大于当前节点订单的订单号
            if (current->right == NULL) {
                // 当右子树为空时，创建新节点并将其插入右子树
                current->right = creatTree_order(insert);
                return TRUE;
            }
            else {
                current = current->right;
            }
        }
    }
}
// 以商家名称为判断标准向商家树中插入节点
bool insertTree_Merchant_name(t_Merchant** root, Merchant* insert) {
    if (*root == NULL) {
        *root = creatTree_Merchant(insert);
        return TRUE;
    }
    // 递归寻找插入位置
    t_Merchant* current = *root;
    while (1)
    {
        if (strcmp((insert)->name, current->M_node->name) < 0)
        {
            // 插入的商家名称小于当前节点的商家名称
            if (current->left == NULL)
            {
                // 当左子树为空时，创建新节点并将其插入左子树
                current->left = creatTree_Merchant(insert);
                return TRUE;
            }
            else
            {
                current = current->left;
            }
        }
        else // strcmp((insert)->name, current->M_node->name) > 0
        {
            // 插入的商家名称大于当前节点的商家名称
            if (current->right == NULL) {
                // 当右子树为空时，创建新节点并将其插入右子树
                current->right = creatTree_Merchant(insert);
                return TRUE;
            }
            else {
                current = current->right;
            }
        }
    }
}