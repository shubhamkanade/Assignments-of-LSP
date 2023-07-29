#include<stdio.h>
#include "sharedfile3.h"

void CheckPerfect(int number)
{
   int i = 1, sum = 0;

    while(i < number )  {
     if(number % i == 0)
          sum = sum + i;
                i++;
           }
     if(sum == number)
          printf("%d is Perfect Number\n", number);
     else
          printf("%d is not a Perfect Number\n", number);
}
   