#ifndef __if_SR_JobStatus_G_h__
#define __if_SR_JobStatus_G_h__
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
// Entity:              if_SR_JobStatus (TransportedInterface)
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
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))
typedef const struct sif_SR_JobStatusProvided
{
    SysReturnType (*ReadJobStatus_BsShare_SwUpdReflash_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdReflash_Element
    SysReturnType (*WriteJobStatus_BsShare_SwUpdReflash_Element)(uint8 const); // Write operation for JobStatus_BsShare_SwUpdReflash_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaMode_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaMode_Element
    SysReturnType (*WriteJobStatus_BsShare_SwUpdFotaMode_Element)(uint8 const); // Write operation for JobStatus_BsShare_SwUpdFotaMode_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaFinPrint_Element
    SysReturnType (*WriteJobStatus_BsShare_SwUpdFotaFinPrint_Element)(uint8 const); // Write operation for JobStatus_BsShare_SwUpdFotaFinPrint_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaStatus_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaStatus_Element
    SysReturnType (*WriteJobStatus_BsShare_SwUpdFotaStatus_Element)(uint8 const); // Write operation for JobStatus_BsShare_SwUpdFotaStatus_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotadecrypt_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotadecrypt_Element
    SysReturnType (*WriteJobStatus_BsShare_SwUpdFotadecrypt_Element)(uint8 const); // Write operation for JobStatus_BsShare_SwUpdFotadecrypt_Element
    SysReturnType (*ReadJobStatus_BsShare_EcuPartNumber_Element)(uint8 * const); // Read operation for JobStatus_BsShare_EcuPartNumber_Element
    SysReturnType (*WriteJobStatus_BsShare_EcuPartNumber_Element)(uint8 const); // Write operation for JobStatus_BsShare_EcuPartNumber_Element
    SysReturnType (*ReadJobStatus_BsShare_VisMeet_Element)(uint8 * const); // Read operation for JobStatus_BsShare_VisMeet_Element
    SysReturnType (*WriteJobStatus_BsShare_VisMeet_Element)(uint8 const); // Write operation for JobStatus_BsShare_VisMeet_Element
    SysReturnType (*ReadJobStatus_BsShare_VehicleConfig_Element)(uint8 * const); // Read operation for JobStatus_BsShare_VehicleConfig_Element
    SysReturnType (*WriteJobStatus_BsShare_VehicleConfig_Element)(uint8 const); // Write operation for JobStatus_BsShare_VehicleConfig_Element
    SysReturnType (*ReadJobStatus_BsConst_SpeedoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_SpeedoGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_SpeedoGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_SpeedoGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TachoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TachoGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_TachoGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_TachoGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_FuelGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_FuelGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_FuelGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_FuelGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TempGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TempGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_TempGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_TempGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_PowerGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_PowerGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_PowerGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_PowerGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_OilGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_OilGauge_Element
    SysReturnType (*WriteJobStatus_BsConst_OilGauge_Element)(uint8 const); // Write operation for JobStatus_BsConst_OilGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TripComputer_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TripComputer_Element
    SysReturnType (*WriteJobStatus_BsConst_TripComputer_Element)(uint8 const); // Write operation for JobStatus_BsConst_TripComputer_Element
    SysReturnType (*ReadJobStatus_BsConst_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Illumination_Element
    SysReturnType (*WriteJobStatus_BsConst_Illumination_Element)(uint8 const); // Write operation for JobStatus_BsConst_Illumination_Element
    SysReturnType (*ReadJobStatus_BsConst_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Audio_Element
    SysReturnType (*WriteJobStatus_BsConst_Audio_Element)(uint8 const); // Write operation for JobStatus_BsConst_Audio_Element
    SysReturnType (*ReadJobStatus_BsConst_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Warning_Element
    SysReturnType (*WriteJobStatus_BsConst_Warning_Element)(uint8 const); // Write operation for JobStatus_BsConst_Warning_Element
    SysReturnType (*ReadJobStatus_BsConst_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsConst_RealTimeClock_Element
    SysReturnType (*WriteJobStatus_BsConst_RealTimeClock_Element)(uint8 const); // Write operation for JobStatus_BsConst_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsConst_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Communication_Element
    SysReturnType (*WriteJobStatus_BsConst_Communication_Element)(uint8 const); // Write operation for JobStatus_BsConst_Communication_Element
    SysReturnType (*ReadJobStatus_BsConst_Power_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Power_Element
    SysReturnType (*WriteJobStatus_BsConst_Power_Element)(uint8 const); // Write operation for JobStatus_BsConst_Power_Element
    SysReturnType (*ReadJobStatus_BsConst_ServiceReminder_Element)(uint8 * const); // Read operation for JobStatus_BsConst_ServiceReminder_Element
    SysReturnType (*WriteJobStatus_BsConst_ServiceReminder_Element)(uint8 const); // Write operation for JobStatus_BsConst_ServiceReminder_Element
    SysReturnType (*ReadJobStatus_BsConst_EngOffTimer_Element)(uint8 * const); // Read operation for JobStatus_BsConst_EngOffTimer_Element
    SysReturnType (*WriteJobStatus_BsConst_EngOffTimer_Element)(uint8 const); // Write operation for JobStatus_BsConst_EngOffTimer_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Warning_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Warning_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Warning_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Power_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Power_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Power_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Power_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Display_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Display_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Display_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Display_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Audio_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Audio_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Audio_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Communication_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Communication_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Communication_Element
    SysReturnType (*ReadJobStatus_BsFusa_Fota_Element)(uint8 * const); // Read operation for JobStatus_BsFusa_Fota_Element
    SysReturnType (*WriteJobStatus_BsFusa_Fota_Element)(uint8 const); // Write operation for JobStatus_BsFusa_Fota_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Config_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Config_Element
    SysReturnType (*WriteJobStatus_BsFuSa_Config_Element)(uint8 const); // Write operation for JobStatus_BsFuSa_Config_Element
    SysReturnType (*ReadJobStatus_BsCys_Certicificate_Element)(uint8 * const); // Read operation for JobStatus_BsCys_Certicificate_Element
    SysReturnType (*WriteJobStatus_BsCys_Certicificate_Element)(uint8 const); // Write operation for JobStatus_BsCys_Certicificate_Element
    SysReturnType (*ReadJobStatus_RefCys_Certicificate_Element)(uint8 * const); // Read operation for JobStatus_RefCys_Certicificate_Element
    SysReturnType (*WriteJobStatus_RefCys_Certicificate_Element)(uint8 const); // Write operation for JobStatus_RefCys_Certicificate_Element
    SysReturnType (*ReadJobStatus_RefCys_Certicificate1_Element)(uint8 * const); // Read operation for JobStatus_RefCys_Certicificate1_Element
    SysReturnType (*WriteJobStatus_RefCys_Certicificate1_Element)(uint8 const); // Write operation for JobStatus_RefCys_Certicificate1_Element
    SysReturnType (*ReadJobStatus_BsRt_Odometer_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Odometer_Element
    SysReturnType (*WriteJobStatus_BsRt_Odometer_Element)(uint8 const); // Write operation for JobStatus_BsRt_Odometer_Element
    SysReturnType (*ReadJobStatus_BsRt_SpeedoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_SpeedoGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_SpeedoGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_SpeedoGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TachoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TachoGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_TachoGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_TachoGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_FuelGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_FuelGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_FuelGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_FuelGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TempGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TempGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_TempGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_TempGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_PowerGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_PowerGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_PowerGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_PowerGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_OilGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_OilGauge_Element
    SysReturnType (*WriteJobStatus_BsRt_OilGauge_Element)(uint8 const); // Write operation for JobStatus_BsRt_OilGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TripComputer_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TripComputer_Element
    SysReturnType (*WriteJobStatus_BsRt_TripComputer_Element)(uint8 const); // Write operation for JobStatus_BsRt_TripComputer_Element
    SysReturnType (*ReadJobStatus_BsRt_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Warning_Element
    SysReturnType (*WriteJobStatus_BsRt_Warning_Element)(uint8 const); // Write operation for JobStatus_BsRt_Warning_Element
    SysReturnType (*ReadJobStatus_BsRt_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsRt_RealTimeClock_Element
    SysReturnType (*WriteJobStatus_BsRt_RealTimeClock_Element)(uint8 const); // Write operation for JobStatus_BsRt_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsRt_Personalization_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Personalization_Element
    SysReturnType (*WriteJobStatus_BsRt_Personalization_Element)(uint8 const); // Write operation for JobStatus_BsRt_Personalization_Element
    SysReturnType (*ReadJobStatus_BsRt_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Illumination_Element
    SysReturnType (*WriteJobStatus_BsRt_Illumination_Element)(uint8 const); // Write operation for JobStatus_BsRt_Illumination_Element
    SysReturnType (*ReadJobStatus_BsRt_CusDlt_Element)(uint8 * const); // Read operation for JobStatus_BsRt_CusDlt_Element
    SysReturnType (*WriteJobStatus_BsRt_CusDlt_Element)(uint8 const); // Write operation for JobStatus_BsRt_CusDlt_Element
    SysReturnType (*ReadJobStatus_BsReten_Odometer_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Odometer_Element
    SysReturnType (*WriteJobStatus_BsReten_Odometer_Element)(uint8 const); // Write operation for JobStatus_BsReten_Odometer_Element
    SysReturnType (*ReadJobStatus_BsReten_Gauges_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Gauges_Element
    SysReturnType (*WriteJobStatus_BsReten_Gauges_Element)(uint8 const); // Write operation for JobStatus_BsReten_Gauges_Element
    SysReturnType (*ReadJobStatus_BsReten_Tripcomputer_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Tripcomputer_Element
    SysReturnType (*WriteJobStatus_BsReten_Tripcomputer_Element)(uint8 const); // Write operation for JobStatus_BsReten_Tripcomputer_Element
    SysReturnType (*ReadJobStatus_BsReten_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Illumination_Element
    SysReturnType (*WriteJobStatus_BsReten_Illumination_Element)(uint8 const); // Write operation for JobStatus_BsReten_Illumination_Element
    SysReturnType (*ReadJobStatus_BsReten_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Audio_Element
    SysReturnType (*WriteJobStatus_BsReten_Audio_Element)(uint8 const); // Write operation for JobStatus_BsReten_Audio_Element
    SysReturnType (*ReadJobStatus_BsReten_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Warning_Element
    SysReturnType (*WriteJobStatus_BsReten_Warning_Element)(uint8 const); // Write operation for JobStatus_BsReten_Warning_Element
    SysReturnType (*ReadJobStatus_BsReten_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsReten_RealTimeClock_Element
    SysReturnType (*WriteJobStatus_BsReten_RealTimeClock_Element)(uint8 const); // Write operation for JobStatus_BsReten_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsReten_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Communication_Element
    SysReturnType (*WriteJobStatus_BsReten_Communication_Element)(uint8 const); // Write operation for JobStatus_BsReten_Communication_Element
    SysReturnType (*ReadJobStatus_BsReten_Personalization_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Personalization_Element
    SysReturnType (*WriteJobStatus_BsReten_Personalization_Element)(uint8 const); // Write operation for JobStatus_BsReten_Personalization_Element
    SysReturnType (*ReadJobStatus_BsReten_VisDlt_Element)(uint8 * const); // Read operation for JobStatus_BsReten_VisDlt_Element
    SysReturnType (*WriteJobStatus_BsReten_VisDlt_Element)(uint8 const); // Write operation for JobStatus_BsReten_VisDlt_Element
    SysReturnType (*ReadJobStatus_BsReten_Power_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Power_Element
    SysReturnType (*WriteJobStatus_BsReten_Power_Element)(uint8 const); // Write operation for JobStatus_BsReten_Power_Element
    SysReturnType (*ReadJobStatus_BsReten_Display_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Display_Element
    SysReturnType (*WriteJobStatus_BsReten_Display_Element)(uint8 const); // Write operation for JobStatus_BsReten_Display_Element
    SysReturnType (*ReadJobStatus_BsDiag_ErrorRecord_Element)(uint8 * const); // Read operation for JobStatus_BsDiag_ErrorRecord_Element
    SysReturnType (*WriteJobStatus_BsDiag_ErrorRecord_Element)(uint8 const); // Write operation for JobStatus_BsDiag_ErrorRecord_Element
    SysReturnType (*ReadJobStatus_BsDiag_Dtc_Element)(uint8 * const); // Read operation for JobStatus_BsDiag_Dtc_Element
    SysReturnType (*WriteJobStatus_BsDiag_Dtc_Element)(uint8 const); // Write operation for JobStatus_BsDiag_Dtc_Element
} tif_SR_JobStatusProvided;
#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                                 Part for the TI user
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_USAGE_VISIBILITY))
typedef const struct sif_SR_JobStatusRequired
{
    SysReturnType (*ReadJobStatus_BsShare_SwUpdReflash_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdReflash_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaMode_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaMode_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaFinPrint_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotaStatus_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotaStatus_Element
    SysReturnType (*ReadJobStatus_BsShare_SwUpdFotadecrypt_Element)(uint8 * const); // Read operation for JobStatus_BsShare_SwUpdFotadecrypt_Element
    SysReturnType (*ReadJobStatus_BsShare_EcuPartNumber_Element)(uint8 * const); // Read operation for JobStatus_BsShare_EcuPartNumber_Element
    SysReturnType (*ReadJobStatus_BsShare_VisMeet_Element)(uint8 * const); // Read operation for JobStatus_BsShare_VisMeet_Element
    SysReturnType (*ReadJobStatus_BsShare_VehicleConfig_Element)(uint8 * const); // Read operation for JobStatus_BsShare_VehicleConfig_Element
    SysReturnType (*ReadJobStatus_BsConst_SpeedoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_SpeedoGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TachoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TachoGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_FuelGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_FuelGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TempGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TempGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_PowerGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_PowerGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_OilGauge_Element)(uint8 * const); // Read operation for JobStatus_BsConst_OilGauge_Element
    SysReturnType (*ReadJobStatus_BsConst_TripComputer_Element)(uint8 * const); // Read operation for JobStatus_BsConst_TripComputer_Element
    SysReturnType (*ReadJobStatus_BsConst_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Illumination_Element
    SysReturnType (*ReadJobStatus_BsConst_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Audio_Element
    SysReturnType (*ReadJobStatus_BsConst_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Warning_Element
    SysReturnType (*ReadJobStatus_BsConst_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsConst_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsConst_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Communication_Element
    SysReturnType (*ReadJobStatus_BsConst_Power_Element)(uint8 * const); // Read operation for JobStatus_BsConst_Power_Element
    SysReturnType (*ReadJobStatus_BsConst_ServiceReminder_Element)(uint8 * const); // Read operation for JobStatus_BsConst_ServiceReminder_Element
    SysReturnType (*ReadJobStatus_BsConst_EngOffTimer_Element)(uint8 * const); // Read operation for JobStatus_BsConst_EngOffTimer_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Warning_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Power_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Power_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Display_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Display_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Audio_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Communication_Element
    SysReturnType (*ReadJobStatus_BsFusa_Fota_Element)(uint8 * const); // Read operation for JobStatus_BsFusa_Fota_Element
    SysReturnType (*ReadJobStatus_BsFuSa_Config_Element)(uint8 * const); // Read operation for JobStatus_BsFuSa_Config_Element
    SysReturnType (*ReadJobStatus_BsCys_Certicificate_Element)(uint8 * const); // Read operation for JobStatus_BsCys_Certicificate_Element
    SysReturnType (*ReadJobStatus_RefCys_Certicificate_Element)(uint8 * const); // Read operation for JobStatus_RefCys_Certicificate_Element
    SysReturnType (*ReadJobStatus_RefCys_Certicificate1_Element)(uint8 * const); // Read operation for JobStatus_RefCys_Certicificate1_Element
    SysReturnType (*ReadJobStatus_BsRt_Odometer_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Odometer_Element
    SysReturnType (*ReadJobStatus_BsRt_SpeedoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_SpeedoGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TachoGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TachoGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_FuelGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_FuelGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TempGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TempGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_PowerGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_PowerGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_OilGauge_Element)(uint8 * const); // Read operation for JobStatus_BsRt_OilGauge_Element
    SysReturnType (*ReadJobStatus_BsRt_TripComputer_Element)(uint8 * const); // Read operation for JobStatus_BsRt_TripComputer_Element
    SysReturnType (*ReadJobStatus_BsRt_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Warning_Element
    SysReturnType (*ReadJobStatus_BsRt_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsRt_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsRt_Personalization_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Personalization_Element
    SysReturnType (*ReadJobStatus_BsRt_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsRt_Illumination_Element
    SysReturnType (*ReadJobStatus_BsRt_CusDlt_Element)(uint8 * const); // Read operation for JobStatus_BsRt_CusDlt_Element
    SysReturnType (*ReadJobStatus_BsReten_Odometer_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Odometer_Element
    SysReturnType (*ReadJobStatus_BsReten_Gauges_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Gauges_Element
    SysReturnType (*ReadJobStatus_BsReten_Tripcomputer_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Tripcomputer_Element
    SysReturnType (*ReadJobStatus_BsReten_Illumination_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Illumination_Element
    SysReturnType (*ReadJobStatus_BsReten_Audio_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Audio_Element
    SysReturnType (*ReadJobStatus_BsReten_Warning_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Warning_Element
    SysReturnType (*ReadJobStatus_BsReten_RealTimeClock_Element)(uint8 * const); // Read operation for JobStatus_BsReten_RealTimeClock_Element
    SysReturnType (*ReadJobStatus_BsReten_Communication_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Communication_Element
    SysReturnType (*ReadJobStatus_BsReten_Personalization_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Personalization_Element
    SysReturnType (*ReadJobStatus_BsReten_VisDlt_Element)(uint8 * const); // Read operation for JobStatus_BsReten_VisDlt_Element
    SysReturnType (*ReadJobStatus_BsReten_Power_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Power_Element
    SysReturnType (*ReadJobStatus_BsReten_Display_Element)(uint8 * const); // Read operation for JobStatus_BsReten_Display_Element
    SysReturnType (*ReadJobStatus_BsDiag_ErrorRecord_Element)(uint8 * const); // Read operation for JobStatus_BsDiag_ErrorRecord_Element
    SysReturnType (*ReadJobStatus_BsDiag_Dtc_Element)(uint8 * const); // Read operation for JobStatus_BsDiag_Dtc_Element
} tif_SR_JobStatusRequired;
#endif // #if (defined(if_SR_JobStatus_USAGE_VISIBILITY))

// =====================================================================================================================
//                                            Transported interface allocator
// =====================================================================================================================

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))
#define mif_SR_JobStatusProvided_Allocate(instanceName, itsif_SR_JobStatus_FCTTBL) \
    tif_SR_JobStatusProvided instanceName = itsif_SR_JobStatus_FCTTBL;
#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

#if (defined(if_SR_JobStatus_USAGE_VISIBILITY))
#define mif_SR_JobStatusRequired_Allocate(instanceName, itsif_SR_JobStatus_FCTTBL) \
    tif_SR_JobStatusRequired instanceName = itsif_SR_JobStatus_FCTTBL;
#endif // #if (defined(if_SR_JobStatus_USAGE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                               Part for the TI provider
// ---------------------------------------------------------------------------------------------------------------------

#if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_SwUpdReflash_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdReflash_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_SwUpdReflash_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_SwUpdReflash_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsShare_SwUpdReflash_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdReflash_Element(Ref, JobStatus_BsShare_SwUpdReflash_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_SwUpdReflash_Element(JobStatus_BsShare_SwUpdReflash_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_SwUpdFotaMode_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaMode_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_SwUpdFotaMode_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_SwUpdFotaMode_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsShare_SwUpdFotaMode_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaMode_Element(Ref, JobStatus_BsShare_SwUpdFotaMode_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_SwUpdFotaMode_Element(JobStatus_BsShare_SwUpdFotaMode_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_SwUpdFotaFinPrint_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaFinPrint_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_SwUpdFotaFinPrint_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_SwUpdFotaFinPrint_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | JobStatus_BsShare_SwUpdFotaFinPrint_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaFinPrint_Element(Ref, JobStatus_BsShare_SwUpdFotaFinPrint_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_SwUpdFotaFinPrint_Element(JobStatus_BsShare_SwUpdFotaFinPrint_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_SwUpdFotaStatus_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaStatus_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_SwUpdFotaStatus_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_SwUpdFotaStatus_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | JobStatus_BsShare_SwUpdFotaStatus_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotaStatus_Element(Ref, JobStatus_BsShare_SwUpdFotaStatus_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_SwUpdFotaStatus_Element(JobStatus_BsShare_SwUpdFotaStatus_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_SwUpdFotadecrypt_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotadecrypt_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_SwUpdFotadecrypt_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_SwUpdFotadecrypt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                        | Class reference
// uint8                 | JobStatus_BsShare_SwUpdFotadecrypt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_SwUpdFotadecrypt_Element(Ref, JobStatus_BsShare_SwUpdFotadecrypt_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_SwUpdFotadecrypt_Element(JobStatus_BsShare_SwUpdFotadecrypt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_EcuPartNumber_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_EcuPartNumber_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_EcuPartNumber_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_EcuPartNumber_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsShare_EcuPartNumber_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_EcuPartNumber_Element(Ref, JobStatus_BsShare_EcuPartNumber_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_EcuPartNumber_Element(JobStatus_BsShare_EcuPartNumber_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_VisMeet_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_VisMeet_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_VisMeet_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_VisMeet_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsShare_VisMeet_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_VisMeet_Element(Ref, JobStatus_BsShare_VisMeet_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_VisMeet_Element(JobStatus_BsShare_VisMeet_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsShare_VehicleConfig_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsShare_VehicleConfig_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsShare_VehicleConfig_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsShare_VehicleConfig_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsShare_VehicleConfig_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsShare_VehicleConfig_Element(Ref, JobStatus_BsShare_VehicleConfig_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsShare_VehicleConfig_Element(JobStatus_BsShare_VehicleConfig_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_SpeedoGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_SpeedoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | JobStatus_BsConst_SpeedoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_SpeedoGauge_Element(Ref, JobStatus_BsConst_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_SpeedoGauge_Element(JobStatus_BsConst_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_TachoGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_TachoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_TachoGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | JobStatus_BsConst_TachoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_TachoGauge_Element(Ref, JobStatus_BsConst_TachoGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_TachoGauge_Element(JobStatus_BsConst_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_FuelGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_FuelGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_FuelGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | JobStatus_BsConst_FuelGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_FuelGauge_Element(Ref, JobStatus_BsConst_FuelGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_FuelGauge_Element(JobStatus_BsConst_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_TempGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_TempGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_TempGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | JobStatus_BsConst_TempGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_TempGauge_Element(Ref, JobStatus_BsConst_TempGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_TempGauge_Element(JobStatus_BsConst_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_PowerGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_PowerGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_PowerGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | JobStatus_BsConst_PowerGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_PowerGauge_Element(Ref, JobStatus_BsConst_PowerGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_PowerGauge_Element(JobStatus_BsConst_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_OilGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_OilGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_OilGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | JobStatus_BsConst_OilGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_OilGauge_Element(Ref, JobStatus_BsConst_OilGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_OilGauge_Element(JobStatus_BsConst_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_TripComputer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_TripComputer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_TripComputer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsConst_TripComputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_TripComputer_Element(Ref, JobStatus_BsConst_TripComputer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_TripComputer_Element(JobStatus_BsConst_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_Illumination_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_Illumination_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsConst_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_Illumination_Element(Ref, JobStatus_BsConst_Illumination_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_Illumination_Element(JobStatus_BsConst_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_Audio_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_Audio_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsConst_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_Audio_Element(Ref, JobStatus_BsConst_Audio_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_Audio_Element(JobStatus_BsConst_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_Warning_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_Warning_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsConst_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_Warning_Element(Ref, JobStatus_BsConst_Warning_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_Warning_Element(JobStatus_BsConst_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_RealTimeClock_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_RealTimeClock_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsConst_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_RealTimeClock_Element(Ref, JobStatus_BsConst_RealTimeClock_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_RealTimeClock_Element(JobStatus_BsConst_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_Communication_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_Communication_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsConst_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_Communication_Element(Ref, JobStatus_BsConst_Communication_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_Communication_Element(JobStatus_BsConst_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_Power_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_Power_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_Power_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsConst_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_Power_Element(Ref, JobStatus_BsConst_Power_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_Power_Element(JobStatus_BsConst_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_ServiceReminder_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_ServiceReminder_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_ServiceReminder_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_ServiceReminder_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | JobStatus_BsConst_ServiceReminder_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_ServiceReminder_Element(Ref, JobStatus_BsConst_ServiceReminder_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_ServiceReminder_Element(JobStatus_BsConst_ServiceReminder_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsConst_EngOffTimer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsConst_EngOffTimer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsConst_EngOffTimer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsConst_EngOffTimer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | JobStatus_BsConst_EngOffTimer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsConst_EngOffTimer_Element(Ref, JobStatus_BsConst_EngOffTimer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsConst_EngOffTimer_Element(JobStatus_BsConst_EngOffTimer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Warning_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Warning_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsFuSa_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Warning_Element(Ref, JobStatus_BsFuSa_Warning_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Warning_Element(JobStatus_BsFuSa_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Power_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Power_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Power_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                            | Class reference
// uint8                 | JobStatus_BsFuSa_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Power_Element(Ref, JobStatus_BsFuSa_Power_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Power_Element(JobStatus_BsFuSa_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Display_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Display_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Display_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsFuSa_Display_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Display_Element(Ref, JobStatus_BsFuSa_Display_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Display_Element(JobStatus_BsFuSa_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Audio_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Audio_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                            | Class reference
// uint8                 | JobStatus_BsFuSa_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Audio_Element(Ref, JobStatus_BsFuSa_Audio_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Audio_Element(JobStatus_BsFuSa_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Communication_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Communication_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsFuSa_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Communication_Element(Ref, JobStatus_BsFuSa_Communication_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Communication_Element(JobStatus_BsFuSa_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFusa_Fota_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFusa_Fota_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFusa_Fota_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFusa_Fota_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                           | Class reference
// uint8                 | JobStatus_BsFusa_Fota_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFusa_Fota_Element(Ref, JobStatus_BsFusa_Fota_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFusa_Fota_Element(JobStatus_BsFusa_Fota_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsFuSa_Config_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsFuSa_Config_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsFuSa_Config_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsFuSa_Config_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsFuSa_Config_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsFuSa_Config_Element(Ref, JobStatus_BsFuSa_Config_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsFuSa_Config_Element(JobStatus_BsFuSa_Config_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsCys_Certicificate_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsCys_Certicificate_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsCys_Certicificate_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | JobStatus_BsCys_Certicificate_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsCys_Certicificate_Element(Ref, JobStatus_BsCys_Certicificate_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsCys_Certicificate_Element(JobStatus_BsCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_RefCys_Certicificate_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_RefCys_Certicificate_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_RefCys_Certicificate_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_RefCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_RefCys_Certicificate_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_RefCys_Certicificate_Element(Ref, JobStatus_RefCys_Certicificate_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_RefCys_Certicificate_Element(JobStatus_RefCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_RefCys_Certicificate1_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_RefCys_Certicificate1_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_RefCys_Certicificate1_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_RefCys_Certicificate1_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_RefCys_Certicificate1_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_RefCys_Certicificate1_Element(Ref, JobStatus_RefCys_Certicificate1_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_RefCys_Certicificate1_Element(JobStatus_RefCys_Certicificate1_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_Odometer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_Odometer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_Odometer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsRt_Odometer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_Odometer_Element(Ref, JobStatus_BsRt_Odometer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_Odometer_Element(JobStatus_BsRt_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_SpeedoGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_SpeedoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | JobStatus_BsRt_SpeedoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_SpeedoGauge_Element(Ref, JobStatus_BsRt_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_SpeedoGauge_Element(JobStatus_BsRt_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_TachoGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_TachoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_TachoGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsRt_TachoGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_TachoGauge_Element(Ref, JobStatus_BsRt_TachoGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_TachoGauge_Element(JobStatus_BsRt_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_FuelGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_FuelGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_FuelGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsRt_FuelGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_FuelGauge_Element(Ref, JobStatus_BsRt_FuelGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_FuelGauge_Element(JobStatus_BsRt_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_TempGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_TempGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_TempGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsRt_TempGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_TempGauge_Element(Ref, JobStatus_BsRt_TempGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_TempGauge_Element(JobStatus_BsRt_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_PowerGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_PowerGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_PowerGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsRt_PowerGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_PowerGauge_Element(Ref, JobStatus_BsRt_PowerGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_PowerGauge_Element(JobStatus_BsRt_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_OilGauge_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_OilGauge_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_OilGauge_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsRt_OilGauge_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_OilGauge_Element(Ref, JobStatus_BsRt_OilGauge_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_OilGauge_Element(JobStatus_BsRt_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_TripComputer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_TripComputer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_TripComputer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | JobStatus_BsRt_TripComputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_TripComputer_Element(Ref, JobStatus_BsRt_TripComputer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_TripComputer_Element(JobStatus_BsRt_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_Warning_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_Warning_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                            | Class reference
// uint8                 | JobStatus_BsRt_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_Warning_Element(Ref, JobStatus_BsRt_Warning_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_Warning_Element(JobStatus_BsRt_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_RealTimeClock_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_RealTimeClock_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | JobStatus_BsRt_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_RealTimeClock_Element(Ref, JobStatus_BsRt_RealTimeClock_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_RealTimeClock_Element(JobStatus_BsRt_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_Personalization_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_Personalization_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_Personalization_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsRt_Personalization_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_Personalization_Element(Ref, JobStatus_BsRt_Personalization_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_Personalization_Element(JobStatus_BsRt_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_Illumination_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_Illumination_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | JobStatus_BsRt_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_Illumination_Element(Ref, JobStatus_BsRt_Illumination_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_Illumination_Element(JobStatus_BsRt_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsRt_CusDlt_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsRt_CusDlt_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsRt_CusDlt_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsRt_CusDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                           | Class reference
// uint8                 | JobStatus_BsRt_CusDlt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsRt_CusDlt_Element(Ref, JobStatus_BsRt_CusDlt_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsRt_CusDlt_Element(JobStatus_BsRt_CusDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Odometer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Odometer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Odometer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | JobStatus_BsReten_Odometer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Odometer_Element(Ref, JobStatus_BsReten_Odometer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Odometer_Element(JobStatus_BsReten_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Gauges_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Gauges_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Gauges_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Gauges_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsReten_Gauges_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Gauges_Element(Ref, JobStatus_BsReten_Gauges_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Gauges_Element(JobStatus_BsReten_Gauges_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Tripcomputer_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Tripcomputer_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Tripcomputer_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Tripcomputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsReten_Tripcomputer_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Tripcomputer_Element(Ref, JobStatus_BsReten_Tripcomputer_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Tripcomputer_Element(JobStatus_BsReten_Tripcomputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Illumination_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Illumination_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | JobStatus_BsReten_Illumination_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Illumination_Element(Ref, JobStatus_BsReten_Illumination_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Illumination_Element(JobStatus_BsReten_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Audio_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Audio_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsReten_Audio_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Audio_Element(Ref, JobStatus_BsReten_Audio_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Audio_Element(JobStatus_BsReten_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Warning_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Warning_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsReten_Warning_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Warning_Element(Ref, JobStatus_BsReten_Warning_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Warning_Element(JobStatus_BsReten_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_RealTimeClock_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_RealTimeClock_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsReten_RealTimeClock_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_RealTimeClock_Element(Ref, JobStatus_BsReten_RealTimeClock_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_RealTimeClock_Element(JobStatus_BsReten_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Communication_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Communication_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | JobStatus_BsReten_Communication_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Communication_Element(Ref, JobStatus_BsReten_Communication_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Communication_Element(JobStatus_BsReten_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Personalization_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Personalization_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Personalization_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | JobStatus_BsReten_Personalization_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Personalization_Element(Ref, JobStatus_BsReten_Personalization_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Personalization_Element(JobStatus_BsReten_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_VisDlt_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_VisDlt_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_VisDlt_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_VisDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | JobStatus_BsReten_VisDlt_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_VisDlt_Element(Ref, JobStatus_BsReten_VisDlt_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_VisDlt_Element(JobStatus_BsReten_VisDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Power_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Power_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Power_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | JobStatus_BsReten_Power_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Power_Element(Ref, JobStatus_BsReten_Power_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Power_Element(JobStatus_BsReten_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsReten_Display_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsReten_Display_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsReten_Display_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsReten_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | JobStatus_BsReten_Display_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsReten_Display_Element(Ref, JobStatus_BsReten_Display_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsReten_Display_Element(JobStatus_BsReten_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsDiag_ErrorRecord_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsDiag_ErrorRecord_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsDiag_ErrorRecord_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsDiag_ErrorRecord_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | JobStatus_BsDiag_ErrorRecord_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsDiag_ErrorRecord_Element(Ref, JobStatus_BsDiag_ErrorRecord_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsDiag_ErrorRecord_Element(JobStatus_BsDiag_ErrorRecord_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>WriteJobStatus_BsDiag_Dtc_Element
// Method      :        if_SR_JobStatus_WriteJobStatus_BsDiag_Dtc_Element(tif_SR_JobStatus_Ref const This, uint8 const JobStatus_BsDiag_Dtc_Element)
// Visibility  :        public
// Description :        Write operation for JobStatus_BsDiag_Dtc_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |          Name(Direction)          |                         Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                          | Class reference
// uint8                 | JobStatus_BsDiag_Dtc_Element(In)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_WriteJobStatus_BsDiag_Dtc_Element(Ref, JobStatus_BsDiag_Dtc_Element) \
    (SysReturnType)(Ref)->WriteJobStatus_BsDiag_Dtc_Element(JobStatus_BsDiag_Dtc_Element)

#endif // #if (defined(if_SR_JobStatus_PROVIDE_VISIBILITY))

// ---------------------------------------------------------------------------------------------------------------------
//                                            Part for the TI provider & user
// ---------------------------------------------------------------------------------------------------------------------

#if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_SwUpdReflash_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdReflash_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_SwUpdReflash_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_SwUpdReflash_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsShare_SwUpdReflash_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdReflash_Element(Ref, pJobStatus_BsShare_SwUpdReflash_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_SwUpdReflash_Element(pJobStatus_BsShare_SwUpdReflash_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_SwUpdFotaMode_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaMode_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_SwUpdFotaMode_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_SwUpdFotaMode_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsShare_SwUpdFotaMode_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaMode_Element(Ref, pJobStatus_BsShare_SwUpdFotaMode_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_SwUpdFotaMode_Element(pJobStatus_BsShare_SwUpdFotaMode_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_SwUpdFotaFinPrint_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_SwUpdFotaFinPrint_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                  Name(Direction)                   |                Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                           | Class reference
// uint8                 | pJobStatus_BsShare_SwUpdFotaFinPrint_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element(Ref, pJobStatus_BsShare_SwUpdFotaFinPrint_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_SwUpdFotaFinPrint_Element(pJobStatus_BsShare_SwUpdFotaFinPrint_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_SwUpdFotaStatus_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaStatus_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_SwUpdFotaStatus_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_SwUpdFotaStatus_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | pJobStatus_BsShare_SwUpdFotaStatus_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotaStatus_Element(Ref, pJobStatus_BsShare_SwUpdFotaStatus_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_SwUpdFotaStatus_Element(pJobStatus_BsShare_SwUpdFotaStatus_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_SwUpdFotadecrypt_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotadecrypt_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_SwUpdFotadecrypt_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_SwUpdFotadecrypt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                  Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                          | Class reference
// uint8                 | pJobStatus_BsShare_SwUpdFotadecrypt_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_SwUpdFotadecrypt_Element(Ref, pJobStatus_BsShare_SwUpdFotadecrypt_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_SwUpdFotadecrypt_Element(pJobStatus_BsShare_SwUpdFotadecrypt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_EcuPartNumber_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_EcuPartNumber_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_EcuPartNumber_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_EcuPartNumber_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsShare_EcuPartNumber_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_EcuPartNumber_Element(Ref, pJobStatus_BsShare_EcuPartNumber_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_EcuPartNumber_Element(pJobStatus_BsShare_EcuPartNumber_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_VisMeet_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_VisMeet_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_VisMeet_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_VisMeet_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsShare_VisMeet_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_VisMeet_Element(Ref, pJobStatus_BsShare_VisMeet_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_VisMeet_Element(pJobStatus_BsShare_VisMeet_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsShare_VehicleConfig_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsShare_VehicleConfig_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsShare_VehicleConfig_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsShare_VehicleConfig_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsShare_VehicleConfig_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsShare_VehicleConfig_Element(Ref, pJobStatus_BsShare_VehicleConfig_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsShare_VehicleConfig_Element(pJobStatus_BsShare_VehicleConfig_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_SpeedoGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_SpeedoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | pJobStatus_BsConst_SpeedoGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_SpeedoGauge_Element(Ref, pJobStatus_BsConst_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_SpeedoGauge_Element(pJobStatus_BsConst_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_TachoGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_TachoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_TachoGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | pJobStatus_BsConst_TachoGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_TachoGauge_Element(Ref, pJobStatus_BsConst_TachoGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_TachoGauge_Element(pJobStatus_BsConst_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_FuelGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_FuelGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_FuelGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | pJobStatus_BsConst_FuelGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_FuelGauge_Element(Ref, pJobStatus_BsConst_FuelGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_FuelGauge_Element(pJobStatus_BsConst_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_TempGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_TempGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_TempGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | pJobStatus_BsConst_TempGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_TempGauge_Element(Ref, pJobStatus_BsConst_TempGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_TempGauge_Element(pJobStatus_BsConst_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_PowerGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_PowerGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_PowerGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | pJobStatus_BsConst_PowerGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_PowerGauge_Element(Ref, pJobStatus_BsConst_PowerGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_PowerGauge_Element(pJobStatus_BsConst_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_OilGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_OilGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_OilGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | pJobStatus_BsConst_OilGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_OilGauge_Element(Ref, pJobStatus_BsConst_OilGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_OilGauge_Element(pJobStatus_BsConst_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_TripComputer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_TripComputer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_TripComputer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsConst_TripComputer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_TripComputer_Element(Ref, pJobStatus_BsConst_TripComputer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_TripComputer_Element(pJobStatus_BsConst_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_Illumination_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_Illumination_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsConst_Illumination_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_Illumination_Element(Ref, pJobStatus_BsConst_Illumination_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_Illumination_Element(pJobStatus_BsConst_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_Audio_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_Audio_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsConst_Audio_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_Audio_Element(Ref, pJobStatus_BsConst_Audio_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_Audio_Element(pJobStatus_BsConst_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_Warning_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_Warning_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsConst_Warning_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_Warning_Element(Ref, pJobStatus_BsConst_Warning_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_Warning_Element(pJobStatus_BsConst_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_RealTimeClock_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_RealTimeClock_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsConst_RealTimeClock_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_RealTimeClock_Element(Ref, pJobStatus_BsConst_RealTimeClock_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_RealTimeClock_Element(pJobStatus_BsConst_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_Communication_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_Communication_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsConst_Communication_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_Communication_Element(Ref, pJobStatus_BsConst_Communication_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_Communication_Element(pJobStatus_BsConst_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_Power_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_Power_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_Power_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsConst_Power_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_Power_Element(Ref, pJobStatus_BsConst_Power_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_Power_Element(pJobStatus_BsConst_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_ServiceReminder_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_ServiceReminder_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_ServiceReminder_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_ServiceReminder_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | pJobStatus_BsConst_ServiceReminder_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_ServiceReminder_Element(Ref, pJobStatus_BsConst_ServiceReminder_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_ServiceReminder_Element(pJobStatus_BsConst_ServiceReminder_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsConst_EngOffTimer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsConst_EngOffTimer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsConst_EngOffTimer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsConst_EngOffTimer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | pJobStatus_BsConst_EngOffTimer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsConst_EngOffTimer_Element(Ref, pJobStatus_BsConst_EngOffTimer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsConst_EngOffTimer_Element(pJobStatus_BsConst_EngOffTimer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Warning_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Warning_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsFuSa_Warning_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Warning_Element(Ref, pJobStatus_BsFuSa_Warning_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Warning_Element(pJobStatus_BsFuSa_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Power_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Power_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Power_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | pJobStatus_BsFuSa_Power_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Power_Element(Ref, pJobStatus_BsFuSa_Power_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Power_Element(pJobStatus_BsFuSa_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Display_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Display_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Display_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsFuSa_Display_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Display_Element(Ref, pJobStatus_BsFuSa_Display_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Display_Element(pJobStatus_BsFuSa_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Audio_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Audio_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | pJobStatus_BsFuSa_Audio_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Audio_Element(Ref, pJobStatus_BsFuSa_Audio_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Audio_Element(pJobStatus_BsFuSa_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Communication_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Communication_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsFuSa_Communication_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Communication_Element(Ref, pJobStatus_BsFuSa_Communication_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Communication_Element(pJobStatus_BsFuSa_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFusa_Fota_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFusa_Fota_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFusa_Fota_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFusa_Fota_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | pJobStatus_BsFusa_Fota_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFusa_Fota_Element(Ref, pJobStatus_BsFusa_Fota_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFusa_Fota_Element(pJobStatus_BsFusa_Fota_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsFuSa_Config_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsFuSa_Config_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsFuSa_Config_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsFuSa_Config_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsFuSa_Config_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsFuSa_Config_Element(Ref, pJobStatus_BsFuSa_Config_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsFuSa_Config_Element(pJobStatus_BsFuSa_Config_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsCys_Certicificate_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsCys_Certicificate_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsCys_Certicificate_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                     | Class reference
// uint8                 | pJobStatus_BsCys_Certicificate_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsCys_Certicificate_Element(Ref, pJobStatus_BsCys_Certicificate_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsCys_Certicificate_Element(pJobStatus_BsCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_RefCys_Certicificate_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_RefCys_Certicificate_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_RefCys_Certicificate_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_RefCys_Certicificate_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_RefCys_Certicificate_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_RefCys_Certicificate_Element(Ref, pJobStatus_RefCys_Certicificate_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_RefCys_Certicificate_Element(pJobStatus_RefCys_Certicificate_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_RefCys_Certicificate1_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_RefCys_Certicificate1_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_RefCys_Certicificate1_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_RefCys_Certicificate1_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_RefCys_Certicificate1_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_RefCys_Certicificate1_Element(Ref, pJobStatus_RefCys_Certicificate1_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_RefCys_Certicificate1_Element(pJobStatus_RefCys_Certicificate1_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_Odometer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_Odometer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_Odometer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsRt_Odometer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_Odometer_Element(Ref, pJobStatus_BsRt_Odometer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_Odometer_Element(pJobStatus_BsRt_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_SpeedoGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_SpeedoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_SpeedoGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_SpeedoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | pJobStatus_BsRt_SpeedoGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_SpeedoGauge_Element(Ref, pJobStatus_BsRt_SpeedoGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_SpeedoGauge_Element(pJobStatus_BsRt_SpeedoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_TachoGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_TachoGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_TachoGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_TachoGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsRt_TachoGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_TachoGauge_Element(Ref, pJobStatus_BsRt_TachoGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_TachoGauge_Element(pJobStatus_BsRt_TachoGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_FuelGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_FuelGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_FuelGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_FuelGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsRt_FuelGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_FuelGauge_Element(Ref, pJobStatus_BsRt_FuelGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_FuelGauge_Element(pJobStatus_BsRt_FuelGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_TempGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_TempGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_TempGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_TempGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsRt_TempGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_TempGauge_Element(Ref, pJobStatus_BsRt_TempGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_TempGauge_Element(pJobStatus_BsRt_TempGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_PowerGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_PowerGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_PowerGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_PowerGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsRt_PowerGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_PowerGauge_Element(Ref, pJobStatus_BsRt_PowerGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_PowerGauge_Element(pJobStatus_BsRt_PowerGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_OilGauge_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_OilGauge_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_OilGauge_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_OilGauge_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsRt_OilGauge_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_OilGauge_Element(Ref, pJobStatus_BsRt_OilGauge_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_OilGauge_Element(pJobStatus_BsRt_OilGauge_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_TripComputer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_TripComputer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_TripComputer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_TripComputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | pJobStatus_BsRt_TripComputer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_TripComputer_Element(Ref, pJobStatus_BsRt_TripComputer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_TripComputer_Element(pJobStatus_BsRt_TripComputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_Warning_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_Warning_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                              | Class reference
// uint8                 | pJobStatus_BsRt_Warning_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_Warning_Element(Ref, pJobStatus_BsRt_Warning_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_Warning_Element(pJobStatus_BsRt_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_RealTimeClock_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_RealTimeClock_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | pJobStatus_BsRt_RealTimeClock_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_RealTimeClock_Element(Ref, pJobStatus_BsRt_RealTimeClock_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_RealTimeClock_Element(pJobStatus_BsRt_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_Personalization_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_Personalization_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_Personalization_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsRt_Personalization_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_Personalization_Element(Ref, pJobStatus_BsRt_Personalization_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_Personalization_Element(pJobStatus_BsRt_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_Illumination_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_Illumination_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                   | Class reference
// uint8                 | pJobStatus_BsRt_Illumination_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_Illumination_Element(Ref, pJobStatus_BsRt_Illumination_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_Illumination_Element(pJobStatus_BsRt_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsRt_CusDlt_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsRt_CusDlt_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsRt_CusDlt_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsRt_CusDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)            |                       Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                             | Class reference
// uint8                 | pJobStatus_BsRt_CusDlt_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsRt_CusDlt_Element(Ref, pJobStatus_BsRt_CusDlt_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsRt_CusDlt_Element(pJobStatus_BsRt_CusDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Odometer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Odometer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Odometer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Odometer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |              Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                  | Class reference
// uint8                 | pJobStatus_BsReten_Odometer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Odometer_Element(Ref, pJobStatus_BsReten_Odometer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Odometer_Element(pJobStatus_BsReten_Odometer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Gauges_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Gauges_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Gauges_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Gauges_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsReten_Gauges_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Gauges_Element(Ref, pJobStatus_BsReten_Gauges_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Gauges_Element(pJobStatus_BsReten_Gauges_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Tripcomputer_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Tripcomputer_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Tripcomputer_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Tripcomputer_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsReten_Tripcomputer_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Tripcomputer_Element(Ref, pJobStatus_BsReten_Tripcomputer_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Tripcomputer_Element(pJobStatus_BsReten_Tripcomputer_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Illumination_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Illumination_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Illumination_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Illumination_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                |                   Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                      | Class reference
// uint8                 | pJobStatus_BsReten_Illumination_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Illumination_Element(Ref, pJobStatus_BsReten_Illumination_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Illumination_Element(pJobStatus_BsReten_Illumination_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Audio_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Audio_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Audio_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Audio_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsReten_Audio_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Audio_Element(Ref, pJobStatus_BsReten_Audio_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Audio_Element(pJobStatus_BsReten_Audio_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Warning_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Warning_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Warning_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Warning_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsReten_Warning_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Warning_Element(Ref, pJobStatus_BsReten_Warning_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Warning_Element(pJobStatus_BsReten_Warning_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_RealTimeClock_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_RealTimeClock_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_RealTimeClock_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_RealTimeClock_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsReten_RealTimeClock_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_RealTimeClock_Element(Ref, pJobStatus_BsReten_RealTimeClock_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_RealTimeClock_Element(pJobStatus_BsReten_RealTimeClock_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Communication_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Communication_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Communication_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Communication_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                Name(Direction)                 |                  Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                       | Class reference
// uint8                 | pJobStatus_BsReten_Communication_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Communication_Element(Ref, pJobStatus_BsReten_Communication_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Communication_Element(pJobStatus_BsReten_Communication_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Personalization_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Personalization_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Personalization_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Personalization_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |                 Name(Direction)                  |                 Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                         | Class reference
// uint8                 | pJobStatus_BsReten_Personalization_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Personalization_Element(Ref, pJobStatus_BsReten_Personalization_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Personalization_Element(pJobStatus_BsReten_Personalization_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_VisDlt_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_VisDlt_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_VisDlt_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_VisDlt_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                | Class reference
// uint8                 | pJobStatus_BsReten_VisDlt_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_VisDlt_Element(Ref, pJobStatus_BsReten_VisDlt_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_VisDlt_Element(pJobStatus_BsReten_VisDlt_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Power_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Power_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Power_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Power_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |            Name(Direction)             |                      Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                               | Class reference
// uint8                 | pJobStatus_BsReten_Power_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Power_Element(Ref, pJobStatus_BsReten_Power_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Power_Element(pJobStatus_BsReten_Power_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsReten_Display_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsReten_Display_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsReten_Display_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsReten_Display_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |             Name(Direction)              |                     Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                 | Class reference
// uint8                 | pJobStatus_BsReten_Display_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsReten_Display_Element(Ref, pJobStatus_BsReten_Display_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsReten_Display_Element(pJobStatus_BsReten_Display_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsDiag_ErrorRecord_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsDiag_ErrorRecord_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsDiag_ErrorRecord_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsDiag_ErrorRecord_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |               Name(Direction)               |                    Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                                    | Class reference
// uint8                 | pJobStatus_BsDiag_ErrorRecord_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsDiag_ErrorRecord_Element(Ref, pJobStatus_BsDiag_ErrorRecord_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsDiag_ErrorRecord_Element(pJobStatus_BsDiag_ErrorRecord_Element)

// =====================================================================================================================
// Upward trac.:        E40_Platform/C_GlobalDesign/SW_Classes/SWC_PACKAGES/MemAbstractMdl/if_SR_JobStatus/<AutoCreatedOperation>ReadJobStatus_BsDiag_Dtc_Element
// Method      :        if_SR_JobStatus_ReadJobStatus_BsDiag_Dtc_Element(tif_SR_JobStatus_Ref const This, uint8 * const pJobStatus_BsDiag_Dtc_Element)
// Visibility  :        public
// Description :        Read operation for JobStatus_BsDiag_Dtc_Element
// Parameters  :
// ---------------------------------------------------------------------------------------------------------------------
//         Type          |           Name(Direction)           |                        Description
// ---------------------------------------------------------------------------------------------------------------------
// tif_SR_JobStatus_Ref  | This(In)                            | Class reference
// uint8                 | pJobStatus_BsDiag_Dtc_Element(Out)  | None
// ---------------------------------------------------------------------------------------------------------------------
// Return type :        SysReturnType
// =====================================================================================================================
#define if_SR_JobStatus_ReadJobStatus_BsDiag_Dtc_Element(Ref, pJobStatus_BsDiag_Dtc_Element) \
    (SysReturnType)(Ref)->ReadJobStatus_BsDiag_Dtc_Element(pJobStatus_BsDiag_Dtc_Element)

#endif // #if ((defined(if_SR_JobStatus_PROVIDE_VISIBILITY)) || (defined(if_SR_JobStatus_USAGE_VISIBILITY)))

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __if_SR_JobStatus_G_h__
