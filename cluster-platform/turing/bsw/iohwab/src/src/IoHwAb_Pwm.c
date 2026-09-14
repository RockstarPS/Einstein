
//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

/*!********************************************************************************************************************
* @ingroup PwmOutput
* @file IoHwAb_Pwm.c
* @brief Provide interfaces for setting the period & duty values.
* ********************************************************************************************************************/

#include "IoHwAb_Pwm.h"
#include "IoHwAb_Filter.h"
#include "Rte_IoHwAb.h"

#if(IOHWAB_PWM_ENABLE == STD_ON)

#define IOHWAB_PWM_STATE_IDEAL        0u
#define IOHWAB_PWM_STATE_ACTIVE       1u

#define IOHWAB_E_PWM_ID_INVALID       (2u)   /* Should be configured in RTE */

/**_
* @brief This structure defines states of PWM adapter
*/

typedef struct
{
    uint32                      RefreshPwmPeriod;
    uint16                      RefreshPwmDuty;
    boolean                     ValidRefreshDuty;
    boolean                     ValidRefreshPeriod;
    boolean                     PwmState;
    boolean                     PeriodicRefreshRequested;
    boolean                     APIRequested;
    boolean                     EdgeNotificationStarted;
} IoHwAb_PwmManagementType;
/**
* @brief This structure defines different status variables of Digital output adapter
*/
typedef struct
{
    uint16                  RefreshCount;
    uint8                   PwmVariantId;      /**< Digital Output Variant Id */
} IoHwAb_PwmStatusType;

static void IoHwAb_Pwm_PeriodicRefresh(void);
/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/
#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

static IoHwAb_PwmStatusType IoHwAb_PwmStatus;                                     /**<  Digital output variant Id*/
static IoHwAb_PwmManagementType IoHwAb_PwmManagement[IOHWAB_NUM_OF_PWM_OUTPUT];     /**<  stores the digital output values for refreshing*/

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>


#define IoHwAb_START_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>
/**
* This method is the Init function for IoHwAb Pwm
* @param     none
* @return    void
*/
void IoHwAb_Pwm_Init(void)
{
    uint16 Index;
    Std_ReturnType VariantResult;

    VariantResult = IoHwAb_Pwm_GetCurrentVariant(&IoHwAb_PwmStatus.PwmVariantId);

    if(E_OK != VariantResult)
    {
        IoHwAb_PwmStatus.PwmVariantId = IOHWAB_MAX_NUM_OF_PWM_VARIANT;
    }
    if( IoHwAb_PwmStatus.PwmVariantId >= IOHWAB_MAX_NUM_OF_PWM_VARIANT)
    {
        /* Init the Refresh value */
        for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
        {
            IoHwAb_PwmManagement[Index].RefreshPwmPeriod =   0u;
            IoHwAb_PwmManagement[Index].RefreshPwmDuty =     0u;
            /* Set PWM state to IDEAL and all the Valid refresh flags to FALSE during Init*/
            IoHwAb_PwmManagement[Index].PwmState       = IOHWAB_PWM_STATE_IDEAL;
            IoHwAb_PwmManagement[Index].ValidRefreshPeriod = FALSE;
            IoHwAb_PwmManagement[Index].ValidRefreshDuty = FALSE;
            IoHwAb_PwmManagement[Index].PeriodicRefreshRequested = FALSE;
            IoHwAb_PwmManagement[Index].APIRequested = FALSE;
            IoHwAb_PwmManagement[Index].EdgeNotificationStarted = FALSE;

        }
    }
    else
    {
        /* Set PWM state to IDEAL and all the Valid refresh flags to FALSE during Init*/
        /* Dont output any Duty or PEriod untill or unless requested by Application, Make all values to 0*/
        for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
        {
            IoHwAb_PwmManagement[Index].RefreshPwmPeriod = 0u;
            IoHwAb_PwmManagement[Index].RefreshPwmDuty =   0u;
            IoHwAb_PwmManagement[Index].PwmState       =   IOHWAB_PWM_STATE_IDEAL;
            IoHwAb_PwmManagement[Index].ValidRefreshPeriod = FALSE;
            IoHwAb_PwmManagement[Index].ValidRefreshDuty = FALSE;
            IoHwAb_PwmManagement[Index].PeriodicRefreshRequested = FALSE;
            IoHwAb_PwmManagement[Index].APIRequested = FALSE;
            IoHwAb_PwmManagement[Index].EdgeNotificationStarted = FALSE;
        }
    }
    /* Init the Refresh count*/
    IoHwAb_PwmStatus.RefreshCount = 0u;

}
/**
* This method is the main function for IoHwAb Pwm output
* @param     none
* @return    void
*/
void IoHwAb_Pwm_MainFunction(void)
{
    Std_ReturnType VariantResult;
    Std_ReturnType ProcessMainFunction = E_OK;

    if(E_OK != IoHwAb_Pwm_PreHook())
    {
        ProcessMainFunction = E_NOT_OK;
    }
    VariantResult = IoHwAb_Pwm_GetCurrentVariant(&IoHwAb_PwmStatus.PwmVariantId);

    if(E_OK != VariantResult)
    {
        IoHwAb_PwmStatus.PwmVariantId = IOHWAB_MAX_NUM_OF_PWM_VARIANT;
        ProcessMainFunction = E_NOT_OK;
    }
    if(IoHwAb_PwmStatus.PwmVariantId >= IOHWAB_MAX_NUM_OF_PWM_VARIANT)
    {
        ProcessMainFunction = E_NOT_OK;
    }
    if(E_OK == ProcessMainFunction)
    {
        IoHwAb_Pwm_PeriodicRefresh();
    }
}

