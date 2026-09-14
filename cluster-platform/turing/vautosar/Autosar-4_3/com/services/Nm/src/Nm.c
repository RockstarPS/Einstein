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
*   @file       Nm.c
*   @ingroup    Nm
*   @brief      The Network Management (Nm) module coordinates network sleep and wake-up for ECUs, ensuring 
*   efficient communication and power management. It handles network state transitions and monitors node presence
*   in automotive networks.
********************************************************************************************************************/
/*******************************************************************************************************************/
/*  Include files                                                                                                  */
/*******************************************************************************************************************/
#include "Nm.h"
#include "Nm_Cbk.h"
#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
#include "Com.h"
#endif
#if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
#include "BswM_Nm.h"
#endif

#if (NM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/*******************************************************************************************************************/
/*  Version check                                                                                                  */
/*******************************************************************************************************************/
/*! @brief Software Version Check */
#if((NM_SW_MAJOR_VERSION != NM_CFG_SW_MAJOR_VERSION) || \
    (NM_SW_MINOR_VERSION != NM_CFG_SW_MINOR_VERSION) || \
    (NM_SW_PATCH_VERSION != NM_CFG_SW_PATCH_VERSION))
#error "Software version is inconsistent between source files and Configuration files!"
#endif
/*! @brief Autosar Version Check */
#if((NM_AR_RELEASE_MAJOR_VERSION != NM_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (NM_AR_RELEASE_MINOR_VERSION != NM_CFG_AR_RELEASE_MINOR_VERSION) || \
    (NM_AR_RELEASE_REVISION_VERSION != NM_CFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/*******************************************************************************************************************/
/*  TypeDef                                                                                                        */
/*******************************************************************************************************************/
/*! @brief NM state change notification values notified to the Com module */
#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
#define NM_RM_BSM                               (0x01u)
#define NM_RM_PBSM                              (0x02u)
#define NM_NO_RM                                (0x04u)
#define NM_NO_RS                                (0x08u)
#define NM_RM_RS                                (0x10u)
#define NM_RM_NO                                (0x20u)
#endif

/*******************************************************************************************************************/
/*  Static Functions                                                                                               */
/*******************************************************************************************************************/
/*! @brief This function returns the Nm Channel index from ComM module index */
static NetworkHandleType Nm_GetChIndexFromComMIndex(NetworkHandleType nmChannelHandle);

#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
static uint8 Nm_ProcessStateChange(Nm_StateType nmPreviousState, Nm_StateType nmCurrentState);
#endif /* NM_STATE_CHANGE_IND_ENABLED */

#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
/*! @brief This function handles the Ready Sleep Bit for the Coordinator */
static void Nm_CoordReadySleepBitHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, boolean Nm_ReqCSRBitFlag);
/*! @brief Invokes the BusNm function to set the Sleep Ready Bit to nmSleepReadyBit */
static Std_ReturnType Nm_BusNmSetSleepReadyBit(NetworkHandleType nmNetworkHandle, boolean nmSleepReadyBit);
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
#if (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/*! @brief Invokes the BusNm function to request the bus synchronization */
static Std_ReturnType Nm_BusNmRequestBusSynchronization(uint8 ChannelIndex);
#endif /* NM_BUS_SYNCHRONIZATION_ENABLED */
/*! @brief This function finds the cluster index for the given channel index */
static Std_ReturnType Nm_FindClusterIndex(uint8 ChannelIndex, uint8* ClusterIndexPtr);
/*! @brief This function checks if all channels in the cluster are ready for shutdown */
static boolean Nm_CoordShutdownReady(const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function checks the shutdown conditions for non-sleep master channels and non-topmost coordinators */
static boolean Nm_CoordCheckSleepConditions(uint8 ChannelIndex, const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function loads the default shutdown timer for the Coordinator */
static Std_ReturnType Nm_CoordShutdownTimerLoader(const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function handles the Coordinator Shutdown Timer */
static Std_ReturnType Nm_CoordShutDownTimerHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, \
                                                    boolean* SleepAllowPtr);
/*! @brief This function handles the Coordinator Shutdown Abort */
static void Nm_CoordShutdownAbortHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function checks if any channel in a cluster has an active network request */
static boolean Nm_CoordCheckAnyNetworkReq(const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function handles network requests for all channels in a cluster */
static void Nm_CoordNetworkReqHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr);
/*! @brief This function the NM_SHUTDOWN_START state for a cluster */
static void Nm_CoordShutdownStartHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, uint8 ClusterIndex);
/*! @brief This function handles the NM_SHUTDOWN_RUN state for a cluster */
static void Nm_CoordShutdownRunHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, uint8 ClusterIndex);
/*! @brief This function processes a single NM coordination cluster */
static void Nm_CoordClusterProcess(uint8 ClusterIndex);

#endif /* NM_COORDINATOR_SUPPORT_ENABLED */

#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
/*! @brief Invokes the BusNm function to request the network */
static Std_ReturnType Nm_BusNmNetworkRequest(uint8 ChannelIndex);
/*! @brief Invokes the BusNm function to release the network */
static Std_ReturnType Nm_BusNmNetworkRelease(uint8 ChannelIndex);
#endif

#if (NM_DEV_ERROR_DETECT == STD_ON)
/*! @brief Local Function to report DET error */
static void Nm_DetReportError(uint8 ApiId, uint8 ErrorId);
#endif

/*******************************************************************************************************************/
/*  Declarations                                                                                                   */
/*******************************************************************************************************************/
/*! @brief Initialize NM Module Init Status */
static boolean Nm_InitStatus = FALSE;

