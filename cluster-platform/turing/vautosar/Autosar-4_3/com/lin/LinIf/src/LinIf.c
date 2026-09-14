//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
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
/*****************************************************************************
* File Name         :  LinIf.c                                               *
* Module Short Name :  LinIf                                                 *
* Description       :  Contains LinIf Funtional Implementations              *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing C                                               *
*                                                                            *
*****************************************************************************/

#include "LinIf.h"
#include "Lin.h"
#include "LinIf_Cbk.h"
#include "LinSm.h"
#include "LinSm_Cbk.h"
#include "LinTrcv.h"
#include "PduR_LinIf.h"
#include "LinTp.h"
#include "Lin_Tp_Cfg.h"
#include "LinTp_Types.h"
#include "LinTp_Par_Cfg.h"
#include "ComStack_Types.h"
#include "LinIf_Par_Cfg.h"
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/********************************************************************************************************************
*  VERSION CHECK                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((LINIF_SW_MAJOR_VERSION != LINIF_CFG_SW_MAJOR_VERSION) || \
    (LINIF_SW_MINOR_VERSION != LINIF_CFG_SW_MINOR_VERSION) || \
    (LINIF_SW_PATCH_VERSION != LINIF_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((LINIF_AR_RELEASE_MAJOR_VERSION != LINIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (LINIF_AR_RELEASE_MINOR_VERSION != LINIF_CFG_AR_RELEASE_MINOR_VERSION) || \
    (LINIF_AR_RELEASE_REVISION_VERSION != LINIF_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
/* Development error macros. */
#if (LINIF_DEV_ERROR_DETECT == STD_ON)
#define LINIF_ERRORWRAPPER(_exp, _api, _err)             \
    if (!(_exp))                                         \
    {                                                    \
        Det_ReportError(LINIF_MODULE_ID, 0, _api, _err); \
        return;                                          \
    }

#define LINIF_ERRORWRAPPER_W_RV(_exp, _api, _err, _rv)   \
    if (!(_exp))                                         \
    {                                                    \
        Det_ReportError(LINIF_MODULE_ID, 0, _api, _err); \
        return (_rv);                                    \
    }

#define DET_REPORT_ERROR(_api, _err) Det_ReportError(LINIF_MODULE_ID, 0, _api, _err);

#else
#define LINIF_ERRORWRAPPER(_exp, _api, _err)
#define LINIF_ERRORWRAPPER_W_RV(_exp, _api, _err, _rv)
#define DET_REPORT_ERROR(_api, _err)
#endif
//=====================================================================================================================
//  FORWARD DECLARATIONS
//=====================================================================================================================

/*  File static variable to hold the configurations   */
static  const LinIf_ConfigType *LinIf_ConfigPtr;

/*  LIN If Global Status  */
static LinIf_StatusType LinIf_GlobalStatus = LINIF_UNINIT;

/*  LIN If Channel data  */
static LinIf_ChannelDataType LinIf_ChannelData[LINIF_NUMBER_OF_CHANNELS];

/*Schedule table handler return data type*/
typedef uint8      LinIf_ScheduleTableHandlerRetType; 

/**This variable store the  Sporadic frame transmit status*/
static uint8 LinIf_Sporadic_Frame_Transmit_Status;

/** Lin scheduler enable/disable status */
static boolean LinIf_SchedularEnableStatus[LINIF_NUMBER_OF_CHANNELS];

#if(LINIF_SPORADIC_FRAME_SUPPORT == STD_ON) 
/*This variable store the Sporadic frame execution count */
static uint8 SporadicFrame_Flag[LINIF_NUMBER_OF_SPORADIC_FRAME];
#endif

/*This array variable store the Sporadic frame transmit flag */

/*Below Two variable only used for avoid compiler warning*/
LinIf_FrameType *LinIF_AvoidCompilerWarning_1;

LinIf_ChannelDataType LinIf_AvoidCompilerWarning;

static uint8 RespData[8] = {0,0,0,0,0,0,0,0}; 

/**
  * @brief  This macro defines reset value.
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LINIF_RESET_VAR     0

/**
  * @brief  This macro defines Sleep request clear flag.
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LINIF_SLEEP_REQUEST_FLAG_CLEAR (boolean)0x00

/**
  * @brief  This macro defines New wakeup request clear flag.
  * unit : N/A
  * Resolution: N/A
  * Range: 1
  * Applicablity: N/A
  */
#define LINIF_NEW_WAKEUP_REQUESTED (boolean)0x01

/**
  * @brief  This macro defines  wakeup request clear flag.
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LINIF_CLEAR_NEW_WAKEUP_REQUESTED (boolean)0x00

/**
  * @brief  This macro defines  Sleep command implemented  flag.
  * unit : N/A
  * Resolution: N/A
  * Range: 1
  * Applicablity: N/A
  */
#define LINIF_SLEEP_CMD_IMPLEMENTED (boolean)0x01

/**
  * @brief  This macro defines clear Sleep command implemented  flag.
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LINIF_CLEAR_SLEEP_CMD_IMPLEMENTED (boolean)0x00



/**
  * @brief  This macro defines Null schedule value.
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LinIf_Schedule_NULL                         (NULL_SCHEDULE)

/**
  * @brief  This macro defines Invalid schedule value.
  * unit : N/A
  * Resolution: N/A
  * Range: 1
  * Applicablity: N/A
  */
#define LinIf_Schedule_Invalid                      ((LinIf_SchHandleType)0xFFu)

/**
  * @brief  This macro defines  Null schedule return value of schedule table handler .
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LinIf_SchdlHdlrRet_OnNullSchedule           ((LinIf_ScheduleTableHandlerRetType)0x00u)

/**
  * @brief  This macro defines  No new message  return value of schedule table handler .
  * unit : N/A
  * Resolution: N/A
  * Range: 1
  * Applicablity: N/A
  */
#define LinIf_SchdlHdlrRet_NoNewMessage             ((LinIf_ScheduleTableHandlerRetType)0x01u)

/**
  * @brief  This macro defines  new message  return value of schedule table handler .
  * unit : N/A
  * Resolution: N/A
  * Range: 2
  * Applicablity: N/A
  */
#define LinIf_SchdlHdlrRet_NewMessage               ((LinIf_ScheduleTableHandlerRetType)0x02u)

/* event-triggered collision resolving table states */

/**
  * @brief  This macro defines  value of Collison resolving state is idle .
  * unit : N/A
  * Resolution: N/A
  * Range: 0
  * Applicablity: N/A
  */
#define LinIf_EvtCollResolvingState_Idle            ((uint8)0x00u)

/**
  * @brief  This macro defines value of  Collison resolving state detected .
  * unit : N/A
  * Resolution: N/A
  * Range: 1
  * Applicablity: N/A
  */
#define LinIf_EvtCollResolvingState_Detected         0x01u

/**
  * @brief  This macro defines value of  Collison resolving state resolving .
  * unit : N/A
  * Resolution: N/A
  * Range: 2
  * Applicablity: N/A
  */
#define LinIf_EvtCollResolvingState_OnResolving     ((uint8)0x02u)





//=====================================================================================================================
//                                  PRIVATE FUNCTION DECLArATIONS 
//=====================================================================================================================

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Sleep_Wakeup_Transistion_Process
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function processes the pending Sleep Wake up requests
/// @return : void
///<br>
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Sleep_Wakeup_Transistion_Process(const uint8 Channel);

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Handle_NewFrameTransfer
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function processes the New frame transfers
/// @return : Void
///<br>
///<br>
//---------------------------------------------------------------------------------------------------------------------



static Std_ReturnType LinIf_Handle_NewFrameTransfer(Lin_PduType *LinIf_LinPduPtr, LinIf_FrameType *Linif_FrameHandle_Data_ptr, uint8 Channel
                        #if ( LINIF_TP_SUPPORTED == STD_ON )
                        ,LinTp_ControlType* const Lin_TpCtrlPtr
                        #endif
                        );
//---------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Reset_Schedule_Table
/// @param : LinIf_ChannelDataType LinIf_SchedTabDataPtr - Current execution schedule table
/// @Description : This function  Reset  the Schedule table 
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Reset_Schedule_Table(LinIf_ChannelDataType LinIf_SchedTabDataPtr);



//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Channel_MainFunction
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function main processing Functions for Individual Channels
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Channel_MainFunction( uint8 Channel);


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Schedule_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function  processing the Scheduling for corresponding  Channels
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Schedule_Processing( uint8 Channel);


//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleProcessing_UnconditionalFrame
/// @param uint8 Channel - Channel Id of the LINIF module
/// @param LinIf_FrameType  Linif_FrameHandle_Data_ptr - it's point to the frame for transmission.
/// @param Lin_PduType *LinIf_LinPduPtr - it is used to store the PID, checksum, pdu direction, data length and sdu ptr of frame.
/// @Description This function is get the data part of frame from PDUR layer.
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_ScheduleProcessing_UnconditionalFrame(Lin_PduType *LinIf_LinPduPtr, const LinIf_FrameType *Linif_FrameHandle_Data_ptr, uint8 Channel);



//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTable_Handler
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function  processing the Schedule table handler for corresponding  Channels
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static LinIf_ScheduleTableHandlerRetType LinIf_ScheduleTable_Handler(LinIf_FrameType *Linif_Frame_Data_ptr,  uint8 Channel);



//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTableHandler_RunOnceFinalization
/// @param : LinIf_ChannelDataType LinIf_SchedTabData - Current execution schedule table
/// @Description :   If schedule table is RUN ONCE,perform the actual switch  and notify the schedule change 
/// @return : void
///<br>
//--------------------------------------------------------------------------------------------------------------------- 
static void    LinIf_ScheduleTableHandler_RunOnceFinalization(LinIf_ChannelDataType *LinIf_SchedTabData  );

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTableHandler_RequestedTableSwitch
/// @param : LinIf_ChannelDataType LinIf_SchedTabData - Current execution schedule table
/// @Description :  If a new table is requested, perform the actual switch (if not a RUNONCE schedule is active) and notify the schedule change 
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void   LinIf_ScheduleTableHandler_RequestedTableSwitch(LinIf_ChannelDataType *LinIf_SchedTabData, uint8 Channel);


#if ( LINIF_SPORADIC_FRAME_SUPPORT == STD_ON )

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleProcessing_SporadicFrame
/// @param uint8 Channel - Channel Id of the LINIF module
/// @param LinIf_FrameType  Linif_FrameHandle_Data_ptr - it's point to the frame for transmission.
/// @param Lin_PduType *LinIf_LinPduPtr - it is used to store the PID, checksum, pdu direction, data length and sdu ptr of frame.
/// @Description This function is used to get a one frame from sporadic frame list .
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType LinIf_ScheduleProcessing_SporadicFrame(Lin_PduType *LinIf_LinPduPtr, uint8 Channel);

#endif


#if(LINIF_SPORADIC_FRAME_SUPPORT == STD_ON) 
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_GetTxPduIdOfSporadicFrameLookupTable
/// @param uint8 IndexNumber - Index of sporadic frame buffer
/// @Description This function is used to get a  frame PduID  from sporadic frame list .
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static uint8 LinIf_GetTxPduIdOfSporadicFrameLookupTable(uint8 IndexNumber);
#endif

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Unconditional_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_UnCont_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the unconditional frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Unconditional_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_UnCont_Frame_Data_ptr);


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_EventTrigger_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_EventTrigger_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Event triggered frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_EventTrigger_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_EventTrigger_Frame_Data_ptr);


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Sporadic_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_SporadicTrigger_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Sporadic frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Sporadic_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_SporadicTrigger_Frame_Data_ptr);


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_SRF_Frame_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_SRF_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Slave response frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_SRF_Frame_Processing( const uint8 Channel, const LinIf_FrameType *Linif_SRF_Frame_Data_ptr);


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_MRF_Frame_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_MRF_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Slave response frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_MRF_Frame_Processing( const uint8 Channel, const LinIf_FrameType *Linif_MRF_Frame_Data_ptr);





