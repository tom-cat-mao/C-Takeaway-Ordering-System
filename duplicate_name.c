#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//check duplicate name
bool duplicate_name_u(struct Password_u* head, char* name)
{
	int flag = 0;
	struct Password_u* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool duplicate_name_m(struct Password_m* head, char* name)
{
	int flag = 0;
	struct Password_m* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool duplicate_name_d(struct Password_d* head, char* name)
{
	int flag = 0;
	struct Password_d* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}