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

File Name        :  Icu_Cfg.c
Module Short Name:  Icu
VOBName          :  
Author           :  kporkodi
Description      :  This file contains configurations needed for Icu module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/
#ifndef ICU_CFG_C
#define ICU_CFG_C

#include "Icu_Cfg.h"
#include "Icu.h"
#include "Det.h"

/*****************************************************************************
*                      Globally  accessed Variable Declarations              *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/* ICU channel configuration */
const Icu_ChannelConfigType Icu_ChannelConfigArray[ICU_CHANNEL_COUNT] = 
{
    {
        0, 
        0,
        CSL_MCU_GPIO0_BASE, 
        ICU_FALLING_EDGE, 
        ICU_MODE_SIGNAL_EDGE_DETECT,
        PmicCdd_nINTGpioInt
    }
};

/* ICU configuration */
const Icu_ConfigType Icu_Config = {
    Icu_ChannelConfigArray,  /* Pointer to channel configurations */
    ICU_CHANNEL_COUNT        /* Number of channels */
};

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void Icu_ReportError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError(ICU_MODULE_ID,ICU_INSTANCE_ID, ApiId, ErrorId);
}


#endif /* ICU_CFG_C */

/*****************************************************************************
*     End of File
*
******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 19-11-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Proveout, Initial Version                             */
/*--------------------------------------------------------------------------*/

/**-------------------------------------------------------------------------*/
/*Date              : 02-12-2024                                            */
/*Version           :                                                       */
/*By                : kporkodi                                              */
/*Traceability      :                                                       */
/*Change Description: Initial Version Platform Release                      */
/*--------------------------------------------------------------------------*/
