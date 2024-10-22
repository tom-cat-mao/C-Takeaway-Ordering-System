#define _CRT_SECURE_NO_WARNINGS
#include "folder_create_change_delete.h"
#include <errno.h>
#include <direct.h> // for _getcwd

void print_current_directory()
{
    char path[_MAX_PATH];
    if (_getcwd(path, sizeof(path)) != NULL) {
        printf("Current directory: %s\n", path);
    } else {
        perror("Error retrieving current directory");
    }
}

// write the merchant list to the merchant list folder
bool write_t_merchant_list(struct Merchant* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the merchant list folder
    if (_chdir(".\\Merchant_List") != 0)
    {
        if (_mkdir(".\\Merchant_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\Merchant_List");
    }

    // write merchant data to different files
    for (struct Merchant* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->name);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

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

        _chdir("..");
    }


    _chdir("..");

// switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }

    return 1;
}

// write the user list to the user list folder
bool write_t_user_list(struct User* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the user list folder
    if (_chdir(".\\User_List") != 0)
    {
        if (_mkdir(".\\User_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\User_List");
    }

    // write User data to different files
    for (struct User* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->name);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

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

        _chdir("..");
    }


    _chdir("..");

    // switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }
    return 1;
}

// write the deliveryman list to the deliveryman list folder
bool write_t_deliveryperson_list(struct DeliveryPerson* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the deliveryperson list folder
    if (_chdir(".\\Delivery_person_List") != 0)
    {
        if (_mkdir(".\\Delivery_person_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\Delivery_person_List");
    }

    // write deliveryman data to different files
    for (struct DeliveryPerson* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->name);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

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

        _chdir("..");
    }


    _chdir("..");

    // switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }

    return 1;
}

// write the order list to the order list folder
bool write_t_order_list(struct order* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the order list folder
    if (_chdir(".\\Order_List") != 0)
    {
        if (_mkdir(".\\Order_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\Order_List");
    }


    // write order data to different files
    for (struct order* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->order_id);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

        FILE* file = fopen(current->order_id, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%s\n", current->order_id);

        // write merchant, delivery person, customer names, addresses, phone numbers
        fprintf(file, "%d\n", current->send_time);
        fprintf(file, "%d\n", current->arrive_time);
        fprintf(file, "%d\n", current->total_time);

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
        if (!write_t_recipe_list(current->r_head))
        {
            perror("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);

        _chdir("..");
    }

    _chdir("..");

    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }
    return 1;
}

// write the recipe class list to the recipe class list folder
bool write_t_r_class_list(struct r_classify* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the recipe classify list folder
    if (_chdir(".\\Recipe_classify_List") != 0)
    {
        if (_mkdir(".\\Recipe_classify_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\Recipe_classify_List");
    }

    // write recipe classify data to different files
    for (struct r_classify* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->name);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

        FILE* file = fopen(current->name, "w");
        if (file == NULL)
        {
            perror("Failed to open the file.\n");
            return 0;
        }

        fprintf(file, "%d\n", current->total_number);
        fprintf(file, "%s\n", current->name);

        // print recipe list
        if (!write_t_recipe_list(current->r_head))
        {
            perror("Failed to write the recipe list.\n");
            return 0;
        }

        fclose(file);

        _chdir("..");
    }

    _chdir("..");
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }

    return 1;
}

// write the recipe list to the recipe list folder
bool write_t_recipe_list(struct recipe* head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }

    // switch to the recipe  list folder
    if (_chdir(".\\Recipe_List") != 0)
    {
        if (_mkdir(".\\Recipe_List") != 0)
        {
            perror("Failed to create the folder.\n");
            return 0;
        }
        _chdir(".\\Recipe_List");
    }

    // write recipe data to different files
    for (struct recipe* current = head; current != NULL; current = current->next)
    {
        char file_path[260];
        sprintf(file_path, "%s\\%s", ".", current->name);

        if (_chdir(file_path) != 0)
        {
            if (_mkdir(file_path) != 0)
            {
                perror("Failed to create the folder.\n");
                return 0;
            }
            _chdir(file_path);
        }

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

        _chdir("..");
    }

    _chdir("..");

    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }
    return 1;
}

