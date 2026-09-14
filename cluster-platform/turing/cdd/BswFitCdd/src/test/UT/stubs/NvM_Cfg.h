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
//#include "Crc.h"

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


#define NVM_NUM_OF_BLOCKS    (63UL)

#define IMMEDIATE_JOB_QUEUE_SIZE 8
#define STANDARD_JOB_QUEUE_SIZE  (62UL)


#define BswMMultiBlockJobStatusInformation
#define CrcNumOfBytes
#define NVM_DATASET_SELECTION_BITS        0
#define NVM_WRITE_VERIFICATION_DATASIZE   (158UL)
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

#define NvMConf___MultiBlockRequest                     (0UL)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock       (1UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_GaugeData       (2UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ChimeData       (3UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TCData       (4UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackupData       (5UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup1Data       (6UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup2Data       (7UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup3Data       (8UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup4Data       (9UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup5Data       (10UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup7Data       (11UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup6Data       (12UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup8Data       (13UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup10Data       (14UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup9Data       (15UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup12Data       (16UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup11Data       (17UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup13Data       (18UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup14Data       (19UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup15Data       (20UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ODOBackup16Data       (21UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TripData       (22UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OatData       (23UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DimData       (24UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_AEEData       (25UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DeltaReProData       (26UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ExternalDiagData       (27UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SDMData       (28UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_LINCOMMData       (29UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SelfDiagData       (30UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DiagnosticServiceData       (31UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DiagnosticServicePartNumberData       (32UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DiagnosticServiceManufacturingData       (33UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_UnknownComponentData       (34UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin       (35UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus       (36UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000       (37UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001       (38UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002       (39UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003       (40UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004       (41UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005       (42UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006       (43UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007       (44UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008       (45UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009       (46UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_010       (47UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_011       (48UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_012       (49UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_013       (50UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_014       (51UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_015       (52UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_016       (53UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_017       (54UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_018       (55UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_019       (56UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_020       (57UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CustomizeSettingData       (58UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_UserCustomizeSettingData       (59UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_AVSData       (60UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ElapsedTimeData       (61UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecurityAccessData       (62UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dcm_86Infinitewindowtimestatus       (63UL)
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
/****************************************************************
Created Time: 10/29/2020 2:30:36 AM
****************************************************************/
