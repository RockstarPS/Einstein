/*=================================================================================================================
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
**==================================================================================================================
**
** Name:           Ioctrlrd_dio_diagcdd
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef IOCRTLRD_PWM_DIAGCDD_CFG_C
#define IOCRTLRD_PWM_DIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Ioctrlrd_pwm_diagcdd_cfg.h"
#include "IoHwAb_Pwm.h"
//#include "Mcu_Cfg.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
static uint8 DimmingControl_duty_VIP_GIP_CH0(uint16 DutyVal,uint8 Action, uint8 *ErrorCode);
static uint8 DimmingControl_duty_VIP_GIP_CH1(uint16 DutyVal,uint8 Action, uint8 *ErrorCode);
#ifdef CONTROL_TYPE_CUSTOMER_CALIB
#if !defined(LED_CONTROl_WITH_DUTY) && !defined(TFT_CONTROL_WITH_DUTY)
static void Get_Dimming_Gain_CHO(uint16 *gain);
static void Get_Dimming_Gain_CH1(uint16 *gain);
#ifdef IOCTRLRD_CUSTOMER_CALIBRATION_ENABLE
static uint8 temp_bcd2dec(uint8 bcd);
#endif
#endif
#endif 
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
// static void PWmControlDuty_SPEED_OUT0(uint16 DutyVal);
// static void PWmControlFreq_SPEED_OUT0(uint8 *Data);
// static void PWmControlDuty_SPEED_OUT1(uint16 DutyVal);
// static void PWmControlFreq_SPEED_OUT1(uint8 *Data);
static void PWmControlDuty_SPEED_OUT2(uint16 DutyVal);
static void PWmControlFreq_SPEED_OUT2(const uint8 *Data);
#endif

#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
static void PWM_All_Lit_Illumination_Control(uint8 *Data,uint8 *errorcode);
static void PWM_All_Lit_illumination_ControlReturnFunction(uint8 *Errorcode);
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
static uint8 OutputControl_duty_VIP_GIP_CH0(uint16 DutyVal, uint8 *ErrorCode);
static uint8 OutputControl_duty_VIP_GIP_CH1(uint16 DutyVal, uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
static uint8 FuelEctIllum_duty_VIP_GIP_CH0(uint16 DutyVal, uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
static uint8 TachoIllum_duty_VIP_GIP_CH0(uint16 DutyVal, uint8 *ErrorCode);
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
static uint8 DisplayIllum_duty_VIP_GIP_CH0(uint16 DutyVal, uint8 *ErrorCode);
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
static Std_ReturnType Ioctrlrd_Pwm_InputCheck_Read(uint8 *Data, uint8 *ErrorCode);
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
const Meet_FreqControlConfigType Meet_FreqControlConfig[FREQ_CONTROL_CHANNEL] =
{
	{&PWmControlFreq_SPEED_OUT2,&PWmControlDuty_SPEED_OUT2,1},
};
#endif
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE

const Meet_DimmingControlConfigType Meet_DimmingControlConfig[DIMMING_CONTROL_CHANNEL] =
{
	//TRUE - GIP, FALSE - VIP
  {(boolean)FALSE,&DimmingControl_duty_VIP_GIP_CH0},
  {(boolean)FALSE,&DimmingControl_duty_VIP_GIP_CH1},
};
#ifdef CONTROL_TYPE_CUSTOMER_CALIB
#if !defined(LED_CONTROl_WITH_DUTY) && !defined(TFT_CONTROL_WITH_DUTY)
const Meet_DimmingReadGainConfigType Meet_DimmingReadGainConfig[DIMMING_CONTROL_CHANNEL] = 
{
    {&Get_Dimming_Gain_CHO},
    {&Get_Dimming_Gain_CH1},
};
#endif
#endif
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
const Meet_OutputControlConfigType Meet_OutputControlConfig[OUTPUT_CONTROL_CHANNEL] =
	{
		// TRUE - GIP, FALSE - VIP
  (boolean)FALSE,&OutputControl_duty_VIP_GIP_CH0,
  (boolean)FALSE,&OutputControl_duty_VIP_GIP_CH1,
};
#endif
#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
const Meet_FuelEctIllumConfigType Meet_FuelEctIllumConfig[FUELECT_ILLUM_CHANNEL] =
	{
		// TRUE - GIP, FALSE - VIP
  (boolean)FALSE,&FuelEctIllum_duty_VIP_GIP_CH0,
};
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
const Meet_TachoIllumConfigType Meet_TachoIllumConfig[TACHO_ILLUM_CHANNEL] =
{
	//TRUE - GIP, FALSE - VIP
  (boolean)FALSE,&TachoIllum_duty_VIP_GIP_CH0,
};
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
const Meet_DisplayIllumConfigType Meet_DisplayIllumConfig[DISPLAY_ILLUM_CHANNEL] =
{
	//TRUE - GIP, FALSE - VIP
  (boolean)FALSE,&DisplayIllum_duty_VIP_GIP_CH0,
};
#endif

#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
//All Lit -All PWM channel (Illumination) control
const Meet_All_LitPWMControlConfigType Meet_All_LitPWMControlConfig=
{
    &PWM_All_Lit_Illumination_Control,&PWM_All_Lit_illumination_ControlReturnFunction,

};
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
const Ioctrlrd_pwm_Read Ioctrlrd_PwmInputCheckConfig=
{
	&Ioctrlrd_Pwm_InputCheck_Read,
};
#endif
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
#ifdef MEET_GIP_ENABLED
static GIPDataRquestState Ioctrlrd_pwm_diag_CurrentGIPState = eGIP_InitiateRequest;
#endif
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
/*=====================================================================================================================
** Function Name    :  DimmingControl_duty_VIP_GIP_CHx
**
** Visibility       :  Public/private 
**
** Description      :  Dimming Control Channel Configuration
**
** Invocation       :  Ioctrlrd_pwm_diag_DimmingControl_STA / Ioctrlrd_pwm_diag_DimmingControl_RCTE
**
** Inputs           :  Duty and Action
**
** Outputs          :  Pass/Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static uint8 DimmingControl_duty_VIP_GIP_CH0 (uint16 DutyVal,uint8 Action, uint8 *ErrorCode)
{ 
	Std_ReturnType ret = E_NOT_OK;

	if(Meet_DimmingControlConfig[0U].vip_or_gip == TRUE)
	{
		#ifdef MEET_GIP_ENABLED
		DiagReqType DiagReq;
		DiagReq.ActionP   = DiagActionType_IOCtrl;
		DiagReq.ServiceId = CIOC_DIMMINGCTRL;

		if(Action == MGRDIAGCDD_IOC_RCTE_ACTION)
		{
			DiagReq.LengthP  = cIOC_DimmingControl_RCT_DataLength;
			DiagReq.DataP[0] = DiagIOC_returnControlToECU;
		}
		else
		{
			DiagReq.LengthP  = cIOC_DimmingControl_STA_DataLength;
			DiagReq.DataP[0] = DIAGIOC_SHORTTERMADJUSTMENT;
			DiagReq.DataP[1] = (uint8)ControlType;
			DiagReq.DataP[2] = (uint8)Channel;
			DiagReq.DataP[3] = (uint8)(DutyVal>>8U);
			DiagReq.DataP[4] = (uint8)DutyVal;
		}


		switch(Ioctrlrd_pwm_diag_CurrentGIPState)
		{
		case eGIP_InitiateRequest:
			ret = Meet_Process_Gip_Diag_Request(Ioctrlrd_pwm_diag_CurrentGIPState, &DiagReq, ErrorCode);
			Ioctrlrd_pwm_diag_CurrentGIPState = eGIP_WaitForResponse;
			break;
		case eGIP_WaitForResponse:
			ret = Meet_Process_Gip_Diag_Request(Ioctrlrd_pwm_diag_CurrentGIPState, &DiagReq, ErrorCode);
			if(ret != DCM_E_PENDING)
			{
				Ioctrlrd_pwm_diag_CurrentGIPState = eGIP_InitiateRequest;
			}
			break;
		default:
			/*No action required in default case*/
			break;
		}
		#endif
	}
	else
	{
		//vip
		if(Action == MGRDIAGCDD_IOC_RCTE_ACTION)
		{
			#ifdef CMEETCDD_STUBS_ILLUM
			Stub_SetDisplayBrightness(900);	//setting 90% - default brightness
			#else
			//setting 50% - default brightness
			DutyVal = 80U; //Setting duty as 50%
			ret = Rte_Call_rpIoHwAb_PWM_PwmSetDuty(eIO_PWM_PWM_LCD_BL_DIMMING, DutyVal, ErrorCode);
			#endif
		}
		else
		{
			if (DutyVal <= MAX_PWM_DUTY)
			{
				#ifdef CMEETCDD_STUBS_ILLUM
				Stub_SetDisplayBrightness(DutyVal);
				#else
				DutyVal = DutyVal * RESOLUTION_FACTOR;
				ret = Rte_Call_rpIoHwAb_PWM_PwmSetDuty(eIO_PWM_PWM_LCD_BL_DIMMING, DutyVal, ErrorCode);
				#endif
			}
			else
			{
				ErrorCode[DATA_BYTE_0] = DCM_E_REQUESTOUTOFRANGE;
				ret = E_NOT_OK;
			}
		}
    }
   return ret;
}

