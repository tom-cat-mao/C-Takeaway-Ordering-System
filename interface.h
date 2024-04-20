#pragma once
#ifndef _INTERFACE_H
#define _INTERFACE_H
#include "wordcolour.h"


void print_Title()
{
	//with the width of 50
	colour(6);//set the colour to yellow
	printf("|--------------------------------------------------|\n");
	printf("|\t\t  HAVE YOU EATEN?\t\t   |\n");
	printf("|--------------------------------------------------|\n\n\n");
	colour(7);//set the colour to default;
}
void print_Exit()
{
	printf("|   ");
	colour(12);
	printf("0.Exit");
	colour(7);
	printf("                                         |\n");
}
void before_sign()
{
	system("cls");//clear the screen
	//enter 1 to sign in, enter 2 to sign up
	print_Title();
	printf("Please choose a number:\n");
	printf("1:Sign in\n");
	printf("2:Sign up\n");
}
void main_menu_Merchant(char *name)
{
	system("cls");
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n",name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Your Recipes       |   2.Password            |\n");
	print_Exit();
	printf("|-- Please select the corresponding numbers 0-6 ---|\n");
}
void main_menu_User(char* name)
{
	system("cls"); 
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Make Order         |   2.History Order       |\n");
	printf("|   3.Password           |                         |\n");
	print_Exit();
	printf("|-- Please select the corresponding numbers 0-3 ---|\n");

}
void main_menu_DeliveryPerson(char* name)
{
	system("cls"); 
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Tasks              |   2.Password            |\n");
	print_Exit();
	printf("|-- Please select the corresponding numbers 0-2 ---|\n");

}
void main_menu_Manager(char* name)
{
	system("cls");
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Change the discount of cards                 |\n");
	print_Exit();
	printf("|-- Please select the corresponding numbers 0-1 ---|\n");
}




#endif
