#ifndef __PowerExtendShutdownTime_Q_G_h__
#define __PowerExtendShutdownTime_Q_G_h__
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
// Entity:              PowerExtendShutdownTime_Q (TransportedInterface)
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

#if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))
typedef const struct sPowerExtendShutdownTime_QProvided
{
    SysReturnType (*SendPowerExtendShutdownTimeData)(SPowerExtendShutdownTime const); // Send operation for PowerExtendShutdownTimeData
} tPowerExtendShutdownTime_QProvided;
#endif // #if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))
typedef const struct sPowerExtendShutdownTime_QRequired
{
    SysReturnType (*ReceivePowerExtendShutdownTimeData)(SPowerExtendShutdownTime * const); // Receive operation for PowerExtendShutdownTimeData
} tPowerExtendShutdownTime_QRequired;
#endif // #if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))
#define mPowerExtendShutdownTime_QProvided_Allocate(instanceName, itsPowerExtendShutdownTime_Q_FCTTBL) \
    tPowerExtendShutdownTime_QProvided instanceName = itsPowerExtendShutdownTime_Q_FCTTBL;
#endif // #if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))

#if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))
#define mPowerExtendShutdownTime_QRequired_Allocate(instanceName, itsPowerExtendShutdownTime_Q_FCTTBL) \
    tPowerExtendShutdownTime_QRequired instanceName = itsPowerExtendShutdownTime_Q_FCTTBL;
#endif // #if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerExtendShutdownTime_Q/<AutoCreatedOperation>SendPowerExtendShutdownTimeData
// Method      :        PowerExtendShutdownTime_Q_SendPowerExtendShutdownTimeData(tPowerExtendShutdownTime_Q_Ref const This, SPowerExtendShutdownTime const PowerExtendShutdownTimeData)
// Visibility  :        public
// Description :        Send operation for PowerExtendShutdownTimeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type               |         Name(Direction)          |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerExtendShutdownTime_Q_Ref  | This(In)                         | Class reference
// SPowerExtendShutdownTime        | PowerExtendShutdownTimeData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerExtendShutdownTime_Q_SendPowerExtendShutdownTimeData(Ref, PowerExtendShutdownTimeData) \
    (SysReturnType)(Ref)->SendPowerExtendShutdownTimeData(PowerExtendShutdownTimeData)

#endif // #if (defined(PowerExtendShutdownTime_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerExtendShutdownTime_Q/<AutoCreatedOperation>ReceivePowerExtendShutdownTimeData
// Method      :        PowerExtendShutdownTime_Q_ReceivePowerExtendShutdownTimeData(tPowerExtendShutdownTime_Q_Ref const This, SPowerExtendShutdownTime * const pdata)
// Visibility  :        public
// Description :        Receive operation for PowerExtendShutdownTimeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type               | Name(Direction) |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerExtendShutdownTime_Q_Ref  | This(In)        | Class reference
// SPowerExtendShutdownTime        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerExtendShutdownTime_Q_ReceivePowerExtendShutdownTimeData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceivePowerExtendShutdownTimeData(pdata)

#endif // #if (defined(PowerExtendShutdownTime_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __PowerExtendShutdownTime_Q_G_h__
