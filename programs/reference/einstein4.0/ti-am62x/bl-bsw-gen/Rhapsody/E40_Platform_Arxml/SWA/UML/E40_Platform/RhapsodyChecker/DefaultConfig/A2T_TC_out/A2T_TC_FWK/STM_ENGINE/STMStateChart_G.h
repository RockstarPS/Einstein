#ifndef __STMStateChart_G_h__
#define __STMStateChart_G_h__
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
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMStateChart_PROTECTED_VISIBILITY))
#define ISysEventNotification_TO_STMStateChart(Ref)    ((tSTMStateChart_Ref)(Ref)->theObject)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "ISysEventNotification_TO_STMStateChart",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMStateChart_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMStateChart_VTBL_Access(classRef) (classRef)->pVTBL
#define STMStateChart_VTBL_ISysEventNotification_Access(classRef) (classRef)->pVTBL->ISysEventNotification.
#if (defined(STMStateChart_PROTECTED_VISIBILITY))
#define STMStateChart_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMStateChart_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMStateChart_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMStateChart_VTBL
{
    tISysEventNotification_VTBL ISysEventNotification;
    void (*Init)(tSTMStateChart_Ref const); // Defined by the Class "STMStateChart" as virtual
    void (*Activate)(tSTMStateChart_Ref const); // Defined by the Class "STMStateChart" as virtual
    void (*DeActivate)(tSTMStateChart_Ref const); // Defined by the Class "STMStateChart" as virtual
    boolean (*IsIn)(tSTMStateChart_Ref const, tSTMState_Ref const); // Defined by the Class "STMStateChart" as virtual
} tSTMStateChart_VTBL;
typedef tSTMStateChart_VTBL* tSTMStateChart_VTBL_Ref;

extern tSTMStateChart_VTBL STMStateChart_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMStateChart
{
    tSTMStateChart_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
// Size of StateTable[1..*]
    t_MAX_CARD StateTable_MAX_CARD; // Auto-generated <MaxCard>
// Reference to StateTable[1..*]
// StateTable is owning the the dynamic data about the state machine 
// - The curent state(states if AND State are used) 
// - The history (for history connector).
// 
// Region Class need to store the curent state.
// CompositeHistoryState need to store the last sub-state (the history).
// 
// The issue is that those classes shall be fully ROM based and cannot own any RAM attribute.
// For this reason all non-const attributes are owned by the statechart class. 
// Each Region and CompositeHistoryState get an item in the state table.
    tSTMState_Ref * const pStateTable_Table; // Auto-generated <FixedTable>
// TheObject attribute is a pointer to the object which own the statechart.
// It is needed to have this reference for calling the action (state entry/exit or transition).
// Actions are methods from "Theobject"
    void * TheObject; // public
// Pointer to manage the relation RootRegion(association, multiplicity[1])
// RootRegion
    tSTMRegion_Ref pRootRegion; // protected
} tSTMStateChart;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMStateChart_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateChart_StateTableTableInstanceName(instanceName) \
    STMStateChart_pStateTable_Table##instanceName
