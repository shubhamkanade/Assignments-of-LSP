#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
   int ret = 0;

   ret = fork();
   if(ret == 0) // child
   {
        execl("./process3","ac","dc",NULL);
   }
   else  //Parent
   {
        printf("Parent is running with PID : %d\n",getpid());
   }

    return 0;
}