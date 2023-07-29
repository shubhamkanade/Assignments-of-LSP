#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

int main()
{
   int ret = 0;
   int cpid = 0, Exit_status = 0;
     int ret1 = 0;
     
   ret = fork();
   if(ret == 0) // child
   {
        execl("./process2","ac","dc",NULL);
   }
   else  //Parent
   {
        printf("Parent is running with PID : %d\n",getpid());
        kill(getpid(), SIGQUIT);
        kill(getppid(),SIGQUIT);
   }



    //kill(getpid(),SIGQUIT);
    return 0;
}