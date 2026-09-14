/******************************************************************************
 * $Revision: 10544 $
 * $Date:: 2014-09-16 10:22:04 +0200#$
 *****************************************************************************/
/* __DISCLAIMER_START__                                                      */
/******************************************************************************
* Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion 
* components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion components. Spansion shall not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this software "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the software.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
* WARRANTY OF NONINFRINGEMENT.  
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
* SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
* FROM, THE SOFTWARE.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Disclaimer and Copyright notice must be 
* included with each copy of this software, whether used in part or whole, 
* at all times.
******************************************************************************/
/* __DISCLAIMER_END__                                                        */
/*****************************************************************************
 ** \file pdl.h
 **
 ** Headerfile for Traveo Peripheral Driver Library 
 **
 ** History:
 **   - 2014-06-22  0.01  HS  Initial version for Traveo
 **   - 2014-06-27  0.02  HS  Change  DMB() from __asm("DMB") for compatibility
 **                           between GHS and IAR
 **							  Add definition for LIN module.
 *****************************************************************************/

#ifndef __PDL_H__
#define __PDL_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "base_types.h"
#include "mcu_settings.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/* Global pre-processor symbols/macros ('define')                            */
/*****************************************************************************/
/**
 ******************************************************************************
 ** All definitions needed for pdl_user.h are stated here 
 ******************************************************************************/ 
#define PDL_ON                1    /*!< Switches a feature on. */
#define PDL_OFF               0    /*!< Switches a feature off. */
#define PDL_WAIT_LOOP_HOOK()  Pdl_WaitLoopHook()
/**
 ******************************************************************************
 ** User Defines for PDL resource activation
 **
 ** Possible definitions are PDL_ON and PDL_OFF.
 **
 ******************************************************************************/

/******************************************************************************/
/* User Setting Include file                                                  */
/******************************************************************************/
#include "pdl_user.h"  /* MUST be included here! */

/**
 ******************************************************************************
 ** PDL resource enable check
 ** 
 ** \note It does not check, if a device has actually any in pdl.h enabled
 **       resource and all instances available!
 **
 ******************************************************************************/

/* Activate code in work_flash.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_WFLASH == PDL_ON)
    #define PDL_PERIPHERAL_WFLASH_ACTIVE
    #include "workflash\workflash.h"
#endif

/* Activate code in frt.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_FRT0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_FRT1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_FRT2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_FRT3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_FRT4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_FRT5 == PDL_ON)
    #define PDL_PERIPHERAL_FRT_ACTIVE
    #include "frt\frt.h"
#endif

/* Activate code in cpu.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_CPU == PDL_ON)
    #define PDL_PERIPHERAL_CPU_ACTIVE
    #include "cpu\cpu.h"
#endif

/* Activate code in mem.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_MEM == PDL_ON)
    #define PDL_PERIPHERAL_MEM_ACTIVE
    #include "mem\mem.h"
#endif

/* Activate code in sysctrl.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_SYSCTRL == PDL_ON)
    #define PDL_PERIPHERAL_SYSCTRL_ACTIVE
    #include "sysctrl\sysctrl.h"
#endif

/* Activate code in port.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_PORT == PDL_ON)
    #define PDL_PERIPHERAL_PORT_ACTIVE
    #include "port\port.h"
#endif

/* Activate code in hwdg.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_HWDG == PDL_ON)
    #define PDL_PERIPHERAL_HWDG_ACTIVE
    #include "hwdg\hwdg.h"
#endif

/* Activate code in swdg.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_SWDG == PDL_ON)
    #define PDL_PERIPHERAL_SWDG_ACTIVE
    #include "swdg\swdg.h"
#endif

/* Activate code in uart.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_UART0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART5 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART6 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART7 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART8 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART9 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART10 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART11 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART12 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART13 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART14 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART15 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART16 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART17 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART18 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART19 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART20 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_UART21 == PDL_ON)
    #define PDL_PERIPHERAL_UART_ACTIVE
    #include "uart\uart.h"
#endif

/* Activate code in lin.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_LIN0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN5 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN6 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN7 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN8 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN9 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN10 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN11 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN12 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN13 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN14 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN15 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN16 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN17 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN18 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN19 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN20 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_LIN21 == PDL_ON)
    #define PDL_PERIPHERAL_LIN_ACTIVE
    #include "lin\lin.h"
#endif

/* Activate code in canfd.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_CANFD0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_CANFD1 == PDL_ON)
    #define PDL_PERIPHERAL_CANFD_ACTIVE
    #include "canfd\canfd.h"
#endif

/* Activate code in pwm.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_PWM0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM5 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM6 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM7 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM8 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM9 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM10 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM11 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM12 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM13 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM14 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM15 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM16 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM17 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM18 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM19 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM20 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM21 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM22 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM23 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM24 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM25 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM26 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM27 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM28 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_PWM29 == PDL_ON)
    #define PDL_PERIPHERAL_PWM_ACTIVE
    #include "pwm\pwm.h"
#endif

/* Activate code in rlt.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_RLT0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT5 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT6 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT7 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT8 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT9 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT10 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT11 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT12 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT13 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT14 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT15 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT16 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT17 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT18 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT19 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT20 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT21 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT22 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT23 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT24 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT25 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT26 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT27 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT28 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_RLT29 == PDL_ON)
    #define PDL_PERIPHERAL_RLT_ACTIVE
    #include "rlt\rlt.h"
#endif

/* Activate code in icu.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_ICU0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_ICU1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_ICU2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_ICU3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_ICU4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_ICU5 == PDL_ON)
    #define PDL_PERIPHERAL_ICU_ACTIVE
    #include "icu\icu.h"
#endif

/* Activate code in eic.c if set to PDL_ON */
#if (PDL_PERIPHERAL_ENABLE_EIC0 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC1 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC2 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC3 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC4 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC5 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC6 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC7 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC8 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC9 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC10 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC11 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC12 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC13 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC14 == PDL_ON) || \
    (PDL_PERIPHERAL_ENABLE_EIC15 == PDL_ON)
    #define PDL_PERIPHERAL_EIC_ACTIVE
    #include "eic\eic.h"
