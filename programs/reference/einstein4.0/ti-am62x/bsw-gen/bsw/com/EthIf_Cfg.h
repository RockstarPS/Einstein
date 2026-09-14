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
*    @file EthIf_Cfg.h
*    @ingroup EthIfConfiguration
*    @brief This is EthIf Pre-compile time configuration header file. It contains definitions of pre-compile time 
*    configuration parameters for the EthIf module.
*    @defgroup EthIfConfiguration
*    @brief This contains the configuration files for the EthIf module.
********************************************************************************************************************/
#ifndef ETHIF_CFG_H
#define ETHIF_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "ComStack_Types.h"
#include "EthIf_Types.h"
#include "EthTrcv_Types.h"

/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief  Switches the development error detection and notification on or off.
    true: detection and notification is enabled.
    false: detection and notification is disabled. */
#define ETHIF_DEV_ERROR_DETECT                  STD_ON
/*! @brief Enables / Disables receive interrupt.*/
#define ETHIF_ENABLE_RX_INTERRUPT               STD_ON
/*! @brief Enables / Disables the transmit interrupt. */
#define ETHIF_ENABLE_TX_INTERRUPT               STD_ON
/*! @brief Enables / Disables GetBaudRate API. */
#define ETHIF_GET_BAUDRATE                      STD_ON
/*! @brief Enables / Disables GetCounterState API. */
#define ETHIF_GET_COUNTER_STATE                 STD_ON
/*! @brief Enables / Disables EthIf_GetTransceiverWakeupMode API */
#define ETHIF_GET_TRANSCEIVER_WAKEUP_MODE_API   STD_ON
/*! @brief Enables/Disables the Global Time APIs used amongst others by Global Time Synchronization over Ethernet */
#define ETHIF_GLOBAL_TIME_SUPPORT               STD_ON
/*! @brief Enables / Disables StartAutoNegotiation API. */
#define ETHIF_START_AUTO_NEGOTIATION            STD_ON     
/*! @brief Enables / Disables version info API */
#define ETHIF_VERSION_INFO_API                  STD_ON
/*! @brief Enables / Disables version info API macro implementation. */
#define ETHIF_VERSION_INFO_API_MACRO            STD_OFF
/*! @brief Configures if wakeup is supported or not. */
#define ETHIF_WAKEUP_SUPPORT                    STD_ON
/*! @brief Specifies the period of main function EthIf_MainFunctionRx and EthIf_MainFunctionTx in milliseconds. Ethernet 
    Interface does not require this information but the BSW scheduler. */
#define ETHIF_MAIN_FUNCTION_PERIOD              10U
/*! @brief Limits the total number of transceivers. 1 .. 255 */
#define ETHIF_MAX_TRCVS_TOTAL                   1U
/*! @brief Maximum number of Ethernet frames per Ethernet controller polled from the Ethernet driver within 
    EthIf_MainFunctionRx. 0 .. 65535 */
#define ETHIF_RX_INDICATION_ITERATIONS          1U
/*! @brief Specifies the frequency of transceiver link state change checks in each period of main function 
    EthIf_MainFunctionTx. 1 .. 255 */
#define ETHIF_TRCV_LINK_STATE_CHG_MAIN_RELOAD   10U
/********************************************************************************************************************
*  #! EthIf Internal feature support                                                                                *
********************************************************************************************************************/
/*! @brief Defines the dummy macro */
#ifndef ETHIF_DUMMY_STATEMENT
#define ETHIF_DUMMY_STATEMENT(v)
#endif
/*******************************************************************************************************************
*  #! EthIf module configuration                                                                                   *
*******************************************************************************************************************/
/* !@brief Defines the number of Eth controllers supported */
#define ETHIF_NUM_OF_CONTROLLERS    1U
/* !@brief Defines the number of Eth transceiver supported */
#define ETHIF_NUM_OF_TRANSCEIVERS   ETHIF_MAX_TRCVS_TOTAL
/* !@brief Defines the number of Eth switch supported */
#define ETHIF_NUM_OF_SWITCHES       1u
/* !@brief Defines the number of Eth frame owners supported */
#define ETHIF_NUM_OF_FRAME_OWNERS   2U
/* !@brief Enables/Disables the support of Eth switches */
#define ETHIF_SWITCH_SUPPORT        STD_OFF
/* !@brief Enables/Disables the support of Eth Trcv */
#define ETHIF_TRCV_SUPPORT          STD_ON
/* !@brief Enables/Disables the support of Eth drv physicall address filter Eth_UpdatePhysAddrFilter api  */
#define ETHIF_ETHDRV_PHYS_ADRS_FILTER_API STD_ON
/* !@brief Defines the EthIf invalid handle */
#define ETHIF_INVALID_HANDLE   255u     
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the EthIf configuration software Major version */
#define ETHIF_CFG_SW_MAJOR_VERSION                      1u
/*! @brief Defines the EthIf configuration software Minor version */
#define ETHIF_CFG_SW_MINOR_VERSION                      0u
/*! @brief Defines the EthIf configuration software Patch version */
#define ETHIF_CFG_SW_PATCH_VERSION                      0u
/* Autosar Release */
/*! @brief Defines the AUTOSAR Release Major version supported by ComM configuration  */
#define ETHIF_CFG_AR_RELEASE_MAJOR_VERSION              4u
/*! @brief Defines the AUTOSAR Release Minor version supported by ComM configuration  */
#define ETHIF_CFG_AR_RELEASE_MINOR_VERSION              3u
/*! @brief Defines the AUTOSAR Release patch version supported by ComM configuration  */
#define ETHIF_CFG_AR_RELEASE_REVISION_VERSION           1u

