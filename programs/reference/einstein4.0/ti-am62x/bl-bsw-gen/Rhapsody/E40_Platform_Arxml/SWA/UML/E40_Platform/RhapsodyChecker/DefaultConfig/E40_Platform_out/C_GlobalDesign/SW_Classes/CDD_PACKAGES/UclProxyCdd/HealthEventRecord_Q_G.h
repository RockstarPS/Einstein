#ifndef __HealthEventRecord_Q_G_h__
#define __HealthEventRecord_Q_G_h__
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
// Entity:              HealthEventRecord_Q (TransportedInterface)
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

#if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthEventRecord_QProvided
{
    SysReturnType (*SendHealthEventRecordData)(SHealthEventRecord const); // Send operation for HealthEventRecordData
} tHealthEventRecord_QProvided;
#endif // #if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))
typedef const struct sHealthEventRecord_QRequired
{
    SysReturnType (*ReceiveHealthEventRecordData)(SHealthEventRecord * const); // Receive operation for HealthEventRecordData
} tHealthEventRecord_QRequired;
#endif // #if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))
#define mHealthEventRecord_QProvided_Allocate(instanceName, itsHealthEventRecord_Q_FCTTBL) \
    tHealthEventRecord_QProvided instanceName = itsHealthEventRecord_Q_FCTTBL;
#endif // #if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))

#if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))
#define mHealthEventRecord_QRequired_Allocate(instanceName, itsHealthEventRecord_Q_FCTTBL) \
    tHealthEventRecord_QRequired instanceName = itsHealthEventRecord_Q_FCTTBL;
#endif // #if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthEventRecord_Q/<AutoCreatedOperation>SendHealthEventRecordData
// Method      :        HealthEventRecord_Q_SendHealthEventRecordData(tHealthEventRecord_Q_Ref const This, SHealthEventRecord const HealthEventRecordData)
// Visibility  :        public
// Description :        Send operation for HealthEventRecordData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            |      Name(Direction)       |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthEventRecord_Q_Ref  | This(In)                   | Class reference
// SHealthEventRecord        | HealthEventRecordData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthEventRecord_Q_SendHealthEventRecordData(Ref, HealthEventRecordData) \
    (SysReturnType)(Ref)->SendHealthEventRecordData(HealthEventRecordData)

#endif // #if (defined(HealthEventRecord_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthEventRecord_Q/<AutoCreatedOperation>ReceiveHealthEventRecordData
// Method      :        HealthEventRecord_Q_ReceiveHealthEventRecordData(tHealthEventRecord_Q_Ref const This, SHealthEventRecord * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthEventRecordData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthEventRecord_Q_Ref  | This(In)        | Class reference
// SHealthEventRecord        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthEventRecord_Q_ReceiveHealthEventRecordData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthEventRecordData(pdata)

#endif // #if (defined(HealthEventRecord_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthEventRecord_Q_G_h__
