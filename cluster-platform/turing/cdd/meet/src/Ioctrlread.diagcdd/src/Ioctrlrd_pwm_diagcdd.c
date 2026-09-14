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

#ifndef IOCRTLRD_PWM_DIAGCDD_C
#define IOCRTLRD_PWM_DIAGCDD_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Ioctrlrd_pwm_diagcdd_cfg.h"
#include "Ioctrlrd_pwm_diagcdd.h"
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S
**====================================================================================================================*/

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/
#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
#ifdef MEET_GIP_ENABLED
uint8 Ioctrlrd_PWM_ControlType = 0U;
uint8 Ioctrlrd_PWM_Channel = 0U;
#else
static uint8 Ioctrlrd_PWM_ControlType = 0U;
static uint8 Ioctrlrd_PWM_Channel = 0U;
#endif
#endif

#ifdef IOCONTROL_PWM_SINGLE_OUTPUTCONTROL_ENABLE
static uint8 PWM_SingleChannelID = 0U;
#endif
/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef IOCONTROlRD_PWM_DIMMING_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_DimmingControl_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_DimmingControl_STA(const uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint16 Duty;
        uint8 ChannelCount;

        #ifdef CONTROL_TYPE_CUSTOMER_CALIB
        uint16 Gain_Single_Chl = 0U;
        uint16 Gain_All_Chl[DIMMING_CONTROL_CHANNEL] = {0U};
        #endif

        #if ((BCDMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01) || (DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01))
        uint16 u16Dimm;
        uint16 u16Dimm_temp;
        #endif

        Ioctrlrd_PWM_ControlType = Data[0];
        Ioctrlrd_PWM_Channel = Data[1];

        #if ((BCDMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01) || (DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01))
        u16Dimm = Data[2];
        u16Dimm_temp = Data[3];
        #endif

        #if (BCDMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01U)
        Duty = DutyManipulateWithBCD(u16Dimm, u16Dimm_temp);
        #endif
        #if (DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL == 0x01U)
        Duty = DutyManipulateWitDecimal(u16Dimm, u16Dimm_temp);
        #endif

        if (Ioctrlrd_PWM_ControlType == CONTROL_TYPE_DIRECT)
        {
            if (Ioctrlrd_PWM_Channel == DIMMING_CTRL_ALL_CHANNEL)
            {
                for (ChannelCount = 0U; ChannelCount < DIMMING_CONTROL_CHANNEL; ChannelCount++)
                {
                    if (Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction != NULL_PTR)
                    {
                        RetVal = Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction(Duty, MGRDIAGCDD_IOC_STA_ACTION, ErrorCode);
                    }
                }
            }
            else
            {
                if ((Ioctrlrd_PWM_Channel <= DIMMING_CONTROL_CHANNEL) && (Ioctrlrd_PWM_Channel != 0U))
                {
                    if (Meet_DimmingControlConfig[Ioctrlrd_PWM_Channel - 1U].DimmingControlFunction != NULL_PTR)
                    {
                        RetVal = Meet_DimmingControlConfig[Ioctrlrd_PWM_Channel - 1U].DimmingControlFunction(Duty, MGRDIAGCDD_IOC_STA_ACTION, ErrorCode);
                    }
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
            }
        }
        #ifdef CONTROL_TYPE_CUSTOMER_CALIB
        else if (Ioctrlrd_PWM_ControlType == CONTROL_TYPE_CUSTOMER_CALIB) // For Customer calibrated control
        {

            if (Ioctrlrd_PWM_Channel == DIMMING_CTRL_ALL_CHANNEL)
            {
                for (ChannelCount = 0; ChannelCount < DIMMING_CONTROL_CHANNEL; ChannelCount++)
                {
                    if (Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction != NULL_PTR)
                    {
                        Meet_DimmingReadGainConfig[ChannelCount].DimmingReadGain(&Gain_All_Chl[ChannelCount]);  // Get the gain value for calculating the Calibrated PWM parameter
                        Duty = (uint16)((Duty * Gain_All_Chl[ChannelCount]) / IOCONTROlRD_PWM_HUNDRED_PERCENT); // u16Scale varies from 0 to 1000

                        RetVal = Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction(Duty, MGRDIAGCDD_IOC_STA_ACTION, ErrorCode);
                    }
                }
            }
            else
            {
                if ((Ioctrlrd_PWM_Channel <= DIMMING_CONTROL_CHANNEL) && (Ioctrlrd_PWM_Channel != 0U))
                {
                    if (Meet_DimmingControlConfig[Ioctrlrd_PWM_Channel - 1U].DimmingControlFunction != NULL_PTR)
                    {
                        Meet_DimmingReadGainConfig[Ioctrlrd_PWM_Channel - 1U].DimmingReadGain(&Gain_Single_Chl);  // Get the gain value for calculating the Calibrated PWM parameter
                        Duty = (uint16)((Duty * Gain_Single_Chl) / IOCONTROlRD_PWM_HUNDRED_PERCENT); // u16Scale varies from 0 to 1000

                        RetVal = Meet_DimmingControlConfig[Ioctrlrd_PWM_Channel - 1U].DimmingControlFunction(Duty, MGRDIAGCDD_IOC_STA_ACTION, ErrorCode);
                    }
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
            }
        }
        #endif
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_DimmingControl_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**
**====================================================================================================================*/

Std_ReturnType Ioctrlrd_pwm_diag_DimmingControl_RCTE(uint8 *ErrorCode)
{
    uint8 ChannelCount;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (ChannelCount = 0U; ChannelCount < DIMMING_CONTROL_CHANNEL; ChannelCount++)
        {
            if (Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction != NULL_PTR)
            {

                RetVal = Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction(0U, MGRDIAGCDD_IOC_RCTE_ACTION, ErrorCode);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return RetVal;
}
#endif

#ifdef IOCONTROlRD_PWM_OUTPUTCONTROL_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_OutputControl_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_OutputControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount = 0U;
        uint8 flagData;
        uint8 index;
        uint8 numBytes;
        uint16 duty = 0U;

        numBytes = (OUTPUT_CONTROL_CHANNEL) * (NO_BYTES_PER_CHANNEL);

        for (index = 0; index < numBytes; index++)
        {
            flagData = (index % NO_BYTES_PER_CHANNEL);

            duty = ((duty << (flagData * NO_BITS_PER_BYTE)) | ((uint16)Data[index]));

            if (flagData != 0U)
            {
                if (Meet_OutputControlConfig[ChannelCount].OutputControlFunction != NULL_PTR)
                {
                    RetVal = Meet_OutputControlConfig[ChannelCount].OutputControlFunction(duty, ErrorCode);
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
                ChannelCount++;
                duty = 0U;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_OutputControl_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/

Std_ReturnType Ioctrlrd_pwm_diag_OutputControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount;

        for (ChannelCount = 0U; ChannelCount < OUTPUT_CONTROL_CHANNEL; ChannelCount++)
        {
            if (Meet_OutputControlConfig[ChannelCount].OutputControlFunction != NULL_PTR)
            {
                RetVal = Meet_OutputControlConfig[ChannelCount].OutputControlFunction(0U, ErrorCode);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
#endif

#ifdef IOCONTROL_PWM_SINGLE_OUTPUTCONTROL_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_OutputControl_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Single_OutputControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint16 duty = 0U;
        PWM_SingleChannelID = Data[DATA_BYTE_0];
     //   duty =  (uint16)(((uint16)Data[1U] << 8U) | (uint16)(Data[2U]));
          duty = ((uint16)((uint16)Data[1U] << 8U) | Data[2U]);
        if (Meet_SingleOutputControlConfig[PWM_SingleChannelID].SingleOutputControlFunction != NULL_PTR)
        {
            RetVal = Meet_SingleOutputControlConfig[PWM_SingleChannelID].SingleOutputControlFunction(duty, ErrorCode);
        }
        else
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_Single_OutputControl_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/

Std_ReturnType Ioctrlrd_pwm_diag_Single_OutputControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;

    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
            if (Meet_SingleOutputControlConfig[PWM_SingleChannelID].SingleOutputControlFunction != NULL_PTR)
            {
                RetVal = Meet_SingleOutputControlConfig[PWM_SingleChannelID].SingleOutputControlFunction(DUTY_SINGLE_OUTPUT_CONTROL_RCTE, ErrorCode);
            }
            else
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
#endif

#ifdef IOCONTROlRD_FUELECT_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_FuelEct_Illumination_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_FuelEct_Illumination_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount = 0U;
        uint8 flagData;
        uint8 index;
        uint8 numBytes;
        uint16 duty = 0U;

        numBytes = (FUELECT_ILLUM_CHANNEL) * (NO_BYTES_PER_CHANNEL);

        for (index = 0; index < numBytes; index++)
        {
            flagData = (index % NO_BYTES_PER_CHANNEL);

            duty = ((duty << (flagData * NO_BITS_PER_BYTE)) | ((uint16)Data[index]));

            if (flagData != 0U)
            {
                if ((Meet_FuelEctIllumConfig[ChannelCount].FuelEctIllumFunction != NULL_PTR) && (duty <= MAX_DUTYVALUE_FUELECT))
                {
                    RetVal = Meet_FuelEctIllumConfig[ChannelCount].FuelEctIllumFunction(duty, ErrorCode);
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
                }
                ChannelCount++;
                duty = 0U;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_FuelEct_Illumination_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_FuelEct_Illumination_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount;

        for (ChannelCount = 0U; ChannelCount < FUELECT_ILLUM_CHANNEL; ChannelCount++)
        {
            if (Meet_FuelEctIllumConfig[ChannelCount].FuelEctIllumFunction != NULL_PTR)
            {
                RetVal = Meet_FuelEctIllumConfig[ChannelCount].FuelEctIllumFunction(0U, ErrorCode);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
#endif

#ifdef IOCONTROlRD_TACHO_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_Tacho_Illumination_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Tacho_Illumination_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount = 0U;
        uint8 flagData;
        uint8 index;
        uint8 numBytes;
        uint16 duty = 0U;

        numBytes = (TACHO_ILLUM_CHANNEL) * (NO_BYTES_PER_CHANNEL);

        for (index = 0; index < numBytes; index++)
        {
            flagData = (index % NO_BYTES_PER_CHANNEL);

            duty = ((duty << (flagData * NO_BITS_PER_BYTE)) | ((uint16)Data[index]));

            if (flagData != 0U)
            {
                if ((Meet_TachoIllumConfig[ChannelCount].TachoIllumFunction != NULL_PTR) && (duty <= MAX_DUTYVALUE_TACHO))
                {
                    RetVal = Meet_TachoIllumConfig[ChannelCount].TachoIllumFunction(duty, ErrorCode);
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
                }
                ChannelCount++;
                duty = 0U;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_Tacho_Illumination_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Tacho_Illumination_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount;

        for (ChannelCount = 0U; ChannelCount < TACHO_ILLUM_CHANNEL; ChannelCount++)
        {
            if (Meet_TachoIllumConfig[ChannelCount].TachoIllumFunction != NULL_PTR)
            {
                RetVal = Meet_TachoIllumConfig[ChannelCount].TachoIllumFunction(0U, ErrorCode);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
#endif

#ifdef IOCONTROlRD_DISPLAY_ILLUMINATION_ENABLE
/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_Display_Illumination_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Display_Illumination_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount = 0U;
        uint8 flagData;
        uint8 index;
        uint8 numBytes;
        uint16 duty = 0U;

        numBytes = (DISPLAY_ILLUM_CHANNEL) * (NO_BYTES_PER_CHANNEL);

        for (index = 0U; index < numBytes; index++)
        {
            flagData = (index % NO_BYTES_PER_CHANNEL);

            duty = ((duty << (flagData * NO_BITS_PER_BYTE)) | ((uint16)Data[index]));

            if (flagData != 0U)
            {
                if ((Meet_DisplayIllumConfig[ChannelCount].DisplayIllumFunction != NULL_PTR) && (duty <= MAX_DUTYVALUE_DISPLAY))
                {
                    RetVal = Meet_DisplayIllumConfig[ChannelCount].DisplayIllumFunction(duty, ErrorCode);
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    break;
                }
                ChannelCount++;
                duty = 0U;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}

/*=====================================================================================================================
** Function Name    :  Ioctrlrd_pwm_diag_Display_Illumination_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Display_Illumination_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        uint8 ChannelCount;

        for (ChannelCount = 0U; ChannelCount < DISPLAY_ILLUM_CHANNEL; ChannelCount++)
        {
            if (Meet_DisplayIllumConfig[ChannelCount].DisplayIllumFunction != NULL_PTR)
            {
                RetVal = Meet_DisplayIllumConfig[ChannelCount].DisplayIllumFunction(0U, ErrorCode);
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
#endif

#ifdef IOCONTROlRD_PWM_FREQUENCY_CONTROL_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_PWMFrequencyControl_STA
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_PWMFrequencyControl_STA(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    uint8 CtrlChannel;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        CtrlChannel = Data[0U];

        if ((CtrlChannel <= FREQ_CONTROL_CHANNEL) && (CtrlChannel != 0U))
        {
            if (Meet_FreqControlConfig[CtrlChannel - 1U].FreqControlFunction != NULL_PTR)
            {
                Meet_FreqControlConfig[CtrlChannel - 1U].DutyControlFunction(FREQ_CONTROL_CHANNEL_DUTY);
                /* Base frequency and calculation for multiplier shall be done in configuration files */
                Meet_FreqControlConfig[CtrlChannel - 1U].FreqControlFunction(Data);
            }
            RetVal = E_OK;
        }
        else
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return RetVal;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_PWMFrequencyControl_RCTE
**
** Visibility       :  Public
**
** Description      :  2F IO CONTROL dimming short term adjustment to ECU
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data , Error code
**
** Outputs          :  Std_ReturnType  E_OK || E_NOT_OK
**
** Critical Section : NO
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_PWMFrequencyControl_RCTE(uint8 *ErrorCode)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ChannelCount;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        for (ChannelCount = 0U; ChannelCount < FREQ_CONTROL_CHANNEL; ChannelCount++)
        {
            if (Meet_FreqControlConfig[ChannelCount].FreqControlFunction != NULL_PTR)
            {
                Meet_FreqControlConfig[ChannelCount].DutyControlFunction(0U);
                Meet_FreqControlConfig[ChannelCount].FreqControlFunction(0U); 
                RetVal = E_OK;
            }
        }
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }

    return RetVal;
}
#endif
#ifdef IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStart
**
** Visibility       :  Public
**
** Description      :  31 Routine service START-This function shall turn ON all the Illumination PWM channel
**       			   for Enabling ALL lit Illumination ON function should configure macro in IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE in meetmgr
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
Std_ReturnType Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Meet_All_LitPWMControlConfig.AllLitPWMControlStart(Data, ErrorCode);
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
** Function Name    :  Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStop
**
** Visibility       :  Public
**
** Description      :  31 Routine service STOP-This function shall turn OFF all the Illumination PWM channel
**       			   for Enabling ALL lit Illumination OFF function should configure macro in IOCONTOLRD_ALL_LIT_ILLUMINATION_ENABLE in meetmgr
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
Std_ReturnType Ioctrlrd_pwm_diag_All_Lit_Illumination_RCStop(uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        Meet_All_LitPWMControlConfig.AllLitPWMControlStop(ErrorCode);
        ret = E_OK;
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCTRLRD_PWM_INPUT_CHECK
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_Pwm_InputCheck_Read
**
** Visibility       :  Public
**
** Description      :  reads the value of PWM ports and return as a frequency
**
**
** Invocation       :  MeetMgr.diagcdd
**
** Inputs           :  Data[In]:NA
** 					   Error code:to be updated with error code if any
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : No
**
**====================================================================================================================*/
Std_ReturnType Ioctrlrd_pwm_diag_Pwm_InputCheck_Read(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ioctrlrd_PwmInputCheckConfig.Ioctrlrd_pwm_Diag_Read(Data, ErrorCode);
    }
    else
    {
        /*invalid mode*/
        *ErrorCode = INVALID_MODE;
    }

    return ret;
}
#endif

#ifdef IOCONTROlRD_PWM_GENBACKLIGHT_DIMMING
Std_ReturnType Ioctrlrd_GenBacklight_illum_STA(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ioctrld_GenBcklight_illumination_PWM_Ctrl(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Ioctrlrd_GenBacklight_illum_RCTE(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ioctrld_GenBcklight_illumination_PWM_RetCtrl(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTROlRD_PWM_PTRBACKLIGHT_DIMMING
Std_ReturnType Ioctrlrd_PtrBacklight_illum_STA(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ioctrld_PtrBcklight_illumination_PWM_Ctrl(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}

Std_ReturnType Ioctrlrd_PtrBacklight_illum_RCTE(uint8 *Data)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);

    if (MfgModeActive == MEET_SESSION)
    {
        ret = Ioctrld_PtrBcklight_illumination_PWM_RetCtrl(Data);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_PULSE_INPUT_CH1
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_pulse_input_CH1_RCStart
**
** Visibility       :  Public
**
** Description      :  31 Routine service START-This function shall get the pulse frequency from IoHwAbsSafe
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
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH1_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_PulseInputCH1Config.PulseInputCH1Start(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_pulse_input_CH1_RCResult
**
** Visibility       :  Public
**
** Description      :  31 Routine service STOP-This function shall give the result of pulse frequency calculated from IoHwAbsSafe
**       			   
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
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH1_RCResult(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_PulseInputCH1Config.PulseInputCH1Result(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
#endif

#ifdef IOCONTOLRD_PULSE_INPUT_CH2
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_pulse_input_CH2_RCStart
**
** Visibility       :  Public
**
** Description      :  31 Routine service START-This function shall get the pulse frequency from IoHwAbsSafe
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
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH2_RCStart(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_PulseInputCH2Config.PulseInputCH2Start(Data, ErrorCode);
    }
    else
    {
        *ErrorCode = INVALID_MODE;
    }
    return ret;
}
/*=====================================================================================================================
**
** Function Name    :  Ioctrlrd_pwm_diag_pulse_input_CH2_RCResult
**
** Visibility       :  Public
**
** Description      :  31 Routine service STOP-This function shall give the result of pulse frequency calculated from IoHwAbsSafe
**       			   
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
Std_ReturnType Ioctrlrd_pwm_diag_pulse_input_CH2_RCResult(uint8 *Data, uint8 *ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MfgModeActive = 0U;
    MGRDIAG_GET_SESSION(&MfgModeActive);
    if (MfgModeActive == MEET_SESSION)
    {
        ret = Meet_PulseInputCH2Config.PulseInputCH2Result(Data, ErrorCode);
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
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and MEET Pre-Condition check.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/Jan/2023
** CDSID             :  ajadhav5
** Traceability      :  RTC-1887181
** Change Description:  Period and Freq control function modified
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  03/Aug/2022
** CDSID             :  ddanecha
** Traceability      :  RTC-1707104
** Change Description:  MeetCdd Coverity-MISRA fix
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
** Change Description:  OutputControl, FuelEct, Tacho and Display illumination control interfaces are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  11/Sept/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1368184
** Change Description:  Dimming Control VIP or GIP check is removed from src file by making
                        Meet_DimmingControlConfig[ChannelCount].DimmingControlFunction common for both VIP and GIP
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/Mar/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1303833
** Change Description:  u16Dimm and u16Dimm_temp variables are enable based on the values of the macros
                        BCDMANIPUTATION_ENABLE_DIMMING_CTRL and DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  BCDMANIPUTATION_ENABLE_DIMMING_CTRL and DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL macro made feauture specific
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 01/Feb/2019
** CDSID             : razhakes
** Traceability      : RTC-1263593
** Change Description: Ioctrl update VIP - GIP communication
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 22/Dec/2018
** CDSID             : dkasiman
** Traceability      : RTC-1258974
** Change Description: Rte_MeetCdd.h file commented.
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
/*=====================================================================================================================
** Date              : 22/05/2018
** CDSID             : rkathir1
** Traceability      : RTC 1113549
** Change Description: Initial version - Ioctrl PWM Implementation for Turing Bookshelf.
**====================================================================================================================*/

#endif /* IOCRTLRD_PWM_DIAGCDD_C */
