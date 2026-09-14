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
// Entity:              STMState (Class)
// Description:         A state models a situation during which some (usually implicit) invariant condition holds. The
//                      invariant may represent a static situation such as an object waiting for some external event to
//                      occur.
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
#define STMState_PRIVATE_VISIBILITY
#define STMState_PROTECTED_VISIBILITY
#define STMStateVertex_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMState_VTBL STMState_VTBL = {
    // Operation "IsActivable" defined by the Class "STMStateVertex", implemented in the Class "STMStateVertex"
    &STMStateVertex_IsActivable_Implementation,
    // Operation "GetAtomicEntry" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_GetAtomicEntry_Implementation,
    // Operation "DoEntry" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_DoEntry_Implementation,
    // Operation "DoExit" defined by the Class "STMState", implemented in the Class "STMState"
    &STMState_DoExit_Implementation,
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
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<AutoCreatedOperation>GetEntryAction
// Method      :        STMState_GetEntryAction(tSTMState_Ref const This)
// Visibility  :        public
// Description :        Read value from EntryAction (Multiplicity [1])
//                      Specify the function to be called when the state is activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMActionFct
// =====================================================================================================================
STMActionFct STMState_GetEntryAction(tSTMState_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetEntryAction());
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<AutoCreatedOperation>GetExitAction
// Method      :        STMState_GetExitAction(tSTMState_Ref const This)
// Visibility  :        public
// Description :        Read value from ExitAction (Multiplicity [1])
//                      Specify the function to be called when the state is exited.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMActionFct
// =====================================================================================================================
STMActionFct STMState_GetExitAction(tSTMState_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetExitAction());
}

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoEntriesFromParent
// Method      :        STMState_DoEntriesFromParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const Parent)
// Visibility  :        public
// Description :        Execute entry action for this state and its parents, until the state "Parent".
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// tSTMState_Ref       | Parent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMState_DoEntriesFromParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const Parent)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMState", "DoEntriesFromParent", This, pStateChart, Parent)
    {
        tSTMState_Ref pState = Parent;
        
        // Exit shall be done from Parent to child.
        // Whereas states are chained from Child to parent
        do
        {
            // Retreive the child of pState
            tSTMState_Ref pSupposedChild = This;
        
            while( (pSupposedChild->pParent != pState) && (NULL != pSupposedChild->pParent) ) // PRQA S 1311
            {
                pSupposedChild = pSupposedChild->pParent;
            }
            // if Parent of "pSupposedChild" is not "pState something" is wrong, "This" is not Child of "Parent"
            if( pSupposedChild->pParent == pState )
            {
                // Iterate
                pState = pSupposedChild;
        
                // Do exit
                STMState_DoEntry(pState, pStateChart);
            }
            else
            {
                // Error: "This" is not child of "Parent" when it shall be.
                mREPORT_CONFIGURATION_ERROR();
        
                // Exit the Loop
                pState = This;
            }
        }
        while( pState != This );
    }
    mLEAVE_METHOD("STMState", "DoEntriesFromParent")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoExitsUntilParent
// Method      :        STMState_DoExitsUntilParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const NewState)
// Visibility  :        public
// Description :        Execute exit actions for this state and for needed parents.
//                      The curent transition target is specified by "NewState".
//                      Parents that shall be exited are the one which are not common beetween this state and the new
//                      state.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// tSTMState_Ref       | NewState(In)     | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMState_DoExitsUntilParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const NewState)
{
    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMState", "DoExitsUntilParent", This, pStateChart, NewState)
    {
        tSTMState_Ref pState = This;
        boolean       Chk = cFalse;
        
        while( NULL != pState ) // PRQA S 1311
        {
            Chk = STMState_IsChildOf(pState, NewState);
            if( cTrue == (!Chk))
            { 
                STMState_DoExit(pState, pStateChart);
                pState = pState->pParent;
            }
            else
            {
                break;
            }
        }
        returnValue = pState;
    }
    mLEAVE_METHOD("STMState", "DoExitsUntilParent")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>IsChildOf
// Method      :        STMState_IsChildOf(tSTMState_Ref const This, tSTMState_Ref const SupposedParent)
// Visibility  :        public
// Description :        Return True if "SupposedParent" is a Parent of this state.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      |   Name(Direction)   |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref  | This(In)            | Class reference
// tSTMState_Ref  | SupposedParent(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMState_IsChildOf(tSTMState_Ref const This, tSTMState_Ref const SupposedParent)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMState", "IsChildOf", This, SupposedParent)
    {
        tSTMState_Ref pState = This;
        
        while( (NULL != pState) && (SupposedParent != pState) ) // PRQA S 1311
        {
            pState = pState->pParent;
        }
        returnValue = ((NULL != pState) ? cTrue : cFalse); // PRQA S 1311
    }
    mLEAVE_METHOD("STMState", "IsChildOf")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>CheckTransitionsUntilRoot
// Method      :        STMState_CheckTransitionsUntilRoot(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
// Visibility  :        public
// Description :        Checks if the recieve event can fire an outgoing transition.
//                      For this state and also for parents.
//                      Returns true if the event is consumed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// tSTMPath_Ref        | pPath(In)        | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMState_CheckTransitionsUntilRoot(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_4("STMState", "CheckTransitionsUntilRoot", This, pStateChart, pEvent, pPath)
    {
        tSTMState_Ref pState = This;
        boolean       Chk = cFalse;
        
        while( NULL != pState ) // PRQA S 1311
        {
            Chk = STMState_CheckTransitions(pState, pStateChart, pEvent, pPath);
            // Check if this state can exit
            if( cTrue == Chk)
            {
                pState = NULL;
                returnValue = cTrue;
            }
            else
            {
                pState = pState->pParent;
            }
        }
    }
    mLEAVE_METHOD("STMState", "CheckTransitionsUntilRoot")
    return (returnValue);
}

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>GetAtomicEntry
// Method      :        STMState_GetAtomicEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        This method shall returns the atomic entry state form the state.
//                      For Atomic State,  it returns This
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMState_GetAtomicEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMState", "GetAtomicEntry", This, pStateChart)
    {
        UNREFERENCED_PARAMETER(pStateChart);
        returnValue = This;
    }
    mLEAVE_METHOD("STMState", "GetAtomicEntry")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoEntry
// Method      :        STMState_DoEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Execute entry action for this state
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMState_DoEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMState", "DoEntry", This, pStateChart)
    {
        void* theObject;
        
        if( NULL != mGetEntryAction() )
        {
            // Get the action function pointer (due to QAC warning)
            const tSTMActionFct pFnAction = mGetEntryAction();
        
            // Get the object pointer (due to QAC warning)
            theObject = STMStateChart_GetTheObject(pStateChart);
            // Execute the action
            pFnAction(theObject);
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMState", "DoEntry")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoExit
// Method      :        STMState_DoExit_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Execute exit action for this state
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMState_DoExit_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMState", "DoExit", This, pStateChart)
    {
        void* theObject;
        
        if( NULL != mGetExitAction() )
        {
             // Get the action function pointer (due to QAC warning)
            const tSTMActionFct pFnAction = mGetExitAction();
             
            // Get the object pointer (due to QAC warning)
            theObject = STMStateChart_GetTheObject(pStateChart);
            // Execute the action
            pFnAction(theObject);
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMState", "DoExit")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>CheckTransitions
// Method      :        STMState_CheckTransitions_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
// Visibility  :        public, virtual
// Description :        Checks if the recieve event can fire an outgoing transition.
//                      Returns true if the event is consumed
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// tSTMPath_Ref        | pPath(In)        | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMState_CheckTransitions_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_4("STMState", "CheckTransitions", This, pStateChart, pEvent, pPath)
    {
        tSTMTransition_Ref pTrans;
        tEvent_Ref         pIEvent = pEvent;
        boolean            Chk;
        
        pTrans = STMPath_First(pPath, STMState_TO_STMStateVertex(This));
        while( NULL != pTrans ) // PRQA S 1311
        {
            // Curent Loop iterate on the transition tree.
            // Exploration of the tree is done with some priorities on three possible directions
            // First direction  - Try to pass curent transition, go to the child
            // Second direction - Go to the sibling ( transition owned by the same StateVetrex as the curent one )
            // last direction   - Go back to the sibling of the parent
        
            // Iteration stops in two cases :
            // - the exploration go back to the root
            // - The exploration reached a StateVertex which is not a connector
        
            // First direction - Try to pass curent transition, go to the child
            Chk = STMTransition_IsPassed(pTrans, pStateChart, pIEvent); 
            if( cTrue == Chk )
            {
                // Check if the path is completed, (if it reached a State)
                Chk = STMStateVertex_IsActivable(pTrans->pTarget); 
                if( cTrue == Chk )
                {
                    // A path has been found until a state, the method can exit
                    returnValue = cTrue;
                    pTrans = NULL;
                }
                else
                {
                    // The path ends to a connector, exploration shall continue
                    // In such case event should not be counted for next transitions till next state
                    pIEvent = NULL;
        
                    // Next transition to process
                    pTrans = STMPath_PassCurentTransition(pPath);
        
                    if( NULL == pTrans ) // PRQA S 1311
                    {
                        // The transition cannot be passed, the path is too long. The exploration continue to other
                        // possible path.
                        pTrans = STMPath_Next(pPath);
                        // Restore the initial state of the event for this path
                        pIEvent = pEvent;
                    }
                    else
                    {
                        // Next transition is found, loop shall continue
                    }
                }
            }
            else
            {
                // Transition is not passed, take the next transition from the state
                pTrans = STMPath_Next(pPath);
            }
        }
    }
    mLEAVE_METHOD("STMState", "CheckTransitions")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
