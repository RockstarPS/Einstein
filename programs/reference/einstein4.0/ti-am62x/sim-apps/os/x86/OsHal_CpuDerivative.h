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

typedef struct
{
    osuint32 osIrqNum;
    osuint32 SysIntIx;
    osIntLevelType osPrioLevel;
    osVoidFunctionType pIsr;
}osIntIrqChn_t;

#define osSYST_BASE        (*((volatile osuint32*)(0xE000E010))) /* System Timer Register Base Address */
#define osSYST_CSR         (*((volatile osuint32*)(0xE000E010))) /* System Timer Control & Status Register Address */
#define osSYST_RVR         (*((volatile osuint32*)(0xE000E014))) /* System Timer Reload Value Register Address */
#define osSYST_CVR         (*((volatile osuint32*)(0xE000E018))) /* System Timer Current Value Register Address */
#define osSYST_CALIB       (*((volatile osuint32*)(0xE000E01C))) /* System Timer Calibration Value Register Address */

#define OS_INT_NVIC_SHPR1_REG                   ( * ( ( volatile osuint32 * ) 0xe000e018 ) )
#define OS_INT_NVIC_SHPR2_REG                   ( * ( ( volatile osuint32 * ) 0xe000e01C ) )
#define OS_INT_NVIC_SHPR3_REG                   ( * ( ( volatile osuint32 * ) 0xe000ed20 ) )

#define osVIM_IRQVECADDR        (*((volatile osuint32*)(0x10000000)))


#define osdIntCfgNvicSHPRI1                     0UL
#define osdIntCfgNvicSHPRI2                     0UL
#define osdIntCfgNvicSHPRI3                     (osdIntCfgKernelPriority << 24UL)

#define osdIntCfgKernelPriority                 0x80UL

#define osdIntCfgMaxSystemPriority              0x20UL

#define osIntIsrCallHook()

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

