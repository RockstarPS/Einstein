/*-------------------------------------------------------------------------------**
**  ***************************************************************************  **
**                                                                               **
**                CONFIDENTIAL VISTEON CORPORATION                               **
**                                                                               **
**   This is an unpublished work of authorship, which contains trade             **
**   secrets, created in 2013. Visteon Corporation owns all rights to            **
**   this work and intends to maintain it in confidence to preserve              **
**   its trade secret status. Visteon Corporation reserves the right,            **
**   under the copyright laws of the United States or those of any               **
**   other country that may have jurisdiction, to protect this work              **
**   as an unpublished work, in the event of an inadvertent or                   **
**   deliberate unauthorized publication. Visteon Corporation also               **
**   reserves its rights under all copyright laws to protect this                **
**   work as a published work, when appropriate. Those having access             **
**   to this work may not copy it, use it, modify it or disclose the             **
**   information contained in it without the written authorization               **
**   of Visteon Corporation.                                                     **
**                                                                               **
**  ***************************************************************************  **
**  ***************************************************************************  **
**    File Name         :  OsHal_CpuDerivative_Common.c                          **
**    Module Short Name :  OsHal_CpuDerivative_Common                            **
**    Description       :  This file contains the implementation for the         **
**                         architecture specific handling supporting the         **
**                         supporting the operating system                       **
**                                                                               **
**   Organization     :  Driver Information Software Section,                    **
**                       Visteon Software Operation                              **
**                       Visteon Corporation                                     **
**                                                                               **
**   --------------------------------------------------------------------------  **
**   Compiler Name    :  GHS                                                     **
**   Target Hardware  :  ARM Core based CPU                                      **
**                                                                               **
**  ***************************************************************************  **
**-------------------------------------------------------------------------------*/
#ifndef OS_HAL_COMMON
#define OS_HAL_COMMON

/************************************* Includes **********************************/
#include "OsPrivate.h"
#include "OsInternal.h"
#include "OsHal_CpuDerivative_Common.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"
/*MISRA RULE 4.8 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 12.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 10.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 20.1 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

osuint32 osPrvLastLR = 0x0;

static void OsHalPrv_osSetupVTOR (const osVoidFunctionType * VectorTable);
static void OsHalPrv_osSetupFpu(void);

/**
 * @brief Service osIntArchInitialize
 * @note  Initializing the interrupt
 * @param void
 * @return void
 */
void osIntArchInitialize (void)
{
    OsHalPrv_osInitSystemInterruptPriority();
    OsHalPrv_osSetupVTOR(osIRQTable);    
    OsHalPrv_osSetupFpu();
}

/**
 * @brief Service OsHalPrv_osSetupFpu
 * @note  Initializing the fpu
 * @param void
 * @return void
 */
static void OsHalPrv_osSetupFpu(void)
{
    #if OS_INTERNAL_FPU_ENABLED
    //Disable Lazy Stacking of FPU
    //We will stack FPU registers during context switch
    FPU->FPCCR &= ~(FPU_FPCCR_LSPEN_Msk);
    //Enable FPU in CoProcessor Registers
    SCB->CPACR |= (0xFU << 20U);
    #endif
}

/**
 * @brief Service OsHalPrv_osSetupVTOR
 * @note  Setup Vector table
 * @param VectorTable
 * @return void
 */
static void OsHalPrv_osSetupVTOR (const osVoidFunctionType * VectorTable)
{
    osuint32 VectorTableStartAddress = (osuint32)(VectorTable);

    //Set up VTOR Register to point to the Os Defined vector table
    OS_INT_INTC_SCB_VTOR = VectorTableStartAddress;
}

/**
 * @brief Service osSetupAndEnableConfiguredInterrupts
 * @note  Setup and Enable Interrupts
 * @param void
 * @return void
 */
void osSetupAndEnableConfiguredInterrupts (void)
{
   osSetupConfiguredInterrupts();
}

/**
 * @brief Service osISRUnhandledException
 * @note  osISRUnhandledException
 * @param void
 * @return void
 */
void osISRUnhandledException (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_SYS_ABORT);
}

/**
 * @brief Service osUnhandledException
 * @note  osUnhandledException
 * @param void
 * @return void
 */
void osUnhandledException (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_SYS_ABORT);
}

/**
 * @brief Service osMemProtectionFault
 * @note  osMemProtectionFault
 * @param void
 * @return void
 */
void osMemProtectionFault (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_STACKFAULT);
}

/**
 * @brief Service osDataAbortHandler
 * @note  osDataAbortHandler
 * @param void
 * @return void
 */
void osDataAbortHandler (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_SYS_ABORT);
}

/**
 * @brief Service osUndefinedInstructionException
 * @note  osUndefinedInstructionException
 * @param void
 * @return void
 */
void osUndefinedInstructionException (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_SYS_ABORT);
}


#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

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
