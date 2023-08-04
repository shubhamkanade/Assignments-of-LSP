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
   printf("First thread\n");
}


int main()
{
   pthread_t TID1;
   pthread_attr_t attr1;
   int ret1 = 0, ret2 = 0;
   int chk1,chk2, s1 = 0, s2 = 0;

     s1 = pthread_attr_init(&attr1);
    chk1 = pthread_attr_setdetachstate(&attr1, PTHREAD_CREATE_DETACHED);
    printf("attr_setdetachstate: %d\n",chk1);
    //printf("attr_init: %d\n",chk);

   ret1 = pthread_create(&TID1,
                        &attr1,
                        ThreadProc1,
                        NULL);

   pthread_join(TID1,NULL);

   pthread_t TID2;
   pthread_attr_t attr2;
   int ret = 0;
   int chk;
    
    s2 = pthread_attr_init(&attr2);
    chk2 = pthread_attr_init(&attr2);
    printf("attr_init: %d\n",chk2);

   ret2 = pthread_create(&TID2,
                        &attr2,
                        ThreadProc2,
                        NULL);

   pthread_join(TID2,NULL);
   printf("End of main thread\n");

   return 0;
   
}