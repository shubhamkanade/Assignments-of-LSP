#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>
#include<pthread.h>

void* ThreadProc1(void *ptr)
{
   printf("First thread\n");
}

void* ThreadProc2(void *ptr)
{
   printf("Second thread\n");
}

void* ThreadProc3(void *ptr)
{
   printf("Third thread\n");
}

void* ThreadProc4(void *ptr)
{
   printf("Fourth thread\n");
}



int main()
{
   pthread_t TID1;
   pthread_t TID2;
   pthread_t TID3;
   pthread_t TID4;
   int ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0;

   ret1 = pthread_create(&TID1,
                        NULL,
                        ThreadProc1,
                        NULL);
   ret2 = pthread_create(&TID2,
                        NULL,
                        ThreadProc2,
                        NULL);
   ret3 = pthread_create(&TID3,
                        NULL,
                        ThreadProc3,
                        NULL);
   ret4 = pthread_create(&TID4,
                        NULL,
                        ThreadProc4,
                        NULL);


   printf("Thread1 is created with ID : %ld\n",TID1);
   printf("Thread2 is created with ID : %ld\n",TID2);
   printf("Thread3 is created with ID : %ld\n",TID3);
   printf("Thread4 is created with ID : %ld\n",TID4);

   pthread_join(TID1,NULL);
   pthread_join(TID2,NULL);
   pthread_join(TID3,NULL);
   pthread_join(TID4,NULL);

   
   printf("End of main thread\n");


   return 0;
   
}