#ifndef __DiagIOCtrlRequest_Q_G_h__
#define __DiagIOCtrlRequest_Q_G_h__
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
// Generated on Fri Jul 26 12:05:09 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              DiagIOCtrlRequest_Q (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))
typedef const struct sDiagIOCtrlRequest_QProvided
{
    SysReturnType (*SendDiagIOCtrlRequestData)(SDiagIOCtrlRequest const); // Send operation for DiagIOCtrlRequestData
} tDiagIOCtrlRequest_QProvided;
#endif // #if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))
typedef const struct sDiagIOCtrlRequest_QRequired
{
    SysReturnType (*ReceiveDiagIOCtrlRequestData)(SDiagIOCtrlRequest * const); // Receive operation for DiagIOCtrlRequestData
} tDiagIOCtrlRequest_QRequired;
#endif // #if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))
#define mDiagIOCtrlRequest_QProvided_Allocate(instanceName, itsDiagIOCtrlRequest_Q_FCTTBL) \
    tDiagIOCtrlRequest_QProvided instanceName = itsDiagIOCtrlRequest_Q_FCTTBL;
#endif // #if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))

#if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))
#define mDiagIOCtrlRequest_QRequired_Allocate(instanceName, itsDiagIOCtrlRequest_Q_FCTTBL) \
    tDiagIOCtrlRequest_QRequired instanceName = itsDiagIOCtrlRequest_Q_FCTTBL;
#endif // #if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagIOCtrlRequest_Q/<AutoCreatedOperation>SendDiagIOCtrlRequestData
// Method      :        DiagIOCtrlRequest_Q_SendDiagIOCtrlRequestData(tDiagIOCtrlRequest_Q_Ref const This, SDiagIOCtrlRequest const DiagIOCtrlRequestData)
// Visibility  :        public
// Description :        Send operation for DiagIOCtrlRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            |      Name(Direction)       |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagIOCtrlRequest_Q_Ref  | This(In)                   | Class reference
// SDiagIOCtrlRequest        | DiagIOCtrlRequestData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagIOCtrlRequest_Q_SendDiagIOCtrlRequestData(Ref, DiagIOCtrlRequestData) \
    (SysReturnType)(Ref)->SendDiagIOCtrlRequestData(DiagIOCtrlRequestData)

#endif // #if (defined(DiagIOCtrlRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagIOCtrlRequest_Q/<AutoCreatedOperation>ReceiveDiagIOCtrlRequestData
// Method      :        DiagIOCtrlRequest_Q_ReceiveDiagIOCtrlRequestData(tDiagIOCtrlRequest_Q_Ref const This, SDiagIOCtrlRequest * const pdata)
// Visibility  :        public
// Description :        Receive operation for DiagIOCtrlRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagIOCtrlRequest_Q_Ref  | This(In)        | Class reference
// SDiagIOCtrlRequest        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagIOCtrlRequest_Q_ReceiveDiagIOCtrlRequestData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveDiagIOCtrlRequestData(pdata)

#endif // #if (defined(DiagIOCtrlRequest_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __DiagIOCtrlRequest_Q_G_h__