// read all merchant list from the file to the memory
bool read_merchant_list(struct Merchant** head, struct Merchant** current, struct t_Merchant** t_head)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }
    
    // switch to the merchant list folder
    if ((_chdir(".\\Merchant_List") != 0))
    {
        perror("Failed to open directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        
        DIR* subdir;
        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if ((_chdir(filepath) != 0))
        {
            perror("Failed to open directory");
            return 0;
        }

        subdir = opendir(".");
        if (subdir == NULL)
        {
            perror("Failed to open directory");
            return 0;
        }

        FILE* file = NULL;
        char file_path[260];
        struct Merchant* newNode = (struct Merchant*)malloc(sizeof(struct Merchant));
        newNode->next = NULL;
        newNode->r_head = NULL;
        newNode->r_tail = NULL;
        newNode->o_head = NULL;
        newNode->o_tail = NULL;
        newNode->t_o_head = NULL;
        newNode->t_r_head = NULL;
        char name[100];
        char address[100];
        char phone[20];

        struct dirent* en;

        while ((en = readdir(subdir)) != NULL)
        {
            if (strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0)
            {
                continue;
            }
            
            if (en->d_type == DT_REG)
            {
                // splice path
                sprintf(file_path, "%s\\%s", ".", en->d_name);
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
                fclose(file);
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Order_List") == 0)
            {
                if (!read_order_list(&(newNode->o_head), &(newNode->o_tail),&(newNode->t_o_head)))
                {
                    perror("Failed to read the order list.\n");
                    return 0;
                }
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Recipe_classify_List") == 0)
            {
                if (!read_r_class_list(&(newNode->r_head), &(newNode->r_tail),&(newNode->t_r_head)))
                {
                    perror("Failed to read the recipe classify list.\n");
                    return 0;
                }
            }
        }
        
        // add new node to the list
        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
            (*current)->next = NULL;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        closedir(subdir);

        _chdir("..");

        insertTree_Merchant_name(t_head, *current);
    }

    // close directory
    closedir(dir);

    _chdir("..");

    // switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }

    return 1;
}

// read all user lists form the file to the memory
bool read_user_list(struct User** head, struct User** current)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }
    
    // switch to the user list folder
    if (_chdir(".\\User_List") != 0)
    {
        perror("Failed to open directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }   

        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if ((_chdir(filepath) != 0))
        {
            perror("Failed to open directory");
            return 0;
        }

        DIR* subdir;
        subdir = opendir(".");
        if (subdir == NULL)
        {
            perror("Failed to open directory");
            return 0;
        }
        
        FILE* file = NULL;
        char file_path[260];
        struct User* newNode = (struct User*)malloc(sizeof(struct User));
        char name[100];
        char address[100];
        char phone[20];
        int c;
        struct dirent* en;
        newNode->next = NULL;
        newNode->o_head = NULL;
        newNode->o_tail = NULL;
        newNode->t_o_head = NULL;
        newNode->prev = NULL;
        

        while ((en = readdir(subdir)) != NULL)
        {
            if (strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0)
            {
                continue;
            }
            
            if (en->d_type == DT_REG)
            {
                // splice path
                sprintf(file_path, "%s\\%s", ".", en->d_name);
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
                fclose(file);
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Order_List") == 0)
            {
                if (!read_order_list(&(newNode->o_head), &(newNode->o_tail),&(newNode->t_o_head)))
                {
                    perror("Failed to read the order list.\n");
                    return 0;
                }
            }
        }

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        closedir(subdir);

        _chdir("..");
    }
    // close directory
    closedir(dir);

    _chdir("..");


    // switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }
    
    return 1;
}

// read all deliveryman lists form the file to the memory
bool read_deliveryperson_list(struct DeliveryPerson** head, struct DeliveryPerson** current)
{
    char initial_dir[_MAX_PATH];
    if (_getcwd(initial_dir, sizeof(initial_dir)) == NULL)
    {
        perror("Failed to get the current directory.\n");
        return 0;
    }
    
    
    // switch to the deliveryman list folder
    if (_chdir(".\\Delivery_person_List") != 0)
    {
        perror("Failed to open the directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if (_chdir(filepath) != 0)
        {
            perror("Failed to open directory");
            return 0;
        }

        DIR* subdir;
        subdir = opendir(".");
        if (subdir == NULL)
        {
            perror("Failed to open directory");
            return 0;
        }
        
        FILE* file = NULL;
        char file_path[260];
        struct DeliveryPerson* newNode = (struct DeliveryPerson*)malloc(sizeof(struct DeliveryPerson));
        char name[100];
        char phone[20];
        int s;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->o_head = NULL;
        newNode->o_tail = NULL;
        newNode->t_o_head = NULL;

        struct dirent* en;
        
        while ((en = readdir(subdir)) != NULL)
        {
            if (strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0)
            {
                continue;
            }
            
            if (en->d_type == DT_REG)
            {
                // splice path
                sprintf(file_path, "%s\\%s", ".", en->d_name);
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
                fclose(file);
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Order_List") == 0)
            {
                if (!read_order_list(&(newNode->o_head), &(newNode->o_tail),&(newNode->t_o_head)))
                {
                    perror("Failed to read the order list.\n");
                    return 0;
                }
            }
        }

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
        closedir(subdir);

        _chdir("..");
    }

    // close directory
    closedir(dir);

    _chdir("..");
    return 1;

    // switch back to the initial directory
    if (_chdir(initial_dir) != 0)
    {
        perror("Failed to switch back to the initial directory.\n");
        return 0;
    }
}

// read all r_classify lists form the file to the memory
bool read_r_class_list(struct r_classify** head, struct r_classify** current, struct t_recipe** t_head)
{
    // switch to the r_classify list folder
    if (_chdir(".\\Recipe_classify_List") != 0 )
    {
        perror("Failed to open the directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if (_chdir(filepath) != 0)
        {
            perror("Failed to open directory");
            return 0;
        }

        DIR* subdir;
        subdir = opendir(".");
        if (subdir == NULL)
        {
            perror("Failed to open directory");
            return 0;
        }

        FILE* file = NULL;
        char file_path[260];
        struct r_classify* newNode = (struct r_classify*)malloc(sizeof(struct r_classify));
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->r_head = NULL;
        newNode->r_tail = NULL;
        newNode->t_r_head = NULL;
        char name[100];
        int total_num;

        struct dirent* en;

        while ((en = readdir(subdir)) != NULL)
        {
            if (strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0)
            {
                continue;
            }
            
            if (en->d_type == DT_REG)
            {
                // splice path
                sprintf(file_path, "%s\\%s", ".", en->d_name);
                // open file
                file = fopen(file_path, "r");
                if (file == NULL)
                {
                    perror("Failed to open file");
                    return 0;
                }

                fscanf(file, "%d\n", &total_num);
                fscanf(file, "%s", name);

                strcpy(newNode->name, name);
                newNode->total_number = total_num;
                fclose(file);
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Recipe_List") == 0)
            {
                if (!read_recipe_list(&(newNode->r_head), &(newNode->r_tail),t_head))
                {
                    perror("Failed to read the recipe list.\n");
                    return 0;
                }
            }
        }

        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = (*current);
            *current = (*current)->next;
            (*current)->next = NULL;
        }

        // close file
        closedir(subdir);

        _chdir("..");
    }

    // close directory
    closedir(dir);

    _chdir("..");
    return 1;
}

// read all recipe lists form the file to the memory
bool read_recipe_list(struct recipe** head, struct recipe** current, struct t_recipe** t_head)
{
    // switch to the recipe list folder
    if (_chdir(".\\Recipe_List") != 0 )
    {
        perror("Failed to open the directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if (_chdir(filepath) != 0)
        {
            perror("Failed to open directory");
            return 0;
        }

        FILE* file = NULL;
        char file_path[260];
        struct recipe* newNode = (struct recipe*)malloc(sizeof(struct recipe));
        newNode->next = NULL;
        newNode->prev = NULL;
        char name[100];
        float price;
        float sale_discount;
        int num;
        int star;

        // splice path
        sprintf(file_path, "%s\\%s", ".", entry->d_name);

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
        newNode->sale_discount = sale_discount;
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
        _chdir("..");

        insertTree_recipe_name(t_head, *current);
    }

    // close directory
    closedir(dir);

    _chdir("..");
    return 1;
}

// read all order lists form the file to the memory
bool read_order_list(struct order** head, struct order** current, struct t_order** t_head)
{
    // switch to the order list folder
    if (_chdir(".\\Order_List") != 0 )
    {
        perror("Failed to open the directory");
        return 0;
    }
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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        
        char filepath[260];
        sprintf(filepath, "%s\\%s", ".", entry->d_name);

        if (_chdir(filepath) != 0)
        {
            perror("Failed to open directory");
            return 0;
        }

        DIR* subdir;
        subdir = opendir(".");
        if (subdir == NULL)
        {
            perror("Failed to open directory");
            return 0;
        }
        
        FILE* file;
        char file_path[260];
        struct order* newNode = (struct order*)malloc(sizeof(struct order));
        newNode->next = NULL;
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->r_head = NULL;
        newNode->r_tail = NULL;
        newNode->t_r_head = NULL;
        char order_id[100];
        char m_name[100];
        char d_name[100];
        char u_name[100];
        char m_address[100];
        char u_address[100];
        char m_phone[20];
        char d_phone[20];
        char u_phone[20];
        int send_time;
        int arrive_time;
        int total_time;
        int s;
        float sum_price;

        struct dirent* en;

        while ((en = readdir(subdir)) != NULL)
        {
            if (strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0)
            {
                continue;
            }

            if (en->d_type == DT_REG)
            {

                // splice path
                sprintf(file_path, "%s\\%s", ".", en->d_name);

                // open file
                file = fopen(file_path, "r");
                if (file == NULL)
                {
                    perror("Failed to open file");
                    return 0;
                }

                fscanf(file, "%s\n", order_id);
                fscanf(file, "%d\n%d\n%d\n", &send_time, &arrive_time, &total_time);
                fscanf(file, "%s\n%s\n%s\n", m_name, m_address, m_phone);
                fscanf(file, "%s\n%s\n", d_name, d_phone);
                fscanf(file, "%s\n%s\n%s\n", u_name, u_address, u_phone);
                fscanf(file, "%d\n%f\n", &s, &sum_price);

                // initialize the new node
                strcpy(newNode->order_id, order_id);

                newNode->send_time = send_time;
                newNode->arrive_time = arrive_time;
                newNode->total_time = total_time;

                strcpy(newNode->m_name, m_name);
                strcpy(newNode->d_name, d_name);
                strcpy(newNode->u_name, u_name);

                strcpy(newNode->m_address, m_address);
                strcpy(newNode->u_address, u_address);

                strcpy(newNode->m_phone, m_phone);
                strcpy(newNode->d_phone, d_phone);
                strcpy(newNode->u_phone, u_phone);

                newNode->s = (enum state_o)s;
                newNode->sum_price = sum_price;
                fclose(file);
            }
            else if (en->d_type == DT_DIR && strcmp(en->d_name, "Recipe_List") == 0)
            {
                if (!read_recipe_list(&(newNode->r_head), &(newNode->r_tail),&(newNode->t_r_head)))
                {
                    perror("Failed to read the recipe list.\n");
                    return 0;
                }
            }
        }


        if (*head == NULL)
        {
            *head = newNode;
            *current = *head;
        }
        else
        {
            (*current)->next = newNode;
            newNode->prev = *current;
            *current = (*current)->next;
        }

        // close file
        closedir(subdir);

        _chdir("..");

        insertTree_order_id(t_head, *current);
    }

    // close directory
    closedir(dir);

    _chdir("..");

    return 1;
}
