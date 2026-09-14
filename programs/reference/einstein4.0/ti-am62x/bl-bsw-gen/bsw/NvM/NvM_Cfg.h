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


#define NVM_NUM_OF_BLOCKS                        (61UL)


#define NVM_TRESHOLD_JOB_PRIORITY                10U

#define NVM_NUM_OF_PRIORITY                      1U

#define NVM_MAX_JOB_PRIORITY                     32U

#define NUM_OF_PRIO_16_BLOCKS                     60UL

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
Created Time: 11-04-2024 19:36:22
****************************************************************/
