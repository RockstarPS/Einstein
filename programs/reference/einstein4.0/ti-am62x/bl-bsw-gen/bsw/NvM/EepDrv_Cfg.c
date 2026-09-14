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

File Name        :  EepDrv_Cfg.c
Module Short Name:  EepDrv_Cfg.c
VOBName          :  
Author           :  
Description      :  Generated File
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef EEPDRV_CFG_C
#define EEPDRV_CFG_C
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EepDrv_Cfg.h"
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

const Eep_DeviceConfigType Eep_DeviceConfig[EEP_NUMBER_OF_DEVICES_SUPPORTED]=
{
    {
        0,      /*ReadSequenceId*/
        0,      /*WriteSequenceId*/
        0,      /*ReadChannel*/
        0,      /*Writechannel*/
        BIG_EEPROM,      /*ChipType*/
        (uint8)0x00,      /*SlaveAddress*/
        (uint8)0xFF,      /*EraseValue*/
        32,      /*ReadBlockSize*/
        32,      /*WriteBlockSize*/
        32,      /*ChipPageSize*/
        35,      /*BufferSize*/
        2,      /*AddressBufferSize*/
        2,      /*BuffStartDataIndex*/
        SPI_EEPROM,      /*Memory Interface Type*/
        32768U,      /*MemorySize*/
        0,      /*BaseAddress*/
        5,      /*Device Timeout*/
    },
};








#endif    /* */
/* end of file */
/*Tool Version Information*/
/* Tool Version - v2.2.17 */
/****************************************************************
Created Time: 11-04-2024 19:36:22
****************************************************************/
