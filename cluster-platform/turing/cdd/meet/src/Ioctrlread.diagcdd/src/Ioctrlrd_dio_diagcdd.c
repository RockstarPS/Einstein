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

#ifndef IOCTRLRD_DIO_DIAGCD_C
#define IOCTRLRD_DIO_DIAGCD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Ioctrlrd_dio_diagcdd_cfg.h"
#include "Ioctrlrd_dio_diagcdd.h"
#include "Mgrdiagcdd.h"
#ifdef LED_CONTROl_WITH_DUTY
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

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_LEDControl_DUTY_STA
**
** Visibility       :  Public
**
** Description      :  2F LED control with DUty short term adjustment
** 					   This function can control each Telltae and corresponding PWM illumination.
** 					   for LED control should configure macro in IOCONTOLRD_LED_CONTROL_DUTY_ENABLE in meetmgr
**                     if both LED and illumination required the macro should configure IOCONTOLRD_LED_CONTROL_DUTY_ENABLE
**                     and LED_CONTROl_WITH_DUTY
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_LEDControl_DUTY_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 arrIndex = 0U;
    uint8 bitPos = 0U;
    uint8 LEDStatus = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (TTIndex = 0U; TTIndex < LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            arrIndex = (TTIndex / NO_OF_BITS_IN_BYTE);
            bitPos = (TTIndex % NO_OF_BITS_IN_BYTE);

            LEDStatus = ((Data[arrIndex] >> bitPos) & 0x01U);

            if (LEDStatus == 0x01U)
            {
                Meet_LEDControlConfig[TTIndex].LEDControlFunction((Meet_LEDControlConfig[TTIndex].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
            }
            else
            {
                Meet_LEDControlConfig[TTIndex].LEDControlFunction((Meet_LEDControlConfig[TTIndex].DIO_LogicLevel != 0U) ? OUTPUT_LOW : OUTPUT_HIGH);
            }
            #ifdef LED_CONTROl_WITH_DUTY
            Meet_DimmingControlConfig[LED_DUTY_CONTROL_CHANNEL].DimmingControlFunction(Data[LED_DUTY_CONTROL_BYTE]);
            #endif
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return (ret);
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_LEDControl_DUTY_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service -LED control short term adjustment to RCTE
** 					   If Control Option = Return control to ECU $00 ;
** 					   All LED shall be reset to default values and corresponding PWM duty also shall be reset to default values
** 					   Return control to ECU request format does not require Data or ID.
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_LEDControl_DUTY_RCTE(uint8 *ErrorCode)
{
    uint8 ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (TTIndex = 0U; TTIndex < LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            Meet_LEDControlConfig[TTIndex].LEDControlFunction(Meet_LEDControlConfig[TTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
            ret = E_OK;
        }
        #ifdef LED_CONTROl_WITH_DUTY
        Meet_DimmingControlConfig[LED_DUTY_CONTROL_CHANNEL].DimmingControlFunction(0);
        #endif
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_FUELLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_FUELLEDControl_DUTY_STA
**
** Visibility       :  Public
**
** Description      :  2F LED control with DUty short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_FUELLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 arrIndex = 0U;
    uint8 bitPos = 0U;
    uint8 LEDStatus = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_FUELLED_SetPWM(eSTA);

        for (TTIndex = 0U; TTIndex < FUEL_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            arrIndex = (TTIndex / NO_OF_BITS_IN_BYTE);
            bitPos = (TTIndex % NO_OF_BITS_IN_BYTE);

            LEDStatus = ((Data[arrIndex] >> bitPos) & 0x01U);

            if (LEDStatus == 0x01U)
            {
                Meet_FUELLEDControlConfig[TTIndex].LEDControlFunction((Meet_FUELLEDControlConfig[TTIndex].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
            }
            else
            {
                Meet_FUELLEDControlConfig[TTIndex].LEDControlFunction((Meet_FUELLEDControlConfig[TTIndex].DIO_LogicLevel != 0U) ? OUTPUT_LOW : OUTPUT_HIGH);
            }
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return (ret);
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_FUELLEDControl_DUTY_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service -LED control short term adjustment to RCTE
** 					   If Control Option = Return control to ECU $00 ;
** 					   All LED shall be reset to default values and corresponding PWM duty also shall be reset to default values
** 					   Return control to ECU request format does not require Data or ID.
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_FUELLEDControl_DUTY_RCTE(uint8 *ErrorCode)
{
    uint8 ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_FUELLED_SetPWM(eRTCtrl);

        for (TTIndex = 0U; TTIndex < FUEL_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            Meet_FUELLEDControlConfig[TTIndex].LEDControlFunction(Meet_FUELLEDControlConfig[TTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
            ret = E_OK;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_TACHOLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_STA
**
** Visibility       :  Public
**
** Description      :  2F LED control with DUty short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 arrIndex = 0U;
    uint8 bitPos = 0U;
    uint8 LEDStatus = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_TACHOLED_SetPWM(eSTA);

        for (TTIndex = 0U; TTIndex < TACHO_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            arrIndex = (TTIndex / NO_OF_BITS_IN_BYTE);
            bitPos = (TTIndex % NO_OF_BITS_IN_BYTE);

            LEDStatus = ((Data[arrIndex] >> bitPos) & 0x01U);

            if (LEDStatus == 0x01U)
            {
                Meet_TACHOLEDControlConfig[TTIndex].LEDControlFunction((Meet_TACHOLEDControlConfig[TTIndex].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
            }
            else
            {
                Meet_TACHOLEDControlConfig[TTIndex].LEDControlFunction((Meet_TACHOLEDControlConfig[TTIndex].DIO_LogicLevel != 0U) ? OUTPUT_LOW : OUTPUT_HIGH);
            }
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return (ret);
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service -LED control short term adjustment to RCTE
** 					   If Control Option = Return control to ECU $00 ;
** 					   All LED shall be reset to default values and corresponding PWM duty also shall be reset to default values
** 					   Return control to ECU request format does not require Data or ID.
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TACHOLEDControl_DUTY_RCTE(uint8 *ErrorCode)
{
    uint8 ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_TACHOLED_SetPWM(eRTCtrl);

        for (TTIndex = 0U; TTIndex < TACHO_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            Meet_TACHOLEDControlConfig[TTIndex].LEDControlFunction(Meet_TACHOLEDControlConfig[TTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
            ret = E_OK;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_ECTLED_CONTROL_DUTY_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_ECTLEDControl_DUTY_STA
**
** Visibility       :  Public
**
** Description      :  2F LED control with DUty short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
**
** Critical Section : No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_ECTLEDControl_DUTY_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 arrIndex = 0U;
    uint8 bitPos = 0U;
    uint8 LEDStatus = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_ECTLED_SetPWM(eSTA);

        for (TTIndex = 0U; TTIndex < ECT_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            arrIndex = (TTIndex / NO_OF_BITS_IN_BYTE);
            bitPos = (TTIndex % NO_OF_BITS_IN_BYTE);

            LEDStatus = ((Data[arrIndex] >> bitPos) & 0x01U);

            if (LEDStatus == 0x01U)
            {
                Meet_ECTLEDControlConfig[TTIndex].LEDControlFunction((Meet_ECTLEDControlConfig[TTIndex].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
            }
            else
            {
                Meet_ECTLEDControlConfig[TTIndex].LEDControlFunction((Meet_ECTLEDControlConfig[TTIndex].DIO_LogicLevel != 0U) ? OUTPUT_LOW : OUTPUT_HIGH);
            }
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return (ret);
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_ECTLEDControl_DUTY_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service -LED control short term adjustment to RCTE
** 					   If Control Option = Return control to ECU $00 ;
** 					   All LED shall be reset to default values and corresponding PWM duty also shall be reset to default values
** 					   Return control to ECU request format does not require Data or ID.
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_ECTLEDControl_DUTY_RCTE(uint8 *ErrorCode)
{
    uint8 ret = E_NOT_OK;
    uint8 TTIndex = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        (void)Dio_diag_ECTLED_SetPWM(eRTCtrl);

        for (TTIndex = 0U; TTIndex < ECT_LED_CONTROL_NUM_OF_SIGNALS; TTIndex++)
        {
            Meet_ECTLEDControlConfig[TTIndex].LEDControlFunction(Meet_ECTLEDControlConfig[TTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
            ret = E_OK;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_DOUT_STA
**
** Visibility       :  Public
**
** Description      :   2F service IO CONTROL DOUT short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DOUT_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 DOUTIndex = 0U;
    uint8 arrIndex = 0U;
    uint8 bitPos = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        for (DOUTIndex = 0U; DOUTIndex < DOUT_CONTROL_NUM_OF_SIGNALS; DOUTIndex++)
        {
            arrIndex = (DOUTIndex / NO_OF_BITS_IN_BYTE);
            bitPos = (DOUTIndex % NO_OF_BITS_IN_BYTE);

            if ((Data[arrIndex] & (1U << bitPos)) != 0U)
            {
                Meet_DOUTControlConfig[DOUTIndex].Dio_DOUTFunction((Meet_DOUTControlConfig[DOUTIndex].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
            }
            else
            {

                Meet_DOUTControlConfig[DOUTIndex].Dio_DOUTFunction(Meet_DOUTControlConfig[DOUTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
            }
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  CMeetCdd_DioDiag_LEDCtrl_RetCtrl_ECU
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL LED control short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DOUT_RCTE(uint8 *ErrorCode)
{
    uint8 ret = E_NOT_OK;
    uint8 DOUTIndex;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (DOUTIndex = 0U; DOUTIndex < DOUT_CONTROL_NUM_OF_SIGNALS; DOUTIndex++)
        {
            Meet_DOUTControlConfig[DOUTIndex].Dio_DOUTFunction(Meet_DOUTControlConfig[DOUTIndex].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
        }

        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef IOCONTOLRD_INTERNAL_DIGITAL_SIGNAL_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_InternalDigitalSignalControl_STA
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL InternalDigitalSignalControl short term adjustment
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignalControl_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 IndexL = 0U;
    uint8 RequestedStatusL = 0U;
    uint8 MfgModeActive = 0U;
    uint8 j = 0;
    uint8 MASK_START_BYTE = (DIN_INT_SIGNAL_CTRL_DATALENGTH / 0x02U);
    uint8 TempL = (DIN_INT_SIGNAL_CTRL_DATALENGTH / 0x02U);
    uint8 MEET_REM_8 = 0x08;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (IndexL = 0U; IndexL < DIN_INT_SIGNAL_CONTROL_SIGNALS; IndexL++)
        {
            if (MASK_START_BYTE < DIN_INT_SIGNAL_CTRL_DATALENGTH)
            {
                if (((Data[MASK_START_BYTE] >> j) & 0x01U) != 0U) // Check if Mask bit for particular channel is 1
                {
                    RequestedStatusL = ((Data[MASK_START_BYTE - TempL] >> j) & 0x01U);

                    Dio_InternaldgtlsglCotrlConfig[IndexL].Dio_InternalDigitalCtrlFunction(RequestedStatusL ^ Dio_InternaldgtlsglCotrlConfig[IndexL].DIO_LogicLevel);
                }
                j++;

                if ((j % MEET_REM_8) == 0x00U) // Switch to next byte
                {
                    j = 0x00; // start from bit position zero
                    MASK_START_BYTE++;
                }
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                break;
            }
        }
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return (ret);
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_InternalDigitalSignalControl_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL InternalDigitalSignalControl short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignalControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 IndexL = 0U;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (IndexL = 0U; IndexL < DIN_INT_SIGNAL_CONTROL_SIGNALS; IndexL++)
        {

            Dio_InternaldgtlsglCotrlConfig[IndexL].Dio_InternalDigitalCtrlFunction(0U ^ Dio_InternaldgtlsglCotrlConfig[IndexL].DIO_LogicLevel);
        }
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_DOUT_CONTROL_PORT_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_DOUT_PORT_Control_STA
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL PORT DOUT short term adjustmen
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DOUT_PORT_Control_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint8 Port_id =Data[IOCTRL_PORTID];
    uint8 MaskByte = Data[IOCTRL_MASK_BYTE];
    uint8 OutputByte = Data[IOCTRL_OUTPUT_BYTE];
    uint8 BitIndex =0u;
    uint8 RequestedStatusL;
    uint8 MEET_REM_8 = DOUT_BITS_PER_PORT; 
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        if(Port_id < DOUT_PORTS_MAX)
        {
            for(BitIndex =0; BitIndex<MEET_REM_8; BitIndex++)
            {
                if(((MaskByte >> BitIndex) & 0x01U)!=0u) //check if mask bit is 1
                {
                    RequestedStatusL = (OutputByte >> BitIndex) & 0x01U; // Get the output status for the bit
                    Meet_DOUT_PORTControlConfig[Port_id][BitIndex].Dio_DOUTPORTFunction(RequestedStatusL);
                }
            }
        }
        ret = E_OK;

    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;

}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_DOUT_PORT_Control_RCTE
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL IO CONTROL LED control short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DOUT_PORT_Control_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 PORTIndex;
    uint8 BitIndex =0u;
    uint8 MEET_REM_8 = DOUT_BITS_PER_PORT; 
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for(PORTIndex=0; PORTIndex < DOUT_PORTS_MAX; PORTIndex++)
        {
            for(BitIndex =0; BitIndex < MEET_REM_8; BitIndex++)
            {
                Meet_DOUT_PORTControlConfig[PORTIndex][BitIndex].Dio_DOUTPORTFunction(SET_PIN_DOUT_INACTIVE);
            }
        }
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IO_INTERNAL_DIGITAL_SIGNAL_READ_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_InternalDigitalSignal_Read
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL InternalDigitalSignalControl read
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_InternalDigitalSignal_Read(uint8 *Data, uint8 *ErrorCode)
{

    uint8 index, byte, bit, SignalValue, SignalCnt;
    Std_ReturnType retval = E_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        SignalCnt = 0;

        for (index = 0; index < DATA_LENGTH_IN_BYTES; index++)
        {
            Data[index] = 0;
        }

        for (byte = 0; byte < DATA_LENGTH_IN_BYTES; byte++)
        {
            for (bit = 0; bit < NO_OF_BITS_IN_BYTE; bit++)
            {
                SignalValue = 0;
                if (Meet_InternaldgtlsglDOUTConfig[SignalCnt].DinInternaldgtlsglDOUTRead != NULL_PTR)
                {
                    Meet_InternaldgtlsglDOUTConfig[SignalCnt].DinInternaldgtlsglDOUTRead(&SignalValue);
                    SignalValue = SignalValue << bit;
                    Data[byte] |= SignalValue;
                }
                SignalCnt++;
                if (SignalCnt >= DIN_PIN_OUT_READ_NUM_OF_SIGNALS)
                {
                    break;
                }
            }
            if (SignalCnt >= DIN_PIN_OUT_READ_NUM_OF_SIGNALS)
            {
                break;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return retval;
}
#endif

#ifdef IO_SELFCHECK_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_SelfCheck_Read
**
** Visibility       :  Public
**
** Description      :  22 service IO RW
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_SelfCheck_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 selfCheckCount;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        #ifndef SELFCHECK_CLEAR_BUFFER
        uint8 bufferCount;

        /*Clearing Data buffer*/
        for (bufferCount = 0U; bufferCount < MAX_NUM_BUFFER; bufferCount++)
        {
            Data[bufferCount] = 0x00U;
        }
        #endif

        for (selfCheckCount = 0U; selfCheckCount < NUM_OF_SELFCHECK; selfCheckCount++)
        {
            if (Meet_SelfCheckConfig[selfCheckCount].SelfCheckFunction != NULL_PTR)
            {
                retVal = Meet_SelfCheckConfig[selfCheckCount].SelfCheckFunction(Data);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return retVal;
}
#endif

#ifdef IO_BUTTON_READ_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_ButtonCheck_Read
**
** Visibility       :  Public
**
** Description      :  22 service IO RW InternalDigitalSignalControl read
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_ButtonCheck_Read(uint8 *Data, uint8 *ErrorCode)
{

    uint8 index, byte, bit, SignalValue, SignalCnt;
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {

        uint8 fl_u8BitMask;
        SignalCnt = 0;

        /*Set all port value's by default '0' */
        for (index = 0; index < DATA_LENGTH_IN_BYTES; index++)
        {
            Data[index] = 0;
        }
        /* Check all ports i.e.bytes */
        for (byte = 0; byte < DATA_LENGTH_IN_BYTES; byte++)
        {
            /* Check for all bits */
            for (bit = 0; bit < NO_OF_BITS_IN_BYTE; bit++)
            {
                SignalValue = 0U;
                /* Checking whether port/bit is configured */
                fl_u8BitMask = (uint8)(1U << bit);
                //(ActiveDinBits[byte] & fl_u8BitMask))
                if (FALSE != DinActiveStatus(byte, fl_u8BitMask))
                {
                    if (Meet_DinConfig[SignalCnt].DinReadingFunction != NULL_PTR)
                    {
                        ret = Meet_DinConfig[SignalCnt].DinReadingFunction(&SignalValue);
                        if ((uint8)E_OK == ret)
                        {
                            Data[byte] = (!(SignalValue ^ Meet_DinConfig[SignalCnt].DIO_LogicLevel)) ? (Data[byte] | (uint8)(1U << bit)) : (Data[byte] & (uint8)(~((uint8)(1U << bit))));
                        }
                        /*if ret = E_NOT_OK it will have default value 0*/
                    }
                    SignalCnt++;
                }
                if (SignalCnt >= DIN_BUTTON_NUM_OF_SIGNALS)
                {
                    break;
                }
            }
            if (SignalCnt >= DIN_BUTTON_NUM_OF_SIGNALS)
            {
                break;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef IO_DOUT_WRITE_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_DigitalOutputs_Write
**
** Visibility       :  Public
**
** Description      :  2E service IO DigitalOutputs Write
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DigitalOutputs_Write(uint8 *Data, uint8 *ErrorCode)
{

    uint8 byte, bit;
    Std_ReturnType ret = E_NOT_OK;
    uint8 fl_u8BitMask;
    uint8 SignalCnt = 0U;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        /* Check all ports i.e.bytes */
        for (byte = 0; byte < DATA_LENGTH_IN_BYTES; byte++)
        {
            /* Check for all bits */
            for (bit = 0; bit < NO_OF_BITS_IN_BYTE; bit++)
            {
                /* Checking whether port/bit is configured */
                fl_u8BitMask = (1U << bit);
                //(ActiveDinBits[byte] & fl_u8BitMask))
                if (FALSE != DoutActiveStatus(byte, fl_u8BitMask))
                {
                    if (Meet_DoutConfig[SignalCnt].DoutWritingFunction != NULL_PTR)
                    {
                        if ((Data[byte] & fl_u8BitMask) != 0U)
                        {
                            (void)Meet_DoutConfig[SignalCnt].DoutWritingFunction((Meet_DoutConfig[SignalCnt].DIO_LogicLevel == 1U) ? OUTPUT_HIGH : OUTPUT_LOW);
                        }
                        else
                        {

                            (void)Meet_DoutConfig[SignalCnt].DoutWritingFunction(Meet_DoutConfig[SignalCnt].DIO_LogicLevel ? OUTPUT_LOW : OUTPUT_HIGH);
                        }
                        ret = E_OK;
                    }
                    SignalCnt++;
                }
                if (SignalCnt >= DOUT_WRITE_NUM_OF_SIGNALS)
                {
                    break;
                }
            }
            if (SignalCnt >= DOUT_WRITE_NUM_OF_SIGNALS)
            {
                break;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_BUZZER_TET_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_TestBuzzerTone_STA
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL and test Buzzer Tone
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestBuzzerTone_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_buzzerToneControlConfig.BuzzerToneControlFunction(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE
**
** Visibility       :  Public
**
** Description      :   2F service IO CONTROL and test Buzzer Tone return to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestBuzzerToneControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_buzzerToneControlConfig.BuzzerToneControlReturnFunction(ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif
#ifdef IOCONTOLRD_SPEAKER_TEST_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TestSpeakerTone_STA
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL and test Speaker Tone
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerTone_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_speakerToneControlConfig.speakerToneControlFunction(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TestSpeakerTone_RCTE
**
** Visibility       :  Public
**
** Description      :   2F service IO CONTROL and test Buzzer Tone return to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerTone_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_speakerToneControlConfig.speakerToneControlReturnFunction(ErrorCode);
        if ((uint8)E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_SPEAKER_VOLUME_TEST_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TestSpeakerVolume_STA
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL and test Speaker Tone
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolume_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_speakerVolumeControlConfig.speakerVolumeControlFunction(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TestSpeakerVolume_RCTE
**
** Visibility       :  Public
**
** Description      :   2F service IO CONTROL and test Buzzer Tone return to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolume_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_speakerVolumeControlConfig.speakerVolumeControlReturnFunction(ErrorCode);
        if ((uint8)E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_ALL_LIT_LED_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_All_Lit_telltale_RCStart
**
** Visibility       :  Public
**
** Description      :  31 Routine service START-This function shall turn ON the all LED's
**       			   for Enabling ALL lit LED ON function should configure macro in IOCONTOLRD_LED_CONTROL_DUTY_ENABLE in meetmgr
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_All_Lit_telltale_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Meet__All_LitLEDControlConfig.AllLitLEDControlStart(Data, ErrorCode);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_All_Lit_telltale_RCStop
**
** Visibility       :  Public
**
** Description      :  31 Routine service STOP-This function shall turn OFF the all LED's
**       			   for Enabling ALL lit LED OFF function should configure macro in IOCONTOLRD_LED_CONTROL_DUTY_ENABLE in meetmgr
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_All_Lit_telltale_RCStop(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Meet__All_LitLEDControlConfig.AllLitLEDControlStop(ErrorCode);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_TFT_CONTINUITY_LOOP_CHECK
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_continuity_loop_check
**
** Visibility       :  Public
**
** Description      :  DID to read the TFT connection status
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_continuity_loop_check(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    Dcm_NegativeResponseCodeType ErrorCode[2] = {0};
    uint8 MfgModeActive = 0U;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_Dio_ConnectionCheckConfig.TFTConnectionCheck(Data, ErrorCode);
    }
    else
    {
        ErrorCode[0] = INVALID_MODE;
        Data[0] = ErrorCode[0];
    }
    return ret;
}
#endif

#ifdef IOCTRLRD_PMIC_CONFIGURATION_CHECK
Std_ReturnType Ioctrlrd_dio_diag_PMIC_Configuration_Check_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_Dio_PMIC_Configration_Check.PMICConfigurationCheck(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef DIAG_DESER_ACCESS_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_DeserRead_RCStart
**
** Visibility       :  Public
**
** Description      :
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_DeserRead_RCStart(uint16 reg, uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean MfgModeActive = 0u;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DIO_MEET_DeserConfig.MEET_Deser_ReadStart(reg, Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Ioctrlrd_dio_diag_DeserWrite(uint16 reg, uint8 Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean MfgModeActive = 0u;

    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = DIO_MEET_DeserConfig.MEET_Deser_Write(reg, Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef SOUNDCHANNELVOLUMECONTROL
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_dio_diag_TestSpeakerVolumeControl_Write
**
** Visibility       :  Public
**
** Description      :  2F service IO CONTROL and test Speaker Tone
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section :  No
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_TestSpeakerVolumeControl_Write(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_VolumeControlConfig.VolumeControlFunction(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_PLAY_TONE_CONTROL
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_dio_diag_SpeakerTone_RCStart
**
** Visibility       :  Public
**
** Description      :  31 Routine service START-This function shall Play tone on the Speaker
**       			   for requested channel
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code.
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_dio_diag_SpeakerTone_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_PlayToneControlConfig.ToneControlFunctionStart(Data, ErrorCode);
    }
    else
    {
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
** Date              :  03/01/2025
** CDSID             :  vbarad
** Traceability      :  JIRA 3839
** Change Description:  Added IO control Digital output DID with condition to check mask and output byte
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Oct/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1811312
** Change Description:  Coverity/MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  04/Aug/2022
** CDSID             :  rtopani
** Traceability      :  RTC-1730821
** Change Description:  Added Volume control DID to change the acoustic level of chime
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  29/06/2022
** CDSID             :  mprajapa
** Traceability      :  RTC 1697574
** Change Description:  To read, write deserialiser register interfaces are added
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/06/2022
** CDSID             :  mpandey2
** Traceability      :  RTC 1653104
** Change Description:  PMIC Configuration Check Read Function  and PMIC Read Registers Periodic Function  Implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  23/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1634375
** Change Description:  Coverity/MISRA Fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  Duty control (LED, FUEL, ECT, TACHO), SelfCheck and DigitalOutputs interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/Dec/2019
** CDSID             : dkasiman
** Traceability      : RTC-1393187
** Change Description: TFT connection check service added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 11/Sept/2018
** CDSID             : razhakes
** Traceability      : RTC-1368176
** Change Description: Digital output control updated.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 22/Dec/2018
** CDSID             : dkasiman
** Traceability      : RTC-1258974
** Change Description: Rte_MeetCdd.h file commented.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  20/7/2018
** CDSID             :  rkathir1
** Traceability      :  RTC 1157783
** Change Description:  Review comments updated function name has changed with control and duty
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 18/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113543
** Change Description: Initial version - Ioctrl dio Implementation for Turing Bookshelf.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 31/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1127781
** Change Description: Review comments fixed buzzer logic changed.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 06/07/2018
** CDSID             : rkathir1
** Traceability      : RTC 1152267
** Change Description: All Lit Telltale function implementation
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 12/06/2018
** CDSID             : rkathir1
** Traceability      : RTC 1148632
** Change Description: Speaker function implement
**====================================================================================================================*/

#endif /* IOCTRLRD_DIO_DIAGCD_C */
