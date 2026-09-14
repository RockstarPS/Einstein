#ifndef __CSysItem_G_h__
#define __CSysItem_G_h__
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
// Entity:              CSysItem (Class)
// Description:         Base class for all A2tom objects. Should have a default empty implementation of DeInit.
// Owner:               A2T_SYS (Package)
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
#define CSysItem_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(CSysItem_PROTECTED_VISIBILITY))
#define CSysItem_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define CSysItem_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(CSysItem_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysItem_VTBL
{
    void (*Init)(tCSysItem_Ref const); // Defined by the Class "CSysItem" as abstract and virtual
    void (*DeInit)(tCSysItem_Ref const); // Defined by the Class "CSysItem" as virtual
} tCSysItem_VTBL;
typedef tCSysItem_VTBL* tCSysItem_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sCSysItem
{
    tCSysItem_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
} tCSysItem;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    CSysItem_Init

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/CSysItem/<Operation>Init
// Method      :        CSysItem_Init(tCSysItem_Ref const This)
// Visibility  :        public, virtual, abstract
// Description :        Initialization. Should act as "constructor". I.e. the method can initialize memory, request
//                      system resources, but should not call objects in other Allocatables.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysItem_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define CSysItem_Init(Ref) \
        CSysItem_VTBL_Access(Ref)->Init(Ref)
#if (defined(CSysItem_PRIVATE_VISIBILITY))
#define mInit() \
        CSysItem_Init(This)
#endif // #if (defined(CSysItem_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/CSysItem/<Operation>DeInit
// Method      :        CSysItem_DeInit_Implementation(tCSysItem_Ref const This)
// Visibility  :        public, virtual
// Description :        De-initialization. Should act like a "destructor". I.e. the method can initialize memory,
//                      release System/OS resources, but should not call objects in other Allocatables.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//      Type      | Name(Direction) |                                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tCSysItem_Ref  | This(In)        | Class reference
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
extern void CSysItem_DeInit_Implementation(tCSysItem_Ref const This);
// =====================================================================================================================
#define CSysItem_DeInit(Ref) \
        CSysItem_VTBL_Access(Ref)->DeInit(Ref)

#define CSysItem_DeInit_Explicit(Ref) \
        CSysItem_DeInit_Implementation(Ref)

#if (defined(CSysItem_PRIVATE_VISIBILITY))
#define mDeInit() \
        CSysItem_DeInit(This)

#define mDeInit_Explicit() \
        CSysItem_DeInit_Explicit(This)
#endif // #if (defined(CSysItem_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __CSysItem_G_h__
