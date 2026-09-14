/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
#ifndef E2E_USERPROFILE_C
#define E2E_USERPROFILE_C
/*****************************************************************************
*  File Name         :  E2E_USERPROFILE_C		  	                         *
*  Module Short Name :  E2E_USERPROFILE_C		  	                         *
*  Description       :  This file contains E2E UserProfile Implementation    *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "E2E_UserProfile.h"
#include "Checksum.h"
#include "OsPrivate.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_E_ROLLINGCOUNTER_WRONG 0x6U
#define E2E_E_CHECKSUM_WRONG  0x7U

#define E2E_USERPROFILE8BITCHECKSUM_MAX_COUNTER_LIMIT    0x10U
#define CALIBRATION_WINDOW_OF_TIME                       10
#define COUNTER_OVERFLOW                                 0xFFFFFFFF

#define E2E_USER_PROF_INC_BY_1U                          1u
#define E2E_USER_PROF_MOD_BY_16U                         16u
#define E2E_USER_PROF_SHIFT_BY_3U                        3u
#define E2E_USER_PROF_VAL_1                              1
#define E2E_USER_PROF_VAL_4BIT                           0xFu
#define E2E_USER_PROF_VAL_8BIT                           0xFFu
#define E2E_USER_PROF_VAL_0x0fu                          0x0fu
#define E2E_USER_PROF_MAX_VAL_32BIT                      0xFFFFFFFF
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static void E2E_ProcessRollingCounter(const E2E_UserProfile8BitCheckSumConfigType* ConfigPtr, E2E_UserProfile8BitCheckSumCheckStateType* StatePtr, uint16 ReceivedCounter);
#define E2EUSERPROF_CODE_SEC_START
#include "MemMap.h"
#include "AssertLib.h"
/*============================================================================
**
** Function Name    :   E2E_ProcessRollingCounter
**
** Visibility       :   Private
**
** Description      :   Provides further checks with respect to Rolling Counter
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile4BitCheckSumConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_UserProfile4BitCheckSumCheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint16 ReceivedCounter - Received Counter value
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
static void E2E_ProcessRollingCounter(const E2E_UserProfile8BitCheckSumConfigType* ConfigPtr, E2E_UserProfile8BitCheckSumCheckStateType* StatePtr, uint16 ReceivedCounter)
{
    uint16 DeltaCounter = E2E_USER_PROF_VAL_1;
    (void)ConfigPtr;
    StatePtr->Status = E2E_USERPROFILE8BITCHECKSUMSTATUS_OK;
    DeltaCounter = (ReceivedCounter - StatePtr->Check_Timecounter);
    if (DeltaCounter == 0UL)
    {
        if (StatePtr->Cal_wind_Time < (uint8)CALIBRATION_WINDOW_OF_TIME)
        {
            if( StatePtr->Error_count < E2E_USER_PROF_MAX_VAL_32BIT )
            {
                StatePtr->Error_count++;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
            StatePtr->Cal_wind_Time++;
        }
    }
    else
    {
        StatePtr->Error_count = 0;
        StatePtr->Cal_wind_Time = 0;
    }

    if (StatePtr->Cal_wind_Time == (uint8)CALIBRATION_WINDOW_OF_TIME)
    {
        if (StatePtr->Error_count != 0UL)
        {
            StatePtr->Status = E2E_USERPROFILE8BITCHECKSUMSTATUS_ROLLING_COUNTER_LOCK;
        }
        else
        {
            StatePtr->Status = E2E_USERPROFILE8BITCHECKSUMSTATUS_OK;
        }
    }
}

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumProtect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E UserProfile.
**                      This includes checksum calculation and handling of alive counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_UserProfile8BitCheckSumProtectStateType * StatePtr - Pointer to ProtectState type.
**                      uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
Std_ReturnType E2E_ProtectUserProfile8BitCheckSumProtect(E2E_UserProfile8BitCheckSumConfigType* ConfigPtr, E2E_UserProfile8BitCheckSumProtectStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    uint8 ComputedChecksum = 0u;
    uint32 CRCOffset = 0u;
    uint32 fl_Timecounter = 0u;

    if((ConfigPtr != NULL)&&(StatePtr != NULL) && (DataPtr!=NULL))
    {
        if((Length != 0u))
        {
            CRCOffset = ConfigPtr->CounterOffset >> E2E_USER_PROF_SHIFT_BY_3U;

            /* Compute CheckSum over bytes that are before CRC*/
            ComputedChecksum = Checksum_CalculateCheckSum8(&DataPtr[0], (Length), E2E_USER_PROF_VAL_0x0fu, TRUE);

            /*copy 8 bit CheckSum onto Data*/
            DataPtr[CRCOffset] =  (uint8)(ComputedChecksum & E2E_USER_PROF_VAL_8BIT );
            /*Compute Rolling counter */
            /* 1. Read the time
               2. find the difference % 10ms
               3. added modules value to counter */

            (void)GetCounterValue(SystemTimer, &fl_Timecounter);
            if (StatePtr->InitValue != TRUE)
            {
                if (StatePtr->Protect_Timecounter < fl_Timecounter)
                {
                    StatePtr->Counter = (fl_Timecounter - StatePtr->Protect_Timecounter)%E2E_USER_PROF_MOD_BY_16U;
                }
                else
                {
                    StatePtr->Counter = ((COUNTER_OVERFLOW - (StatePtr->Protect_Timecounter)) + fl_Timecounter)%E2E_USER_PROF_MOD_BY_16U;
                }
            }
            StatePtr->Protect_Timecounter = fl_Timecounter;
            StatePtr->InitValue = FALSE;
            /*Copy the 4 bit of Rolling counter */
            DataPtr[CRCOffset+E2E_USER_PROF_INC_BY_1U]  = (StatePtr->Counter & E2E_USER_PROF_VAL_0x0fu);
            ret = E2E_E_OK;

        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
