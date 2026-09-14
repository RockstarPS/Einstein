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
/*!*****************************************************************************************************************
*   @file EthSM.c
*   @ingroup EthSM
*   @brief This file implements the AUTOSAR EthSM module.The EthSM module is responsible for providing abstract 
*   interface to the AUTOSAR Communication Manager to startup or shutdown the communication on an Ethernet cluster
*   by accessing Ethernet Interface layer to control the Ethernet HW i,e Controllers, Transceivers and switches.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthSM.h"              
#include "EthSM_Cbk.h"  
#include "EthSM_Lcfg.h"
#include "ComM_BusSM.h" 
#include "BswM_EthSM.h"  
#include "TcpIp_EthSM.h" 
#if (ETHSM_DUMMY_MODE == STD_OFF)
#include "EthIf.h"              
#endif      
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
#include "Dem.h"
#endif
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif


/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((ETHSM_SW_MAJOR_VERSION != ETHSM_CFG_SW_MAJOR_VERSION) || \
    (ETHSM_SW_MINOR_VERSION != ETHSM_CFG_SW_MINOR_VERSION) || \
    (ETHSM_SW_PATCH_VERSION != ETHSM_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((ETHSM_AR_RELEASE_MAJOR_VERSION != ETHSM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ETHSM_AR_RELEASE_MINOR_VERSION != ETHSM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ETHSM_AR_RELEASE_REVISION_VERSION != ETHSM_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef ETHSM_LOCAL 
#define ETHSM_LOCAL                             static
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE                            static inline
#endif

#ifndef ETHSM_LOCAL_INLINE
#define ETHSM_LOCAL_INLINE                      LOCAL_INLINE
#endif

#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
#define EthSM_DetReportError(ApiId,ErrId) (void)Det_ReportError(ETHSM_MODULE_ID,ETHSM_INSTANCE_ID,(ApiId),(ErrId))
#else
#define EthSM_DetReportError(ApiId,ErrId)    
#endif

/* Mode request owners */
#define	ETHSM_COMM_MODE_REQUEST                 0u
#define	ETHSM_ETHIF_ETH_MODE_REQUEST            1u
#define	ETHSM_ETHIF_ETHTRCV_MODE_REQUEST        2u
#define ETHSM_TCPIP_MODE_REQUEST                3u

#define ETHSM_INVALID_HANDLE                    0xFFu
#define ETHSM_INVALID_CTRL                      0xFFu

#define ETHSM_MODE_REQUEST_CLEAR(handle, owner)  (EthSM_NetworkStatus[handle].RequestStream &= (~(1u << owner)))

#define ETHSM_MODE_REQUEST_SET(handle, owner )   (EthSM_NetworkStatus[handle].RequestStream |=  (1u << owner))

#define ETHSM_MODE_POS(owner)  (1u << owner)

#define ETHSM_GET_CHANNEL(handle ) (pEthSMConfig->pNetworkConfig[handle].EthSMComMNetworkHandle)

#define ETHSM_GET_CTRL_IDX(handle ) (pEthSMConfig->pNetworkConfig[handle].EthSMEthIfControllerId)

#define ETHSM_GET_TRCV_AVAIL_STATUS(handle ) (pEthSMConfig->pNetworkConfig[handle].EthSMIsEthTrcvAvailable)
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
#define ETHSM_GET_DEM_LINK_DOWN_EVENT_ID(handle ) (pEthSMConfig->pNetworkConfig[handle].EthSMLinkDownDemEventId)
#endif
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the EthSM init status type */
typedef enum 
{    
    ETHSM_STATUS_UNINIT=0U, /* EthSM not initialized */   
    ETHSM_STATUS_INIT       /*! @brief EthSM initialized */      
} EthSM_InitStatusType;

