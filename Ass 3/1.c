#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0, fdDest = 0, ret = 0;

    char buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return 0;
    }

    fdSource = open(argv[1], O_RDONLY);

    if(fdSource == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fdDest = creat(argv[2], 0777);

    if(fdDest == -1)
    {
        printf("Unable to create file");
        return -1;
    }

    while((ret = read(fdSource,buffer,sizeof(buffer))) != 0)
    {
        write(fdDest,buffer,ret);
    }
    close(fdSource);
    close(fdDest);
    return 0;
}