#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

#pragma pack(1)

struct Employee
{
    int id;
    char name[30];
    int age;
};


int main(int argc, char *argv[])
{
    int fd = 0;
    struct Employee sobj;
    
    
    sobj.id = 10;
    sobj.age = 20;
    strcpy(sobj.name,"saurabh");

    
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }
    
    fd = creat(argv[1], 0777);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    write(fd,&sobj,sizeof(sobj));
    
    read(fd,&sobj,sizeof(sobj));

	printf("Id is : %d \n", sobj.id);
	printf("Name : %s \n", sobj.name);
	printf("Age : %d \n", sobj.age);

    return 0;
}