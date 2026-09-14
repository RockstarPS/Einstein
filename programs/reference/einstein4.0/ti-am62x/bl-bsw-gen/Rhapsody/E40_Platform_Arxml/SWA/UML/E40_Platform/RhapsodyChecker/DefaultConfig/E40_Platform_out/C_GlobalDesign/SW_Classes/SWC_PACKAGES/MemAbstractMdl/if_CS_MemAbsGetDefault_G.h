#ifndef __if_CS_MemAbsGetDefault_G_h__
#define __if_CS_MemAbsGetDefault_G_h__
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
// Generated on Tue Apr 09 20:02:56 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              if_CS_MemAbsGetDefault (TransportedInterface)
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

#if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))
typedef const struct sif_CS_MemAbsGetDefaultRequired
{
    SysReturnType (*Call_Get_Default_BsShare_SwUpdReflash_Element)(Arr_u8_8 * const); // Initiate call of Get_Default_BsShare_SwUpdReflash_Element
    SysReturnType (*Call_Get_Default_BsShare_SwUpdFotaMode_Element)(Arr_u8_16 * const); // Initiate call of Get_Default_BsShare_SwUpdFotaMode_Element
    SysReturnType (*Call_Get_Default_BsShare_SwUpdFotaFinPrint_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsShare_SwUpdFotaFinPrint_Element
    SysReturnType (*Call_Get_Default_BsShare_SwUpdFotaStatus_Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsShare_SwUpdFotaStatus_Element
    SysReturnType (*Call_Get_Default_BsShare_SwUpdFotadecrypt_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsShare_SwUpdFotadecrypt_Element
    SysReturnType (*Call_Get_Default_BsShare_EcuPartNumber_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsShare_EcuPartNumber_Element
    SysReturnType (*Call_Get_Default_BsShare_VisMeet_Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsShare_VisMeet_Element
    SysReturnType (*Call_Get_Default_BsShare_VehicleConfig_Element)(Arr_u8_256 * const); // Initiate call of Get_Default_BsShare_VehicleConfig_Element
    SysReturnType (*Call_Get_Default_BsConst_SpeedoGauge_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_SpeedoGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_TachoGauge_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_TachoGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_FuelGauge_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsConst_FuelGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_TempGauge_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_TempGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_PowerGauge_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_PowerGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_OilGauge_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_OilGauge_Element
    SysReturnType (*Call_Get_Default_BsConst_TripComputer_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_TripComputer_Element
    SysReturnType (*Call_Get_Default_BsConst_Illumination_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsConst_Illumination_Element
    SysReturnType (*Call_Get_Default_BsConst_Audio_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsConst_Audio_Element
    SysReturnType (*Call_Get_Default_BsConst_Warning_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_Warning_Element
    SysReturnType (*Call_Get_Default_BsConst_RealTimeClock_Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsConst_RealTimeClock_Element
    SysReturnType (*Call_Get_Default_BsConst_Communication_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsConst_Communication_Element
    SysReturnType (*Call_Get_Default_BsConst_Power_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsConst_Power_Element
    SysReturnType (*Call_Get_Default_BsConst_ServiceReminder_Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsConst_ServiceReminder_Element
    SysReturnType (*Call_Get_Default_BsConst_EngOffTimer_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsConst_EngOffTimer_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Warning_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsFuSa_Warning_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Power_Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsFuSa_Power_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Display_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsFuSa_Display_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Audio_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsFuSa_Audio_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Communication_Element)(Arr_u8_16 * const); // Initiate call of Get_Default_BsFuSa_Communication_Element
    SysReturnType (*Call_Get_Default_BsFusa_Fota_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsFusa_Fota_Element
    SysReturnType (*Call_Get_Default_BsFuSa_Config_Element)(Arr_u8_16 * const); // Initiate call of Get_Default_BsFuSa_Config_Element
    SysReturnType (*Call_Get_Default_BsCys_Certicificate_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsCys_Certicificate_Element
    SysReturnType (*Call_Get_Default_RefCys_Certicificate_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_RefCys_Certicificate_Element
    SysReturnType (*Call_Get_Default_RefCys_Certicificate1_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_RefCys_Certicificate1_Element
    SysReturnType (*Call_Get_Default_BsRt_Odometer_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsRt_Odometer_Element
    SysReturnType (*Call_Get_Default_BsRt_SpeedoGauge_Element)(Arr_u8_8 * const); // Initiate call of Get_Default_BsRt_SpeedoGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_TachoGauge_Element)(Arr_u8_16 * const); // Initiate call of Get_Default_BsRt_TachoGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_FuelGauge_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsRt_FuelGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_TempGauge_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsRt_TempGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_PowerGauge_Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsRt_PowerGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_OilGauge_Element)(Arr_u8_8 * const); // Initiate call of Get_Default_BsRt_OilGauge_Element
    SysReturnType (*Call_Get_Default_BsRt_TripComputer_Element)(Arr_u8_64 * const); // Initiate call of Get_Default_BsRt_TripComputer_Element
    SysReturnType (*Call_Get_Default_BsRt_Warning _Element)(Arr_u8_32 * const); // Initiate call of Get_Default_BsRt_Warning _Element
    SysReturnType (*Call_Get_Default_BsRt_RealTimeClock _Element)(Arr_u8_48 * const); // Initiate call of Get_Default_BsRt_RealTimeClock _Element
    SysReturnType (*Call_Get_Default_BsRt_Personalization _Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsRt_Personalization _Element
    SysReturnType (*Call_Get_Default_BsRt_Illumination_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsRt_Illumination_Element
    SysReturnType (*Call_Get_Default_BsRt_CusDlt_Element)(Arr_u8_128 * const); // Initiate call of Get_Default_BsRt_CusDlt_Element
    SysReturnType (*Call_Get_Default_BsReten_Odometer_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Odometer_Element
    SysReturnType (*Call_Get_Default_BsReten_Gauges_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Gauges_Element
    SysReturnType (*Call_Get_Default_BsReten_Tripcomputer_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Tripcomputer_Element
    SysReturnType (*Call_Get_Default_BsReten_Illumination_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Illumination_Element
    SysReturnType (*Call_Get_Default_BsReten_Audio_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Audio_Element
    SysReturnType (*Call_Get_Default_BsReten_Warning_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Warning_Element
    SysReturnType (*Call_Get_Default_BsReten_RealTimeClock_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_RealTimeClock_Element
    SysReturnType (*Call_Get_Default_BsReten_Communication_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Communication_Element
    SysReturnType (*Call_Get_Default_BsReten_Personalization_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Personalization_Element
    SysReturnType (*Call_Get_Default_BsReten_VisDlt_Element)(Arr_u8_256 * const); // Initiate call of Get_Default_BsReten_VisDlt_Element
    SysReturnType (*Call_Get_Default_BsReten_Power_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Power_Element
    SysReturnType (*Call_Get_Default_BsReten_Display_Element)(Arr_u8_100 * const); // Initiate call of Get_Default_BsReten_Display_Element
    SysReturnType (*Call_Get_Default_BsDiag_ErrorRecord_Element)(Arr_u8_1024 * const); // Initiate call of Get_Default_BsDiag_ErrorRecord_Element
    SysReturnType (*Call_Get_Default_BsDiag_Dtc_Element)(Arr_u8_2048 * const); // Initiate call of Get_Default_BsDiag_Dtc_Element
} tif_CS_MemAbsGetDefaultRequired;
#endif // #if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))
#define mif_CS_MemAbsGetDefaultRequired_Allocate(instanceName, itsif_CS_MemAbsGetDefault_FCTTBL) \
    tif_CS_MemAbsGetDefaultRequired instanceName = itsif_CS_MemAbsGetDefault_FCTTBL;
#endif // #if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_SwUpdReflash_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdReflash_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_8 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_SwUpdReflash_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_8                     | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdReflash_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_SwUpdReflash_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_SwUpdFotaMode_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaMode_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_16 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_SwUpdFotaMode_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_16                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaMode_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_SwUpdFotaMode_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_SwUpdFotaFinPrint_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaFinPrint_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_SwUpdFotaFinPrint_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaFinPrint_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_SwUpdFotaFinPrint_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_SwUpdFotaStatus_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaStatus_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_SwUpdFotaStatus_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotaStatus_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_SwUpdFotaStatus_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_SwUpdFotadecrypt_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotadecrypt_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_SwUpdFotadecrypt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_SwUpdFotadecrypt_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_SwUpdFotadecrypt_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_EcuPartNumber_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_EcuPartNumber_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_EcuPartNumber_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_EcuPartNumber_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_EcuPartNumber_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_VisMeet_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_VisMeet_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_VisMeet_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_VisMeet_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_VisMeet_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsShare_VehicleConfig_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsShare_VehicleConfig_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_256 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsShare_VehicleConfig_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_256                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsShare_VehicleConfig_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsShare_VehicleConfig_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_SpeedoGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_SpeedoGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_SpeedoGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_SpeedoGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_TachoGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TachoGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TachoGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_TachoGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_FuelGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_FuelGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_FuelGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_FuelGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_TempGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TempGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TempGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_TempGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_PowerGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_PowerGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_PowerGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_PowerGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_OilGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_OilGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_OilGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_OilGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_TripComputer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TripComputer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_TripComputer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_TripComputer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_Illumination_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Illumination_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Illumination_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_Illumination_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_Audio_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Audio_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Audio_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_Audio_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_Warning_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Warning_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Warning_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_Warning_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_RealTimeClock_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_RealTimeClock_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_RealTimeClock_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_RealTimeClock_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_Communication_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Communication_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Communication_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_Communication_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_Power_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Power_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_Power_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_Power_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_ServiceReminder_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_ServiceReminder_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_ServiceReminder_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_ServiceReminder_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_ServiceReminder_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsConst_EngOffTimer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsConst_EngOffTimer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsConst_EngOffTimer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsConst_EngOffTimer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsConst_EngOffTimer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Warning_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Warning_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Warning_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Warning_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Power_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Power_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Power_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Power_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Display_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Display_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Display_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Display_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Audio_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Audio_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Audio_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Audio_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Communication_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Communication_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_16 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_16                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Communication_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Communication_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFusa_Fota_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFusa_Fota_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFusa_Fota_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFusa_Fota_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFusa_Fota_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsFuSa_Config_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Config_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_16 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsFuSa_Config_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_16                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsFuSa_Config_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsFuSa_Config_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsCys_Certicificate_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsCys_Certicificate_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsCys_Certicificate_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsCys_Certicificate_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_RefCys_Certicificate_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_RefCys_Certicificate_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_RefCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_RefCys_Certicificate_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_RefCys_Certicificate_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_RefCys_Certicificate1_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_RefCys_Certicificate1_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_RefCys_Certicificate1_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_RefCys_Certicificate1_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_RefCys_Certicificate1_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_Odometer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Odometer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Odometer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_Odometer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_SpeedoGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_SpeedoGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_8 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_8                     | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_SpeedoGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_SpeedoGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_TachoGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TachoGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_16 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_16                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TachoGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_TachoGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_FuelGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_FuelGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_FuelGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_FuelGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_TempGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TempGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TempGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_TempGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_PowerGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_PowerGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_PowerGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_PowerGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_OilGauge_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_OilGauge_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_8 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_8                     | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_OilGauge_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_OilGauge_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_TripComputer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TripComputer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_64 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_64                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_TripComputer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_TripComputer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_Warning _Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Warning _Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_32 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_Warning _Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_32                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Warning _Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_Warning _Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_RealTimeClock _Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_RealTimeClock _Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_48 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_RealTimeClock _Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_48                    | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_RealTimeClock _Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_RealTimeClock _Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_Personalization _Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Personalization _Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_Personalization _Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Personalization _Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_Personalization _Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_Illumination_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Illumination_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_Illumination_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_Illumination_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsRt_CusDlt_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsRt_CusDlt_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_128 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsRt_CusDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_128                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsRt_CusDlt_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsRt_CusDlt_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Odometer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Odometer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Odometer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Odometer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Gauges_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Gauges_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Gauges_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Gauges_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Gauges_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Tripcomputer_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Tripcomputer_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Tripcomputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Tripcomputer_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Tripcomputer_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Illumination_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Illumination_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Illumination_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Illumination_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Audio_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Audio_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Audio_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Audio_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Warning_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Warning_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Warning_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Warning_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_RealTimeClock_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_RealTimeClock_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_RealTimeClock_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_RealTimeClock_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Communication_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Communication_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Communication_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Communication_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Personalization_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Personalization_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Personalization_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Personalization_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_VisDlt_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_VisDlt_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_256 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_VisDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_256                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_VisDlt_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_VisDlt_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Power_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Power_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Power_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Power_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsReten_Display_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Display_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_100 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsReten_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_100                   | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsReten_Display_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsReten_Display_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsDiag_ErrorRecord_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsDiag_ErrorRecord_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_1024 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsDiag_ErrorRecord_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_1024                  | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsDiag_ErrorRecord_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsDiag_ErrorRecord_Element(pPtr)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_CS_MemAbsGetDefault/<AutoCreatedOperation>Call_Get_Default_BsDiag_Dtc_Element
// Method      :        if_CS_MemAbsGetDefault_CallGet_Default_BsDiag_Dtc_Element(tif_CS_MemAbsGetDefault_Ref const This, Arr_u8_2048 * const pPtr)
// Visibility  :        public
// Description :        Initiate call of Get_Default_BsDiag_Dtc_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//             Type             | Name(Direction) |                              Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_CS_MemAbsGetDefault_Ref  | This(In)        | Class reference
// Arr_u8_2048                  | pPtr(Out)       | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_CS_MemAbsGetDefault_CallGet_Default_BsDiag_Dtc_Element(Ref, pPtr) \
    (SysReturnType)(Ref)->Call_Get_Default_BsDiag_Dtc_Element(pPtr)

#endif // #if (defined(if_CS_MemAbsGetDefault_USAGE_VISIBILITY))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_CS_MemAbsGetDefault_G_h__
