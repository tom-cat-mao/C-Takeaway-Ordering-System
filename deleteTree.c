#define _CRT_SECURE_NO_WARNINGS
#include "classTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// 以菜品名称为判断标准从菜单树中删除节点（已检验）
bool delete_recipe_name(t_recipe** root, char* name) {
    if (*root == NULL) {
        return FALSE;
    }

    if (strcmp(name, (*root)->r_node->name) < 0) {
        delete_recipe_name(&((*root)->left), name);
    }
    else if (strcmp(name, (*root)->r_node->name) > 0) {
        delete_recipe_name(&((*root)->right), name);
    }
    else // 找到需要删除的节点
    {
        t_order* temp;
        // 没有子节点或只有一个子节点的情况
        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return TRUE;
        }
        else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return TRUE;
        }
        else
        {
            // 有两个子节点的情况，找到右子树中最小的节点替代当前节点
            t_recipe* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->r_node->name, minValueNode->r_node->name);
            delete_recipe_name(&((*root)->right), minValueNode->r_node->name);
        }
    }
}
// 以订单号为判断标准从订单树中删除节点
bool delete_order_id(t_order** root, char* order_id) {
    if (*root == NULL) {
        return FALSE;
    }

    if (strcmp(order_id, (*root)->o_node->order_id) < 0) {
        delete_order_id(&((*root)->left), order_id);
    }
    else if (strcmp(order_id, (*root)->o_node->order_id) > 0) {
        delete_order_id(&((*root)->right), order_id);
    }
    else // 找到需要删除的节点
    {
        t_order* temp;
        // 没有子节点或只有一个子节点的情况
        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return TRUE;
        }
        else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return TRUE;
        }
        else
        {
            // 有两个子节点的情况，找到右子树中最小的节点替代当前节点
            t_order* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->o_node->order_id, minValueNode->o_node->order_id);
            delete_order_id(&((*root)->right), minValueNode->o_node->order_id);
        }
    }
}
// 以商家名称为判断标准从商家树中删除节点
bool delete_Merchant_name(t_Merchant** root, char* name) {
    if (*root == NULL) {
        return FALSE;
    }

    if (strcmp(name, (*root)->M_node->name) < 0) {
        delete_Merchant_name(&((*root)->left), name);
    }
    else if (strcmp(name, (*root)->M_node->name) > 0) {
        delete_Merchant_name(&((*root)->right), name);
    }
    else // 找到需要删除的节点
    {
        t_order* temp;
        // 没有子节点或只有一个子节点的情况
        if ((*root)->left == NULL) {
            temp = *root;
            *root = (*root)->right;
            free(temp);
            return TRUE;
        }
        else if ((*root)->right == NULL) {
            temp = *root;
            *root = (*root)->left;
            free(temp);
            return TRUE;
        }
        else
        {
            // 有两个子节点的情况，找到右子树中最小的节点替代当前节点
            t_Merchant* minValueNode = (*root)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }
            strcpy((*root)->M_node->name, minValueNode->M_node->name);
            delete_Merchant_name(&((*root)->right), minValueNode->M_node->name);
        }
    }
}
