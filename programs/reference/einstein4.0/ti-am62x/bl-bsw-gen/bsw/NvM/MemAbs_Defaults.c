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
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element,sizeof(Arr_u8_128));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsShare_VisMeet_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element,sizeof(Arr_u8_48));
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

Std_ReturnType MemAbstractMdl_Get_Default_BsConst_Illumination_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination.BsConst_Illumination_Element,sizeof(Arr_u8_128));
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

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Warning_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning_ROM_NVBlockDescriptor_BsFuSa_Warning.BsFuSa_Warning_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Power_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power_ROM_NVBlockDescriptor_BsFuSa_Power.BsFuSa_Power_Element,sizeof(Arr_u8_48));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Display_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display_ROM_NVBlockDescriptor_BsFuSa_Display.BsFuSa_Display_Element,sizeof(Arr_u8_64));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Audio_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio_ROM_NVBlockDescriptor_BsFuSa_Audio.BsFuSa_Audio_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Communication_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication_ROM_NVBlockDescriptor_BsFuSa_Communication.BsFuSa_Communication_Element,sizeof(Arr_u8_16));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFusa_Fota_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota_ROM_NVBlockDescriptor_BsFusa_Fota.BsFusa_Fota_Element,sizeof(Arr_u8_32));
    return E_OK;
}

Std_ReturnType MemAbstractMdl_Get_Default_BsFuSa_Config_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config_ROM_NVBlockDescriptor_BsFuSa_Config.BsFuSa_Config_Element,sizeof(Arr_u8_16));
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

Std_ReturnType MemAbstractMdl_Get_Default_BsReten_VisDlt_Element(uint8* Ptr)
{
    MemLib_MemCpy(Ptr,Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt_ROM_NVBlockDescriptor_BsReten_VisDlt.BsReten_VisDlt_Element,sizeof(Arr_u8_256));
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
Created Time: 11-04-2024 19:36:22
****************************************************************/
