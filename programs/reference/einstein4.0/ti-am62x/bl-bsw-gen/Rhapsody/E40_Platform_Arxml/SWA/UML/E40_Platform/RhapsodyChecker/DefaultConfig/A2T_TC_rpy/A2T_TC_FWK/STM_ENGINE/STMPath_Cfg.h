#ifndef __STMPath_Cfg_h__
#define __STMPath_Cfg_h__
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
//       This is a template configuration file. First version is auto-generated, further versions are manually updated
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

// Do not change or remove this line! This is the start of the code protection section. Idea of the section to preserve handwritten code.

// ---------------------------------------------------------------------------------------------------------------------
//                                Attributes multiplicities not pre-defined in the model
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// STMPath_Items_MAX_CARD[1]
// Description :        Items(Item is a list of vertex/transition in  the curent path.) array size
// ---------------------------------------------------------------------------------------------------------------------
#define STMPath_Items_MAX_CARD ((int)MAX_CARD)

// ---------------------------------------------------------------------------------------------------------------------
//                                       Attributes with "PreCompiled" stereotype
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
// MaxPath[1]
// Description :        This static attribute repesent the maximum allowed number of transition between two states.
// ---------------------------------------------------------------------------------------------------------------------
#define STMPath_MaxPath ((uint16)5UL)

// Do not change or remove this line! This is the end of the code protection section.

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMPath_Cfg_h__