#endif


/**
 ******************************************************************************
 ** Interrupt vector definitions
 ******************************************************************************/

/** WFLASH *******************************************************************/
#if (PDL_PERIPHERAL_ENABLE_WFLASH == PDL_ON)
#else
#endif

/** FRT **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_FRT0 == PDL_ON)
    #define PDL_IRQ_ISR_FRT0    (Frt_Isr_Frt0)
#else
    #define PDL_IRQ_ISR_FRT0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_FRT1 == PDL_ON)
    #define PDL_IRQ_ISR_FRT1    (Frt_Isr_Frt1)
#else
    #define PDL_IRQ_ISR_FRT1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_FRT2 == PDL_ON)
    #define PDL_IRQ_ISR_FRT2    (Frt_Isr_Frt2)
#else
    #define PDL_IRQ_ISR_FRT2    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_FRT3 == PDL_ON)
    #define PDL_IRQ_ISR_FRT3    (Frt_Isr_Frt3)
#else
    #define PDL_IRQ_ISR_FRT3    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_FRT4 == PDL_ON)
    #define PDL_IRQ_ISR_FRT4    (Frt_Isr_Frt4)
#else
    #define PDL_IRQ_ISR_FRT4    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_FRT5 == PDL_ON)
    #define PDL_IRQ_ISR_FRT5    (Frt_Isr_Frt5)
#else
    #define PDL_IRQ_ISR_FRT5    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

/** CPU ***********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_CPU == PDL_ON)
#else
#endif

/** MEM ***********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_MEM == PDL_ON)
#else
#endif

/** Port **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_PORT == PDL_ON)
#else
#endif

/** HWDG **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_HWDG == PDL_ON)
    #define PDL_IRQ_ISR_HWDG        (Hwdg_Isr_PreWarn)
    #define PDL_NMI_ISR_HWDG        (Hwdg_Isr_NMI)
#else
    #define PDL_IRQ_ISR_HWDG        (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_NMI_ISR_HWDG        (INTERRUPTS_NMI_DEFAULT_HANDLER)
#endif

/** SWDG **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_SWDG == PDL_ON)
    #define PDL_IRQ_ISR_SWDG        (Swdg_Isr_PreWarn)
    #define PDL_NMI_ISR_SWDG        (Swdg_Isr_NMI)
#else
    #define PDL_IRQ_ISR_SWDG        (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_NMI_ISR_SWDG        (INTERRUPTS_NMI_DEFAULT_HANDLER)
#endif

/** UART **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_UART0 == PDL_ON)
    #define PDL_IRQ_ISR_MFS0_TX    (Uart_Isr_Uart0_Tx)
    #define PDL_IRQ_ISR_MFS0_RX    (Uart_Isr_Uart0_Rx)
    #define PDL_IRQ_ISR_MFS0_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN0 == PDL_ON)
    #define PDL_IRQ_ISR_MFS0_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS0_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS0_ERR   (Lin_Isr_Lin0_Status)
#else
    #define PDL_IRQ_ISR_MFS0_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS0_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS0_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART1 == PDL_ON)
    #define PDL_IRQ_ISR_MFS1_TX    (Uart_Isr_Uart1_Tx)
    #define PDL_IRQ_ISR_MFS1_RX    (Uart_Isr_Uart1_Rx)
    #define PDL_IRQ_ISR_MFS1_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN1 == PDL_ON)
    #define PDL_IRQ_ISR_MFS1_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS1_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS1_ERR   (Lin_Isr_Lin1_Status)
#else
    #define PDL_IRQ_ISR_MFS1_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS1_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS1_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART2 == PDL_ON)
    #define PDL_IRQ_ISR_MFS2_TX    (Uart_Isr_Uart2_Tx)
    #define PDL_IRQ_ISR_MFS2_RX    (Uart_Isr_Uart2_Rx)
    #define PDL_IRQ_ISR_MFS2_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN2 == PDL_ON)
    #define PDL_IRQ_ISR_MFS2_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS2_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS2_ERR   (Lin_Isr_Lin2_Status)
#else
    #define PDL_IRQ_ISR_MFS2_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS2_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS2_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART3 == PDL_ON)
    #define PDL_IRQ_ISR_MFS3_TX    (Uart_Isr_Uart3_Tx)
    #define PDL_IRQ_ISR_MFS3_RX    (Uart_Isr_Uart3_Rx)
    #define PDL_IRQ_ISR_MFS3_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN3 == PDL_ON)
    #define PDL_IRQ_ISR_MFS3_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS3_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS3_ERR   (Lin_Isr_Lin3_Status)
#else
    #define PDL_IRQ_ISR_MFS3_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS3_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS3_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART4 == PDL_ON)
    #define PDL_IRQ_ISR_MFS4_TX    (Uart_Isr_Uart4_Tx)
    #define PDL_IRQ_ISR_MFS4_RX    (Uart_Isr_Uart4_Rx)
    #define PDL_IRQ_ISR_MFS4_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN4 == PDL_ON)
    #define PDL_IRQ_ISR_MFS4_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS4_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS4_ERR   (Lin_Isr_Lin4_Status)
#else
    #define PDL_IRQ_ISR_MFS4_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS4_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS4_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART5 == PDL_ON)
    #define PDL_IRQ_ISR_MFS5_TX    (Uart_Isr_Uart5_Tx)
    #define PDL_IRQ_ISR_MFS5_RX    (Uart_Isr_Uart5_Rx)
    #define PDL_IRQ_ISR_MFS5_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN5 == PDL_ON)
    #define PDL_IRQ_ISR_MFS5_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS5_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS5_ERR   (Lin_Isr_Lin5_Status)
#else
    #define PDL_IRQ_ISR_MFS5_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS5_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS5_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART6 == PDL_ON)
    #define PDL_IRQ_ISR_MFS6_TX    (Uart_Isr_Uart6_Tx)
    #define PDL_IRQ_ISR_MFS6_RX    (Uart_Isr_Uart6_Rx)
    #define PDL_IRQ_ISR_MFS6_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN6 == PDL_ON)
    #define PDL_IRQ_ISR_MFS6_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS6_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS6_ERR   (Lin_Isr_Lin6_Status)
#else
    #define PDL_IRQ_ISR_MFS6_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS6_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS6_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART7 == PDL_ON)
    #define PDL_IRQ_ISR_MFS7_TX    (Uart_Isr_Uart7_Tx)
    #define PDL_IRQ_ISR_MFS7_RX    (Uart_Isr_Uart7_Rx)
    #define PDL_IRQ_ISR_MFS7_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN7 == PDL_ON)
    #define PDL_IRQ_ISR_MFS7_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS7_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS7_ERR   (Lin_Isr_Lin7_Status)
#else
    #define PDL_IRQ_ISR_MFS7_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS7_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS7_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART8 == PDL_ON)
    #define PDL_IRQ_ISR_MFS8_TX    (Uart_Isr_Uart8_Tx)
    #define PDL_IRQ_ISR_MFS8_RX    (Uart_Isr_Uart8_Rx)
    #define PDL_IRQ_ISR_MFS8_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN8 == PDL_ON)
    #define PDL_IRQ_ISR_MFS8_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS8_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS8_ERR   (Lin_Isr_Lin8_Status)
#else
    #define PDL_IRQ_ISR_MFS8_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS8_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS8_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART9 == PDL_ON)
    #define PDL_IRQ_ISR_MFS9_TX    (Uart_Isr_Uart9_Tx)
    #define PDL_IRQ_ISR_MFS9_RX    (Uart_Isr_Uart9_Rx)
    #define PDL_IRQ_ISR_MFS9_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN9 == PDL_ON)
    #define PDL_IRQ_ISR_MFS9_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS9_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS9_ERR   (Lin_Isr_Lin9_Status)
#else
    #define PDL_IRQ_ISR_MFS9_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS9_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS9_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART10 == PDL_ON)
    #define PDL_IRQ_ISR_MFS10_TX    (Uart_Isr_Uart10_Tx)
    #define PDL_IRQ_ISR_MFS10_RX    (Uart_Isr_Uart10_Rx)
    #define PDL_IRQ_ISR_MFS10_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN10 == PDL_ON)
    #define PDL_IRQ_ISR_MFS10_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS10_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS10_ERR   (Lin_Isr_Lin10_Status)
#else
    #define PDL_IRQ_ISR_MFS10_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS10_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS10_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART11 == PDL_ON)
    #define PDL_IRQ_ISR_MFS11_TX    (Uart_Isr_Uart11_Tx)
    #define PDL_IRQ_ISR_MFS11_RX    (Uart_Isr_Uart11_Rx)
    #define PDL_IRQ_ISR_MFS11_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN11 == PDL_ON)
    #define PDL_IRQ_ISR_MFS11_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS11_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS11_ERR   (Lin_Isr_Lin11_Status)
#else
    #define PDL_IRQ_ISR_MFS11_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS11_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS11_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART12 == PDL_ON)
    #define PDL_IRQ_ISR_MFS12_TX    (Uart_Isr_Uart12_Tx)
    #define PDL_IRQ_ISR_MFS12_RX    (Uart_Isr_Uart12_Rx)
    #define PDL_IRQ_ISR_MFS12_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN12 == PDL_ON)
    #define PDL_IRQ_ISR_MFS12_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS12_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS12_ERR   (Lin_Isr_Lin12_Status)
#else
    #define PDL_IRQ_ISR_MFS12_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS12_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS12_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART13 == PDL_ON)
    #define PDL_IRQ_ISR_MFS13_TX    (Uart_Isr_Uart13_Tx)
    #define PDL_IRQ_ISR_MFS13_RX    (Uart_Isr_Uart13_Rx)
    #define PDL_IRQ_ISR_MFS13_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN13 == PDL_ON)
    #define PDL_IRQ_ISR_MFS13_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS13_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS13_ERR   (Lin_Isr_Lin13_Status)
#else
    #define PDL_IRQ_ISR_MFS13_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS13_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS13_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART14 == PDL_ON)
    #define PDL_IRQ_ISR_MFS14_TX    (Uart_Isr_Uart14_Tx)
    #define PDL_IRQ_ISR_MFS14_RX    (Uart_Isr_Uart14_Rx)
    #define PDL_IRQ_ISR_MFS14_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN14 == PDL_ON)
    #define PDL_IRQ_ISR_MFS14_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS14_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS14_ERR   (Lin_Isr_Lin14_Status)
#else
    #define PDL_IRQ_ISR_MFS14_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS14_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS14_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART15 == PDL_ON)
    #define PDL_IRQ_ISR_MFS15_TX    (Uart_Isr_Uart15_Tx)
    #define PDL_IRQ_ISR_MFS15_RX    (Uart_Isr_Uart15_Rx)
    #define PDL_IRQ_ISR_MFS15_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN15 == PDL_ON)
    #define PDL_IRQ_ISR_MFS15_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS15_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS15_ERR   (Lin_Isr_Lin15_Status)
#else
    #define PDL_IRQ_ISR_MFS15_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS15_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS15_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART16 == PDL_ON)
    #define PDL_IRQ_ISR_MFS16_TX    (Uart_Isr_Uart16_Tx)
    #define PDL_IRQ_ISR_MFS16_RX    (Uart_Isr_Uart16_Rx)
    #define PDL_IRQ_ISR_MFS16_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN16 == PDL_ON)
    #define PDL_IRQ_ISR_MFS16_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS16_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS16_ERR   (Lin_Isr_Lin16_Status)
#else
    #define PDL_IRQ_ISR_MFS16_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS16_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS16_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART17 == PDL_ON)
    #define PDL_IRQ_ISR_MFS17_TX    (Uart_Isr_Uart17_Tx)
    #define PDL_IRQ_ISR_MFS17_RX    (Uart_Isr_Uart17_Rx)
    #define PDL_IRQ_ISR_MFS17_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN17 == PDL_ON)
    #define PDL_IRQ_ISR_MFS17_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS17_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS17_ERR   (Lin_Isr_Lin17_Status)
#else
    #define PDL_IRQ_ISR_MFS17_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS17_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS17_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART18 == PDL_ON)
    #define PDL_IRQ_ISR_MFS18_TX    (Uart_Isr_Uart18_Tx)
    #define PDL_IRQ_ISR_MFS18_RX    (Uart_Isr_Uart18_Rx)
    #define PDL_IRQ_ISR_MFS18_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN18 == PDL_ON)
    #define PDL_IRQ_ISR_MFS18_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS18_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS18_ERR   (Lin_Isr_Lin18_Status)
#else
    #define PDL_IRQ_ISR_MFS18_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS18_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS18_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART19 == PDL_ON)
    #define PDL_IRQ_ISR_MFS19_TX    (Uart_Isr_Uart19_Tx)
    #define PDL_IRQ_ISR_MFS19_RX    (Uart_Isr_Uart19_Rx)
    #define PDL_IRQ_ISR_MFS19_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN19 == PDL_ON)
    #define PDL_IRQ_ISR_MFS19_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS19_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS19_ERR   (Lin_Isr_Lin19_Status)
#else
    #define PDL_IRQ_ISR_MFS19_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS19_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS19_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART20 == PDL_ON)
    #define PDL_IRQ_ISR_MFS20_TX    (Uart_Isr_Uart20_Tx)
    #define PDL_IRQ_ISR_MFS20_RX    (Uart_Isr_Uart20_Rx)
    #define PDL_IRQ_ISR_MFS20_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN20 == PDL_ON)
    #define PDL_IRQ_ISR_MFS20_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS20_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS20_ERR   (Lin_Isr_Lin20_Status)
#else
    #define PDL_IRQ_ISR_MFS20_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS20_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS20_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_UART21 == PDL_ON)
    #define PDL_IRQ_ISR_MFS21_TX    (Uart_Isr_Uart21_Tx)
    #define PDL_IRQ_ISR_MFS21_RX    (Uart_Isr_Uart21_Rx)
    #define PDL_IRQ_ISR_MFS21_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#elif (PDL_PERIPHERAL_ENABLE_LIN21 == PDL_ON)
    #define PDL_IRQ_ISR_MFS21_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS21_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS21_ERR   (Lin_Isr_Lin21_Status)
#else
    #define PDL_IRQ_ISR_MFS21_TX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS21_RX    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_MFS21_ERR   (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

/** CAN-FD **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_CANFD0 == PDL_ON)
    #define PDL_IRQ_ISR_CANFD0    (CanFD_Isr_CanFD0)
#else
    #define PDL_IRQ_ISR_CANFD0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_CANFD1 == PDL_ON)
    #define PDL_IRQ_ISR_CANFD1    (CanFD_Isr_CanFD1)
#else
    #define PDL_IRQ_ISR_CANFD1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

/** Base Timer (PWM & RLT) **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_PWM0 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM8 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM9 == PDL_ON) \
    || (PDL_PERIPHERAL_ENABLE_PWM10 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM11 == PDL_ON)
    #define PDL_IRQ_ISR_BT0    (Pwm_Isr_Pwm0)
#elif (PDL_PERIPHERAL_ENABLE_RLT0 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT8 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT9 == PDL_ON) \
    || (PDL_PERIPHERAL_ENABLE_RLT10 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT11 == PDL_ON)
    #define PDL_IRQ_ISR_BT0    (Rlt_Isr_Rlt0)
#else
    #define PDL_IRQ_ISR_BT0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM1 == PDL_ON)
    #define PDL_IRQ_ISR_BT1    (Pwm_Isr_Pwm1)
#elif (PDL_PERIPHERAL_ENABLE_RLT1 == PDL_ON)
    #define PDL_IRQ_ISR_BT1    (Rlt_Isr_Rlt1)
#else
    #define PDL_IRQ_ISR_BT1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM2 == PDL_ON)
    #define PDL_IRQ_ISR_BT2    (Pwm_Isr_Pwm2)
#elif (PDL_PERIPHERAL_ENABLE_RLT2 == PDL_ON)
    #define PDL_IRQ_ISR_BT2    (Rlt_Isr_Rlt2)
#else
    #define PDL_IRQ_ISR_BT2    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM3 == PDL_ON)
    #define PDL_IRQ_ISR_BT3    (Pwm_Isr_Pwm3)
#elif (PDL_PERIPHERAL_ENABLE_RLT3 == PDL_ON)
    #define PDL_IRQ_ISR_BT3    (Rlt_Isr_Rlt3)
#else
    #define PDL_IRQ_ISR_BT3    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM4 == PDL_ON)
    #define PDL_IRQ_ISR_BT4    (Pwm_Isr_Pwm4)
#elif (PDL_PERIPHERAL_ENABLE_RLT4 == PDL_ON)
    #define PDL_IRQ_ISR_BT4    (Rlt_Isr_Rlt4)
#else
    #define PDL_IRQ_ISR_BT4    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM5 == PDL_ON)
    #define PDL_IRQ_ISR_BT5    (Pwm_Isr_Pwm5)
#elif (PDL_PERIPHERAL_ENABLE_RLT5 == PDL_ON)
    #define PDL_IRQ_ISR_BT5    (Rlt_Isr_Rlt5)
#else
    #define PDL_IRQ_ISR_BT5    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM6 == PDL_ON)
    #define PDL_IRQ_ISR_BT6    (Pwm_Isr_Pwm6)
#elif (PDL_PERIPHERAL_ENABLE_RLT6 == PDL_ON)
    #define PDL_IRQ_ISR_BT6    (Rlt_Isr_Rlt6)
#else
    #define PDL_IRQ_ISR_BT6    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM7 == PDL_ON)
    #define PDL_IRQ_ISR_BT7    (Pwm_Isr_Pwm7)
#elif (PDL_PERIPHERAL_ENABLE_RLT7 == PDL_ON)
    #define PDL_IRQ_ISR_BT7    (Rlt_Isr_Rlt7)
#else
    #define PDL_IRQ_ISR_BT7    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM12 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM20 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM21 == PDL_ON) \
    || (PDL_PERIPHERAL_ENABLE_PWM22 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_PWM23 == PDL_ON)
    #define PDL_IRQ_ISR_BT12    (Pwm_Isr_Pwm12)
#elif (PDL_PERIPHERAL_ENABLE_RLT12 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT20 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT21 == PDL_ON) \
    || (PDL_PERIPHERAL_ENABLE_RLT22 == PDL_ON) || (PDL_PERIPHERAL_ENABLE_RLT23 == PDL_ON)
    #define PDL_IRQ_ISR_BT12    (Rlt_Isr_Rlt12)
#else
    #define PDL_IRQ_ISR_BT12    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM13 == PDL_ON)
    #define PDL_IRQ_ISR_BT13    (Pwm_Isr_Pwm13)
#elif (PDL_PERIPHERAL_ENABLE_RLT13 == PDL_ON)
    #define PDL_IRQ_ISR_BT13    (Rlt_Isr_Rlt13)
#else
    #define PDL_IRQ_ISR_BT13    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM14 == PDL_ON)
    #define PDL_IRQ_ISR_BT14    (Pwm_Isr_Pwm14)
#elif (PDL_PERIPHERAL_ENABLE_RLT14 == PDL_ON)
    #define PDL_IRQ_ISR_BT14    (Rlt_Isr_Rlt14)
#else
    #define PDL_IRQ_ISR_BT14    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM15 == PDL_ON)
    #define PDL_IRQ_ISR_BT15    (Pwm_Isr_Pwm15)
#elif (PDL_PERIPHERAL_ENABLE_RLT15 == PDL_ON)
    #define PDL_IRQ_ISR_BT15    (Rlt_Isr_Rlt15)
#else
    #define PDL_IRQ_ISR_BT15    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM16 == PDL_ON)
    #define PDL_IRQ_ISR_BT16    (Pwm_Isr_Pwm16)
#elif (PDL_PERIPHERAL_ENABLE_RLT16 == PDL_ON)
    #define PDL_IRQ_ISR_BT16    (Rlt_Isr_Rlt16)
#else
    #define PDL_IRQ_ISR_BT16    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM17 == PDL_ON)
    #define PDL_IRQ_ISR_BT17    (Pwm_Isr_Pwm17)
#elif (PDL_PERIPHERAL_ENABLE_RLT17 == PDL_ON)
    #define PDL_IRQ_ISR_BT17    (Rlt_Isr_Rlt17)
#else
    #define PDL_IRQ_ISR_BT17    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM18 == PDL_ON)
    #define PDL_IRQ_ISR_BT18    (Pwm_Isr_Pwm18)
#elif (PDL_PERIPHERAL_ENABLE_RLT18 == PDL_ON)
    #define PDL_IRQ_ISR_BT18    (Rlt_Isr_Rlt18)
#else
    #define PDL_IRQ_ISR_BT18    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM19 == PDL_ON)
    #define PDL_IRQ_ISR_BT19    (Pwm_Isr_Pwm19)
#elif (PDL_PERIPHERAL_ENABLE_RLT19 == PDL_ON)
    #define PDL_IRQ_ISR_BT19    (Rlt_Isr_Rlt19)
#else
    #define PDL_IRQ_ISR_BT19    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM24 == PDL_ON)
    #define PDL_IRQ_ISR_BT24    (Pwm_Isr_Pwm24)
#elif (PDL_PERIPHERAL_ENABLE_RLT24 == PDL_ON)
    #define PDL_IRQ_ISR_BT24    (Rlt_Isr_Rlt24)
#else
    #define PDL_IRQ_ISR_BT24    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM25 == PDL_ON)
    #define PDL_IRQ_ISR_BT25    (Pwm_Isr_Pwm25)
#elif (PDL_PERIPHERAL_ENABLE_RLT25 == PDL_ON)
    #define PDL_IRQ_ISR_BT25    (Rlt_Isr_Rlt25)
#else
    #define PDL_IRQ_ISR_BT25    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM26 == PDL_ON)
    #define PDL_IRQ_ISR_BT26    (Pwm_Isr_Pwm26)
#elif (PDL_PERIPHERAL_ENABLE_RLT26 == PDL_ON)
    #define PDL_IRQ_ISR_BT26    (Rlt_Isr_Rlt26)
#else
    #define PDL_IRQ_ISR_BT26    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM27 == PDL_ON)
    #define PDL_IRQ_ISR_BT27    (Pwm_Isr_Pwm27)
#elif (PDL_PERIPHERAL_ENABLE_RLT27 == PDL_ON)
    #define PDL_IRQ_ISR_BT27    (Rlt_Isr_Rlt27)
#else
    #define PDL_IRQ_ISR_BT27    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM28 == PDL_ON)
    #define PDL_IRQ_ISR_BT28    (Pwm_Isr_Pwm28)
#elif (PDL_PERIPHERAL_ENABLE_RLT28 == PDL_ON)
    #define PDL_IRQ_ISR_BT28    (Rlt_Isr_Rlt28)
#else
    #define PDL_IRQ_ISR_BT28    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_PWM29 == PDL_ON)
    #define PDL_IRQ_ISR_BT29    (Pwm_Isr_Pwm29)
#elif (PDL_PERIPHERAL_ENABLE_RLT29 == PDL_ON)
    #define PDL_IRQ_ISR_BT29    (Rlt_Isr_Rlt29)
#else
    #define PDL_IRQ_ISR_BT29    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

/** ICU **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_ICU0 == PDL_ON)
    #define PDL_IRQ_ISR_ICU0_0    (Icu_Isr_Icu0Channel0)
    #define PDL_IRQ_ISR_ICU0_1    (Icu_Isr_Icu0Channel1)
#else
    #define PDL_IRQ_ISR_ICU0_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU0_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_ICU1 == PDL_ON)
    #define PDL_IRQ_ISR_ICU1_0    (Icu_Isr_Icu1Channel0)
    #define PDL_IRQ_ISR_ICU1_1    (Icu_Isr_Icu1Channel1)
#else
    #define PDL_IRQ_ISR_ICU1_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU1_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_ICU2 == PDL_ON)
    #define PDL_IRQ_ISR_ICU2_0    (Icu_Isr_Icu2Channel0)
    #define PDL_IRQ_ISR_ICU2_1    (Icu_Isr_Icu2Channel1)
#else
    #define PDL_IRQ_ISR_ICU2_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU2_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_ICU3 == PDL_ON)
    #define PDL_IRQ_ISR_ICU3_0    (Icu_Isr_Icu3Channel0)
    #define PDL_IRQ_ISR_ICU3_1    (Icu_Isr_Icu3Channel1)
#else
    #define PDL_IRQ_ISR_ICU3_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU3_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_ICU4 == PDL_ON)
    #define PDL_IRQ_ISR_ICU4_0    (Icu_Isr_Icu4Channel0)
    #define PDL_IRQ_ISR_ICU4_1    (Icu_Isr_Icu4Channel1)
#else
    #define PDL_IRQ_ISR_ICU4_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU4_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_ICU5 == PDL_ON)
    #define PDL_IRQ_ISR_ICU5_0    (Icu_Isr_Icu5Channel0)
    #define PDL_IRQ_ISR_ICU5_1    (Icu_Isr_Icu5Channel1)
#else
    #define PDL_IRQ_ISR_ICU5_0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
    #define PDL_IRQ_ISR_ICU5_1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

/** EIC **********************************************************************/
#if (PDL_PERIPHERAL_ENABLE_EIC0 == PDL_ON)
    #define PDL_IRQ_ISR_EIC0    (Eic_Isr_Eic0Channel0)
