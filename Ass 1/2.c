#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{

	int fd = 0;

        if(argc != 3)
        {
                printf("Invalid number of arguments\n");
                return -1;
        }

        fd = open(argv[1], atoi(argv[2]));

        if(fd == -1)
        {
                printf("Unable to open file\n");
                return -1;
        }
        else
                printf("File is successfully opened with fd : %d\n",fd);

        return 0;
}
