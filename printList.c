#define _CRT_SECURE_NO_WARNINGS
#include"class.h"

//��ӡ�˵��еĲ�Ʒ
void printList_recipe_1(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\n", head->name, head->price);
        head = head->next;
    }
}

//��ӡ�����в�Ʒ
void printList_recipe_2(recipe* head)
{
    printf("Recipe List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tPrice: %.2f\tQuantity: %d\n", head->name, head->price, head->num);
        head = head->next;
    }
}

//��ӡ��Ʒ����
void printList_r_classify(r_classify* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("%s\n", head->name);
        if (head->r_head == NULL)
        {
            printf("�ò�Ʒ�໹δ���Ӳ�Ʒ\n");
        }
        else
        {
            printList_recipe_1(head->r_head);
        }
        head = head->next;
    }
}

// ��ӡ����
void print_order_list(order* head)
{
    printf("Order List:\n");
    while (head != NULL)
    {
        printf("%d-%02d-%02d %02d:%02d:%02d\n", head->localTime->tm_year + 1900, head->localTime->tm_mon + 1, head->localTime->tm_mday,
            head->localTime->tm_hour, head->localTime->tm_min, head->localTime->tm_sec);
        printf("Order ID: %s\n", head->order_id);
        printf("Merchant: %s\tAddress: %s\tPhone: %s\n", head->m_name, head->m_address, head->m_phone);
        printf("User: %s\tAddress: %s\tPhone: %s\n", head->u_name, head->u_address, head->u_phone);
        printf("Delivery Person: %s\tPhone: %s\n", head->d_name, head->d_phone);
        printList_recipe_2(head->r_head); // ��ӡ�����еĲ�Ʒ�б�
        printf("Total Price: %.2f\n", head->sum_price);
        switch (head->s){
        case WAY:
            printf("Order State: Waiting\n");
            break;
        case DILLVERING:
            printf("Order State: Delivering\n");
            break;
        case FINISH:
            printf("Order State: Finished\n");
            break;
        default:
            printf("Order State: Unknown\n");
            break;
        }
        head = head->next;
    }
}

//��ӡ�̼��б�
void printList_merchant(Merchant* head)
{
    printf("Class List:\n");
    while (head != NULL)
    {
        printf("Name: %s\tAddress: %s\n", head->name, head->address);
        head = head->next;
    }
}