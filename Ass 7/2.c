#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    void (*fptr)(char*, char*);
    char name1[30], name2[30];

    ptr = dlopen("./library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"CompareFiles");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }


    printf("Enter 1st file name\n");
    scanf("%s",name1);

    printf("Enter 2nd file name\n");
    scanf("%s",name2);
    
    fptr(name1,name2);
    return 0;
}