#else
    #define PDL_IRQ_ISR_EIC0    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC1 == PDL_ON)
    #define PDL_IRQ_ISR_EIC1    (Eic_Isr_Eic0Channel1)
#else
    #define PDL_IRQ_ISR_EIC1    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC2 == PDL_ON)
    #define PDL_IRQ_ISR_EIC2    (Eic_Isr_Eic0Channel2)
#else
    #define PDL_IRQ_ISR_EIC2    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC3 == PDL_ON)
    #define PDL_IRQ_ISR_EIC3    (Eic_Isr_Eic0Channel3)
#else
    #define PDL_IRQ_ISR_EIC3    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC4 == PDL_ON)
    #define PDL_IRQ_ISR_EIC4    (Eic_Isr_Eic0Channel4)
#else
    #define PDL_IRQ_ISR_EIC4    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC5 == PDL_ON)
    #define PDL_IRQ_ISR_EIC5    (Eic_Isr_Eic0Channel5)
#else
    #define PDL_IRQ_ISR_EIC5    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC6 == PDL_ON)
    #define PDL_IRQ_ISR_EIC6    (Eic_Isr_Eic0Channel6)
#else
    #define PDL_IRQ_ISR_EIC6    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC7 == PDL_ON)
    #define PDL_IRQ_ISR_EIC7    (Eic_Isr_Eic0Channel7)