/**
* This method will write the PWM outputs periodically to refresh the state. Refreshing is done in specific counts per cycle
* to reduce the cpu load
* @param     none
* @return    void
*/
static void IoHwAb_Pwm_PeriodicRefresh(void)
{
    /* MISRA C-2012 Directive 4.4 JUSTIFICATION: The code snippet done as intentional is verified and does not have any functional impact.*/
    /* #if (IOHWAB_PWM_REFRESH_PERCYCLE > 0)*/
    uint16 Index;
    uint16 CurrentCycleRefreshCount = 0u;
    uint32 TempPeriod;
    uint16 TempDuty;

    /* Init the Refresh value*/
    for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
    {
        if((IoHwAb_PwmManagement[Index].ValidRefreshPeriod == FALSE) && (IoHwAb_PwmManagement[Index].ValidRefreshDuty == FALSE))
        {
            /* Make PWM state to IDEAL to not output*/
            IoHwAb_PwmManagement[Index].PwmState = IOHWAB_PWMS_STATE_IDEAL;
        }
        else
        {
            /* Make PWM state to ACTIVE to  output*/
            IoHwAb_PwmManagement[Index].PwmState = IOHWAB_PWMS_STATE_ACTIVE;
        }
    }

    /* Write the mcal PWM in a fixed count per cycle*/
    for(Index = IoHwAb_PwmStatus.RefreshCount ; (Index < IOHWAB_NUM_OF_PWM_OUTPUT)&&(CurrentCycleRefreshCount < IOHWAB_PWM_REFRESH_PERCYCLE); Index ++)
    {
        if(IOHWAB_PWMS_STATE_IDEAL != IoHwAb_PwmManagement[Index].PwmState)
        {
            /* Check for valid DUTY value already requested and periodic refresh is required*/

            if(TRUE == IoHwAb_PwmManagement[Index].ValidRefreshDuty)
            {
                TempDuty = IoHwAb_PwmManagement[Index].RefreshPwmDuty;

                /* Check for valid PERIOD value already requested and periodic refresh is required*/
                if(TRUE == IoHwAb_PwmManagement[Index].ValidRefreshPeriod)
                {
                    TempPeriod = IoHwAb_PwmManagement[Index].RefreshPwmPeriod;

                    /* Output both DUTY and PERIOD if both refresh required*/
                    /* MISRA C-2012 Rule 10.3 JUSTIFICATION: The values are verified and does not have functional impact.*/
                    if((IoHwAb_PwmCfg[Index].PwmDutyPeriodUpdateOnEdgeNotification == FALSE) || \
                                            (IoHwAb_PwmManagement[Index].EdgeNotificationStarted == FALSE))
                    {
                        if(TempPeriod != 0u)
						{
							/* Call PWM MCAL API directly, if not required to update on Edge Notification*/
							Pwm_SetPeriodAndDuty(IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId,TempPeriod,TempDuty);
						}
						else
						{
							IoHwAb_PwmManagement[Index].PeriodicRefreshRequested = FALSE;
							IoHwAb_PwmManagement[Index].APIRequested = FALSE;
							IoHwAb_PwmManagement[Index].EdgeNotificationStarted = FALSE;
							Pwm_SetOutputToIdle(IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId);							
						}
                    }
                    else
                    {
                        /*Set internal requested flag to true, if update required on Edge Notification*/
                        IoHwAb_PwmManagement[Index].PeriodicRefreshRequested = TRUE;
                    }
                }
                else
                {
                    if((IoHwAb_PwmCfg[Index].PwmDutyPeriodUpdateOnEdgeNotification == FALSE) || \
                                            (IoHwAb_PwmManagement[Index].EdgeNotificationStarted == FALSE))
                    {
                        /* Output Only DUTY if PERIOD  refresh is not required*/
                        Pwm_SetDutyCycle(IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId,TempDuty );
                    }
                    else
                    {    /*Set internal requested flag to true, if update required on Edge Notification*/
                        IoHwAb_PwmManagement[Index].PeriodicRefreshRequested = TRUE;
                    }
                }
            }
        }
        /* MISRA C-2012 Rule 14.2 JUSTIFICATION: The value of CurrentCycleRefreshCount is checked and it is modified in the function as code design. Hence does not have any functional impact.*/
		CurrentCycleRefreshCount++;
        IoHwAb_PwmStatus.RefreshCount++;
    }
    /* Clear the refresh count when it is greater than or equal to number of outputs*/
    if(IoHwAb_PwmStatus.RefreshCount >= IOHWAB_NUM_OF_PWM_OUTPUT)
    {
        IoHwAb_PwmStatus.RefreshCount = 0u;
    }
    //#endif
}


