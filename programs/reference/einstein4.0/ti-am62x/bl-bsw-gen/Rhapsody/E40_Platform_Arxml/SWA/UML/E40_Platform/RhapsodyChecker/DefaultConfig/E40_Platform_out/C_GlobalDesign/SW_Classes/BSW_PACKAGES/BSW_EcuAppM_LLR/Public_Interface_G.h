#ifndef __Public_Interface_G_h__
#define __Public_Interface_G_h__
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
// Entity:              Public_Interface (Interface)
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
#define Public_Interface_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(Public_Interface_PROTECTED_VISIBILITY))
#define Public_Interface_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define Public_Interface_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(Public_Interface_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sPublic_Interface_VTBL
{
    void (*EcuAppM_SetWakeupSources)(void * const); // Defined by the Interface "Public_Interface" as abstract
    void (*EcuAppM_Init)(void * const); // Defined by the Interface "Public_Interface" as abstract
    void (*EcuAppM_MainFunction)(void * const); // Defined by the Interface "Public_Interface" as abstract
} tPublic_Interface_VTBL;
typedef tPublic_Interface_VTBL* tPublic_Interface_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sPublic_Interface
{
    tPublic_Interface_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    void * theObject; //Pointer to the actual object
} tPublic_Interface;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    Public_Interface_EcuAppM_SetWakeupSources
//    Public_Interface_EcuAppM_Init
//    Public_Interface_EcuAppM_MainFunction

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Public_Interface/<Operation>EcuAppM_SetWakeupSources
// Method      :        Public_Interface_EcuAppM_SetWakeupSources(void * const This)
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
#define Public_Interface_EcuAppM_SetWakeupSources(IRef) \
        Public_Interface_VTBL_Access(IRef)->EcuAppM_SetWakeupSources((IRef)->theObject)
#if (defined(Public_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_SetWakeupSources() \
        Public_Interface_EcuAppM_SetWakeupSources(This)
#endif // #if (defined(Public_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Public_Interface/<Operation>EcuAppM_Init
// Method      :        Public_Interface_EcuAppM_Init(void * const This)
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
#define Public_Interface_EcuAppM_Init(IRef) \
        Public_Interface_VTBL_Access(IRef)->EcuAppM_Init((IRef)->theObject)
#if (defined(Public_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_Init() \
        Public_Interface_EcuAppM_Init(This)
#endif // #if (defined(Public_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/BSW_PACKAGES/BSW_EcuAppM_LLR/Public_Interface/<Operation>EcuAppM_MainFunction
// Method      :        Public_Interface_EcuAppM_MainFunction(void * const This)
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
#define Public_Interface_EcuAppM_MainFunction(IRef) \
        Public_Interface_VTBL_Access(IRef)->EcuAppM_MainFunction((IRef)->theObject)
#if (defined(Public_Interface_PRIVATE_VISIBILITY))
#define mEcuAppM_MainFunction() \
        Public_Interface_EcuAppM_MainFunction(This)
#endif // #if (defined(Public_Interface_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __Public_Interface_G_h__