#else
    #define PDL_IRQ_ISR_EIC7    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC8 == PDL_ON)
    #define PDL_IRQ_ISR_EIC8    (Eic_Isr_Eic0Channel8)
#else
    #define PDL_IRQ_ISR_EIC8    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC9 == PDL_ON)
    #define PDL_IRQ_ISR_EIC9    (Eic_Isr_Eic0Channel9)
#else
    #define PDL_IRQ_ISR_EIC9    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC10 == PDL_ON)
    #define PDL_IRQ_ISR_EIC10    (Eic_Isr_Eic0Channel10)
#else
    #define PDL_IRQ_ISR_EIC10    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC11 == PDL_ON)
    #define PDL_IRQ_ISR_EIC11    (Eic_Isr_Eic0Channel11)
#else
    #define PDL_IRQ_ISR_EIC11    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC12 == PDL_ON)
    #define PDL_IRQ_ISR_EIC12    (Eic_Isr_Eic0Channel12)
#else
    #define PDL_IRQ_ISR_EIC12    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC13 == PDL_ON)
    #define PDL_IRQ_ISR_EIC13    (Eic_Isr_Eic0Channel13)
#else
    #define PDL_IRQ_ISR_EIC13    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC14 == PDL_ON)
    #define PDL_IRQ_ISR_EIC14    (Eic_Isr_Eic0Channel14)
