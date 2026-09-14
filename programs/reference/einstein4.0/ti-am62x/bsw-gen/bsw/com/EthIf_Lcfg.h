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
*    @file EthIf_Lcfg.h
*    @ingroup EthIfConfiguration
*    @brief This is EthIf link time configuration header file. It contains definitions of link time
*    configuration parameters for the EthIf module.
*    @defgroup EthIfConfiguration
*    @brief This contains the link time configurations for the EthIf module.
********************************************************************************************************************/
#ifndef ETHIF_LCFG_H
#define ETHIF_LCFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "EthIf_Cfg.h"
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* #! EthIf const config  data                                                                                       *
********************************************************************************************************************/
extern const EthIf_ControllerType EthIf_Controller[ETHIF_NUM_OF_CONTROLLERS];
extern const EthIf_FrameOwnerType EthIf_FrameOwner[ETHIF_NUM_OF_FRAME_OWNERS];
extern const EthIf_SwitchType EthIf_Switch[ETHIF_NUM_OF_SWITCHES];
extern const EthIf_ULTxConfirmationFuncType EthIf_ULTxConfirmationFuncArr[ETHIF_NUM_OF_FRAME_OWNERS];
extern const EthIf_ULRxIndicationFuncType EthIf_ULRxIndicationFuncArr[ETHIF_NUM_OF_FRAME_OWNERS];
extern const EthIf_TrcvLinkStateChgFuncType EthIf_TrcvLinkStateChgFuncArr[ETHIF_NUM_OF_FRAME_OWNERS];
extern const EthIf_ConfigType EthIf_Config;
#endif /* ETHIF_LCFG_H */

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/


