#define _CRT_SECURE_NO_WARNINGS
#include "class.h"

//创建订单菜品列表
recipe* creatList_recipe_1(char* n, float p, int num)
{
    recipe* newNode = (recipe*)malloc(sizeof(recipe));   //申请新节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->price = p;
    newNode->num = num;
    newNode->next = NULL;

    return newNode;
}

//创建菜单里的菜品列表
recipe* creatList_recipe_2(char* n, float p)
{
    recipe* newNode = (recipe*)malloc(sizeof(recipe));   //申请新节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    newNode->price = p;
    newNode->next = NULL;

    return newNode;
}

//创建菜类列表
r_classify* creatList_r_classify(char* n)
{
    r_classify* newNode = (r_classify*)malloc(sizeof(r_classify));//申请节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return;
    }

    strcpy(newNode->name, n);
    newNode->r_head = NULL;

    //是否添加菜品
    printf("Add recipes or not (Y/N):\t");
    char flag = getchar();//获取输入
    getchar();

    flag = upper(flag);//转换为大写
    //添加菜品
    if (flag == 'Y')
    {
        int i;
        for (i = 1;; i++)
        {
            char name[100];
            float price;
            printf("\nPlease enter the name of the recipe(q to quit):\t");
            scanf("%s", name);
            if (name[0] == 'q')
            {
                break;
            }

            // enter the price of the recipe
            printf("\nPlease enter the price of the recipe:\t");
            scanf("%f", price);
            printf("\n");
            newNode->r_head = creatList_recipe_2(name, price);
        }
        newNode->total_number = i;
    }
    else
    {
        newNode->total_number = 0;
        free(newNode);
        newNode = NULL;
        return NULL;
    }

    newNode->next = NULL;

    return newNode;
}

//创建订单列表
order* creatList_order(char* merchant_name, char* merchant_address, char* merchant_phone,
    char* deliver_name, char* deliver_phone, char* user_name, char* user_adderss, char* user_phone)
{
    order* newNode = (order*)malloc(sizeof(order));//申请节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    // initit order information
    strcpy(newNode->m_name, merchant_name);
    strcpy(newNode->m_address, merchant_address);
    strcpy(newNode->m_phone, merchant_phone);
    strcpy(newNode->u_name, user_name);
    strcpy(newNode->u_address, user_adderss);
    strcpy(newNode->u_phone, user_phone);
    strcpy(newNode->d_name, deliver_name);
    strcpy(newNode->d_phone, deliver_phone);
    set_time(newNode->localTime);
    strftime(newNode->order_id, sizeof(newNode->order_id), "%Y%m%d %H%M%S", newNode->localTime);
    for (int i = 7, j = strlen(newNode->order_id); i < 11; i++,j++)
    {
        
        newNode->order_id[j] = newNode->u_phone[i];
        
    }
    newNode->next = NULL;

    return newNode;
}

//创建商家链表
Merchant* creatList_merchant(char* n, char* p, char* a, char* pn)
{
    Merchant* newNode = (Merchant*)malloc(sizeof(Merchant));//申请节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    return newNode;
}

//创建用户链表
User* creatList_user(char* n, char* p, char* a, char* pn)
{
    User* newNode = (User*)malloc(sizeof(User));//申请节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->address, a);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    return newNode;
}

//创建外卖员列表
DeliveryPerson* creatList_deliveryperson(char* n, char* p, char* pn)
{
    DeliveryPerson* newNode = (DeliveryPerson*)malloc(sizeof(DeliveryPerson));//申请节点空间

    //检查节点是否申请成功
    if (!newNode)
    {
        return NULL;
    }

    strcpy(newNode->name, n);
    strcpy(newNode->password, p);
    strcpy(newNode->phone, pn);
    newNode->next = NULL;

    return newNode;
}
