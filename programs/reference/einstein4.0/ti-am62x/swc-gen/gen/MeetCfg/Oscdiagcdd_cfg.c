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
** Name:           Oscdiagcdd_cfg.c
**
** Description:    
**                 
**
**===================================================================================================================*/

#ifndef OSCDIAGCDD_CFG_C
#define OSCDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
 #include "Oscdiagcdd_cfg.h"
 #include "Mgrdiagcdd_cfg.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CONTROL

#define MAIN_CLK_SOURCE							(uint8)2
// Main clock *1/2
#define MAIN_CLK_DIVISOR						(uint8)6
#define	CLK_ENABLE								(uint8)1

#define SUB_CLK_SOURCE							(uint8)3
#define SUB_CLK_DIVISOR							(uint8)0

#endif

#ifdef MEET_GIP_ENABLED
#define cIOC_QuartzControl      			((uint32)0xFD06)
#define cIOC_QuartzControl_DataLength		((uint8)0x05)
#endif
/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CORRECTION
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/
static uint8 OscdiagCorrction_SetNVM(uint8* data);
static uint8 OscdiagCorrction_GetNVM(uint8 *data);
static void OscdiagCorrection_SetJobStatus(uint8 data);
static void OscdiagCorrection_GetJobStatus(uint8* data);
#endif

#ifdef OSCDIAG_QUARTZ_CONTROL
	static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA1(uint8 *ErrorCode);
	static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA2(uint8 *ErrorCode);
	static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA3(uint8 *ErrorCode);
	static Std_ReturnType Oscdiagservice_cfg_quartz_control_RCTE(uint8 *ErrorCode);
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
static Std_ReturnType Oscidiag_ClockValue_Read(uint8 *Data);
static Std_ReturnType Oscidiag_ClockValue_Write(uint8 *Data);
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef OSCDIAG_QUARTZ_CORRECTION
const Oscdiag_Service Oscdiag_Service_Map =
{
    {&OscdiagCorrction_SetNVM},{&OscdiagCorrction_GetNVM},{&OscdiagCorrection_SetJobStatus},{&OscdiagCorrection_GetJobStatus},
};
#endif

#ifdef OSCDIAG_QUARTZ_CONTROL

const Oscdiagservice_quartz_ctrl_STA OscdiagService_quartz_control_STA_Map[MAX_NUMBER_OF_QUARTZ_SIGNAL] = 
{
	{&Oscdiagservice_cfg_quartz_control_STA1},
	{&Oscdiagservice_cfg_quartz_control_STA2},
	{&Oscdiagservice_cfg_quartz_control_STA3},
};

const Oscdiagservice_quartz_ctrl_RCTE OscdiagService_quartz_control_RCTE_Map[1] = 
{
	{&Oscdiagservice_cfg_quartz_control_RCTE},
};
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
const Meet_ClockValueConfigType Meet_ClockConfig =
{
	&Oscidiag_ClockValue_Read,
	&Oscidiag_ClockValue_Write,
};
#endif