/**
* This method is used to set the PWM Output
* @param     ChannelId 		- Channel Number of the PWM OUTPUT
* @param     Pwm_Duty     - Value needs to be set for Output Duty
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetDuty is in Os_TrustedServiceCfg.h and does not have any functional impact.*/

Std_ReturnType IoHwAb_Pwm_SetDuty(IoHwAb_PwmSignalIdType PwmId, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus)
{
    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    sint32 CalcPwmDuty;

    if(IoHwAb_PwmStatus.PwmVariantId >= IOHWAB_MAX_NUM_OF_PWM_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;   /* RTE Config*/
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
        {
            /* If Pwm SIgnald matches with Pwm HW Channel Id*/
            if (PwmId == IoHwAb_PwmCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_OF_PWM_OUTPUT)
        {
            JobResult = E_NOT_OK;
            *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;   /* RTE Config*/
        }
        else
        {
            /* Convert the PWM output to Calculated Output*/
            JobResult = IoHwAb_Filter_ResolutionCalc((IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].PwmDuty_ResolutionId), (uint32)Pwm_Duty, &CalcPwmDuty);
            if((E_OK == JobResult) && (((sint32)IOHWAB_PWM_DUTY_MIN <= CalcPwmDuty) && ((sint32)IOHWAB_PWM_DUTY_MAX >= CalcPwmDuty)))            {
                if((IoHwAb_PwmCfg[Index].PwmDutyPeriodUpdateOnEdgeNotification == FALSE) || \
                                            (IoHwAb_PwmManagement[Index].EdgeNotificationStarted == FALSE))
                {
                    /* Call PWM MCAL API directly, if not required to update on Edge Notification*/
                  Pwm_SetDutyCycle(IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId, (uint16)CalcPwmDuty );
                }
                else
                {
                    /*Set internal requested flag to true, if update required on Edge Notification*/
                    IoHwAb_PwmManagement[Index].APIRequested = TRUE;
                }
                /* Update the output value to refresh value for periodic refreshing*/
                IoHwAb_PwmManagement[Index].RefreshPwmDuty = (uint16)CalcPwmDuty;
                IoHwAb_PwmManagement[Index].ValidRefreshDuty = TRUE;
                IoHwAb_PwmManagement[Index].PwmState       =   IOHWAB_PWM_STATE_ACTIVE;
            }
            else
            {
                JobResult = E_INVALID_ARG;
            }
            
        }
    }
    return JobResult;
}

/* This method is used to set the PWM Output
* @param     PwmId 		- Channel Number of the PWM OUTPUT
* @param     Pwm_Period     - Value needs to be set for Output Duty
* @param     Pwm_Duty       - Value of the Pwm Period
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/

/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetDutyAndPeriod is in Os_TrustedServiceCfg.h and does not have any functional impact.*/

