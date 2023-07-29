#include<stdio.h>
#include "sharedfile4.h"

void CalulateFactorial(int number)
{
   int ans = 1;

   if(number < 0)
   {
       number = -number;
   }

   while(number != 0)
   {
          ans *= number;
   }

   printf("Factorial of given number is %d\n", ans);
}
   