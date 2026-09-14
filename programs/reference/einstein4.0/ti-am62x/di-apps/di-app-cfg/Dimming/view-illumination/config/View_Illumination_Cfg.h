/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2017 -2018. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **==========================================================================*/
#ifndef VIEW_ILLUMINATION_CFG_H
#define VIEW_ILLUMINATION_CFG_H
/*============================================================================*/
#include "Rte_View_Illumination.h"
/*Configure Applicable Illumination Data */
/*MSB--------LSB*/
/*7 bit --- Duty*/
/*6 bit --- Brightness*/
/*5 bit --- RGB_Dimming*/
/*4 bit --- Bulb*/
/*3 bit --- LED*/
/*2 bit --- Dial*/
/*1 bit --- Display*/
/*0 bit --- Telltale*/
#define APPL_ILLUMINATION_DATA 0x02u //0b10011111
#define BYTE_LENGTH            8u
#define PWM_RESOLUTION 100u
#define CONVERT_TO_CAN_PERCENTAGE(value) ((value * 255U) / 100U)

/*===============================*/
/*NO OF ILLUMINATION COMPONENTS*/
#define NO_OF_DUTY      1u
#define NO_OF_BULB      1u
#define NO_OF_LED       1u
#define NO_OF_DIAL      1u
#define NO_OF_DISPLAYS  1u
#define NO_OF_RGB       1u
#define NO_OF_BGT       1u
#define NO_OF_TELLTALES 1u
/*===============================*/

#define SIGNAL_ID    255u
#define GPIO_ID   255u
#define eIO_PWM_DIM 30u

#define DUTY_OUT_TYPE      {CAN_OUT}
#define BULB_OUT_TYPE      {IOHWAB_OUT}
#define LED_OUT_TYPE       {IOHWAB_OUT}
#define DIAL_OUT_TYPE      {IOHWAB_OUT}
#define DISPLAY_OUT_TYPE   {IOHWAB_OUT}
#define BGT_OUT_TYPE       {IOHWAB_OUT}
#define RGB_OUT_TYPE       {IOHWAB_OUT}
#define TELLTALE_OUT_TYPE  {IOHWAB_OUT}

#define DUTY_ID_TYPE       {SIGNAL_ID}
#define BULB_ID_TYPE       {GPIO_ID}
#define LED_ID_TYPE        {GPIO_ID}
#define DIAL_ID_TYPE       {GPIO_ID}
#define DISPLAY_ID_TYPE    {eIO_PWM_DIM}
#define BGT_ID_TYPE        {GPIO_ID}
#define RGB_ID_TYPE        {GPIO_ID}
#define TT_ID_TYPE         {GPIO_ID}

// #define TURN_LR_INDICATOR_OUT                 IOHWAB_OUT
// #define POSITION_LIGHTS_INDICATOR_OUT         IOHWAB_OUT
// #define FRONT_FOG_INDICATOR_OUT               IOHWAB_OUT

// #define TT_INDEX1 TURN_LR_INDICATOR_OUT
// #define TT_INDEX2 POSITION_LIGHTS_INDICATOR_OUT
// #define TT_INDEX3 FRONT_FOG_INDICATOR_OUT

// #define TT_ID_TYPE1  GPIO_ID
// #define TT_ID_TYPE2  GPIO_ID
// #define TT_ID_TYPE3  GPIO_ID

#endif

/*============================================================================*/
/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17414
** Change Description: View-Illumination - Config - Inital version
**
**============================================================================*/
