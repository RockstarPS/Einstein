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
*    @file PduR_Cfg.h
*    @ingroup PduRConfiguration
*    @brief This is PduR Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the PduR module.
*    @defgroup PduRConfiguration
*    @brief This contains the configuration parameteres for the PduR module.
********************************************************************************************************************/
#ifndef PDUR_CFG_H
#define PDUR_CFG_H
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "PduR_Types.h"
/********************************************************************************************************************
*  #! Precompile Configuration                                                                                      *
********************************************************************************************************************/
/*! @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF.*/
#define PDUR_DEV_ERROR_DETECT                   STD_ON
/*! @brief Enables/Disables support for MetaData handling.*/
#define PDUR_META_DATA_SUPPORT                  STD_OFF
/*! @brief Enables/Disables the routing functionality of PDUR*/
/*! @brief Enables/Disables the PduR_GetVersionInfo API availability.*/
#define PDUR_VERSION_INFO_API                   STD_ON
/*! @brief Enables/Disables the zero-cost-operation functionality.*/
#define PDUR_ZERO_COST_OPERATION                STD_OFF

/* Internal Feature Macro support */ 
/*! @brief Enables/Disables the routing group support */
#define PDUR_ROUTING_PATH_GROUP                 STD_OFF
/********************************************************************************************************************
*  #! SW and AUTOSAR Version Macros                                                                                 *
********************************************************************************************************************/
/*! @brief Defines the PduR configuration software Major version */
#define PDUR_CFG_SW_MAJOR_VERSION                               1u
/*! @brief Defines the PduR configuration software Minor version */
#define PDUR_CFG_SW_MINOR_VERSION                               0u
/*! @brief Defines the PduR configuration software Patch version */
#define PDUR_CFG_SW_PATCH_VERSION                               0u
/*! @brief Defines the AUTOSAR Release Major version supported by PduR configuration  */
#define PDUR_CFG_AR_RELEASE_MAJOR_VERSION                       4u
/*! @brief Defines the AUTOSAR Release Minor version supported by PduR configuration  */
#define PDUR_CFG_AR_RELEASE_MINOR_VERSION                       3u
/*! @brief Defines the AUTOSAR Release Patch version supported by PduR configuration  */
#define PDUR_CFG_AR_RELEASE_REVISION_VERSION                    1u
/*******************************************************************************************************************
*  #! PduR module configuration                                                                                    *
*******************************************************************************************************************/
/*! @brief defines the module id for the each modules */
#define PDUR_MODULE_ID_COM      0U
#define PDUR_MODULE_ID_CANIF    1U
#define PDUR_MODULE_ID_CANTP    2U
#define PDUR_MODULE_ID_LINIF    3U
#define PDUR_MODULE_ID_DCM      4U
#define PDUR_NUM_OF_MODULE_ID   5U

#define COM_TX_PDU1 0U
#define COM_TX_PDU2 0U
#define DCM_TX_PDU1 0U
#define CANIF_RX_PDU2 0U
#define CANTP_RX_PDU1 0U
#define CANIF_TX_PDU1 0U
#define CANIF_TX_PDU2 0U
#define FLEXIF_TX_PDU1 0U
#define CANTP_TX_PDU1 0U
#define COM_RX_PDU2 0U
#define COM_RX_PDU1 0U
#define CDD_RX_PDU1 0U
#define DCM_RX_PDU1 0U
#define CANIF_RX_PDU1 0U
#define PDUR_TX_PDU1 0U
#define PDUR_TX_PDU2 0U
#define PDUR_RX_PDU1 0U
#define PDUR_RX_PDU2 0U

