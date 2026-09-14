#ifndef __STMState_G_h__
#define __STMState_G_h__
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
//                                                      Inclusions
// ---------------------------------------------------------------------------------------------------------------------
#include "STM_ENGINE_G.h"

// ---------------------------------------------------------------------------------------------------------------------
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#define STMState_TO_STMStateVertex(Ref)    ((tSTMStateVertex_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_TO_STMStateVertex",310
#endif // #ifdef _QAC_

#if (defined(STMState_PROTECTED_VISIBILITY))
#define STMStateVertex_TO_STMState(Ref)    ((tSTMState_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateVertex_TO_STMState",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMState_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMState_PROTECTED_VISIBILITY))
#define STMState_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMState_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMState_VTBL
{
    boolean (*IsActivable)(tSTMStateVertex_Ref const); // Defined by the Class "STMStateVertex" as virtual
    tSTMState_Ref (*GetAtomicEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoExit)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    boolean (*CheckTransitions)(tSTMState_Ref const, tSTMStateChart_Ref const, Event_Ref const, tSTMPath_Ref const); // Defined by the Class "STMState" as virtual
} tSTMState_VTBL;
typedef tSTMState_VTBL* tSTMState_VTBL_Ref;

extern tSTMState_VTBL STMState_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMState
{
    tSTMState_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
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
} tSTMState;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMState_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) \
    const tSTMTransition_Ref STMStateVertex_pTransitionsTable##instanceName[Transitions_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMState_Allocate(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent) \
                                                                                                                        \
mSTMState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) = pTransitionsTable; \
tSTMState instanceName = {\
    &STMState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)STMStateVertex_pTransitionsTable##instanceName, \
    EntryAction, \
    ExitAction, \
    pParent \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMState_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMState_Allocate_Explicit(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent) \
                                                                                                                        \
