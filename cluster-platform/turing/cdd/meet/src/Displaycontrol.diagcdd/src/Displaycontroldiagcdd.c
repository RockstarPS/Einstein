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
** Name:           Displaycontroldiagcdd.c
**
** Description:    contains display control related services.checks if software in Manufacturing mode before executing service request
**
**
**===================================================================================================================*/

#ifndef DISPLAYCONTROLDIAGCDD_C
#define DISPLAYCONTROLDIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Displaycontroldiagcdd.h"
#include "Displaycontroldiagcdd_cfg.h"
#ifdef TFT_CONTROL_WITH_DUTY
#include "Ioctrlrd_pwm_diagcdd_cfg.h"
#endif
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef DISPLAY_TOUCH_TEST_CHECK
static eDisplayRoutineStatus DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_INACTIVE;
static boolean DisplayCtrl_TouchTest_DiagRequest = FALSE;
static uint8 TouchTest_ResultStatus[DISPLAY_TOUCH_TEST_RESULT] = {0U};
#endif

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef TFTPATTERNCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTPatternControl_Duty_STA
**
** Visibility       :  Public
**
** Description      :  allows to display some defined patterns either from memory or dynamically generated ,
** 					   This function will invoke API for TFT pattern control
**                     If Required to control TFT patterns should configure macro TFTPATTERNCTRLENABLE in Mgrdiagcdd.h
**                     If required to control TFT patterns as well illumination should configure macro TFT_CONTROl_WITH_DUTY in Mgrdiagcdd.h
**                     and TFTPATTERNCTRLENABLE in Mgrdiagcdd.h
**                     and Corresponding illumination RTE should be place in  Ioctrlrd_pwm_diagcdd_cfg.c file
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD0D
**
** Inputs           :  Data[In]:TFT Pattern Parameter
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTPatternControl_Duty_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTPatternCtrlConfig.DisplayCtrlDiag_STA(Data, ErrorCode);

        #ifdef TFT_CONTROL_WITH_DUTY
        Meet_DimmingControlConfig[TFT_DUTY_CONTREOL_CHANNEL].DimmingControlFunction(Data[TFT_DUTY_CONTROL_BYTE]);
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTPatternControl_Duty_RCTE
**
** Visibility       :  Public
**
** Description      :  This function will invoke API for TFT pattern control to ECU
**                     If Required to control TFT patterns should configure macro TFTPATTERNCTRLENABLE in Mgrdiagcdd.h
**                     If required to control TFT patterns as well illumination should configure macro TFT_CONTROl_WITH_DUTY in Mgrdiagcdd.h
**                     and TFTPATTERNCTRLENABLE in Mgrdiagcdd.h
**                     and Corresponding illumination RTE should be place in  Ioctrlrd_pwm_diagcdd_cfg.c file
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD0D
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTPatternControl_Duty_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        ret = TFTPatternCtrlConfig.DisplayCtrlDiag_RCTE(ErrorCode);
        #ifdef TFT_CONTROL_WITH_DUTY
        Meet_DimmingControlConfig[TFT_DUTY_CONTREOL_CHANNEL].DimmingControlFunction(0);
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef TFTFULLCOLORCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTFullColorControl_STA
**
** Visibility       :  Public
**
** Description      :  allows to display a colour on the display area defined in RGB
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD0E
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
Std_ReturnType Displaycontroldiag_TFTFullColorControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTFullColorCtrlConfig.DisplayCtrlDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTFullColorControl_RCTE
**
** Visibility       :  Public
**
** Description      :  Returns TFT Full Color Control to ECU
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD0E
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTFullColorControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTFullColorCtrlConfig.DisplayCtrlDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TFTONEDOTCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTOneDotUpdateControl_STA
**
** Visibility       :  Public
**
** Description      :  allow to update the current pattern displayed by setting one dot on coordinates X-Y to a RGB level defined
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD0F
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
Std_ReturnType Displaycontroldiag_TFTOneDotUpdateControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTOneDotCtrlConfig.DisplayCtrlDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTOneDotUpdateControl_RCTE
**
** Visibility       :  Public
**
** Description      :  returns TFT OneDot Update Control to ECU
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD0F
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTOneDotUpdateControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTOneDotCtrlConfig.DisplayCtrlDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TFTXYSHIFTCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTXYShiftControl_STA
**
** Visibility       :  Public
**
** Description      :  allows to shift current controlled pattern in accordance with X ,Y Axis shift provided
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD10
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
Std_ReturnType Displaycontroldiag_TFTXYShiftControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTXYShiftCtrlConfig.DisplayCtrlDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTXYShiftControl_RCTE
**
** Visibility       :  Public
**
** Description      :  returns TFT XY Shift control to ECU
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD10
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTXYShiftControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTXYShiftCtrlConfig.DisplayCtrlDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef TFTADJCHESSPTRNCTRLENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTAdjustableChessboardPatternControl_STA
**
** Visibility       :  Public
**
** Description      :  allows to do pixel chessboard and reverse chessboard with cell area size adjustable and with configurable colors
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_STA_Diag_FD11
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
Std_ReturnType Displaycontroldiag_TFTAdjustableChessboardPatternControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTAdjChessPtrnCtrlConfig.DisplayCtrlDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTAdjustableChessboardPatternControl_RCTE
**
** Visibility       :  Public
**
** Description      :  returns Chessboard Pattern Control to ECU
**
** Invocation       :  MeetMgr.diagcdd, Function:IOCTL_RCTE_Diag_FD11
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTAdjustableChessboardPatternControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTAdjChessPtrnCtrlConfig.DisplayCtrlDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef DISPLAYXYPARAMETERENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DisplayXYParameterReading_Read
**
** Visibility       :  Public
**
** Description      :  Reads X Shift and Y Shift parameters and checks if value within bounds
**
** Invocation       :  MeetMgr.diagcdd, Function:Read_Diag_FA50
**
** Inputs           :  Data[out]:contains X Shift Parameter and Y Shift Parameter in signed 2's complement format
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_DisplayXYParameterReading_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayXYParameterConfig.DisplayCtrlDiag_Read(Data);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DisplayXYParameterReading_Write
**
** Visibility       :  Public
**
** Description      :  Configures XShift and YShift parameter
**
** Invocation       :  MeetMgr.diagcdd, Function:Write_Diag_FA50
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
Std_ReturnType Displaycontroldiag_DisplayXYParameterReading_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayXYParameterConfig.DisplayCtrlDiag_Write(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef DISPLAYSPLSEQEXEENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DisplaySpecialSequencesExecution_RCStart
**
** Visibility       :  Public
**
** Description      : allow to perform TFT control validations
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_START_Diag_F116
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
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplaySplSeqConfig.DisplayCtrlDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DisplaySpecialSequencesExecution_RCStop
**
** Visibility       :  Public
**
** Description      :  Stops Display special sequences execution
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_STOP_Diag_F116
**
** Inputs           :  Data[out]:status of routine control stop
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplaySplSeqConfig.DisplayCtrlDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DisplaySpecialSequencesExecution_RCStatus
**
** Visibility       :  Public
**
** Description      :  returns status of Display special sequences execution
**
** Invocation       :  MeetMgr.diagcdd, Function:RC_RESULTS_Diag_F116
**
** Inputs           :  Data[out]:status of routine control
                       Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_DisplaySpecialSequencesExecution_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplaySplSeqConfig.DisplayCtrlDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef DISPLAY_CONTENT_CHECK
Std_ReturnType DisplayContentVerfication_RC_Start(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayCtrlDiag_ePRNDL_RGBChecksum_monitor_start(Data);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef LCD_CONTROL_ALL_LIT_SEGMENT_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_LCDAllSegmentControl_RCStart
**
** Visibility       :  Public
**
** Description      :  allows to display All segment ON in the LCD screen
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:segments
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_LCDAllSegmentControl_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayCtrlAllSegmentConfig.DisplayCtrlAllLCDsegment_Start(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_LCDAllSegmentControl_RCStop
**
** Visibility       :  Public
**
** Description      :  allows to display All segment OFF in the LCD screen
**
** Invocation       :  MeetMgr.diagcdd,
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_LCDAllSegmentControl_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayCtrlAllSegmentConfig.DisplayCtrlAllLCDsegment_Stop(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef TFT_CONTROL_ALL_LIT_COLOR_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TFTAllLit_ColorControl_RCStart
**
** Visibility       :  Public
**
** Description      :  allows to display in TFT mentioned color
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:segments
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTAllLit_ColorControl_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayCtrlAllLitTFTConfig.DisplayCtrlAllTFTColor_Start(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_LCDAllSegmentControl_RCStop
**
** Visibility       :  Public
**
** Description      :  allows to display in TFT Blank
**
** Invocation       :  MeetMgr.diagcdd,
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TFTAllLit_ColorControl_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayCtrlAllLitTFTConfig.DisplayCtrlAllTFTColor_Stop(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef DISPLAY_LCD_SEGMENT_CTRL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_LCDSegmentControl_Duty_STA
**
** Visibility       :  Public
**
** Description      :  allows to display some defined Segment control, this function will provide only API for segment control
**                     If Required to control LCD segment should configure macro LCD_SEGMENT_CTRL_ENABLE in Mgrdiagcdd.h
**                     If required to control LCD as well illumination should configure macro LCD_CONTROl_WITH_DUTY in Displaycontroldiagcdd_cfg.h
**                     and LCD_SEGMENT_CTRL_ENABLE in Mgrdiagcdd.h
**                     and Corresponding illumination RTE should be place in  Ioctrlrd_pwm_diagcdd_cfg.c file
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:LCD segment Parameter
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_LCDSegmentControl_Duty_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = LCDSegmentCtrlConfig.DisplayCtrlLCDDiag_STA(Data, ErrorCode);
        #ifdef LCD_CONTROL_WITH_DUTY
        Meet_DimmingControlConfig[LCD_DUTY_CONTREOL_CHANNEL].DimmingControlFunction(Data[LCD_DUTY_CONTROL_BYTE]);
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_LCDSegmentControl_Duty_RCTE
**
** Visibility       :  Public
**
** Description      :  allows to display return back to normal from short term adjustment,this function will provide only API for segment control
**                     If Required to control LCD segment should configure macro LCD_SEGMENT_CTRL_ENABLE in Mgrdiagcdd.h
**                     If required to control LCD as well illumination should configure macro LCD_CONTROl_WITH_DUTY in Displaycontroldiagcdd_cfg.h
**                     and LCD_SEGMENT_CTRL_ENABLE in Mgrdiagcdd.h
**                     and Corresponding illumination RTE should be place in  Ioctrlrd_pwm_diagcdd_cfg.c file
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_LCDSegmentControl_Duty_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = LCDSegmentCtrlConfig.DisplayCtrlLCDDiag_RCTE(ErrorCode);
        #ifdef LCD_CONTROL_WITH_DUTY
        Meet_DimmingControlConfig[LCD_DUTY_CONTREOL_CHANNEL].DimmingControlFunction(0);
        #endif
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef TFT_VIDEOCHECK_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_VideoCheck_STA
**
** Visibility       :  Public
**
** Description      :  allows to check the video hardware interface
**					   outputs standard video format (color bars) on TFT
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_VideoCheck_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTVideoCheckConfig.DisplayCtrlDiag_STA(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_VideoCheck_RCTE
**
** Visibility       :  Public
**
** Description      :  Cluster shall exit showing video format and show previous screen
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/

Std_ReturnType Displaycontroldiag_VideoCheck_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = TFTVideoCheckConfig.DisplayCtrlDiag_RCTE(ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#endif

#ifdef DISPLAY_CONTENT_INTEGRITY_CHECK
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStart
**
** Visibility       :  Public
**
** Description      :  allows to check the checksum of the image  displayed in TFT
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_DCIC_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayContentIntegrity.DisplayCtrlDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStop
**
** Visibility       :  Public
**
** Description      :  Cluster shall exit from showing the image
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Displaycontroldiag_DCIC_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayContentIntegrity.DisplayCtrlDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStatus
**
** Visibility       :  Public
**
** Description      :  Cluster shall return the checksum status of the image
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Displaycontroldiag_DCIC_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayContentIntegrity.DisplayCtrlDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

#endif

#ifdef DISPLAY_TOUCH_TEST_CHECK
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TouchTest_RCStart
**
** Visibility       :  Public
**
** Description      :  This function starts routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In] : NA
**					   Errorcode : To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eDisplayROUTINE_INPROGRESS == DisplayCtrlDiag_TouchTest_RCStatus)
        {
            /*Already Routine in progress*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
        else
        {
            ret = DisplayTouchTestConfig.DisplayCtrlDiag_TouchTest_Write(Data);

            if (ret == (uint8)E_OK)
            {
                DisplayCtrl_TouchTest_DiagRequest = TRUE;
                DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_INPROGRESS;
                Data[DATA_BYTE_0] = (uint8)DisplayCtrlDiag_TouchTest_RCStatus;
            }
            else
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TouchTest_RCStop
**
** Visibility       :  Public
**
** Description      :  This function stops routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In] : NA
** 					   Errorcode : To be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchTest_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        DisplayCtrl_TouchTest_DiagRequest = FALSE;

        DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_TesterSTOPPED;

        Data[DATA_BYTE_0] = (uint8)DisplayCtrlDiag_TouchTest_RCStatus;

        DisplayTouchTestConfig.DisplayCtrlDiag_TouchTest_PostCondition();

        ret = E_OK;
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_TouchTest_RCStatus
**
** Visibility       :  Public
**
** Description      :  This function provides result of routine to test all the touch points on the display
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In] : NA
** 					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK : Fail
**
** Critical Section :  Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchTest_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint8 idx = 0;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if (eDisplayROUTINE_INACTIVE != DisplayCtrlDiag_TouchTest_RCStatus)
        {
            Data[DATA_BYTE_0] = (uint8)DisplayCtrlDiag_TouchTest_RCStatus;

            for (idx = 0U; idx < DISPLAY_TOUCH_TEST_RESULT; idx++)
            {
                Data[idx + 1U] = TouchTest_ResultStatus[idx];
            }
            ret = E_OK;
        }
        else
        {
            /*Routine not started*/
            *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        }
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
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

void Displaycontroldiag_TouchTest_Task(void)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 ErrorCode = 0U;

    if (DisplayCtrl_TouchTest_DiagRequest == TRUE)
    {
        ret = DisplayTouchTestConfig.DisplayCtrlDiag_TouchTest_PreCondition(&ErrorCode);

        if (ret == (uint8)E_OK)
        {
            ret = DisplayTouchTestConfig.DisplayCtrlDiag_TouchTest_Read(&TouchTest_ResultStatus);

            if (ret == (uint8)E_OK)
            {
                DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_FINISH_OK;
            }
            else if (ret == (uint8)E_NOT_OK)
            {
                DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_FINISH_NOK;
            }
            else
            {
                /*Wait State - No Action Required*/
            }
        }
        else
        {
            if (ErrorCode == DCM_E_CONDITIONSNOTCORRECT)
            {
                DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_EcuSTOPPED;
            }
            else
            {
                DisplayCtrlDiag_TouchTest_RCStatus = eDisplayROUTINE_FINISH_OK;
            }
        }

        if ((DisplayCtrlDiag_TouchTest_RCStatus == eDisplayROUTINE_FINISH_OK) ||
            (DisplayCtrlDiag_TouchTest_RCStatus == eDisplayROUTINE_FINISH_NOK) ||
            (DisplayCtrlDiag_TouchTest_RCStatus == eDisplayROUTINE_EcuSTOPPED))
        {
            DisplayCtrl_TouchTest_DiagRequest = FALSE;
            DisplayTouchTestConfig.DisplayCtrlDiag_TouchTest_PostCondition();
        }
    }
}
#endif

#ifdef DISPLAYCONTROLDIAG_I2CTEST_ROUTINE
/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStart
**
** Visibility       :  Public
**
** Description      :  allows to check the I2C Test
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_I2CTest_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayI2CTestConfig.DisplayCtrlDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStop
**
** Visibility       :  Public
**
** Description      :  Cluster shall stop I2C test routine
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Displaycontroldiag_I2CTest_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayI2CTestConfig.DisplayCtrlDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
**
** Function Name    :  Displaycontroldiag_DCIC_RCStatus
**
** Visibility       :  Public
**
** Description      :  Cluster shall return the status of I2C test
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Errorcode:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

Std_ReturnType Displaycontroldiag_I2CTest_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayI2CTestConfig.DisplayCtrlDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef DISPLAYCONTROLDIAG_TSW_I2CREAD_ROUTINE
/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TSWI2CREAD_RCStart
** Visibility       :  Public
** Description      :  allows to read the TSW Data through I2C.
** Invocation       :  MeetMgr.diagcdd
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TSWI2CREAD_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayI2CReadConfig.DisplayCtrlI2CRead_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TSWI2CREAD_RCStatus
** Visibility       :  Public
** Description      :  Cluster shall return data from TSW HW
** Invocation       :  MeetMgr.diagcdd
** Inputs           :  Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TSWI2CREAD_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayI2CReadConfig.DisplayCtrlI2CRead_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef DISPLAY_TOUCH_VERIFICATION_CHECK
/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TouchVerification_RCStart
** Visibility       :  Public
** Description      :  allows to read the Touch coordinates from TouchCdd
** Invocation       :  MeetMgr.diagcdd
** Inputs           :  Data[In]: NA
**					   Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchVerification_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayTouchVerificationConfig.DisplayCtrlDiag_Start(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TouchVerification_RCStop
** Visibility       :  Public
** Description      :  Cluster shall stop reading the Touch coordinates from TouchCdd
** Invocation       :  MeetMgr.diagcdd
** Inputs           :  Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section : Yes/No
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchVerification_RCStop(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayTouchVerificationConfig.DisplayCtrlDiag_Stop(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}

/*=====================================================================================================================
** Function Name    :  Displaycontroldiag_TouchVerification_RCStatus
** Visibility       :  Public
** Description      :  Cluster shall return Touch coordinates from TouchCdd
** Invocation       :  MeetMgr.diagcdd
** Inputs           :  Errorcode:to be updated with error code if any
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
** Critical Section :  Yes/No
**====================================================================================================================*/
Std_ReturnType Displaycontroldiag_TouchVerification_RCStatus(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DisplayTouchVerificationConfig.DisplayCtrlDiag_Result(Data, ErrorCode);
    }
    else
    {
        /*Invalid Mode*/
        *ErrorCode = INVALID_MODE;
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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation.
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
** Change Description:  I2C-Read service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  I2C-Test service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1744046
** Change Description:  Touch-Test service added.
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
** Change Description: Implementation of DRS  FE0B, FE0C
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  17/05/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1310404
** Change Description:  Display content integrity check(SIG unit check) service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/02/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1263596
** Change Description:  Display module Update VIP - GIP communication
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
** Change Description: TFT segment control illumination function added
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
#endif /* DISPLAYCONTROLDIAGCDD_C */