/*! @brief Defines the EthSM Network status type */
typedef struct 
{
    ComM_ModeType               RequestedMode;  /*! @brief holds network Request mode */
    ComM_ModeType               CurrentMode;    /*! @brief holds current mode of network */
    TcpIp_StateType             TcpIpState;     /*! @brief holds TCP/IP state of network  */
    EthTrcv_LinkStateType       TrcvLinkState;  /*! @brief holds Trcv Link state of network  */
    EthSM_NetworkModeStateType  NetworkMode;    /*! @brief states of the network mode of state machine */
    Eth_ModeType                CtrlMode;       /*! @brief holds the Eth controller mode */
    EthTrcv_ModeType            TrcvMode;       /*! @brief holds the EthTrcv  mode */
    uint8                       RequestStream;  /*! @brief holds request for network is done or not status*/
} EthSM_NetworkStatusType;

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
static EthSM_InitStatusType EthSM_InitStatus = ETHSM_STATUS_UNINIT;
static EthSM_NetworkStatusType EthSM_NetworkStatus[ETHSM_NUM_OF_NETWORKS];
const  EthSM_ConfigType * pEthSMConfig = &EthSM_Config;

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define ETHSM_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      This service process for EthSM full com state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComStateHandler(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service process for EthSM No Com state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_NoComStateHandler(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to check the tranciever link state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  LinkState Link state of the Transceivers for the Network
*   @param[in]  Active Flag to by pass the check
*   @return     status of the request TRUE : Link state is same : link state is different
********************************************************************************************************************/
ETHSM_LOCAL_INLINE FUNC(boolean,ETHSM_CODE) EthSM_CheckTrcvLink
(
    NetworkHandleType NetworkHandle,
    EthTrcv_LinkStateType LinkState,
    boolean Active
);
/*!******************************************************************************************************************
*   @brief      This service is used to check the tranciever mode is same as requested mode
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  Mode Requested Transceivers mode for the Network
*   @return     status of the request TRUE : Mode is same FALSE : Mode is different
********************************************************************************************************************/
ETHSM_LOCAL_INLINE FUNC(boolean,ETHSM_CODE) EthSM_CheckTrcvMode(NetworkHandleType NetworkHandle, EthTrcv_ModeType Mode);
/*!******************************************************************************************************************
*   @brief      This service is used to check the CtrlIdx is valid
*   @param[in]  CtrlIdx Ethernet controller Id
*   @return     CtrlIdx for valid ctrl else invalid ctrl id ETHSM_INVALID_CTRL
********************************************************************************************************************/
ETHSM_LOCAL FUNC(uint8,ETHSM_CODE) EthSM_CheckEthIfCtrl ( uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is used to get the NetworkHandle from the CtrlIdx
*   @param[in]  CtrlIdx Ethernet controller Id
*   @return     networkHandle for valid handle , else invalid network handle ETHSM_INVALID_HANDLE
********************************************************************************************************************/
ETHSM_LOCAL FUNC(NetworkHandleType,ETHSM_CODE) EthSM_GetNetworkHandleEth ( uint8 CtrlIdx);
/*!******************************************************************************************************************
*   @brief      This service is used to get the EthSM NetworkHandle from the ComM NetworkHandle
*   @param[in]  Channel ComM NetworkHandle Id
*   @return     networkHandle for valid handle , else invalid network handle ETHSM_INVALID_HANDLE
********************************************************************************************************************/
ETHSM_LOCAL FUNC(NetworkHandleType,ETHSM_CODE) EthSM_GetNetworkHandleComM ( NetworkHandleType Channel);
/*!******************************************************************************************************************
*   @brief      This service is used to update the Network state and notify the upper layer
*   @param[in]  NetworkHandle  Network handle id
*   @param[in]  State  Network state to be updated
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_ChangeNetworkModeState 
( 
    NetworkHandleType NetworkHandle,
    EthSM_NetworkModeStateType State
);
/*!******************************************************************************************************************
*   @brief      This service is used to Enables or disables Ethernet controller and Ethernet tranciever
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_RequestEthIfModeChg(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to change the Requests mode of TcpIp module
*   @param[in]  NetworkHandle  Network handle id
*   @param[in]  State  TcpIp state to be updated
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_RequestTcpIpModeChg( NetworkHandleType NetworkHandle,TcpIp_StateType State);
/*!******************************************************************************************************************
*   @brief      This service is used to Gets and updates the individual controller modes of mapped Ethernet interface
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_UpdateControllerMode(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to handle the FULL communication WaitOnline state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComWaitOnlineStateHandler(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to handle the FULL communication Online state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComOnlineSMStateHandler(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to handle the FULL communication OnHold state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComOnHoldSMStateHandler(NetworkHandleType NetworkHandle);
/*!******************************************************************************************************************
*   @brief      This service is used to transfer to offline mode
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_TransferOfflineStateHandler(NetworkHandleType NetworkHandle);

#define ETHSM_STOP_SEC_CODE
#include "MemMap.h"

#define ETHSM_START_SEC_CODE
#include "MemMap.h"
/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This function initialize the EthSM.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, ETHSM_CODE) EthSM_Init( void )
{
    NetworkHandleType NetworkHandle;
    
    for ( NetworkHandle = 0; NetworkHandle < ETHSM_NUM_OF_NETWORKS; NetworkHandle++) 
    {
        EthSM_NetworkStatus[NetworkHandle].RequestedMode = COMM_NO_COMMUNICATION;
        EthSM_NetworkStatus[NetworkHandle].CurrentMode   = COMM_NO_COMMUNICATION;
        EthSM_NetworkStatus[NetworkHandle].NetworkMode   = ETHSM_STATE_OFFLINE;
        EthSM_NetworkStatus[NetworkHandle].TrcvLinkState = ETHTRCV_LINK_STATE_DOWN;
        EthSM_NetworkStatus[NetworkHandle].CtrlMode      = ETH_MODE_DOWN;
        EthSM_NetworkStatus[NetworkHandle].TrcvMode      = ETHTRCV_MODE_DOWN;
        EthSM_NetworkStatus[NetworkHandle].RequestStream = 0;
        EthSM_NetworkStatus[NetworkHandle].TcpIpState    = TCPIP_STATE_OFFLINE;
    }
    EthSM_InitStatus = ETHSM_STATUS_INIT;
}   
#if (ETHSM_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service puts out the version information of this module.
*   @param[out] versioninfo Pointer where to put out the version information
*   @ServiceID  0x02
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void, ETHSM_CODE) EthSM_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ETHSM_APPL_VAR) versioninfo )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    
    if (NULL_PTR == versioninfo)
    {
        ErrorId = ETHSM_E_PARAM_POINTER;   
    }
    else
    {
        versioninfo->moduleID = ETHSM_MODULE_ID;  
        versioninfo->vendorID = ETHSM_VENDOR_ID;  
        versioninfo->sw_major_version = ETHSM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ETHSM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ETHSM_SW_PATCH_VERSION;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_GETVERSIONINFO_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif

}    
#endif
/********************************************************************************************************************
*   @brief      Handles the communication mode and sets the Ethernet network active or passive.
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  ComM_Mode Requested communication mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x05
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,ETHSM_CODE) EthSM_RequestComMode( NetworkHandleType NetworkHandle, ComM_ModeType ComM_Mode )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    NetworkHandleType EthSMNetworkHandle = EthSM_GetNetworkHandleComM(NetworkHandle);
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_NUM_OF_NETWORKS <= EthSMNetworkHandle)
    {
        ErrorId = ETHSM_E_INVALID_NETWORK_HANDLE;   
    }
    else if (COMM_FULL_COMMUNICATION < ComM_Mode)
    {
        ErrorId = ETHSM_E_INVALID_NETWORK_MODE;   
    }
    else
    {
        EthSM_NetworkStatus[EthSMNetworkHandle].RequestedMode = ComM_Mode;
        #if (ETHSM_DUMMY_MODE == STD_ON) 
        if(ComM_Mode == COMM_FULL_COMMUNICATION)
        {
            EthSM_NetworkStatus[EthSMNetworkHandle].CtrlMode = ETH_MODE_ACTIVE;
            EthSM_NetworkStatus[EthSMNetworkHandle].TrcvMode = ETHTRCV_MODE_ACTIVE;
        }
        else if(ComM_Mode == COMM_NO_COMMUNICATION)
        {
            EthSM_NetworkStatus[EthSMNetworkHandle].CtrlMode = ETH_MODE_DOWN;
            EthSM_NetworkStatus[EthSMNetworkHandle].TrcvMode = ETHTRCV_MODE_DOWN;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        RetVal = E_OK;
    }

#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_REQUESTCOMMODE_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}   
/********************************************************************************************************************
*   @brief      This service shall put out the current communication mode of a Ethernet network.
*   @param[in]  NetworkHandle Network handle whose current communication mode shall be put out
*   @param[out  ComM_ModePtr Pointer where to put out the current communication mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,ETHSM_CODE) EthSM_GetCurrentComMode
( 
    NetworkHandleType NetworkHandle,
    P2VAR(ComM_ModeType,AUTOMATIC,ETHSM_APPL_VAR) ComM_ModePtr 
)
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    NetworkHandleType EthSMNetworkHandle = EthSM_GetNetworkHandleComM(NetworkHandle);
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_NUM_OF_NETWORKS <= EthSMNetworkHandle)
    {
        ErrorId = ETHSM_E_INVALID_NETWORK_HANDLE;   
    }
    else if (NULL_PTR == ComM_ModePtr)
    {
        ErrorId = ETHSM_E_PARAM_POINTER;   
    }
    else
    {
        *ComM_ModePtr = EthSM_NetworkStatus[EthSMNetworkHandle].CurrentMode;
        RetVal = E_OK;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_GETCURRENTCOMMODE_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;    
}   
/********************************************************************************************************************
*   @brief      This service shall put out the current internal mode of a Ethernet network.
*   @param[in]  NetworkHandle Network handle whose current communication mode shall be put out
*   @param[out  EthSM_InternalMode Pointer where to put out the current internal mode
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType,ETHSM_CODE) EthSM_GetCurrentInternalMode
( 
    NetworkHandleType NetworkHandle, 
    P2VAR(EthSM_NetworkModeStateType,AUTOMATIC,ETHSM_APPL_VAR) EthSM_InternalMode
)
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    NetworkHandleType EthSMNetworkHandle = EthSM_GetNetworkHandleComM(NetworkHandle);
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_NUM_OF_NETWORKS <= EthSMNetworkHandle)
    {
        ErrorId = ETHSM_E_INVALID_NETWORK_HANDLE;   
    }
    else if (NULL_PTR == EthSM_InternalMode)
    {
        ErrorId = ETHSM_E_PARAM_POINTER;   
    }
    else
    {
        *EthSM_InternalMode = EthSM_NetworkStatus[EthSMNetworkHandle].NetworkMode;
        RetVal = E_OK;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_GETCURRENTINTERNALMODE_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;    
}   

/********************************************************************************************************************
*   @brief      Cyclic Main Function which is called from the Scheduler.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void,ETHSM_CODE) EthSM_MainFunction( void )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    NetworkHandleType NetworkHandle;
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else
    {
        for (NetworkHandle = 0; NetworkHandle < ETHSM_NUM_OF_NETWORKS; NetworkHandle++) 
        {
            if(EthSM_NetworkStatus[NetworkHandle].RequestedMode == COMM_FULL_COMMUNICATION)
            {
                EthSM_FullComStateHandler(NetworkHandle);
            }
            else if(EthSM_NetworkStatus[NetworkHandle].RequestedMode == COMM_NO_COMMUNICATION)
            {
                EthSM_NoComStateHandler(NetworkHandle);
            }
            else
            {
                /* Do nothing for COMM_SILENT_COMMUNICATION */
            }
        }
    }
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_MAINFUNCTION_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif
}   

