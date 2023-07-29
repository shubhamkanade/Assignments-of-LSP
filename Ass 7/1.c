#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)(int,int);
    void (*fptr1)(int,int);
    void (*fptr2)(int,int);
    void (*fptr3)(int,int);

    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"Add");
    fptr1 = dlsym(ptr, "Sub");
    fptr2 = dlsym(ptr, "Mult");
    fptr3 = dlsym(ptr, "Div");

    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr(3,4);
    fptr1(3,4);
    fptr2(5,4);
    fptr3(10,5);
    return 0;
}