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
** Name:           Displaycontroldiagcdd_cfg.c
**
** Description:    contains configurable functions to call RTE /API for each service
**                 
**
**===================================================================================================================*/

#ifndef DISPLAYCONTROLDIAGCDD_CFG_C
#define DISPLAYCONTROLDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
//#include "Rte_NVM_Type.h"
#include "Displaycontroldiagcdd_cfg.h"
#include "Mgrdiagcdd_cfg.h"				
#include "Mgrdiagcdd.h"		
#include "Displaycontroldiagcdd.h"
#if defined (DISPLAYCONTROLDIAG_I2CTEST_ROUTINE) || defined(DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE)
#include "I2c.h"
#include "I2c_Cfg.h"
#endif			
//#include <hmi_logic_state_handler.h>//coverity fix CID : 1589767
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
#define  DCIC_VALID_CHECKSUM   0x86991DCFU   // 4bytes value required
#define  DCIC_INVALID_CHECKSUM 0x00000000U  // 4bytes value required
#endif
/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef MEET_GIP_ENABLED
static GIPDataRquestState Display_TFTGIPDataReqState = eGIP_InitiateRequest;
#endif

#ifdef TFTPATTERNCTRLENABLE
static Std_ReturnType DisplayCtrlDiag_TFTPatternCtrl_STA(const uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTPatternCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTFULLCOLORCTRLENABLE
static Std_ReturnType DisplayCtrlDiag_TFTFullColorCtrl_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTFullColorCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTONEDOTCTRLENABLE
static Std_ReturnType DisplayCtrlDiag_TFTOneDotCtrl_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTOneDotCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTXYSHIFTCTRLENABLE
static Std_ReturnType DisplayCtrlDiag_TFTXYShiftCtrl_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTXYShiftCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
static Std_ReturnType DisplayCtrlDiag_TFTAdjChessPtrnCtrl_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTAdjChessPtrnCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef DISPLAYXYPARAMETERENABLE
static Std_ReturnType DisplayCtrlDiag_DisplayXYParameter_Read(uint8 *Data);
static Std_ReturnType DisplayCtrlDiag_DisplayXYParameter_Write(uint8 *Data,uint8 *ErrorCode);
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Start(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Stop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Res(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
static Std_ReturnType DisplayCtrlDiag_All_LCD_Segment_Start(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_All_LCD_Segment_Stop(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
static Std_ReturnType DisplayCtrlDiag_All_LIT_TFTcolor_Start(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_All_LIT_TFTcolor_Stop(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
static Std_ReturnType DisplayCtrlDiag_LCDSegmentCtrl_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_LCDSegmentCtrl_RCTE(uint8 *ErrorCode);
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
static Std_ReturnType DisplayCtrlDiag_TFTVideoCheck_STA(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TFTVideoCheck_RCTE(uint8 *ErrorCode);
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStop(uint8 *Data, const uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
static Std_ReturnType DisplayCtrlDiag_TouchTest_PreCondition(uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TouchTest_Read(uint8 *Data);
static Std_ReturnType DisplayCtrlDiag_TouchTest_Write(uint8 *Data);
static void DisplayCtrlDiag_TouchTest_PostCondition(void);
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
static Std_ReturnType DisplayCtrlDiag_TswI2CRead_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TswI2CRead_RCStatus(uint8 *Data, uint8 *ErrorCode);
static void Displaycontroldiag_I2C_WriteSeq(void);
static void Displaycontroldiag_I2C_ReadSeq(void);
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStart(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStop(uint8 *Data, uint8 *ErrorCode);
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStatus(uint8 *Data, uint8 *ErrorCode);
void DisplayCtrlDiag_TouchPanelCtrl_ReadConversion(uint8 *pu8_Touch_Data);
#endif
/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef DISPLAYXYPARAMETERENABLE
static boolean NVMWrtReq=FALSE;
#endif

#ifdef TFTPATTERNCTRLENABLE
const DisplayCtrlDiag_IOCTL TFTPatternCtrlConfig =
{
    &DisplayCtrlDiag_TFTPatternCtrl_STA,&DisplayCtrlDiag_TFTPatternCtrl_RCTE,
}; 
#endif

#ifdef TFTFULLCOLORCTRLENABLE
const DisplayCtrlDiag_IOCTL TFTFullColorCtrlConfig =
{
    &DisplayCtrlDiag_TFTFullColorCtrl_STA,&DisplayCtrlDiag_TFTFullColorCtrl_RCTE,
};
#endif

#ifdef TFTONEDOTCTRLENABLE
const DisplayCtrlDiag_IOCTL TFTOneDotCtrlConfig =
{
    &DisplayCtrlDiag_TFTOneDotCtrl_STA,&DisplayCtrlDiag_TFTOneDotCtrl_RCTE,
};
#endif

#ifdef TFTXYSHIFTCTRLENABLE
const DisplayCtrlDiag_IOCTL TFTXYShiftCtrlConfig =
{
    &DisplayCtrlDiag_TFTXYShiftCtrl_STA,&DisplayCtrlDiag_TFTXYShiftCtrl_RCTE,
};
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
const DisplayCtrlDiag_IOCTL TFTAdjChessPtrnCtrlConfig =
{
    &DisplayCtrlDiag_TFTAdjChessPtrnCtrl_STA,&DisplayCtrlDiag_TFTAdjChessPtrnCtrl_RCTE,
};
#endif

#ifdef DISPLAYXYPARAMETERENABLE
const DisplayCtrlDiag_ReadWrite DisplayXYParameterConfig =
{
    &DisplayCtrlDiag_DisplayXYParameter_Read,&DisplayCtrlDiag_DisplayXYParameter_Write,
};
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
const DisplayCtrlDiag_RCTL DisplaySplSeqConfig =
{
    &DisplayCtrlDiag_DisplaySplSeq_Start,&DisplayCtrlDiag_DisplaySplSeq_Stop,&DisplayCtrlDiag_DisplaySplSeq_Res,
};
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
const DisplayCtrlAllSegmentDiag DisplayCtrlAllSegmentConfig =
{
    &DisplayCtrlDiag_All_LCD_Segment_Start,&DisplayCtrlDiag_All_LCD_Segment_Stop,
};
#endif
#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
const DisplayCtrlAllLitTFTDiag DisplayCtrlAllLitTFTConfig =
{
    &DisplayCtrlDiag_All_LIT_TFTcolor_Start,&DisplayCtrlDiag_All_LIT_TFTcolor_Stop,
};
#endif
#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
const DisplayCtrlLCDDiag_IOCTL LCDSegmentCtrlConfig =
{
    &DisplayCtrlDiag_LCDSegmentCtrl_STA,&DisplayCtrlDiag_LCDSegmentCtrl_RCTE,
};
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
const DisplayCtrlDiag_IOCTL TFTVideoCheckConfig=
{
	&DisplayCtrlDiag_TFTVideoCheck_STA,&DisplayCtrlDiag_TFTVideoCheck_RCTE,
};
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
const DisplayCtrlDiag_RCTL DisplayContentIntegrity =
{
    &DisplayCtrlDiag_DCIC_RCStart,&DisplayCtrlDiag_DCIC_RCStop,&DisplayCtrlDiag_DCIC_RCStatus,
};
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
static eDisplayRoutineStatus DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_INACTIVE;
static boolean DisplayCtrl_I2CTest_DiagRequest = FALSE;
const DisplayCtrlDiag_RCTL DisplayI2CTestConfig =
{
    &DisplayCtrlDiag_I2CTest_RCStart, &DisplayCtrlDiag_I2CTest_RCStop, &DisplayCtrlDiag_I2CTest_RCStatus,
};
const I2c_InterfaceValidationType I2c_InterfaceValidation[MAX_I2C_CHANNEL_ID]  =
{
    { CHANNEL0, I2C_GMSL1,     TRUE,},
    { CHANNEL1, I2C_PMIC1,     TRUE,},
    { CHANNEL2, I2C_RESERVED,  FALSE,},
    { CHANNEL3, I2C_RESERVED,  FALSE,},
    { CHANNEL4, I2C_RESERVED,  FALSE,},
    { CHANNEL5, I2C_RESERVED,  FALSE,},
    { CHANNEL6, I2C_RESERVED,  FALSE,},
};
static uint8 I2cSlaveChannel = 0U;
static uint8 I2cSlaveAddress = 0U;
static uint8 DisplayCtrlDiag_I2CTest_Variable = 0xFFu;
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
const DisplayTouchTest DisplayTouchTestConfig =
{
	&DisplayCtrlDiag_TouchTest_PreCondition, &DisplayCtrlDiag_TouchTest_Read, &DisplayCtrlDiag_TouchTest_Write, &DisplayCtrlDiag_TouchTest_PostCondition
};

static uint16 TouchTest_CounterMaxValue = 0U;
static uint16 TouchTest_Counter = 0U;
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
static eDisplayRoutineStatus DisplayCtrlDiag_TswI2CRead_Status = eDisplayROUTINE_INACTIVE;
static eDisplayI2CSeq_StateType TswI2CRead_I2CSeq = eDisplayI2CSeq_Idle;
static eDisplayTSWLink_StateType TswI2CRead_DiagStatus = eTSWLink_NOT_TRIGGERED;
static uint8 I2c_Sid[TSWI2C_ChCount] = {0x02U, 0x03U, 0x0AU, 0x0BU, 0x0CU, 0x0DU, 0x10U, 0x11U, 0x12U, 0x13U, 0x04U, 0x05U, 0x06U, 0x07U, 0x16U, 0x17U};
static uint8 TSW_Index = 0U;
static uint8 I2c_DataBuffer[TSWI2C_ChCount] = {0U};

const DisplayCtrlI2CRead DisplayI2CReadConfig =
{
    &DisplayCtrlDiag_TswI2CRead_RCStart, &DisplayCtrlDiag_TswI2CRead_RCStatus,
};
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
static boolean DisplayCtrl_TouchVerification_DiagRequest = FALSE;
static Std_ReturnType DisplayCtrl_TouchVerification_ReadStatus = E_NOT_OK;
static eDisplayRoutineStatus DisplayCtrlDiag_TouchVerification_Status = eDisplayROUTINE_INACTIVE;
//static uint8 TP_Data[TSV_LENGTH] = {0U};
static uint8 TP_Data[TOUCH_DATA_LENGTH];


const DisplayCtrlDiag_RCTL DisplayTouchVerificationConfig =
{
    &DisplayCtrlDiag_TouchVerification_RCStart, &DisplayCtrlDiag_TouchVerification_RCStop, &DisplayCtrlDiag_TouchVerification_RCStatus,
};
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef TFTPATTERNCTRLENABLE
/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TFTPatternCtrl_STA
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Pattern control STA (Short Term Adjustment)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTPatternControl_Duty_STA
**
** Inputs           :  Data[In]:TFT Pattern Parameter
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTPatternCtrl_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

	#ifdef MEET_GIP_ENABLED
    DiagReqType DiagReq;
    uint8 idx = 0U;
    DiagReq.ActionP = DiagActionType_IOCtrl;
    DiagReq.ServiceId = cIOC_TftPatternControl;
    DiagReq.LengthP = cIOC_TftPatternControl_DataLength + 1U;
    DiagReq.DataP[0] = 3U;
    DiagReq.DataP[1] = DiagReq.DataP[0];

    
    for(idx = 0;idx < DiagReq.LengthP;idx++)
    {
       DiagReq.DataP[idx + 1U] = Data[idx];
    }

    switch( Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              Display_TFTGIPDataReqState = eGIP_WaitForResponse;
              break;
        case eGIP_WaitForResponse:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              if(ret != DCM_E_PENDING)
              {
                  Display_TFTGIPDataReqState = eGIP_InitiateRequest;
              }
              break;
        default:
              /*No action required in default case*/
              break;
    } 
	#else

    UNUSED(ErrorCode);

    /*****************************
     * TFT Display Pattern according to input values:
     * 0x00u = Grey and color scales V1
     * 0x01u = 8 colors V1
     * 0x02u = Horizontal grey scale V1
     * 0x03u = Gamma test V1
     * 0x04u = 17 grey bars V1
     * 0x05u = 1x1 chess pattern with black line around V1
     * 0x06u = 2x2 chess pattern V1
     * 0x07u = 4x4 chess pattern V1
     * 0x08u = 8x8 chess pattern V1
     * 0x09u = 16x16 chess pattern V1
     * 0x0Au = Large chess pattern V1
     * 0x0Bu = Crosstalk 1 White on Grey128 V1
     * 0x0Cu = Crosstalk 2 Black on Grey128 V1
     * 0x0Du = Orientation check V1
     * 0x0Eu = Full area flicker pattern 1dot_1line V1
     * 0x13u = Mura setup V1
     * 0x14u = Black V1
     * 0x15u = White V1
     * 0x16u = Red V1
     * 0x17u = Green V1
     * 0x18u = Blue V1
     * 0x19u = Yellow V1
     * 0x1Au = Cyan V1
     * 0x1Bu = Magenta V1
     * 0x1Cu = Grey128 V1
     * 0x1Du = 3-level burn-in V1
     * 0x1Eu = Domains V1
     * 0x1Fu = White rectangular border of thickness 1.5mm over black screen
     * 0x20u = White rectangular border of thickness 1.5mm and white horizontal and vertical line in centre
     * For all other values set display pattern to no action
     *****************************/
    if(Data[0] <= MAX_PATTERN_NUMBER)
    {
    	//ret = Rte_Write_pp_SR_EOL_displayPattern_DisplayPatternData(Data[0]);
    }
    else
    {
    	//ret = Rte_Write_pp_SR_EOL_displayPattern_DisplayPatternData(DEFAULT_DISPLAY_PATTERN);
    }

	#endif

	return ret;
}
/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TFTPatternCtrl_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Pattern control RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Displaycontroldiag_TFTPatternControl_Duty_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTPatternCtrl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    
	#ifdef MEET_GIP_ENABLED
    DiagReqType DiagReq;

    DiagReq.ActionP = DiagActionType_IOCtrl;
    DiagReq.ServiceId = cIOC_TftPatternControl;
    DiagReq.LengthP = 1U;
    DiagReq.DataP[0] = 0U;
    switch( Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
            ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
            Display_TFTGIPDataReqState = eGIP_WaitForResponse;
            break;
        case eGIP_WaitForResponse:
            ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
            if(ret != DCM_E_PENDING)
            {
                Display_TFTGIPDataReqState = eGIP_InitiateRequest;
            }
            break;
        default:
            /*No action required in default case*/
            break;
    }  
	#else

    UNUSED(ErrorCode);

    //Setting pattern back to EOL screen as RCTE
    //ret = Rte_Write_pp_SR_EOL_displayPattern_DisplayPatternData(EOLSCREEN_DISPLAY_PATTERN);

	#endif

    return ret;
}
#endif

#ifdef TFTFULLCOLORCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTFullColorCtrl_STA
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Full color control STA (Short Term Adjustment)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTFullColorControl_STA
**
** Inputs           :  Data[In]:Red Channel,Green Channel,Blue Channel
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTFullColorCtrl_STA(uint8 *Data, uint8 *ErrorCode)
{
     
	Std_ReturnType ret = E_NOT_OK;
	#ifdef MEET_GIP_ENABLED
    MeetDiagReqType DiagReq;
    DiagReq.ActionP = DiagActionType_IOCtrl;
    DiagReq.ServiceId = cIOC_TftPatternControl;
    DiagReq.LengthP = cIOC_TftFullColorCntrl_DataLength+1;
    DiagReq.DataP[0] = MGRDIAGCDD_IOC_STA_ACTION;
	uint8 idx = 0u;    
    for(idx=1;idx < DiagReq.LengthP;idx++)
    {
        DiagReq.DataP[idx] = Data[idx-1];
    }
  	
    
    switch(Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
            ret = Meet_Process_Gip_Diag_Request(Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
            Display_TFTGIPDataReqState = eGIP_WaitForResponse;
            break;
         case eGIP_WaitForResponse:
             ret = Meet_Process_Gip_Diag_Request(Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
             if(ret != DCM_E_PENDING)
             {
                 Display_TFTGIPDataReqState = eGIP_InitiateRequest;
             }
             break;
          default:
              /*No action required in default case*/
              break;
    }   
	 
   	#else
	{
  
	ret = E_OK;
    }
	#endif

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTFullColorCtrl_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Full color control RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTFullColorControl_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTFullColorCtrl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
	#ifdef MEET_GIP_ENABLED
    MeetDiagReqType DiagReq;
    
    DiagReq.ActionP = DiagActionType_IOCtrl;
    DiagReq.ServiceId = cIOC_TftFullColorCntrl;
    DiagReq.LengthP = 1;
    DiagReq.DataP[0] = MGRDIAGCDD_IOC_RCTE_ACTION;
    
    		
    switch(Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
            ret = Meet_Process_Gip_Diag_Request(Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
            Display_TFTGIPDataReqState = eGIP_WaitForResponse;
            break;
        case eGIP_WaitForResponse:
            ret = Meet_Process_Gip_Diag_Request(Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
            if(ret != DCM_E_PENDING)
            {
               Display_TFTGIPDataReqState = eGIP_InitiateRequest;
            }
            break;
        default:
        	/*No action required in default case*/
            break;
    }  
   	#else
	{
  
	ret = E_OK;
    }
	#endif

    return ret;
}
#endif

#ifdef TFTONEDOTCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTOneDotCtrl_STA
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT one dot update control STA (Short Term Adjustment)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTOneDotUpdateControl_STA
**
** Inputs           :  Data[In]:X,Y Co-ordinate,Red Channel,Green Channel,Blue Channel
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTOneDotCtrl_STA(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with functionality/RTE*/
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTOneDotCtrl_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT one dot update control RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTOneDotUpdateControl_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTOneDotCtrl_RCTE(uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with functionality/RTE*/
}
#endif

#ifdef TFTXYSHIFTCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTXYShiftCtrl_STA
**
** Visibility       :  Private 
**
** Description      :  checks if X and Y Shift values specified are within defined bounds and then calls the API to do TFT XY Shift control STA (Short Term Adjustment).
**					   if X and Y Shift values are out of bounds , request out of range is responded
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTXYShiftControl_STA
**
** Inputs           :  Data[In]: Shift Area ID,X axis shift, Y axis shift,rotation(in 100th of degree)
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTXYShiftCtrl_STA(uint8 *Data, uint8 *ErrorCode)
{
 return E_OK; /*to be replaced with RTE*/
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTXYShiftCtrl_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT  XY Shift control RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTXYShiftControl_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTXYShiftCtrl_RCTE(uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with functionality/RTE*/
}
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTAdjChessPtrnCtrl_STA
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Adjustable chessboard pattern STA (Short Term Adjustment)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTAdjustableChessboardPatternControl_STA
**
** Inputs           :  Data[In]: Pattern type,X Axis size,Y Axis size, 2 RGB Colour values
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTAdjChessPtrnCtrl_STA(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with functionality/RTE*/
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTAdjChessPtrnCtrl_RCTE
**
** Visibility       :  Private 
**
** Description      :  calls the API to do TFT Adjustable chessboard pattern RCTE(Return control to ECU)
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTAdjustableChessboardPatternControl_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**					   
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTAdjChessPtrnCtrl_RCTE(uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with functionality/RTE*/
}
#endif

#ifdef DISPLAYXYPARAMETERENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DisplayXYParameter_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read the X Y Parameter values from NVM and converts 8 bit values to 16 bit
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DisplayXYParameterReading_Read
**
** Inputs           :  Data[out]:contains X Shift Parameter and Y Shift Parameter in signed 2's complement format
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DisplayXYParameter_Read(uint8 *Data)
{
 return E_OK; /*to be replaced with RTE*/
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DisplayXYParameter_Write
**
** Visibility       :  Private 
**
** Description      :  checks if X,Y Parameters are within bounds and calls API to write the X Y Parameter values to NVM and converts 16 bit values to 8 bit
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DisplayXYParameterReading_Write
**
** Inputs           :  Data[in]:contains X Shift Parameter and Y Shift Parameter in signed 2's complement format
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DisplayXYParameter_Write(uint8 *Data,uint8 *ErrorCode)
{
 return E_OK; /*to be replaced with RTE*/
}
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DisplaySplSeq_Start
**
** Visibility       :  Private 
**
** Description      :  calls API to start Display special sequence execution
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DisplaySpecialSequencesExecution_RCStart
**
** Inputs           :  Data[in]:Display Sequence ID
**					   Data[out]:status of routine control start					   
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Start(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with RTE*/
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DisplaySplSeq_Stop
**
** Visibility       :  Private 
**
** Description      :  updates routine stop record
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DisplaySpecialSequencesExecution_RCStop
**
** Inputs           :  Data[out]:routine stop record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Stop(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with RTE*/
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DisplaySplSeq_Res
**
** Visibility       :  Private 
**
** Description      :  updates routine status record
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DisplaySpecialSequencesExecution_RCStatus
**
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DisplaySplSeq_Res(uint8 *Data, uint8 *ErrorCode)
{
    return E_OK; /*to be replaced with RTE*/
}
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_All_LCD_Segment_Start
**
** Visibility       :  Private
**
** Description      :  API provided for All LCD segment, this function invoke corresponding All segment ON LCD function
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_LCDAllSegmentControl_RCStart
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_All_LCD_Segment_Start(uint8 *Data, uint8 *ErrorCode)
{
return(1);
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_All_LCD_Segment_Stop
**
** Visibility       :  Private
**
** Description      :  API provided for All LCD segment, this function invoke corresponding All segment OFF LCD function
**
** Invocation       :  Displaycontrol.diagcdd, Function:DDisplaycontroldiag_LCDAllSegmentControl_RCStop
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_All_LCD_Segment_Stop(uint8 *Data, uint8 *ErrorCode)
{
return(1);
}
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_All_LIT_TFTcolor_Start
**
** Visibility       :  Private
**
** Description      : API provided for All Lit TFT Color, this function invoke corresponding Color enable in TFT
**
** Invocation       :  Displaycontrol.diagcdd, Function:DDisplaycontroldiag_LCDAllSegmentControl_RCStop
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_All_LIT_TFTcolor_Start(uint8 *Data, uint8 *ErrorCode)
{
	return(1);
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_All_LCD_Segment_Stop
**
** Visibility       :  Private
**
** Description      :  API provided for All Lit TFT Color, this function invoke the function of  TFT Screen goes to blank
**
** Invocation       :  Displaycontrol.diagcdd, Function:DDisplaycontroldiag_LCDAllSegmentControl_RCStop
**
** Inputs           :  Data[out]:Segments ON status data
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_All_LIT_TFTcolor_Stop(uint8 *Data, uint8 *ErrorCode)
{
	return(1);
}
#endif
#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_LCDSegmentCtrl_STA
**
** Visibility       :  Private
**
** Description      :  calls the API to do LCD Segment control STA (Short Term Adjustment)
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_TFTPatternControl_Duty_STA
**
** Inputs           :  Data[In]:LCD Segment Parameter
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_LCDSegmentCtrl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret=E_OK;
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_LCDSegmentCtrl_RCTE
**
** Visibility       :  Private
**
** Description      :  calls the API to do LCD segment control return to normal
**
** Invocation       :  Displaycontrol.diagcdd, Displaycontroldiag_LCDSegmentControl_Duty_STA
**
** Inputs           :  Data[In]:
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_LCDSegmentCtrl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret=E_OK;
    return ret;
}
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTVideoCheck_STA
**
** Visibility       :  Private
**
** Description      :  calls the API to check the video hardware interface
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_VideoCheck_STA
**
** Inputs           :  Data[In]:NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTVideoCheck_STA(uint8 *Data, uint8 *ErrorCode)
{
	UNUSED(Data);
	UNUSED(ErrorCode);

	Std_ReturnType ret = E_NOT_OK;

	//ret = Rte_Call_rp_CS_VideoControl_EOL_Request_Video(StartVideo);

	return ret;
}
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_TFTVideoCheck_RCTE
**
** Visibility       :  Private
**
** Description      :  calls the API to display previous screen
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_VideoCheck_RCTE
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TFTVideoCheck_RCTE(uint8 *ErrorCode)
{
	UNUSED(ErrorCode);

	Std_ReturnType ret = E_NOT_OK;

	//ret = Rte_Call_rp_CS_VideoControl_EOL_Request_Video(StopVideo);

	return ret;
}
#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStart
**
** Visibility       :  Private 
**
** Description      :  calls API to start checking the checksum of the image
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStart
**
** Inputs           :  Data[in]:Display checksum ID
**					   Data[out]:status of routine control start					   
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
	#ifdef MEET_GIP_ENABLED

    uint32 fl_chcksum_val_U32 = 0;
    uint8 idx = 0;
    MeetDiagReqType DiagReq;
    // SDiagResponse_t DiagResp;
     
    DiagReq.ActionP = DiagActionType_RoutineCtrl;
    DiagReq.ServiceId = (uint16)cIOC_DCICRoutine;
    DiagReq.LengthP = cIOC_DCICRoutine_DataLength;
    DiagReq.DataP[0] = MGRDIAGCDD_ROC_START_ACTION;
    
    for(idx = 1U;idx < DiagReq.LengthP;idx++)
    {
       DiagReq.DataP[idx] = Data[idx-1U];
    }
    if(Data[idx-1U] == 0U)
    {
        fl_chcksum_val_U32 = DCIC_VALID_CHECKSUM;
    }
    else
    {
        fl_chcksum_val_U32 = DCIC_INVALID_CHECKSUM;
    }
    DiagReq.DataP[2] = (uint8)(fl_chcksum_val_U32>>24);
    DiagReq.DataP[3] = (uint8)(fl_chcksum_val_U32>>16);
    DiagReq.DataP[4] = (uint8)(fl_chcksum_val_U32>>8);
    DiagReq.DataP[5] = (uint8)(fl_chcksum_val_U32);

    switch( Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              Display_TFTGIPDataReqState = eGIP_WaitForResponse;
              break;
        case eGIP_WaitForResponse:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              if(ret != DCM_E_PENDING)
              {
                  if(DCM_E_OK == ret)
                {
                    // DiagResp = *Diag_TIGIP_GetDiagResponse();
                    // if(1u == DiagResp.Length)
                    // {
                        Data[0] = DiagReq.DataP[1];//DiagResp.DiagRespBuffer[0];
                        ret = E_OK;
                    // }
                    // else
                    // {
                    //     //Size mismatch
                    //     ret = DCM_E_NOT_OK;
                    // }
                }
                else
                {
                     /* no  action*/
                }
                
                  Display_TFTGIPDataReqState = eGIP_InitiateRequest;
              }
              else
              {
            /* no  action*/                  
              }
              

              break;
        default:
              /*No action required in default case*/
              break;
    }   
	#endif
    return ret;

}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStop
**
** Visibility       :  Private 
**
** Description      :  updates routine stop record
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStop
**
** Inputs           :  Data[out]:routine stop record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
	#ifdef MEET_GIP_ENABLED

    MeetDiagReqType DiagReq;
     
    DiagReq.ActionP = DiagActionType_RoutineCtrl;
    DiagReq.ServiceId = cIOC_DCICRoutine;
    DiagReq.LengthP = 1;
    DiagReq.DataP[0] = MGRDIAGCDD_ROC_STOP_ACTION;
    
    for(int idx=1;idx < DiagReq.LengthP;idx++)
    {
       DiagReq.DataP[idx] = Data[idx];
    }

    switch( Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              Display_TFTGIPDataReqState = eGIP_WaitForResponse;
              break;
        case eGIP_WaitForResponse:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              if(ret != DCM_E_PENDING)
              {
                  Display_TFTGIPDataReqState = eGIP_InitiateRequest;
              }
              else
              {
            /* no  action*/                  
              }
              
              break;
        default:
            /* no  action*/
              break;
    }   
    #endif
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStatus
**
** Visibility       :  Private 
**
** Description      :  updates routine status record
**                      
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStatus
**
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_DCIC_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
	#ifdef MEET_GIP_ENABLED
    DiagReqType DiagReq;
    // SDiagResponse_t DiagResp;
	uint8 idx = 0u;     
    DiagReq.ActionP = DiagActionType_RoutineCtrl;
    DiagReq.ServiceId = cIOC_DCICRoutine;
    DiagReq.LengthP = cIOC_DCICRoutine_DataLength+1;
    DiagReq.DataP[0] = MGRDIAGCDD_ROC_RESULTS_ACTION;
    
    for(idx=1U;idx < DiagReq.LengthP;idx++)
    {
       DiagReq.DataP[idx] = Data[idx];
    }

    switch( Display_TFTGIPDataReqState)
    {
        case eGIP_InitiateRequest:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              Display_TFTGIPDataReqState = eGIP_WaitForResponse;
              break;
        case eGIP_WaitForResponse:
              ret = Meet_Process_Gip_Diag_Request( Display_TFTGIPDataReqState, &DiagReq, ErrorCode);
              if(ret != DCM_E_PENDING)
              {
                if(DCM_E_OK == ret)
                {
                    // DiagResp = *Diag_TIGIP_GetDiagResponse();
                    // if(2u == DiagResp.Length)
                    // {
                        Data[0] = DiagReq.DataP[1];
                        Data[1] = eROUTINE_FINISH_OK;
                        ret = E_OK;
                    // }
                    // else
                    // {
                    //     //Size mismatch
                    //     ret = DCM_E_NOT_OK;
                    // }
                }
                else if ( ret == 34u)
                {
                    Data[0] = DiagReq.DataP[1];
                    Data[1] = eROUTINE_FINISH_NOK;
                    ret = E_OK;
                }
                  Display_TFTGIPDataReqState = eGIP_InitiateRequest;
              }
              else
              {
                /* no  action*/
              }
              break;
        default:
            /* no  action*/
              break;
    }   
#endif
    return ret;
}
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStart
**
** Visibility       :  Private
**
** Description      :  calls API to start checking the checksum of the image
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStart
**
** Inputs           :  Data[in]:Display checksum ID
**					   Data[out]:status of routine control start
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(eDisplayROUTINE_INPROGRESS == DisplayCtrlDiag_I2CTest_Status)
    {
    	/*Already Routine in progress*/
    	*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }
    else
    {
        if(Data[0] < MAX_I2C_CHANNEL_ID)
        {
            if((FALSE != I2c_InterfaceValidation[Data[0]].ActiveStatus) && (Data[1] == I2c_InterfaceValidation[Data[0]].SlaveAddress) && (Data[1] != I2C_RESERVED))
            {
                if(I2c_GetSequenceResult(Data[0]) == E_OK)
                {
                    I2cSlaveChannel = Data[0];
                    I2cSlaveAddress = Data[1];
                    DisplayCtrl_I2CTest_DiagRequest = TRUE;
                    DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_INPROGRESS;
                    Data[DATA_BYTE_0] = DisplayCtrlDiag_I2CTest_Status;
                    ret = E_OK;
                }
                else
                {
    	            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
        }
    }   
 
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStop
**
** Visibility       :  Private
**
** Description      :  updates routine stop record
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStop
**
** Inputs           :  Data[out]:routine stop record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStop(uint8 *Data, const uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    (void)ErrorCode;

    if (Data != NULL_PTR)
    {
        DisplayCtrl_I2CTest_DiagRequest = FALSE;
        DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_TesterSTOPPED;

    Data[DATA_BYTE_0] = (uint8)DisplayCtrlDiag_I2CTest_Status;

        ret = E_OK;
    }
    else
    {

    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  DisplayCtrlDiag_DCIC_RCStatus
**
** Visibility       :  Private
**
** Description      :  updates routine status record
**
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStatus
**
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_I2CTest_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DisplayCtrlDiag_I2CTest_Status == eDisplayROUTINE_INPROGRESS)
    {
        *ErrorCode = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
    }
    else if ((DisplayCtrlDiag_I2CTest_Status == eDisplayROUTINE_FINISH_OK) || 
             (DisplayCtrlDiag_I2CTest_Status == eDisplayROUTINE_FINISH_NOK))
    {
        Data[DATA_BYTE_0] = DisplayCtrlDiag_I2CTest_Status;
        Data[DATA_BYTE_1] = I2cSlaveChannel;
        Data[DATA_BYTE_2] = I2cSlaveAddress;
        Data[DATA_BYTE_3] = DisplayCtrlDiag_I2CTest_Variable;

        DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_INACTIVE;
        DisplayCtrl_I2CTest_DiagRequest= FALSE;

        ret = E_OK;    
    }
    else
    {
    	/*Routine not started*/
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TouchTest_Task
**
** Visibility       :  Public
**
** Description      :  This is runnable function for touch test routine
**
** Invocation       :  MeetMgr.diagcdd - Function : CmpActive
**
** Inputs           :  void
**
** Outputs          :  void
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
void Displaycontroldiag_I2CTest_Task(void)
{
    static uint8 TxBufferI2c[3u] = {0};
    static uint8 RxBufferI2c[3u] = {0};
    static uint16 TxBufferLengthI2C = 3u;
    static uint16 RxBufferLengthI2C = 3u;
    Std_ReturnType ret = E_NOT_OK;
	if(DisplayCtrl_I2CTest_DiagRequest == TRUE)
	{
        
        ret = I2c_GetSequenceResult(I2cSlaveChannel);
        if(E_OK == ret)
        {
            ret = I2c_SetupEB(I2cSlaveChannel,TxBufferI2c,RxBufferI2c,TxBufferLengthI2C,RxBufferLengthI2C,I2cSlaveAddress);
            if(ret == E_OK)
            {
            /* Async Mode */
              //  ret = I2c_AsyncTransmit(I2cSlaveChannel);
                if(ret == E_OK)
                {
                    DisplayCtrlDiag_I2CTest_Variable = 0x01U;
                    DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_FINISH_OK;
                 }
                else
                {
                    DisplayCtrlDiag_I2CTest_Variable = 0x00U;
                    DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_FINISH_NOK;
                }
            }
            else
            {
                DisplayCtrlDiag_I2CTest_Variable = 0x00U;
                DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_FINISH_NOK;
            }	
            DisplayCtrl_I2CTest_DiagRequest= FALSE;

        }
        else
        {
            DisplayCtrlDiag_I2CTest_Status = eDisplayROUTINE_INPROGRESS;
        }	
    }
}
#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
static Std_ReturnType DisplayCtrlDiag_TouchTest_PreCondition(uint8 *ErrorCode)
{
	Std_ReturnType ret = E_NOT_OK, retDio = E_NOT_OK, retAdc = E_NOT_OK;
	boolean DioPinStatus = FALSE;
	uint8 locErrorCode = IOHWAB_E_ERROR, ErrorCodeDio = IOHWAB_E_ERROR, ErrorCodeAdc = IOHWAB_E_ERROR;
	sint32 AdcValue = 0;
	uint16 Read_adc_voltage = 0U;

	TouchTest_Counter++;

	if(TouchTest_Counter <= TouchTest_CounterMaxValue)
	{
		/*Get IGN status*/
		//retDio = Rte_Call_rp_CS_IoHwAb_Din_GetProcessedInput(eIO_Din_IGN_INT, &DioPinStatus, &ErrorCodeDio);

		/*Get battery voltage*/
		//retAdc = Rte_Call_rp_CS_IoHwAb_ADC_GetProcessedAdc(eIO_ADC_BATT_MON, &AdcValue, &ErrorCodeAdc);

		ret = (retDio | retAdc);

		locErrorCode = (ErrorCodeDio | ErrorCodeAdc);

		if(((uint8)E_OK == ret) && ((uint8)IOHWAB_E_NO_ERROR == locErrorCode))
		{
			Read_adc_voltage = (uint16)AdcValue;

			/*Check battery supply is in appropriate range and whether IGNITION is ON*/
			if((Read_adc_voltage >= MIN_BATTERY_VOLTAGE) && (Read_adc_voltage <= MAX_BATTERY_VOLTAGE) && ((boolean)TRUE == DioPinStatus))
			{
				ret = E_OK;
				*ErrorCode = DCM_E_OK;
			}
			else
			{
				ret = E_NOT_OK;
				*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			}
		}
		else
		{
			ret = E_NOT_OK;
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
		}
	}

	return ret;
}
// static Std_ReturnType DisplayCtrlDiag_TouchTest_Read(uint8 *Data)
// {
// 	Std_ReturnType ret = E_NOT_OK;

// 	return ret;
// }
static Std_ReturnType DisplayCtrlDiag_TouchTest_Write(uint8 *Data)
{
	Std_ReturnType ret = E_OK;

	/* Data[0] - Value received in Seconds
	 * This value is used in Displaycontroldiag_TouchTest_Task(), Which is called at every 10ms from CmpActive()
	 * Convert into MS*/

	TouchTest_CounterMaxValue = (uint16)(Data[0] * 100U);

	return ret;
}

static void DisplayCtrlDiag_TouchTest_PostCondition(void)
{
	TouchTest_Counter = 0U; /*Reset TouchTest Counter*/
}
#endif
#ifdef DISPLAY_TOUCH_TEST_CHECK
static Std_ReturnType DisplayCtrlDiag_TouchTest_Read(uint8 *Data)
{
    (void)Data;
	Std_ReturnType ret = E_NOT_OK;

	return ret;
}
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TswI2CRead_RCStart
** Visibility       :  Private
** Description      :  calls API to start checking the checksum of the image
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStart
** Inputs           :  Data[in]:Display checksum ID
**					   Data[out]:status of routine control start
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TswI2CRead_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(eDisplayROUTINE_INPROGRESS == DisplayCtrlDiag_TswI2CRead_Status)
    {
        /*Already Routine in progress*/
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	}
    else
    {
    	TswI2CRead_I2CSeq = eDisplayI2CSeq_Write;
    	DisplayCtrlDiag_TswI2CRead_Status = eDisplayROUTINE_INPROGRESS;
        ret = E_OK;
    }
    return ret;
}

/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TswI2CRead_RCStatus
** Visibility       :  Private
** Description      :  updates routine status record
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStatus
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TswI2CRead_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(eDisplayROUTINE_FINISH_OK == DisplayCtrlDiag_TswI2CRead_Status)
    {
        //Filling Data buffer
        Data[0] = (uint8)DisplayCtrlDiag_TswI2CRead_Status;
        for(uint8 Data_index = 0u; Data_index < TSWI2C_ChCount; Data_index++)
        {
            Data[Data_index + 1u] = I2c_DataBuffer[Data_index];
        }
    	ret = E_OK;
    }
    else if(eDisplayROUTINE_INACTIVE != DisplayCtrlDiag_TswI2CRead_Status)
    {
    	/*Routine not started*/
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = E_NOT_OK;
    }
    else
    {
        /*Routine started failed or inprogress*/
		*ErrorCode = TswI2CRead_DiagStatus;
        ret = E_NOT_OK;
    }
    return ret;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TswI2CRead_Task
** Visibility       :  Public
** Description      :  This is runnable function for touch switch I2C read routine
** Invocation       :  MeetMgr.diagcdd - Function : CmpActive
** Inputs           :  void
** Outputs          :  void
** Critical Section :  Yes/No
**====================================================================================================================*/
void Displaycontroldiag_TswI2CRead_Task(void)
{
	if(TswI2CRead_I2CSeq == eDisplayI2CSeq_Write)
    {
        Displaycontroldiag_I2C_WriteSeq();
    }
    else if(TswI2CRead_I2CSeq == eDisplayI2CSeq_Read)
    {
        Displaycontroldiag_I2C_ReadSeq();
    }
    else if(TswI2CRead_I2CSeq == eDisplayI2CSeq_Error)
    {
        TswI2CRead_DiagStatus = eTSWLink_ERROR;
    }
    else
    {
        /*Do Nothing*/
    }
    return;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_I2C_WriteSeq
** Visibility       :  Private
** Description      :  updates routine status record
** Invocation       :  Displaycontroldiagcdd_cfg, Function:Displaycontroldiag_TswI2CRead_Task
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section :  Yes/No
**====================================================================================================================*/
void Displaycontroldiag_I2C_WriteSeq(void)
{
    if(TSW_Index < TSWI2C_ChCount)
    {
        if(E_OK == I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_TOUCH_SW, &I2c_Sid[TSW_Index], NULL, TSWI2C_I2CLENGTH))
        {
            if(E_OK == I2c_AsyncTransmit(I2cConf_I2cSequence_I2cSequence_TOUCH_SW))
            {
                TswI2CRead_DiagStatus = eTSWLink_PROGRESS;
            }
            else
            {
                TswI2CRead_DiagStatus = eTSWLink_Failed;
            }
        }
        else
        {
            TswI2CRead_DiagStatus = eTSWLink_Failed;
        }
    }
    else if(TSW_Index == TSWI2C_ChCount)
    {
        TswI2CRead_I2CSeq = eDisplayI2CSeq_Idle;
        TswI2CRead_DiagStatus = eTSWLink_COMPLETED;
        DisplayCtrlDiag_TswI2CRead_Status = eDisplayROUTINE_FINISH_OK;
    }
    else
    {
        /*Do Nothing*/
    }
    return;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_I2C_ReadSeq
** Visibility       :  Private
** Description      :  updates routine status record
** Invocation       :  Displaycontroldiagcdd_cfg, Function:Displaycontroldiag_TswI2CRead_Task
** Inputs           :  void
** Outputs          :  void
** Critical Section :  Yes/No
**====================================================================================================================*/
void Displaycontroldiag_I2C_ReadSeq(void)
{
    if(E_OK == I2c_SetupEB(I2cConf_I2cChannel_I2cChannel_TOUCH_SW, NULL, &I2c_DataBuffer[TSW_Index], TSWI2C_I2CLENGTH))
    {
        if(E_OK == I2c_AsyncTransmit(I2cConf_I2cSequence_I2cSequence_TOUCH_SW))
        {
            TswI2CRead_DiagStatus = eTSWLink_PROGRESS;
            if(TSW_Index < TSWI2C_ChCount)
            {
                TSW_Index = TSW_Index + 1U;
            }
        }
        else
        {
            TswI2CRead_DiagStatus = eTSWLink_Failed;
        }
    }
    else
    {
        TswI2CRead_DiagStatus = eTSWLink_Failed;
    }
    return;
}

void Displaycontroldiag_TOUCH_SW_I2cSeqEndCallback(void)
{
    if(TswI2CRead_I2CSeq == eDisplayI2CSeq_Write)
	{
		TswI2CRead_I2CSeq = eDisplayI2CSeq_Read;
	}
	else if(TswI2CRead_I2CSeq == eDisplayI2CSeq_Read)
	{
		TswI2CRead_I2CSeq = eDisplayI2CSeq_Write;
	}
    else
    {
        /*Do Nothing*/
    }
    return;
}

void Displaycontroldiag_TOUCH_SW_I2cSeqErrorCallback(void)
{
    TswI2CRead_I2CSeq = eDisplayI2CSeq_Error;
    TswI2CRead_DiagStatus = eTSWLink_ERROR;
    return;
}
#endif
#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TouchVerification_RCStart
** Visibility       :  Private
** Description      :  Start Reading touch coordinates data from TouchCdd
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStart
** Inputs           :  Data[in]:Display checksum ID
**					   Data[out]:status of routine control start
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(eDisplayROUTINE_INPROGRESS == DisplayCtrlDiag_TouchVerification_Status)
    {
        /*Already Routine in progress*/
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        Data[DATA_BYTE_0] = 0x00U;
    }
    else
    {
        DisplayCtrl_TouchVerification_DiagRequest = TRUE;
	    DisplayCtrlDiag_TouchVerification_Status = eDisplayROUTINE_INPROGRESS;
        Data[DATA_BYTE_0] = 0x01U;
	    ret = E_OK;
	}
    return ret;
}

/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TouchVerification_RCStop
** Visibility       :  Private
** Description      :  Stop Reading touch coordinates data from TouchCdd
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStop
** Inputs           :  Data[out]:routine stop record
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    DisplayCtrl_TouchVerification_DiagRequest = FALSE;
    DisplayCtrlDiag_TouchVerification_Status = eDisplayROUTINE_TesterSTOPPED;
    Data[DATA_BYTE_0] = 0x01U;
    ret = E_OK;
    return ret;
}

/*=====================================================================================================================
** Function Name    :  DisplayCtrlDiag_TouchVerification_RCStatus
** Visibility       :  Private
** Description      :  updates routine status record
** Invocation       :  Displaycontrol.diagcdd, Function:Displaycontroldiag_DCIC_RCStatus
** Inputs           :  Data[out]:routine status record
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
static Std_ReturnType DisplayCtrlDiag_TouchVerification_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if(eDisplayROUTINE_INACTIVE != DisplayCtrlDiag_TouchVerification_Status)
    {
        if(DisplayCtrl_TouchVerification_ReadStatus == (Std_ReturnType)E_OK)
        {
    	    DisplayCtrlDiag_TouchVerification_Status = eDisplayROUTINE_FINISH_OK;
            (void) MemLib_MemCpy( &Data[0U], &TP_Data[0U], TSV_LENGTH);
    	    ret = E_OK;
        }
        else
        {
            DisplayCtrlDiag_TouchVerification_Status = eDisplayROUTINE_FINISH_NOK;
            ret = E_NOT_OK;
        }
    }
    else
    {
    	/*Routine not started*/
		*ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }

    DisplayCtrl_TouchVerification_DiagRequest = FALSE;
    DisplayCtrl_TouchVerification_ReadStatus = E_NOT_OK;
    return ret;
}

void DisplayCtrlDiag_TouchPanelCtrl_ReadConversion(uint8 *pu8_Touch_Data)
{
    if(DisplayCtrl_TouchVerification_DiagRequest == TRUE)
    {
        (void) MemLib_MemCpy( &TP_Data[0U], pu8_Touch_Data, sizeof(TP_Data));
        DisplayCtrl_TouchVerification_ReadStatus = E_OK;
    }
    else
    {
        /*Do Nothing*/
    }
    return;
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
** Date              :  17/April/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1985454
** Change Description:  Touch Screen Verification Routine Services are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  15/Mar/2023
** CDSID             :  mprajapa
** Traceability      :  RTC-1951989
** Change Description:  I2C-Read Related Configuration is added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Touch-Test Related Configuration is added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  20/Jun/2022
** CDSID             :  kkarupp1
** Traceability      :  RTC-1670983
** Change Description: Display Content Verification DR added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/09/2019
** CDSID             :  vsupraja
** Traceability      :  RTC 1372600
** Change Description:  VIP MEET - Fix MISRA warnings
**====================================================================================================================*/
/**====================================================================================================================
** Date              :  10/09/2019
** CDSID             :  vsupraja
** Traceability      :  RTC 1367817
** Change Description:  Updated DCIC routine status - VIP
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  10/09/2019
** CDSID             :  vsupraja
** Traceability      :  RTC 1367486
** Change Description:  P33 : DCIC result routine update in VIP
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 
** Change Description:  Display content integrity check(SIG unit check) service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/02/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1263596
** Change Description:  vip - gip communication implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/1/2019
** CDSID             :  athiyag2
** Traceability      :  RTC 1265368
** Change Description:  compiler warning fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  20/9/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1195633
** Change Description:  Video check function added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1148635
** Change Description: LCD segment control with or with out illumination
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 11/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit All Segment LCD ON /OFF API  function implemented
** 					   All Lit All TFT color control API  function implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1137720
** Change Description:  warning fixed
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  6/6/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1113505
** Change Description:  Initial version - DisplaycontrolDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 11/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit All Segment LCD ON /OFF API  function implemented
** 					   All Lit All TFT color control API  function implemented
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1148635
** Change Description: LCD segment control with or with out illumination
**====================================================================================================================*/

#endif
