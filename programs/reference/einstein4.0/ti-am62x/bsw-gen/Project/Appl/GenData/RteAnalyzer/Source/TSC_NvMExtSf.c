/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_NvMExtSf.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_NvMExtSf.h"
#include "TSC_NvMExtSf.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
{
  return Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Ptr);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(const Rte_DT_Arr_u8_128_0 *BsConst_Audio_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Audio_Element(BsConst_Audio_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Communication_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Communication_Element(BsConst_Communication_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(const Rte_DT_Arr_u8_32_0 *BsConst_EngOffTimer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_EngOffTimer_Element(BsConst_EngOffTimer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(const Rte_DT_Arr_u8_128_0 *BsConst_FuelGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_FuelGauge_Element(BsConst_FuelGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_OilGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_OilGauge_Element(BsConst_OilGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_PowerGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_PowerGauge_Element(BsConst_PowerGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(const Rte_DT_Arr_u8_32_0 *BsConst_Power_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Power_Element(BsConst_Power_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsConst_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_RealTimeClock_Element(BsConst_RealTimeClock_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(const Rte_DT_Arr_u8_48_0 *BsConst_ServiceReminder_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_ServiceReminder_Element(BsConst_ServiceReminder_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_SpeedoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_SpeedoGauge_Element(BsConst_SpeedoGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TachoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TachoGauge_Element(BsConst_TachoGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TempGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TempGauge_Element(BsConst_TempGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsConst_TripComputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_TripComputer_Element(BsConst_TripComputer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(const Rte_DT_Arr_u8_64_0 *BsConst_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsConst_Warning_Element(BsConst_Warning_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *BsCys_Certicificate_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsCys_Certicificate_Element(BsCys_Certicificate_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(const Rte_DT_Arr_u8_2048_0 *BsDiag_Dtc_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_Dtc_Element(BsDiag_Dtc_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(const Rte_DT_Arr_u8_1024_0 *BsDiag_ErrorRecord_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsDiag_ErrorRecord_Element(BsDiag_ErrorRecord_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Audio_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Audio_Element(BsReten_Audio_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Communication_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Communication_Element(BsReten_Communication_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Display_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Display_Element(BsReten_Display_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Gauges_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Gauges_Element(BsReten_Gauges_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Illumination_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Illumination_Element(BsReten_Illumination_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Odometer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Odometer_Element(BsReten_Odometer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Personalization_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Personalization_Element(BsReten_Personalization_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Power_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Power_Element(BsReten_Power_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(const Rte_DT_Arr_u8_100_0 *BsReten_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_RealTimeClock_Element(BsReten_RealTimeClock_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Tripcomputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Tripcomputer_Element(BsReten_Tripcomputer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(const Rte_DT_Arr_u8_100_0 *BsReten_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsReten_Warning_Element(BsReten_Warning_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(const Rte_DT_Arr_u8_128_0 *BsRt_CusDlt_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_CusDlt_Element(BsRt_CusDlt_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_FuelGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_FuelGauge_Element(BsRt_FuelGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(const Rte_DT_Arr_u8_100_0 *BsRt_Illumination_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Illumination_Element(BsRt_Illumination_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Odometer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Odometer_Element(BsRt_Odometer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_OilGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_OilGauge_Element(BsRt_OilGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(const Rte_DT_Arr_u8_128_0 *BsRt_Personalization_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Personalization_Element(BsRt_Personalization_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_PowerGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_PowerGauge_Element(BsRt_PowerGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(const Rte_DT_Arr_u8_48_0 *BsRt_RealTimeClock_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_RealTimeClock_Element(BsRt_RealTimeClock_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(const Rte_DT_Arr_u8_8_0 *BsRt_SpeedoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_SpeedoGauge_Element(BsRt_SpeedoGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(const Rte_DT_Arr_u8_16_0 *BsRt_TachoGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TachoGauge_Element(BsRt_TachoGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(const Rte_DT_Arr_u8_32_0 *BsRt_TempGauge_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TempGauge_Element(BsRt_TempGauge_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(const Rte_DT_Arr_u8_64_0 *BsRt_TripComputer_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_TripComputer_Element(BsRt_TripComputer_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(const Rte_DT_Arr_u8_32_0 *BsRt_Warning_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsRt_Warning_Element(BsRt_Warning_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyManufacturingDate)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyManufacturingDate(BsShare_AssemblyManufacturingDate);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_AssemblyPlantNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_AssemblyPlantNumber(BsShare_AssemblyPlantNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(const Rte_DT_Arr_u8_61_0 *BsShare_EcuPartNumber_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_EcuPartNumber_Element(BsShare_EcuPartNumber_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(UInt16 BsShare_HWModification)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_HWModification(BsShare_HWModification);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(const Rte_DT_Arr_u8_9_0 *BsShare_PCBSerialNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_PCBSerialNumber(BsShare_PCBSerialNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(const Rte_DT_Arr_u8_10_0 *BsShare_ProductSerialNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_ProductSerialNumber(BsShare_ProductSerialNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(const Rte_DT_Arr_u8_3_0 *BsShare_SMTManufacturingDate)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTManufacturingDate(BsShare_SMTManufacturingDate);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(const Rte_DT_Arr_u8_3_0 *BsShare_SMTPlantNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SMTPlantNumber(BsShare_SMTPlantNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(const Rte_DT_Arr_u8_32_0 *BsShare_SwUpdFotaFinPrint_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaFinPrint_Element(BsShare_SwUpdFotaFinPrint_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(const Rte_DT_Arr_u8_16_0 *BsShare_SwUpdFotaMode_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaMode_Element(BsShare_SwUpdFotaMode_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(const Rte_DT_Arr_u8_48_0 *BsShare_SwUpdFotaStatus_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotaStatus_Element(BsShare_SwUpdFotaStatus_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(const Rte_DT_Arr_u8_64_0 *BsShare_SwUpdFotadecrypt_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdFotadecrypt_Element(BsShare_SwUpdFotadecrypt_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(const Rte_DT_Arr_u8_8_0 *BsShare_SwUpdReflash_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_SwUpdReflash_Element(BsShare_SwUpdReflash_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(const Rte_DT_Arr_u8_256_0 *BsShare_VehicleConfig_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VehicleConfig_Element(BsShare_VehicleConfig_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(UInt16 BsShare_VisMeet_EOLEntry_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_EOLEntry_Element(BsShare_VisMeet_EOLEntry_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(const Rte_DT_Arr_u8_46_0 *BsShare_VisMeet_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisMeet_Element(BsShare_VisMeet_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPCBPartNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPCBPartNumber(BsShare_VisteonPCBPartNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(const Rte_DT_Arr_u8_17_0 *BsShare_VisteonPartNumber)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_BsShare_VisteonPartNumber(BsShare_VisteonPartNumber);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate1_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate1_Element(RefCys_Certicificate1_Element);
}
Std_ReturnType TSC_NvMExtSf_Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(const Rte_DT_Arr_u8_64_0 *RefCys_Certicificate_Element)
{
  return Rte_Call_rp_CS_MemAbsSet_Set_RefCys_Certicificate_Element(RefCys_Certicificate_Element);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* NvMExtSf */
      /* NvMExtSf */



