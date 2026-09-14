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
**   Compiler Name    :                                                          **
**   Target Hardware  :  R5F ARM Core based CPU                                  **
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

osuint32 osPrvLastLR = 0x0;

/**
 * @brief Service osIntArchInitialize
 * @note  Initializing the interrupt
 * @param void
 * @return void
 */
void osIntArchInitialize (void)
{
    osSetupExceptionStacks(); /* Setup all ARM stacks except user mode stack and system mode stack */
    osHalPrv_SetArmExceptions();
    osHalPrv_SetupIRQAndFIQ();
}

/**
 * @brief Service osSetupAndEnableConfiguredInterrupts
 * @note  Setup and Enable Interrupts
 * @param void
 * @return void
 */
void osSetupAndEnableConfiguredInterrupts (void)
{
    osEnableNMIandAborts();
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
**   Date              : 15-Oct-2023                                                **
**   CDSID             : nchellap                                                   **
**   JIRA Id           :                                                     **
**   Change Description: Initial release for Cpu derivative common for Cortex R     **
**----------------------------------------------------------------------------------**/