/********************************************************************************************************************
*   @brief      Called when mode has been read out. Either triggered by previous EthIf_GetControllerMode or by 
*   EthIf_SetControllerMode call. Can directly be called within the trigger functions.
*   @param[in]  CtrlIdx Ethernet controller whose mode has changed
*   @param[in]  CtrlMode Notified Ethernet controller mode
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different Ethernet controllers)
********************************************************************************************************************/
FUNC(void, ETHSM_CODE) EthSM_CtrlModeIndication ( uint8 CtrlIdx, Eth_ModeType CtrlMode )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if ((ETHSM_INVALID_CTRL == EthSM_CheckEthIfCtrl(CtrlIdx)))
    {
        ErrorId = ETHSM_E_PARAM_CONTROLLER;   
    }
    else
    {
        NetworkHandleType NetworkHandle =  EthSM_GetNetworkHandleEth(CtrlIdx);
        ETHSM_MODE_REQUEST_CLEAR(NetworkHandle,ETHSM_ETHIF_ETH_MODE_REQUEST);
        EthSM_NetworkStatus[NetworkHandle].CtrlMode  = CtrlMode;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_CTRLMODEINDICATION_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif  
    
}
/********************************************************************************************************************
*   @brief      Called when mode has been read out. Either triggered by previous EthIf_GetTransceiverMode or by 
*   EthIf_SetTransceiverMode call. Can directly be called within the trigger functions.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  TrcvMode Notified Ethernet transceiver mode
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (only for different Ethernet controllers)
********************************************************************************************************************/
FUNC(void, ETHSM_CODE) EthSM_TrcvModeIndication ( uint8 CtrlIdx, EthTrcv_ModeType TrcvMode )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    NetworkHandleType NetworkHandle;
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_INVALID_CTRL == EthSM_CheckEthIfCtrl(CtrlIdx))
    {
        ErrorId = ETHSM_E_PARAM_CONTROLLER;   
    }
    else
    {
        NetworkHandle =  EthSM_GetNetworkHandleEth(CtrlIdx);
        ETHSM_MODE_REQUEST_CLEAR(NetworkHandle,ETHSM_ETHIF_ETHTRCV_MODE_REQUEST);
        EthSM_NetworkStatus[NetworkHandle].TrcvMode = TrcvMode;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_TRCVMODEINDICATION_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif   
}
/********************************************************************************************************************
*   @brief      This service is called by the Ethernet Interface to report a transceiver link state change.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  TransceiverLinkState Actual transceiver link state of the specific network handle
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
FUNC(void, ETHSM_CODE) EthSM_TrcvLinkStateChg( uint8 CtrlIdx, EthTrcv_LinkStateType TransceiverLinkState )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_INVALID_CTRL == EthSM_CheckEthIfCtrl(CtrlIdx))
    {
        ErrorId = ETHSM_E_PARAM_CONTROLLER;   
    }
    else 
    {
        if (ETHTRCV_LINK_STATE_ACTIVE >= TransceiverLinkState)
        {
            EthSM_NetworkStatus[EthSM_GetNetworkHandleEth(CtrlIdx)].TrcvLinkState = TransceiverLinkState;
        }
    }
   
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_TRCVLINKSTATECHG_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif    
}
/********************************************************************************************************************
*   @brief      This service is called by the TcpIp to report the actual TcpIp state (e.g. online, offline).
*   @param[in]  CtrlIdx EthIf controller index to identify the communication network where the TcpIp state is changed
*   @param[in]  TcpIpState Actual TcpIp state of the specific network handle
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
FUNC(Std_ReturnType,ETHSM_CODE) EthSM_TcpIpModeIndication( uint8 CtrlIdx, TcpIp_StateType TcpIpState )
{
    uint8 ErrorId = ETHSM_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    NetworkHandleType NetworkHandle;
    
    if (ETHSM_STATUS_INIT != EthSM_InitStatus)
    {
        ErrorId = ETHSM_E_UNINIT;   
    }
    else if (ETHSM_INVALID_CTRL == EthSM_CheckEthIfCtrl(CtrlIdx))
    {
        ErrorId = ETHSM_E_PARAM_CONTROLLER;   
    }
    else if (TCPIP_STATE_SHUTDOWN < TcpIpState)
    {
        ErrorId = ETHSM_E_INVALID_TCP_IP_MODE;   
    }
    else
    {
        NetworkHandle =  EthSM_GetNetworkHandleEth(CtrlIdx);
        ETHSM_MODE_REQUEST_CLEAR(NetworkHandle,ETHSM_TCPIP_MODE_REQUEST);
        EthSM_NetworkStatus[NetworkHandle].TcpIpState = TcpIpState;
        RetVal = E_OK;
    }
    
#if (ETHSM_DEV_ERROR_DETECT == STD_ON)
    if (ETHSM_E_NO_ERROR != ErrorId)
    {
        EthSM_DetReportError(ETHSM_GETCURRENTINTERNALMODE_API, ErrorId);
    }
#else
    ETHSM_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;    
}

/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This service process for EthSM full com state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComStateHandler(NetworkHandleType NetworkHandle)
{    
    switch (EthSM_NetworkStatus[NetworkHandle].NetworkMode)
    {
        case ETHSM_STATE_OFFLINE:
            EthSM_UpdateControllerMode(NetworkHandle);
            if((TRUE == EthSM_CheckTrcvMode(NetworkHandle, ETHTRCV_MODE_ACTIVE)) && 
               (EthSM_NetworkStatus[NetworkHandle].CtrlMode == ETH_MODE_ACTIVE))
            {
                EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_TRCVLINK);
            }
            else
            {
                EthSM_RequestEthIfModeChg(NetworkHandle);
            }
            break;
        case ETHSM_STATE_WAIT_TRCVLINK:
            if(TRUE == EthSM_CheckTrcvLink(NetworkHandle, ETHTRCV_LINK_STATE_ACTIVE, TRUE))
            {
                if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_ONLINE)
                {
                    EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_ONLINE);
                }
                else
                {
                    EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_ONLINE);
                }
            }
            break;
        case ETHSM_STATE_WAIT_ONLINE:
            EthSM_FullComWaitOnlineStateHandler(NetworkHandle);
            break;
        case ETHSM_STATE_ONLINE:
            EthSM_FullComOnlineSMStateHandler(NetworkHandle);
            break;
        case ETHSM_STATE_ONHOLD:
            EthSM_FullComOnHoldSMStateHandler(NetworkHandle);
            break;
        default:
            break;
    }
}

/********************************************************************************************************************
*   @brief      This service process for EthSM No Com state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_NoComStateHandler(NetworkHandleType NetworkHandle)
{
    NetworkHandleType Channel;
    Channel = ETHSM_GET_CHANNEL(NetworkHandle);
    switch (EthSM_NetworkStatus[NetworkHandle].NetworkMode)
    {
        case ETHSM_STATE_WAIT_TRCVLINK:
            EthSM_UpdateControllerMode(NetworkHandle);
            if((EthSM_NetworkStatus[NetworkHandle].CtrlMode == ETH_MODE_DOWN) && 
               (TRUE == EthSM_CheckTrcvMode(NetworkHandle, ETHTRCV_MODE_DOWN)))
            {
                EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_OFFLINE);
            }else
            {
                EthSM_RequestEthIfModeChg(NetworkHandle);
            }
            break;
        case ETHSM_STATE_WAIT_ONLINE:
            EthSM_TransferOfflineStateHandler(NetworkHandle);
            break;
        case ETHSM_STATE_ONLINE:
            if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_OFFLINE)
            {
                EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_OFFLINE);
            }
            else
            {
                EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_OFFLINE);
            }
            break;
        case ETHSM_STATE_ONHOLD:
            EthSM_TransferOfflineStateHandler(NetworkHandle);
            if(EthSM_NetworkStatus[NetworkHandle].NetworkMode == ETHSM_STATE_ONHOLD)
            {
                ComM_BusSM_ModeIndication(Channel, &EthSM_NetworkStatus[NetworkHandle].CurrentMode);
            }
            break;
        case ETHSM_STATE_WAIT_OFFLINE:
            EthSM_UpdateControllerMode(NetworkHandle);
            if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_OFFLINE)
            {
                if((EthSM_NetworkStatus[NetworkHandle].CtrlMode == ETH_MODE_DOWN) && 
                   (TRUE == EthSM_CheckTrcvMode(NetworkHandle, ETHTRCV_MODE_DOWN)))
                {
                    EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_OFFLINE);
                    ComM_BusSM_ModeIndication(Channel, &EthSM_NetworkStatus[NetworkHandle].CurrentMode);
                }
                else
                {
                    EthSM_RequestEthIfModeChg(NetworkHandle);
                }
            }
            break;
        case ETHSM_STATE_OFFLINE:
            break;
        default:
            break;
    }
}

/********************************************************************************************************************
*   @brief      This service is used to check the tranciever link state 
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  LinkState Link state of the Transceivers for the Network
*   @param[in]  Active Flag to by pass the check
*   @return     status of the request TRUE : Link state is same : link state is different
********************************************************************************************************************/
ETHSM_LOCAL_INLINE FUNC(boolean,ETHSM_CODE) EthSM_CheckTrcvLink
(
    NetworkHandleType NetworkHandle,
    EthTrcv_LinkStateType LinkState,
    boolean Active
)
{
    boolean TrcvLinkStatus;

#if(ETHSM_DUMMY_MODE == STD_ON)
    TrcvLinkStatus = Active;
#else
#if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
    if(TRUE == ETHSM_GET_TRCV_AVAIL_STATUS(NetworkHandle))
    {
        if(LinkState == EthSM_NetworkStatus[NetworkHandle].TrcvLinkState )
        {
            TrcvLinkStatus = TRUE;
        }
        else
        {
            TrcvLinkStatus = FALSE;
        }
    }
    else 
    {
        if(TRUE == Active)
        {
            TrcvLinkStatus = TRUE;   /* TRUE means By pass TRCV State making TRUE by default */
        }
        else 
        {
            TrcvLinkStatus = FALSE;  /* FALSE means no need to enter TRCV related state since no Support */
        }
    }
#else
    TrcvLinkStatus = Active;
#endif
#endif
    return TrcvLinkStatus;
}

