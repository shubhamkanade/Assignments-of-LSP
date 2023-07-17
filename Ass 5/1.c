#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

#pragma pack(1)

struct Student
{
    int rno;
    char name[30];
    int age;
    float marks;
};


int main(int argc, char *argv[])
{
    int fd = 0;
    struct Student sobj;
    
    sobj.rno = 10;
    sobj.age = 20;
    sobj.marks = 3.4f;
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

    return 0;
}