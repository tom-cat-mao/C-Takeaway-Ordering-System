#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// search for the free delivery preson
DeliveryPerson* find_free_d(DeliveryPerson* head)
{
	int flag = 0;
	DeliveryPerson* current = head;
	while (current != NULL)
	{
		if (current->s == FREE)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}

	if (flag == 1)
	{
		return current;
	}
	else
	{
		printf("there is no delivery person free now\n");
		return NULL;
	}
}