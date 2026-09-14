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

File Name        :  Fee_Cfg.h
Module Short Name:  Fee_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef FEE_CFG_H
#define FEE_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Fee_Types.h"
#include "Fls.h"
#include "NvM_Cbk.h"
#include "FeeExt.h"
#include "AssertLib.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef FEE_CFG_C
#define EXTERN extern
#else
#define EXTERN
#endif


EXTERN void NvM_Memif_Internal_Notification(uint8 status);


#define FEE_NVM_JOB_END_NOTIFICATION()               NvM_JobEndNotification()
#define FEE_NVM_JOB_ERROR_NOTIFICATION()             NvM_JobErrorNotification()
#define FEE_NVM_INTERNAL_NOTIFICATION(x)             NvM_Memif_Internal_Notification(x)
#define FEE_DEBUG_ERROR(x)                           DEBUG_ASSERT(x)


#define FLS_WRITE(x,y,z)                         FeeExt_Write(x,y,z)
#define FLS_READ(x,y,z)                          FeeExt_Read(x,y,z)
#define FLS_GET_JOB_RESULT()                     FeeExt_GetJobResult()
#define FLS_ERASE(x,y)                           FeeExt_Erase(x,y)
#define FLS_CANCEL()                             FeeExt_Cancel()
#define FLS_READ_WITHOUT_BLANKCHECK(x,y,z)       FeeExt_ReadImmediate(x,y,z)
#define FLS_BLANK_CHECK(x,y)                      FeeExt_BlankCheck(x,y)

#define FEE_BACKGROUND_SECTORSWITCH              STD_ON

#define FEE_NUM_BLOCKS          18UL
#define FEE_NUM_PARTITIONS      1U
#define FEE_MAX_LENGTH          4116UL
#define FEE_SECTOR_HEADER_SIZE  8U
#define FEE_SECTOR_FOOTER_SIZE  8U
#define FEE_HEADER_SIZE         8U
#define FEE_NUM_OF_SECTORS      2U

#define FEE_RELOAD_TIMER        0U
#define FEE_TIMER_WAIT_TIME     1U

#define FEE_RESET_INFO_BLOCK_LEN 8U
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct  
{
  uint16 BlockNumber;
  uint16 BlockSize;
  uint8  PartitionNo;
  boolean ImmediateData;
}Fee_BlockConfigType;


typedef struct  
{
  uint32 SectorStartAddress;
  uint16 SectorSize;
}Fee_SectorConfigType;


typedef struct  
{
  uint32 SectorStartAddress;
  uint16 SectorSize;
  uint32 BackupSectorAddress;
  uint16 BackupSectorSize;
}Fee_ResetSectorConfigType;


typedef struct  
{
  uint8 StartingSectorId;
  uint8  NumberOfSectors;
  boolean BackgroundSectorSwitch;
  uint16  MaxLength;
}Fee_PartitionConfigType;



/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
EXTERN const Fee_BlockConfigType Fee_BlockConfig[FEE_NUM_BLOCKS];

EXTERN const Fee_PartitionConfigType Fee_PartitionConfig[FEE_NUM_PARTITIONS];

EXTERN const Fee_SectorConfigType Fee_SectorConfig[FEE_NUM_OF_SECTORS];

EXTERN const Fee_ResetSectorConfigType Fee_InternalSectorConfig;
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
#undef EXTERN

#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.16 */
/****************************************************************
Created Time: 6/21/2024 3:57:49 PM
****************************************************************/
