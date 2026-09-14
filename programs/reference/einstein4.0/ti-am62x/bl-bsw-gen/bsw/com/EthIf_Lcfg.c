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
*    @file EthIf_Lcfg.c
*    @ingroup EthIfConfiguration
*    @brief This is EthIf Link time configuration source file. It contains definitions of Link time configuration
*     parameters for the EthIf module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthIf.h"
#include "EthIf_Lcfg.h"
#include "TcpIp.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/

/********************************************************************************************************************
* #! EthIf const config  data                                                                                       *
********************************************************************************************************************/

/*! @brief Defines the Ethernet controller configuration 
    EthIfCtrlId         : Index of the Ethernet controller within the context of the EthIf
    EthIfMaxTxBufsTotal : Total number of transmit buffers. 
    EthIfEthCtrlId;     : Index of Eth controller within the context of the Ethernet Driver 
    EthIfEthTrcvId;     : Index of Eth Trcv 
    EthIfCtrlMtu;       : maximum Payload size
    EthIfVlanId;        : 12 bit VLAN ID 
*/
const EthIf_ControllerType EthIf_Controller[ETHIF_NUM_OF_CONTROLLERS]=
{
    { 0U, 128u, 0U, 0U, 1536u,4095u }
};

/* 
EthIfFrameType
    IPv4 : 0x0800
    ARP  : 0x0806
    AVTP : 0x22F0
    RARP : 0x8035
    VLAN : 0x8100
    IPv6 : 0x86DD
    PTP  : 0x88F7
*/
/*! @brief  Defines the Ethernet Frame configuration
    EthIfFrameType              : Frame Type ex: ARP, IPV4 
    EthIfRxIndicationHandle     : RxIndication handle 
    EthIfTxConfirmationHandle   : TxConfirmation handle 
*/
const EthIf_FrameOwnerType EthIf_FrameOwner[ETHIF_NUM_OF_FRAME_OWNERS]=
{
    { 0x0800, 0U , 0U }, /* Ipv4 */
    { 0x0806, 0U , 0U } /* Ipv4 Arp*/
};

/*! @brief  Defines the Ethernet switch configuration
    EthIfEthSwitchId    : Index of Switches in context of Eth Interface
    EthIfSwitchIdx      : Index of Switches in context of Eth Switch module
*/
const EthIf_SwitchType EthIf_Switch[ETHIF_NUM_OF_SWITCHES]=
{
    { 0u, 0u }
};

/*! @brief  Defines the Ethernet tx confirmation owner callback function
*/
const EthIf_ULTxConfirmationFuncType EthIf_ULTxConfirmationFuncArr[ETHIF_NUM_OF_FRAME_OWNERS]=
{
    NULL_PTR
};

/*! @brief  Defines the Ethernet rx indication owner callback function
*/
const EthIf_ULRxIndicationFuncType EthIf_ULRxIndicationFuncArr[ETHIF_NUM_OF_FRAME_OWNERS]=
{
    &TcpIp_RxIndication
};

/*! @brief  Defines the Ethernet trcv link state owner callback function
*/
const EthIf_TrcvLinkStateChgFuncType EthIf_TrcvLinkStateChgFuncArr[ETHIF_NUM_OF_FRAME_OWNERS]=
{
    NULL_PTR
};

/*! @brief  Defines the  EthIf configuration
pEthIfCtrlCfg               :   pointer to hold controller config data
pEthIfOwnerCfg              :   pointer to hold Owner config data
pEthIfSwitchCfg             :   pointer to hold switches config data
pEthIfULTxConfirmationFunc  :   pointer to hold Tx confirmation functions list
pEthIfULRxIndicationFunc    :   pointer to Rx indication function list
pEthIfTrcvLinkStateChgFunc  :   pointer to hold Trcv Link state functions list
EthIfCtrlCount              :   Num of Controllers configured
EthIfTrcvCount              :   Num of Trcv configured
EthIfSwitchCount            :   Num of Switches configured
EthIfOwnersCount            :   Num of Owners configured
*/
const EthIf_ConfigType EthIf_Config=
{
    &EthIf_Controller[0],
    &EthIf_FrameOwner[0],
    &EthIf_Switch[0],
    &EthIf_ULTxConfirmationFuncArr[0],
    &EthIf_ULRxIndicationFuncArr[0],
    &EthIf_TrcvLinkStateChgFuncArr[0],
    ETHIF_NUM_OF_CONTROLLERS,
    ETHIF_NUM_OF_TRANSCEIVERS,
    ETHIF_NUM_OF_SWITCHES,
    ETHIF_NUM_OF_FRAME_OWNERS
};
/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