/********************************************************************************************************************
*   @brief      This service is used to check the tranciever mode is same as requested mode
*   @param[in]  NetworkHandle Handle of destinated communication network for request
*   @param[in]  Mode Requested Transceivers mode for the Network
*   @return     status of the request TRUE : Mode is same FALSE : Mode is different
********************************************************************************************************************/
ETHSM_LOCAL_INLINE FUNC(boolean,ETHSM_CODE) EthSM_CheckTrcvMode(NetworkHandleType NetworkHandle, EthTrcv_ModeType Mode)
{
    boolean TrcvStatus;
    
#if(ETHSM_DUMMY_MODE == STD_ON)
    TrcvStatus = TRUE;
#else
#if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
    if(TRUE == ETHSM_GET_TRCV_AVAIL_STATUS(NetworkHandle))
    {
        if(Mode == EthSM_NetworkStatus[NetworkHandle].TrcvMode )
        {
            TrcvStatus = TRUE;
        }else 
        {
            TrcvStatus = FALSE;
        }
    }
    else
    {
        TrcvStatus = TRUE;
    }
#else
    TrcvStatus = TRUE;
#endif
#endif
    return TrcvStatus;
}

/********************************************************************************************************************
*   @brief      This service is used to check the CtrlIdx is valid
*   @param[in]  CtrlIdx Ethernet controller Id
*   @return     CtrlIdx for valid ctrl else invalid ctrl id ETHSM_INVALID_CTRL
********************************************************************************************************************/
ETHSM_LOCAL FUNC(uint8,ETHSM_CODE) EthSM_CheckEthIfCtrl ( uint8 CtrlIdx)
{
    uint8 Id;
    uint8 RetId = ETHSM_INVALID_CTRL;
    for (Id = 0; Id < ETHSM_NUM_OF_NETWORKS; Id++)
    {
        if(Id == ETHSM_GET_CTRL_IDX(Id)) 
        {
            RetId = Id;
            break;
        }
    }
    return RetId;
}
/********************************************************************************************************************
*   @brief      This service is used to get the NetworkHandle from the CtrlIdx
*   @param[in]  CtrlIdx Ethernet controller Id
*   @return     networkHandle for valid handle , else invalid network handle ETHSM_INVALID_HANDLE
********************************************************************************************************************/
ETHSM_LOCAL FUNC(NetworkHandleType,ETHSM_CODE) EthSM_GetNetworkHandleEth ( uint8 CtrlIdx)
{
    NetworkHandleType NetworkHandle;
    NetworkHandleType RetNetworkHandle=ETHSM_INVALID_HANDLE;
    for (NetworkHandle = 0; NetworkHandle < ETHSM_NUM_OF_NETWORKS; NetworkHandle++) 
    {
        if(CtrlIdx == ETHSM_GET_CTRL_IDX(NetworkHandle)) 
        {
            RetNetworkHandle = NetworkHandle;
            break;
        }
    }
    return RetNetworkHandle;
}

