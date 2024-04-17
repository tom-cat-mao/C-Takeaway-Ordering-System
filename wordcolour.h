#pragma once
#ifndef _WORDCOLOUR_H
#define _WORDCOLOUR_H
#include <stdio.h>
#include <windows.h>
/*
the corresponding colour of word_colour
0 = black
1 = blue
3 = light green
4 = red
5 = purple
6 = yellow
7 = white
8 = gray
9 = light blue
10 = light green
11 = light light green
12 = light red
13 = light purple
14 = light yellow
15 = bright white
*/
void colour(const int word_colour)
{
    if (word_colour >= 0 && word_colour <= 15)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), word_colour);
    }
    else//set the word colour to default
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

}
#endif
