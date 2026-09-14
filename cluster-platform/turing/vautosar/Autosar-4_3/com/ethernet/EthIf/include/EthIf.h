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
*   @file EthIf.h
*   @ingroup EthIf
*   @brief This file provides the declaration of the EthIf API. This header file should be included by other
*   modules that use the EthIf API.
*   @defgroup EthIf
*   @brief The main task of the Ethernet Interface: Provide to upper layers a hardware independent interface to the 
*   Ethernet Communication System comprising multiple different wired or wireless Ethernet controllers and 
*   transceivers. This interface shall be uniform for all Ethernet controllers and transceivers. Thus, the upper 
*   layers (TCP/IP, EthSM, CDD, V2x modules) may access the underlying bus system in a uniform manner.
********************************************************************************************************************/
#ifndef ETHIF_H
#define ETHIF_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "Eth_GeneralTypes.h" 
#include "EcuM_Types.h"
#include "EthSM.h"
#include "EthSM_Cbk.h"
#include "EthIf_Types.h"
#include "EthIf_Cfg.h"
/********************************************************************************************************************
*  PUBLIC MACRO DEFINITIONS                                                                                         *
********************************************************************************************************************/
/* Software Version */
/*! @brief Defines the EthIf SW major version */
#define ETHIF_SW_MAJOR_VERSION                              1u
/*! @brief Defines the EthIf SW minor version */
#define ETHIF_SW_MINOR_VERSION                              0u
/*! @brief Defines the EthIf SW patch version */
#define ETHIF_SW_PATCH_VERSION                              0u
/* Autosar Release */
/*! @brief Defines the EthIf AUTOSAR major version */
#define ETHIF_AR_RELEASE_MAJOR_VERSION                      4u
/*! @brief Defines the EthIf AUTOSAR minor version */
#define ETHIF_AR_RELEASE_MINOR_VERSION                      3u
/*! @brief Defines the EthIf AUTOSAR patch version */
#define ETHIF_AR_RELEASE_REVISION_VERSION                   1u
/********************************************************************************************************************
*  MODULE INFORMATION                                                                                               *
********************************************************************************************************************/                      
/*! @brief Defines the Vendor Id of EthIf module. */
#define ETHIF_VENDOR_ID                                     0x0033u
/*! @brief Defines the Module Id of EthIf module.*/
#define ETHIF_MODULE_ID                                     65u
/*! @brief Defines the version Id of EthIf module.*/
#define ETHIF_INSTANCE_ID                                   0u
/********************************************************************************************************************
*  API Id                                                                                                           *
********************************************************************************************************************/
/*! @brief Defines the service Id for EthIf_Init function */
#define ETHIF_INIT_API						0x01u
/*! @brief Defines the service Id for EthIf_SetControllerMode function */
#define ETHIF_SETCTRLMODE_API   			0x03u
/*! @brief Defines the service Id for EthIf_GetControllerMode function */
#define ETHIF_GETCTRLMODE_API		        0x04u
/*! @brief Defines the service Id for EthIf_SetTransceiverMode function */
#define ETHIF_SETTRCVMODE_API			    0x06u
/*! @brief Defines the service Id for EthIf_GetTransceiverMode function */
#define ETHIF_GETTRCVMODE_API				0x07u
/*! @brief Defines the service Id for EthIf_SetTransceiverWakeupMode function */
#define ETHIF_SETTRCVWAKEUPMODE_API		    0x2Eu
/*! @brief Defines the service Id for EthIf_GetTransceiverWakeupMode function */
#define ETHIF_GETTRCVWAKEUPMODE_API		    0x2Fu
/*! @brief Defines the service Id for EthIf_CheckWakeup function */
#define ETHIF_CHECKWAKEUP_API               0x30u
/*! @brief Defines the service Id for EthIf_GetPhysAddr function */
#define ETHIF_GETPHYADDR_API                0x08u
/*! @brief Defines the service Id for EthIf_SetPhysAddr function */
#define ETHIF_SETPHYADDR_API                0x0Du
/*! @brief Defines the service Id for EthIf_UpdatePhysAddrFilter function */
#define ETHIF_UPDATEPHYADDRFILTER_API       0x0Cu
/*! @brief Defines the service Id for EthIf_GetPortMacAddr function */
#define ETHIF_GETPORTMACADDR_API            0x28u
/*! @brief Defines the service Id for EthIf_GetArlTable function */
#define ETHIF_GETARLTABEL_API               0x29u
/*! @brief Defines the service Id for EthIf_GetBufferLevel function */
#define ETHIF_GETBUFLEVEL_API               0x2Au
/*! @brief Defines the service Id for EthIf_GetDropCount function */
#define ETHIF_GETDROPCOUNT_API              0x2Bu
/*! @brief Defines the service Id for EthIf_StoreConfiguration function */
#define ETHIF_STORECONFIG_API               0x2Cu
/*! @brief Defines the service Id for EthIf_ResetConfiguration function */
#define ETHIF_RESETCONFIG_API               0x2Du
/*! @brief Defines the service Id for EthIf_GetCurrentTime function */
#define ETHIF_GETCURRENTTIME_API            0x22u
/*! @brief Defines the service Id for EthIf_EnableEgressTimeStamp function */
#define ETHIF_ENABLEEGRESSTIMESTAMP_API     0x23u
/*! @brief Defines the service Id for EthIf_GetEgressTimeStamp function */
#define ETHIF_GETEGRESSTIMESTAMP_API        0x24u
/*! @brief Defines the service Id for EthIf_GetIngressTimeStamp function */
#define ETHIF_GETINGRESSTIMESTAMP_API       0x25u
/*! @brief Defines the service Id for EthIf_SetCorrectionTime function */
#define ETHIF_SETCORRECTIONTIME_API         0x26u
/*! @brief Defines the service Id for EthIf_SetGlobalTime function */
#define ETHIF_SETGLOBALTIME_API             0x27u
/*! @brief Defines the service Id for EthIf_ProvideTxBuffer function */
#define ETHIF_PROVIDETXBUFFER_API           0x09u
/*! @brief Defines the service Id for EthIf_Transmit function */
#define ETHIF_TRANSMIT_API                  0x0Au
/*! @brief Defines the service Id for EthIf_GetVersionInfo function */
#define ETHIF_GETVERSIONINFO_API            0x0Bu 
/*! @brief Defines the service Id for EthIf_RxIndication function */
#define ETHIF_RXINDICATION_API              0x10u
/*! @brief Defines the service Id for EthIf_TxConfirmation function */
#define ETHIF_TXCONFIRMATION_API            0x11u
/*! @brief Defines the service Id for EthIf_CtrlModeIndication function */
#define ETHIF_CTRLMODEINDICATION_API        0x0Eu
/*! @brief Defines the service Id for EthIf_TrcvModeIndication function */
#define ETHIF_TRCVMODEINDICATION_API        0x0Fu
/*! @brief Defines the service Id for EthIf_MainFunctionRx function */
#define ETHIF_MAINFUNCTIONRX_API            0x20u
/*! @brief Defines the service Id for EthIf_MainFunctionTx function */
#define ETHIF_MAINFUNCTIONTX_API            0x21u      
/*! @brief Defines the service Id for EthIf_GetCtrlIdxList function */
#define ETHIF_GETCTRLIDXLIST_API            0x44u              
/*! @brief Defines the service Id for EthIf_GetVlanId function */
#define ETHIF_GETVLANID_API                 0x43u              
/*! @brief Defines the service Id for EthIf_GetAndResetMeasurementData function */
#define ETHIF_GETANDRESETMEASUREMENTDATA_API 0x45u              
/********************************************************************************************************************
*  DEVELOPMENT ERRORS VALUES                                                                                        *
********************************************************************************************************************/
/*! @brief API service called with Invalid controller index */
#define ETHIF_E_INV_CTRL_IDX		 		0x01u
/*! @brief API service called with Invalid transceiver index */
#define ETHIF_E_INV_TRCV_IDX	      		0x02u
/*! @brief API service called with Invalid switch index */
#define ETHIF_E_INV_SWT_IDX 		        0x03u
/*! @brief API service called with Invalid port group index */
#define ETHIF_E_INV_PORT_GROUP_IDX 		    0x04u
/*! @brief API service called with EthIf module was not initialized */
#define ETHIF_E_UNINIT		      	        0x05u
/*! @brief API service called with Invalid pointer in parameter list */
#define ETHIF_E_PARAM_POINTER    			0x06u
/*! @brief API service called with Invalid parameter */
#define ETHIF_E_INV_PARAM  				    0x07u
/*! @brief API service called with Initialization failure */
#define ETHIF_E_INIT_FAILED  				0x08u
/*! @brief Defines No error id  */
#define ETHIF_E_NO_ERROR                    0xFFu
/********************************************************************************************************************
*  PUBLIC FUNCTION PROTOTYPES                                                                                       *
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
extern FUNC(void, ETHIF_CODE) EthIf_Init( P2CONST(EthIf_ConfigType,AUTOMATIC,ETHIF_APPL_CONST) CfgPtr );
/*!******************************************************************************************************************
*   @brief      Enables / disables the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[in]  CfgPtr  ETH_MODE_DOWN: disable the controller ETH_MODE_ACTIVE: enable the controller
*   @return     E_OK: success E_NOT_OK: controller mode could not be changed
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetControllerMode( uint8 CtrlIdx, Eth_ModeType CtrlMode );
/*!******************************************************************************************************************
*   @brief      Obtains the state of the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] CtrlModePtr  pointer to the get the controller mode
*               ETH_MODE_DOWN: the controller is disabled ETH_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: controller could not be initialized
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetControllerMode
( 
    uint8 CtrlIdx, 
    P2VAR(Eth_ModeType,AUTOMATIC,ETHIF_APPL_VAR) CtrlModePtr 
);
/*!******************************************************************************************************************
*   @brief      Enables / disables the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvMode  ETHTRCV_MODE_DOWN: the controller is disabled ETHTRCV_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: transceiver mode could not be changed
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverMode( uint8 TrcvIdx, EthTrcv_ModeType TrcvMode );
/*!******************************************************************************************************************
*   @brief      Obtains the state of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[out]  TrcvModePtr  pointer to the get the controller mode
*               ETHTRCV_MODE_DOWN: the controller is disabled ETHTRCV_MODE_ACTIVE: the controller is enabled
*   @return     E_OK: success E_NOT_OK: transceiver could not be initialized
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverMode
( 
    uint8 TrcvIdx,
    P2VAR(EthTrcv_ModeType,AUTOMATIC,ETHIF_APPL_VAR) TrcvModePtr 
);
/*!******************************************************************************************************************
*   @brief      Enables / disables the wake up mode or clear the wake-up reason of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[in]  TrcvWakeupMode  ETHTRCV_WUM_DISABLE: disable transceiver wake up 
*               ETHTRCV_WUM_ENABLE: enable transceiver wake up ETHTRCV_WUM_CLEAR: clears transceiver wake up reason
*   @return     E_OK: success E_NOT_OK: transceiver wake up could not be changed or wake-up reason could not be cleared
*   @ServiceID  0x2e
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetTransceiverWakeupMode
( 
    uint8 TrcvIdx, 
    EthTrcv_WakeupModeType TrcvWakeupMode 
);
/*!******************************************************************************************************************
*   @brief      Returns the wake up mode of the indexed transceiver
*   @param[in]  TrcvIdx Index of the transceiver within the context of the Ethernet Interface
*   @param[out] TrcvWakeupModePtr  pointer to get the wakeup mode
*               ETHTRCV_WUM_DISABLE: transceiver wake up is disabled ETHTRCV_WUM_ENABLE: transceiver wake up is enabled
*   @return     E_OK: success E_NOT_OK: transceiver wake up mode could not be obtained
*   @ServiceID  0x2f
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetTransceiverWakeupMode
(
    uint8 TrcvIdx,
    P2VAR(EthTrcv_WakeupModeType,AUTOMATIC,ETHIF_APPL_VAR) TrcvWakeupModePtr 
);
/*!******************************************************************************************************************
*   @brief      Service is called by integration code to check a wakeup source.
*   @param[in]  WakeupSource source (transceiver) which initiated the wake up event
*   @return     E_OK when function has been successfully executed
*               E_NOT_OK when function could not be successfully executed
*   @ServiceID  0x30
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant.
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_CheckWakeup( EcuM_WakeupSourceType WakeupSource );
/*!******************************************************************************************************************
*   @brief      Obtains the physical source address used by the indexed controller
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] PhysAddrPtr Physical source address (MAC address) in network byte order
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_GetPhysAddr
( 
    uint8 CtrlIdx,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) PhysAddrPtr 
);
/*!******************************************************************************************************************
*   @brief      Sets the physical source address used by the indexed controller.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Driver.
*   @param[out] PhysAddrPtr Pointer to memory containing the physical source address (MAC address) in network byte 
*               order.
*   @ServiceID  0x0d
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same CtrlIdx, reentrant for different
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_SetPhysAddr
( 
    uint8 CtrlIdx,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr 
);
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_UpdatePhysAddrFilter
( 
    uint8 CtrlIdx,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr,
    Eth_FilterActionType Action
);
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetPortMacAddr
( 
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) MacAddrPtr,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) SwitchIdxPtr,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) PortIdxPtr 
);
#if (ETHIF_SWITCH_SUPPORT == STD_ON)
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetArlTable
( 
    uint8 SwitchIdx,
    P2VAR(EthSwt_MacVlanType,AUTOMATIC,ETHIF_APPL_VAR) ArlTable 
);
#endif
/*!******************************************************************************************************************
*   @brief      Reads the buffer level of the corresponding switch. Whether this buffer level is one value for the 
*               entire switch (shared memory) or one value for each port at a switch is technology dependent.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @param[out] SwitchBufferLevelPtr The interpretation of this value is switch dependent 
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized
*   @ServiceID  0x2a
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetBufferLevel
( 
    uint8 SwitchIdx, 
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) SwitchBufferLevelPtr 
);
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCtrlIdxList
( 
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) NumberOfCtrlIdx,
    P2VAR(uint8,AUTOMATIC,ETHIF_APPL_VAR) CtrlIdxListPtr 
);
/*!******************************************************************************************************************
*   @brief      Returns the VLAN identifier of the requested Ethernet controller.
*   @param[in]  CtrlIdx Index of the Ethernet controller within the context of the Ethernet Interface
*   @param[out] VlanIdPtr Pointer to store the VLAN identifier (VID) of the Ethernet controller. 0 if the the Ethernet 
*               controller represents no virtual network (VLAN).
*   @retrun     E_OK: success E_NOT_OK: failure
*   @ServiceID  0x43
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetVlanId
( 
    uint8 CtrlIdx, 
    P2VAR(uint16,AUTOMATIC,ETHIF_APPL_VAR) VlanIdPtr 
);
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetAndResetMeasurementData
( 
    EthIf_MeasurementIdxType MeasurementIdx,
    boolean MeasurementResetNeeded,
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) MeasurementDataPtr 
);
#if (ETHIF_AR_RELEASE_MAJOR_VERSION == 4u) && (ETHIF_AR_RELEASE_MINOR_VERSION == 2U) 
/*!******************************************************************************************************************
*   @brief      To get the drop count for the ethernet frames.  # 4.2
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @param[out] DropCount Reference to data buffer, where to copy dropcount data
*   @retrun     E_OK: success E_NOT_OK: failure
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetDropCount
( 
    uint8 SwitchIdx,
    P2VAR(uint32,AUTOMATIC,ETHIF_APPL_VAR) DropCount
);
#endif
/*!******************************************************************************************************************
*   @brief      Stores the configuration of the learned MAC/Port tables of a switch in a persistent manner and will
*               be used by e.g. CDD.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized or unknown index
*   @ServiceID  0x2c
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_StoreConfiguration( uint8 SwitchIdx );
/*!******************************************************************************************************************
*   @brief      Resets the configuration of the learned MAC/Port tables of a switch in a persistent manner and will 
*               be used by e.g. CDD. The statically configured entries shall still remain.
*   @param[in]  SwitchIdx Index of the switch within the context of the Ethernet Switch Driver
*   @retrun     E_OK: success E_NOT_OK: switch port could not be initialized or unknown index
*   @ServiceID  0x2d
*   @Sync/Async Synchronous /Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_ResetConfiguration( uint8 SwitchIdx );
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_GetCurrentTime
( 
    uint8 CtrlIdx,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
);
/*!******************************************************************************************************************
*   @brief      Activates egress time stamping on a dedicated message object. Some HW does store once the egress time
*               stamp marker and some HW needs it always before transmission. There will be no "disable" functionality,
*               due to the fact, that the message type is always "time stamped" by network design.
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[out] BufIdx Index of the message buffer, where Application expects egress time stamping
*   @ServiceID  0x23
*   @Sync/Async Synchronous 
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_EnableEgressTimeStamp( uint8 CtrlIdx, Eth_BufIdxType BufIdx );
/*!******************************************************************************************************************
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
extern FUNC(void, ETHIF_CODE) EthIf_GetEgressTimeStamp
(
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
);
/*!******************************************************************************************************************
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
extern FUNC(void, ETHIF_CODE) EthIf_GetIngressTimeStamp
( 
    uint8 CtrlIdx,
    P2VAR(Eth_DataType,AUTOMATIC,ETHIF_APPL_VAR) DataPtr,
    P2VAR(Eth_TimeStampQualType,AUTOMATIC,ETHIF_APPL_VAR) timeQualPtr,
    P2VAR(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_VAR) timeStampPtr 
);
#if (ETHIF_AR_RELEASE_MAJOR_VERSION == 4u) && (ETHIF_AR_RELEASE_MINOR_VERSION == 2U) 
/*!******************************************************************************************************************
*   @brief      Allows the Time Slave to adjust the local ETH Reference clock in HW. # 4.2
*   @param[in]  CtrlIdx Index of the addresses ETH controller.
*   @param[in]  timeOffsetPtr offset between time stamp grandmaster and time stamp by local clock: 
*               (OriginTimeStampSync[FUP] – IngressTimeStampSync) + Pdelay
*   @param[in]  time elements to calculate and to modify the ratio of the frequency of the grandmaster in relation to 
*               the frequency of the Local Clock with: ratio = OriginTimeStampDelta / IngressTimeStampDelta
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_SetCorrectionTime
( 
    uint8 CtrlIdx,
    P2CONST(Eth_TimeIntDiffType,AUTOMATIC,ETHIF_APPL_CONST) timeOffsetPtr,
    P2CONST(Eth_RateRatioType,AUTOMATIC,ETHIF_APPL_CONST) rateRatioPtr 
);
/*!******************************************************************************************************************
*   @brief      Allows the Time Master to adjust the global ETH Reference clock in HW. We can use this method to set a
*               global time base on ETH in general or to synchronize the global ETH time base with another time base
*               # 4.2
*   @param[in]  CtrlIdx Index of the addresses ETH controller. 
*   @param[in]  timeStampPtr new time stamp
*   @param[in]  time elements to calculate and to modify the ratio of the frequency of the grandmaster in relation to 
*               the frequency of the Local Clock with: ratio = OriginTimeStampDelta / IngressTimeStampDelta
*   @return     E_OK: successful E_NOT_OK: failed
********************************************************************************************************************/
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_SetGlobalTime
( 
    uint8 CtrlIdx,
    P2CONST(Eth_TimeStampType,AUTOMATIC,ETHIF_APPL_CONST) timeStampPtr 
);
#endif
/*!******************************************************************************************************************
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
extern FUNC(BufReq_ReturnType, ETHIF_CODE) EthIf_ProvideTxBuffer
( 
    uint8 CtrlIdx,
    Eth_FrameType FrameType,
    uint8 Priority,
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETHIF_APPL_VAR) BufIdxPtr,
    P2VAR(P2VAR(uint8, AUTOMATIC, ETHIF_APPL_VAR), AUTOMATIC, ETHIF_APPL_VAR) BufPtr,
    P2VAR(uint16, AUTOMATIC, ETHIF_APPL_VAR) LenBytePtr
);
/*!******************************************************************************************************************
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
extern FUNC(Std_ReturnType, ETHIF_CODE) EthIf_Transmit
( 
    uint8 CtrlIdx,
    Eth_BufIdxType BufIdx,
    Eth_FrameType FrameType,
    boolean TxConfirmation,
    uint16 LenByte,
    P2CONST(uint8,AUTOMATIC,ETHIF_APPL_CONST) PhysAddrPtr 
);

#if (ETHIF_VERSION_INFO_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      Returns the version information of this module
*   @param[out] VersionInfoPtr Version information of this module
*   @ServiceID  0x0b
*   @Sync/Async Synchronous 
*   @Reentrancy Reentrant
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ETHIF_APPL_VAR) VersionInfoPtr);
#endif
/*!******************************************************************************************************************
*   @brief      The function checks for new received frames and issues transmission confirmations in polling mode. 
*               It checks also for transceiver state changes.
*   @ServiceID  0x20
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_MainFunctionRx( void );
/*!******************************************************************************************************************
*   @brief      The function issues transmission confirmations in polling mode. It checks also for transceiver state
*               changes.
*   @ServiceID  0x21
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_MainFunctionTx( void );
/*!******************************************************************************************************************
*   @brief      The function is polling different communication hardware (Ethernet transceiver, 
*               Ethernet switch ports) related information, e.g. link state, signal quality
*   @ServiceID  0x21
********************************************************************************************************************/
extern FUNC(void, ETHIF_CODE) EthIf_MainFunctionState( void );

#define ETHIF_STOP_SEC_CODE
#include "MemMap.h"

#endif /* ETHIF_H */
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

