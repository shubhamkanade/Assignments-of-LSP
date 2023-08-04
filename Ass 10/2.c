// Write a program which creates two threads , first thread print number from 1 - 500, and other thread print numbers from 500 - 1;

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
   int i = 0;
   for(i = 0; i <= 50; i++)
   {
    printf("%d\n",i);
   }
}

void * ThreadProc2(void * ptr)
{
    int i = 0;
   for(i = 50; i >= 1; i--)
   {
    printf("%d\n",i);
   }
}

int main()
{
  pthread_t  TID1;
  pthread_t TID2;
  int ret1 = 0;
  int ret2 = 0;

  ret1 = pthread_create(&TID1, NULL, ThreadProc1, NULL);

  

  if(ret1 != 0)
  {
    printf("Unable to create thread 1 \n");
    return -1;
  }
  else
  {
    printf("Thread 1 is created with Id : %d\n",TID1);
  }
  printf("Start of thread 1 : ");
  pthread_join(TID1,NULL);

   ret2 = pthread_create(&TID2, NULL, ThreadProc2, NULL);
   if(ret2 != 0)
  {
    printf("Unable to create thread  2 \n");
    return -1;
  }
   else
  {
    printf("Thread 2 is created with Id : %d\n",TID2);
  }
  printf("Start of Thread 2 : ");
  pthread_join(TID2,NULL);
  
  







    return 0;
}