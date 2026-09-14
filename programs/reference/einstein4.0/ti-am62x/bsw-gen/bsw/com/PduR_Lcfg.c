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
#include "PduR_Cfg.h"
#include "CanIf.h"
#include "CanIf_Cfg.h"
#include "CanTp.h"
#include "CanTp_Cbk.h"
#include "Com.h"
#include "Com_Cfg.h"
#include "Dcm_Cfg.h"
#include "Dcm_Cbk.h"
#include "PduR_LinIf.h"
#include "PduR_CanNm.h"
#include "PduR_CanTp.h"
#include "PduR_Dcm.h"

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
VAR(boolean, PDUR_VAR_NOINIT)
PduR_RoutingPathGrpEnableSts[PDUR_NUM_OF_ROUTING_PATH_GROUP];

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
CONST(boolean, PDUR_CONFIG_DATA)
PduR_RpGroupInitStatus[PDUR_NUM_OF_ROUTING_PATH_GROUP] =
    {
        0U};

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
CONST(PduR_ModuleConfigType, PDUR_CONFIG_DATA)
PduR_ModuleConfig[PDUR_NUM_OF_MODULE_ID] =
    {
        {/* PDUR_MODULE_ID_COM */
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
         &Com_TpTxConfirmation},
        {&CanIf_Transmit,
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
         NULL_PTR},
        {/* PDUR_MODULE_ID_CANTP  */
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
         NULL_PTR},
        {/* PDUR_MODULE_ID_DCM  */
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
         &Dcm_TpTxConfirmation}};

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
CONST(PduR_SourcePduCfgType, PDUR_CONFIG_DATA)
PduR_SourcePduCfg[PDUR_NUM_OF_SRC_PDU] =
    {
        /* Upper layer- Tx*/
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_CLUSTER_TX_NORMAL_COM_HS, PDUR_DEST_CLUSTER_TX_NORMAL_COM_HS, COM_PDU_CLUSTER_TX_NORMAL_COM_HS_512_CAN0}, /* 0 PDUR_SRC_CLUSTER_TX_NORMAL_COM_HS */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_CLUSTER_TX_NORMAL_COM_MS, PDUR_DEST_CLUSTER_TX_NORMAL_COM_MS, COM_PDU_CLUSTER_TX_NORMAL_COM_MS_513_CAN0}, /* 1 PDUR_SRC_CLUSTER_TX_NORMAL_COM_MS */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_CLUSTER_TX_NORMAL_COM_LS, PDUR_DEST_CLUSTER_TX_NORMAL_COM_LS, COM_PDU_CLUSTER_TX_NORMAL_COM_LS_514_CAN0}, /* 2 PDUR_SRC_CLUSTER_TX_NORMAL_COM_LS */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_CLUSTER_TX_REDUCED_COM, PDUR_DEST_CLUSTER_TX_REDUCED_COM, COM_PDU_CLUSTER_TX_REDUCED_COM_528_CAN0},       /* 3 PDUR_SRC_CLUSTER_TX_REDUCED_COM */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_CLUSTER_SECURE_TX, PDUR_DEST_CLUSTER_SECURE_TX, COM_PDU_CLUSTER_SECURE_TX_768_CAN0},                      /* 4 PDUR_SRC_CLUSTER_SECURE_TX */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_DEBUG_FRAME1, PDUR_DEST_DEBUG_FRAME1, COM_PDU_DEBUG_FRAME1_1360_CAN0},                                    /* 5 PDUR_SRC_DEBUG_FRAME1 */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_DEBUG_FRAME2, PDUR_DEST_DEBUG_FRAME2, COM_PDU_DEBUG_FRAME2_1361_CAN0},                                    /* 6 PDUR_SRC_DEBUG_FRAME2 */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_DEBUG_FRAME3, PDUR_DEST_DEBUG_FRAME3, COM_PDU_DEBUG_FRAME3_1362_CAN0},                                    /* 7 PDUR_SRC_DEBUG_FRAME3 */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_DEBUG_FRAME4, PDUR_DEST_DEBUG_FRAME4, COM_PDU_DEBUG_FRAME4_1363_CAN0},                                    /* 8 PDUR_SRC_DEBUG_FRAME4 */
        {TRUE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_COM, PDUR_DEST_DEBUG_FRAME5, PDUR_DEST_DEBUG_FRAME5, COM_PDU_DEBUG_FRAME5_1364_CAN0},                                    /* 9 PDUR_SRC_DEBUG_FRAME5 */
        {TRUE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_DCM, PDUR_DEST_DIAG_RESP_UUDT, PDUR_DEST_DIAG_RESP_UUDT, DCM_PDU_DIAG_RESP_UUDT},                                        /* 10 PDUR_SRC_DIAG_RESP_UUDT */
        {TRUE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_DCM, PDUR_DEST_DIAG_RESP_USDT, PDUR_DEST_DIAG_RESP_USDT, DCM_PDU_DIAG_RESP_USDT},                                        /* 11 PDUR_SRC_DIAG_RESP_USDT */

        /* lower layer-Rx */
        {FALSE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_CANIF, PDUR_DEST_VEHICLE_CONTROL, PDUR_DEST_VEHICLE_CONTROL, CANIF_PDU_VEHICLE_CONTROL},            /* 12 PDUR_SRC_VEHICLE_CONTROL */
        {FALSE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_CANIF, PDUR_DEST_ILLUM_CONTROL, PDUR_DEST_ILLUM_CONTROL, CANIF_PDU_ILLUM_CONTROL},                  /* 13 PDUR_SRC_ILLUM_CONTROL */
        {FALSE, PDUR_PDU_TYPE_IF, PDUR_MODULE_ID_CANIF, PDUR_DEST_ABS, PDUR_DEST_ABS, CANIF_PDU_ABS},                                                /* 14 PDUR_SRC_ABS */
        {FALSE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_CANTP, PDUR_DEST_DIAG_REQ_PHYSICAL, PDUR_DEST_DIAG_REQ_PHYSICAL, CANTP_PDU_DIAG_REQ_PHYSICAL},      /* 15 PDUR_SRC_DIAG_REQ_PHYSICAL */
        {FALSE, PDUR_PDU_TYPE_TP, PDUR_MODULE_ID_CANTP, PDUR_DEST_DIAG_REQ_FUNCTIONAL, PDUR_DEST_DIAG_REQ_FUNCTIONAL, CANTP_PDU_DIAG_REQ_FUNCTIONAL} /* 16 PDUR_SRC_DIAG_REQ_FUNCTIONAL */
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
CONST(PduR_DestPduCfgType, PDUR_CONFIG_DATA)
PduR_DestPduCfg[PDUR_NUM_OF_DEST_PDU] =
    {
        /* Upper layer-Tx */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_CLUSTER_TX_NORMAL_COM_HS, CANIF_PDU_CLUSTER_TX_NORMAL_COM_HS, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT}, /* 0 PDUR_DEST_CLUSTER_TX_NORMAL_COM_HS */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_CLUSTER_TX_NORMAL_COM_MS, CANIF_PDU_CLUSTER_TX_NORMAL_COM_MS, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT}, /* 1 PDUR_DEST_CLUSTER_TX_NORMAL_COM_MS */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_CLUSTER_TX_NORMAL_COM_LS, CANIF_PDU_CLUSTER_TX_NORMAL_COM_LS, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT}, /* 2 PDUR_DEST_CLUSTER_TX_NORMAL_COM_LS */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_CLUSTER_TX_REDUCED_COM, CANIF_PDU_CLUSTER_TX_REDUCED_COM, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},     /* 3 PDUR_DEST_CLUSTER_TX_REDUCED_COM */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_CLUSTER_SECURE_TX, CANIF_PDU_CLUSTER_SECURE_TX, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},               /* 4 PDUR_DEST_CLUSTER_SECURE_TX */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DEBUG_FRAME1, CANIF_PDU_DEBUG_FRAME_1, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},                        /* 5 PDUR_DEST_DEBUG_FRAME1 */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DEBUG_FRAME2, CANIF_PDU_DEBUG_FRAME_2, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},                        /* 6 PDUR_DEST_DEBUG_FRAME2 */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DEBUG_FRAME3, CANIF_PDU_DEBUG_FRAME_3, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},                        /* 7 PDUR_DEST_DEBUG_FRAME3 */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DEBUG_FRAME4, CANIF_PDU_DEBUG_FRAME_4, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},                        /* 8 PDUR_DEST_DEBUG_FRAME4 */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DEBUG_FRAME5, CANIF_PDU_DEBUG_FRAME_5, PDUR_MODULE_ID_CANIF, PUDR_PDU_DIRECTION_TRANSMIT},                        /* 9 PDUR_DEST_DEBUG_FRAME5 */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DIAG_RESP_UUDT, CANTP_PDU_DIAG_RESP_UUDT, PDUR_MODULE_ID_CANTP, PUDR_PDU_DIRECTION_TRANSMIT},                     /* 10 PDUR_DEST_DIAG_RESP_UUDT */
        {PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT, TRUE, PDUR_SRC_DIAG_RESP_USDT, CANTP_PDU_DIAG_RESP_USDT, PDUR_MODULE_ID_CANTP, PUDR_PDU_DIRECTION_TRANSMIT},                     /* 11 PDUR_DEST_DIAG_RESP_USDT */

        /*Lower layer-Rx*/
        {PDUR_DATA_PROVISIONING_NONE, FALSE, PDUR_SRC_VEHICLE_CONTROL, COM_PDU_VEHICLECONTROL_256_CAN0, PDUR_MODULE_ID_COM, PDUR_PDU_DIRECTION_RECEIVE}, /* 12 PDUR_DEST_VEHICLECONTROL */
        {PDUR_DATA_PROVISIONING_NONE, FALSE, PDUR_SRC_ILLUM_CONTROL, COM_PDU_ILLUM_CONTROL_257_CAN0, PDUR_MODULE_ID_COM, PDUR_PDU_DIRECTION_RECEIVE},    /* 13 PDUR_DEST_ILLUM_CONTROL */
        {PDUR_DATA_PROVISIONING_NONE, FALSE, PDUR_SRC_ABS, COM_PDU_ABS_258_CAN00, PDUR_MODULE_ID_COM, PDUR_PDU_DIRECTION_RECEIVE},                       /*14 PDUR_DEST_ABS*/
        {PDUR_DATA_PROVISIONING_NONE, FALSE, PDUR_SRC_DIAG_REQ_PHYSICAL, DCM_PDU_E4_DIAG_PHY_REQ, PDUR_MODULE_ID_DCM, PDUR_PDU_DIRECTION_RECEIVE},       /* 15 PDUR_DEST_DIAG_REQ_PHYSICAL */
        {PDUR_DATA_PROVISIONING_NONE, FALSE, PDUR_SRC_DIAG_REQ_FUNCTIONAL, DCM_PDU_E4_DIAG_FUNC_REQ, PDUR_MODULE_ID_DCM, PDUR_PDU_DIRECTION_RECEIVE}     /* 16 PDUR_DEST_DIAG_REQ_FUNCTIONAL */
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
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComTransmit(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr)
{
    return PduR_UpTransmit(TxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief      This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication
 *               module.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComCancelTransmit(PduIdType TxPduId)
{
    return PduR_UpCancelTransmit(TxPduId);
}

/********************************************************************************************************************
 *   @brief      This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    return PduR_UpChangeParameter(id, parameter, value);
}
/********************************************************************************************************************
 *   @brief      This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 *               protocol module.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_ComCancelReceive(PduIdType RxPduId)
{
    return PduR_UpCancelReceive(RxPduId);
}

/********************************************************************************************************************
 *   @brief      Indication of a received PDU from a lower layer communication interface module.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanIfRxIndication(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr)
{
    PduR_LoRxIndication(RxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief      The lower layer communication interface module confirms the transmission of a PDU, or the failure to
 *               transmit a PDU.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanIfTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    PduR_LoTxConfirmation(TxPduId, result);
}

/********************************************************************************************************************
 *   @brief     Within this API, the upper layer module (called module) shall check whether the available data fits
 *              into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
 *              buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in
 *              PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_CanIfTriggerTransmit(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
{
    return PduR_LoTriggerTransmit(TxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief      This function is called to provide the received data of an I-PDU segment (N-PDU) to the upper layer.
 *               Each call to this function provides the next part of the I-PDU data. The size of the remaining buffer
 *               is written to the position indicated by bufferSizePtr.
 ********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpCopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
    return PduR_LoTpCopyRxData(id, info, bufferSizePtr);
}

/********************************************************************************************************************
 *   @brief     Called after an I-PDU has been received via the TP API, the result indicates whether the transmission
 *              was successful or not.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result)
{
    PduR_LoTpRxIndication(id, result);
}

/********************************************************************************************************************
 *   @brief     This service is called at the start of receiving an N-SDU. The N-SDU might be fragmented into
 *              multiple N-PDUs (FF with one or more following CFs) or might consist of a single N-PDU (SF).
 *              The service shall provide the currently available maximum buffer size when invoked with TpSduLength
 *              equal to 0.
 ********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpStartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
{
    return PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr);
}

/********************************************************************************************************************
 *   @brief     This service is called to acquire the transmit data of an I-PDU segment (N-PDU). Each call to this
 *              function provides the next part of the I-PDU data unless retry->TpDataState is TP_DATARETRY. In this
 *              case the function restarts to copy the data beginning at the offset from the current position
 *              indicated by retry->TxTpDataCnt. The size of the remaining data is written to the position indicated
 *              by availableDataPtr.
 ********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
PduR_CanTpCopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) info,
    P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
{
    return PduR_LoTpCopyTxData(id, info, retry, availableDataPtr);
}

/********************************************************************************************************************
 *   @brief     This service is called after the I-PDU has been transmitted on its network, the result indicates
 *              whether the transmission was successful or not.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result)
{
    PduR_LoTxConfirmation(id, result);
}

/********************************************************************************************************************
 *   @brief     This service Requests transmission of an I-PDU.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmTransmit(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr)
{
    return PduR_UpTransmit(TxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief     This service Requests cancellation of an ongoing transmission of a PDU in a lower layer communication
 *               module.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelTransmit(PduIdType TxPduId)
{
    return PduR_UpCancelTransmit(TxPduId);
}

/********************************************************************************************************************
 *   @brief     This service Request to change a specific transport protocol parameter (e.g. block size). obsolete
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    return PduR_UpChangeParameter(id, parameter, value);
}

/********************************************************************************************************************
 *   @brief     This service Requests cancellation of an ongoing reception of an I-PDU in a lower layer transport
 *               protocol module.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_DcmCancelReceive(PduIdType RxPduId)
{
    return PduR_UpCancelReceive(RxPduId);
}

/********************************************************************************************************************
 *   @brief    Indication of a received PDU from a lower layer communication interface module.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanNmRxIndication(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr)
{
    PduR_LoRxIndication(RxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief    The lower layer communication interface module confirms the transmission of a PDU, or the failure to
 *              transmit a PDU.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_CanNmTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    PduR_LoTpTxConfirmation(TxPduId, result);
}

/********************************************************************************************************************
 *   @brief    Within this API, the upper layer module (called module) shall check whether the available data fits
 *             into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
 *             buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in
 *             PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_CanNmTriggerTransmit(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
{
    return PduR_LoTriggerTransmit(TxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief    Indication of a received PDU from a lower layer communication interface module.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_LinIfRxIndication(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_CONST) PduInfoPtr)
{
    PduR_LoRxIndication(RxPduId, PduInfoPtr);
}

/********************************************************************************************************************
 *   @brief    The lower layer communication interface module confirms the transmission of a PDU, or the failure to
 *              transmit a PDU.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE)
PduR_LinIfTxConfirmation(PduIdType TxPduId, Std_ReturnType result)
{
    PduR_LoTxConfirmation(TxPduId, result);
}

/********************************************************************************************************************
 *   @brief    Within this API, the upper layer module (called module) shall check whether the available data fits
 *             into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into the
 *             buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data in
 *             PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 ********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE)
PduR_LinIfTriggerTransmit(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr)
{
    return PduR_LoTriggerTransmit(TxPduId, PduInfoPtr);
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
