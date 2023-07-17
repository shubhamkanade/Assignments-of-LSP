
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct stat sobj;
    char buffer[20] = {'\0'};

    struct dirent *entry = NULL;

    if (argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("Entries from the directory file are : \n");

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(buffer,"%s/%s",argv[1],entry -> d_name);
        stat(buffer, &sobj);

        if (S_ISREG(sobj.st_mode))
         {
            printf("File name is %s and Its a regular file\n", entry -> d_name);
        }
        else if (S_ISDIR(sobj.st_mode))
        {
            printf("Directory name is %s Its a directory\n", entry -> d_name);
        }
        else if (S_ISLNK(sobj.st_mode))
        {
            printf("Its a symbolic link\n", entry -> d_name);
        }
        
    }

    closedir(dp);
    return 0;
}
