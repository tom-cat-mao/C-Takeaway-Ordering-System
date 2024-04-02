#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// 折扣更改
bool discount_change(double* d, int c)
{
	double n = 0;
	if(!scanf("%lf", &n))
		return false;
	d[c] = n;
	return true;
}


// 会员卡更改
bool card_class_change(User* head, int c)
{
	User* current = head;
	char n[100] = { "\n" };
	if(!scanf("%s", n))
		return false;
	while (current != NULL)
	{
		if (strcmp(current->name, n) == 0)
		{
			break;
		}
		else
		{
			current = current->next;
		}
	}
	if (current == NULL)
	{
		printf("Congratulations ,you have become our sliver card user.\n");
		current->c = 0;
	}
	else
	{
		current->c = c;
	}
	return true;
}