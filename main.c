#include"class.h"
#include"classTree.h"
#include"folder_create_change_delete.h"
#include"SearchFuzzy&SaleRecipe.h"
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
	recipe* r_tail;
	r_classify* rc_head;
	r_classify* rc_current;
	r_classify* rc_tail;
	order* o_head;
	order* o_current;
	order* o_tail;
	Merchant* m_head;
	Merchant* m_current;
	Merchant* m_tail;
	User* u_head;
	User* u_current;
	User* u_tail;
	DeliveryPerson* d_head;
	DeliveryPerson* d_current;
	DeliveryPerson* d_tail;

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
		//close
		case 0:
			flag = 0;
			break;


		//User
		case 1:
			break;





		//Merchant
		case 2:
			for (int flag_1 = 1; flag_1 = 0;)
			{
				printf("0.Return,1.Sign in,2.Sign up\n");
				int t_1 = 0;
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
					scanf("%s", name);
					if (compare_m(p_head_m, name, &p_m_current))//compare the merchant's name and password
					{
						m_current = find_m(m_head, name);//find the merchant in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.recipe,2.order,3.password");
							int t_2 = 0;
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
														scanf("%s", rc_name);
														rc_current = creatList_r_classify(rc_name);
														insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; flag_6++)
														{
															printf("0.return,1.add recipe\n");
															int t_6 = 0;
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
																scanf("%s", r_name);
																printf("please enter the price:\n");
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
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);
														char new_rc_name[100] = { '\0' };
														printf("please enter the new name:\n");
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
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//create recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.add recipe\n");
															int t_6 = 0;
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
																scanf("%s", r_name);
																printf("please enter the price:\n");
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
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//delete recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.delete recipe\n");
															int t_6 = 0;
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
														scanf("%s", rc_name);
														rc_current = find_r_classify(m_current, rc_name);

														//move recipe
														for (int flag_6 = 1; flag_6 != 0; )
														{
															printf("0.return,1.move recipe\n");
															int t_6 = 0;
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
																scanf("%s", r_name);
																r_current = search_recipe_name(m_current->t_r_head, r_name);
																r_current = creatList_recipe_2(r_current->name, r_current->price);
																rc_current->total_number = rc_current->total_number - 1;
																delete_recipe_name(&(m_current->t_r_head), r_name, &(rc_current->r_head), &(rc_current->r_tail));
																printf("please enter the recipe class name you want to move in:\n");
																char rc_name[100] = { '\0' };
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



														break;

													//search price range
													case 3:
														for (int flag_6 = 1; flag_6 != 0;)
														{
															printf("0.log out,1.continue,2.return\n");
															int t_6 = 0;
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
																scanf("%d%d", &max_price, &min_price);
																for (int flag_7 = 1; flag_7 = 0;)
																{
																	printf("0.return,1.lower,2.upper\n");
																	int t_7 = 0;
																	scanf("%d", &t_7);
																	switch (t_7)
																	{
																	case 0:
																		flag_7 = 0;
																		break;
																	case 1:
																		//output_recipe_high_to_low();
																		break;
																	case 2:
																		//output_recipe_low_to_high();
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

											//set slae recipe
											case 5:
												for (int flag_5 = 1; flag_5 != 0;)
												{
													printf("0.log out,1.set sale recipe,2.return\n");
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

													//set sale recip
													case 1:
														char r_name[100] = { '\0' };
														printf("please enter the recipe you want to operate:\n");
														scanf("%s", r_name);
														r_current = search_recipe_name(m_current->t_r_head, r_name);
														for (;;)
														{
															printf("please enter the sale discount:\n");
															float sale = 0.0;
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
																			m_current->r_head->r_head = r_mergeSortUpper_p(m_current->r_head->r_head);
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
																		break;

																	//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_p(m_current->r_head->r_head);
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
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
																			m_current->r_head->r_head = r_mergeSortUpper_s(m_current->r_head->r_head);
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
																		break;

																		//lower
																	case 2:
																		while (m_current->r_head != NULL)
																		{
																			m_current->r_head->r_head = r_mergeSortLower_s(m_current->r_head->r_head);
																			m_current->r_head = m_current->r_head->next;
																		}
																		printList_r_classify(m_current->r_head);
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





								break;

							//password change
							case 3:
								merchant_change_p(m_current, p_m_current);
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
					char name[100] = { '\0' };
					char password[100] = { '\0' };
					char address[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("please enter your username:\n");
					scanf("%s", name);
					printf("please enter your password:\n");
					scanf("%s", password);
					printf("please enter your address:\n");
					scanf("%s", address);
					printf("please enter your phone number:\n");
					scanf("%s", phone);
					m_createList_p(&p_head_m, &p_m_current, m_creatNode_p(name, password, phone));
					m_current = creatList_merchant(name, password, address, phone);
					insertEnd_m(&m_head, &m_tail, m_current);
					insertTree_Merchant_name(&t_m_head, m_current);
					printf("continue to create recipe\n");

					//create recipe class and recipe
					for (int flag_2 = 1; flag_2 != 0;)
					{
						printf("0.return,1.contiune\n");
						int t_2 = 0;
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
							scanf("%s", rc_name);
							rc_current = creatList_r_classify(rc_name);
							insertEnd_rc(&(m_current->r_head), &(m_current->r_tail), rc_current);

							//create recipe
							for (int flag_3 = 1; flag_3 != 0; flag_3++)
							{
								printf("0.return,1.add recipe\n");
								int t_3 = 0;
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
									scanf("%s", r_name);
									printf("please enter the price:\n");
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
					scanf("%s", name);
					if (compare_d(p_head_d, name,&p_d_current))//compare name and password to log in
					{
						d_current = find_d(d_head, name);//find the delivery person in the list

						for (int flag_2 = 1; flag_2 != 0;)
						{
							printf("0.log out,1.order,2.change password");
							int t_2 = 0;
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
										scanf("%d", &s);
										set_state_o(d_current->o_tail, s);
										Synchronization_o_s(d_current->o_tail, m_head, u_head);
										break;

									//return to the front page
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

							//change password
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

				// sign up
				case 2:
					char name[100] = { '\0' };
					char password[100] = { '\0' };
					char phone[100] = { '\0' };
					printf("please enter your username:\n");
					scanf("%s", name);
					printf("please enter your password:\n");
					scanf("%s", password);
					printf("please enter your phone number:\n");
					scanf("%s", phone);
					d_createList_p(&p_head_d, &p_d_current, d_creatNode_p(name, password, phone));
					d_current = creatList_deliveryperson(name, password, phone);
					insertEnd_d(&d_head, &d_tail, d_current);
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