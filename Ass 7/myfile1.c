#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include "sharedfile.h"
#define BLOCKSIZE 1024

void CompareFiles(char file1[30], char file2[30])
{
     int fd1 = 0, fd2 = 0, ret = 0;
    struct stat obj1, obj2;
    char buffer1[BLOCKSIZE], buffer2[BLOCKSIZE];

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return;
    }

    fstat(fd1, &obj1);
    fstat(fd2, &obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different in size\n");
        return;
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
}