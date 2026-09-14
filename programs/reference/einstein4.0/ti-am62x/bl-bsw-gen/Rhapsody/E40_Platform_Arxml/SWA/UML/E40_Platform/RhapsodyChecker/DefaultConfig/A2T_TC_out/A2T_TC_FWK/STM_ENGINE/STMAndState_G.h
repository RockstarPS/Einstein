#ifndef __STMAndState_G_h__
#define __STMAndState_G_h__
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
//                                      Inherited classes reference transformation
// ---------------------------------------------------------------------------------------------------------------------
#define STMAndState_TO_STMStateVertex(Ref)    ((tSTMStateVertex_Ref)(Ref))
#define STMAndState_TO_STMState(Ref)    ((tSTMState_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_TO_STMStateVertex",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_TO_STMState",310
#endif // #ifdef _QAC_

#if (defined(STMAndState_PROTECTED_VISIBILITY))
#define STMStateVertex_TO_STMAndState(Ref)    ((tSTMAndState_Ref)(Ref))
#define STMState_TO_STMAndState(Ref)    ((tSTMAndState_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateVertex_TO_STMAndState",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMState_TO_STMAndState",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMAndState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMAndState_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMAndState_PROTECTED_VISIBILITY))
#define STMAndState_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMAndState_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMAndState_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMAndState_VTBL
{
    boolean (*IsActivable)(tSTMStateVertex_Ref const); // Defined by the Class "STMStateVertex" as virtual
    tSTMState_Ref (*GetAtomicEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoEntry)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    void (*DoExit)(tSTMState_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMState" as virtual
    boolean (*CheckTransitions)(tSTMState_Ref const, tSTMStateChart_Ref const, Event_Ref const, tSTMPath_Ref const); // Defined by the Class "STMState" as virtual
} tSTMAndState_VTBL;
typedef tSTMAndState_VTBL* tSTMAndState_VTBL_Ref;

extern tSTMAndState_VTBL STMAndState_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMAndState
{
    tSTMAndState_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
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
// Attributes from the class "STMAndState"
// Cardinality of the relation Regions(composition, multiplicity[1..*])
// Designates the regions owned be the AndState
    t_MAX_CARD Regions_MAX_CARD; // Auto-generated <MaxCard>
// Pointer to manage the relation Regions(composition, multiplicity[1..*])
// Designates the regions owned be the AndState
    tSTMRegion_Ref * pRegionsTable; // Auto-generated <Relation Table>
} tSTMAndState;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMAndState_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMAndState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) \
    const tSTMTransition_Ref STMStateVertex_pTransitionsTable##instanceName[Transitions_MAX_CARD]
#define mSTMAndState_RegionsTableInstance(instanceName,Regions_MAX_CARD) \
    const tSTMRegion_Ref STMAndState_pRegionsTable##instanceName[Regions_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMAndState_Allocate(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent, Regions_MAX_CARD, pRegionsTable) \
                                                                                                                        \
mSTMAndState_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) = pTransitionsTable; \
mSTMAndState_RegionsTableInstance(instanceName,Regions_MAX_CARD) = pRegionsTable; \
tSTMAndState instanceName = {\
    &STMAndState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)STMStateVertex_pTransitionsTable##instanceName, \
    EntryAction, \
    ExitAction, \
    pParent, \
    Regions_MAX_CARD, \
    (tSTMRegion_Ref *)STMAndState_pRegionsTable##instanceName \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMAndState_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMAndState_Allocate_Explicit(instanceName, Transitions_MAX_CARD, pTransitionsTable, EntryAction, ExitAction, pParent, Regions_MAX_CARD, pRegionsTable) \
                                                                                                                        \