Std_ReturnType IoHwAb_Pwm_SetDutyAndPeriod(IoHwAb_PwmSignalIdType PwmId, uint32 Pwm_Period, uint16 Pwm_Duty, IoHwAb_ErrorType* ErrorStatus)
{

    Std_ReturnType JobResult = E_OK;
    uint16 Index;
    sint32 CalcPwmDuty;
    sint32 CalcPwmPeriod;

    if(IoHwAb_PwmStatus.PwmVariantId >= IOHWAB_MAX_NUM_OF_PWM_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;    /* RTE Config*/
    }
    else
    {
        for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
        {
            if (PwmId == IoHwAb_PwmCfg[Index].SignalId)
            {
                break;
            }
        }
        if(Index >= IOHWAB_NUM_OF_PWM_OUTPUT)
        {
            JobResult = E_NOT_OK;
            *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;
        }
        else
        {
            uint32 LocalPwmPeriod = Pwm_Period;
			if(LocalPwmPeriod > IOHWAB_PWM_PERIOD_MASK)  // Values greater than this threshold allowable value for PWM period are reset to 0 to maintain valid period ranges.
			{
				LocalPwmPeriod = 0U;
			}
            /* Convert the PWM output to Calculated value*/
            JobResult |= IoHwAb_Filter_ResolutionCalc((IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].PwmDuty_ResolutionId), (uint32) Pwm_Duty, &CalcPwmDuty);
            JobResult |= IoHwAb_Filter_ResolutionCalc((IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].PwmPeriod_ResolutionId), LocalPwmPeriod, &CalcPwmPeriod);

            if((E_OK == JobResult) && (((sint32)IOHWAB_PWM_DUTY_MIN <= CalcPwmDuty) && ((sint32)IOHWAB_PWM_DUTY_MAX >= CalcPwmDuty)))
            {
                if((IoHwAb_PwmCfg[Index].PwmDutyPeriodUpdateOnEdgeNotification == FALSE) || \
                                            (IoHwAb_PwmManagement[Index].EdgeNotificationStarted == FALSE))
                {
                    /* Call PWM MCAL API directly, if not required to update on Edge Notification*/
                    Pwm_SetPeriodAndDuty(IoHwAb_PwmCfg[Index].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId, (Pwm_PeriodType) CalcPwmPeriod, (uint16) CalcPwmDuty );
					IoHwAb_PwmManagement[Index].EdgeNotificationStarted = FALSE;
					if(0 < CalcPwmPeriod)
					{
						IoHwAb_PwmManagement[Index].EdgeNotificationStarted = TRUE;
					}
                }
                else
                {
                    /*Set internal requested flag to true, if update required on Edge Notification*/
                    IoHwAb_PwmManagement[Index].APIRequested = TRUE;
                }
                /* Update the output value to refresh value for periodic refreshing*/
                IoHwAb_PwmManagement[Index].RefreshPwmDuty = (uint16)CalcPwmDuty;
                IoHwAb_PwmManagement[Index].RefreshPwmPeriod = (uint32)CalcPwmPeriod;
                IoHwAb_PwmManagement[Index].ValidRefreshDuty = TRUE;
                IoHwAb_PwmManagement[Index].ValidRefreshPeriod = TRUE;
                IoHwAb_PwmManagement[Index].PwmState  = IOHWAB_PWM_STATE_ACTIVE;
            }
            else
            {
                JobResult = E_INVALID_ARG;
            }
        }
    }
    return JobResult;
}

/**
* This method is used to set the PWM Channel to IDEAL State (LOW)
* @param     PwmId 		- Channel Number of the PWM OUTPUT
* @return    Std_ReturnType - E_OK-Operation successful, E_NOT_OK-Operation failure
*/
/* MISRA C-2012 Directive 4.5 JUSTIFICATION: The other declaration of IoHwAb_Pwm_SetIdeal is in Os_TrustedServiceCfg.h and does not have any functional impact.*/
Std_ReturnType IoHwAb_Pwm_SetIdeal(IoHwAb_PwmSignalIdType PwmId, IoHwAb_ErrorType* ErrorStatus)
{

    Std_ReturnType JobResult = E_OK;
    uint16 Index;

    if(IoHwAb_PwmStatus.PwmVariantId >= IOHWAB_MAX_NUM_OF_PWM_VARIANT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;    /* RTE Config*/
    }
    for(Index = 0u ; Index < IOHWAB_NUM_OF_PWM_OUTPUT; Index ++)
    {
        if (PwmId == IoHwAb_PwmCfg[Index].SignalId)
        {
            break;
        }
    }
    if(Index >= IOHWAB_NUM_OF_PWM_OUTPUT)
    {
        JobResult = E_NOT_OK;
        *ErrorStatus = IOHWAB_E_PWM_ID_INVALID;
    }
    if(E_OK == JobResult)
    {
        (void)Pwm_SetOutputToIdle((Pwm_ChannelType)PwmId);
        IoHwAb_PwmManagement[PwmId].PeriodicRefreshRequested = FALSE;
        IoHwAb_PwmManagement[PwmId].APIRequested = FALSE;
        IoHwAb_PwmManagement[PwmId].EdgeNotificationStarted = FALSE;
    }
    return JobResult;
}

