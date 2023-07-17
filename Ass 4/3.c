#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat obj1, obj2;
    char buffer1[BLOCKSIZE], buffer2[BLOCKSIZE];

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1, &obj1);
    fstat(fd2, &obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different in size\n");
        return -1;
    }

    while((ret = read(fd1,buffer1,sizeof(buffer1))) != 0)
    {
        ret = read(fd2,buffer2,sizeof(buffer2));

        if(memcmp(buffer1, buffer2, ret) < 0)
            break;
    }

    if(ret == 0)
    printf("Files are identical\n");
    else
    printf("Files are different\n");
    
    return 0;
}