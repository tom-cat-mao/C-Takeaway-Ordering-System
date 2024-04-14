#include "folder_create_change_delete.h"

// write the merchant list to the merchant list folder
bool write_t_merchant_list(Merchant* head) 
{
    // switch to the merchant list folder
    chdir("Merchant List");

    // write merchant data to different files
    for (Merchant* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->address);
        fprintf(file, "%s\n", current->phone);
        // print order list
        if (!write_t_order_list(current->o_head))
        {
            printf("Failed to write the order list.\n");
            return 0;
        }

        // print r_classify and recipe list
        if (!write_t_r_class_list(current->r_head))
        {
            printf("Failed to write the recipe classify list.\n");
            return 0;
        }

        fclose(file);
    }


    chdir("..");
    return 1;
}

// write the user list to the user list folder
bool write_t_user_list(User* head) 
{
    // switch to the user list folder
    chdir("User List");

    // write User data to different files
    for (User* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->address);
        fprintf(file, "%s\n", current->phone);
        fprintf(file, "%s\n", current->c);

        // print order list
        if (!write_t_order_list(current->head))
        {
            printf("Failed to write the order list.\n");
            return 0;
        }

        fclose(file);
    }


    chdir("..");
    return 1;
}

// write the deliveryman list to the deliveryman list folder
bool write_t_deliveryperson_list(DeliveryPerson* head) 
{
    // switch to the deliveryperson list folder
    chdir("Deliveryperson List");

    // write deliveryman data to different files
    for (DeliveryPerson* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->phone);
        fprintf(file, "%s\n", current->s);
        
        // print order list
        if (!write_t_order_list(current->o_head))
        {
            printf("Failed to write the order list.\n");
            return 0;
        }

        fclose(file);
    }


    chdir("..");
    return 1;
}

// write the order list to the order list folder
bool write_t_order_list(order* head) 
{
    // switch to the order list folder
    chdir("Order List");

    // write order data to different files
    for (order* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->order_id, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->order_id);
        fprintf(file, "%s\n", current->localTime);
        fprintf(file, "%s\n", current->send_time);
        fprintf(file, "%s\n", current->arrive_time);
        fprintf(file, "%s\n", current->m_address);
        fprintf(file, "%s\n", current->m_phone);
        fprintf(file, "%s\n", current->d_name);
        fprintf(file, "%s\n", current->d_phone);
        fprintf(file, "%s\n", current->u_name);
        fprintf(file, "%s\n", current->u_address);
        fprintf(file, "%s\n", current->u_phone);
        fprintf(file, "%s\n", current->s);
        fprintf(file, "%s\n", current->sum_price);

        // print recipe classify list
        if (!write_t_r_class_list(current->r_head))
        {
            printf("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);
    }

    chdir("..");
    return 1;
}

// write the recipe class list to the recipe class list folder
bool write_t_r_class_list(r_classify* head) 
{
    // switch to the recipe classify list folder
    chdir("Recipe classify List");

    // write recipe classify data to different files
    for (r_classify* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);

        // print recipe list
        if (!write_t_recipe_list(current->r_head))
        {
            printf("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);
    }

    chdir("..");
    return 1;
}

// write the recipe list to the recipe list folder
bool write_t_recipe_list(recipe* head) 
{
    // switch to the recipe  list folder
    chdir("Recipe List");

    // write recipe data to different files
    for (recipe* current = head; current != NULL; current = current->next)
    {
        FILE* file = fopen(current->name, "w");
        if (file == NULL) 
        {
            printf("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->name);
        fprintf(file, "%s\n", current->price);
        fprintf(file, "%s\n", current->num);
        fprintf(file, "%s\n", current->sale_discount);

        fclose(file);
    }

    chdir("..");
    return 1;
}


bool read_merchant_list(Merchant* head, Merchant* current)
{
    // switch to the merchant list folder
    chdir("Merchant List");
    DIR *dir;
    struct dirent *entry;
    FILE *file;
    char file_path[260];

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
        Merchant* newNode = (Merchant*)malloc(sizeof(Merchant));
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

        fscanf(file, "%s\n%s\n%s", name, address, phone);
        
        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        strcpy(newNode->phone, phone);

        // read_order_list(newNode->o_head, newNode->o_tail);
        // read_r_class_list(newNode->r_head, newNode->r_tail);
        
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }

    // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    chdir("..");
    return 1;
}

bool read_user_list(User* head, User* current)
{
    // switch to the user list folder
    chdir("User List");
    DIR *dir;
    struct dirent *entry;
    FILE *file;
    char file_path[260];

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
        User* newNode = (User*)malloc(sizeof(User));
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

        fscanf(file, "%s\n%s\n%s", name, address, phone);
        
        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        strcpy(newNode->phone, phone);
        strcpy(newNode->c, c);

        // read_order_list(newNode->o_head, newNode->o_tail);
        
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }

    // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    chdir("..");
    return 1;
}

bool read_deliveryperson_list(User* head, User* current)
{
    // switch to the user list folder
    chdir("User List");
    DIR *dir;
    struct dirent *entry;
    FILE *file;
    char file_path[260];

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
        User* newNode = (User*)malloc(sizeof(User));
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

        fscanf(file, "%s\n%s\n%s", name, address, phone);
        
        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        strcpy(newNode->phone, phone);
        strcpy(newNode->c, c);

        // read_order_list(newNode->o_head, newNode->o_tail);
        
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }

    // close file
        fclose(file);
    }

    // close directory
    closedir(dir);


    chdir("..");
    return 1;
}
