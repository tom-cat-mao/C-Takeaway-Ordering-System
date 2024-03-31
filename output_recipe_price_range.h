#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include"mergeSortRecipe.h"

//按价格从高到低输出菜品
void output_recipe_high_to_low(recipe* head, float minPrice, float maxPrice)
{
    // 首先对菜品链表从高到低排序
    r_mergeSortLower(&head);
    // 遍历链表，输出在价格区间内的菜品名称
    recipe* current = head;
    while (current != NULL && current->price >= minPrice) {
        if (current->price <= maxPrice) 
        {
            printf("菜品名称：%s\t价格：%.2f\n", current->name, current->price);
        }
        current = current->next;
    }
}
//按价格从低到高输出菜品
void output_recipe_low_to_high(recipe* head, float minPrice, float maxPrice) {
    // 首先对菜品链表从低到高排序
    r_mergeSortUpper(&head);

    // 遍历链表，输出在价格区间内的菜品名称
    recipe* current = head;
    while (current != NULL && current->price <= maxPrice) {
        if (current->price >= minPrice) {
            printf("菜品名称：%s\t价格：%.2f\n", current->name, current->price);
        }
        current = current->next;
    }
}