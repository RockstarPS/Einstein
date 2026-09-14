/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2018. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*!***************************************************************************
* @ingroup Input-Output Hardware Abstraction
* @file IoHwAb.c
* @brief IoHwAb main layer which handles the Init, Mainfunctions and APIs for SWCs
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb.h"
#include "Rte_IoHwAb.h"
/*****************************************************************************
*  Private Macros Definitions                                                **
******************************************************************************/
/**
* @brief State of IoHwAb when module is uninitialized
*/
#define IOHWAB_UNINIT   0x5A5Au
/**
* @brief State of IoHwAb when module is idle
*/
#define IOHWAB_IDLE     0xA5A5u



#define IOHWAB_MODULE_ID                   0x0254U
#define IOHWAB_VENDOR_ID                   0x0033U
#define IOHWAB_AR_RELEASE_MAJOR_VERSION    0x04U
#define IOHWAB_AR_RELEASE_MINOR_VERSION    0x02U
#define IOHWAB_AR_RELEASE_PATCH_VERSION    0x01U
#define IOHWAB_SW_MAJOR_VERSION            0x01U
#define IOHWAB_SW_MINOR_VERSION            0x01U
#define IOHWAB_SW_PATCH_VERSION            0x47U

/******************************************************************************
*  Private Variable Definitions                                               *
*******************************************************************************/
#define IoHwAb_START_SEC_VAR_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

static uint16 IoHwAb_Status = IOHWAB_UNINIT; /**<  Initialize the status variable*/

#define IoHwAb_STOP_SEC_VAR_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb module
* @param     none
* @return    void
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_Init is verified and same as macro does not have any functional imapct.*/
void IoHwAb_Init(void)
{
    if(IoHwAb_Status == IOHWAB_UNINIT)
    {
        /* Initialize the adapters required for IoHwAb */
        /* MISRA C-2012 Directive 4.9 JUSTIFICATION: The macro IOHWAB_ADAPTER_INIT() is defined in IoHwAb_Cfg.h.This file uses it. Does not have functional impact.*/
        IOHWAB_ADAPTER_INIT()
        /* Set the status to idle once init is completed*/
        IoHwAb_Status = IOHWAB_IDLE;
    }

}

/**
* This method is the main function for IoHwAb module
* @param     none
* @return    void
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_MainFunction is verified and same as macro does not have any functional imapct.*/
void IoHwAb_MainFunction(void)
{
     /* WdgM checkpoint for IoHwAb safe */
    IOHWAB_WATCHDOG_SERVICE_CALL();
    
    /* Check if init is completed*/
    if(IoHwAb_Status !=IOHWAB_UNINIT)
    {
        /* MISRA C-2012 Rule 2.2 JUSTIFICATION: As per visteon coding standard IOHWAB_ADAPTER_DEINIT() is defined. This implementation is used for future purpose.*/
        /* MISRA C-2012 Rule 4.9 JUSTIFICATION: The macro IOHWAB_ADAPTER_MAINFUNCTION() is defined in IoHwAb_Cfg.h.This file uses it. Does not have functional impact.*/
        IOHWAB_ADAPTER_MAINFUNCTION()
    }
    
   
}

/**
* This method De-initialize the IoHwAb module
* @param     none
* @return    void
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_DeInit is verified and same as macro does not have any functional imapct.*/
void IoHwAb_DeInit(void)
{
    /* MISRA C-2012 Directive 4.9 JUSTIFICATION: The macro IOHWAB_ADAPTER_DEINIT() is defined in IoHwAb_Cfg.h.This file uses it. Does not have functional impact.*/
    IOHWAB_ADAPTER_DEINIT()
    /* Uninitialize the IoHwAb*/
    IoHwAb_Status = IOHWAB_UNINIT;
}

