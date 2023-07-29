#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "sharedfile6.h"

void DisplayFileInfo(char file[30])
{
   struct stat sobj;

    stat(file,&sobj);

    printf("File size is : %jd\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);
    printf("Mode of file : %d\n",sobj.st_mode);	
}
   