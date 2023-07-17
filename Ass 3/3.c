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
    char oldname[30] = {'\0'}, newname[30] = {'\0'};

    struct direct *entry = NULL;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname, "%s/%s",argv[1],entry -> d_name);
        sprintf(newname, "%s/%s",argv[2],entry -> d_name);

        rename(oldname, newname);
    }

    closedir(dp);

    return 0;
}