#if (IOHWAB_DOUT_ENABLE == STD_ON)
/**
* This method is used to set the Output Pin
* @param     OutputId 		- ID of the Output signal
* @param     OutputSignal   - Value needs to be set for Output signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_SetOutputPin is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_SetOutputPin is verified and same as macro does not have any functional imapct.*/
Std_ReturnType IoHwAb_SetOutputPin(IoHwAb_DOutSignalIdType OutputId, boolean OutputSignal, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DOut_SetOutputPin(OutputId, OutputSignal, ErrorStatus);
    }
    return RetValue;
}
/**
* This method is used to set the output as a group of output pins
* @param     OutputGroupId 	- ID of the Output group
* @param     OutputGroup    - Value needs to be set for Output signal- each bit is considered as single output signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_SetOutputGroup is in RTE does not have any functional impact.*/
/* MISRA C-2012 Rule 8.7 JUSTIFICATION: As per code design, the function IoHwAb_SetOutputGroup declared as extern and will be used by other components in future.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_SetOutputGroup is verified and same as macro does not have any functional imapct.*/
Std_ReturnType  IoHwAb_SetOutputGroup(IoHwAb_DOutGroupIdType OutputGroupId, uint32 OutputGroup, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DOut_SetOutputGroup(OutputGroupId, OutputGroup, ErrorStatus);
    }
    return RetValue;
}

#endif

#if (IOHWAB_DIN_ENABLE == STD_ON)
/**
* This method is used to get the input value after processing
* @param     InputId 		- ID of the input signal
* @param     InputSignal    - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetProcessedInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_GetProcessedInput is verified and same as macro does not have any functional imapct.*/
Std_ReturnType IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, boolean* InputSignal, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DIn_GetProcessedValue(InputId, InputSignal, ErrorStatus);
    }
    return RetValue;
}
/**
* This method is used to get the raw input value from the stored buffer- Asynchronous
* @param     InputId 		- ID of the input signal
* @param     AsyncInput     - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetAsyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetAsyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard, function IoHwAb_GetAsyncRawInput is verified and same as macro does not have any functional impact.*/
Std_ReturnType IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, boolean* AsyncInput, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DIn_GetASyncRawValue(InputId,AsyncInput, ErrorStatus);
    }
    return RetValue;
}
/**
* This method is used to get the raw input value synchronously reading MCAL
* @param     InputId 		- ID of the input signal
* @param     SyncInput      - parameter to get the value of the input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetSyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 8.5 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetSyncRawInput is in Os_TrustedServiceCfg.h does not have any functional impact.*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard, function IoHwAb_GetSyncRawInput is verified and same as macro does not have any functional impact.*/
Std_ReturnType IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, boolean* SyncInput, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DIn_GetSyncRawValue(InputId, SyncInput, ErrorStatus);
    }
    return RetValue;
}

/**
* This method is used to get the raw input value from the stored buffer- Asynchronous
* @param     InputGroupId 	- ID of the input signal
* @param     InputGroup     - parameter  to be get the input group- each bit holds the value of each single input signal
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard,function IoHwAb_GetInputGroup is verified and same as macro does not have any functional imapct.*/
/* MISRA C-2012 Rule 8.7 JUSTIFICATION: As per code design, the function IoHwAb_GetInputGroup declared as extern and will be used by other components in future.*/
Std_ReturnType  IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputGroupId, uint32* InputGroup, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_DIn_GetGroup(InputGroupId, InputGroup, ErrorStatus);
    }
    return RetValue;
}
#endif
#if (IOHWAB_ADC_ENABLE == STD_ON)
/**
* This method is used to get the Adc singal value after processing
* @param     AdcId 	        - ID of the Adc signal
* @param     ProcessedAdc   - parameter  to be get the processed adc value
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_GetProcessedAdc is verified and same as macro does not have any functional imapct.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetProcessedAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, sint32* ProcessedAdc, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_Adc_GetProcessedAdc(AdcId, ProcessedAdc, ErrorStatus);
    }
    return RetValue;
}
/**
* This method is used to get the raw adc value from stored buffer - Asynchronus
* @param     AdcId 	         - ID of the Adc signal
* @param     AsyncRawAdc     - parameter  to be get the input adc raw value
* @return    Std_ReturnType  - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_GetAsyncRawAdc is verified and same as macro does not have any functional imapct.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetAsyncRawAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, uint16* AsyncRawAdc, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_Adc_GetAsyncRawAdc(AdcId, AsyncRawAdc, ErrorStatus);
    }
    return RetValue;
}
/**
* This method is used to get the raw adc value synchronously from MCAL
* @param     AdcId 	        - ID of the Adc signal
* @param     SyncRawAdc     - parameter  to be get the input adc raw value
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Rule 5.5 JUSTIFICATION: As per visteon coding standard function IoHwAb_GetSyncRawAdc is verified and same as macro does not have any functional imapct.*/
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_GetSyncRawAdc is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, uint16* SyncRawAdc, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Dout interface to set the pin*/
        RetValue = IoHwAb_Adc_GetSyncRawAdc(AdcId,SyncRawAdc, ErrorStatus);
    }
    return RetValue;
}

