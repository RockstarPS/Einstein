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
CRC_32 = 0,
CRC_16,
CRC_8,
}NvM_CrcEnumeration;

typedef enum
{
NVM_NATIVE_BLOCK = 0,
NVM_REDUNDANT_BLOCK,
NVM_DATASET_BLOCK
}NvM_BlockType;


#define NVM_CRC_BYTES           1
#define NVM_CRC_CALC_MAX_LEN    32
#define NVM_CRC_CALCULATE       Crc_CalculateCRC8


#define NVM_NUM_OF_BLOCKS    (66UL)

#define IMMEDIATE_JOB_QUEUE_SIZE 8
#define STANDARD_JOB_QUEUE_SIZE  (65UL)


#define BswMMultiBlockJobStatusInformation
#define CrcNumOfBytes
#define NVM_DATASET_SELECTION_BITS        0
#define NVM_WRITE_VERIFICATION_DATASIZE   (2576UL)
#define DrvModeSwitch
#define JobPrioritization
#define MultiBlockCallback
#define PollingMode
#define SetRamBlockStatusApi
#define SizeImmediateJobQueue
#define SizeStandardJobQueue
#define VersionInfoApi
#define WriteVerification

#define MEMIF_FEE   0
#define MEMIF_EA    1
#define MEMIF_SNVM    2

#define NvMConf___MultiBlockRequest                     (0UL)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock       (1UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Magic_Flag       (2UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FBL_Validity_Flag       (3UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FBL_Switch_RoleBackFlag       (4UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FBL_OTA_Magic_Flag       (5UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FBL_FOTA_Status       (6UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Chimes       (7UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Config       (8UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Diagnostics       (9UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EOL       (10UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FuelGauge       (11UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Illumination       (12UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_IOD       (13UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer       (14UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TripComputer       (15UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Personalization       (16UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Health_Management       (17UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Health_Management2       (18UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cybersecurity       (19UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_GaugeFuel       (20UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_FOTA_Signature       (21UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_UpdateState       (22UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_PartitionStates       (23UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_PartitionValidities       (24UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_PartitionRevisions       (25UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_ModuleStates       (26UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_ModuleValidities       (27UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_ModuleRevisions       (28UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_RegionStates       (29UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_RegionEraseAddresses       (30UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_SegmentAttributes       (31UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_SegmentWriteAddresses       (32UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_SegmentCount       (33UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_ResumeInfo       (34UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_RegionPartitionId       (35UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_SegmentPartitionId       (36UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffModuleStates       (37UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffModuleValidities       (38UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffRegionStates       (39UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffRegionEraseAddresses       (40UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffSegmentAttributes       (41UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffSegmentWriteAddresses       (42UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vSwUpdM_Appl_DiffSegmentCount       (43UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vStreamProc_DiffUpdWindRiver_Appl_ResumeAddress       (44UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vStreamProc_DiffUpdWindRiver_Appl_StateDataLen       (45UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_vStreamProc_DiffUpdWindRiver_Appl_StateData       (46UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0       (47UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_1       (48UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_2       (49UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_3       (50UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin       (51UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus       (52UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000       (53UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001       (54UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002       (55UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003       (56UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004       (57UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005       (58UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CddOsph_CddOsphChannel_00       (59UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CddOsph_CddOsphChannel_01       (60UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CddOsph_CddOsphChannel_02       (61UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CddOsoh_Data       (62UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy1       (63UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Config_Copy2       (64UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy1       (65UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Illumination_Copy2       (66UL)
/* NvM Block specific Configuration */
typedef struct
{
  void (*InitCallback) (void);
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
/* Tool Version - V2.2.8  */
/****************************************************************
Created Time: 1/4/2022 1:33:53 PM
****************************************************************/