/********************************************************************************************************************
* #! EthIf types                                                                                                    *
* #! macro , typedef declaration                                                                                    *
********************************************************************************************************************/
/*! @brief Defines the configuration type of Etherner interface controller state  */
typedef struct 
{
    uint8     EthIfCtrlId;         /*! @brief Index of the Ethernet controller within the context of the EthIf */
    uint8     EthIfMaxTxBufsTotal; /*! @brief total number of transmit buffers. */
    uint8     EthIfEthCtrlId;      /*! @brief Index of Eth controller within the context of the Ethernet Driver */
    uint8     EthIfEthTrcvId;      /*! @brief Index of Eth Trcv */
    uint16    EthIfCtrlMtu;        /*! @brief maximum Payload size */
    uint16    EthIfVlanId;         /*! @brief 12 bit VLAN ID */
}EthIf_ControllerType;

/*! @brief Defines the function type for User defined Tx Confirmation callback */
typedef P2FUNC(void,ETHIF_APPL_CODE,EthIf_ULTxConfirmationFuncType)( uint8 CtrlIdx, Eth_BufIdxType BufIdx );

/*! @brief  Defines the function type for User defined Rx Indication callback */
typedef P2FUNC(void,ETHIF_APPL_CODE,EthIf_ULRxIndicationFuncType)
( 
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    boolean IsBroadcast,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_DATA) DataPtr,
    uint16 LenByte
);

/*! @brief  Defines the function type for User defined TrcvLinkState callback */
typedef P2FUNC(void,ETHIF_APPL_CODE,EthIf_TrcvLinkStateChgFuncType)(uint8 CtrlIdx, EthTrcv_LinkStateType TrcvLinkState);

/*! @brief Defines the type for the frame owner */
typedef struct 
{
    uint32  EthIfFrameType;              /*! @brief  Frame Type ex: ARP, iV4 */
    uint8   EthIfRxIndicationHandle;      /*! @brief  RxIndication handle */
    uint8   EthIfTxConfirmationHandle;    /*! @brief  TxConfirmation handle */
}EthIf_FrameOwnerType;

/*! @brief Defines the configuration type for the Ethernet switch */
typedef struct 
{
    uint8   EthIfEthSwitchId; /*! @brief  Index of Switches in context of Eth Interface*/
    uint8   EthIfSwitchIdx;   /*! @brief  Index of Switches in context of Eth Switch module*/
}EthIf_SwitchType;

/*! @brief Defines the  EthIf configuration type */
typedef struct 
{
    /*! @brief  pointer to hold controller config data*/
    const EthIf_ControllerType *            pEthIfCtrlCfg;   
    /*! @brief  pointer to hold Owner config data */
    const EthIf_FrameOwnerType *            pEthIfOwnerCfg;  
    /*! @brief  pointer to hold switches config data */
    const EthIf_SwitchType *                pEthIfSwitchCfg; 
    /*! @brief  pointer to hold Tx confirmation functions list */
    const EthIf_ULTxConfirmationFuncType*   pEthIfULTxConfirmationFuncArr;
    /*! @brief  pointer to Rx indication function list */    
    const EthIf_ULRxIndicationFuncType *    pEthIfULRxIndicationFuncArr;
    /*! @brief pointer to hold Trcv Link state functions list */    
    const EthIf_TrcvLinkStateChgFuncType*   pEthIfTrcvLinkStateChgFuncArr;
    /*! @brief  Num of Controllers configure */
    uint8                                   EthIfCtrlCount;   
    /*! @brief  Num of Trcv configured */
    uint8                                   EthIfTrcvCount;     
    /*! @brief  Num of Switches configured */
    uint8                                   EthIfSwitchCount; 
    /*! @brief  Num fo Owners configured */
    uint8                                   EthIfOwnersCount;   
}EthIf_ConfigType;

#endif /* ETHIF_CFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
