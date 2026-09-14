#ifndef __CSysContextStatus_G_h__
#define __CSysContextStatus_G_h__
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
// Entity:              CSysContextStatus (Class)
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
#define CSysContextStatus_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CSysContextStatus_PROTECTED_VISIBILITY))
#define CSysContextStatus_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CSysContextStatus_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CSysContextStatus_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysContextStatus_VTBL
{
    OsTaskIdType (*GetTaskId)(tCSysContextStatus_Ref const); // Defined by the Class "CSysContextStatus" as abstract and virtual
    OsCoreIdType (*GetCoreId)(tCSysContextStatus_Ref const); // Defined by the Class "CSysContextStatus" as abstract and virtual
    OsIsrIdType (*GetIsrId)(tCSysContextStatus_Ref const); // Defined by the Class "CSysContextStatus" as abstract and virtual
    void (*GetContextId)(tCSysContextStatus_Ref const); // Defined by the Class "CSysContextStatus" as abstract and virtual
} tCSysContextStatus_VTBL;
typedef tCSysContextStatus_VTBL* tCSysContextStatus_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysContextStatus
{
    tCSysContextStatus_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCSysContextStatus;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysContextStatus_GetTaskId
//    CSysContextStatus_GetCoreId
//    CSysContextStatus_GetIsrId
//    CSysContextStatus_GetContextId

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysContextStatus/<Operation>GetTaskId
// Method      :        CSysContextStatus_GetTaskId(tCSysContextStatus_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysContextStatus_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        OsTaskIdType
// =====================================================================================================================
#define CSysContextStatus_GetTaskId(Ref) \
        CSysContextStatus_VTBL_Access(Ref)->GetTaskId(Ref)
#if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
#define mGetTaskId() \
        CSysContextStatus_GetTaskId(This)
#endif // #if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysContextStatus/<Operation>GetCoreId
// Method      :        CSysContextStatus_GetCoreId(tCSysContextStatus_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysContextStatus_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        OsCoreIdType
// =====================================================================================================================
#define CSysContextStatus_GetCoreId(Ref) \
        CSysContextStatus_VTBL_Access(Ref)->GetCoreId(Ref)
#if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
#define mGetCoreId() \
        CSysContextStatus_GetCoreId(This)
#endif // #if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysContextStatus/<Operation>GetIsrId
// Method      :        CSysContextStatus_GetIsrId(tCSysContextStatus_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysContextStatus_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        OsIsrIdType
// =====================================================================================================================
#define CSysContextStatus_GetIsrId(Ref) \
        CSysContextStatus_VTBL_Access(Ref)->GetIsrId(Ref)
#if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
#define mGetIsrId() \
        CSysContextStatus_GetIsrId(This)
#endif // #if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysContextStatus/<Operation>GetContextId
// Method      :        CSysContextStatus_GetContextId(tCSysContextStatus_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        This function return the concatenation of Core, Isr and Task to build a unique ContextId
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysContextStatus_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysContextStatus_GetContextId(Ref) \
        CSysContextStatus_VTBL_Access(Ref)->GetContextId(Ref)
#if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
#define mGetContextId() \
        CSysContextStatus_GetContextId(This)
#endif // #if (defined(CSysContextStatus_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CSysContextStatus_G_h__
