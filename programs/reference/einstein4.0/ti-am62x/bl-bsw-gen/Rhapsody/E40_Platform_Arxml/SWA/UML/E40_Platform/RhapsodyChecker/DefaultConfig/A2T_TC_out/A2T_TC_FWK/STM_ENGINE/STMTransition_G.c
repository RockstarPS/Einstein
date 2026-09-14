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
// Entity:              STMTransition (Class)
// Description:         A transition is a directed relationship between a source vertex and a target vertex. 
//                      
//                      It may be part of a compound transition (a chain of transition between two states), which takes
//                      the state machine from one state to another, representing the complete response of the state
//                      machine to an occurrence of an event of a particular type.
//                      
//                      Note that for compound transition, only first transition  is trigered by an event, other can
//                      only define guards.
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
#define STMTransition_PRIVATE_VISIBILITY
#define STMTransition_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                    Read functions for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetAction
// Method      :        STMTransition_GetAction(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Action (Multiplicity [1])
//                      Designates the function which is executed when the transition is passed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMTransitionActionFct
// =====================================================================================================================
STMTransitionActionFct STMTransition_GetAction(tSTMTransition_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetAction());
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetGuard
// Method      :        STMTransition_GetGuard(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Guard (Multiplicity [1])
//                      A guard is a function pointer to a function which can returns True or False.
//                      
//                      The guard is evaluated when an event occurrence is dispatched by the state machine. If the
//                      guard is true at that time, the transition may be enabled; otherwise, it is disabled. Guards
//                      should be pure expressions without side effects. Guard expressions with side effects are ill
//                      formed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMGuardFct
// =====================================================================================================================
STMGuardFct STMTransition_GetGuard(tSTMTransition_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetGuard());
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetEvent
// Method      :        STMTransition_GetEvent(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Event (Multiplicity [1])
//                      Specifies the triggers that may fire the transition.
//                      Three case are possible :
//                      - The event is eSTMNullEventID, the transition is designed to be polled.
//                      - The event is eSTMNonEventID, the transition is part of a compound transition, the trigger is
//                      defined by the first transition in the list.
//                      - The event is a specific event which fire the transition.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        EventID
// =====================================================================================================================
EventID STMTransition_GetEvent(tSTMTransition_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetEvent());
}

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>IsPassed
// Method      :        STMTransition_IsPassed(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public
// Description :        Check if the transition can be passed. 
//                      To pass a transition, the event shall be the expected one, the guard shall be true.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMTransition_IsPassed(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMTransition", "IsPassed", This, pStateChart, pEvent)
    {
        tEventID EventID;
        
        if( NULL != pEvent ) // PRQA S 1311
        {
            EventID = pEvent->ID;
        }
        else
        {
            EventID = eSTMNullEventID;
        }
        if( (mGetEvent() == EventID) || (mGetEvent() == eSTMNonEventID) )
        {
            void* theObject;
        
            if( NULL != mGetGuard() )
            {
                // Get the guard function pointer (due to QAC warning)
                const tSTMGuardFct pFnGuard = mGetGuard();
        
                // Get the object pointer (due to QAC warning)
                theObject = STMStateChart_GetTheObject(pStateChart);
                // Execute the guard function
                returnValue = pFnGuard(theObject, pEvent);
            }
            else
            {
                returnValue = cTrue;
            }
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMTransition", "IsPassed")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>DoAction
// Method      :        STMTransition_DoAction(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public
// Description :        Execute the action associated to the transition.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMTransition_DoAction(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMTransition", "DoAction", This, pStateChart, pEvent)
    {
        void* theObject;
        
        if( NULL != mGetAction() )
        {
            // Get the action function pointer (due to QAC warning)
            const tSTMTransitionActionFct pFnAction = mGetAction();
        
            // Get the object pointer (due to QAC warning)
            theObject = STMStateChart_GetTheObject(pStateChart);
            // Execute the action
            pFnAction(theObject, pEvent);
        }
        else
        {
        }
    }
    mLEAVE_METHOD("STMTransition", "DoAction")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>GetTarget
// Method      :        STMTransition_GetTarget(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        returns the vertex target.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMStateVertex_Ref
// =====================================================================================================================
tSTMStateVertex_Ref STMTransition_GetTarget(tSTMTransition_Ref const This)
{
    tSTMStateVertex_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMTransition", "GetTarget", This)
    {
        returnValue = This->pTarget;
    }
    mLEAVE_METHOD("STMTransition", "GetTarget")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
