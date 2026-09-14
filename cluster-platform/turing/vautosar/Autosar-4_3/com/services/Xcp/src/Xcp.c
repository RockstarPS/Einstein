/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!******************************************************************************************************************
*   @file Xcp.c
*   @ingroup Xcp
*   @brief This file provides the implemetation of Xcp as per AUTOSAR 4.3.
*   @defgroup Xcp
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Xcp.h"
#include "Xcp_Internal.h"
#include "Xcp_StdCmd.h"
#include "Xcp_CalibCmd.h"
#include "Xcp_DaqCmd.h"
#include "Xcp_PagCmd.h"
#include "Xcp_PgmCmd.h"
#if (XCP_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((XCP_SW_MAJOR_VERSION != XCP_CFG_SW_MAJOR_VERSION) || \
    (XCP_SW_MINOR_VERSION != XCP_CFG_SW_MINOR_VERSION) || \
    (XCP_SW_PATCH_VERSION != XCP_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((XCP_AR_RELEASE_MAJOR_VERSION != XCP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (XCP_AR_RELEASE_MINOR_VERSION != XCP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (XCP_AR_RELEASE_REVISION_VERSION != XCP_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  #! Feature validation check                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  #! PRIVATE MACRO DEFINITIONS                                                                                     *
********************************************************************************************************************/
#if (XCP_DEV_ERROR_DETECT == STD_ON)
#define Xcp_DetReportError(ApiId,ErrId) (void)Det_ReportError(XCP_MODULE_ID,XCP_INSTANCE_ID,(ApiId),(ErrId))
#else
#define Xcp_DetReportError(ApiId,ErrId)
#endif
/*! @brief Defines the size of the Xcp command processor function list */
#define XCP_CMD_PROCESSOR_FUNC_LIST_SIZE  64U
/*! @brief Macro to get the xcp command processor function from the list */
#define Xcp_GetCmdProcessorFunction(x)  (Xcp_CmdProcessorFuncList[(x)])

/********************************************************************************************************************
*  #! PRIVATE TYPE DECLARATION                                                                                      *
********************************************************************************************************************/
/* !@brief Defines the type for the xcp command processor function type */
typedef P2FUNC(void,XCP_CODE,Xcp_CmdProcessorFuncType)
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);
/********************************************************************************************************************
*  #! PRIVATE FUNCTION PROTOTYPES                                                                                   *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief  This API is used to process the STIM event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] Daq DAQ id value 
*   @param[in] Action event action value
*   @return Status for the event request 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessStimEventStatus(Xcp_ChannelType XcpChannel, uint16 Daq, uint8 Action);
/*!******************************************************************************************************************
*   @brief  This API is used to process DAQ event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] DaqListIdx DAQ list id value 
*   @return Status for the DAQ event  
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessEventDaq(Xcp_ChannelType XcpChannel,uint16 DaqListIdx );
/*!******************************************************************************************************************
*   @brief  This API is used to process STIM event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] DaqListIdx DAQ list id value 
*   @return Status for the STIM event  
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessEventStim( Xcp_ChannelType XcpChannel, uint16 DaqListIdx );
/*!******************************************************************************************************************
*   @brief  This API is used to send the async event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_SendAsyncEvent( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief  This API is used to send the DTO from the queue for the channel. 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_SendDtoFromQueue( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief  This API is used to process the DAQ resume request for the channel. 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_DaqResumeProcess(Xcp_ChannelType XcpChannel);
/*!******************************************************************************************************************
*   @brief  This API is used to process the Event channel requested for the Xcp channel . 
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] EventChannel Event channel idx 
*   @return status of the Event channel request
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessChannelEvent(Xcp_ChannelType XcpChannel,uint16 EventChannel);
/*!******************************************************************************************************************
*   @brief  This API is used to process the transmission of response frame
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_SendCrm( Xcp_ChannelType XcpChannel );
/*!******************************************************************************************************************
*   @brief  This API is used to process the reserved/unknowm cmd 
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] CmdPtr pointer to the command buffer  
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_CmdProcessorReservedCmd
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
);

/*!******************************************************************************************************************
*   @brief  This API is used to get the xcp channel id from the network channel id .
*   @param[in] Channel Network channel idx 
*   @return Xcp channel idx if matched else XCP_NUM_OF_CHANNELS
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(Xcp_ChannelType,XCP_CODE) Xcp_GetXcpChannelFromNetworkChannel(NetworkHandleType Channel);
#define XCP_STOP_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  #! PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                     *
********************************************************************************************************************/
/*! @brief Defines the Initialization state of Xcp */
Xcp_InitStateType Xcp_InitState = XCP_INIT_STATE_UNINTITIALIZED;
/*! @brief Defines the XCP command processor function list table.*/
static Xcp_CmdProcessorFuncType Xcp_CmdProcessorFuncList[XCP_CMD_PROCESSOR_FUNC_LIST_SIZE]=
{
    Xcp_StdCmdProcessorConnect,                     /* 0xFF = CONNECT */
    Xcp_StdCmdProcessorDisconnect,                  /* 0xFE = DISCONNECT */
    Xcp_StdCmdProcessorGetStatus,                   /* 0xFD = GET_STATUS */                 
    Xcp_StdCmdProcessorSynch,                       /* 0xFC = SYNCH */
    Xcp_StdCmdProcessorGetCommModeInfo,             /* 0xFB = GET_COMM_MODE_INFO */
    Xcp_StdCmdProcessorGetId,                       /* 0xFA = GET_ID */
#if( (XCP_DAQ_RESUME == STD_ON) || (XCP_PAGE_FREEZE == STD_ON) )
    Xcp_StdCmdProcessorSetRequest,                  /* 0xF9 = SET_REQUEST */
#else
    Xcp_CmdProcessorReservedCmd,                    /* 0xF9 = SET_REQUEST */
#endif
#if( XCP_SEED_KEY == STD_ON )
    Xcp_StdCmdProcessorGetSeed,                       /* 0xF8 = GET_SEED */
    Xcp_StdCmdProcessorUnlock,                        /* 0xF7 = UNLOCK */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xF8 = GET_SEED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xF7 = UNLOCK */
#endif
    Xcp_StdCmdProcessorSetMta,                        /* 0xF6 = SET_MTA */
    Xcp_StdCmdProcessorUpload,                        /* 0xF5 = UPLOAD */
    Xcp_StdCmdProcessorShortUpload,                   /* 0xF4 = SHORT_UPLOAD */
#if( XCP_CHECKSUM == STD_ON )
    Xcp_StdCmdProcessorBuildChecksum,                 /* 0xF3 = BUILD_CHECKSUM */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xF3 = BUILD_CHECKSUM */
#endif
    Xcp_StdCmdProcessorTlCmd,                         /* 0xF2 = TRANSPORT_LAYER_CMD */
#if( XCP_USER_COMMAND == STD_ON )
    Xcp_StdCmdProcessorUserCmd,                       /* 0xF1 = USER_CMD */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xF1 = USER_CMD */
#endif
#if( XCP_CALIBRATION == STD_ON )
    Xcp_CalibCmdProcessorDownload,                    /* 0xF0 = DOWNLOAD */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xF0 = DOWNLOAD */
#endif
#if( XCP_BLOCK_DOWNLOAD == STD_ON )
    Xcp_CalibCmdProcessorDownloadNext,                /* 0xEF = DOWNLOAD_NEXT */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xEF = DOWNLOAD_NEXT */
#endif
#if( (XCP_CALIBRATION == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
    Xcp_CalibCmdProcessorDownloadMax,                 /* 0xEE = DOWNLOAD_MAX */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xEE = DOWNLOAD_MAX */
#endif
#if( XCP_SHORT_DOWNLOAD == STD_ON ) && ( XCP_CALIBRATION == STD_ON )
    Xcp_CalibCmdProcessorShortDownload,               /* 0xED = SHORT_DOWNLOAD */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xED = SHORT_DOWNLOAD */
#endif
#if( XCP_MODIFY_BITS == STD_ON ) && ( XCP_CALIBRATION == STD_ON )
    Xcp_CalibCmdProcessorModifyBits,                  /* 0xEC = MODIFY_BITS */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xEC = MODIFY_BITS */
#endif
#if( XCP_CALIBRATION_PAGE == STD_ON )
    Xcp_PagCmdProcessorSetCalPage,                    /* 0xEB = SET_CAL_PAGE */
    Xcp_PagCmdProcessorGetCalPage,                    /* 0xEA = GET_CAL_PAGE */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xEB = SET_CAL_PAGE */
    Xcp_CmdProcessorReservedCmd,                      /* 0xEA = GET_CAL_PAGE */
#endif
#if( XCP_PAGE_INFO == STD_ON )
    Xcp_PagCmdProcessorGetPageProcessorInfo,          /* 0xE9 = GET_PAG_PROCESSOR_INFO */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xE9 = GET_PAG_PROCESSOR_INFO */
#endif
    Xcp_PagCmdProcessorGetSegmentInfo,                /* 0xE8 = GET_SEGMENT_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE7 = GET_PAGE_INFO */
#if( XCP_PAGE_FREEZE == STD_ON )
    Xcp_PagCmdProcessorSetSegmentMode,                /* 0xE6 = SET_SEGMENT_MODE */
    Xcp_PagCmdProcessorGetSegmentMode,                /* 0xE5 = GET_SEGMENT_MODE */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xE6 = SET_SEGMENT_MODE */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE5 = GET_SEGMENT_MODE */
#endif
#if( XCP_COPY_CAL_PAGE == STD_ON )
    Xcp_PagCmdProcessorCopyCalPage,                   /* 0xE4 = COPY_CAL_PAGE */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xE4 = COPY_CAL_PAGE */
#endif
#if( XCP_DAQ == STD_ON )
    Xcp_CmdProcessorReservedCmd,                      /* 0xE3 = CLEAR_DAQ_LIST */
    Xcp_DaqCmdProcessorSetDaqPtr,                     /* 0xE2 = SET_DAQ_PTR */
    Xcp_DaqCmdProcessorWriteDaq,                      /* 0xE1 = WRITE_DAQ */
    Xcp_DaqCmdProcessorSetDaqListMode,                /* 0xE0 = SET_DAQ_LIST_MODE */
    Xcp_DaqCmdProcessorGetDaqListMode,                /* 0xDF = GET_DAQ_LIST_MODE */
    Xcp_DaqCmdProcessorStartStopDaqList,              /* 0xDE = START_STOP_DAQ_LIST */
    Xcp_DaqCmdProcessorStartStopSynch,                /* 0xDD = START_STOP_SYNCH */
# if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
    Xcp_DaqCmdProcessorGetDaqClock,                   /* 0xDC = GET_DAQ_CLOCK */
# else
    Xcp_CmdProcessorReservedCmd,                      /* 0xDC = GET_DAQ_CLOCK */
# endif
    Xcp_CmdProcessorReservedCmd,                      /* 0xDB = READ_DAQ */
    Xcp_DaqCmdProcessorGetDaqProcessorInfo,           /* 0xDA = GET_DAQ_PROCESSOR_INFO */
    Xcp_DaqCmdProcessorGetDaqResolutionInfo,          /* 0xD9 = GET_DAQ_RESOLUTION_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD8 = GET_DAQ_LIST_INFO */
# if( XCP_DAQ_EVENT_INFO == STD_ON )
    Xcp_DaqCmdProcessorGetDaqEventInfo,               /* 0xD7 = GET_DAQ_EVENT_INFO */
# else
    Xcp_CmdProcessorReservedCmd,                      /* 0xD7 = GET_DAQ_EVENT_INFO */
# endif
    Xcp_DaqCmdProcessorFreeDaq,                       /* 0xD6 = FREE_DAQ */
    Xcp_DaqCmdProcessorAllocDaq,                      /* 0xD5 = ALLOC_DAQ */
    Xcp_DaqCmdProcessorAllocOdt,                      /* 0xD4 = ALLOC_ODT */
    Xcp_DaqCmdProcessorAllocOdtEntry,                 /* 0xD3 = ALLOC_ODT_ENTRY */
#else /* ( XCP_DAQ == STD_ON ) */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE3 = CLEAR_DAQ_LIST */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE2 = SET_DAQ_PTR */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE1 = WRITE_DAQ */
    Xcp_CmdProcessorReservedCmd,                      /* 0xE0 = SET_DAQ_LIST_MODE */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDF = GET_DAQ_LIST_MODE */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDE = START_STOP_DAQ_LIST */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDD = START_STOP_SYNCH */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDC = GET_DAQ_CLOCK */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDB = READ_DAQ */
    Xcp_CmdProcessorReservedCmd,                      /* 0xDA = GET_DAQ_PROCESSOR_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD9 = GET_DAQ_RESOLUTION_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD8 = GET_DAQ_LIST_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD7 = GET_DAQ_EVENT_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD6 = FREE_DAQ */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD5 = ALLOC_DAQ */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD4 = ALLOC_ODT */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD3 = ALLOC_ODT_ENTRY */
#endif /* ( XCP_DAQ == STD_ON ) */
#if( (XCP_PROGRAM == STD_ON) || (XCP_BOOTLOADER_DOWNLOAD == STD_ON) )
    Xcp_PgmCmdProcessorProgramStart,                  /* 0xD2 = PROGRAM_START */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xD2 = PROGRAM_START */
#endif
#if( XCP_PROGRAM == STD_ON )
    Xcp_PgmCmdProcessorProgramClear,                  /* 0xD1 = PROGRAM_CLEAR */
    Xcp_PgmCmdProcessorProgram,                       /* 0xD0 = PROGRAM */
    Xcp_PgmCmdProcessorProgramReset,                  /* 0xCF = PROGRAM_RESET */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xD1 = PROGRAM_CLEAR */
    Xcp_CmdProcessorReservedCmd,                      /* 0xD0 = PROGRAM */
    Xcp_CmdProcessorReservedCmd,                      /* 0xCF = PROGRAM_RESET */
#endif
#if( (XCP_PROGRAM == STD_ON) && (XCP_PROGRAM_INFO == STD_ON) )
    Xcp_PgmCmdProcessorGetPgmProcessorInfo,           /* 0xCE = GET_PGM_PROCESSOR_INFO */
    Xcp_PgmCmdProcessorGetSectorInfo,                 /* 0xCD = GET_SECTOR_INFO */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xCE = GET_PGM_PROCESSOR_INFO */
    Xcp_CmdProcessorReservedCmd,                      /* 0xCD = GET_SECTOR_INFO */
#endif
#if( XCP_BOOTLOADER_DOWNLOAD == STD_ON )
    Xcp_PgmCmdProcessorProgramPrepare,                /* 0xCC = PROGRAM_PREPARE */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xCC = PROGRAM_PREPARE */
#endif
    Xcp_CmdProcessorReservedCmd,                      /* 0xCB = PROGRAM_FORMAT */
#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_ON) )
    Xcp_PgmCmdProcessorProgramNext,                   /* 0xCA = PROGRAM_NEXT */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xCA = PROGRAM_NEXT */
#endif
#if( (XCP_PROGRAM == STD_ON) && (XCP_BLOCK_DOWNLOAD == STD_OFF) )
    Xcp_CmdPgm_ProgramMax,                            /* 0xC9 = PROGRAM_MAX */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xC9 = PROGRAM_MAX */
#endif
    Xcp_CmdProcessorReservedCmd,                      /* 0xC8 = PROGRAM_VERIFY */
#if( XCP_WRITE_DAQ_MULTIPLE == STD_ON )
    Xcp_DaqCmdProcessorWriteDaqMultiple,              /* 0xC7 = WRITE_DAQ_MULTIPLE */
#else
    Xcp_CmdProcessorReservedCmd,                      /* 0xC7 = WRITE_DAQ_MULTIPLE */
#endif
    Xcp_CmdProcessorReservedCmd,                      /* 0xC6 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC5 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC4 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC3 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC2 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC1 = RESERVED */
    Xcp_CmdProcessorReservedCmd,                      /* 0xC0 = RESERVED */
};
/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define XCP_START_SEC_CODE
#include "MemMap.h" 
/********************************************************************************************************************
*   @brief      This service initializes interfaces and variables of the AUTOSAR XCP layer.
*   @param[in]  Xcp_ConfigPtr Pointer to the configuration data of the Xcp module
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_Init(P2CONST(Xcp_ConfigType, AUTOMATIC, XCP_APPL_CONST) Xcp_ConfigPtr)
{
    Xcp_ChannelType XcpChannel;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Intialize the channel status */
        Xcp_UtilMemSet((uint8 *)&Xcp_ChannelCtrlStatus[0],(uint8)sizeof(Xcp_ChannelCtrlStatusType),0U);
        /* Initialize the STIM mode */
        Xcp_StimMode = XCP_STIM_SINGLE_SHOT_MODE;
        /* Initialize the channel */
        for (XcpChannel = 0; XcpChannel < XCP_NUM_OF_CHANNELS; XcpChannel++ )
        {
            /* Enable transmission mode */
            Xcp_TransmissionMode[XcpChannel] = XCP_TX_ON;
            /* lock all resources */
            Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionInitStatus = (uint8)(XCP_RM_ALL_RESOURCES);
            /* Initialize DAQ queue */
            Xcp_DaqCmdQueueInit(XcpChannel);
            /* process daq resume */
            if (Xcp_ApplCheckDaqResume(XcpChannel) == TRUE)
            {
                /* Initialize the queue limit */
                Xcp_CalcSendQueueEntrySizeAndLimit(XcpChannel);
                /* update resume status */
                Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= (uint16)XCP_SESSION_RESUME;
                /* start all daq list */
                Xcp_DaqCmdStartAllSelectedDaq(XcpChannel);
                /* Nofify app about state */
                Xcp_ApplConnectionStateNotification(XcpChannel,XCP_CON_STATE_RESUME);
            }
            else
            {
                /* Nofify app about state */
                Xcp_ApplConnectionStateNotification(XcpChannel,XCP_CON_STATE_DISCONNECTED);
            }
        }
        /* Set Xcp to state intialized */
        Xcp_InitState = XCP_INIT_STATE_INTITIALIZED;
    }
}
/********************************************************************************************************************
*   @brief      Returns the version information.
*   @param[out] versioninfo  Pointer to where to store the version information of this module
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,XCP_APPL_VAR) versioninfo )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    /* check for dev error */
    if (NULL_PTR == versioninfo)
    {
        ErrorId = XCP_E_PARAM_POINTER;
    }
    else
    {
        /* Get version info */
        versioninfo->vendorID = XCP_VENDOR_ID;
        versioninfo->moduleID = XCP_MODULE_ID;
        versioninfo->sw_major_version = XCP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = XCP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = XCP_SW_PATCH_VERSION;
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_GETVERSIONINFO_API , ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This API is used to turn on and off of the TX capabilities of used communication bus channel in XCP 
*               module
*   @param[in]  Channel The Network channel for the used bus communication
*   @param[in]  Mode Enabled or disabled Transmission mode Parameters
*   XCP_TX_OFF - Tx disabled
*   XCP_TX_ON - Tx enabled
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetTransmissionMode( NetworkHandleType Channel, Xcp_TransmissionModeType Mode )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    Xcp_ChannelType XcpChannel = 0U;
    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (Mode > XCP_TX_ON)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            XcpChannel = Xcp_GetXcpChannelFromNetworkChannel(Channel);
            if (XcpChannel < XCP_NUM_OF_CHANNELS )
            {
                Xcp_TransmissionMode[XcpChannel] = Mode;
            }
            else
            {
                ErrorId = XCP_E_INVALID_PARAM;
            }
        }
    }
#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_SETTRANSMISSION_MODE , ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  CmdPtr pointer to the command buffer 
*   @ServiceID  0x42
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_TlRxIndication( Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) CmdPtr )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    uint8 CmdProcessFuncIdx = 0U;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (NULL_PTR == CmdPtr)
        {
            ErrorId = XCP_E_PARAM_POINTER;
        }
        else if (XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* check if it is already connected or the connect cmd is requested */
            if ((Xcp_ChannelCtrlStatus[XcpChannel].ConnectionState == XCP_CONNECTION_STATE_TYPE_CONNECTED) ||
                (CmdPtr[XCP_CRO_CMD_BYTE] ==XCP_CMD_CONNECT))
            {
                if(CmdPtr[XCP_CRO_CMD_BYTE] >= XCP_CMD_START)
                {
                    /* check for existing command processing */
                    if((CmdPtr[XCP_CRO_CMD_BYTE] != XCP_CMD_CONNECT) &&
                        ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)(XCP_CRM_PENDING)) != 0u ) &&
                        ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)(XCP_CRM_REQUEST)) != 0u ) )
                    {
                        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_ERROR;
                    }
                    else
                    {
                        CmdProcessFuncIdx = (uint8)(~CmdPtr[XCP_CRO_CMD_BYTE]);
                        if (XCP_CMD_PROCESSOR_FUNC_LIST_SIZE > CmdProcessFuncIdx)
                        {
                            /* It is a CMD frame, prepare default response */ 
                            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[0] = XCP_PID_RES;
                            Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen = 1u;
                            /* invoke the command processor function */
                            Xcp_GetCmdProcessorFunction(CmdProcessFuncIdx)(XcpChannel,CmdPtr);
                            /* update the session status */
                            Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= (uint16)XCP_SESSION_POLLING;
                            /* check if CTO response to be transmitted */
                            if((Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen > 0u) && 
                            (Xcp_ChannelCtrlStatus[XcpChannel].ResponsePending == FALSE))
                            { 
                                Xcp_SendCrm( XcpChannel );
                            }
                        }
                    }
                }
                else
                {
                    #if( XCP_STIM == STD_ON )
                    # if( XCP_SEED_KEY == STD_ON )
                    if (Xcp_ResourceProtectionCheck(XcpChannel,XCP_RESOURCE_PROTECTION_STATUS_STIM_BIT) != XCP_CMD_OK)
                    {
                        Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_ACCESS_LOCKED);
                    }
                    else
                    #endif
                    {
                        Xcp_DtoBufferType* pStimBuffer;
                        if( CmdPtr[0] < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts)
                        {
                            pStimBuffer = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.pStimBuffer[CmdPtr[0]];
                            if (pStimBuffer != NULL_PTR)
                            {
                                Xcp_EnterCriticalSection();
                                pStimBuffer->Buffer[0] = CmdPtr[0];
                                Xcp_UtilMemCopy((uint8 *)&pStimBuffer->Buffer[1],
                                                &CmdPtr[1], Xcp_ChannelCtrlStatus[XcpChannel].MaxDto-1U );
                                Xcp_ExitCriticalSection();
                            }
                        }
                    }
                    #endif
                }
            }
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_TLRXINDICATION_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      Indication of a tramsision for PDU from a lower layer communication interface module.
*   @param[in]  XcpChannel Xcp channel Idx
*   @ServiceID  0x40
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_TlTxConfirmation( Xcp_ChannelType XcpChannel )
{
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* clear pending status */
            Xcp_ChannelCtrlStatus[XcpChannel].SendStatus &= (uint8)((~XCP_SEND_PENDING) & 0xFFu);
            /* transmit pending request */
            if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus  & (uint8)XCP_CRM_REQUEST) != 0u )
            {
                Xcp_ChannelCtrlStatus[XcpChannel].SendStatus &= (uint8)((~XCP_CRM_REQUEST) & 0xFFu);
                Xcp_SendCrm(XcpChannel);
            }
            #if(XCP_SEND_EVENT == STD_ON)
            else if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus  & (uint8)XCP_EVT_REQUEST) != 0u )
            {
                Xcp_ChannelCtrlStatus[XcpChannel].SendStatus &= (uint8)((~XCP_EVT_REQUEST) & 0xFFu);
                Xcp_SendAsyncEvent(XcpChannel);
            }
            #endif
            #if(XCP_DAQ == STD_ON)
            else if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus  & (uint16)XCP_SESSION_DAQ) != 0u )
            {
                Xcp_SendDtoFromQueue(XcpChannel);
            }
            #endif
            #if( XCP_BLOCK_UPLOAD == STD_ON )
            else if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus  & (uint16)XCP_SESSION_BLOCK_UPLOAD) != 0u )
            {
                uint8 cmd[2];
                cmd[0] = (uint8)XCP_CMD_UPLOAD;
                cmd[1] = (uint8)Xcp_ChannelCtrlStatus[XcpChannel].NextDataBlockSize;

                /* #90 Reset PENDING flag, execute upload command and send the frame. */
                Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_BLOCK_UPLOAD) & 0xFFFFu);
                Xcp_StdCmdProcessorUpload(XcpChannel,&cmd[0]);
                Xcp_SendCrm(XcpChannel);
            }
            #endif
            else
            {
                /* Do Nothing */
            }
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_TLTXCONFIRMATION_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Scheduled function of the XCP module
*   @ServiceID  0x40
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_MainFunction( void )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    Xcp_ChannelType XcpChannel;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else
        {
            for (XcpChannel = 0; XcpChannel < XCP_NUM_OF_CHANNELS; XcpChannel++)
            {
                /* process pending dto from the queue*/
                Xcp_SendDtoFromQueue(XcpChannel);
                /* process the resume status */
                Xcp_DaqResumeProcess(XcpChannel);           
            }
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_MAINFUNCTION_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
} 
/********************************************************************************************************************
*   @brief      This API is used to set the active TL and its properties for this channel .
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  XcpChannel MaxCto Maximum supported CTO length in bytes 
*   @param[in]  XcpChannel MaxDto Maximum supported Dto length in bytes
*   @param[in]  XcpChannel ActiveTl active tl idx 
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetActiveTl( Xcp_ChannelType XcpChannel, uint8 MaxCto, uint16 MaxDto, uint8 ActiveTl )
{
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if ((XCP_NUM_OF_CHANNELS <= XcpChannel) ||
                 (XCP_MAX_CTO_MAX < MaxCto) || 
                 (XCP_MAX_DTO_MAX < MaxDto) ||
                 (XCP_NUM_OF_TL_SUPPORTED <= ActiveTl))
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* update property of active tl */
            #if( XCP_DAQ == STD_ON )
            if (Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl != ActiveTl)
            {
                Xcp_DaqCmdStopAllDaq(XcpChannel);
            }
            #endif
            Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl = ActiveTl;
            Xcp_ChannelCtrlStatus[XcpChannel].MaxCto = MaxCto;
            Xcp_ChannelCtrlStatus[XcpChannel].MaxDto = MaxDto;
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_SETACTIVETL_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This API is used to get the active TL for this channel.
*   @param[in]  XcpChannel Xcp channel Idx
*   @return  XcpChannel ActiveTl active tl idx 
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_GetActiveTl( Xcp_ChannelType XcpChannel )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    uint8 ActiveTl = XCP_NUM_OF_TL_SUPPORTED;
    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* get current active tl */
            ActiveTl = Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl;
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_GETACTIVETL_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
    return ActiveTl;
}
/********************************************************************************************************************
*   @brief      This API is used to disconnect the Xcp.
*   @param[in]  XcpChannel Xcp channel Idx
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_Disconnect( Xcp_ChannelType XcpChannel )
{
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* reset connection state */
            Xcp_ChannelCtrlStatus[XcpChannel].ConnectionState = XCP_CONNECTION_STATE_TYPE_UNCONNECTED;
            Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_CONNECTED) & 0xFFFFu); 
            #if( XCP_DAQ == STD_ON )
            Xcp_DaqCmdStopAllDaq( XcpChannel );
            #endif
            #if( XCP_SEED_KEY == STD_ON )
            /* Lock all resources */
            Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus = (uint8)( XCP_RM_ALL_RESOURCES );
            #endif
            /* notify to application layer */
            Xcp_ApplConnectionStateNotification(XcpChannel,XCP_CON_STATE_DISCONNECTED);
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_DISCONNECT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief  This Api used to process the event channel
* @param[in] EventChannel pointer to destination buffer data
* @return Event processing status
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_Event( uint16 EventChannel )
{
    Xcp_ChannelType ChannelIdx;
    uint8 ErrorId = XCP_E_NO_ERROR;
    uint8 RetVal = XCP_EVENT_NOP;
    
    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if(XCP_MAX_EVENT <= EventChannel )
        {
            ErrorId = XCP_E_INVALID_PARAM;
        } 
        else
        {
            for (ChannelIdx = 0U;ChannelIdx<XCP_NUM_OF_CHANNELS;ChannelIdx++)
            {
                /* check for Daq session */
                if( (Xcp_ChannelCtrlStatus[ChannelIdx].SessionStatus & XCP_SESSION_DAQ) != 0u )
                {
                    RetVal = Xcp_ProcessChannelEvent(ChannelIdx,EventChannel);
                }
            }
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_EVENT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
  return RetVal;
}
/********************************************************************************************************************
* @brief  This Api used to set the STIM mode 
* @param[in] Mode STIM mode to be set 0: XCP_STIM_SINGLE_SHOT_MODE, 1: XCP_STIM_CONTINUOUS_MODE
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_SetStimMode(uint8 Mode)
{
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
	    else if(Mode > XCP_STIM_CONTINUOUS_MODE)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        } 
        else
        {
            Xcp_StimMode = Mode;
        }
    }
#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_EVENT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
* @brief  This Api used to set the STIM event status for the event channel
* @param[in] EventChannel Event channel idx
* @param[in] Action event value . 0: XCP_STIM_CHECK_ODT_BUFFER, 1: XCP_STIM_RESET_ODT_BUFFER
* @return Returns the stim event status 
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_StimEventStatus( uint16 EventChannel, uint8 Action )
{
    uint16 Daq;
    Xcp_ChannelType XcpChannel;
    uint8 ErrorId = XCP_E_NO_ERROR;;
    uint8 RetVal = XCP_NO_STIM_DATA_AVAILABLE;
    
    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
	    else if((XCP_MAX_EVENT <= EventChannel ) || (Action > XCP_STIM_RESET_ODT_BUFFER))
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            for (XcpChannel = 0u; XcpChannel < XCP_NUM_OF_CHANNELS; XcpChannel++)
            {
                if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus & XCP_SESSION_DAQ) != 0U)
                {
                    for (Daq = 0U;Daq < Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfDaqLists;Daq++)
                    {
                        if (((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[Daq] & XCP_DAQ_FLAG_RUNNING) != 0U) &&
                            (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqToEventChannelMap[Daq] == EventChannel ) &&
                            ((Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[Daq] & XCP_DAQ_FLAG_DIRECTION) != 0U))
                        {
                            RetVal = Xcp_ProcessStimEventStatus(XcpChannel,Daq, Action);   
                        }
                    }
                }
            }
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_EVENT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This API is used update the protection status .
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  ResourceValBitMask resource value mask bit
*   @param[in]  SetClear set/clear the status. 0- set the status . 1- clear the status
*   @return  returns the status of the protection register
********************************************************************************************************************/
FUNC(uint8, XCP_CODE) Xcp_ModifyProtectionStatus
(
    Xcp_ChannelType XcpChannel,
    uint8 ResourceValBitMask,
    boolean SetClear 
)
{
    uint8 RetVal = 0U;
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
	    else if(XCP_NUM_OF_CHANNELS <= XcpChannel )
        {
            ErrorId = XCP_E_INVALID_PARAM;
        } 
        else
        {
            if (SetClear == TRUE)
            {
                Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus |= ResourceValBitMask;
                Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionInitStatus  |= ResourceValBitMask;
            }
            else
            {
                
                Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus &= (uint8)((~ResourceValBitMask) & 0xFFu);
                Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionInitStatus  &= (uint8)((~ResourceValBitMask) & 0xFFu);
            }
            RetVal = Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionInitStatus;
        }
    }

#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_EVENT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief     This service used to copy data from source buffer to destination buffer
*   @param[in] DestPtr pointer to destination buffer data
*   @param[in] SrcPtr pointer to source buffer data
*   @param[in] Length byte size to be copied
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_UtilMemCopy
(
    P2VAR(uint8,AUTOMATIC,XCP_APPL_DATA) DestPtr , 
    CONSTP2CONST(uint8,AUTOMATIC,XCP_APPL_CONST) SrcPtr , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}
/********************************************************************************************************************
* @brief  This Api used to set requested data to the destination buffer
* @param[out] DestPtr pointer to destination buffer data
* @param[in] Value value to be set
* @param[in] Length byte size to be set
********************************************************************************************************************/
FUNC(void,XCP_CODE) Xcp_UtilMemSet
(   
    P2VAR(uint8,AUTOMATIC,XCP_APPL_DATA) DestPtr , 
    uint8 Value , 
    PduLengthType Length
)
{
    PduLengthType Idx;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value;
    }
}
/********************************************************************************************************************
*   @brief      This API is used to update the response buffer with the negative response
*   @param[in]  XcpChannel Xcp channel Idx
*   @param[in]  ErrorCommand the error command value 
********************************************************************************************************************/
void Xcp_SetNegativeResponse(Xcp_ChannelType XcpChannel,uint8 ErrorCommand)
{
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[0U] = XCP_PID_ERR;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[1U] = ErrorCommand;
    Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen += 2U;

}
/*!******************************************************************************************************************
*   @brief      This service is used to whether access of the requested reource is protected or not.
*   @param[in]  XcpChannel  Channel Id type
*   @param[in]  Resource resource value for which the protection status to be checked.
*   @return status of the access protection protection 
*   XCP_CMD_OK: resourced unlocked XCP_ERR_ACCESS_LOCKED: resource locked.
********************************************************************************************************************/
FUNC(uint8,XCP_CODE) Xcp_ResourceProtectionCheck(Xcp_ChannelType XcpChannel,uint8 Resource)
{
    uint8 RetVal = XCP_CMD_OK;

    if((Xcp_ChannelCtrlStatus[XcpChannel].ResourceProtectionStatus & Resource) != 0U)
    {
        RetVal = XCP_ERR_ACCESS_LOCKED;
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief  This API is used to calculate the send queue entry size and limit value for the xcp channel 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
FUNC(void, XCP_CODE) Xcp_CalcSendQueueEntrySizeAndLimit( Xcp_ChannelType XcpChannel )
{  
    /* Calculate entry queue size and make it even byte boundary */
    Xcp_DaqSendQueue[XcpChannel].EntrySize = ((Xcp_ChannelCtrlStatus[XcpChannel].MaxDto +  XCP_CONNECT_DTO_OFFSET + 1U) & 0xFFFEU);
    /* update the limit and convert it into even byte boundary */
    Xcp_DaqSendQueue[XcpChannel].QueueSizeLimit = Xcp_DaqSendQueue[XcpChannel].QueueSize / ((Xcp_ChannelCtrlStatus[XcpChannel].MaxDto +  XCP_CONNECT_DTO_OFFSET + 1U) & 0xFFFEU) ;
    Xcp_DaqSendQueue[XcpChannel].QueueSizeLimit *= Xcp_DaqSendQueue[XcpChannel].EntrySize;
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION			                                                                    *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief  This API is used to process the STIM event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx  
*   @param[in] Daq DAQ id value 
*   @param[in] Action event action value
*   @return Status for the event request 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessStimEventStatus(Xcp_ChannelType XcpChannel, uint16 Daq, uint8 Action)
{
    uint16 EntryIdx;
    Xcp_OdtIdxType Odt;
    uint8 RetVal = XCP_NO_STIM_DATA_AVAILABLE;
    P2VAR(Xcp_DtoBufferType,AUTOMATIC,XCP_VAR_NOINIT) pStimBuffer;

    for (Odt = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[Daq];
        ((Odt < (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[Daq]+
        Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtsOfDaq[Daq])) && 
        (Odt < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))) ;Odt++)
    {
        EntryIdx = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[Daq];
        /* Check for valid entry */
        if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx] != 0U)
        {
            pStimBuffer = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.pStimBuffer[Odt];
            if (pStimBuffer != NULL_PTR)
            {
                if (Action == XCP_STIM_CHECK_ODT_BUFFER)
                {
                    if (pStimBuffer->Buffer[0u] != (uint8)0xFFu )
                    {
                        /* STIM data available */
                        RetVal = XCP_STIM_DATA_AVAILABLE; 
                    }
                }
                else if (Action == XCP_STIM_RESET_ODT_BUFFER)
                {
                    pStimBuffer->Buffer[0u] = 0xFFu;
                }
                else
                {
                    /* Do Nothing */
                }
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief  This API is used to process DAQ event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] DaqListIdx DAQ list id value 
*   @return Status for the DAQ event  
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessEventDaq(Xcp_ChannelType XcpChannel,uint16 DaqListIdx )
{
    uint8 Odt;
    uint8 OdtEntry;
    uint16 DtoLength;
    uint32 WriteIdx,DtoBufferIdx;
    Xcp_OdtEntryIdxType EntryIdx;
    uint8 RetVal = XCP_EVENT_DAQ;
    Xcp_TimestampType XcpTimestamp;
    P2VAR(uint8,AUTOMATIC,XCP_VAR_NOINIT)  pDtoBuffer;
    P2VAR(Xcp_DaqListStatusType,AUTOMATIC,XCP_VAR_NOINIT) pDaqListStatus;

    pDaqListStatus = &Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus;
    /* process for all Odt's of daq list */
    Xcp_EnterCriticalSection();
    for (Odt = 0; ((Odt < pDaqListStatus->NumOfOdtsOfDaq[DaqListIdx]) &&
        ((pDaqListStatus->FirstOdtIdxOfDaq[DaqListIdx]+Odt) < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))); Odt++)
    {
        EntryIdx = pDaqListStatus->FirstOdtEntryIdxOfDaq[pDaqListStatus->FirstOdtIdxOfDaq[DaqListIdx]+Odt];
        /* check send queue size and do wrap if length exceeds limit */
        WriteIdx = Xcp_DaqSendQueue[XcpChannel].WriteIdx + Xcp_DaqSendQueue[XcpChannel].EntrySize;
        if (WriteIdx >= Xcp_DaqSendQueue[XcpChannel].QueueSizeLimit)
        {
            WriteIdx = 0U;
        }
        /* validate the write idx for overflow condition */
        if (WriteIdx != Xcp_DaqSendQueue[XcpChannel].ReadIdx)
        {
            DtoBufferIdx = (XcpChannel*Xcp_DaqSendQueue[XcpChannel].QueueSize) + Xcp_DaqSendQueue[XcpChannel].WriteIdx; 
            if (XCP_DAQ_SEND_QUEUE_SIZE > DtoBufferIdx)
            {
                pDtoBuffer = &Xcp_DaqSendQueueRef[DtoBufferIdx];
            }
            else
            {
                pDtoBuffer = NULL_PTR;
            }
            
        }
        else
        {
            /* update Daq overload status and exit processing */
            Xcp_DaqSendQueue[XcpChannel].OverloadFlag = XCP_DAQ_OVERLOAD_MSB;
            RetVal |= XCP_EVENT_DAQ_OVERLOAD;
            break;
        }
        if (pDtoBuffer != NULL_PTR)
        {
            /* update PID for the response */
            #if (XCP_DAQ_HDR_LEN == 1u)
            pDtoBuffer[2u] = (uint8)(pDaqListStatus->FirstOdtIdxOfDaq[DaqListIdx] + Odt);
            #else 
            pDtoBuffer[2u] = Odt;
            pDtoBuffer[3u] = DaqListIdx;
            #endif 
            #if( XCP_DAQ_OVERRUN_INDICATION == STD_ON )
            pDtoBuffer[2u] |= Xcp_DaqSendQueue[XcpChannel].OverloadFlag;
            Xcp_DaqSendQueue[XcpChannel].OverloadFlag = 0U;
            #endif
            DtoLength = XCP_DAQ_HDR_LEN + 2U; // update for Dto length 
            /* Timestamp update */
            # if( XCP_DAQ_TIMESTAMP_SIZE > 0 )
            /* update timestamp in first ODT response frame */
            if((Odt == 0u) 
            #if( XCP_DAQ_TIMESTAMP_FIXED == STD_OFF )
            && ((pDaqListStatus->DaqListMode[DaqListIdx] & XCP_DAQ_LIST_TIMESTAMP) > 0u) 
            #endif
            )      
            {
                XcpTimestamp = Xcp_ApplGetTimeStamp();
                #if( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_WORD )
                pDtoBuffer[DtoLength] = (uint8) XcpTimestamp;
                pDtoBuffer[DtoLength+1u] |= (uint8) (XcpTimestamp >> 8U);
                #elif( XCP_DAQ_TIMESTAMP_SIZE == XCP_DAQ_TIMESTAMP_DWORD )
                pDtoBuffer[DtoLength] = (uint8) XcpTimestamp;
                pDtoBuffer[DtoLength+1u] |= (uint8) (XcpTimestamp >> 8U); 
                pDtoBuffer[DtoLength+2u] |= (uint8) (XcpTimestamp >> 16U); 
                pDtoBuffer[DtoLength+3u] |= (uint8) (XcpTimestamp >> 24U); 
                #else
                pDtoBuffer[DtoLength] = XcpTimestamp;
                #endif 
                DtoLength += sizeof(Xcp_TimestampType);

            }
            #endif
            /* iterate for OdtEnty */
            for(OdtEntry = 0u; 
                OdtEntry < pDaqListStatus->NumOfOdtEntriesOfDaq[pDaqListStatus->FirstOdtIdxOfDaq[DaqListIdx]+Odt];
                OdtEntry++ )
            {
                if(EntryIdx < XCP_MAX_ODT_ENTRIES) 
                {
                    if(pDaqListStatus->OdtEntriesSize[EntryIdx] > 0u)
                    {
                        if(((DtoLength + pDaqListStatus->OdtEntriesSize[EntryIdx]) > Xcp_DaqSendQueue[XcpChannel].EntrySize) ||
                            ((DtoLength + pDaqListStatus->OdtEntriesSize[EntryIdx]) >= XCP_DAQ_SEND_QUEUE_SIZE))
                        {
                            /* invalid length and exit processing */
                            break;
                        }
                        /* copy data to the buffer */
                        Xcp_UtilMemCopy(&pDtoBuffer[DtoLength],
                                        (uint8 *)pDaqListStatus->OdtEntries[EntryIdx],pDaqListStatus->OdtEntriesSize[EntryIdx]);
                        DtoLength += (uint16)pDaqListStatus->OdtEntriesSize[EntryIdx];
                    }
                    else
                    {
                        /* no entries, exit processing */
                        break; 
                    }
                    EntryIdx++;
                }
            }
            /* update dto length and write idx */
            pDtoBuffer[0] = (uint8)(DtoLength -2U);
            pDtoBuffer[1] |= (uint8)((DtoLength -2U) >> 8U);
        } /* pDtoBuffer != NULL_PTR */
    }
    Xcp_ExitCriticalSection();

    return RetVal;
}
/********************************************************************************************************************
*   @brief  This API is used to process STIM event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] DaqListIdx DAQ list id value 
*   @return Status for the STIM event  
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessEventStim( Xcp_ChannelType XcpChannel, uint16 DaqListIdx )
{
    uint16 DtoLength;
    uint8 OdtEntry;
    Xcp_OdtIdxType Odt;
    Xcp_OdtEntryIdxType EntryIdx;
    uint8 RetVal = XCP_EVENT_STIM;
    P2VAR(Xcp_DtoBufferType,AUTOMATIC,XCP_VAR_NOINIT) pStimBuf;
    /* process for all Ots of the daq list idx */
    for (Odt = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqListIdx]; 
         ((Odt < (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqListIdx] +
         Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdts)) && 
         (Odt < (XCP_MAX_ODT_DAQ + XCP_MAX_ODT_STIM))); Odt++)
    {
        EntryIdx = Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[Odt];

        if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[Odt] == 0U)
        {
            /* return if no entries found */
            break;
        }
        pStimBuf=Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.pStimBuffer[Odt];
        /* validate the stim buffer and process */
        if (pStimBuf == NULL_PTR)
        {
            break;
        }
        else if (pStimBuf->Buffer[0] == 0xFFU)
        {
            /* No STIM data available */
            RetVal |= XCP_EVENT_STIM_OVERRUN; 
        } 
        else
        {
            Xcp_EnterCriticalSection();
            if (Xcp_StimMode == XCP_STIM_SINGLE_SHOT_MODE)
            {
                pStimBuf->Buffer[0] = 0xFFu;
            }
            #if (XCP_DAQ_HDR_LEN == 1u)
            DtoLength = 1u;
            #else
            DtoLength = 2u;
            #endif
            /* upadate timestamp */
            #if( XCP_DAQ_TIMESTAMP_SIZE > 0u )
            /* Time stamp is only applicable in first ODT of STIM. If it is the 1st ODT, remove the timestamp. */
            if( Odt == Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.FirstOdtIdxOfDaq[DaqListIdx] )
            {
                #if( XCP_DAQ_TIMESTAMP_FIXED == STD_OFF )
                if( (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.DaqListMode[DaqListIdx] & XCP_DAQ_FLAG_TIMESTAMP) > 0u )
                #endif
                {
                    DtoLength += sizeof(Xcp_TimestampType);
                }
            }
            #endif
            
            /* check for valid Daq and update entries for all odt */
            for (OdtEntry = 0U;
                OdtEntry< Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[Odt];OdtEntry++)
            {
                if(EntryIdx < XCP_MAX_ODT_ENTRIES)
                {
                    if (Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx] > 0U)
                    {
                        if (((DtoLength + Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx]) >
                            Xcp_ChannelCtrlStatus[XcpChannel].MaxDto) || 
                            ((DtoLength + Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx]) > XCP_MAX_DTO_MAX))
                        {
                            /* if the odt entry size exceeds, break the iteration */
                            break;
                        }
                        /* copy the data to the buffer */
                        Xcp_UtilMemCopy((uint8 *)(Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntries[EntryIdx]),
                                &pStimBuf->Buffer[DtoLength],
                                Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx]);
                        DtoLength += (uint16)Xcp_ChannelCtrlStatus[XcpChannel].Xcp_DaqListStatus.OdtEntriesSize[EntryIdx];
                    }
                    else
                    {
                        /* no more entries to copy */
                        break;
                    }
                    EntryIdx++;
                }
            }
            Xcp_ExitCriticalSection();
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief  This API is used to send the DTO from the queue for the channel. 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_SendDtoFromQueue( Xcp_ChannelType XcpChannel )
{
    uint16 MsgLen,BuffIdx;
    Xcp_TlSendFunctPtrType pTlSendFunct;
    P2VAR(uint8,AUTOMATIC,XCP_VAR_NOINIT) pMsgBuffer;

    if (((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)XCP_SEND_PENDING) == 0u) &&
        (Xcp_DaqSendQueue[XcpChannel].WriteIdx != Xcp_DaqSendQueue[XcpChannel].ReadIdx))
    {
        pTlSendFunct = Xcp_TlConfig[Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl].TlSendFunctPtr;
        if (pTlSendFunct != NULL_PTR)
        {
            Xcp_ChannelCtrlStatus[XcpChannel].SendStatus |= (uint8)XCP_DTO_PENDING;
            /* update the buffer */
            BuffIdx = (XcpChannel * Xcp_DaqSendQueue[XcpChannel].QueueSize) + Xcp_DaqSendQueue[XcpChannel].ReadIdx;
            if ((BuffIdx + 2U) < XCP_DAQ_SEND_QUEUE_SIZE)
            {
                MsgLen = *(uint16 *)(&Xcp_DaqSendQueueRef[BuffIdx]);
                pMsgBuffer = &Xcp_DaqSendQueueRef[BuffIdx+2U];
                /* send the message */
                pTlSendFunct(XcpChannel,MsgLen,pMsgBuffer);
                /* update the readidx */
                if((Xcp_DaqSendQueue[XcpChannel].ReadIdx + Xcp_DaqSendQueue[XcpChannel].EntrySize) >=
                    Xcp_DaqSendQueue[XcpChannel].QueueSizeLimit)
                {
                    Xcp_DaqSendQueue[XcpChannel].ReadIdx = 0u;
                }
                else
                {
                    Xcp_DaqSendQueue[XcpChannel].ReadIdx = Xcp_DaqSendQueue[XcpChannel].ReadIdx + Xcp_DaqSendQueue[XcpChannel].EntrySize;
                }
            }
        }
    }
}
/********************************************************************************************************************
*   @brief  This API is used to process the DAQ resume request for the channel. 
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_DaqResumeProcess(Xcp_ChannelType XcpChannel)
{
    if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus & (uint16)XCP_SESSION_STORE_DAQ_REQ_RESUME) != 0U)
    {
        /* process the daq store with resume request */
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_STORE_DAQ_REQ_RESUME) & 0xFFFFu);
        Xcp_ApplDaqResumeStore(XcpChannel,TRUE);
    }
    else if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus & XCP_SESSION_STORE_DAQ_REQ_NO_RESUME) != 0U)
    {
        /* process the daq store with no resume request */
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_STORE_DAQ_REQ_NO_RESUME) & 0xFFFFu);
        Xcp_ApplDaqResumeStore(XcpChannel,FALSE);         
    }
    else if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus & (uint16)XCP_SESSION_CLEAR_DAQ_REQ) != 0u )
    {
        /* process the clear daq request */
        Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_CLEAR_DAQ_REQ) & 0xFFFFu);
        Xcp_ApplDaqResumeClear(XcpChannel);
        Xcp_ChannelCtrlStatus[XcpChannel].SessionConfigurationId = 0U;
    }
    else if ((Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus & (uint16)XCP_SESSION_STORE_CAL_REQ) != 0u)
    {
        /* process the calibration store request */
        if (Xcp_ApplResumeCalStore(XcpChannel) == TRUE)
        {
            Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus &= (uint16)((~XCP_SESSION_STORE_CAL_REQ) & 0xFFFFu);
        }
    }
    else
    {
        /* Do Nothing */
    }
}
/********************************************************************************************************************
*   @brief  This API is used to process the Event channel requested for the Xcp channel . 
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] EventChannel Event channel idx 
*   @return status of the Event channel request
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(uint8, XCP_CODE) Xcp_ProcessChannelEvent(Xcp_ChannelType XcpChannel,uint16 EventChannel)
{
    uint8 RetVal = XCP_EVENT_NOP;
    uint16 DaqListIdx;
    P2VAR(Xcp_ChannelCtrlStatusType,AUTOMATIC,XCP_VAR_NOINIT) pChannelCtrlStatus;
    /* Iterate over all the daq list supported , process if Daqlist is supported by this event 
                    channel and its  active */
    pChannelCtrlStatus = &Xcp_ChannelCtrlStatus[XcpChannel];
    for (DaqListIdx=0U;
        ((DaqListIdx < pChannelCtrlStatus->Xcp_DaqListStatus.NumOfDaqLists) && 
        (DaqListIdx < XCP_MAX_DAQ));DaqListIdx++)
    {
        if (((pChannelCtrlStatus->Xcp_DaqListStatus.DaqListMode[DaqListIdx] & XCP_DAQ_LIST_RUNNING ) != 0U) &&
            (pChannelCtrlStatus->Xcp_DaqListStatus.DaqToEventChannelMap[DaqListIdx] == EventChannel))
        {
            /* check for prescalar count expiry */
            if (pChannelCtrlStatus->Xcp_DaqListStatus.DaqListPrescalarCounter[DaqListIdx] > 0u)
            {
                pChannelCtrlStatus->Xcp_DaqListStatus.DaqListPrescalarCounter[DaqListIdx]--;
                if (pChannelCtrlStatus->Xcp_DaqListStatus.DaqListPrescalarCounter[DaqListIdx] == 0U)
                {
                    /* if prescalar count expired, then process the event stim/daq */
                    pChannelCtrlStatus->Xcp_DaqListStatus.DaqListPrescalarCounter[DaqListIdx] = 
                    pChannelCtrlStatus->Xcp_DaqListStatus.DaqListPrescalarInitialValue[DaqListIdx];                                   
                    # if( XCP_STIM == STD_ON )
                    if((pChannelCtrlStatus->Xcp_DaqListStatus.DaqListMode[DaqListIdx] & XCP_DAQ_FLAG_DIRECTION) > 0u )
                    {
                        RetVal |= Xcp_ProcessEventStim(XcpChannel, DaqListIdx);
                    }
                    else
                    # endif
                    {
                        RetVal |= Xcp_ProcessEventDaq(XcpChannel, DaqListIdx);
                    }
                }
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief  This API is used to process the transmission of response frame
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL FUNC(void, XCP_CODE) Xcp_SendCrm( Xcp_ChannelType XcpChannel )
{
    uint8 ErrorId = XCP_E_NO_ERROR;
    Xcp_TlSendFunctPtrType pTlSendFunct;
    Xcp_TlSendFlushFunctPtrType pTlSendFlushFunct;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
        else if (XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else
        {
            /* check if message already pending */
            if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & XCP_SEND_PENDING) != 0U)
            {
                if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & XCP_CRM_REQUEST) != 0U)
                {
                    /* if previous requested not transmitted the set sesion error */
                    Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= XCP_SESSION_ERROR;
                }
                Xcp_ChannelCtrlStatus[XcpChannel].SendStatus |= (uint8)XCP_CRM_REQUEST;
            }
            else
            {
                Xcp_ChannelCtrlStatus[XcpChannel].SendStatus |= (uint8)XCP_CRM_PENDING;
                pTlSendFunct = Xcp_TlConfig[Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl].TlSendFunctPtr;
                pTlSendFlushFunct = Xcp_TlConfig[Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl].TlSendFlushFunctPtrType;
                if (pTlSendFunct != NULL_PTR)
                {
                    /* Request transmit */
                    pTlSendFunct(XcpChannel, 
                                Xcp_ChannelCtrlStatus[XcpChannel].ResponseBufferLen,
                                &Xcp_ChannelCtrlStatus[XcpChannel].ResponseBuffer[0]);
                }
                /* request transmit flush */
                if (pTlSendFlushFunct != NULL_PTR)
                {
                    pTlSendFlushFunct(XcpChannel,XCP_FLUSH_CTO);
                }
            }
        }
    }
    
