#ifndef __PowerSystemStateReqChange_G_h__
#define __PowerSystemStateReqChange_G_h__
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
// Entity:              PowerSystemStateReqChange (TransportedInterface)
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

#if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))
typedef const struct sPowerSystemStateReqChangeProvided
{
    SysReturnType (*ReadPowerSystemStateReqChangeData)(SPowerSystemStateReqChange * const); // Read operation for PowerSystemStateReqChangeData
    SysReturnType (*WritePowerSystemStateReqChangeData)(SPowerSystemStateReqChange const); // Write operation for PowerSystemStateReqChangeData
} tPowerSystemStateReqChangeProvided;
#endif // #if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerSystemStateReqChange_USAGE_VISIBILITY))
typedef const struct sPowerSystemStateReqChangeRequired
{
    SysReturnType (*ReadPowerSystemStateReqChangeData)(SPowerSystemStateReqChange * const); // Read operation for PowerSystemStateReqChangeData
} tPowerSystemStateReqChangeRequired;
#endif // #if (defined(PowerSystemStateReqChange_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))
#define mPowerSystemStateReqChangeProvided_Allocate(instanceName, itsPowerSystemStateReqChange_FCTTBL) \
    tPowerSystemStateReqChangeProvided instanceName = itsPowerSystemStateReqChange_FCTTBL;
#endif // #if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))

#if (defined(PowerSystemStateReqChange_USAGE_VISIBILITY))
#define mPowerSystemStateReqChangeRequired_Allocate(instanceName, itsPowerSystemStateReqChange_FCTTBL) \
    tPowerSystemStateReqChangeRequired instanceName = itsPowerSystemStateReqChange_FCTTBL;
#endif // #if (defined(PowerSystemStateReqChange_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerSystemStateReqChange/<AutoCreatedOperation>WritePowerSystemStateReqChangeData
// Method      :        PowerSystemStateReqChange_WritePowerSystemStateReqChangeData(tPowerSystemStateReqChange_Ref const This, SPowerSystemStateReqChange const PowerSystemStateReqChangeData)
// Visibility  :        public
// Description :        Write operation for PowerSystemStateReqChangeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type               |          Name(Direction)           |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerSystemStateReqChange_Ref  | This(In)                           | Class reference
// SPowerSystemStateReqChange      | PowerSystemStateReqChangeData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerSystemStateReqChange_WritePowerSystemStateReqChangeData(Ref, PowerSystemStateReqChangeData) \
    (SysReturnType)(Ref)->WritePowerSystemStateReqChangeData(PowerSystemStateReqChangeData)

#endif // #if (defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY)) || (defined(PowerSystemStateReqChange_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerSystemStateReqChange/<AutoCreatedOperation>ReadPowerSystemStateReqChangeData
// Method      :        PowerSystemStateReqChange_ReadPowerSystemStateReqChangeData(tPowerSystemStateReqChange_Ref const This, SPowerSystemStateReqChange * const pPowerSystemStateReqChangeData)
// Visibility  :        public
// Description :        Read operation for PowerSystemStateReqChangeData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//              Type               |           Name(Direction)            |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerSystemStateReqChange_Ref  | This(In)                             | Class reference
// SPowerSystemStateReqChange      | pPowerSystemStateReqChangeData(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerSystemStateReqChange_ReadPowerSystemStateReqChangeData(Ref, pPowerSystemStateReqChangeData) \
    (SysReturnType)(Ref)->ReadPowerSystemStateReqChangeData(pPowerSystemStateReqChangeData)

#endif // #if ((defined(PowerSystemStateReqChange_PROVIDE_VISIBILITY)) || (defined(PowerSystemStateReqChange_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __PowerSystemStateReqChange_G_h__
