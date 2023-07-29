#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)(int);
    int number = 0;

    ptr = dlopen("./library3.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"CheckPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

     printf("Enter number to check perfect or not\n");
    scanf("%d",&number);
    fptr(number);
    return 0;
}
