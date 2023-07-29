#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int number = 0;
    void (*fptr)(int);

    ptr = dlopen("./library2.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"CheckPrime");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("Enter number to check prime or not\n");
    scanf("%d",&number);
    fptr(number);

    return 0;
}
