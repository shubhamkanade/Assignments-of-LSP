#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int fd = 0, ret = 0;

	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	fd = open(argv[1], O_WRONLY);

    ret = lseek(fd,atoi(argv[2]),0);

    truncate(argv[1],ret);

    printf("lenth is %d\n",ret);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	
	return 0;

}
