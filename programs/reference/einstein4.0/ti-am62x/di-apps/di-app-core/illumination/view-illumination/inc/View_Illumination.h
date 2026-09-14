/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2025. Visteon Corporation owns all rights to this work and
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
#ifndef VIEW_ILLUMINATION_H
#define VIEW_ILLUMINATION_H
 /*==========================================================================*/
#include "Rte_Type.h"
#include "View_Illumination_Cfg.h"


#define IOHWAB_OUT 1u
#define UCL_OUT    2u
#define CAN_OUT    3u

typedef struct
{
    uint8 data;
    uint8 signal_id;

}com_out;

typedef struct
{
    uint16 Duty_Out[NO_OF_DUTY];
    uint16 Brightness_Out[NO_OF_BGT];
    uint16 RGB_Out[NO_OF_RGB];
    uint16 Bulb_Out[NO_OF_BULB];
    uint16 LED_Out[NO_OF_LED];
    uint16 Dial_Out[NO_OF_DIAL];
    uint16 Display_Out[NO_OF_DISPLAYS];
    uint16 Telltale_Out[NO_OF_TELLTALES];
    
}View_Ip;


static void Input_Processing(void);
static void Process_View_Illumination(void);

void Duty_Mode_Process(uint16 l_PWMData[NO_OF_DUTY]);
void Bulb_Mode_Process(uint16 l_PWMData[NO_OF_BULB]);
void LED_Mode_Process(uint16 l_PWMData[NO_OF_LED]);
void Dial_Mode_Process(uint16 l_PWMData[NO_OF_DIAL]);
void Display_Mode_Process(uint16 l_PWMData[NO_OF_DISPLAYS]);
void Brightness_Mode_Process(uint16 l_PWMData[NO_OF_BGT]);
void Telltale_Mode_Process(uint16 l_PWMData[NO_OF_TELLTALES]);
void RGB_Mode_Process(uint16 l_PWMData[NO_OF_RGB]);

#endif
/*==========================================================================*/
/*============================================================================
**
** Date              : 16-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-16462
** Change Description: View-Illumination - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 28-07-2025
** CDSID             : aelango6
** Traceability      : DICMBD-1303
** Change Description: Requirement Traceability added
**
**============================================================================*/