static uint8 DimmingControl_duty_VIP_GIP_CH1(uint16 DutyVal,uint8 Action, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_OK;
	if(Meet_DimmingControlConfig[1U].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	 //ret = Rte_Call_rpIoHwABSet_Impl_SetDuty(eIODutyOutId_VEHICLE_SPEED,DutyVal); // RTE proj specific
  
   }
    return ret;
    
}

#ifdef CONTROL_TYPE_CUSTOMER_CALIB
#if !defined(LED_CONTROl_WITH_DUTY) && !defined(TFT_CONTROL_WITH_DUTY)
/*=====================================================================================================================
** Function Name    :  Get_Dimming_Gain_CHx
**
** Visibility       :  Public/private
**
** Description      :  Customer calibration gain
**
** Invocation       :  Ioctrlrd_pwm_diag_DimmingControl STA/RCTE
**
** Inputs           :  Gain
**
** Outputs          :  void
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static void Get_Dimming_Gain_CHO(uint16 *gain)
{
    #ifdef IOCTRLRD_CUSTOMER_CALIBRATION_ENABLE
	uint8 PwmCalib[3U] = { 0U };
	uint16 u16Dimm;
	uint16 u16Dimm_temp;
	uint16 duty_data;

	*gain = (uint16)0U;

	/*Read customer calibrated gain*/
	//Rte_Call_rpMfgModNvmReadWriteRequest_GetNV_PWMTFTBLCalibration(PwmCalib);

	u16Dimm = PwmCalib[0U];
	u16Dimm_temp = PwmCalib[1U];

	u16Dimm = temp_bcd2dec(u16Dimm);
	u16Dimm = u16Dimm * 100U;
	u16Dimm_temp = temp_bcd2dec(u16Dimm_temp);
	duty_data = u16Dimm + u16Dimm_temp;

	/*Calculate Gain*/
	*gain =  (uint16)duty_data;
	#else
	/*If channel is not controlled via customer calibration then apply default gain*/
	*gain = IOCONTROlRD_PWM_DEFAULT_GAIN;
	#endif
}

