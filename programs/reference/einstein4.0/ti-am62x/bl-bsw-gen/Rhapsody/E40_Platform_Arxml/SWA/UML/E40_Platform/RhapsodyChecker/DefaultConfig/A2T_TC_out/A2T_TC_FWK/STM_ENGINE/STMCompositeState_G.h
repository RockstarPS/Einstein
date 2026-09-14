#ifndef __STMCompositeState_G_h__
#define __STMCompositeState_G_h__
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
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#define STMCompositeState_TO_STMStateVertex(Ref)    ((tSTMStateVertex_Ref)(Ref))
#define STMCompositeState_TO_STMState(Ref)    ((tSTMState_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_TO_STMStateVertex",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_TO_STMState",310
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PROTECTED_VISIBILITY))
#define STMStateVertex_TO_STMCompositeState(Ref)    ((tSTMCompositeState_Ref)(Ref))
#define STMState_TO_STMCompositeState(Ref)    ((tSTMCompositeState_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateVertex_TO_STMCompositeState",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_TO_STMCompositeState",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMCompositeState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMCompositeState_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMCompositeState_PROTECTED_VISIBILITY))
#define STMCompositeState_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMCompositeState_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMCompositeState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMCompositeState_VTBL
{
    boolean (*IsActivable)(tSTMStateVertex_Ref const); // Defined by the Class "STMStateVertex" as virtual
    tSTMState_Ref (*GetAtomicEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoExit)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    boolean (*CheckTransitions)(tSTMState_Ref const, tSTMStateChart_Ref const, Event_Ref const, tSTMPath_Ref const); // Defined by the Class "STMState" as virtual
} tSTMCompositeState_VTBL;
typedef tSTMCompositeState_VTBL* tSTMCompositeState_VTBL_Ref;

extern tSTMCompositeState_VTBL STMCompositeState_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMCompositeState
{
    tSTMCompositeState_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
// Attributes from the class "STMStateVertex"
// Cardinality of the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    t_MAX_CARD Transitions_MAX_CARD; // Auto-generated <MaxCard>
// Pointer to manage the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    tSTMTransition_Ref * pTransitionsTable; // Auto-generated <Relation Table>
// Attributes from the class "STMState"
// Specify the function to be called when the state is activated.
    STMActionFct EntryAction; // public
// Specify the function to be called when the state is exited.
    STMActionFct ExitAction; // public
// Pointer to manage the relation Parent(association, multiplicity[1])
// Designates the Parent state (Parent is a composite state).
// It can be NULL if the state have no parent.
    tSTMState_Ref pParent; // protected
// Attributes from the class "STMCompositeState"
// Pointer to manage the relation EntryState(association, multiplicity[1])
// Designate the sub-state to activate when this state is activated
    tSTMState_Ref pEntryState; // protected
} tSTMCompositeState;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMCompositeState_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMCompositeState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) \
    const tSTMTransition_Ref STMStateVertex_pTransitionsTable##instanceName[Transitions_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMCompositeState_Allocate(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent, pEntryState) \
                                                                                                                        \
mSTMCompositeState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) = pTransitionsTable; \
tSTMCompositeState instanceName = {\
    &STMCompositeState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)STMStateVertex_pTransitionsTable##instanceName, \
    EntryAction, \
    ExitAction, \
    pParent, \
    pEntryState \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMCompositeState_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMCompositeState_Allocate_Explicit(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent, pEntryState) \
                                                                                                                        \
