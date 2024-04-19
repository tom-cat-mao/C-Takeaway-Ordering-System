#pragma once
#ifndef _INTERFACE_H
#define _INTERFACE_H
#include "wordcolour.h"
//some little fuctions
void print_Title()
{
	//with the width of 50
	colour(6);//set the colour to yellow
	printf("|--------------------------------------------------|\n");
	printf("|\t\t  HAVE YOU EATEN?\t\t   |\n");
	printf("|--------------------------------------------------|\n\n\n");
	colour(7);//set the colour to default;
}
void print_Exit(int i)
{
	printf("|   ");
	colour(12);
	printf("%d.Close",i);
	colour(7);
	printf("                                        |\n");
}
void print_Logout(int i)
{
	printf("|   ");
	colour(12);
	printf("%d.Log out",i);
	colour(7);
	printf("                                      |\n");
}
void print_ChooseNumber(int first, int last)
{
	printf("|-- Please select the corresponding numbers ");
	colour(6);
	printf("%d", first);
	colour(7);
	printf("-");
	colour(6);
	printf("%d", last);
	colour(7);
	0 - 3;
	printf(" ---| \n");
}
void illegal_number()
{   
	system("cls");
	print_Title();
	colour(12);
	printf("The number you enter is illegal!\n");
	colour(7);
	printf("Press Enter to continue.\n");
	getchar();
}


// the following are the real print functions

//choose identity/sign in&up
void choose_identity()
{
	system("cls");
	print_Title();
	printf("Please choose your identity:\n");
	printf("|   1.User               |   2.Merchant            |\n");
	printf("|   3.Delivery Preson                              |\n");
	print_Exit(0);
	print_ChooseNumber(0, 3);
}
void choose_sign()
{
	system("cls");//clear the screen
	//enter 1 to sign in, enter 2 to sign up
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Sign in            |   2.Sign up             |\n");
	printf("|   0.Return                                       |\n");
	print_ChooseNumber(0, 2);
}

//Merchant
void main_menu_Merchant_1(char *name)
{
	system("cls");
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n",name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Your Recipes       |   2.Your Orders         |\n");
	printf("|   3.Password                                     |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);
}
void main_menu_Merchant_2()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Recipe Class       |   2.Recipe              |\n");
	printf("|   3.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);
}
void main_menu_Merchant_3()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Add Recipe Class   |   2.Delete Recipe Class |\n");
	printf("|   3.Change Recipe Class's Name                   |\n");
	printf("|   4.Inquiry Recipe Class                         |\n");
	printf("|   5.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 5);
}
void main_menu_Merchant_4()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Continue           |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_Merchant_5()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Add Recipe          |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Merchant_6()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Add Recipe         |   2.Delete Recipe       |\n");
	printf("|   3.Move Recipe        |   4.Inquiry Recipe      |\n");
	printf("|   5.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 5);
}
void main_menu_Merchant_7()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Continue            |\n");
	print_ChooseNumber(0, 1);
}

//User
void main_menu_User(char* name)
{
	system("cls"); 
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Make Order         |   2.History Order       |\n");
	printf("|   3.Password           |                         |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);

}

//DeliveryPerson
void main_menu_DeliveryPerson_1(char* name)
{
	system("cls"); 
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Tasks              |   2.Change Password     |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}
void main_menu_DeliveryPerson_2()
{
	system("cls");
	print_Title();
	printf("Which operation do you want to perform?\n");
	printf("|   1.Set The Order      |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}
void main_menu_DeliveryPerson_3()
{
	system("cls");
	print_Title();
	printf("Please enter the statement of the order:\n");
	printf("|   1.Delivering         |   2.Finish              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}




//Manager
void main_menu_Manager(char* name)
{
	system("cls");
	print_Title();
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Change the discount of cards                 |\n");
	print_Logout(0);
	print_ChooseNumber(0, 1);
}



#endif
