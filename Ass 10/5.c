// Write a program which is used to get thread id inside its thread function

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{

    printf("Vaule from main thread is %d\n",(int)ptr);
   printf(" The thread id is %d\n",pthread_self());

}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, NULL);

    if(ret != 0)
    {
        printf("Unabel to create thread \n");
        return -1;
    }

   // printf("Thread is created with ID : %d\n",TID);
    pthread_join(TID,NULL);
    printf("End of main thread\n");

    return 0;
}