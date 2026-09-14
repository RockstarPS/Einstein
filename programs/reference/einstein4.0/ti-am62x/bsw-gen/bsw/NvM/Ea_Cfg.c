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
          53,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1   */
    {
          5323,            /*   uint16 BlockBaseAddress;    */
          53,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2   */
    {
          5378,            /*   uint16 BlockBaseAddress;    */
          53,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio   */
    {
          5433,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning   */
    {
          5565,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock   */
    {
          5633,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication   */
    {
          5685,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power   */
    {
          5753,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder   */
    {
          5789,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer   */
    {
          5841,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate   */
    {
          5877,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate   */
    {
          5945,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate   */
    {
          6013,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate   */
    {
          6081,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1   */
    {
          6149,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1   */
    {
          6217,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer   */
    {
          6285,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer   */
    {
          6417,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge   */
    {
          6549,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge   */
    {
          6561,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge   */
    {
          6573,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge   */
    {
          6593,            /*   uint16 BlockBaseAddress;    */
          18,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge   */
    {
          6613,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge   */
    {
          6649,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge   */
    {
          6685,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge   */
    {
          6721,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge   */
    {
          6757,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge   */
    {
          6793,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge   */
    {
          6829,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge   */
    {
          6841,            /*   uint16 BlockBaseAddress;    */
          10,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer   */
    {
          6853,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer   */
    {
          6921,            /*   uint16 BlockBaseAddress;    */
          66,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning   */
    {
          6989,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning   */
    {
          7025,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock   */
    {
          7061,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock   */
    {
          7113,            /*   uint16 BlockBaseAddress;    */
          50,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization   */
    {
          7165,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization   */
    {
          7297,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination   */
    {
          7429,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination   */
    {
          7533,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt   */
    {
          7637,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt   */
    {
          7769,            /*   uint16 BlockBaseAddress;    */
          130,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer   */
    {
          7901,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer   */
    {
          8005,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges   */
    {
          8109,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges   */
    {
          8213,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer   */
    {
          8317,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer   */
    {
          8421,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination   */
    {
          8525,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination   */
    {
          8629,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio   */
    {
          8733,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio   */
    {
          8837,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning   */
    {
          8941,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning   */
    {
          9045,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock   */
    {
          9149,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock   */
    {
          9253,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication   */
    {
          9357,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication   */
    {
          9461,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization   */
    {
          9565,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization   */
    {
          9669,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power   */
    {
          9773,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power   */
    {
          10033,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display   */
    {
          10293,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display   */
    {
          10397,            /*   uint16 BlockBaseAddress;    */
          102,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord   */
    {
          10501,            /*   uint16 BlockBaseAddress;    */
          1026,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord   */
    {
          11529,            /*   uint16 BlockBaseAddress;    */
          1026,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc   */
    {
          12557,            /*   uint16 BlockBaseAddress;    */
          2050,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc   */
    {
          14609,            /*   uint16 BlockBaseAddress;    */
          2050,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_Group1   */
    {
          16661,            /*   uint16 BlockBaseAddress;    */
          34,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus   */
    {
          16697,            /*   uint16 BlockBaseAddress;    */
          4,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin   */
    {
          16703,            /*   uint16 BlockBaseAddress;    */
          7,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus   */
    {
          16712,            /*   uint16 BlockBaseAddress;    */
          21,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000   */
    {
          16735,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001   */
    {
          16754,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002   */
    {
          16773,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003   */
    {
          16792,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004   */
    {
          16811,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005   */
    {
          16830,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006   */
    {
          16849,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007   */
    {
          16868,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008   */
    {
          16887,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009   */
    {
          16906,            /*   uint16 BlockBaseAddress;    */
          17,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_AppInfo   */
    {
          16925,            /*   uint16 BlockBaseAddress;    */
          129,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_SWHangInfo   */
    {
          17056,            /*   uint16 BlockBaseAddress;    */
          12,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo   */
    {
          17070,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
          1,            /*   uint8  NoOfInstances;    */
          0,             /*   uint8 BlockFlags; */
          0,                       /* Device Index    */
    },
    /*  NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo   */
    {
          17330,            /*   uint16 BlockBaseAddress;    */
          258,           /*   uint16 BlockSize;      */
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
Created Time: 10/30/2025 10:39:38 PM
****************************************************************/
