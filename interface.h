#ifndef _INTERFACE_H
#define _INTERFACE_H
//some little fuctions
#include "wordcolour.h"
void print_Title();

void print_Exit(int i);

void print_Logout(int i);

void print_ChooseNumber(int first, int last);

void cls_title();

void delete_several_lines(int numlines);

void illegal_number();//"wrong choice"  illegal_number();

void upper_lower();

void lower_upper();

void upper_lower_return();

void lower_upper_choose();

void upper_lower_choose();

void sort_star_price();

void sort_star_price_comprehensive();

void pause_cls();

void sleep();   //delete_several_lines(5);illegal_number();

void success_delete_recipe();

void success_delete_class();

void success_delete_merchant();

void success_add_class();

void continue_return();//delete_several_lines(5);

void return_continue();

void y_n();

void distribute_DP();

// the following are the real print functions

//choose identity/sign in&up  delete_several_lines(1);
void choose_identity();

void choose_sign();

void only_sign();

//User illegal_number();
void main_menu_User_1(char* name);

void main_menu_User_2();

void main_menu_User_3();

void main_menu_User_4();

void main_menu_User_5();

void main_menu_User_6();

void main_menu_User_7();//delete_several_lines(1);

void main_menu_User_8();

void main_menu_User_9();

void main_menu_User_10();

//Merchant  illegal_number();
void main_menu_Merchant_1(char *name);

void main_menu_Merchant_2();

void main_menu_Merchant_3();

void main_menu_Merchant_5();

void main_menu_Merchant_6();//illegal_number();delete_several_lines(5);

void main_menu_Merchant_8();

void main_menu_Merchant_9();

void main_menu_Merchant_10();

void main_menu_Merchant_11();

void main_menu_Merchant_delete_recipe();//delete_several_lines(5);

void main_menu_Merchant_move_recipe();

//DeliveryPerson   
void main_menu_DeliveryPerson_1(char* name);

void main_menu_DeliveryPerson_2();

void main_menu_DeliveryPerson_3();

//Administrator 
void main_menu_Administrator();

void main_menu_Administrator_2();

void main_menu_Administrator_3();

void main_menu_Administrator_4();

void main_menu_Administrator_5();

//print recipe list


#endif