#else
    #define PDL_IRQ_ISR_EIC14    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif

#if (PDL_PERIPHERAL_ENABLE_EIC15 == PDL_ON)
    #define PDL_IRQ_ISR_EIC15    (Eic_Isr_Eic0Channel15)
#else
    #define PDL_IRQ_ISR_EIC15    (INTERRUPTS_IRQ_DEFAULT_HANDLER)
#endif






/**
 *****************************************************************************
 ** \defgroup PDLMacroGroup General PDL macros
 ** \brief This section describes the interface for the PDL General macros
 **
 ** Provided functions of General PDL macros:
 **
 ** - PDL_WRITE_REG_SYNC()
 ** - PDL_SAFELY_DISABLE_INTERRUPT()
 ** 
 ** For more detail, see PDL_WRITE_REG_SYNC(), PDL_SAFELY_DISABLE_INTERRUPT()
 ** sections.
 *****************************************************************************/
/*@{ */

/**
 *****************************************************************************
 ** Including mechanism to synchronously write the register,
 ** including all latency time of bus bridges.
 ** This is ensured by reading back the register which will force the CPU to
 ** wait until the write/read-back operation is completed. Reading an address
 ** on the same bus as written before, will stall the CPU until all pending
 ** write operations in CPU write buffer to strictly ordered memory areas like
 ** I/O registers are completed.
 **
 ** This macro should be used to ensure a safe clearing of interrupt flags
 ** before returning from the ISR, to prevent ISR double execution in case of
 ** not-yet-cleared interrupt flags in a peripheral.
 **
 ** Typically the appropriate clear register is used to clear the
 ** interrupt status flag of a peripheral.
 **
 ** See Cortex-R5 TRM Appendix-D D.1 Memory ordering
 **
 *****************************************************************************/
#define PDL_WRITE_REG_SYNC(Register, val)   \
        {                                   \
            Register = val;                 \
            Register;                       \
            DMB();                          \
        }

/**
 *****************************************************************************
 ** Macro for synchronously disabling an interrupt of a peripheral
 ** including all latency time of bus bridges, interrupt status
 ** signal to the Interrupt Controller and interrupt priority evaluation.
 ** This macro should be used to ensure a safe, interrupt protected
 ** code execution after execution of this macro.
 **
 ** Typically the appropriate clear register is used to clear the
 ** interrupt enable flag of a peripheral.
 *****************************************************************************/
#define PDL_SAFELY_DISABLE_INTERRUPT(Register, val)     \
        {                                               \
            Register = val;                             \
            Register;                                   \
            NOP(); NOP(); NOP(); NOP(); NOP(); NOP();   \
        }

/*@} */


/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes                                                */
/*****************************************************************************/

/**
 ******************************************************************************
 ** This hook is part of wait loops.
 ******************************************************************************/
extern void Pdl_WaitLoopHook(void) ;

#ifdef __cplusplus
}
#endif

#endif /* __PDL_H__ */
