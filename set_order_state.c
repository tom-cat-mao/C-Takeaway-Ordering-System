#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// Set the state of the order
void set_state_o(order* tail, int s)
{
	tail->s = s;
	if (s == 1)
	{
		set_time(tail->send_time);
	}
	if (s == 2)
	{
		set_time(tail->arrive_time);
	}
}