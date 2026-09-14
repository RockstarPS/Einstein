#ifndef __STMRegion_G_h__
#define __STMRegion_G_h__
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
// Entity:              STMRegion (Class)
// Description:         A region is an orthogonal  part (At one time only one state of the region can be active ) of
//                      either a ANDState or a StateChart.
//                      From a model point view, It contains states and transitions.
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
#define STMRegion_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(STMRegion_PROTECTED_VISIBILITY))
#define STMRegion_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define STMRegion_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(STMRegion_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMRegion_VTBL
{
    void (*Activate)(tSTMRegion_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMRegion" as virtual
    void (*DeActivate)(tSTMRegion_Ref const, tSTMStateChart_Ref const); // Defined by the Class "STMRegion" as virtual
    boolean (*ProcessEvt)(tSTMRegion_Ref const, tSTMStateChart_Ref const, Event_Ref const); // Defined by the Class "STMRegion" as virtual
    boolean (*IsIn)(tSTMRegion_Ref const, tSTMStateChart_Ref const, tSTMState_Ref const); // Defined by the Class "STMRegion" as virtual
} tSTMRegion_VTBL;
typedef tSTMRegion_VTBL* tSTMRegion_VTBL_Ref;

extern tSTMRegion_VTBL STMRegion_VTBL;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sSTMRegion
{
    tSTMRegion_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
// CurentStateID is an index in the StateTable owed by the statechart.
// The item in the table is used to save the curent state in the Region.
// When item is NULL, this mean that the Region is not activated.
    uint16 CurentStateID; // public
// Pointer to manage the relation EntryState(association, multiplicity[1])
    tSTMState_Ref pEntryState; // protected
} tSTMRegion;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================

// Standard allocator mSTMRegion_Allocate

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMRegion_Allocate(instanceName, CurentStateID, pEntryState) \
                                                                                                                        \
tSTMRegion instanceName = {\
    &STMRegion_VTBL, \
    CurentStateID, \
    pEntryState \
}
// ---------------------------------------------------------------------------------------------------------------------

// Explicit allocator mSTMRegion_Allocate_Explicit

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Allocator definition
// ---------------------------------------------------------------------------------------------------------------------
#define mSTMRegion_Allocate_Explicit(instanceName, CurentStateID, pEntryState) \
                                                                                                                        \
tSTMRegion instanceName = {\
    &STMRegion_VTBL, \
    CurentStateID, \
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
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<AutoCreatedOperation>GetCurentStateID
// Method      :        STMRegion_GetCurentStateID(tSTMRegion_Ref const This)
// Visibility  :        public
// Description :        Read value from CurentStateID (Multiplicity [1])
//                      CurentStateID is an index in the StateTable owed by the statechart.
//                      The item in the table is used to save the curent state in the Region.
//                      When item is NULL, this mean that the Region is not activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type       | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        uint16
// =====================================================================================================================
extern uint16 STMRegion_GetCurentStateID(tSTMRegion_Ref const This);

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMRegion_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                      Read macro for public, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "CurentStateID" (public) with reference argument
#define mGetXCurentStateID(Ref) STMRegion_ROM_Access(Ref,CurentStateID)
// Read value from the attribute "CurentStateID" (public) without reference argument
#define mGetCurentStateID() STMRegion_ROM_Access(This,CurentStateID)

#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                           Attributes with protected access
// ---------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------------------------------
//                                        Short accessors for in-class usage only
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(STMRegion_PRIVATE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                     Read macro for protected, constant attributes
// ---------------------------------------------------------------------------------------------------------------------

// Read value from the attribute "pEntryState" (protected) with reference argument
#define mGetXpEntryState(Ref) STMRegion_ROM_Access(Ref,pEntryState)
// Read value from the attribute "pEntryState" (protected) without reference argument
#define mGetpEntryState() STMRegion_ROM_Access(This,pEntryState)

#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>Activate
// Method      :        STMRegion_Activate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Activate the Region.
//                      At activation time the entry state is activated (entry actions are executed).
//                      After actiavtion the Region is able to process events.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void STMRegion_Activate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMRegion_Activate(Ref, pStateChart) \
        STMRegion_VTBL_Access(Ref)->Activate(Ref, pStateChart)

#define STMRegion_Activate_Explicit(Ref, pStateChart) \
        STMRegion_Activate_Implementation(Ref, pStateChart)

#if (defined(STMRegion_PRIVATE_VISIBILITY))
#define mActivate(pStateChart) \
        STMRegion_Activate(This, pStateChart)

#define mActivate_Explicit(pStateChart) \
        STMRegion_Activate_Explicit(This, pStateChart)
#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>DeActivate
// Method      :        STMRegion_DeActivate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public, virtual
// Description :        Deactivate the Region.
//                      Active state is exited, exit actions are executed.
//                      After activation the Region is not consuming any event.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void STMRegion_DeActivate_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart);
// =====================================================================================================================
#define STMRegion_DeActivate(Ref, pStateChart) \
        STMRegion_VTBL_Access(Ref)->DeActivate(Ref, pStateChart)

#define STMRegion_DeActivate_Explicit(Ref, pStateChart) \
        STMRegion_DeActivate_Implementation(Ref, pStateChart)

#if (defined(STMRegion_PRIVATE_VISIBILITY))
#define mDeActivate(pStateChart) \
        STMRegion_DeActivate(This, pStateChart)

#define mDeActivate_Explicit(pStateChart) \
        STMRegion_DeActivate_Explicit(This, pStateChart)
#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>ProcessEvt
// Method      :        STMRegion_ProcessEvt_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent)
// Visibility  :        public, virtual
// Description :        Verify if the event can be consumed in the curent state, and exectute the transition if needed.
//                      Returns cTrue if the event is consumed.
//                      
//                      Note that this function allways returns false if the region is deactivated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// Event_Ref           | pEvent(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
extern boolean STMRegion_ProcessEvt_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, Event_Ref const pEvent);
// =====================================================================================================================
#define STMRegion_ProcessEvt(Ref, pStateChart, pEvent) \
        STMRegion_VTBL_Access(Ref)->ProcessEvt(Ref, pStateChart, pEvent)

#define STMRegion_ProcessEvt_Explicit(Ref, pStateChart, pEvent) \
        STMRegion_ProcessEvt_Implementation(Ref, pStateChart, pEvent)

#if (defined(STMRegion_PRIVATE_VISIBILITY))
#define mProcessEvt(pStateChart, pEvent) \
        STMRegion_ProcessEvt(This, pStateChart, pEvent)

#define mProcessEvt_Explicit(pStateChart, pEvent) \
        STMRegion_ProcessEvt_Explicit(This, pStateChart, pEvent)
#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>IsIn
// Method      :        STMRegion_IsIn_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const pState)
// Visibility  :        public, virtual
// Description :        Return true if the curent state is "This" state or one "This" sub-state.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// tSTMState_Ref       | pState(In)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
extern boolean STMRegion_IsIn_Implementation(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart, tSTMState_Ref const pState);
// =====================================================================================================================
#define STMRegion_IsIn(Ref, pStateChart, pState) \
        STMRegion_VTBL_Access(Ref)->IsIn(Ref, pStateChart, pState)

#define STMRegion_IsIn_Explicit(Ref, pStateChart, pState) \
        STMRegion_IsIn_Implementation(Ref, pStateChart, pState)

#if (defined(STMRegion_PRIVATE_VISIBILITY))
#define mIsIn(pStateChart, pState) \
        STMRegion_IsIn(This, pStateChart, pState)

#define mIsIn_Explicit(pStateChart, pState) \
        STMRegion_IsIn_Explicit(This, pStateChart, pState)
#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                                Public methods section
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/STM_ENGINE/STMRegion/<Operation>GetCurentState
// Method      :        STMRegion_GetCurentState(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart)
// Visibility  :        public
// Description :        Returns a pointer to the curent state.
//                      Returns NULL if the statechart is not activated.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//        Type         | Name(Direction)  |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tSTMRegion_Ref      | This(In)         | Class reference
// tSTMStateChart_Ref  | pStateChart(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        tSTMState_Ref
// =====================================================================================================================
extern tSTMState_Ref STMRegion_GetCurentState(tSTMRegion_Ref const This, tSTMStateChart_Ref const pStateChart);
// ---------------------------------------------------------------------------------------------------------------------
#if (defined(STMRegion_PRIVATE_VISIBILITY))
#define mGetCurentState(pStateChart) \
        STMRegion_GetCurentState(This, pStateChart)
#endif // #if (defined(STMRegion_PRIVATE_VISIBILITY))
// ---------------------------------------------------------------------------------------------------------------------

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __STMRegion_G_h__