void IoHwAb_PWM_Edge_Notify(IoHwAb_PwmSignalIdType PwmID)
{
    uint32 TempPeriod;
    uint16 TempDuty;

    IoHwAb_PwmManagement[PwmID].EdgeNotificationStarted = TRUE;
    if((IoHwAb_PwmManagement[PwmID].PeriodicRefreshRequested == TRUE) || \
        (IoHwAb_PwmManagement[PwmID].APIRequested == TRUE))
    {
        if(TRUE == IoHwAb_PwmManagement[PwmID].ValidRefreshDuty)
        {
            TempDuty = IoHwAb_PwmManagement[PwmID].RefreshPwmDuty;
            if((TempDuty == 0u) || (TempDuty == 0x8000u))
            {
                /* If Duty requested is 0, then we won't get further edge notification
                    So we rely on the periodic refresh or User API to set the new duty cycle*/
                IoHwAb_PwmManagement[PwmID].EdgeNotificationStarted = FALSE;
            }
            /* Check for valid PERIOD value already requested and periodic refresh is required*/
            if(TRUE == IoHwAb_PwmManagement[PwmID].ValidRefreshPeriod)
            {
                TempPeriod = IoHwAb_PwmManagement[PwmID].RefreshPwmPeriod;
                Pwm_SetPeriodAndDuty(IoHwAb_PwmCfg[PwmID].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId,TempPeriod,TempDuty);
				//***//
				if(TempPeriod == 0u)
				{
					/* if period is 0 there will not be any edge notification further */
					IoHwAb_PwmManagement[PwmID].PeriodicRefreshRequested = FALSE;
					IoHwAb_PwmManagement[PwmID].APIRequested = FALSE;
					IoHwAb_PwmManagement[PwmID].EdgeNotificationStarted = FALSE;
					/* Set PWM to idle (low) state */
					Pwm_SetOutputToIdle(IoHwAb_PwmCfg[PwmID].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId);
				}
				
            }
            else
            {
                Pwm_SetDutyCycle(IoHwAb_PwmCfg[PwmID].IoHwAb_PwmChannel[IoHwAb_PwmStatus.PwmVariantId].Pwm_ChannelId,TempDuty );
            }
        }
        IoHwAb_PwmManagement[PwmID].PeriodicRefreshRequested = FALSE;
        IoHwAb_PwmManagement[PwmID].APIRequested = FALSE;
    }
}

/**
* This method is the DeInit function for IoHwAb Pwm
* @param     none
* @return    void
*/
void IoHwAb_Pwm_DeInit(void)
{

    /* Need to decide whether to Set the PWM channel to IDEAL State here*/

}

#define IoHwAb_STOP_SEC_CODE
/* MISRA C-2012 Rule 20.1 JUSTIFICATION: As per Autosar Standard,IoHwAb_MemMap.h is used to map memory segments in IoHwAb.*/
#include <IoHwAb_MemMap.h>

#endif

/* End of File*/
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
Date              :7-Feb-2020
By                :PPARIMI1
Traceability      :758686: JLR RICM IoHwAb PWM changes
Change Description:Initial Version for IoHwAb PWM chnages
******************************************************************************/
/*****************************************************************************
Date              :2-Jun-2020
By                :bbaskara
Traceability      :877370: IoHwAb:Compiler warning due to same macro usage in
                    PWM & Dout
Change Description:Updated the Macro name
******************************************************************************/
/*****************************************************************************
Date              :29-April-2021
By                :akv
Traceability      :1307388: IoHwAb pwm : wrong check
Change Description: Wrong check against the resolution multiplier is removed.
					boundary check for pwm duty is added.
******************************************************************************/
/*****************************************************************************
Date              :30-April-2021
By                :akv
Traceability      :1259373: IoHwAb_Pwm periodic refresh issue.
Change Description: closing bracket are corrected to proper place
******************************************************************************/
/*****************************************************************************
Date              :25-July-2021
By                :akv
Traceability      :1400410: Nissan C53L: Compiler Warning in IoHwAb_Pwm.c file
Change Description: New line is aded at the end of the file.
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
Change Description:Added Misra warning comments as per bsw generalrequiremenr
******************************************************************************/
/*****************************************************************************
Date              :18-Aug-2023
By                :abandlap
Traceability      :vAutosar IoHwAb Streamline Update
Change Description:Added a timer support function for pwm configured channel.
******************************************************************************/
/*****************************************************************************
Date              :13-Jun-2024
By                :msavariy
Traceability      : https://visteon.atlassian.net/browse/NS30479-87888
Change Description: PMW HW which doesn't support wait for period to complete, the logic updated 
                    to use PWM edge notification to update new period.
******************************************************************************/
