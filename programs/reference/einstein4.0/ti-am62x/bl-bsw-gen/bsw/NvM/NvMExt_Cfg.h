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

File Name        :  NvMExt_Cfg.h
Module Short Name:  NvMExt_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVMEXT_CFG_H
#define NVMEXT_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "NvM.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define NUM_OF_PHASE_1_BLOCKS         9U

#define NUM_OF_PHASE_2_BLOCKS         4U

#define NUM_OF_PHASE_3_BLOCKS         15U


#define NUM_SLEEP_RETENTION_BLOCKS        0U

#define NUM_OF_PHASES                     3U
#define NVMEXT_NUM_OF_MULTIPLE_BLOCKS   0
#define NVMEXT_NUM_OF_CONFIG_SETS		NVMEXT_NUM_OF_MULTIPLE_BLOCKS + 1

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef void (*PhaseNotifyFuncRefType)(uint8 Status);

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

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

typedef struct
{
    uint16 NoOfBlocks;
    PhaseNotifyFuncRefType PhaseCallout;
    uint16 *BlockIdListPtr;
    uint8 *RetentionStatePtr;
}NvMExt_PhaseReadConfigType;


extern const NvM_BlockIdType Phase1BlockId[NUM_OF_PHASE_1_BLOCKS];


extern const uint8 Phase1SleepRetentionState[NUM_OF_PHASE_1_BLOCKS];


extern const NvM_BlockIdType Phase2BlockId[NUM_OF_PHASE_2_BLOCKS];


extern const uint8 Phase2SleepRetentionState[NUM_OF_PHASE_2_BLOCKS];


extern const NvM_BlockIdType Phase3BlockId[NUM_OF_PHASE_3_BLOCKS];


extern const uint8 Phase3SleepRetentionState[NUM_OF_PHASE_3_BLOCKS];




extern void NvMExt_Phase1ReadCompletionNotification(uint8 Status);
extern void NvMExt_Phase2ReadCompletionNotification(uint8 Status);
extern void NvMExt_Phase3ReadCompletionNotification(uint8 Status);




extern const NvM_BlockIdType NvMExt_MasterRetentionList[NUM_SLEEP_RETENTION_BLOCKS+1];

extern const NvMExt_PhaseReadConfigType NvMExt_PhaseReadConfig[NUM_OF_PHASES+1];



typedef struct
{
    uint32 *RamBufferArray;
    uint16 *MultipleCopiesIndexBuffer;
    uint8 NumberOfCopies;
    Std_ReturnType (*BlockCallback)(uint8,NvM_RequestResultType);
    uint16 Length;
}NvMExt_MultipleBlockConfigType;

extern const NvMExt_MultipleBlockConfigType NvMExt_MultipleBlockConfig[NVMEXT_NUM_OF_CONFIG_SETS];
#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 11-04-2024 19:36:22
****************************************************************/
