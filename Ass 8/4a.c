#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

int main()
{
   int ret = 0;

   ret = fork();
   if(ret == 0) // child
   {
        execl("./process1","4a","4a1",NULL);
   }
   else  //Parent
   {
        printf("Parent is running with PID : %d\n",getpid());
         kill(getpid(), SIGQUIT);
        kill(getppid(),SIGQUIT);
   }

    return 0;
}