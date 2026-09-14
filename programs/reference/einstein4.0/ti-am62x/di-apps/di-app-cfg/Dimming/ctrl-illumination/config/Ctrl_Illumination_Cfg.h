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
#ifndef CTRL_ILLUMINATION_CFG_H
#define CTRL_ILLUMINATION_CFG_H
/*==========================================================================*/
#include "Rte_Type.h"
#include "ctrl_Illumination_Extn.h"
#include "Ctrl_Illumination.h"
//#include "IllumMdl.h"
#include "Ctrl_Illum_Cfg.h"
#include "Rte_Ctrl_Illumination.h"
#include "Stubs.h" 

#define UPDATE_ILLUMINATION_TABLE(pdata)      Illumination_Table_Update(pdata)
#define DEFAULT_CONTROL(pdata1,pdata2)    Set_PWM_to_Default(pdata1,pdata2)
#define ILLUMINATION_OFF(pdata1,pdata2)   Set_PWM_to_Off(pdata1,pdata2)

#define RTE_READ_ILL_MDL_DATA(pdata)   Rte_Read_Ctrl_Illumination_rp_IllumCtrl_Ip_IllumCtrl_Ip_Data(pdata)
#define RTE_WRITE_IL_CTRL_DATA(pdata)  Rte_Write_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data(pdata)

#define CTRL_ILLUMINATION_INPUT_ADAPTER(pdata) Ctrl_Illumination_InputAdapter(pdata)
#define CTRL_ILLUMINATION_OUTPUT_ADAPTER(pdata) Ctrl_Illumination_OutputAdapter(pdata)
#define SLEW_RATE_DETERMINATION(pdata1) Slew_Rate_Determination(pdata1)
#define GET_MIN_MAX_VAL_OF_TABLE(pdata1,pdata2,pdata3,pdata4) Get_Min_Max_Data(pdata1,pdata2,pdata3,pdata4)

#define CAN_COMMUNICATION(pdata) Stub_Write_3B8_StopCommunication(pdata)
#define GET_WARNING_STATUS(pdata)  X(pdata)
#define SEND_MODE_INFO(pdata)  Y(pdata)
#define SEND_STEP_INFO(pdata)  Y(pdata)
#define GET_ROUTINE_DATA(pdata)  X(pdata)

#define GET_C020_ROUTINE_DATA(pdata) X(pdata)
#define GET_C021_ROUTINE_DATA(pdata) X(pdata)

#endif
/*==========================================================================*/
/*============================================================================
**
** Date              : 15-05-2025
** CDSID             : aelango6
** Traceability      : MSIL32083-17413
** Change Description: Ctrl-Illumination - Config - Inital version
**
**============================================================================*/
