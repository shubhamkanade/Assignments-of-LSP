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
    DIR *dp = NULL;
    struct direct *entry = NULL;
    int fd = 0, fd1 = 0, ret = 0;
    char buffer[10] = {'\0'}, name[10] = {'\0'};

    dp = opendir(argv[1]);

    if(argc != 2)
    {
        printf("Unable to open file\n");
        return -1;
    }

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    
    fd1 = open(argv[2], O_WRONLY);

    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
       sprintf(name,"%s/%s",argv[1],entry -> d_name);
       fd = open(name, O_RDONLY);
       ret = read(fd,buffer,sizeof(buffer));
       write(fd1,buffer,ret);
       close(fd);
    }

    closedir(dp);

    if(entry == NULL)
        printf("Data written successfully\n");

    return 0;
}