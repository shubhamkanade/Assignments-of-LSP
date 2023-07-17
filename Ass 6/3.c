#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    char filename[40] = {'\0'};
    int fd = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
   
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(filename, "%s/%s",argv[1], argv[2]);
        fd = creat(filename, 0777);
        if(fd != -1)
        {
            printf("File created successfully\n");
            break;
        }
    }
    

    closedir(dp);
    return 0;
}