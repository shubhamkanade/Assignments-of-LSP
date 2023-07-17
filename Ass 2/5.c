#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    int max = 0;
    char filename[20] = {'\0'};
    char buffer[20] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
   
    printf("Entries from the directory file are : \n");
   
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(buffer,"%s/%s",argv[1],entry -> d_name);
        stat(buffer, &sobj);

        //printf("File name is %s and File size is : %ld\n",buffer, sobj.st_size);
        if(sobj.st_size > max)
        {
            max = sobj.st_size;
            strcpy(filename,entry -> d_name);
        }

    
    }
        printf("Largest file is %s with size %d\n",filename, max);

    closedir(dp);
    return 0;
}

