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
*   @file EthTcv.c
*   @ingroup EthTcv
*   @brief This file implements the AUTOSAR EthTcv module.The EthTcv module is responsible to Provide the upper layer
*   (Ethernet Interface) a hardware independent interface comprising multiple equal transceivers. This interface 
*   shall be uniform for all transceivers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthTrcv.h"
#include "EthTrcv_Lcfg.h"
#include "SchM_EthTrcv.h"
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((ETHTRCV_SW_MAJOR_VERSION != ETHTRCV_CFG_SW_MAJOR_VERSION) || \
    (ETHTRCV_SW_MINOR_VERSION != ETHTRCV_CFG_SW_MINOR_VERSION) || \
    (ETHTRCV_SW_PATCH_VERSION != ETHTRCV_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((ETHTRCV_AR_RELEASE_MAJOR_VERSION != ETHTRCV_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ETHTRCV_AR_RELEASE_MINOR_VERSION != ETHTRCV_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ETHTRCV_AR_RELEASE_REVISION_VERSION != ETHTRCV_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
#define EthTrcv_DetReportError(ApiId,ErrId) (void)Det_ReportError(ETHTRCV_MODULE_ID,ETHTRCV_INSTANCE_ID,(ApiId),(ErrId)) 
/*! @brief Defines the EthTrcv Init status */
EthTrcv_StateType EthTrcv_InitStatus = ETHTRCV_STATE_UNINIT;  
EthTrcv_LinkStateType EthTrcv_LinkState = ETHTRCV_LINK_STATE_DOWN;
EthTrcv_WakeupModeType  EthTrcv_WakeupMode = ETHTRCV_WUM_DISABLE;
EthTrcv_ModeType EthTrcv_Mode = ETHTRCV_MODE_DOWN;
const EthTrcv_ConfigType * pEthTrcvConfig = &EthTrcv_Config; 
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define ETHTRCV_START_SEC_CODE
#include "MemMap.h"

#define ETHTRCV_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define ETHTRCV_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      Initializes the Ethernet Transceiver Driver
*   @param[in]  CfgPtr  Points to the implementation specific structure 
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, ETHTRCV_CODE) EthTrcv_Init( P2CONST(EthTrcv_ConfigType,AUTOMATIC,ETHTRCV_APPL_CONST) CfgPtr )
{
    ETHTRCV_DUMMY_STATEMENT(CfgPtr);
    /* Initialize the status */ 
    EthTrcv_WakeupMode = ETHTRCV_WUM_DISABLE;
    //LwIpAdp_LinkStateUpdate(LINK_UP);
    EthTrcv_Mode = ETHTRCV_MODE_DOWN;
    /* Update the Eth trcv init status */
    EthTrcv_InitStatus = ETHTRCV_STATE_INIT;
}

/*!******************************************************************************************************************
*   @brief      Enables / disables the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver
*   @param[in]  CtrlMode ETHTRCV_MODE_DOWN: disable the transceiver ETHTRCV_MODE_ACTIVE: enable the transceiver 
*   @return     E_OK: Service accepted E_NOT_OK: Service denied
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType CtrlMode )
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        EthTrcv_Mode = CtrlMode;
        EthIf_TrcvModeIndication(TrcvIdx,EthTrcv_Mode);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_SETTRANSCEIVERMODE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Obtains the state of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] TrcvModePtr ETHTRCV_MODE_DOWN: the transceiver is disabled 
*               ETHTRCV_MODE_ACTIVE: the transceiver is enable
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_ModeType,AUTOMATIC,ETHTRCV_APPL_DATA) TrcvModePtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == TrcvModePtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        *TrcvModePtr = EthTrcv_Mode;
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETTRANSCEIVERMODE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Enables / disables the wake-up mode or clear the wake-up reason of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[in]  TrcvWakeupMode ETHTRCV_WUM_DISABLE: disable transceiver wake up ETHTRCV_WUM_ENABLE: enable transceiver 
*               wake up  ETHTRCV_WUM_CLEAR: clears transceiver wake up reason 
*   @return     E_OK: transceiver wake up mode has been changed. 
*               E_NOT_OK: transceiver wake up mode could not be changed or the wake-up reason could not be cleared.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_SetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    EthTrcv_WakeupModeType TrcvWakeupMode 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(TrcvWakeupMode);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_SETTRANSCEIVERWAKEUPMODE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Returns the wake up mode of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] TrcvWakeupModePtr ETHTRCV_WUM_DISABLE: transceiver wake up is disabled 
*               ETHTRCV_WUM_ENABLE: transceiver wake up is enabled
*   @return     E_OK: success E_NOT_OK: transceiver wake up mode could not be obtained
*   @ServiceID  0x0e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_WakeupModeType,AUTOMATIC,ETHTRCV_APPL_DATA) TrcvWakeupModePtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == TrcvWakeupModePtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(TrcvWakeupModePtr);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETTRANSCEIVERWAKEUPMODE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Service is called by EthTrcv in case a wake-up interrupt is detected.
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @return     E_OK: The function has been successfully executed E_NOT_OK: The function could not be successfully 
*               executed
*   @ServiceID  0x0f
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_CheckWakeup( uint8 TrcvIdx )
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_CHECKWAKEUP_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Restarts the negotiation of the transmission parameters used by the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x05
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_StartAutoNegotiation( uint8 TrcvIdx )
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_STARTAUTONEGOTIATION_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Obtains the link state of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] LinkStatePtr ETHTRCV_LINK_STATE_DOWN: transceiver is disconnected 
*               ETHTRCV_LINK_STATE_ACTIVE: transceiver is connected
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetLinkState
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_LinkStateType,AUTOMATIC,ETHTRCV_APPL_DATA) LinkStatePtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == LinkStatePtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        *LinkStatePtr = EthTrcv_LinkState;
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETLINKSTATE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Obtains the baud rate of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] BaudRatePtr ETHTRCV_BAUD_RATE_10MBIT: 10MBit connection ETHTRCV_BAUD_RATE_100MBIT: 100MBit connection
*               ETHTRCV_BAUD_RATE_1000MBIT: 1000MBit connection
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetBaudRate
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_BaudRateType,AUTOMATIC,ETHTRCV_APPL_DATA) BaudRatePtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == BaudRatePtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(BaudRatePtr);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETBAUDRATE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Obtains the duplex mode of the indexed transceiver
*   @param[in]  TrcvIdx  Index of the transceiver within the context of the Ethernet Transceiver Driver 
*   @param[out] DuplexModePtr ETHTRCV_DUPLEX_MODE_HALF: half duplex connections 
*               ETHTRCV_DUPLEX_MODE_FULL: full duplex connection 
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHTRCV_CODE) EthTrcv_GetDuplexMode
( 
    uint8 TrcvIdx, 
    P2VAR(EthTrcv_DuplexModeType,AUTOMATIC,ETHTRCV_APPL_DATA) DuplexModePtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == DuplexModePtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(DuplexModePtr);
        RetVal = E_OK;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETDUPLEXMODE_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/*!******************************************************************************************************************
*   @brief      Returns the version information of this module
*   @param[out] VersionInfoPtr Version information of this module
*   @ServiceID  0x0b
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(void, ETHTRCV_CODE) EthTrcv_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,ETHTRCV_APPL_DATA) VersionInfoPtr 
) 
{
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (NULL_PTR == VersionInfoPtr)
    {
        ErrorId = ETHTRCV_E_PARAM_POINTER;
    }
    else
    {
        VersionInfoPtr->moduleID = ETHTRCV_MODULE_ID;  
        VersionInfoPtr->vendorID = ETHTRCV_VENDOR_ID;  
        VersionInfoPtr->sw_major_version = ETHTRCV_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = ETHTRCV_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = ETHTRCV_SW_PATCH_VERSION;
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_GETVERSIONINFO_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
}

/*!******************************************************************************************************************
*   @brief      Called when information has been read out via MII interface. Triggered by previous Eth_ReadMii call. 
*               Can directly be called within Eth_ReadMii.
*   @param[in]  CtrlIdx Index of the controller within the context of the Ethernet Driver
*   @param[in]  TrcvIdx Index of the transceiver on the MII
*   @param[in]  RegIdx Index of the transceiver register on the MII
*   @param[in]  RegVal Value contained in the indexed register 
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different Parameters.
********************************************************************************************************************/
FUNC(void, ETHTRCV_CODE) EthTrcv_ReadMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx, uint8 RegVal )
{
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(CtrlIdx);
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(RegVal);
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_READMIIINDICATION_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
}

/*!******************************************************************************************************************
*   @brief      Called when information has been written via MII interface. Triggered by previous Eth_WriteMii call.
*               Can directly be called within Eth_WriteMii.
*   @param[in]  CtrlIdx Index of the controller within the context of the Ethernet Driver
*   @param[in]  TrcvIdx Index of the transceiver on the MII
*   @param[in]  RegIdx Index of the transceiver register on the MII
*   @ServiceID  0x0a
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different Parameters.
********************************************************************************************************************/
FUNC(void, ETHTRCV_CODE) EthTrcv_WriteMiiIndication( uint8 CtrlIdx, uint8 TrcvIdx, uint8 RegIdx )
{
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else if (pEthTrcvConfig->EthTrcvTotalTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHTRCV_E_INV_TRCV_IDX;
    }
    else
    {
        ETHTRCV_DUMMY_STATEMENT(CtrlIdx);
        ETHTRCV_DUMMY_STATEMENT(TrcvIdx);
        ETHTRCV_DUMMY_STATEMENT(RegIdx);
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_WRITEMIIINDICATION_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
}

/*!******************************************************************************************************************
*   @brief      Used for polling state changes and wakeup reasons. Calls EthTrcv_TrcvModeIndication when the transceiver
*               mode changed. Stores wakeup events if EthTrcvWakeUpSupport is set to ETHTRCV_WAKEUP_BY_POLLING.
*   @ServiceID  0x0c
********************************************************************************************************************/
FUNC(void, ETHTRCV_CODE) EthTrcv_MainFunction( void )
{
    uint8 ErrorId = ETHTRCV_E_NO_ERROR;
    
    if (ETHTRCV_STATE_INIT != EthTrcv_InitStatus)
    {
        ErrorId = ETHTRCV_E_NOT_INITIALIZED;
    }
    else
    {
        
    }
#if (ETHTRCV_DEV_ERROR_DETECT == STD_ON)
    if (ETHTRCV_E_NO_ERROR != ErrorId)
    {
        EthTrcv_DetReportError(ETHTRCV_MAINFUNCTION_API, ErrorId);
    }
#else
    ETHTRCV_DUMMY_STATEMENT(ErrorId);
#endif
}

#define ETHTRCV_STOP_SEC_CODE
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

