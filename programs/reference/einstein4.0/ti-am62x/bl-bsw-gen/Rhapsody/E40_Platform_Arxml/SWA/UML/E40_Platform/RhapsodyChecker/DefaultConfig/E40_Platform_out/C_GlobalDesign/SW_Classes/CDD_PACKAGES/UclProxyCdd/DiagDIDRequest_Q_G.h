#ifndef __DiagDIDRequest_Q_G_h__
#define __DiagDIDRequest_Q_G_h__
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
// Entity:              DiagDIDRequest_Q (TransportedInterface)
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

#if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))
typedef const struct sDiagDIDRequest_QProvided
{
    SysReturnType (*SendDiagDIDRequestData)(SDiagDIDRequest const); // Send operation for DiagDIDRequestData
} tDiagDIDRequest_QProvided;
#endif // #if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))
typedef const struct sDiagDIDRequest_QRequired
{
    SysReturnType (*ReceiveDiagDIDRequestData)(SDiagDIDRequest * const); // Receive operation for DiagDIDRequestData
} tDiagDIDRequest_QRequired;
#endif // #if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))
#define mDiagDIDRequest_QProvided_Allocate(instanceName, itsDiagDIDRequest_Q_FCTTBL) \
    tDiagDIDRequest_QProvided instanceName = itsDiagDIDRequest_Q_FCTTBL;
#endif // #if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))

#if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))
#define mDiagDIDRequest_QRequired_Allocate(instanceName, itsDiagDIDRequest_Q_FCTTBL) \
    tDiagDIDRequest_QRequired instanceName = itsDiagDIDRequest_Q_FCTTBL;
#endif // #if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagDIDRequest_Q/<AutoCreatedOperation>SendDiagDIDRequestData
// Method      :        DiagDIDRequest_Q_SendDiagDIDRequestData(tDiagDIDRequest_Q_Ref const This, SDiagDIDRequest const DiagDIDRequestData)
// Visibility  :        public
// Description :        Send operation for DiagDIDRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          |     Name(Direction)     |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagDIDRequest_Q_Ref  | This(In)                | Class reference
// SDiagDIDRequest        | DiagDIDRequestData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagDIDRequest_Q_SendDiagDIDRequestData(Ref, DiagDIDRequestData) \
    (SysReturnType)(Ref)->SendDiagDIDRequestData(DiagDIDRequestData)

#endif // #if (defined(DiagDIDRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagDIDRequest_Q/<AutoCreatedOperation>ReceiveDiagDIDRequestData
// Method      :        DiagDIDRequest_Q_ReceiveDiagDIDRequestData(tDiagDIDRequest_Q_Ref const This, SDiagDIDRequest * const pdata)
// Visibility  :        public
// Description :        Receive operation for DiagDIDRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagDIDRequest_Q_Ref  | This(In)        | Class reference
// SDiagDIDRequest        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagDIDRequest_Q_ReceiveDiagDIDRequestData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveDiagDIDRequestData(pdata)

#endif // #if (defined(DiagDIDRequest_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __DiagDIDRequest_Q_G_h__
