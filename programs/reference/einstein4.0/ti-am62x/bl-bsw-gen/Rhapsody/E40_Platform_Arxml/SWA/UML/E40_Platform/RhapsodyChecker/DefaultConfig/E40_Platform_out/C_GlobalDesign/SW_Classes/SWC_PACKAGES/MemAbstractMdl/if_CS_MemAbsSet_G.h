#ifndef __if_CS_MemAbsSet_G_h__
#define __if_CS_MemAbsSet_G_h__
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
// Generated on Fri Jul 26 12:05:16 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_MemAbsSet (TransportedInterface)
// Description:         None
// Owner:               MemAbstractMdl (Package)
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
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbsSetRequired
{
    SysReturnType (*Call_Set_BsShare_SwUpdReflash_Element)(Arr_u8_8 * const); // Initiate call of Set_BsShare_SwUpdReflash_Element
    SysReturnType (*Call_Set_BsShare_SwUpdFotaMode_Element)(Arr_u8_16 * const); // Initiate call of Set_BsShare_SwUpdFotaMode_Element
    SysReturnType (*Call_Set_BsShare_SwUpdFotaFinPrint_Element)(Arr_u8_32 * const); // Initiate call of Set_BsShare_SwUpdFotaFinPrint_Element
    SysReturnType (*Call_Set_BsShare_SwUpdFotaStatus_Element)(Arr_u8_48 * const); // Initiate call of Set_BsShare_SwUpdFotaStatus_Element
    SysReturnType (*Call_Set_BsShare_SwUpdFotadecrypt_Element)(Arr_u8_64 * const); // Initiate call of Set_BsShare_SwUpdFotadecrypt_Element
    SysReturnType (*Call_Set_BsShare_EcuPartNumber_Element)(Arr_u8_128 * const); // Initiate call of Set_BsShare_EcuPartNumber_Element
    SysReturnType (*Call_Set_BsShare_VisMeet_Element)(Arr_u8_48 * const); // Initiate call of Set_BsShare_VisMeet_Element
    SysReturnType (*Call_Set_BsShare_VehicleConfig_Element)(Arr_u8_256 * const); // Initiate call of Set_BsShare_VehicleConfig_Element
    SysReturnType (*Call_Set_BsConst_SpeedoGauge_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_SpeedoGauge_Element
    SysReturnType (*Call_Set_BsConst_TachoGauge_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_TachoGauge_Element
    SysReturnType (*Call_Set_BsConst_FuelGauge_Element)(Arr_u8_128 * const); // Initiate call of Set_BsConst_FuelGauge_Element
    SysReturnType (*Call_Set_BsConst_TempGauge_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_TempGauge_Element
    SysReturnType (*Call_Set_BsConst_PowerGauge_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_PowerGauge_Element
    SysReturnType (*Call_Set_BsConst_OilGauge_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_OilGauge_Element
    SysReturnType (*Call_Set_BsConst_TripComputer_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_TripComputer_Element
    SysReturnType (*Call_Set_BsConst_Illumination_Element)(Arr_u8_128 * const); // Initiate call of Set_BsConst_Illumination_Element
    SysReturnType (*Call_Set_BsConst_Audio_Element)(Arr_u8_128 * const); // Initiate call of Set_BsConst_Audio_Element
    SysReturnType (*Call_Set_BsConst_Warning_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_Warning_Element
    SysReturnType (*Call_Set_BsConst_RealTimeClock_Element)(Arr_u8_48 * const); // Initiate call of Set_BsConst_RealTimeClock_Element
    SysReturnType (*Call_Set_BsConst_Communication_Element)(Arr_u8_64 * const); // Initiate call of Set_BsConst_Communication_Element
    SysReturnType (*Call_Set_BsConst_Power_Element)(Arr_u8_32 * const); // Initiate call of Set_BsConst_Power_Element
    SysReturnType (*Call_Set_BsConst_ServiceReminder_Element)(Arr_u8_48 * const); // Initiate call of Set_BsConst_ServiceReminder_Element
    SysReturnType (*Call_Set_BsConst_EngOffTimer_Element)(Arr_u8_32 * const); // Initiate call of Set_BsConst_EngOffTimer_Element
    SysReturnType (*Call_Set_BsFuSa_Warning_Element)(Arr_u8_32 * const); // Initiate call of Set_BsFuSa_Warning_Element
    SysReturnType (*Call_Set_BsFuSa_Power_Element)(Arr_u8_48 * const); // Initiate call of Set_BsFuSa_Power_Element
    SysReturnType (*Call_Set_BsFuSa_Display_Element)(Arr_u8_64 * const); // Initiate call of Set_BsFuSa_Display_Element
    SysReturnType (*Call_Set_BsFuSa_Audio_Element)(Arr_u8_32 * const); // Initiate call of Set_BsFuSa_Audio_Element
    SysReturnType (*Call_Set_BsFuSa_Communication_Element)(Arr_u8_16 * const); // Initiate call of Set_BsFuSa_Communication_Element
    SysReturnType (*Call_Set_BsFusa_Fota_Element)(Arr_u8_32 * const); // Initiate call of Set_BsFusa_Fota_Element
    SysReturnType (*Call_Set_BsFuSa_Config_Element)(Arr_u8_16 * const); // Initiate call of Set_BsFuSa_Config_Element
    SysReturnType (*Call_Set_BsCys_Certicificate_Element)(Arr_u8_64 * const); // Initiate call of Set_BsCys_Certicificate_Element
    SysReturnType (*Call_Set_RefCys_Certicificate_Element)(Arr_u8_64 * const); // Initiate call of Set_RefCys_Certicificate_Element
    SysReturnType (*Call_Set_RefCys_Certicificate1_Element)(Arr_u8_64 * const); // Initiate call of Set_RefCys_Certicificate1_Element
    SysReturnType (*Call_Set_BsRt_Odometer_Element)(Arr_u8_128 * const); // Initiate call of Set_BsRt_Odometer_Element
    SysReturnType (*Call_Set_BsRt_SpeedoGauge_Element)(Arr_u8_8 * const); // Initiate call of Set_BsRt_SpeedoGauge_Element
    SysReturnType (*Call_Set_BsRt_TachoGauge_Element)(Arr_u8_16 * const); // Initiate call of Set_BsRt_TachoGauge_Element
    SysReturnType (*Call_Set_BsRt_FuelGauge_Element)(Arr_u8_32 * const); // Initiate call of Set_BsRt_FuelGauge_Element
    SysReturnType (*Call_Set_BsRt_TempGauge_Element)(Arr_u8_32 * const); // Initiate call of Set_BsRt_TempGauge_Element
    SysReturnType (*Call_Set_BsRt_PowerGauge_Element)(Arr_u8_32 * const); // Initiate call of Set_BsRt_PowerGauge_Element
    SysReturnType (*Call_Set_BsRt_OilGauge_Element)(Arr_u8_8 * const); // Initiate call of Set_BsRt_OilGauge_Element
    SysReturnType (*Call_Set_BsRt_TripComputer_Element)(Arr_u8_64 * const); // Initiate call of Set_BsRt_TripComputer_Element
    SysReturnType (*Call_Set_BsRt_Warning_Element)(Arr_u8_32 * const); // Initiate call of Set_BsRt_Warning_Element
    SysReturnType (*Call_Set_BsRt_RealTimeClock_Element)(Arr_u8_48 * const); // Initiate call of Set_BsRt_RealTimeClock_Element
    SysReturnType (*Call_Set_BsRt_Personalization_Element)(Arr_u8_128 * const); // Initiate call of Set_BsRt_Personalization_Element
    SysReturnType (*Call_Set_BsRt_Illumination_Element)(Arr_u8_100 * const); // Initiate call of Set_BsRt_Illumination_Element
    SysReturnType (*Call_Set_BsRt_CusDlt_Element)(Arr_u8_128 * const); // Initiate call of Set_BsRt_CusDlt_Element
    SysReturnType (*Call_Set_BsReten_Odometer_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Odometer_Element
    SysReturnType (*Call_Set_BsReten_Gauges_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Gauges_Element
    SysReturnType (*Call_Set_BsReten_Tripcomputer_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Tripcomputer_Element
    SysReturnType (*Call_Set_BsReten_Illumination_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Illumination_Element
    SysReturnType (*Call_Set_BsReten_Audio_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Audio_Element
    SysReturnType (*Call_Set_BsReten_Warning_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Warning_Element
    SysReturnType (*Call_Set_BsReten_RealTimeClock_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_RealTimeClock_Element
    SysReturnType (*Call_Set_BsReten_Communication_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Communication_Element
    SysReturnType (*Call_Set_BsReten_Personalization_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Personalization_Element
    SysReturnType (*Call_Set_BsReten_VisDlt_Element)(Arr_u8_256 * const); // Initiate call of Set_BsReten_VisDlt_Element
    SysReturnType (*Call_Set_BsReten_Power_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Power_Element
    SysReturnType (*Call_Set_BsReten_Display_Element)(Arr_u8_100 * const); // Initiate call of Set_BsReten_Display_Element
    SysReturnType (*Call_Set_BsDiag_ErrorRecord_Element)(Arr_u8_1024 * const); // Initiate call of Set_BsDiag_ErrorRecord_Element
    SysReturnType (*Call_Set_BsDiag_Dtc_Element)(Arr_u8_2048 * const); // Initiate call of Set_BsDiag_Dtc_Element
} tif_CS_MemAbsSetRequired;
#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))
#define mif_CS_MemAbsSetRequired_Allocate(instanceName, itsif_CS_MemAbsSet_FCTTBL) \
    tif_CS_MemAbsSetRequired instanceName = itsif_CS_MemAbsSet_FCTTBL;
#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_SwUpdReflash_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_SwUpdReflash_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_8 * const BsShare_SwUpdReflash_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_SwUpdReflash_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_8              | BsShare_SwUpdReflash_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_SwUpdReflash_Element(Ref, BsShare_SwUpdReflash_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_SwUpdReflash_Element(BsShare_SwUpdReflash_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_SwUpdFotaMode_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaMode_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_16 * const BsShare_SwUpdFotaMode_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_SwUpdFotaMode_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_16             | BsShare_SwUpdFotaMode_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaMode_Element(Ref, BsShare_SwUpdFotaMode_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_SwUpdFotaMode_Element(BsShare_SwUpdFotaMode_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_SwUpdFotaFinPrint_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaFinPrint_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsShare_SwUpdFotaFinPrint_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_SwUpdFotaFinPrint_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                               | Class reference
// Arr_u8_32             | BsShare_SwUpdFotaFinPrint_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaFinPrint_Element(Ref, BsShare_SwUpdFotaFinPrint_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_SwUpdFotaFinPrint_Element(BsShare_SwUpdFotaFinPrint_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_SwUpdFotaStatus_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaStatus_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsShare_SwUpdFotaStatus_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_SwUpdFotaStatus_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                             | Class reference
// Arr_u8_48             | BsShare_SwUpdFotaStatus_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotaStatus_Element(Ref, BsShare_SwUpdFotaStatus_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_SwUpdFotaStatus_Element(BsShare_SwUpdFotaStatus_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_SwUpdFotadecrypt_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotadecrypt_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsShare_SwUpdFotadecrypt_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_SwUpdFotadecrypt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                              | Class reference
// Arr_u8_64             | BsShare_SwUpdFotadecrypt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_SwUpdFotadecrypt_Element(Ref, BsShare_SwUpdFotadecrypt_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_SwUpdFotadecrypt_Element(BsShare_SwUpdFotadecrypt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_EcuPartNumber_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_EcuPartNumber_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsShare_EcuPartNumber_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_EcuPartNumber_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_128            | BsShare_EcuPartNumber_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_EcuPartNumber_Element(Ref, BsShare_EcuPartNumber_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_EcuPartNumber_Element(BsShare_EcuPartNumber_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_VisMeet_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_VisMeet_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsShare_VisMeet_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_VisMeet_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_48             | BsShare_VisMeet_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_VisMeet_Element(Ref, BsShare_VisMeet_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_VisMeet_Element(BsShare_VisMeet_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsShare_VehicleConfig_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsShare_VehicleConfig_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_256 * const BsShare_VehicleConfig_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsShare_VehicleConfig_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_256            | BsShare_VehicleConfig_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsShare_VehicleConfig_Element(Ref, BsShare_VehicleConfig_Element) \
    (SysReturnType)(Ref)->Call_Set_BsShare_VehicleConfig_Element(BsShare_VehicleConfig_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_SpeedoGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_SpeedoGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                         | Class reference
// Arr_u8_64             | BsConst_SpeedoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_SpeedoGauge_Element(Ref, BsConst_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_SpeedoGauge_Element(BsConst_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_TachoGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_TachoGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_TachoGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                        | Class reference
// Arr_u8_64             | BsConst_TachoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_TachoGauge_Element(Ref, BsConst_TachoGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_TachoGauge_Element(BsConst_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_FuelGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_FuelGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsConst_FuelGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                       | Class reference
// Arr_u8_128            | BsConst_FuelGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_FuelGauge_Element(Ref, BsConst_FuelGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_FuelGauge_Element(BsConst_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_TempGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_TempGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_TempGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                       | Class reference
// Arr_u8_64             | BsConst_TempGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_TempGauge_Element(Ref, BsConst_TempGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_TempGauge_Element(BsConst_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_PowerGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_PowerGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_PowerGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                        | Class reference
// Arr_u8_64             | BsConst_PowerGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_PowerGauge_Element(Ref, BsConst_PowerGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_PowerGauge_Element(BsConst_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_OilGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_OilGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_OilGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                      | Class reference
// Arr_u8_64             | BsConst_OilGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_OilGauge_Element(Ref, BsConst_OilGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_OilGauge_Element(BsConst_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_TripComputer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_TripComputer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_TripComputer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_64             | BsConst_TripComputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_TripComputer_Element(Ref, BsConst_TripComputer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_TripComputer_Element(BsConst_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_Illumination_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_Illumination_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsConst_Illumination_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_128            | BsConst_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_Illumination_Element(Ref, BsConst_Illumination_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_Illumination_Element(BsConst_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_Audio_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_Audio_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsConst_Audio_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_128            | BsConst_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_Audio_Element(Ref, BsConst_Audio_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_Audio_Element(BsConst_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_Warning_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_Warning_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_Warning_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_64             | BsConst_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_Warning_Element(Ref, BsConst_Warning_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_Warning_Element(BsConst_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_RealTimeClock_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_RealTimeClock_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsConst_RealTimeClock_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_48             | BsConst_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_RealTimeClock_Element(Ref, BsConst_RealTimeClock_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_RealTimeClock_Element(BsConst_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_Communication_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_Communication_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsConst_Communication_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_64             | BsConst_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_Communication_Element(Ref, BsConst_Communication_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_Communication_Element(BsConst_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_Power_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_Power_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsConst_Power_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_32             | BsConst_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_Power_Element(Ref, BsConst_Power_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_Power_Element(BsConst_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_ServiceReminder_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_ServiceReminder_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsConst_ServiceReminder_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_ServiceReminder_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                             | Class reference
// Arr_u8_48             | BsConst_ServiceReminder_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_ServiceReminder_Element(Ref, BsConst_ServiceReminder_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_ServiceReminder_Element(BsConst_ServiceReminder_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsConst_EngOffTimer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsConst_EngOffTimer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsConst_EngOffTimer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsConst_EngOffTimer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                         | Class reference
// Arr_u8_32             | BsConst_EngOffTimer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsConst_EngOffTimer_Element(Ref, BsConst_EngOffTimer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsConst_EngOffTimer_Element(BsConst_EngOffTimer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Warning_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Warning_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsFuSa_Warning_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_32             | BsFuSa_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Warning_Element(Ref, BsFuSa_Warning_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Warning_Element(BsFuSa_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Power_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Power_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsFuSa_Power_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)      |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                  | Class reference
// Arr_u8_48             | BsFuSa_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Power_Element(Ref, BsFuSa_Power_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Power_Element(BsFuSa_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Display_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Display_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsFuSa_Display_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_64             | BsFuSa_Display_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Display_Element(Ref, BsFuSa_Display_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Display_Element(BsFuSa_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Audio_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Audio_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsFuSa_Audio_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)      |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                  | Class reference
// Arr_u8_32             | BsFuSa_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Audio_Element(Ref, BsFuSa_Audio_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Audio_Element(BsFuSa_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Communication_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Communication_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_16 * const BsFuSa_Communication_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_16             | BsFuSa_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Communication_Element(Ref, BsFuSa_Communication_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Communication_Element(BsFuSa_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFusa_Fota_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFusa_Fota_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsFusa_Fota_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFusa_Fota_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |     Name(Direction)      |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                 | Class reference
// Arr_u8_32             | BsFusa_Fota_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFusa_Fota_Element(Ref, BsFusa_Fota_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFusa_Fota_Element(BsFusa_Fota_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsFuSa_Config_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsFuSa_Config_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_16 * const BsFuSa_Config_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsFuSa_Config_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_16             | BsFuSa_Config_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsFuSa_Config_Element(Ref, BsFuSa_Config_Element) \
    (SysReturnType)(Ref)->Call_Set_BsFuSa_Config_Element(BsFuSa_Config_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsCys_Certicificate_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsCys_Certicificate_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsCys_Certicificate_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                         | Class reference
// Arr_u8_64             | BsCys_Certicificate_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsCys_Certicificate_Element(Ref, BsCys_Certicificate_Element) \
    (SysReturnType)(Ref)->Call_Set_BsCys_Certicificate_Element(BsCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_RefCys_Certicificate_Element
// Method      :        if_CS_MemAbsSet_CallSet_RefCys_Certicificate_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const RefCys_Certicificate_Element)
// Visibility  :        public
// Description :        Initiate call of Set_RefCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_64             | RefCys_Certicificate_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_RefCys_Certicificate_Element(Ref, RefCys_Certicificate_Element) \
    (SysReturnType)(Ref)->Call_Set_RefCys_Certicificate_Element(RefCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_RefCys_Certicificate1_Element
// Method      :        if_CS_MemAbsSet_CallSet_RefCys_Certicificate1_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const RefCys_Certicificate1_Element)
// Visibility  :        public
// Description :        Initiate call of Set_RefCys_Certicificate1_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_64             | RefCys_Certicificate1_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_RefCys_Certicificate1_Element(Ref, RefCys_Certicificate1_Element) \
    (SysReturnType)(Ref)->Call_Set_RefCys_Certicificate1_Element(RefCys_Certicificate1_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_Odometer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_Odometer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsRt_Odometer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_128            | BsRt_Odometer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_Odometer_Element(Ref, BsRt_Odometer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_Odometer_Element(BsRt_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_SpeedoGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_SpeedoGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_8 * const BsRt_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                      | Class reference
// Arr_u8_8              | BsRt_SpeedoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_SpeedoGauge_Element(Ref, BsRt_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_SpeedoGauge_Element(BsRt_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_TachoGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_TachoGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_16 * const BsRt_TachoGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_16             | BsRt_TachoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_TachoGauge_Element(Ref, BsRt_TachoGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_TachoGauge_Element(BsRt_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_FuelGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_FuelGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsRt_FuelGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_32             | BsRt_FuelGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_FuelGauge_Element(Ref, BsRt_FuelGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_FuelGauge_Element(BsRt_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_TempGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_TempGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsRt_TempGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_32             | BsRt_TempGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_TempGauge_Element(Ref, BsRt_TempGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_TempGauge_Element(BsRt_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_PowerGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_PowerGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsRt_PowerGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_32             | BsRt_PowerGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_PowerGauge_Element(Ref, BsRt_PowerGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_PowerGauge_Element(BsRt_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_OilGauge_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_OilGauge_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_8 * const BsRt_OilGauge_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_8              | BsRt_OilGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_OilGauge_Element(Ref, BsRt_OilGauge_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_OilGauge_Element(BsRt_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_TripComputer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_TripComputer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_64 * const BsRt_TripComputer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                       | Class reference
// Arr_u8_64             | BsRt_TripComputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_TripComputer_Element(Ref, BsRt_TripComputer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_TripComputer_Element(BsRt_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_Warning_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_Warning_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_32 * const BsRt_Warning_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)      |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                  | Class reference
// Arr_u8_32             | BsRt_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_Warning_Element(Ref, BsRt_Warning_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_Warning_Element(BsRt_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_RealTimeClock_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_RealTimeClock_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_48 * const BsRt_RealTimeClock_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                        | Class reference
// Arr_u8_48             | BsRt_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_RealTimeClock_Element(Ref, BsRt_RealTimeClock_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_RealTimeClock_Element(BsRt_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_Personalization_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_Personalization_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsRt_Personalization_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_128            | BsRt_Personalization_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_Personalization_Element(Ref, BsRt_Personalization_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_Personalization_Element(BsRt_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_Illumination_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_Illumination_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsRt_Illumination_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                       | Class reference
// Arr_u8_100            | BsRt_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_Illumination_Element(Ref, BsRt_Illumination_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_Illumination_Element(BsRt_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsRt_CusDlt_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsRt_CusDlt_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_128 * const BsRt_CusDlt_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsRt_CusDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |     Name(Direction)      |                             Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                 | Class reference
// Arr_u8_128            | BsRt_CusDlt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsRt_CusDlt_Element(Ref, BsRt_CusDlt_Element) \
    (SysReturnType)(Ref)->Call_Set_BsRt_CusDlt_Element(BsRt_CusDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Odometer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Odometer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Odometer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |        Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                      | Class reference
// Arr_u8_100            | BsReten_Odometer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Odometer_Element(Ref, BsReten_Odometer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Odometer_Element(BsReten_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Gauges_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Gauges_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Gauges_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Gauges_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_100            | BsReten_Gauges_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Gauges_Element(Ref, BsReten_Gauges_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Gauges_Element(BsReten_Gauges_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Tripcomputer_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Tripcomputer_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Tripcomputer_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Tripcomputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_100            | BsReten_Tripcomputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Tripcomputer_Element(Ref, BsReten_Tripcomputer_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Tripcomputer_Element(BsReten_Tripcomputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Illumination_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Illumination_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Illumination_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                          | Class reference
// Arr_u8_100            | BsReten_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Illumination_Element(Ref, BsReten_Illumination_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Illumination_Element(BsReten_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Audio_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Audio_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Audio_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_100            | BsReten_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Audio_Element(Ref, BsReten_Audio_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Audio_Element(BsReten_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Warning_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Warning_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Warning_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_100            | BsReten_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Warning_Element(Ref, BsReten_Warning_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Warning_Element(BsReten_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_RealTimeClock_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_RealTimeClock_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_RealTimeClock_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_100            | BsReten_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_RealTimeClock_Element(Ref, BsReten_RealTimeClock_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_RealTimeClock_Element(BsReten_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Communication_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Communication_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Communication_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                           | Class reference
// Arr_u8_100            | BsReten_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Communication_Element(Ref, BsReten_Communication_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Communication_Element(BsReten_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Personalization_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Personalization_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Personalization_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                             | Class reference
// Arr_u8_100            | BsReten_Personalization_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Personalization_Element(Ref, BsReten_Personalization_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Personalization_Element(BsReten_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_VisDlt_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_VisDlt_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_256 * const BsReten_VisDlt_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_VisDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                    | Class reference
// Arr_u8_256            | BsReten_VisDlt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_VisDlt_Element(Ref, BsReten_VisDlt_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_VisDlt_Element(BsReten_VisDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Power_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Power_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Power_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |      Name(Direction)       |                            Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                   | Class reference
// Arr_u8_100            | BsReten_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Power_Element(Ref, BsReten_Power_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Power_Element(BsReten_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsReten_Display_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsReten_Display_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_100 * const BsReten_Display_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsReten_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |       Name(Direction)        |                           Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                     | Class reference
// Arr_u8_100            | BsReten_Display_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsReten_Display_Element(Ref, BsReten_Display_Element) \
    (SysReturnType)(Ref)->Call_Set_BsReten_Display_Element(BsReten_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsDiag_ErrorRecord_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsDiag_ErrorRecord_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_1024 * const BsDiag_ErrorRecord_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsDiag_ErrorRecord_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |         Name(Direction)         |                          Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                        | Class reference
// Arr_u8_1024           | BsDiag_ErrorRecord_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsDiag_ErrorRecord_Element(Ref, BsDiag_ErrorRecord_Element) \
    (SysReturnType)(Ref)->Call_Set_BsDiag_ErrorRecord_Element(BsDiag_ErrorRecord_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsSet/<AutoCreatedOperation>Call_Set_BsDiag_Dtc_Element
// Method      :        if_CS_MemAbsSet_CallSet_BsDiag_Dtc_Element(tif_CS_MemAbsSet_Ref const This, Arr_u8_2048 * const BsDiag_Dtc_Element)
// Visibility  :        public
// Description :        Initiate call of Set_BsDiag_Dtc_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |     Name(Direction)     |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsSet_Ref  | This(In)                | Class reference
// Arr_u8_2048           | BsDiag_Dtc_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsSet_CallSet_BsDiag_Dtc_Element(Ref, BsDiag_Dtc_Element) \
    (SysReturnType)(Ref)->Call_Set_BsDiag_Dtc_Element(BsDiag_Dtc_Element)

#endif // #if (defined(if_CS_MemAbsSet_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbsSet_G_h__
