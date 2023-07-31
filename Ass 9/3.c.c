// write a program which is used to print the priority of process

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0;

    ret = fork();

    ret = getpriority(PRIO_PROCESS,0);

    printf("Priority of process is %d\n",ret);




    return 0;
}