#define PDUR_PDU_VIN_01            0U
#define PDUR_PDU_SERVICE_KEY_01    0U
#define PDUR_PDU_MDK_ZV_REQ        0U
#define PDUR_PDU_VIN_01_M0         0U
#define PDUR_PDU_VIN_01_M1         0U
#define PDUR_PDU_VIN_01_M2         0U
#define PDUR_PDU_SERVICE_KEY_01_M0 0U
#define PDUR_PDU_SERVICE_KEY_01_M1 0U
#define PDUR_PDU_SERVICE_KEY_01_M2 0U
#define PDUR_PDU_SERVICE_KEY_01_M3 0U
#define PDUR_PDU_SERVICE_KEY_01_M4 0U
#define PDUR_PDU_SERVICE_KEY_01_M5 0U
#define PDUR_PDU_SERVICE_KEY_01_M6 0U
#define PDUR_PDU_SERVICE_KEY_01_M7 0U
#define PDUR_PDU_SERVICE_KEY_01_M8 0U
#define PDUR_PDU_SERVICE_KEY_01_M9 0U
#define PDUR_PDU_MDK_ZV_REQ_M0     0U
#define PDUR_PDU_MDK_ZV_REQ_M1     0U
#define PDUR_PDU_MDK_ZV_REQ_M2     0U
#define PDUR_PDU_MDK_ZV_REQ_M3     0U
#define PDUR_PDU_MDK_ZV_REQ_M4     0U
#define PDUR_PDU_MDK_ZV_REQ_M5     0U
#define PDUR_PDU_MDK_ZV_REQ_STATIC 0U
#define PDUR_PDU_VIN_01            0U
#define PDUR_PDU_VIN_01PDUR_PDU_MDK_ZV_REQ            0U
#define PDUR_PDU_MDK_ZV_RESP_M0    0U
#define PDUR_PDU_MDK_ZV_RESP_M1    0U
#define PDUR_PDU_PSD_06_M0         0U
#define PDUR_PDU_MOTOR_09_M0       0U
#define PDUR_PDU_MOTOR_09_M1       0U
#define PDUR_PDU_MOTOR_09_M2       0U
#define PDUR_PDU_MOTOR_09_M3       0U
#define PDUR_PDU_MOTOR_GAS_01_M0   0U
#define PDUR_PDU_MOTOR_GAS_01_M1   0U
#define PDUR_PDU_MDK_ZV_RESP_STATIC   0U
#define PDUR_PDU_MOTOR_09_STATIC   0U
#define PDUR_PDU_MOTOR_GAS_01_STATIC   0U
#define PDUR_PDU_MDK_ZV_RESP_M0   0U
#define PDUR_PDU_MDK_ZV_RESP_M1   0U



#define PDUR_PDU_BODY_CNTRL7 0

#define PDUR_PDU_CLIMATIC_PANEL 0

/*******************************************************************************************************************
*  #! PduR source and destination Pdu configuration                                                                *
*******************************************************************************************************************/
/*! @brief  Defines the Source PduId of the module */
#define PDUR_SRC_CLIMATIC_PANEL     0U  /*  COM_TX -> CANIF tx msg */
#define PDUR_SRC_E4_DIAG_RES        1U  /*  Dcm Tx -> CANTp tx msg */
#define PDUR_SRC_BODY_CNTRL7        2U  /*  CanIf Rx -> Com Rx msg */
#define PDUR_SRC_EXTERNAL_LIGHTS    3U  /*  CanIf Rx -> Com Rx msg */
#define PDUR_SRC_E4_DIAG_PHY_REQ    4U  /*  CanTp Rx -> Dcm Rx msg */
#define PDUR_SRC_E4_DIAG_FUNC_REQ   5U  /*  CanTp Rx -> Dcm Rx msg */
#define PDUR_NUM_OF_SRC_PDU         6U

/*! @brief Defines the destination PduId of the module */
#define PDUR_DEST_CLIMATIC_PANEL    0U   /*  COM_TX -> CANIF tx msg */
#define PDUR_DEST_E4_DIAG_RES       1U   /*  Dcm Tx -> CANTp tx msg */
#define PDUR_DEST_BODY_CNTRL7       2U   /*  CanIf Rx -> Com Rx msg */
#define PDUR_DEST_EXTERNAL_LIGHTS   3U   /*  CanIf Rx -> Com Rx msg */
#define PDUR_DEST_E4_DIAG_PHY_REQ   4U   /*  CanTp Rx -> Dcm Rx msg */
#define PDUR_DEST_E4_DIAG_FUNC_REQ  5U   /*  CanTp Rx -> Dcm Rx msg */
#define PDUR_NUM_OF_DEST_PDU        6U

/*******************************************************************************************************************
*  #! PduR Pdu group configuration                                                                                 *
*******************************************************************************************************************/
/*! @brief Defines the number of routing path group supported. */
#define PDUR_NUM_OF_ROUTING_PATH_GROUP          1u
/*! @brief Defines the pdu to routing path group id mapping */
#define PDUR_NUM_OF_PDU_TO_GROUP_ID_MAP_BYTES   1u
/*! @brief Defines the default configuration id */
#define PDUR_DEFAULT_CONFIGURATION_ID           0u
/*! @brief unused  parameter macros */
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v)
#endif
/*******************************************************************************************************************
* #! PduR configuration macros ,typedef and structure                                                              *
********************************************************************************************************************/
/*! @brief The PDUR module shall call the transmit function in the destination module.
    The destination module will request the I-PDU using the triggerTransmit function. The I-PDU is shall be
    buffered.*/
