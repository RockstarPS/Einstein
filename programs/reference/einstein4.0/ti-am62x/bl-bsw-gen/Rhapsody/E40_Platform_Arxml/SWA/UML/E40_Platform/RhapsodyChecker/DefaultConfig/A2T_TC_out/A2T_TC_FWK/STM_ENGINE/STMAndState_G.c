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
// Entity:              STMAndState (Class)
// Description:         A ANDState state is decomposed into two or more orthogonal regions. Each region has a set of
//                      mutually exclusive disjoint subvertices and a set of transitions.
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
#define STMAndState_PRIVATE_VISIBILITY
#define STMAndState_PROTECTED_VISIBILITY
#define STMStateVertex_PROTECTED_VISIBILITY
#define STMState_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMAndState_VTBL STMAndState_VTBL = {
    // Operation "IsActivable" defined by the Class "STMStateVertex", implemented in the Class "STMStateVertex"
    &STMStateVertex_IsActivable_Implementation,
    // Operation "GetAtomicEntry" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_GetAtomicEntry_Implementation,
    // Operation "DoEntry" defined by the Class "STMState", implemented in the Class "STMAndState"
    &STMAndState_DoEntry_Implementation,
    // Operation "DoExit" defined by the Class "STMState", implemented in the Class "STMAndState"
    &STMAndState_DoExit_Implementation,
    // Operation "CheckTransitions" defined by the Class "STMState", implemented in the Class "STMAndState"
    &STMAndState_CheckTransitions_Implementation
};

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMAndState/<Operation>DoEntry
// Method      :        STMAndState_DoEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Execute entry action for this state
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMAndState_DoEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
{
    tSTMAndState_Ref const This = STMState_TO_STMAndState(parentRef);

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMAndState", "DoEntry", This, pStateChart)
    {
        t_MAX_CARD CntRegion;
        
        STMState_DoEntry(STMAndState_TO_STMState(This), pStateChart);// PRQA S 310
        
        for( CntRegion=0; CntRegion < This->Regions_MAX_CARD; CntRegion++ )
        {
            tSTMRegion_Ref pRegion = This->pRegionsTable[CntRegion];
            STMRegion_Activate(pRegion, pStateChart);
        }
    }
    mLEAVE_METHOD("STMAndState", "DoEntry")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMAndState/<Operation>DoExit
// Method      :        STMAndState_DoExit_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Execute exit action for this state
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMAndState_DoExit_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
{
    tSTMAndState_Ref const This = STMState_TO_STMAndState(parentRef);

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMAndState", "DoExit", This, pStateChart)
    {
        t_MAX_CARD CntRegion;
        
        for( CntRegion=0; CntRegion < This->Regions_MAX_CARD; CntRegion++ )
        {
            tSTMRegion_Ref pRegion = This->pRegionsTable[CntRegion];
            STMRegion_DeActivate(pRegion, pStateChart);
        }
        STMState_DoExit(STMAndState_TO_STMState(This), pStateChart); // PRQA S 310
    }
    mLEAVE_METHOD("STMAndState", "DoExit")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMAndState/<Operation>CheckTransitions
// Method      :        STMAndState_CheckTransitions_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
// Visibility  :        public, virtual
// Description :        Checks if the recieve event can fire an outgoing transition.
//                      Returns true if the event is consumed
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// tSTMPath_Ref        | pPath(In)        | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMAndState_CheckTransitions_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
{
    tSTMAndState_Ref const This = STMState_TO_STMAndState(parentRef);

    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_4("STMAndState", "CheckTransitions", This, pStateChart, pEvent, pPath)
    {
        t_MAX_CARD CntRegion;
        boolean    Chk;
        
        for( CntRegion=0; (CntRegion < This->Regions_MAX_CARD) && (cFalse == returnValue); CntRegion++ )
        {
            tSTMRegion_Ref pRegion = This->pRegionsTable[CntRegion];
            Chk = STMRegion_ProcessEvt(pRegion, pStateChart, pEvent);
            if( cTrue == Chk )
            {
                returnValue = cTrue;
            }
            else
            {
            }
        }
        if( cFalse == returnValue )
        {
            STMState_CheckTransitions(STMAndState_TO_STMState(This), pStateChart, pEvent, pPath); // PRQA S 310
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMAndState", "CheckTransitions")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
