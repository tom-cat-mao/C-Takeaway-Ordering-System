#define _CRT_SECURE_NO_WARNINGS
#include"class.h"
//to find a special r_classify in onre Merchant
struct r_classify* find_r_classify(struct Merchant* merchant, const char* classify_name)
{
    struct r_classify* current_r_classify = merchant->r_head;

    while (current_r_classify != NULL)
    {
        if (strcmp(current_r_classify->name, classify_name) == 0)
        {
            return current_r_classify;
        }
        current_r_classify = current_r_classify->next;
    }
    //while nothing found
    return NULL;
}