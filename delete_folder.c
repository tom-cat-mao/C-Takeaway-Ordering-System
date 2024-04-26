#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include "delete_folder.h"

bool delete_m_u_d_folder ()
{
    if (!RemoveDir("Merchant_List"))
    {
        perror("Unable to delete Merchant_List folder");
        return false;
    }
    if (!RemoveDir("User_List"))
    {
        perror("Unable to delete User_List folder");
        return false;
    }
    if (!RemoveDir("Delivery_person_List"))
    {
        perror("Unable to delete Deliveryperson_List folder");
        return false;
    }
}

bool RemoveDir(const char* path)
{
    WIN32_FIND_DATA ffd;
    char tmpPath[MAX_PATH];

//    make a copy of the path
    sprintf(tmpPath, "%s\\*", path);

    HANDLE hFind = FindFirstFile(tmpPath, &ffd);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Failed to find files in %s\n", path);
        return 0;
    }

    do
    {
        if (strcmp(ffd.cFileName, ".") != 0 && strcmp(ffd.cFileName, "..") != 0) {
            sprintf(tmpPath, "%s\\%s", path, ffd.cFileName);

//            if the file is a directory, call RemoveDir recursively
            if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                RemoveDir(tmpPath);
                RemoveDirectory(tmpPath);
            }
            else
            {
//                else delete the file
                DeleteFile(tmpPath);
            }
        }
    } while (FindNextFile(hFind, &ffd) != 0);

    FindClose(hFind);
    return 1;
}