#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_SENDCRM_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief  This API is used to process the reserved/unknowm cmd 
*   @param[in] XcpChannel xcp channel idx 
*   @param[in] CmdPtr pointer to the command buffer  
********************************************************************************************************************/
XCP_LOCAL FUNC(void,XCP_CODE) Xcp_CmdProcessorReservedCmd
(
    Xcp_ChannelType XcpChannel, 
    CONSTP2CONST(uint8, AUTOMATIC, XCP_VAR_NOINIT ) CmdPtr
)
{
    Xcp_SetNegativeResponse(XcpChannel,XCP_ERR_CMD_UNKNOWN);
    XCP_DUMMY_STATEMENT(CmdPtr);
}
/********************************************************************************************************************
* @brief  This Api used to process the transmission of event data for the xcp channel
* @param[in] XcpChannel xcp channel idx
* @param[in] EventCode event code value
* @param[in] EventData pointer to the event data buffer
* @param[in] Length Length of the event data
********************************************************************************************************************/
#if(XCP_SEND_EVENT == STD_ON)
FUNC(void, XCP_CODE) Xcp_SendEvent
(
    Xcp_ChannelType XcpChannel,
    uint8 EventCode,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) EventData,
    uint8 Length 
)
{
    uint8 ErrorId = XCP_E_NO_ERROR;

    if (Xcp_ControlState == XCP_CONTROL_STATE_ENABLE)
    {
        /* Check for dev error */
        if (XCP_INIT_STATE_UNINTITIALIZED == Xcp_InitState)
        {
            ErrorId = XCP_E_UNINIT;
        }
	    else if(XCP_NUM_OF_CHANNELS <= XcpChannel)
        {
            ErrorId = XCP_E_INVALID_PARAM;
        }
        else if( EventData == NULL_PTR )
        {
            ErrorId = XCP_E_PARAM_POINTER;
        }
        else
        {
            /* check for no pending tx */
            if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)XCP_SEND_PENDING) != 0u)
            {   
                Xcp_ChannelCtrlStatus[XcpChannel].EventFrameBuffer[0] = XCP_PID_EV;
                Xcp_ChannelCtrlStatus[XcpChannel].EventFrameBuffer[1] = EventCode;
                Xcp_ChannelCtrlStatus[XcpChannel].EventFrameLength +=2u;

                if (Length <= XCP_SENDEVENT_MAX_LENGTH(XcpChannel))
                {
                    Xcp_UtilMemCopy(&Xcp_ChannelCtrlStatus[XcpChannel].EventFrameBuffer[2],&EventData[0],Length);
                    Xcp_ChannelCtrlStatus[XcpChannel].EventFrameLength += Length;
                }           
                else
                {
                    ErrorId = XCP_E_INVALID_PARAM;
                }
                Xcp_SendAsyncEvent(XcpChannel);
            }
        }
    }
