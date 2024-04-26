#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//1-10
int getRandomNumber_1() 
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

//10-50
int getRandomNumber_2()
{
    srand(time(NULL));
    return rand() % 41 + 10;
}

//50-100
int getRandomNumber_3()
{
    srand(time(NULL));
    return rand() % 51 + 50;
}