#define _CRT_SECURE_NO_WARNINGS

#include"class.h"
#include"classTree.h"
#include"folder_create_change_delete.h"
#include"SearchFuzzy&SaleRecipe.h"
#include"interface.h"
#include"mergeSortOrder.h"
#include"mergeSortRecipe.h"
#include"output_recipe_price_range.h"
#include"sale_recipe.h"

int main()
{
	//Create password list head node
	struct Password_m* p_head_m = NULL;
	struct Password_m* p_m_current = NULL;
	struct Password_m* p_m_tail = NULL;
	struct Password_u* p_head_u = NULL;
	struct Password_u* p_u_current = NULL;
	struct Password_u* p_u_tail = NULL;
	struct Password_d* p_head_d = NULL;
	struct Password_d* p_d_current = NULL;
	struct Password_d* p_d_tail = NULL;

	// Create list head node and current node
	struct recipe* r_head = NULL;
	struct recipe* r_current = NULL;
	struct recipe* r_tail = NULL;
	struct r_classify* rc_head = NULL;
	struct r_classify* rc_current = NULL;
	struct r_classify* rc_tail = NULL;
	struct order* o_head = NULL;
	struct order* o_current = NULL;
	struct order* o_tail = NULL;
	struct Merchant* m_head = NULL;
	struct Merchant* m_current = NULL;
	struct Merchant* m_tail = NULL;
	struct User* u_head = NULL;
	struct User* u_current = NULL;
	struct User* u_tail = NULL;
	struct DeliveryPerson* d_head = NULL;
	struct DeliveryPerson* d_current = NULL;
	struct DeliveryPerson* d_tail = NULL;

	// Create tree head node and current node
	struct t_recipe* t_r_head = NULL;
	struct t_recipe* t_r_current = NULL;
	struct t_order* t_o_head = NULL;
	struct t_order* t_o_current = NULL;
	struct t_Merchant* t_m_head = NULL;
	struct t_Merchant* t_m_current = NULL;

	//read file
	m_readIntoList_p(&p_head_m, &p_m_tail);
	u_readIntoList_p(&p_head_u, &p_u_tail);
	d_readIntoList_p(&p_head_d, &p_d_tail);
	read_merchant_list(&m_head, &m_tail,&t_m_head);
	read_user_list(&u_head, &u_tail);
	read_deliveryperson_list(&d_head, &d_tail);

	//enter the program
	print_Title();

	for (int flag = 1; flag != 0;)
	{
		
		choose_identity();
		fflush(stdout);
		int t = 0;
		scanf("%d", &t);//6
		cls_title();
		switch (t)
		{
			//close
		case 0:
			flag = 0;
			break;


			//User
		case 1:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				choose_sign();
                fflush(stdout);
				int t_1 = 0;
				scanf("%d", &t_1);//5
				cls_title();
				switch (t_1)
				{
					//return
				case 0:
					flag_1 = 0;
					break;

					//sign in
				case 1:
					char name[100];
					printf("Please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					cls_title();
					if (compare_u(p_head_u, name, &p_u_current))//compare the user's name and password
					{
						cls_title();
						u_current = find_u(u_head, name);//find user in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							main_menu_User_1(name);
                            fflush(stdout);
							int t_2 = 0;
							scanf("%d", &t_2);//10
							delete_several_lines(10);
							switch (t_2)
							{
								//log out
							case 0:
								flag_2 = 0;
								flag_1 = 0;
								break;

								//make an order
							case 1:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									printList_merchant(m_head);
									main_menu_User_2();
									
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);//5
									delete_several_lines(5);
									switch (t_3)
									{
										//log out
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;

										//choose a merchant
									case 1:
										char m_name[100];
										printf("Please enter the merchant you choose:\n");
                                        fflush(stdout);
										scanf("%s", m_name);//2
										cls_title();
										m_current = search_Merchant_name(t_m_head, m_name);

										int judge = 0;

										for (int flag_4 = 1; flag_4 != 0;)
										{
											cls_title();
											printList_r_classify(m_current->r_head);
                                            fflush(stdout);
											main_menu_User_3();
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);//6
											delete_several_lines(6);
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//sort
											case 1:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													main_menu_User_5();
                                                    fflush(stdout);
													int t_5 = 0;
													scanf("%d", &t_5);//5
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//sort
													case 1:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															
															sort_star_price_comprehensive();
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);//6
															delete_several_lines(6);
															cls_title();
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//sort by price
															case 1:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	upper_lower_choose();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);//5
																	delete_several_lines(5);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		struct r_classify* temp_1 = m_current->r_head;
																		while (temp_1 != NULL)
																		{
																			temp_1->r_head = r_mergeSortUpper_p(temp_1->r_head, &(temp_1->r_tail));
																			temp_1 = temp_1->next;

																		}
																		printList_r_classify(m_current->r_head);

                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//lower
																	case 2:
																		struct r_classify* temp_2 = m_current->r_head;
																		while (temp_2 != NULL)
																		{
																			temp_2->r_head = r_mergeSortLower_p(temp_2->r_head, &(temp_2->r_tail));
																			temp_2 = temp_2->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("Please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("Pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		delete_several_lines(4);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;

																//sort by star
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	upper_lower();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);//5
																	delete_several_lines(5);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		struct r_classify* temp_1 = m_current->r_head;
																		while (temp_1 != NULL)
																		{
																			temp_1->r_head = r_mergeSortUpper_s(temp_1->r_head, &(temp_1->r_tail));
																			temp_1 = temp_1->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//lower
																	case 2:
																		struct r_classify* temp_2 = m_current->r_head;
																		while (temp_2 != NULL)
																		{
																			temp_2->r_head = r_mergeSortLower_s(temp_2->r_head, &(temp_2->r_tail));
																			temp_2 = temp_2->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("Please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("Pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		delete_several_lines(4);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;

																//sort by comprehensive
															case 3:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	upper_lower();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);//5
																	delete_several_lines(5);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		struct r_classify* temp_1 = m_current->r_head;
																		while (temp_1 != NULL)
																		{
																			temp_1->r_head = r_mergeSortUpper_c(temp_1->r_head, &(temp_1->r_tail));
																			temp_1 = temp_1->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//lower
																	case 2:
																		struct r_classify* temp_2 = m_current->r_head;
																		while (temp_2 != NULL)
																		{
																			temp_2->r_head = r_mergeSortLower_c(temp_2->r_head, &(temp_2->r_tail));
																			temp_2 = temp_2->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("Please enter the recipe name:\n");
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("Pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		delete_several_lines(4);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//search
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													main_menu_User_9();
													int t_5 = 0;
													scanf("%d", &t_5);//6
													delete_several_lines(6);
													switch (t_5)
													{
														//return
													case 0:
														flag_5 = 0;
														break;

														//accurate search
													case 1:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															main_menu_User_10();
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);//5
															delete_several_lines(5);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//single inquiry
															case 1:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	return_continue();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);//4
																	delete_several_lines(4);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//continue
																	case 1:
																		char r_name[100] = { '\0' };
																		printf("Please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		delete_several_lines(2);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		if (r_current == NULL)
																		{
																			printf("We don't have the recipe you search\n");
																			sleep();
																			delete_several_lines(1);
                                                                            fflush(stdout);
																		}
																		else
																		{
																			//print
																			print_current_recipe(r_current);
																			char j;
																			y_n();
                                                                            fflush(stdout);
																			scanf("%c", &j);//2
																			if (j == 'Y')
																			{
																				judge = 1;
																				printf("Pleae enter the number you want:\n");
                                                                                fflush(stdout);
																				int n = 0;
																				scanf("%d", &n);
																				delete_several_lines(4);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																				insertEnd_r(&r_head, &r_tail, r_current);
																			}
																		}
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}


																break;

																//combination inquiry
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	return_continue();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	delete_several_lines(4);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//continue
																	case 1:
																		char rc_name[100] = { '\0' };
																		char r_name[100] = { '\0' };
																		printf("Please enter the r_class and the rcipe you want to search:\n");
                                                                        fflush(stdout);
																		scanf("%s", rc_name);
																		scanf("%s", r_name); 
																		delete_several_lines(3);

																		rc_current = find_r_classify(m_current, rc_name);
																		if (rc_current == NULL)
																		{
																			printf("We don't have the class you want!\n");
                                                                            fflush(stdout);
																			sleep();
																			delete_several_lines(1);
																		}
																		else
																		{
																			r_current = find_recipe_by_list(rc_current, r_name);
																			if (r_current == NULL)
																			{
																				printf("We don't have the recipe you search\n");
                                                                                fflush(stdout);
																				sleep();
																				delete_several_lines(1);
																			}
																			else
																			{
																				//print
																				char j;
																				y_n();
                                                                                fflush(stdout);
																				scanf("%c", &j);
																				delete_several_lines(2);
																				if (j == 'Y')
																				{
																					judge = 1;
																					printf("Pleae enter the number you want:\n");
                                                                                    fflush(stdout);
																					int n = 0;
																					scanf("%d", &n);
																					delete_several_lines(2);
																					r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																					insertEnd_r(&r_head, &r_tail, r_current);
																				}
																			}
																		}
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}

																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//fuzzy search
													case 2:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															return_continue();
															int t_6 = 0;
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//continue
															case 1:
																char str[100] = { '\0' };
																printf("Please enter the string you want to search:\n");
                                                                fflush(stdout);
																scanf("%s", str);
																delete_several_lines(2);
																FuzzySearchInClassify(m_current->r_head, str);
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("Whether you want to order any recipe?\n");
                                                                    fflush(stdout);
																	return_continue();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	delete_several_lines(4);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//continue
																	case 1:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("Please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("Pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		delete_several_lines(4);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//price range
													case 3:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															return_continue();
															int t_6 = 0;
															scanf("%d", &t_6);
                                                            fflush(stdout);
															delete_several_lines(4);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//continue
															case 1:
																float max_price = 0.0;
																float min_price = 0.0;
																printf("Please enter the max price and the min price:\n");
                                                                fflush(stdout);
																scanf("%f%f", &max_price, &min_price);
																delete_several_lines(2);
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	lower_upper();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	delete_several_lines(5);
																	switch (t_7)
																	{
																	case 0:
																		flag_7 = 0;
																		break;
																	case 1:
																		output_recipe_high_to_low(m_current->r_head, min_price, max_price);
																		for (int flag_8 = 1; flag_8 != 0;)
																		{
																			printf("Whether you want to order any recipe?\n");
																			return_continue();
                                                                            fflush(stdout);
																			int t_8 = 0;
																			scanf("%d", &t_8);
																			delete_several_lines(5);
																			switch (t_8)
																			{
																				//return
																			case 0:
																				flag_8 = 0;
																				break;

																				//continue
																			case 1:
																				judge = 1;

																				char r_name[100] = { '\0' };
																				printf("Please enter the recipe name:\n");
                                                                                fflush(stdout);
																				scanf("%s", r_name);
																				r_current = search_recipe_name(m_current->t_r_head, r_name);
																				printf("Pleae enter the number you want:\n");
                                                                                fflush(stdout);
																				int n = 0;
																				scanf("%d", &n);
																				delete_several_lines(4);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
                                                                                fflush(stdout);
																				insertEnd_r(&r_head, &r_tail, r_current);
																				break;
																			default:
																				illegal_number();
																				break;
																			}
																		}
																		break;
																	case 2:
																		output_recipe_low_to_high(m_current->r_head, min_price, max_price);
																		for (int flag_8 = 1; flag_8 != 0;)
																		{
																			printf("Whether you want to order any recipe?\n");
																			return_continue();
                                                                            fflush(stdout);
																			int t_8 = 0;
																			scanf("%d", &t_8);
																			delete_several_lines(5);
																			switch (t_8)
																			{
																				//return
																			case 0:
																				flag_8 = 0;
																				break;

																				//continue
																			case 1:
																				judge = 1;

																				char r_name[100] = { '\0' };
																				printf("Please enter the recipe name:\n");
                                                                                fflush(stdout);
																				scanf("%s", r_name);
																				r_current = search_recipe_name(m_current->t_r_head, r_name);
																				printf("Pleae enter the number you want:\n");
																				int n = 0;
																				scanf("%d", &n);
																				delete_several_lines(4);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																				insertEnd_r(&r_head, &r_tail, r_current);
																				break;
																			default:
																				illegal_number();
																				break;
																			}
																		}
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//sale recipe
													case 4:
														SaleRecipeSearch(m_current->t_r_head);
														for (int flag_6 = 1; flag_6 != 0;)
														{
															return_continue();
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//continue
															case 1:
																judge = 1;

																char r_name[100] = { '\0' };
																printf("Please enter the recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																printf("Pleae enter the number you want:\n");
                                                                fflush(stdout);
																int n = 0;
																scanf("%d", &n);
																delete_several_lines(4);
																r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																insertEnd_r(&r_head, &r_tail, r_current);
																break;

															default:
																illegal_number();
																break;
															}
														}

														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//choose
											case 3:
												judge = 1;

												char r_name[100] = { '\0' };
												printf("Please enter the recipe name:\n");
                                                fflush(stdout);
												scanf("%s", r_name);
												r_current = search_recipe_name(m_current->t_r_head, r_name);
												printf("Please enter the number you want:\n");
                                                fflush(stdout);
												int n = 0;
												scanf("%d", &n);
												delete_several_lines(4);
												r_current = creatList_recipe_1(r_current->name, r_current->price, n);
												insertEnd_r(&r_head, &r_tail, r_current);
												break;

												//return||finish
											case 4:
												flag_4 = 0;
												break;
											default:
												illegal_number();
												break;
											}
										}

										if (judge == 1)
										{
											d_current = find_free_d(d_head);
											d_current->s = BUSY;
											o_current = creatList_order(m_current, u_current, d_current);
											o_current->r_head = r_head;
											o_current->r_tail = r_tail;
											sumPrice(o_current, o_current->r_head, u_current->c, discount);
											insertEnd_o(&(u_current->o_head), &(u_current->o_tail), o_current);
											insertEnd_o(&(m_current->o_head), &(m_current->o_tail), o_current);
											insertEnd_o(&(d_current->o_head), &(d_current->o_tail), o_current);
											insertTree_order_id(&(u_current->t_o_head), o_current);
											insertTree_order_id(&(m_current->t_o_head), o_current);
										}
										cls_title();
										break;

										//return
									case 2:
										flag_3 = 0;
										break;
									default:
										illegal_number();
										break;
									}
								}
								cls_title();
								break;

								//view and cancel order
							case 2:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									main_menu_User_6();
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);
									delete_several_lines(6);
									switch (t_3)
									{
										//log out
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;

										//show order
									case 1:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(u_current->o_tail);
											main_menu_User_7();
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
											cls_title();
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//sort in time
											case 1:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													
													upper_lower();
                                                    fflush(stdout);
													int  t_5 = 0;
													scanf("%d", &t_5);
													cls_title();
													switch (t_5)
													{
														//return
													case 0:
														flag_5 = 0;
														break;

														//upper
													case 1:
														u_current->o_head = o_mergeSortLower_t(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
                                                        fflush(stdout);
														pause_cls();
														break;

														//lower
													case 2:
														u_current->o_head = o_mergeSortUpper_t(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
                                                        fflush(stdout);
														pause_cls();
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;

												//sort in price
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													upper_lower();
													int  t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													cls_title();
													switch (t_5)
													{
														//return
													case 0:
														flag_5 = 0;
														break;

														//upper
													case 1:
														u_current->o_head = o_mergeSortLower_p(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
                                                        fflush(stdout);
														pause_cls();
														break;

														//lower
													case 2:
														u_current->o_head = o_mergeSortUpper_p(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
														fflush(stdout);
														pause_cls();
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;


											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													continue_return();
													int t_5 = 0;
													fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//continue
													case 1:
														char o_id[100] = { '\0' };
														printf("Please enter the order you want to search:\n");
														fflush(stdout);
														scanf("%s", o_id);
														delete_several_lines(2);
														o_current = search_order_id(u_current->t_o_head, o_id);
														cls_title();
														print_current_order(o_current);
														pause_cls();
														//print
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
													
												}
												
												break;
												//return
											case 4:
												flag_4 = 0;
												break;
											default:
												illegal_number();
												break;
											}
										}
										
										break;

										//cancel order
									case 2:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(u_current->o_tail);
											continue_return();
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
											delete_several_lines(5);
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//contiune
											case 1:
												char o_id[100] = { '\0' };
												printf("Please enter the order id you want to cancel\n");
                                                fflush(stdout);
												scanf("%s", o_id);
												
												o_current = search_order_id(u_current->t_o_head, o_id);
												y_n();
												char j;
                                                fflush(stdout);
												scanf("%c", &j);
												delete_several_lines(4);
												switch (j)
												{
												case 'Y':
													o_current->s = CANCEL;
													Synchronization_o_s_for_u(o_current, m_head, d_head);
													d_current = find_d(d_head, o_current->d_name);
													d_current->s = FREE;
													break;
												case 'N':
													break;
												default:
													illegal_number();
													break;
												}
												break;

												//return
											case 2:
												flag_4 = 0;
												break;
											default:
												illegal_number();
												break;
											}
											cls_title();
										}
										
										break;

										//return
									case 3:
										flag_3 = 0;
										break;
									default:
										illegal_number();
										break;
									}
								}
								break;

								//change card
							case 3:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									return_continue();
									int t_3 = 0;
									scanf("%d", &t_3);
									delete_several_lines(4);
									switch (t_3)
									{
										//return
									case 0:
										flag_3 = 0;
										break;

										//continue
									case 1:
										main_menu_User_8();
										int t_3 = 0;
										fflush(stdout);
										scanf("%d", &t_3);
										delete_several_lines(6);
										switch (t_3)
										{
										case 1:
											u_current->c = SILVER;
											break;
										case 2:
											u_current->c = GOLD;
											break;
										case 3:
											u_current->c = PLATINUM;
											break;
										default:
											illegal_number();
											break;
										}
										break;
									default:
										illegal_number();
										break;
									}
									
								}
								break;

								//change password
							case 4:
								user_change_p(u_current, p_u_current);
								sleep();
								cls_title();
								break;

								//deactivate

							case 5:
								delete_user(u_head, u_current->name);
								break;
							default:
								illegal_number();
								break;
							}
						}

					}
					break;

					//sign up
				case 2:
					//create user's detail information
					char name_1[100] = { '\0' };
					char password[100] = { '\0' };
					char address[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_1);
					if (duplicate_name_u(p_head_u, name_1))//judge the username
					{
						printf("Please enter your password:\n");
						scanf("%s", password);
						printf("Please enter your address:\n");
						scanf("%s", address);
						printf("Please enter your phone number:\n");
						scanf("%s", phone);
						delete_several_lines(8);
						u_createList_p(&p_head_u, &p_u_tail, u_creatNode_p(name_1, password, phone));
						u_current = creatList_user(name_1, password, address, phone);
						insertEnd_u(&u_head, &u_tail, u_current);
					}
					else
					{
						delete_several_lines(2);
						colour(12);
						printf("The username already exist!\n");
						colour(7);
						sleep();
						delete_several_lines(1);
					}
					break;

					//forget password
				case 3:
					char name_u[100] = { '\0' };
					char phone_u[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_u);
					printf("Please enter your phone number:\n");
					scanf("%s", phone_u);
					delete_several_lines(4);
					if (!get_back_p_u(p_head_u, name_u, phone_u))
					{
						colour(12);
						printf("There is something wrong with the details you entered!\n");
						colour(7);
						sleep();
						delete_several_lines(1);
					}

					break;
				default:
					illegal_number();
					break;
				}
			}
			break;





			//Merchant
		case 2:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				choose_sign();
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
				cls_title();
				switch (t_1)
				{
					//return to the front page
				case 0:
					flag_1 = 0;
					break;

					//sign in
				case 1:
					char name[100] = { '\0' };
					printf("Please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					cls_title();
					if (compare_m(p_head_m, name, &p_m_current))//compare the merchant's name and password
					{
						cls_title();
						m_current = find_m(m_head, name);//find the merchant in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							main_menu_Merchant_1(name);
							int t_2 = 0;
                            fflush(stdout);
							scanf("%d", &t_2);
							delete_several_lines(8);
							switch (t_2)
							{
								//log out
							case 0:
								flag_2 = 0;
								flag_1 = 0;
								break;

								//setting in recipe 
							case 1:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									printList_r_classify(m_current->r_head);//all recipes
									main_menu_Merchant_2();
									int t_3 = 0;
                                    fflush(stdout);
									scanf("%d", &t_3);
									cls_title();
									switch (t_3)
									{
										//log out
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;

										//operate in recipe class
									case 1:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											printList_r_classify(m_current->r_head);
											main_menu_Merchant_3();
											int t_4 = 0;
                                            fflush(stdout);
											scanf("%d", &t_4);
											delete_several_lines(8);
											
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//add recipe class
											case 1:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//continue
													case 1:
														printf("Please enter your recipe class name:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														delete_several_lines(2);
														rc_current = creatList_r_classify(rc_name);
														insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);
														
														int num_1 = 0;

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															main_menu_Merchant_5();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//create recipe
															case 1:
																num_1++;
																char r_name[100] = { '\0' };
																float p = 0.0;
																printf("Please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																printf("Please enter the price:\n");
                                                                fflush(stdout);
																scanf("%f", &p);
																delete_several_lines(4);
																r_current = creatList_recipe_2(r_name, p);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = num_1;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//delete recipe class
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(6);
													switch (t_5)
													{
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;
													case 1:
														char rc_name[100] = { '\0' };
														printf("Please enter the recipe class you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														delete_several_lines(2);
														rc_current = find_r_classify(m_current, rc_name);
														delete_specific_r_class(&rc_current, &(m_current->r_head), &(m_current->r_tail));
														
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//change recipe name
											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;
													case 1:
														char rc_name[100] = { '\0' };
														printf("Please enter the recipe class you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);
														char new_rc_name[100] = { '\0' };
														printf("Please enter the new name:\n");
                                                        fflush(stdout);
														scanf("%s", new_rc_name);
														delete_several_lines(4);
														strcpy(rc_current->name, new_rc_name);
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//inquiry recipe class
											case 4:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;
													case 1:
														char rc_name[100] = { '\0' };
														printf("Please enter the recipe class you want to see:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														delete_several_lines(2);
														rc_current = find_r_classify(m_current, rc_name);
														printList_recipe_1(rc_current->r_head);
														pause_cls();
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//return
											case 5:
												flag_4 = 0;
												cls_title();
												break;
											default:
												illegal_number();
												break;
											}
											cls_title();
										}
										break;

										//operate in recipe
									case 2:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											printList_r_classify(m_current->r_head);
											main_menu_Merchant_6();
											int t_4 = 0;
                                            fflush(stdout);
											scanf("%d", &t_4);
											delete_several_lines(8);
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//add recipe
											case 1:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//continue
													case 1:
														printf("Please enter your recipe class name you want to operate:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														delete_several_lines(2);
														rc_current = find_r_classify(m_current, rc_name);

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															cls_title();
															printList_r_classify(m_current->r_head);
															main_menu_Merchant_5();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//create recipe
															case 1:
																char r_name[100] = { '\0' };
																float p = 0.0;
																printf("Please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																printf("Please enter the price:\n");
                                                                fflush(stdout);
																scanf("%f", &p);
																cls_title();
																r_current = creatList_recipe_2(r_name, p);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = rc_current->total_number + 1;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														cls_title();
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;

												//delete recipe
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													cls_title();
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//continue
													case 1:
														printList_r_classify(m_current->r_head);
														printf("Please enter your recipe class name you want to operate:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														cls_title();
														rc_current = find_r_classify(m_current, rc_name);

														//delete recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printList_r_classify(m_current->r_head);
															main_menu_Merchant_delete_recipe();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//delete recipe
															case 1:
																char r_name[100] = { '\0' };
																printf("Please enter recipe name you want to delete:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																delete_several_lines(2);
																delete_recipe_name(&(m_current->t_r_head), r_name, &(rc_current->r_head), &(rc_current->r_tail));
																rc_current->total_number = rc_current->total_number - 1;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;

												//move recipe
											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													continue_return();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													cls_title();
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//continue
													case 1:
														cls_title();
														printList_r_classify(m_current->r_head);
														printf("Please enter the recipe class name you want to move from:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														cls_title();
														rc_current = find_r_classify(m_current, rc_name);

														//move recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															main_menu_Merchant_move_recipe();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(4);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//move recipe
															case 1:
																char r_name[100] = { '\0' };
																printList_r_classify(m_current->r_head);
																printf("Please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																r_current = creatList_recipe_2(r_current->name, r_current->price);
																rc_current->total_number = rc_current->total_number - 1;
																delete_recipe_name(&(m_current->t_r_head), r_name, &(rc_current->r_head), &(rc_current->r_tail));
																printf("Please enter the recipe class name you want to move in:\n");
																char rc_name[100] = { '\0' };
                                                                fflush(stdout);
																scanf("%s", rc_name);
																cls_title();
																rc_current = find_r_classify(m_current, rc_name);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = rc_current->total_number + 1;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;

												//inquiry recipe
											case 4:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													main_menu_Merchant_8();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													cls_title();
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//fuzzy search
													case 1:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															continue_return();
															int t_6 = 0;
															scanf("%d", &t_6);
															cls_title();
															switch (t_6)
															{
																//log out
															case 0:
																flag_6 = 0;
																flag_5 = 0;
																flag_4 = 0;
																flag_3 = 0;
																flag_2 = 0;
																flag_1 = 0;
																break;

																// continue
															case 1:
																char str[100] = { '\0' };
																printf("Please enter the name you want to search:");
																scanf("%s", str);
																delete_several_lines(2);
                                                                fflush(stdout);
																FuzzySearchInClassify(m_current->r_head, str);
																pause_cls();
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//sale recipe search
													case 2:
														
														
														for (int flag_6 = 1; flag_6 != 0;)
														{
															SaleRecipeSearch(m_current->t_r_head);
															continue_return();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(5);
															switch (t_6)
															{
																//log out
															case 0:
																flag_6 = 0;
																flag_5 = 0;
																flag_4 = 0;
																flag_3 = 0;
																flag_2 = 0;
																flag_1 = 0;
																break;

																//continue
															case 1:
																char r_name[100] = { '\0' };
																printf("Please enter the recipe you want to operate:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																delete_several_lines(2);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																for (;;)
																{
																	printf("Please enter the sale discount:\n");
																	float sale_ = 0;
                                                                    fflush(stdout);
																	scanf("%f", &sale_);
																	delete_several_lines(2);
																	if (bool_set_sale_recipe(r_current, sale_))
																	{
																		cls_title();
																		
																		break;
																	}
																}
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																illegal_number();
																break;
															}
														}
														cls_title();

														break;

														//search price range
													case 3:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															continue_return();
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															delete_several_lines(5);
															switch (t_6)
															{
																//log out
															case 0:
																flag_6 = 0;
																flag_5 = 0;
																flag_4 = 0;
																flag_3 = 0;
																flag_2 = 0;
																flag_1 = 0;
																break;

																//continue
															case 1:
																float max_price = 0.0;
																float min_price = 0.0;
																printf("Please enter the max price and the min price:\n");
                                                                fflush(stdout);
																scanf("%d%d", &max_price, &min_price);
																delete_several_lines(2);
																for (int flag_7 = 1; flag_7 = 0;)
																{
																	lower_upper();
																	int t_7 = 0;
                                                                    fflush(stdout);
																	scanf("%d", &t_7);
																	delete_several_lines(5);
																	switch (t_7)
																	{
																	case 0:
																		flag_7 = 0;
																		break;
																	case 1:
																		output_recipe_high_to_low(m_current->r_head, min_price, max_price);
																		pause_cls();

																		break;
																	case 2:
																		output_recipe_low_to_high(m_current->r_head, min_price, max_price);
																		pause_cls();
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 4:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;

												//set sale recipe
											case 5:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													main_menu_Merchant_9();
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//set sale recip
													case 1:
														char r_name[100] = { '\0' };
														printf("Please enter the recipe you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", r_name);
														delete_several_lines(2);
														r_current = search_recipe_name(m_current->t_r_head, r_name);
														for (;;)
														{
															printf("Please enter the sale discount:\n");
                                                            fflush(stdout);
															float sale_ = 0;
															scanf("%f", &sale_);
															delete_several_lines(2);
															if (bool_set_sale_recipe(r_current, sale_))
															{
																sleep();
																delete_several_lines(1);
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}

												break;


												//sort recipe
											case 6:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													cls_title();
													printList_r_classify(m_current->r_head);
													main_menu_Merchant_10();
                                                    fflush(stdout);
													int t_5 = 0;
                                                    scanf("%d",&t_5);
													delete_several_lines(5);
													switch (t_5)
													{
														//log out
													case 0:
														flag_5 = 0;
														flag_4 = 0;
														flag_3 = 0;
														flag_2 = 0;
														flag_1 = 0;
														break;

														//sort
													case 1:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															sort_star_price();
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
															delete_several_lines(5);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//sort by price
															case 1:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	upper_lower();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	delete_several_lines(5);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		struct r_classify* temp_1 = m_current->r_head;
																		while (temp_1 != NULL)
																		{
																			temp_1->r_head = r_mergeSortUpper_p(temp_1->r_head, &(temp_1->r_tail));
																			temp_1 = temp_1->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//lower
																	case 2:
																		struct r_classify* temp_2 = m_current->r_head;
																		while (temp_2 != NULL)
																		{
																			temp_2->r_head = r_mergeSortLower_p(temp_2->r_head, &(temp_2->r_tail));
																			temp_2 = temp_2->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;
																	default:
																		illegal_number();
																		break;
																	}
																}
																break;

																//sort by star
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	upper_lower();
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	delete_several_lines(5);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		struct r_classify* temp_1 = m_current->r_head;
																		while (temp_1 != NULL)
																		{
																			temp_1->r_head = r_mergeSortUpper_s(temp_1->r_head, &(temp_1->r_tail));
																			temp_1 = temp_1->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;

																		//lower
																	case 2:
																		struct r_classify* temp_2 = m_current->r_head;
																		while (temp_2 != NULL)
																		{
																			temp_2->r_head = r_mergeSortLower_s(temp_2->r_head, &(temp_2->r_tail));
																			temp_2 = temp_2->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		pause_cls();
																		break;
																	default:
																		break;
																	}
																}
																break;
															default:
																illegal_number();
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														illegal_number();
														break;
													}
												}
												break;


												//return
											case 7:
												flag_4 = 0;
												cls_title();
												break;
											default:
												illegal_number();
												break;
											}

										}
										break;

										//return
									case 3:
										flag_3 = 0;
										cls_title();
										break;
									default:
										illegal_number();
										break;
									}
								}
								break;

								//setting in order
							case 2:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									print_order_list(m_current->o_tail);
									main_menu_Merchant_11();
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);
									delete_several_lines(6);
									switch (t_3)
									{
										//log out
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;

										//distribute delivery person
									case 1:
										cls_title();
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(m_current->o_tail);
											return_continue();
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
											delete_several_lines(4);
											switch (t_4)
											{
												//return
											case 0:
												flag_4 = 0;
												cls_title();
												break;

												//continue
											case 1:
												distribute_DP();
												char o_id[100] = { '\0' };
												printf("Please enter the order you want to operate:\n");
                                                fflush(stdout);
												scanf("%s", o_id);
												cls_title();
												o_current = search_order_id(m_current->t_o_head, o_id);
												//
												d_current = find_free_d(d_head);
												d_current->s = BUSY;
												strcpy(o_current->d_name, d_current->name);
												strcpy(o_current->d_phone, d_current->phone);
												Synchronization_o_d_for_m(o_current, d_head, u_head);
												break;
											default:
												illegal_number();
												break;
											}

										}
										break;

										//sort order
									case 2:
										cls_title();
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(m_current->o_tail);
											upper_lower_return();
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
											cls_title();
											switch (t_4)
											{
												//log out
											case 0:
												flag_4 = 0;
												flag_3 = 0;
												flag_2 = 0;
												flag_1 = 0;
												break;

												//upper
											case 1:
												m_current->o_tail = o_mergeSortLower_t(m_current->o_head, &(m_current->o_tail));
												print_order_list(m_current->o_tail);
                                                fflush(stdout);
												pause_cls();
												break;

												//lower
											case 2:
												m_current->o_tail = o_mergeSortUpper_t(m_current->o_head, &(m_current->o_tail));
												print_order_list(m_current->o_tail);
                                                fflush(stdout);
												pause_cls();
												break;

												//return
											case 3:
												flag_4 = 0;
												cls_title();
												break;
											default:
												illegal_number();
												break;
											}
										}
										break;

										//return
									case 3:
										flag_3 = 0;
										cls_title();
										break;
									default:
										illegal_number();
										break;
									}
								}
								break;

								//password change
							case 3:
								merchant_change_p(m_current, p_m_current);
								sleep();
								cls_title();
								break;

								//deactivate
							case 4:
								delete_merchant(m_head, m_current->name);
								break;
							default:
								illegal_number();
								break;
							}
						}
					}
					break;

					//sign up
				case 2:
					//create merchant's detail information
					char name_2[100] = { '\0' };
					char password[100] = { '\0' };
					char address[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_2);
					
					if (duplicate_name_m(p_head_m, name_2))//judge the username
					{
						printf("Please enter your password:\n");
						scanf("%s", password);
						printf("Please enter your address:\n");
						scanf("%s", address);
						printf("Please enter your phone number:\n");
						scanf("%s", phone);
						cls_title();
						m_createList_p(&p_head_m, &p_m_tail, m_creatNode_p(name_2, password, phone));
						m_current = creatList_merchant(name_2, password, address, phone);
						insertEnd_m(&m_head, &m_tail, m_current);
						insertTree_Merchant_name(&t_m_head, m_current);
						printf("Continue to create recipe\n");

						//create recipe class and recipe
						for (int flag_2 = 1; flag_2 != 0;)
						{
							return_continue();
							int t_2 = 0;
							scanf("%d", &t_2);
							cls_title();
							switch (t_2)
							{
								//return to the front page
							case 0:
								flag_2 = 0;
								break;

								//create recipe class and recipe
							case 1:
								printf("Please enter your recipe class name:\n");
								char rc_name[100] = { '\0' };
								scanf("%s", rc_name);
								cls_title();
								rc_current = creatList_r_classify(rc_name);
								insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);

								int num = 0;
								//create recipe
								for (int flag_3 = 1; flag_3 != 0; )
								{
									main_menu_Merchant_5();
									int t_3 = 0;
									scanf("%d", &t_3);
									cls_title();
									switch (t_3)
									{
										// return to the front page
									case 0:
										flag_3 = 0;
										break;

										//create recipe
									case 1:
										num++;
										char r_name[100] = { '\0' };
										float p = 0.0;
										printf("Please enter recipe name:\n");
										scanf("%s", r_name);
										printf("Please enter the price:\n");
										scanf("%f", &p);
										cls_title();
										r_current = creatList_recipe_2(r_name, p);
										insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
										insertTree_recipe_name(&(m_current->t_r_head), r_current);
										rc_current->total_number = num;
										break;
									default:
										illegal_number();
										break;
									}
								}
								break;
							default:
								illegal_number();
								break;
							}
						}
					}
					else
					{
						colour(12);
						printf("The username already exist!\n");
						colour(7);
						sleep();
						cls_title();
					}

					break;

					//forget password
				case 3:
					char name_m[100] = { '\0' };
					char phone_m[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_m);
					printf("Please enter your phone number:\n");
					scanf("%s", phone_m);
					delete_several_lines(4);
					if (!get_back_p_m(p_head_m, name_m, phone_m))
					{
						colour(12);
						printf("There is something wrong with the details you entered!\n");
						colour(7);
						sleep();
						delete_several_lines(1);
					}
					cls_title();
					break;
				default:
					illegal_number();
					break;
				}
			}
			break;



			// Deliveryperson
		case 3:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				choose_sign();
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
				cls_title();
				switch (t_1)
				{
					// return
				case 0:
					flag_1 = 0;
					break;

					// sign in
				case 1:
					char name[100] = { '\0' };
					printf("Please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					cls_title();
					if (compare_d(p_head_d, name, &p_d_current))//compare name and password to log in
					{
						d_current = find_d(d_head, name);//find the delivery person in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							cls_title();
							main_menu_DeliveryPerson_1(name);
							int t_2 = 0;
                            fflush(stdout);
							scanf("%d", &t_2);
							cls_title();
							switch (t_2)
							{
								//log out
							case 0:
								flag_2 = 0;
								flag_1 = 0;
								break;

								//show order
							case 1:
								
								
								for (int flag_3 = 1; flag_3 != 0;)
								{
									print_order_list(d_current->o_tail);
									
									main_menu_DeliveryPerson_2();
									int t_3 = 0;
                                    fflush(stdout);
									scanf("%d", &t_3);
									cls_title();
									switch (t_3)
									{
										//log out
									case 0:
										flag_3 = 0;
										flag_2 = 0;
										flag_1 = 0;
										break;

										//set the order statement
									case 1:

										print_current_order(d_current->o_tail);
										main_menu_DeliveryPerson_3();
										int s = 0;
                                        fflush(stdout);
										scanf("%d", &s);
										cls_title();
										if (s == 1)
										{
											d_current->s = BUSY;
										}
										else
										{
											d_current->s = FREE;
										}
										set_state_o(d_current->o_tail, s);
										Synchronization_o_s_for_d(d_current->o_tail, m_head, u_head);
										break;

										//return to the front page
									case 2:
										flag_3 = 0;
										break;
									default:
										illegal_number();
                                        fflush(stdout);
										break;
									}
                                    fflush(stdout);
									
								}
								cls_title();
								break;

								//change password
							case 2:
								deliveryPerson_change_p(d_current, p_d_current);
								break;

								//deactivate
							case 3:
								delete_delivery_person(d_head, d_current->name);
								break;
							default:
								illegal_number();
								break;
							}
							cls_title();
						}
					}
					break;

				case 2:
					char name_3[100] = { '\0' };
					char password[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_3);
					delete_several_lines(2);
					if (duplicate_name_d(p_head_d, name_3))//judge the username
					{
						printf("Please enter your password:\n");
						scanf("%s", password);
						printf("Please enter your phone number:\n");
						scanf("%s", phone);
						delete_several_lines(4);
						d_createList_p(&p_head_d, &p_d_tail, d_creatNode_p(name_3, password, phone));
						d_current = creatList_deliveryperson(name_3, password, phone);
						insertEnd_d(&d_head, &d_tail, d_current);
					}
					else
					{
						colour(12);
						printf("The username already exist!\n");
						colour(7);
						sleep();
						delete_several_lines(1);
					}

					break;

					//forget password
				case 3:
					char name_d[100] = { '\0' };
					char phone_d[100] = { '\0' };
					printf("Please enter your username:\n");
					scanf("%s", name_d);
					printf("Please enter your phone number:\n");
					scanf("%s", phone_d);
					delete_several_lines(4);
					if (!get_back_p_d(p_head_d, name_d, phone_d))
					{
						colour(12);
						printf("There is something wrong with the details you entered!\n");
						colour(7);
						sleep();
						delete_several_lines(1);
					}

					break;
				default:
					illegal_number();
					break;
				}
			}
			break;

			//administrator
		case 4:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				only_sign();
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
				cls_title();
				switch (t_1)
				{
					//return
				case 0:
					flag_1 = 0;
					break;

					//sign in
				case 1:
					char name[100] = { '\0' };
					char password[100] = { '\0' };
					printf("Please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
                    fflush(stdout);
					printf("Please enter your password:\n");
					scanf("%s", password);
					cls_title();
					if (strcmp(name, "adm") == 0)
					{
						if (strcmp(password, "1234") == 0)
						{
							for (int flag_2 = 1; flag_2 != 0;)
							{
								main_menu_Administrator();
								int t_2 = 0;
								fflush(stdout);
								scanf("%d", &t_2);
								cls_title();
								switch (t_2)
								{
									//log out
								case 0:
									flag_2 = 0;
									flag_1 = 0;
									break;

									//merchant
								case 1:
									m_current = m_head;
									int count = 0;
									printf("Merchant:\n");
									while (m_current != NULL)
									{
										printf("        --------------------------------------------\n");
										printf("\t%s\n", m_current->name);
										count++;
										m_current = m_current->next;
									}
									printf("        --------------------------------------------\n");
									printf("Total number:%d\n\n", count);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										main_menu_Administrator_2();
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										delete_several_lines(4);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("Please enter the name:\n");
											char name[100];
                                            fflush(stdout);
											scanf("%s", name);
											delete_merchant(m_head, name);
											delete_several_lines(2);
											printf("The Merchant has been successfully deleted.\n");
											sleep();
											delete_several_lines(1);
											break;
										default:
											illegal_number();
											break;
										}
									}
									cls_title();
									break;

									//user
								case 2:
									u_current = u_head;
									int count_1 = 0;
									printf("User:\n");
									while (u_current != NULL)
									{
										printf("        --------------------------------------------\n");
										printf("\t%s\n", u_current->name);
										count_1++;
										u_current = u_current->next;
									}
									
									printf("        --------------------------------------------\n");
									printf("Total number:%d\n\n", count_1);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										main_menu_Administrator_3();
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										delete_several_lines(4);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("Please enter the name:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											delete_user(u_head, name);
											delete_several_lines(2);
											printf("The User has been successfully deleted.\n");
											sleep();
											delete_several_lines(1);
											break;
										default:
											illegal_number();
											break;
										}
									}
									cls_title();
									break;

									//deliver person
								case 3:
									
									d_current = d_head;
									int count_2 = 0;
									printf("Deliver Person:\n");
									while (d_current != NULL)
									{
										printf("        --------------------------------------------\n");
										printf("\t%s\n", d_current->name);
										count_2++;
										d_current = d_current->next;
									}
									
									printf("        --------------------------------------------\n");
									printf("Total number:%d", count_2);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										main_menu_Administrator_4();
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										delete_several_lines(4);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("Please enter the name:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											delete_delivery_person(d_head, name);
											delete_several_lines(2);
											printf("The Deliver Person has been successfully deleted.\n");
											sleep();
											delete_several_lines(1);
											break;
										default:
											illegal_number();
											break;
										}
									}
									cls_title();
									break;

									//change discount
								case 4:
									for (int flag_3 = 1; flag_3 != 0;)
									{
										main_menu_Administrator_5();
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										delete_several_lines(4);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("Please enter the card class:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											printf("Please enter the new discount:\n");
											float d = 0.0;
                                            fflush(stdout);
											scanf("%f", &d);
											delete_several_lines(4);
											if (d > 0 && d <= 1)
											{
												change_discount_manager(name, d);
											}
											else
											{
												illegal_number();
											}
											break;
										default:
											illegal_number();
											break;
										}
									}
									break;
								default:
									illegal_number();
									break;
								}
								cls_title();
							}

						}
					}
					break;
				default:
					illegal_number();
					break;
				}

			}
			break;
		default:
			illegal_number();
            fflush(stdout);
			break;
		}
	}

	//write in file
	d_writeIntoFile_p(p_head_d);
	m_writeIntoFile_p(p_head_m);
	u_writeIntoFile_p(p_head_u);
	write_t_merchant_list(m_head);
	write_t_user_list(u_head);
	write_t_deliveryperson_list(d_head);


	return 0;
}
