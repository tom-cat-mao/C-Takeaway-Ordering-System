#ifndef _FOLDER_C_C_D_H_
#define _FOLDER_C_C_D_H_
#include "class.h"

// write the merchant list to the merchant list folder
bool write_t_merchant_list(Merchant* head);

// write the user list to the user list folder
bool write_t_user_list(User* head);

// write the deliveryman list to the deliveryman list folder
bool write_t_deliveryperson_list(DeliveryPerson* head);

// write the order list to the order list folder
bool write_t_order_list(order* head);

// write the recipe class list to the recipe class list folder
bool write_t_r_class_list(r_classify* head);

// write the recipe list to the recipe list folder
bool write_t_recipe_list(recipe* head);







// read data from a file
bool readData(const char* fileName);





#endif // _FOLDER_C_C_D_H_