#ifndef __ISysTaskNotification_G_h__
#define __ISysTaskNotification_G_h__
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
// Entity:              ISysTaskNotification (Interface)
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
#define ISysTaskNotification_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(ISysTaskNotification_PROTECTED_VISIBILITY))
#define ISysTaskNotification_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define ISysTaskNotification_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(ISysTaskNotification_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sISysTaskNotification_VTBL
{
    void (*Task)(void * const); // Defined by the Interface "ISysTaskNotification" as abstract and virtual
} tISysTaskNotification_VTBL;
typedef tISysTaskNotification_VTBL* tISysTaskNotification_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sISysTaskNotification
{
    tISysTaskNotification_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    void * theObject; //Pointer to the actual object
} tISysTaskNotification;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    ISysTaskNotification_Task

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/Osal/ISysTaskNotification/<Operation>Task
// Method      :        ISysTaskNotification_Task(void * const This)
// Visibility  :        public, virtual, abstract
// Description :        None
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//  Type   | Name(Direction) |                                         Description
// ---------------------------------------------------------------------------------------------------------------------
// void *  | This(In)        | Pointer to the actual object
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        void
// =====================================================================================================================
#define ISysTaskNotification_Task(IRef) \
        ISysTaskNotification_VTBL_Access(IRef)->Task((IRef)->theObject)
#if (defined(ISysTaskNotification_PRIVATE_VISIBILITY))
#define mTask() \
        ISysTaskNotification_Task(This)
#endif // #if (defined(ISysTaskNotification_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __ISysTaskNotification_G_h__
