#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char* argv[])
{   
     
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    int ret = 0;

    if(argc != 2)
    {
        printf("invalid arguments\n");
        return 0;
    }

    ret = mkdir(argv[1],0777);

    if(ret == 0)
    {
        printf("Unable to create directory");
        return -1;
    }
    else
        printf("Directory %s is created successfully\n", argv[1]);

    return 0;
}