#define mSTMStateChart_StateTableTableInstance(instanceName,StateTable_MAX_CARD) \
    static tSTMState_Ref mSTMStateChart_StateTableTableInstanceName(instanceName)[StateTable_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateChart_Allocate(instanceName, StateTable_MAX_CARD, pStateTable_Table, TheObject, pRootRegion) \
                                                                                                                        \
mSTMStateChart_StateTableTableInstance(instanceName,StateTable_MAX_CARD) = pStateTable_Table; \
tSTMStateChart instanceName = {\
    &STMStateChart_VTBL, \
    StateTable_MAX_CARD, \
    mSTMStateChart_StateTableTableInstanceName(instanceName), \
    TheObject, \
    pRootRegion \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMStateChart_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateChart_Allocate_Explicit(instanceName, StateTable_MAX_CARD, pStateTable_Table, TheObject, pRootRegion) \
                                                                                                                        \
tSTMStateChart instanceName = {\
    &STMStateChart_VTBL, \
    StateTable_MAX_CARD, \
    pStateTable_Table, \
    TheObject, \
    pRootRegion \
}
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                              Interface(s) instanciation
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateChart_Allocate_ISysEventNotification(instanceName,objRef) \
    const tISysEventNotification instanceName = {&STMStateChart_VTBL.ISysEventNotification, (void *) objRef}

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
void ISysEventNotification_ToSTMStateChart_Allocate(tISysEventNotification_Ref const This, tSTMStateChart_Ref const pSTMStateChart);

// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                             Attributes with public access
// ---------------------------------------------------------------------------------------------------------------------

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
extern void * STMStateChart_GetTheObject(tSTMStateChart_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMStateChart_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "TheObject" (public) with reference argument
#define mGetXTheObject(Ref) STMStateChart_ROM_Access(Ref,TheObject)
// Read value from the attribute "TheObject" (public) without reference argument
#define mGetTheObject() STMStateChart_ROM_Access(This,TheObject)

#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMStateChart_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "pRootRegion" (protected) with reference argument
#define mGetXpRootRegion(Ref) STMStateChart_ROM_Access(Ref,pRootRegion)
// Read value from the attribute "pRootRegion" (protected) without reference argument
#define mGetpRootRegion() STMStateChart_ROM_Access(This,pRootRegion)

#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Attributes with private access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMStateChart_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for private, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "StateTable_MAX_CARD" (private) with reference argument
#define mGetXStateTable_MAX_CARD(Ref) STMStateChart_ROM_Access(Ref,StateTable_MAX_CARD)
// Read value from the attribute "StateTable_MAX_CARD" (private) without reference argument
#define mGetStateTable_MAX_CARD() STMStateChart_ROM_Access(This,StateTable_MAX_CARD)

// Read value from the attribute "pStateTable_Table" (private) with reference argument
#define mGetXpStateTable_Table(Ref) STMStateChart_ROM_Access(Ref,pStateTable_Table)
// Read value from the attribute "pStateTable_Table" (private) without reference argument
#define mGetpStateTable_Table() STMStateChart_ROM_Access(This,pStateTable_Table)

#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

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
extern boolean STMStateChart_ProcessEvt_Implementation(void * const parentRef, Event_Ref const pEvent);
// =====================================================================================================================
#define STMStateChart_ProcessEvt(Ref, pEvent) \
        STMStateChart_VTBL_ISysEventNotification_Access(Ref)ProcessEvt((void *)(Ref), pEvent)

#define STMStateChart_ProcessEvt_Explicit(Ref, pEvent) \
        STMStateChart_ProcessEvt_Implementation((void *)(Ref), pEvent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateChart_ProcessEvt",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateChart_ProcessEvt",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateChart_ProcessEvt_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateChart_ProcessEvt_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mProcessEvt(pEvent) \
        STMStateChart_ProcessEvt(This, pEvent)

#define mProcessEvt_Implementation(pEvent) \
        STMStateChart_ProcessEvt_Implementation(This, pEvent)

#define mProcessEvt_Explicit(pEvent) \
        STMStateChart_ProcessEvt_Explicit(This, pEvent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt",310
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt",311
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mProcessEvt_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMStateChart_Init_Implementation(tSTMStateChart_Ref const This);
// =====================================================================================================================
#define STMStateChart_Init(Ref) \
        STMStateChart_VTBL_Access(Ref)->Init(Ref)

#define STMStateChart_Init_Explicit(Ref) \
        STMStateChart_Init_Implementation(Ref)

#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mInit() \
        STMStateChart_Init(This)

#define mInit_Explicit() \
        STMStateChart_Init_Explicit(This)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMStateChart_Activate_Implementation(tSTMStateChart_Ref const This);
// =====================================================================================================================
#define STMStateChart_Activate(Ref) \
        STMStateChart_VTBL_Access(Ref)->Activate(Ref)

#define STMStateChart_Activate_Explicit(Ref) \
        STMStateChart_Activate_Implementation(Ref)

#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mActivate() \
        STMStateChart_Activate(This)

#define mActivate_Explicit() \
        STMStateChart_Activate_Explicit(This)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMStateChart_DeActivate_Implementation(tSTMStateChart_Ref const This);
// =====================================================================================================================
#define STMStateChart_DeActivate(Ref) \
        STMStateChart_VTBL_Access(Ref)->DeActivate(Ref)

#define STMStateChart_DeActivate_Explicit(Ref) \
        STMStateChart_DeActivate_Implementation(Ref)

#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mDeActivate() \
        STMStateChart_DeActivate(This)

#define mDeActivate_Explicit() \
        STMStateChart_DeActivate_Explicit(This)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern boolean STMStateChart_IsIn_Implementation(tSTMStateChart_Ref const This, tSTMState_Ref const pState);
// =====================================================================================================================
#define STMStateChart_IsIn(Ref, pState) \
        STMStateChart_VTBL_Access(Ref)->IsIn(Ref, pState)

#define STMStateChart_IsIn_Explicit(Ref, pState) \
        STMStateChart_IsIn_Implementation(Ref, pState)

#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mIsIn(pState) \
        STMStateChart_IsIn(This, pState)

#define mIsIn_Explicit(pState) \
        STMStateChart_IsIn_Explicit(This, pState)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
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
extern tSTMState_Ref STMStateChart_GetCurentState(tSTMStateChart_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mGetCurentState() \
        STMStateChart_GetCurentState(This)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern tSTMState_Ref STMStateChart_GetInternalState(tSTMStateChart_Ref const This, uint16 const Index);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mGetInternalState(Index) \
        STMStateChart_GetInternalState(This, Index)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern void STMStateChart_SetInternalState(tSTMStateChart_Ref const This, uint16 const Index, tSTMState_Ref const pState);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMStateChart_PRIVATE_VISIBILITY))
#define mSetInternalState(Index, pState) \
        STMStateChart_SetInternalState(This, Index, pState)
#endif // #if (defined(STMStateChart_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMStateChart_G_h__
