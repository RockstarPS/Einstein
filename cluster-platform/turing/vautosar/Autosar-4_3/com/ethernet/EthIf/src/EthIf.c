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
*   @file EthIf.c
*   @ingroup EthIf
*   @brief This file implements the AUTOSAR EthIf module.The EthIf module is responsible for the control flow
*          abstraction of the configured Eth Controllers , Eth Transceivers and Eth Switches.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Eth.h"
#include "EthIf.h"
#include "EthIf_Lcfg.h"
#include "EthIf_Cbk.h"
#include "SchM_EthIf.h"
#if (ETHIF_TRCV_SUPPORT == STD_ON)
 #include "EthTrcv.h"
#endif
#if (ETHIF_SWITCH_SUPPORT == STD_ON)
#include "EthSwt.h"
#endif
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((ETHIF_SW_MAJOR_VERSION != ETHIF_CFG_SW_MAJOR_VERSION) || \
    (ETHIF_SW_MINOR_VERSION != ETHIF_CFG_SW_MINOR_VERSION) || \
    (ETHIF_SW_PATCH_VERSION != ETHIF_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((ETHIF_AR_RELEASE_MAJOR_VERSION != ETHIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (ETHIF_AR_RELEASE_MINOR_VERSION != ETHIF_CFG_AR_RELEASE_MINOR_VERSION) || \
    (ETHIF_AR_RELEASE_REVISION_VERSION != ETHIF_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#define EthIf_DetReportError(ApiId,ErrId) (void)Det_ReportError(ETHIF_MODULE_ID,ETHIF_INSTANCE_ID,(ApiId),(ErrId))
/*! @brief Defines the ethernet frame type for Vlan */
#define ETH_FRAME_TYPE_VLAN     0x8100u
/*! @brief Defines the Vlan ethernet frame type High byte  */
#define ETH_FRAME_VLAN_HI       0x81u
/*! @brief Defines the Vlan ethernet frame type Low byte  */
#define ETH_FRAME_VLAN_LOW      0x00u
#define PCP_SHIFT_BITS_5        5u
#define PCP_SHIFT_BITS_4        4u
#define PCP_MASK                0xE0u
#define VLAN_MASK_NIBBLE        0x0F00u
#define VLAN_MASK_BYTE          0x00FFu
#define SHIFT_EIGHT_BITS        8u
#define FRAME_MASK_HI           0xFF00u
#define FRAME_MASK_LOW          0x00FFu
#define VLAN_TAG_SIZE           4u
#define PRIORITY_SIZE           8u
#define ETHIF_VID_MASK          0x0FFFu
#define ETHIF_SHIFT_BYTE1       8u
#define ETHIF_BYTE_MASK         0xFFu
#define INVALID_VLAN_ID         4095u
#define INVALID_BUFFER_INDEX    0xFFFFFFFFUL
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the type for the mapping of buffer id and frame type */
typedef struct 
{
    Eth_FrameType  FrameType; /*! @brief frame type mapped to the buffer id */
    uint32  BufferIdx; /*! @brief buffer idx mapped to the frame owner */
}EthIf_BufferIdToFrameMapType;

typedef enum
{
    ETHIF_CTRL_LINK_STATE_NO_LINK = 0u,
    ETHIF_CTRL_LINK_STATE_LINK_CHANGE_DOWN = 1u,
    ETHIF_CTRL_LINK_STATE_LINK_CHANGE_UP = 2u,
    ETHIF_CTRL_LINK_STATE_LINK = 3u
}EthIf_CtrlLinkStateType;
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/*! @brief Defines the type for the mapping of buffer id and frame type at run time */
EthIf_BufferIdToFrameMapType EthIf_BufferIdToFrameMap[ETHIF_NUM_OF_FRAME_OWNERS]; 
EthIf_CtrlLinkStateType EthIf_CtrlLinkState[ETHIF_NUM_OF_CONTROLLERS]; 
/*! @brief Defines the EthIf Init status */
EthIf_StateType EthIf_InitStatus = ETHIF_STATE_UNINIT;  
/*! @brief Defines the EthIf Init status */
const EthIf_ConfigType* pEthIfConfig = &EthIf_Config;

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/

#define ETHIF_START_SEC_CODE
#include "MemMap.h"

#define ETHIF_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define ETHIF_START_SEC_CODE
#include "MemMap.h"
/*!******************************************************************************************************************
*   @brief      Initializes the Ethernet Interface
*   @param[in]  CfgPtr  Points to the implementation specific structure
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_Init( P2CONST(EthIf_ConfigType,AUTOMATIC,ETHIF_APPL_CONST) CfgPtr )
{
    uint8 OwnerIdx;
    uint8 CtrlIdx;

    /* Initilaize the buffer to frame id mapping */
    for (OwnerIdx=0; OwnerIdx < pEthIfConfig->EthIfOwnersCount; OwnerIdx++)
    {
        EthIf_BufferIdToFrameMap[OwnerIdx].FrameType = pEthIfConfig->pEthIfOwnerCfg[OwnerIdx].EthIfFrameType;
        EthIf_BufferIdToFrameMap[OwnerIdx].BufferIdx = INVALID_BUFFER_INDEX;
    }
    /* intialize the controller */ 
    for (CtrlIdx = 0u; CtrlIdx < pEthIfConfig->EthIfCtrlCount;CtrlIdx++)
    {
        EthIf_CtrlLinkState[CtrlIdx] = ETHIF_CTRL_LINK_STATE_NO_LINK;
    }
    /* Set the status to Init */
    EthIf_InitStatus = ETHIF_STATE_INIT;
    ETHIF_DUMMY_STATEMENT(CfgPtr);
}

/********************************************************************************************************************
*   @brief      Enables / disables the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  CfgPtr  ETH_MODE_DOWN: disable the controller ETH_MODE_ACTIVE: enable the controller
*   @return     E_OK: success E_NOT_OK: controller mode could not be changed
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetControllerMode( uint8 CtrlIdx, Eth_ModeType CtrlMode )
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx )
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;
    }
    else
    {
        RetVal = Eth_SetControllerMode(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, CtrlMode);
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETCTRLMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Obtains the state of the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] CtrlModePtr  pointer to the get the controller mode
*               ETH_MODE_DOWN: the controller is disabled ETH_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: controller could not be initialized
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetControllerMode
( 
    uint8 CtrlIdx, 
    P2VAR(Eth_ModeType,AUTOMATIC,ETHIF_APPL_VAR) CtrlModePtr 
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx )
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;
    }
    else if (NULL_PTR == CtrlModePtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;
    }
    else
    {
        RetVal = Eth_GetControllerMode(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, CtrlModePtr);
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETCTRLMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Enables / disables the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvMode  ETHTRCV_MODE_DOWN: the controller is disabled ETHTRCV_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: transceiver mode could not be changed
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType TrcvMode )
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfTrcvCount <= TrcvIdx )
    {
        ErrorId = ETHIF_E_INV_TRCV_IDX ;
    }
    else 
    {
        EthTrcv_SetTransceiverMode(TrcvIdx,TrcvMode);
        RetVal = E_OK;
    }    
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETTRCVMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Obtains the state of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[out]  TrcvModePtr  pointer to the get the controller mode
*               ETHTRCV_MODE_DOWN: the controller is disabled ETHTRCV_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverMode
( 
    uint8 TrcvIdx,
    P2VAR(EthTrcv_ModeType,AUTOMATIC,ETHIF_APPL_VAR) TrcvModePtr 
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfTrcvCount <= TrcvIdx )
    {
        ErrorId = ETHIF_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == TrcvModePtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;
    }
    else
    {
        EthTrcv_GetTransceiverMode(TrcvIdx,TrcvModePtr);
        RetVal=E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETTRCVMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif
    
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Enables / disables the wake up mode or clear the wake-up reason of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvWakeupMode  ETHTRCV_WUM_DISABLE: disable transceiver wake up 
*               ETHTRCV_WUM_ENABLE: enable transceiver wake up ETHTRCV_WUM_CLEAR: clears transceiver wake up reason
*   @return     E_OK: success E_NOT_OK: transceiver wake up could not be changed or wake-up reason could not be cleared
*   @ServiceID  0x2e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    EthTrcv_WakeupModeType TrcvWakeupMode 
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfTrcvCount <= TrcvIdx )
    {
        ErrorId = ETHIF_E_INV_TRCV_IDX ;
    }
    else 
    {
        ETHIF_DUMMY_STATEMENT(TrcvWakeupMode);
        RetVal = E_OK;
    }    
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETTRCVWAKEUPMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Returns the wake up mode of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[out] TrcvWakeupModePtr  pointer to get the wakeup mode
*               ETHTRCV_WUM_DISABLE: transceiver wake up is disabled ETHTRCV_WUM_ENABLE: transceiver wake up is enabled
*   @return     E_OK: success E_NOT_OK: transceiver wake up mode could not be obtained
*   @ServiceID  0x2f
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverWakeupMode
(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType,AUTOMATIC,ETHIF_APPL_VAR) TrcvWakeupModePtr 
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfTrcvCount <= TrcvIdx )
    {
        ErrorId = ETHIF_E_INV_TRCV_IDX;
    }
    else if (NULL_PTR == TrcvWakeupModePtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(TrcvWakeupModePtr);
        RetVal=E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETTRCVWAKEUPMODE_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif
    
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Service is called by integration code to check a wakeup source.
*   @param[in]  WakeupSource source (transceiver) which initiated the wake up event
*   @return     E_OK when function has been successfully executed
*               E_NOT_OK when function could not be successfully executed
*   @ServiceID  0x30
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(WakeupSource);
        RetVal=E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_CHECKWAKEUP_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Obtains the physical source address used by the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] PhysAddrPtr Physical source address (MAC address) in network byte order
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_GetPhysAddr
( 
    uint8 CtrlIdx,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) PhysAddrPtr
)
{
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        Eth_GetPhysAddr(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, PhysAddrPtr);
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETPHYADDR_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Sets the physical source address used by the indexed controller.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Driver.
*   @param[out] PhysAddrPtr Pointer to memory containing the physical source address (MAC address) in network byte 
*               order.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_SetPhysAddr
( 
    uint8 CtrlIdx,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr 
)
{
    uint8 ErrorId=ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        Eth_SetPhysAddr(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, PhysAddrPtr);
    }    
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETPHYADDR_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Update the physical source address to/from the indexed controller filter. If the Ethernet Controller 
*               is not capable to do the filtering, the software has to do this.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Driver.
*   @param[in]  PhysAddrPtr Pointer to memory containing the physical destination address (MAC address) in network byte
*               order. This is the multicast destination address of the layer 2 Ethernet packet
*   @param[in]  Action Add or remove the address from the Ethernet controllers filter
*   @retrun     E_OK: filter was successfully changed E_NOT_OK: filter could not be changed
*   @ServiceID  0x0c
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_UpdatePhysAddrFilter
( 
    uint8 CtrlIdx,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr,
    Eth_FilterActionType Action
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        #if (ETHIF_ETHDRV_PHYS_ADRS_FILTER_API == STD_ON)
        RetVal = Eth_UpdatePhysAddrFilter( pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, PhysAddrPtr, Action);
        #else
        ETHIF_DUMMY_STATEMENT(Action);
        #endif
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_UPDATEPHYADDRFILTER_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Obtains the port over which this MAC-address can be reached.
*   @param[in]  MacAddrPtr MAC-address for which a switch port is searched over which the node with this MAC-address 
*               can be reached.
*   @param[out] SwitchIdxPtr Pointer to the switch index
*   @param[out] PortIdxPtr Pointer to the port index
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized
*   @ServiceID  0x28
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetPortMacAddr
( 
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) MacAddrPtr,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) SwitchIdxPtr,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) PortIdxPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if ((NULL_PTR == MacAddrPtr) || (NULL_PTR == SwitchIdxPtr) || (NULL_PTR == PortIdxPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(MacAddrPtr);
        ETHIF_DUMMY_STATEMENT(SwitchIdxPtr);
        ETHIF_DUMMY_STATEMENT(PortIdxPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETPORTMACADDR_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}

#if (ETHIF_SWITCH_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Obtains the address resolution table of a switch and copies the list into a user provided buffer. The
*               function will copy all or numberOfElements into the output list. If input value of numberOfElements 
*               is 0 the function will not copy any data but only return the number of valid entries in the cache. 
*               arlTableListPointer may be NULL_PTR in this case.
*   @param[in]  switchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @param[in,out] numberOfElements In: Maximum number of elements which can be written into the arlTable 
*                  Out: Number of elements which are currently available in the EthSwitch module.
*   @param[out] arlTableListPointer Returns a pointer to the memory where the ARL table of the switch consisting of a 
*               list of structs with MAC-address, VLAN-ID and port shall be stored.
*   @retrun     E_OK: success E_NOT_OK: requested switchIdx is not valid or inactive
*   @ServiceID  0x29
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetArlTable
( 
    uint8 SwitchIdx,
    P2VAR(EthSwt_MacVlanType,AUTOMATIC,ETHIF_APPL_VAR) ArlTable 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfSwitchCount <= SwitchIdx)
    {
        ErrorId = ETHIF_E_INV_SWT_IDX;   
    }
    else if ((NULL_PTR == MacAddrPtr) || (NULL_PTR == SwitchIdxPtr) || (NULL_PTR == PortIdxPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(MacAddrPtr);
        ETHIF_DUMMY_STATEMENT(SwitchIdxPtr);
        ETHIF_DUMMY_STATEMENT(PortIdxPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETARLTABEL_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
#endif
/********************************************************************************************************************
*   @brief      Reads the buffer level of the corresponding switch. Whether this buffer level is one value for the 
*               entire switch (shared memory) or one value for each port at a switch is technology dependent.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @param[out] SwitchBufferLevelPtr The interpretation of this value is switch dependent 
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized
*   @ServiceID  0x2a
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetBufferLevel
( 
    uint8 SwitchIdx, 
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) SwitchBufferLevelPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfSwitchCount <= SwitchIdx)
    {
        ErrorId = ETHIF_E_INV_SWT_IDX;   
    }
    else if (NULL_PTR == SwitchBufferLevelPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(SwitchBufferLevelPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETBUFLEVEL_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Reads the buffer level of the corresponding switch. Whether this buffer level is one value for the 
*               entire switch (shared memory) or one value for each port at a switch is technology dependent.
*   @param[in,out]  NumberOfCtrlIdx in: maximum number of controllers in CtrlIdxListPtr, 0 to return the number of 
*               controllers but without filling CtrlIdxListPtr. out: number of active controllers.
*   @param[out] CtrlIdxListPtr List of active controller indexes
*   @retrun     E_OK: success E_NOT_OK: failure
*   @ServiceID  0x44
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCtrlIdxList
( 
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) NumberOfCtrlIdx,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) CtrlIdxListPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if ((NULL_PTR == NumberOfCtrlIdx) || (NULL_PTR == CtrlIdxListPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(NumberOfCtrlIdx);
        ETHIF_DUMMY_STATEMENT(CtrlIdxListPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETCTRLIDXLIST_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Returns the VLAN identifier of the requested Ethernet controller.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] VlanIdPtr Pointer to store the VLAN identifier (VID) of the Ethernet controller. 0 if the the Ethernet 
*               controller represents no virtual network (VLAN).
*   @retrun     E_OK: success E_NOT_OK: failure
*   @ServiceID  0x43
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetVlanId
( 
    uint8 CtrlIdx, 
    P2VAR(uint16,AUTOMATIC,ETHIF_APPL_VAR) VlanIdPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == VlanIdPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(VlanIdPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETVLANID_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Allows to read and reset detailed measurement data for diagnostic purposes. Get all MeasurementIdx's
*               at once is not supported. ETHIF_MEAS_ALL shall only be used to reset all MeasurementIdx's at once.
*               A NULL_PTR shall be provided for MeasurementDataPtr in this case.
*   @param[in]  MeasurementIdx Data index of measurement data
*   @param[in]  MeasurementResetNeeded Flag to trigger a reset of the measurement data.
*   @param[out] MeasurementDataPtr Reference to data buffer, where to copy measurement data
*   @retrun     E_OK: success E_NOT_OK: failure
*   @ServiceID  0x45
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetAndResetMeasurementData
( 
    EthIf_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) MeasurementDataPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (NULL_PTR == MeasurementDataPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(MeasurementIdx);
        ETHIF_DUMMY_STATEMENT(MeasurementResetNeeded);
        ETHIF_DUMMY_STATEMENT(MeasurementDataPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETANDRESETMEASUREMENTDATA_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
#if (ETHIF_AR_RELEASE_MAJOR_VERSION == 4u) && (ETHIF_AR_RELEASE_MINOR_VERSION == 2U)
/********************************************************************************************************************
*   @brief      To get the drop count for the ethernet frames
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @param[out] DropCount Reference to data buffer, where to copy dropcount data
*   @retrun     E_OK: success E_NOT_OK: failure
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetDropCount
( 
    uint8 SwitchIdx,
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) DropCount
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfSwitchCount <= SwitchIdx)
    {
        ErrorId = ETHIF_E_INV_SWT_IDX;   
    }
    else if (NULL_PTR == DropCount)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(VlanIdPtr);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETDROPCOUNT_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
#endif
/********************************************************************************************************************
*   @brief      Stores the configuration of the learned MAC/Port tables of a switch in a persistent manner and will
*               be used by e.g. CDD.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized or unknown index
*   @ServiceID  0x2c
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_StoreConfiguration( uint8 SwitchIdx )
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfSwitchCount <= SwitchIdx)
    {
        ErrorId = ETHIF_E_INV_SWT_IDX;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(SwitchIdx);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_STORECONFIG_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Resets the configuration of the learned MAC/Port tables of a switch in a persistent manner and will 
*               be used by e.g. CDD. The statically configured entries shall still remain.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized or unknown index
*   @ServiceID  0x2d
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_ResetConfiguration( uint8 SwitchIdx )
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfSwitchCount <= SwitchIdx)
    {
        ErrorId = ETHIF_E_INV_SWT_IDX;   
    }
    else
    {
        ETHIF_DUMMY_STATEMENT(SwitchIdx);
        RetVal = E_OK;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_RESETCONFIG_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
#if (ETHIF_GLOBAL_TIME_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Returns a time value out of the HW registers according to the capability of the HW. Is the HW 
*               resolution is lower than the Eth_TimeStampType resolution resp. range, the remaining bits will be 
*               filled with 0.
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[out] timeQualPtr quality of HW time stamp, e.g. based on current drift
*   @param[out] timeStampPtr current time stamp
*   @retrun     E_OK: successful E_NOT_OK: failed
*   @ServiceID  0x22
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCurrentTime
( 
    uint8 CtrlIdx,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        RetVal = Eth_GetCurrentTime(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, 
                                    timeQualPtr, timeStampPtr );
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETCURRENTTIME_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Activates egress time stamping on a dedicated message object. Some HW does store once the egress time
*               stamp marker and some HW needs it always before transmission. There will be no "disable" functionality,
*               due to the fact, that the message type is always "time stamped" by network design.
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[out] BufIdx Index of the message buffer, where Application expects egress time stamping
*   @ServiceID  0x23
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_EnableEgressTimeStamp( uint8 CtrlIdx, Eth_BufIdxType BufIdx )
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else
    {
        Eth_EnableEgressTimeStamp(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, BufIdx );
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_ENABLEEGRESSTIMESTAMP_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Reads back the egress time stamp on a dedicated message object. It must be called within the 
*               TxConfirmation() function.
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[in]  BufIdx Index of the message buffer, where the Upper Layer expects egress time stamping
*   @param[out] timeQualPtr quality of HW time stamp, e.g. based on current drift
*   @param[out] timeStampPtr current time stamp
*   @ServiceID  0x24
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_GetEgressTimeStamp
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
)
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        Eth_GetEgressTimeStamp(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, BufIdx,
                                timeQualPtr, timeStampPtr );
    }  
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETEGRESSTIMESTAMP_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Reads back the ingress time stamp on a dedicated message object. It must be called within the 
*               RxIndication() function.
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[in]  DataPtr Pointer to the message buffer, where Application expects ingress time stamping
*   @param[out] timeQualPtr quality of HW time stamp, e.g. based on current drift
*   @param[out] timeStampPtr current time stamp
*   @ServiceID  0x25
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_GetIngressTimeStamp
( 
    uint8 CtrlIdx,
    P2VAR(Eth_DataType,AUTOMATIC,ETHIF_APPL_VAR) DataPtr,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
)
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ((NULL_PTR == timeQualPtr) || (NULL_PTR == timeStampPtr) || (NULL_PTR == DataPtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        Eth_GetIngressTimeStamp(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, DataPtr,
                                    timeQualPtr, timeStampPtr );
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETINGRESSTIMESTAMP_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
#if (ETHIF_AR_RELEASE_MAJOR_VERSION == 4u) && (ETHIF_AR_RELEASE_MINOR_VERSION == 2U)
/********************************************************************************************************************
*   @brief      Allows the Time Slave to adjust the local ETH Reference clock in HW..
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[in]  timeOffsetPtr offset between time stamp grandmaster and time stamp by local clock: 
*               (OriginTimeStampSync[FUP] – IngressTimeStampSync) + Pdelay
*   @param[in]  time elements to calculate and to modify the ratio of the frequency of the grandmaster in relation to 
*               the frequency of the Local Clock with: ratio = OriginTimeStampDelta / IngressTimeStampDelta
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_SetCorrectionTime
( 
    uint8 CtrlIdx,
    P2CONST(Eth_TimeIntDiffType,AUTOMATIC,ETHIF_APPL_CONST) timeOffsetPtr,
    P2CONST(Eth_RateRatioType,AUTOMATIC,ETHIF_APPL_CONST) rateRatioPtr 
)
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ((NULL_PTR == timeOffsetPtr) || (NULL_PTR == rateRatioPtr) )
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        Eth_SetCorrectionTime(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, timeOffsetPtr, rateRatioPtr );
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETCORRECTIONTIME_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Allows the Time Master to adjust the global ETH Reference clock in HW. We can use this method to set a
*               global time base on ETH in general or to synchronize the global ETH time base with another time base
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[in]  timeStampPtr new time stamp
*   @param[in]  time elements to calculate and to modify the ratio of the frequency of the grandmaster in relation to 
*               the frequency of the Local Clock with: ratio = OriginTimeStampDelta / IngressTimeStampDelta
*   @return     E_OK: successful E_NOT_OK: failed
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetGlobalTime
( 
    uint8 CtrlIdx,
    P2CONST(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_CONST) timeStampPtr 
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == timeStampPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        RetVal = Eth_SetGlobalTime(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, timeStampPtr);
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_SETGLOBALTIME_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
#endif
#endif
/********************************************************************************************************************
*   @brief      Provides access to a transmit buffer of the specified Ethernet controller.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  FrameType Ethernet Frame Type (EtherType)
*   @param[in]  Priority Priority value which shall be used for the 3-bit PCP field of the VLAN tag
*   @param[out] BufIdxPtr Index to the granted buffer resource. To be used for subsequent requests
*   @param[out] BufPtr Pointer to the granted buffer
*   @param[in,out]  LenBytePtr in: desired length in bytes, out: granted length in bytes
*   @return     BUFREQ_OK: success BUFREQ_E_NOT_OK: development error detected BUFREQ_E_BUSY: all buffers in use
*   @ServiceID  0x09
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(BufReq_ReturnType, ETHIF_CODE) EthIf_ProvideTxBuffer
( 
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    uint8 Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHIF_APPL_VAR) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, ETHIF_APPL_VAR) LenBytePtr
)
{
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    uint8 * pDataBuf;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ((NULL_PTR == BufIdxPtr) || (NULL_PTR == BufPtr) || (NULL_PTR == LenBytePtr))
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        if(INVALID_VLAN_ID == pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId)
        {
            if(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlMtu >= *LenBytePtr)
            {
                RetVal = Eth_ProvideTxBuffer(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId,0u, 
                                                BufIdxPtr, BufPtr, LenBytePtr);
            }
            else 
            {
                RetVal = BUFREQ_E_NOT_OK;
            }
        }
        else
        {
            if((pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlMtu >= *LenBytePtr) && (Priority < PRIORITY_SIZE))
            {
                *LenBytePtr= (*LenBytePtr + VLAN_TAG_SIZE);
                RetVal = Eth_ProvideTxBuffer(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId,
                                                0u,BufIdxPtr, BufPtr, LenBytePtr);

                pDataBuf = *BufPtr;
                if (BUFREQ_OK == RetVal)
                {
                    pDataBuf[0]  = (uint8)( Priority << PCP_SHIFT_BITS_5);
                    pDataBuf[0]  &= (uint8)PCP_MASK;
                    pDataBuf[0] |= (uint8)((pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId & VLAN_MASK_NIBBLE) >> SHIFT_EIGHT_BITS);
                    pDataBuf[1]  = (uint8)(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId & VLAN_MASK_BYTE);
                    pDataBuf[2]  = (uint8)((FrameType >> ETHIF_SHIFT_BYTE1) & ETHIF_BYTE_MASK);
                    pDataBuf[3]  = (uint8)( FrameType & ETHIF_BYTE_MASK);
                }

                *BufPtr = &pDataBuf[VLAN_TAG_SIZE];
                *LenBytePtr = (*LenBytePtr - VLAN_TAG_SIZE);
            }
            else 
            {
                RetVal = BUFREQ_E_NOT_OK;
            }
        }
    }
    ETHIF_DUMMY_STATEMENT(FrameType);
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_PROVIDETXBUFFER_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;
}
/********************************************************************************************************************
*   @brief      Triggers transmission of a previously filled transmit buffer
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  BufIdx Index of the buffer resource
*   @param[in]  FrameType Ethernet Frame Type (EtherType)
*   @param[in]  TxConfirmation Activates transmission confirmation
*   @param[in]  LenByte Data length in byte 
*   @param[in]  PhysAddrPtr Physical target address (MAC address) in network byte order 
*   @return     BUFREQ_OK: success BUFREQ_E_NOT_OK: transmission failed
*   @ServiceID  0x0a
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Transmit
( 
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    Eth_FrameType FrameType,
    boolean TxConfirmation,
    uint16 LenByte,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr 
)
{
    uint8 OwnerIdx;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfMaxTxBufsTotal <= BufIdx)
    {
        ErrorId = ETHIF_E_INV_PARAM;   
    }
    else if (NULL_PTR == PhysAddrPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {

        if(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlMtu >= LenByte)
        {
            if(INVALID_VLAN_ID != pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId)
            {
                RetVal = Eth_Transmit(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, BufIdx, 
                                        ETH_FRAME_TYPE_VLAN, TxConfirmation, (LenByte + VLAN_TAG_SIZE), PhysAddrPtr);
            }
            else
            {
                RetVal = Eth_Transmit(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, BufIdx, FrameType, 
                                        TxConfirmation, LenByte, PhysAddrPtr);
            }
            if ((E_OK == RetVal) && (pEthIfConfig->pEthIfULTxConfirmationFuncArr != NULL_PTR))
            {
                for (OwnerIdx=0; OwnerIdx < pEthIfConfig->EthIfOwnersCount; OwnerIdx++) 
                {
                    if (FrameType == (Eth_FrameType)EthIf_BufferIdToFrameMap[OwnerIdx].FrameType)
                    {
                        if (TRUE == TxConfirmation) 
                        {
                            /* Currently used buffer index stored for the requested frame type */
                            EthIf_BufferIdToFrameMap[OwnerIdx].BufferIdx = BufIdx; 
                        } 
                        else 
                        {
                            /* Reset the buffer index when no TxConfirmation is requested */
                            EthIf_BufferIdToFrameMap[OwnerIdx].BufferIdx = INVALID_BUFFER_INDEX; 
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            RetVal = E_NOT_OK;
        }
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_TRANSMIT_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

    return RetVal;   
}

#if (ETHIF_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      Returns the version information of this module
*   @param[out] VersionInfoPtr Version information of this module
*   @ServiceID  0x0b
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ETHIF_APPL_VAR) VersionInfoPtr)
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    
    if (NULL_PTR == VersionInfoPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        VersionInfoPtr->moduleID = ETHIF_MODULE_ID;  
        VersionInfoPtr->vendorID = ETHIF_VENDOR_ID;  
        VersionInfoPtr->sw_major_version = ETHIF_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = ETHIF_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = ETHIF_SW_PATCH_VERSION;
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_GETVERSIONINFO_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
#endif
#if (ETHIF_ENABLE_RX_INTERRUPT == STD_OFF)
/********************************************************************************************************************
*   @brief      The function checks for new received frames and issues transmission confirmations in polling mode. 
*               It checks also for transceiver state changes.
*   @ServiceID  0x20
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_MainFunctionRx( void )
{
    uint8 CtrlIdx;
    uint8 IterationIdx;
    uint8 ErrorId = ETHIF_E_NO_ERROR;
    Eth_RxStatusType RxStatus = ETH_NOT_RECEIVED;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else
    {
        for(CtrlIdx = 0u; CtrlIdx < pEthIfConfig->EthIfCtrlCount; CtrlIdx++)
        {
            Eth_Receive(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, &RxStatus);

            for(IterationIdx= 0; IterationIdx < ETHIF_RX_INDICATION_ITERATIONS ; IterationIdx++)
            {
                if(RxStatus == ETH_RECEIVED_MORE_DATA_AVAILABLE)
                {
                    Eth_Receive(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId, &RxStatus);
                }
                else
                {
                    break;
                }
            }
        }
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_MAINFUNCTIONRX_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
#endif
#if (ETHIF_ENABLE_TX_INTERRUPT == STD_OFF)
/********************************************************************************************************************
*   @brief      The function issues transmission confirmations in polling mode. It checks also for transceiver state
*               changes.
*   @ServiceID  0x21
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_MainFunctionTx( void )
{
    uint8 CtrlIdx;
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else
    {
        for(CtrlIdx=0; CtrlIdx < pEthIfConfig->EthIfCtrlCount; CtrlIdx++)
        {
            Eth_TxConfirmation( pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId );
        }
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_MAINFUNCTIONTX_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
#endif
/********************************************************************************************************************
*   @brief      The function is polling different communication hardware (Ethernet transceiver, 
*               Ethernet switch ports) related information, e.g. link state, signal quality
*   @ServiceID  0x21
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_MainFunctionState( void )
{
    uint8 CtrlIdx;
    Eth_ModeType Eth_Mode = ETH_MODE_DOWN; 
    EthTrcv_LinkStateType LinkState=ETHTRCV_LINK_STATE_DOWN;  
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else
    {
        /* intialize the controller */ 
        for (CtrlIdx = 0u; CtrlIdx < pEthIfConfig->EthIfCtrlCount;CtrlIdx++)
        {
            /* check for change  */
            (void)Eth_GetControllerMode(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthCtrlId,&Eth_Mode);
            (void)EthTrcv_GetLinkState(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfEthTrcvId,&LinkState);
            if (Eth_Mode == ETH_MODE_ACTIVE)
            {
                if (LinkState == ETHTRCV_LINK_STATE_ACTIVE)
                {
                    if (EthIf_CtrlLinkState[CtrlIdx] != ETHIF_CTRL_LINK_STATE_LINK)
                    {
                        EthIf_CtrlLinkState[CtrlIdx] = ETHIF_CTRL_LINK_STATE_LINK_CHANGE_UP;
                    }
                }
                else
                {
                    if (EthIf_CtrlLinkState[CtrlIdx] != ETHIF_CTRL_LINK_STATE_NO_LINK)
                    {
                        EthIf_CtrlLinkState[CtrlIdx] = ETHIF_CTRL_LINK_STATE_LINK_CHANGE_DOWN;
                    }
                }
            }
            
            // notify change 
            if (EthIf_CtrlLinkState[CtrlIdx] == ETHIF_CTRL_LINK_STATE_LINK_CHANGE_UP)
            {
                EthIf_CtrlLinkState[CtrlIdx] = ETHIF_CTRL_LINK_STATE_LINK;
                EthSM_TrcvLinkStateChg(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlId,ETHTRCV_LINK_STATE_ACTIVE);
            }
            else if (EthIf_CtrlLinkState[CtrlIdx] == ETHIF_CTRL_LINK_STATE_LINK_CHANGE_DOWN)
            {
                EthIf_CtrlLinkState[CtrlIdx] = ETHIF_CTRL_LINK_STATE_NO_LINK;
                EthSM_TrcvLinkStateChg(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlId,ETHTRCV_LINK_STATE_DOWN);
            }
            else
            {

            }
        }
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_MAINFUNCTIONTX_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/********************************************************************************************************************
*   @brief      Confirms frame transmission by the indexed controller
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  BufIdx Index of the transmitted buffer
*   @param[in]  Result E_OK: The transmission was successful, E_NOT_OK: The transmission failed.
*   @ServiceID  0x11
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_TxConfirmation( uint8 CtrlIdx, Eth_BufIdxType BufIdx, Std_ReturnType Result )
{
    uint8 OwnerIdx;
    uint8 TxHandle;
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if ( pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfMaxTxBufsTotal <= BufIdx )
    {
        ErrorId = ETHIF_E_INV_PARAM;   
    }
    else
    {
        /* TX Confirmation function to UL */
        if(NULL_PTR != pEthIfConfig->pEthIfULTxConfirmationFuncArr)
        {
            for (OwnerIdx=0; OwnerIdx < pEthIfConfig->EthIfOwnersCount; OwnerIdx++) 
            {
                if (BufIdx == EthIf_BufferIdToFrameMap[OwnerIdx].BufferIdx )
                {
                    TxHandle = pEthIfConfig->pEthIfOwnerCfg[OwnerIdx].EthIfTxConfirmationHandle;

                    if ((ETHIF_INVALID_HANDLE != TxHandle) &&
                        (NULL_PTR != pEthIfConfig->pEthIfULTxConfirmationFuncArr[TxHandle]))
                    {
                        pEthIfConfig->pEthIfULTxConfirmationFuncArr[TxHandle]( CtrlIdx, BufIdx );
                    }
                    break;
                }
            }
        }
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_TXCONFIRMATION_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}

