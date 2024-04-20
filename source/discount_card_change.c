#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

// Change discount
bool discount_change(double* d, int c)
{
	double n = 0;
	if(!scanf("%lf", &n))
		return false;
	d[c] = n;
	return true;
}

// Change membership card
bool card_class_change(struct User* head, int c)
{
	struct User* current = head;
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
		printf("Congratulations, you have become our silver card user.\n");
		current->c = SILVER;
	}
	else
	{
		current->c = c;
	}
	return true;
}