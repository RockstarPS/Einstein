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
*    @file PduR_Lcfg.c
*    @ingroup PduRConfiguration
*    @brief This is PduR Link time configuration source file. It contains definitions of Link time configuration
*    parameters for the PduR module.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Lcfg.h"
#include "PduR_CanIf.h"
#include "PduR_Com.h"
#include "CanIf.h"
#include "CanTp.h"
#include "CanTp_Cbk.h"
#include "Com.h"
#include "Dcm_Cbk.h"

/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PDUBLIC VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/
/********************************************************************************************************************
* #! GLOBAL VARIABLES                                                                                               *
********************************************************************************************************************/

#if (PDUR_ROUTING_PATH_GROUP == STD_ON)

#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

/*! @brief Defines the routing path group enable status  */
VAR(boolean,PDUR_VAR_NOINIT) PduR_RoutingPathGrpEnableSts[PDUR_NUM_OF_ROUTING_PATH_GROUP];

#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "MemMap.h"

#endif
/********************************************************************************************************************
* #! PduR const config  data                                                                                        *
********************************************************************************************************************/

#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
    
#define PDUR_START_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"
/*  @brief Defines the Routing path group Init status */
CONST(boolean,PDUR_CONFIG_DATA) PduR_RpGroupInitStatus[PDUR_NUM_OF_ROUTING_PATH_GROUP]=
{
    0U
};

#define PDUR_STOP_SEC_CONFIG_DATA_BOOLEAN
#include "MemMap.h"

#endif

