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
#ifndef CTRL_ILLUMINATION_H
#define CTRL_ILLUMINATION_H
/*==========================================================================*/
//#include "rtwtypes.h"
#include <stddef.h>
#include "Ctrl_Illum_Cfg.h"
#include "Rte_Type.h"

#define COMP_MAX            8u
#define SWITCHING_ALGO_MAX  4u

#define ONE 1u

typedef struct
{
   uint8 Mode;
   uint8 Level;
   uint8 Status;
   uint8 switching_control;
}Ctrl_Ip;

typedef struct 
{
    Ctrl_Ip Bulb_Control[NO_OF_BULB];
    Ctrl_Ip LED_Control[NO_OF_LED];
    Ctrl_Ip Dial_Control[NO_OF_DIAL];
    Ctrl_Ip Display_Control[NO_OF_DISPLAYS];
    Ctrl_Ip Telltale_Control[NO_OF_TELLTALES];
    Ctrl_Ip Duty_Control[NO_OF_DUTY];
    Ctrl_Ip RGB_Control[NO_OF_RGB];
    Ctrl_Ip Brightness_Control[NO_OF_BGT];

}Input_Data;


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
    
}Ctrl_Op;

typedef struct
{
    //uint8 Timersts;
    uint8 TimerID;
    uint8 Prev_val;
    uint8 Curr_val;
    uint16 TimerVal;

}Tmr_Ctrl_Ip;

typedef struct 
{
    uint8 table_index;
    uint8 Illum_index;

}Index_Data;

typedef struct 
{
    uint8 Curr_Mode;
    uint16 Curr_Pwm;

}Curr_data;

typedef struct
{   
    Index_Data l_Index_Ip;
    Curr_data l_Curr_Ip;
    Ctrl_Ip l_Ctrl_Ip;
    Tmr_Ctrl_Ip l_ModeCtrl_Ip;
    Tmr_Ctrl_Ip l_StepCtrl_Ip;

}Switch_Ctrl_Ip;

typedef struct 
{
    uint8 table_index;
    uint8 Illum_index;
    uint8 Curr_Mode;
    uint16 Curr_pwm;
    uint16 tgt_pwm;
    uint16 table_data[TOT_STEP];
    Ctrl_Ip l_Ctrl_Ip;

}Sl_Ctrl_Ip;

typedef struct 
{
    uint8 prev_mode;
    uint16 slewrate;

}Sl_Ctrl_Op;

typedef struct {
    uint8* array;
    size_t size;
} PWM_Array;


static void Input_Processing(void);
static void Process_Ctrl_Illumination(void);
static void Output_Processing(void);
static void Illumination_Data_handle(void);
/*Generic timer handling functions*/
static boolean handle_timer(uint8 timerId, uint32 loadtime);
/*Generic slewrate control functions*/
uint16 handle_slew(uint16 current_val, uint16 target_val, uint16 slewrate);

void Slicing_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);
void Timing_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);
void Default_control(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);
void Off_mode(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);

uint8 Mode_Timer_Control(Tmr_Ctrl_Ip l_ModeCtrl_Ip);
uint8 Step_Timer_Control(Tmr_Ctrl_Ip l_StepCtrl_Ip);

void DutyMode_Control(void);
void BulbMode_Control(void);
void LEDMode_Control(void);
void DialMode_Control(void);
void DisplayMode_Control(void);
void BrightnessMode_Control(void);
void TelltaleMode_Control(void);
void RGBMode_Control(void);

#endif

/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-16461
** Change Description: Ctrl-Illumination - Inital version
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

