#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0, fd1 = 0;
    char buffer[40] = "Hello world";

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
     
    fd = creat(argv[1], 0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    else
    {
        printf("File is succesfully created with fd : %d\n",fd);
    }

    fd1 = open(argv[1], O_WRONLY);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    else
    {
        printf("File is succesfully opened with fd : %d\n",fd);
    }
	
    write(fd1,buffer,strlen(buffer));
    return 0;
}
