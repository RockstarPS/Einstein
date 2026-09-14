#ifndef __HealthDumpGetData_Q_G_h__
#define __HealthDumpGetData_Q_G_h__
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
// Entity:              HealthDumpGetData_Q (TransportedInterface)
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

#if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDumpGetData_QProvided
{
    SysReturnType (*SendHealthDumpGetDataData)(SHealthDumpGetData const); // Send operation for HealthDumpGetDataData
} tHealthDumpGetData_QProvided;
#endif // #if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))
typedef const struct sHealthDumpGetData_QRequired
{
    SysReturnType (*ReceiveHealthDumpGetDataData)(SHealthDumpGetData * const); // Receive operation for HealthDumpGetDataData
} tHealthDumpGetData_QRequired;
#endif // #if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))
#define mHealthDumpGetData_QProvided_Allocate(instanceName, itsHealthDumpGetData_Q_FCTTBL) \
    tHealthDumpGetData_QProvided instanceName = itsHealthDumpGetData_Q_FCTTBL;
#endif // #if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))
#define mHealthDumpGetData_QRequired_Allocate(instanceName, itsHealthDumpGetData_Q_FCTTBL) \
    tHealthDumpGetData_QRequired instanceName = itsHealthDumpGetData_Q_FCTTBL;
#endif // #if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpGetData_Q/<AutoCreatedOperation>SendHealthDumpGetDataData
// Method      :        HealthDumpGetData_Q_SendHealthDumpGetDataData(tHealthDumpGetData_Q_Ref const This, SHealthDumpGetData const HealthDumpGetDataData)
// Visibility  :        public
// Description :        Send operation for HealthDumpGetDataData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            |      Name(Direction)       |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpGetData_Q_Ref  | This(In)                   | Class reference
// SHealthDumpGetData        | HealthDumpGetDataData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpGetData_Q_SendHealthDumpGetDataData(Ref, HealthDumpGetDataData) \
    (SysReturnType)(Ref)->SendHealthDumpGetDataData(HealthDumpGetDataData)

#endif // #if (defined(HealthDumpGetData_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpGetData_Q/<AutoCreatedOperation>ReceiveHealthDumpGetDataData
// Method      :        HealthDumpGetData_Q_ReceiveHealthDumpGetDataData(tHealthDumpGetData_Q_Ref const This, SHealthDumpGetData * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDumpGetDataData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//           Type            | Name(Direction) |                                Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpGetData_Q_Ref  | This(In)        | Class reference
// SHealthDumpGetData        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpGetData_Q_ReceiveHealthDumpGetDataData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDumpGetDataData(pdata)

#endif // #if (defined(HealthDumpGetData_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDumpGetData_Q_G_h__
