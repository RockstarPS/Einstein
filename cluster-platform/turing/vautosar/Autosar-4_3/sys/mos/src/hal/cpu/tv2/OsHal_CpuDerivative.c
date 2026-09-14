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
**    File Name         :  OsHal_CpuDerivative.c                                 **
**    Module Short Name :  OsHal_CpuDerivative                                   **
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
#ifndef OS_HAL_PROCESSOR
#define OS_HAL_PROCESSOR

/************************************* Includes **********************************/
#include "OsMain.h"
#include "OsPrivate.h"
#include "OsInternal.h"
#include "OsHal_CpuDerivative.h"
#include "OsHal_CpuDerivative_Int.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"
/*MISRA RULE 4.8 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 20.1 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
/*MISRA RULE 10.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

static void OsHalPrv_EnableIRQ (const osIntIrqChn_t * const pThisIrqParam);

/**
 * @brief Service OsHalPrv_osInitSystemInterruptPriority
 * @note  Initializing the interrupt priority
 * @param void
 * @return void
 */
void OsHalPrv_osInitSystemInterruptPriority (void)
{
    OS_INT_NVIC_SHPR1_REG = osdIntCfgNvicSHPRI1;
    OS_INT_NVIC_SHPR2_REG = osdIntCfgNvicSHPRI2;
    OS_INT_NVIC_SHPR3_REG = osdIntCfgNvicSHPRI3;
}

/**
 * @brief Service OsHalPrv_EnableIRQ
 * @note  Enable IRQ
 * @param pThisIrqParam
 * @return void
 */
static void OsHalPrv_EnableIRQ (const osIntIrqChn_t * const pThisIrqParam)
{
    /* This SysIntIx NVIC might be enabled if there are more than one system interrupts mapped
     * to the same Index
     * NVIC_GetEnableIRQ returns 1 if Interrupt is enabled already
     * NVIC_GetEnableIRQ returns 0 if Interrupt is disabled */
	if(0U == NVIC_GetEnableIRQ((IRQn_Type)pThisIrqParam->SysIntIx))
    {
        /* Set priority to interrupt */
        NVIC_SetPriority((IRQn_Type)pThisIrqParam->SysIntIx, pThisIrqParam->osPrioLevel);
        /* Enable interrupt */
        NVIC_ClearPendingIRQ((IRQn_Type)pThisIrqParam->SysIntIx);
    #ifdef MOS_INTERNAL_VECTOR_WRITE
        /* register interrupt handler */
        //todo: this api needs re-design if this section is enabled
        NVIC_RegisterIsrHandler_basic(pThisIrqParam->osIrqNum,(uint32)pThisIrqParam->pIsr);
    #endif
        /* Enable interrupt */
        NVIC_EnableIRQ((IRQn_Type)pThisIrqParam->SysIntIx);
    }
}


/**
 * @brief Service OsInt_SetupInterrupt
 * @note  Setup IRQ
 * @param pThisIrqParam
 * @return void
 */
void OsInt_SetupInterrupt (const osIntIrqChn_t * const pThisIrqParam)
{
    /* This service will be called by intvect only if the Interrupt is
     * NOT ARM Core Interrupts! */

    /* Enable the Peripheral Interrupt and assign the CPU mapped Interrupt */
    osHal_EnableIRQSteer(pThisIrqParam);
    //convert the Shared Peripheral Interrupt to M4_EXT_INTRx

    /*Finally enable external interrupts in M7 NVIC*/
    OsHalPrv_EnableIRQ(pThisIrqParam);

}

/**
 * @brief Service OsHal_EnableInterruptSource
 * @note  Enable InterruptSource
 * @param ISRID
 * @param ClearPending
 * @return StatusType
 */
StatusType OsHal_EnableInterruptSource(ISRType ISRID, boolean ClearPending)
{
    OsIrqConfigInfoType *pThisIsr = OsIntVect_GetIsrConfig(ISRID); /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    StatusType Status = E_NOT_OK;
    if (ISRID < OsNumberOfIsr)
    {
        if (pThisIsr->SysMapIrqId != osIntvUserCpuIrqInvalid)
        {
            OsHalPrv_EnableIrqSource(pThisIsr->IrqId);
        }

        if (0U == NVIC_GetEnableIRQ((IRQn_Type)pThisIsr->SysMapIrqId))
        {

            if (ClearPending != FALSE)
            {
                NVIC_ClearPendingIRQ((IRQn_Type)pThisIsr->SysMapIrqId);
            }

            /* Set priority to interrupt */
            NVIC_SetPriority((IRQn_Type)pThisIsr->SysMapIrqId,pThisIsr->PrioLevel);

            NVIC_EnableIRQ((IRQn_Type)pThisIsr->SysMapIrqId);
         }

         Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief Service OsHal_DisableInterruptSource
 * @note  Disable InterruptSource
 * @param ISRID
 * @return StatusType
 */
StatusType OsHal_DisableInterruptSource (ISRType ISRID)
{
    OsIrqConfigInfoType *pThisIsr = OsIntVect_GetIsrConfig(ISRID); /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    StatusType Status = E_NOT_OK;
    if (ISRID < OsNumberOfIsr)
    {
        if(pThisIsr->SysMapIrqId != osIntvUserCpuIrqInvalid)
        {
            OsHalPrv_DisableIrqSource(pThisIsr->IrqId);
        }
        else
        {
            //This is not an interrupt mapped to System ISRID
            //Disable this in the NVIC
            NVIC_ClearPendingIRQ((IRQn_Type)pThisIsr->IrqId);
            /* Enable interrupt */
            NVIC_DisableIRQ((IRQn_Type)pThisIsr->IrqId);

        }
        Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief Service osStartArchTimer
 * @note  Start Timer
 * @param void
 * @return void
 */
void osStartArchTimer (void)
{
/* ssebast1; System Timer Enabling */
    osSYST_RVR = osdReloadValue;
    osSYST_CSR = 0x00000007; //CLKSOURCE=Core clock; TICKINT = Asserts SysTick exception; Counter=ENABLE
}

/**
 * @brief Service OsHal_CheckIntrPending
 * @note  Check Pending Timer Exception
 * @param void
 * @return void
 */
void OsHal_CheckIntrPending (void)
{
    /* Check if Systick Pending Bit is Set */
    if((OS_HAL_ICSR_ADDR & OS_HAL_ICSR_PENDSTSET_BIT) == OS_HAL_ICSR_PENDSTSET_BIT)
    {
        /* If Systick timer is pending before exit, OS is Overloaded */
        OsErr_osApplicationErrorHook(OsDlt_OsTickTimer, NULL_PTR , E_OS_OVERLOAD);
    }
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
