#ifndef __ISysEventNotification_G_h__
#define __ISysEventNotification_G_h__
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
// Entity:              ISysEventNotification (Interface)
// Description:         Global event notification interface.
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
#define ISysEventNotification_VTBL_Access(classRef) (classRef)->pVTBL
#if (defined(ISysEventNotification_PROTECTED_VISIBILITY))
#define ISysEventNotification_ROM_Access(classRef,attribute) ((classRef)->attribute)
#define ISysEventNotification_ROM_AccessTbl(classRef,idx,attribute) ((classRef)->attribute[idx])
#endif // #if (defined(ISysEventNotification_PROTECTED_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Virtual table definition
// ---------------------------------------------------------------------------------------------------------------------
typedef const struct sISysEventNotification_VTBL
{
    boolean (*ProcessEvt)(void * const, Event_Ref const); // Defined by the Interface "ISysEventNotification" as abstract and virtual
} tISysEventNotification_VTBL;
typedef tISysEventNotification_VTBL* tISysEventNotification_VTBL_Ref;

// ---------------------------------------------------------------------------------------------------------------------
//                               ROM structure (Constant attributes are allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------
typedef struct sISysEventNotification
{
    tISysEventNotification_VTBL_Ref pVTBL; // Auto-generated pointer to virtual table
    void * theObject; //Pointer to the actual object
} tISysEventNotification;

// =====================================================================================================================
//                                                    Class allocator
// =====================================================================================================================
// Class allocator was not created here, because the class is abstract. It does not implement the following method(s):
//    ISysEventNotification_ProcessEvt

// =====================================================================================================================
//                                                    Methods section
// =====================================================================================================================

// ---------------------------------------------------------------------------------------------------------------------
//                                              Virtual & abstract methods
// ---------------------------------------------------------------------------------------------------------------------

// =====================================================================================================================
// Upward trac.:        A2T_TC/A2T_TC_FWK/A2T_SYS/ISysEventNotification/<Operation>ProcessEvt
// Method      :        ISysEventNotification_ProcessEvt(void * const This, Event_Ref const pEvent)
// Visibility  :        public, virtual, abstract
// Description :        Event handler method to be implemented by the Users.
//                      
//                      Return:
//                      cTrue - event consumed.
//                      cFalse - event not consumed.
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//    Type    | Name(Direction) |                                       Description
// ---------------------------------------------------------------------------------------------------------------------
// void *     | This(In)        | Pointer to the actual object
// Event_Ref  | pEvent(In)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        boolean
// =====================================================================================================================
#define ISysEventNotification_ProcessEvt(IRef, pEvent) \
        ISysEventNotification_VTBL_Access(IRef)->ProcessEvt((IRef)->theObject, pEvent)
#if (defined(ISysEventNotification_PRIVATE_VISIBILITY))
#define mProcessEvt(pEvent) \
        ISysEventNotification_ProcessEvt(This, pEvent)
#endif // #if (defined(ISysEventNotification_PRIVATE_VISIBILITY))
// =====================================================================================================================

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __ISysEventNotification_G_h__
