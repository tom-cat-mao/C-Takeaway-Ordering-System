#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

void set_time(struct tm* localTime)
{
    // Get the current system time
    time_t currentTime;

    // Get the timestamp of the current time
    currentTime = time(NULL);

    // Convert to local time
    localTime = localtime(&currentTime);
}
