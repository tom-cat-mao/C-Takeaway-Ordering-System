#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"class.h"
#include"mergeSortRecipe.h"
#include"output_recipe_price_range.h"

int main() {
    // 创建一些菜品节点
    recipe* dish1 = (recipe*)malloc(sizeof(recipe));
    strcpy(dish1->name, "鱼香肉丝");
    dish1->price = 25.0;
    dish1->next = NULL;

    recipe* dish2 = (recipe*)malloc(sizeof(recipe));
    strcpy(dish2->name, "宫保鸡丁");
    dish2->price = 30.0;
    dish2->next = NULL;

    recipe* dish3 = (recipe*)malloc(sizeof(recipe));
    strcpy(dish3->name, "红烧肉");
    dish3->price = 35.0;
    dish3->next = NULL;

    // 构建菜品链表
    dish1->next = dish2;
    dish2->next = dish3;

    // 打印完整菜单
    printf("完整菜单：\n");
    recipe* current = dish1;
    while (current != NULL) {
        printf("菜品名称：%s\t价格：%.2f\n", current->name, current->price);
        current = current->next;
    }

    // 打印价格区间内的菜品，从低到高
    printf("\n价格区间内的菜品，从低到高（30-35）：\n");
    output_recipe_low_to_high(dish1, 30.0, 35.0);

    // 打印价格区间内的菜品，从高到低
    printf("\n价格区间内的菜品，从高到低（30-35）：\n");
    output_recipe_high_to_low(dish1, 30.0, 35.0);

    // 释放内存
    free(dish1);
    free(dish2);
    free(dish3);

    return 0;
}

