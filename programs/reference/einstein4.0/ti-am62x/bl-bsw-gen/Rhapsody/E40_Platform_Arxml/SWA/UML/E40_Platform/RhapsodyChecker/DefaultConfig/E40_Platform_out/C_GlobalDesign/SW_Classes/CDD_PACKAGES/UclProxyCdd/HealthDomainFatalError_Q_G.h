#ifndef __HealthDomainFatalError_Q_G_h__
#define __HealthDomainFatalError_Q_G_h__
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
// Entity:              HealthDomainFatalError_Q (TransportedInterface)
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

#if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDomainFatalError_QProvided
{
    SysReturnType (*SendHealthDomainFatalErrorData)(SHealthDomainFatalError const); // Send operation for HealthDomainFatalErrorData
} tHealthDomainFatalError_QProvided;
#endif // #if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))
typedef const struct sHealthDomainFatalError_QRequired
{
    SysReturnType (*ReceiveHealthDomainFatalErrorData)(SHealthDomainFatalError * const); // Receive operation for HealthDomainFatalErrorData
} tHealthDomainFatalError_QRequired;
#endif // #if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))
#define mHealthDomainFatalError_QProvided_Allocate(instanceName, itsHealthDomainFatalError_Q_FCTTBL) \
    tHealthDomainFatalError_QProvided instanceName = itsHealthDomainFatalError_Q_FCTTBL;
#endif // #if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))
#define mHealthDomainFatalError_QRequired_Allocate(instanceName, itsHealthDomainFatalError_Q_FCTTBL) \
    tHealthDomainFatalError_QRequired instanceName = itsHealthDomainFatalError_Q_FCTTBL;
#endif // #if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDomainFatalError_Q/<AutoCreatedOperation>SendHealthDomainFatalErrorData
// Method      :        HealthDomainFatalError_Q_SendHealthDomainFatalErrorData(tHealthDomainFatalError_Q_Ref const This, SHealthDomainFatalError const HealthDomainFatalErrorData)
// Visibility  :        public
// Description :        Send operation for HealthDomainFatalErrorData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              |         Name(Direction)         |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDomainFatalError_Q_Ref  | This(In)                        | Class reference
// SHealthDomainFatalError        | HealthDomainFatalErrorData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDomainFatalError_Q_SendHealthDomainFatalErrorData(Ref, HealthDomainFatalErrorData) \
    (SysReturnType)(Ref)->SendHealthDomainFatalErrorData(HealthDomainFatalErrorData)

#endif // #if (defined(HealthDomainFatalError_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDomainFatalError_Q/<AutoCreatedOperation>ReceiveHealthDomainFatalErrorData
// Method      :        HealthDomainFatalError_Q_ReceiveHealthDomainFatalErrorData(tHealthDomainFatalError_Q_Ref const This, SHealthDomainFatalError * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDomainFatalErrorData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type              | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDomainFatalError_Q_Ref  | This(In)        | Class reference
// SHealthDomainFatalError        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDomainFatalError_Q_ReceiveHealthDomainFatalErrorData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDomainFatalErrorData(pdata)

#endif // #if (defined(HealthDomainFatalError_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDomainFatalError_Q_G_h__
