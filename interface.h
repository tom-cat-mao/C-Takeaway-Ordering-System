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
void cls_title()
{
	system("cls");
	print_Title();
}
void delete_several_lines(int numlines)
{
	// use ANSI Escape Code to clear several lines
	for (int i = 0; i < numlines; i++)
	{
		printf("\x1b[A");//move up one line
		printf("\x1b[2K");//clear this line
	}

	printf("\r");
}
void illegal_number()//"wrong choice"  illegal_number();
{   
	colour(12);
	printf("The number you enter is illegal!\n");
	colour(7);
	printf("Press Enter to continue.\n");
	getchar();
	delete_several_lines(3);
}
void upper_lower()
{
	
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Upper               |\n");
	printf("|   2.Lower                                        |\n");
	print_ChooseNumber(0, 2);
}
void lower_upper()
{

	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Lower               |\n");
	printf("|   2.Upper                                        |\n");
	print_ChooseNumber(0, 2);
}
void upper_lower_return()
{
    printf("Which operation do you want to perform?\n");
	printf("|   1.Upper              |   2.Lower               |\n");
	printf("|   3.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);
}
void lower_upper_choose()
{

	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Lower               |\n");
	printf("|   2.Upper              |   4.Choose              |\n");
	print_ChooseNumber(0, 4);
}
void sort_star_price()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Sort By Price       |\n");
	printf("|   2.Sort By Stars                                |\n");
	print_ChooseNumber(0, 2);
}
void sort_star_price_comprehensive()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Sort By Price       |\n");
	printf("|   2.Sort By Stars                                |\n");
	printf("|   3.Sort By Comprehensive                        |\n");
	print_ChooseNumber(0, 3);
}
void pause_cls()
{
	printf("Press enter to continue.\n");
	getchar();
	cls_title();
}
void sleep()   //delete_several_lines(5);illegal_number();
{
	printf("Jump after 3 seconds.");
	Sleep(1000);
	delete_several_lines(0);
	printf("Jump after 2 seconds..");
	Sleep(1000);
	delete_several_lines(0);
	printf("Jump after 1 seconds...");
	Sleep(1000);
	delete_several_lines(0);
}
void success_delete_recipe()
{
	printf("The Recipe has been successfully deleted.\n");
	sleep();
	delete_several_lines(1);
}
void success_delete_class()
{
	printf("The Class has been successfully deleted.\n");
	sleep();
	delete_several_lines(1);
}
void success_delete_merchant()
{
	printf("The Merchant has been successfully deleted.\n");
	sleep();
	delete_several_lines(1);
}
void success_add_class()
{
	printf("The Class has been successfully added.\n");
	sleep();
	delete_several_lines(1);
}
void continue_return()//delete_several_lines(5);
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Continue           |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void return_continue()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Continue            |\n");
	print_ChooseNumber(0, 1);
}
void y_n()
{
	printf("Y(Yes) or N(No) for choose this recipe:\n");
}


// the following are the real print functions

//choose identity/sign in&up  delete_several_lines(1);
void choose_identity()
{
	system("cls");
	print_Title();
	printf("Please choose your identity:\n");
	printf("|   1.User               |   2.Merchant            |\n");
	printf("|   3.Delivery Preson    |   4.Administrator       |\n");
	print_Exit(0);
	print_ChooseNumber(0, 4);
}
void choose_sign()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Sign in             |\n");
	printf("|   2.Sign up            |   3.Forget Password     |\n");
	print_ChooseNumber(0, 3);
}
void only_sign()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Sign in             |\n");
	print_ChooseNumber(0, 1);
}

