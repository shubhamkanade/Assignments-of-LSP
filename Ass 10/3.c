// write a program which creates single thread and we have to pass parameter to thar thread from main thread

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    printf("Vaule from main thread is %d\n",(int)ptr);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int No = 21;

    ret = pthread_create(&TID, NULL, ThreadProc, (int *)No);

    if(ret != 0)
    {
        printf("Unabel to create thread \n");
        return -1;
    }

    printf("Thread is created with ID : %d\n",TID);
    pthread_join(TID,NULL);
    printf("End of main thread\n");

    return 0;
}