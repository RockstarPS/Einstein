#ifndef __STMTransition_G_h__
#define __STMTransition_G_h__
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
// Entity:              STMTransition (Class)
// Description:         A transition is a directed relationship between a source vertex and a target vertex. 
//                      
//                      It may be part of a compound transition (a chain of transition between two states), which takes
//                      the state machine from one state to another, representing the complete response of the state
//                      machine to an occurrence of an event of a particular type.
//                      
//                      Note that for compound transition, only first transition  is trigered by an event, other can
//                      only define guards.
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
#if (defined(STMTransition_PROTECTED_VISIBILITY))
#define STMTransition_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMTransition_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMTransition_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMTransition
{
// Designates the function which is executed when the transition is passed.
    STMTransitionActionFct Action; // public
// A guard is a function pointer to a function which can returns True or False.
// 
// The guard is evaluated when an event occurrence is dispatched by the state machine. If the guard is true at that
// time, the transition may be enabled; otherwise, it is disabled. Guards should be pure expressions without side
// effects. Guard expressions with side effects are ill formed.
    STMGuardFct Guard; // public
// Specifies the triggers that may fire the transition.
// Three case are possible :
// - The event is eSTMNullEventID, the transition is designed to be polled.
// - The event is eSTMNonEventID, the transition is part of a compound transition, the trigger is defined by the first
// transition in the list.
// - The event is a specific event which fire the transition.
    EventID Event; // public
// Pointer to manage the relation Target(association, multiplicity[1])
// Designates the target vertex that is reached when the transition is taken.
    tSTMStateVertex_Ref pTarget; // protected
} tSTMTransition;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMTransition_Allocate

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMTransition_Allocate(instanceName, Action, Guard, Event, pTarget) \
                                                                                                                        \
tSTMTransition instanceName = {\
    Action, \
    Guard, \
    Event, \
    pTarget \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMTransition_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMTransition_Allocate_Explicit(instanceName, Action, Guard, Event, pTarget) \
                                                                                                                        \
tSTMTransition instanceName = {\
    Action, \
    Guard, \
    Event, \
    pTarget \
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
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetAction
// Method      :        STMTransition_GetAction(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Action (Multiplicity [1])
//                      Designates the function which is executed when the transition is passed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMTransitionActionFct
// =====================================================================================================================
extern STMTransitionActionFct STMTransition_GetAction(tSTMTransition_Ref const This);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetGuard
// Method      :        STMTransition_GetGuard(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Guard (Multiplicity [1])
//                      A guard is a function pointer to a function which can returns True or False.
//                      
//                      The guard is evaluated when an event occurrence is dispatched by the state machine. If the
//                      guard is true at that time, the transition may be enabled; otherwise, it is disabled. Guards
//                      should be pure expressions without side effects. Guard expressions with side effects are ill
//                      formed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        STMGuardFct
// =====================================================================================================================
extern STMGuardFct STMTransition_GetGuard(tSTMTransition_Ref const This);

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<AutoCreatedOperation>GetEvent
// Method      :        STMTransition_GetEvent(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        Read value from Event (Multiplicity [1])
//                      Specifies the triggers that may fire the transition.
//                      Three case are possible :
//                      - The event is eSTMNullEventID, the transition is designed to be polled.
//                      - The event is eSTMNonEventID, the transition is part of a compound transition, the trigger is
//                      defined by the first transition in the list.
//                      - The event is a specific event which fire the transition.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        EventID
// =====================================================================================================================
extern EventID STMTransition_GetEvent(tSTMTransition_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMTransition_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "Action" (public) with reference argument
#define mGetXAction(Ref) STMTransition_ROM_Access(Ref,Action)
// Read value from the attribute "Action" (public) without reference argument
#define mGetAction() STMTransition_ROM_Access(This,Action)

// Read value from the attribute "Guard" (public) with reference argument
#define mGetXGuard(Ref) STMTransition_ROM_Access(Ref,Guard)
// Read value from the attribute "Guard" (public) without reference argument
#define mGetGuard() STMTransition_ROM_Access(This,Guard)

// Read value from the attribute "Event" (public) with reference argument
#define mGetXEvent(Ref) STMTransition_ROM_Access(Ref,Event)
// Read value from the attribute "Event" (public) without reference argument
#define mGetEvent() STMTransition_ROM_Access(This,Event)

#endif // #if (defined(STMTransition_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMTransition_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "pTarget" (protected) with reference argument
#define mGetXpTarget(Ref) STMTransition_ROM_Access(Ref,pTarget)
// Read value from the attribute "pTarget" (protected) without reference argument
#define mGetpTarget() STMTransition_ROM_Access(This,pTarget)

#endif // #if (defined(STMTransition_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>IsPassed
// Method      :        STMTransition_IsPassed(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public
// Description :        Check if the transition can be passed. 
//                      To pass a transition, the event shall be the expected one, the guard shall be true.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
extern boolean STMTransition_IsPassed(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMTransition_PRIVATE_VISIBILITY))
#define mIsPassed(pStateChart, pEvent) \
        STMTransition_IsPassed(This, pStateChart, pEvent)
#endif // #if (defined(STMTransition_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>DoAction
// Method      :        STMTransition_DoAction(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public
// Description :        Execute the action associated to the transition.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void STMTransition_DoAction(tSTMTransition_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMTransition_PRIVATE_VISIBILITY))
#define mDoAction(pStateChart, pEvent) \
        STMTransition_DoAction(This, pStateChart, pEvent)
#endif // #if (defined(STMTransition_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMTransition/<Operation>GetTarget
// Method      :        STMTransition_GetTarget(tSTMTransition_Ref const This)
// Visibility  :        public
// Description :        returns the vertex target.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction) |                                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMTransition_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMStateVertex_Ref
// =====================================================================================================================
extern tSTMStateVertex_Ref STMTransition_GetTarget(tSTMTransition_Ref const This);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMTransition_PRIVATE_VISIBILITY))
#define mGetTarget() \
        STMTransition_GetTarget(This)
#endif // #if (defined(STMTransition_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMTransition_G_h__
