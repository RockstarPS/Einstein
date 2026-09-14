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

File Name        :  NvMDefault_Cfg.h
Module Short Name:  NvMDefault_Cfg.h
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef NVMDEFAULT_CFG_H
#define NVMDEFAULT_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "General_Cfg.h"
#include "Std_Types.h"

#define NUM_OF_NVM_BLOCKS       95


typedef struct
{
    uint16    BlockID;
    uint8*    RamAddress[NUM_OF_VARIANT];
}NvM_BlockListType;


extern const NvM_BlockListType NvM_BlockList[NUM_OF_NVM_BLOCKS];


#endif    /* */
/* end of file */
/*Tool Version Information*/
/* SREC Tool Version - v2.0.0 */
/****************************************************************
Created Time: 8/18/2022 8:38:19 PM
****************************************************************/
