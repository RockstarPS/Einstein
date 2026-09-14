/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2024. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        I2c_Cfg.c
 * @details     <b>TI Mcal driver for i2c</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef I2C_CFG_C
#define I2C_CFG_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "I2c_Cfg.h"

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*
I2C_CHANNEL_CONFIG_PARAM : {Priority , Hardware Unit , Callback Function}
1.	Priority          – This number indicates the priority of this sequence/channel. The lower the number, the higher the priority.
2.	Hardware Unit     – This index shall mention the hardware unit to be used for this channel/sequence.
                        This shall point to the index of I2C_CONFIG_PARAM.
3.	Callback Function – The Function pointer of the callback notification function needs to be invoked to
                        update the success/error status upon completion of data transmission/reception.

*/
#define I2C_CHANNEL_CONFIG_PARAM \
    {0, I2C_GMSL,         Client_I2CEndNotification1, I2C_STANDARD_MODE, 23, 15, 13},    \
	{1, I2C_GMSL,         Client_I2CEndNotification2, I2C_STANDARD_MODE, 23, 15, 13}

const I2c_ChannelConfigType    I2c_ChannelConfig[I2C_NUMBER_OF_SW_CHANNELS] = {I2C_CHANNEL_CONFIG_PARAM};

const I2c_ConfigType  I2c_Config[I2C_NUMBER_OF_HW_CHANNELS] = {
    {
      MCU_I2C0_BLOCK,
      I2C_SLAVE_MODE | I2C_MASTER_MODE,
      I2C_MULTI_MASTER
    }
};

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void I2c_EnterCriticalSection(void)
{
    osSuspendAllInterrupts();
}
void I2c_ExitCriticalSection(void)
{
    osResumeAllInterrupts();
}


#ifdef callbackcode

static volatile uint8 notification_complete = 0;

void Client_I2CEndNotification1(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
    /* update the application required scenario */
    notification_complete++;
}

void Client_I2CEndNotification2(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
    /* update the application required scenario */
    notification_complete++;
}

#endif /* callbackcode */

#endif

