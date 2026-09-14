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
// Entity:              STMRegion (Class)
// Description:         A region is an orthogonal  part (At one time only one state of the region can be active ) of
//                      either a ANDState or a StateChart.
//                      From a model point view, It contains states and transitions.
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
#define STMRegion_PRIVATE_VISIBILITY
#define STMRegion_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMRegion_VTBL STMRegion_VTBL = {
    // Operation "Activate" defined by the Class "STMRegion", implemented in the Class "STMRegion"
    &STMRegion_Activate_Implementation,
    // Operation "DeActivate" defined by the Class "STMRegion", implemented in the Class "STMRegion"
    &STMRegion_DeActivate_Implementation,
    // Operation "ProcessEvt" defined by the Class "STMRegion", implemented in the Class "STMRegion"
    &STMRegion_ProcessEvt_Implementation,
    // Operation "IsIn" defined by the Class "STMRegion", implemented in the Class "STMRegion"
    &STMRegion_IsIn_Implementation
};

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                    Read functions for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<AutoCreatedOperation>GetCurentStateID
// Method      :        STMRegion_GetCurentStateID(tSTMRegion_Ref const This)
// Visibility  :        public
// Description :        Read value from CurentStateID (Multiplicity [1])
//                      CurentStateID is an index in the StateTable owed by the statechart.
//                      The item in the table is used to save the curent state in the Region.
//                      When item is NULL, this mean that the Region is not activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type       | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        uint16
// =====================================================================================================================
uint16 STMRegion_GetCurentStateID(tSTMRegion_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetCurentStateID());
}

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>GetCurentState
// Method      :        STMRegion_GetCurentState(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public
// Description :        Returns a pointer to the curent state.
//                      Returns NULL if the statechart is not activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMRegion_GetCurentState(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMRegion", "GetCurentState", This, pStateChart)
    {
        returnValue = STMStateChart_GetInternalState(pStateChart, mGetCurentStateID());
    }
    mLEAVE_METHOD("STMRegion", "GetCurentState")
    return (returnValue);
}

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>Activate
// Method      :        STMRegion_Activate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Activate the Region.
//                      At activation time the entry state is activated (entry actions are executed).
//                      After actiavtion the Region is able to process events.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMRegion_Activate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMRegion", "Activate", This, pStateChart)
    {
        const tSTMState_Ref pCurrentState = STMState_GetAtomicEntry(This->pEntryState, pStateChart);
        
        STMState_DoEntriesFromParent(pCurrentState, pStateChart, NULL);
        STMStateChart_SetInternalState(pStateChart, mGetCurentStateID(), pCurrentState);
    }
    mLEAVE_METHOD("STMRegion", "Activate")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>DeActivate
// Method      :        STMRegion_DeActivate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Deactivate the Region.
//                      Active state is exited, exit actions are executed.
//                      After activation the Region is not consuming any event.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMRegion_DeActivate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMRegion", "DeActivate", This, pStateChart)
    {
        const tSTMState_Ref pCurrentState = STMStateChart_GetInternalState(pStateChart, mGetCurentStateID());
        
        STMState_DoExitsUntilParent(pCurrentState, pStateChart, NULL); // PRQA S 3200 
        STMStateChart_SetInternalState(pStateChart, mGetCurentStateID(), NULL);
    }
    mLEAVE_METHOD("STMRegion", "DeActivate")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>ProcessEvt
// Method      :        STMRegion_ProcessEvt_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public, virtual
// Description :        Verify if the event can be consumed in the curent state, and exectute the transition if needed.
//                      Returns cTrue if the event is consumed.
//                      
//                      Note that this function allways returns false if the region is deactivated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMRegion_ProcessEvt_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMRegion", "ProcessEvt", This, pStateChart, pEvent)
    {
        const tSTMState_Ref pCurrentState = STMStateChart_GetInternalState(pStateChart, mGetCurentStateID());
        tSTMPath            Path;
        tSTMState_Ref       pState;
        boolean             Chk;
        
        // Check if a path exist to another state.
        Chk = STMState_CheckTransitionsUntilRoot(pCurrentState, pStateChart, pEvent, &Path);
        if( cTrue == Chk )
        {
            // A path has be found
            tSTMTransition_Ref pTrans;
            tSTMState_Ref      pExitedState = NULL;
            tSTMState_Ref      pNewState;
        
            // get Last transition form path
            pTrans = STMPath_CurentItem(&Path);
            mCGAssert(NULL != pTrans);
            
             // The New state is the target of last transition in the path
            pState = (tSTMState_Ref)STMTransition_GetTarget(pTrans); // PRQA S 310
            mCGAssert(NULL != pState);
            pNewState = STMState_GetAtomicEntry(pState, pStateChart);
            
            // Leave curent state
            // if it is a reaction in state, no change of state is needed
            if( NULL != pNewState ) // PRQA S 1311
            {
                // pCurentState and its parents shall be left
                pExitedState = STMState_DoExitsUntilParent(pCurrentState, pStateChart, pNewState);
            }
            else
            {
            }
            // Execute actions from path
            STMPath_DoActions(&Path, pStateChart, pEvent);
            // Enter new state
            // if it is a reaction in state, no change of state is needed
            if( NULL != pNewState ) // PRQA S 1311
            {
                // if it is a reaction in state, no change of state is needed
                STMStateChart_SetInternalState(pStateChart, mGetCurentStateID(), pNewState);
                STMState_DoEntriesFromParent(pNewState, pStateChart, pExitedState);
            }
            else
            {
            }
            returnValue = cTrue;
        }
        else
        {
            returnValue = cFalse;               // No path to another state, event is not processed
        }
    }
    mLEAVE_METHOD("STMRegion", "ProcessEvt")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>IsIn
// Method      :        STMRegion_IsIn_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const pState)
// Visibility  :        public, virtual
// Description :        Return true if the curent state is "This" state or one "This" sub-state.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// tSTMState_Ref       | pState(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMRegion_IsIn_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const pState)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMRegion", "IsIn", This, pStateChart, pState)
    {
        tSTMState_Ref const pCurrentState = STMStateChart_GetInternalState(pStateChart, mGetCurentStateID());
        
        // pState is active if it is a parent of the curent one.
        returnValue = STMState_IsChildOf(pCurrentState, pState);
    }
    mLEAVE_METHOD("STMRegion", "IsIn")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
