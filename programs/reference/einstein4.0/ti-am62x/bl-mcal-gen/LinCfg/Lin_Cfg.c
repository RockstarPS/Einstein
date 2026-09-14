/******************************************************************************
**              CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2024. Visteon Corporation owns all rights to this work and
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

File Name        :  Lin_Cfg.c
Module Short Name:  Lin_Cfg.c
VOBName          :  
Author           :  mhishamu
Description      :  This file contains configurations needed for Lin module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef LIN_CFG_C
#define LIN_CFG_C

/*****************************************************************************
*                               Include files                                *
******************************************************************************/

#include "Lin_Cfg.h"

/*****************************************************************************
*                              Global Variables                              *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

Lin_ChannelInfoType Lin_ChannelInfo[LIN_NUM_OF_CHANNELS];

const Lin_ChannelConfigType Lin_ChannelConfig[LIN_NUM_OF_CHANNELS] =
{
    {
        19200,
        0,
        FALSE,
        0,
        0,
        13,
        0
    }
};

const Lin_ConfigType Lin_Config =
{
    &Lin_ChannelConfig[0],
    LIN_NUM_OF_CHANNELS,
    0
};

/*****************************************************************************
*                                 Global Functions                           *
******************************************************************************/

void Lin_UartIf_RxIndication_0(ESciDrvChnResult ReceiveResult, uint32 SciBytesReceived, uint32 SciExtraBytesReceived)
{
    Lin_UartIf_RxIndication(0, ReceiveResult, SciBytesReceived, SciExtraBytesReceived);
}

#endif /* LIN_CFG_C */

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : -05-2024                                              */
/*Version           :                                                       */
/*By                : mhishamu                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/