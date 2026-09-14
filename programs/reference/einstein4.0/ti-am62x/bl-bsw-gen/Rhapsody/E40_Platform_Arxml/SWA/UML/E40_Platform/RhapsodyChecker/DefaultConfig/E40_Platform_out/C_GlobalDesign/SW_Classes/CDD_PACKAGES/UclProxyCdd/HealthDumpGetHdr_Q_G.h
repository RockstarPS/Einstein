#ifndef __HealthDumpGetHdr_Q_G_h__
#define __HealthDumpGetHdr_Q_G_h__
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
// Entity:              HealthDumpGetHdr_Q (TransportedInterface)
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

#if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDumpGetHdr_QProvided
{
    SysReturnType (*SendHealthDumpGetHdrData)(SHealthDumpGetHdr const); // Send operation for HealthDumpGetHdrData
} tHealthDumpGetHdr_QProvided;
#endif // #if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))
typedef const struct sHealthDumpGetHdr_QRequired
{
    SysReturnType (*ReceiveHealthDumpGetHdrData)(SHealthDumpGetHdr * const); // Receive operation for HealthDumpGetHdrData
} tHealthDumpGetHdr_QRequired;
#endif // #if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))
#define mHealthDumpGetHdr_QProvided_Allocate(instanceName, itsHealthDumpGetHdr_Q_FCTTBL) \
    tHealthDumpGetHdr_QProvided instanceName = itsHealthDumpGetHdr_Q_FCTTBL;
#endif // #if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))
#define mHealthDumpGetHdr_QRequired_Allocate(instanceName, itsHealthDumpGetHdr_Q_FCTTBL) \
    tHealthDumpGetHdr_QRequired instanceName = itsHealthDumpGetHdr_Q_FCTTBL;
#endif // #if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpGetHdr_Q/<AutoCreatedOperation>SendHealthDumpGetHdrData
// Method      :        HealthDumpGetHdr_Q_SendHealthDumpGetHdrData(tHealthDumpGetHdr_Q_Ref const This, SHealthDumpGetHdr const HealthDumpGetHdrData)
// Visibility  :        public
// Description :        Send operation for HealthDumpGetHdrData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type           |      Name(Direction)      |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpGetHdr_Q_Ref  | This(In)                  | Class reference
// SHealthDumpGetHdr        | HealthDumpGetHdrData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpGetHdr_Q_SendHealthDumpGetHdrData(Ref, HealthDumpGetHdrData) \
    (SysReturnType)(Ref)->SendHealthDumpGetHdrData(HealthDumpGetHdrData)

#endif // #if (defined(HealthDumpGetHdr_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpGetHdr_Q/<AutoCreatedOperation>ReceiveHealthDumpGetHdrData
// Method      :        HealthDumpGetHdr_Q_ReceiveHealthDumpGetHdrData(tHealthDumpGetHdr_Q_Ref const This, SHealthDumpGetHdr * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDumpGetHdrData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type           | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpGetHdr_Q_Ref  | This(In)        | Class reference
// SHealthDumpGetHdr        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpGetHdr_Q_ReceiveHealthDumpGetHdrData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDumpGetHdrData(pdata)

#endif // #if (defined(HealthDumpGetHdr_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDumpGetHdr_Q_G_h__
