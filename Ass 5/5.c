#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK 1024

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    int ret = 0;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char buffer[BLOCK];
    char buffer1[BLOCK];
     char * line = NULL;
      char buf[100];
   
    int fd = 0, fd1 = 0, fd2 = 0;
    int read_bytes;
   
     char filename[30];
    int size = 0;
    int file_read=0;
    char header[30] = {'\0'};
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    // while ((ret = read(fd, buffer,sizeof(buffer))) != 0)
    // {
       
    //     break;
    // }
    while(1)
    {
    ret = read(fd,header,15);
    if(ret == 0)
    break;
    write(1,header,ret);

    sscanf(header,"%s %d",filename,&size);
    // printf("file name %s\n",filename);
    // printf("file size %d\n", size);

    fd1 = creat(filename,0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    ret = read(fd,buffer,size);

    write(fd1,buffer,ret);

    
    }

    // ret = read(fd,header,15);
    //  write(1,header,ret);
    //  sscanf(header,"%s %d",filename,&size);
    // fd2 = creat(filename,0777);

    // read(fd,buffer,size);

    // write(fd2,buffer,size);
    // close(fd1);

    return 0;
}