tSTMAndState instanceName = {\
    &STMAndState_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)pTransitionsTable, \
    EntryAction, \
    ExitAction, \
    pParent, \
    Regions_MAX_CARD, \
    (tSTMRegion_Ref *)pRegionsTable \
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
#define STMAndState_GetEntryAction(Ref) \
        STMState_GetEntryAction(STMAndState_TO_STMState(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetEntryAction",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mGetEntryAction() \
        STMAndState_GetEntryAction(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetEntryAction",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_GetExitAction(Ref) \
        STMState_GetExitAction(STMAndState_TO_STMState(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetExitAction",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mGetExitAction() \
        STMAndState_GetExitAction(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetExitAction",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMAndState_PRIVATE_VISIBILITY))

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

#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMAndState_PRIVATE_VISIBILITY))

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

// Read value from the attribute "Regions_MAX_CARD" (protected) with reference argument
#define mGetXRegions_MAX_CARD(Ref) STMAndState_ROM_Access(Ref,Regions_MAX_CARD)
// Read value from the attribute "Regions_MAX_CARD" (protected) without reference argument
#define mGetRegions_MAX_CARD() STMAndState_ROM_Access(This,Regions_MAX_CARD)

// Read value from the attribute "pRegionsTable" (protected) with reference argument
#define mGetXpRegionsTable(Ref) STMAndState_ROM_Access(Ref,pRegionsTable)
// Read value from the attribute "pRegionsTable" (protected) without reference argument
#define mGetpRegionsTable() STMAndState_ROM_Access(This,pRegionsTable)

#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))

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
#define STMAndState_GetTransition(Ref, Index) \
        STMStateVertex_GetTransition(STMAndState_TO_STMStateVertex(Ref), Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetTransition",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mGetTransition(Index) \
        STMAndState_GetTransition(This, Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetTransition",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_DoEntriesFromParent(Ref, pStateChart, Parent) \
        STMState_DoEntriesFromParent(STMAndState_TO_STMState(Ref), pStateChart, Parent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoEntriesFromParent",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mDoEntriesFromParent(pStateChart, Parent) \
        STMAndState_DoEntriesFromParent(This, pStateChart, Parent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntriesFromParent",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_DoExitsUntilParent(Ref, pStateChart, NewState) \
        STMState_DoExitsUntilParent(STMAndState_TO_STMState(Ref), pStateChart, NewState)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoExitsUntilParent",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mDoExitsUntilParent(pStateChart, NewState) \
        STMAndState_DoExitsUntilParent(This, pStateChart, NewState)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExitsUntilParent",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_IsChildOf(Ref, SupposedParent) \
        STMState_IsChildOf(STMAndState_TO_STMState(Ref), SupposedParent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_IsChildOf",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mIsChildOf(SupposedParent) \
        STMAndState_IsChildOf(This, SupposedParent)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsChildOf",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_CheckTransitionsUntilRoot(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitionsUntilRoot(STMAndState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_CheckTransitionsUntilRoot",310
#endif // #ifdef _QAC_
#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mCheckTransitionsUntilRoot(pStateChart, pEvent, pPath) \
        STMAndState_CheckTransitionsUntilRoot(This, pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitionsUntilRoot",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
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
#define STMAndState_IsActivable(Ref) \
        STMStateVertex_IsActivable(STMAndState_TO_STMStateVertex(Ref))

#define STMAndState_IsActivable_Explicit(Ref) \
        STMStateVertex_IsActivable_Explicit(STMAndState_TO_STMStateVertex(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_IsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_IsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_IsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_IsActivable_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mIsActivable() \
        STMAndState_IsActivable(This)

#define mIsActivable_Explicit() \
        STMAndState_IsActivable_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMState/<Operation>GetAtomicEntry
// Method      :        STMState_GetAtomicEntry(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        This method shall returns the atomic entry state form the state.
//                      For Atomic State,  it returns This
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMState_Ref       | parentRef(In)    | Parent class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
#define STMAndState_GetAtomicEntry(Ref, pStateChart) \
        STMState_GetAtomicEntry(STMAndState_TO_STMState(Ref), pStateChart)

#define STMAndState_GetAtomicEntry_Explicit(Ref, pStateChart) \
        STMState_GetAtomicEntry_Explicit(STMAndState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetAtomicEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetAtomicEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetAtomicEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_GetAtomicEntry_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mGetAtomicEntry(pStateChart) \
        STMAndState_GetAtomicEntry(This, pStateChart)

#define mGetAtomicEntry_Explicit(pStateChart) \
        STMAndState_GetAtomicEntry_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mGetAtomicEntry_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMAndState_DoEntry_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMAndState_DoEntry(Ref, pStateChart) \
        STMState_DoEntry(STMAndState_TO_STMState(Ref), pStateChart)

#define STMAndState_DoEntry_Explicit(Ref, pStateChart) \
        STMAndState_DoEntry_Implementation(STMAndState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoEntry_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mDoEntry(pStateChart) \
        STMAndState_DoEntry(This, pStateChart)

#define mDoEntry_Implementation(pStateChart) \
        STMAndState_DoEntry_Implementation(This, pStateChart)

#define mDoEntry_Explicit(pStateChart) \
        STMAndState_DoEntry_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoEntry_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern void STMAndState_DoExit_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMAndState_DoExit(Ref, pStateChart) \
        STMState_DoExit(STMAndState_TO_STMState(Ref), pStateChart)

#define STMAndState_DoExit_Explicit(Ref, pStateChart) \
        STMAndState_DoExit_Implementation(STMAndState_TO_STMState(Ref), pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoExit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoExit",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoExit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_DoExit_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mDoExit(pStateChart) \
        STMAndState_DoExit(This, pStateChart)

#define mDoExit_Implementation(pStateChart) \
        STMAndState_DoExit_Implementation(This, pStateChart)

#define mDoExit_Explicit(pStateChart) \
        STMAndState_DoExit_Explicit(This, pStateChart)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mDoExit_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

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
extern boolean STMAndState_CheckTransitions_Implementation(tSTMState_Ref const parentRef, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent, tSTMPath_Ref const pPath);
// =====================================================================================================================
#define STMAndState_CheckTransitions(Ref, pStateChart, pEvent, pPath) \
        STMState_CheckTransitions(STMAndState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#define STMAndState_CheckTransitions_Explicit(Ref, pStateChart, pEvent, pPath) \
        STMAndState_CheckTransitions_Implementation(STMAndState_TO_STMState(Ref), pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_CheckTransitions",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_CheckTransitions",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_CheckTransitions_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMAndState_CheckTransitions_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMAndState_PRIVATE_VISIBILITY))
#define mCheckTransitions(pStateChart, pEvent, pPath) \
        STMAndState_CheckTransitions(This, pStateChart, pEvent, pPath)

#define mCheckTransitions_Implementation(pStateChart, pEvent, pPath) \
        STMAndState_CheckTransitions_Implementation(This, pStateChart, pEvent, pPath)

#define mCheckTransitions_Explicit(pStateChart, pEvent, pPath) \
        STMAndState_CheckTransitions_Explicit(This, pStateChart, pEvent, pPath)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions",310
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions",311
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mCheckTransitions_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMAndState_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMAndState_G_h__