#endif

#if (IOHWAB_PWM_ENABLE == STD_ON)
/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetDuty is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_PwmSetDuty(IoHwAb_PwmSignalIdType PwmId, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Pwm interface to set the Duty*/
        RetValue = IoHwAb_Pwm_SetDuty(PwmId, Pwm_Duty, ErrorStatus);
    }
    return RetValue;
}

/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetDutyAndPeriod is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_PwmSetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, uint32 Pwm_Period, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Pwm interface to set the Period and Duty*/
        RetValue = IoHwAb_Pwm_SetDutyAndPeriod(PwmId, Pwm_Period, Pwm_Duty, ErrorStatus);
    }
    return RetValue;
}

/* MISRA C-2012 Rule 8.3 JUSTIFICATION: As per code design, the other declaration of IoHwAb_PwmSetIdeal is in Os_TrustedServiceCfg.h does not have any functional impact.*/
Std_ReturnType IoHwAb_PwmSetIdeal(IoHwAb_PwmSignalIdType PwmId,  IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IOHWAB_UNINIT == IoHwAb_Status)
    {
        *ErrorStatus = IOHWAB_E_ERROR;
    }
    else
    {
        /* Call the Pwm interface to set PWM to Idle*/
        RetValue = IoHwAb_Pwm_SetIdeal(PwmId, ErrorStatus);
    }
    return RetValue;
}

#endif

#if (IOHWAB_VERSION_INFO_API == STD_ON)
/**
 * @brief GetVersionInfo -  Service to return version info of the module
 *
 * @param VersionInfo
 *
 * @return void
 */
void IoHwAb_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if(NULL_PTR != VersionInfo)
    {
        VersionInfo->vendorID         = IOHWAB_VENDOR_ID;
        VersionInfo->moduleID         = IOHWAB_MODULE_ID;
        VersionInfo->sw_major_version = IOHWAB_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = IOHWAB_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = IOHWAB_SW_PATCH_VERSION;
    }
}
#endif

#if defined(IOHWAB_PULSEINPUT_ENABLE) && (IOHWAB_PULSEINPUT_ENABLE == STD_ON)
/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	          - ID of the  signal
* @param     PulseInputChnlCfgParam   - Hold the configuration paramter for the pulse input
* @param     SSpeedCalcParam          - Hold the configuration paramter for the speed calculations
* @param     ErrorStatus              -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Start_Signal_Measurement_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, SPulseInputConfigParam *PulseInputChnlCfgParam, SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Function initaite the start for the PIC module*/
        RetValue = IoHwAb_PulseInput_Start_Signal_Measurement(PulseInputId, PulseInputChnlCfgParam, SpdCalParam,ErrorStatus);
    }

    return RetValue;
}

/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	- ID of the  signal
* @param     ErrorStatus    -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Stop_Signal_Measurement_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Function initaite the stop for the PIC module*/
        RetValue = IoHwAb_PulseInput_Stop_Signal_Measurement(PulseInputId,ErrorStatus);

    }

    return RetValue;
}


