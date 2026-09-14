#ifndef __DiagRoutineRequest_Q_G_h__
#define __DiagRoutineRequest_Q_G_h__
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
// Entity:              DiagRoutineRequest_Q (TransportedInterface)
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

#if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))
typedef const struct sDiagRoutineRequest_QProvided
{
    SysReturnType (*SendDiagRoutineRequestData)(SDiagRoutineRequest const); // Send operation for DiagRoutineRequestData
} tDiagRoutineRequest_QProvided;
#endif // #if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))
typedef const struct sDiagRoutineRequest_QRequired
{
    SysReturnType (*ReceiveDiagRoutineRequestData)(SDiagRoutineRequest * const); // Receive operation for DiagRoutineRequestData
} tDiagRoutineRequest_QRequired;
#endif // #if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))
#define mDiagRoutineRequest_QProvided_Allocate(instanceName, itsDiagRoutineRequest_Q_FCTTBL) \
    tDiagRoutineRequest_QProvided instanceName = itsDiagRoutineRequest_Q_FCTTBL;
#endif // #if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))

#if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))
#define mDiagRoutineRequest_QRequired_Allocate(instanceName, itsDiagRoutineRequest_Q_FCTTBL) \
    tDiagRoutineRequest_QRequired instanceName = itsDiagRoutineRequest_Q_FCTTBL;
#endif // #if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagRoutineRequest_Q/<AutoCreatedOperation>SendDiagRoutineRequestData
// Method      :        DiagRoutineRequest_Q_SendDiagRoutineRequestData(tDiagRoutineRequest_Q_Ref const This, SDiagRoutineRequest const DiagRoutineRequestData)
// Visibility  :        public
// Description :        Send operation for DiagRoutineRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//            Type            |       Name(Direction)       |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagRoutineRequest_Q_Ref  | This(In)                    | Class reference
// SDiagRoutineRequest        | DiagRoutineRequestData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagRoutineRequest_Q_SendDiagRoutineRequestData(Ref, DiagRoutineRequestData) \
    (SysReturnType)(Ref)->SendDiagRoutineRequestData(DiagRoutineRequestData)

#endif // #if (defined(DiagRoutineRequest_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/DiagRoutineRequest_Q/<AutoCreatedOperation>ReceiveDiagRoutineRequestData
// Method      :        DiagRoutineRequest_Q_ReceiveDiagRoutineRequestData(tDiagRoutineRequest_Q_Ref const This, SDiagRoutineRequest * const pdata)
// Visibility  :        public
// Description :        Receive operation for DiagRoutineRequestData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//            Type            | Name(Direction) |                               Description
// ---------------------------------------------------------------------------------------------------------------------
// tDiagRoutineRequest_Q_Ref  | This(In)        | Class reference
// SDiagRoutineRequest        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define DiagRoutineRequest_Q_ReceiveDiagRoutineRequestData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveDiagRoutineRequestData(pdata)

#endif // #if (defined(DiagRoutineRequest_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __DiagRoutineRequest_Q_G_h__
