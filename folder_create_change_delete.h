#ifndef _FOLDER_C_C_D_H_
#define _FOLDER_C_C_D_H_
#include "class.h"
#include "dirent.h"
#include <direct.h>

// write the merchant list to the merchant list folder
bool write_t_merchant_list(struct Merchant* head);

// write the user list to the user list folder
bool write_t_user_list(struct User* head);

// write the deliveryman list to the deliveryman list folder
bool write_t_deliveryperson_list(struct DeliveryPerson* head);

// write the order list to the order list folder
bool write_t_order_list(struct order* head);

// write the recipe class list to the recipe class list folder
bool write_t_r_class_list(struct r_classify* head);

// write the recipe list to the recipe list folder
bool write_t_recipe_list(struct recipe* head);


// read all merchant list from the file to the memory
bool read_merchant_list(struct Merchant** head, struct Merchant** current, struct t_Merchant** t_head);

// read all user lists form the file to the memory
bool read_user_list(struct User** head, struct User** current);

// read all deliveryman lists form the file to the memory
bool read_deliveryperson_list(struct DeliveryPerson** head, struct DeliveryPerson** current);

// read all r_classify lists form the file to the memory
bool read_r_class_list(struct r_classify** head, struct r_classify** current);

// read all recipe lists form the file to the memory
bool read_recipe_list(struct recipe** head, struct recipe** current, struct t_recipe** t_head);

// read all order lists form the file to the memory
bool read_order_list(struct order** head, struct order** current, struct t_order** t_head);














#endif // _FOLDER_C_C_D_H_