#ifdef OSCDIAG_QUARTZ_CORRECTION
/*=====================================================================================================================
**
** Function Name    :  OscdiagCorrction_SetNVM
**
** Visibility       :  Public 
**
** Description      :  Used to write NVM value and RTE call for ppm correction value should be mapped here. 
**                      
**
** Invocation       : Oscdiag_Quartz_Correction_Write
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static uint8 OscdiagCorrction_SetNVM(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  OscdiagCorrction_GetNVM
**
** Visibility       :  Public 
**
** Description      :  Used to read ppm correction value available in NVM and RTE  
**                     call for the same has to be mapped here 
**
** Invocation       : Oscdiag_Quartz_Correction_Read
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static uint8 OscdiagCorrction_GetNVM(uint8 *data)
{
    return E_OK;
}
/*=====================================================================================================================
**
** Function Name    :  OscdiagCorrection_SetJobStatus
**
** Visibility       :  Public 
**
** Description      :  Used to set NVM job status as 0 for the previous request of ppm correction write and RTE  
**                     call for the same has to be mapped here 
**
** Invocation       : Oscdiag_Quartz_Correction_Write
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static void OscdiagCorrection_SetJobStatus(uint8 data)
{
}
/*=====================================================================================================================
**
** Function Name    :  OscdiagCorrection_GetJobStatus
**
** Visibility       :  Public 
**
** Description      :  Used to Get NVM job status for the current request of ppm correction write and RTE  
**                     call for the same has to be mapped here 
**
** Invocation       : Oscdiag_Quartz_Correction_Write
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static void OscdiagCorrection_GetJobStatus(uint8* data)
{
    *data = 0;
}
 #endif
 
#ifdef OSCDIAG_QUARTZ_CONTROL
/*=====================================================================================================================
**
** Function Name    :  Oscdiagservice_cfg_quartz_control_STA1
**
** Visibility       :  Public 
**
** Description      :  Used to do the STA for quartz control Data value 1.(ie : 0x01: 16 MHz Quartz (VIP))
**                      
**
** Invocation       :  Oscdiag_Quartz_Control_ShortTermAdjustment
**
** Inputs           :  
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA1(uint8 *ErrorCode)
{
	// Main clock - 16MHz quartz
	// generate 125KHz from 16MHz  i.e 16MHz /128 =125KHz
			
	// set mode for port pin P1_16 
	Port_SetPinMode(PORT_PIN_P116,PORT_PIN_MODE_P116_SYSC0_CLK);

	//update Clock output function control register (SYSC_CKOTCNTR)
	//Os_Call_Meet_SetRegClockOutput(MAIN_CLK_SOURCE, MAIN_CLK_DIVISOR, CLK_ENABLE);
    Meet_SetRegClockOutput(MAIN_CLK_SOURCE, MAIN_CLK_DIVISOR, CLK_ENABLE);
	return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Oscdiagservice_cfg_quartz_control_STA2
**
** Visibility       :  Public 
**
** Description      :  Used to do the STA for quartz control Data value 2.(0x02: 32 KHz Quartz (VIP))
**                      
**
** Invocation       :  Oscdiag_Quartz_Control_ShortTermAdjustment
**
** Inputs           :  
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA2(uint8 *ErrorCode)
{
	//sub clock 
	// set mode for port pin P1_16 
	Port_SetPinMode(PORT_PIN_P116,PORT_PIN_MODE_P116_SYSC0_CLK);

	//update Clock output function control register (SYSC_CKOTCNTR)
	//Os_Call_Meet_SetRegClockOutput(SUB_CLK_SOURCE, SUB_CLK_DIVISOR, CLK_ENABLE);
	Meet_SetRegClockOutput(SUB_CLK_SOURCE, SUB_CLK_DIVISOR, CLK_ENABLE);
		
    return E_OK;
}

/*=====================================================================================================================
**
** Function Name    :  Oscdiagservice_cfg_quartz_control_STA3
**
** Visibility       :  Public 
**
** Description      :  Used to do the STA for quartz control Data value 3.(0x03: 24 MHz Quartz (GIP))
**                      
**
** Invocation       :  Oscdiag_Quartz_Control_ShortTermAdjustment
**
** Inputs           :  
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/

static Std_ReturnType Oscdiagservice_cfg_quartz_control_STA3(uint8 *ErrorCode)
{

   Std_ReturnType ret = E_NOT_OK;
   #ifdef MEET_GIP_ENABLED
   MeetDiagReqType DiagReq; 
   DiagReq.ActionP   = DiagActionType_IOCtrl;
   DiagReq.ServiceId = cIOC_QuartzControl;
   DiagReq.LengthP  = cIOC_QuartzControl_DataLength+1;
   DiagReq.DataP[0] = MGRDIAGCDD_IOC_STA_ACTION;
   DiagReq.DataP[1] = (uint8)3;

   switch(Oscdiag_CurrentGIPState)
   {
       case eGIP_InitiateRequest:
          ret = Meet_Process_Gip_Diag_Request(Oscdiag_CurrentGIPState, &DiagReq, ErrorCode);
          Oscdiag_CurrentGIPState = eGIP_WaitForResponse;
          break;
       case eGIP_WaitForResponse:
          ret = Meet_Process_Gip_Diag_Request(Oscdiag_CurrentGIPState, &DiagReq, ErrorCode);
          if(ret != DCM_E_PENDING)
          {
             Oscdiag_CurrentGIPState = eGIP_InitiateRequest;
          }
         break;
       default:
    	 /*No action required*/
         break;
   }
	#else
		ret = E_OK;
	#endif
	   return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Oscdiagservice_cfg_quartz_control_RCTE
