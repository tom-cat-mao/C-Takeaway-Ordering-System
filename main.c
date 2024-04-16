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
	Password_m* p_m_current;
	Password_u* p_head_u;
	Password_u* p_u_current;
	Password_d* p_head_d;
	Password_d* p_d_current;

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

	//enter the program
	print_Title();

	//read file
	read_merchant_list(&m_head, &m_current);
	read_user_list(&u_head, &u_current);
	read_deliveryperson_list(&d_head, &d_current);
	m_readIntoList_p(&p_head_m);
	u_readIntoList_p(&p_head_u);
	d_readIntoList_p(&p_head_d);

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
					char name[100] = { '\0' };
					printf("please enter your username:\n");
					scanf("%s", name);
					if (compare_d(p_head_d, name,&p_d_current))
					{
						d_current = find_d(d_head, name);
						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.order,2.change password");
							int t_2 = 0;
							scanf("%d", &t_2);
							switch (t_2)
							{
							case 0:
								flag_2 = 0;
								flag_1 = 0;
								break;
							case 1:
								print_order_list(d_current->o_tail);
								for (int flag_3 = 1; flag_3 != 0;)
								{
									printf("0.log out,1.set the order,2.return\n");
									int t_3 = 0;
									scanf("%d", &t_3);
									switch (t_3)
									{
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;
									case 1:
										print_current_order(d_current->o_tail);
										printf("please enter the statement of the order:(1.delivering,2.Finish)\n");
										int s = 0;
										scanf("%d", &s);
										set_state_o(d_current->o_tail, s);
										break;
									case 2:
										flag_3 = 0;
										break;
									default:
										printf("wrong choice!\n");
										break;
									}
									print_current_order(d_current->o_tail);
								}
								
								break;
							case 2:
								deliveryPerson_change_p(d_current, p_d_current);
								break;
							default:
								printf("wrong choice!\n");
								break;
							}
						}
					}
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
					d_createList_p(&p_head_d, &p_d_current, d_creatNode_p(name, password, phone));
					DeliveryPerson* node = creatList_deliveryperson(name, password, phone);
					insertEnd_d(&d_head, &d_current, node);
					break;
				default:
					printf("wrong choice!\n");
					break;
				}
			}
			break;
		default:
			printf("wrong choice!\n");
			break;
		}
	}

	//write in file
	write_t_merchant_list(m_head);
	write_t_user_list(u_head);
	write_t_deliveryperson_list(d_head);
	m_writeIntoFile_p(p_head_m);
	u_writeIntoFile_p(p_head_u);
	d_writeIntoFile_p(p_head_d);

	return 0;
}