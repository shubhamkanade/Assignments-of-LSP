// Write a program which is used to yield the processor by by using appropriate system call

#include<stdio.h>
#include<stdlib.h>
#include<sched.h>

int main()
{
    int ret = 0;

    ret =  sched_yield();

 




    return 0;
}