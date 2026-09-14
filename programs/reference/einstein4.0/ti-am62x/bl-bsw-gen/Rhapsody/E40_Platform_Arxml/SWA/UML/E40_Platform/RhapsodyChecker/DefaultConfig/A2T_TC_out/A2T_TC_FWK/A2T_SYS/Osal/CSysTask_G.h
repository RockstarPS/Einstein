#ifndef __CSysTask_G_h__
#define __CSysTask_G_h__
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
// Generated on Tue Aug 06 13:07:42 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              CSysTask (Class)
// Description:         None
// Owner:               Osal (Package)
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
#define CSysTask_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CSysTask_PROTECTED_VISIBILITY))
#define CSysTask_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CSysTask_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CSysTask_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysTask_VTBL
{
    void (*CancelTask)(tCSysTask_Ref const); // Defined by the Class "CSysTask" as abstract and virtual
    void (*ActivateTask)(tCSysTask_Ref const); // Defined by the Class "CSysTask" as abstract and virtual
} tCSysTask_VTBL;
typedef tCSysTask_VTBL* tCSysTask_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysTask
{
    tCSysTask_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCSysTask;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysTask_CancelTask
//    CSysTask_ActivateTask

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysTask/<Operation>CancelTask
// Method      :        CSysTask_CancelTask(tCSysTask_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysTask_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysTask_CancelTask(Ref) \
        CSysTask_VTBL_Access(Ref)->CancelTask(Ref)
#if (defined(CSysTask_PRIVATE_VISIBILITY))
#define mCancelTask() \
        CSysTask_CancelTask(This)
#endif // #if (defined(CSysTask_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysTask/<Operation>ActivateTask
// Method      :        CSysTask_ActivateTask(tCSysTask_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysTask_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysTask_ActivateTask(Ref) \
        CSysTask_VTBL_Access(Ref)->ActivateTask(Ref)
#if (defined(CSysTask_PRIVATE_VISIBILITY))
#define mActivateTask() \
        CSysTask_ActivateTask(This)
#endif // #if (defined(CSysTask_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CSysTask_G_h__
