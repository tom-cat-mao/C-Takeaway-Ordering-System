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
#include"wordcolour.h"

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
	read_merchant_list(&m_head, &m_tail);
	read_user_list(&u_head, &u_tail);
	read_deliveryperson_list(&d_head, &d_tail);

	//enter the program
	print_Title();

	for (int flag = 1; flag != 0;)
	{
		printf("please choose your identity:(0.Close,1.User,2.Merchant,3.Delivery Preson,4.administrator)\n");
        fflush(stdout);
		int t = 0;
		scanf("%d", &t);
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
				printf("0.return,1.sign in,2.sign up\n");
                fflush(stdout);
				int t_1 = 0;
				scanf("%d", &t_1);
				switch (t_1)
				{
					//return
				case 0:
					flag_1 = 0;
					break;

					//sign in
				case 1:
					char name[100];
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					if (compare_u(p_head_u, name, &p_u_current))//compare the user's name and password
					{
						u_current = find_u(u_head, name);//find user in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.make an order,2.view and cancel order,3.change card,4.password change,5.deactivate\n");
                            fflush(stdout);
							int t_2 = 0;
							scanf("%d", &t_2);
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
									printf("0.log out,1.choose a merchant,2.return\n");
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);
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
										printf("please enter the merchant you choose:\n");
                                        fflush(stdout);
										scanf("%s", m_name);
										m_current = search_Merchant_name(t_m_head, m_name);

										int judge = 0;

										for (int flag_4 = 1; flag_4 != 0;)
										{
											printList_r_classify(m_current->r_head);
                                            fflush(stdout);
											printf("0.log out,1.sort,2.search,3choose,4.return||finish\n");
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
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
													printf("0.log out,1.sort,2.return\n");
                                                    fflush(stdout);
													int t_5 = 0;
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
															printf("0.return,1.sort by price,2.sort by stars,3.sort by comprehensive\n");
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
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
																	printf("0.return,1.upper,2.lower,3.choose\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortUpper_p(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_p(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		break;
																	}
																}
																break;

																//sort by star
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("0.return,1.upper,2.lower\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortUpper_s(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_s(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
																		break;
																	default:
																		break;
																	}
																}
																break;

																//sort by comprehensive
															case 3:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("0.return,1.upper,2.lower\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortUpper_c(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_c(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//choose
																	case 3:
																		judge = 1;

																		char r_name[100] = { '\0' };
																		printf("please enter the recipe name:\n");
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
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
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//search
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.return,1.accurate search,2.fuzzy search,3.price range,4.sale recipe\n");
													int t_5 = 0;
													scanf("%d", &t_5);
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
															printf("0.return,1.single inquiry,2.combination inquiry\n");
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
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
																	printf("0.return,1.continue\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//continue
																	case 1:
																		char r_name[100] = { '\0' };
																		printf("please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		if (r_current == NULL)
																		{
																			printf("we don't have the recipe you search\n");
                                                                            fflush(stdout);
																		}
																		else
																		{
																			//print
																			char j;
																			printf("Y\\N(Y for choose this recipe)\n");
                                                                            fflush(stdout);
																			scanf("%c", &j);
																			if (j == 'Y')
																			{
																				judge = 1;
																				printf("pleae enter the number you want:\n");
                                                                                fflush(stdout);
																				int n = 0;
																				scanf("%d", &n);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																				insertEnd_r(&r_head, &r_tail, r_current);
																			}
																		}
																		break;
																	default:
																		break;
																	}
																}


																break;

																//combination inquiry
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("0.return,1.continue\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
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
																		printf("please enter the r_class and the rcipe you want to search:\n");
                                                                        fflush(stdout);
																		scanf("%s", rc_name);
																		scanf("%s", r_name);
																		rc_current = find_r_classify(m_current, rc_name);
																		if (rc_current == NULL)
																		{
																			printf("we don't have the class you want\n");
                                                                            fflush(stdout);
																		}
																		else
																		{
																			r_current = find_recipe_by_list(rc_current, r_name);
																			if (r_current == NULL)
																			{
																				printf("we don't have the recipe you search\n");
                                                                                fflush(stdout);
																			}
																			else
																			{
																				//print
																				char j;
																				printf("Y\\N(Y for choose this recipe)\n");
                                                                                fflush(stdout);
																				scanf("%c", &j);
																				if (j == 'Y')
																				{
																					judge = 1;
																					printf("pleae enter the number you want:\n");
                                                                                    fflush(stdout);
																					int n = 0;
																					scanf("%d", &n);
																					r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																					insertEnd_r(&r_head, &r_tail, r_current);
																				}
																			}
																		}
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
														break;

														//fuzzy search
													case 2:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.return,1.continue\n");
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
															switch (t_6)
															{
																//return
															case 0:
																flag_6 = 0;
																break;

																//continue
															case 1:
																char str[100] = { '\0' };
																printf("please enter the string you want to search:\n");
                                                                fflush(stdout);
																scanf("%s", str);
																FuzzySearchInClassify(m_current->r_head, str);
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("whether you want to order any recipe\n");
                                                                    fflush(stdout);
																	printf("0.return,1.continue\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
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
																		printf("please enter the recipe name:\n");
                                                                        fflush(stdout);
																		scanf("%s", r_name);
																		r_current = search_recipe_name(m_current->t_r_head, r_name);
																		printf("pleae enter the number you want:\n");
                                                                        fflush(stdout);
																		int n = 0;
																		scanf("%d", &n);
																		r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																		insertEnd_r(&r_head, &r_tail, r_current);
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
														break;

														//price range
													case 3:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.return,1.continue\n");
															int t_6 = 0;
															scanf("%d", &t_6);
                                                            fflush(stdout);
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
																printf("please enter the max price and the min price:\n");
                                                                fflush(stdout);
																scanf("%f%f", &max_price, &min_price);
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("0.return,1.lower,2.upper\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																	case 0:
																		flag_7 = 0;
																		break;
																	case 1:
																		output_recipe_high_to_low(m_current->r_head, min_price, max_price);
																		for (int flag_8 = 1; flag_8 != 0;)
																		{
																			printf("whether you want to order any recipe\n");
																			printf("0.return,1.continue\n");
                                                                            fflush(stdout);
																			int t_8 = 0;
																			scanf("%d", &t_8);
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
																				printf("please enter the recipe name:\n");
                                                                                fflush(stdout);
																				scanf("%s", r_name);
																				r_current = search_recipe_name(m_current->t_r_head, r_name);
																				printf("pleae enter the number you want:\n");
                                                                                fflush(stdout);
																				int n = 0;
																				scanf("%d", &n);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
                                                                                fflush(stdout);
																				insertEnd_r(&r_head, &r_tail, r_current);
																				break;
																			default:
																				break;
																			}
																		}
																		break;
																	case 2:
																		output_recipe_low_to_high(m_current->r_head, min_price, max_price);
																		for (int flag_8 = 1; flag_8 != 0;)
																		{
																			printf("whether you want to order any recipe\n");
																			printf("0.return,1.continue\n");
                                                                            fflush(stdout);
																			int t_8 = 0;
																			scanf("%d", &t_8);
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
																				printf("please enter the recipe name:\n");
                                                                                fflush(stdout);
																				scanf("%s", r_name);
																				r_current = search_recipe_name(m_current->t_r_head, r_name);
																				printf("pleae enter the number you want:\n");
																				int n = 0;
																				scanf("%d", &n);
																				r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																				insertEnd_r(&r_head, &r_tail, r_current);
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
																break;
															default:
																break;
															}
														}
														break;

														//sale recipe
													case 4:
														SaleRecipeSearch(m_current->t_r_head);
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.return,1.continue\n");
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
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
																printf("please enter the recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																printf("pleae enter the number you want:\n");
                                                                fflush(stdout);
																int n = 0;
																scanf("%d", &n);
																r_current = creatList_recipe_1(r_current->name, r_current->price, n);
																insertEnd_r(&r_head, &r_tail, r_current);
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

												break;

												//choose
											case 3:
												judge = 1;

												char r_name[100] = { '\0' };
												printf("please enter the recipe name:\n");
                                                fflush(stdout);
												scanf("%s", r_name);
												r_current = search_recipe_name(m_current->t_r_head, r_name);
												printf("please enter the number you want:\n");
                                                fflush(stdout);
												int n = 0;
												scanf("%d", &n);
												r_current = creatList_recipe_1(r_current->name, r_current->price, n);
												insertEnd_r(&r_head, &r_tail, r_current);
												break;

												//return||finish
											case 4:
												flag_4 = 0;
												break;
											default:
												break;
											}
										}

										if (judge == 1)
										{
											d_current = find_free_d(d_head);
											o_current = creatList_order(m_current, u_current, d_current);
											o_current->r_head = r_head;
											o_current->r_tail = r_tail;
											o_current->sum_price = sumPrice(o_current, o_current->r_head, u_current->c, discount);
											insertEnd_o(&(u_current->o_head), &(u_current->o_tail), o_current);
											insertEnd_o(&(m_current->o_head), &(m_current->o_tail), o_current);
											insertEnd_o(&(d_current->o_head), &(d_current->o_tail), o_current);
											insertTree_order_id(&(u_current->t_o_head), o_current);
											insertTree_order_id(&(m_current->t_o_head), o_current);
										}

										break;

										//return
									case 2:
										flag_3 = 0;
										break;
									default:
										break;
									}
								}
								break;

								//view and cancel order
							case 2:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									printf("0.log out,1.show order,2.cancel order,3.return\n");
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);
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
											printf("0.log out,1.sort in time,2.sort in price,3.search,4.return\n");
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
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
													printf("0.return,1.upper,2.lower\n");
                                                    fflush(stdout);
													int  t_5 = 0;
													scanf("%d", &t_5);
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
														break;

														//lower
													case 2:
														u_current->o_head = o_mergeSortUpper_t(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
                                                        fflush(stdout);
														break;
													default:
														break;
													}
												}
												break;

												//sort in price
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.return,1.upper,2.lower\n");
													int  t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														break;

														//lower
													case 2:
														u_current->o_head = o_mergeSortUpper_p(u_current->o_head, &(u_current->o_tail));
														print_order_list(u_current->o_tail);
														break;
													default:
														break;
													}
												}
												break;


											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1.contiune,2.return\n");
													int t_5 = 0;
													scanf("%d", &t_5);
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
														printf("please enter the order you want to search:\n");
														fflush(stdout);
														scanf("%s", o_id);
														o_current = search_order_id(u_current->t_o_head, o_id);
														//print
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
													
												}
												break;
												//return
											case 4:
												flag_4 = 0;
												break;
											default:
												break;
											}
										}
										break;

										//cancel order
									case 2:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(u_current->o_tail);
											printf("0.log out,1.contiune,2.return\n");
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
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
												printf("please enter the order id you want to cancel\n");
                                                fflush(stdout);
												scanf("%s", o_id);
												o_current = search_order_id(u_current->t_o_head, o_id);
												printf("Y\\N(Y for cancle)\n");
												char j;
                                                fflush(stdout);
												scanf("%c", &j);
												switch (j)
												{
												case 'Y':
													o_current->s = CANCEL;
													Synchronization_o_s_for_u(o_current, m_head, d_head);
													break;
												case 'N':
													break;
												default:
													break;
												}
												break;

												//return
											case 2:
												flag_4 = 0;
												break;
											default:
												break;
											}

										}
										break;

										//return
									case 3:
										flag_3 = 0;
										break;
									default:
										break;
									}
								}
								break;

								//change card
							case 3:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									printf("0.return,1.contiune\n");
									int t_3 = 0;
									scanf("%d", &t_3);
									switch (t_3)
									{
										//return
									case 0:
										flag_3 = 0;
										break;

										//continue
									case 1:
										printf("1.SILVER,2.GOLD,3.PLATINUM\n");
										int t_3 = 0;
										fflush(stdout);
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
											break;
										}
										break;
									default:
										break;
									}
									
								}
								break;

								//change password
							case 4:
								user_change_p(u_current, p_u_current);
								break;

								//deactivate
							case 5:
								delete_user(u_head, u_current->name);
								break;
							default:
								break;
							}
						}

					}
					break;

					//sign up
				case 2:
					//create user's detail information
					char name_1[100];
					char password[100] = { '\0' };
					char address[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name_1);
					printf("please enter your password:\n");
                    fflush(stdout);
					scanf("%s", password);
					printf("please enter your address:\n");
                    fflush(stdout);
					scanf("%s", address);
					printf("please enter your phone number:\n");
                    fflush(stdout);
					scanf("%s", phone);
					u_createList_p(&p_head_u, &p_u_tail, u_creatNode_p(name_1, password, phone));
					u_current = creatList_user(name_1, password, address, phone);
					insertEnd_u(&u_head, &u_tail, u_current);
					break;
				default:
					break;
				}
			}
			break;





			//Merchant
		case 2:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				printf("0.Return,1.Sign in,2.Sign up\n");
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
				switch (t_1)
				{
					//return to the front page
				case 0:
					flag_1 = 0;
					break;

					//sign in
				case 1:
					char name[100] = { '\0' };
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					if (compare_m(p_head_m, name, &p_m_current))//compare the merchant's name and password
					{
						m_current = find_m(m_head, name);//find the merchant in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.recipe,2.order,3.password£¬4.deactivate\n");
							int t_2 = 0;
                            fflush(stdout);
							scanf("%d", &t_2);
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
									printList_r_classify(m_current->r_head);
									printf("0.log out,1.operate in recipe class,2.operate in recipe,3return\n");
									int t_3 = 0;
                                    fflush(stdout);
									scanf("%d", &t_3);
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

											printf("0.log out,1.add recipe class,2.delete recipe class,3.change recipe class's name,4.inquiry recipe class,5.return\n");
											int t_4 = 0;
                                            fflush(stdout);
											scanf("%d", &t_4);
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
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter your recipe class name:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = creatList_r_classify(rc_name);
														insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; flag_6++)
														{
															printf("0.return,1.add recipe\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
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
																printf("please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																printf("please enter the price:\n");
                                                                fflush(stdout);
																scanf("%f", &p);
																r_current = creatList_recipe_2(r_name, p);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = flag_6;
																break;
															default:
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//delete recipe class
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter the recipe class you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);
														delete_specific_r_class(&rc_current, &(m_current->r_head), &(m_current->r_tail));
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//change recipe name
											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter the recipe class you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);
														char new_rc_name[100] = { '\0' };
														printf("please enter the new name:\n");
                                                        fflush(stdout);
														scanf("%s", new_rc_name);
														strcpy(rc_current->name, new_rc_name);
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//inquiry recipe class
											case 4:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter the recipe class you want to see:\n");
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);
														printList_recipe_1(rc_current->r_head);
														break;
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//return
											case 5:
												flag_4 = 0;
												break;
											default:
												break;
											}
										}
										break;

										//operate in recipe
									case 2:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											printf("0.log out,1.add recipe,2.delete recipe,3.move recipe,4.inquiry recipe,5.set slae recipe,6.sort recipe,7.return\n");
											int t_4 = 0;
                                            fflush(stdout);
											scanf("%d", &t_4);
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
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter your recipe class name you want to operate:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.add recipe\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
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
																printf("please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																printf("please enter the price:\n");
                                                                fflush(stdout);
																scanf("%f", &p);
																r_current = creatList_recipe_2(r_name, p);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = rc_current->total_number + 1;
																break;
															default:
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}
												break;

												//delete recipe
											case 2:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter your recipe class name you want to operate:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//delete recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.delete recipe\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//delete recipe
															case 1:
																char r_name[100] = { '\0' };
																printf("please enter recipe name you want to delete:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																delete_recipe_name(&(m_current->t_r_head), r_name, &(rc_current->r_head), &(rc_current->r_tail));
																rc_current->total_number = rc_current->total_number - 1;
																break;
															default:
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}
												break;

												//move recipe
											case 3:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1,continue,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter the recipe class name you want to move from:\n");
														char rc_name[100] = { '\0' };
                                                        fflush(stdout);
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//move recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.move recipe\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
															switch (t_6)
															{
																// return to the front page
															case 0:
																flag_6 = 0;
																break;

																//move recipe
															case 1:
																char r_name[100] = { '\0' };
																printf("please enter recipe name:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																r_current = creatList_recipe_2(r_current->name, r_current->price);
																rc_current->total_number = rc_current->total_number - 1;
																delete_recipe_name(&(m_current->t_r_head), r_name, &(rc_current->r_head), &(rc_current->r_tail));
																printf("please enter the recipe class name you want to move in:\n");
																char rc_name[100] = { '\0' };
                                                                fflush(stdout);
																scanf("%s", rc_name);
																rc_current = find_r_classify(m_current, rc_name);
																insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
																insertTree_recipe_name(&(m_current->t_r_head), r_current);
																rc_current->total_number = rc_current->total_number + 1;
																break;
															default:
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;

												//inquiry recipe
											case 4:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1.fuzzy search,2.sale recipe search,3.search price range,4.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
															printf("0.log out,1.continue,2.return\n");
															int t_6 = 0;
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
																printf("please enter the name you want to search:");
																scanf("%s", str);
                                                                fflush(stdout);
																FuzzySearchInClassify(m_current->r_head, str);
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																break;
															}
														}
														break;

														//sale recipe search
													case 2:
														SaleRecipeSearch(m_current->t_r_head);
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.log out,1.continue,2.return\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
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
																printf("please enter the recipe you want to operate:\n");
                                                                fflush(stdout);
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																for (;;)
																{
																	printf("please enter the sale discount:\n");
																	float sale = 0.0;
                                                                    fflush(stdout);
																	scanf("%f", sale);
																	if (bool_set_sale_recipe(r_current, sale))
																	{
																		break;
																	}
																}
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																break;
															}
														}


														break;

														//search price range
													case 3:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.log out,1.continue,2.return\n");
															int t_6 = 0;
                                                            fflush(stdout);
															scanf("%d", &t_6);
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
																printf("please enter the max price and the min price:\n");
                                                                fflush(stdout);
																scanf("%d%d", &max_price, &min_price);
																for (int flag_7 = 1; flag_7 = 0;)
																{
																	printf("0.return,1.lower,2.upper\n");
																	int t_7 = 0;
                                                                    fflush(stdout);
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																	case 0:
																		flag_7 = 0;
																		break;
																	case 1:
																		output_recipe_high_to_low(m_current->r_head, min_price, max_price);
																		break;
																	case 2:
																		output_recipe_low_to_high(m_current->r_head, min_price, max_price);
																		break;
																	default:
																		break;
																	}
																}
																break;

																//return
															case 2:
																flag_6 = 0;
																break;
															default:
																break;
															}
														}
														break;

														//return
													case 4:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}
												break;

												//set sale recipe
											case 5:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1.set sale recipe,2.return\n");
													int t_5 = 0;
                                                    fflush(stdout);
													scanf("%d", &t_5);
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
														printf("please enter the recipe you want to operate:\n");
                                                        fflush(stdout);
														scanf("%s", r_name);
														r_current = search_recipe_name(m_current->t_r_head, r_name);
														for (;;)
														{
															printf("please enter the sale discount:\n");
                                                            fflush(stdout);
															float sale = 0;
															scanf("%f", sale);
															if (bool_set_sale_recipe(r_current, sale))
															{
																break;
															}
														}
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}

												break;


												//sort recipe
											case 6:
												for (int flag_5 = 0; flag_5 != 0;)
												{
													printf("0.log out,1.sort,2.return\n");
                                                    fflush(stdout);
													int t_5 = 0;
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
														for (int flag_6 = 0; flag_6 != 0;)
														{
															printf("0.return,1.sort by price,2.sort by stars\n");
                                                            fflush(stdout);
															int t_6 = 0;
															scanf("%d", &t_6);
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
																	printf("0.return,1.upper,2.lower\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortUpper_p(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_p(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;
																	default:
																		break;
																	}
																}
																break;

																//sort by star
															case 2:
																for (int flag_7 = 1; flag_7 != 0;)
																{
																	printf("0.return,1.upper,2.lower\n");
                                                                    fflush(stdout);
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																		//return
																	case 0:
																		flag_7 = 0;
																		break;

																		//upper
																	case 1:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortUpper_s(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_s(m_current->r_head->r_head, &(m_current->r_head->r_tail));
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
                                                                        fflush(stdout);
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
														break;

														//return
													case 2:
														flag_5 = 0;
														break;
													default:
														break;
													}
												}
												break;


												//return
											case 7:
												flag_4 = 0;
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
								break;

								//setting in order
							case 2:
								for (int flag_3 = 1; flag_3 != 0;)
								{
									print_order_list(m_current->o_tail);
									printf("0.log out,1.distribute delivery person2.sort order,3,return");
                                    fflush(stdout);
									int t_3 = 0;
									scanf("%d", &t_3);
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
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(m_current->o_tail);
											printf("0.return,1.continue\n");
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
											switch (t_4)
											{
												//return
											case 0:
												flag_4 = 0;
												break;

												//continue
											case 1:
												printf("you can only operate the order which haven't distributed a delivery person\n");
												char o_id[100] = { '\0' };
												printf("please enter the order you want to operate:\n");
                                                fflush(stdout);
												scanf("%s", o_id);
												o_current = search_order_id(m_current->t_o_head, o_id);
												//
												d_current = find_free_d(d_head);
												strcpy(o_current->d_name, d_current->name);
												strcpy(o_current->d_phone, d_current->phone);
												Synchronization_o_d_for_m(o_current, d_head, u_head);
												break;
											default:
												break;
											}

										}
										break;

										//sort order
									case 2:
										for (int flag_4 = 1; flag_4 != 0;)
										{
											print_order_list(m_current->o_tail);
											printf("0.log out,1.upper,2.lower,3.return\n");
                                            fflush(stdout);
											int t_4 = 0;
											scanf("%d", &t_4);
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
												break;

												//lower
											case 2:
												m_current->o_tail = o_mergeSortUpper_t(m_current->o_head, &(m_current->o_tail));
												print_order_list(m_current->o_tail);
                                                fflush(stdout);
												break;

												//return
											case 3:
												flag_4 = 0;
												break;
											default:
												break;
											}
										}
										break;

										//return
									case 3:
										flag_3 = 0;
										break;
									default:
										break;
									}
								}
								break;

								//password change
							case 3:
								merchant_change_p(m_current, p_m_current);
								break;

								//deactivate
							case 4:
								delete_merchant(m_head, m_current->name);
								break;
							default:
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
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name_2);
					printf("please enter your password:\n");
                    fflush(stdout);
					scanf("%s", password);
					printf("please enter your address:\n");
                    fflush(stdout);
					scanf("%s", address);
					printf("please enter your phone number:\n");
                    fflush(stdout);
					scanf("%s", phone);
					m_createList_p(&p_head_m, &p_m_tail, m_creatNode_p(name_2, password, phone));
					m_current = creatList_merchant(name_2, password, address, phone);
					insertEnd_m(&m_head, &m_tail, m_current);
					insertTree_Merchant_name(&t_m_head, m_current);
					printf("continue to create recipe\n");
                    fflush(stdout);

					//create recipe class and recipe
					for (int flag_2 = 1; flag_2 != 0;)
					{
						printf("0.return,1.contiune\n");
						int t_2 = 0;
                        fflush(stdout);
						scanf("%d", &t_2);
						switch (t_2)
						{
							//return to the front page
						case 0:
							flag_2 = 0;
							break;

							//create recipe class and recipe
						case 1:
							printf("please enter your recipe class name:\n");
							char rc_name[100] = { '\0' };
                            fflush(stdout);
							scanf("%s", rc_name);
							rc_current = creatList_r_classify(rc_name);
							insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);

							//create recipe
							for (int flag_3 = 1; flag_3 != 0;)
							{
								printf("0.return,1.add recipe\n");
								int t_3 = 0;
                                fflush(stdout);
								scanf("%d", &t_3);
								switch (t_3)
								{
									// return to the front page
								case 0:
									flag_3 = 0;
									break;

									//create recipe
								case 1:
									char r_name[100] = { '\0' };
									float p = 0.0;
									printf("please enter recipe name:\n");
                                    fflush(stdout);
									scanf("%s", r_name);
									printf("please enter the price:\n");
                                    fflush(stdout);
									scanf("%f", &p);
									r_current = creatList_recipe_2(r_name, p);
									insertEnd_r(&(rc_current->r_head), &(rc_current->r_tail), r_current);
									insertTree_recipe_name(&(m_current->t_r_head), r_current);
									rc_current->total_number = flag_3;
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
					break;
				default:
					printf("wrong choice!\n");
                    fflush(stdout);
					break;
				}
			}
			break;




			// Deliveryperson
		case 3:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				printf("0.Return,1.Sign in,2.Sign up\n");
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
				switch (t_1)
				{
					// return
				case 0:
					flag_1 = 0;
					break;

					// sign in
				case 1:
					char name[100] = { '\0' };
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
					if (compare_d(p_head_d, name, &p_d_current))//compare name and password to log in
					{
						d_current = find_d(d_head, name);//find the delivery person in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.order,2.change password,3.deactivate\n");
							int t_2 = 0;
                            fflush(stdout);
							scanf("%d", &t_2);
							switch (t_2)
							{
								//log out
							case 0:
								flag_2 = 0;
								flag_1 = 0;
								break;

								//show order
							case 1:
								print_order_list(d_current->o_tail);

								for (int flag_3 = 1; flag_3 != 0;)
								{
									printf("0.log out,1.set the order,2.return\n");
									int t_3 = 0;
                                    fflush(stdout);
									scanf("%d", &t_3);
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
										printf("please enter the statement of the order:(1.delivering,2.Finish)\n");
										int s = 0;
                                        fflush(stdout);
										scanf("%d", &s);
										set_state_o(d_current->o_tail, s);
										Synchronization_o_s_for_d(d_current->o_tail, m_head, u_head);
										break;

										//return to the front page
									case 2:
										flag_3 = 0;
										break;
									default:
										printf("wrong choice!\n");
                                        fflush(stdout);
										break;
									}
									print_current_order(d_current->o_tail);
                                    fflush(stdout);
								}

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
								printf("wrong choice!\n");
								break;
							}
						}
					}
					break;

					// sign up
				case 2:
					char name_3[100] = { '\0' };
					char password[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name_3);
					printf("please enter your password:\n");
                    fflush(stdout);
					scanf("%s", password);
					printf("please enter your phone number:\n");
                    fflush(stdout);
					scanf("%s", phone);
					d_createList_p(&p_head_d, &p_d_tail, d_creatNode_p(name_3, password, phone));
					d_current = creatList_deliveryperson(name_3, password, phone);
					insertEnd_d(&d_head, &d_tail, d_current);
					break;
				default:
					printf("wrong choice!\n");
                    fflush(stdout);
					break;
				}
			}
			break;

			//administrator
		case 4:
			for (int flag_1 = 1; flag_1 != 0;)
			{
				printf("0.return,1.sign in\n");
				int t_1 = 0;
                fflush(stdout);
				scanf("%d", &t_1);
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
					printf("please enter your username:\n");
                    fflush(stdout);
					scanf("%s", name);
                    fflush(stdout);
					printf("please enter your password:\n");
					scanf("%s", password);
					if (strcmp(name, "adm") == 0)
					{
						if (strcmp(password, "1234") == 0)
						{
							for (int flag_2 = 1; flag_2 != 0;)
							{
								printf("0.log out,1.merchant,2.user,3.deliver person,4.change discount\n");
								int t_2 = 0;
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
									while (m_current != NULL)
									{
										printf("%s\n", m_current->name);
										count++;
										m_current = m_current->next;
									}
									printf("total number:%d", count);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										printf("0.return,1.delete merchant\n");
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("please enter the name:\n");
											char name[100];
                                            fflush(stdout);
											scanf("%s", name);
											delete_merchant(m_head, name);
											break;
										default:
											break;
										}
									}
									break;

									//user
								case 2:
									u_current = u_head;
									int count_1 = 0;
									while (u_current != NULL)
									{
										printf("%s\n", u_current->name);
										count_1++;
										u_current = u_current->next;
									}
									printf("total number:%d", count_1);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										printf("0.return,1.delete user\n");
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("please enter the name:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											delete_user(u_head, name);
											break;
										default:
											break;
										}
									}
									break;

									//deliver person
								case 3:
									d_current = d_head;
									int count_2 = 0;
									while (d_current != NULL)
									{
										printf("%s\n", d_current->name);
										count_2++;
										d_current = d_current->next;
									}
									printf("total number:%d", count_2);
									for (int flag_3 = 1; flag_3 != 0;)
									{
										printf("0.return,1.delete delivery person\n");
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("please enter the name:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											delete_delivery_person(d_head, name);
											break;
										default:
											break;
										}
									}
									break;

									//change discount
								case 4:
									for (int flag_3 = 1; flag_3 != 0;)
									{
										printf("0.return,1.change discount\n");
										int t_3 = 0;
                                        fflush(stdout);
										scanf("%d", &t_3);
										switch (t_3)
										{
											//return
										case 0:
											flag_3 = 0;
											break;

											//delete
										case 1:
											printf("please enter the card class:\n");
											char name[100] = { '\0' };
                                            fflush(stdout);
											scanf("%s", name);
											printf("please enter the new discount:\n");
											float d = 0.0;
                                            fflush(stdout);
											scanf("%f", &d);
											if (d > 0 && d <= 1)
											{
												change_discount_manager(name, d);
											}
											else
											{
												printf("illegal input\n");
											}
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

						}
					}
					break;
				default:
					break;
				}

			}
			break;
		default:
			printf("wrong choice!\n");
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
