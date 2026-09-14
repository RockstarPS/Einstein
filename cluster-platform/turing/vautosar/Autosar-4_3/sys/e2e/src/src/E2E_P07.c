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
/*****************************************************************************
*  File Name         :  E2E_P07.c                                            *
*  Module Short Name :  E2E_P07                                              *
*  Description       :  This file contains E2E Profile 7 Implementation      *
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
#ifndef E2E_P07_C
#define E2E_P07_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "E2E_P07.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*============================================================================
**
** Function Name    :   E2E_P07MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 7 to a generic check status, 
**                      which can be used by E2E state machine check function. The E2E Profile 7 delivers a
**                      more fine-granular status, but this is not relevant for the E2E state machine
**
** Invocation       :
**
** Inputs           :   Std_ReturnType CheckReturn - Profile-independent status of the reception on one single Data in one cycle.
**                      E2E_P07CheckStatusType Status - Status determined by E2E_P07Check function
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

E2E_PCheckStatusType E2E_P07MapStatusToSM( Std_ReturnType CheckReturn, E2E_P07CheckStatusType Status )
{
    E2E_PCheckStatusType retval = E2E_P_ERROR;
    if( CheckReturn == E2E_E_OK )
    {
        if( ( E2E_P07STATUS_OK == Status ) || ( E2E_P07STATUS_OKSOMELOST == Status ) )
        {
            retval = E2E_P_OK;
        }

        else if( E2E_P07STATUS_ERROR == Status )
        {
            retval = E2E_P_ERROR;
        }

        else if( E2E_P07STATUS_REPEATED == Status )
        {
            retval = E2E_P_REPEATED;
        }

        else if( E2E_P07STATUS_NONEWDATA == Status )
        {
            retval = E2E_P_NONEWDATA;
        }

        else if( E2E_P07STATUS_WRONGSEQUENCE == Status )
        {
            retval = E2E_P_WRONGSEQUENCE;
        }

        else
        {
            /* do nothing */
        }
    }

    else
    {
        /* do nothing */
    }

    return retval;
}

/*============================================================================
**
** Function Name    :   E2E_P07ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the protection state.
**
** Invocation       :
**
** Inputs           :   E2E_P07ProtectStateType* StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_P07ProtectInit( E2E_P07ProtectStateType* StatePtr )
{
    Std_ReturnType retval = E2E_E_INPUTERR_NULL;

    if( NULL != StatePtr )
    {
        StatePtr->Counter = 0u;
        retval = E2E_E_OK;
    }
    else
    {
        /* do nothing */
    }
    return retval;
}

/*============================================================================
**
** Function Name    :   E2E_P07CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P07CheckStateType* StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_P07CheckInit( E2E_P07CheckStateType* StatePtr )
{
    Std_ReturnType retval = E2E_E_INPUTERR_NULL;

    if( NULL != StatePtr )
    {
        StatePtr->Counter = 0xFFFFFFFFuL;
        StatePtr->Status = E2E_P07STATUS_ERROR;
        retval = E2E_E_OK;
    }
    else
    {
        /* do nothing */
    }
    return retval;

}