/********************************************************************************************************************
*   @brief      This service is used to get the EthSM NetworkHandle from the ComM NetworkHandle
*   @param[in]  Channel ComM NetworkHandle Id
*   @return     networkHandle for valid handle , else invalid network handle ETHSM_INVALID_HANDLE
********************************************************************************************************************/
ETHSM_LOCAL FUNC(NetworkHandleType,ETHSM_CODE) EthSM_GetNetworkHandleComM ( NetworkHandleType Channel)
{
    NetworkHandleType HandleId;
    NetworkHandleType RetHandleId=ETHSM_INVALID_HANDLE;
    for (HandleId = 0; HandleId < ETHSM_NUM_OF_NETWORKS; HandleId++)
    {
        if(Channel == ETHSM_GET_CHANNEL(HandleId))
        {
            RetHandleId = Channel;
            break;
        }
    }
    return RetHandleId;
}

/********************************************************************************************************************
*   @brief      This service is used to update the Network state and notify the upper layer
*   @param[in]  NetworkHandle  Network handle id
*   @param[in]  State  Network state to be updated
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_ChangeNetworkModeState 
( 
    NetworkHandleType NetworkHandle,
    EthSM_NetworkModeStateType State
)
{
    EthSM_NetworkStatus[NetworkHandle].NetworkMode  = State;
    switch (EthSM_NetworkStatus[NetworkHandle].NetworkMode)
    {
        case ETHSM_STATE_OFFLINE:
        case ETHSM_STATE_WAIT_TRCVLINK:
        case ETHSM_STATE_WAIT_ONLINE:
            EthSM_NetworkStatus[NetworkHandle].CurrentMode = COMM_NO_COMMUNICATION;
        break;
        case ETHSM_STATE_ONLINE:
        case ETHSM_STATE_ONHOLD:
        case ETHSM_STATE_WAIT_OFFLINE:
            EthSM_NetworkStatus[NetworkHandle].CurrentMode = COMM_FULL_COMMUNICATION;
        break;
        default:
        break;
    }

    BswM_EthSM_CurrentState(ETHSM_GET_CHANNEL(NetworkHandle),State);

}

/********************************************************************************************************************
*   @brief      This service is used to Enables or disables Ethernet controller and Ethernet tranciever
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_RequestEthIfModeChg(NetworkHandleType NetworkHandle) 
{
    if(((EthSM_NetworkStatus[NetworkHandle].RequestStream & (ETHSM_MODE_POS(ETHSM_ETHIF_ETH_MODE_REQUEST))) != (ETHSM_MODE_POS(ETHSM_ETHIF_ETH_MODE_REQUEST))) &&
    ((EthSM_NetworkStatus[NetworkHandle].RequestStream & (ETHSM_MODE_POS(ETHSM_ETHIF_ETHTRCV_MODE_REQUEST))) != (ETHSM_MODE_POS(ETHSM_ETHIF_ETHTRCV_MODE_REQUEST))))
    {
        ETHSM_MODE_REQUEST_SET(NetworkHandle,ETHSM_ETHIF_ETH_MODE_REQUEST);
        #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
        if(STD_ON == ETHSM_GET_TRCV_AVAIL_STATUS(NetworkHandle))
        {
            ETHSM_MODE_REQUEST_SET(NetworkHandle,ETHSM_ETHIF_ETHTRCV_MODE_REQUEST);
        }
        #endif

        #if (ETHSM_DUMMY_MODE != STD_ON)
        boolean status;
        status = TRUE;
        uint8 CtrlIdx;
        Eth_ModeType CtrlMode;
        CtrlMode = ETH_MODE_DOWN;
        #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
        EthTrcv_ModeType TrcvMode;
        TrcvMode = ETHTRCV_MODE_DOWN;
        #endif
        CtrlIdx = ETHSM_GET_CTRL_IDX(NetworkHandle);
        switch (EthSM_NetworkStatus[NetworkHandle].RequestedMode)
        {
            case COMM_NO_COMMUNICATION:
                CtrlMode = ETH_MODE_DOWN;
        #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
                TrcvMode = ETHTRCV_MODE_DOWN;
        #endif
                break;
            case COMM_FULL_COMMUNICATION:
                CtrlMode = ETH_MODE_ACTIVE;
        #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
                TrcvMode = ETHTRCV_MODE_ACTIVE;
        #endif
                break;
            default:
                status = FALSE;
                break;
        }
        if (status == TRUE) 
        {
            if (E_OK == EthIf_SetControllerMode (CtrlIdx,CtrlMode))
            {
                #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
                if(STD_ON == ETHSM_GET_TRCV_AVAIL_STATUS(NetworkHandle) )
                {
                    (void) EthIf_SetTransceiverMode(CtrlIdx,TrcvMode);
                }
                #endif
            }
        }
        #endif
    }
}

/********************************************************************************************************************
*   @brief      This service is used to change the Requests mode of TcpIp module
*   @param[in]  NetworkHandle  Network handle id
*   @param[in]  State  TcpIp state to be updated
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_RequestTcpIpModeChg( NetworkHandleType NetworkHandle,TcpIp_StateType State)
{
    if((EthSM_NetworkStatus[NetworkHandle].RequestStream & (ETHSM_MODE_POS(ETHSM_TCPIP_MODE_REQUEST))) != (ETHSM_MODE_POS(ETHSM_TCPIP_MODE_REQUEST)))
    {
        ETHSM_MODE_REQUEST_SET(NetworkHandle,ETHSM_TCPIP_MODE_REQUEST);
        #if !defined(CFG_ETHSM_TCPIP_NO_SYNC)
        (void) TcpIp_RequestComMode(ETHSM_GET_CTRL_IDX(NetworkHandle),State);
        #else
        EthSM_NetworkStatus[NetworkHandle].TcpIpState = State;
        #endif
    }
}

/********************************************************************************************************************
*   @brief      This service is used to Gets and updates the individual controller modes of mapped Ethernet interface
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_UpdateControllerMode(NetworkHandleType NetworkHandle)
{
    #if (ETHSM_DUMMY_MODE != STD_ON)
    uint8 CtrlIdx;
    Std_ReturnType RetVal;
    Eth_ModeType CtrlMode;
    #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
    EthTrcv_ModeType TrcvMode;
    #endif
    CtrlIdx = ETHSM_GET_CTRL_IDX(NetworkHandle);
    RetVal = EthIf_GetControllerMode(CtrlIdx,&CtrlMode);
    if(RetVal == E_OK)
    {
        EthSM_NetworkStatus[NetworkHandle].CtrlMode  = CtrlMode;
        #if (ETHSM_ETH_TRCV_SUPPORT == STD_ON)
        if(TRUE == ETHSM_GET_TRCV_AVAIL_STATUS(NetworkHandle))
        {
            RetVal = EthIf_GetTransceiverMode(CtrlIdx,&TrcvMode);
            if(RetVal == E_OK)
            {
                EthSM_NetworkStatus[NetworkHandle].TrcvMode  = TrcvMode;
            }
        }
        #endif
    }
    #else
    ETHSM_DUMMY_STATEMENT(NetworkHandle);
    #endif
}

/********************************************************************************************************************
*   @brief      This service is used to handle the FULL communication WaitOnline state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComWaitOnlineStateHandler(NetworkHandleType NetworkHandle)
{
    NetworkHandleType Channel = ETHSM_GET_CHANNEL(NetworkHandle);

    if(TRUE == EthSM_CheckTrcvLink(NetworkHandle, ETHTRCV_LINK_STATE_DOWN, FALSE))
    {
        if(TCPIP_STATE_OFFLINE == EthSM_NetworkStatus[NetworkHandle].TcpIpState )
        {
            EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_TRCVLINK);
        }
        else
        {
            EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_OFFLINE);
        }
    }
    else if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_ONLINE)
    {
        EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_ONLINE);
        ComM_BusSM_ModeIndication(Channel, &EthSM_NetworkStatus[NetworkHandle].CurrentMode);
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is used to handle the FULL communication Online state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComOnlineSMStateHandler(NetworkHandleType NetworkHandle)
{
    NetworkHandleType Channel = ETHSM_GET_CHANNEL(NetworkHandle);
    if(TRUE == EthSM_CheckTrcvLink(NetworkHandle, ETHTRCV_LINK_STATE_DOWN, FALSE))
    {
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
        Dem_ReportErrorStatus(ETHSM_GET_DEM_LINK_DOWN_EVENT_ID(NetworkHandle), DEM_EVENT_STATUS_FAILED);
#endif
        if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_ONHOLD)
        {
            EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_ONHOLD);
        }
        else
        {
            EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_ONHOLD);
        }
    }
    
    if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_OFFLINE)
    {
        EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_ONLINE);
        ComM_BusSM_ModeIndication(Channel, &EthSM_NetworkStatus[NetworkHandle].CurrentMode);
        /* Note: The ntw state will reach ETHSM_STATE_WAIT_ONLINE, who will set up TCP active again?,
         * no specification in Autosar, it will be hung in ETHSM_STATE_WAIT_ONLINE as long as link state is active */
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is used to handle the FULL communication OnHold state
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_FullComOnHoldSMStateHandler(NetworkHandleType NetworkHandle)
{
    NetworkHandleType Channel = ETHSM_GET_CHANNEL(NetworkHandle);
    if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_OFFLINE)
    {
        EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_WAIT_TRCVLINK);
        ComM_BusSM_ModeIndication(Channel, &EthSM_NetworkStatus[NetworkHandle].CurrentMode);
    }
    else if (TRUE == EthSM_CheckTrcvLink(NetworkHandle, ETHTRCV_LINK_STATE_ACTIVE, TRUE))
    {
#if (ETHSM_DEM_ERROR_DETECT == STD_ON)
        Dem_ReportErrorStatus(ETHSM_GET_DEM_LINK_DOWN_EVENT_ID(NetworkHandle), DEM_EVENT_STATUS_PASSED);
#endif
        if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_ONLINE)
        {
            EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_ONLINE);
        }else
        {
            EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_ONLINE);
        }
    }
    else
    {
        /* Do nothing */
    }
}

/********************************************************************************************************************
*   @brief      This service is used to transfer to offline mode
*   @param[in]  NetworkHandle  Network handle id
********************************************************************************************************************/
ETHSM_LOCAL FUNC(void,ETHSM_CODE) EthSM_TransferOfflineStateHandler(NetworkHandleType NetworkHandle)
{
    EthSM_UpdateControllerMode(NetworkHandle);
    if(EthSM_NetworkStatus[NetworkHandle].TcpIpState == TCPIP_STATE_OFFLINE)
    {
        if((EthSM_NetworkStatus[NetworkHandle].CtrlMode == ETH_MODE_DOWN) && 
           (TRUE == EthSM_CheckTrcvMode(NetworkHandle, ETHTRCV_MODE_DOWN)))
        {
            EthSM_ChangeNetworkModeState(NetworkHandle,ETHSM_STATE_OFFLINE);
        }
        else
        {
            EthSM_RequestEthIfModeChg(NetworkHandle);
        }
    }
    else
    {
        EthSM_RequestTcpIpModeChg(NetworkHandle,TCPIP_STATE_OFFLINE);
    }
}

#define ETHSM_STOP_SEC_CODE
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
*  @date    29-Sep-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

