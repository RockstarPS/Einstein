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

File Name        :  IoExp_Cfg.h
Module Short Name:  IoExp_Cfg.h
VOBName          :  
Author           :  GTHANAPP
Description      :  This file contains configurations needed for ExtIO module
Organization     :  Driver Information Software Section,
                    Visteon Corporation

******************************************************************************/

#ifndef IOEXP_CFG_H
#define IOEXP_CFG_H
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "Std_Types.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define IOEXP_I2C_CHANNELID             0u

#define IOEXP_NUM_OF_DEVICES            2u


#define IOEXP_NUM_OF_DI_PINS            0u
#define IOEXP_NUM_OF_DO_PINS            8u
#define IOEXP_NUM_OF_AI_PINS            5u

#define IOEXP_I2CSEQUENCE               0u

#define IOEXP_TOTAL_PIN_CONFIGURED       (IOEXP_NUM_OF_DI_PINS + IOEXP_NUM_OF_DO_PINS + IOEXP_NUM_OF_AI_PINS)

#define IOEXP_DEV_ERROR_DETECT          STD_ON



/*PIN Numbers - The pin number is the software channel. Note the following points
1. If all channels are AIN/DIN/DOUT then continou number will the sw channel Id
2. If 4 - DIN, 4 - DOUT , 8 - AIN, (considering 2 device) then each DIN, DOUT and AIN starts with 0
Ex: #define IOEXP_PIN1_GPIO_DIN   0u
    #define IOEXP_PIN2_GPIO_DIN   1u 
    #define IOEXP_PIN3_GPIO_DIN   3u
    #define IOEXP_PIN4_GPIO_DIN   4u
    
    #define IOEXP_PIN5_GPIO_DOUT   0u
    #define IOEXP_PIN6_GPIO_DOUT   1u...etc
    
    #define IOEXP_PIN1_GPIO_ADC     0u
    #define IOEXP_PIN2_GPIO_ADC     1u...etc           */


//#define IOEXP_AI_MAIN_PWB_TEMP           0u
#define IOEXP_AI_TFT_LED_TEMP            0u
#define IOEXP_AI_FALD_BL_TEMP            1u
//#define IOEXP_AI_VBATT_MON               3u
#define IOEXP_AI_30V0_BL_PWR_UC          2u
#define IOEXP_AI_CABLE_DEATECT_TT        3u
#define IOEXP_AI_SBATT2_MON              4u
//#define IOEXP_AI_SOC_TEMP_SENS3          7u

#define IOEXP_DIO_ADC_GPIO_08            0u
#define IOEXP_DIO_ADC_GPIO_09            1u
#define IOEXP_DIO_ADC_GPIO_10            2u
#define IOEXP_DIO_ADC_GPIO_11            3u
#define IOEXP_DIO_ADC_GPIO_12            4u
#define IOEXP_DIO_ADC_GPIO_13            5u
#define IOEXP_DIO_ADC_GPIO_14            6u
#define IOEXP_DIO_ADC_GPIO_15            7u

#define IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM 1u

#define IOEXP_ADC_CONF_GROUP_ID   IoExp_AdcConf_AdcGroupId_AdcGroup_ANA_COM
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    PUSH_PULL = 0,
    OPEN_DRAIN,
}IoExp_DoutDriveType;

typedef struct
{
    uint8 SW_ChannelID;             /* SW Channel ID */
    uint8 HW_ChannelID;             /* HW pin connected */
    uint8 DeviceIndex;              /* Device Index */
}IoExp_DInConfigType;

typedef struct
{
    uint8 SW_ChannelID;             /* SW Channel ID */
    uint8 HW_ChannelID;             /* HW pin connected */
    uint8 DeviceIndex;              /* Device Index */
    IoExp_DoutDriveType DriveType;  /* GPO Drive Type */
    uint8 DefaultPinState;          /* Default GPO Pin Level */
}IoExp_DOutConfigType;

typedef struct
{
    uint8 SW_ChannelID;             /* SW Channel ID */
    uint8 HW_ChannelID;             /* HW pin connected */
    uint8 DeviceIndex;              /* Device Index */
}IoExp_AInConfigType;


/*****************************************************************************
*                                 Macro Declarations                          *
******************************************************************************/

#if IOEXP_NUM_OF_DI_PINS > 0u
    #define IOEXP_NUM_OF_DI_PINS_CFG_COUNT      IOEXP_NUM_OF_DI_PINS
#else
    #define IOEXP_NUM_OF_DI_PINS_CFG_COUNT      1u
#endif

#if IOEXP_NUM_OF_DO_PINS > 0u
    #define IOEXP_NUM_OF_DO_PINS_CFG_COUNT      IOEXP_NUM_OF_DO_PINS
#else
    #define IOEXP_NUM_OF_DO_PINS_CFG_COUNT      1u
#endif

#if IOEXP_NUM_OF_AI_PINS > 0u
    #define IOEXP_NUM_OF_AI_PINS_CFG_COUNT      IOEXP_NUM_OF_AI_PINS
#else
    #define IOEXP_NUM_OF_AI_PINS_CFG_COUNT      1u
#endif

extern const IoExp_DInConfigType IoExp_DInConfig[IOEXP_NUM_OF_DI_PINS_CFG_COUNT];
extern const IoExp_DOutConfigType IoExp_DOutConfig[IOEXP_NUM_OF_DO_PINS_CFG_COUNT];
extern const IoExp_AInConfigType IoExp_AInConfig[IOEXP_NUM_OF_AI_PINS_CFG_COUNT];

extern const uint8 IOEXP_I2C_DeviceAddress[IOEXP_NUM_OF_DEVICES];

extern void IoExp_Det_ReportError(uint16 ModuleId, uint8  InstanceId, uint8  ApiId, uint8  ErrorId);

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#endif    /* IOEXP_CFG_H */
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
/*Date              : 08-03-2024                                            */
/*Version           :                                                       */
/*By                : gthanapp                                              */
/*Traceability      :                                                       */
/*Change Description: Initial release                                       */
/*--------------------------------------------------------------------------*/