#if (XCP_DEV_ERROR_DETECT == STD_ON)
    if (XCP_E_NO_ERROR != ErrorId)
    {
        Xcp_DetReportError(XCP_SENDEVENT_API, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
/********************************************************************************************************************
*   @brief  This API is used to send the async event for the Xcp channel
*   @param[in] XcpChannel xcp channel idx 
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(void, XCP_CODE) Xcp_SendAsyncEvent( Xcp_ChannelType XcpChannel )
{
    Xcp_TlSendFunctPtrType pTlSendFunct;

    Xcp_EnterCriticalSection();
    /* check for pending transmission and update session status */
    if ((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)XCP_SEND_PENDING) !=0U )
    {
        if((Xcp_ChannelCtrlStatus[XcpChannel].SendStatus & (uint8)XCP_EVT_REQUEST) != 0u )
        {
            Xcp_ChannelCtrlStatus[XcpChannel].SessionStatus |= (uint16)XCP_SESSION_ERROR;
        }
        Xcp_ChannelCtrlStatus[XcpChannel].SendStatus |= (uint8)XCP_EVT_REQUEST;
    }
    else
    {
        Xcp_ChannelCtrlStatus[XcpChannel].SendStatus |= (uint8)XCP_EVT_PENDING;
        pTlSendFunct = Xcp_TlConfig[Xcp_ChannelCtrlStatus[XcpChannel].ActiveTl].TlSendFunctPtr;
        if (pTlSendFunct != NULL_PTR)
        {
            pTlSendFunct(XcpChannel,Xcp_ChannelCtrlStatus[XcpChannel].EventFrameLength,
                        &Xcp_ChannelCtrlStatus[XcpChannel].EventFrameBuffer[0]);
            Xcp_ChannelCtrlStatus[XcpChannel].EventFrameLength = 0U;
        }
    }
    Xcp_ExitCriticalSection();
}
/********************************************************************************************************************
*   @brief  This API is used to get the xcp channel id from the network channel id .
*   @param[in] Channel Network channel idx 
*   @return Xcp channel idx if matched else XCP_NUM_OF_CHANNELS
********************************************************************************************************************/
XCP_LOCAL_INLINE FUNC(Xcp_ChannelType,XCP_CODE) Xcp_GetXcpChannelFromNetworkChannel(NetworkHandleType Channel)
{
    Xcp_ChannelType XcpChannel;
    for (XcpChannel = 0U;XcpChannel < XCP_NUM_OF_CHANNELS; XcpChannel++)
    {
        if (Xcp_ChannelConfig[XcpChannel].NetworkChannelId == Channel)
        {
            break;
        }
    }
    return XcpChannel;
}
#define XCP_STOP_SEC_CODE
#include "MemMap.h" 
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    30-Apr-2024
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

