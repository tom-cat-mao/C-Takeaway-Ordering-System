#pragma once
#ifndef _WORDCOLOUR_H
#define _WORDCOLOUR_H
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define COLOR_FORE_RED      "\x1b[31m"//set the foreground color to red
#define COLOR_FORE_GREEN    "\x1b[32m"//set the foreground color to green
#define COLOR_FORE_BACK_DEFAULT   "\x1b[39m"//set both ground colors to defluat
#define COLOR_BACK_DEFLAUT  "\x1b[49m"//set the background color to defluat
#include <windows.h>
#define CONFIG_CONSOLE_COLOR \
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); \
if (hOut == INVALID_HANDLE_VALUE) \
{ \
    return GetLastError(); \
} \
DWORD dwMode = 0; \
if (!GetConsoleMode(hOut, &dwMode)) \
{ \
    return GetLastError(); \
} \
dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; \
if (!SetConsoleMode(hOut, dwMode)) \
{ \
    return GetLastError(); \
}
#endif