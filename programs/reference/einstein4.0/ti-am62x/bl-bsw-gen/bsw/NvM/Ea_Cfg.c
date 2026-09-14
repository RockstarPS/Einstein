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

File Name        :  Ea_Cfg.c
Module Short Name:  Ea_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef EA_CFG_C
#define EA_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Ea_Cfg.h"

 #define EA_CODE_SEC_START   
 #include "MemMap.h"
     
 #define EA_DATA_SEC_START   
 #include "MemMap.h"
     
 #define EA_CONST_SEC_START  
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


/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
const uint8 Ea_DatasetSelectionBits  = 0;

const Ea_FunctionPointerType Ea_DeviceFunctionPointer[EA_NUMBER_OF_DEVICES_SUPPORTED] =
{
        {
        EepDrv_SetMode,
        EepDrv_Read,
        EepDrv_Write,
        EepDrv_Compare,
        EepDrv_Erase,
        EepDrv_Cancel,
        EepDrv_GetStatus,
        EepDrv_GetJobResult,
        }
};

const Ea_ConfigType Ea_Config[EA_NUM_BLOCKS]=
{
    {
        0,                       /* BlockBaseAddress */
        8,                       /* BlockSize        */
        1,                       /* NoOfInstances    */
        0,                        /* Bit0 - ImmediateData, Bit1 - Verification Enabled   */
        0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash   */
    {
          4096,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode   */
    {
          4108,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint   */
    {
          4128,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus   */
    {
          4164,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt   */
    {
          4216,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber   */
    {
          4284,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet   */
    {
          4416,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig   */
    {
          4468,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge   */
    {
          4728,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge   */
    {
          4796,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge   */
    {
          4864,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge   */
    {
          4996,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge   */
    {
          5064,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge   */
    {
          5132,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer   */
    {
          5200,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination   */
    {
          5268,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio   */
    {
          5400,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning   */
    {
          5532,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock   */
    {
          5600,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication   */
    {
          5652,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power   */
    {
          5720,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder   */
    {
          5756,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer   */
    {
          5808,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning   */
    {
          5844,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning   */
    {
          5880,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power   */
    {
          5916,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power   */
    {
          5968,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display   */
    {
          6020,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display   */
    {
          6088,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio   */
    {
          6156,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio   */
    {
          6192,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication   */
    {
          6228,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication   */
    {
          6248,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota   */
    {
          6268,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota   */
    {
          6304,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config   */
    {
          6340,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config   */
    {
          6360,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate   */
    {
          6380,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate   */
    {
          6448,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate   */
    {
          6516,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate   */
    {
          6584,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1   */
    {
          6652,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1   */
    {
          6720,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer   */
    {
          6788,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer   */
    {
          6920,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge   */
    {
          7052,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge   */
    {
          7064,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge   */
    {
          7076,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge   */
    {
          7096,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge   */
    {
          7116,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge   */
    {
          7152,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge   */
    {
          7188,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge   */
    {
          7224,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge   */
    {
          7260,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge   */
    {
          7296,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge   */
    {
          7332,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge   */
    {
          7344,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer   */
    {
          7356,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer   */
    {
          7424,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning   */
    {
          7492,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning   */
    {
          7528,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock   */
    {
          7564,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock   */
    {
          7616,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization   */
    {
          7668,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization   */
    {
          7800,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination   */
    {
          7932,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination   */
    {
          8036,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt   */
    {
          8140,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt   */
    {
          8272,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer   */
    {
          8404,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer   */
    {
          8508,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges   */
    {
          8612,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges   */
    {
          8716,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer   */
    {
          8820,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer   */
    {
          8924,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination   */
    {
          9028,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination   */
    {
          9132,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio   */
    {
          9236,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio   */
    {
          9340,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning   */
    {
          9444,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning   */
    {
          9548,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock   */
    {
          9652,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock   */
    {
          9756,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication   */
    {
          9860,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication   */
    {
          9964,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization   */
    {
          10068,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization   */
    {
          10172,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt   */
    {
          10276,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt   */
    {
          10536,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power   */
    {
          10796,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power   */
    {
          10900,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display   */
    {
          11004,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display   */
    {
          11108,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord   */
    {
          11212,            /*   uint16 BlockBaseAddress;    */
          1026,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord   */
    {
          12240,            /*   uint16 BlockBaseAddress;    */
          1026,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc   */
    {
          13268,            /*   uint16 BlockBaseAddress;    */
          2050,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc   */
    {
          15320,            /*   uint16 BlockBaseAddress;    */
          2050,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
};
#define EA_CONST_SEC_END
 #include "MemMap.h"

#define EA_DATA_SEC_END
 #include "MemMap.h"

#define EA_CODE_SEC_END
 #include "MemMap.h"


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 11-04-2024 19:36:22
****************************************************************/
