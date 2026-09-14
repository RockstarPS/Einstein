#ifndef __PowerSystemState_G_h__
#define __PowerSystemState_G_h__
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
// Entity:              PowerSystemState (TransportedInterface)
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

#if (defined(PowerSystemState_PROVIDE_VISIBILITY))
typedef const struct sPowerSystemStateProvided
{
    SysReturnType (*ReadPowerSystemStateData)(SPowerSystemState * const); // Read operation for PowerSystemStateData
    SysReturnType (*WritePowerSystemStateData)(SPowerSystemState const); // Write operation for PowerSystemStateData
} tPowerSystemStateProvided;
#endif // #if (defined(PowerSystemState_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerSystemState_USAGE_VISIBILITY))
typedef const struct sPowerSystemStateRequired
{
    SysReturnType (*ReadPowerSystemStateData)(SPowerSystemState * const); // Read operation for PowerSystemStateData
} tPowerSystemStateRequired;
#endif // #if (defined(PowerSystemState_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(PowerSystemState_PROVIDE_VISIBILITY))
#define mPowerSystemStateProvided_Allocate(instanceName, itsPowerSystemState_FCTTBL) \
    tPowerSystemStateProvided instanceName = itsPowerSystemState_FCTTBL;
#endif // #if (defined(PowerSystemState_PROVIDE_VISIBILITY))

#if (defined(PowerSystemState_USAGE_VISIBILITY))
#define mPowerSystemStateRequired_Allocate(instanceName, itsPowerSystemState_FCTTBL) \
    tPowerSystemStateRequired instanceName = itsPowerSystemState_FCTTBL;
#endif // #if (defined(PowerSystemState_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(PowerSystemState_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerSystemState/<AutoCreatedOperation>WritePowerSystemStateData
// Method      :        PowerSystemState_WritePowerSystemStateData(tPowerSystemState_Ref const This, SPowerSystemState const PowerSystemStateData)
// Visibility  :        public
// Description :        Write operation for PowerSystemStateData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          |      Name(Direction)      |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerSystemState_Ref  | This(In)                  | Class reference
// SPowerSystemState      | PowerSystemStateData(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerSystemState_WritePowerSystemStateData(Ref, PowerSystemStateData) \
    (SysReturnType)(Ref)->WritePowerSystemStateData(PowerSystemStateData)

#endif // #if (defined(PowerSystemState_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(PowerSystemState_PROVIDE_VISIBILITY)) || (defined(PowerSystemState_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/CDD_PACKAGES/UclProxyCdd/PowerSystemState/<AutoCreatedOperation>ReadPowerSystemStateData
// Method      :        PowerSystemState_ReadPowerSystemStateData(tPowerSystemState_Ref const This, SPowerSystemState * const pPowerSystemStateData)
// Visibility  :        public
// Description :        Read operation for PowerSystemStateData
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//          Type          |       Name(Direction)       |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tPowerSystemState_Ref  | This(In)                    | Class reference
// SPowerSystemState      | pPowerSystemStateData(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define PowerSystemState_ReadPowerSystemStateData(Ref, pPowerSystemStateData) \
    (SysReturnType)(Ref)->ReadPowerSystemStateData(pPowerSystemStateData)

#endif // #if ((defined(PowerSystemState_PROVIDE_VISIBILITY)) || (defined(PowerSystemState_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __PowerSystemState_G_h__
