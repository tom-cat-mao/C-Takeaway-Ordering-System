#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//check whether the input is an intger
bool isInteger(char* str) 
{
    if (*str == '\0') 
        return false;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (i == 0 && (str[i] == '+' || str[i] == '-')) 
            continue; 
        if (str[i] < '0' || str[i] > '9') 
            return false; 
    }

    return true;
}