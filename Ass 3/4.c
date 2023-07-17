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
    DIR *dp = NULL;
    char name[30] = {'\0'};
    struct stat sfile;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to opn directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s",argv[1], entry -> d_name);
        stat(name, &sfile);

        if(sfile.st_size == 0)
        remove(name);

    }
    
    return 0;
}