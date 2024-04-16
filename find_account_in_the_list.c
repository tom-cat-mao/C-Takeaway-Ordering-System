#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Find account in the list
Merchant* find_m(Merchant* head, char* n)
{
	Merchant* current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, n) == 0)
		{
			break;
		}
		current = current->next;
	}
	return current;
}

User* find_u(User* head, char* n)
{
	User* current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, n) == 0)
		{
			break;
		}
		current = current->next;
	}
	return current;
}

DeliveryPerson* find_d(DeliveryPerson* head, char* n)
{
	DeliveryPerson* current = head;
	while (current != NULL)
	{
		if (strcmp(current->name, n) == 0)
		{
			break;
		}
		current = current->next;
	}
	return current;
}