Std_ReturnType E2E_UserProfile8BitCheckSumProtectInit(E2E_UserProfile8BitCheckSumProtectStateType* StatePtr)
{
    Std_ReturnType ret = 0u;
    if (StatePtr != NULL)
    {
        StatePtr->Counter = 0u;
        StatePtr->Protect_Timecounter = 0u;
        StatePtr->InitValue = TRUE;
        ret = E2E_E_OK;
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumCheck
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E the E2E UserProfile.
**                      This includes checksum calculation and handling of alive counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_UserProfile8BitCheckSumCheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
Std_ReturnType E2E_CheckUserProfile8BitCheckSumCheck(E2E_UserProfile8BitCheckSumConfigType* ConfigPtr,E2E_UserProfile8BitCheckSumCheckStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint8 ReceivedCheckSum = 0u;
    uint8 ReceivedCounter = 0u;
    uint8 ComputedCheckSum = 0u;
    Std_ReturnType ret = 0u;
    uint32 ComputedOffset = 0u;

    if((ConfigPtr != NULL)&&(StatePtr != NULL) && (DataPtr != NULL))
    {
        if(Length != 0u)
        {
            ComputedOffset  = ConfigPtr->CounterOffset >> E2E_USER_PROF_SHIFT_BY_3U; /* Read the Counter from Data, at the configured offset*/
            ReceivedCheckSum = DataPtr[ComputedOffset];
            ReceivedCounter = (DataPtr[ComputedOffset+E2E_USER_PROF_INC_BY_1U]) ;
            if(E2E_USERPROFILE8BITCHECKSUM_MAX_COUNTER_LIMIT >= ReceivedCounter)
            {
                /* Compute CRC over bytes that are before CRC*/
                ComputedCheckSum = Checksum_CalculateCheckSum8(&DataPtr[0], (uint32)Length, E2E_USER_PROF_VAL_4BIT, TRUE);
                if(ReceivedCheckSum == ComputedCheckSum)
                {

                    E2E_ProcessRollingCounter(ConfigPtr, StatePtr, (uint16)ReceivedCounter);
                    StatePtr->Check_Timecounter = ReceivedCounter;
                    if (StatePtr->Status != E2E_USERPROFILE8BITCHECKSUMSTATUS_OK )
                    {
                        ret = E2E_E_ROLLINGCOUNTER_WRONG;
                    }

                }
                else
                {
                    StatePtr->Status = E2E_USERPROFILE8BITCHECKSUMSTATUS_ABN_CHECKSUM;
                    ret = E2E_E_CHECKSUM_WRONG;
                }
            }
            else
            {
                ret = E2E_E_INPUTERR_WRONG;
            }
        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumCheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumCheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
Std_ReturnType E2E_UserProfile8BitCheckSumCheckInit(E2E_UserProfile8BitCheckSumCheckStateType* StatePtr)
{
    Std_ReturnType ret = 0u;
    if (StatePtr != NULL)
    {
        StatePtr->Status            = E2E_USERPROFILE8BITCHECKSUMSTATUS_ERROR;
        StatePtr->Cal_wind_Time     = 0u;
        StatePtr->Check_Timecounter = 0u;
        StatePtr->Error_count       = 0u;
        ret = E_OK;
    }

    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}
#define E2EUSERPROF_CODE_SEC_END
#include "MemMap.h"
#endif
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
Date               : 11-Sep-2020
CDSID              : bbaskara
Traceability       : RTC #1039071
Change Description : Initial Framework version of E2E Module
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 25-April-2022
CDSID              : gthanapp
Traceability       : RTC #1621566
Change Description : Cerc Warning Fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-May-2022
CDSID              : dbalasub
Traceability       : RTC #1654041
Change Description : Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/



