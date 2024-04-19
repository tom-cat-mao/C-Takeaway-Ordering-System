#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//find recipe by list
recipe* find_recipe_by_list(r_classify* head, char* name)
{
	int flag = 0;

	recipe* current = head->r_head;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			flag = 0;
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
		return NULL;
	}
}