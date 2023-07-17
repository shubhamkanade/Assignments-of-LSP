#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char* argv[])
{   
    int fd1 = 0, fd2 = 0, ret = 0;
    char buffer[50] = {'\0'}, buffer1[50] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);

    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
        printf("File is successfully opened %s\n", argv[1]);

    ret = read(fd1,buffer,sizeof(buffer));

    if(ret == 0)
    {
        printf("Unable to read data\n");
        return -1;
    }

    fd2 = open(argv[2], O_WRONLY);

    if(fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
     printf("File is successfully opened %s\n", argv[2]);

    write(fd2,buffer,ret);

    return 0;
}