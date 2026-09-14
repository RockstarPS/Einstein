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
#ifndef E2E_P06_C
#define E2E_P06_C
/*****************************************************************************
*  File Name         :  E2E_P06.c                                            *
*  Module Short Name :  E2E_P06                                              *
*  Description       :  This file contains E2E Profile 6 Implementation      *
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
#include "E2E_P06.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_P06_MAX_COUNTER_LIMIT   0xffu

#define E2E_P06_VAL_1U                  1U
#define E2E_P06_INC_BY_1U               1U
#define E2E_P06_INC_BY_2U               2U
#define E2E_P06_INC_BY_3U               3U
#define E2E_P06_INC_BY_4U               4U
#define E2E_P06_DEC_BY_2U               2U
#define E2E_P06_SHIFT_BY_8U             8U
#define E2E_P06_DIV_BY_8U               8U
#define E2E_P06_VAL_0xff00u             0xff00u
#define E2E_P06_VAL_0x00ffu             0x00ffu
#define E2E_P06_MAX_VAL_8BIT            0xFFu
#define E2E_P06_MAX_VAL_16BIT           0xFFFFu
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static void E2E_ProcessDeltaCounter(const E2E_P06ConfigType* ConfigPtr, E2E_P06CheckStateType* StatePtr, uint8 ReceivedCounter);

#define E2EP06_CODE_SEC_START
#include "MemMap.h"
/*============================================================================
**
** Function Name    :   E2E_ProcessDeltaCounter
**
** Visibility       :   Private
**
** Description      :   Provides further checks with respect to Delta Counter
**
** Invocation       :
**
** Inputs           :   E2E_P06ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P06CheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint8 ReceivedCounter - Received Counter value
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
static void E2E_ProcessDeltaCounter(const E2E_P06ConfigType* ConfigPtr, E2E_P06CheckStateType* StatePtr, uint8 ReceivedCounter)
{
    uint8 DeltaCounter = 0u;
    if(ReceivedCounter >= StatePtr->Counter)
    {
        DeltaCounter = ReceivedCounter - StatePtr->Counter;
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    if (DeltaCounter <= ConfigPtr->MaxDeltaCounter)
        /* DeltaCounter check for 0 is removed because of static analysis, this is included in the below checks*/
        /*CID 16044196*/
    {
        if (DeltaCounter > 0u)
        {
            if (DeltaCounter == E2E_P06_VAL_1U)
            {
                StatePtr->Status = E2E_P06STATUS_OK;
            }
            else
            {
                StatePtr->Status = E2E_P06STATUS_OKSOMELOST;
            }
        }
        else
        {
            StatePtr->Status = E2E_P06STATUS_REPEATED;
        }
    }
    else
    {
        StatePtr->Status = E2E_P06STATUS_WRONGSEQUENCE;
    }
}

