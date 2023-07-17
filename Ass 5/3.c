#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    int fd = 0;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    struct FileInfo fobj;
    char namecopy[30] = {'\0'};

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("newfile.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            read(fd,&fobj,sizeof(fobj));
            printf("file name %s\n", fobj.FileName);
            printf("file size %d\n", fobj.FileSize);
        }
    }

    closedir(dp);
    
    return 0;
}