/*****************************************************************************************************************
** Service Name     : Nm_InitMemory
** Service ID       : None
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Return value     : void
** Description      : This service initializes the global variables
*****************************************************************************************************************/
void Nm_InitMemory(void)
{
    /* Update NM Module Init Status */
    Nm_InitStatus = FALSE;
}
/*****************************************************************************************************************
** Service Name     : Nm_Init
** Service ID       : 0x00
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : ConfigPtr (Post build configuration is not handled in the code)
** Return value     : void
** Description      : This service initializes the NM module
*****************************************************************************************************************/
void Nm_Init(const Nm_ConfigType* ConfigPtr)
{
    /* SWS_Nm_00127 */
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    NetworkHandleType ChannelIndex = NM_NUMBER_OF_CHANNELS;
    NetworkHandleType ClusterIndex = NM_NUMBER_OF_CLUSTERS;
    /* Iterate through all channels */
    for (ChannelIndex = 0U; ChannelIndex < NM_NUMBER_OF_CHANNELS; ChannelIndex++)
    {
        /* Initialize status buffers */
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag = FALSE;
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
        Nm_CoordStatus[ChannelIndex].Nm_RemoteSleepInd = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_BusAwake = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_UpperLayNetworkReq = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_AllowShutdown = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_LowerLayBusSyncPoint = FALSE;
        Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer = 0U;
    }
    /* Check if coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
    /* Iterate through all clusters */
    for (ClusterIndex = 0U; ClusterIndex < NM_NUMBER_OF_CLUSTERS; ClusterIndex++)
    {
        /* Initialize shutdown state buffer */
        Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_INIT;
    }
#endif /* NM_NUMBER_OF_CLUSTERS */
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */

    /* Update NM Module Init Status */
    Nm_InitStatus = TRUE;
    NM_UNUSED_PARAM(ConfigPtr);
}
/*****************************************************************************************************************
** Service Name     : Nm_PassiveStartUp
** Service ID       : 0x01
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_PassiveStartUp function.
*****************************************************************************************************************/
Std_ReturnType Nm_PassiveStartUp( NetworkHandleType nmNetworkHandle )
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    uint8 ClusterIndex = 0x0U;
#endif

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmPassiveStartUpFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
                /* SWS_Nm_00245 */
                if (Nm_FindClusterIndex(nmHandle, &ClusterIndex) == E_OK)
                {
                    RetVal = Nm_NetworkRequest(nmNetworkHandle);
                }
                else
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
                {
                    /* Invoke Bus NM function pointer */
                    RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmPassiveStartUpFunctPtr)(nmHandle));
                }
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_PASSIVESTARTUP_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
/*****************************************************************************************************************
** Service Name     : Nm_NetworkRequest
** Service ID       : 0x02
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_NetworkRequest function.
*****************************************************************************************************************/
Std_ReturnType Nm_NetworkRequest(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    uint8 ClusterIndex = 0x0U;
#endif

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
        if (Nm_ChannelConfig[nmHandle].NmCoordClusterIndex != NM_MAX_CLUSTERS)
        {
            Nm_CoordStatus[nmHandle].Nm_UpperLayNetworkReq = TRUE;
            Nm_CoordStatus[nmHandle].Nm_AllowShutdown = FALSE;
            /* Check if Coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
            if (Nm_FindClusterIndex(nmHandle, &ClusterIndex) == E_OK)
            {
                /* SWS_Nm_00002 & SWS_Nm_00181 */
                if ((Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_RUN) || \
                        (Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_ABORT))
                {
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
                }
                else
                {
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_START;
                }
            }
#endif /* NM_NUMBER_OF_CLUSTERS */
        }
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        RetVal = Nm_BusNmNetworkRequest(nmHandle);
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_NETWORKREQUEST_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_NetworkRelease
** Service ID       : 0x03
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_NetworkRelease function.
*****************************************************************************************************************/
Std_ReturnType Nm_NetworkRelease(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
        if (Nm_ChannelConfig[nmHandle].NmCoordClusterIndex != NM_MAX_CLUSTERS)
        {
            Nm_CoordStatus[nmHandle].Nm_UpperLayNetworkReq = FALSE;
            RetVal = E_OK;
        }
        else
        {
            /* Invoke Bus NM function pointer */
            RetVal = Nm_BusNmNetworkRelease(nmHandle);
        }
#else
        /* Invoke Bus NM function pointer */
        RetVal = Nm_BusNmNetworkRelease(nmHandle);
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_NETWORKRELEASE_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (NM_COM_CONTROL_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_DisableCommunication
** Service ID       : 0x04
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_DisableCommunication function.
*****************************************************************************************************************/
Std_ReturnType Nm_DisableCommunication(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmDisableCommunicationFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmDisableCommunicationFunctPtr)(nmHandle));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_DISABLECOMMUNICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_EnableCommunication
** Service ID       : 0x05
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_EnableCommunication function.
*****************************************************************************************************************/
Std_ReturnType Nm_EnableCommunication(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmEnableCommunicationFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmEnableCommunicationFunctPtr)(nmHandle));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_ENABLECOMMUNICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (NM_USER_DATA_ENABLED == STD_ON)
#if ((NM_PASSIVE_MODE_ENABLED == STD_OFF) && (NM_COM_USER_DATA_SUPPORT == STD_OFF))
/*****************************************************************************************************************
** Service Name     : Nm_SetUserData
** Service ID       : 0x06
** Sync/Async       : Synchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle, nmUserDataPtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_SetUserData function to set user data for NM messages
                      transmitted next on the bus
*****************************************************************************************************************/
Std_ReturnType Nm_SetUserData(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmUserDataPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmSetUserDataFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmSetUserDataFunctPtr)
                          (nmHandle, nmUserDataPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_SETUSERDATA_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
/*****************************************************************************************************************
** Service Name     : Nm_GetUserData
** Service ID       : 0x07
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmUserDataPtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_GetUserData function to get user data out of the last
                      successfully received NM message
*****************************************************************************************************************/
Std_ReturnType Nm_GetUserData(NetworkHandleType nmNetworkHandle, uint8* nmUserDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If data pointer is valid */
    else if (NULL_PTR == nmUserDataPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetUserDataFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetUserDataFunctPtr)
                          (nmHandle, nmUserDataPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETUSERDATA_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if ((NM_NODE_ID_ENABLED == STD_ON) || (NM_USER_DATA_ENABLED == STD_ON))
/*****************************************************************************************************************
** Service Name     : Nm_GetPduData
** Service ID       : 0x08
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmPduData
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_GetPduData function to get the whole PDU data out of the most
                      recently received NM message
*****************************************************************************************************************/
Std_ReturnType Nm_GetPduData(NetworkHandleType nmNetworkHandle, uint8* nmPduDataPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If PDU data pointer is valid */
    else if (NULL_PTR == nmPduDataPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetPduDataFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetPduDataFunctPtr)
                          (nmHandle, nmPduDataPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETPDUDATA_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (NM_NODE_DETECTION_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_RepeatMessageRequest
** Service ID       : 0x09
** Sync/Async       : Asynchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_RepeatMessageRequest function to set Repeat Message Request
                      Bit for NM messages transmitted next on the bus
*****************************************************************************************************************/
Std_ReturnType Nm_RepeatMessageRequest(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmRepeatMessageRequestFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmRepeatMessageRequestFunctPtr)(nmHandle));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_REPEATMESSAGEREQUEST_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (NM_NODE_ID_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_GetNodeIdentifier
** Service ID       : 0x0a
** Sync/Async       : Synchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmNodeIdPtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_GetNodeIdentifier function to get node identifier out of
                      the last successfully received NM message
*****************************************************************************************************************/
Std_ReturnType Nm_GetNodeIdentifier(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If pointer parameter is valid */
    else if (NULL_PTR == nmNodeIdPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetNodeIdentifierFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetNodeIdentifierFunctPtr)
                          (nmHandle, nmNodeIdPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETNODEIDENTIFIER_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_GetLocalNodeIdentifier
** Service ID       : 0x0b
** Sync/Async       : Synchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmNodeIdPtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_GetLocalNodeIdentifier function to get node identifier
                      configured for the local node
*****************************************************************************************************************/
Std_ReturnType Nm_GetLocalNodeIdentifier(NetworkHandleType nmNetworkHandle, uint8* nmNodeIdPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If pointer parameter is valid */
    else if (NULL_PTR == nmNodeIdPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetLocalNodeIdentifierFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetLocalNodeIdentifierFunctPtr)
                          (nmHandle, nmNodeIdPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETLOCALNODEIDENTIFIER_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
#if (NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_CheckRemoteSleepIndication
** Service ID       : 0x0d
** Sync/Async       : Synchronous
** Reentrancy       : Non-reentrant for the same NetworkHandle, reentrant otherwise
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmRemoteSleepIndPtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_CheckRemoteSleepIndication function to check if remote sleep
                      indication takes place or not
*****************************************************************************************************************/
Std_ReturnType Nm_CheckRemoteSleepIndication(NetworkHandleType nmNetworkHandle, boolean* nmRemoteSleepIndPtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If pointer parameter is valid */
    else if (NULL_PTR == nmRemoteSleepIndPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmCheckRemoteSleepIndicationFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmCheckRemoteSleepIndicationFunctPtr)
                          (nmHandle, nmRemoteSleepIndPtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_CHECKREMOTESLEEPINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#endif
/*****************************************************************************************************************
** Service Name     : Nm_GetState
** Service ID       : 0x0e
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Parameters [out] : nmStatePtr, nmModePtr
** Return value     : Std_ReturnType
** Description      : This function calls the <BusNm>_GetState function to get the state of the network management
*****************************************************************************************************************/
Std_ReturnType Nm_GetState(NetworkHandleType nmNetworkHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;
    NetworkHandleType nmHandle = Nm_GetChIndexFromComMIndex(nmNetworkHandle);

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if ((NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle) || (NM_NUMBER_OF_CHANNELS <= nmHandle))
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If state and mode pointer is valid */
    else if ((NULL_PTR == nmStatePtr) || (NULL_PTR == nmModePtr))
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetStateFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke Bus NM function pointer */
                RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmGetStateFunctPtr)
                          (nmHandle, nmStatePtr, nmModePtr));
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETSTATE_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
    return RetVal;
}
#if (NM_VERSION_INFO_API == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_GetVersionInfo
** Service ID       : 0x0f
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Parameters [out] : nmVerInfoPtr
** Return value     : None
** Description      : This service returns the version information of this module
*****************************************************************************************************************/
void Nm_GetVersionInfo(Std_VersionInfoType* nmVerInfoPtr)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;

    /* Check If pointer parameter is valid */
    if (NULL_PTR == nmVerInfoPtr)
    {
        ErrorId = NM_E_PARAM_POINTER;
    }
    else
    {
        Nm_EnterCriticalSection(); //todo: added critical check to fix compiler warnings
        nmVerInfoPtr->vendorID = NM_VENDOR_ID;
        nmVerInfoPtr->moduleID = NM_MODULE_ID;
        nmVerInfoPtr->sw_major_version = NM_SW_MAJOR_VERSION;
        nmVerInfoPtr->sw_minor_version = NM_SW_MINOR_VERSION;
        nmVerInfoPtr->sw_patch_version = NM_SW_PATCH_VERSION;
        Nm_ExitCriticalSection();
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_GETVERSIONINFO_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
/*****************************************************************************************************************
** Service Name     : Nm_NetworkStartIndication
** Service ID       : 0x11
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that a NM-message has been received in the Bus-Sleep Mode, what
                      indicates that some nodes in the network have already entered the Network Mode
*****************************************************************************************************************/
void Nm_NetworkStartIndication(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;

    /* Check If requested Network is valid */
    if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Notify a network start to the ComM Module */
        ComM_Nm_NetworkStartIndication(Nm_ChannelConfig[nmNetworkHandle].ComMChRef);
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_NETWORKSTARTINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : Nm_NetworkMode
** Service ID       : 0x12
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that the network management has entered Network Mode
*****************************************************************************************************************/
void Nm_NetworkMode(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    uint8 ClusterIndex = 0x0U;
#endif

    /* Check If requested Network is valid */
    if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
        Nm_CoordStatus[nmNetworkHandle].Nm_BusAwake = TRUE;
        Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd = FALSE;
        /* Check if Coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
        if (Nm_FindClusterIndex(nmNetworkHandle, &ClusterIndex) == E_OK)
        {
            /* SWS_Nm_00181 */
            if ((Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_RUN) || \
                (Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_ABORT))
            {
                Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
            }
            else
            {
                Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_START;
            }
        }
#endif /* NM_NUMBER_OF_CLUSTERS */
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        /* Notify that network management has entered Network Mode to the ComM Module */
        ComM_Nm_NetworkMode(Nm_ChannelConfig[nmNetworkHandle].ComMChRef);
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_NETWORKMODE_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : Nm_PrepareBusSleepMode
** Service ID       : 0x13
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that the network management has entered Prepare Bus Sleep Mode
*****************************************************************************************************************/
void Nm_PrepareBusSleepMode(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;

    /* Check If requested Network is valid */
    if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
        Nm_CoordStatus[nmNetworkHandle].Nm_LowerLayBusSyncPoint = FALSE;
        Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd = FALSE;
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        /* Notify that network management has entered Prepare Bus Sleep Mode to the ComM Module */
        ComM_Nm_PrepareBusSleepMode(Nm_ChannelConfig[nmNetworkHandle].ComMChRef);
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_PREPAREBUSSLEEPMODE_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : Nm_BusSleepMode
** Service ID       : 0x14
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that the network management has entered Bus Sleep Mode
*****************************************************************************************************************/
void Nm_BusSleepMode(NetworkHandleType nmNetworkHandle)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    uint8 ClusterIndex = 0x0U;
#endif

    /* Check If requested Network is valid */
    if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
        /* Clear all status flags */
        Nm_CoordStatus[nmNetworkHandle].Nm_LowerLayBusSyncPoint = FALSE;
        Nm_CoordStatus[nmNetworkHandle].Nm_BusAwake = FALSE;
        Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd = FALSE;
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        Nm_CoordStatus[nmNetworkHandle].Nm_CoorRsbFlag = FALSE;
#endif
        /* Check if Coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
        if (Nm_FindClusterIndex(nmNetworkHandle, &ClusterIndex) == E_OK)
        {
            if ((Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_START) && \
                (Nm_CoordStatus[nmNetworkHandle].Nm_UpperLayNetworkReq == FALSE))
            {
                Nm_CoordStatus[nmNetworkHandle].Nm_UpperLayNetworkReq = FALSE;
                (void)Nm_BusNmNetworkRelease(nmNetworkHandle);
            }
        }
#endif /* NM_NUMBER_OF_CLUSTERS */
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        /* Notify that network management has entered Bus Sleep Mode to the ComM Module */
        ComM_Nm_BusSleepMode(Nm_ChannelConfig[nmNetworkHandle].ComMChRef);
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_BUSSLEEPMODE_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
#if (NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_RemoteSleepIndication
** Service ID       : 0x17
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that the network management has detected that all other nodes on the
                      network are ready to enter Bus Sleep Mode
*****************************************************************************************************************/
void Nm_RemoteSleepIndication(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00192 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Set Remote Sleep Indication Flag */
        Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd = TRUE;
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_REMOTESLEEPINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : Nm_RemoteSleepCancellation
** Service ID       : 0x18
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This service notifies that the network management has detected that not all other nodes on
                      the network are ready to enter Bus Sleep Mode
*****************************************************************************************************************/
void Nm_RemoteSleepCancellation(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00193 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    uint8 ClusterIndex = 0x0U;
    
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Clear Remote Sleep Indication Flag */
        Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd = FALSE;
        /* Check if any coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
        /* Check if the channel is a sleep master */
        if (Nm_ChannelConfig[nmNetworkHandle].NmChannelSleepMaster == FALSE)
        {
            /* Check if the channel is part of a cluster */
            if (Nm_FindClusterIndex(nmNetworkHandle, &ClusterIndex) == E_OK)
            {
                /* SWS_Nm_00181 */
                /* Check if the cluster is in shutdown mode */
                if ((Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_RUN) || \
                    (Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_ABORT))
                {
                    /* Abort the cluster shutdown */
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
                }
                else
                {
                    /* Start the cluster shutdown */
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_START;
                }
            }
        }
#endif /* NM_NUMBER_OF_CLUSTERS */
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_REMOTESLEEPCANCELLATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
/*****************************************************************************************************************
** Service Name     : Nm_SynchronizationPoint
** Service ID       : 0x19
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Notification to the NM Coordinator functionality that this is a suitable point in time to
                      initiate the coordinated shutdown on
*****************************************************************************************************************/
void Nm_SynchronizationPoint(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00194 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    uint8 ClusterIndex = 0U;
    
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* SWS_Nm_00172 & SWS_Nm_00173*/
        /* Check if the channel is a synchronizing network */
        if (Nm_ChannelConfig[nmNetworkHandle].NmSynchronizingNetwork == TRUE)
        {
            /* Check if the channel is part of a cluster and is in shutdown mode */
            if((Nm_FindClusterIndex(nmNetworkHandle, &ClusterIndex) == E_OK) && \
                (Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_START))
            {
                /* Check if the channel is a sleep master */
                if (Nm_ChannelConfig[nmNetworkHandle].NmChannelSleepMaster == FALSE)
                {
                    /* Set the lower layer bus synchronization point to remote sleep indication */
                    Nm_CoordStatus[nmNetworkHandle].Nm_LowerLayBusSyncPoint = \
                                                                    Nm_CoordStatus[nmNetworkHandle].Nm_RemoteSleepInd;
                }
                else
                {
                    /* Check if the upper layer network request is active */
                    if (Nm_CoordStatus[nmNetworkHandle].Nm_UpperLayNetworkReq == FALSE)
                    {
                        /* Set the lower layer bus synchronization point */
                        Nm_CoordStatus[nmNetworkHandle].Nm_LowerLayBusSyncPoint = TRUE;
                    }
                    else
                    {
                        /* Clear the lower layer bus synchronization point */
                        Nm_CoordStatus[nmNetworkHandle].Nm_LowerLayBusSyncPoint = FALSE;
                    }
                }
            }
        }
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_SYNCHRONIZATIONPOINT_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_CoordReadyToSleepIndication
** Service ID       : 0x1e
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Sets an indication, when the NM Coordinator Sleep Ready bit in the Control Bit Vector is set
*****************************************************************************************************************/
void Nm_CoordReadyToSleepIndication(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00254 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Check if the channel is the active coordinator */
        if (Nm_ChannelConfig[nmNetworkHandle].NmActiveCoordinator == FALSE)
        {
            /* Set the coordinator request sleep bit */
            Nm_CoordStatus[nmNetworkHandle].Nm_CoorRsbFlag = TRUE;
        }
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_COORDREADYTOSLEEPINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordReadyToSleepCancellation
** Service ID       : 0x1f
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Cancels an indication, when the NM Coordinator Sleep Ready bit in the Control Bit Vector
                      is set back to 0
*****************************************************************************************************************/
void Nm_CoordReadyToSleepCancellation(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00272 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    uint8 ClusterIndex = 0x0U;
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_COMM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Check if the channel is the active coordinator */
        if (Nm_ChannelConfig[nmNetworkHandle].NmActiveCoordinator == FALSE)
        {
            /* Clear the coordinator request sleep bit */
            Nm_CoordStatus[nmNetworkHandle].Nm_CoorRsbFlag = FALSE;
            /* Check if any coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
            /* Check if the channel is part of a cluster */
            if (Nm_FindClusterIndex(nmNetworkHandle, &ClusterIndex) == E_OK)
            {
                /* SWS_Nm_00181 */
                /* Check if the cluster is in shutdown mode */
                if ((Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_RUN) || \
                    (Nm_ShutdownState[ClusterIndex] == NM_SHUTDOWN_ABORT))
                {
                    /* Abort the cluster shutdown */
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
                }
                else
                {
                    /* Start the cluster shutdown */
                    Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_START;
                }
            }
#endif /* NM_NUMBER_OF_CLUSTERS */
        }
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_COORDREADYTOSLEEPCANCELLATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
#if (NM_PDU_RX_INDICATION_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_PduRxIndication
** Service ID       : 0x15
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Notification to application that a NM message has been received
*****************************************************************************************************************/
void Nm_PduRxIndication(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00112,SWS_Nm_00164 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmNetworkHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmPduRxIndicationFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
            }
            else
#endif
            {
                /* Invoke application callout function */
                (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmPduRxIndicationFunctPtr)(nmNetworkHandle);
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_PDURXINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_StateChangeNotification
** Service ID       : 0x16
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle, nmPreviousState, nmCurrentState
** Return value     : void
** Description      : Notification that the state of the lower layer <BusNm> has changed
*****************************************************************************************************************/
void Nm_StateChangeNotification(NetworkHandleType nmNetworkHandle, Nm_StateType nmPreviousState,
                                Nm_StateType nmCurrentState)
{
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    uint8 NmStateSignal = 0U;

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    /* Check If NM states are same */
    else if (nmCurrentState == nmPreviousState)
    {
        ErrorId = NM_E_SAME_STATES;
    }
    /* Check If NM states are valid */
    else if ((nmCurrentState >= NM_STATE_NUMBER_OF_STATES) || (nmPreviousState >= NM_STATE_NUMBER_OF_STATES))
    {
        ErrorId = NM_E_INVALID_STATE;
    }
    else
    {
        if(TRUE == Nm_ChannelConfig[nmNetworkHandle].NmStateReportEnabled)
        {
            /* Get the state signal value based on state transition */
            NmStateSignal = Nm_ProcessStateChange(nmPreviousState, nmCurrentState);
            
            /* SWS_Nm_00249 - Com API to update the signal object */
            (void)Com_SendSignal(Nm_ChannelConfig[nmNetworkHandle].NmStateReportSignalId, &NmStateSignal);
            /* Call the upper layer state change notification */
            /* NM_UL_STATE_CHANGE_NOTIFICATION(nmNetworkHandle, nmPreviousState, nmCurrentState); */
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_STATECHANGENOTIFICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (NM_REPEAT_MSG_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_RepeatMessageIndication
** Service ID       : 0x1a
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Service to indicate that an NM message with set Repeat Message Request Bit has been received
*****************************************************************************************************************/
void Nm_RepeatMessageIndication(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00230 */
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_RepeatMessageIndicationFunctType Nm_RepeatMessageIndicationFunct = NULL_PTR;

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check if requested Network is valid */
    else if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Get the function pointer from configuration */
        Nm_RepeatMessageIndicationFunct = Nm_OemFunctConfig[nmNetworkHandle].UlRepeatMessageIndicationFunctPtr;
        /* Check if the function pointer is valid */
        if (Nm_RepeatMessageIndicationFunct == NULL_PTR)
        {
            ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
        }
        else
        {
            /* Invoke OEM NM function */
            ((Nm_RepeatMessageIndicationFunct)(nmNetworkHandle));
        }
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        Nm_DetReportError(NM_SID_REPEATMESSAGEINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (NM_PASSIVE_MODE_ENABLED == STD_OFF)
/*****************************************************************************************************************
** Service Name     : Nm_TxTimeoutException
** Service ID       : 0x1b
** Sync/Async       : Asynchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : Service to indicate that an attempt to send an NM message failed
*****************************************************************************************************************/
void Nm_TxTimeoutException(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00234 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_TxTimeoutExceptionFunctType TxTimeoutExceptionFunct = NULL_PTR;

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check if requested Network is valid */
    else if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        /* Get the function pointer from configuration */
        TxTimeoutExceptionFunct = Nm_OemFunctConfig[nmNetworkHandle].UlTxTimeoutExceptionFunctPtr;
        /* Check if the function pointer is valid */
        if (TxTimeoutExceptionFunct == NULL_PTR)
        {
            ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
        }
        else
        {
            /* Invoke OEM NM function */
            ((TxTimeoutExceptionFunct)(nmNetworkHandle));
        }
    }

#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        Nm_DetReportError(NM_SID_TXTIMEOUTEXCEPTION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (NM_CAR_WAKE_UP_RX_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_CarWakeUpIndication
** Service ID       : 0x1d
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Return value     : void
** Description      : This function is called by a <Bus>Nm to indicate reception of a CWU request
*****************************************************************************************************************/
void Nm_CarWakeUpIndication(NetworkHandleType nmNetworkHandle)
{
    /* SWS_Nm_00252,SWS_Nm_00285 */
    /* Local Variables */
    uint8 ErrorId = NM_E_NO_ERROR;
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = 0xFFU;

    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        ErrorId = NM_E_UNINIT;
    }
    /* Check If requested Network is valid */
    else if (NM_NUMBER_OF_CHANNELS <= nmNetworkHandle)
    {
        ErrorId = NM_E_HANDLE_UNDEF;
    }
    else
    {
        BusNmFunctCfgIndex = Nm_ChannelConfig[nmNetworkHandle].BusNmFunctConfigId;
        if(NM_NUM_OF_BUS_NM_SUPPORTED > BusNmFunctCfgIndex)
        {
#if (NM_DEV_ERROR_DETECT == STD_ON)
            /* Check If respective Bus NM function pointer is valid */
            if (NULL_PTR == (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmCarWakeUpCalloutFunctPtr))
            {
                ErrorId = NM_E_FUNCTION_PTR_IS_NULL;
                BswM_Nm_CarWakeUpIndication(nmNetworkHandle);
            }
            else
#endif
            {
                /* Invoke application callout function */
                (Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmCarWakeUpCalloutFunctPtr)(nmNetworkHandle);
            }
        }
        else
        {
            ErrorId = NM_E_HANDLE_UNDEF;
            BswM_Nm_CarWakeUpIndication(nmNetworkHandle);
        }
    }
#if (NM_DEV_ERROR_DETECT == STD_ON)
    if (NM_E_NO_ERROR != ErrorId)
    {
        /* Report DET Error */
        Nm_DetReportError(NM_SID_CARWAKEUPINDICATION_API, ErrorId);
    }
#else
    NM_UNUSED_PARAM(ErrorId);
#endif
}
#endif
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_MainFunction
** Service ID       : 0x10
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : None
** Return value     : void
** Description      : This function implements the processes of the NM Interface, which need a fix cyclic
                      scheduling
*****************************************************************************************************************/
void Nm_MainFunction(void)
{
    /* SWS_Nm_00020 & SWS_Nm_00118 */
    /* Local Variables */
    uint8 ClusterIndex = 0x0U;

    /* SWS_Nm_00121 */
    /* Check If module is Initialized */
    if (TRUE != Nm_InitStatus)
    {
        /* Do nothing - return immediately without error */
    }
    else
    {
    /* Check if coordination clusters exist */
#if (NM_NUMBER_OF_CLUSTERS > NM_ZERO)
        /* SWS_Nm_00001 & SWS_Nm_00167 */
        /* Iterate through all clusters */
        for (ClusterIndex = 0U; ClusterIndex < NM_NUMBER_OF_CLUSTERS; ClusterIndex++)
        {
            /* Process each cluster independently */
            Nm_CoordClusterProcess(ClusterIndex);
        }
#endif /* NM_NUMBER_OF_CLUSTERS */
    }
}
#endif
/*****************************************************************************************************************
** Service Name     : Nm_GetChIndexFromComMIndex
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmChannelHandle
** Return value     : NetworkHandleType
** Description      : This function returns the Nm Channel index from ComM module index
*****************************************************************************************************************/
static NetworkHandleType Nm_GetChIndexFromComMIndex(NetworkHandleType nmChannelHandle)
{
    /* Local Variables */
    NetworkHandleType NmChannel = (NetworkHandleType)NM_NO_COMM_TO_NM_CHIND;

    if (NM_COMM_NUMBER_OF_CHANNELS > nmChannelHandle)
    {
        NmChannel = Nm_ComMToNmChannelMapping[nmChannelHandle];
    }
    return NmChannel;
}
#if (NM_STATE_CHANGE_IND_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_ProcessStateChange
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle - Network handle
** Parameters [in]  : nmPreviousState - Previous NM state
** Parameters [in]  : nmCurrentState - Current NM state  
** Return value     : uint8 - State signal value to be sent
** Description      : Determines the state signal value based on state transitions
*****************************************************************************************************************/
static uint8 Nm_ProcessStateChange(Nm_StateType nmPreviousState, Nm_StateType nmCurrentState)
{
    uint8 NmStateSignal = 0U;
    
    if (nmCurrentState == NM_STATE_REPEAT_MESSAGE)
    {
        switch(nmPreviousState)
        {
            case NM_STATE_BUS_SLEEP:
                NmStateSignal = NM_RM_BSM;
                break;
            case NM_STATE_PREPARE_BUS_SLEEP:
                NmStateSignal = NM_RM_PBSM;
                break;
            case NM_STATE_READY_SLEEP:
                NmStateSignal = NM_RM_RS;
                break;
            case NM_STATE_NORMAL_OPERATION:
                NmStateSignal = NM_RM_NO;
                break;
            default:
                /* do nothing */
                break;
        }
    }
    else if (nmCurrentState == NM_STATE_NORMAL_OPERATION)
    {
        switch(nmPreviousState)
        {
            case NM_STATE_REPEAT_MESSAGE:
                NmStateSignal = NM_NO_RM;
                break;
            case NM_STATE_READY_SLEEP:
                NmStateSignal = NM_NO_RS;
                break;
            default:
                /* do nothing */
                break;
        }
    }
    else
    {
        /* Do nothing */
    }
    
    return NmStateSignal;
}
#endif
#if (STD_OFF == NM_PASSIVE_MODE_ENABLED)
/*****************************************************************************************************************
** Service Name     : Nm_BusNmNetworkRequest
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ChannelIndex
** Return value     : Std_ReturnType
** Description      : This function handles the BusNm Network Request for the specified channel.
*****************************************************************************************************************/
static Std_ReturnType Nm_BusNmNetworkRequest(uint8 ChannelIndex)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    /* Get the BusNm function configuration index for the current channel */
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = Nm_ChannelConfig[ChannelIndex].BusNmFunctConfigId;
    /* Check if the BusNm function configuration index is valid */
    if(BusNmFunctCfgIndex < NM_NUM_OF_BUS_NM_SUPPORTED)
    {
        /* Check If respective Bus NM function pointer is valid */
        if ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmNetworkRequestFunctPtr) != NULL_PTR)
        {
            /* Invoke Bus NM function pointer */
            RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmNetworkRequestFunctPtr)(ChannelIndex));
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
            /* Indicate that the lower layer network is requested */
            Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested = TRUE;
            /* Check if the network was successfully requested */
            if (RetVal != E_OK)
            {
                /* Clear Bus Awake status */
                Nm_CoordStatus[ChannelIndex].Nm_BusAwake = FALSE;
            }
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        }
    }
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_BusNmNetworkRelease
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ChannelIndex
** Return value     : Std_ReturnType
** Description      : This function handles the BusNm Network Release for the specified channel.
*****************************************************************************************************************/
static Std_ReturnType Nm_BusNmNetworkRelease(uint8 ChannelIndex)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    /* Get the BusNm function configuration index for the current channel */
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = Nm_ChannelConfig[ChannelIndex].BusNmFunctConfigId;
    /* Check if the BusNm function configuration index is valid */
    if(BusNmFunctCfgIndex < NM_NUM_OF_BUS_NM_SUPPORTED)
    {
        /* Check If respective Bus NM function pointer is valid */
        if ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmNetworkReleaseFunctPtr) != NULL_PTR)
        {
            /* Invoke Bus NM function pointer */
            RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmNetworkReleaseFunctPtr)(ChannelIndex));
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
            /* Indicate that the lower layer network is released */
            Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested = FALSE;
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
        }
    }
    return RetVal;
}
#endif /* NM_PASSIVE_MODE_ENABLED */
#if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_BusNmSetSleepReadyBit
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : nmNetworkHandle
** Parameters [in]  : nmSleepReadyBit
** Return value     : Std_ReturnType
** Description      : Invokes the BusNm function to set the Sleep Ready Bit to nmSleepReadyBit
*****************************************************************************************************************/
static Std_ReturnType Nm_BusNmSetSleepReadyBit(NetworkHandleType nmNetworkHandle, boolean nmSleepReadyBit)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    /* Retrieve the BusNm function configuration index for the current channel */
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = Nm_ChannelConfig[nmNetworkHandle].BusNmFunctConfigId;
    /* Check if the BusNm function configuration index is valid */
    if (BusNmFunctCfgIndex < NM_NUM_OF_BUS_NM_SUPPORTED)
    {
        /* Check If respective Bus NM function pointer is valid */
        if(Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmSetSleepReadyBitFunctPtr != NULL_PTR)
        {
            /* Invoke the BusNm function to set the Sleep Ready Bit to nmSleepReadyBit */
            RetVal = Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmSetSleepReadyBitFunctPtr(nmNetworkHandle, \
                                                                                            nmSleepReadyBit);
        }
    }
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordReadySleepBitHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Nm_PerClusterPtr
** Parameters [in]  : Nm_ReqCSRBitFlag
** Return value     : void
** Description      : This function handles the Coordinator Ready Sleep Bit (CSRBit) for the NM Coordinator 
                      functionality.
*****************************************************************************************************************/
static void Nm_CoordReadySleepBitHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, boolean Nm_ReqCSRBitFlag)
{
    /* Local Variables */
    uint8 ChannelIndex = 0U;
    uint8 Index = 0U;
    boolean CoorRsb = FALSE;
    boolean NeedHandle = FALSE;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 NmClusterIncNumChannel = Nm_PerClusterPtr->NmClusterIncNumChannel;
    /* Check if the current cluster is the top-most coordinator */
    if (Nm_PerClusterPtr->NmTopMostCoordinator == TRUE)
    {
        /* Check if the requested Coordinator Ready Sleep Bit (CSRBit) is set */
        if (Nm_ReqCSRBitFlag == TRUE)
        {
            /* Set the Coordinator Ready Sleep Bit (CSRBit) */
            CoorRsb = TRUE;
            /* Indicate that CSR needs to be handled */
            NeedHandle = TRUE;
        }
    }
    else
    {
        /* Indicate that CSR needs to be handled */
        NeedHandle = TRUE;
        /* Loop through all channels in the cluster */
        for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
        {
            /* Get the channel index */
            ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
            /* Check if the channel is not the active coordinator */
            if (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == FALSE)
            {
                /* Get the Coordinator Ready Sleep Bit (CSRBit) status and break the loop */
                CoorRsb = Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag;
                break;
            }
        }
    }

    /* Check if CSR needs to be handled */
    if (NeedHandle == TRUE)
    {
        /* SWS_Nm_00001 */
        /* Loop through all channels in the cluster */
        for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
        {
            /* Get the channel index */
            ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
            /* Check if the channel is the active coordinator */
            if (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == TRUE)
            {
                /* Check if the Coordinator Ready Sleep Bit (CSRBit) needs to be updated */
                if (CoorRsb != Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag)
                {
                    /* Call the function to update the Coordinator Ready Sleep Bit (CSRBit) */
                    RetVal = Nm_BusNmSetSleepReadyBit(ChannelIndex, CoorRsb);
                    /* Check if the update was successful */
                    if (RetVal == E_OK)
                    {
                        /* Update the Coordinator Ready Sleep Bit (CSRBit) status */
                        Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag = CoorRsb;
                    }
                }
            }
        }
    }
}
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
/*****************************************************************************************************************
** Service Name     : Nm_CoordCheckAnyNetworkReq
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Non-Reentrant
** Parameters [in]  : Nm_PerClusterPtr - Pointer to cluster configuration
** Return value     : boolean - TRUE if any network is requested, FALSE otherwise
** Description      : Checks if any channel in a cluster has an active network request
*****************************************************************************************************************/
static boolean Nm_CoordCheckAnyNetworkReq(const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    uint8 Index;
    uint8 ChannelIndex;
    boolean AnyNetworkRequested = FALSE;
    uint8 NumChannels = Nm_PerClusterPtr->NmClusterIncNumChannel;
    const uint8* ClusterChannels = Nm_PerClusterPtr->NmClusterIncChannel;
    
    /* Check if any channel in the cluster has an active network request */
    for (Index = 0U; Index < NumChannels; Index++)
    {
        /* Get the channel index */
        ChannelIndex = ClusterChannels[Index];
        /* Check if the channel has an active network request */
        if (Nm_CoordStatus[ChannelIndex].Nm_UpperLayNetworkReq == TRUE)
        {
            /* Set active network requested flag and break out of the loop */
            AnyNetworkRequested = TRUE;
            break;
        }
    }
    
    return AnyNetworkRequested;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordNetworkReqHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Non-Reentrant
** Parameters [in]  : Nm_PerClusterPtr - Pointer to cluster configuration
** Return value     : void
** Description      : Handles network requests for all channels in a cluster
*****************************************************************************************************************/
static void Nm_CoordNetworkReqHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    uint8 Index;
    uint8 ChannelIndex;
    uint8 ActiveIdx;
    uint8 ActiveChannel;
    boolean SendMessage;
    uint8 NumChannels = Nm_PerClusterPtr->NmClusterIncNumChannel;
    const uint8* ClusterChannels = Nm_PerClusterPtr->NmClusterIncChannel;
    
    /* Looping over the channels in the cluster */
    for (Index = 0U; Index < NumChannels; Index++)
    {
        /* Get the channel index */
        ChannelIndex = ClusterChannels[Index];
        
        /* Check if the channel is not the active coordinator */
        if (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == FALSE)
        {
            /* Clear the send message flag */
            SendMessage = FALSE;
            
            /* Check if the upper layer network request is active */
            if (Nm_CoordStatus[ChannelIndex].Nm_UpperLayNetworkReq == TRUE)
            {
                /* Set the send message flag */
                SendMessage = TRUE;
            }
            /* If no upper layer network request is active, check for any active coordinator */
            else
            {
                /* Checking for any active coordinator */
                for (ActiveIdx = 0U; ActiveIdx < NumChannels; ActiveIdx++)
                {
                    /* Get the channel index */
                    ActiveChannel = ClusterChannels[ActiveIdx];
                    /* Check if the channel is an active coordinator and is not in sleep mode */
                    if ((Nm_ChannelConfig[ActiveChannel].NmActiveCoordinator == TRUE) && 
                        (Nm_CoordStatus[ActiveChannel].Nm_RemoteSleepInd == FALSE))
                    {
                        /* Set the send message flag and break the loop as we found an active coordinator */
                        SendMessage = TRUE;
                        break;
                    }
                }
            }
            
            /* Check if the send message flag is set */
            if (SendMessage == TRUE)
            {
                /* Check if the lower layer network request is not active */
                if (Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested == FALSE)
                {
                    /* Request network on the bus */
                    (void)Nm_BusNmNetworkRequest(ChannelIndex);
                }
            }
            /* Check if the lower layer network request is active */
            else if (Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested == TRUE)
            {
                /* Release network on the bus */
                (void)Nm_BusNmNetworkRelease(ChannelIndex);
            }
            else
            {
                /* Do nothing */
            }
        }
    }
}

/*****************************************************************************************************************
** Service Name     : Nm_CoordShutdownStartHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Non-Reentrant
** Parameters [in]  : Nm_PerClusterPtr - Pointer to cluster configuration
** Parameters [in]  : ClusterIndex - Index of the cluster
** Return value     : void
** Description      : Handles the NM_SHUTDOWN_START state for a cluster
*****************************************************************************************************************/
static void Nm_CoordShutdownStartHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, uint8 ClusterIndex)
{
    boolean ShutdownReady;
    Std_ReturnType TimerLoaderRetVal;
    
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
    /* Handle Coordinator Ready Sleep Bit with FALSE */
    Nm_CoordReadySleepBitHandle(Nm_PerClusterPtr, FALSE);
#endif /* NM_COORDINATOR_SYNC_SUPPORT */

    /* Check if the shutdown is ready */
    ShutdownReady = Nm_CoordShutdownReady(Nm_PerClusterPtr);
    if (ShutdownReady == TRUE)
    {
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        /* Handle Coordinator Ready Sleep Bit with TRUE */
        Nm_CoordReadySleepBitHandle(Nm_PerClusterPtr, TRUE);
#endif /* NM_COORDINATOR_SYNC_SUPPORT */

        /* Check if the shutdown timer is loaded */
        TimerLoaderRetVal = Nm_CoordShutdownTimerLoader(Nm_PerClusterPtr);
        if (TimerLoaderRetVal == E_OK)
        {
            /* Begin shutdown */
            Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_RUN;
        }
    }
}

/*****************************************************************************************************************
** Service Name     : Nm_CoordShutdownRunHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Non-Reentrant
** Parameters [in]  : Nm_PerClusterPtr - Pointer to cluster configuration
** Parameters [in]  : ClusterIndex - Index of the cluster
** Return value     : void
** Description      : Handles the NM_SHUTDOWN_RUN state for a cluster
*****************************************************************************************************************/
static void Nm_CoordShutdownRunHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, uint8 ClusterIndex)
{
    boolean ShutdownReady;
    boolean SleepAllow = FALSE;
    Std_ReturnType TimerHandlerRetVal;
    
    /* Check if the shutdown is ready */
    ShutdownReady = Nm_CoordShutdownReady(Nm_PerClusterPtr);
    if (ShutdownReady == TRUE)
    {
        /* Handle the shutdown timer and see if sleep is allowed */
        TimerHandlerRetVal = Nm_CoordShutDownTimerHandle(Nm_PerClusterPtr, &SleepAllow);
        
        /* Check if the shutdown timer is not loaded */
        if (TimerHandlerRetVal != E_OK)
        {
            /* Abort shutdown */
            Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
        }
        else
        {
            /* Check if sleep is allowed */
            if (SleepAllow == TRUE)
            {
                /* Shutdown successful */
                Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_STOP;
            }
        }
    }
    else
    {
        /* Abort shutdown if it's no longer ready */
        Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_ABORT;
    }
}

/*****************************************************************************************************************
** Service Name     : Nm_CoordClusterProcess
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Non-Reentrant
** Parameters [in]  : ClusterIndex - Index of the cluster to process
** Return value     : void
** Description      : Processes a single NM coordination cluster
*****************************************************************************************************************/
static void Nm_CoordClusterProcess(uint8 ClusterIndex)
{
    boolean AnyNetworkRequested;
    const Nm_PerClusterConfigType* Nm_PerClusterPtr;
    
    /* Get pointer to the current cluster configuration */
    Nm_PerClusterPtr = &Nm_CoordConfig.NmPerClusterPtr[ClusterIndex];
    
    /* Check if any channel in the cluster has an active network request */
    AnyNetworkRequested = Nm_CoordCheckAnyNetworkReq(Nm_PerClusterPtr);
    
    /* If any channel is not ready to sleep, request network on all active busses in the cluster */
    if (AnyNetworkRequested == TRUE)
    {
        /* Handle network requests for the cluster */
        Nm_CoordNetworkReqHandle(Nm_PerClusterPtr);
    }
    
    /* Check which shutdown state the cluster is in and handle accordingly */
    switch (Nm_ShutdownState[ClusterIndex])
    {
        case NM_SHUTDOWN_START:
            Nm_CoordShutdownStartHandle(Nm_PerClusterPtr, ClusterIndex);
            break;
            
        case NM_SHUTDOWN_RUN:
            Nm_CoordShutdownRunHandle(Nm_PerClusterPtr, ClusterIndex);
            break;
            
        case NM_SHUTDOWN_ABORT:
            /* Handle Coordinator Shutdown Abort */
            Nm_CoordShutdownAbortHandle(Nm_PerClusterPtr);
            /* Reset Shutdown State to Start */
            Nm_ShutdownState[ClusterIndex] = NM_SHUTDOWN_START;
            break;
            
        default:
            /* Other states (INIT, STOP) don't need special handling in the main function */
            break;
    }
}
/*****************************************************************************************************************
** Service Name     : Nm_FindClusterIndex
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ChannelIndex
** Parameters [in]  : ClusterIndexPtr
** Return value     : Std_ReturnType
** Description      : Finds the cluster index for the given channel index
*****************************************************************************************************************/
static Std_ReturnType Nm_FindClusterIndex(uint8 ChannelIndex, uint8* ClusterIndexPtr)
{
    /* SWS_Nm_00168 */
    /* Local Variables */
    uint8 Index = 0U;
    Std_ReturnType RetVal = E_NOT_OK;
    /* Check if Nm Cluster Configuration is available */
    if (Nm_CoordConfig.NmPerClusterPtr != NULL_PTR)
    {
        /* Loop over the clusters */
        for (Index = 0U; Index < NM_NUMBER_OF_CLUSTERS; Index++)
        {
            /* Check if the channel belongs to the current cluster */
            if (Nm_ChannelConfig[ChannelIndex].NmCoordClusterIndex == \
                Nm_CoordConfig.NmPerClusterPtr[Index].NmCoorClusterIndex)
            {
                /* Channel belongs to the current cluster, break the loop */
                RetVal = E_OK;
                *ClusterIndexPtr = Index;
                break;
            }
        }
    }
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordShutdownReady
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Nm_PerClusterPtr
** Parameters [in]  : None
** Return value     : Boolean
** Description      : This function checks if all channels in the cluster are ready for shutdown.
*****************************************************************************************************************/
static boolean Nm_CoordShutdownReady(const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    /* Local Variables */
    uint8 Index = 0U;
    boolean RetVal = FALSE;
    boolean ContinueProcessing = TRUE;
    uint8 ChannelIndex = 0U;
    uint8 NmClusterIncNumChannel = Nm_PerClusterPtr->NmClusterIncNumChannel;
    /* SWS_Nm_00001 */
    /* Loop over the channels in the cluster */
    for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
    {
        /* Get the channel index */
        ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
        /* SWS_Nm_00169 & SWS_Nm_00171 */
        /* Check if the channel is awake */
        if (Nm_CoordStatus[ChannelIndex].Nm_BusAwake == TRUE)
        {
            /* SWS_Nm_00002 & SWS_Nm_00003 */
            /* Check if the upper layer network request is active */
            if (Nm_CoordStatus[ChannelIndex].Nm_UpperLayNetworkReq == TRUE)
            {
                /* Shutdown not ready */
                ContinueProcessing = FALSE;
            }
            else
            {
                /* SWS_Nm_00003 & SWS_Nm_00228 */
                /* Check shutdown conditions for non-sleep master channels (remote sleep indication) and non-topmost \
                   coordinators (coordinator ready sleep bit) */
                if (Nm_CoordCheckSleepConditions(ChannelIndex, Nm_PerClusterPtr) == TRUE)
                {
                    /* Shutdown not ready */
                    ContinueProcessing = FALSE;
                }
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
                /* Check if remote sleep indication is active and if the current channel is the topmost coordinator */
                if ((Nm_CoordStatus[ChannelIndex].Nm_RemoteSleepInd == TRUE) && \
                    (Nm_PerClusterPtr->NmTopMostCoordinator == TRUE))
                {
                    /* SWS_Nm_00172 */
                    /* Check if the current channel is synchronizing */
                    if ((Nm_ChannelConfig[ChannelIndex].NmSynchronizingNetwork == TRUE) && \
                        (Nm_CoordStatus[ChannelIndex].Nm_LowerLayBusSyncPoint == FALSE))
                    {
                        /* Shutdown not ready */
                        ContinueProcessing = FALSE;
                    }
                }
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
            }
        }
        else
        {
            /* Check if the upper layer network request is active */
            if (Nm_CoordStatus[ChannelIndex].Nm_UpperLayNetworkReq == TRUE)
            {
                /* Shutdown not ready */
                ContinueProcessing = FALSE;
            }
        }
        if (ContinueProcessing == FALSE)
        {
            /* Shutdown not ready for this channel, break the loop */
            break;
        }
    }
    /* Check if all channels in the cluster have been evaluated for shutdown readiness */
    if (Index >= Nm_PerClusterPtr->NmClusterIncNumChannel)
    {
        /* All channels are ready for shutdown */
        RetVal = TRUE;
    }

    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordCheckSleepConditions
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ChannelIndex
** Parameters [in]  : Nm_PerClusterPtr
** Return value     : boolean
** Description      : Checks the shutdown conditions for non-sleep master channels and non-topmost coordinators
*****************************************************************************************************************/
static boolean Nm_CoordCheckSleepConditions(uint8 ChannelIndex, const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    boolean ShutdownNotReady = FALSE;
    
    /* SWS_Nm_00003 & SWS_Nm_00228 */
    /* Check shutdown conditions for non-sleep master channels (remote sleep indication) */
    if ((Nm_ChannelConfig[ChannelIndex].NmChannelSleepMaster == FALSE) &&
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == TRUE) &&
#endif
        (Nm_CoordStatus[ChannelIndex].Nm_RemoteSleepInd == FALSE))
    {
        ShutdownNotReady = TRUE;
    }
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
    /* Check shutdown conditions for non-topmost coordinators (coordinator ready sleep bit) */
    else if ((Nm_PerClusterPtr->NmTopMostCoordinator == FALSE) && 
             (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == TRUE) && 
             (Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag == FALSE))
    {
        ShutdownNotReady = TRUE;
    }
    else
    {
        /* Do nothing */
    }
#endif /* NM_COORDINATOR_SYNC_SUPPORT */

    return ShutdownNotReady;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordShutdownTimerLoader
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Nm_PerClusterPtr
** Parameters [in]  : None
** Return value     : Std_ReturnType
** Description      : This function loads the shutdown timer for the NM Coordinator functionality.
*****************************************************************************************************************/
static Std_ReturnType Nm_CoordShutdownTimerLoader(const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    /* Local Variables */
    uint8 Index = 0U;
    uint8 ChannelIndex = 0U;
    Std_ReturnType RetVal = E_OK;
    uint8 NmClusterIncNumChannel = Nm_PerClusterPtr->NmClusterIncNumChannel;
    /* SWS_Nm_00172 */
    /* Check if the synchronization network flag is set */
    if (Nm_PerClusterPtr->NmSyncNetFlag == TRUE)
    {
        /* Loop through all channels in the cluster */
        for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
        {
            /* Get the channel index */
            ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
            /* Check if the channel is awake and synchronizing but lower layer is not synchronized */
            if ((Nm_CoordStatus[ChannelIndex].Nm_BusAwake == TRUE) && \
                (Nm_ChannelConfig[ChannelIndex].NmSynchronizingNetwork == TRUE) && \
                (Nm_CoordStatus[ChannelIndex].Nm_LowerLayBusSyncPoint == FALSE))
            {
                /* Timer cannot be started - break the loop */
                RetVal = E_NOT_OK;
                break;
            }
        }
    }
    /* Check if the shutdown timer can be started */
    if (RetVal == E_OK)
    {
        /* Loop through all channels in the cluster */
        for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
        {
            /* Get the channel index */
            ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
            /* SWS_Nm_00169 & SWS_Nm_00171 */
            /* Check if the channel is awake */
            if (Nm_CoordStatus[ChannelIndex].Nm_BusAwake == TRUE)
            {
                /* Set the allow shutdown flag */
                Nm_CoordStatus[ChannelIndex].Nm_AllowShutdown = TRUE;
                /* SWS_Nm_00174 & SWS_Nm_00175 */
                /* Check if the configured shutdown time is valid and if the channel is the active coordinator */
                if ((Nm_ChannelConfig[ChannelIndex].NmBusNmShutdownTime > NM_GLOBAL_COORDINATOR_TIME)
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
                    || (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == FALSE)
#endif
                )
                {
                    /* Set the shutdown timer to 0 */
                    Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer = 0U;
                }
                else
                {
                    /* Set the shutdown timer to the remaining time */
                    Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer = \
                                    (NM_GLOBAL_COORDINATOR_TIME - Nm_ChannelConfig[ChannelIndex].NmBusNmShutdownTime);
                }
            }
        }
    }
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordShutDownTimerHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Nm_PerClusterPtr
** Parameters [in]  : None
** Return value     : Std_ReturnType
** Description      : This function handles the shutdown timer for the NM Coordinator functionality.
*****************************************************************************************************************/
static Std_ReturnType Nm_CoordShutDownTimerHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr, \
                                                    boolean* SleepAllowPtr)
{
    /* Local Variables */
    uint8 Index = 0U;
    uint8 ChannelIndex = 0U;
    Std_ReturnType RetVal = E_OK;
    boolean SleepAllowed = TRUE;
    uint8 NmClusterIncNumChannel = Nm_PerClusterPtr->NmClusterIncNumChannel;
    /* Loop through all channels in the cluster */
    for (Index = 0U; Index < NmClusterIncNumChannel; Index++)
    {
        /* Get the channel index */
        ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
        /* SWS_Nm_00169 */
        /* Check if the channel is awake */
        if (Nm_CoordStatus[ChannelIndex].Nm_BusAwake == TRUE)
        {
            /* Clear the sleep allowed flag */
            SleepAllowed = FALSE;
            /* Check if the shutdown timer is active */
            if (Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer > 0U)
            {
                /* Decrement the shutdown timer */
                Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer--;
                /* SWS_Nm_00176 */
                /* Check if the shutdown timer has expired and shutdown is allowed */
                if ((Nm_CoordStatus[ChannelIndex].Nm_ShutdownTimer == 0U) && \
                    (Nm_CoordStatus[ChannelIndex].Nm_AllowShutdown == TRUE))
                {
                    /* Clear the allow shutdown flag */
                    Nm_CoordStatus[ChannelIndex].Nm_AllowShutdown = FALSE;
#if (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
                    /* Request bus synchronization */
                    RetVal = Nm_BusNmRequestBusSynchronization(ChannelIndex);
                    /* Check if the request was successful */
                    if (RetVal == E_OK)
#endif /* NM_BUS_SYNCHRONIZATION_ENABLED */
                    {
                        /* Check if the lower layer network is requested */
                        if (Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested == TRUE)
                        {
                            /* Release the lower layer network */
                            RetVal = Nm_BusNmNetworkRelease(ChannelIndex);
                        }
                        else
                        {
                            /* No lower layer network to release */
                            RetVal = E_OK;
                        }
                    }
                    /* Check if the release or the bus synchronization was successful */
                    if (RetVal != E_OK)
                    {
                        /* Handle release/synchronization failure - break the loop */
                        break;
                    }
                }
            }
        }
    }
    /* Check if the shutdown timer was successfully handled */
    if ((RetVal == E_OK) && (SleepAllowed == TRUE))
    {
        /* Allow sleep */
        *SleepAllowPtr = TRUE;
    }
    return RetVal;
}
/*****************************************************************************************************************
** Service Name     : Nm_CoordShutdownAbortHandle
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : Nm_PerClusterPtr
** Parameters [in]  : None
** Return value     : Std_ReturnType
** Description      : This function handles the shutdown abort for the NM Coordinator functionality.
*****************************************************************************************************************/
static void Nm_CoordShutdownAbortHandle(const Nm_PerClusterConfigType* Nm_PerClusterPtr)
{
    /* Local Variables */
    uint8 Index = 0U;
    uint8 ChannelIndex = 0U;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 NmClusterIncNumChannel = Nm_PerClusterPtr->NmClusterIncNumChannel;
    /* Loop through all channels in the cluster */
    for (Index = 0x0U; Index < NmClusterIncNumChannel; Index++)
    {
        /* Get the channel index */
        ChannelIndex = Nm_PerClusterPtr->NmClusterIncChannel[Index];
        /* SWS_Nm_00169, SWS_Nm_00177 & SWS_Nm_00183 */
        /* Check if the channel is awake */
        if (Nm_CoordStatus[ChannelIndex].Nm_BusAwake == TRUE)
        {
            /* Check if the lower layer network is requested */
            if (Nm_CoordStatus[ChannelIndex].Nm_IsLowerLayNetworkRequested == FALSE)
            {
                /* Clear the allow shutdown flag */
                Nm_CoordStatus[ChannelIndex].Nm_AllowShutdown = FALSE;
                /* SWS_Nm_00235 */
                /* Request the lower layer network */
                RetVal = Nm_BusNmNetworkRequest(ChannelIndex);
                /* Check if the request was successful */
                if (RetVal != E_OK)
                {
                    /* Clear the bus awake flag */
                    Nm_CoordStatus[ChannelIndex].Nm_BusAwake = FALSE;
                }
            }
        }
        /* SWS_Nm_00182 */
        else
        {
            /* Notify Communication Manager about NM restart */
            ComM_Nm_RestartIndication(Nm_ChannelConfig[ChannelIndex].ComMChRef);
        }
#if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        /* Check if the channel is the active coordinator */
        if (Nm_ChannelConfig[ChannelIndex].NmActiveCoordinator == FALSE)
        {
            /* Clear the coordinator remote sleep flag */
            Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag = FALSE;
        }
        else
        {
            /* SWS_Nm_00267 */
            /* Handle Coordinator Ready Sleep Bit with FALSE */
            RetVal = Nm_BusNmSetSleepReadyBit(ChannelIndex, FALSE);
            /* Check if the operation was successful */
            if (RetVal == E_OK)
            {
                /* Clear the coordinator remote sleep flag */
                Nm_CoordStatus[ChannelIndex].Nm_CoorRsbFlag = FALSE;
            }
        }
#endif /* NM_COORDINATOR_SYNC_SUPPORT */
    }
}
#if (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_BusNmRequestBusSynchronization
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ChannelIndex
** Return value     : Std_ReturnType
** Description      : This function requests bus synchronization for the specified channel.
*****************************************************************************************************************/
static Std_ReturnType Nm_BusNmRequestBusSynchronization(uint8 ChannelIndex)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    /* Get the BusNm function configuration index for the current channel */
    Nm_BusNmInterfaceConfigIdType BusNmFunctCfgIndex = Nm_ChannelConfig[ChannelIndex].BusNmFunctConfigId;
    if(BusNmFunctCfgIndex < NM_NUM_OF_BUS_NM_SUPPORTED)
    {
        /* Check If respective Bus NM function pointer is valid */
        if ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmRequestBusSynchronizationFunctPtr) != NULL_PTR)
        {
            /* Invoke Bus NM function pointer */
            RetVal = ((Nm_BusNmFunctConfig[BusNmFunctCfgIndex].BusNmRequestBusSynchronizationFunctPtr)(ChannelIndex));
        }
    }
    return RetVal;
}
#endif /* NM_BUS_SYNCHRONIZATION_ENABLED */
#endif /* NM_COORDINATOR_SUPPORT_ENABLED */
#if (NM_DEV_ERROR_DETECT == STD_ON)
/*****************************************************************************************************************
** Service Name     : Nm_DetReportError
** Service ID       : Local Function
** Sync/Async       : Synchronous
** Reentrancy       : Reentrant
** Parameters [in]  : ApiId, ErrorId
** Return value     : void
** Description      : This function will Report Develpment Error to DET.
*****************************************************************************************************************/
static void Nm_DetReportError(uint8 ApiId, uint8 ErrorId)
{
    /* Development Error Report */
    (void)Det_ReportError(NM_MODULE_ID, NM_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/*****************************************************************************************************************
*                                 END OF FILE                                                                    *
******************************************************************************************************************/
/*****************************************************************************************************************
*   For each change to this file, be sure to record:                                                             *
*      1.  who made the change and when the change was made                                                      *
*      2.  why the change was made and the intended result                                                       *
*   Following block needs to be repeated for each change                                                         *
******************************************************************************************************************/
/*!***************************************************************************************************************
*  @date            14-Jul-2023
*  @version         0.0.1
*  @author          EA
*  @brief           Initial Version
*  @tracability     
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date            14-Jul-2025
*  @version         1.0.0
*  @author          MHISHAMU
*  @brief           Implemented Coordination Support
*  @tracability     DICVA-19335
*******************************************************************************************************************/
