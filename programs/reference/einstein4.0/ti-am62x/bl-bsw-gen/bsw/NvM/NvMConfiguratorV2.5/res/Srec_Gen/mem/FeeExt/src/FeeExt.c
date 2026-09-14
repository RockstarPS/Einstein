/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2022. Visteon Corporation owns all rights to           *
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
#ifndef FEEEXT_C
#define FEEEXT_C
/*****************************************************************************
*  File Name         :  FeeExt.c                                             *
*  Module Short Name :  FeeExt                                               *
*  Description       :                                                       *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Traveo II                                              *
*                                                                            *
******************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Fls.h"
#include "FeeExt.h"

/*****************************************************************************
 *  Private Macros Definitions                                                **
 ******************************************************************************/
#define FEE_EXT_MAX_32BIT_VALUE               0xFFFFFFFF

/**********************************************************************************************************************
 * TYPE DEFINITIONS
 *********************************************************************************************************************/
typedef enum
{
    FEE_EXT_TIMER_IDLE = 0U,
    FEE_EXT_TIMER_STARTED,
    FEE_EXT_TIMER_STOPPED,
    FEE_EXT_TIMER_ELAPSED,
} FeeExt_TimerStatusType;

typedef struct
{
    TickType                  StartTime;
    TickType                  EndTime;
    FeeExt_TimerStatusType    Status;
} FeeExt_TimerType;

/**********************************************************************************************************************
 * GLOBAL DECLARATIONS
 *********************************************************************************************************************/
static FeeExt_TimerType FeeExt_Timer;

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/
static void FeeExt_Timeout_Start(void);
static void FeeExt_Timeout_Check(void);


/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/**
 * This method is the init function of FeeExt module
 * @param     none
 * @return    void
 */
void FeeExt_Init(void)
{
    FeeExt_Timer.StartTime = 0U;
    FeeExt_Timer.EndTime = 0U;
    FeeExt_Timer.Status = FEE_EXT_TIMER_IDLE;
    Fls_SetCycleMode(MEMIF_MODE_FAST);
}

/**
 * This method provides the Fls erase functionality through FeeExt module with timeout condition
 * @param     uint32 TargetAddress, uint32 Length
 * @return    Std_ReturnType
 */
Std_ReturnType FeeExt_Erase (uint32 TargetAddress, uint32 Length)
{
    Std_ReturnType fl_return = E_NOT_OK;
    fl_return = Fls_Erase(TargetAddress, Length);
    if(E_OK == fl_return)
    {
        FeeExt_Timeout_Start();
    }
    return fl_return;
}


/**
 * This method provides the Fls write functionality through FeeExt module with timeout condition
 * @param     uint32 TargetAddress, uint8* SourceAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
Std_ReturnType FeeExt_Write (uint32 TargetAddress, uint8* SourceAddressPtr, uint32 Length)
{
    Std_ReturnType fl_return = E_NOT_OK;
    fl_return = Fls_Write(TargetAddress, SourceAddressPtr, Length);
    if(E_OK == fl_return)
    {
        FeeExt_Timeout_Start();
    }
    return fl_return;
}

/**
 * This method provides the Fls cancel functionality through FeeExt module
 * @param     none
 * @return    void
 */
void FeeExt_Cancel(void)
{
    FeeExt_Timer.Status = FEE_EXT_TIMER_STOPPED;
    Fls_Cancel();
}


/**
 * This method provides the Fls Get Status functionality through FeeExt module and returns the status
 * @param     void
 * @return    MemIf_StatusType
 */
MemIf_StatusType FeeExt_GetStatus(void)
{
    MemIf_StatusType ReturnStatus = MEMIF_IDLE;
    ReturnStatus = Fls_GetStatus();
    return ReturnStatus;
}

/**
 * This method provides the Fls Get Job Result status through FeeExt module
   Also checks for timeout elapsed and triggers FLs_Cancel
 * @param     void
 * @return    MemIf_JobResultType
 */
MemIf_JobResultType FeeExt_GetJobResult(void)
{
    MemIf_JobResultType ReturnValue;
    ReturnValue = Fls_GetJobResult();
    if(MEMIF_JOB_PENDING == ReturnValue)
    {
        FeeExt_Timeout_Check();
        if(FEE_EXT_TIMER_ELAPSED == FeeExt_Timer.Status)
        {
            FeeExt_Cancel();
            ReturnValue = MEMIF_JOB_FAILED;
        }
    }
    else
    {
        /*FeeExt_Timer.Status = FEE_EXT_TIMER_STOPPED;*/
    }
    return ReturnValue;
}

/**
 * This method provides the Fls read functionality through FeeExt module with timeout condition
 * @param     uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
Std_ReturnType FeeExt_Read (uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length)
{
    Std_ReturnType fl_return = E_NOT_OK;
    fl_return = Fls_Read(SourceAddress, TargetAddressPtr, Length);
    if(E_OK == fl_return)
    {
        FeeExt_Timeout_Start();
    }
    return fl_return;
}

/**
 * This method provides the Fls read immediate functionality through FeeExt module with timeout condition
 * @param     uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
Std_ReturnType FeeExt_ReadImmediate (uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length)
{
    Std_ReturnType fl_return = E_NOT_OK;
    fl_return = Fls_ReadImmediate(SourceAddress, TargetAddressPtr, Length);
    if(E_OK == fl_return)
    {
        FeeExt_Timeout_Start();
    }
    return fl_return;
}

/**
 * This method provides the Fls read immediate functionality through FeeExt module with timeout condition
 * @param     uint32 SourceAddress, uint8* TargetAddressPtr, uint32 Length
 * @return    Std_ReturnType
 */
Std_ReturnType FeeExt_BlankCheck (uint32 TargetAddress, uint32 Length)
{
    Std_ReturnType fl_return = E_NOT_OK;
    fl_return = Fls_BlankCheck(TargetAddress, Length);
    if(E_OK == fl_return)
    {
        FeeExt_Timeout_Start();
    }
    return fl_return;
}

/**
 * This method gives Start time counter value and provide corresponding status
 * @param     none
 * @return    void
 */
static void FeeExt_Timeout_Start(void)
{
    FEE_EXT_GET_SYSTEM_TIMER(&FeeExt_Timer.StartTime);
    FeeExt_Timer.Status = FEE_EXT_TIMER_STARTED;
}


/**
 * This method checks for the timeout difference between start and end time and provides corresponding status
 * @param     none
 * @return    void
 */
static void FeeExt_Timeout_Check(void)
{
    TickType Delay = 0;

    if(FEE_EXT_TIMER_STARTED == FeeExt_Timer.Status)
    {
        FEE_EXT_GET_SYSTEM_TIMER(&FeeExt_Timer.EndTime);

        if(FeeExt_Timer.EndTime >= FeeExt_Timer.StartTime)
        {
            Delay = ( FeeExt_Timer.EndTime - FeeExt_Timer.StartTime );
        }
        else
        {
            Delay = (FeeExt_Timer.EndTime + (FEE_EXT_MAX_32BIT_VALUE - FeeExt_Timer.StartTime) );
        }

        if(Delay >= FEE_EXT_TIMEOUT_VALUE)
        {
            FeeExt_Timer.Status = FEE_EXT_TIMER_ELAPSED;
        }
    }
}


#endif /*FEEEXT_C*/

/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 26-Jun-2022
CDSID              : nchellap
Traceability       :
Change Description : Initial version of FeeExt
-----------------------------------------------------------------------------*/


