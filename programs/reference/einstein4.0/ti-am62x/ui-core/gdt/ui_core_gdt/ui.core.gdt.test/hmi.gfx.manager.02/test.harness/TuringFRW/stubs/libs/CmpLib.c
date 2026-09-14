//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#include "Std_Types.h"
#include "CmpLib.h"

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/// @brief Bit-mask  for memorizing the active/inactive history sub-state
#define cCMP_STATE_ACTIVE_BIT               ((CmpStateType)0x80) /// when set means ACTIVE sub-state, else INACTIVE sub-state


//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
//----------------------------------------------------------------------------------------------------------------------
/// @brief    This function is called periodically. Never call this function directly. Use the macros.
///
/// @param    pObj: This is pointer to the instance of the state-machine.
//----------------------------------------------------------------------------------------------------------------------
void CmpLib_Task ( const SCmpType * const pObj )
{
    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
    if ( (NULL != pObj) && (NULL != pObj->State) )
    {
        CmpStateType  State = (*pObj->State) & ~cCMP_STATE_ACTIVE_BIT;
        CmpStateType  StateActiveBit = (*pObj->State) & cCMP_STATE_ACTIVE_BIT;

        if ( State < cCMP_RUNNABLE_STATES )
        {
            Std_ReturnType Ret  = pObj->Process[State]();

            switch ( State )
            {
                case eCmpState_Init:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                       *pObj->State = ( (0 != StateActiveBit) ?  (eCmpState_Active | cCMP_STATE_ACTIVE_BIT) : eCmpState_InActive );
                    }
                    break;

                case eCmpState_DeInit:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                       *pObj->State = eCmpState_Off; // cleans active bit
                    }
                    break;

                case eCmpState_Activation:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                       *pObj->State = eCmpState_Active | cCMP_STATE_ACTIVE_BIT;
                    }
                    break;

                case eCmpState_DeActivation:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                       *pObj->State = eCmpState_InActive; // cleans active bit
                    }
                    break;

                case eCmpState_Diag:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                        *pObj->State = eCmpState_DiagReturn | StateActiveBit;
                    }
                    break;

                case eCmpState_DiagReturn:
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    if ( E_OK == Ret )
                    {
                        *pObj->State = ( (0 != StateActiveBit) ?  (eCmpState_Active | cCMP_STATE_ACTIVE_BIT) : eCmpState_InActive );
                    }
                    break;

                default:
                    // do nothing
                    break;
            }
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief    Turing standard life-cycle state machine. Never call this function directly. Use the macros.
///
/// @param    pObj: This is pointer to the instance of the state-machine.
/// @param    Cmd:  Command to be executed
///
/// @return   Std_ReturnType:   E_OK        - command complete. State is changed.
/// <br>                        E_NOT_READY - the component is not ready yet. State NOT changed.
/// <br>                        E_NOT_OK    - invalid parameter/s. State NOT changed.
//----------------------------------------------------------------------------------------------------------------------
Std_ReturnType CmpLib_Command ( const SCmpType * const pObj,  const ECmpCmd Cmd )
{
    Std_ReturnType Ret = E_NOT_OK;

    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
    if ( (NULL != pObj) && (NULL != pObj->State) )
    {
        CmpStateType State = (*pObj->State) & ~cCMP_STATE_ACTIVE_BIT;
        CmpStateType StateActiveBit = (*pObj->State) & cCMP_STATE_ACTIVE_BIT;

        switch ( Cmd )
        {
            case eCmpCmd_Init:
                if ( eCmpState_InActive == State )
                {
                    Ret = E_OK;
                }
                else if ( eCmpState_Init == State )
                {
                    Ret = E_NOT_READY;
                }
                else
                {
                    Ret = pObj->Process[eCmpState_Init]();

                    if ( E_NOT_READY == Ret )
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        *pObj->State = eCmpState_Init;    // cleans active bit
                    }
                    else if ( E_OK == Ret )
                    {
                        *pObj->State = eCmpState_InActive;    // cleans active bit
                    }
                    else
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        Ret = E_NOT_OK;
                    }
                }

                break;

            case eCmpCmd_DeInit:
                if ( eCmpState_Off == State )
                {
                    Ret = E_OK;
                }
                else if ( eCmpState_DeInit == State )
                {
                    Ret = E_NOT_READY;
                }
                else
                {
                    Ret = pObj->Process[eCmpState_DeInit]();

                    if ( E_NOT_READY == Ret )
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        *pObj->State = eCmpState_DeInit;   // cleans active bit
                    }
                    else if ( E_OK == Ret )
                    {
                        *pObj->State = eCmpState_Off;   // cleans active bit
                    }
                    else
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        Ret = E_NOT_OK;
                    }
                }
                break;

            case eCmpCmd_Activate:
                if ( eCmpState_InActive == State )
                {
                    *pObj->State = eCmpState_Activation;
                    Ret = E_OK;
                }
                else if ( eCmpState_Active == State )
                {
                    Ret = E_OK;
                }
                else
                {
                    // do nothing, CMP_COMMAND_ACTIVATE should be sent only if State is INACTIVE
                }
                break;

            case eCmpCmd_DeActivate:
                if ( eCmpState_Active == State )
                {
                    *pObj->State = eCmpState_DeActivation;
                    Ret = E_OK;
                }
                else if ( eCmpState_InActive == State )
                {
                    Ret = E_OK;
                }
                else
                {
                    // do nothing, CMP_COMMAND_DEACTIVATE should be sent only if State is ACTIVE
                }
                break;

            case eCmpCmd_DiagStart:
                if ( eCmpState_Diag == State )
                {
                    Ret = E_OK;
                }
                else
                {
                    if  ( (eCmpState_Active == State) || (eCmpState_InActive == State) )
                    {
                        *pObj->State = ( eCmpState_Diag | StateActiveBit );
                        Ret = E_OK;
                    }
                }
                break;

            case eCmpCmd_DiagStop:
                if ( eCmpState_Diag == State )
                {
                    *pObj->State =  ( eCmpState_DiagReturn | StateActiveBit );
                    Ret = E_OK;
                }
                break;


            case eCmpCmd_ReStart:
                if ( (eCmpState_Activation == State ) ||
                     (eCmpState_DeActivation == State)||
                     (eCmpState_Diag == State)        ||
                     (eCmpState_DiagReturn == State) )
                {
                    Ret = E_NOT_OK;
                }
                else if ( eCmpState_Init == State )
                {
                    Ret = E_NOT_READY;
                }
                else
                {
                    Ret = pObj->Process[eCmpState_Init]();

                    if ( E_NOT_READY == Ret )
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        *pObj->State = ( eCmpState_Init | StateActiveBit );
                    }
                    else if ( E_OK == Ret )
                    {
                        *pObj->State = ( (0 != StateActiveBit) ?  (eCmpState_Active | cCMP_STATE_ACTIVE_BIT) : eCmpState_InActive );
                    }
                    else
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        Ret = E_NOT_OK;
                    }
                }

                break;

            case eCmpCmd_Reset:
                if ( eCmpState_Init == State )
                {
                    Ret = E_NOT_READY;
                }
                else
                {
                    *pObj->State &= ~cCMP_STATE_ACTIVE_BIT;
                    Ret = pObj->Process[eCmpState_Init]();

                    if ( E_NOT_READY == Ret )
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        *pObj->State = eCmpState_Init;  // cleans active bit
                    }
                    else if ( E_OK == Ret )
                    {
                        *pObj->State = eCmpState_InActive;   // cleans active bit
                    }
                    else
                    // polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
                    {
                        Ret = E_NOT_OK;
                    }
                }

                break;

            default:
                // do not put assert here, please!!!
                break;
        }
    }

    return Ret;
}

//----------------------------------------------------------------------------------------------------------------------
// For UT only
#ifdef UTEST

CMPLIB_INSTANCE( test )
SCmpType testObj = { { &CmpInit, &CmpDeInit, &CmpActive, &CmpActivation, &CmpDeActivation, &CmpDiag, &CmpDiagReturn }, &CmpState };

#ifndef CHECKER
    static Std_ReturnType CmpInit         ( void ) { return E_OK; }
    static Std_ReturnType CmpDeInit       ( void ) { return E_OK; }
    static Std_ReturnType CmpActive       ( void ) { return E_OK; }
    static Std_ReturnType CmpActivation   ( void ) { return E_OK; }
    static Std_ReturnType CmpDeActivation ( void ) { return E_OK; }
    static Std_ReturnType CmpDiag         ( void ) { return E_OK; }
    static Std_ReturnType CmpDiagReturn   ( void ) { return E_OK; }
#endif

#endif  // UTEST
