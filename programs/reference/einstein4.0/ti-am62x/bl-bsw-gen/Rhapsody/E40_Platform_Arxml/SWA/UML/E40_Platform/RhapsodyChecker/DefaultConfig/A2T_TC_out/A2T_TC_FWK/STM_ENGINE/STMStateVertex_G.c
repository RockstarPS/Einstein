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
// Generated on Tue Aug 06 13:07:39 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              STMStateVertex (Class)
// Description:         A StateVertex is an abstraction of a node in a state machine graph. 
//                      In general, it can be the source or destination of any number of transitions. 
//                      
//                      For example, a connector is a StateVertex, a state is a StateVertex.
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
#define STMStateVertex_PRIVATE_VISIBILITY
#define STMStateVertex_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMStateVertex_VTBL STMStateVertex_VTBL = {
    // Operation "IsActivable" defined by the Class "STMStateVertex", implemented in the Class "STMStateVertex"
    &STMStateVertex_IsActivable_Implementation
};

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateVertex/<Operation>GetTransition
// Method      :        STMStateVertex_GetTransition(tSTMStateVertex_Ref const This, uint16 const Index)
// Visibility  :        public
// Description :        Returns the outgoing transition related to the index.
//                      Return NULL if index is out of bounds.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateVertex_Ref  | This(In)        | Class reference
// uint16               | Index(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMTransition_Ref
// =====================================================================================================================
tSTMTransition_Ref STMStateVertex_GetTransition(tSTMStateVertex_Ref const This, uint16 const Index)
{
    tSTMTransition_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMStateVertex", "GetTransition", This, Index)
    {
        if( Index < This->Transitions_MAX_CARD )
        {
            returnValue = This->pTransitionsTable[Index];
        }
        else
        {
            returnValue = NULL;
        }
    }
    mLEAVE_METHOD("STMStateVertex", "GetTransition")
    return (returnValue);
}

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateVertex/<Operation>IsActivable
// Method      :        STMStateVertex_IsActivable_Implementation(tSTMStateVertex_Ref const This)
// Visibility  :        public, virtual
// Description :        Return True if the StateVertex can be activated.
//                      
//                      When an vertex is not activable, the ingoing and outgoing transitions shall be passed
//                      simultaneously (with the same event).
//                      
//                      When a vertex is activable, it receives events which are triggering its outgoing transitions.
//                      
//                      For example, connectors are not activable, state are activable.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateVertex_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMStateVertex_IsActivable_Implementation(tSTMStateVertex_Ref const This)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMStateVertex", "IsActivable", This)
    {
        returnValue = cTrue;
    }
    mLEAVE_METHOD("STMStateVertex", "IsActivable")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