tSTMCompositeState instanceName = {\
    &STMCompositeState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)pTransitionsTable, \
    EntryAction, \
    ExitAction, \
    pParent, \
    pEntryState \
}
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
#define STMCompositeState_GetEntryAction(Ref) \
        STMState_GetEntryAction(STMCompositeState_TO_STMState(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetEntryAction",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mGetEntryAction() \
        STMCompositeState_GetEntryAction(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetEntryAction",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define STMCompositeState_GetExitAction(Ref) \
        STMState_GetExitAction(STMCompositeState_TO_STMState(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetExitAction",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mGetExitAction() \
        STMCompositeState_GetExitAction(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetExitAction",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the inherited attribute "EntryAction" (public) with reference argument
#define mGetXEntryAction(Ref) STMState_ROM_Access(Ref,EntryAction)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXEntryAction",310
#endif // #ifdef _QAC_

// Read value from the inherited attribute "ExitAction" (public) with reference argument
#define mGetXExitAction(Ref) STMState_ROM_Access(Ref,ExitAction)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXExitAction",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the inherited attribute "Transitions_MAX_CARD" (protected) with reference argument
#define mGetXTransitions_MAX_CARD(Ref) STMStateVertex_ROM_Access(Ref,Transitions_MAX_CARD)
// Read value from the inherited attribute "Transitions_MAX_CARD" (protected) without reference argument
#define mGetTransitions_MAX_CARD() STMStateVertex_ROM_Access(This,Transitions_MAX_CARD)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXTransitions_MAX_CARD",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetTransitions_MAX_CARD",310
#endif // #ifdef _QAC_

// Read value from the inherited attribute "pTransitionsTable" (protected) with reference argument
#define mGetXpTransitionsTable(Ref) STMStateVertex_ROM_Access(Ref,pTransitionsTable)
// Read value from the inherited attribute "pTransitionsTable" (protected) without reference argument
#define mGetpTransitionsTable() STMStateVertex_ROM_Access(This,pTransitionsTable)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXpTransitionsTable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetpTransitionsTable",310
#endif // #ifdef _QAC_

// Read value from the inherited attribute "pParent" (protected) with reference argument
#define mGetXpParent(Ref) STMState_ROM_Access(Ref,pParent)
// Read value from the inherited attribute "pParent" (protected) without reference argument
#define mGetpParent() STMState_ROM_Access(This,pParent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetXpParent",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetpParent",310
#endif // #ifdef _QAC_

// Read value from the attribute "pEntryState" (protected) with reference argument
#define mGetXpEntryState(Ref) STMCompositeState_ROM_Access(Ref,pEntryState)
// Read value from the attribute "pEntryState" (protected) without reference argument
#define mGetpEntryState() STMCompositeState_ROM_Access(This,pEntryState)

#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                   Inherited methods
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
#define STMCompositeState_GetTransition(Ref, Index) \
        STMStateVertex_GetTransition(STMCompositeState_TO_STMStateVertex(Ref), Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetTransition",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mGetTransition(Index) \
        STMCompositeState_GetTransition(This, Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetTransition",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define STMCompositeState_DoEntriesFromParent(Ref, pStateChart, Parent) \
        STMState_DoEntriesFromParent(STMCompositeState_TO_STMState(Ref), pStateChart, Parent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoEntriesFromParent",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mDoEntriesFromParent(pStateChart, Parent) \
        STMCompositeState_DoEntriesFromParent(This, pStateChart, Parent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntriesFromParent",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define STMCompositeState_DoExitsUntilParent(Ref, pStateChart, NewState) \
        STMState_DoExitsUntilParent(STMCompositeState_TO_STMState(Ref), pStateChart, NewState)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoExitsUntilParent",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mDoExitsUntilParent(pStateChart, NewState) \
        STMCompositeState_DoExitsUntilParent(This, pStateChart, NewState)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExitsUntilParent",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define STMCompositeState_IsChildOf(Ref, SupposedParent) \
        STMState_IsChildOf(STMCompositeState_TO_STMState(Ref), SupposedParent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_IsChildOf",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mIsChildOf(SupposedParent) \
        STMCompositeState_IsChildOf(This, SupposedParent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsChildOf",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
#define STMCompositeState_CheckTransitionsUntilRoot(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitionsUntilRoot(STMCompositeState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_CheckTransitionsUntilRoot",310
#endif // #ifdef _QAC_
#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mCheckTransitionsUntilRoot(pStateChart, pEvent, pPath) \
        STMCompositeState_CheckTransitionsUntilRoot(This, pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitionsUntilRoot",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateVertex/<Operation>IsActivable
// Method      :        STMStateVertex_IsActivable(tSTMStateVertex_Ref const parentRef)
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
// tSTMStateVertex_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
#define STMCompositeState_IsActivable(Ref) \
        STMStateVertex_IsActivable(STMCompositeState_TO_STMStateVertex(Ref))

#define STMCompositeState_IsActivable_Explicit(Ref) \
        STMStateVertex_IsActivable_Explicit(STMCompositeState_TO_STMStateVertex(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_IsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_IsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_IsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_IsActivable_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mIsActivable() \
        STMCompositeState_IsActivable(This)

#define mIsActivable_Explicit() \
        STMCompositeState_IsActivable_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern tSTMState_Ref STMCompositeState_GetAtomicEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMCompositeState_GetAtomicEntry(Ref, pStateChart) \
        STMState_GetAtomicEntry(STMCompositeState_TO_STMState(Ref), pStateChart)

#define STMCompositeState_GetAtomicEntry_Explicit(Ref, pStateChart) \
        STMCompositeState_GetAtomicEntry_Implementation(STMCompositeState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetAtomicEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetAtomicEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetAtomicEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_GetAtomicEntry_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mGetAtomicEntry(pStateChart) \
        STMCompositeState_GetAtomicEntry(This, pStateChart)

#define mGetAtomicEntry_Implementation(pStateChart) \
        STMCompositeState_GetAtomicEntry_Implementation(This, pStateChart)

#define mGetAtomicEntry_Explicit(pStateChart) \
        STMCompositeState_GetAtomicEntry_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoEntry
// Method      :        STMState_DoEntry(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
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
#define STMCompositeState_DoEntry(Ref, pStateChart) \
        STMState_DoEntry(STMCompositeState_TO_STMState(Ref), pStateChart)

#define STMCompositeState_DoEntry_Explicit(Ref, pStateChart) \
        STMState_DoEntry_Explicit(STMCompositeState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoEntry_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mDoEntry(pStateChart) \
        STMCompositeState_DoEntry(This, pStateChart)

#define mDoEntry_Explicit(pStateChart) \
        STMCompositeState_DoEntry_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>DoExit
// Method      :        STMState_DoExit(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
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
#define STMCompositeState_DoExit(Ref, pStateChart) \
        STMState_DoExit(STMCompositeState_TO_STMState(Ref), pStateChart)

#define STMCompositeState_DoExit_Explicit(Ref, pStateChart) \
        STMState_DoExit_Explicit(STMCompositeState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoExit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoExit",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoExit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_DoExit_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mDoExit(pStateChart) \
        STMCompositeState_DoExit(This, pStateChart)

#define mDoExit_Explicit(pStateChart) \
        STMCompositeState_DoExit_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>CheckTransitions
// Method      :        STMState_CheckTransitions(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath)
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
#define STMCompositeState_CheckTransitions(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitions(STMCompositeState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#define STMCompositeState_CheckTransitions_Explicit(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitions_Explicit(STMCompositeState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_CheckTransitions",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_CheckTransitions",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_CheckTransitions_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMCompositeState_CheckTransitions_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMCompositeState_PRIVATE_VISIBILITY))
#define mCheckTransitions(pStateChart, pEvent, pPath) \
        STMCompositeState_CheckTransitions(This, pStateChart, pEvent, pPath)

#define mCheckTransitions_Explicit(pStateChart, pEvent, pPath) \
        STMCompositeState_CheckTransitions_Explicit(This, pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions",310
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions",311
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMCompositeState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMCompositeState_G_h__
