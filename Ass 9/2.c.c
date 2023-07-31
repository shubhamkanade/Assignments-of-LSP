// write a program which creates two processes 
// process 1 count the number of capital letters from demo.txt file
// process 2 count number of capital letters from hello.txt

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  char Buffer[200];
  int iCnt = 0;
  int iRet = 0;
  int i = 0;
  int fd = 0;

  fd = open("Demo.txt",O_RDONLY);

  while( (iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
  {
    for( i = 0; i < iRet; i++)
    {
      if( (Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
      {
        iCnt++;
      }
    }
  }

  printf("Number of capital characters are : %d\n",iCnt);

  close(fd);
  


  return 0;
}