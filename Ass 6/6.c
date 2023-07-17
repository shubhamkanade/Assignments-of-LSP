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
    char random_garbage[1024];
    struct stat obj;
    char name[30];
    int fd = 0;
    int ret = 0;
     DIR *dp = NULL;
    struct direct *entry = NULL;

    if(argc != 2)
    {
        printf("Unable to open file\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

     while((entry = readdir(dp)) != NULL)
    {
       sprintf(name,"%s/%s",argv[1],entry -> d_name);   
       stat(name, &obj);
       fd = open(name, O_WRONLY);
       if(S_ISREG(obj.st_mode))
       {
            if(obj.st_size > 1024)
            {
            ret = lseek(fd,1024,0);
            truncate(name,ret);
            }
            else
            {   
                printf("In else");
                  lseek(fd, 1 * 1024, 0);
                  write(fd, random_garbage, 1024);
            }

       }
    }
   

	
   
    return 0;
}