#ifdef IOCTRLRD_CUSTOMER_CALIBRATION_ENABLE
static uint8 temp_bcd2dec(uint8 bcd)
{
    uint8 dec = 0U;
    uint8 mult;

    for (mult=1U; bcd == 0U; mult*=10U)
    {
        dec += (bcd & 0x0FU) * mult;
        bcd = bcd >> 4U;
    }
    return dec;

}
#endif
/*=====================================================================================================================
**
** Function Name    :  Get_Dimming_Gain_CH1
**
** Visibility       :  Public/private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void Get_Dimming_Gain_CH1(uint16 *gain)
{
	*gain = IOCONTROlRD_PWM_DEFAULT_GAIN;
	//Need to replaced with RTE call to read the Gain
}

#endif
#endif
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
/*=====================================================================================================================
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**====================================================================================================================*/
static uint8 OutputControl_duty_VIP_GIP_CH0 (uint16 DutyVal, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
   if(Meet_OutputControlConfig[0].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	   //ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCU_PRND_OUT, DutyVal, ErrorCode);
   }
    return ret;

}
/*=====================================================================================================================
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**====================================================================================================================*/
static uint8 OutputControl_duty_VIP_GIP_CH1(uint16 DutyVal, uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK;
	if(Meet_OutputControlConfig[1].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	   //ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_TFTD_BL_DIMMING, DutyVal, ErrorCode);
   }
    return ret;

}
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**====================================================================================================================*/
static uint8 FuelEctIllum_duty_VIP_GIP_CH0 (uint16 DutyVal, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
   if(Meet_OutputControlConfig[0].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	   //ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCU_CTRL_FLTEMPSCALE, DutyVal, ErrorCode);
   }
   return ret;
}
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**====================================================================================================================*/
static uint8 TachoIllum_duty_VIP_GIP_CH0 (uint16 DutyVal, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
   if(Meet_OutputControlConfig[0].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	   //ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_MCU_CTRL_TACHOSCALE, DutyVal, ErrorCode);
   }
    return ret;
}
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**====================================================================================================================*/
static uint8 DisplayIllum_duty_VIP_GIP_CH0 (uint16 DutyVal, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
   if(Meet_OutputControlConfig[0].vip_or_gip == TRUE)
   {
	   //gip
   }
   else
   {
	   //ret = Rte_Call_rp_CS_IoHwAb_PWM_PwmSetDuty(eIO_PWM_TFTD_BL_DIMMING, DutyVal, ErrorCode);
   }
    return ret;
}
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
// static void PWmControlDuty_SPEED_OUT0(uint16 DutyVal)
// {	
	/* Dummy code */
// }
// static void PWmControlDuty_SPEED_OUT1(uint16 DutyVal)
// {	
	/* Dummy code */
// }


