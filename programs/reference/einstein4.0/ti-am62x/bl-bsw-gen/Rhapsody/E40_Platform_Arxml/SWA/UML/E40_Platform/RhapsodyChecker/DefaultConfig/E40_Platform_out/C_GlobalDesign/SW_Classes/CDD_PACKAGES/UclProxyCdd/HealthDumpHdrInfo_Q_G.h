#ifndef __HealthDumpHdrInfo_Q_G_h__
#define __HealthDumpHdrInfo_Q_G_h__
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
// Entity:              HealthDumpHdrInfo_Q (TransportedInterface)
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

#if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDumpHdrInfo_QProvided
{
    SysReturnType (*SendHealthDumpHdrInfoData)(SHealthDumpHdrInfo const); // Send operation for HealthDumpHdrInfoData
} tHealthDumpHdrInfo_QProvided;
#endif // #if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))
typedef const struct sHealthDumpHdrInfo_QRequired
{
    SysReturnType (*ReceiveHealthDumpHdrInfoData)(SHealthDumpHdrInfo * const); // Receive operation for HealthDumpHdrInfoData
} tHealthDumpHdrInfo_QRequired;
#endif // #if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))
#define mHealthDumpHdrInfo_QProvided_Allocate(instanceName, itsHealthDumpHdrInfo_Q_FCTTBL) \
    tHealthDumpHdrInfo_QProvided instanceName = itsHealthDumpHdrInfo_Q_FCTTBL;
#endif // #if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))
#define mHealthDumpHdrInfo_QRequired_Allocate(instanceName, itsHealthDumpHdrInfo_Q_FCTTBL) \
    tHealthDumpHdrInfo_QRequired instanceName = itsHealthDumpHdrInfo_Q_FCTTBL;
#endif // #if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpHdrInfo_Q/<AutoCreatedOperation>SendHealthDumpHdrInfoData
// Method      :        HealthDumpHdrInfo_Q_SendHealthDumpHdrInfoData(tHealthDumpHdrInfo_Q_Ref const This, SHealthDumpHdrInfo const HealthDumpHdrInfoData)
// Visibility  :        public
// Description :        Send operation for HealthDumpHdrInfoData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            |      Name(Direction)       |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpHdrInfo_Q_Ref  | This(In)                   | Class reference
// SHealthDumpHdrInfo        | HealthDumpHdrInfoData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpHdrInfo_Q_SendHealthDumpHdrInfoData(Ref, HealthDumpHdrInfoData) \
    (SysReturnType)(Ref)->SendHealthDumpHdrInfoData(HealthDumpHdrInfoData)

#endif // #if (defined(HealthDumpHdrInfo_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpHdrInfo_Q/<AutoCreatedOperation>ReceiveHealthDumpHdrInfoData
// Method      :        HealthDumpHdrInfo_Q_ReceiveHealthDumpHdrInfoData(tHealthDumpHdrInfo_Q_Ref const This, SHealthDumpHdrInfo * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDumpHdrInfoData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpHdrInfo_Q_Ref  | This(In)        | Class reference
// SHealthDumpHdrInfo        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpHdrInfo_Q_ReceiveHealthDumpHdrInfoData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDumpHdrInfoData(pdata)

#endif // #if (defined(HealthDumpHdrInfo_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDumpHdrInfo_Q_G_h__