//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_Init
/// @param LinIf_ConfigType *ConfigPtr - Pointer to the Configuration Structure.
/// @Description Initializes the LIN Interface.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_Init(const LinIf_ConfigType *ConfigPtr)
{

    /*Assign Configuration values into global variables*/
    LinIf_ConfigPtr = ConfigPtr;

    /* local variable to initialize all the LIN channels  */
    uint8 fl_LinIf_ChId_U8;

    /** Check configuration pointer is valid  */
    LINIF_ERRORWRAPPER((LinIf_ConfigPtr != NULL), LINIF_INIT_SERVICE_ID, LINIF_E_PARAMETER_POINTER);
    /** Check LIN IF module is already initialized  */
    LINIF_ERRORWRAPPER((LinIf_GlobalStatus != LINIF_INITIALIZATION), LINIF_INIT_SERVICE_ID, LINIF_E_ALREADY_INITIALIZED);

    for (fl_LinIf_ChId_U8 = 0; fl_LinIf_ChId_U8 < LINIF_NUMBER_OF_CHANNELS; fl_LinIf_ChId_U8++)
    {
        /* Flush all the channel related data before initialization  */
        (void)memset(&LinIf_ChannelData[fl_LinIf_ChId_U8], LINIF_RESET_VAR, sizeof(LinIf_ChannelDataType));

        /** Get the startup status from User Configuration  **/
        LinIf_ChannelData[fl_LinIf_ChId_U8].Channel_Status = LinIf_ConfigPtr->LinIfChannel[fl_LinIf_ChId_U8].LinIfStartupState;

        /* Check the channel startup status requested  is SLEEP  */
        if (LINIF_CHANNEL_SLEEP == LinIf_ChannelData[fl_LinIf_ChId_U8].Channel_Status)
        {
            /* It is expected that Lin Driver goes to sleep */
            (void)Lin_GoToSleepInternal(fl_LinIf_ChId_U8); 
  
            /*[SWS_LinIf_00712] ⌈When the function Lin_GoToSleep or Lin_GotoSleepInternal is called,
             the function LinIf_MainFunction shall clear the wakeup flag of selected channel.*/
            LinIf_ChannelData[fl_LinIf_ChId_U8].LinIf_WakeupFlag  = LINIF_WAKEUP_NOT_OCCURRED;
            
        }
        else
        {
            /* No action Required  */
        }

        /** Set the schedule type NULL_SCHEDULE for each configured channel */
        LinIf_ChannelData[fl_LinIf_ChId_U8].Current_ScheduleTable_InExecution = (LinIf_ScheduleTableType *)LinIf_ConfigPtr->LinIfChannel[fl_LinIf_ChId_U8].LinIfScheduleTable;
		/* Enable scheduler processing */
		LinIf_SchedularEnableStatus[fl_LinIf_ChId_U8] = TRUE;
    }

    /*Initialize sporadic transmit status as not OK*/
    LinIf_Sporadic_Frame_Transmit_Status  = E_NOT_OK;  

    /*  All channel related initializations are completed 
        change the Global state of LIN_IF to INIT  */
    LinIf_GlobalStatus = LINIF_INITIALIZATION;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_DeInit
/// @param void
/// @Description Deintializes the LIN If module
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_DeInit(void)
{
    /* local variable to initialize all the LIN channels  */
    uint8 fl_LinIf_ChId_U8;

    for (fl_LinIf_ChId_U8 = 0; fl_LinIf_ChId_U8 < LINIF_NUMBER_OF_CHANNELS; fl_LinIf_ChId_U8++)
    {
        /* Reset All the channel global variables  */
        (void)memset(&LinIf_ChannelData, LINIF_RESET_VAR, sizeof(LinIf_ChannelDataType));
    }

    /* Change the LIN_IF global status to  UNINIT*/
    LinIf_GlobalStatus = LINIF_UNINIT;
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleRequest
/// @param NetworkHandleType Channel - Channel index.
///        LinIf_SchHandleType NewScheduleRequest - Identification of the new schedule to be set.
/// @Description To request a new schedule change.
/// @return Std_ReturnType - E_OK: Schedule table request has been accepted.
/// E_NOT_OK: Schedule table switch request has not been accepted due to one of the following reasons: -
/// LIN Interface has not been initialized - referenced channel does not exist (identification is out of range)
/// referenced schedule table does not exist (identification is out of range) -
/// State is sleep
/// Note: this function shall be called only after LinIf modules ins initialized using LinIf_Init
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_ScheduleRequest(NetworkHandleType Channel, LinIf_SchHandleType NewScheduleRequest)
{
    /**  Check LIN IF module is initialized  **/
    LINIF_ERRORWRAPPER_W_RV((LinIf_GlobalStatus != LINIF_UNINIT), LINIF_SCHEDULEREQUEST_SERVICE_ID, LINIF_E_UNINIT, E_NOT_OK);

    /**  Check whether the Channel Selected  is valid  */
    LINIF_ERRORWRAPPER_W_RV((Channel < LINIF_NUMBER_OF_CHANNELS), LINIF_SCHEDULEREQUEST_SERVICE_ID, LINIF_E_NONEXISTENT_CHANNEL, E_NOT_OK);

    /** Check whether the NewScheduleRequest count is valid  */
    LINIF_ERRORWRAPPER_W_RV((NewScheduleRequest < LINIF_SCH_CNT), LINIF_SCHEDULEREQUEST_SERVICE_ID, LINIF_E_SCHEDULE_REQUEST_ERROR, E_NOT_OK);

    /** Check whether the Selected LINIF Channel is operational   */
    LINIF_ERRORWRAPPER_W_RV((LinIf_ChannelData[Channel].Channel_Status != LINIF_CHANNEL_SLEEP && LinIf_ChannelData[Channel].Channel_Status != LINIF_CHANNEL_SLEEP_TRANS), LINIF_SCHEDULEREQUEST_SERVICE_ID, LINIF_E_SCHEDULE_REQUEST_ERROR, E_NOT_OK);

    /* All conditions are ok */

    /* Set the new Schedule Requested flag  */
    LinIf_ChannelData[Channel].IsNewScheduleRequestReceived = TRUE;

    /** Set the new requested Schedule table  */
    LinIf_ChannelData[Channel].New_ScheduleRequest = NewScheduleRequest;

    return E_OK;
}


#if ( LINIF_TRANCEIVER_DRIVER_SUPPORTED == STD_ON )
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_SetTrcvMode
/// @param NetworkHandleType Channel - Identification of the LIN channel
///        LinTrcv_TrcvModeType TransceiverModePtr - Requested mode transition.
/// @Description Set the given LIN transceiver to the given mode.
/// @return Std_ReturnType - E_OK: Will be returned, if the transceiver state has been changed to the requested mode..
/// E_NOT_OK: Will be returned, if the transceiver state change has failed or the parameter is out of the allowed range.
/// The previous state has not been changed.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_SetTrcvMode(NetworkHandleType Channel, LinTrcv_TrcvModeType TransceiverMode)
{
    /*This local variables get status of API"LinTrcv_SetOpMode" from Lin Transceiver driver*/
    uint8 fl_LinIf_SetTrcvMode_Result_U8 = E_NOT_OK;

            /**  Check LIN IF module is not initialized  **/
    LINIF_ERRORWRAPPER_W_RV((LinIf_GlobalStatus != LINIF_UNINIT), LINIF_SETTRCVMODE_SERVICE_ID, LINIF_E_UNINIT, E_NOT_OK);
    /* If development error detection is enabled and an invalid mode is requested for TransceiverMode, the function 
       LinIf_SetTrcvMode shall report LINIF_E_TRCV_INV_MODE to the default error tracer */
    LINIF_ERRORWRAPPER_W_RV((TransceiverMode == LINTRCV_OP_MODE_NORMAL) && (TransceiverMode == LINTRCV_OP_MODE_SLEEP) ,LINIF_SETTRCVMODE_SERVICE_ID, LINIF_E_TRCV_INV_MODE, E_NOT_OK );

    /**  Check whether the Channel Selected  is valid  */
    LINIF_ERRORWRAPPER_W_RV((Channel < LINIF_NUMBER_OF_CHANNELS), LINIF_SETTRCVMODE_SERVICE_ID, LINIF_E_NONEXISTENT_CHANNEL, E_NOT_OK);

     /* The API LinIf_SetTrcvMode returns the value that is returned by LinTrcv_SetOpMode. */
    /* Set the Transceiver mode by calling Lin Trcv Driver  */
    fl_LinIf_SetTrcvMode_Result_U8 = LinTrcv_SetOpMode(Channel, TransceiverMode);

   /*Return the status of API LinIf_SetTrcvMode from lin transceiver driver*/
    return fl_LinIf_SetTrcvMode_Result_U8;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_GetTrcvMode
/// @param NetworkHandleType Channel - Identification of the LIN channel
///        LinTrcv_TrcvModeType* TransceiverModePtr - pointer to a memory location where output value will be stored.
/// @Description To get the current lin transceiver mode.
/// @return Std_ReturnType - E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
/// E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or
/// channel parameter is invalid or pointer is NULL.
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_GetTrcvMode(NetworkHandleType Channel, LinTrcv_TrcvModeType *TransceiverModePtr)
{
    /*This local variables get status of API"LinTrcv_GetOpMode" from Lin Transceiver driver*/
    uint8 fl_LinIf_GetTrcvMode_Result_U8 = E_NOT_OK;

        /**  Check LIN IF module is not initialized  **/
    LINIF_ERRORWRAPPER_W_RV((LinIf_GlobalStatus != LINIF_UNINIT), LINIF_GETTRCVMODE_SERVICE_ID, LINIF_E_UNINIT, E_NOT_OK);

    /* If development error detection is enabled and an invalid value for Channel is given, the function LinIf_GetTrcvMode shall report 
       LINIF_E_NONEXISTENT_CHANNEL to the default error tracer. */
    /**  Check whether the Channel Selected  is valid  */
    LINIF_ERRORWRAPPER_W_RV((Channel < LINIF_NUMBER_OF_CHANNELS), LINIF_GETTRCVMODE_SERVICE_ID, LINIF_E_NONEXISTENT_CHANNEL, E_NOT_OK);

    /* If development error detection is enabled and the parameter TransceiverModePtr has an invalid value, the function 
       LinIf_GetTrcvMode shall raise the development error code LINIF_E_PARAM_POINTER. */
    /** Check configuration pointer is valid  */
    LINIF_ERRORWRAPPER_W_RV((TransceiverModePtr != NULL), LINIF_GETTRCVMODE_SERVICE_ID, LINIF_E_PARAMETER_POINTER, E_NOT_OK);

    /* invoke the underlying function LinTrcv_GetOpMode(LinNetwork, OpMode) for 
       the corresponding requested LIN transceiver. */
    fl_LinIf_GetTrcvMode_Result_U8 = LinTrcv_GetOpMode(Channel, TransceiverModePtr);

   /*Return the status of API LinTrcv_GetOpMode from lin transceiver driver*/
    return fl_LinIf_GetTrcvMode_Result_U8;
}

#endif /*LINIF_TRANCEIVER_DRIVER_SUPPORTED == STD_ON*/
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_MainFunction
/// @param void
/// @Description This is the main processing function for LIN if module.
///              This funcion will be shall be invoked periodically.
///              LinIf_MainFunction is resposible for transmitting Sleep/wake Up, Unconditonal frames.
/// @return void
/// Note: this function shall be called only after LinIf modules is initialized using LinIf_Init
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_MainFunction(void)
{
    uint8 fl_chIndex_U8;

    #if ( LINIF_TP_SUPPORTED == STD_ON )
    LinTp_ControlType* tpCtrlTmp;
    #endif

    if (LinIf_GlobalStatus != LINIF_UNINIT)
    {

        /** Process for all the configured channels */
        for (fl_chIndex_U8 = 0; fl_chIndex_U8 < LINIF_NUMBER_OF_CHANNELS; fl_chIndex_U8++)
        {
            /* Process Sleep - Wake up Transistions for Each channel  */
            LinIf_Sleep_Wakeup_Transistion_Process(fl_chIndex_U8);

                /* Process Frame Transistion and Reception for each channel  */
            LinIf_Channel_MainFunction(fl_chIndex_U8);

            
            #if ( LINIF_TP_SUPPORTED == STD_ON )

    
            tpCtrlTmp = LinTp_GetAddrCtrl(fl_chIndex_U8);
        
            /*Update LinTP P2 timer Handle*/
            LinTp_P2_Timer_Handling(tpCtrlTmp, fl_chIndex_U8);

            /*-Notifies the upper layers after each main processing function cycle of the LIN TP
               -LinTp post notification to the PduR of last transmitted/ received TP message */
            LinTp_MainPostProcessing(tpCtrlTmp, fl_chIndex_U8);
            #endif

        }
    }
    else
    {
            /*Do nothing*/
    }
}
//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_GotoSleep
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function LinIf_GotoSleep initiates a transition into sleep mode on the selected
///                channel/controller.
/// @return : Std_ReturnType - E_OK: Request to go to sleep has been accepted
///           or sleep transition is already in progress or controller is already in sleep state.
///           E_NOT_OK: Request to go to sleep has not been accepted due to one or more of the following reasons:
///           LIN Interface has not been initialized -
///           referenced channel does not exist (identification is out of range)
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinIf_GotoSleep(NetworkHandleType Channel)
{
    /**  Check LIN IF module is not initialized  **/
    LINIF_ERRORWRAPPER_W_RV((LinIf_GlobalStatus != LINIF_UNINIT), LINIF_GOTOSLEEP_SERVICE_ID, LINIF_E_UNINIT, E_NOT_OK);

    /**  Check whether the Channel Selected  is valid  */
    LINIF_ERRORWRAPPER_W_RV((Channel < LINIF_NUMBER_OF_CHANNELS), LINIF_GOTOSLEEP_SERVICE_ID, LINIF_E_NONEXISTENT_CHANNEL, E_NOT_OK);

    /* Check whether LINIF Channel is operational  */
    if (LinIf_ChannelData[Channel].Channel_Status == LINIF_CHANNEL_OPERATIONAL)
    {

        /** Initiate a transition into sleep mode on the selected channel */
        /*  LinIf_GotoSleep will start the process of putting the 
            bus into sleep and shall not do it immediately */
        LinIf_ChannelData[Channel].Channel_Status = LINIF_CHANNEL_SLEEP_TRANS;

        /* Clear the Sleep Request in process flag  */
        LinIf_ChannelData[Channel].SleepRequestStatus = LINIF_SLEEP_REQUEST_FLAG_CLEAR;
    }
    else
    {
        /* LinIf_GotoSleep shall have no effect on the channel if 
           it is already in the sleep state */
    }

    return E_OK;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Wakeup
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function LinIf_GotoSleep initiates a transition into sleep mode on the selected
///                channel/controller.
/// @return : Std_ReturnType - E_OK: Request to wake up has been accepted or the controller is not in sleep state.
///           E_NOT_OK: Request to wake up has not been accepted due to one or more of the following reasons:
///           LIN Interface has not been initialized -
///           referenced channel does not exist (identification is out of range)
///           Lin_Wakeup has returned E_NOT_OK
///<br>
//---------------------------------------------------------------------------------------------------------------------

Std_ReturnType LinIf_WakeUp(NetworkHandleType Channel)
{
    Std_ReturnType fl_linwakeup_result = E_OK;
    /** LIN Interface has to be initialized with a call of LinIf_Init before this API service*/
    LINIF_ERRORWRAPPER_W_RV((LinIf_GlobalStatus != LINIF_UNINIT), LINIF_WAKEUP_SERVICE_ID, LINIF_E_UNINIT, E_NOT_OK);

    /** @req LINIF565 */
    LINIF_ERRORWRAPPER_W_RV((Channel < LINIF_NUMBER_OF_CHANNELS), LINIF_WAKEUP_SERVICE_ID, LINIF_E_NONEXISTENT_CHANNEL, E_NOT_OK);

    /* Check the current Channel Status  */
    switch (LinIf_ChannelData[Channel].Channel_Status)
    {
    case LINIF_CHANNEL_SLEEP:
        /** LIN_IF Channel is in sleep state */
        /* Driver always returns E_OK */
        /*Check whether if wake up is occured by bus or not*/
        if (LinIf_ChannelData[Channel].LinIf_WakeupFlag ==  LINIF_WAKEUP_NOT_OCCURRED)
        {
            /*If wake up is not occurred by bus, request the wake up by driver*/
            fl_linwakeup_result = Lin_Wakeup(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId);

            /*Set current schedule table index as zero position*/
            LinIf_ChannelData[Channel].CurrentScheduleTableIndex = 0;

            /*Set current schedule table time delay as Zero*/
            LinIf_ChannelData[Channel].Current_DelayInTicks = 0;

        }
        else
        {
            /* code */
        }
        

        break;

    case LINIF_CHANNEL_OPERATIONAL:
        /** @req LINIF670 */

        LinSM_WakeUpConfirmation(Channel, TRUE);
        break;

    case LINIF_CHANNEL_SLEEP_TRANS:
        /* Set the Wakeup Flag to Process the Wake received during Sleep Transistion */
        LinIf_ChannelData[Channel].NewWakeUpRequestReceived = LINIF_NEW_WAKEUP_REQUESTED;
        break;
    default:
        /*Do Nothing */
        break;
    }

    /*Return wake up result status*/
    return fl_linwakeup_result;
}

//=====================================================================================================================
//  PRIVATE FUNCTION DEFINITIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_Sleep_Wakeup_Transistion_Process
/// @param uint8 Channel - Channel Id of the LINIF module
/// @Description To process the pending sleep/Wake Up transistions for each channel.
/// @return void
///<br>
//---------------------------------------------------------------------------------------------------------------------

static void LinIf_Sleep_Wakeup_Transistion_Process(const uint8 Channel)
{
    uint8 fl_LinIf_Sleep_Sdu = 0;
    uint8 * fl_LinIf_Sleep_SduPtr = NULL_PTR;
    Lin_StatusType fl_Lin_Local_Status;
    LinIf_StatusType fl_LinIf_Local_Status;

    /* Get the LINIF Channel Status  */
    fl_LinIf_Local_Status = LinIf_ChannelData[Channel].Channel_Status;
    fl_LinIf_Sleep_SduPtr = &fl_LinIf_Sleep_Sdu;
    /* Get the status of the LIN Channel  */
    fl_Lin_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_LinIf_Sleep_SduPtr);

    switch (fl_LinIf_Local_Status)
    {
    case LINIF_CHANNEL_SLEEP_TRANS:
        /* On going Sleep Transistion present */
        /* Check Lin is in other than sleep state  */
        if (LIN_CH_SLEEP != fl_Lin_Local_Status)
        {
            /* Check Sleep command is implemented by the Driver */
            if (LINIF_SLEEP_CMD_IMPLEMENTED != LinIf_ChannelData[Channel].SleepRequestStatus)
            {
                /* Check whether any wake up requested received during Sleep transistions */
                if (LINIF_NEW_WAKEUP_REQUESTED != LinIf_ChannelData[Channel].NewWakeUpRequestReceived)
                {
                    /** Invoke the driver function to Send Sleep Frames  */
                    (void)Lin_GoToSleep(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId); //Driver always returns E_OK

                    /*[SWS_LinIf_00712] ⌈When the function Lin_GoToSleep or Lin_GotoSleepInternal is called,
                     the function LinIf_MainFunction shall clear the wakeup flag of selected channel.*/
                    LinIf_ChannelData[Channel].LinIf_WakeupFlag  = LINIF_WAKEUP_NOT_OCCURRED;
                    /* Set Sleep implemented Flag  */
                    LinIf_ChannelData[Channel].SleepRequestStatus = LINIF_SLEEP_CMD_IMPLEMENTED;
                }
                else
                {
                    /* If the go-to-sleep command is requested and the upper layer 
                           requests a wake-up before the go-to-sleep command is executed, 
                           the LIN Interface shall neither send the pending go-to-sleep command 
                           nor a wake-up on the bus and shall maintain the LIN channel state 
                           LINIF_CHANNEL_OPERATIONAL */
                    LinIf_ChannelData[Channel].Channel_Status = LINIF_CHANNEL_OPERATIONAL;

                    /* Clear the Sleep Request in process flag  */
                    LinIf_ChannelData[Channel].SleepRequestStatus = LINIF_CLEAR_SLEEP_CMD_IMPLEMENTED;
                }
            }
            else
            {
                /** When processing the go-to-sleep command, 
                     *  the function LinIf_MainFunction_<ChannelId> shall call 
                     *  the function Lin_GetStatus of the LIN Driver module, 
                     *  after the delay of the sleep mode frame has passed. 
                     *  When the return code of the function Lin_GetStatus is not 
                     *  LIN_CH_SLEEP, the go-to-sleep command transmission 
                     *  has failed.  */

                /* The delay of sleep mode frame is assumed to be time_base arbitarily since ASR is not specific */
                LinIf_ChannelData[Channel].Channel_Status = LINIF_CHANNEL_SLEEP;
                /* Clear the SleepRequestedStatus Flag   */
                LinIf_ChannelData[Channel].SleepRequestStatus = LINIF_CLEAR_SLEEP_CMD_IMPLEMENTED;
                /** When the go-to-sleep command was not sent successful, the LIN Interface shall invoke 
                     *  the function <User>_GotoSleepConfirmation with the parameter FALSE. */
                if(LinIf_ConfigPtr->LinIfGotoSleepConfirmationUL == LIN_SM)
                {
                    /*If LinIfGotoSleepConfirmationUL equal to Lin State manager , the confirmation notification will send to Lin SM Layer */
                    
                    LinSM_GotoSleepConfirmation(Channel,FALSE);
                    
                }
                else
                {
                    /*If LinIfGotoSleepConfirmationUL equal to CDD module , the confirmation notification will send to Corresponding CDD layer*/
                }
                
                
            }
        }
        else
        {
            /* LINIF is in Sleep State  */

            /* Check whether Wake Up requested by Upper Layer during sleep Transistion */
            if (LINIF_NEW_WAKEUP_REQUESTED != LinIf_ChannelData[Channel].NewWakeUpRequestReceived)
            {
                /** When processing the go-to-sleep command, the function LinIf_MainFunction_<ChannelId> shall call the function 
                     *  Lin_GetStatus of the LIN Driver module, after the delay of the sleep 
                     *  mode frame has passed. When the return code of the function Lin_GetStatus 
                     *  is LIN_CH_SLEEP, the function LinIf_MainFunction_<ChannelId> shall set the 
                     *  channel state of the affected channel to LINIF_CHANNEL_SLEEP. In this case, 
                     *  the go-to-sleep command transmission has successfully been performed */

                LinIf_ChannelData[Channel].Channel_Status = LINIF_CHANNEL_SLEEP;
                /** When the go-to-sleep command was sent successful or the function Lin_GoToSleepInternal was called, 
                     *  the LIN Interface shall invoke the function <User>_GotoSleepConfirmation with the 
                     *  parameter TRUE */
                

                if(LinIf_ConfigPtr->LinIfGotoSleepConfirmationUL == LIN_SM)
                {
                    /*If LinIfGotoSleepConfirmationUL equal to Lin State manager , the confirmation notification will send to Lin SM Layer */
                    LinSM_GotoSleepConfirmation(Channel,TRUE);
                }
                else
                {
                    /*If LinIfGotoSleepConfirmationUL equal to CDD module , the confirmation notification will send to Corresponding CDD layer*/
                }

                /** When entering the LINIF_CHANNEL_SLEEP state during the go-to-sleep command process, 
                     *  the function LinIf_MainFunction_<ChannelId> 
                     *  shall switch the current used schedule table to the NULL_SCHEDULE*/
                /* Set NULL schedule at sleep */
                LinIf_ChannelData[Channel].CurrentScheduleTableIndex = 0;

                /* Reset the Delay in ticks  */
                LinIf_ChannelData[Channel].Current_DelayInTicks = 0;

                LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution = (LinIf_ScheduleTableType *)LinIf_ConfigPtr->LinIfChannel[Channel].LinIfScheduleTable;
            }
            else
            {
                /* When the LIN Interface has checked the go-to-sleep command during 
                       the transition to sleep, using the function Lin_GetStatus of the LIN
                       Driver module and the return code of this function is LIN_CH_SLEEP, 
                       the LIN Interface shall call the function Lin_Wakeup to wake-up the 
                       channel again. */
                if (LinIf_ChannelData[Channel].LinIf_WakeupFlag ==  LINIF_WAKEUP_NOT_OCCURRED)
                {
                    /* Driver always returns E_OK */
                    (void)Lin_Wakeup(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId);
                    /* Set NULL schedule at Wake Up  */
                    LinIf_ChannelData[Channel].CurrentScheduleTableIndex = 0;
                    /* Reset the delay in Ticks   */
                    LinIf_ChannelData[Channel].Current_DelayInTicks = 0;
                    /* Clear the wake request  */
                    LinIf_ChannelData[Channel].NewWakeUpRequestReceived = LINIF_CLEAR_NEW_WAKEUP_REQUESTED;
                }
                else
                {
                    /* Do nothing */
                }
                
            }
        }

        break;

    case LINIF_CHANNEL_SLEEP:

        if (LIN_CH_SLEEP != fl_Lin_Local_Status)
        {
            /** The LIN Interface shall transit from the channel state LINIF_CHANNEL_SLEEP to LINIF_CHANNEL_OPERATIONAL 
             *  when it has detected a wake-up request for the corresponding channel */
            LinIf_ChannelData[Channel].Channel_Status = LINIF_CHANNEL_OPERATIONAL;

            /** When the return code of the function LinIf_Wakeup is E_OK, the LIN Interface shall issue the function 
             * <User>_WakeupConfirmation with the parameter TRUE */
            
            /*Check whether Upper layer module of LinIF layer is LinSM or CDD*/
            if(LinIf_ConfigPtr->LinIfWakeupConfirmationUL == LIN_SM)
            {
                
                /*If LinIfGotoSleepConfirmationUL equal to Lin State manager , the confirmation notification will send to Lin SM Layer */
                    LinSM_WakeUpConfirmation(Channel, TRUE);
                    
            }
            else
            {
                /*If LinIfWakeupConfirmationUL equal to CDD module , the confirmation notification will send to Corresponding CDD layer*/
            }
        }
        break;

    default:
        /* Other Cases are handled in LINIF_Main_Function */
        break;
    }
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_SchedulerControl
/// @param : NetworkHandleType Channel - Identification of the LIN channel.
/// @Description : The function enables/disables the schedule table processing.
///<br>
//---------------------------------------------------------------------------------------------------------------------
void LinIf_SchedulerControl(NetworkHandleType Channel,boolean CtrlStatus)
{
	if (LINIF_NUMBER_OF_CHANNELS > Channel)
	{
		LinIf_SchedularEnableStatus[Channel] = CtrlStatus;
	}
}


//=====================================================================================================================
//  PRIVATE FUNCTION DEFINITIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleProcessing_UnconditionalFrame
/// @param uint8 Channel - Channel Id of the LINIF module
/// @param LinIf_FrameType  Linif_FrameHandle_Data_ptr - it's point to the frame for transmission.
/// @param Lin_PduType *LinIf_LinPduPtr - it is used to store the PID, checksum, pdu direction, data length and sdu ptr of frame.
/// @Description This function is get the data part of frame from PDUR layer.
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
Std_ReturnType LinIf_ScheduleProcessing_UnconditionalFrame(Lin_PduType *LinIf_LinPduPtr, const LinIf_FrameType *Linif_FrameHandle_Data_ptr, uint8 Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  /*This local variable stores the PDU-R indication datas of the corresponding PDU ID */
  PduInfoType                    pduInfo;

  /*This local variable store return value of function call "PduR_LinIfTriggerTransmit"*/
  Std_ReturnType                 fl_TransmitStatus_u8;

  /* Initialize return value as not OK */
  fl_TransmitStatus_u8 = E_NOT_OK;


  /*  If unconditional frame has direction Tx */
  if ( LinIf_LinPduPtr->Drc == LIN_MASTER_RESPONSE )
  {
    /* set pointer for get transmit data from PDU layer */
    LinIf_LinPduPtr->SduPtr   = (uint8*)(&(LinIf_ChannelData[Channel].LinIf_TxData[0])); 

   /*Assign data pointer and length to local variable to get data part of frame from PduR layer*/
    pduInfo.SduLength      = LinIf_LinPduPtr->Dl;
    pduInfo.SduDataPtr     = LinIf_LinPduPtr->SduPtr;

    /*  Request data from PduR for frame to transmit */
    fl_TransmitStatus_u8 = (Std_ReturnType)PduR_LinIfTriggerTransmit(Linif_FrameHandle_Data_ptr->LinIfTxTargetPduId, &pduInfo); 

  }
  else
  {
      /* Do nothing */
      fl_TransmitStatus_u8 = E_OK; /* Added for slave response, need to be updated - pchinnat */
  }
  
  /*return trigger transmit  status from Pdu layer*/
  return fl_TransmitStatus_u8;
}




#if ( LINIF_SPORADIC_FRAME_SUPPORT == STD_ON )
//=====================================================================================================================
//  PRIVATE FUNCTION DEFINITIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_ScheduleProcessing_SporadicFrame
/// @param uint8 Channel - Channel Id of the LINIF module
/// @param LinIf_FrameType  Linif_FrameHandle_Data_ptr - it's point to the frame for transmission.
/// @param Lin_PduType *LinIf_LinPduPtr - it is used to store the PID, checksum, pdu direction, data length and sdu ptr of frame.
/// @Description This function is used to get a one frame from sporadic frame list .
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static Std_ReturnType LinIf_ScheduleProcessing_SporadicFrame(Lin_PduType *LinIf_LinPduPtr,  uint8 Channel)
{
  
  /* ----- Implementation ----------------------------------------------- */
    /*Set sporadic frame transmit status as not ok*/
    LinIf_Sporadic_Frame_Transmit_Status  = E_NOT_OK;  
    uint8 LinIf_SporadicFrame_ExecutionCount;

    /*This local variable stores the PDU-R indication datas of the corresponding PDU ID */
    PduInfoType PduInfoPtr;

    LinIf_FrameType *Linif_FrameHandle_Data_ptr;

    for(LinIf_SporadicFrame_ExecutionCount=0U;LinIf_SporadicFrame_ExecutionCount<LINIF_NUMBER_OF_SPORADIC_FRAME;LinIf_SporadicFrame_ExecutionCount++)
    {
        /*[SWS_LinIf_00471] ⌈The LIN Interface shall transmit the specific sporadic frame (defined in the LIN 2.1 specification)
         in the associated sporadic slot according to the priority of the sporadic frames. The priority of the sporadic frames is the
          order in which the sporadic frames are listed in the LDF. ⌋*/
        if (SporadicFrame_Flag[LinIf_SporadicFrame_ExecutionCount] == LINIF_SET)
        {
            /*Get the Current sporadic Frame Details  */
            Linif_FrameHandle_Data_ptr = &LINIF_User_SporadicFrameList[LinIf_SporadicFrame_ExecutionCount];

            /* Get the Lin PID  */
            LinIf_LinPduPtr->Pid = (Linif_FrameHandle_Data_ptr->LinIfPid);

            /*Clear the Sporadic Frame Priority Flag once the frame allocate to transmit */
            SporadicFrame_Flag[LinIf_SporadicFrame_ExecutionCount] = 0;


            /* Set the Data length to be transmitted  */
            LinIf_LinPduPtr->Dl = Linif_FrameHandle_Data_ptr->LinIfLength;

            /* Check the Frame Checksum Type */
            if (Linif_FrameHandle_Data_ptr->LinIfChecksumType == LINIF_ENHANCED)
            {
                /*If frame check sum type is enhanced, assign to pdu pointer of Lin driver*/
                LinIf_LinPduPtr->Cs = LIN_ENHANCED_CS;
            }
            else
            {
                /*If frame check sum type is Classic, assign to pdu pointer of Lin driver*/
                LinIf_LinPduPtr->Cs = LIN_CLASSIC_CS;
            }

            /* Check whether the Frame Direction is receive or transmit*/
            if (Linif_FrameHandle_Data_ptr->LinIfPduDirection == LinIfTxPdu)
            {
                /*If Frame direction is TxPdu , assign Master response to Pdu pointer of Lin driver*/
                LinIf_LinPduPtr->Drc = LIN_MASTER_RESPONSE;
                
                /* set pointer for get transmit data from PDU layer */
                LinIf_LinPduPtr->SduPtr   = (uint8*)(&(LinIf_ChannelData[Channel].LinIf_TxData[0])); 
                /*Assign data pointer and length to local variable to get data part of frame from PduR layer*/
                PduInfoPtr.SduLength      = LinIf_LinPduPtr->Dl;

                PduInfoPtr.SduDataPtr     = LinIf_LinPduPtr->SduPtr;

                /*  Request data from PduR for frame to transmit */
                (void)PduR_LinIfTriggerTransmit( Linif_FrameHandle_Data_ptr->LinIfTxTargetPduId, &PduInfoPtr);
            
            }
            else
            {
                /*If Frame direction is RxPdu , assign Slave response to Pdu pointer of Lin driver*/
                LinIf_LinPduPtr->Drc = LIN_SLAVE_RESPONSE;
            }

            /*Set sporadic frame transmit status as OK.*/
            LinIf_Sporadic_Frame_Transmit_Status = E_OK;
            
            
        }
        else
        {
            /*Do nothing*/
        }

        /*Increment the Sporadic frame execution count , if sporadic frame flag is not set*/

        /*Check the sporadic frame transmit status as Ok or not*/
        if(LinIf_Sporadic_Frame_Transmit_Status == E_OK)
        {
            break;
        }
        else
        {
            /* Do nothing */
        }
        
    }
    /*Return the Sporadic Frame transmit status*/
    return LinIf_Sporadic_Frame_Transmit_Status;
}
#endif


#if(LINIF_SPORADIC_FRAME_SUPPORT == STD_ON) 
//=====================================================================================================================
//  PRIVATE FUNCTION DEFINITIONS
//=====================================================================================================================
//---------------------------------------------------------------------------------------------------------------------
/// @brief LinIf_GetTxPduIdOfSporadicFrameLookupTable
/// @param uint8 IndexNumber - Index of sporadic frame buffer
/// @Description This function is used to get a  frame PduID  from sporadic frame list .
/// @return Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static uint8 LinIf_GetTxPduIdOfSporadicFrameLookupTable(uint8 IndexNumber)
{
    uint8 returnValue;

    /*Initialize return value as Zero*/
    returnValue = 0;

    switch(IndexNumber)
    {
        /*If index number is zero, return corresponding PduID value from Sporadic frame List*/
        case 0:
            returnValue = 0x04U;
            break;
        /*If index number is One, return corresponding PduID value from Sporadic frame List*/
        case 1:
            returnValue = 0x05U;
            break;
        /*If index number is Two, return corresponding PduID value from Sporadic frame List*/
        case 2:
            returnValue = 0x06U;
            break;
        default:
            /*Do nothing*/
            break; 
    }

    return(returnValue);

}
#endif/*LINIF_SPORADIC_FRAME_SUPPORT == STD_ON*/


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Handle_NewFrameTransfer
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_FrameHandle_Data_ptr - it's point to the frame for transmission.
/// @param Lin_PduType *LinIf_LinPduPtr - it is used to store the PID, checksum, pdu direction, data length and sdu ptr of frame.
/// @Description : This function processes the new frame transfer request for each channel
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------

static Std_ReturnType LinIf_Handle_NewFrameTransfer(Lin_PduType *LinIf_LinPduPtr, LinIf_FrameType *Linif_FrameHandle_Data_ptr, uint8 Channel
                        #if ( LINIF_TP_SUPPORTED == STD_ON )
                        ,LinTp_ControlType* const Lin_TpCtrlPtr
                        #endif
                        )
{
    /*This local variable store the return status of send frame function call*/
  Std_ReturnType     sendFrameTmp;

  /*Initialize local variable send frame status as not Ok*/
  sendFrameTmp = E_NOT_OK;

  /*  Handle frame depending on frame type */
  switch ( Linif_FrameHandle_Data_ptr->LinIfFrameType )
  {
    /*Ckeck whether sporadic frame support is enabled or Not*/
    #if ( LINIF_SPORADIC_FRAME_SUPPORT == STD_ON )
    /***********************************************************************************************************
     *  LinIf_FrameType_SporadicFrame
     **********************************************************************************************************/
    /* Sporadic frame: */
    case SPORADIC:

    /* If an associated unconditional frames is flagged for transmission,
    *     enter unconditional case to request transmit data from PduR (-> LinIf_ScheduleProcessing_SporadicFrame() ) */
    sendFrameTmp = LinIf_ScheduleProcessing_SporadicFrame( LinIf_LinPduPtr,Channel);
        break; 

    #endif

    /***********************************************************************************************************
      *  LinIf_FrameType_UnconditionalFrame
      **********************************************************************************************************/
    
    case UNCONDITIONAL: 
    /* Unconditional frame: Default RX and TX frame handling (-> LinIf_ScheduleProcessing_UnconditionalFrame() ) */
      sendFrameTmp = LinIf_ScheduleProcessing_UnconditionalFrame( LinIf_LinPduPtr, Linif_FrameHandle_Data_ptr,Channel); 
      break;

    case EVENT_TRIGGERED:
    /*Event triggered frame pdu direction is RxPdu, so its no need get data part of frame from PduR layer*/
    /* set pointer for get transmit data from PDU layer */
    LinIf_LinPduPtr->SduPtr   = (uint8*)(&(LinIf_ChannelData[Channel].LinIf_TxData[0]));
    sendFrameTmp = E_OK;

     break;

     case MRF:
     #if ( LINIF_TP_SUPPORTED == STD_ON )
     /*Prepares a MRF for transmission used by transport protocol.*/
     sendFrameTmp = LinTp_TxScheduleProcessing(Lin_TpCtrlPtr, &LinIf_ChannelData[Channel],LinIf_LinPduPtr);
     #endif
     break;

    default:
        /*Do nothing*/
      break;
  }
    /*Return Send Frame Status*/
  return sendFrameTmp;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Unconditional_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_UnCont_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the unconditional frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Unconditional_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_UnCont_Frame_Data_ptr)
{
    /*This local variable stores the status of the corresponding channel */
    Lin_StatusType fl_LinIf_Local_Status;

    /*This local variable stores the datas of the corresponding channel */
    uint8* fl_Lin_Sdu_Ptr = NULL;

    /*This local variable stores the PDU-R indication datas of the corresponding PDU ID */
    PduInfoType fl_LinIf_GetPduData;


    /* Check whether the direction of frame is receive or not*/
    if (Linif_UnCont_Frame_Data_ptr->LinIfPduDirection == LinIfRxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether s reception or transmit process is finished */
        /* pchinnat - Receive path to be verified */
        if ((fl_LinIf_Local_Status == LIN_RX_OK) ||
            (fl_LinIf_Local_Status == LIN_OPERATIONAL))
        {
            if(fl_LinIf_Local_Status == LIN_RX_OK)
            {
                /*Assign received data into local variables*/
                fl_LinIf_GetPduData.SduDataPtr = fl_Lin_Sdu_Ptr;

                /*Assign received data length into lacal variables*/
                fl_LinIf_GetPduData.SduLength = Linif_UnCont_Frame_Data_ptr->LinIfLength;

                /*Notification Indicate to Upper layer*/
                PduR_LinIfRxIndication(Linif_UnCont_Frame_Data_ptr->LinIfTxTargetPduId, &fl_LinIf_GetPduData);
            }

        }
        else
        { /* RX_ERROR or BUSY */
            /** When the LIN Interface has determined the LIN Driver module’s status as LIN_RX_BUSY or LIN_RX_ERROR, 
                 *  the LIN Interface shall consider the received frame as lost. Therefore, the LIN Interface shall 
                 *  report the runtime error code LINIF_E_RESPONSE to the Default Error Tracer, if this frame is an unconditional frame. */

            /* When the LIN Interface has determined the LIN Driver module’s 
                   status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
                   expected frame as lost. Therefore, the LIN Interface shall report the 
                   runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
                   if this frame is an unconditional frame*/

                DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    /* Check whether the direction of frame is transmission or not*/
    else if (Linif_UnCont_Frame_Data_ptr->LinIfPduDirection == LinIfTxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether status as reception or transmit finished */
        if (fl_LinIf_Local_Status == LIN_TX_OK)
        {
           /* TX confirmation Callback  */
                             
           PduR_LinIfTxConfirmation(Linif_UnCont_Frame_Data_ptr->LinIfTxTargetPduId);
        }
        else
        { 
            /* TX_ERROR or BUSY */
        /* When the LIN Interface has determined the LIN Driver module’s 
        status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
        expected frame as lost. Therefore, the LIN Interface shall report the 
        runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
        if this frame is an unconditional frame*/
            DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    else
    {
        /*Do nothing*/
    }
}



//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_EventTrigger_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_EventTrigger_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Event triggered frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_EventTrigger_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_EventTrigger_Frame_Data_ptr)
{
    /*This local variable stores the status of the corresponding channel */
    Lin_StatusType fl_LinIf_Local_Status;

    /*This local variable stores the datas of the corresponding channel */
    uint8 *fl_Lin_Sdu_Ptr = NULL;

    /*This local variable stores the PDU-R indication datas of the corresponding PDU ID */
    PduInfoType fl_LinIf_GetPduData;


    /* Check whether the direction of frame is receive or not*/
    if (Linif_EventTrigger_Frame_Data_ptr->LinIfPduDirection == LinIfRxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether status as reception or transmit finished */
        if (fl_LinIf_Local_Status == LIN_RX_OK)
        {
            /*Assign received data into lacal variables*/
            fl_LinIf_GetPduData.SduDataPtr = fl_Lin_Sdu_Ptr;

            /*Assign received data length into lacal variables*/
            fl_LinIf_GetPduData.SduLength = Linif_EventTrigger_Frame_Data_ptr->LinIfLength;
            
            /*Notification Indicate to Upper layer*/
            PduR_LinIfRxIndication(Linif_EventTrigger_Frame_Data_ptr->LinIfTxTargetPduId, &fl_LinIf_GetPduData);


        }
        else
        { /* RX_ERROR or BUSY */
            /** When the LIN Interface has determined the LIN Driver module’s status as LIN_RX_BUSY or LIN_RX_ERROR, 
                 *  the LIN Interface shall consider the received frame as lost. Therefore, the LIN Interface shall 
                 *  report the runtime error code LINIF_E_RESPONSE to the Default Error Tracer, if this frame is an unconditional frame. */

                    if ( ( fl_LinIf_Local_Status == (Lin_StatusType)LIN_RX_BUSY ) || ( fl_LinIf_Local_Status == (Lin_StatusType)LIN_RX_ERROR ) )
                    {
                        /* collision on EVT frame detected */
                        LinIf_ChannelData[Channel].New_CollisonScheduleRequest_Status = LinIf_EvtCollResolvingState_Detected;

                        /*[SWS_LinIf_00588] ⌈If a collision occurs in an event-triggered frame response, then the LIN Interface shall 
                        switch to the corresponding collision resolving schedule table. ⌋*/
                        (void)LinIf_ScheduleRequest(Channel,LINIF_COLLISON_SCHEDULE_INDEX);
                        /* else: schedule table change was requested before, so collision resolving is lost */
                    }
                    /*  If no response received, no slave has responded, nothing to do */
                    /*  If no response received, no slave has responded, nothing to do */
                    /* silent EVT frame - no further action required */
                    /*
                    else if (fl_LinIf_Local_Status == (Lin_StatusType)LIN_RX_NO_RESPONSE)
                    {
                        
                    }*/
                    else
                    {
                        /*Do nothing*/
                    }
                
        }
    }
    /* Check whether the direction of frame is transmission or not*/
    else if (Linif_EventTrigger_Frame_Data_ptr->LinIfPduDirection == LinIfTxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether status as reception or transmit finished */
        if (fl_LinIf_Local_Status == LIN_TX_OK)
        {
           /* TX confirmation Callback  */
            PduR_LinIfTxConfirmation(Linif_EventTrigger_Frame_Data_ptr->LinIfTxTargetPduId);
        }
        else
        {
                /* TX_ERROR or BUSY */
            /* When the LIN Interface has determined the LIN Driver module’s 
            status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
            expected frame as lost. Therefore, the LIN Interface shall report the 
            runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
            if this frame is an unconditional frame*/
                
                DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    else
    {
            /*Do nothing*/
    }

}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Sporadic_Frame_MessageProcessing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_SporadicTrigger_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Sporadic frame receive and transmission status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Sporadic_Frame_MessageProcessing( const uint8 Channel, const LinIf_FrameType *Linif_SporadicTrigger_Frame_Data_ptr)
{
        /*This local variable stores the status of the corresponding channel */
    Lin_StatusType fl_LinIf_Local_Status;

    /*This local variable stores the datas of the corresponding channel */
    uint8 *fl_Lin_Sdu_Ptr = NULL;

    /*This local variable stores the PDU-R indication datas of the corresponding PDU ID */
    PduInfoType fl_LinIf_GetPduData;



    /* Check whether the direction of frame is receive or not*/
    if (Linif_SporadicTrigger_Frame_Data_ptr->LinIfPduDirection == LinIfRxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether status as reception or transmit finished */
        if (fl_LinIf_Local_Status == LIN_RX_OK)
        {
            /*Assign received data into lacal variables*/
            fl_LinIf_GetPduData.SduDataPtr = fl_Lin_Sdu_Ptr;

            /*Assign received data length into lacal variables*/
            fl_LinIf_GetPduData.SduLength = Linif_SporadicTrigger_Frame_Data_ptr->LinIfLength;
            /** @req LINIF289 */
            PduR_LinIfRxIndication(Linif_SporadicTrigger_Frame_Data_ptr->LinIfTxTargetPduId, &fl_LinIf_GetPduData);

        }
        else
        { /* RX_ERROR or BUSY */
            /** When the LIN Interface has determined the LIN Driver module’s status as LIN_RX_BUSY or LIN_RX_ERROR, 
                 *  the LIN Interface shall consider the received frame as lost. Therefore, the LIN Interface shall 
                 *  report the runtime error code LINIF_E_RESPONSE to the Default Error Tracer, if this frame is an unconditional frame. */

            /* When the LIN Interface has determined the LIN Driver module’s 
                   status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
                   expected frame as lost. Therefore, the LIN Interface shall report the 
                   runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
                   if this frame is an unconditional frame*/

                DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);

            
        }
    }
    /* Check whether the direction of frame is transmission or not*/
    else if (Linif_SporadicTrigger_Frame_Data_ptr->LinIfPduDirection == LinIfTxPdu)
    {
        /*Get Transmit/reception Status from Lin Driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check whether status as reception or transmit finished */
        if (fl_LinIf_Local_Status == LIN_TX_OK)
        {
           /* TX confirmation Callback  */
              PduR_LinIfTxConfirmation(Linif_SporadicTrigger_Frame_Data_ptr->LinIfTxTargetPduId);
        }
        else
        {


        /* When the LIN Interface has determined the LIN Driver module’s 
                status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
                expected frame as lost. Therefore, the LIN Interface shall report the 
                runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
                if this frame is an unconditional frame*/                   
            DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    else
    {
            /*Do nothing*/
    }

}




//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_SRF_Frame_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_SRF_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the Slave response frame receive status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_SRF_Frame_Processing( const uint8 Channel, const LinIf_FrameType *Linif_SRF_Frame_Data_ptr)
{
    /*This local variable stores the status of the corresponding channel */
    Lin_StatusType fl_LinIf_Local_Status;

    /*This local variable stores the datas of the corresponding channel */
    uint8 *fl_Lin_Sdu_Ptr = NULL;

    /* Check whether the direction of frame is receive or transmission*/
    if (Linif_SRF_Frame_Data_ptr->LinIfPduDirection == LinIfRxPdu)
    {
        /*Get Status channel from lin driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check the transmission status is ok or not ok*/
        if (fl_LinIf_Local_Status == LIN_RX_OK)
        {
            /*This function processes a received SRF containing transport protocol data.*/
                LinTp_RxIndication(Channel, fl_Lin_Sdu_Ptr); 

        }
        else
        { 
            /* RX_ERROR or BUSY */
            /** When the LIN Interface has determined the LIN Driver module’s status as LIN_RX_BUSY or LIN_RX_ERROR, 
                 *  the LIN Interface shall consider the received frame as lost. Therefore, the LIN Interface shall 
                 *  report the runtime error code LINIF_E_RESPONSE to the Default Error Tracer, if this frame is an unconditional frame. */

            /* When the LIN Interface has determined the LIN Driver module’s 
                   status as LIN_RX_NO_RESPONSE, the LIN Interface shall consider the 
                   expected frame as lost. Therefore, the LIN Interface shall report the 
                   runtime error code LINIF_E_RESPONSE to the Default Error Tracer, 
                   if this frame is an unconditional frame*/

                DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    
    else
    {
            /*Do nothing*/
    }
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_MRF_Frame_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @param LinIf_FrameType  Linif_MRF_Frame_Data_ptr - it's point to the frame for transmission.
/// @Description : This function processes the master frame transmission status
/// @return : Std_ReturnType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_MRF_Frame_Processing( const uint8 Channel, const LinIf_FrameType *Linif_MRF_Frame_Data_ptr)
{
    /*This local variable stores the status of the corresponding channel */
    Lin_StatusType fl_LinIf_Local_Status;

        /*This local variable stores the datas of the corresponding channel */
    uint8 *fl_Lin_Sdu_Ptr = NULL;

    LinTp_ControlType* tpCtrlTmp;

    tpCtrlTmp = LinTp_GetAddrCtrl(Channel);

    /* Check whether the direction of frame is receive or transmission*/
    if (Linif_MRF_Frame_Data_ptr->LinIfPduDirection == LinIfTxPdu)
    {
        /*Get Status channel from lin driver*/
        fl_LinIf_Local_Status = Lin_GetStatus(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &fl_Lin_Sdu_Ptr);

        /*Check the transmission status is ok or not ok*/
        if (fl_LinIf_Local_Status == LIN_TX_OK)
        {
            /*Post-processes the transmission of a MRF containing transport protocol data.*/
            LinTp_TxMessageProcessing(tpCtrlTmp,fl_LinIf_Local_Status);
        }
        else
        { 
            /* TX_ERROR or BUSY */
            DET_REPORT_ERROR(LINIF_MAINFUNCTION_SERVICE_ID, LINIF_E_RESPONSE);
        }
    }
    else
    {
        /*Do nothing*/
    }
}





//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Channel_MainFunction
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function main processing Functions for Individual Channels
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Channel_MainFunction( uint8 Channel)
{
        /*This local variables store entery datas of schedule table*/
    LinIfEntryType *fl_Linif_Tbl_Entry_ptr;

    /*This local variable store the details of Frame transmission*/
    LinIf_FrameType *fl_Linif_Frame_Data_ptr;

    /* This local variable store  current schedule table index  */
    uint16 fl_Linif_Schedule_Tbl_index_U16;


    #if ( LINIF_TP_SUPPORTED == STD_ON )
        LinTp_ControlType* tpCtrlTmp;
    #endif



    /** In the state LINIF_CHANNEL_OPERATIONAL, the LIN Interface shall process the currently 
     *  selected schedule table within the function 
     *  LinIf_MainFunction_<ChannelId> */
    if ((LinIf_ChannelData[Channel].Channel_Status == LINIF_CHANNEL_OPERATIONAL) && 
		(LinIf_SchedularEnableStatus[Channel] == TRUE))
    {
        /* Check if NULL schedule is present otherwise check status of last sent */
        if ((((LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution) == NULL) ||
             ((LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution->LinIfEntry) == NULL)) != TRUE)
        {
            /* Fetch current schedule table index  */
            fl_Linif_Schedule_Tbl_index_U16 = LinIf_ChannelData[Channel].CurrentScheduleTableIndex;
            /* Fetch current Table entry  */
            fl_Linif_Tbl_Entry_ptr = (LinIfEntryType *)(&LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution->LinIfEntry[fl_Linif_Schedule_Tbl_index_U16]);
            /* Get the Current Frame Details  */
            fl_Linif_Frame_Data_ptr = (LinIf_FrameType *)(fl_Linif_Tbl_Entry_ptr->LinIfFrameRef);

            if(fl_Linif_Frame_Data_ptr->LinIfFrameType == UNCONDITIONAL)
            {
                /*This function call processes the unconditional frame receive and transmission status*/
                LinIf_Unconditional_Frame_MessageProcessing(Channel,fl_Linif_Frame_Data_ptr);
            }
            else if (fl_Linif_Frame_Data_ptr->LinIfFrameType == EVENT_TRIGGERED)
            {
                /* This function call  processes the Event triggered frame receive and transmission status*/
                LinIf_EventTrigger_Frame_MessageProcessing(Channel,fl_Linif_Frame_Data_ptr);
            }
            else if ((fl_Linif_Frame_Data_ptr->LinIfFrameType == SPORADIC)&& (LinIf_Sporadic_Frame_Transmit_Status == (uint8)E_OK))
            {
                /*This function call processes the Sporadic frame receive and transmission status*/
                LinIf_Sporadic_Frame_MessageProcessing(Channel,fl_Linif_Frame_Data_ptr);
                
            }
            else if(fl_Linif_Frame_Data_ptr->LinIfFrameType == SRF)
            {
                    /* This function call processes the Slave response frame receive status*/
                    LinIf_SRF_Frame_Processing(Channel,fl_Linif_Frame_Data_ptr);
            }
            else if(fl_Linif_Frame_Data_ptr->LinIfFrameType == MRF)
            {
                /* This function call processes the master request frame receive status*/
                LinIf_MRF_Frame_Processing(Channel,fl_Linif_Frame_Data_ptr);
            }
            else
            {
                    /*Do Nothing*/
            }
            
            
            
        }
        else
        {
            /* Do nothing */
        }
        
    #if ( LINIF_TP_SUPPORTED == STD_ON )
        tpCtrlTmp = LinTp_GetAddrCtrl(Channel);
        LinTp_Timer_Handling(tpCtrlTmp);
    #endif

       /*Process the scheduling of  coresponding channel*/
        LinIf_Schedule_Processing(Channel);

    }
    else
    {
        /*Do Nothing*/
    }
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Schedule_Processing
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function  processing the Scheduling for corresponding  Channels
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Schedule_Processing( uint8 Channel)
{

    /*This local variable store the details of Frame transmission*/
    LinIf_FrameType Linif_FrameHandle_Data;

    /*This local variable store return status of schedule handler function call*/
    LinIf_ScheduleTableHandlerRetType       scheduleTableHandlerRetTmp;

    /*This local variable store transmit data for Lin driver*/
    Lin_PduType      linPduTmp;

    /*This local variable store the return status of function call"LinIf_Handle_NewFrameTransfer"*/
    Std_ReturnType      fl_FrameHandlerTmp_u8;

    /*This local variable store the return status of function call"Lin_SendFrame"*/
    Std_ReturnType fl_SendFrameStaus_u8;

    /*Check whether TP support is enabled or not*/
    #if ( LINIF_TP_SUPPORTED == STD_ON )
    LinTp_ControlType* tpCtrlTmp;
    #endif

      /*Initialize return value of send frame function call  as not OK*/
    fl_SendFrameStaus_u8 = E_NOT_OK;

    /*Initialize return value of new frame transfer function call  as not OK*/
    fl_FrameHandlerTmp_u8 = E_NOT_OK;
    /*Check whether TP support is enabled or not*/
    #if ( LINIF_TP_SUPPORTED == STD_ON )
    tpCtrlTmp = LinTp_GetAddrCtrl(Channel);
    LinTp_BufferPolling(tpCtrlTmp);
    #endif
    
    /*This function  processing the Schedule table handler for corresponding  Channels*/
    scheduleTableHandlerRetTmp = LinIf_ScheduleTable_Handler(&Linif_FrameHandle_Data,  Channel);

    /*Store check sum model type to transfer from lin interface to lin driver*/
    linPduTmp.Cs                              =  (Lin_FrameCsModelType)Linif_FrameHandle_Data.LinIfChecksumType;

    /*Store data length to transfer from lin interface to lin driver*/
    linPduTmp.Dl                              = (Lin_FrameDlType) Linif_FrameHandle_Data.LinIfLength;

    /*Check whether frame direction is transmission or receive*/
    if (Linif_FrameHandle_Data.LinIfPduDirection == LinIfTxPdu)
    {
       /*Store frame direction to transfer from lin interface to lin driver*/
        linPduTmp.Drc                       = (Lin_FrameResponseType)LIN_MASTER_RESPONSE;
    }
    else
    {
      /*Store frame direction to transfer from lin interface to lin driver*/
     linPduTmp.Drc                       = (Lin_FrameResponseType)LIN_SLAVE_RESPONSE;
    }

    /*Store protected identifier to transfer from lin interface to lin driver*/
    linPduTmp.Pid                             = (Lin_FramePidType) Linif_FrameHandle_Data.LinIfPid;

    /* set SDU pointer to a defined value, will be overwritten in case of Tx */
    linPduTmp.SduPtr                          = NULL_PTR; 

    /* Check the return status of schedule handler function call equal to new message*/
    if(scheduleTableHandlerRetTmp == LinIf_SchdlHdlrRet_NewMessage)
    {
        /*Check whether TP support is enabled or not*/
            #if ( LINIF_TP_SUPPORTED == STD_ON )

            /*Get data part of frame to transmit*/
            fl_FrameHandlerTmp_u8 = LinIf_Handle_NewFrameTransfer(&linPduTmp, &Linif_FrameHandle_Data, Channel, tpCtrlTmp);
            #else

            /*Get data part of frame to transmit*/
            fl_FrameHandlerTmp_u8 = LinIf_Handle_NewFrameTransfer(&linPduTmp, &Linif_FrameHandle_Data, Channel);

            #endif
    }
    else
    {
        /*Do Nothing*/
    }



    /* Check the return status of send frame  function call equal to status OK*/
    if(fl_FrameHandlerTmp_u8 == (Std_ReturnType)E_OK)
    {
	    if(linPduTmp.SduPtr == NULL_PTR)
		{
			linPduTmp.SduPtr = &RespData[0];
		}
       /* Invoke LIN driver to send/receive LIN Frame  */
        fl_SendFrameStaus_u8 =  Lin_SendFrame(LinIf_ConfigPtr->LinIfChannel[Channel].LinIfChannelId, &linPduTmp);
    }
    else
    {
       /*Do Nothing*/
    }



    /*To avoid compiler warning , below lines are added*/
    if(fl_SendFrameStaus_u8 == (Std_ReturnType)E_OK)
    {
        /*Do nothing*/
    }
            


}


//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTable_Handler
/// @param : uint8 Channel - Channel Id of the LIN module
/// @Description : This function  processing the Schedule table handler for corresponding  Channels
/// @return : LinIf_ScheduleTableHandlerRetType
///<br>
//---------------------------------------------------------------------------------------------------------------------
static LinIf_ScheduleTableHandlerRetType LinIf_ScheduleTable_Handler(LinIf_FrameType *Linif_Frame_Data_ptr,  uint8 Channel)
{
    
    /*This local variables store entery datas of schedule table*/
    LinIfEntryType *fl_Linif_Tbl_Entry_ptr;

     /*This variable stotre the run mode type of schedule table*/
    LinIfRunModeType schedRunMode;

    /*This local variable store the new message transmission status*/
    LinIf_ScheduleTableHandlerRetType retVal;

    /*This local variable store the delay between processing two frames*/
    uint16 fl_Linif_Get_NewDelay_U16;



    /* Check if NULL schedule is present otherwise check status of last sent */
    if (((LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution) == NULL) &&
         ((LinIf_ChannelData[Channel].New_ScheduleRequest) == LinIf_Schedule_Invalid)) 
    {
        /* set return status as null schedule table*/
        retVal = LinIf_SchdlHdlrRet_OnNullSchedule;
    }
    else
    {
        /*Check the  Current_DelayInTicks is greater than zero or not*/
        if (LinIf_ChannelData[Channel].Current_DelayInTicks > 0U)
        {
            /*Decreement the Current_DelayInTicks, Not time for sending yet */
            LinIf_ChannelData[Channel].Current_DelayInTicks--;
        }
        else
        {
            /* Do nothing */
        }
        
        /*Set return value as no new message start*/
         retVal   = LinIf_SchdlHdlrRet_NoNewMessage;

        /*Check whether the time delay is elapsed or not*/
        if (LinIf_ChannelData[Channel].Current_DelayInTicks == 0U)
        {
            /*Set return value as  new message start*/
            retVal     = LinIf_SchdlHdlrRet_NewMessage;
        }   
        /*Check whether new schedule request is received or not*/
        else if ( ( LinIf_ChannelData[Channel].IsNewScheduleRequestReceived == TRUE ) && ( LinIf_ChannelData[Channel].New_ScheduleRequest != LinIf_Schedule_Invalid )  ) 
        {
            /*Get the current schedule table run mode*/
            schedRunMode   = LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution->LinIfRunMode;

            /*Check whether the schedule table mode is run once and zero'th position index, or check whether schedule table mode is run continuous*/
            if ( (( schedRunMode == RUN_ONCE ) && ( LinIf_ChannelData[Channel].CurrentScheduleTableIndex == (uint8)0x00u )) ||
                ( schedRunMode == RUN_CONTINUOUS ) )
            {
                /*Set return value as  new message start*/
                retVal   = LinIf_SchdlHdlrRet_NewMessage;
            }
            else
            {
                /* Do nothing */
            }
                
        }
        else
        {
            /* Do nothing */
        }
        

        /*Check whether return value is equal to new message start or not */
        if ( retVal == LinIf_SchdlHdlrRet_NewMessage )
        {

            /* Update index after getting status of last frame */
            LinIf_ChannelData[Channel].CurrentScheduleTableIndex = (LinIf_ChannelData[Channel].CurrentScheduleTableIndex + 1U) % LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution->LinIfNofEntries;

                                
                /* Switch back to previous table if collision resolving table is run through */
            #if ( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            /*Check the current schedule table index as zero and collison schedule process is ongoing*/
            if((LinIf_ChannelData[Channel].CurrentScheduleTableIndex == 0)&&(LinIf_ChannelData[Channel].New_CollisonScheduleRequest_Status == LinIf_EvtCollResolvingState_OnResolving ))
            {
                 /* Collision resolving table is run through, so switch back to previous table */
                LinIf_ChannelData[Channel].CurrentScheduleTableIndex     = LinIf_ChannelData[Channel].Previous_ScheduleTableIndex; 

                /*Set collison schedule request status as idle*/
                LinIf_ChannelData[Channel].New_CollisonScheduleRequest_Status  = LinIf_EvtCollResolvingState_Idle; 
            }
            else
            {
                /* Do nothing */
            }
                        
            #endif

                
            /*  if NULL schedule table is requested, set it and quit, no further handling required */
            /*[SWS_LinIf_00444] ⌈If the LIN Interface’s environment is requesting a NULL_SCHEDULE (or set in case of
             initialization or sleep) the schedule table manager of the LIN Interface shall change to NULL_SCHEDULE when
              the next schedule entry is due (even if the current is RUN_ONCE).*/
            if ( LinIf_ChannelData[Channel].New_ScheduleRequest == LinIf_Schedule_NULL)
            {
                    /* switch to NULL schedule table */
                    LinIf_Reset_Schedule_Table(LinIf_ChannelData[Channel]); 

                    /* set return status as null schedule table*/
                    retVal  = LinIf_SchdlHdlrRet_OnNullSchedule;

                    /*Set new schedule request status as invalid*/
                    LinIf_ChannelData[Channel].New_ScheduleRequest = LinIf_Schedule_Invalid;

            }
            else
            {
                /*Process the run once schedule table finalization status*/
                LinIf_ScheduleTableHandler_RunOnceFinalization(&LinIf_ChannelData[Channel]); 

                /* If a new table is requested, perform the actual switch (if not a RUNONCE schedule is active) and notify the schedule change */
                LinIf_ScheduleTableHandler_RequestedTableSwitch( &LinIf_ChannelData[Channel], Channel); 
                
                /* If new table is NULL schedule table, reset frame delay and quit */
                if ( (LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution) == NULL  )
                {   
                    /* set return status as null schedule table*/
                    retVal     = LinIf_SchdlHdlrRet_OnNullSchedule;
                }
                else
                {

                    /* Fetch current Schedule Table entry  */
                    fl_Linif_Tbl_Entry_ptr = (LinIfEntryType *)(&LinIf_ChannelData[Channel].Current_ScheduleTable_InExecution->LinIfEntry[LinIf_ChannelData[Channel].CurrentScheduleTableIndex]);
                    
                    /* Get the Current Frame Details from Schedule table */
                    (void)memcpy(Linif_Frame_Data_ptr,fl_Linif_Tbl_Entry_ptr->LinIfFrameRef,sizeof(LinIf_FrameType));
                    //*Linif_Frame_Data_ptr =*(fl_Linif_Tbl_Entry_ptr->LinIfFrameRef);

                                                        
                    /* Set new delay */
                    /*[SWS_LinIf_00261] ⌈The delay between processing two frames shall be a multiple of the LIN Interface time-base (configuration parameter LinIfTimeBase).*/
                    fl_Linif_Get_NewDelay_U16 = fl_Linif_Tbl_Entry_ptr->LinIfDelay / LinIf_ConfigPtr->LinIfTimeBase;

                    /* LinIfDelay can be zero for the first frame on the table*/
                    LinIf_ChannelData[Channel].Current_DelayInTicks = (uint16)((fl_Linif_Get_NewDelay_U16 > 0U) ? (fl_Linif_Get_NewDelay_U16 - 1U) : 0U);
                    
                }
            }
        }
        else
        {
            /* Do nothing */
        }
        
        /*Below instruction only for avoid compiler warning*/
        LinIF_AvoidCompilerWarning_1 = Linif_Frame_Data_ptr;
            
    }

    return retVal;

}




#if ( LINIFCANCELTRANSMITSUPPORTED == STD_ON )
/*
*     Service name:       LinIf_CancelTransmit 
*     Service ID[hex]:    0x0c 
*     Parameters (in):    LinTxPduId
*     Parameters (inout): None 
*     Parameters (out):   None 
*     Return value:       Std_ReturnType E_NOT_OK: Cancel Transmit request has not been accepted. 
*/  
Std_ReturnType LinIf_CancelTransmit( PduIdType LinTxPduId )
{
/*As per 4.2.1 spec requirement[SWS_LinIf_00649] ⌈The cancellation request shall always be rejected by returning E_NOT_OK. ⌋ ()*/

    Std_ReturnType    retVal;
    retVal = E_NOT_OK;

    return retVal;

}
#endif



/*--------------------------------------------------------------------------------------------------------
* 
* Service name:    LinIf_Transmit
* Syntax:          Std_ReturnType LinIf_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr )
* Service ID[hex]: 0x04
*  Sync/Async:     Asynchronous 
* Reentrancy:      Non Reentrant 
* Parameters (in): LinTxPduId -  Upper layer identification of the LIN frame to be transmitted (not the LIN protected ID).
*                                  This parameter is used to determine the corresponding LIN protected ID (PID) and implicitly the 
*                                LIN Driver instance    as well as the corresponding LIN Controller device. 
*                   PduInfoPtr  - Pointer to a structure with frame related data: DLC and pointer to frame data buffer. 
*                               This parameter is not used by this call. 
*  Parameters (inout): None
*  Parameters (out):   None
*  Return value:      Std_ReturnType   - E_OK: Transmit request has been accepted. 
*                                      -  E_NOT_OK: Transmit request has not been accepted due to one or more of the following reasons: 
*                                      - LIN Interface has not been initialized 
*                                      - referenced PDU does not exist (identification is out of range) 
*                                      - NULL_SCHEDULE is set 
*  Description:       Indicates a request.
*----------------------------------------------------------------------------------------------------------------------*/
Std_ReturnType LinIf_Transmit( PduIdType LinTxPduId, const PduInfoType* PduInfoPtr )
{

    Std_ReturnType    retVal;

    retVal  = (Std_ReturnType)E_NOT_OK;

      /* this feature is not included  due to  disable of Sporadic frame   */
    #if(LINIF_SPORADIC_FRAME_SUPPORT == STD_ON) 

    /*Check whether the development error is enabled or disabled*/
    #if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    uint8             errorId;
    #endif

    uint8     indexTmp;
  


    /* ----- Development Error Checks ------------------------------------- */

    /*Check whether the development error is enabled or disabled*/
    #if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*Initialize error iD as No error*/
    errorId = LINIF_E_NO_ERROR;

    #endif
#if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*  Check if component is initialized */
    if ( LinIf_GlobalStatus != LINIF_INITIALIZATION )
    {
      /*Initialize error ID as lin interface as un initialize status*/
        errorId = LINIF_E_UNINIT;
    }
    /*  Check validity of parameter PduInfoPtr */
    else if ( PduInfoPtr == NULL_PTR )
    {
        /*Initialize error ID as Invalid parameter pointer*/
        errorId = LINIF_E_PARAMETER_POINTER;
    }
    /*  Check validity of parameter LinTxPduId */
    else if ( LinTxPduId >= TOTAL_NO_OF_UNCONDITIONAL_FRAME )
    {
      /*Initialize error ID as Invalid parameter */
        errorId = LINIF_E_PARAMETER;
    }
    else
    #endif

    {
   
    /*  Search all sporadic frames for the one with given LinTxPduId and set its transmission bit flag */

        if ( 0u != LINIF_NUMBER_OF_SPORADIC_FRAME ) 
        { /* sporadic frames exist in current configuration */
          /* search all entries of SporadicFrameLookupTable for the entry with the given PduId */
            for (indexTmp = 0; indexTmp < LINIF_NUMBER_OF_SPORADIC_FRAME; indexTmp++)
            {
              /*Check the TxPduID is valid or not*/
                if ( LinIf_GetTxPduIdOfSporadicFrameLookupTable(indexTmp) == LinTxPduId )
                { 
                    /* LinTxPduId matches - set transmit request flag */
                    /*[SWS_LinIf_00470] ⌈The LIN Interface shall flag the specific sporadic frame (defined in the LIN 2.1 specification) for transfer. ⌋*/
                      SporadicFrame_Flag[indexTmp] = 1;

                      /*Set return value AS Ok*/
                      retVal = E_OK;
                      break; /* quit search */
                }
                else
                {
                    /*Do Nothing*/
                }
            }
        }
        else
        {
            /*Do nothing*/
        }


    /*  Set the return value to E_OK if LinTxPduId is valid */
    /* E_NOT_OK shall only be returned if LinIf is not initialized or referenced PDU does not exist (identification is out of range) */
    /* That means E_OK should also be returned for non-sporadic frames */
#if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      if ( errorId != LINIF_E_NO_ERROR )
      {
          /*Report a error to det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_TRANSMIT, errorId);
      }
      else
      {
          /* Do nothing */
      }
#endif
    }

#endif

    return(retVal);
}



#if ( LINIF_TRANCEIVER_DRIVER_SUPPORTED == STD_ON )
/*
* Service name:         LinIf_GetTrcvWakeupReason 
* Syntax:                Std_ReturnType LinIf_GetTrcvWakeupReason( NetworkHandleType Channel, LinTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr )
* Service ID[hex]:        0x0a
* Sync/Async:           Synchronous 
*  Reentrancy:           Reentrant 
* Parameters (in):       Channel - Identification of the LIN channel 
* Parameters (inout):    None 
* Parameters (out):      TrcvWuReasonPtr - Pointer to a memory location where output value will be stored.
* Return value: -        Std_ReturnType - E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK. 
 *                                        E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or
 *                                         channel parameter is invalid or pointer is NULL.
* Description:      Returns the reason for the wake up that has been detected by the LIN Transceiver Driver.
*/
Std_ReturnType LinIf_GetTrcvWakeupReason( NetworkHandleType Channel, LinTrcv_TrcvWakeupReasonType* TrcvWuReasonPtr )
{

     /* ----- Local Variables ---------------------------------------------- */

    Std_ReturnType     retVal;

    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    LinTrcv_TrcvModeType                                            transceiverModePtr;
    Std_ReturnType                                                  retTrcvMode;
    uint8                                                           errorId;
    # endif

    /*In default , assign Return value as Not OK*/
    retVal  = (Std_ReturnType)E_NOT_OK;

    /* ----- Development Error Checks ------------------------------------- */
    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*In default , Assign Error ID as No reeor */
    errorId = LINIF_E_NO_ERROR;
    #endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* Check if component is initialized */
    if ( LinIf_GlobalStatus != LINIF_INITIALIZATION )
    {
        /*Assign Error iD as Un initialization state*/ 
        errorId = LINIF_E_UNINIT;
    }
    /*  Check validity of parameter Channel */
    else if ( Channel >= LINIF_NUMBER_OF_CHANNELS )
    {
      /*Assign Error ID as Non Exsisting hannel*/
        errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
    /*  Check validity of parameter TrcvWuReasonPtr */
    else if ( TrcvWuReasonPtr == NULL_PTR )
    {
      /*Assign Erro ID as Invalid Parameter*/
        errorId = LINIF_E_PARAMETER_POINTER;
    }
    else
    # endif
    {
        # if ( LINIF_DEV_ERROR_DETECT == STD_ON )

        /*  Check if transceiver is in normal mode */
        retTrcvMode = LinIf_GetTrcvMode(Channel, &transceiverModePtr); 

        /*Check whether the Transceiver mode id Normal or Sleep*/
        if ( (retTrcvMode == E_OK) && (transceiverModePtr != LINTRCV_TRCVMODE_NORMAL) )
        {
          /*If Transceiver mode is not in normal mode, assign error ID as LINIF_E_TRCV_NOT_NORMAL*/ 
            errorId = LINIF_E_TRCV_NOT_NORMAL;
        }
        else
    # endif
        {

            /*Get Bus Wakeup reasons from Lin Transceiver Layer*/
            retVal  = LinTrcv_GetBusWuReason(Channel, TrcvWuReasonPtr);
        }
      
    }
  

    /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if ( errorId != LINIF_E_NO_ERROR )
    {
      /*Report a Error to Det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_GETTRCVWAKEUPREASON, errorId);
    }
    else
    {
      /* Do nothing */
    }
  
# endif

    return retVal;
}

#endif/*LinIfTrcvDriverSupported == STD_ON */



#if ( LINIF_TRANCEIVER_DRIVER_SUPPORTED == STD_ON )
/*
* Service name: LinIf_SetTrcvWakeupMode 
* Syntax: Std_ReturnType LinIf_SetTrcvWakeupMode( NetworkHandleType Channel,
* LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode ) 
* Service ID[hex]: 0x0b 
* Sync/Async: Synchronous
* Reentrancy: Reentrant
*  Parameters (in): Channel - Identification of the LIN channel
*                   LinTrcvWakeupMode - Requested transceiver wake up reason.
*  Parameters (inout): None 
*  Parameters (out): None
*   Return value:  Std_ReturnType E_OK: The call of the LIN Transceiver Driver's API service has returned E_OK.
*                                E_NOT_OK: The call of the LIN Transceiver Driver's API service has returned E_NOT_OK or channel or mode parameter is invalid.
*  Description: This API enables, disables and clears the notification for wakeup events on the addressed network
*/
Std_ReturnType LinIf_SetTrcvWakeupMode( NetworkHandleType Channel,LinTrcv_TrcvWakeupModeType LinTrcvWakeupMode )

{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType                              retVal;

    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    uint8                                       errorId;
    # endif

    /*In default , assign Return value as Not OK*/
    retVal  = (Std_ReturnType)E_NOT_OK;

    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*In default , Assign Error ID as No reeor */
    errorId = LINIF_E_NO_ERROR;
    # endif

    /* ----- Development Error Checks ------------------------------------- */
    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*  Check if component is initialized */
    if ( LinIf_GlobalStatus != LINIF_INITIALIZATION )
    {
     /*Assign Error iD as Un initialization state*/ 
        errorId = LINIF_E_UNINIT;
    }
    /*  Check validity of parameter Channel */
    else if ( Channel >= LINIF_NUMBER_OF_CHANNELS )
    {
       /*Assign Error ID as Non Exsisting hannel*/
        errorId = LINIF_E_NONEXISTENT_CHANNEL;
    }
    /* Check validity of parameter LinTrcvWakeupMode */

    else if ( !((LinTrcvWakeupMode == LINTRCV_WUMODE_ENABLE) || (LinTrcvWakeupMode == LINTRCV_WUMODE_DISABLE) || (LinTrcvWakeupMode == LINTRCV_WUMODE_CLEAR)) )
    { 
        /*Assign Erro ID as Invalid Parameter*/
        errorId = LINIF_E_PARAMETER;
    }
    else
# endif
    {
       /*Set Wakeup Up Mode on Lin Transceiver */
        retVal      = LinTrcv_SetWakeupMode(Channel, LinTrcvWakeupMode); 
      

    }

    /* ----- Development Error Report --------------------------------------- */
    # if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if ( errorId != LINIF_E_NO_ERROR )
    {
       /*Report a Error to Det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_SETTRCVWAKEUPMODE, errorId);
    }
    else
    {
      /*Do nothing*/
    }
    # endif

    return retVal;
} 
#endif/*LinIfTrcvDriverSupported == STD_ON */



#if ( LINIF_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  LinIf_GetVersionInfo()
 **********************************************************************************************************************/
/*!
Service name: LinIf_GetVersionInfo 
 Service ID[hex]: 0x03 
 Sync/Async: Synchronous
 Reentrancy: Reentrant
Parameters (in): None 
Parameters (inout): None
 Parameters (out): versioninfo Pointer to where to store the version information of this module. 
 Return value: None 
 Description: Returns the version information of this module.
 */
void LinIf_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
    
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* ----- Local Variables ---------------------------------------------- */
    uint8                                                errorId;

    /* ----- Development Error Checks ------------------------------------- */
    /*In default , Assign Error ID as No reeor */

    errorId = LINIF_E_NO_ERROR;
# endif


    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /* Check validity of parameter versioninfo.  */
    if ( versioninfo == NULL_PTR )
    {
        /*Assign Erro ID as Invalid Parameter*/
        errorId = LINIF_E_PARAMETER_POINTER;
    }
    else
    # endif
    {
        /* ----- Implementation ----------------------------------------------- */
        /*  Set versioninfo parameter with component information */
        versioninfo->vendorID           = (uint16)LINIF_VENDOR_ID; 
        versioninfo->moduleID           = (uint16)LINIF_MODULE_ID; 
        versioninfo->sw_major_version   = (uint8)LINIF_SW_MAJOR_VERSION; 
        versioninfo->sw_minor_version   = (uint8)LINIF_SW_MINOR_VERSION; 
        versioninfo->sw_patch_version   = (uint8)LINIF_SW_PATCH_VERSION; 
    }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if ( errorId != LINIF_E_NO_ERROR )
    {
       /*Report a Error to Det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_GETVERSIONINFO, errorId);
    }
    else
    {
        /*Do nothing*/
    }
  
# endif
}
#endif /*LinIfVersionInfoApi == STD_ON */



/***********************************************************************************************************************
 *  LinIf_WakeupConfirmation()
 ********************************************************************************************************************
* Service name:LinIf_WakeupConfirmation 
* Syntax: void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource ) 
* Service ID[hex]:0x61 
* Sync/Async: Synchronous 
* Reentrancy:Reentrant 
* Parameters (in): WakeupSource Source device which initiated the wakeup event: LIN controller or LIN transceiver 
*  Parameters (inout): None 
* Parameters (out): None 
* Return value: None 
*  Description: The LIN Driver or LIN Transceiver Driver will call this function to report the wake up source after the successful wakeup detection during CheckWakeup or after power on by bus.
 */
void LinIf_WakeupConfirmation( EcuM_WakeupSourceType WakeupSource )
{

/*Check Whether the Lin Driver Wakeup support or Lin Transceiver wakeup support is enabled or not*/
#if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
  /* ----- Local Variables ---------------------------------------------- */

# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    uint8                                                 wakeupsourceFound;
    uint8                                                 errorId;
# endif
    uint8                                                 indexTmp;

# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*In default, set wakeup source found as Zero*/
    wakeupsourceFound = 0;

    /*In default , Assign Error ID as No reeor */
    errorId           = LINIF_E_NO_ERROR;
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /*  Check if Lin IF layer  is initialized */
    if ( LinIf_GlobalStatus == LINIF_UNINIT )
    {
       /*Assign Error iD as Un initialization state*/ 
        errorId = LINIF_E_UNINIT;
    }
    else
# endif
    {
        /* ----- Implementation ----------------------------------------------- */
        /*  Check for each LinIf channel if given wakeup source is configured for this channel */
        for (indexTmp = 0; indexTmp < LINIF_NUMBER_OF_CHANNELS; indexTmp++)
        {
          /*  If wakeup source belongs to a Lin (driver) channel, set the external wakeup flag for the identified channel */
    # if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON )
            if ( (Lin_LinChannel_0_PC.LinChannelEcuMWakeupSource & WakeupSource) != (EcuM_WakeupSourceType)0x00u)
            {
                /*Set wake up flag as wakeup occurred*/
                /*[SWS_LinIf_00716] ⌈The function LinIf_WakeupConfirmation shall set the wakeup flag for the channel depending on the given parameter WakeupSource.
                The wakeup flags shall be provided for each channel.*/
                LinIf_ChannelData[indexTmp].LinIf_WakeupFlag = LINIF_WAKEUP_OCCURRED; 
            
                #  if ( LINIF_DEV_ERROR_REPORT == STD_ON )

                /*Set wakeup source found as One*/
                wakeupsourceFound = 1;
                #  endif
            } 
            else
            {
              /* Do nothing */
            }
          
    # endif

    # if ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
            /*  If wakeup source belongs to a Lin transceiver channel, set the external wakeup flag for the identified channel */
            if ( (LinTrcv_WakeSourceId[indexTmp] & WakeupSource) != (EcuM_WakeupSourceType)0x00u)
            {
                /*Set wake up flag as wakeup occurred*/
                /*[SWS_LinIf_00716] ⌈The function LinIf_WakeupConfirmation shall set the wakeup flag for the channel depending on the given parameter WakeupSource.
                The wakeup flags shall be provided for each channel.*/
                LinIf_ChannelData[indexTmp].LinIf_WakeupFlag = LINIF_WAKEUP_OCCURRED; 
            
    #  if ( LINIF_DEV_ERROR_REPORT == STD_ON )

                /*Set wakeup source found as One*/
                wakeupsourceFound = 1;
    #  endif
            }
            else
            {
                /* Do nothing */
            } 
          
    # endif
        }


    }

    /*  If wakeup source does not belong to any Lin channel: report error */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if (wakeupsourceFound == 0)
    {
        /*API service called with invalid parameter for WakeupSource*/
        errorId = LINIF_E_PARAM_WAKEUPSOURCE;
    }
    else
    {
        /* Do nothing */
    }
    
# endif
  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if ( errorId != LINIF_E_NO_ERROR )
    {
       /*Report a Error to Det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_WAKEUPCONFIRMATION, errorId);
    }
    else
    {
      /* Do nothing */
    }
  
# endif
#endif
}



/*Check Whether the Lin Driver Wakeup support or Lin Transceiver wakeup support is enabled or not*/
#if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
/***********************************************************************************************************************
 *  LinIf_CheckWakeup()
 **********************************************************************************************************************
* Service name: LinIf_CheckWakeup 
* Syntax: Std_ReturnType LinIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource ) 
* Service ID[hex]: 0x60
*   Sync/Async: Synchronous
*    Reentrancy: Reentrant 
*    Parameters (in): WakeupSource - Source device, which initiated the wakeup event: LIN controller or LIN transceiver
*  Parameters (inout): None
* Parameters (out): None
*  Return value: Std_ReturnType  E_OK: No error has occurred during execution of the API 
*                               E_NOT_OK: An error has occurred during execution of the API or invalid WakeupSource 
* Description: Will be called when the EcuM has been notified about a wakeup on a specific LIN channel.
 */
Std_ReturnType LinIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType     retVal;
    uint8      linIfChannelLoopIndex;

    /* ----- Development Error Checks ------------------------------------- */
    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    uint8       errorId;
    #endif

    /*In default , assign Return value as Not OK*/
    retVal    = (Std_ReturnType)E_NOT_OK;

    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*In default , Assign Error ID as No reeor */
    errorId    = LINIF_E_NO_ERROR;
    #endif

  /* ----- Development Error Checks ------------------------------------- */
    # if ( LINIF_DEV_ERROR_DETECT == STD_ON )
    /*  Check if component is initialized */
    if ( LinIf_GlobalStatus == LINIF_UNINIT )
    {
      /*Assign Error iD as Un initialization state*/ 
        errorId = LINIF_E_UNINIT;
    }
    else
    # endif
    {
        /* ----- Implementation ----------------------------------------------- */
        /*  Check for each LinIf channel if given wakeup source is configured for this channel */
        for (linIfChannelLoopIndex = 0; linIfChannelLoopIndex < LINIF_NUMBER_OF_CHANNELS; linIfChannelLoopIndex++)
        {
            /*Check Whether the Lin Driver Wakeup support  is enabled or not*/
            # if ( LINIF_LIN_CHANNEL_WAKEUP_SUPPORT == STD_ON )
            /*  If wakeup source belongs to LIN driver module, call Lin_CheckWakeup for the identified channel */
            if ( (Lin_LinChannel_0_PC.LinChannelEcuMWakeupSource & WakeupSource) != (EcuM_WakeupSourceType)0x00u)
            {

                /*Check Whether the Lin multiple Driver  support  is enabled or not*/
                #  if ( LINIF_MULTIPLE_DRIVER_SUPPORTED == STD_ON )
                        /*Do nothing*/
                #  else
                    /*Call the API Lin_CheckWakeup from Lin Driver */
                (void) Lin_CheckWakeup(linIfChannelLoopIndex);
                #  endif
        /*Assing Return value as E_OK*/
                retVal = (Std_ReturnType)E_OK;
            }
            # endif

            /*Check Whether the  Lin Transceiver wakeup support is enabled or not*/
            # if ( LINIF_LINTRCV_WAKEUP_SUPPORT == STD_ON )
            /*  If wakeup source belongs to a LIN transceiver, call LinTrcv_CheckWakeup for the identified transceiver and channel */
            if ( (LinTrcv_WakeSourceId[linIfChannelLoopIndex] & WakeupSource) != (EcuM_WakeupSourceType)0x00u)
            {
                /*Call LinTrcv_CheckWakeup from Lin transceiver layer*/
                retVal = (Std_ReturnType)E_OK;
            }
            else
            {
              /* Do nothing */
            }
      
            # endif
        }

    /*  If wakeup source does not belong to any Lin channel: report error */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
        if (retVal != E_OK)
        {
            /*API service called with invalid parameter for WakeupSource*/
            errorId = LINIF_E_PARAM_WAKEUPSOURCE;
        }
# endif
    }

  /* ----- Development Error Report --------------------------------------- */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
    if ( errorId != LINIF_E_NO_ERROR )
    {
       /*Report a Error to Det module*/
        (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINIF_SID_CHECKWAKEUP, errorId);
    }
    else
    {
      /* Do nothing */
    }
  
# endif

    return retVal;
}
#endif



//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_Reset_Schedule_Table
/// @param : LinIf_ChannelDataType LinIf_SchedTabDataPtr - Current execution schedule table
/// @Description : This function  Reset  the Schedule table 
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
static void LinIf_Reset_Schedule_Table(LinIf_ChannelDataType LinIf_SchedTabDataPtr)
{
    /*  Reset all schedule table related variables, set NULL schedule table, abort collision resolving table */
    LinIf_SchedTabDataPtr.Current_ScheduleTable_InExecution              = NULL; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */
    LinIf_SchedTabDataPtr.Previous_ScheduleTable_InExecution               = NULL; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */
    LinIf_SchedTabDataPtr.CurrentScheduleTableIndex   = (uint16)0x00u; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */
    LinIf_SchedTabDataPtr.Previous_ScheduleTableIndex    = (uint16)0x00u; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */
    LinIf_SchedTabDataPtr.New_ScheduleRequest            = LinIf_Schedule_Invalid; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */

    #if ( LINIF_EVT_FRM_SUPPORTED == STD_ON )
    LinIf_SchedTabDataPtr.New_CollisonScheduleRequest_Status     = LinIf_EvtCollResolvingState_Idle; /* SBSW_LINIF_FLUSHALLSCHED_SCHED_DATA_PTR */
    #endif

    LinIf_AvoidCompilerWarning = LinIf_SchedTabDataPtr;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTableHandler_RunOnceFinalization
/// @param : LinIf_ChannelDataType LinIf_SchedTabData - Current execution schedule table
/// @Description :   If schedule table is RUN ONCE,perform the actual switch  and notify the schedule change 
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
    
static void  LinIf_ScheduleTableHandler_RunOnceFinalization(LinIf_ChannelDataType *LinIf_SchedTabData  )
{
  /* ----- Implementation ----------------------------------------------- */
  /*  If current schedule table is of type run-once and run through */
    if ( ( LinIf_SchedTabData->Current_ScheduleTable_InExecution->LinIfRunMode == RUN_ONCE ) &&
       ( LinIf_SchedTabData->CurrentScheduleTableIndex == (uint8)0x00u ) )
    {
        /* Current table is run once and table is all run through */

        /*  Change to to last continuous schedule table and saved resume slot 

        *[SWS_LinIf_00397] ⌈The LIN Interface shall perform the latest requested schedule table of the type RUN_CONTINUOUS
         if no further schedule requests are left to be served after a RUN_ONCE schedule table.*/

        LinIf_SchedTabData->Current_ScheduleTable_InExecution  = LinIf_ChannelData->Previous_ScheduleTable_InExecution;

        /*[SWS_LinIf_00485] ⌈The definition where the execution of a schedule table shall be proceeded in case it has been interrupted by a table of the
         type RUN_ONCE shall be configurable by the configuration parameter LinIfResumePosition. ⌋*/

        if ( LinIf_SchedTabData->Previous_ScheduleTable_InExecution->LinIfResumePosition == CONTINUE_AT_IT_POINT )
        {
          /* Start from interrupted slot */
            LinIf_SchedTabData->CurrentScheduleTableIndex = LinIf_ChannelData->Previous_ScheduleTableIndex;
        }
        else
        {
          /* Start from beginning slot */
            LinIf_SchedTabData->CurrentScheduleTableIndex = 0;
        }

    }
    else
    {
      /*Do Nothing*/
    }
  
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief : LinIf_ScheduleTableHandler_RequestedTableSwitch
/// @param : LinIf_ChannelDataType LinIf_SchedTabData - Current execution schedule table
/// @Description :  If a new table is requested, perform the actual switch (if not a RUNONCE schedule is active) and notify the schedule change 
/// @return : void
///<br>
//---------------------------------------------------------------------------------------------------------------------
/*  If a new table is requested, perform the actual switch (if not a RUNONCE schedule is active) and notify the schedule change */
static void   LinIf_ScheduleTableHandler_RequestedTableSwitch(LinIf_ChannelDataType *LinIf_SchedTabData, uint8 Channel)
{
    if ( LinIf_SchedTabData->New_ScheduleRequest != LinIf_Schedule_Invalid )
    {
       
        /* If current active table is of type run-continuous */
        /*[SWS_LinIf_00028] ⌈The LIN Interface shall select a new schedule table for execution during the next schedule entry 
        if the current schedule is RUN_CONTINUOUS. ⌋*/
        if ( LinIf_SchedTabData->Current_ScheduleTable_InExecution->LinIfRunMode == RUN_CONTINUOUS )
        {
            /* #30 A normal continuous table is active, switch to requested schedule */
            if (( LinIf_ConfigPtr->LinIfChannel[Channel].LinIfScheduleTable[LinIf_SchedTabData->New_ScheduleRequest].LinIfRunMode == RUN_ONCE )&&(LinIf_SchedTabData->New_CollisonScheduleRequest_Status != LinIf_EvtCollResolvingState_Detected))
            { /* If requested table is a run-once table, save position of current table */
                LinIf_SchedTabData->Previous_ScheduleTable_InExecution = LinIf_SchedTabData->Current_ScheduleTable_InExecution;
                LinIf_SchedTabData->Previous_ScheduleTableIndex = LinIf_SchedTabData->CurrentScheduleTableIndex;
            }
#if ( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            else if ( LinIf_SchedTabData->New_CollisonScheduleRequest_Status == LinIf_EvtCollResolvingState_Detected )
            { 
                /*  If new table is a collision resolving schedule, save position of current table */
                /*[SWS_LinIf_00176] ⌈The LIN Interface shall switch to the given collision resolving schedule table at the end of the
                current frame slot after a collision has been detected. ⌋*/
                LinIf_SchedTabData->Previous_ScheduleTable_InExecution = LinIf_SchedTabData->Current_ScheduleTable_InExecution;
                LinIf_SchedTabData->Previous_ScheduleTableIndex = LinIf_SchedTabData->CurrentScheduleTableIndex;
                LinIf_SchedTabData->New_CollisonScheduleRequest_Status     = LinIf_EvtCollResolvingState_OnResolving; 
            }
#endif    
            else
            {
                /* MISRA only */
            }

            LinIf_SchedTabData->Current_ScheduleTable_InExecution = (LinIf_ScheduleTableType *)(&LinIf_ConfigPtr->LinIfChannel[Channel].LinIfScheduleTable[LinIf_SchedTabData->New_ScheduleRequest]);
            LinIf_SchedTabData->CurrentScheduleTableIndex = 0;

             /*[SWS_LinIf_00495] ⌈If the switch from one schedule table to another schedule table has been performed, 
                the schedule table manager shall call the function <User>_ScheduleRequestConfirmation. ⌋*/
            LinSM_ScheduleRequestConfirmation(Channel,LinIf_ChannelData[Channel].New_ScheduleRequest);

            /* schedule table change handled, remove request */
            LinIf_SchedTabData->New_ScheduleRequest              = LinIf_Schedule_Invalid; 

        }
        /*  If current active table is of type run-continuous */
        /*[SWS_LinIf_00393] ⌈The LIN Interface shall execute a schedule table of the type RUN_ONCE from the first entry
         to the last entry before changing to a new schedule table. But, if a collision occurs in an event-triggered frame 
         response, the LIN Interface shall switch to a collision resolving schedule table according to SWS_LinIf_00176.*/
        else if ( LinIf_SchedTabData->Current_ScheduleTable_InExecution->LinIfRunMode == RUN_ONCE )
        {

            #if ( LINIF_EVT_FRM_SUPPORTED == STD_ON )
            if ( LinIf_SchedTabData->New_CollisonScheduleRequest_Status == LinIf_EvtCollResolvingState_Detected )
            { /*  If new table is a collision resolving schedule, save position of current table */

                      /*[SWS_LinIf_00176] ⌈The LIN Interface shall switch to the given collision resolving schedule table at the end of the
                  current frame slot after a collision has been detected. ⌋*/   

                LinIf_SchedTabData->Previous_ScheduleTable_InExecution = LinIf_SchedTabData->Current_ScheduleTable_InExecution;
                LinIf_SchedTabData->Previous_ScheduleTableIndex = LinIf_SchedTabData->CurrentScheduleTableIndex;
                LinIf_SchedTabData->New_CollisonScheduleRequest_Status     = LinIf_EvtCollResolvingState_OnResolving; 
            }
            else
            {
                    /* Do nothing */
            }
            #endif
            LinIf_SchedTabData->Current_ScheduleTable_InExecution = (&LinIf_ConfigPtr->LinIfChannel[Channel].LinIfScheduleTable[LinIf_SchedTabData->New_ScheduleRequest]);
            LinIf_SchedTabData->CurrentScheduleTableIndex = 0;

            /*[SWS_LinIf_00495] ⌈If the switch from one schedule table to another schedule table has been performed, 
            the schedule table manager shall call the function <User>_ScheduleRequestConfirmation. ⌋*/
            LinSM_ScheduleRequestConfirmation(Channel,LinIf_ChannelData[Channel].New_ScheduleRequest);

            /* schedule table change handled, remove request */
            LinIf_SchedTabData->New_ScheduleRequest              = LinIf_Schedule_Invalid; 

        }
        else
        {
            /*Do Nothing*/
        }

    /* else : currently a run once table is active which is not run through yet so wait until table end */
    }
    else
    {
      /*Do Nothing*/
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
**============================================================================

**============================================================================
**Date               : 24-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update Schedule Table processing and Implement a Event 
                        triggered and Sporadic Frame
                        
**============================================================================

**============================================================================
**Date               : 10-APRIL-2019
**CDSID              : MKANNAN2
**Traceability       : RTC 
**Change Description :  Update Schedule Table against more than one Frames
                        Implement a API's LinIf_GetTrcvWakeupReason,LinIf_SetTrcvWakeupMode,LinIf_CancelTransmit
                         LinIf_CheckWakeup,LinIf_WakeupConfirmation
**============================================================================
**============================================================================
**Date               : 15-Oct-2019
**CDSID              : ABAVALAT
**Traceability       : RTC 
**Change Description : Include Header file LinSm_Cbk.h
**                     Updated LinSM_ScheduleRequestConfirmation. 
**                     Changed function name LinTrcv_NCV_7321_GetOpMode to
**                     LinTrcv_GetOpMode
**============================================================================
**============================================================================
**Date               : 11-Sep-2019
**CDSID              : ABAVALAT
**Traceability       : RTC #11365080
**Change Description : Include Header file LinNm_Cbk.h
**============================================================================
**============================================================================
**Date               : 04-SEP-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1352138 and 1352141 
**Change Description : 1. Added File Descriptions
                       2. Added Function descriptions for all the functions
                       3. Converted all the decimal constants to hexadecimal constants.
                       4. Changed Name of the Validate Macro Functions to LINIF_ERRORWRAPPER
                       5. Changed Macro Name MODULE_ID_LINIF to LINIF_MODULE_ID
                       6. Changed all the local variables proper naming conventions
                       7. Removed all the commented code sections which are not used
**============================================================================
**============================================================================
**Date               : 26-July-2019
**CDSID              : BPANNEER
**Traceability       : RTC #1285296
**Change Description : Initial Version.
**============================================================================*/
