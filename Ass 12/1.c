#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>
#include<string.h>

#include<pthread.h>

int main()
{
   
   int fd[2];
   int iRet = 0;
   char arr[] = "Marvellous infosystems";
   char buffer[512];

   pipe(fd);

   iRet = fork();

   if(iRet == 0) //Child process
   {
         printf("Child process scheduled for writing into pipe\n");
         close(fd[0]);
         write(fd[1], arr, strlen(arr));
         exit(0);
   }
   else // parent process
   {
         printf("Parent process scheduled for reading from pipe\n");
         close(fd[1]);
         read(fd[0],buffer,sizeof(buffer));
         printf("Data from PIPE is : %s\n",buffer);
   }

   return 0;
   
}