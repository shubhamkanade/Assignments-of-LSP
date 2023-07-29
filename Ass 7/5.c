#include<stdio.h>
#include "Sharedfile6.h"

int main()
{
    char file[30];
    printf("Enter file name\n");
    scanf("%s",file);
    DisplayFileInfo(file);
    return 0;
}