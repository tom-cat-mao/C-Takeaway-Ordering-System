#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

// Find account in the list
struct Merchant* find_m(struct Merchant* head, char* n)
{
	struct Merchant* current = head;
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

struct User* find_u(struct User* head, char* n)
{
	struct User* current = head;
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

struct DeliveryPerson* find_d(struct DeliveryPerson* head, char* n)
{
	struct DeliveryPerson* current = head;
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