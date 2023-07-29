#include<stdio.h>
#include "sharedfile.h"

void Add(int no1, int no2)
{
    printf("Addition is %d\n", no1 + no2);
}

void Sub(int no1, int no2)
{
    printf("Subtraction is %d\n", no1 - no2);
}

void Mult(int no1, int no2)
{
    printf("Multiplication is %d\n", no1 * no2);
}

void Div(int no1, int no2)
{
    printf("Division is %d\n", no1 / no2);
}

