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
#ifndef E2E_P02_C
#define E2E_P02_C
/*****************************************************************************
*  File Name         :  E2E_P02.c                                            *
*  Module Short Name :  E2E_P02                                              *
*  Description       :  This file contains E2E Profile 2 Implementation      *
*                       		                                             *
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
#include "E2E_P02.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_P02_MAX_COUNTER_LIMIT		15u
#define E2E_P02_ONE                     1u
#define E2E_P02_DELTACOUNT              16u

#define E2E_P02_MAX_VAL_8BIT            0xFFu
#define E2E_P02_MAX_VAL_8BITu           0xffu
#define E2E_P02_VAL_127u                127u
#define E2E_P02_SHIFT_BY_3U             3U
#define E2E_P02_VAL_0xF0u               0xF0u
#define E2E_P02_VAL_0x0fu               0x0fu
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
static void E2E_CalculateDeltaCounter(const E2E_P02ConfigType* ConfigPtr, E2E_P02CheckStateType* StatePtr, uint8 ReceivedCounter);

/*============================================================================
**
** Function Name    :   E2E_P02Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 2.
**						This includes checksum calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P02ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_P02Protect(const E2E_P02ConfigType* ConfigPtr, E2E_P02ProtectStateType* StatePtr, uint8* DataPtr)
{
    uint32 DataLength = 0U;
    uint8 CRCValue = 0U;
    uint8 CrcStartValue8 = E2E_P02_MAX_VAL_8BIT;
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;

    if ((ConfigPtr != NULL) && (StatePtr != NULL) && (DataPtr != NULL))
    {
        if ( StatePtr->Counter  >= E2E_P02_MAX_COUNTER_LIMIT)
        {
            StatePtr->Counter = 0;
        }
        else
        {
            StatePtr->Counter +=E2E_P02_ONE ;
        }
        DataLength = (uint32)(ConfigPtr->DataLength >> E2E_P02_SHIFT_BY_3U);
        DataPtr[E2E_P02_ONE] = ((uint8)(DataPtr[E2E_P02_ONE] & E2E_P02_VAL_0xF0u) | (uint8)(StatePtr->Counter & E2E_P02_VAL_0x0fu));

        /* CERT C 19646072*/
        if (DataLength < E2E_P02_ONE)
        {
            /* Handle error */
        }
        else
        {
            CRCValue = Crc_CalculateCRC8H2F(&DataPtr[E2E_P02_ONE],(DataLength-E2E_P02_ONE), CrcStartValue8, TRUE);
        }

        CRCValue = Crc_CalculateCRC8H2F(&ConfigPtr->DataIDList[StatePtr->Counter], E2E_P02_ONE, CRCValue, FALSE);

        DataPtr[0] = CRCValue;
        ret = E_OK;
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_P02ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P02ProtectInit(E2E_P02ProtectStateType* StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;

    if (NULL != StatePtr)
    {
        StatePtr->Counter = 0u;
        ret  = E_OK;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_P02Check
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E profile 2. This includes checksum
**						calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P02ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P02CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P02Check(const E2E_P02ConfigType* ConfigPtr, E2E_P02CheckStateType* StatePtr, const uint8* DataPtr)
{
    /* Verify Recieved CRC against the Data */

    uint8 CRCValue = 0U;
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    uint8 DataID = 0U;
    uint8 ReceivedCounter = 0U;
    uint8 ReceivedCRC = 0U;
    uint32 DataLength = 0U;

    if ((ConfigPtr != NULL) && (StatePtr != NULL) && (DataPtr != NULL))
    {
        if (StatePtr->MaxDeltaCounter < E2E_P02_MAX_COUNTER_LIMIT)
        {
            StatePtr->MaxDeltaCounter++;
        }
        if (FALSE != StatePtr->NewDataAvailable)
        {
            ReceivedCRC = DataPtr[0];
            ReceivedCounter = DataPtr[E2E_P02_ONE] & (E2E_P02_VAL_0x0fu); /*Lower Nibble */
            DataID = ConfigPtr->DataIDList[ReceivedCounter];
            DataLength = (uint32)(ConfigPtr->DataLength >> E2E_P02_SHIFT_BY_3U);
            /* Calculate CRC and set */
            /* CERT C 19646069*/
            if (DataLength < E2E_P02_ONE)
            {
                /* Handle error */
            }
            else
            {
                CRCValue = Crc_CalculateCRC8H2F ( &DataPtr[E2E_P02_ONE], (DataLength-E2E_P02_ONE), E2E_P02_MAX_VAL_8BITu, TRUE); /* Calculate CRC upto CRC Offset posiotion */
            }
            CRCValue = Crc_CalculateCRC8H2F ( &DataID, E2E_P02_ONE, CRCValue, FALSE); /*Calculate CRC after CRC Offset position */

            /* Compare the CRC values */
            if (ReceivedCRC == CRCValue)
            {
                /* New Data Received? */
                if (FALSE != StatePtr->WaitForFirstData)
                {
                    StatePtr->WaitForFirstData = FALSE;
                    StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
                    StatePtr->LastValidCounter = ReceivedCounter;
                    StatePtr->Status = E2E_P02STATUS_INITIAL;
                }
                else
                {
                    /* Process Delta Counter */
                    E2E_CalculateDeltaCounter (ConfigPtr, StatePtr, ReceivedCounter);
                }
            }
            else
            {
                StatePtr->Status = E2E_P02STATUS_WRONGCRC;
            }
        }
        else
        {
            if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P02_MAX_COUNTER_LIMIT)
            {
                StatePtr->NoNewOrRepeatedDataCounter++;
            }
            StatePtr->Status = E2E_P02STATUS_NONEWDATA;
        }
        ret = E_OK;
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_CalculateDeltaCounter
**
** Visibility       :
**
** Description      :   Calculates the Delta counter
**
** Invocation       :
**
** Inputs           :   E2E_P02ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P02CheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint16 ReceivedCounter - Received Counter value
** Outputs          :	void
**
** Critical Section :	NA
**
**==========================================================================*/
static void E2E_CalculateDeltaCounter(const E2E_P02ConfigType* ConfigPtr, E2E_P02CheckStateType* StatePtr, uint8 ReceivedCounter)
{
    sint8 DeltaCounter = 0;
    /*CERT_C 19646076*/
    if (((ReceivedCounter) - (StatePtr->LastValidCounter)) <= E2E_P02_VAL_127u)
    {
        DeltaCounter = (ReceivedCounter) - (StatePtr->LastValidCounter);
    }
    else
    {
        /* Handle error */
    }

    if (DeltaCounter < 0)
    {
        DeltaCounter += (sint8)E2E_P02_DELTACOUNT;
    }
    if (DeltaCounter == 0)
    {
        if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P02_MAX_COUNTER_LIMIT)
        {
            StatePtr->NoNewOrRepeatedDataCounter++;
        }
        StatePtr->Status = E2E_P02STATUS_REPEATED;
    }
    else if (DeltaCounter == (sint8)E2E_P02_ONE)
    {
        StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
        StatePtr->LastValidCounter = ReceivedCounter;
        StatePtr->LostData = 0u;
        if (StatePtr->NoNewOrRepeatedDataCounter <= ConfigPtr->MaxNoNewOrRepeatedData)
        {
            StatePtr->NoNewOrRepeatedDataCounter = 0u;
            if (StatePtr->SyncCounter > 0u)
            {
                StatePtr->SyncCounter--;
                StatePtr->Status = E2E_P02STATUS_SYNC;
            }
            else
            {
                StatePtr->Status= E2E_P02STATUS_OK;
            }
        }
        else
        {
            StatePtr->NoNewOrRepeatedDataCounter = 0u;
            StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;
            StatePtr->Status = E2E_P02STATUS_SYNC;
        }
    }
    else if ((DeltaCounter > (sint8)E2E_P02_ONE) && (DeltaCounter <= (sint8)(StatePtr->MaxDeltaCounter)))
    {
        /* No subsequent data received, delta counter is within range */
        StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
        StatePtr->LastValidCounter = ReceivedCounter;
        StatePtr->LostData = DeltaCounter - (sint8)E2E_P02_ONE;
        if (StatePtr->NoNewOrRepeatedDataCounter <= ConfigPtr->MaxNoNewOrRepeatedData)
        {
            StatePtr->NoNewOrRepeatedDataCounter = 0u;
            if (StatePtr->SyncCounter > 0u)
            {
                StatePtr->SyncCounter--;
                StatePtr->Status = E2E_P02STATUS_SYNC;
            }
            else
            {
                StatePtr->Status= E2E_P02STATUS_OKSOMELOST;
            }
        }
        else
        {
            StatePtr->NoNewOrRepeatedDataCounter = 0u;
            StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;
            StatePtr->Status = E2E_P02STATUS_SYNC;
        }
    }
    else
    {
        /* Incorrect sequence of Data received */
        StatePtr->NoNewOrRepeatedDataCounter = 0u;
        StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;
        if (StatePtr->SyncCounter > 0u)
        {
            StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
            StatePtr->LastValidCounter = ReceivedCounter;
        }
        StatePtr->Status = E2E_P02STATUS_WRONGSEQUENCE;
    }
}

/*============================================================================
**
** Function Name    :   E2E_P02CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P02CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P02CheckInit(E2E_P02CheckStateType* StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_NULL;
    if (StatePtr != NULL)
    {
        StatePtr->LastValidCounter           = 0u;
        StatePtr->MaxDeltaCounter            = 0u;
        StatePtr->WaitForFirstData           = TRUE;
        StatePtr->NewDataAvailable           = TRUE;
        StatePtr->LostData                   = 0u;
        StatePtr->Status                     = E2E_P02STATUS_NONEWDATA;
        StatePtr->NoNewOrRepeatedDataCounter = 0u;
        StatePtr->SyncCounter                = 0u;
        ret = E_OK;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_P02MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 2 to a generic check status, which
**						can be used by E2E state machine check function. The E2E Profile 2 delivers a
**						more fine-granular status, but this is not relevant for the E2E state machine.
**
** Invocation       :
**
** Inputs           :   E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
E2E_PCheckStatusType E2E_P02MapStatusToSM(Std_ReturnType CheckReturn, E2E_P02CheckStatusType Status, boolean profileBehavior)
{
    E2E_PCheckStatusType RetVal = E2E_P_ERROR;
    if (E2E_E_OK == CheckReturn)
    {
        switch(Status)
        {
        case E2E_P02STATUS_OK:
            RetVal = E2E_P_OK;
            break;
        case E2E_P02STATUS_OKSOMELOST:
            RetVal = E2E_P_OK;
            break;
        case E2E_P02STATUS_WRONGCRC:
            RetVal = E2E_P_ERROR;
            break;
        case E2E_P02STATUS_REPEATED:
            RetVal = E2E_P_REPEATED;
            break;
        case E2E_P02STATUS_NONEWDATA:
            RetVal = E2E_P_NONEWDATA;
            break;
        case E2E_P02STATUS_WRONGSEQUENCE:
            RetVal = E2E_P_WRONGSEQUENCE;
            break;
        case E2E_P02STATUS_SYNC:
            if (FALSE == profileBehavior)
            {
                RetVal = E2E_P_WRONGSEQUENCE;
            }
            else
            {
                RetVal = E2E_P_OK;
            }
            break;
        case E2E_P02STATUS_INITIAL:
            if (FALSE == profileBehavior)
            {
                RetVal = E2E_P_OK;
            }
            else
            {
                RetVal = E2E_P_WRONGSEQUENCE;
            }
            break;
        default:
            /* Do Nothing */
            break;
        }

    }
    return RetVal;
}

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
Date               : 17-Apr-2020
CDSID              : ssebast1
Traceability       : RTC #794879
Change Description : Initial Framework version of E2E Module with Profile2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 13-Apr-2022
CDSID              : nchellap
Traceability       : RTC #1578588 and 1578593
Change Description : Updated logic of counter for message transmission
                     Updated logic of delta counter for message reception
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
