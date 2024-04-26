#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include "delete_folder.h"

bool delete_m_u_d_folder ()
{
    if (!delete_folder("Merchant_List"))
    {
        perror("Unable to delete Merchant_List folder");
        return false;
    }
    if (!delete_folder("User_List"))
    {
        perror("Unable to delete User_List folder");
        return false;
    }
    if (!delete_folder("Deliveryperson_List"))
    {
        perror("Unable to delete Deliveryperson_List folder");
        return false;
    }
}

bool delete_folder(const char *folderPath)
{
//    make sure the folderPath is not NULL
    char path[MAX_PATH];
    snprintf(path, sizeof(path), "%s\\*", folderPath);

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(path, &findFileData);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            //ignore the "." and ".." folder
            if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
                snprintf(path, sizeof(path), "%s\\%s", folderPath, findFileData.cFileName);
                if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    //reserve to delete the sub folder
                    delete_folder(path);
                }
                else
                {
                    //delete the file
                    if (!DeleteFile(path))
                    {
                        printf("Unable to delete file: %s\n", path);
                        fflush(stdout);
                    }
                    else
                    {
                        printf("Deleted file: %s\n", path);
                    }
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

//        close the handle
        FindClose(hFind);
    }

    //delete the folder
    if (!RemoveDirectory(folderPath))
    {
        printf("Unable to delete directory: %s\n", folderPath);
    }
    else
    {
        printf("Deleted directory: %s\n", folderPath);
    }
}