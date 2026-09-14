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
#ifndef CTRL_ILLUMINATION_EXTN_H
#define CTRL_ILLUMINATION_EXTN_H
/*==========================================================================*/
#include "Rte_Type.h"
#include "Ctrl_Illumination.h"
//#include "Rte_IlluminationMdl.h"
#include "Ctrl_Illum_Cfg.h"

// extern uint8 Duty_Table[NO_OF_DUTY][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 Bulb_Table[NO_OF_BULB][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 LED_Table[NO_OF_LED][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 Display_Table[NO_OF_DISPLAYS][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 Dial_Table[NO_OF_DIAL][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 BGT_Table[NO_OF_BGT][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 RGB_Table[NO_OF_RGB][TOT_ILLUM_MODE][TOT_STEP];
// extern uint8 TT_Table[NO_OF_TELLTALES][TOT_ILLUM_MODE][TOT_STEP];


//void Illumination_Table_Update(Ctrl_Ip l_Ctrl_Ip);
void Illumination_Table_Update(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP]);
void Ctrl_Illumination_InputAdapter(Input_Data *l_Input_Data);
void Ctrl_Illumination_OutputAdapter(Ctrl_Op l_Ctrl_Op);

void Get_Duty_Data(void);
void Get_Bulb_Data(void);
void Get_Dial_Data(void);
void Get_LED_Data(void);
void Get_Display_Data(void);
void Get_Brightness_Data(void);
void Get_Telltale_Data(void);
void Get_RGB_Data(void);

void Ign_On_Data_handle(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP],IllumCtrl_Ip l_IllumCtrl_Ip);
void Ign_Off_Data_handle(uint16 (*outputTable[])[TOT_ILLUM_MODE][TOT_STEP],IllumCtrl_Ip l_IllumCtrl_Ip);
void Set_PWM_to_Default(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);
void Set_PWM_to_Off(Switch_Ctrl_Ip l_SwitchCtrl_Ip,uint16 *Ill_Pwm_Data);
Sl_Ctrl_Op Slew_Rate_Determination(Sl_Ctrl_Ip l_Sl_Ctrl_Ip);
void Get_Min_Max_Data(uint16 arr[], uint8 n, uint16 *max, uint16 *min);
// void mergeSort(uint16 arr[], uint16 temp[], uint8 left, uint8 right);
// void merge(uint16 arr[], uint16 temp[], uint8 left, uint8 mid, uint8 right);

void X(uint8 *data);
void Y(uint8 data);

#define INDEX_0             (0u)
#define INDEX_1             (1u)
#define INDEX_2             (2u)
#define INDEX_3             (3u)
#define INDEX_4             (4u)
#define INDEX_5             (5u)
#define INDEX_6             (6u)
#define INDEX_7             (7u)

// #define eIGN_OFF     (1U)
// #define eIGN_ON      (2U)

// #ifndef GET_NVM_K_DIM_P_LIGHTS
// #define    GET_NVM_K_DIM_P_LIGHTS(pData)                Rte_Call_rp_CS_MemAbsGet_Get_NVM_K_dim_P_LIGHTS_U16(pData)                  
// #endif

// #ifndef GET_NVM_K_DIM_F_FOG
// #define    GET_NVM_K_DIM_F_FOG(pData)                   Rte_Call_rp_CS_MemAbsGet_Get_NVM_K_dim_F_FOG_U16(pData) 
// #endif


#endif
/*==========================================================================*/
/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17658
** Change Description: Ctrl-Illumination-Extn - Inital version
**
**============================================================================*/
/*============================================================================
**
** Date              : 27-06-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-23936
** Change Description: Ctrl-Illumination-Extn - Version 2
**
**============================================================================*/
/*============================================================================
**
** Date              : 30-07-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-26360
** Change Description: MSIL req - Warning & Diag req added
**
**============================================================================*/

