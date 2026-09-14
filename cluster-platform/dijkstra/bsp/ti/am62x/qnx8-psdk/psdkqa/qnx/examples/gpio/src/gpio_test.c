/*
 *  Copyright (c) Texas Instruments Incorporated 2018-2021
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/neutrino.h>
#include <ti/osal/RegisterIntr.h>
#include <hw/inout.h>
#include <sys/mman.h>

#include "ti/drv/sciclient/sciclient.h"
#include "ti/csl/csl_types.h"

/* GIC Interrupt Configuration Registers */
#define GICD_PADDR 0x01800000
#define ARM_GICD_ICFGRn 0x0C00
#define ARM_GICV3D_SIZE 0x10000

/* PADCONFIG Register */
#define CSL_PADCFG_CTRL0_CFG0_BASE (0xf0000UL)
#define CSL_PADCFG_CTRL0_CFG0_SIZE (0x8000UL)

/* GPIO1 Register */
#define CONFIG_GPIO1_BASE_ADDR (0x00601000UL)
#define CONFIG_GPIO1_SIZE (0x1000U)

/* GPIO1_49 (LED) Registers */
#define PIN_MMC1_SDWP 0x4244
#define GPIO_SET_DATA23 0x040
#define GPIO_CLR_DATA23 0x044
#define GPIO_DIR23 0x038

/* GPIO1_23 (Push Button) Registers */
#define PIN_UART0_RTSN 0x41D4
#define GPIO_SET_DATA01 0x018
#define GPIO_CLR_DATA01 0x01C
#define GPIO_IN_DATA01 0x020
#define GPIO_SET_RIS_TRIG01 0x024
#define GPIO_CLR_RIS_TRIG01 0x028
#define GPIO_SET_FAL_TRIG01 0x02C
#define GPIO_CLR_FAL_TRIG01 0x030
#define GPIO_INTSTAT01 0x034
#define GPIO_DIR01 0x010

/* GPIO Bit Interrupt Enable Register */
#define GPIO_BINTEN 0x008

#define PIN_MODE(mode)      (mode)
#define PIN_INPUT_ENABLE    (0x1U << 18U)
#define PIN_PULL_DISABLE    (0x1U << 16U)

/*
 * This example performs the following:
 *    Configures a GPIO pin connected to an LED on the SK in output mode and blinks it 5 times
 *    Configures a GPIO pin connected to the Push Button in input mode and configures it to generate interrupt on rising edge
 *    The application waits forever and prints a message whenever the Push button is pressed
*/

static void GPIO_bankIsrFxn(uintptr_t args);

void Gpio_blink_led(void)
{
    printf("Blinking LED1 5 times\n");
    /* Virtual Address for PADCONFIG base address */
    uintptr_t pinmux_base = mmap_device_io(CSL_PADCFG_CTRL0_CFG0_SIZE, CSL_PADCFG_CTRL0_CFG0_BASE);
    out32(pinmux_base +  PIN_MMC1_SDWP, PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE);

    /* Virtual Address for GPIO1 base address  */
    uintptr_t gpio1_base = mmap_device_io(CONFIG_GPIO1_SIZE, CONFIG_GPIO1_BASE_ADDR);
    out32(gpio1_base +  GPIO_DIR23, 0xFFFDFFFFU);

    //Blink LED connected to GPIO1_49 5 times
    for (int i =0; i<5; i++){
        out32(gpio1_base +  GPIO_SET_DATA23, 0x00020000U);
        sleep(1);
        out32(gpio1_base +  GPIO_CLR_DATA23, 0x00020000U);
        sleep(1);
    }  
}

/**
 * Set GIC SPI interrupt trigger mode
 *
 * @param irq   Interrupt vector number
 * @param edge  !0: edge-triggered, 0: level-triggered
 *
*/
void gic_v3_set_intr_trig_mode(const unsigned irq, const unsigned edge)
{
    const uint32_t mask = 0x2 << ((irq % 16) * 2);
    const uint32_t offset  = (irq / 16) * 4;
    uint32_t val = 0;
    
    uintptr_t gic_base = mmap_device_io(ARM_GICV3D_SIZE, GICD_PADDR);
    const uint32_t cur_val = in32(gic_base + ARM_GICD_ICFGRn + offset);
	val = cur_val;

	if (edge != 0) val |=  mask;
	else val &= ~mask;

	out32(gic_base + ARM_GICD_ICFGRn + offset, val);
}

