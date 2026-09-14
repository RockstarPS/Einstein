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
 * @file        I2c_Cfg.h
 * @details     <b>TI Mcal driver for i2c</b>
 * @note
 *              Compiler    : clang \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2024
 *
 */
#ifndef I2C_CFG_H
#define I2C_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Std_Types.h"
#include "I2c_Types.h"
#include "OsMain.h"
#include "Det.h"
#include "pinmux.h"
#include "Port.h"
#include "Dio.h"

/* Timeout = Main Function Periodicity x I2C_STOP_TIMEOUT_COUNT
If the I2c_MainFunction() Periodicity is 10ms, then to achieve the 100ms timeout, the I2C_STOP_TIMEOUT_COUNT needs to be configured as 10 */
#define I2C_STOP_TIMEOUT_COUNT  200U

/* Bus Busy Timeout - TBD by the User/Application on the timeout value */
/* Timeout count now is keep as per the Main Function periodicity */
#define I2C_BUSBUSY_TIMEOUT_COUNT 200u

#ifdef RTCCDD_ENABLE
    #define I2C_NUMBER_OF_HW_CHANNELS   4U
    #define I2C_NUMBER_OF_SW_CHANNELS   4U
#else
    #define I2C_NUMBER_OF_HW_CHANNELS   3U
    #define I2C_NUMBER_OF_SW_CHANNELS   3U
#endif


#define I2C_NUMBER_OF_FREEBUS_CHANNELS  2U
#define I2C_FREEBUS_CLK_EDGES  9U

/* hw units */
#define I2C_GMSL     0u
#define I2C_PMIC     1u
#define I2C_DAC      2u
#define I2C_RTC      3u

typedef enum
{
    I2C_STANDARD_MODE = 100000,
    I2C_FAST_MODE = 400000,
} I2C_TransferModeType;

/* End Notification for sequeunce */
typedef void (*I2C_EndNotificationCallbackType)(uint8 sequence, uint8 busstate, uint8 sequencestate);
/* I2c SW Channel Configuration */
typedef struct
{
    /* I2c Sequence Priority */
    uint8 SeqPriority;
    /* I2c Hw unit associated */
    uint8 HwUnit;
    /* End notification Function Call */
    I2C_EndNotificationCallbackType   I2C_EndNotificationCallback;
    /* I2C Mode to be configured */
    I2C_TransferModeType TransferMode;
    /* Prescaler value for selected OPMODE */
    uint8 psc;
    /* High Phase Over Sampling Value for Clock generation */
    uint8 sclh;
    /* Low Phase Over Sampling Value for Clock generation */
    uint8 scll;
} I2c_ChannelConfigType;

#define callbackcode

#ifdef callbackcode
void Client_I2CEndNotification2(uint8 sequence, uint8 busstate, uint8 sequencestate);
void Client_I2CEndNotification1(uint8 sequence, uint8 busstate, uint8 sequencestate);

#endif

extern void IoExp_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);
extern void PmicCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);
extern void RtcCdd_I2cEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);
extern void DAC_I2CEndNotification(uint8 sequence, uint8 busstate, uint8 sequencestate);
typedef struct
{
    /* SCB Base Address*/
    I2c_RegisterPtrType BaseAddress;
    uint32 I2C_Mode;
    /* Configure Multi Master or Single Master */
    uint8  MasterSetting;
} I2c_ConfigType;

typedef struct
{
    /* I2c Hw unit associated */
    uint8 HwUnit;
    /* Port Pin number of I2C SCL */
    uint32 I2C_PortPinScl;
    /* Port Pin number of I2C SDA */
    uint32 I2C_PortPinSda;
    /* Dio Channel number of I2C SCL */
    Dio_ChannelType I2C_DioPinScl;
    /* Dio Channel number of I2C SDA */
    Dio_ChannelType I2C_DioPinSda; 
    /* Port Instance to which I2C belongs*/
    uint32 Instance;
    /* Pinmux Instance in Sysconfig */
    uint32 PinmuxInstance;
    /* PinMux configuration to convert I2C to Dio Out */
    Pinmux_PerCfg_t *PinMux_I2C_To_DioOut_Cfg;
    /* Pinmux configuration to convert Dio to I2C */
    Pinmux_PerCfg_t *PinMux_Dio_To_I2C_Cfg;
    /* PinMux configuration to convert I2C to Dio In */
    Pinmux_PerCfg_t *PinMux_I2C_To_DioIn_Cfg;
} I2C_BusFreeConfType;

/* Baud rate - 400KHz -> So the time for half cycle is 1.25us. The bus free 'for loop' atleast takes 1.25instuctions */
/* eg: 240Mhz Core Clock Ticks =  1.25(x) = (1.25us * 240MHz) -> here 'x' will give your ticks to be used */
/* The clock freq generated for this free bus sequence should be made sure that it doesn't exceed the 
set baud rate */
typedef struct
{
    uint16 Freebus_IdleTicks;
} I2c_FreeBusTicksType;


extern const I2c_ConfigType           I2c_Config[I2C_NUMBER_OF_HW_CHANNELS];
extern const I2c_ChannelConfigType    I2c_ChannelConfig[I2C_NUMBER_OF_SW_CHANNELS];
extern const I2C_BusFreeConfType    I2C_BusFreeConf[I2C_NUMBER_OF_FREEBUS_CHANNELS];
extern const I2c_FreeBusTicksType    I2c_FreeBusTicks;
extern const Pinmux_PerCfg_t gPinMux_Pmic_Dio_To_I2C_Cfg[];
extern const Pinmux_PerCfg_t gPinMux_Pmic_I2C_To_Dio_Cfg[];
extern const Pinmux_PerCfg_t gPinMux_Pmic_I2C_To_DioIn_Cfg[];
extern const Pinmux_PerCfg_t gPinMux_IoExp_Dio_To_I2C_Cfg[];
extern const Pinmux_PerCfg_t gPinMux_IoExp_I2C_To_Dio_Cfg[];
extern const Pinmux_PerCfg_t gPinMux_IoExp_I2C_To_DioIn_Cfg[];
/*****************************************************************************
*                               Functions                                    *
******************************************************************************/
extern void I2c_EnterCriticalSection(void);
extern void I2c_ExitCriticalSection(void);

void I2c_Det_ReportError(uint8 ApiId, uint8 ErrorId);

#endif