/********************************************************************************************************************
*   @brief      Called asynchronously when mode has been read out. Triggered by previous Eth_SetControllerMode call. 
*               Can directly be called within the trigger functions
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  CtrlMode Notified Ethernet controller mode
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_CtrlModeIndication( uint8 CtrlIdx, Eth_ModeType CtrlMode ) 
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else
    {
        EthSM_CtrlModeIndication(pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfCtrlId, CtrlMode);
    }  
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_CTRLMODEINDICATION_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}
/*!******************************************************************************************************************
*   @brief      Called asynchronously when a mode change has been read out. If the function is triggered by previous 
*               call of EthTrcv_SetTransceiverMode it can directly be called within the trigger function.
*   @param[in]  TrcvIdx Index of the Ethernet transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvMode Notified Ethernet transceiver mode
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same TrcvIdx, reentrant for different
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_TrcvModeIndication( uint8 TrcvIdx, EthTrcv_ModeType TrcvMode )
{
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfTrcvCount <= TrcvIdx)
    {
        ErrorId = ETHIF_E_INV_TRCV_IDX;   
    }
    else
    {
        EthSM_TrcvModeIndication(pEthIfConfig->pEthIfCtrlCfg[TrcvIdx].EthIfEthTrcvId, TrcvMode);
    }  
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_CTRLMODEINDICATION_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif
}
/*!******************************************************************************************************************
*   @brief      Handles a received frame received by the indexed controller
*   @param[in]  CtrlIdx Index of the physical Ethernet controller within the context of the Ethernet Interface
*   @param[in]  FrameType Frame type of received Ethernet frame
*   @param[in]  IsBroadcast parameter to indicate a broadcast frame
*   @param[in]  PhysAddrPtr Pointer to Physical source address (MAC address in network byte order) of received Ethernet 
*               frame
*   @param[in]  DataPtr Pointer to payload of received Ethernet frame.
*   @param[in]  LenByte Length (bytes) of the payload in received frame
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(void, ETHIF_CODE) EthIf_RxIndication
( 
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr,
    P2VAR(Eth_DataType,AUTOMATIC,ETHIF_APPL_DATA) DataPtr,
    uint16 LenByte
)
{
    uint8 OwnerIdx;
    uint8 RxHandle;
    boolean RxStatus = TRUE;    
    uint16 DestLenByte = 0u;
    uint16 VlanCtrlInfo = 0u;
    Eth_FrameType DestFrameType = 0u;
    Eth_DataType* DestDataPtr = NULL_PTR;
    uint8 ErrorId = ETHIF_E_NO_ERROR;

    if (ETHIF_STATE_INIT != EthIf_InitStatus)
    {
        ErrorId = ETHIF_E_UNINIT;
    }
    else if (pEthIfConfig->EthIfCtrlCount <= CtrlIdx)
    {
        ErrorId = ETHIF_E_INV_CTRL_IDX;   
    }
    else if (NULL_PTR == DataPtr)
    {
        ErrorId = ETHIF_E_PARAM_POINTER;   
    }
    else
    {
        if(INVALID_VLAN_ID == pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId)
        {
            DestFrameType = FrameType;
            DestDataPtr   = DataPtr;
            DestLenByte   = LenByte;
        }
        else 
        {
            if(FrameType == ETH_FRAME_TYPE_VLAN)
            {
                VlanCtrlInfo |= (uint16) DataPtr[0] << ETHIF_SHIFT_BYTE1;
                VlanCtrlInfo |= (uint16) DataPtr[1];
                
                if((VlanCtrlInfo & ETHIF_VID_MASK) != pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId )
                {
                    RxStatus = FALSE;
                } 
                else 
                {
                    DestFrameType = 0u;
                    DestDataPtr   = &DataPtr[VLAN_TAG_SIZE];
                    DestLenByte   = LenByte-VLAN_TAG_SIZE;
                    DestFrameType |=  (Eth_FrameType) DataPtr[2] << ETHIF_SHIFT_BYTE1; 
                    DestFrameType |=  (Eth_FrameType) DataPtr[3];
                }
            }
            else
            {
                RxStatus = FALSE;
            }
        } /* (INVALID_VLAN_ID == pEthIfConfig->pEthIfCtrlCfg[CtrlIdx].EthIfVlanId) */
        if (RxStatus == TRUE) 
        {
            for(OwnerIdx =0 ; OwnerIdx <  pEthIfConfig->EthIfOwnersCount; OwnerIdx ++)
            {
               if(DestFrameType == pEthIfConfig->pEthIfOwnerCfg[OwnerIdx].EthIfFrameType)
               {
                   RxHandle = pEthIfConfig->pEthIfOwnerCfg[OwnerIdx].EthIfRxIndicationHandle;
                   if(( RxHandle != ETHIF_INVALID_HANDLE) && 
                      (NULL_PTR != pEthIfConfig->pEthIfULRxIndicationFuncArr[RxHandle]))
                   {
                       pEthIfConfig->pEthIfULRxIndicationFuncArr[RxHandle](CtrlIdx, DestFrameType, IsBroadcast, 
                                                                    PhysAddrPtr, (uint8*)DestDataPtr, DestLenByte);
                   }
               }
            }
        } /* (RxStatus == TRUE) */
    }
    
#if (ETHIF_DEV_ERROR_DETECT == STD_ON)
    if (ETHIF_E_NO_ERROR != ErrorId)
    {
        EthIf_DetReportError(ETHIF_RXINDICATION_API, ErrorId);
    }
#else
    ETHIF_DUMMY_STATEMENT(ErrorId);
#endif

}

#define ETHIF_STOP_SEC_CODE
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
