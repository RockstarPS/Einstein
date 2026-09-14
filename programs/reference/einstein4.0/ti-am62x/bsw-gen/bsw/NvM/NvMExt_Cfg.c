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

File Name        :  NvMExt_Cfg.c
Module Short Name:  NvMExt_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVMEXT_CFG_C
#define NVMEXT_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvMExt_Cfg.h"

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

const NvM_BlockIdType Phase1BlockIdList[NUM_OF_PHASE_1_BLOCKS] = 
    {
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_Group1,
    };


const uint8 Phase1SleepRetentionState[NUM_OF_PHASE_1_BLOCKS] = 
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
    };
const NvM_BlockIdType Phase2BlockIdList[NUM_OF_PHASE_2_BLOCKS] = 
    {
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus,
    };


const uint8 Phase2SleepRetentionState[NUM_OF_PHASE_2_BLOCKS] = 
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
const NvM_BlockIdType Phase3BlockIdList[NUM_OF_PHASE_3_BLOCKS] = 
    {
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc,
    };


const uint8 Phase3SleepRetentionState[NUM_OF_PHASE_3_BLOCKS] = 
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };


const NvMExt_PhaseReadConfigType NvMExt_PhaseReadConfig[NUM_OF_PHASES+1] = 
{
    {
        0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    {
        NUM_OF_PHASE_1_BLOCKS,
        NvMExt_Phase1ReadCompletionNotification,
        (uint16 *)&Phase1BlockIdList[0],
        (uint8 *)&Phase1SleepRetentionState[0],
    },
    {
        NUM_OF_PHASE_2_BLOCKS,
        NvMExt_Phase2ReadCompletionNotification,
        (uint16 *)&Phase2BlockIdList[0],
        (uint8 *)&Phase2SleepRetentionState[0],
    },
    {
        NUM_OF_PHASE_3_BLOCKS,
        NvMExt_Phase3ReadCompletionNotification,
        (uint16 *)&Phase3BlockIdList[0],
        (uint8 *)&Phase3SleepRetentionState[0],
    },
};


const NvM_BlockIdType NvMExt_MasterRetentionList[NUM_SLEEP_RETENTION_BLOCKS+1] = 
    {
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_Group1,
        0
    };


const NvMExt_MultipleBlockConfigType NvMExt_MultipleBlockConfig[NVMEXT_NUM_OF_CONFIG_SETS] = 
    {
       {
            NULL,
            NULL,
            0,
        },
    };
#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 8/24/2024 5:22:32 PM
****************************************************************/
