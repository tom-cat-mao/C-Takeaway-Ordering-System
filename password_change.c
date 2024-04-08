#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//Change merchant's password
void merchant_change_p(Merchant* head)
{
	Merchant* current = head;
	char n[100] = { "\n" };
	scanf("%s", n);
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
		printf("This account does not exist!\n");
		return;
	}
	else
	{
		int i;
		int count = 5;
		for (i = 0; i < 5; i++)
		{
			printf("Please enter old password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			if (strcmp(current->password, p) == 0)
			{
				break;
			}
			else
			{
				count--;
				printf("Wrong password! Please enter again.\nYou have %d times left.\n", count);
			}
		}
		if (i == 5)
		{
			printf("Wrong password!\n");
			return;
		}
		else
		{
			printf("Please enter new password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			strcpy(current->password, p);
		}
	}
}

//Change user's password
void user_change_p(User* head)
{
	User* current = head;
	char n[100] = { "\n" };
	scanf("%s", n);
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
		printf("This account does not exist!\n");
		return;
	}
	else
	{
		int i;
		int count = 5;
		for (i = 0; i < 5; i++)
		{
			printf("Please enter old password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			if (strcmp(current->password, p) == 0)
			{
				break;
			}
			else
			{
				count--;
				printf("Wrong password! Please enter again\nYou have %d times left.\n", count);
			}
		}
		if (i == 5)
		{
			printf("Wrong password\n");
			return;
		}
		else
		{
			printf("Please enter new password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			strcpy(current->password, p);
		}
	}
}

//Change deliver person's password
void deliveryPerson_change_p(DeliveryPerson* head)
{
	DeliveryPerson* current = head;
	char n[100] = { "\n" };
	scanf("%s", n);
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
		printf("This account does not exist!\n");
		return;
	}
	else
	{
		int i;
		int count = 5;
		for (i = 0; i < 5; i++)
		{
			printf("Please enter old password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			if (strcmp(current->password, p) == 0)
			{
				break;
			}
			else
			{
				count--;
				printf("Wrong password! Plaese enter again\nYou have %d times left.\n", count);
			}
		}
		if (i == 5)
		{
			printf("Wrong password\n");
			return;
		}
		else
		{
			printf("Please enter new password:");
			char p[100] = { "\n" };
			scanf("%s", p);
			strcpy(current->password, p);
		}
	}
}