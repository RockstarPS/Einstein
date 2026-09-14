#include "Std_Types.h"

#define MAILBOX_BASE_ADDR     (0x29040000UL)

#define GIP_TO_VIP_OFFSET     (0x40UL)
#define VIP_TO_GIP_OFFSET     (0x44UL)
#define GIP_TX_READY_OFFSET   (0xC0UL)

/* ================= REGISTER ACCESS ================= */

#define GIP_TO_VIP_REG \
    (*(volatile uint32*)(MAILBOX_BASE_ADDR + GIP_TO_VIP_OFFSET))

#define VIP_TO_GIP_REG \
    (*(volatile uint32*)(MAILBOX_BASE_ADDR + VIP_TO_GIP_OFFSET))

#define GIP_TX_READY_REG \
    (*(volatile uint32*)(MAILBOX_BASE_ADDR + GIP_TX_READY_OFFSET))

void VipMailbox_Handler(void)
{
    static uint8 counter = 0U;

    /* Check if GIP has written data */
    if (GIP_TX_READY_REG > 0U)
    {
        uint32 data;

        /* Read received data */
        data = GIP_TO_VIP_REG;
        counter++;

        /* Send response back */
        VIP_TO_GIP_REG = data;
 
    }
}
