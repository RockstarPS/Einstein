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
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag,
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_SecDiag_1,
    };


const uint8 Phase1SleepRetentionState[NUM_OF_PHASE_1_BLOCKS] = 
    {
        1,
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
};


const NvM_BlockIdType NvMExt_MasterRetentionList[NUM_SLEEP_RETENTION_BLOCKS+1] = 
    {
        NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_Retention_RAM_Gp_0,
        0
    };


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.11 */
/****************************************************************
Created Time: 6/28/2022 10:03:02 AM
****************************************************************/