#define PDUR_DATA_PROVISIONING_TRIGGER_TRANSMIT 0U
/*! @brief The PDUR module shall call the transmit function in the destination module and not buffer the I-PDU*/
#define PDUR_DATA_PROVISIONING_DIRECT_TRANSMIT  1U
/*! @brief The PDUR module does nothing. This should be used for receive direction type*/
#define PDUR_DATA_PROVISIONING_NONE             2U
/*! @brief This defines the PduId type as IF */
#define PDUR_PDU_TYPE_IF					    0U
/*! @brief This defines the PduId type as TP */
#define PDUR_PDU_TYPE_TP					    1U
/*! @brief This defines the PduR direction as Transmit */
#define PUDR_PDU_DIRECTION_TRANSMIT	            0U
/*! @brief This defines the PduR direction as Receive */
#define PUDR_PDU_DIRECTION_RECEIVE	            1U


#define PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_A_45618847      0U
#define PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_B_45618847      0U
#define PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_C_45618847      0U
#define PduRConf_PduRDestPdu_DST_Lin_PT_LIN_IPC_D_45618847      0U
/********************************************************************************************************************
*                                       #! PduR Internal types                                                      *
*                                       #! typedef declaration                                                      *
********************************************************************************************************************/
/*! @brief Defines the module id type */
typedef uint8 PduR_ModuleIdType;
/*! @brief Defines the pdu type as IF or TP */
typedef uint8 PduR_PduType;
#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
/*! @brief Defines the PduId to Routing group mapping */
typedef uint8 PduR_PduToGroupIdMapType[PDUR_NUM_OF_PDU_TO_GROUP_ID_MAP_BYTES];
#endif
/*! @brief Defines the Pdu dircetion type Tx or Rx */
typedef uint8 PduR_PduDirectionType;
/*! @brief Defines the function type for the PduR Lower layer communication interface transmission.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoIfTransmitFunctType)
(
    PduIdType TxPduId, 
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
);
/*! @brief Defines the function type for the PduR Lower layer communication interface cancel transmission.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoIfCancelTransmitFunctType)(PduIdType TxPduId);
/*! @brief Defines the function type for the PduR Lower layer  transport protocol cancel receive.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoTpCancelReceiveFunctType)(PduIdType RxPduId);
/*! @brief Defines the function type for the PduR Lower layer  transport protocol cancel transmit.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoTpCancelTransmitFunctType)(PduIdType TxPduId);
/*! @brief Defines the function type for the PduR Lower layer  transport protocol change Parameter.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoTpChangeParameterFunctType)
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);
/*! @brief Defines the function type for the PduR Lower layer  transport protocol transmit.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_LoTpTransmitFunctType)
(
    PduIdType TxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
);
/*! @brief Defines the function type for the PduR upper layer communication interface receive indication.*/
typedef P2FUNC(void,PDUR_APPL_CODE,PduR_UpIfRxIndicationFunctType)
(
    PduIdType RxPduId,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) PduInfoPtr
);
/*! @brief Defines the function type for the PduR upper layer interface communication trigger transmit.*/
typedef P2FUNC(Std_ReturnType,PDUR_APPL_CODE,PduR_UpIfTriggerTransmitFunctType)
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
/*! @brief Defines the function type for the PduR upper layer interface communication transmit confirmation.*/
typedef P2FUNC(void,PDUR_APPL_CODE,PduR_UpIfTxConfirmationFunctType)(PduIdType TxPduId,Std_ReturnType result);
/*! @brief Defines the function type for the PduR upper layer transport protocol receive data copy.*/
typedef P2FUNC(BufReq_ReturnType,PDUR_APPL_CODE,PduR_UpTpCopyRxDataFunctType)
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
);
/*! @brief Defines the function type for the PduR upper layer transport protocol transmit data copy.*/
typedef P2FUNC(BufReq_ReturnType,PDUR_APPL_CODE,PduR_UpTpCopyTxDataFunctType)
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    P2CONST(RetryInfoType,AUTOMATIC,PDUR_APPL_CONST) retry,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) availableDataPtr
);
/*! @brief Defines the function type for the PduR upper layer transport protocol start of reception .*/
typedef P2FUNC(BufReq_ReturnType,PDUR_APPL_CODE,PduR_UpTpStartOfReceptionFunctType)
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,PDUR_APPL_DATA) bufferSizePtr
);
/*! @brief Defines the function type for the PduR upper layer transport protocol reception indication  .*/
typedef P2FUNC(void,PDUR_APPL_CODE,PduR_UpTpRxIndicationFunctType)(PduIdType id,Std_ReturnType result);
/*! @brief Defines the function type for the PduR upper layer transport protocol transmit confirmation.*/
typedef P2FUNC(void,PDUR_APPL_CODE,PduR_UpTpTxConfirmationFunctType)(PduIdType id, Std_ReturnType result);
/*! @brief Defines the source Pdu configuration */
typedef struct
{
    /*! @brief Defines whether Tx confirmation support is requried */
	boolean 			TxConfirmationSupport;
    /*! @brief Defines the PduId type , IF or TP */
	PduR_PduType		PduType;
    /*! @brief Defines the source module Id */
	PduR_ModuleIdType	SrcModule;
    /*! @brief Defines the destination pdu start Id */
	PduIdType			DestStartPduId;
    /*! @brief Defines the destination pdu end Id */
	PduIdType			DestEndPduId;
    /*! @brief Defines the source module pdu Id */
	PduIdType			ModuleSrcPduId;
#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
    /*! @brief Defines the routing path group Ids to which it belongs. Each bit represents a group Id*/
    PduR_PduToGroupIdMapType        SrcPduToGroupIdMap;
#endif
}PduR_SourcePduCfgType;

