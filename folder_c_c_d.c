#define _CRT_SECURE_NO_WARNINGS
#include "folder_create_change_delete.h"


// write the merchant list to the merchant list folder
bool write_t_merchant_list(struct Merchant* head)
{
    // switch to the merchant list folder
    if (_chdir("Merchant List") != 0)
    {
        if (_mkdir("Merchant List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("Merchant List");
    }

    // write merchant data to different files
    for (struct Merchant* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->address);
        fprintf(file, "%s\n", current->phone);
        // print order list
        if (!write_t_order_list(current->o_head))
        {
            perror("Failed to write the order list.\n");
            return 0;
        }

        // print r_classify and recipe list
        if (!write_t_r_class_list(current->r_head))
        {
            perror("Failed to write the recipe classify list.\n");
            return 0;
        }

        fclose(file);
    }


    _chdir("..");
    return 1;
}

// write the user list to the user list folder
bool write_t_user_list(struct User* head)
{
    // switch to the user list folder
    if (_chdir("User List") != 0)
    {
        if (_mkdir("User List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("User List");
    }

    // write User data to different files
    for (struct User* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->address);
        fprintf(file, "%s\n", current->phone);
        fprintf(file, "%d\n", current->c);

        // print order list
        if (!write_t_order_list(current->o_head))
        {
            perror("Failed to write the order list.\n");
            return 0;
        }

        fclose(file);
    }


    _chdir("..");
    return 1;
}

// write the deliveryman list to the deliveryman list folder
bool write_t_deliveryperson_list(struct DeliveryPerson* head)
{
    // switch to the deliveryperson list folder
    if (_chdir("Deliveryperson List") != 0)
    {
        if (_mkdir("Deliveryperson List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("Deliveryperson List");
    }

    // write deliveryman data to different files
    for (struct DeliveryPerson* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->phone);
        fprintf(file, "%d\n", current->s);

        // print order list
        if (!write_t_order_list(current->o_head))
        {
            perror("Failed to write the order list.\n");
            return 0;
        }

        fclose(file);
    }


    _chdir("..");
    return 1;
}

// write the order list to the order list folder
bool write_t_order_list(struct order* head)
{
    // switch to the order list folder
    if (_chdir("Order List") != 0)
    {
        if (_mkdir("Order List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("Order List");
    }

    // write order data to different files
    for (struct order* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->order_id, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->order_id);

        // write loacal time include year, month, day, hour, minute, second
        fprintf(file, "%d\n", current->localTime->tm_mon);
        fprintf(file, "%d\n", current->localTime->tm_mday);
        fprintf(file, "%d\n", current->localTime->tm_hour);
        fprintf(file, "%d\n", current->localTime->tm_min);
        fprintf(file, "%d\n", current->localTime->tm_sec);

        // write send time include year, month, day, hour, minute, second
        fprintf(file, "%d\n", current->send_time->tm_mon);
        fprintf(file, "%d\n", current->send_time->tm_mday);
        fprintf(file, "%d\n", current->send_time->tm_hour);
        fprintf(file, "%d\n", current->send_time->tm_min);
        fprintf(file, "%d\n", current->send_time->tm_sec);

        // write arrive time include year, month, day, hour, minute, second
        fprintf(file, "%d\n", current->arrive_time->tm_mon);
        fprintf(file, "%d\n", current->arrive_time->tm_mday);
        fprintf(file, "%d\n", current->arrive_time->tm_hour);
        fprintf(file, "%d\n", current->arrive_time->tm_min);
        fprintf(file, "%d\n", current->arrive_time->tm_sec);

        // write merchant, delivery person, customer names, addresses, phone numbers
        fprintf(file, "%s\n", current->m_name);
        fprintf(file, "%s\n", current->m_address);
        fprintf(file, "%s\n", current->m_phone);


        fprintf(file, "%s\n", current->d_name);
        fprintf(file, "%s\n", current->d_phone);


        fprintf(file, "%s\n", current->u_name);
        fprintf(file, "%s\n", current->u_address);
        fprintf(file, "%s\n", current->u_phone);


        fprintf(file, "%d\n", current->s);
        fprintf(file, "%f\n", current->sum_price);

        // print recipe list
        if (write_t_recipe_list(current->r_head))
        {
            perror("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);
    }

    _chdir("..");
    return 1;
}

// write the recipe class list to the recipe class list folder
bool write_t_r_class_list(struct r_classify* head)
{
    // switch to the recipe classify list folder
    if (_chdir("Recipe classify List") != 0)
    {
        if (_mkdir("Recipe classify List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("Recipe classify List");
    }

    // write recipe classify data to different files
    for (struct r_classify* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);

        // print recipe list
        if (!write_t_recipe_list(current->r_head))
        {
            perror("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);
    }

    _chdir("..");
    return 1;
}

// write the recipe list to the recipe list folder
bool write_t_recipe_list(struct recipe* head)
{
    // switch to the recipe  list folder
    if (_chdir("Recipe List") != 0)
    {
        if (_mkdir("Recipe List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir("Recipe List");
    }

    // write recipe data to different files
    for (struct recipe* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%f\n", current->price);
        fprintf(file, "%d\n", current->num);
        fprintf(file, "%f\n", current->sale_discount);
        fprintf(file, "%d\n", current->star);

        fclose(file);
    }

    _chdir("..");
    return 1;
}

// read all merchant list from the file to the memory
bool read_merchant_list(struct Merchant** head, struct Merchant** current)
{
    // switch to the merchant list folder
    _chdir("Merchant List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct Merchant* newNode = (struct Merchant*)malloc(sizeof(struct Merchant));
        char name[100];
        char address[100];
        char phone[20];
        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s\n%s\n%s\n", name, address, phone);

        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        strcpy(newNode->phone, phone);

        if (!read_order_list(&(newNode->o_head), &(newNode->o_tail)))
        {
            perror("Failed to read the order list.\n");
            return 0;
        }

        if (!read_r_class_list(&(newNode->r_head), &(newNode->r_tail)))
        {
            perror("Failed to read the recipe classify list.\n");
            return 0;
        }

        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    _chdir("..");
    return 1;
}

// read all user lists form the file to the memory
bool read_user_list(struct User** head, struct User** current)
{
    // switch to the user list folder
    _chdir("User List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct User* newNode = (struct User*)malloc(sizeof(struct User));
        char name[100];
        char address[100];
        char phone[20];
        int c;
        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s\n%s\n%s\n%d\n", name, address, phone, &c);

        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        strcpy(newNode->phone, phone);
        newNode->c = (enum card)c;

        if (!read_order_list(&(newNode->o_head), NULL))
        {
            perror("Failed to read the order list.\n");
            return 0;
        }

        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    _chdir("..");
    return 1;
}

// read all deliveryman lists form the file to the memory
bool read_deliveryperson_list(struct DeliveryPerson** head, struct DeliveryPerson** current)
{
    // switch to the deliveryman list folder
    _chdir("Deliveryperson List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct DeliveryPerson* newNode = (struct DeliveryPerson*)malloc(sizeof(struct DeliveryPerson));
        char name[100];
        char phone[20];
        int s;
        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s\n%s\n%d\n", name, phone, &s);

        strcpy(newNode->name, name);
        strcpy(newNode->phone, phone);
        newNode->s = (enum state_d)s;

        if (!read_order_list(&(newNode->o_head), NULL))
        {
            perror("Failed to read the order list.\n");
            return 0;
        }

        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    _chdir("..");
    return 1;
}

// read all r_classify lists form the file to the memory
bool read_r_class_list(struct r_classify** head, struct r_classify** current)
{
    // switch to the r_classify list folder
    _chdir("Recipe classify List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct r_classify* newNode = (struct r_classify*)malloc(sizeof(struct r_classify));
        char name[100];

        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s", name);

        strcpy(newNode->name, name);

        if (!read_recipe_list(&(newNode->r_head), &(newNode->r_tail)))
        {
            perror("Failed to read the recipe list.\n");
            return 0;
        }

        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = (*current);
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);

    _chdir("..");
    return 1;
}

// read all recipe lists form the file to the memory
bool read_recipe_list(struct recipe** head, struct recipe** current)
{
    // switch to the recipe list folder
    _chdir("Recipe List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct recipe* newNode = (struct recipe*)malloc(sizeof(struct recipe));
        char name[100];
        float price;
        float sale_discount;
        int num;
        int star;

        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s\n%f\n%d\n%f\n%d", name, &price, &num, &sale_discount, &star);

        // initialize the new node
        strcpy(newNode->name, name);
        newNode->price = price;
        newNode->num = num;
        sale_discount = newNode->sale_discount;
        newNode->star = star;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = (*current);
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);

    _chdir("..");
    return 1;
}

// read all order lists form the file to the memory
bool read_order_list(struct order** head, struct order** current)
{
    // switch to the order list folder
    _chdir("Order List");
    DIR* dir;
    struct dirent* entry;

    // open current directory
    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Failed to open directory");
        return 0;
    }

    // view all files in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        FILE* file;
        char file_path[260];
        struct order* newNode = (struct order*)malloc(sizeof(struct order));
        char order_id[100];
        char m_name[100];
        char d_name[100];
        char u_name[100];
        char m_address[100];
        char u_address[100];
        char m_phone[20];
        char d_phone[20];
        char u_phone[20];
        int s;
        float sum_price;
        struct tm* _localTime;
        struct tm* arrive_time;
        struct tm* send_time;
        int l_mday, l_month, l_hour, l_min, l_sec;
        int a_mday, a_month, a_hour, a_min, a_sec;
        int s_mday, s_month, s_hour, s_min, s_sec;

        // splice path
        sprintf(file_path, "%s/%s", ".", entry->d_name);

        // open file
        file = fopen(file_path, "r");
        if (file == NULL)
        {
            perror("Failed to open file");
            return 0;
        }

        fscanf(file, "%s\n", order_id);
        fscanf(file, "%d\n%d\n%d\n%d\n%d\n", &l_month, &l_mday, &l_hour, &l_min, &l_sec);
        fscanf(file, "%d\n%d\n%d\n%d\n%d\n", &s_month, &s_mday, &s_hour, &s_min, &s_sec);
        fscanf(file, "%d\n%d\n%d\n%d\n%d\n", &a_month, &a_mday, &a_hour, &a_min, &a_sec);
        fscanf(file, "%s\n%s\n%s\n", m_name, m_address, m_phone);
        fscanf(file, "%s\n%s\n", d_name, d_phone);
        fscanf(file, "%s\n%s\n%s\n", u_name, u_address, u_phone);
        fscanf(file, "%d\n%f\n", &s, &sum_price);

        // initialize the new node
        strcpy(newNode->order_id, order_id);


        strcpy(newNode->m_name, m_name);
        strcpy(newNode->d_name, d_name);
        strcpy(newNode->u_name, u_name);

        strcpy(newNode->m_address, m_address);
        strcpy(newNode->u_address, u_address);

        strcpy(newNode->m_phone, m_phone);
        strcpy(newNode->d_phone, d_phone);
        strcpy(newNode->u_phone, u_phone);

        _localTime = (struct tm*)malloc(sizeof(struct tm));
        _localTime->tm_mday = l_mday;
        _localTime->tm_mon = l_month - 1;
        _localTime->tm_hour = l_hour;
        _localTime->tm_min = l_min;
        _localTime->tm_sec = l_sec;

        time_t t = mktime(_localTime);
        free(_localTime);

        _localTime = localtime(&t);


        arrive_time = (struct tm*)malloc(sizeof(struct tm));
        arrive_time->tm_mday = a_mday;
        arrive_time->tm_mon = a_month - 1;
        arrive_time->tm_hour = a_hour;
        arrive_time->tm_min = a_min;
        arrive_time->tm_sec = a_sec;

        t = mktime(arrive_time);
        free(arrive_time);

        arrive_time = localtime(&t);


        send_time = (struct tm*)malloc(sizeof(struct tm));

        send_time->tm_mday = s_mday;
        send_time->tm_mon = s_month - 1;
        send_time->tm_hour = s_hour;
        send_time->tm_min = s_min;
        send_time->tm_sec = s_sec;

        t = mktime(send_time);
        free(send_time);
        send_time = localtime(&t);


        newNode->s = (enum state_o)s;
        newNode->sum_price = sum_price;

        if (!read_recipe_list(&(newNode->r_head), &(newNode->r_tail)))
        {
            perror("Failed to read the recipe classify list.\n");
            return 0;
        }


        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            newNode->prev = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        fclose(file);
    }

    // close directory
    closedir(dir);

    _chdir("..");

    return 1;
}
