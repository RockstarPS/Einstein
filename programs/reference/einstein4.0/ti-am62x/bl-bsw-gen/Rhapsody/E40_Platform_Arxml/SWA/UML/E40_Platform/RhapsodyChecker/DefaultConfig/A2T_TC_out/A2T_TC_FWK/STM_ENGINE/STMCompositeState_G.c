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
// Entity:              STMCompositeState (Class)
// Description:         A Composite State is a State which contains other States.
//                      
//                      This object do not get the list of owned states.
//                      This choice is resulting to the fact that event are propagated form the child to the parent.
//                      On that case, the child can easily propagate events to the parent, and parent does'nt need to
//                      known the children.
//                      
//                      The composite state need only to known the entry state for the initial activation.
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
#define STMCompositeState_PRIVATE_VISIBILITY
#define STMCompositeState_PROTECTED_VISIBILITY
#define STMStateVertex_PROTECTED_VISIBILITY
#define STMState_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMCompositeState_VTBL STMCompositeState_VTBL = {
    // Operation "IsActivable" defined by the Class "STMStateVertex", implemented in the Class "STMStateVertex"
    &STMStateVertex_IsActivable_Implementation,
    // Operation "GetAtomicEntry" defined by the Class "STMState", implemented in the Class "STMCompositeState"
    &STMCompositeState_GetAtomicEntry_Implementation,
    // Operation "DoEntry" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_DoEntry_Implementation,
    // Operation "DoExit" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_DoExit_Implementation,
    // Operation "CheckTransitions" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_CheckTransitions_Implementation
};

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMCompositeState/<Operation>GetAtomicEntry
// Method      :        STMCompositeState_GetAtomicEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        This method shall returns the atomic entry state form the state.
//                      For Composite State, it return the Entry state attribute
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMCompositeState_GetAtomicEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
{
    tSTMCompositeState_Ref const This = STMState_TO_STMCompositeState(parentRef);

    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMCompositeState", "GetAtomicEntry", This, pStateChart)
    {
        UNREFERENCED_PARAMETER(pStateChart);
        returnValue = This->pEntryState;
    }
    mLEAVE_METHOD("STMCompositeState", "GetAtomicEntry")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