#define PDUR_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/*  @brief Defines the Interface configuration of PDUR BSW modules 
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
CONST(PduR_ModuleConfigType,PDUR_CONFIG_DATA) PduR_ModuleConfig[PDUR_NUM_OF_MODULE_ID]=
{
    { /* PDUR_MODULE_ID_COM */
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        &Com_RxIndication,
        &Com_TriggerTransmit,
        &Com_TxConfirmation,
        &Com_CopyRxData,
        &Com_CopyTxData,
        &Com_StartOfReception,
        &Com_TpRxIndication,
        &Com_TpTxConfirmation
    },
    { 
        &CanIf_Transmit,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    { /* PDUR_MODULE_ID_CANTP  */ 
        NULL_PTR,
        NULL_PTR,
        &CanTp_CancelReceive,
        &CanTp_CancelTransmit,
        NULL_PTR,
        &CanTp_Transmit,
        &CanTp_RxIndication,
        NULL_PTR,
        &CanTp_TxConfirmation,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    { /* PDUR_MODULE_ID_FLEX */
        NULL_PTR, /* LoIfTransmitFunctPtr */
        NULL_PTR, /* LoIfCancelTransmitFunctPtr */
        NULL_PTR, /* LoTpCancelReceiveFunctPtr */
        NULL_PTR, /* LoTpCancelTransmitFunctPtr */
        NULL_PTR, /* LoTpChangeParameterFunctPtr */
        NULL_PTR, /* LoTpTransmitFunctPtr */
        NULL_PTR, /* UpIfRxIndicationFunctPtr */
        NULL_PTR, /* UpIfTriggerTransmitFunctPtr */
        NULL_PTR, /* UpIfTxConfirmationFunctPtr */
        NULL_PTR, /* UpTpCopyRxDataFunctPtr */
        NULL_PTR, /* UpTpCopyTxDataFunctPtr */
        NULL_PTR, /* UpTpStartOfReceptionFunctPtr */
        NULL_PTR, /* UpTpRxIndicationFunctPtr */
        NULL_PTR  /* UpTpTxConfirmationFunctPtr */
    },
    { /* PDUR_MODULE_ID_DCM  */ 
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        &Dcm_TxConfirmation,
        &Dcm_CopyRxData,
        &Dcm_CopyTxData,
        &Dcm_StartOfReception,
        &Dcm_TpRxIndication,
        &Dcm_TpTxConfirmation
    }
};

/*  @brief Defines the source Pdu configuration 
    Elements                :   Description
    TxConfirmationSupport   :   whether Tx confirmation support is requried.
    PduType                 :   the PduId type , IF or TP
    SrcModule               :   the source module Id
    DestStartPduId          :   the destination pdu start Id
    DestEndPduId            :   the destination pdu end Id
    ModuleSrcPduId          :   the source module pdu Id
    SrcPduToGroupIdMap      :   the routing path group Ids to which it belongs
*/
CONST(PduR_SourcePduCfgType,PDUR_CONFIG_DATA) PduR_SourcePduCfg[PDUR_NUM_OF_SRC_PDU]=
{
    /* Upper layer */
    {  TRUE, PDUR_PDU_TYPE_IF,  PDUR_MODULE_ID_COM,   PDUR_DEST_CLIMATIC_PANEL,     PDUR_DEST_CLIMATIC_PANEL,   COM_PDU_CLIMATIC_PANEL  },  /* 0 PDUR_SRC_CLIMATIC_PANEL */
    {  TRUE, PDUR_PDU_TYPE_TP,  PDUR_MODULE_ID_DCM,   PDUR_DEST_E4_DIAG_RES,        PDUR_DEST_E4_DIAG_RES,      DCM_PDU_E4_DIAG_RES     },  /* 1 PDUR_SRC_E4_DIAG_RES */
    /* lower layer */
    {  FALSE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_CANIF, PDUR_DEST_BODY_CNTRL7,        PDUR_DEST_BODY_CNTRL7 ,     CANIF_PDU_BODY_CNTRL7},      /* 2 PDUR_SRC_BODY_CNTRL7 */
    {  FALSE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_CANIF, PDUR_DEST_EXTERNAL_LIGHTS,    PDUR_DEST_EXTERNAL_LIGHTS,  CANIF_PDU_EXTERNAL_LIGHTS},  /* 3 PDUR_SRC_EXTERNAL_LIGHTS */
    {  FALSE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_CANTP, PDUR_DEST_E4_DIAG_PHY_REQ,     PDUR_DEST_E4_DIAG_PHY_REQ,   CANTP_PDU_E4_DIAG_PHY_REQ},  /* 4 PDUR_SRC_E4_DIAG_PHY_REQ */
    {  FALSE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_CANTP, PDUR_DEST_E4_DIAG_FUNC_REQ,    PDUR_DEST_E4_DIAG_FUNC_REQ,  CANTP_PDU_E4_DIAG_FUNC_REQ}, /* 5 PDUR_SRC_E4_DIAG_FUNC_REQ */
};

/*  @brief Defines the destination Pdu configuration 
    Elements                :   Description
    DataProvisioning        :   the data provision type of the Pdu
    TxConfirmationSupport   :   whether Tx confirmation support is requried
    SrcPduId                :   the source pdu start Id
    ModuleDestPduId         :   the destination modult pdu Id
    DestModuleId            :   the destination module Id
    PduDestDirection        :   the destination direction Tx or Rx
    DestPduToGroupIdMap     :   the routing path group Ids to which it belongs
*/
CONST(PduR_DestPduCfgType,PDUR_CONFIG_DATA) PduR_DestPduCfg[PDUR_NUM_OF_DEST_PDU]=
{
    /* Upper layer */
    {  PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE,  PDUR_SRC_CLIMATIC_PANEL,   CANIF_PDU_CLIMATIC_PANEL,   PDUR_MODULE_ID_CANIF,   PUDR_PDU_DIRECTION_TRANSMIT},  /* 0 PDUR_DEST_CLIMATIC_PANEL */
    {  PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE,  PDUR_SRC_E4_DIAG_RES,      CANTP_PDU_E4_DIAG_RES,      PDUR_MODULE_ID_CANTP,   PUDR_PDU_DIRECTION_TRANSMIT},  /* 1 PDUR_DEST_E4_DIAG_RES */
    {  PDUR_DATA_PROVISIONING_NONE,            FALSE, PDUR_SRC_BODY_CNTRL7,      COM_PDU_BODY_CNTRL7 ,       PDUR_MODULE_ID_COM,     PUDR_PDU_DIRECTION_RECEIVE},   /* 2 PDUR_DEST_BODY_CNTRL7 */
    {  PDUR_DATA_PROVISIONING_NONE,            FALSE, PDUR_SRC_EXTERNAL_LIGHTS,  COM_PDU_EXTERNAL_LIGHTS ,   PDUR_MODULE_ID_COM,     PUDR_PDU_DIRECTION_RECEIVE},   /* 3 PDUR_DEST_EXTERNAL_LIGHTS */
    {  PDUR_DATA_PROVISIONING_NONE,            FALSE, PDUR_SRC_E4_DIAG_PHY_REQ,  DCM_PDU_E4_DIAG_PHY_REQ,    PDUR_MODULE_ID_DCM,     PUDR_PDU_DIRECTION_RECEIVE},   /* 4 PDUR_DEST_E4_DIAG_PHY_REQ */
    {  PDUR_DATA_PROVISIONING_NONE,            FALSE, PDUR_SRC_E4_DIAG_FUNC_REQ, DCM_PDU_E4_DIAG_FUNC_REQ,   PDUR_MODULE_ID_DCM,     PUDR_PDU_DIRECTION_RECEIVE}    /* 5 PDUR_DEST_E4_DIAG_FUNC_REQ */
};

#define PDUR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*   @brief      This service Requests transmission of an I-PDU from Com.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_ComTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    return PduR_UpTransmit(TxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication 
*               module.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_ComCancelTransmit(PduIdType TxPduId)
{
    return PduR_UpCancelTransmit(TxPduId);
}

/********************************************************************************************************************
*   @brief      This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_ComChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    return PduR_UpChangeParameter(id,parameter,value);
}
/********************************************************************************************************************
*   @brief      This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
*               protocol module.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_ComCancelReceive(PduIdType RxPduId)
{
    return PduR_UpCancelReceive(RxPduId);
}

/********************************************************************************************************************
*   @brief      Indication of a received PDU from a lower layer communication interface module.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_CanIfRxIndication
(
    PduIdType RxPduId, 
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    PduR_LoRxIndication(RxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief      The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*               transmit a PDU.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
    PduR_LoTxConfirmation(TxPduId,result);
}

/********************************************************************************************************************
*   @brief     Within this API, the upper layer module (called module) shall check whether the available data fits 
*              into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
*              buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in 
*              PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_CanIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
)
{
    return PduR_LoTriggerTransmit(TxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief      This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
*               Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer 
*               is written to the position indicated by bufferSizePtr.
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpCopyRxData
(
    PduIdType id, 
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
)
{
    return PduR_LoTpCopyRxData(id,info,bufferSizePtr);
}

/********************************************************************************************************************
*   @brief     Called after an I-PDU has been received via the TP API, the result indicates whether the transmission 
*              was successful or not.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result)
{
    PduR_LoTpRxIndication(id,result);
}

/********************************************************************************************************************
*   @brief     This service is called at the start of receiving an N-SDU. The N-SDU might be fragmented into 
*              multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF). 
*              The service shall provide the currently available maximum buffer size when invoked with TpSduLength 
*              equal to 0.
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
)
{
    return PduR_LoTpStartOfReception(id,info,TpSduLength,bufferSizePtr);
}

/********************************************************************************************************************
*   @brief     This service is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this 
*              function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this 
*              case the function restarts to copy the data beginning at the offset from the current position 
*              indicated by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated 
*              by availableDataPtr.
********************************************************************************************************************/
FUNC(BufReq_ReturnType,PDUR_CODE) PduR_CanTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(RetryInfoType,AUTOMATIC,PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) availableDataPtr
)
{
    return PduR_LoTpCopyTxData(id,info,retry,availableDataPtr);
}

/********************************************************************************************************************
*   @brief     This service is called after the I-PDU has been transmitted on its network, the result indicates 
*              whether the transmission was successful or not.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    PduR_LoTpTxConfirmation(id,result);
}

/********************************************************************************************************************
*   @brief     This service Requests transmission of an I-PDU.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    return PduR_UpTransmit(TxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief     This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication 
*               module.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmCancelTransmit(PduIdType TxPduId)
{
    return PduR_UpCancelTransmit(TxPduId);
}

/********************************************************************************************************************
*   @brief     This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    return PduR_UpChangeParameter(id,parameter,value);
}

/********************************************************************************************************************
*   @brief     This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
*               protocol module.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_DcmCancelReceive(PduIdType RxPduId)
{
    return PduR_UpCancelReceive(RxPduId);
}

/********************************************************************************************************************
*   @brief    Indication of a received PDU from a lower layer communication interface module.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_CanNmRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    PduR_LoRxIndication(RxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief    The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*              transmit a PDU.
********************************************************************************************************************/
 FUNC(void,PDUR_CODE) PduR_CanNmTxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
    PduR_LoTpTxConfirmation(TxPduId,result);
}

