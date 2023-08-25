
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#define SCALAR_ADD_BASE_ADDRESS 0x40000000
#define MAP_SIZE 0x00010000
typedef unsigned int uint32_t;
int main()
{
    int fd;
    uint32_t *base_addr_mapped;
    fd = open("/dev/mem", O_RDWR | O_SYNC);
    base_addr_mapped = (uint32_t *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SCALAR_ADD_BASE_ADDRESS);
    printf("base_addr_mapped: %p \n", base_addr_mapped);

    uint32_t *addend1;
    uint32_t *addend2;
    addend1 = base_addr_mapped + 0x00000004; // input addend1
    addend2 = base_addr_mapped + 0x00000006; // input addend2

    *addend1 = 100;
    *addend2 = 99;

    printf("addend1 base_addr_mapped : %p,value : %d\n", addend1, *addend1);
    printf("addend2 base_addr_mapped : %p,value : %d\n", addend2, *addend2);

    uint32_t *result;
    result = base_addr_mapped + 0x00000008; // output address

    printf("result addr : %p,value : %d\n", result, *result);
    munmap(base_addr_mapped, MAP_SIZE);
    close(fd);
}