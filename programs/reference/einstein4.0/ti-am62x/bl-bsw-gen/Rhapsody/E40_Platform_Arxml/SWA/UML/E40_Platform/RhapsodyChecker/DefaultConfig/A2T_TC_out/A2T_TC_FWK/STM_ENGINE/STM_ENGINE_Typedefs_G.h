#ifndef __STM_ENGINE_Typedefs_G_h__
#define __STM_ENGINE_Typedefs_G_h__
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
// This file contains package types definition
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:39 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              STM_ENGINE (DesignUnit)
// Description:         STM Engine main package.
// Owner:               A2T_TC_FWK (Package)
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
//                                                   Types definition
// ---------------------------------------------------------------------------------------------------------------------

// Language type STMBool
#ifndef A2T_TypesProtection_STMBool
#define A2T_TypesProtection_STMBool
// ---------------------------------------------------------------------------------------------------------------------
// This type is defined only to fix remaining issues related to the generation of the statechart items: guards.
// 
// Fix needs to be done in the UML Autocode Generator.
// ---------------------------------------------------------------------------------------------------------------------
#ifndef STK_TYPE_BOOL
#define STK_TYPE_BOOL
typedef boolean Bool;
#endif // STK_TYPE_BOOL
#endif

// Language type STMEvent
#ifndef A2T_TypesProtection_STMEvent
#define A2T_TypesProtection_STMEvent
// ---------------------------------------------------------------------------------------------------------------------
// This type is defined only to fix remaining issues related to the generation of the statechart items: complex events,
// guards and actions.
// 
// Fix needs to be done in the UML Autocode Generator.
// ---------------------------------------------------------------------------------------------------------------------
#define STMEvent  Event
#define tSTMEvent Event
#endif

// Language type STMEvent_Ref
#ifndef A2T_TypesProtection_STMEvent_Ref
#define A2T_TypesProtection_STMEvent_Ref
// ---------------------------------------------------------------------------------------------------------------------
// This type is defined only to fix remaining issues related to the generation of the statechart items: complex events,
// guards and actions.
// 
// Fix needs to be done in the UML Autocode Generator.
// ---------------------------------------------------------------------------------------------------------------------
#define STMEvent_Ref  Event_Ref
#define tSTMEvent_Ref Event_Ref
#endif

// Language type STMActionFct
#ifndef A2T_TypesProtection_STMActionFct
#define A2T_TypesProtection_STMActionFct
// ---------------------------------------------------------------------------------------------------------------------
// Function pointer to enter state or exit state action.
// ---------------------------------------------------------------------------------------------------------------------
typedef void (*STMActionFct)(void* This);
#define tSTMActionFct STMActionFct
#endif

// Enumeration type STMPredefinedEventID
#ifndef A2T_TypesProtection_STMPredefinedEventID
#define A2T_TypesProtection_STMPredefinedEventID
// ---------------------------------------------------------------------------------------------------------------------
// Predefined event ID code.
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    STMNullEventID,
    STMNonEventID
} STMPredefinedEventID;
#define eSTMNullEventID STMNullEventID
#define eSTMNonEventID STMNonEventID
#define tSTMPredefinedEventID STMPredefinedEventID
#endif

// Language type STMGuardFct
#ifndef A2T_TypesProtection_STMGuardFct
#define A2T_TypesProtection_STMGuardFct
// ---------------------------------------------------------------------------------------------------------------------
// Pointer to a guard function.
// ---------------------------------------------------------------------------------------------------------------------
typedef boolean (*STMGuardFct)(const void* This, const Event_Ref pEvent);
#define tSTMGuardFct STMGuardFct
#endif

// Structure type STMPathItem
#ifndef A2T_TypesProtection_STMPathItem
#define A2T_TypesProtection_STMPathItem
// ---------------------------------------------------------------------------------------------------------------------
// PathItem stucture.
// Owned by the Path class.
// ---------------------------------------------------------------------------------------------------------------------
typedef struct _STMPathItem_tag {
//  ITrans
    uint16 iTrans;
//  Vertex pointer.
    tSTMStateVertex_Ref pVertex;
} STMPathItem;
#define tSTMPathItem STMPathItem
#endif

// Language type STMTransitionActionFct
#ifndef A2T_TypesProtection_STMTransitionActionFct
#define A2T_TypesProtection_STMTransitionActionFct
// ---------------------------------------------------------------------------------------------------------------------
// Function pointer to a transition action.
// ---------------------------------------------------------------------------------------------------------------------
typedef void (*STMTransitionActionFct)(const void* This, const Event_Ref pEvent);
#define tSTMTransitionActionFct STMTransitionActionFct
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STM_ENGINE_Typedefs_G_h__
