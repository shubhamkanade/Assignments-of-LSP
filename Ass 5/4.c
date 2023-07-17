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
    int fd = 0, fd1 = 0, fd2 = 0;
    char filename[30];
    int size = 0;

    char header[30];

    if (argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    // fd = creat("AllCombine.txt",0777);

    fd = creat("AllCombine.txt", 0777);
    if (fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);
        if (S_ISREG(sobj.st_mode))
        {
            fd1 = open(name, O_RDONLY);

            sprintf(header,"%s %ld\n",entry -> d_name, sobj.st_size);
            //sscanf(header,"%s %d",filename,&size);
            // printf("file name %s\n",filename);
            // printf("file size %d\n", size);
            while ((ret = read(fd1, buffer, sizeof(buffer))) != 0)
            {
                write(fd,header,strlen(header));
                write(fd, buffer, ret);
                memset(buffer, 0, sizeof(buffer));
            }
            write(fd,"\n",1);
        }
        close(fd1);
    }

    closedir(dp);

    return 0;
}