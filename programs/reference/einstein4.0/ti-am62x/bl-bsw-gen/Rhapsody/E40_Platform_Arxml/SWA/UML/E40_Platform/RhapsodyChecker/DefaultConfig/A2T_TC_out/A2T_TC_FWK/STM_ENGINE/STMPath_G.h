#ifndef __STMPath_G_h__
#define __STMPath_G_h__
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
// Entity:              STMPath (Class)
// Description:         Path class allow to iterate in a tree of transition/vertex.
//                      - The root of the tree is a state.
//                      - Nodes are StateVertex.
//                      - Branches are transitions.
//                       
//                      The path respesents the chain of transition/StateVertex allowing to go from a state to another.
//                      It realizes an iterator pattern. The collection applied to the iterator is the tree, an then
//                      the iterator for navigating in the tress is a path.
//                      It implement the usual iterator methods (First, Next, CurentItem), it also implements
//                      additionnal methods adapted to this specific case.
//                      This class is an helper to simplify the naviagation in the tree.
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
#include "STMPath_Cfg.h"

// ---------------------------------------------------------------------------------------------------------------------
//                                           General access to the class data
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PROTECTED_VISIBILITY))
#define STMPath_Access(classRef,attribute) ((classRef)->attribute)
#define STMPath_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMPath_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                 RAM structure (In <<RamBased>> class this structure holds all non static attributes)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sSTMPath
{
// Number of entries in the Items list.
    uint16 Size; // private
// Item is a list of vertex/transition in  the curent path.
    STMPathItem Items[STMPath_Items_MAX_CARD]; // private
} tSTMPath;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class doesn't have non-static ROM attributes or virtual table

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
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<AutoCreatedOperation>GetMaxPath
// Method      :        STMPath_GetMaxPath(void)
// Visibility  :        static, public
// Description :        Read value from MaxPath (Multiplicity [1])
//                      This static attribute repesent the maximum allowed number of transition between two states.
// Parameters  :        None
// Return type :        uint16
// =====================================================================================================================
extern uint16 STMPath_GetMaxPath(void);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMPath_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "MaxPath" (static, public)
#define mGetMaxPath() (STMPath_MaxPath)

#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Attributes with private access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMPath_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                 Read/Write macro for private, non-constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read/Write value from/to the attribute "Size" (private) with reference argument
#define mSetXSize(Ref, Data) (STMPath_Access(Ref,Size) = (Data))
#define mGetXSize(Ref) STMPath_Access(Ref,Size)
// Read/Write value from/to the attribute "Size" (private) without reference argument
#define mSetSize(Data) (STMPath_Access(This,Size) = (Data))
#define mGetSize() STMPath_Access(This,Size)

// Read/Write value from/to the attribute "Items" (private) with reference argument
#define mSetXItems(Ref, idx, Data) (STMPath_AccessTbl(Ref, idx, Items) = (Data))
#define mGetXItems(Ref, idx) STMPath_AccessTbl(Ref, idx, Items)
// Read/Write value from/to the attribute "Items" (private) without reference argument
#define mSetItems(idx, Data) (STMPath_AccessTbl(This, idx, Items) = (Data))
#define mGetItems(idx) STMPath_AccessTbl(This, idx, Items)

#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<Operation>First
// Method      :        STMPath_First(tSTMPath_Ref const This, tSTMStateVertex_Ref const pVertex)
// Visibility  :        public
// Description :        Initialization the path to the first transition of the root vertex.
//                      Root vertex is passed as agrument of the method.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMPath_Ref         | This(In)        | Class reference
// tSTMStateVertex_Ref  | pVertex(In)     | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMTransition_Ref
// =====================================================================================================================
extern tSTMTransition_Ref STMPath_First(tSTMPath_Ref const This, tSTMStateVertex_Ref const pVertex);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PRIVATE_VISIBILITY))
#define mFirst(pVertex) \
        STMPath_First(This, pVertex)
#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<Operation>PassCurentTransition
// Method      :        STMPath_PassCurentTransition(tSTMPath_Ref const This)
// Visibility  :        public
// Description :        Pass the curent transition in the path and returns the first transition from the new vertex.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//     Type      | Name(Direction) |                                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMPath_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMTransition_Ref
// =====================================================================================================================
extern tSTMTransition_Ref STMPath_PassCurentTransition(tSTMPath_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PRIVATE_VISIBILITY))
#define mPassCurentTransition() \
        STMPath_PassCurentTransition(This)
#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<Operation>Next
// Method      :        STMPath_Next(tSTMPath_Ref const This)
// Visibility  :        public
// Description :        Change the path to the next possible and returns the last transition.
//                      Donot try to pass the transitions, only goes to the sibling, and to the sibling of the parent.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//     Type      | Name(Direction) |                                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMPath_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMTransition_Ref
// =====================================================================================================================
extern tSTMTransition_Ref STMPath_Next(tSTMPath_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PRIVATE_VISIBILITY))
#define mNext() \
        STMPath_Next(This)
#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<Operation>CurentItem
// Method      :        STMPath_CurentItem(tSTMPath_Ref const This)
// Visibility  :        public
// Description :        returns the last transition from the path.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//     Type      | Name(Direction) |                                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMPath_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMTransition_Ref
// =====================================================================================================================
extern tSTMTransition_Ref STMPath_CurentItem(tSTMPath_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PRIVATE_VISIBILITY))
#define mCurentItem() \
        STMPath_CurentItem(This)
#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<Operation>DoActions
// Method      :        STMPath_DoActions(tSTMPath_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public
// Description :        Execute actions form transition in the path (Done form path origin to target).
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMPath_Ref        | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void STMPath_DoActions(tSTMPath_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMPath_PRIVATE_VISIBILITY))
#define mDoActions(pStateChart, pEvent) \
        STMPath_DoActions(This, pStateChart, pEvent)
#endif // #if (defined(STMPath_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMPath_G_h__
