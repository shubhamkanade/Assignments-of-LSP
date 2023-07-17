#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

		int fd = 0, mode = 0;

        if(argc != 3)
        {
                printf("Invalid number of arguments\n");
                return -1;
        }

		if(strcmp(argv[2], "read") == 0)
			mode = R_OK;
		else if (strcmp(argv[2], "write") == 0)
		{
			mode = W_OK;
		}
		else if (strcmp(argv[2], "execute") == 0)
		{
			mode = X_OK;
		}

		if(access(argv[1], mode) < 0)
		{
			printf("File is not opened in any access\n");
		}
		else
		{
			printf("File is opened in %s access\n",argv[2]);
		}
}