/*============================================================================
**
** Function Name    :   E2E_P07Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 7. 
**                      This includes checksum calculation, handling of counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P07ConfigType* ConfigPtr - Pointer to a configuration type.
**						E2E_P07ProtectStateType* StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**                      uint32 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_P07Protect(const E2E_P07ConfigType* ConfigPtr, E2E_P07ProtectStateType* StatePtr, uint8* DataPtr, uint32 Length)
{
    uint32 NewOffset = 0u;
    Std_ReturnType ret = 0u;
    uint64 ComputedCRC = 0xFFFFFFFFFFFFFFFFu;

    if((NULL != ConfigPtr) && (NULL != StatePtr) && (NULL != DataPtr))
    {
        /* Both length parameters are Bit-values and therefore need to be divided by 8 */
        if((Length >= (ConfigPtr->MinDataLength >> E2E_P07_SHIFT_BY_3U)) && (Length <= (ConfigPtr->MaxDataLength >> E2E_P07_SHIFT_BY_3U)))
        {
            
            NewOffset = ConfigPtr->Offset / E2E_P07_DIV_BY_8U;
            
            DataPtr[NewOffset+8u]  = (uint8) (Length >> E2E_P07_SHIFT_BY_24U); 
            DataPtr[NewOffset+9u]  = (uint8) (Length >> E2E_P07_SHIFT_BY_16U);
            DataPtr[NewOffset+10u] = (uint8) (Length >> E2E_P07_SHIFT_BY_8U);
            DataPtr[NewOffset+11u] = (uint8) (Length);
            
            DataPtr[NewOffset+12u] = (uint8) (StatePtr->Counter >> E2E_P07_SHIFT_BY_24U); 
            DataPtr[NewOffset+13u] = (uint8) (StatePtr->Counter >> E2E_P07_SHIFT_BY_16U);
            DataPtr[NewOffset+14u] = (uint8) (StatePtr->Counter >> E2E_P07_SHIFT_BY_8U);
            DataPtr[NewOffset+15u] = (uint8) (StatePtr->Counter);
            
            DataPtr[NewOffset+16u] = (uint8) (ConfigPtr->DataID >> E2E_P07_SHIFT_BY_24U); 
            DataPtr[NewOffset+17u] = (uint8) (ConfigPtr->DataID >> E2E_P07_SHIFT_BY_16U);
            DataPtr[NewOffset+18u] = (uint8) (ConfigPtr->DataID >> E2E_P07_SHIFT_BY_8U);
            DataPtr[NewOffset+19u] = (uint8) (ConfigPtr->DataID);
            
            if(E2E_ZERO_VALUE < ConfigPtr->Offset) 
            {  
                /*compute CRC over bytes that are before CRC.computation length: NewOffset, where NewOffset is number of bytes before the E2E header*/       
                ComputedCRC = Crc_CalculateCRC64(&DataPtr[0], NewOffset, E2E_UINT64_MAX_VALUE, TRUE);   
            }
            
            else
            {
                /* do nothing */
            }

            /* Compute CRC over bytes that are after CRC */

            ComputedCRC = Crc_CalculateCRC64(&DataPtr[NewOffset+8u], Length-NewOffset-8u,ComputedCRC, FALSE);

            DataPtr[NewOffset] =       (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_56U); 
            DataPtr[NewOffset + 1u] =  (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_48U); 
            DataPtr[NewOffset + 2u] =  (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_40U); 
            DataPtr[NewOffset + 3u] =  (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_32U); 
            DataPtr[NewOffset + 4u] =  (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_24U); 
            DataPtr[NewOffset + 5u] =  (uint8) (ComputedCRC  >> E2E_P07_SHIFT_BY_16U); 
            DataPtr[NewOffset + 6u] =  (uint8) (ComputedCRC  >>  E2E_P07_SHIFT_BY_8U); 
            DataPtr[NewOffset + 7u] =  (uint8) (ComputedCRC);        
            
            /* Counter is incremented. Valid values are 0..0xFFFFFFFF. Thus there is no need to care about overflow */
            StatePtr->Counter++; 

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
** Function Name    :   E2E_P07Check
**
** Visibility       :   Public
**
** Description      :   Checks the Data received using the E2E profile 7. 
**                      This includes CRC calculation, handling of Counter and Data ID.
**
** Invocation       :
**
** Inputs           :   const E2E_P07ConfigType* ConfigPtr - Pointer to a configuration type.
**						E2E_P07CheckStateType* StatePtr - Pointer to CheckSate type.
**						const uint8* DataPtr - Data Pointer.
**                      uint32 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P07Check( const E2E_P07ConfigType* ConfigPtr, E2E_P07CheckStateType* StatePtr, const uint8* DataPtr, uint32 Length )
{
    boolean NewDataAvailable = FALSE;   
    uint32 ReceivedLength = 0u;
    uint32 ReceivedCounter = 0u;
    uint32 ReceivedDataID  = 0u;
    uint64 ReceivedCRC = 0u;
    Std_ReturnType ret = 0u;
    uint32 NewOffset = 0u;
    uint64 ComputedCRC = 0xFFFFFFFFFFFFFFFFuLL;
    uint32 DeltaCounter = 0u;

    if( (NULL != ConfigPtr) && (NULL != StatePtr) ) //check if input configptr and stateptr is null
    {

        if( ((NULL != DataPtr) && (E2E_ZERO_VALUE != Length) ) || ((NULL == DataPtr) && (E2E_ZERO_VALUE == Length)) ) // Check: Either both Data and Length mean that a message isavailable,                                                                   // or both mean the opposite.
        {
            if(NULL != DataPtr)
            {
                if((Length >= (ConfigPtr->MinDataLength >> E2E_P07_SHIFT_BY_3U)) && (Length <= (ConfigPtr->MaxDataLength >> E2E_P07_SHIFT_BY_3U)))
                {
                    NewDataAvailable = TRUE;
                }

                else
                {
                    ret = E2E_E_INPUTERR_WRONG;
                }
            

                NewOffset = ConfigPtr->Offset / E2E_P07_DIV_BY_8U; 

                ReceivedLength = (((uint32) DataPtr[NewOffset +  8u]) << E2E_P07_SHIFT_BY_24U) | (((uint32) DataPtr[NewOffset +  9u]) << E2E_P07_SHIFT_BY_16U) | (((uint32) DataPtr[NewOffset + 10u]) << E2E_P07_SHIFT_BY_8U)  | ( (uint32) DataPtr[NewOffset + 11u]);

                ReceivedCounter = (((uint32) DataPtr[NewOffset + 12u]) << E2E_P07_SHIFT_BY_24U) | (((uint32) DataPtr[NewOffset + 13u]) << E2E_P07_SHIFT_BY_16U) | (((uint32) DataPtr[NewOffset + 14u]) << 8u)  | ( (uint32) DataPtr[NewOffset + 15u]);

                ReceivedDataID = (((uint32) DataPtr[NewOffset + 16u]) << E2E_P07_SHIFT_BY_24U) | (((uint32) DataPtr[NewOffset + 17u]) << E2E_P07_SHIFT_BY_16U) | (((uint32) DataPtr[NewOffset + 18u]) << E2E_P07_SHIFT_BY_8U)  | ( (uint32) DataPtr[NewOffset + 19u]);

                ReceivedCRC = (((uint64) DataPtr[NewOffset]) << E2E_P07_SHIFT_BY_56U) | (((uint64) DataPtr[NewOffset + 1u]) << E2E_P07_SHIFT_BY_48U) | (((uint64) DataPtr[NewOffset + 2u]) << E2E_P07_SHIFT_BY_40U) | (((uint64) DataPtr[NewOffset + 3u]) << E2E_P07_SHIFT_BY_32U) |
                            (((uint64) DataPtr[NewOffset + 4u]) << E2E_P07_SHIFT_BY_24U) | (((uint64) DataPtr[NewOffset + 5u]) << E2E_P07_SHIFT_BY_16U) | (((uint64) DataPtr[NewOffset + 6u]) << E2E_P07_SHIFT_BY_8U)  | ( (uint64) DataPtr[NewOffset + 7u]);

                if (E2E_ZERO_VALUE < ConfigPtr->Offset)
                {
                    ComputedCRC = Crc_CalculateCRC64 (&DataPtr[0], NewOffset, ComputedCRC, TRUE); 
                }

                /* #20 Compute CRC over bytes that are after CRC (at least 12 bytes of header) */
                ComputedCRC = Crc_CalculateCRC64 (&DataPtr[NewOffset + 8u], Length - NewOffset - 8u, ComputedCRC, FALSE); 

                if(TRUE == NewDataAvailable)
                {
                    if( (ReceivedCRC == ComputedCRC) && (ReceivedDataID == ConfigPtr->DataID) && (ReceivedLength == Length) )
                    {
                        if(ReceivedCounter >= StatePtr->Counter)
                        {
                            DeltaCounter = ReceivedCounter - StatePtr->Counter;
                        }
                        else
                        {
                            DEBUG_ASSERT( FALSE );
                        }

                        if(DeltaCounter <= ConfigPtr->MaxDeltaCounter)
                        {
                            if( DeltaCounter > 0u )
                            {
                                if(DeltaCounter == 1u)
                                {
                                    StatePtr->Status = E2E_P07STATUS_OK;
                                }
                                else
                                {
                                    StatePtr->Status = E2E_P07STATUS_OKSOMELOST;
                                }
                            }
                            else
                            {
                                StatePtr->Status = E2E_P07STATUS_REPEATED;
                            }
                        }
                        else
                        {
                            StatePtr->Status = E2E_P07STATUS_WRONGSEQUENCE;
                        }

                        StatePtr->Counter = ReceivedCounter;
                    }
                    else
                    {
                        StatePtr->Status = E2E_P07STATUS_ERROR;
                    }
                }
                else
                {
                    StatePtr->Status = E2E_P07STATUS_NONEWDATA;
                }
            }
            else
            {
                /* Do nothing */
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

#define E2EP07_CODE_SEC_END
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
Date               : 19-Oct-2023
CDSID              : gthanapp
Traceability       : JIRA #DICVA-395
Change Description : Initial Framework version of E2E Module with Profile7
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
