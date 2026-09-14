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
* @file IoHwAb_PulseOut.c
* @brief Capturing and processing of Pulse Output module
* ****************************************************************************/
/*****************************************************************************
*  Include Files                                                             *
******************************************************************************/
#include "IoHwAb_PulseOut.h"
#include "IoHwAb_Gpt.h"
#include "Rte_IoHwAb.h"

#if (IOHWAB_PULSEOUT_ENABLE == STD_ON)
/*****************************************************************************
*  Private Variable Definitions                                              *
******************************************************************************/
/**
* @brief Structure to store the Pulseout time duration
*/
typedef struct
{
    uint32  	HighPulseDuration ;		             /**< variable to store the high pulse out duration .Hold the time in ms. */
    uint32   	LowPulseDuration ;	                     /**< variable to store the low pulse out duration.Hold the time in ms. */
    boolean  	PulseOutPinStatus ;		              /**< variable to store the PulseOutPinStatus status. */
} IoHwAb_PulseOutTimeDurationType;

#define IoHwAb_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>
/*Structure is used to monitor periodically the time, vehicle status and PulseOutPINID*/
/*Data to this structure will be updated only by SWC*/
static IoHwAb_PulseOutDataType    			IoHwAb_TotalPulseOutDuration;

/*Structure is used to hold the high pulse out time , low pulse out time and the pins status */
static IoHwAb_PulseOutTimeDurationType    	IoHwAb_PulseOutTimeDuration;

/*variable tell when to accept load the new time */
static boolean IoHwAb_PulseOutAcceptNewTime;

#define IoHwAb_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include <IoHwAb_MemMap.h>

/******************************************************************************
*  Public Function Definitions                                                *
*******************************************************************************/
#define IoHwAb_START_SEC_CODE
#include <IoHwAb_MemMap.h>
/**
* This method initialize the IoHwAb pulseout module
* @param     none
* @return    void
*/
void IoHwAb_PulseOut_Init(void)
{

    /* Initialize the total pulse out duration*/
    IoHwAb_TotalPulseOutDuration					= 0u;

    /* Initialize the high and low pulse duration*/
    IoHwAb_PulseOutTimeDuration.HighPulseDuration   = 0u;
    IoHwAb_PulseOutTimeDuration.LowPulseDuration    = 0u;
    /* Set pulse out pin state during init*/
    IoHwAb_PulseOutTimeDuration.PulseOutPinStatus   = IOHWAB_PULSEOUT_DIO_INIT_VALUE;

    /* Make the pin to Init state*/
    Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);

    /* Enable the notification for the GPT timer*/
    IoHwAb_Gpt_EnableNotification(IOHWAB_PULSEOUT_GPT_TIMER);

    /* Start the  timer with minimum time*/
    IoHwAb_Gpt_StartTimer(IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IOHWAB_PULSEOUT_MIN_MICROSEC));

    IoHwAb_PulseOutAcceptNewTime = (boolean)TRUE;

}

/**
* This method IoHwAb_PulseOut_DeInit the IoHwAb pulseout module
* @param     none
* @return    void
*/
void IoHwAb_PulseOut_DeInit(void)
{

    /* Stop the timer , when the IGN is OFF */
    IoHwAb_Gpt_StopTimer(IOHWAB_PULSEOUT_GPT_TIMER);

    /* Set pulse out pin state during Deinit*/
    IoHwAb_PulseOutTimeDuration.PulseOutPinStatus = IOHWAB_PULSEOUT_DIO_DEINIT_VALUE;

    /* Make the pin to Deinit state*/
    Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);

    /* Deinitialize the total pulse out duration*/
    IoHwAb_TotalPulseOutDuration 					= 0u;
    /* Deinitialize the high and low pulse duration*/
    IoHwAb_PulseOutTimeDuration.HighPulseDuration 	= 0u;
    IoHwAb_PulseOutTimeDuration.LowPulseDuration 	= 0u;

}

/**
* This method is the main function for IoHwAb pulse output module
* In this function , we will periodically monitor the status of the pin,
** when vehicle is in STOP state.
* @param     none
* @return    void
*/
void IoHwAb_PulseOut_MainFunction(void)
{

    /* Enter critical section*/
    IOHWAB_PULSEOUT_ENTER_CRITICAL_SECTION();

    if(0u == IoHwAb_TotalPulseOutDuration)
    {

        /* Make the pin to expected state*/
        Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus );

    }

    /* Exit critical section*/
    IOHWAB_PULSEOUT_EXIT_CRITICAL_SECTION();
}

