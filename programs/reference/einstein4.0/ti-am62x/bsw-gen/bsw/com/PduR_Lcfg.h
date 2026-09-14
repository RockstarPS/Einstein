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
*    @file PduR_Lcfg.h
*    @ingroup PduRConfiguration
*    @brief This is PduR link time configuration header file. It contains definitions of link time
*    configuration parameters for the PduR module.
*    @defgroup PduRConfiguration
*    @brief This contains the link time configurations for the PduR module.
********************************************************************************************************************/
#ifndef PDUR_LCFG_H
#define PDUR_LCFG_H
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/
#if (PDUR_ROUTING_PATH_GROUP == STD_ON)

#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief Defines the routing path group enable status  */
extern VAR(boolean,PDUR_VAR_NOINIT) PduR_RoutingPathGrpEnableSts[PDUR_NUM_OF_ROUTING_PATH_GROUP];

#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#endif
/********************************************************************************************************************
* #! PduR const config  data                                                                                        *
********************************************************************************************************************/
#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*! @brief Defines the Interface configuration of PDUR BSW modules 
    Elements                     :   Description
    LoIfTransmitFunctPtr         :   the function for the PduR Lower layer communication interface transmission.
    LoIfCancelTransmitFunctPtr   :   the function for the PduR Lower layer communication interface cancel transmission.
    LoTpCancelReceiveFunctPtr    :   the function for the PduR Lower layer transport protocol cancel receive.
    LoTpCancelTransmitFunctPtr   :   the function for the PduR Lower layer transport protocol cancel transmit.
    LoTpChangeParameterFunctPtr  :   the function for the PduR Lower layer transport protocol change Parameter.
    LoTpTransmitFunctPtr         :   the function for the PduR Lower layer transport protocol transmit.
    UpIfRxIndicationFunctPtr     :   the function for the PduR upper layer communication interface reception 
    UpIfTriggerTransmitFunctPtr  :   the function for the PduR upper layer communication interface trigger transmit 
    UpIfTxConfirmationFunctPtr   :   the function for the PduR upper layer communication interface transmit confirmation
    UpTpCopyRxDataFunctPtr       :   the function for the PduR upper layer transport protocol receive data copy 
    UpTpCopyTxDataFunctPtr       :   the function for the PduR upper layer transport protocol transmit data copy 
    UpTpStartOfReceptionFunctPtr :   the function for the PduR upper layer transport protocol start of reception 
    UpTpRxIndicationFunctPtr     :   the function for the PduR upper layer transport protocol receive 
    UpTpTxConfirmationFunctPtr   :   the function for the PduR upper layer transport protocol transmit confirmation 
*/
extern CONST(PduR_ModuleConfigType,PDUR_CONFIG_DATA) PduR_ModuleConfig[PDUR_NUM_OF_MODULE_ID];
/*! @brief Defines the source Pdu configuration 
    Elements                :   Description
    TxConfirmationSupport   :   whether Tx confirmation support is requried.
    PduType                 :   the PduId type , IF or TP
    SrcModule               :   the source module Id
    DestStartPduId          :   the destination pdu start Id
    DestEndPduId            :   the destination pdu end Id
    ModuleSrcPduId          :   the source module pdu Id
    SrcPduToGroupIdMap      :   the routing path group Ids to which it belongs
*/
extern CONST(PduR_SourcePduCfgType,PDUR_CONFIG_DATA) PduR_SourcePduCfg[PDUR_NUM_OF_SRC_PDU];
/*! @brief Defines the destination Pdu configuration 
    Elements                :   Description
    DataProvisioning        :   the data provision type of the Pdu
    TxConfirmationSupport   :   whether Tx confirmation support is requried
    SrcPduId                :   the source pdu start Id
    ModuleDestPduId         :   the destination modult pdu Id
    PduDestDirection        :   the destination direction Tx or Rx
    DestPduToGroupIdMap     :   the routing path group Ids to which it belongs
*/
extern CONST(PduR_DestPduCfgType,PDUR_CONFIG_DATA) PduR_DestPduCfg[PDUR_NUM_OF_DEST_PDU];

#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
#define PDUR_START_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"
/*! @brief Defines the Routing path group Init status */
extern CONST(uint8,PDUR_CONFIG_DATA) PduR_RpGroupInitStatus[PDUR_NUM_OF_ROUTING_PATH_GROUP];

#define PDUR_STOP_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"
#endif

#endif /* PDUR_LCFG_H */
