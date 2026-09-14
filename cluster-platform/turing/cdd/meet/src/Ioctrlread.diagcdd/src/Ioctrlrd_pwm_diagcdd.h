/*===================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
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
**===================================================================================================================
**
** Name:           Ioctrlrd_dio_diagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef IOCRTLRD_PWM_DIAGCDD_H
#define IOCRTLRD_PWM_DIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
#define DIMMING_CTRL_ALL_CHANNEL 			(uint8)0xFF
#endif
#define IOCONTROlRD_PWM_HUNDRED_PERCENT 	(1000U)
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_DimmingControl_STA(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_DimmingControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_OutputControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_OutputControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROL_PWM_SINGLE_OUTPUTCONTROL_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_Single_OutputControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_Single_OutputControl_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_FuelEct_Illumination_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_FuelEct_Illumination_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_Tacho_Illumination_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_Tacho_Illumination_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_Display_Illumination_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_Display_Illumination_RCTE(uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_PWMFrequencyControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_PWMFrequencyControl_RCTE(uint8 *ErrorCode);
#endif
#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
Std_ReturnType Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStop(uint8 *ErrorCode);
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
Std_ReturnType Ioctrlrd_pwm_diag_Pwm_InputCheck_Read(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_PWM_GENBACKLIGHT_DIMMING
Std_ReturnType Ioctrlrd_GenBacklight_illum_STA(uint8 *Data);
Std_ReturnType Ioctrlrd_GenBacklight_illum_RCTE(uint8 *Data);
Std_ReturnType Ioctrld_GenBcklight_illumination_PWM_Read(uint8 *Data);
#define Ioctrld_Read_GenBcklight_illum(Data) 		Ioctrld_GenBcklight_illumination_PWM_Read(Data);
#endif

#ifdef IOCONTROlRD_PWM_PTRBACKLIGHT_DIMMING
Std_ReturnType Ioctrlrd_PtrBacklight_illum_STA(uint8 *Data);
Std_ReturnType Ioctrlrd_PtrBacklight_illum_RCTE(uint8 *Data);
Std_ReturnType Ioctrld_PtrBcklight_illumination_PWM_Read(uint8 *Data);
#define Ioctrld_Read_PtrBcklight_illum(Data) 		Ioctrld_PtrBcklight_illumination_PWM_Read(Data);
#endif

#ifdef IOCONTOLRD_PULSE_INPUT_CH1
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH1_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH1_RCResult(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef IOCONTOLRD_PULSE_INPUT_CH2
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH2_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH2_RCResult(uint8 *Data, uint8 *ErrorCode);
#endif

/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  OutputControl, FuelEct, Tacho and Display illumination control interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/01/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208215
** Change Description: Dimming control updated with Control Type1(customer calibrated level)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 11/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit PWM illumination ON/OFF function implemented
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 22/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113549
** Change Description: Initial version - Ioctrl PWM Implementation for Turing Bookshelf.
**=======================================================================================================================*/

#endif /* IOCRTLRD_PWM_DIAGCDD_H */