/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	   - ID of the  signal
* @param     SSpeedCalcParam   - Hold the configuration paramter for the speed calculations
* @param     ErrorStatus       -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_Update_CalibParam_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId,SSpeedCalcParam *SpdCalParam, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Function used to update calibparam for the pulse input*/
        RetValue = IoHwAb_PulseInput_Update_CalibParam(PulseInputId, SpdCalParam,ErrorStatus);

    }

    return RetValue;
}

/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	 - ID of the  signal
* @param     EdgeCount       - get the rolling counts
* @param     ErrorStatus     -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_GetRollingCount_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint8 *EdgeCount,  IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Function used to get rolling counts*/
        RetValue = IoHwAb_PulseInput_GetRollingCount(PulseInputId, EdgeCount,ErrorStatus);
    }

    return RetValue;
}


/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	 - ID of the  signal
* @param     ErrorStatus     -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_ResetRollingCount_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Function used to reset rolling counts*/
        RetValue = IoHwAb_PulseInput_ResetRollingCount(PulseInputId,ErrorStatus);

    }

    return RetValue;
}

/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	 - ID of the  signal
* @param     SignalStatus    -Provide the status of duty , period  signals
* @param     ErrorStatus     -  Send whethr the data is processed properly
* @return    Std_ReturnType  - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_GetCurrentSignalStatus_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint16 *SignalStatus, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /* Get the current signal status*/
        RetValue = IoHwAb_PulseInput_GetCurrentSignalStatus(PulseInputId, SignalStatus,ErrorStatus);
    }

    return RetValue;
}

/**
* This method is used to get the Adc singal value after processing
* @param     PulseInputId 	- ID of the  signal
* @param     SpeedVal       - get the current speed of the signal
* @param     ErrorStatus    -  Send whethr the data is processed properly
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
Std_ReturnType IoHwAb_GetCurrentSpeed_PulseInput(IoHwAb_PulseInputSignalIdType PulseInputId, uint32* SpeedVal, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType RetValue= E_NOT_OK;

    if(IoHwAb_Status != IOHWAB_UNINIT)
    {
        /*Get the current spped */
        RetValue = IoHwAb_PulseInput_GetCurrentSpeed(PulseInputId, SpeedVal,ErrorStatus);
    }

    return RetValue;
}


#define IoHwAb_STOP_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

#endif
/*End of File*/
/*****************************************************************************
*  for each change to this file, be sure to record:                         *
*     1.  who made the change and when the change was made                  *
*     2.  why the change was made and the intended result                   *
*  Following block needs to be repeated for each change
******************************************************************************
*  Note: In the trace-ability column we need to trace back to the Design Doc.*
*  For the initial version it is traced to the Design Document section.     *
*  For further changes it shall trace to the source of the change which may *
*  be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*  other reason                                                            *
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1181436:MMC: Safe IoHwAb Delivery
Change Description:Initial Version for IoHwAb safe implementation
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC- RTC #1240636: MMC:Callback function required in
                   IoHwAb_MainFunction safe
Change Description:Added macro for WdgM checkpoint
******************************************************************************/
/*****************************************************************************
Date              :22-Aug-2018
By                :pragesh
Traceability      :RTC-1246752: MMC: Coverity & MISRA warnings analysis, fix
                   and approve
Change Description:Updated memory location of IoHwAb_Status.
******************************************************************************/
/*****************************************************************************
Date              :5-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:Updated for IoHwAb_PulseInput safe implementation
******************************************************************************/
/*****************************************************************************
Date              :21-Dec-2018
By                :nrajaman
Traceability      :1206553: Hyundai SP2: PIC component upgrade for ASIL compliance.
Change Description:PR comments updated
******************************************************************************/
/*****************************************************************************
Date              :02-Aug-2022
By                :jkanikal
Traceability      :1710112:[vautosar]iohwab quality
Change Description:IoHwAb Audit Fix Coverity Misra warnings fix
******************************************************************************/
/*****************************************************************************
Date              :17-Aug-2022
By                :jkanikal
Traceability      :1736922: [vautosar]BSW general requirements for IOHW
Change Description:Added GetVersionInfo API as per bsw generalrequiremenr
******************************************************************************/
