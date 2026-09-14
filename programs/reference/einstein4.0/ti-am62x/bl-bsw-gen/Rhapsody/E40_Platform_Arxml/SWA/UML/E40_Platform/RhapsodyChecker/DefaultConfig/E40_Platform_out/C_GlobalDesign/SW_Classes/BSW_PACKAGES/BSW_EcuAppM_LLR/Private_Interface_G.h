#ifndef __Private_Interface_G_h__
#define __Private_Interface_G_h__
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
// Generated on Fri Jul 26 12:05:17 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              Private_Interface (Interface)
// Description:         None
// Owner:               BSW_EcuAppM_LLR (Package)
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
#define Private_Interface_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(Private_Interface_PROTECTED_VISIBILITY))
#define Private_Interface_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define Private_Interface_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(Private_Interface_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sPrivate_Interface_VTBL
{
    void (*EcuAppM_OnPowerSeqStart)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GroupStatusChangeCbk)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_ProcessJobStatus)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_CheckApplicationSleepStatus)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GroupStateChangeRequest)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_ReadWakeupSourcesConfigData)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GroupsDeactivationStatus)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_IsGroupsActivationDeactivationAllowed)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GroupsLifeCycleMgr)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_ProcessGroupsDeactivation)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_ProcessGroupsActivation)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateMachine_EcuAppM_GroupsMgmtState)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_IsPreGroupsActivated)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateChart_Init)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateChart)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateMachine_step)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_StateMachine_initialize)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GetApplicationSleepStatus)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GetWakeupEventStatus)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_SetEcuAppMState)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_GetWakeupSources)(void * const); // Defined by the Interface "Private_Interface" as abstract
    void (*EcuAppM_ClearWakeupSources)(void * const); // Defined by the Interface "Private_Interface" as abstract
} tPrivate_Interface_VTBL;
typedef tPrivate_Interface_VTBL* tPrivate_Interface_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sPrivate_Interface
{
    tPrivate_Interface_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    void * theObject; //Pointer to the actual object
} tPrivate_Interface;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    Private_Interface_EcuAppM_OnPowerSeqStart
//    Private_Interface_EcuAppM_GroupStatusChangeCbk
//    Private_Interface_EcuAppM_ProcessJobStatus
//    Private_Interface_EcuAppM_CheckApplicationSleepStatus
//    Private_Interface_EcuAppM_GroupStateChangeRequest
//    Private_Interface_EcuAppM_ReadWakeupSourcesConfigData
//    Private_Interface_EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState
//    Private_Interface_EcuAppM_GroupsDeactivationStatus
//    Private_Interface_EcuAppM_IsGroupsActivationDeactivationAllowed
//    Private_Interface_EcuAppM_GroupsLifeCycleMgr
//    Private_Interface_EcuAppM_ProcessGroupsDeactivation
//    Private_Interface_EcuAppM_ProcessGroupsActivation
//    Private_Interface_EcuAppM_StateMachine_EcuAppM_GroupsMgmtState
//    Private_Interface_EcuAppM_IsPreGroupsActivated
//    Private_Interface_EcuAppM_StateChart_Init
//    Private_Interface_EcuAppM_StateChart
//    Private_Interface_EcuAppM_StateMachine_step
//    Private_Interface_EcuAppM_StateMachine_initialize
//    Private_Interface_EcuAppM_GetApplicationSleepStatus
//    Private_Interface_EcuAppM_GetWakeupEventStatus
//    Private_Interface_EcuAppM_SetEcuAppMState
//    Private_Interface_EcuAppM_GetWakeupSources
//    Private_Interface_EcuAppM_ClearWakeupSources

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_OnPowerSeqStart
// Method      :        Private_Interface_EcuAppM_OnPowerSeqStart(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_OnPowerSeqStart(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_OnPowerSeqStart((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_OnPowerSeqStart() \
        Private_Interface_EcuAppM_OnPowerSeqStart(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GroupStatusChangeCbk
// Method      :        Private_Interface_EcuAppM_GroupStatusChangeCbk(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GroupStatusChangeCbk(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GroupStatusChangeCbk((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GroupStatusChangeCbk() \
        Private_Interface_EcuAppM_GroupStatusChangeCbk(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_ProcessJobStatus
// Method      :        Private_Interface_EcuAppM_ProcessJobStatus(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_ProcessJobStatus(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_ProcessJobStatus((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_ProcessJobStatus() \
        Private_Interface_EcuAppM_ProcessJobStatus(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_CheckApplicationSleepStatus
// Method      :        Private_Interface_EcuAppM_CheckApplicationSleepStatus(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_CheckApplicationSleepStatus(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_CheckApplicationSleepStatus((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_CheckApplicationSleepStatus() \
        Private_Interface_EcuAppM_CheckApplicationSleepStatus(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GroupStateChangeRequest
// Method      :        Private_Interface_EcuAppM_GroupStateChangeRequest(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GroupStateChangeRequest(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GroupStateChangeRequest((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GroupStateChangeRequest() \
        Private_Interface_EcuAppM_GroupStateChangeRequest(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_ReadWakeupSourcesConfigData
// Method      :        Private_Interface_EcuAppM_ReadWakeupSourcesConfigData(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_ReadWakeupSourcesConfigData(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_ReadWakeupSourcesConfigData((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_ReadWakeupSourcesConfigData() \
        Private_Interface_EcuAppM_ReadWakeupSourcesConfigData(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState
// Method      :        Private_Interface_EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState() \
        Private_Interface_EcuAppM_StateMachine_enter_internal_EcuAppM_GroupsMgmtState(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GroupsDeactivationStatus
// Method      :        Private_Interface_EcuAppM_GroupsDeactivationStatus(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GroupsDeactivationStatus(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GroupsDeactivationStatus((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GroupsDeactivationStatus() \
        Private_Interface_EcuAppM_GroupsDeactivationStatus(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_IsGroupsActivationDeactivationAllowed
// Method      :        Private_Interface_EcuAppM_IsGroupsActivationDeactivationAllowed(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_IsGroupsActivationDeactivationAllowed(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_IsGroupsActivationDeactivationAllowed((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_IsGroupsActivationDeactivationAllowed() \
        Private_Interface_EcuAppM_IsGroupsActivationDeactivationAllowed(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GroupsLifeCycleMgr
// Method      :        Private_Interface_EcuAppM_GroupsLifeCycleMgr(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GroupsLifeCycleMgr(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GroupsLifeCycleMgr((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GroupsLifeCycleMgr() \
        Private_Interface_EcuAppM_GroupsLifeCycleMgr(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_ProcessGroupsDeactivation
// Method      :        Private_Interface_EcuAppM_ProcessGroupsDeactivation(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_ProcessGroupsDeactivation(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_ProcessGroupsDeactivation((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_ProcessGroupsDeactivation() \
        Private_Interface_EcuAppM_ProcessGroupsDeactivation(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_ProcessGroupsActivation
// Method      :        Private_Interface_EcuAppM_ProcessGroupsActivation(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_ProcessGroupsActivation(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_ProcessGroupsActivation((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_ProcessGroupsActivation() \
        Private_Interface_EcuAppM_ProcessGroupsActivation(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateMachine_EcuAppM_GroupsMgmtState
// Method      :        Private_Interface_EcuAppM_StateMachine_EcuAppM_GroupsMgmtState(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateMachine_EcuAppM_GroupsMgmtState(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateMachine_EcuAppM_GroupsMgmtState((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateMachine_EcuAppM_GroupsMgmtState() \
        Private_Interface_EcuAppM_StateMachine_EcuAppM_GroupsMgmtState(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_IsPreGroupsActivated
// Method      :        Private_Interface_EcuAppM_IsPreGroupsActivated(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_IsPreGroupsActivated(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_IsPreGroupsActivated((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_IsPreGroupsActivated() \
        Private_Interface_EcuAppM_IsPreGroupsActivated(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateChart_Init
// Method      :        Private_Interface_EcuAppM_StateChart_Init(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateChart_Init(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateChart_Init((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateChart_Init() \
        Private_Interface_EcuAppM_StateChart_Init(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateChart
// Method      :        Private_Interface_EcuAppM_StateChart(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateChart(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateChart((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateChart() \
        Private_Interface_EcuAppM_StateChart(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateMachine_step
// Method      :        Private_Interface_EcuAppM_StateMachine_step(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateMachine_step(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateMachine_step((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateMachine_step() \
        Private_Interface_EcuAppM_StateMachine_step(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_StateMachine_initialize
// Method      :        Private_Interface_EcuAppM_StateMachine_initialize(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_StateMachine_initialize(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_StateMachine_initialize((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_StateMachine_initialize() \
        Private_Interface_EcuAppM_StateMachine_initialize(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GetApplicationSleepStatus
// Method      :        Private_Interface_EcuAppM_GetApplicationSleepStatus(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GetApplicationSleepStatus(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GetApplicationSleepStatus((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GetApplicationSleepStatus() \
        Private_Interface_EcuAppM_GetApplicationSleepStatus(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GetWakeupEventStatus
// Method      :        Private_Interface_EcuAppM_GetWakeupEventStatus(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GetWakeupEventStatus(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GetWakeupEventStatus((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GetWakeupEventStatus() \
        Private_Interface_EcuAppM_GetWakeupEventStatus(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_SetEcuAppMState
// Method      :        Private_Interface_EcuAppM_SetEcuAppMState(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_SetEcuAppMState(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_SetEcuAppMState((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_SetEcuAppMState() \
        Private_Interface_EcuAppM_SetEcuAppMState(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_GetWakeupSources
// Method      :        Private_Interface_EcuAppM_GetWakeupSources(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_GetWakeupSources(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_GetWakeupSources((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_GetWakeupSources() \
        Private_Interface_EcuAppM_GetWakeupSources(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Private_Interface/<Operation>EcuAppM_ClearWakeupSources
// Method      :        Private_Interface_EcuAppM_ClearWakeupSources(void * const This)
// Visibility  :        public, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define Private_Interface_EcuAppM_ClearWakeupSources(IRef) \
        Private_Interface_VTBL_Access(IRef)->EcuAppM_ClearWakeupSources((IRef)->theObject)
#if (defined(Private_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_ClearWakeupSources() \
        Private_Interface_EcuAppM_ClearWakeupSources(This)
#endif // #if (defined(Private_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __Private_Interface_G_h__