/*============================================================================
**
** Function Name    :   E2E_P06Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 6.
**						This includes checksum calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P06ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P06ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P06Protect(E2E_P06ConfigType* ConfigPtr, E2E_P06ProtectStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint16 Offset = 0u;
    Std_ReturnType ret = 0u;
    uint16 ComputedCRC = 0u;
    uint8 var = 0u;

    if((ConfigPtr != NULL)&&(StatePtr != NULL) && (DataPtr!=NULL))
    {
        if((Length >= ConfigPtr->MinDataLength)&&(Length <= ConfigPtr->MaxDataLength))
        {

            Offset = ConfigPtr->Offset / E2E_P06_DIV_BY_8U;

            /*Copy 2 bytes of Length and 1 byte of Counter onto Data in big endian format*/
            DataPtr[Offset+E2E_P06_INC_BY_2U]  = (uint8)(Length & E2E_P06_VAL_0x00ffu);
            DataPtr[Offset+E2E_P06_INC_BY_3U]  = (uint8)((Length & E2E_P06_VAL_0xff00u)>>E2E_P06_SHIFT_BY_8U);
            DataPtr[Offset+E2E_P06_INC_BY_4U]  = (uint8)(StatePtr->Counter);


            if(ConfigPtr->Offset > 0u)
            {
                ComputedCRC = Crc_CalculateCRC16(&DataPtr[0], Offset, E2E_P06_MAX_VAL_16BIT, TRUE);
                if((Offset + E2E_P06_INC_BY_2U) < Length) /* To Protect negative rollback value */
                {
                    ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P06_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P06_DEC_BY_2U), ComputedCRC, FALSE);
                }
            }
            else
            {
                if((Offset + E2E_P06_INC_BY_2U) < Length) /* To Protect negative rollback value */
                {
                    ComputedCRC= Crc_CalculateCRC16(&DataPtr[Offset+E2E_P06_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P06_DEC_BY_2U), E2E_P06_MAX_VAL_16BIT, TRUE);
                }
            }
            var = (uint8)(((ConfigPtr->DataID) >>(E2E_P06_SHIFT_BY_8U)) & (E2E_P06_MAX_VAL_8BIT));
            ComputedCRC= Crc_CalculateCRC16(&var, E2E_P06_VAL_1U, ComputedCRC, FALSE);
            var = (uint8)(ConfigPtr->DataID & E2E_P06_MAX_VAL_8BIT);
            ComputedCRC= Crc_CalculateCRC16(&var, E2E_P06_VAL_1U, ComputedCRC, FALSE);

            /*Copy 2 bytes of ComputedCRC onto Data in big endian format*/
            DataPtr[Offset] = (uint8)(ComputedCRC & E2E_P06_VAL_0x00ffu);
            DataPtr[Offset+E2E_P06_INC_BY_1U] = (uint8)((ComputedCRC & E2E_P06_VAL_0xff00u)>>E2E_P06_SHIFT_BY_8U);


            StatePtr->Counter++;
            if(StatePtr->Counter == E2E_P06_MAX_COUNTER_LIMIT)
            {
                StatePtr->Counter = 0u;
            }
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
** Function Name    :   E2E_P06ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_P06ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_P06ProtectInit(E2E_P06ProtectStateType* StatePtr)
{
    Std_ReturnType ret = 0u;
    if (StatePtr != NULL)
    {
        StatePtr->Counter = 0u;
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
** Function Name    :   E2E_P06Check
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E profile 6. This includes checksum
**						calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P06ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P06CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P06Check(E2E_P06ConfigType* ConfigPtr, E2E_P06CheckStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint32 ReceivedCRC     = 0u;
    uint16 ReceivedLength  = 0u;
    uint8 ReceivedCounter  = 0u;
    uint16 ComputedCRC     = 0u;
    uint16 Offset          = 0u;
    Std_ReturnType ret     = 0u;
    uint8 var = 0u;

    if ((ConfigPtr != NULL) && (StatePtr != NULL))
    {
        if(((DataPtr != NULL) && (Length != 0u)) || ((DataPtr == NULL) && (Length == 0u)))
        {
            if(DataPtr != NULL)
            {
                if((Length >= ConfigPtr->MinDataLength) && (Length <= ConfigPtr->MaxDataLength))
                {
                    ReceivedLength  = (uint16)(((uint16)DataPtr[Offset + E2E_P06_INC_BY_3U] << E2E_P06_SHIFT_BY_8U) | ((uint16)DataPtr[Offset +E2E_P06_INC_BY_2U]));
                    ReceivedCounter = (uint8)DataPtr[Offset + E2E_P06_INC_BY_4U];
                    ReceivedCRC     = (uint16)(((uint16)DataPtr[Offset + E2E_P06_INC_BY_1U] << E2E_P06_SHIFT_BY_8U) | ((uint16)DataPtr[Offset]));

                    if(ConfigPtr->Offset > 0u)
                    {
                        ComputedCRC = Crc_CalculateCRC16(&DataPtr[0], (uint32)Offset, E2E_P06_MAX_VAL_16BIT, TRUE);
                        if((Offset + E2E_P06_INC_BY_2U) < Length) /* To Protect negative rollback value */
                        {
                            ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P06_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P06_DEC_BY_2U), ComputedCRC, FALSE);
                        }
                    }
                    else
                    {
                        if((Offset + E2E_P06_INC_BY_2U) < Length) /* To Protect negative rollback value */
                        {
                            ComputedCRC= Crc_CalculateCRC16(&DataPtr[Offset+E2E_P06_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P06_DEC_BY_2U), E2E_P06_MAX_VAL_16BIT, TRUE);
                        }
                    }
                    var = (uint8)(((ConfigPtr->DataID) >> (E2E_P06_SHIFT_BY_8U)) & (E2E_P06_MAX_VAL_8BIT));
                    ComputedCRC = Crc_CalculateCRC16(&var, E2E_P06_VAL_1U, ComputedCRC, FALSE);
                    var = (uint8)(ConfigPtr->DataID & E2E_P06_MAX_VAL_8BIT);
                    ComputedCRC = Crc_CalculateCRC16(&var, E2E_P06_VAL_1U, ComputedCRC, FALSE);

                    if(ReceivedCRC == ComputedCRC)
                    {
                        if(ReceivedLength == Length)
                        {
                            E2E_ProcessDeltaCounter(ConfigPtr, StatePtr, ReceivedCounter);
                            StatePtr->Counter = ReceivedCounter;
                        }
                        else
                        {
                            StatePtr->Status = (E2E_P06CheckStatusType)E2E_P06STATUS_ERROR;
                        }
                    }
                    else
                    {
                        StatePtr->Status = (E2E_P06CheckStatusType)E2E_P06STATUS_ERROR;
                    }
                    /*The condition check for NewDataAvailable was added as per the spec. The check is removed because of static analysis*/
                    /*CID 15564367*/
                }
                else
                {
                    ret = E2E_E_INPUTERR_WRONG;
                }
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
** Function Name    :   E2E_P06CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P06CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P06CheckInit(E2E_P06CheckStateType* StatePtr)
{
    Std_ReturnType ret = 0u;
    if (StatePtr != NULL)
    {
        StatePtr->Counter = E2E_P06_MAX_VAL_8BIT;
        StatePtr->Status = E2E_P06STATUS_ERROR;

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
** Function Name    :   E2E_P06MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 6 to a generic check status, which
**						can be used by E2E state machine check function. The E2E Profile 6 delivers a
**						more fine-granular status, but this is not relevant for the E2E state machine.
**
** Invocation       :
**
** Inputs           :   E2E_P06ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
E2E_PCheckStatusType E2E_P06MapStatusToSM(Std_ReturnType CheckReturn, E2E_P06CheckStatusType Status)
{
    E2E_PCheckStatusType RetVal = E2E_P_ERROR;
    if ((Std_ReturnType)E_NOT_OK != CheckReturn)
    {
        if(Status == (E2E_P06STATUS_OK))
        {
            RetVal = E2E_P_OK;
        }
        else if(Status == E2E_P06STATUS_OKSOMELOST)
        {
            RetVal = E2E_P_OK;
        }
        else if (Status == E2E_P06STATUS_ERROR)
        {
            RetVal = E2E_P_ERROR;
        }
        else if (Status == E2E_P06STATUS_REPEATED)
        {
            RetVal = E2E_P_REPEATED;
        }
        else if (Status == E2E_P06STATUS_NONEWDATA)
        {
            RetVal = E2E_P_NONEWDATA;
        }
        else if (Status == E2E_P06STATUS_WRONGSEQUENCE)
        {
            RetVal = E2E_P_WRONGSEQUENCE;
        }
        else
        {
            /*do nothing*/
        }
    }
    return RetVal;
}

#define E2EP06_CODE_SEC_END
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
Date               : 21-Apr-2020
CDSID              : pangraje
Traceability       : RTC #897020
Change Description : Initial Framework version of E2E Module with Profile6
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
