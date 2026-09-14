#ifndef __STMStateVertex_G_h__
#define __STMStateVertex_G_h__
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
// Entity:              STMStateVertex (Class)
// Description:         A StateVertex is an abstraction of a node in a state machine graph. 
//                      In general, it can be the source or destination of any number of transitions. 
//                      
//                      For example, a connector is a StateVertex, a state is a StateVertex.
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
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#define STMStateVertex_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMStateVertex_PROTECTED_VISIBILITY))
#define STMStateVertex_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMStateVertex_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMStateVertex_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMStateVertex_VTBL
{
    boolean (*IsActivable)(tSTMStateVertex_Ref const); // Defined by the Class "STMStateVertex" as virtual
} tSTMStateVertex_VTBL;
typedef tSTMStateVertex_VTBL* tSTMStateVertex_VTBL_Ref;

extern tSTMStateVertex_VTBL STMStateVertex_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMStateVertex
{
    tSTMStateVertex_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
// Cardinality of the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    t_MAX_CARD Transitions_MAX_CARD; // Auto-generated <MaxCard>
// Pointer to manage the relation Transitions(composition, multiplicity[1..*])
// Represents the outgoing transitions from the StateVertex.
    tSTMTransition_Ref * pTransitionsTable; // Auto-generated <Relation Table>
} tSTMStateVertex;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMStateVertex_Allocate
// ---------------------------------------------------------------------------------------------------------------------
//                                                      Help macro
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateVertex_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) \
    const tSTMTransition_Ref STMStateVertex_pTransitionsTable##instanceName[Transitions_MAX_CARD]

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateVertex_Allocate(instanceName, Transitions_MAX_CARD, pTransitionsTable) \
                                                                                                                        \
mSTMStateVertex_TransitionsTableInstance(instanceName,Transitions_MAX_CARD) = pTransitionsTable; \
tSTMStateVertex instanceName = {\
    &STMStateVertex_VTBL, \
    Transitions_MAX_CARD, \
    (tSTMTransition_Ref *)STMStateVertex_pTransitionsTable##instanceName \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMStateVertex_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMStateVertex_Allocate_Explicit(instanceName, Transitions_MAX_CARD, pTransitionsTable) \
                                                                                                                        \
tSTMStateVertex instanceName = {\
    &STMStateVertex_VTBL, \
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

#if (defined(STMStateVertex_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "Transitions_MAX_CARD" (protected) with reference argument
#define mGetXTransitions_MAX_CARD(Ref) STMStateVertex_ROM_Access(Ref,Transitions_MAX_CARD)
// Read value from the attribute "Transitions_MAX_CARD" (protected) without reference argument
#define mGetTransitions_MAX_CARD() STMStateVertex_ROM_Access(This,Transitions_MAX_CARD)

// Read value from the attribute "pTransitionsTable" (protected) with reference argument
#define mGetXpTransitionsTable(Ref) STMStateVertex_ROM_Access(Ref,pTransitionsTable)
// Read value from the attribute "pTransitionsTable" (protected) without reference argument
#define mGetpTransitionsTable() STMStateVertex_ROM_Access(This,pTransitionsTable)

#endif // #if (defined(STMStateVertex_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMStateVertex/<Operation>IsActivable
// Method      :        STMStateVertex_IsActivable_Implementation(tSTMStateVertex_Ref const This)
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
// tSTMStateVertex_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
extern boolean STMStateVertex_IsActivable_Implementation(tSTMStateVertex_Ref const This);
// =====================================================================================================================
#define STMStateVertex_IsActivable(Ref) \
        STMStateVertex_VTBL_Access(Ref)->IsActivable(Ref)

#define STMStateVertex_IsActivable_Explicit(Ref) \
        STMStateVertex_IsActivable_Implementation(Ref)

#if (defined(STMStateVertex_PRIVATE_VISIBILITY))
#define mIsActivable() \
        STMStateVertex_IsActivable(This)

#define mIsActivable_Explicit() \
        STMStateVertex_IsActivable_Explicit(This)
#endif // #if (defined(STMStateVertex_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
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
extern tSTMTransition_Ref STMStateVertex_GetTransition(tSTMStateVertex_Ref const This, uint16 const Index);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMStateVertex_PRIVATE_VISIBILITY))
#define mGetTransition(Index) \
        STMStateVertex_GetTransition(This, Index)
#endif // #if (defined(STMStateVertex_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMStateVertex_G_h__
