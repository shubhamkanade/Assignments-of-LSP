#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>


int main(int argc, char *argv[])
{
    DIR *dp  = NULL;

    struct direct *entry = NULL;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to create directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(argv[2], entry -> d_name)) == 0)
        {
            printf("File is present\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("File is not present\n");
        return -1;
    }

    return 0;
}