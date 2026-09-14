#ifndef __DiagResponse_Q_G_h__
#define __DiagResponse_Q_G_h__
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
// Entity:              DiagResponse_Q (TransportedInterface)
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

#if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))
typedef const struct sDiagResponse_QProvided
{
    SysReturnType (*SendDiagResponseData)(SDiagResponse const); // Send operation for DiagResponseData
} tDiagResponse_QProvided;
#endif // #if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagResponse_Q_USAGE_VISIBILITY))
typedef const struct sDiagResponse_QRequired
{
    SysReturnType (*ReceiveDiagResponseData)(SDiagResponse * const); // Receive operation for DiagResponseData
} tDiagResponse_QRequired;
#endif // #if (defined(DiagResponse_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))
#define mDiagResponse_QProvided_Allocate(instanceName, itsDiagResponse_Q_FCTTBL) \
    tDiagResponse_QProvided instanceName = itsDiagResponse_Q_FCTTBL;
#endif // #if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))

#if (defined(DiagResponse_Q_USAGE_VISIBILITY))
#define mDiagResponse_QRequired_Allocate(instanceName, itsDiagResponse_Q_FCTTBL) \
    tDiagResponse_QRequired instanceName = itsDiagResponse_Q_FCTTBL;
#endif // #if (defined(DiagResponse_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagResponse_Q/<AutoCreatedOperation>SendDiagResponseData
// Method      :        DiagResponse_Q_SendDiagResponseData(tDiagResponse_Q_Ref const This, SDiagResponse const DiagResponseData)
// Visibility  :        public
// Description :        Send operation for DiagResponseData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         |    Name(Direction)    |                               Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagResponse_Q_Ref  | This(In)              | Class reference
// SDiagResponse        | DiagResponseData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagResponse_Q_SendDiagResponseData(Ref, DiagResponseData) \
    (SysReturnType)(Ref)->SendDiagResponseData(DiagResponseData)

#endif // #if (defined(DiagResponse_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagResponse_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagResponse_Q/<AutoCreatedOperation>ReceiveDiagResponseData
// Method      :        DiagResponse_Q_ReceiveDiagResponseData(tDiagResponse_Q_Ref const This, SDiagResponse * const pdata)
// Visibility  :        public
// Description :        Receive operation for DiagResponseData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type         | Name(Direction) |                                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagResponse_Q_Ref  | This(In)        | Class reference
// SDiagResponse        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagResponse_Q_ReceiveDiagResponseData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveDiagResponseData(pdata)

#endif // #if (defined(DiagResponse_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __DiagResponse_Q_G_h__
