#ifndef __HealthDumpData_Q_G_h__
#define __HealthDumpData_Q_G_h__
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
// Entity:              HealthDumpData_Q (TransportedInterface)
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

#if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))
typedef const struct sHealthDumpData_QProvided
{
    SysReturnType (*SendHealthDumpDataData)(SHealthDumpData const); // Send operation for HealthDumpDataData
} tHealthDumpData_QProvided;
#endif // #if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpData_Q_USAGE_VISIBILITY))
typedef const struct sHealthDumpData_QRequired
{
    SysReturnType (*ReceiveHealthDumpDataData)(SHealthDumpData * const); // Receive operation for HealthDumpDataData
} tHealthDumpData_QRequired;
#endif // #if (defined(HealthDumpData_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))
#define mHealthDumpData_QProvided_Allocate(instanceName, itsHealthDumpData_Q_FCTTBL) \
    tHealthDumpData_QProvided instanceName = itsHealthDumpData_Q_FCTTBL;
#endif // #if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))

#if (defined(HealthDumpData_Q_USAGE_VISIBILITY))
#define mHealthDumpData_QRequired_Allocate(instanceName, itsHealthDumpData_Q_FCTTBL) \
    tHealthDumpData_QRequired instanceName = itsHealthDumpData_Q_FCTTBL;
#endif // #if (defined(HealthDumpData_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpData_Q/<AutoCreatedOperation>SendHealthDumpDataData
// Method      :        HealthDumpData_Q_SendHealthDumpDataData(tHealthDumpData_Q_Ref const This, SHealthDumpData const HealthDumpDataData)
// Visibility  :        public
// Description :        Send operation for HealthDumpDataData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          |     Name(Direction)     |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpData_Q_Ref  | This(In)                | Class reference
// SHealthDumpData        | HealthDumpDataData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpData_Q_SendHealthDumpDataData(Ref, HealthDumpDataData) \
    (SysReturnType)(Ref)->SendHealthDumpDataData(HealthDumpDataData)

#endif // #if (defined(HealthDumpData_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(HealthDumpData_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/HealthDumpData_Q/<AutoCreatedOperation>ReceiveHealthDumpDataData
// Method      :        HealthDumpData_Q_ReceiveHealthDumpDataData(tHealthDumpData_Q_Ref const This, SHealthDumpData * const pdata)
// Visibility  :        public
// Description :        Receive operation for HealthDumpDataData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          | Name(Direction) |                                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tHealthDumpData_Q_Ref  | This(In)        | Class reference
// SHealthDumpData        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define HealthDumpData_Q_ReceiveHealthDumpDataData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceiveHealthDumpDataData(pdata)

#endif // #if (defined(HealthDumpData_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __HealthDumpData_Q_G_h__
