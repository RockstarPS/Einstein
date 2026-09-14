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
#ifndef IOCRTLRD_PWM_DIAGCDD_CFG_H
#define IOCRTLRD_PWM_DIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/

/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
#define CONTROL_TYPE_DIRECT 			(0U)
#define CONTROL_TYPE_CUSTOMER_CALIB 	(1U)
#define DIMMING_CONTROL_CHANNEL 		(10U)    	//Number of dimming channel can configure
#define IOCONTROlRD_PWM_DEFAULT_GAIN   	1000
#define MAX_PWM_DUTY 					(0x00A0U)	//if any max limit can be configured here
#define DIDPWMNOCTRL    				(uint16)(0xFFFFu)
#define RESOLUTION_FACTOR				(100U)
#ifdef MEET_GIP_ENABLED
#define CIOC_DIMMINGCTRL      					((uint32)0xFD51)
#define cIOC_DimmingControl_STA_DataLength		((uint8)0x05)
#define cIOC_DimmingControl_RCT_DataLength		((uint8)0x01)
#endif
#endif

#define NO_BYTES_PER_CHANNEL 	(2U)
#define NO_BITS_PER_BYTE 		(8U)

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
#define OUTPUT_CONTROL_CHANNEL 	(2U)
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
#define FUELECT_ILLUM_CHANNEL 	(1U)
#define MAX_DUTYVALUE_FUELECT   (0x2710U)
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
#define MAX_DUTYVALUE_TACHO   	(0x2710U)
#define TACHO_ILLUM_CHANNEL 	(1U)
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
#define MAX_DUTYVALUE_DISPLAY  	(0x2710U)
#define DISPLAY_ILLUM_CHANNEL 	(1U)
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
#define FREQ_CONTROL_CHANNEL       (1U)		//Number of Frequency  channel can configure
#define FREQ_CONTROL_CHANNEL_DUTY  (50U)  //Duty  
#define FREQ_CONTROL_ONE_MEG_VALUE (5000000U)
#define DUTY_CONTROL_RESOLUTION    (100U)
#endif


/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
typedef struct
{
 boolean vip_or_gip;
 uint8 (*DimmingControlFunction) (uint16 DutyValue,uint8 Action,uint8 *ErrorCode);
}Meet_DimmingControlConfigType;
#ifdef CONTROL_TYPE_CUSTOMER_CALIB
#if !defined(LED_CONTROl_WITH_DUTY) && !defined(TFT_CONTROL_WITH_DUTY)
typedef struct
{
 void (*DimmingReadGain) (uint16 *gain);
}Meet_DimmingReadGainConfigType;
#endif
#endif
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
typedef struct
{
 boolean vip_or_gip;
 uint8 (*OutputControlFunction) (uint16 DutyValue, uint8 *ErrorCode);
}Meet_OutputControlConfigType;
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
typedef struct
{
 boolean vip_or_gip;
 uint8 (*FuelEctIllumFunction) (uint16 DutyValue, uint8 *ErrorCode);
}Meet_FuelEctIllumConfigType;
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
typedef struct
{
 boolean vip_or_gip;
 uint8 (*TachoIllumFunction) (uint16 DutyValue, uint8 *ErrorCode);
}Meet_TachoIllumConfigType;
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
typedef struct
{
 boolean vip_or_gip;
 uint8 (*DisplayIllumFunction) (uint16 DutyValue, uint8 *ErrorCode);
}Meet_DisplayIllumConfigType;
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
typedef struct
{
 void (*FreqControlFunction) (uint8 *Data);
 void (*DutyControlFunction) (uint16 DutyValue);
 	uint8 ChannelId;
	uint8 Reserved[3];                           /* Explicit padding to align the total size */
}Meet_FreqControlConfigType;
#endif

#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
typedef struct
{
	void (*AllLitPWMControlStart) (uint8 *Data,uint8 *errorcode);
	void (*AllLitPWMControlStop)	(uint8 *errorcode);
}Meet_All_LitPWMControlConfigType;
#endif

typedef struct
{
	Std_ReturnType (*Ioctrlrd_pwm_Diag_Read) (uint8 *Data, uint8 *ErrorCode);
}Ioctrlrd_pwm_Read;

/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
extern const Meet_DimmingControlConfigType Meet_DimmingControlConfig[DIMMING_CONTROL_CHANNEL];
#ifdef MEET_GIP_ENABLED
extern uint8 ControlType;
extern uint8 Channel;
#endif

#ifdef CONTROL_TYPE_CUSTOMER_CALIB
#if !defined(LED_CONTROl_WITH_DUTY) && !defined(TFT_CONTROL_WITH_DUTY)
extern const Meet_DimmingReadGainConfigType Meet_DimmingReadGainConfig[DIMMING_CONTROL_CHANNEL]; 
#endif
#endif
#endif
#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
extern const Meet_FreqControlConfigType Meet_FreqControlConfig[FREQ_CONTROL_CHANNEL];
#endif
#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
extern const Meet_All_LitPWMControlConfigType Meet_All_LitPWMControlConfig;
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
extern const Meet_OutputControlConfigType Meet_OutputControlConfig[OUTPUT_CONTROL_CHANNEL];
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
extern const Meet_FuelEctIllumConfigType Meet_FuelEctIllumConfig[FUELECT_ILLUM_CHANNEL];
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
extern const Meet_TachoIllumConfigType Meet_TachoIllumConfig[TACHO_ILLUM_CHANNEL];
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
extern const Meet_DisplayIllumConfigType Meet_DisplayIllumConfig[DISPLAY_ILLUM_CHANNEL];
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
extern const Ioctrlrd_pwm_Read Ioctrlrd_PwmInputCheckConfig;
#endif
/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/

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
** Date              :  31/Jan/2023
** CDSID             :  ajadhav5
** Traceability      :  RTC-1887181 
** Change Description:  Duty and Period control function modified for data manipulation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Typedefs are related macros are added to support OutputControl, FuelEct, Tacho and Display
** 						illumination control.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 9/Sept/2019 
** CDSID             : razhakes
** Traceability      : RTC 1368184
** Change Description: Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction is made common for both VIP and GIP
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 05/Apr/2019 
** CDSID             : dkasiman
** Traceability      : RTC 1308973
** Change Description: Coverity fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/02/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1263593
** Change Description:  vip - gip communication added for dimming control
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

#endif