/*! @brief Defines the destination Pdu configuration type */
typedef struct
{
    /*! @brief Defines the data provision type of the Pdu */
	PduR_DataProvisioningType	DataProvisioning;
    /*! @brief Defines whether Tx confirmation support is requried */
	boolean 					TxConfirmationSupport;
    /*! @brief Defines the source pdu start Id */
	PduIdType					SrcPduId;
    /*! @brief Defines the destination modult pdu Id */
	PduIdType					ModuleDestPduId;
    /*! @brief Defines the destination module Id */
	PduR_ModuleIdType	        DestModuleId;
    /*! @brief Defines the destination direction Tx or Rx */
	PduR_PduDirectionType		PduDestDirection;
#if (PDUR_ROUTING_PATH_GROUP == STD_ON)
    /*! @brief Defines the routing path group Ids to which it belongs. Each bit represents a group Id*/
    PduR_PduToGroupIdMapType    DestPduToGroupIdMap;
#endif
}PduR_DestPduCfgType;

/*! @brief Defines the Interface configuration of PDUR BSW modules */
typedef struct
{
    /*! @brief Defines the function type for the PduR Lower layer communication interface transmission.*/
    PduR_LoIfTransmitFunctType              LoIfTransmitFunctPtr;
    /*! @brief Defines the function type for the PduR Lower layer communication interface cancel transmission.*/
    PduR_LoIfCancelTransmitFunctType        LoIfCancelTransmitFunctPtr;
    /*! @brief Defines the function type for the PduR Lower layer transport protocol cancel receive.*/
    PduR_LoTpCancelReceiveFunctType         LoTpCancelReceiveFunctPtr;
    /*! @brief Defines the function type for the PduR Lower layer transport protocol cancel transmit.*/
    PduR_LoTpCancelTransmitFunctType        LoTpCancelTransmitFunctPtr;
    /*! @brief Defines the function type for the PduR Lower layer transport protocol change Parameter.*/
    PduR_LoTpChangeParameterFunctType       LoTpChangeParameterFunctPtr;
    /*! @brief Defines the function type for the PduR Lower layer transport protocol transmit.*/
    PduR_LoTpTransmitFunctType              LoTpTransmitFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer communication interface reception */
    PduR_UpIfRxIndicationFunctType          UpIfRxIndicationFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer communication interface trigger transmit */
    PduR_UpIfTriggerTransmitFunctType       UpIfTriggerTransmitFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer communication interface transmit confirmation*/
    PduR_UpIfTxConfirmationFunctType        UpIfTxConfirmationFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer transport protocol receive data copy */
    PduR_UpTpCopyRxDataFunctType            UpTpCopyRxDataFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer transport protocol transmit data copy */
    PduR_UpTpCopyTxDataFunctType            UpTpCopyTxDataFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer transport protocol start of reception */
    PduR_UpTpStartOfReceptionFunctType      UpTpStartOfReceptionFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer transport protocol receive  */
    PduR_UpTpRxIndicationFunctType          UpTpRxIndicationFunctPtr;
    /*! @brief Defines the function type for the PduR upper layer transport protocol transmit confirmation */
    PduR_UpTpTxConfirmationFunctType        UpTpTxConfirmationFunctPtr;
} PduR_ModuleConfigType;

/*! @brief  This type contains the implementation-specific post build configuration structure of PduR .
            Dummy config is used as post build not supported*/
typedef struct
{
    uint8 dummy;
} PduR_PBConfigType;

#endif /* PDUR_CFG_H */

/********************************************************************************************************************
*                                 END OF FILE                                                                       *
********************************************************************************************************************/