/**
 * Configure MAIN_GPIOMUX_INTROUTER0 Interrupt Router with Input Source and Output Destination
*/
void Sciclient_gpioIrqSet(void)
{
    int32_t                             retVal=-1;
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;

    rmIrqReq.valid_params           = 0U;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params          |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
    rmIrqReq.global_event           = 0U;
    rmIrqReq.src_id                 = 3;    /* IR Device ID - AM62X_DEV_MAIN_GPIOMUX_INTROUTER0 */
    rmIrqReq.src_index              = 181U; /* Interrupt Source - GPIO1.gpio_bank.1 */
    rmIrqReq.dst_id                 = 3;    /* IR Device ID - AM62X_DEV_MAIN_GPIOMUX_INTROUTER0 */
    rmIrqReq.dst_host_irq           = 0U;   /* IR Output - gpiomux_introuter.outp.0 */
    rmIrqReq.ia_id                  = 0U;
    rmIrqReq.vint                   = 0U;
    rmIrqReq.vint_status_bit_index  = 0U;
    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;

    const Sciclient_ReqPrm_t    reqPrm =
    {
        TISCI_MSG_RM_IRQ_SET,
        TISCI_MSG_FLAG_AOP,
        (uint8_t *) &rmIrqReq,
        sizeof(rmIrqReq),
        SCICLIENT_SERVICE_WAIT_FOREVER
    };

    Sciclient_RespPrm_t     respPrm =
    {
        0,
        (uint8_t *) &rmIrqResp,
        sizeof (rmIrqResp)
    };

    /* Request Main Gpiomux interrupt router configuration */
    retVal = Sciclient_service(&reqPrm, &respPrm);

    /* Check Response flag for ACK from Sciserver */
    if(retVal==0 && ((respPrm.flags & TISCI_MSG_FLAG_ACK) == TISCI_MSG_FLAG_ACK))
    {
        printf("Sciclient event config passed!!\r\n");
    } else {
        printf("[Error] Sciclient event config failed!!\r\n");
    }
    return;
}

void Gpio_push_button(void)
{
    /* Configure Push button connected to GPIO1_23 as input and generate interrupt on Rising Edge */
    uintptr_t pinmux_base = mmap_device_io(CSL_PADCFG_CTRL0_CFG0_SIZE, CSL_PADCFG_CTRL0_CFG0_BASE);
    out32(pinmux_base +  PIN_UART0_RTSN, PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE);

    uintptr_t gpio1_base = mmap_device_io(CONFIG_GPIO1_SIZE, CONFIG_GPIO1_BASE_ADDR);
    out32(gpio1_base +  GPIO_DIR01, 0x00800000U);
    out32(gpio1_base +  GPIO_SET_RIS_TRIG01, 0x00800000U);
    out32(gpio1_base +  GPIO_INTSTAT01, 0x00800000U); /* Clear interrupt status */
    out32(gpio1_base +  GPIO_BINTEN, 0x2); /* Enable Bank 1 interrupt */

    printf("Waiting for push button\n");
    while(1)
    {
        //Wait for push button press
    }
}

/**
 * Interrupt Registration
*/
void Register_interrupts(void)
{
    OsalRegisterIntrParams_t intrPrms;
    int32_t osalRetVal;
    HwiP_Handle hwiHandle = NULL;
    uint32_t coreIntrNum = 32U; /*gicss0.spi.32 is connected to gpiomux_introuter.outp.0 */
    uint32_t pin = 23U; /* place holder for ISR argument */

    Osal_RegisterInterrupt_initParams(&intrPrms);

    intrPrms.corepacConfig.arg              = (uintptr_t)&pin;
    intrPrms.corepacConfig.isrRoutine       = &GPIO_bankIsrFxn;
    intrPrms.corepacConfig.priority         = 1;
    intrPrms.corepacConfig.intVecNum        = coreIntrNum;
    intrPrms.corepacConfig.corepacEventNum  = 0;
    intrPrms.corepacConfig.enableIntr       = 1;
    intrPrms.corepacConfig.intAutoEnable    = 1;

    osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
    if(osalRetVal == 0)
        printf("Registered interrupt successfully\n");
    else
        printf("Interrupt registration failed \n");
}

static void GPIO_bankIsrFxn(uintptr_t args)
{
    printf("Push Button Pressed!\n");
    uintptr_t gpio1_base = mmap_device_io(CONFIG_GPIO1_SIZE, CONFIG_GPIO1_BASE_ADDR);
    out32(gpio1_base +  GPIO_INTSTAT01, 0x00800000U); /* Clear interrupt status */
}

int main(void)
{
    /* Get IO priveleges */
    if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
    {
        perror("ThreadCtl(_NTO_TCTL_IO");
        return 1;
    }

    Gpio_blink_led();
    Sciclient_gpioIrqSet();
    gic_v3_set_intr_trig_mode(32, 1); //Set IRQ -> 32, Edge triggered -> true
    Register_interrupts();
    Gpio_push_button();
    return EXIT_SUCCESS;
}
