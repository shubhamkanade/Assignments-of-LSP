#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int ret = 0;
    char buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((ret = read(fd,buffer,sizeof(buffer))) != 0)
    {
        write(1,buffer,ret);
    }
    
    close(fd);

    return 0;
}
