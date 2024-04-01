#pragma once
#ifndef CLASSTREE_H
#define CLASSTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 菜单树节点
typedef struct t_recipe
{
    recipe* r_node;

    struct t_recipe* left;
    struct t_recipe* right;
} t_recipe;
// 订单树节点
typedef struct t_order
{
    order* o_node;

    struct t_order* left;
    struct t_order* right;
}t_order;
// 商家树节点
typedef struct t_Merchant
{
    Merchant* M_node;

    struct t_Merchant* left;
    struct t_Merchant* right;
}t_Merchant;

//创建树
// 创建新的菜单树节点(已检验）
t_recipe* creatTree_recipe(recipe* example);
// 创建新的订单树节点
t_order* creatTree_order(order* example);
// 创建新的商家树节点
t_Merchant* creatTree_Merchant(Merchant* example);

//插入节点
// 以菜品名称为判断标准向菜单树中插入节点（已检验）
bool insertTree_recipe_name(t_recipe** root, recipe* insert);
// 以订单的订单号为判断标准向订单树中插入节点
bool insertTree_order_id(t_order** root, order* insert);
// 以商家名称为判断标准向商家树中插入节点
bool insertTree_Merchant_name(t_Merchant** root, Merchant* insert);

//删除节点
// 以菜品名称为判断标准从菜单树中删除节点（已检验）
bool delete_recipe_name(t_recipe** root, char* name);
// 以订单号为判断标准从订单树中删除节点
bool delete_order_id(t_order** root, char* order_id);
// 以商家名称为判断标准从商家树中删除节点
bool delete_Merchant_name(t_Merchant** root, char* name);

//精准查询节点
//以菜品名称为判断标准从菜单树中查找节点,返回菜品链表中的节点
recipe* search_recipe_name(t_recipe* root, const char* recipe_name);
//以订单号为判断标准从订单树中查找节点,返回订单链表中的节点
order* search_order_id(t_order* root, const char* order_id);
// 以商家名称为判断标准从商家树中查找节点,返回商家链表中的节点
Merchant* search_Merchant_name(t_Merchant* root, const char* Merchant_name);



#endif