/**
* Below function is ISR call back ,  does below functionality:
* 1. Get the new time .
* 2. Check whether PIN need to be toggled or not
* This method is used
* @param     None
* @return    None
*/
void IoHwAb_PulseOut_Cbk_Notification(void)
{

    IoHwAb_PulseOutDataType ReadPulseOutDuration = 0U;

    /* Below Callback needs to be invoked through RTE port*/
    (void)IOHWAB_PULSEOUT_APPL_CALLBACK(&ReadPulseOutDuration);

    IoHwAb_TotalPulseOutDuration = ReadPulseOutDuration;

    /* Consider the vehicle speed is valid*/
    if(0u != IoHwAb_TotalPulseOutDuration)
    {

        if((boolean)FALSE != IoHwAb_PulseOutAcceptNewTime)
        {
            /* Divide the time passed on from SWC and store internally*/
            IoHwAb_PulseOutTimeDuration.HighPulseDuration = IoHwAb_TotalPulseOutDuration/2uL;

            IoHwAb_PulseOutTimeDuration.LowPulseDuration = IoHwAb_TotalPulseOutDuration/2uL;
            /* Set this flag to false , so that new time will not be loaded from SWC*/
            IoHwAb_PulseOutAcceptNewTime = (boolean)FALSE;
        }

        /* Macro to enable the new time updation during Low pulse*/
#ifdef IOHWAB_PULSEOUT_NEW_TIME_UPDATE_DURING_LOW_PULSE
        if(IoHwAb_PulseOutTimeDuration.PulseOutPinStatus != (Dio_LevelType)STD_HIGH)
        {

            /* set the pin to high*/
            IoHwAb_PulseOutTimeDuration.PulseOutPinStatus = (Dio_LevelType)STD_HIGH;

            /* Make the pulseout pin  to LOW*/
            Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);

            /* Condition to check , whether conveted TICS is less than or equal to MAX tics of the configured GPT timer*/
            if(IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.HighPulseDuration) <= IOHWAB_PULSEOUT_MAX_TICKS)
            {
                /* load the timer , when the vehicle is in RUN State*/
                IoHwAb_Gpt_StartTimer( IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.HighPulseDuration));
            }
            /* Set this flag to true , so that new time will be loaded from SWC*/
            IoHwAb_PulseOutAcceptNewTime = (boolean)TRUE;
        }
        else
        {

            /* set the value*/
            IoHwAb_PulseOutTimeDuration.PulseOutPinStatus = (Dio_LevelType)STD_LOW;

            /* Make the pulseout pin  to LOW*/
            Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);


            /* Condition to check , whether conveted TICS is less than or equal to MAX tics of the configured GPT timer */
            if(IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.LowPulseDuration) <= IOHWAB_PULSEOUT_MAX_TICKS)
            {
                /* load the timer , when the vehicle is in RUN State*/
                IoHwAb_Gpt_StartTimer( IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.LowPulseDuration));
            }

        }
#else
        if(IoHwAb_PulseOutTimeDuration.PulseOutPinStatus != (Dio_LevelType)STD_HIGH)
        {
            /* set the pin to high*/
            IoHwAb_PulseOutTimeDuration.PulseOutPinStatus = (Dio_LevelType)STD_HIGH;

            /* Make the pulseout pin  to LOW*/
            Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);

            /* Condition to check , whether conveted TICS is less than or equal to MAX tics of the configured GPT timer*/
            if(IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.HighPulseDuration) <= IOHWAB_PULSEOUT_MAX_TICKS)
            {
                /* load the timer , when the vehicle is in RUN State*/
                IoHwAb_Gpt_StartTimer( IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.HighPulseDuration));
            }
        }
        else
        {
            /* set the value*/
            IoHwAb_PulseOutTimeDuration.PulseOutPinStatus = (Dio_LevelType)STD_LOW;

            /* Make the pulseout pin  to LOW*/
            Dio_WriteChannel( IOHWAB_PULSEOUT_DIO_CHANNEL,  IoHwAb_PulseOutTimeDuration.PulseOutPinStatus);

            /* Condition to check , whether conveted TICS is less than or equal to MAX tics of the configured GPT timer*/
            if(IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.LowPulseDuration) <= IOHWAB_PULSEOUT_MAX_TICKS)
            {
                /* load the timer , when the vehicle is in RUN State*/
                IoHwAb_Gpt_StartTimer( IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IoHwAb_PulseOutTimeDuration.LowPulseDuration));
            }
            /* Set this flag , so that new time will be loaded from SWC*/
            IoHwAb_PulseOutAcceptNewTime = (boolean)TRUE;
        }
#endif
    }
    else
    {
        /* start the  timer with minimum time*/
        IoHwAb_Gpt_StartTimer(IOHWAB_PULSEOUT_GPT_TIMER, IOHWAB_PULSEOUT_MICROSEC_TO_TICKS(IOHWAB_PULSEOUT_MIN_MICROSEC));

    }
}

#define IoHwAb_STOP_SEC_CODE
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
Date              :19-Nov-2018
By                :pragesh
Traceability      :RTC# 1238746
Change Description:Initial Version for IoHwAb_PulseOut safe implementation
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
