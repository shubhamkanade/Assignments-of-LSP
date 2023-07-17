#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>


int main(int argc, char *argv[])
{
    char random_garbage[1024];
    int fd = 0;
    if(argc != 2)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

    lseek(fd, 1 * 1024, 0);
    write(fd, random_garbage, 1024);
    close(fd);

    return 0;
}