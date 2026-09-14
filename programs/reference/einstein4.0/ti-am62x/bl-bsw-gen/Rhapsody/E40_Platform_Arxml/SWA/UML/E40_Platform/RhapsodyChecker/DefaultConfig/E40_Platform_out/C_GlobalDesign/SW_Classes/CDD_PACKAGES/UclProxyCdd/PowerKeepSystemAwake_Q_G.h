#ifndef __PowerKeepSystemAwake_Q_G_h__
#define __PowerKeepSystemAwake_Q_G_h__
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
// Entity:              PowerKeepSystemAwake_Q (TransportedInterface)
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

#if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))
typedef const struct sPowerKeepSystemAwake_QProvided
{
    SysReturnType (*SendPowerKeepSystemAwakeData)(SPowerKeepSystemAwake const); // Send operation for PowerKeepSystemAwakeData
} tPowerKeepSystemAwake_QProvided;
#endif // #if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))
typedef const struct sPowerKeepSystemAwake_QRequired
{
    SysReturnType (*ReceivePowerKeepSystemAwakeData)(SPowerKeepSystemAwake * const); // Receive operation for PowerKeepSystemAwakeData
} tPowerKeepSystemAwake_QRequired;
#endif // #if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))
#define mPowerKeepSystemAwake_QProvided_Allocate(instanceName, itsPowerKeepSystemAwake_Q_FCTTBL) \
    tPowerKeepSystemAwake_QProvided instanceName = itsPowerKeepSystemAwake_Q_FCTTBL;
#endif // #if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))

#if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))
#define mPowerKeepSystemAwake_QRequired_Allocate(instanceName, itsPowerKeepSystemAwake_Q_FCTTBL) \
    tPowerKeepSystemAwake_QRequired instanceName = itsPowerKeepSystemAwake_Q_FCTTBL;
#endif // #if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerKeepSystemAwake_Q/<AutoCreatedOperation>SendPowerKeepSystemAwakeData
// Method      :        PowerKeepSystemAwake_Q_SendPowerKeepSystemAwakeData(tPowerKeepSystemAwake_Q_Ref const This, SPowerKeepSystemAwake const PowerKeepSystemAwakeData)
// Visibility  :        public
// Description :        Send operation for PowerKeepSystemAwakeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             |        Name(Direction)        |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerKeepSystemAwake_Q_Ref  | This(In)                      | Class reference
// SPowerKeepSystemAwake        | PowerKeepSystemAwakeData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerKeepSystemAwake_Q_SendPowerKeepSystemAwakeData(Ref, PowerKeepSystemAwakeData) \
    (SysReturnType)(Ref)->SendPowerKeepSystemAwakeData(PowerKeepSystemAwakeData)

#endif // #if (defined(PowerKeepSystemAwake_Q_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerKeepSystemAwake_Q/<AutoCreatedOperation>ReceivePowerKeepSystemAwakeData
// Method      :        PowerKeepSystemAwake_Q_ReceivePowerKeepSystemAwakeData(tPowerKeepSystemAwake_Q_Ref const This, SPowerKeepSystemAwake * const pdata)
// Visibility  :        public
// Description :        Receive operation for PowerKeepSystemAwakeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerKeepSystemAwake_Q_Ref  | This(In)        | Class reference
// SPowerKeepSystemAwake        | pdata(Out)      | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerKeepSystemAwake_Q_ReceivePowerKeepSystemAwakeData(Ref, pdata) \
    (SysReturnType)(Ref)->ReceivePowerKeepSystemAwakeData(pdata)

#endif // #if (defined(PowerKeepSystemAwake_Q_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __PowerKeepSystemAwake_Q_G_h__