static void PWmControlDuty_SPEED_OUT2(uint16 DutyVal)
{	
    uint8 errorStatus = 0U;
    uint16 targetDuty = 0U;
    targetDuty = (uint16)((uint32)DutyVal * (uint32)DUTY_CONTROL_RESOLUTION); 
    (void)IoHwAb_Pwm_SetDuty(eIO_DOUT_DO_PWM_DIMMING, targetDuty, &errorStatus);
}
/*=====================================================================================================================
**
** Function Name    :  Name of the function
**
** Visibility       :  Public/private
**
** Description      :
**
**
** Invocation       :
**
** Inputs           :  Input arguments.
**
** Outputs          :  output arguments
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
// static void PWmControlFreq_SPEED_OUT0(uint8 *Data,uint8 index)
// {
	/* Dummy code */
// }
// static void PWmControlFreq_SPEED_OUT1(uint8 *Data,uint8 index)
// {
	/* Dummy code */
// }

static void PWmControlFreq_SPEED_OUT2(const uint8 *Data)
{
    uint8 errorStatus = 0U;
    uint32 Period = 0U;

    /* Guardrail: Validate input pointer before dereferencing */
    if (Data != NULL_PTR)
    {
        uint16 FreqVal = ((uint16)*(Data + 3U) << 8U) | (uint16)*(Data + 4U);
        uint16 DutyVal = ((uint16)*(Data + 1U) << 8U) | (uint16)*(Data + 2U);

        /* Calculate Period */
        Period = (uint32)(FREQ_CONTROL_ONE_MEG_VALUE / FreqVal);

        (void)IoHwAb_Pwm_SetDutyAndPeriod(eIO_DOUT_DO_PWM_DIMMING, Period, DutyVal, &errorStatus);
    }
}
#endif
#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
/*=====================================================================================================================
**
** Function Name    :  PWM_All_Lit_Illumination_Control
**
** Visibility       :  private
**
** Description      :  This function shall TURN ON all PWM channel for All Lit requirement
**
**
** Invocation       :  Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStart
**
** Inputs           :  Data PWM channel.
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void PWM_All_Lit_Illumination_Control(uint8 *Data,uint8 *errorcode)
{
	//Rte_Call_rpIoHwABSet_Impl_SetDuty(SwMDO_TT_DIMMING_PWM,100);
	//Rte_Call_rpIoHwABSet_Impl_SetDuty(SwMDO_TT_DIMMING_PWM,100);
	//Rte_Call_rpIoHwABSet_Impl_SetDuty(SwMPWM_RIGHT_SCALES_BL,100);
	//Rte_Call_rpIoHwABSet_Impl_SetDuty(SwMPWM_LEFT_SCALES_BL,100);


}
/*=====================================================================================================================
**
** Function Name    :  PWM_All_Lit_illumination_ControlReturnFunction
**
** Visibility       :  private
**
** Description      :  This function shall TURN ON all PWM channel for All Lit requirement
**
**
** Invocation       :  Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStart
**
** Inputs           :  Data PWM channel.
**
** Outputs          :  void
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void PWM_All_Lit_illumination_ControlReturnFunction(uint8 *Errorcode)
{
}
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_Pwm_InputCheck_Read
**
** Visibility       :  private
**
** Description      :  This function reads the pwm port
**
**
** Invocation       :  Ioctrlrd_pwm_diag_Pwm_InputCheck_Read
**
** Inputs           :  Data[In]:NA
** 					   ErrorCode:to be updated with errorcode if any
**
** Outputs          :  E_OK:Success
** 					   E_NOT_OK:Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType Ioctrlrd_Pwm_InputCheck_Read(uint8 *Data, uint8 *ErrorCode)
{
	UNUSED(ErrorCode);
	uint16 fl_u16Value = 0u;
	
    //Rte_Read_CMeetCdd_rp_SR_Illumination_Data_FinalTFTDisplayIllumination(&fl_u16Value);

    *Data       = (uint8) (fl_u16Value >> DIDSHIFT1BYTE);
    *(Data + 1) = (uint8) (fl_u16Value);

	return E_OK;
}
#endif
/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/Jan/2023
** CDSID             :  ajadhav5
** Traceability      :  RTC-1887181 
** Change Description:   Duty and Period control function modified for data manipulation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Misra warning fix
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
** Change Description:  Configuration  interfaces are added to support OutputControl, FuelEct, Tacho and Display
** 						illumination control.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/Dec/2019
** CDSID             : dkasiman
** Traceability      : RTC-1389700 
** Change Description: BCD to Dec conversion done for pwm calibration value.
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
** Change Description:   vip - gip communication added for dimming control
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 10/01/2018
** CDSID             : gdhilipr
** Traceability      : RTC 1208215
** Change Description: Dimming control updated with Control Type1(customer calibrated level)
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 22/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113549
** Change Description: Initial version - Ioctrl PWM Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif
