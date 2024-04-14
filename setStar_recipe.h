#pragma once
#ifndef _SETSTAR_RECIPE
#define _SETSTAR_RECIPE
#include "class.h"
int generateRandomNumber()
{
    // set a seed
    srand(time(NULL));

    // generate a random int from one to five
    int randomNumber = rand() % 5+1;

    return randomNumber;
}
#endif