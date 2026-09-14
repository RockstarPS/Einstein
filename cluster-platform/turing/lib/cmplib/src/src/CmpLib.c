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
/*MISRA RULE 4.8 VIOLATION and MISRA RULE 10.5 VIOLATION: the file includes the definition of AlarmBaseType but not used. So,It is not a functional impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/// @brief Bit-mask  for memorizing the active/inactive history sub-state
/*MISRA RULE 2.5 VIOLATION and MISRA RULE 10.5 VIOLATION: It that function declared as macro in other file not an impact,we can ignore it. So,It is not a functional impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#define CMBLIB_CONST_SEC_START
#include "MemMap.h"

#define cCMP_STATE_ACTIVE_BIT               ((CmpStateType)0x80) /// when set means ACTIVE sub-state, else INACTIVE sub-state
/*MISRA RULE 2.5 VIOLATION and MISRA RULE 10.5 VIOLATION: It that function declared as macro in other file not an impact,we can ignore it. So,It is not a functional impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#define CMBLIB_CONST_SEC_END
#include "MemMap.h"

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================

#define CMBLIB_CODE_SEC_START
#include "MemMap.h"

//----------------------------------------------------------------------------------------------------------------------
/// @brief    This function is called periodically. Never call this function directly. Use the macros.
///
/// @param    pObj: This is pointer to the instance of the state-machine.
//----------------------------------------------------------------------------------------------------------------------
void CmpLib_Task(const SCmpType * const pObj)
{
	// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
	if ((NULL != pObj) && (NULL != pObj->State))
	{
		CmpStateType State = (*pObj->State) & ~cCMP_STATE_ACTIVE_BIT; /* CID 6298875 Nested memory access : No speculative execution possible as system uses only a single processor core */
		CmpStateType StateActiveBit = (*pObj->State) & cCMP_STATE_ACTIVE_BIT;

		if (State < (CmpStateType)cCMP_RUNNABLE_STATES)
		{
			Std_ReturnType Ret = pObj->Process[State](); /* CID 6298875 Nested memory access: No speculative execution possible as system uses only a single processor core */
/*MISRA RULE 10.4 VIOLATION and MISRA RULE 10.5 VIOLATION: In this file left and right hand operand are different but not an impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
			if ((Std_ReturnType)E_OK == Ret)
			{
				switch (State)
				{
					case (uint8)eCmpState_Init:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State
								= (CmpStateType) ((0U != StateActiveBit) ? ((CmpStateType) eCmpState_Active
										| cCMP_STATE_ACTIVE_BIT)
										: (CmpStateType) eCmpState_InActive);
						break;

					case (uint8)eCmpState_DeInit:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State = (CmpStateType) eCmpState_Off; // cleans active bit
						break;

					case (uint8)eCmpState_Activation:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State
								= (CmpStateType) ((CmpStateType) eCmpState_Active
										| cCMP_STATE_ACTIVE_BIT);
						break;

					case (uint8)eCmpState_DeActivation:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State = (CmpStateType) eCmpState_InActive; // cleans active bit
						break;
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
					case (uint8)eCmpState_WakeUp:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State
								= (CmpStateType) ((0U != StateActiveBit) ? ((CmpStateType) eCmpState_Active
										| cCMP_STATE_ACTIVE_BIT)
										: (CmpStateType) eCmpState_InActive);
						break;
#endif

					case (uint8)eCmpState_Diag:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State
								= (CmpStateType) ((CmpStateType) eCmpState_DiagReturn
										| StateActiveBit);
						break;
				/*MISRA RULE 10.3 VIOLATION and MISRA RULE 10.5 VIOLATION: For this data type it is with in the range of values,so it not gives functonal impact. ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
					case (uint8)eCmpState_DiagReturn:
						// polyspace<RTE:UNR> Unreachable code from Polyspace point of view, however it is tested with VectorCast.
						*pObj->State
								= (CmpStateType) ((0U != StateActiveBit) ? ((CmpStateType) eCmpState_Active
										| cCMP_STATE_ACTIVE_BIT)
										: (CmpStateType) eCmpState_InActive);
						break;

					default:
						// do nothing
						break;
				}
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

    
    if ( (NULL != pObj) && (NULL != pObj->State) )
    {
            CmpStateType State = (*pObj->State) & ~cCMP_STATE_ACTIVE_BIT;
            CmpStateType StateActiveBit = (*pObj->State) & cCMP_STATE_ACTIVE_BIT;

            switch ( Cmd )
            {
                case eCmpCmd_Init:
                    if ( (CmpStateType)eCmpState_InActive == State )
                    {
                        Ret = E_OK;
                    }
                    else if ( (CmpStateType)eCmpState_Init == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ( (CmpStateType)eCmpState_Off == State )
                    {
                        Ret = pObj->Process[eCmpState_Init]();

                        if ( E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_Init;    // cleans active bit
                        }
                        else if ((Std_ReturnType)E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_InActive;    // cleans active bit
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                case eCmpCmd_DeInit:
                    if ( (CmpStateType)eCmpState_Off == State )
                    {
                        Ret = E_OK;
                    }
                    else if ( (CmpStateType)eCmpState_DeInit == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ( (CmpStateType)eCmpState_Init != State )
                    {
                        Ret =pObj->Process[eCmpState_DeInit]();

                        if ( E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_DeInit;   // cleans active bit
                        }
                        else if ((Std_ReturnType)E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_Off;   // cleans active bit
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                case eCmpCmd_Activate:
                    if ((CmpStateType)eCmpState_Active == State )
                    {
                        Ret = E_OK;
                    }
                    else if ((CmpStateType)eCmpState_Activation == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ((CmpStateType)eCmpState_InActive == State )
                    {
                        Ret =pObj->Process[eCmpState_Activation]();
                        if ( E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_Activation;
                        }
						/*MISRA RULE 10.4 VIOLATION and MISRA RULE 10.4 VIOLATION: In this file left and right hand operand are different but not an impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
                        else if ((Std_ReturnType)E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)((CmpStateType)eCmpState_Active | cCMP_STATE_ACTIVE_BIT);
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                case eCmpCmd_DeActivate:
                    if ((CmpStateType)eCmpState_InActive == State )
                    {
                        Ret = E_OK;
                    }
                    else if ((CmpStateType)eCmpState_DeActivation == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ((CmpStateType)eCmpState_Active == State )
                    {
                        Ret =pObj->Process[eCmpState_DeActivation]();
                        if ( E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_DeActivation;
                        }
                        else if ((Std_ReturnType) E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_InActive;
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
               case eCmpCmd_WakeUp:
                    if ( (CmpStateType)eCmpState_InActive == State )
                    {
                        Ret = E_OK;
                    }
                    else if ( (CmpStateType)eCmpState_WakeUp == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ( (CmpStateType)eCmpState_Off == State )
                    {
                        Ret =pObj->Process[eCmpState_WakeUp]();

                        if ((Std_ReturnType)E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_WakeUp;    // cleans active bit
                        }
                        else if ( E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_InActive;    // cleans active bit
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;
#endif

                case eCmpCmd_DiagStart:
                    if ((CmpStateType)eCmpState_Diag == State )
                    {
                        Ret = E_OK;
                    }
                    else
                    {
                        if  (((CmpStateType)eCmpState_Active == State) || ((CmpStateType)eCmpState_InActive == State))
                        {
                            *pObj->State = (CmpStateType)( (CmpStateType)eCmpState_Diag | StateActiveBit );
                            Ret = E_OK;
                        }
                    }
                    break;

                case eCmpCmd_DiagStop:
                    if (((CmpStateType)eCmpState_Active == State) || ((CmpStateType)eCmpState_InActive == State))
                    {
                        Ret = E_OK;
                    }
                    else if ((CmpStateType)eCmpState_DiagReturn == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ((CmpStateType)eCmpState_Diag == State )
                    {
                        Ret =pObj->Process[eCmpState_DiagReturn]();
                        if ((Std_ReturnType) E_NOT_OK != Ret )
                        {
                            *pObj->State =  (CmpStateType)( (CmpStateType)eCmpState_DiagReturn | StateActiveBit );
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                case eCmpCmd_ReStart:
                    if ((CmpStateType)eCmpState_Init == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ( ((CmpStateType)eCmpState_Active == State) || ((CmpStateType)eCmpState_InActive == State) )
                    {
                        Ret = pObj->Process[eCmpState_Init]();
                        if ((Std_ReturnType)E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)( (CmpStateType)eCmpState_Init | StateActiveBit );
                        }
                        else if ((Std_ReturnType) E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)( (0U != StateActiveBit) ?  ((CmpStateType)eCmpState_Active | cCMP_STATE_ACTIVE_BIT) : (CmpStateType)eCmpState_InActive );
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                case eCmpCmd_Reset:
                    if ( (CmpStateType)eCmpState_Init == State )
                    {
                        Ret = E_NOT_READY;
                    }
                    else if ( ((CmpStateType)eCmpState_DeInit != State) && ((CmpStateType)eCmpState_Off != State) )
                    {
                        *pObj->State &= ~cCMP_STATE_ACTIVE_BIT;
                        Ret = pObj->Process[eCmpState_Init]();

                        if ((Std_ReturnType)E_NOT_READY == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_Init;  // cleans active bit
                        }
                        else if ((Std_ReturnType)E_OK == Ret )
                        {
                            *pObj->State = (CmpStateType)eCmpState_InActive;   // cleans active bit
                        }
                        else
                        {
                            Ret = E_NOT_OK;
                        }
                    }
                    else
                    {
                        Ret = E_NOT_OK;
                    }
                    break;

                default:

                    break;
            }
        }

    return Ret;
}

#define CMBLIB_CODE_SEC_END
/*MISRA RULE 20.1 VIOLATION and MISRA RULE 10.5 VIOLATION: In this file #include preceded by code is require but not an impact ; This is the reason why the MISRA
                     rule could not be followed in this special case*/
#include "MemMap.h"
//----------------------------------------------------------------------------------------------------------------------
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