//User illegal_number();
void main_menu_User_1(char* name)
{
    printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Recipe                                       |\n");
	printf("|   2.Order                                        |\n");
	printf("|   3.Password Change                              |\n");
	printf("|   4.Deactivate                                   |\n");
	print_Logout(0);
	print_ChooseNumber(0, 4);
}
void main_menu_User_2()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Choose A Merchant  |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_User_3()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Sort               |   2.Search              |\n");
	printf("|   3.Choose             |   4.Return||Finish      |\n");
	print_Logout(0);  
	print_ChooseNumber(0, 4);
}
void main_menu_User_4()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Your Recipes       |   2.Your Orders         |\n");
	printf("|   3.Password           |   4.Deactivate          |\n");
	print_Logout(0);
	print_ChooseNumber(0, 4);
}
void main_menu_User_5()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Sort               |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_User_6()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Show Order         |   2.Cancel Order        |\n");
	printf("|   3.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0,3);
}
void main_menu_User_7()//delete_several_lines(1);
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Sort in time       |   2.Sort in price       |\n");
	printf("|   3.Search             |   4.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 4);
}
void main_menu_User_8()
{
	printf("Which level would you like to change to?\n");
	printf("|   1.SILVER                                       |\n");
	printf("|   2.GOLD                                         |\n");
	printf("|   3.PLATINUM                                     |\n");
	print_ChooseNumber(1, 3);
}
void main_menu_User_9()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.accurate search     |\n");
	printf("|   2.Fuzzy Search       |   3.Search Price Range  |\n");
	printf("|   4.Sale Recipe Search                           |\n");
	print_ChooseNumber(0, 4);
}
void main_menu_User_10()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Single Inquiry      |\n");
	printf("|   2.Combination Inquiry                          |\n");
	print_ChooseNumber(0, 2);
}

//Merchant  illegal_number();
void main_menu_Merchant_1(char *name)
{
	
	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n",name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Your Recipes       |   2.Your Orders         |\n");
	printf("|   3.Password           |   4.Deactivate          |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);
}
void main_menu_Merchant_2()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Recipe Class       |   2.Recipe              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_Merchant_3()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Add Recipe Class   |   2.Delete Recipe Class |\n");
	printf("|   3.Change Recipe's Name                         |\n");
	printf("|   4.Inquiry Recipe Class                         |\n");
	printf("|   5.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 5);
}
void main_menu_Merchant_5()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Add Recipe          |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Merchant_6()//illegal_number();delete_several_lines(5);
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Add Recipe         |   2.Delete Recipe       |\n");
	printf("|   3.Move Recipe        |   4.Inquiry Recipe      |\n");
	printf("|   5.set sale recipe    |   6.Sort Recipe         |\n");
	printf("|   7.Return                                       |\n");
	print_Logout(0);
	print_ChooseNumber(0, 7);
}
void main_menu_Merchant_8()
{   
	printf("Which operation do you want to perform?\n");
	printf("|   1.Fuzzy Search       |   2.Sale Recipe Search  |\n");
	printf("|   3.Search Price Range |   4.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 4);
}
void main_menu_Merchant_9()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Set sale recipe    |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_Merchant_10()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Sort               |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);
}
void main_menu_Merchant_11()
{
	printf("Which operation do you want to perform?\n");
	printf("|   1.Distribute Delivery Person                   |\n");
	printf("|   2.Sort Order         |   3.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 3);
}
void main_menu_Merchant_delete_recipe()//delete_several_lines(5);
{ 
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Delete Recipe       |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Merchant_move_recipe()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Move Recipe         |\n");
    print_ChooseNumber(0, 1);
}

//DeliveryPerson   
void main_menu_DeliveryPerson_1(char* name)
{

	printf("Hi,%s.Welcome to HAVE YOU EATEN.\n", name);
	printf("Which operation do you want to perform?\n");
	printf("|   1.Tasks              |   2.Change Password     |\n");
	printf("|   3.Deactivate                                   |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}
void main_menu_DeliveryPerson_2()
{

	printf("Which operation do you want to perform?\n");
	printf("|   1.Set The Order      |   2.Return              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}
void main_menu_DeliveryPerson_3()
{

	printf("Please enter the statement of the order:\n");
	printf("|   1.Delivering         |   2.Finish              |\n");
	print_Logout(0);
	print_ChooseNumber(0, 2);

}

//Administrator 
void main_menu_Administrator()
{
    printf("Hi,adm.Welcome to HAVE YOU EATEN.\n");
	printf("Which operation do you want to perform?\n");
	printf("|   1.Merchant           |   2.User                |\n");
	printf("|   3.Delivery Preson    |   4.Change discount     |\n");
	print_Logout(0);
	print_ChooseNumber(0, 4);
}
void main_menu_Administrator_2()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Delete Merchant     |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Administrator_3()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Delete User         |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Administrator_4()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Delete Delivery Man |\n");
	print_ChooseNumber(0, 1);
}
void main_menu_Administrator_5()
{
	printf("Which operation do you want to perform?\n");
	printf("|   0.Return             |   1.Change Discount     |\n");
	print_ChooseNumber(0, 1);
}

//print recipe list


#endif
