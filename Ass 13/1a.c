//client for named pipe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main()
{
   
   int fd = 0;
   
   char *path = "/tmp/pipe";
   char buffer[512];

   printf("Client is running and reading from pipe...\n");

   fd = open(path,O_RDONLY);

   read(fd,buffer,10);
   
   printf("datad from pipe is : %s\n",buffer);
   return 0;
   
}