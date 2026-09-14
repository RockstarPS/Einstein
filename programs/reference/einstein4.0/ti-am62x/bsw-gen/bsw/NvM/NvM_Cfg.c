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

File Name        :  NvM_Cfg.c
Module Short Name:  NvM_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_CFG_C
#define NVM_CFG_C
#define RTE_MICROSAR_PIM_EXPORT

#include "Rte_Type.h"
#include "Rte_NvM.h"
#include "NvM_Cfg.h"
#include "SchM_NvM.h"
#include "EcuMExt.h"
#include "Dem.h"
#include "Dem_Cbk.h"
#include "NvMExt_PrivateCfg.h"


#define NVM_CODE_SEC_START
 #include "MemMap.h"

#define NVM_DATA_SEC_START
 #include "MemMap.h"

#define NVM_CONST_SEC_START
 #include "MemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#ifdef __ghs__
#pragma alignvar (8)
#endif
uint8 NvMConfigBlock_RamBlock_au8[8];


extern VAR(NV_Data_BsShare_SwUpdReflash, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash;

extern CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_SwUpdFotaMode, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode;

extern CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint;

extern CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_SwUpdFotaStatus, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus;

extern CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_SwUpdFotadecrypt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt;

extern CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_EcuPartNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber;

extern CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_VisMeet, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet;

extern CONST(NV_Data_BsShare_VisMeet, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsShare_VehicleConfig, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig;

extern CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge;

extern CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge;

extern CONST(NV_Data_BsConst_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge;

extern CONST(NV_Data_BsConst_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge;

extern CONST(NV_Data_BsConst_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge;

extern CONST(NV_Data_BsConst_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge;

extern CONST(NV_Data_BsConst_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer;

extern CONST(NV_Data_BsConst_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination;

extern CONST(NV_Data_BsConst_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
extern VAR(NV_Data_BsConst_Illumination_Copy1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1;

extern CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Illumination_Copy2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2;

extern CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio;

extern CONST(NV_Data_BsConst_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning;

extern CONST(NV_Data_BsConst_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock;

extern CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication;

extern CONST(NV_Data_BsConst_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power;

extern CONST(NV_Data_BsConst_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_ServiceReminder, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder;

extern CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsConst_EngOffTimer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer;

extern CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate;

extern CONST(NV_Data_BsCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_RefCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate;

extern CONST(NV_Data_RefCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_RefCys_Certicificate1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1;

extern CONST(NV_Data_RefCys_Certicificate1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1 - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer;

extern CONST(NV_Data_BsRt_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge;

extern CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge;

extern CONST(NV_Data_BsRt_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge;

extern CONST(NV_Data_BsRt_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge;

extern CONST(NV_Data_BsRt_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge;

extern CONST(NV_Data_BsRt_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge;

extern CONST(NV_Data_BsRt_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer;

extern CONST(NV_Data_BsRt_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning;

extern CONST(NV_Data_BsRt_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock;

extern CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization;

extern CONST(NV_Data_BsRt_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination;

extern CONST(NV_Data_BsRt_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsRt_CusDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt;

extern CONST(NV_Data_BsRt_CusDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer;

extern CONST(NV_Data_BsReten_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Gauges, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges;

extern CONST(NV_Data_BsReten_Gauges, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Tripcomputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer;

extern CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination;

extern CONST(NV_Data_BsReten_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio;

extern CONST(NV_Data_BsReten_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning;

extern CONST(NV_Data_BsReten_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock;

extern CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication;

extern CONST(NV_Data_BsReten_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization;

extern CONST(NV_Data_BsReten_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power;

extern CONST(NV_Data_BsReten_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsReten_Display, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display;

extern CONST(NV_Data_BsReten_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsDiag_ErrorRecord, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord;

extern CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(NV_Data_BsDiag_Dtc, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc;

extern CONST(NV_Data_BsDiag_Dtc, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc - CallBack  */
extern Std_ReturnType Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(uint32, RTE_VAR_INIT) Retention_Group1;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0 - CallBack  */
extern Std_ReturnType NvMExt_NotfyJobEnd_Retention_Group1( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(uint16, RTE_VAR_INIT) RetentionBlockStatus;

extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) RetentionBlockStatusDefault;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus - CallBack  */
extern Std_ReturnType NvMExt_NotfyJobEnd_RetentionBlockStatus( uint8 ServiceId, NvM_RequestResultType JobResult );
extern VAR(Dem_Cfg_OpCycleType, RTE_VAR_INIT) Dem_Cfg_OpCycle;

extern CONST(Dem_Cfg_OpCycleType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_Cfg_OpCycleInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_UdsStatusDataType, RTE_VAR_INIT) Dem_Cfg_StatusData;

extern CONST(Dem_Cfg_UdsStatusDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_Cfg_StatusDataInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_0;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_1;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_2;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_3;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_4;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_5;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_6;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_7;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_8;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(Dem_Cfg_PrimaryMemEntryType, RTE_VAR_INIT) Dem_PrimaryEntry_9;

extern CONST(Dem_Cfg_PrimaryMemEntryType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Dem_MemoryEntryInit;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009 - CallBack  */
extern Std_ReturnType Dem_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(uint8, RTE_VAR_INIT) DltExt_AppInfo;

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) DltExt_AppInfo_Init;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_AppInfo - CallBack  */
extern Std_ReturnType DltExt_NvM_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(uint8, RTE_VAR_INIT) DltExt_SWHangInfo;

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) DltExt_SWHangInfo_Init;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_SWHangInfo - CallBack  */
extern Std_ReturnType DltExt_NvM_SWHang_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );

extern VAR(uint8, RTE_VAR_INIT) DltExt_ResetInfo;

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) DltExt_ResetInfo_Init;
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo - CallBack  */
extern Std_ReturnType DltExt_ResetInfo_JobFinished( uint8 ServiceId, NvM_RequestResultType JobResult );
/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const NvM_BlockDescriptorType NvM_BlockConfig[NVM_NUM_OF_BLOCKS+1]=
{
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);                                  */                   
        NULL,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */                   
        NULL,        /*   uint8*    RamBlockDataAddress;        */                   
        NULL,        /*   uint8*    RomBlockDataAddress;        */                   
        0,           /*   uint16    NvBlockBaseNumber;          */                   
        0,           /*   uint16    NvBlockLength;              */                   
        0,           /*   uint16    NvRamBlockIdentifier;       */                   
        1,           /*   uint8     BlockJobPriority;           */                   
        0,           /*   uint8     MaxNumReadRetries;          */                   
        0,           /*   uint8     MaxNumWriteRetries;         */                   
        0,           /*   uint8     NvBlockNum;                 */                   
        0,           /*   uint8     NvRamDeviceId;              */                   
        0,           /*   uint8     RomBlockNum;                */                   
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */                   
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */    
        0,           /*   boolean   BlockUseCrc;                */                   
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */                   
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);                                */                                
        NULL,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);   */                                
        (uint8*)&NvMConfigBlock_RamBlock_au8,        /*   uint8*    RamBlockDataAddress;        */                                
        NULL,        /*   uint8*    RomBlockDataAddress;        */                                
        0,           /*   uint16    NvBlockBaseNumber;          */                                
        8,          /*   uint16    NvBlockLength;              */                                
        0,           /*   uint16    NvRamBlockIdentifier;       */                                
        1,           /*   uint8     BlockJobPriority;           */                                
        0,           /*   uint8     MaxNumReadRetries;          */                                
        0,           /*   uint8     MaxNumWriteRetries;         */                                
        0,           /*   uint8     NvBlockNum;                 */                                
        0,           /*   uint8     NvRamDeviceId;              */                                
        0,           /*   uint8     RomBlockNum;                */                                
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */                                
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */                 
        0,           /*   boolean   BlockUseCrc;                */                                
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */                                
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash,        /*   uint8*    RomBlockDataAddress;        */
        2,           /*   uint16    NvBlockBaseNumber;          */
        8,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode,        /*   uint8*    RomBlockDataAddress;        */
        3,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint,        /*   uint8*    RomBlockDataAddress;        */
        4,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus,        /*   uint8*    RomBlockDataAddress;        */
        5,           /*   uint16    NvBlockBaseNumber;          */
        48,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt,        /*   uint8*    RomBlockDataAddress;        */
        6,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber,        /*   uint8*    RomBlockDataAddress;        */
        7,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet,        /*   uint8*    RomBlockDataAddress;        */
        8,           /*   uint16    NvBlockBaseNumber;          */
        48,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig,        /*   uint8*    RomBlockDataAddress;        */
        9,           /*   uint16    NvBlockBaseNumber;          */
        256,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge,        /*   uint8*    RomBlockDataAddress;        */
        10,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge,        /*   uint8*    RomBlockDataAddress;        */
        11,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge,        /*   uint8*    RomBlockDataAddress;        */
        12,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge,        /*   uint8*    RomBlockDataAddress;        */
        13,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge,        /*   uint8*    RomBlockDataAddress;        */
        14,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge,        /*   uint8*    RomBlockDataAddress;        */
        15,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer,        /*   uint8*    RomBlockDataAddress;        */
        16,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination,        /*   uint8*    RomBlockDataAddress;        */
        17,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1,        /*   uint8*    RomBlockDataAddress;        */
        18,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2,        /*   uint8*    RomBlockDataAddress;        */
        19,           /*   uint16    NvBlockBaseNumber;          */
        52,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio,        /*   uint8*    RomBlockDataAddress;        */
        20,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning,        /*   uint8*    RomBlockDataAddress;        */
        21,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock,        /*   uint8*    RomBlockDataAddress;        */
        22,           /*   uint16    NvBlockBaseNumber;          */
        48,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication,        /*   uint8*    RomBlockDataAddress;        */
        23,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power,        /*   uint8*    RomBlockDataAddress;        */
        24,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder,        /*   uint8*    RomBlockDataAddress;        */
        25,           /*   uint16    NvBlockBaseNumber;          */
        48,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer,        /*   uint8*    RomBlockDataAddress;        */
        26,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate,        /*   uint8*    RomBlockDataAddress;        */
        27,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate,        /*   uint8*    RomBlockDataAddress;        */
        29,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1,        /*   uint8*    RomBlockDataAddress;        */
        31,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer,        /*   uint8*    RomBlockDataAddress;        */
        33,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge,        /*   uint8*    RomBlockDataAddress;        */
        35,           /*   uint16    NvBlockBaseNumber;          */
        8,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge,        /*   uint8*    RomBlockDataAddress;        */
        37,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge,        /*   uint8*    RomBlockDataAddress;        */
        39,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge,        /*   uint8*    RomBlockDataAddress;        */
        41,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge,        /*   uint8*    RomBlockDataAddress;        */
        43,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge,        /*   uint8*    RomBlockDataAddress;        */
        45,           /*   uint16    NvBlockBaseNumber;          */
        8,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer,        /*   uint8*    RomBlockDataAddress;        */
        47,           /*   uint16    NvBlockBaseNumber;          */
        64,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning,        /*   uint8*    RomBlockDataAddress;        */
        49,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock,        /*   uint8*    RomBlockDataAddress;        */
        51,           /*   uint16    NvBlockBaseNumber;          */
        48,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization,        /*   uint8*    RomBlockDataAddress;        */
        53,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination,        /*   uint8*    RomBlockDataAddress;        */
        55,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt,        /*   uint8*    RomBlockDataAddress;        */
        57,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer,        /*   uint8*    RomBlockDataAddress;        */
        59,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges,        /*   uint8*    RomBlockDataAddress;        */
        61,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer,        /*   uint8*    RomBlockDataAddress;        */
        63,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination,        /*   uint8*    RomBlockDataAddress;        */
        65,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio,        /*   uint8*    RomBlockDataAddress;        */
        67,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning,        /*   uint8*    RomBlockDataAddress;        */
        69,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock,        /*   uint8*    RomBlockDataAddress;        */
        71,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication,        /*   uint8*    RomBlockDataAddress;        */
        73,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization,        /*   uint8*    RomBlockDataAddress;        */
        75,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power,        /*   uint8*    RomBlockDataAddress;        */
        77,           /*   uint16    NvBlockBaseNumber;          */
        256,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display,        /*   uint8*    RomBlockDataAddress;        */
        79,           /*   uint16    NvBlockBaseNumber;          */
        100,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord,        /*   uint8*    RomBlockDataAddress;        */
        81,           /*   uint16    NvBlockBaseNumber;          */
        1024,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc,        /*   uint8*    RomBlockDataAddress;        */
        83,           /*   uint16    NvBlockBaseNumber;          */
        2048,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        NvMExt_NotfyJobEnd_Retention_Group1,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Retention_Group1,        /*   uint8*    RamBlockDataAddress;        */
        NULL,        /*   uint8*    RomBlockDataAddress;        */
        85,           /*   uint16    NvBlockBaseNumber;          */
        32,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        NvMExt_NotfyJobEnd_RetentionBlockStatus,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&RetentionBlockStatus,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&RetentionBlockStatusDefault,        /*   uint8*    RomBlockDataAddress;        */
        86,           /*   uint16    NvBlockBaseNumber;          */
        2,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        0,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        0,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_Cfg_OpCycle,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_Cfg_OpCycleInit,        /*   uint8*    RomBlockDataAddress;        */
        87,           /*   uint16    NvBlockBaseNumber;          */
        6,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_Cfg_StatusData,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_Cfg_StatusDataInit,        /*   uint8*    RomBlockDataAddress;        */
        88,           /*   uint16    NvBlockBaseNumber;          */
        20,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_0,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        89,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_1,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        90,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_2,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        91,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_3,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        92,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_4,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        93,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_5,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        94,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_6,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        95,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_7,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        96,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_8,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        97,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        Dem_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&Dem_PrimaryEntry_9,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&Dem_MemoryEntryInit,        /*   uint8*    RomBlockDataAddress;        */
        98,           /*   uint16    NvBlockBaseNumber;          */
        16,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_AppInfo   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        DltExt_NvM_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&DltExt_AppInfo,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&DltExt_AppInfo_Init,        /*   uint8*    RomBlockDataAddress;        */
        99,           /*   uint16    NvBlockBaseNumber;          */
        128,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_8,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_SWHangInfo   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        DltExt_NvM_SWHang_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&DltExt_SWHangInfo,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&DltExt_SWHangInfo_Init,        /*   uint8*    RomBlockDataAddress;        */
        100,           /*   uint16    NvBlockBaseNumber;          */
        10,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        1,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_NATIVE_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo   */
    {
        NULL,        /*   Std_ReturnType (*InitCallback) (void);          */
        DltExt_ResetInfo_JobFinished,        /*   Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);     */
        (uint8*)&DltExt_ResetInfo,        /*   uint8*    RamBlockDataAddress;        */
        (uint8*)&DltExt_ResetInfo_Init,        /*   uint8*    RomBlockDataAddress;        */
        101,           /*   uint16    NvBlockBaseNumber;          */
        256,          /*   uint16    NvBlockLength;              */
        0,           /*   uint16    NvRamBlockIdentifier;       */
        16,           /*   uint8     BlockJobPriority;           */
        3,           /*   uint8     MaxNumReadRetries;          */
        3,           /*   uint8     MaxNumWriteRetries;         */
        2,           /*   uint8     NvBlockNum;                 */
        MEMIF_EA,   /*   uint8     NvRamDeviceId;              */
        1,           /*   uint8     RomBlockNum;                */
        CRC_16,       /*   NvM_CrcEnumeration BlockCrcType;      */
        NVM_REDUNDANT_BLOCK,           /*   NvM_BlockType BlockManagementType;    */
        1,           /*   boolean   BlockUseCrc;                */
        0,           /*   boolean   BlockUseSetRamBlockStatus;  */
        0,           /*   boolean BlockWriteProt;               */
        0,           /*   boolean   BswMBlockStatusInformation; */
        0,           /*   boolean   CalcRamBlockCrc;            */
        1,           /*   boolean   SelectBlockForReadAll;      */
        0,           /*   boolean   SelectBlockForWriteAll;     */
        0           /*   boolean   WriteBlockOnce;             */
    },
};
const NvM_JobQueueManagementType NvM_JobQueueManagementTable[NVM_MAX_JOB_PRIORITY] = 
{
    {
        0,                                  /*JobPriority*/
        0,                                  /*Index*/
        &NvM_JobQueuePriority0[0],              /*JobQueueAddress*/
        NUM_OF_PRIO_0_BLOCKS                /*JobQueueLength*/
    },
    {
        1,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        2,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        3,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        4,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        5,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        6,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        7,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        8,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        9,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        10,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        11,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        12,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        13,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        14,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        15,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        16,                                  /*JobPriority*/
        1,                                  /*Index*/
        &NvM_JobQueuePriority16[0],              /*JobQueueAddress*/
        NUM_OF_PRIO_16_BLOCKS                /*JobQueueLength*/
    },
    {
        17,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        18,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        19,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        20,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        21,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        22,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        23,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        24,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        25,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        26,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        27,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        28,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        29,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        30,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
    {
        31,                                  /*JobPriority*/
        255,                                  /*Index*/
        NULL,                               /*JobQueueAddress*/
        0                                   /*JobQueueLength*/
    },
};
/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                              Limited Scope Prototypes                      *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

extern void NvMExt_MultipleJobEndNotification(uint8 ServiceId, NvM_RequestResultType JobResult);
void NvM_MultiBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult)
{
    NvMExt_MultipleJobEndNotification(ServiceId, JobResult);
}

void NvM_EnterCriticalSection(void)
{
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

void NvM_ExitCriticalSection(void)
{
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}


#define NVM_CONST_SEC_END
 #include "MemMap.h"

#define NVM_DATA_SEC_END
 #include "MemMap.h"

#define NVM_CODE_SEC_END
 #include "MemMap.h"

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 10/30/2025 10:18:44 PM
****************************************************************/