**
** Visibility       :  Public 
**
** Description      :  Used to do the RCTE for quartz control
**                      
**
** Invocation       :  Oscdiag_Quartz_Control_ReturnControlToECU
**
** Inputs           :  
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
static Std_ReturnType Oscdiagservice_cfg_quartz_control_RCTE(uint8 *ErrorCode)
{
     Port_SetPinMode(PORT_PIN_P116,PORT_PIN_MODE_P116_GPIO);

	/*if gip*/
   Std_ReturnType ret = E_NOT_OK;
      	#ifdef MEET_GIP_ENABLED
   MeetDiagReqType DiagReq; 
   DiagReq.ActionP   = DiagActionType_IOCtrl;
   DiagReq.ServiceId = cIOC_QuartzControl;
   DiagReq.LengthP  = cIOC_QuartzControl_DataLength+1;
   DiagReq.DataP[0] = MGRDIAGCDD_IOC_RCTE_ACTION;

   switch(Oscdiag_CurrentGIPState)
   {
       case eGIP_InitiateRequest:
          ret = Meet_Process_Gip_Diag_Request(Oscdiag_CurrentGIPState, &DiagReq, ErrorCode);
          Oscdiag_CurrentGIPState = eGIP_WaitForResponse;
          break;
       case eGIP_WaitForResponse:
          ret = Meet_Process_Gip_Diag_Request(Oscdiag_CurrentGIPState, &DiagReq, ErrorCode);
          if(ret != DCM_E_PENDING)
          {
             Oscdiag_CurrentGIPState = eGIP_InitiateRequest;
          }
         break;
       default:
	   	 /*No action required in default case*/
         break;
   }
  
	#else
		ret = E_OK;
	#endif
	   return ret;
}

void Meet_SetRegClockOutput(uint8 Cksel, uint8 Ckoutdiv, boolean Enclko)
{
	Mcu_RegClockOutputType 	ClockOutputClk;

	ClockOutputClk.Cksel = Cksel;
	ClockOutputClk.Ckoutdiv = Ckoutdiv;
	ClockOutputClk.Enclko = Enclko;

	Mcu_SetRegClockOutput(&ClockOutputClk);
}

#endif

#ifdef OSCDIAG_CLOCK_MONITORING
Std_ReturnType Oscdiag_ClockMonitoring_start(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    //ret = Rte_Read_CMeetCdd_rp_SR_FuSaCdd_ClockTst_u8ClockMonResult(Data);
	return ret;
}
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Oscidiag_ClockValue_Read
**
** Visibility       :  Public
**
** Description      :  Used to read time
**
** Invocation       :  Oscdiag_ClockValue_Read
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType Oscidiag_ClockValue_Read(uint8 *Data)
{
	Std_ReturnType ret;
	/*Rtc_TimeDateType TimeDate;

	ret = RtcCdd_GetTimeDate(&TimeDate);

	Data[0] = TimeDate.Hour;
	Data[1] = TimeDate.Minute;
	Data[2] = TimeDate.Second;
	Data[3] = TimeDate.AmPm;*/

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Oscidiag_ClockValue_Write
**
** Visibility       :  Public
**
** Description      :  Used to write time
**
** Invocation       :  Oscdiag_ClockValue_Write
**
** Inputs           :  data
**
** Outputs          :  E_OK/E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
static Std_ReturnType Oscidiag_ClockValue_Write(uint8 *Data)
{
	Std_ReturnType ret = E_NOT_OK;
	/*Rtc_TimeDateType TimeDate, TimeDateGet;

	TimeDate.Hour = Data[0];
	TimeDate.Minute = Data[1];
	TimeDate.Second = Data[2];
	TimeDate.AmPm = Data[3];*/

	//RtcCdd_GetTimeDate(&TimeDateGet);

	/*Setting year and month to default values in range*/

	/*TimeDate.DayOfWeek = TimeDateGet.DayOfWeek;
	TimeDate.HourMode = TimeDateGet.HourMode;
	TimeDate.Month = TimeDateGet.Month;
	TimeDate.Year = TimeDateGet.Year;
	TimeDate.Date = TimeDateGet.Date;*/

	//ret = RtcCdd_SetTimeDate(&TimeDate);

	if(ret == E_INVALID_ARG)
	{
		ret = E_NOT_OK;
	}

	return ret;
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
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Config interfaces are added to support clock value read and write interfaces.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1321988
** Change Description:  Configure the pin mode from clock generation to GPIO in RCTE function
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1268470
** Change Description:  vip - gip communication communication for quartz control is added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/May/2018   
** CDSID             :  dkasiman
** Traceability      :  RTC-1111915
** Change Description:  Initial verion for MeetCdd bookshelf - OSC diag services
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 5/Jun/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Review comments fix - Osc diag services
**=======================================================================================================================*/
#endif
