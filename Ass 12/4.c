#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>

int main(void){
    int fd = open("/tmp/test_mmap", O_CREAT | O_RDWR);
    char *mapped_region = mmap(NULL, sysconf(_SC_PAGESIZE), PROT_WRITE, MAP_SHARED, fd, 0);
    mapped_region[0] = '0';
    mapped_region[1] = '1';
    mapped_region[2] = '2';
    mapped_region[3] = '3';
    mapped_region[4] = '4';
    mapped_region[5] = '5';
}