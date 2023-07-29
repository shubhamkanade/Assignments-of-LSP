#include<stdio.h>
#include "sharedfile2.h"

void CheckPrime(int n)
{
    int i = 0,m = 0, flag = 0;    

    m=n/2;

    for(i=2;i<=m;i++)    
    {    
        if(n%i==0)    
        {    
            printf("Number is not prime");    
            flag=1;    
            break;    
        }    
    }

    if(flag==0)    
        printf("Number is prime");    
}