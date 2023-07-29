#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)();
    int number = 0;

    ptr = dlopen("./library5.so",RTLD_LAZY | RTLD_LOCAL);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"Display");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("Enter a number\n");
    scanf("%d",&number);
    fptr(number);
    return 0;
}