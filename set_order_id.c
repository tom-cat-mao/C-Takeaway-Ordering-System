#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//set order id
void generateRandomString(char* str) 
{
    
    srand(time(NULL));

    int i;
    for (i = 0; i < 4; i++) 
    {
        
        str[i] = '0' + rand() % 10;
    }
    
    str[length] = '\0';
}