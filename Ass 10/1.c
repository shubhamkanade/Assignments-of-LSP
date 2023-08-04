// Write a program which is used to create simple thread by using pthread library

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    printf("Inside thread \n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    else
    {
        printf("Thread is created with ID :  %d\n",TID);
    }

    return 0;
}