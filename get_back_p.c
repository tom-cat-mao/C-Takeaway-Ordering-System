#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include "interface.h"

//get back password
bool get_back_p_u(struct Password_u* head, char* name, char* phone)
{
	int flag = 0;
	struct Password_u* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0 && strcmp(phone, current->phone) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		printf("Your password:%s\n", current->password);
		sleep();
		return true;
	}
	else
	{
		return false;
	}
}

bool get_back_p_d(struct Password_d* head, char* name, char* phone)
{
	int flag = 0;
	struct Password_d* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0 && strcmp(phone, current->phone) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		printf("Your password:%s\n", current->password);
		sleep();
		return true;
	}
	else
	{
		return false;
	}
}

bool get_back_p_m(struct Password_m* head, char* name, char* phone)
{
	int flag = 0;
	struct Password_m* current = head;
	while (current != NULL)
	{
		if (strcmp(name, current->name) == 0 && strcmp(phone, current->phone) == 0)
		{
			flag = 1;
			break;
		}
		current = current->next;
	}
	if (flag == 1)
	{
		printf("Your password:%s\n", current->password);
		sleep();
		return true;
	}
	else
	{
		return false;
	}
}