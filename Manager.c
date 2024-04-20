#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

void change_discount_manager(char* card_level, double new_value)
{
    if (!strcmp(card_level,"PLATINUM"))
    {
        discount[0] = new_value;
        printf("The discount of PLATINUM member has been set to %.2f\n", discount[0]);
    }
    else if (!strcmp(card_level, "SILVER"))
    {
        discount[1] = new_value;
        printf("The discount of SILVER member has been set to %.2f\n", discount[1]);
    }
    else if (!strcmp(card_level, "GOLD"))
    {
        discount[2] = new_value;
        printf("The discount of GOLD member has been set to %.2f\n", discount[2]);
    }
}
