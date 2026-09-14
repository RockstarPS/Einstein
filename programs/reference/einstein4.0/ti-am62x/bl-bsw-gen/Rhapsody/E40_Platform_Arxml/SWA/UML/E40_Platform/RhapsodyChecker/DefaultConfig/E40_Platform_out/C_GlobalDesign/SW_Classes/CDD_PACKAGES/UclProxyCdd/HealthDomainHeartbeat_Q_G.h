#ifndef __HealthDomainHeartbeat_Q_G_h__
#define __HealthDomainHeartbeat_Q_G_h__
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
// Entity:              HealthDomainHeartbeat_Q (TransportedInterface)
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

#if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDomainHeartbeat_QProvided
{
    SysReturnType (*SendHealthDomainHeartbeatData)(SHealthDomainHeartbeat const); // Send operation for HealthDomainHeartbeatData
} tHealthDomainHeartbeat_QProvided;
#endif // #if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))
typedef const struct sHealthDomainHeartbeat_QRequired
{
    SysReturnType (*ReceiveHealthDomainHeartbeatData)(SHealthDomainHeartbeat * const); // Receive operation for HealthDomainHeartbeatData
} tHealthDomainHeartbeat_QRequired;
#endif // #if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))
#define mHealthDomainHeartbeat_QProvided_Allocate(instanceName, itsHealthDomainHeartbeat_Q_FCTTBL) \
    tHealthDomainHeartbeat_QProvided instanceName = itsHealthDomainHeartbeat_Q_FCTTBL;
#endif // #if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))
#define mHealthDomainHeartbeat_QRequired_Allocate(instanceName, itsHealthDomainHeartbeat_Q_FCTTBL) \
    tHealthDomainHeartbeat_QRequired instanceName = itsHealthDomainHeartbeat_Q_FCTTBL;
#endif // #if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDomainHeartbeat_Q/<AutoCreatedOperation>SendHealthDomainHeartbeatData
// Method      :        HealthDomainHeartbeat_Q_SendHealthDomainHeartbeatData(tHealthDomainHeartbeat_Q_Ref const This, SHealthDomainHeartbeat const HealthDomainHeartbeatData)
// Visibility  :        public
// Description :        Send operation for HealthDomainHeartbeatData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type              |        Name(Direction)         |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDomainHeartbeat_Q_Ref  | This(In)                       | Class reference
// SHealthDomainHeartbeat        | HealthDomainHeartbeatData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDomainHeartbeat_Q_SendHealthDomainHeartbeatData(Ref, HealthDomainHeartbeatData) \
    (SysReturnType)(Ref)->SendHealthDomainHeartbeatData(HealthDomainHeartbeatData)

#endif // #if (defined(HealthDomainHeartbeat_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDomainHeartbeat_Q/<AutoCreatedOperation>ReceiveHealthDomainHeartbeatData
// Method      :        HealthDomainHeartbeat_Q_ReceiveHealthDomainHeartbeatData(tHealthDomainHeartbeat_Q_Ref const This, SHealthDomainHeartbeat * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDomainHeartbeatData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type              | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDomainHeartbeat_Q_Ref  | This(In)        | Class reference
// SHealthDomainHeartbeat        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDomainHeartbeat_Q_ReceiveHealthDomainHeartbeatData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDomainHeartbeatData(pdata)

#endif // #if (defined(HealthDomainHeartbeat_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDomainHeartbeat_Q_G_h__
