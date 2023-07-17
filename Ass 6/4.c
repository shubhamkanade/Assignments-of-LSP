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
    struct stat obj;
    int fd = 0;

    if(argc != 2)
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
        sprintf(filename, "%s/%s",argv[1], entry -> d_name);
        stat(filename, &obj);
        if(S_ISREG(obj.st_mode))
            if(obj.st_size > 100)
                remove(filename);
       
    }
    

    closedir(dp);
    return 0;
}