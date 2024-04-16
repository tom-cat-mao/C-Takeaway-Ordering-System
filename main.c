#include"class.h"
#include"classTree.h"
#include"folder_create_change_delete.h"
#include"FuzzySearch.h"
#include"interface.h"
#include"mergeSortOrder.h"
#include"mergeSortRecipe.h"
#include"output_recipe_price_range.h"
#include"sale_recipe.h"
#include"setStar_recipe.h"
#include"wordcolour.h"

int main()
{
	//Create password list head node
	Password_m* p_head_m;
	Password_u* p_head_u;
	Password_d* p_head_d;

	// Create list head node and current node
	recipe* r_head;
	recipe* r_current;
	r_classify* rc_head;
	r_classify* rc_current;
	order* o_head;
	order* o_current;
	Merchant* m_head;
	Merchant* m_current;
	User* u_head;
	User* u_current;
	DeliveryPerson* d_head;
	DeliveryPerson* d_current;

	// Create tree head node and current node
	t_recipe* t_r_head;
	t_recipe* t_r_current;
	t_order* t_o_head;
	t_order* t_o_current;
	t_Merchant* t_m_head;
	t_Merchant* t_m_current;

	//read file
	read_merchant_list(m_head, m_current);
	read_user_list(u_head, u_current);
	read_deliveryperson_list(d_head, d_current);

	for (int flag = 1; flag != 0;)
	{
		printf("please choose your identity:(0.Close,1.User,2.Merchant,3.Delivery Preson)\n");
		int t = 0;
		scanf("%d", &t);
		switch (t)
		{
		case 0:
			flag = 0;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				printf("0.Return,1.Sign in,2.Sign up\n");
				int t_1 = 0;
				scanf("%d", &t_1);
				switch (t_1)
				{
				case 0:
					flag_1 = 0;
					break;
				case 1:

					break;
				case 2:
					char name[100] = { '\0' };
					char password = { '\0' };
					char phone = { '\0' };
					printf("please enter your username:\n");
					scanf("%s", name);
					printf("please enter your password:\n");
					scanf("%s", password);
					printf("please enter your phone number:\n");
					scanf("%s", phone);
					DeliveryPerson* node = creatList_deliveryperson(name, password, phone);
					insertEnd_d(&d_head, &d_current, node);
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}
	}

	//write in file
	write_t_merchant_list(m_head);
	write_t_user_list(u_head);
	write_t_deliveryperson_list(d_head);

	return 0;
}