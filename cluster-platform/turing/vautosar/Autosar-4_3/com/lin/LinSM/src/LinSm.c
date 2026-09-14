/*---------------------------------------------------------------------------------------------------------------------

 *VISTEON CORPORATION CONFIDENTIAL
*________________________________
* [2015] Visteon Corporation
* All Rights Reserved.
*NOTICE: This is an unpublished work of authorship, which contains trade secrets.
*Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
*its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
* under all copyright laws to protect this work as a published work, when appropriate.
*Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
*without the written authorization of Visteon Corporation.
---------------------------------------------------------------------------------------------------------------------*/
/*****************************************************************************
* File Name         :  LinSm.c                                               *
* Module Short Name :  LinSm                                                 *
* Description       :  Contains LinSm Funtional Implementations              *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing A                                               *
*                                                                            *
*****************************************************************************/

#include "Std_Types.h"
#include "Lin.h"
#include "LinIf.h"
#include "LinSm.h"
#include "LinTrcv.h"
#include "ComM_Types.h"
#include "Com_Types.h"
#include "ComM_BusSM.h"
#if defined(USE_COMM)
#include "ComM.h"
#endif
#include "Det.h"
#if defined(USE_LINSM_MEMMAP)
#include "LinSM_MemMap.h"
#endif
#if defined(USE_SCHM_LINSM)
#include "SchM_LinSM.h"
#endif
#include "Lin_GeneralTypes.h"
#if defined(USE_BSWM)
#include "BswM_LinSM.h"
#endif

/********************************************************************************************************************
*  VERSION CHECK                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((LINSM_SW_MAJOR_VERSION != LINSM_CFG_SW_MAJOR_VERSION) || \
    (LINSM_SW_MINOR_VERSION != LINSM_CFG_SW_MINOR_VERSION) || \
    (LINSM_SW_PATCH_VERSION != LINSM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((LINSM_AR_RELEASE_MAJOR_VERSION != LINSM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (LINSM_AR_RELEASE_MINOR_VERSION != LINSM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (LINSM_AR_RELEASE_REVISION_VERSION != LINSM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/* Development error macros. */

#if (LINSM_DEV_ERROR_DETECT == STD_ON)
#define LINSM_ERRORWRAPPER(_exp, _api, _err)             \
    if (!(_exp))                                         \
    {                                                    \
       (void)Det_ReportError(LINSM_MODULE_ID, 0, _api, _err);                                         \
    }                                                    

#define LINSM_ERRORWRAPPER_W_RV(_exp, _api, _err, _rv)   \
    if (!(_exp))                                         \
    {                                                    \
        (void)Det_ReportError(LINSM_MODULE_ID, 0, _api, _err); \
      return (_rv);                                    \
    }
#else
#define LINSM_ERRORWRAPPER(_exp, _api, _err)
#define LINSM_ERRORWRAPPER_W_RV(_exp, _api, _err, _rv)
#endif

#if defined(USE_BSWM)

#define BSWM_LINSM_CURRENTSCHEDULE(_ch) \
    BswM_LinSM_CurrentSchedule(_ch, LinSMSchTablCurr[_ch]);

#define BSWM_LINSM_CURRENTSTATE(_ch, _state) \
    BswM_LinSM_CurrentState(_ch, _state);

#else
#define BSWM_LINSM_CURRENTSCHEDULE(_ch)
#define BSWM_LINSM_CURRENTSTATE(_ch, _state)
#endif

#if defined(USE_COM)
#define LINSM_COM_BUSMODE_INDICATION(_ch, ComMode) \
    ComM_BusSM_ModeIndication(_ch, ComMode);
#else

#define LINSM_COM_BUSMODE_INDICATION(_ch, ComMode)

#endif

#define LINSM_RESET_VAR 0x00u

/*=====================================================================================================================
*  FORWARD DECLARATIONS
*=====================================================================================================================*/

/*  File static variable to hold the configurations   */
static const LinSM_ConfigType *LinSM_ConfigPtr;

/*  LIN If Global Status  */
static LinSM_StatusType LinSm_GlobalStatus = LINSM_UNINIT;

/*  LIN If Channel Data  */
static LinSM_ChannelDataType LinSM_ChannelData[LINSM_NUMBER_OF_CHANNELS];

/*  Gloabal Variable initial value to increment maximum count  */
static uint16 LinSMModeRequestRepetitionMax;


//=====================================================================================================================
//  								PRIVATE FUNCTION DECLArATIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinSM_DecrementTimerCount
/// @param : uint16 *timer - Pointer to the timer count variable
/// @Description : This function decrements the timer counter varibable
/// @return : void
///<br>
///<br>
//---------------------------------------------------------------------------------------------------------------------

static void LinSM_DecrementTimerCount(uint16 *timer);

