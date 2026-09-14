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
// Entity:              STMStateChart (Class)
// Description:         A Statechart own the curent state and the structure of the state machine.
//                      The StateChart class is instanciated as many time as class which own the Statechart is
//                      instanciated.
//                      
//                      The Statechart class owns :
//                      - The dynamic data about the state machine 
//                          - The curent state(states if AND State are used) 
//                          - The history (for history connector).
//                      - The structure of the state machine (a pointer to the root region)
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
#define STMStateChart_PRIVATE_VISIBILITY
#define STMStateChart_PROTECTED_VISIBILITY
#define ISysEventNotification_PROTECTED_VISIBILITY

// ---------------------------------------------------------------------------------------------------------------------
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// =====================================================================================================================
//                                                Virtual table instance
// =====================================================================================================================
tSTMStateChart_VTBL STMStateChart_VTBL = {
    // Items from the Interface "ISysEventNotification"
    {
        // Operation "ProcessEvt" defined by the Interface "ISysEventNotification", implemented in the Class "STMStateChart"
        &STMStateChart_ProcessEvt_Implementation
    },
    // Operation "Init" defined by the Class "STMStateChart", implemented in the Class "STMStateChart"
    &STMStateChart_Init_Implementation,
    // Operation "Activate" defined by the Class "STMStateChart", implemented in the Class "STMStateChart"
    &STMStateChart_Activate_Implementation,
    // Operation "DeActivate" defined by the Class "STMStateChart", implemented in the Class "STMStateChart"
    &STMStateChart_DeActivate_Implementation,
    // Operation "IsIn" defined by the Class "STMStateChart", implemented in the Class "STMStateChart"
    &STMStateChart_IsIn_Implementation
};

// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                              Interface(s) initialization
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/ISysEventNotification/<AutoCreatedOperation>ToSTMStateChart_Allocate
// Method      :        ISysEventNotification_ToSTMStateChart_Allocate(tISysEventNotification_Ref const This, tSTMStateChart_Ref const pSTMStateChart)
// Visibility  :        public
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         |   Name(Direction)   |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tISysEventNotification_Ref              | This(In)            | Interface instance
// tSTMStateChart_Ref  | pSTMStateChart(In)  | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void ISysEventNotification_ToSTMStateChart_Allocate(tISysEventNotification_Ref const This, tSTMStateChart_Ref const pSTMStateChart)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_2("ISysEventNotification", "ToSTMStateChart_Allocate", This, pSTMStateChart)
    {
        mCGAssert(NULL != pSTMStateChart); // To avoid QAC Msg(2:0506) Dereferencing pointer value that is possibly NULL.
        This->pVTBL = &pSTMStateChart->pVTBL->ISysEventNotification;
        This->theObject = (void *) pSTMStateChart; // PRQA S 311
    }
    mLEAVE_METHOD("ISysEventNotification", "ToSTMStateChart_Allocate")
}

// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                    Read functions for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<AutoCreatedOperation>GetTheObject
// Method      :        STMStateChart_GetTheObject(tSTMStateChart_Ref const This)
// Visibility  :        public
// Description :        Read value from TheObject (Multiplicity [1])
//                      TheObject attribute is a pointer to the object which own the statechart.
//                      It is needed to have this reference for calling the action (state entry/exit or transition).
//                      Actions are methods from "Theobject"
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void *
// =====================================================================================================================
void * STMStateChart_GetTheObject(tSTMStateChart_Ref const This)
{
    mCGAssert(NULL != This);
    return (mGetTheObject());
}

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>GetCurentState
// Method      :        STMStateChart_GetCurentState(tSTMStateChart_Ref const This)
// Visibility  :        public
// Description :        Returns a pointer to the curent state.
//                      Returns NULL if the statechart is not activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMStateChart_GetCurentState(tSTMStateChart_Ref const This)
{
    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMStateChart", "GetCurentState", This)
    {
        returnValue = STMRegion_GetCurentState(This->pRootRegion, This);
    }
    mLEAVE_METHOD("STMStateChart", "GetCurentState")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>GetInternalState
// Method      :        STMStateChart_GetInternalState(tSTMStateChart_Ref const This, uint16 const Index)
// Visibility  :        public
// Description :        Method reserved for internal Engine purpose.
//                      Allow to read an item in the StateTable.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// uint16              | Index(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
tSTMState_Ref STMStateChart_GetInternalState(tSTMStateChart_Ref const This, uint16 const Index)
{
    tSTMState_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMStateChart", "GetInternalState", This, Index)
    {
        if( Index < This->StateTable_MAX_CARD )
        {
            returnValue = mGetpStateTable_Table()[Index];
        }
        else
        {
            // Error: the State size is not propoerly configured.
            mREPORT_CONFIGURATION_ERROR();
            returnValue = NULL;
        }
    }
    mLEAVE_METHOD("STMStateChart", "GetInternalState")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>SetInternalState
// Method      :        STMStateChart_SetInternalState(tSTMStateChart_Ref const This, uint16 const Index, tSTMState_Ref const pState)
// Visibility  :        public
// Description :        Method reserved for internal Engine purpose.
//                      Allow to set an item in the StateTable.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// uint16              | Index(In)       | None
// tSTMState_Ref       | pState(In)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMStateChart_SetInternalState(tSTMStateChart_Ref const This, uint16 const Index, tSTMState_Ref const pState)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMStateChart", "SetInternalState", This, Index, pState)
    {
        if( Index < This->StateTable_MAX_CARD )
        {
            mGetpStateTable_Table()[Index] = pState;
        }
        else
        {
            // Error: the State size is not propoerly configured.
            mREPORT_CONFIGURATION_ERROR();
        }
    }
    mLEAVE_METHOD("STMStateChart", "SetInternalState")
}

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual methods sub-section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>Init
// Method      :        STMStateChart_Init_Implementation(tSTMStateChart_Ref const This)
// Visibility  :        public, virtual
// Description :        Initialize the Statechart.
//                      After initialization, Statechart is Deactivated.
//                      History from HistoryConnectors is lost.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMStateChart_Init_Implementation(tSTMStateChart_Ref const This)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMStateChart", "Init", This)
    {
        t_MAX_CARD Cnt;
        
        for( Cnt=0; Cnt < This->StateTable_MAX_CARD; Cnt++)
        {
            mGetpStateTable_Table()[Cnt] = NULL;
        }
    }
    mLEAVE_METHOD("STMStateChart", "Init")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>Activate
// Method      :        STMStateChart_Activate_Implementation(tSTMStateChart_Ref const This)
// Visibility  :        public, virtual
// Description :        Activate the statechart.
//                      At activation time the entry state is activated (entry actions are executed).
//                      After actiavtion the statechart is able to process events.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMStateChart_Activate_Implementation(tSTMStateChart_Ref const This)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMStateChart", "Activate", This)
    {
        STMRegion_Activate(This->pRootRegion, This);
    }
    mLEAVE_METHOD("STMStateChart", "Activate")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>DeActivate
// Method      :        STMStateChart_DeActivate_Implementation(tSTMStateChart_Ref const This)
// Visibility  :        public, virtual
// Description :        Deactivate the statechart.
//                      Active state is exited, exit actions are executed.
//                      After activation the statechart is not consuming any event.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
void STMStateChart_DeActivate_Implementation(tSTMStateChart_Ref const This)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMStateChart", "DeActivate", This)
    {
        STMRegion_DeActivate(This->pRootRegion, This);
    }
    mLEAVE_METHOD("STMStateChart", "DeActivate")
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>IsIn
// Method      :        STMStateChart_IsIn_Implementation(tSTMStateChart_Ref const This, tSTMState_Ref const pState)
// Visibility  :        public, virtual
// Description :        Return true if the curent state is "This" state or one "This" sub-state.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateChart_Ref  | This(In)        | Class reference
// tSTMState_Ref       | pState(In)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMStateChart_IsIn_Implementation(tSTMStateChart_Ref const This, tSTMState_Ref const pState)
{
    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMStateChart", "IsIn", This, pState)
    {
        returnValue = STMRegion_IsIn(This->pRootRegion, This, pState);
    }
    mLEAVE_METHOD("STMStateChart", "IsIn")
    return (returnValue);
}

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateChart/<Operation>ProcessEvt
// Method      :        STMStateChart_ProcessEvt_Implementation(void * const parentRef, Event_Ref const pEvent)
// Visibility  :        public, virtual
// Description :        Verify if the event can be consumed in the curent state, and exectute the transition if needed.
//                      Returns cTrue if the event is consumed.
//                      
//                      Note that this functiion allways returns false if the statechate is deactivated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//    Type    | Name(Direction) |                                       Description
// ---------------------------------------------------------------------------------------------------------------------
// void *     | parentRef(In)   | Pointer to the actual object
// Event_Ref  | pEvent(In)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
boolean STMStateChart_ProcessEvt_Implementation(void * const parentRef, Event_Ref const pEvent)
{
    tSTMStateChart_Ref const This = (tSTMStateChart_Ref)(parentRef);

    boolean returnValue = cFalse;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMStateChart", "ProcessEvt", This, pEvent)
    {
        returnValue = STMRegion_ProcessEvt(mGetpRootRegion(), This, pEvent);
    }
    mLEAVE_METHOD("STMStateChart", "ProcessEvt")
    return (returnValue);
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
