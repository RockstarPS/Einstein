/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  OsHal_CpuDerivative.h                                *
*  Module Short Name :  OsHal_CpuDerivative                                  *
*  Description       :  Internal header which has cpu specific definitions   *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  INDEPENDENT                                            *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef OS_HAL_PROCESSOR_H
#define OS_HAL_PROCESSOR_H

#include "OsTypes.h"

/* Added for TI AM62Px Micro VIM configuration */
#define osVIM_BASE              0x07FF0000UL
#define osVIM_IRQVEC            (0x18u)
#define osVIM_FIQVEC            (0x1Cu)
#define osVIM_ACTIRQ            (0x20u)
#define osVIM_ACTFIQ            (0x24u)
#define osVIM_INT_VEC(x)        (*((volatile osuint32*)(osVIM_BASE + (0x2000u + ((x) * 0x4u)))))
#define osVIM_INT_PRI(x)        (*((volatile osuint32*)(osVIM_BASE + (0x1000u + ((x) * 0x4u)))))
#define osVIM_INT_EN(x)         (*((volatile osuint32*)(osVIM_BASE + (0x408u + (((x)>>5) & 0xFu) * 0x20u))))
#define osVIM_BIT_POS(x)        ( (x) & 0x1Fu )
#define osVIM_INT_DIS(x)        (*((volatile osuint32*)(osVIM_BASE + (0x40Cu + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_STS(x)            (*(volatile osuint32*)(osVIM_BASE + (0x404u + (((x)>> 5) & 0xFu) * 0x20u)))
#define osVIM_INT_TYPE(x)       (*((volatile osuint32*)(osVIM_BASE + (0x41Cu + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_INT_MAP(x)        (*((volatile osuint32*)(osVIM_BASE + (0x418u + (((x)>> 5) & 0xFu) * 0x20u))))
#define osVIM_IRQVECADDR        (*((volatile osuint32*)(osVIM_BASE + (osVIM_IRQVEC))))
#define osVIM_FIQVECADDR        (*((volatile osuint32*)(osVIM_BASE + (osVIM_FIQVEC))))
#define osVIM_ACTIRQADDR        (volatile osuint32*)(osVIM_BASE + (osVIM_IRQVEC))
#define osVIM_GET_STSHWADDR(x)  (volatile osuint32*)(osVIM_BASE + (0x404u + (((x)>> 5) & 0xFu) * 0x20u))

/* Added for TI AM62Px Micro TIMER configuration */
#define osMCU_IRQ_EOI           (0x20u)
#define osMCU_IRQ_STATUS_RAW    (0x24u)
#define osMCU_IRQ_STATUS        (0x28u)
#define osMCU_IRQ_INT_ENABLE    (0x2Cu)
#define osMCU_IRQ_INT_DISABLE   (0x30u)
#define osMCU_TCLR              (0x38u)
#define osMCU_TCRR              (0x3cu)
#define osMCU_TLDR              (0x40u)
#define osMCU_TWPS              (0x48u)
#define TIMER_TCLR_PEND_MASK    (0x01u)
#define TIMER_TCRR_PEND_MASK    (0x02u)
#define TIMER_TLDR_PEND_MASK    (0x04u)

/* Added for TI AM62Px Micro */
#define osEXCFG_BASE            0x00000000
#define osEXCFG_UNDEFINACT      (*((volatile osuint32*)(osEXCFG_BASE+0x00000024UL)))
#define osEXCFG_SVCINACT        (*((volatile osuint32*)(osEXCFG_BASE+0x00000028UL)))
#define osEXCFG_PABORTINACT     (*((volatile osuint32*)(osEXCFG_BASE+0x0000002CUL)))
#define osEXCFG_DABORTINACT     (*((volatile osuint32*)(osEXCFG_BASE+0x00000030UL)))

/* MCU Timer Base address for TI AM62P */
#define MCU_TIMER0_BASEADDR 0x4800000U
#define MCU_TIMER1_BASEADDR 0x4810000U
#define MCU_TIMER2_BASEADDR 0x4820000U
#define MCU_TIMER3_BASEADDR 0x4830000U

#define OS_HAL_OVRFLW_BIT_MASK    0x02U

#define osIntIsrCallHook()  (*((volatile osuint32 *)(osMCU_TIMER + osMCU_IRQ_STATUS))) |= (0x1 << 0x1); /* acknowledge the interrupt */

#define OsHal_CpuStartOS(x)                     __asm ("ldr        r0,=osStartOSasmArm "); \
                                                __asm ("bx         r0                  "); \

/* Os APIs for Enable Interrupt Source */
extern StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending);
/* Os APIs for Disable Interrupt Source */
extern StatusType OsHal_DisableInterruptSource(ISRType ISRID);

extern void osSetupExceptionStacks(void); /* Setup all ARM stacks except user mode stack and system mode stack */
extern void osHalPrv_SetArmExceptions(void);
extern void osHalPrv_SetupIRQAndFIQ(void);

extern void osStartArchTimer (void);
extern void osIntArchInitialize (void);
extern void osSetupAndEnableConfiguredInterrupts (void);
extern osuint32 osGetCPSR(void);
extern void osSetBitsARMCoreSCTLR(osuint32 BitsToSet);
extern void osEnableNMIandAborts(void);
extern void OsHal_CheckIntrPending(void);

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**   ------------------------------------------------------------------------------ **
**   Date              : 27-Jul-2022                                                **
**   CDSID             : rsivaku4                                                   **
**   RTC Id            : 1709142                                                    **
**   Change Description: MPU nesting prevention and Moving Internal.c to HAL        **
**----------------------------------------------------------------------------------**/

