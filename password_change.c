#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
#include "wordcolour.h"

//Change merchant's password
void merchant_change_p(struct Merchant* current, struct Password_m* p_current)
{
	char password[100] = { '\0' };
	printf("Please enter your new password:\n");
	scanf("%s", password);
	strcpy(current->password, password);
	strcpy(p_current->password, password);
	colour(10);
	printf("Your password has been successfully changed!\n");
	colour(7);
}

//Change user's password
void user_change_p(struct User* current, struct  Password_u* p_current)
{
	char password[100] = { '\0' };
	printf("Please enter your new password:\n");
	scanf("%s", password);
	strcpy(current->password, password);
	strcpy(p_current->password, password);
	colour(10);
	printf("Your password has been successfully changed!\n");
	colour(7);
}

//Change deliver person's password
void deliveryPerson_change_p(struct DeliveryPerson* current, struct Password_d* p_current)
{
	char password[100] = { '\0' };
	printf("Please enter your new password:\n");
	scanf("%s", password);
	strcpy(current->password, password);
	strcpy(p_current->password, password);
	colour(10);
	printf("Your password has been successfully changed!\n");
	colour(7);
}