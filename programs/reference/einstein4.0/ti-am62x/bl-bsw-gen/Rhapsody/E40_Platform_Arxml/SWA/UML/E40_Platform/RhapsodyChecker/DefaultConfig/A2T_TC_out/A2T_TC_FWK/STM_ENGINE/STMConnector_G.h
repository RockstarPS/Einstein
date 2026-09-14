#ifndef __STMConnector_G_h__
#define __STMConnector_G_h__
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
// Entity:              STMConnector (Class)
// Description:         A connector is an abstraction of transient vertices in the state machine graph. 
//                      Connector are used to connect multiple transitions into more complex state transitions paths.
//                      For example, by combining a transition entering a connector with a set of transitions exiting
//                      connector , we get a compound transition.
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
#define STMConnector_TO_STMStateVertex(Ref)    ((tSTMStateVertex_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_TO_STMStateVertex",310
#endif // #ifdef _QAC_

#if (defined(STMConnector_PROTECTED_VISIBILITY))
#define STMStateVertex_TO_STMConnector(Ref)    ((tSTMConnector_Ref)(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMStateVertex_TO_STMConnector",310
#endif // #ifdef _QAC_

#endif // #if (defined(STMConnector_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMConnector_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMConnector_PROTECTED_VISIBILITY))
#define STMConnector_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMConnector_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMConnector_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMConnector_VTBL
{
    boolean (*IsActivable)(tSTMStateVertex_Ref const); // Defined by the Class "STMStateVertex" as virtual
} tSTMConnector_VTBL;
typedef tSTMConnector_VTBL* tSTMConnector_VTBL_Ref;

extern tSTMConnector_VTBL STMConnector_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMConnector
{
    tSTMConnector_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
// Attributes from the class "STMStateVertex"
// Cardinality of the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    t_MAX_CARD Transitions_MAX_CARD; // Auto-generated <MaxCard>
// Pointer to manage the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    tSTMTransition_Ref * pTransitionsTable; // Auto-generated <Relation Table>
} tSTMConnector;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMConnector_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMConnector_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) \
    const tSTMTransition_Ref STMStateVertex_pTransitionsTable##instanceName[Transitions_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMConnector_Allocate(instanceName, Transitions_MAX_CARD, pTransitionsTable) \
                                                                                                                        \
mSTMConnector_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) = pTransitionsTable; \
tSTMConnector instanceName = {\
    &STMConnector_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)STMStateVertex_pTransitionsTable##instanceName \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMConnector_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMConnector_Allocate_Explicit(instanceName, Transitions_MAX_CARD, pTransitionsTable) \
                                                                                                                        \
tSTMConnector instanceName = {\
    &STMConnector_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)pTransitionsTable \
}
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
//                                              Attribute accessors section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMConnector_PRIVATE_VISIBILITY))

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

#endif // #if (defined(STMConnector_PRIVATE_VISIBILITY))

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
#define STMConnector_GetTransition(Ref, Index) \
        STMStateVertex_GetTransition(STMConnector_TO_STMStateVertex(Ref), Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_GetTransition",310
#endif // #ifdef _QAC_
#if (defined(STMConnector_PRIVATE_VISIBILITY))
#define mGetTransition(Index) \
        STMConnector_GetTransition(This, Index)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310)
#pragma PRQA_MACRO_MESSAGES_OFF "mGetTransition",310
#endif // #ifdef _QAC_
#endif // #if (defined(STMConnector_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMConnector/<Operation>IsActivable
// Method      :        STMConnector_IsActivable_Implementation(tSTMStateVertex_Ref const parentRef)
// Visibility  :        public, virtual
// Description :        Shall return True if the StateVertex can be activated.
//                      
//                      Connector are transient vertices and cannot be activated.
//                      This method always returns cFalse
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMStateVertex_Ref  | parentRef(In)   | Parent class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
extern boolean STMConnector_IsActivable_Implementation(tSTMStateVertex_Ref const parentRef);
// =====================================================================================================================
#define STMConnector_IsActivable(Ref) \
        STMStateVertex_IsActivable(STMConnector_TO_STMStateVertex(Ref))

#define STMConnector_IsActivable_Explicit(Ref) \
        STMConnector_IsActivable_Implementation(STMConnector_TO_STMStateVertex(Ref))

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_IsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_IsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_IsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "STMConnector_IsActivable_Explicit",311
#endif // #ifdef _QAC_

#if (defined(STMConnector_PRIVATE_VISIBILITY))
#define mIsActivable() \
        STMConnector_IsActivable(This)

#define mIsActivable_Implementation() \
        STMConnector_IsActivable_Implementation(This)

#define mIsActivable_Explicit() \
        STMConnector_IsActivable_Explicit(This)

#ifdef _QAC_
// See UML AUTOCODE GUIDELINE for justification of message Msg(2:0310) & Msg(3:0311)
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable",311
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Implementation",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Implementation",311
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",310
#pragma PRQA_MACRO_MESSAGES_OFF "mIsActivable_Explicit",311
#endif // #ifdef _QAC_
#endif // #if (defined(STMConnector_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMConnector_G_h__
