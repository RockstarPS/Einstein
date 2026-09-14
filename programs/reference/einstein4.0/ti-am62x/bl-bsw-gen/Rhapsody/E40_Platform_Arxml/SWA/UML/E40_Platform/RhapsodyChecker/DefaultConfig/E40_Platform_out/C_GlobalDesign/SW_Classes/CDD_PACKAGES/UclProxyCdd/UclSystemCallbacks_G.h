#ifndef __UclSystemCallbacks_G_h__
#define __UclSystemCallbacks_G_h__
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
// Generated on Fri Jul 26 12:05:08 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              UclSystemCallbacks (TransportedInterface)
// Description:         None
// Owner:               UclProxyCdd (Package)
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
//                                     Function table declaration (allocated in ROM)
// ---------------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(UclSystemCallbacks_USAGE_VISIBILITY))
typedef const struct sUclSystemCallbacksRequired
{
    SysReturnType (*Call_ErrorNotification)(uint8 const, sint32 const); // Initiate call of ErrorNotification
    SysReturnType (*Call_LinkStatusChanged)(uint8 const, sint32 const); // Initiate call of LinkStatusChanged
} tUclSystemCallbacksRequired;
#endif // #if (defined(UclSystemCallbacks_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(UclSystemCallbacks_USAGE_VISIBILITY))
#define mUclSystemCallbacksRequired_Allocate(instanceName, itsUclSystemCallbacks_FCTTBL) \
    tUclSystemCallbacksRequired instanceName = itsUclSystemCallbacks_FCTTBL;
#endif // #if (defined(UclSystemCallbacks_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(UclSystemCallbacks_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/UclSystemCallbacks/<AutoCreatedOperation>Call_ErrorNotification
// Method      :        UclSystemCallbacks_CallErrorNotification(tUclSystemCallbacks_Ref const This, uint8 const DLInst, sint32 const ErrorCode)
// Visibility  :        public
// Description :        Initiate call of ErrorNotification
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type           | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tUclSystemCallbacks_Ref  | This(In)        | Class reference
// uint8                    | DLInst(In)      | None
// sint32                   | ErrorCode(In)   | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define UclSystemCallbacks_CallErrorNotification(Ref, DLInst, ErrorCode) \
    (SysReturnType)(Ref)->Call_ErrorNotification(DLInst, ErrorCode)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/UclSystemCallbacks/<AutoCreatedOperation>Call_LinkStatusChanged
// Method      :        UclSystemCallbacks_CallLinkStatusChanged(tUclSystemCallbacks_Ref const This, uint8 const DLInst, sint32 const Status)
// Visibility  :        public
// Description :        Initiate call of LinkStatusChanged
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type           | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tUclSystemCallbacks_Ref  | This(In)        | Class reference
// uint8                    | DLInst(In)      | None
// sint32                   | Status(In)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define UclSystemCallbacks_CallLinkStatusChanged(Ref, DLInst, Status) \
    (SysReturnType)(Ref)->Call_LinkStatusChanged(DLInst, Status)

#endif // #if (defined(UclSystemCallbacks_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __UclSystemCallbacks_G_h__
