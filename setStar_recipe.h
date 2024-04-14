#pragma once
#ifndef _SETSTAR_RECIPE
#define _SETSTAR_RECIPE
#include "class.h"
int generateRandomStar()
{
    // set a seed
    srand(time(NULL));

    // generate a random int from one to five
    int randomStar = rand() % 5+1;

    return randomStar;
}
#endif