#ifndef _QAC_
// *********************************************************************************************************************
// Company:             Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:           This software is JCI property.
//                      Duplication or disclosure without JCI written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:             E40_Platform
// Language:            C
// ---------------------------------------------------------------------------------------------------------------------
//      DO NOT CHANGE THIS FILE! IT HAS BEEN GENERATED. ANY CHANGES WILL BE OVERWRITTEN AT THE NEXT GENERATION!
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:40 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              STMCompositeHistoryState (Class)
// Description:         A CompositeHistoryState is an CompositeState which memorize the curent sub-state before exiting
//                      and reactivate the last sub-state when it is re-activated.
// Owner:               STM_ENGINE (Package)
// ---------------------------------------------------------------------------------------------------------------------
// Rhapsody version:    9.0.1
// Generator version:   V3.0.27
// Generator date:      11/12/2014 12:04:26,40
// ---------------------------------------------------------------------------------------------------------------------
// PVCS section start
// PVCS Log:
// $Log: $
// PVCS section end
// *********************************************************************************************************************
#endif // #ifndef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Disabled QAC warnings
// ---------------------------------------------------------------------------------------------------------------------
#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:3220)
#pragma PRQA_MESSAGES_OFF 3220
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:3673)
#pragma PRQA_MESSAGES_OFF 3673
#endif // #ifdef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                           Auto generated visibility defines
// ---------------------------------------------------------------------------------------------------------------------
#define STMCompositeHistoryState_PRIVATE_VISIBILITY
#define STMCompositeHistoryState_PROTECTED_VISIBILITY
#define STMStateVertex_PROTECTED_VISIBILITY
#define STMState_PROTECTED_VISIBILITY
#define STMCompositeState_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMCompositeHistoryState_VTBL STMCompositeHistoryState_VTBL = {
    // Operation "IsActivable" defined by the Class "STMStateVertex", implemented in the Class "STMStateVertex"
    &STMStateVertex_IsActivable_Implementation,
    // Operation "GetAtomicEntry" defined by the Class "STMState", implemented in the Class "STMCompositeHistoryState"
    &STMCompositeHistoryState_GetAtomicEntry_Implementation,
    // Operation "DoEntry" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_DoEntry_Implementation,
    // Operation "DoExit" defined by the Class "STMState", implemented in the Class "STMCompositeHistoryState"
    &STMCompositeHistoryState_DoExit_Implementation,
    // Operation "CheckTransitions" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_CheckTransitions_Implementation
};

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                    Read functions for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMCompositeHistoryState/<AutoCreatedOperation>GetHistoryStateID
// Method      :        STMCompositeHistoryState_GetHistoryStateID(tSTMCompositeHistoryState_Ref const This)
// Visibility  :        public
// Description :        Read value from HistoryStateID (Multiplicity [1])
//                      HistoryStateID is an index in the StateTable owed by the statechart.
//                      The item in the table is used to save the curent sub-state before leaving the history state,
//                      for been able to restore the sub-state at the entry.
//                      
//                      After initialization the Item in the table is NULL, at first activation of the
//                      ComopositeHistoryState there is no previous state to restore, the default entry point is used.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMCompositeHistoryState_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        uint16
// =====================================================================================================================
uint16 STMCompositeHistoryState_GetHistoryStateID(tSTMCompositeHistoryState_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetHistoryStateID());
}

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMCompositeHistoryState/<Operation>GetAtomicEntry
// Method      :        STMCompositeHistoryState_GetAtomicEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        This method returns the atomic entry state form the state.
//                      
//                      If HistoryState is not not NULL, it returns the History.
//                      Else it return the Entry state attribute.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMCompositeHistoryState_GetAtomicEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
{
    tSTMCompositeHistoryState_Ref const This = STMState_TO_STMCompositeHistoryState(parentRef);

    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMCompositeHistoryState", "GetAtomicEntry", This, pStateChart)
    {
        // Recover the history state
        returnValue = STMStateChart_GetInternalState(pStateChart, mGetHistoryStateID());
        
        if( NULL == returnValue ) // PRQA S 1311
        {
            // There is no memorized history
            // The default entry is used
            returnValue = This->pEntryState;
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMCompositeHistoryState", "GetAtomicEntry")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMCompositeHistoryState/<Operation>DoExit
// Method      :        STMCompositeHistoryState_DoExit_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Execute exit action for this state.
//                      In addition of the execution of the exit action, the CompositeHistoryState shall save the
//                      curent state before leaving.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMCompositeHistoryState_DoExit_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
{
    tSTMCompositeHistoryState_Ref const This = STMState_TO_STMCompositeHistoryState(parentRef);

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMCompositeHistoryState", "DoExit", This, pStateChart)
    {
        // Get curent State
        const tSTMState_Ref pCurrentState = STMStateChart_GetCurentState(pStateChart);
        
        // Save curent state in the history
        STMStateChart_SetInternalState(pStateChart, mGetHistoryStateID(), pCurrentState);
        STMState_DoExit_Explicit(STMCompositeHistoryState_TO_STMState(This), pStateChart); // PRQA S 310
    }
    mLEAVE_METHOD("STMCompositeHistoryState", "DoExit")
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
