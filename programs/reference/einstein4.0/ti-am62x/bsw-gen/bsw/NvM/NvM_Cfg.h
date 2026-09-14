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

File Name        :  NvM_Cfg.h
Module Short Name:  NvM_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVM_CFG_H
#define NVM_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "NvM_Types.h"
#include "Crc.h"
#include "AssertLib.h"
#include "Stubs.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#ifndef NVM_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif

#ifdef __ghs__
#pragma alignvar (8)
#endif
extern uint8 NvMConfigBlock_RamBlock_au8[8];
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


typedef enum
{
CRC_32 = 0u,
CRC_16,
CRC_8,
}NvM_CrcEnumeration;

typedef enum
{
NVM_NATIVE_BLOCK = 0u,
NVM_REDUNDANT_BLOCK,
NVM_DATASET_BLOCK
}NvM_BlockType;


#define NVM_DEBUG_ERROR(x)                       DEBUG_ASSERT(x)
#define NVM_CRC_BYTES                            1U
#define NVM_CRC_CALC_MAX_LEN                     32U
#define NVM_CRC_CALCULATE                        Crc_CalculateCRC8


#define NVM_NUM_OF_BLOCKS                        (72UL)


#define NVM_TRESHOLD_JOB_PRIORITY                10U

#define NVM_NUM_OF_PRIORITY                      2U

#define NVM_MAX_JOB_PRIORITY                     32U

#define NUM_OF_PRIO_0_BLOCKS                     1UL

#define NUM_OF_PRIO_16_BLOCKS                     70UL

#define BswMMultiBlockJobStatusInformation
#define CrcNumOfBytes
#define NVM_DATASET_SELECTION_BITS               0
#define NVM_WRITE_VERIFICATION_DATASIZE          (2064UL)
#define DrvModeSwitch
#define NVM_JOB_PRIORITIZATION                    STD_ON
#define MultiBlockCallback
#define PollingMode
#define SetRamBlockStatusApi
#define VersionInfoApi
#define WriteVerification

#define MEMIF_FEE                                 0U
#define MEMIF_EA                                  1U
#define MEMIF_SNVM                                2U

#define NvMConf___MultiBlockRequest                     (0UL)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock       (1UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash       (2UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode       (3UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint       (4UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus       (5UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt       (6UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber       (7UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet       (8UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig       (9UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge       (10UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge       (11UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge       (12UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge       (13UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge       (14UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge       (15UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer       (16UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination       (17UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1       (18UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2       (19UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio       (20UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning       (21UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock       (22UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication       (23UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power       (24UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder       (25UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer       (26UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate       (27UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate       (28UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1       (29UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer       (30UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge       (31UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge       (32UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge       (33UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge       (34UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge       (35UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge       (36UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer       (37UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning       (38UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock       (39UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization       (40UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination       (41UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt       (42UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer       (43UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges       (44UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer       (45UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination       (46UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio       (47UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning       (48UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock       (49UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication       (50UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization       (51UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power       (52UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display       (53UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord       (54UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc       (55UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_Group1       (56UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus       (57UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin       (58UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus       (59UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000       (60UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001       (61UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002       (62UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003       (63UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004       (64UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005       (65UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006       (66UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007       (67UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008       (68UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009       (69UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_AppInfo       (70UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_SWHangInfo       (71UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DltExt_ResetInfo       (72UL)
/* NvM Block specific Configuration */
typedef struct
{
  Std_ReturnType (*InitCallback) (void);
  Std_ReturnType (*SingleBlockCallback)(uint8,NvM_RequestResultType);
  uint8*    RamBlockDataAddress;
  uint8*    RomBlockDataAddress;
  uint16    NvBlockBaseNumber;
  uint16    NvBlockLength;
  uint16    NvRamBlockIdentifier;
  uint8     BlockJobPriority;
  uint8     MaxNumReadRetries;
  uint8     MaxNumWriteRetries;
  uint8     NvBlockNum;
  uint8     NvRamDeviceId;
  uint8     RomBlockNum;
  NvM_CrcEnumeration BlockCrcType;
  NvM_BlockType BlockManagementType;
  boolean   BlockUseCrc;
  boolean   BlockUseSetRamBlockStatus;
  boolean BlockWriteProt;
  boolean   BswMBlockStatusInformation;
  boolean   CalcRamBlockCrc;
  boolean   SelectBlockForReadAll;
  boolean   SelectBlockForWriteAll;
  boolean   WriteBlockOnce;
}NvM_BlockDescriptorType;

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

EXTERN const NvM_BlockDescriptorType NvM_BlockConfig[NVM_NUM_OF_BLOCKS+1];

EXTERN NvM_StandardQueueType NvM_JobQueueParameter[NVM_NUM_OF_PRIORITY];

EXTERN const NvM_JobQueueManagementType NvM_JobQueueManagementTable[NVM_MAX_JOB_PRIORITY];

EXTERN NvM_QueueType NvM_JobQueuePriority0[NUM_OF_PRIO_0_BLOCKS];
EXTERN NvM_QueueType NvM_JobQueuePriority16[NUM_OF_PRIO_16_BLOCKS];

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

EXTERN void NvM_EnterCriticalSection(void);

EXTERN void NvM_ExitCriticalSection(void);

#undef EXTERN

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 10/30/2025 10:39:38 PM
****************************************************************/
