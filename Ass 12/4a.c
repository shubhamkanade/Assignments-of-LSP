#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>

int main(void){
    int fd = open("/tmp/test_mmap", O_CREAT | O_RDWR, S_IRWXU);
    char *mapped_region = mmap(NULL, sysconf(_SC_PAGESIZE), PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%c\n", mapped_region[0]);
    printf("%c\n", mapped_region[1]);
    printf("%c\n", mapped_region[2]);
    printf("%c\n", mapped_region[3]);
    printf("%c\n", mapped_region[4]);
    printf("%c\n", mapped_region[5]);
}