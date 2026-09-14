#ifndef __CSysAlarm_G_h__
#define __CSysAlarm_G_h__
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
// Entity:              CSysAlarm (Class)
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
#define CSysAlarm_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CSysAlarm_PROTECTED_VISIBILITY))
#define CSysAlarm_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CSysAlarm_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CSysAlarm_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysAlarm_VTBL
{
    void (*StartAlarm)(tCSysAlarm_Ref const); // Defined by the Class "CSysAlarm" as abstract and virtual
    void (*CancelAlarm)(tCSysAlarm_Ref const); // Defined by the Class "CSysAlarm" as abstract and virtual
} tCSysAlarm_VTBL;
typedef tCSysAlarm_VTBL* tCSysAlarm_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysAlarm
{
    tCSysAlarm_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCSysAlarm;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysAlarm_StartAlarm
//    CSysAlarm_CancelAlarm

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysAlarm/<Operation>StartAlarm
// Method      :        CSysAlarm_StartAlarm(tCSysAlarm_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type       | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysAlarm_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysAlarm_StartAlarm(Ref) \
        CSysAlarm_VTBL_Access(Ref)->StartAlarm(Ref)
#if (defined(CSysAlarm_PRIVATE_VISIBILITY))
#define mStartAlarm() \
        CSysAlarm_StartAlarm(This)
#endif // #if (defined(CSysAlarm_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysAlarm/<Operation>CancelAlarm
// Method      :        CSysAlarm_CancelAlarm(tCSysAlarm_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type       | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysAlarm_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysAlarm_CancelAlarm(Ref) \
        CSysAlarm_VTBL_Access(Ref)->CancelAlarm(Ref)
#if (defined(CSysAlarm_PRIVATE_VISIBILITY))
#define mCancelAlarm() \
        CSysAlarm_CancelAlarm(This)
#endif // #if (defined(CSysAlarm_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CSysAlarm_G_h__
