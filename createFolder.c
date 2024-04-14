#define _CRT_SECURE_NO_WARNINGS
#include <sys/stat.h>
#include "class.h"

bool CreateFolder(char* fn, User* head)
{
    FILE* fp;

    // If the folder does not exist, create the folder
    if (_access(fn, 0) == -1)
    {
        _mkdir(fn);// Create a folder
    }

    char path1[] = { "C:\\Users\\sunqf\\Desktop\\file\\file\\" };// the path of the folder 
    char path2[100] = { '\0' };
    sprintf(path2, "%s%s%s", path1, fn, "\\");// create the path of the folder

    // write user into the file
    User* currentUser = head;
    while (currentUser != NULL)
    {
        char path3[100] = { '\0' };
        sprintf(path3, "%s%s%s", path2, currentUser->name, ".txt");//create the path of the file
        fp = fopen(path3, "a+");


        if (fp == NULL)
        {
            printf("Error opening file!\n");
            return false;
        }

        // write in the details of the user
        fprintf(fp, "details:\n");
        fprintf(fp, "%s\n", currentUser->name);
        fprintf(fp, "%s\n", currentUser->address);
        fprintf(fp, "%s\n", currentUser->phone);
        fprintf(fp, "%d\n", currentUser->c);

        //write in the order of the user
        order* currentOrder = currentUser->head;
        while (currentOrder != NULL)
        {
            int i = 0;
            i++;
            fprintf(fp, "order_%d\n", i);
            //fprintf(fp," %lld\n", mktime(currentOrder->localTime));
            fprintf(fp, "%s\n", currentOrder->order_id);
            /*fprintf(fp, " %s\t%s\t%s\n", currentOrder->m_name, currentOrder->m_address, currentOrder->m_phone);
            fprintf(fp," %s\t%s\t%s\n", currentOrder->u_name, currentOrder->u_address, currentOrder->u_phone);
            fprintf(fp," %s\t%s\n", currentOrder->d_name, currentOrder->d_phone);*/
            fprintf(fp, "%f\n", currentOrder->sum_price);

            //write in the recipe of the order
            struct recipe* currentRecipe = currentOrder->r_head;
            while (currentRecipe != NULL)
            {
                int j = 0;
                j++;
                fprintf(fp, "recipe_%d\n", j);
                fprintf(fp, "%s\t%f\t%d\n", currentRecipe->name, currentRecipe->price, currentRecipe->num);
                currentRecipe = currentRecipe->next;
            }
            currentOrder = currentOrder->next;
        }
        currentUser = currentUser->next;
    }

    fclose(fp);
}
