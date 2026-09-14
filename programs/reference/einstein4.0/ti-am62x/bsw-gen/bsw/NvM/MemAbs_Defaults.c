/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have  jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation
**
******************************************************************************/

/******************************************************************************

File Name        :  MemAbs_Defaults.c
Module Short Name:  MemAbs_Defaults.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef MEMABS_DEFAULTS_C
#define MEMABS_DEFAULTS_C


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "MemAbs_Defaults.h"
#include "Rte_Type.h"
#include "Rte_MemAbstractMdl.h"
#include "NvMDefaults.h"
#include "MemLib.h"


/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdReflash_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash.BsShare_SwUpdReflash_Element,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaMode_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode.BsShare_SwUpdFotaMode_Element,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaFinPrint_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint.BsShare_SwUpdFotaFinPrint_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotaStatus_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus.BsShare_SwUpdFotaStatus_Element,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SwUpdFotadecrypt_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt.BsShare_SwUpdFotadecrypt_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_EcuPartNumber_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element,sizeof(Arr_u8_61));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisteonPartNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPartNumber,sizeof(Arr_u8_17));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisteonPCBPartNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPCBPartNumber,sizeof(Arr_u8_17));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_ProductSerialNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_ProductSerialNumber,sizeof(Arr_u8_10));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_PCBSerialNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_PCBSerialNumber,sizeof(Arr_u8_9));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SMTManufacturingDate(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTManufacturingDate,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_AssemblyManufacturingDate(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyManufacturingDate,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_SMTPlantNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTPlantNumber,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_AssemblyPlantNumber(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyPlantNumber,sizeof(Arr_u8_3));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_HWModification(uint16* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_HWModification;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element,sizeof(Arr_u8_46));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisMeet_EOLEntry_Element(uint16* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_EOLEntry_Element;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VehicleConfig_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig.BsShare_VehicleConfig_Element,sizeof(Arr_u8_256));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_SpeedoGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge.BsConst_SpeedoGauge_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TachoGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge.BsConst_TachoGauge_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_FuelGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge.BsConst_FuelGauge_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TempGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge.BsConst_TempGauge_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PowerGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge.BsConst_PowerGauge_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_OilGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge.BsConst_OilGauge_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_TripComputer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer.BsConst_TripComputer_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Slope_m;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Shift_b;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_X,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_Y,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Temp_Threshold_Hysteresis_Derating;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Derating_Backlight_Disable;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Temperature_Sensor_Conv,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_PCB_Temperature_Sensor_Conv,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level(uint16* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Display_Illum_Max_Level;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_PWM_boost_bypass_duty;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte(uint18* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_BsConst_Illumination_ReservedByte,sizeof(Arr_u8_28));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy1(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Slope_m_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy1(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Shift_b_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy1(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Derating_Backlight_Disable_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy1(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temperature_Sensor_Conv_SafeCopy1,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy1(uint16* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Display_Illum_Max_Level_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy1(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PWM_boost_bypass_duty_SafeCopy1;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(uint18* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_BsConst_Illumination_ReservedByte_SafeCopy1,sizeof(Arr_u8_28));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Slope_m_SafeCopy2(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Slope_m_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Compensation_Line_Shift_b_SafeCopy2(uint32* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Shift_b_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(uint16* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2,sizeof(Arr_u16_7));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Derating_Backlight_Disable_SafeCopy2(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Derating_Backlight_Disable_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Temperature_Sensor_Conv_SafeCopy2(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temperature_Sensor_Conv_SafeCopy2,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(uint32* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2,sizeof(T_NV_Temperature_Conversion));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Display_Illum_Max_Level_SafeCopy2(uint16* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Display_Illum_Max_Level_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_PWM_boost_bypass_duty_SafeCopy2(uint8* Ptr)
{
    *(Ptr) = Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PWM_boost_bypass_duty_SafeCopy2;
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(uint18* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_BsConst_Illumination_ReservedByte_SafeCopy2,sizeof(Arr_u8_28));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Audio_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio.BsConst_Audio_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Warning_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning.BsConst_Warning_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_RealTimeClock_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock.BsConst_RealTimeClock_Element,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Communication_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication.BsConst_Communication_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Power_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power.BsConst_Power_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_ServiceReminder_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder.BsConst_ServiceReminder_Element,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_EngOffTimer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer.BsConst_EngOffTimer_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsCys_Certicificate_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate.BsCys_Certicificate_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RefCys_Certicificate_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate.RefCys_Certicificate_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_RefCys_Certicificate1_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1.RefCys_Certicificate1_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Odometer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer.BsRt_Odometer_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_SpeedoGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge.BsRt_SpeedoGauge_Element,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TachoGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge.BsRt_TachoGauge_Element,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_FuelGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge.BsRt_FuelGauge_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TempGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge.BsRt_TempGauge_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_PowerGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge.BsRt_PowerGauge_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_OilGauge_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge.BsRt_OilGauge_Element,sizeof(Arr_u8_8));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_TripComputer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer.BsRt_TripComputer_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Warning_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning.BsRt_Warning_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_RealTimeClock_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock.BsRt_RealTimeClock_Element,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Personalization_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization.BsRt_Personalization_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_Illumination_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination.BsRt_Illumination_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsRt_CusDlt_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt.BsRt_CusDlt_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Odometer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer.BsReten_Odometer_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Gauges_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges.BsReten_Gauges_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Tripcomputer_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer.BsReten_Tripcomputer_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Illumination_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination.BsReten_Illumination_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Audio_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio.BsReten_Audio_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Warning_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning.BsReten_Warning_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_RealTimeClock_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock.BsReten_RealTimeClock_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Communication_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication.BsReten_Communication_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Personalization_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization.BsReten_Personalization_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Power_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power.BsReten_Power_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_Display_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display.BsReten_Display_Element,sizeof(Arr_u8_100));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsDiag_ErrorRecord_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord.BsDiag_ErrorRecord_Element,sizeof(Arr_u8_1024));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsDiag_Dtc_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc.BsDiag_Dtc_Element,sizeof(Arr_u8_2048));
    return E_OK;
}


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 26-05-2025 7.18.16 PM
****************************************************************/
