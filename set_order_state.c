#define _CRT_SECURE_NO_WARNINGS
#include "class.h"
#include"classTree.h"

// Set the state of the order
void set_state_o(order* tail, int s)
{
	tail->s = s;
	if (s == 1)
	{
		set_time(tail->send_time);
	}
	if (s == 2)
	{
		set_time(tail->arrive_time);
		tail->total_time = mktime(tail->arrive_time) - mktime(tail->send_time);
	}
}

// Synchronization order statement
void Synchronization_o_s_for_d(order* tail, Merchant* m_head, User* u_head)
{
	Merchant* m_current = find_m(m_head, tail->m_name);
	User* u_current = find_u(u_head, tail->u_name);
	order* o_current_u = search_order_id(u_current->t_o_head, tail->order_id);
	order* o_current_m = search_order_id(m_current->t_o_head, tail->order_id);
	o_current_m->s = tail->s;
	o_current_u->s = tail->s;
	if (tail->s == 1)
	{
		o_current_m->send_time = tail->send_time;
		o_current_u->send_time = tail->send_time;
	}
	if (tail->s == 2)
	{
		o_current_m->arrive_time = tail->arrive_time;
		o_current_u->arrive_time = tail->arrive_time;
		o_current_m->total_time = tail->total_time;
		o_current_u->total_time = tail->total_time;
	}
}

// Synchronization order statement
void Synchronization_o_s_for_u(order* current, Merchant* m_head, DeliveryPerson* d_head)
{
	Merchant* m_current = find_m(m_head, current->m_name);
	DeliveryPerson* d_current = find_d(d_head, current->d_name);
	order* o_current_d = search_order_id(d_current->t_o_head, current->order_id);
	order* o_current_m = search_order_id(m_current->t_o_head, current->order_id);
	o_current_m->s = current->s;
	o_current_d->s = current->s;
	printf("order has canceled\n");
}

// Synchronization order delivery person
void Synchronization_o_d_for_m(order* current, DeliveryPerson* d_head, User* u_head)
{
	DeliveryPerson* d_current = find_d(d_head, current->d_name);
	User* u_current = find_u(u_head, current->u_name);
	order* o_current_u = search_order_id(u_current->t_o_head, current->order_id);
	order* o_current_d = d_current->o_tail;
	strcpy(o_current_d->d_name, d_current->name);
	strcpy(o_current_d->d_phone, d_current->phone);
	strcpy(o_current_u->d_name, d_current->name);
	strcpy(o_current_u->d_phone, d_current->phone);
	
}

// Synchronization order delivery person
void Synchronization_o_d_for_u(order* current, DeliveryPerson* d_head, Merchant* m_head)
{
	DeliveryPerson* d_current = find_d(d_head, current->d_name);
	Merchant* m_current = find_m(m_head, current->m_name);
	order* o_current_m = search_order_id(m_current->t_o_head, current->order_id);
	order* o_current_d = d_current->o_tail;
	strcpy(o_current_d->d_name, d_current->name);
	strcpy(o_current_d->d_phone, d_current->phone);
	strcpy(o_current_m->d_name, d_current->name);
	strcpy(o_current_m->d_phone, d_current->phone);

}