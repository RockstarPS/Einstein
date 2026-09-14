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
#include "Os.h"

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
    {0, I2C_PMIC,         PmicCdd_I2cEndNotification,I2C_FAST_MODE,     9, 5, 7, 0, 0},\
    {1, I2C_ADC,          Ads7142Cdd_I2cEndNotification, I2C_HIGHSPEED_MODE, 9, 5, 7, 12, 5},\
    {2, I2C_BackLight,    BacklightCdd_I2cEndNotification, I2C_FAST_MODE, 9, 5, 7, 0, 0}, \
    {3, I2C_Rtc,          RtcCdd_I2cEndNotification, I2C_FAST_MODE, 9, 5, 7, 0, 0}


const I2c_ChannelConfigType    I2c_ChannelConfig[I2C_NUMBER_OF_SW_CHANNELS] = {I2C_CHANNEL_CONFIG_PARAM};

const I2c_ConfigType  I2c_Config[I2C_NUMBER_OF_HW_CHANNELS] = {

	{
      MCU_I2C0_BLOCK,
      I2C_SLAVE_MODE | I2C_MASTER_MODE,
      I2C_MULTI_MASTER
    },

    {
      MAIN_I2C0_BLOCK,
      I2C_SLAVE_MODE | I2C_MASTER_MODE,
      I2C_MULTI_MASTER
    },

    {
      MAIN_I2C2_BLOCK,
      I2C_SLAVE_MODE | I2C_MASTER_MODE,
      I2C_MULTI_MASTER
    },
    {
      MAIN_I2C3_BLOCK,
      I2C_SLAVE_MODE | I2C_MASTER_MODE,
      I2C_MULTI_MASTER
    }
};

const I2c_FreeBusTicksType     I2c_FreeBusTicks = {10u};

const I2C_BusFreeConfType    I2C_BusFreeConf[I2C_NUMBER_OF_FREEBUS_CHANNELS] = {
    {
        I2C_PMIC,
        17,
        18,
        MCU_GPIO0_B01_Ch17,
        MCU_GPIO0_B01_Ch18,
        INSTANCE_MCU_GPIO0,
        PINMUX_DOMAIN_ID_MCU,
        gPinMux_Pmic_I2C_To_Dio_Cfg,
        gPinMux_Pmic_Dio_To_I2C_Cfg,
        gPinMux_Pmic_I2C_To_DioIn_Cfg
    },
    {
        I2C_ADC,
        26,
        27,
        Main_GPIO1_Channel_26,
        Main_GPIO1_Channel_27,
        INSTANCE_MAIN_GPIO1,
        PINMUX_DOMAIN_ID_MAIN,
        gPinMux_Adc_I2C_To_Dio_Cfg,
        gPinMux_Adc_Dio_To_I2C_Cfg,
        gPinMux_Adc_I2C_To_DioIn_Cfg
    }
};
// E11 - MCU_GPIO0_17 - SCL
// D11 - MCU_GPIO0_18 - SDA
/* PinMux configuration for I2C fo PMIC lines*/
static const Pinmux_PerCfg_t gPinMux_Pmic_Dio_To_I2C_Cfg[NO_OF_PINMUX_ENTRIES] = {

        /* MCU_I2C0 pin config */
    /* MCU_I2C0_SCL -> MCU_I2C0_SCL (E11) */
    {
        PIN_MCU_I2C0_SCL,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
        /* MCU_I2C0_SDA -> MCU_I2C0_SDA (D11) */
    {
        PIN_MCU_I2C0_SDA,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DIRECTION )
    },
    {PINMUX_END, 0U}
};

/* PinMux configuration for I2C to convert as DIO Output */
static const Pinmux_PerCfg_t gPinMux_Pmic_I2C_To_Dio_Cfg[NO_OF_PINMUX_ENTRIES] = {

        /* MCU_I2C0 pin config */
    /* MCU_I2C0_SCL -> MCU_I2C0_SCL (E11) */
    {
        PIN_MCU_I2C0_SCL,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
        /* MCU_I2C0_SDA -> MCU_I2C0_SDA (D11) */
    {
        PIN_MCU_I2C0_SDA,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
    {PINMUX_END, 0U}
};

/* PinMux configuration for I2C to convert as DIO Input*/
static const Pinmux_PerCfg_t gPinMux_Pmic_I2C_To_DioIn_Cfg[NO_OF_PINMUX_ENTRIES] = {
        /* MCU_I2C0 pin config */
    /* MCU_I2C0_SCL -> MCU_I2C0_SCL (E11) */
    {
        PIN_MCU_I2C0_SCL,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
        /* MCU_I2C0_SDA -> MCU_I2C0_SDA (D11) */
    {
        PIN_MCU_I2C0_SDA,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
    {PINMUX_END, 0U}
};
// B25 - GPIO1_26 - SCL
// A24 - GPIO1_27 - SDA
/* PinMux configuration for I2C fo ADC lines*/
static const Pinmux_PerCfg_t gPinMux_Adc_Dio_To_I2C_Cfg[NO_OF_PINMUX_ENTRIES] = {
    /* I2C0_SCL -> I2C0_SCL (B25) */
    {
        PIN_I2C0_SCL,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
    /* I2C0_SDA -> I2C0_SDA (A24) */
    {
        PIN_I2C0_SDA,
        ( PIN_MODE(0) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
    {PINMUX_END, 0U}
};

/* PinMux configuration for I2C to convert as DIO Output */
static const Pinmux_PerCfg_t gPinMux_Adc_I2C_To_Dio_Cfg[NO_OF_PINMUX_ENTRIES] = {
    /* I2C0_SCL -> I2C0_SCL (B25) */
    {
        PIN_I2C0_SCL,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
    /* I2C0_SDA -> I2C0_SDA (A24) */
    {
        PIN_I2C0_SDA,
        ( PIN_MODE(7) | PIN_PULL_DISABLE )
    },
    {PINMUX_END, 0U}
};

/* PinMux configuration for I2C to convert as DIO Input*/
static const Pinmux_PerCfg_t gPinMux_Adc_I2C_To_DioIn_Cfg[NO_OF_PINMUX_ENTRIES] = {
    /* I2C0_SCL -> I2C0_SCL (B25) */
    {
        PIN_I2C0_SCL,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
    /* I2C0_SDA -> I2C0_SDA (A24) */
    {
        PIN_I2C0_SDA,
        ( PIN_MODE(7) | PIN_INPUT_ENABLE | PIN_PULL_DISABLE )
    },
    {PINMUX_END, 0U}
};

/*****************************************************************************
*                               Functions                                    *
******************************************************************************/

void I2c_EnterCriticalSection(void)
{
    SuspendAllInterrupts();
}
void I2c_ExitCriticalSection(void)
{
    ResumeAllInterrupts();
}

void I2c_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    (void)Det_ReportError(I2C_MODULE_ID, I2C_INSTANCE_ID, ApiId, ErrorId);
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

void BacklightCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
    (void)sequence;
    (void)busstate;
    (void)sequencestate;
}

void RtcCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate)
{
    (void)sequence;
    (void)busstate;
    (void)sequencestate;
}
#endif /* callbackcode */

#endif
