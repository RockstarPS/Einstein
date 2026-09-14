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


#define NVM_CRC_BYTES                            1U
#define NVM_CRC_CALC_MAX_LEN                     32U
#define NVM_CRC_CALCULATE                        Crc_CalculateCRC8


#define NVM_NUM_OF_BLOCKS                        (133UL)


#define NVM_TRESHOLD_JOB_PRIORITY                10U

#define NVM_NUM_OF_PRIORITY                      4U

#define NVM_MAX_JOB_PRIORITY                     32U

#define NUM_OF_PRIO_0_BLOCKS                     21U

#define NUM_OF_PRIO_8_BLOCKS                     1U

#define NUM_OF_PRIO_9_BLOCKS                     3U

#define NUM_OF_PRIO_16_BLOCKS                     107U

#define BswMMultiBlockJobStatusInformation
#define CrcNumOfBytes
#define NVM_DATASET_SELECTION_BITS               0
#define NVM_WRITE_VERIFICATION_DATASIZE          (6160UL)
#define DrvModeSwitch
#define NVM_JOB_PRIORITIZATION                    STD_ON
#define MultiBlockCallback
#define PollingMode
#define SetRamBlockStatusApi
#define VersionInfoApi
#define WriteVerification

#define MEMIF_FEE                                 0
#define MEMIF_EA                                  1
#define MEMIF_SNVM                                2

#define NvMConf___MultiBlockRequest                     (0UL)
#define NvMConf_NvMBlockDescriptor_NvMConfigBlock       (1UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblMetaData       (2UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblGeneral       (3UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartOne       (4UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartTwo       (5UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvMFblShareDataPartThree       (6UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Magic_Flag       (7UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0       (8UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RetentionBlockStatus       (9UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_2       (10UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_1       (11UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_2       (12UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_0       (13UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_2       (14UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_0       (15UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_2       (16UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTS_1       (17UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_0       (18UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSTATE_2       (19UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockSRM_1       (20UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_0       (21UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEYLC       (22UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_0       (23UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockPARAM_1       (24UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_0       (25UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockLEARN_1       (26UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_2       (27UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDL       (28UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockKEY_1       (29UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_I5CM_ID_NVM_BlockDET       (30UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_IVD_0X0250       (31UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Com_Cfg_VAR       (32UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Gamma_Adjustment_VAR       (33UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RGB_Calibration_VAR       (34UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_Adjustment_VAR       (35UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_4       (36UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RPM_Gauge_FIR_Coefficients       (37UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_1       (38UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_2       (39UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bcct_Cfg_VAR_3       (40UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_VAR       (41UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_1       (42UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Nvm_Block_Reserved_2       (43UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Hysteresis_Coolant       (44UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Bargraph_Treshold_Switch_Coolant       (45UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_EEPVersionInfo_CONST       (46UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_0       (47UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_1       (48UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Odometer_2       (49UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_VAR       (50UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_DiagCfg_CONST       (51UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST       (52UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_PartNumber_CONST       (53UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE1       (54UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE2       (55UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE3       (56UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE4       (57UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE5       (58UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE6       (59UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE7       (60UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_USER_PROFILE0       (61UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_EOL_HWCalib_CONST_1       (62UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Cluster_Settings       (63UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCoding_CONST       (64UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_VAR       (65UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Service_History_Data       (66UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DtcAgingAdminDataBlock       (67UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_VariantCodingCheck_CONST       (68UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_ServiceKey_VAR       (69UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_ServiceCfg_VAR       (70UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_1       (71UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DATE_VAR       (72UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_0       (73UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_REFUEL_Logger_VAR       (74UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_COMPONENTS_Cfg_CONST       (75UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_TANK_Variant_CONST       (76UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dev_Messages       (77UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR       (78UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_OperatingTime_VAR       (79UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_Curve_Scales_VAR       (80UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_0       (81UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_1       (82UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AC_IlluminationCfg_VAR_3       (83UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SRV_TKM_ZvCrH_TKM_ZvCrHPimTkKeyInCarNeed       (84UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SAFETY_RECORD_VAR       (85UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_0       (86UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockGfaKey_1       (87UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_0       (88UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_KsNvmBlockMisc_1       (89UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_CAN_VAR       (90UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Recorder_VAR_2       (91UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NvM_VKMS       (92UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PersistentData       (93UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_ConfigurationFingerprint_Data       (94UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemAdmin       (95UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemStatus       (96UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_000       (97UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_001       (98UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_002       (99UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_003       (100UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_004       (101UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_005       (102UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_006       (103UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_007       (104UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_008       (105UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_009       (106UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_010       (107UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_011       (108UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_012       (109UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_013       (110UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_014       (111UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_015       (112UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_016       (113UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_017       (114UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_018       (115UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_019       (116UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_020       (117UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_021       (118UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_022       (119UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_023       (120UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_024       (121UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_025       (122UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_026       (123UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_027       (124UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_028       (125UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DemPrimary_029       (126UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Dcm_86Infinitewindowtimestatus       (127UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_LogData       (128UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_NVM_BLOCK_SFD_PublicKey       (129UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag       (130UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_DIAG_AdaptationChannel_VAR_2       (131UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_WLTP_Odo_VAR       (132UL)
#define NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1       (133UL)
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

EXTERN NvM_QueueType NvM_JobQueuePriority8[NUM_OF_PRIO_8_BLOCKS];

EXTERN NvM_QueueType NvM_JobQueuePriority9[NUM_OF_PRIO_9_BLOCKS];

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
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:27 AM
****************************************************************/
