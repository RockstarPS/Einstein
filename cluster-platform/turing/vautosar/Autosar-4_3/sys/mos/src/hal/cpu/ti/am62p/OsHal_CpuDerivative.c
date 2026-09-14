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
**   Compiler Name    :                                                          **
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

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/* Private functions */
static void TimerWaitPendingStateCheck(osuint32 MaskValue);

void osHalPrv_SetArmExceptions(void)
{
    /* Setup ARM Exceptions */
    osEXCFG_UNDEFINACT  = (osuint32)(osExceptionTable[1]);  /* Undefined */
    osEXCFG_SVCINACT    = (osuint32)(osExceptionTable[2]);  /* Supervisor */
    osEXCFG_PABORTINACT = (osuint32)(osExceptionTable[3]);  /* Prefetch Abort */ 
    osEXCFG_DABORTINACT = (osuint32)(osExceptionTable[4]);  /* Data Abort */ 
}

void osHalPrv_SetupIRQAndFIQ(void)
{
    osuint32 i;
    /* Setup all IRQs */
    for (i=0; i<osdNumberOfIRQs; i++)
    {
        osVIM_INT_VEC(i)       = (osuint32)osIRQTable[i] & 0xFFFFFFFCU;
    }

    for (i=0; i<osdNumberOfConfiguredIRQs; i++)
    {
        /* Set IRQPL register according to the configuration (i.e. osIRQPrioTable) */
        osVIM_INT_PRI(osIRQPrioTable[i].osIPNumber) = (osIRQPrioTable[i].osIPLevel & 0xF);
    }

    for(i=0; i<(256/32); i++)
    {
        /* disable all interrupts */
        osVIM_INT_DIS(i*32) = 0xFFFFFFFFu;

        /* clear all pending interrupts */
        osVIM_STS(i*32) = 0xFFFFFFFFu;

        /* make all as level */
        osVIM_INT_TYPE(i*32) = 0x0u;

        /* make all as IRQ */
        osVIM_INT_MAP(i*32) = 0x0u;
    }
      
    osuint32 RetVal = 0;
    RetVal = osVIM_IRQVECADDR;
    RetVal = osVIM_FIQVECADDR;
    (void)RetVal;
    /*ACK IRQ*/
    osVIM_IRQVECADDR = 0;
    osVIM_FIQVECADDR = 0;
    
#if 0
    /* Setup all FIQs/NMIs */         
    for (i=0; i<osdNumberOfFIQs; i++)
    {
        if (osFIQTable[i]!=0)
        {
            osIRQ0_NMIVA(i)       = (osuint32)osFIQTable[i]; 
        }
    }

    /* Setup FIQs/NMIs prios and enable the FIQs/NMIs */
    #if osdNumberOfConfiguredFIQs>0
    for (i=0; i<osdNumberOfConfiguredFIQs; i++)
    {
        /* Set NMIPL register according to the configuration (i.e. osFIQPrioTable) */
        osIRQ0_NMIPL(osFIQPrioTable[i].osIPNumber) = osFIQPrioTable[i].osIPLevel;
    }
    #endif

#endif
    /* Setup core to use Low exception vectors and VIC */
    osSetBitsARMCoreSCTLR(0x01000000);  /* 'VE' = 1 == enable VIC; 'V' = 0 == Low vector*/

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
	StatusType Status = E_NOT_OK;
    volatile osuint32 *addr;
    osuint32 bitPos;
    osuint16 IrqNum = 0;

    if (ISRID < (ISRType)OsNumberOfIsr)
    {
        IrqNum = osIRQPrioTable[ISRID].osIPNumber;
    	if(FALSE != ClearPending)
    	{
    		addr = &osVIM_STS(IrqNum);
            bitPos = osVIM_BIT_POS(IrqNum);
            *addr = ((osuint32)0x1u << bitPos);
    	}
    	OS_HAL_COMPILER_BARRIER();
        
        addr = &osVIM_INT_EN(IrqNum);
        bitPos = osVIM_BIT_POS(IrqNum);
        *addr = ((osuint32)0x1u << bitPos);
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
StatusType OsHal_DisableInterruptSource(ISRType ISRID)
{
    StatusType Status = E_NOT_OK;
    volatile osuint32 *addr;
    osuint32 bitPos;
    osuint16 IrqNum = 0;

    if (ISRID < (ISRType)OsNumberOfIsr)
    {
        IrqNum = osIRQPrioTable[ISRID].osIPNumber;
    	addr = &osVIM_INT_DIS(IrqNum);
        bitPos = osVIM_BIT_POS(IrqNum);
        *addr = ((osuint32)0x1 << bitPos);
        OS_HAL_COMPILER_BARRIER();
    	Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief Service TimerWaitPendingStateCheck
 * @note  Service to check timer wait pending state register
 * @param void
 * @return void
 */
static void TimerWaitPendingStateCheck(osuint32 MaskValue)
{
    /* Var to check timer wait pending state register */
    volatile osuint32 *twps_reg = (volatile osuint32 *)(osMCU_TIMER + osMCU_TWPS);
    while((*twps_reg & MaskValue) == MaskValue)
    {
        /* wait */
    }
}

/**
 * @brief Service osStartArchTimer
 * @note  Start Timer
 * @param void
 * @return void
 */
void osStartArchTimer (void)
{
    volatile osuint32 *addr;
    /*Stop Timer*/
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_TCLR);
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);
    *addr &= ~(0x1U << 0U);
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);

    /*Clear Overflow Interrupt*/
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_IRQ_STATUS);
    *addr = (0x1U << 0x1U);
    /*read back and make sure interrupt was indeed cleared, if not clear it again*/
    if(*addr & (0x1U << 0x1U))
    {
        *addr = (0x1U << 0x1U);
    }

    /* set timer control value */
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_TCLR);
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);
    *addr = 2U;
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);

    /* set timer count value */
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_TCRR);
    TimerWaitPendingStateCheck(TIMER_TCRR_PEND_MASK);
    *addr = osdReloadValue;
    TimerWaitPendingStateCheck(TIMER_TCRR_PEND_MASK);

    /* set reload value */
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_TLDR);
    TimerWaitPendingStateCheck(TIMER_TLDR_PEND_MASK);
    *addr = osdReloadValue; /*1ms reload value*/
    TimerWaitPendingStateCheck(TIMER_TLDR_PEND_MASK);
    
    /* enable interrupt */
    addr = (volatile osuint32 *)(osMCU_TIMER + osMCU_IRQ_INT_ENABLE);
    *addr = (0x1U << 0x1U);

    /* start timer */
    addr = (osuint32 *)(osMCU_TIMER + osMCU_TCLR);
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);
    *addr |= (0x1U << 0U);
    TimerWaitPendingStateCheck(TIMER_TCLR_PEND_MASK);
}

/**
 * @brief Service OsHal_CheckIntrPending
 * @note  Check Pending Timer Exception
 * @param void
 * @return void
 */
void OsHal_CheckIntrPending (void)
{
    /* Read Interrupt Status */
    volatile osuint32 TimerIntrStatus = (*((volatile osuint32 *)(osMCU_TIMER + osMCU_IRQ_STATUS)));
    /* Check if Peripheral Timer Interrupt Bit is Set */
    if((TimerIntrStatus & OS_HAL_OVRFLW_BIT_MASK) == OS_HAL_OVRFLW_BIT_MASK)
    {
        /* If timer Interrupt is pending before exit, OS is Overloaded */
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
