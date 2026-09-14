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
// Generated on Tue Aug 06 13:07:41 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
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
#define STMPath_PRIVATE_VISIBILITY
#define STMPath_PROTECTED_VISIBILITY

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
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMPath/<AutoCreatedOperation>GetMaxPath
// Method      :        STMPath_GetMaxPath(void)
// Visibility  :        static, public
// Description :        Read value from MaxPath (Multiplicity [1])
//                      This static attribute repesent the maximum allowed number of transition between two states.
// Parameters  :        None
// Return type :        uint16
// =====================================================================================================================
uint16 STMPath_GetMaxPath(void)
{
    return (mGetMaxPath());
}

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
tSTMTransition_Ref STMPath_First(tSTMPath_Ref const This, tSTMStateVertex_Ref const pVertex)
{
    tSTMTransition_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_2("STMPath", "First", This, pVertex)
    {
        tSTMPathItem* const pItem = &mGetItems(0);
        
        mSetSize(1);
        pItem->iTrans = 0;
        pItem->pVertex = pVertex;
        returnValue = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
    }
    mLEAVE_METHOD("STMPath", "First")
    return (returnValue);
}

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
tSTMTransition_Ref STMPath_PassCurentTransition(tSTMPath_Ref const This)
{
    tSTMTransition_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMPath", "PassCurentTransition", This)
    {
        // Get Curent transition
        tSTMPathItem*            pItem  = &mGetItems((mGetSize() - 1));
        const tSTMTransition_Ref pTrans = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
        
        if( mGetSize() < STMPath_MaxPath )
        {
            // Push a new Item in the stack
            pItem = &mGetItems(mGetSize());
            mSetSize(mGetSize() + 1);
            // Set the Item fields.
            pItem->iTrans = 0;
            pItem->pVertex = STMTransition_GetTarget(pTrans);
            returnValue = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
        }
        else
        {
            // Error: the path size is not propoerly configured.
            mREPORT_CONFIGURATION_ERROR();
            returnValue = NULL;
        }
    }
    mLEAVE_METHOD("STMPath", "PassCurentTransition")
    return (returnValue);
}

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
tSTMTransition_Ref STMPath_Next(tSTMPath_Ref const This)
{
    tSTMTransition_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMPath", "Next", This)
    {
        tSTMTransition_Ref pTrans = NULL;
        
        while( (mGetSize() > 0) && (NULL == pTrans) ) // PRQA S 1311
        {
            // Get curent Item in the stack
            tSTMPathItem* pItem = &mGetItems((mGetSize() - 1));
        
            // Go (Attend to go) to the sibling of the curent transition
            pItem->iTrans++;
            pTrans = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
            // if there is no Sibling for curent transition
            if( NULL == pTrans ) // PRQA S 1311
            {
                // Go to the parent sibling (attend to)
                // POP last item from the stack
                mSetSize(mGetSize() - 1);
            }
            else
            {
            }
        }
        returnValue = pTrans;
    }
    mLEAVE_METHOD("STMPath", "Next")
    return (returnValue);
}

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
tSTMTransition_Ref STMPath_CurentItem(tSTMPath_Ref const This)
{
    tSTMTransition_Ref returnValue = NULL;

    mCGAssert(NULL != This);
    mENTER_METHOD_1("STMPath", "CurentItem", This)
    {
        tSTMPathItem* const pItem = &mGetItems((mGetSize() - 1));
        
        returnValue = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
    }
    mLEAVE_METHOD("STMPath", "CurentItem")
    return (returnValue);
}

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
void STMPath_DoActions(tSTMPath_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
{
    mCGAssert(NULL != This);
    mENTER_METHOD_3("STMPath", "DoActions", This, pStateChart, pEvent)
    {
        uint16             Cnt;
        tSTMTransition_Ref pTrans;
        
        for( Cnt=0; Cnt < mGetSize(); Cnt++ )
        {
            tSTMPathItem* pItem = &mGetItems(Cnt);
        
            pTrans = STMStateVertex_GetTransition(pItem->pVertex, pItem->iTrans);
            STMTransition_DoAction(pTrans, pStateChart,  pEvent);
        }
    }
    mLEAVE_METHOD("STMPath", "DoActions")
}

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