tSTMState instanceName = {\
    &STMState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)pTransitionsTable, \
    EntryAction, \
    ExitAction, \
    pParent \
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
extern STMActionFct STMState_GetEntryAction(tSTMState_Ref const This);

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
extern STMActionFct STMState_GetExitAction(tSTMState_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "EntryAction" (public) with reference argument
#define mGetXEntryAction(Ref) STMState_ROM_Access(Ref,EntryAction)
// Read value from the attribute "EntryAction" (public) without reference argument
#define mGetEntryAction() STMState_ROM_Access(This,EntryAction)

// Read value from the attribute "ExitAction" (public) with reference argument
#define mGetXExitAction(Ref) STMState_ROM_Access(Ref,ExitAction)
// Read value from the attribute "ExitAction" (public) without reference argument
#define mGetExitAction() STMState_ROM_Access(This,ExitAction)

#endif // #if (defined(STMState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMState_PRIVATE_VISIBILITY))

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

// Read value from the attribute "pParent" (protected) with reference argument
#define mGetXpParent(Ref) STMState_ROM_Access(Ref,pParent)
// Read value from the attribute "pParent" (protected) without reference argument
#define mGetpParent() STMState_ROM_Access(This,pParent)

#endif // #if (defined(STMState_PRIVATE_VISIBILITY))

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
#define STMState_GetTransition(Ref, Index) \
        STMStateVertex_GetTransition(STMState_TO_STMStateVertex(Ref), Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_GetTransition",310
#endif // #ifdef _QAC_
#if (defined(STMState_PRIVATE_VISIBILITY))
#define mGetTransition(Index) \
        STMState_GetTransition(This, Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetTransition",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
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
#define STMState_IsActivable(Ref) \
        STMStateVertex_IsActivable(STMState_TO_STMStateVertex(Ref))

#define STMState_IsActivable_Explicit(Ref) \
        STMStateVertex_IsActivable_Explicit(STMState_TO_STMStateVertex(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_IsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_IsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_IsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_IsActivable_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMState_PRIVATE_VISIBILITY))
#define mIsActivable() \
        STMState_IsActivable(This)

#define mIsActivable_Explicit() \
        STMState_IsActivable_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern tSTMState_Ref STMState_GetAtomicEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMState_GetAtomicEntry(Ref, pStateChart) \
        STMState_VTBL_Access(Ref)->GetAtomicEntry(Ref, pStateChart)

#define STMState_GetAtomicEntry_Explicit(Ref, pStateChart) \
        STMState_GetAtomicEntry_Implementation(Ref, pStateChart)

#if (defined(STMState_PRIVATE_VISIBILITY))
#define mGetAtomicEntry(pStateChart) \
        STMState_GetAtomicEntry(This, pStateChart)

#define mGetAtomicEntry_Explicit(pStateChart) \
        STMState_GetAtomicEntry_Explicit(This, pStateChart)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMState_DoEntry_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMState_DoEntry(Ref, pStateChart) \
        STMState_VTBL_Access(Ref)->DoEntry(Ref, pStateChart)

#define STMState_DoEntry_Explicit(Ref, pStateChart) \
        STMState_DoEntry_Implementation(Ref, pStateChart)

#if (defined(STMState_PRIVATE_VISIBILITY))
#define mDoEntry(pStateChart) \
        STMState_DoEntry(This, pStateChart)

#define mDoEntry_Explicit(pStateChart) \
        STMState_DoEntry_Explicit(This, pStateChart)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMState_DoExit_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMState_DoExit(Ref, pStateChart) \
        STMState_VTBL_Access(Ref)->DoExit(Ref, pStateChart)

#define STMState_DoExit_Explicit(Ref, pStateChart) \
        STMState_DoExit_Implementation(Ref, pStateChart)

#if (defined(STMState_PRIVATE_VISIBILITY))
#define mDoExit(pStateChart) \
        STMState_DoExit(This, pStateChart)

#define mDoExit_Explicit(pStateChart) \
        STMState_DoExit_Explicit(This, pStateChart)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern boolean STMState_CheckTransitions_Implementation(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath);
// =====================================================================================================================
#define STMState_CheckTransitions(Ref, pStateChart, pEvent, pPath) \
        STMState_VTBL_Access(Ref)->CheckTransitions(Ref, pStateChart, pEvent, pPath)

#define STMState_CheckTransitions_Explicit(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitions_Implementation(Ref, pStateChart, pEvent, pPath)

#if (defined(STMState_PRIVATE_VISIBILITY))
#define mCheckTransitions(pStateChart, pEvent, pPath) \
        STMState_CheckTransitions(This, pStateChart, pEvent, pPath)

#define mCheckTransitions_Explicit(pStateChart, pEvent, pPath) \
        STMState_CheckTransitions_Explicit(This, pStateChart, pEvent, pPath)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
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
extern void STMState_DoEntriesFromParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const Parent);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMState_PRIVATE_VISIBILITY))
#define mDoEntriesFromParent(pStateChart, Parent) \
        STMState_DoEntriesFromParent(This, pStateChart, Parent)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern tSTMState_Ref STMState_DoExitsUntilParent(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const NewState);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMState_PRIVATE_VISIBILITY))
#define mDoExitsUntilParent(pStateChart, NewState) \
        STMState_DoExitsUntilParent(This, pStateChart, NewState)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern boolean STMState_IsChildOf(tSTMState_Ref const This, tSTMState_Ref const SupposedParent);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMState_PRIVATE_VISIBILITY))
#define mIsChildOf(SupposedParent) \
        STMState_IsChildOf(This, SupposedParent)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

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
extern boolean STMState_CheckTransitionsUntilRoot(tSTMState_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMState_PRIVATE_VISIBILITY))
#define mCheckTransitionsUntilRoot(pStateChart, pEvent, pPath) \
        STMState_CheckTransitionsUntilRoot(This, pStateChart, pEvent, pPath)
#endif // #if (defined(STMState_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMState_G_h__