/********************************************************************************************************************
*   @brief    Within this API, the upper layer module (called module) shall check whether the available data fits 
*             into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
*             buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in 
*             PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_CanNmTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
)
{
    return PduR_LoTriggerTransmit(TxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief    Indication of a received PDU from a lower layer communication interface module.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LinIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
)
{
    PduR_LoRxIndication(RxPduId,PduInfoPtr);
}

/********************************************************************************************************************
*   @brief    The lower layer communication interface module confirms the transmission of a PDU, or the failure to 
*              transmit a PDU.
********************************************************************************************************************/
FUNC(void,PDUR_CODE) PduR_LinIfTxConfirmation(PduIdType TxPduId,Std_ReturnType result)
{
    PduR_LoTxConfirmation(TxPduId,result);
}

/********************************************************************************************************************
*   @brief    Within this API, the upper layer module (called module) shall check whether the available data fits 
*             into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
*             buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in 
*             PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
********************************************************************************************************************/
FUNC(Std_ReturnType,PDUR_CODE) PduR_LinIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
)
{
    return PduR_LoTriggerTransmit(TxPduId,PduInfoPtr);
}

#define PDUR_STOP_SEC_CODE
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
*  @date    14-JUL-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - vAUTOSAR 4.3 version Initial update
*******************************************************************************************************************/

