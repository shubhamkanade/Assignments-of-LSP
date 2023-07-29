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
    int fd = 0, ret = 0;
    char buffer[20] = {'\0'};

    if(argc != 3)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    ret = read(fd,buffer,sizeof(buffer));

    printf("Data from file\n");
    write(1,buffer,ret);
    
    return 0;
}
