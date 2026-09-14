#ifndef __CSysExclusiveArea_G_h__
#define __CSysExclusiveArea_G_h__
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
// Entity:              CSysExclusiveArea (Class)
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
#define CSysExclusiveArea_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CSysExclusiveArea_PROTECTED_VISIBILITY))
#define CSysExclusiveArea_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CSysExclusiveArea_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CSysExclusiveArea_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysExclusiveArea_VTBL
{
    void (*EnterExclusiveArea)(tCSysExclusiveArea_Ref const); // Defined by the Class "CSysExclusiveArea" as abstract and virtual
    void (*ExitExclusiveArea)(tCSysExclusiveArea_Ref const); // Defined by the Class "CSysExclusiveArea" as abstract and virtual
} tCSysExclusiveArea_VTBL;
typedef tCSysExclusiveArea_VTBL* tCSysExclusiveArea_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysExclusiveArea
{
    tCSysExclusiveArea_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCSysExclusiveArea;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysExclusiveArea_EnterExclusiveArea
//    CSysExclusiveArea_ExitExclusiveArea

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysExclusiveArea/<Operation>EnterExclusiveArea
// Method      :        CSysExclusiveArea_EnterExclusiveArea(tCSysExclusiveArea_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysExclusiveArea_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysExclusiveArea_EnterExclusiveArea(Ref) \
        CSysExclusiveArea_VTBL_Access(Ref)->EnterExclusiveArea(Ref)
#if (defined(CSysExclusiveArea_PRIVATE_VISIBILITY))
#define mEnterExclusiveArea() \
        CSysExclusiveArea_EnterExclusiveArea(This)
#endif // #if (defined(CSysExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/CSysExclusiveArea/<Operation>ExitExclusiveArea
// Method      :        CSysExclusiveArea_ExitExclusiveArea(tCSysExclusiveArea_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type           | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysExclusiveArea_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysExclusiveArea_ExitExclusiveArea(Ref) \
        CSysExclusiveArea_VTBL_Access(Ref)->ExitExclusiveArea(Ref)
#if (defined(CSysExclusiveArea_PRIVATE_VISIBILITY))
#define mExitExclusiveArea() \
        CSysExclusiveArea_ExitExclusiveArea(This)
#endif // #if (defined(CSysExclusiveArea_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CSysExclusiveArea_G_h__
