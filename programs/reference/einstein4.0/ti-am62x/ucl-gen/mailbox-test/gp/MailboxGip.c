#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
 #define MAILBOX_BASE_ADDR    0x29040000

#define GIP_TO_VIP_OFFSET    0x40
#define VIP_TO_GIP_OFFSET    0x44
#define GIP_RX_READY_OFFSET  0xC4

void* memoryMapping()
{
    int fd;
    void *mb;
    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) 
    {
        mb = NULL;
        perror("open");
    }

    mb = mmap(NULL,getpagesize(),PROT_READ | PROT_WRITE,MAP_SHARED,fd,MAILBOX_BASE_ADDR);

    if (mb == MAP_FAILED) 
    {
        mb = NULL;
        close(fd);
        perror("mmap");
    }
    close(fd);
    return mb;
}

void mailBoxTest()
{
    
}
int main(void)
{
    volatile uint32_t *gip_to_vip;
    volatile uint32_t *vip_to_gip;
    volatile uint32_t *gip_rx_ready;

    void* memPtr = memoryMapping();
    gip_to_vip   = (volatile uint32_t *)((uint8_t *)memPtr + GIP_TO_VIP_OFFSET);
    vip_to_gip   = (volatile uint32_t *)((uint8_t *)memPtr + VIP_TO_GIP_OFFSET);
    gip_rx_ready = (volatile uint32_t *)((uint8_t *)memPtr + GIP_RX_READY_OFFSET);

    printf("Mailbox test started...\n");

    while (1)
    {
        uint32_t data = rand();

        /* Send data */
        *gip_to_vip = data;

        printf("GIP SENT : 0x%08X\n", data);

        /* Wait for response */
        while ((*gip_rx_ready & 0x1) == 0)
            ;
        uint32_t response = *vip_to_gip;

        printf("GIP RECEIVED : 0x%08X\n", response);

        /* Clear status bit */
        *gip_rx_ready = 0x1;

        sleep(1);
    }

    munmap(memPtr, getpagesize());
    
    return 0;
}