//=====================================================================================================================
//  								PUBLIC FUNCTION DEFINITIONS
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_Init
/// @param LinSM_ConfigType *ConfigPtr - Pointer to the LinSM post-build configuration data.
/// @Description This function initializes the LinSM.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_Init(const LinSM_ConfigType *ConfigPtr)
{
    uint8 LinSm_Chnl_Count_fl;

	/**  Check whether the Configuration Pointer is valid */
    LINSM_ERRORWRAPPER( (ConfigPtr!=NULL), LINSM_INIT_SERVICE_ID, LINSM_E_INIT_FAILED );

        for (LinSm_Chnl_Count_fl = 0; LinSm_Chnl_Count_fl < LINSM_NUMBER_OF_CHANNELS; LinSm_Chnl_Count_fl++)
        {
            /* Flush all the channel related data before initialization  */
            (void)memset(&LinSM_ChannelData[LinSm_Chnl_Count_fl], LINSM_RESET_VAR, sizeof(LinSM_ChannelData));
            /** The sub-state LINSM_NO_COM shall be active when entering the LINSM_INIT state, 
		 * for all networks when LinSM_Init is called */
            LinSM_ChannelData[LinSm_Chnl_Count_fl].Channel_Status = LINSM_NO_COM;
            /** The LinSM_Init function shall set the schedule type NULL_SCHEDULE
		 *  for each configured channel */
            LinSM_ChannelData[LinSm_Chnl_Count_fl].CurrentScheduleRequest = 0;
        }
        /* Get the user configuration data. */
        LinSM_ConfigPtr = ConfigPtr;

        /* The LinSM state-machine shall transit from any state or sub-state 
	   to the state LINSM_INIT when LinSM_Init is called. */
        /* Set LINSM to INIT state  */
        LinSm_GlobalStatus = LIN_SM_INIT;
        LinSMModeRequestRepetitionMax =0x00u;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_DeInit
/// @param None.
/// @Description This function deinitializes the LinSM.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_DeInit(void)
{
    /* local variable to deinitialize all the LIN channels  */
    uint8 LinSm_ChId_fl;

    for (LinSm_ChId_fl = 0; LinSm_ChId_fl < LINIF_NUMBER_OF_CHANNELS; LinSm_ChId_fl++)
    {
        /* Reset All the channel global variables  */
        (void)memset(&LinSM_ChannelData[LinSm_ChId_fl], LINSM_RESET_VAR, sizeof(LinSM_ChannelDataType));
    } 

    /* Change the LIN SM  global status to  UNINIT*/
    LinSm_GlobalStatus = LINSM_UNINIT;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_ScheduleRequest
/// @param NetworkHandleType network - Identification of the LIN channel.
///        LinIf_SchHandleType LinSM_schedule - Pointer to the new Schedule table
/// @Description The upper layer requests a schedule table to be changed on one LIN network.
/// @return Std_ReturnType - E_OK - Schedule table request has been accepted.
///         E_NOT_OK - Schedule table switch request has not been accepted due to one of the following reasons:
///         LinSM has not been initialized referenced channel does not exist (identification is out of range)
///         Referenced schedule table does not exist (identification is out of range)
///         Sub-state is not LINSM_FULL_COM
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinSM_ScheduleRequest(NetworkHandleType network, LinIf_SchHandleType schedule)
{
    Std_ReturnType fl_LinSm_Schedule_result = E_NOT_OK;
    Std_ReturnType fl_LinSm_Status_U8 = E_NOT_OK;
    network = 0; // Need to remove this declaration
    /** If the state LINSM_UNINIT is active then the error-code 
     * LINSM_E_UNINIT shall be reported to the DET module and E_NOT_OK shall be returned. */
    LINSM_ERRORWRAPPER_W_RV((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_SCHEDULE_REQUEST_SERVICE_ID, LINSM_E_UNINIT, E_NOT_OK);
    /** If the network parameter has an invalid value then the error-code LINSM_E_NONEXISTENT_NETWORK 
     *  shall be reported to the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((network < LINSM_NUMBER_OF_CHANNELS), LINSM_SCHEDULE_REQUEST_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK, E_NOT_OK);
    /** If LinSMDevErrorDetect is enabled: If the schedule parameter has an invalid value, then the error-code 
     *  LINSM_E_PARAMETER shall be reported to the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((schedule < LINSM_SCH_CNT), LINSM_SCHEDULE_REQUEST_SERVICE_ID, LINSM_E_PARAMETER, E_NOT_OK);

    /** If the function LinSM_ScheduleRequest is called and another request is in process on the same network, 
     *  the LinSM_ScheduleRequest shall return directly with E_NOT_OK*/
    /** If the function LinSM_ScheduleRequest is called and the state is not LINSM_FULL_COM, 
     * the LinSM_ScheduleRequest shall return directly with E_NOT_OK. */

    if ((LINSM_MAIN_PROCESSING_PERIOD < LinSM_ChannelData[network].ScheduleRequestTimerCount) ||
        (LINSM_FULL_COM != LinSM_ChannelData[network].Channel_Status))
    {
        fl_LinSm_Status_U8 = E_NOT_OK;
    }
    else
    {
        /* Set the schedule Request confirmation timer for the specified network. */
        /** Before the LinSM calls the LinIf_GotoSleep, LinIf_Wakeup or LinIf_ScheduleRequest is called, 
         * the LinSM module shall start a timer. */
        /* Get the Timer count */
        LinSM_ChannelData[network].ScheduleRequestTimerCount = LinSM_ConfigPtr->LinSMChannels[network].LinSMConfirmationTimeout;
        /* Get the schedule Table index  */
        LinSM_ChannelData[network].NewScheduleRequest = schedule;
        /* Schedule the entry  */
        fl_LinSm_Schedule_result = LinIf_ScheduleRequest(network, schedule);

        if (fl_LinSm_Schedule_result != (uint8)E_OK)
        {

            /** Retain the old schedule table **/
            LinSM_ChannelData[network].NewScheduleRequest = LinSM_ChannelData[network].CurrentScheduleRequest;
            /** Reset the timer count  */
            LinSM_ChannelData[network].ScheduleRequestTimerCount = 0;
        }
        else
        {
            /** Get the status   */
            fl_LinSm_Status_U8 = fl_LinSm_Schedule_result;
        }
    }
    return fl_LinSm_Status_U8;
}


# if ( LINSM_VERSION_INFO_API == STD_ON )
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GetVersionInfo
/// @param Std_VersionInfoType versioninfo - Identification of the version information
///        
/// @.
/// @return Std_ReturnType - None
///<br>
//---------------------------------------------------------------------------------------------------------------------

void LinSM_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

/*Check whether development error detection parameter is enabled or not*/
#if ( LINSM_DEV_ERROR_DETECT == STD_ON )

  /*This local variable is used for store error ID
    and Initialize local variable"errorId" as no error occured */
   uint8                     errorId= LINSM_E_NO_ERROR;
/* checking versioninfo parameter value is equal to null pointer */
  if ( versioninfo == NULL_PTR )
  {
      /*if version info is equal to null pointer, assign errorid as LINSM_E_PARAMETER_POINTER */
      errorId = LINSM_E_PARAMETER_POINTER;
  }
  else
# endif  
  {
    /* version information for linSM vendor id*/  
    versioninfo->vendorID         = (uint16)LINSM_VENDOR_ID;
    /* version information for linSM module id*/
    versioninfo->moduleID         = (uint16)LINSM_MODULE_ID;
    /* version information for linSM major version*/
    versioninfo->sw_major_version = (uint8) LINSM_SW_MAJOR_VERSION;
    /* version information for linSM minor version*/
    versioninfo->sw_minor_version = (uint8) LINSM_SW_MINOR_VERSION;
    /* version information for linSM patch version*/
    versioninfo->sw_patch_version = (uint8) LINSM_SW_PATCH_VERSION;
  }
/*Check whether development error detection parameter is enabled or not*/
#if (LINSM_DEV_ERROR_DETECT == STD_ON)
/*Check whether if error is occured or not*/
  if (LINSM_E_NO_ERROR != errorId)
  {
     /*If error is occurred, report to DET module with errorID, function ID,module ID and Instance ID.*/ 
    (void)Det_ReportError( LINSM_MODULE_ID, LINSM_INSTANCE_ID_DET, LINSM_SID_GET_VERSION_INFO, errorId ); 
  }
  else
  {
      /*Do Nothing*/
  }
#endif
}
#endif /* LINSM_VERSION_INFO_API == STD_ON */

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GetCurrentComMode
/// @param NetworkHandleType network - Identification of the LIN channel.
///        ComM_ModeType* mode - Returns the active mode, see ComM_ModeType for descriptions of the modes
/// @Description Function to query the current communication mode.
/// @return Std_ReturnType - E_OK - Ok E_NOT_OK - Not possible to perform the request.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinSM_GetCurrentComMode(NetworkHandleType network, ComM_ModeType *mode)
{
	 network = 0; // Need to remove this declaration
    if (LINSM_NUMBER_OF_CHANNELS > network)
    {
        /** If active state is LINSM_UNINIT the state COMM_NO_COMMUNICATION shall be returned. 
         * This is also captured above when the DET is enabled. This is to be defensive. */
        if ((LinSm_GlobalStatus == LINSM_UNINIT) && (mode != NULL_PTR))
        {
            *mode = COMM_NO_COMMUNICATION;
        }
        else
        {
            /* Do Nothing */
        }
    }
         else
        {
            /* Do Nothing */
        } 
    /**If the state LINSM_UNINIT is active, then the error-code LINSM_E_UNINIT shall be reported to the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_GET_CURRENT_COM_MODE_SERVICE_ID, LINSM_E_UNINIT, E_NOT_OK);
    /** If the network parameter has an invalid value, then the error-code LINSM_E_NONEXISTENT_NETWORK shall be reported to the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((network < LINSM_NUMBER_OF_CHANNELS), LINSM_GET_CURRENT_COM_MODE_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK, E_NOT_OK);
    /** If the mode pointer parameter is invalid (e.g. NULL), then the error-code LINSM_E_PARAM_POINTER shall be reported to the DET module and E_NOT_OK shall be returned. */
    LINSM_ERRORWRAPPER_W_RV((mode != NULL_PTR), LINSM_GET_CURRENT_COM_MODE_SERVICE_ID, LINSM_E_PARAMETER_POINTER, E_NOT_OK);

    switch (LinSM_ChannelData[network].Channel_Status)
    {
    case LINSM_FULL_COM:
        /** If active state is LINSM_FULL_COM the state COMM_FULL_COMMUNICATION 
         * shall be returned. */
        *mode = COMM_FULL_COMMUNICATION;
        break;
    default:
        /** If active state is LINSM_NO_COM the state COMM_NO_COMMUNICATION 
         * shall be returned. */
        *mode = COMM_NO_COMMUNICATION;
        break;
    }
    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_RequestComMode
/// @param NetworkHandleType network - Identification of the LIN channel.
///        ComM_ModeType mode - Request mode
/// @Description Requesting of a communication mode. The mode switch will not be made instant.
///              The LinSM will notify the caller when mode transition is made..
/// @return Std_ReturnType - E_OK - Ok E_NOT_OK - Not possible to perform the request.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinSM_RequestComMode(NetworkHandleType network, ComM_ModeType mode)
{
    Std_ReturnType fl_LinSm_RequestComMode_Result = E_NOT_OK;
    boolean fl_LinSM_RequestComMode_CheckValid_Entry_bool = FALSE;
    Std_ReturnType fl_LinSm_Transceiver_NormalMode_Result;

#if defined(USE_COM)
    ComM_ModeType fl_LinSm_ComMode;
#endif
    network = 0; // Need to remove this declaration
    /** If the state LINSM_UNINIT is active, then the error-code LINSM_E_UNINIT shall be reported to 
     *  the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_REQUEST_COM_MODE_SERVICE_ID, LINSM_E_UNINIT, E_NOT_OK);
    /** If the network parameter has an invalid value, then the error-code LINSM_E_NONEXISTENT_NETWORK shall be 
     *  reported to the DET module and E_NOT_OK shall be returned */
    LINSM_ERRORWRAPPER_W_RV((network < LINSM_NUMBER_OF_CHANNELS), LINSM_REQUEST_COM_MODE_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK, E_NOT_OK);
    /** If the mode parameter has an invalid value, then the error-code LINSM_E_PARAMETER shall be reported to the DET module 
     *  and E_NOT_OK shall be returned. */
    LINSM_ERRORWRAPPER_W_RV(((mode == COMM_NO_COMMUNICATION) || (mode == COMM_SILENT_COMMUNICATION) || (mode == COMM_FULL_COMMUNICATION)), LINSM_REQUEST_COM_MODE_SERVICE_ID, LINSM_E_PARAMETER_POINTER, E_NOT_OK);

    /* Check whether the requested mode and the current mode are same */
    fl_LinSM_RequestComMode_CheckValid_Entry_bool = ((COMM_NO_COMMUNICATION == mode) && (LINSM_NO_COM == LinSM_ChannelData[network].Channel_Status)) || ((COMM_FULL_COMMUNICATION == mode) && (LINSM_FULL_COM == LinSM_ChannelData[network].Channel_Status));

    /* Set the mode only if the requested mode and curent mode are different */
    if ((TRUE != fl_LinSM_RequestComMode_CheckValid_Entry_bool) && (LINSM_MAIN_PROCESSING_PERIOD >= LinSM_ChannelData[network].WakeUpTimerCount))
    {

        switch (mode)
        {
        case COMM_NO_COMMUNICATION:
            /* Set the GotoSleep confirmation timer for the specified channel. */
            LinSM_ChannelData[network].GoToSleepTimerCount = LinSM_ConfigPtr->LinSMChannels[network].LinSMConfirmationTimeout;
            if ((uint8)E_OK == LinIf_GotoSleep(network))
            {
                /** LinSM_RequestComMode shall store the requested mode, if the return value is E_OK */
                LinSM_ChannelData[network].Channel_Status = LINSM_NO_COM;
                fl_LinSm_RequestComMode_Result = E_OK;
            }
            else
            {
                /** E_NOT_OK is retuned by upper layer the LinIf_GotoSleep shall also return E_NOT_OK. */
                /** Reset the gotosleep timer counter */
                BSWM_LINSM_CURRENTSTATE(network, LINSM_FULL_COM);
#if defined(USE_COM)
                fl_LinSm_ComMode = COMM_FULL_COMMUNICATION;
                LINSM_COM_BUSMODE_INDICATION(3U, &fl_LinSm_ComMode); /* TODO: call with comM channel */
#endif
                LinSM_ChannelData[network].GoToSleepTimerCount = 0;
            }
            break;
        case COMM_SILENT_COMMUNICATION:
            /* COMM_SILENT_COMMUNICATION is requested the 
               function shall return E_NOT_OK directly without action */
            break;
        case COMM_FULL_COMMUNICATION:
            /* Set the transceiver to normal mode  */
            fl_LinSm_Transceiver_NormalMode_Result = LinIf_SetTrcvMode(network, LINTRCV_TRCVMODE_NORMAL);

            if ((uint8)E_OK == fl_LinSm_Transceiver_NormalMode_Result)
            {
                /* Set the Wakeup confirmation timer for the specified channel. */
                LinSM_ChannelData[network].WakeUpTimerCount = (uint16)LinSM_ConfigPtr->LinSMChannels[network].LinSMConfirmationTimeout;
                if ((uint8)E_OK == LinIf_WakeUp(network))
                {
                    fl_LinSm_RequestComMode_Result = E_OK;
                    LinSMModeRequestRepetitionMax++;
                }
                else
                {
                    BSWM_LINSM_CURRENTSTATE(network, LINSM_FULL_COM);
#if defined(USE_COM)
                    fl_LinSm_ComMode = COMM_FULL_COMMUNICATION;
                    LINSM_COM_BUSMODE_INDICATION(3U, &fl_LinSm_ComMode);  /* TODO - call with comM channel */
#endif
                    /** Reset the wake-up timer  */
                    LinSM_ChannelData[network].WakeUpTimerCount = 0;
                }
            }
            else
            {
                /* do noting */
            }

            break;
        default:
            /* Error Handling conditons */
            break;
        }
    }
    else
    {
        /* Do nothing */
    }
    return fl_LinSm_RequestComMode_Result;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_MainFunction
/// @param None
/// @Description Periodic function that runs the timers of different request timeouts.
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_MainFunction(void)
{
    uint8 fl_LinSm_Channel_Id_U8;
#if defined(USE_COM)
    ComM_ModeType fl_LinSM_Main_ComMode;
#endif  
    /** Check Whether  LINSM is initialized  */
    LINSM_ERRORWRAPPER((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_MAIN_FUNCTION_SERVICE_ID, LINSM_E_UNINIT);
    /** The LinSM_MainFunction shall handle the timers that are attached to the functions LinIf_GotoSleep, 
     * LinIf_Wakeup or LinIf_ScheduleRequest */
    for (fl_LinSm_Channel_Id_U8 = 0;
         fl_LinSm_Channel_Id_U8 < LINSM_NUMBER_OF_CHANNELS;
         fl_LinSm_Channel_Id_U8++)
    {

        /* Check Whether Schedule Request timer count has started */
        if (LINSM_MAIN_PROCESSING_PERIOD <= LinSM_ChannelData[fl_LinSm_Channel_Id_U8].ScheduleRequestTimerCount)
        {
            /** The handling (countdown and expiration) of the all request timers 
              * used by the LinSM module shall be made done in the LinSM_MainFunction */
            LinSM_DecrementTimerCount(&LinSM_ChannelData[fl_LinSm_Channel_Id_U8].ScheduleRequestTimerCount);
            if (LinSM_ChannelData[fl_LinSm_Channel_Id_U8].ScheduleRequestTimerCount < LINSM_MAIN_PROCESSING_PERIOD)
            {
                /** If timer has elapsed, the LinSM module shall call BswM_LinSM_CurrentSchedule 
                 * with unchanged schedule table. */
                /** Be aware of that the LinIf will switch to a 
                 * NULL schedule when entering sleep, 
                 * then it may make a schedule switch callback. */
                BSWM_LINSM_CURRENTSCHEDULE(fl_LinSm_Channel_Id_U8);
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
        /* Check Whether GotoSleep timer count has started */
        if (LINSM_MAIN_PROCESSING_PERIOD <= LinSM_ChannelData[fl_LinSm_Channel_Id_U8].GoToSleepTimerCount)
        {
            /** The handling (countdown and expiration) of the all request timers 
              * used by the LinSM module shall be made done in the LinSM_MainFunction */
            LinSM_DecrementTimerCount(&LinSM_ChannelData[fl_LinSm_Channel_Id_U8].GoToSleepTimerCount);
            if (LinSM_ChannelData[fl_LinSm_Channel_Id_U8].GoToSleepTimerCount < LINSM_MAIN_PROCESSING_PERIOD)
            {

                /** If request timer elapses (i.e. module LinIf is not notifying within the timeout) and 
                 * the maximum number of retries have been reached,in the case of a LinIf_Wakeup request, 
                 * the LinSM module shall notify ComM module with same state. */
#if defined(USE_COM)
                fl_LinSM_Main_ComMode = COMM_FULL_COMMUNICATION;
                LINSM_COM_BUSMODE_INDICATION(fl_LinSm_Channel_Id_U8, &fl_LinSM_Main_ComMode);
#endif
                BSWM_LINSM_CURRENTSTATE(fl_LinSm_Channel_Id_U8, LINSM_FULL_COM);
            }
            else
            {
                /* Do Nothing */
            }
        }
            else
            {
                /* Do Nothing */
            }
        /* Check Whether WakeUp timer count has started */
        if (LINSM_MAIN_PROCESSING_PERIOD < LinSM_ChannelData[fl_LinSm_Channel_Id_U8].WakeUpTimerCount)
        {
            /** The handling (countdown and expiration) of the all request timers 
              * used by the LinSM module shall be made done in the LinSM_MainFunction */
            LinSM_DecrementTimerCount(&LinSM_ChannelData[fl_LinSm_Channel_Id_U8].WakeUpTimerCount);
            /* checking whether request timer is expired*/
            if(LinSM_ChannelData[fl_LinSm_Channel_Id_U8].WakeUpTimerCount < LINSM_MAIN_PROCESSING_PERIOD)
            {   /* Checking the maximum request repetition count, if wakeup request maximum count even 
            after timer expires untill the maximum count reached the call back wake up request will be sent*/
                if(WAKEUP_ATTEMPT != LinSMModeRequestRepetitionMax)
            {
                /*calling LinSM_RequestComMode function for wakeup request to Linif layer*/
                (void)LinSM_RequestComMode(fl_LinSm_Channel_Id_U8, COMM_FULL_COMMUNICATION);
            }
            else
            {
                 /** If request timer elapses (i.e. module LinIf is not notifying within the timeout) and 
                 * the maximum number of retries have been reached,in the case of a LinIf_Wakeup request, 
                 * the LinSM module shall notify ComM module with same state. */
#if defined(USE_COM)
                fl_LinSM_Main_ComMode = COMM_NO_COMMUNICATION;
               LINSM_COM_BUSMODE_INDICATION(fl_LinSm_Channel_Id_U8, &fl_LinSM_Main_ComMode);
#endif
                BSWM_LINSM_CURRENTSTATE(fl_LinSm_Channel_Id_U8, LINSM_NO_COM);

            }
               
            }
            else
            {
                /* Do Nothing */
            }
        }
             else
            {
                /* Do Nothing */
            }
    }
}
//=====================================================================================================================
//  								CALLBACK FUNCTION DEFINITIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_ScheduleRequestConfirmation
/// @param NetworkHandleType network - Identification of the LIN channel.
///        LinIf_SchHandleType schedule_changed - Handle value to the new active Schedule table
/// @Description The LinIf module will call this callback when the new requested schedule table is active.
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_ScheduleRequestConfirmation(NetworkHandleType network, LinIf_SchHandleType schedule)
{
	network = 0; // Need to remove this declaration
    /** If the state LINSM_UNINIT is active, then the error-code LINSM_E_UNINIT shall be reported to DET module */
    /** Check for LINSM global state */
    LINSM_ERRORWRAPPER((LINSM_UNINIT != LinSm_GlobalStatus), LINSM_SCHEDULE_REQUEST_CONF_SERVICE_ID, LINSM_E_UNINIT);
    /** If the network parameter has an invalid value, then the error-code LINSM_E_NONEXISTENT_NETWORK shall be reported to the DET module */
    /** Check for valid Channel  */
    LINSM_ERRORWRAPPER((LINSM_NUMBER_OF_CHANNELS > network), LINSM_SCHEDULE_REQUEST_CONF_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK);

    /* Check Timer elapsed */

    if (LINSM_MAIN_PROCESSING_PERIOD < LinSM_ChannelData[network].ScheduleRequestTimerCount)
    {

        /* When the LinSM module gets the confirmation of setting a schedule table from the 
       LinIf module the BswM_LinSM_CurrentSchedule shall be called, if not timer has elapsed */
        LinSM_ChannelData[network].CurrentScheduleRequest = schedule;
    }
    else
    { 
        /* Do Nothing */
    }
        /** If the LinIf module calls the confirmation callback before the timeout occurs, 
     * the active timer shall stop, so that the timeout will not occur */
    /* Reset the timer */
    LinSM_ChannelData[network].ScheduleRequestTimerCount = 0;   
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_WakeUpConfirmation
/// @param NetworkHandleType network - Identification of the LIN channel.
///        success schedule_changed - True if wakeup was successfully sent, false otherwise
/// @Description The LinIf will call this callback when the wake up signal command is
///              sent not successfully/successfully on the network..
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_WakeUpConfirmation(NetworkHandleType network, boolean success)
{
    
#if defined(USE_COM)
    ComM_ModeType fl_LinSM_WakeUp_ComMode;
#endif
    network = 0; // Need to remove this declaration
    /** If the state LINSM_UNINIT is active, then the error-code LINSM_E_UNINIT shall be reported to the DET module. */
    LINSM_ERRORWRAPPER((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_WAKEUP_CONF_SERVICE_ID, LINSM_E_UNINIT);
    /** If the network parameter has an invalid value, then the error-code LINSM_E_NONEXISTENT_NETWORK shall be reported to the DET module */
    LINSM_ERRORWRAPPER((network < LINSM_NUMBER_OF_CHANNELS), LINSM_WAKEUP_CONF_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK);

    /** If LinIf module calls the confirmation callback after the timer has elapsed, no further notification shall be 
     *  made to the ComM modules, i.e. the confirmation is ignored*/
    /* Check for Timer Elpased */
    if (LINSM_MAIN_PROCESSING_PERIOD < LinSM_ChannelData[network].WakeUpTimerCount)
    {
        /* Check whether the schedule change is successfull */
        if (FALSE != success)
        {
            /* When the LinIf notifies that the WakeUp is successfully sent (success = true), 
               the state shall be set to LINSM_FULL_COM */
#if defined(USE_COM)
            fl_LinSM_WakeUp_ComMode = COMM_FULL_COMMUNICATION;
            LINSM_COM_BUSMODE_INDICATION(network, &fl_LinSM_WakeUp_ComMode);
#endif
            /** When entering LINSM_FULL_COM the BswM shall be notified of the state 
             * change by calling the BswM_LinSM_CurrentState with the parameter 
             * LINSM_FULL_COM for the specified network */
            BSWM_LINSM_CURRENTSTATE(network, LINSM_FULL_COM);
            /* Change the state to LINSM_FULL_COM */
            LinSM_ChannelData[network].Channel_Status = LINSM_FULL_COM;
        }
        else
        {
            /** In all other cases from  the state shall be set 
             * same state as previous to the request (so that a mode indication callback 
             * is made to BswM and ComM)*/
            /* do nothing */
        }
    }
    else
    { 
        /* Do Nothing */
    }
         /** If the LinIf module calls the confirmation callback before the timeout occurs, 
     *  the active timer shall stop, 
     *  so that the timeout will not occur.*/

    /* Reset the Wake Up timer */
    LinSM_ChannelData[network].WakeUpTimerCount = 0;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinSM_GotoSleepConfirmation
/// @param network - Identification of the LIN channel
///        success - True if goto sleep was successfully sent, false otherwise
/// @Description The LinIf will call this callback when the go to sleep
///              command is sent successfully or not sent successfully
///              on the network..
/// @return void.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinSM_GotoSleepConfirmation(NetworkHandleType network, boolean success)
{
#if defined(USE_COM)
    ComM_ModeType fl_LinSM_GotoSleep_ComMode;
#endif
    network = 0; // Need to remove this declaration
    /** If the state LINSM_UNINIT is active, then the error-code LINSM_E_UNINIT shall be reported to the DET module */
    /* Check for valid LINSM Global state */
    LINSM_ERRORWRAPPER((LinSm_GlobalStatus != LINSM_UNINIT), LINSM_GOTO_SLEEP_CONF_SERVICE_ID, LINSM_E_UNINIT);
    /** If LinSMDevErrorDetect is enabled: If the network parameter has an invalid value, then the error-code 
     * LINSM_E_NONEXISTENT_NETWORK shall be reported to the DET module. */
    /* Check for valid LINSM Global state */
    LINSM_ERRORWRAPPER((network < LINSM_NUMBER_OF_CHANNELS), LINSM_GOTO_SLEEP_CONF_SERVICE_ID, LINSM_E_NONEXISTENT_NETWORK);

    /** If LinIf module calls the confirmation callback after the timer has elapsed, no further notification shall be made to the ComM modules, i.e. 
     * the confirmation is ignored. */
    /* Check whether the gotoSleepTimer is expired */
    if (LINSM_MAIN_PROCESSING_PERIOD < LinSM_ChannelData[network].GoToSleepTimerCount)
    {
        /* Check whether goto sleep process is successful */
        /* if (FALSE != success) */
        {
            LinSM_ChannelData[network].Channel_Status = LINSM_NO_COM;
            /* Set the transceiver mode to sleep */
            (void)LinIf_SetTrcvMode(network, LINTRCV_TRCVMODE_SLEEP);

            /** When entering LINSM_NO_COM the LinSM module shall notify 
             *  BswM of the state change by calling the BswM_LinSM_CurrentState 
             * with the parameter LINSM_NO_COM for the specific network */
#if defined(USE_COM)
            fl_LinSM_GotoSleep_ComMode = COMM_NO_COMMUNICATION;
            LINSM_COM_BUSMODE_INDICATION(2U, &fl_LinSM_GotoSleep_ComMode);  /* TODO - call with comM channel */
#endif
            /** When entering LINSM_NO_COM the LinSM module shall notify 
             *  BswM of the state change by calling the BswM_LinSM_CurrentState 
             * with the parameter LINSM_NO_COM for the specific network. */
            BSWM_LINSM_CURRENTSTATE(network, LINSM_NO_COM);
        }
#if 0
        else
        {
            /** If the LinIf_GotoSleep returns E_NOT_OK the LinSM_RequestComMode 
             * shall return E_NOT_OK.If the LinSM module returns 
             * LinSM_RequestComMode with E_NOT_OK, the same state shall be set 
             * (so that a ComM_BusSM_ModeIndication and BswM_LinSM_CurrentState
             * are called). */
            BSWM_LINSM_CURRENTSTATE(network, LINSM_FULL_COM);
#if defined(USE_COM)
            fl_LinSM_GotoSleep_ComMode = COMM_FULL_COMMUNICATION;
            LINSM_COM_BUSMODE_INDICATION(2U, &fl_LinSM_GotoSleep_ComMode);  /* TODO - call with comM channel */
#endif
        }
#endif
    }
    else
    {
        /* Do Nothing */
    }
    /** If the LinIf module calls the confirmation callback before 
     * the timeout occurs, the active timer shall stop, so that 
     * the timeout will not occur. */
    /** Reset the GotoSleepTimer */
    LinSM_ChannelData[network].GoToSleepTimerCount = 0;      
}


//=====================================================================================================================
//  								PRIVATE FUNCTION DEFINITIONS
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinSM_DecrementTimerCount
/// @param : uint16 *timer - Pointer to the timer count variable
/// @Description : This function decrements the timer counter varibable
/// @return : void
///<br>
///<br>
//---------------------------------------------------------------------------------------------------------------------

static void LinSM_DecrementTimerCount(uint16 *timer)
{
    uint16 fl_LinSM_TimerCount_U16;

    if (NULL != timer)
    {
        /* Get the timer count */
        fl_LinSM_TimerCount_U16 = (uint16)*timer;

        /** Check For Timeout occured */
        if (LINSM_MAIN_PROCESSING_PERIOD <= fl_LinSM_TimerCount_U16)
        {
            /** All request timers shall have a time that is a divisible by 
             *  the LinSM_MainFunction */
            fl_LinSM_TimerCount_U16 = fl_LinSM_TimerCount_U16 - LINSM_MAIN_PROCESSING_PERIOD;
        }
        else
        {
            /** When a timer expires, i.e. greater than the 
             *  configuration parameter LinSMConfirmationTimeout, 
             * a timeout occurs.*/
            (void)Det_ReportError(LINSM_MODULE_ID, 0, LINSM_MAIN_FUNCTION_SERVICE_ID, LINSM_E_CONFIRMATION_TIMEOUT);
        }

        /* Update the timer count to the back to actual variable  */
        *timer = fl_LinSM_TimerCount_U16;
    }
    else
    {
        /* Do Nothing */
    }
}

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================ */

/*============================================================================
**Date               : 15-APR-2020
**CDSID              : BPANDURA
**Traceability       : RTC #724726 #835035 #835036 #835037 #724728
**Change Description : Removed LinNM LinNm_NetworkRequest and LinNm_NetworkRelease function.
                       Added callback function LinIf_GotoSleep, LinIf_WakeUp to notify LinIf layer
                       for sleep and wake up request.
                       Added LinSM_GetVersionInfo function.
                       Changed LinSM_ScheduleRequest(NetworkHandleType network, LinIf_SchHandleType Schedule)
                       parameters from channel to network and LinSM_schedule to Schedule.
                       Changed LinSM_WakeUpConfirmation(NetworkHandleType network, boolean success)
                       parameter from channel to network.
                       Changed LinSM_GotoSleep_Confirmation(NetworkHandleType network,boolean success)
                       parameters from channel to network.
                       Added LinSMModeRequestRepetitionMax feature for [SWS_LinSM_00304] ⌈If request timout 
                       has occurred for LinIf_Wakeup and the maximum retries (LinSMModeRequestRepetitionMax)
                       have not been reached, the LinIf_Wakeup request will be sent again.
                       Added else statement for LinSM_DecrementTimerCount, LinSM_GotoSleepConfirmation, 
                       LinSM_WakeUpConfirmation, LinSM_ScheduleRequestConfirmation, LinSM_MainFunction,
                       LinSM_RequestComMode, LinSM_GetCurrentComMode, LinSM_ScheduleRequest.
                       
**============================================================================*/
/*============================================================================
**Date               : 15-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : .
**============================================================================*/
/*============================================================================
**Date               : 05-Mar-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : Initial Version.
**============================================================================*/
