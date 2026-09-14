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
*    @file CanIf.c
*    @ingroup CanIf
*    @brief This file implements the AUTOSAR CanIf module.The CanIf module is responsible for the control flow
*           abstraction of the configured CAN Controllers and CAN Transceivers.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "CanIf.h"
#include "CanIf_Lcfg.h"
#include "CanIf_Cbk.h"
#include "SchM_CanIf.h"
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
/********************************************************************************************************************
*  Version check                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_CFG_SW_MAJOR_VERSION) || \
    (CANIF_SW_MINOR_VERSION != CANIF_CFG_SW_MINOR_VERSION) || \
    (CANIF_SW_PATCH_VERSION != CANIF_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_CFG_AR_RELEASE_MINOR_VERSION) || \
    (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif
/********************************************************************************************************************
*  feature validation check                                                                                         *
********************************************************************************************************************/
#if((CANIF_META_DATA_TX_SUPPORT == STD_ON) && (CANIF_META_DATA_SUPPORT == STD_OFF))
    #error "Invalid configuration : CANIF_META_DATA_SUPPORT should be STD_ON "
#endif

#if((CANIF_META_DATA_RX_SUPPORT == STD_ON) && (CANIF_META_DATA_SUPPORT == STD_OFF))
    #error "Invalid configuration : CANIF_META_DATA_SUPPORT should be STD_ON "
#endif

/* Unsupported feature */
#if(CANIF_SUPPORT_TTCAN == STD_ON)
    #error " TTCAN feature not supported "
#endif
#if(CANIF_PUBLIC_PN_FILTER_SUPPORT == STD_ON)
    #error " PN filter feature not supported "
#endif 
#if(CANIF_RX_PDU_RANGE_SUPPORT == STD_ON)
    #error " Rx PDU range feature not supported "
#endif
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
/* Macro for static and inline type */
#ifndef CANIF_LOCAL 
#define CANIF_LOCAL                               static
#endif

#ifndef CANIF_LOCAL_INLINE
#define CANIF_LOCAL_INLINE                        LOCAL_INLINE
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*! @brief Defines the Hash1 generation for double hash algorithm */ 
#define CANIF_UTILGETHASH1(key,size)	((key) % (size))
/*! @brief Defines the the Hash2 generation for double hash algorithm */ 
#define CANIF_UTILGETHASH2(key,prime)	((prime)-((key)%(prime)))
#endif
/*! @brief Defines the the util macro for unused vairable */
#define CANIF_UNUSED_PARAMETER(x)       (void)(x)
/*! @brief Defines the maximum standarad CAN ID value  */
#define CANIF_STD_CAN_ID_MAX_VAL                            0x7ffU
/*! @brief Defines the maximum extended CAN ID value  */
#define CANIF_STD_EXT_ID_MAXVAL                             0x1fffffffU
/* Can Id type */
/*  00 CAN message with Standard CAN ID
    01 CAN FD frame with Standard CAN ID
    10 CAN message with Extended CAN ID
    11 CAN FD frame with Extended CAN ID */
#if (CANIF_EXTENDEDID_SUPPORT == STD_ON)
 /*! @brief Defines the mask value for the standarad CAN ID , if extended id is supported */
#define CANIF_CANID_MASK                                    0xC0000000u
 /*! @brief Defines the mask value for the CAN FD ID ,if extended id is supported */
#define CANIF_CANID_FD_CAN                                  0x40000000u
 /*! @brief Defines the mask value for the Extended CAN ID ,if extended id is supported */
#define CANIF_CANID_EXTENDED_CAN                            0x80000000u
#else
 /*! @brief Defines the mask value for the standarad CAN ID , if extended id not supported */
#define CANIF_CANID_MASK                                    0xC000u
 /*! @brief Defines the mask value for the CAN FD ID ,if extended id not supported */
#define CANIF_CANID_FD_CAN                                  0x4000u
 /*! @brief Defines the mask value for the Extended CAN ID ,if extended id not supported */
#define CANIF_CANID_EXTENDED_CAN                            0x8000u
#endif
/********************************************************************************************************************
*  PRIVATE TYPE DEFINITIONS                                                                                         *
********************************************************************************************************************/
/*! @brief Defines the search parameter type */
typedef struct
{
    /*! @brief Defines the start id of the RxPduId of the mailbox */
	CanIf_PduIdConfigIdType	RxStartPduId;
    /*! @brief Defines the end id of the RxPduId of the mailbox  */
	CanIf_PduIdConfigIdType RxEndPduId;
    /*! @brief Defines the Id of the received message */
	CanIf_PduIdConfigIdType	RcvdRxPduId;
    /*! @brief Defines the Id of the received message */
	Can_IdType 				RcvdCanId;
}CanIf_RxSearchParamType;
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

#define CANIF_START_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"

/* CanIf Module Init Status */
CANIF_LOCAL VAR(boolean,CANIF_VAR_INIT)  CanIf_InitStatus = FALSE;

#define CANIF_STOP_SEC_VAR_INIT_LOCAL_BOOLEAN
#include "MemMap.h"

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/

#define CANIF_START_SEC_CODE
#include "MemMap.h"

/*!******************************************************************************************************************
*   @brief      This method used to get the controller id for the Tx PduId
*   @param[in]  CanTxPduId  Tx Pdu Id.
*   @return     CanIf_ControllerIdType Returns the controller id of the Tx PduId
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerIdType,CANIF_CODE) CanIf_GetCtrlId(PduIdType CanTxPduId);
/*!******************************************************************************************************************
*   @brief      This method used to get the current controller mode
*   @param[in]  CtrlId  controller Id.
*   @return     CanIf_ControllerModeType Returns the controller mode
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerModeType,CANIF_CODE) CanIf_GetCurrentCtrlMode(CanIf_ControllerIdType CtrlId);
/*!******************************************************************************************************************
*   @brief      This method used to set the current controller mode
*   @param[in]  CtrlId  controller Id.
*   @param[in]  CtrlMode  controller mode to be set.
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UpdateCurrentCtrlMode
(
    CanIf_ControllerIdType CtrlId,
    CanIf_ControllerModeType CtrlMode
);
/*!******************************************************************************************************************
*   @brief      This method used to get the current Pdu mode
*   @param[in]  CtrlId  controller Id.
*   @return     CanIf_PduModeType Returns the Pdu mode
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_PduModeType,CANIF_CODE) CanIf_GetCurrentPduMode(CanIf_ControllerIdType CtrlId);
/*!******************************************************************************************************************
*   @brief      This method used to set the current Pdu mode
*   @param[in]  CtrlId  controller Id.
*   @param[in]  PduMode  pdu mode to be set.
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UpdateCurrentPduMode(CanIf_ControllerIdType CtrlId, CanIf_PduModeType PduMode);
/*!******************************************************************************************************************
*   @brief      This method used to set the Can controller mode
*   @param[in]  ControllerId  controller Id.
*   @param[in]  ControllerMode  controller mode to be set.
*   @return     Std_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetCanCtrlMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);
/*!******************************************************************************************************************
*   @brief      This method used initiate the transmit request 
*   @param[in]  CanIfTxSduId  Can Tx Sdu Id
*   @param[in]  CanIfTxInfoPtr  pointer to Pdu information 
*   @return     Can_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_ReturnType,CANIF_CODE) CanIf_InitiateTransfer
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
);
/*!******************************************************************************************************************
*   @brief      This method used to transmit the pdu 
*   @param[in]  CtrlId  controller Id
*   @param[in]  CanIfTxHandle  Can If HTH handle
*   @param[in]  PduInfo  pointer to Pdu information 
*   @return     Can_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_ReturnType,CANIF_CODE) CanIf_WritePdu
(
    CanIf_ControllerIdType CtrlId,
    Can_HwHandleType CanIfTxHandle,
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST) PduInfo
);
/*!******************************************************************************************************************
*   @brief      This method used to process the filtering of the received can id , SW filtering
*   @param[in]  Mailbox  Mailbox id
*   @param[in]  CanIfRxPduId  Can If HRH handle
*   @param[in]  PduInfo  pointer to Pdu information 
*   @return     boolean  TRUE if received CanId is valid , FALSE if received CanId is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_AcceptanceFilter
(
    P2CONST(Can_HwType,AUTOMATIC,CANIF_APPL_CONST) Mailbox,
    P2VAR(uint16,AUTOMATIC,CANIF_APPL_DATA) CanIfRxPduId
);
/*!******************************************************************************************************************
*   @brief      This method used to get the CanId of the Tx Sdu Id
*   @param[in]  CanIfTxSduId  the Tx Sdu Id
*   @return     Can_IdType returns the Can id
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_IdType,CANIF_CODE) CanIf_GetCanIdentifier(PduIdType CanIfTxSduId);
/*!******************************************************************************************************************
*   @brief      This method used to get the PduLength of the received Pdu
*   @param[in]  CanIfTxSduId  the Tx Sdu Id
*   @param[in]  CanIfTxInfoPtr  the pdu info
*   @return     PduLengthType returns the pdu length for the tx
********************************************************************************************************************/
CANIF_LOCAL FUNC(PduLengthType,CANIF_CODE) CanIf_GetPduLength
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
);
#if (CANIF_TRCV_HANDLING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method used to get the controller id mapped to the transceiver
*   @param[in]  TransceiverId  the transceiver id
*   @return     CanIf_ControllerIdType returns the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerIdType,CANIF_CODE) CanIf_GetTrcvCtrlId(uint8 TransceiverId);
#endif
#if (((CANIF_TRCV_HANDLING == STD_ON) || (CANIF_WAKEUP_SUPPORT == STD_ON)) && \
    (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON))
/*!******************************************************************************************************************
*   @brief      This method used to validate the controller id
*   @param[in]  CtrlId  the controller id
*   @param[in]  ApiId  the Api id which called for validation
*   @return     CanIf_ControllerIdType returns the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(Std_ReturnType,CANIF_CODE) CanIf_ValidateCtrlId(CanIf_ControllerIdType CtrlId, uint8 ApiId);
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method used to intialize the transmit buffers
*   @param[in]  ControllerId  the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_TxInitializeBuffer(uint8 ControllerId);
/*!******************************************************************************************************************
*   @brief      This method used to check if FIFO is empty
*   @param[in]  TxBufferFifoId  fifo id
*   @return     boolean return status , TRUE if fifo is empty . FALSE if fifo is not empty
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_TxCheckFifoEmpty(CanIf_TxBufferIdType TxBufferFifoId);
/*!******************************************************************************************************************
*   @brief      This method used to transmit the available message in the transmit buffer to the CanDriver
*   @param[in]  TxBufferId  Tx buffer id
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_TxBufferDispacth(CanIf_TxBufferIdType TxBufferId);
/*!******************************************************************************************************************
*   @brief      This method used to handle the transmit busy from the Can driver and store the message in buffer if
*               supported
*   @param[in]  CanHohId  Tx HOH id
*   @param[in]  pPduInfo  pointer to PduInfo
*   @return     Can_ReturnType  E_OK if the message stored in the buffer  
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_ReturnType,CANIF_CODE) CanIf_TxBusyResponseHandler
(
    Can_HwHandleType CanHohId,
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST) pPduInfo
);
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method used to intialize the receive buffer
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_InitializeRxBuffer(void);
#endif
#if ((CANIF_PUBLIC_TX_BUFFERING == STD_ON) || \
    (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)|| \
    (CANIF_META_DATA_TX_SUPPORT == STD_ON) || \
    (CANIF_META_DATA_RX_SUPPORT == STD_ON))
/*!******************************************************************************************************************
*   @brief      This method is used to byte copy
*   @param[in]  DestPtr pointer to destination buffer 
*   @param[in]  SrcPtr pointer to source buffer 
*   @param[in]  Length length to tbe copied
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UtilMemCpy
(
    P2VAR(uint8,AUTOMATIC,CANIF_APPL_DATA) DestPtr,
    CONSTP2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST) SrcPtr,
    PduLengthType Length
);
#endif
#if ((CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)|| (CANIF_META_DATA_RX_SUPPORT == STD_ON))
/*!******************************************************************************************************************
*   @brief      This method is used to initialize the buffer with init value
*   @param[in]  DestPtr pointer to destination buffer 
*   @param[in]  Value init value 
*   @param[in]  Length length to tbe set
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,CANIF_APPL_DATA) DestPtr,
    uint8 Value,
    PduLengthType Length
);
#endif
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
/*!******************************************************************************************************************
*   @brief      This method is used to report error to DET
*   @param[in]  ApiId Api Id 
*   @param[in]  ErrorId error id 
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_Det_ReportError(uint8 ApiId, uint8 ErrorId);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
/*!******************************************************************************************************************
*   @brief      This method is uses index search filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageIndexSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/*!******************************************************************************************************************
*   @brief      This method is uses double hash filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageDoubleHashSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
/*!******************************************************************************************************************
*   @brief      This method is uses binary filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageBinarySearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
);
#endif
#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
/*!******************************************************************************************************************
*   @brief      This method is uses linear filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageLinearSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
);
#endif
/*!******************************************************************************************************************
*   @brief      This method is used to get the CanId mask.
*   @param[in]  CanIf_RxCanIdMaskIdx mask index value 
*   @return     uint32 returns the mask status
********************************************************************************************************************/
CANIF_LOCAL FUNC(uint32,CANIF_CODE) CanIf_RxGetCanIdMask( CanIf_RxCanIdMaskIdxType CanIf_RxCanIdMaskIdx);

#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  PUBLIC FUNCTION IMPLEMENTATION                                                                                   *
********************************************************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*   @brief      This service Initializes internal and external interfaces of the CAN Interfacefor the further
*               processing
*   @param[in]  ConfigPtr  Pointer to configuration parameter set, used e.g. for post build parameters
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_Init(P2CONST(CanIf_ConfigType,AUTOMATIC,CANIF_APPL_CONST) ConfigPtr)
{
    CanIf_ControllerIdType ControllerId = 0U;
    CANIF_UNUSED_PARAMETER(ConfigPtr);
    #if ((CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON) || \
        (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON) || \
        (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON) || \
        (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON))
    PduIdType PduId;
    #endif
    #if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
    PduIdType DynamicPduId;
    #endif
    
    /* Update Module Init Status */
    CanIf_InitStatus = TRUE;
    /* Loop all the Configured Controller */
    for (ControllerId = 0U; ControllerId < CANIF_NUM_OF_CAN_CONTROLLERS; ControllerId++)
    {
        /* Initialize Controller mode */
        CanIf_CtrlInfo[ControllerId].CurrentCtrlMode = CANIF_CS_UNINIT;
        /* Initialize Pdu mode */
        CanIf_CtrlInfo[ControllerId].CurrentPduMode = CANIF_OFFLINE;
        #if ((CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON) && \
            (CANIF_WAKEUP_SUPPORT == STD_ON))
        CanIf_WakeupDetected[ControllerId] = FALSE;
        #endif
        #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
        CanIf_TxInitializeBuffer(ControllerId);
        #endif
    }
    #if ((CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON) || \
        (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON))
    /* Initialize Tx Confirmation Notify status */
    for (PduId = 0U; PduId < CANIF_NUM_OF_TX_PDU; PduId++)
    {
        /* Initialize Notify status */
        CanIf_TxNotifyStatus[PduId] = CANIF_NO_NOTIFICATION;
    }
    #endif
    #if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
    DynamicPduId = 0U;
    /* Initialize Dynamic Tx Pdu configuration status */
    for (PduId = 0U; PduId < CANIF_NUM_OF_TX_PDU; PduId++)
    {
        /* Check whether TxPduType is CANIF_TX_PDU_TYPE_DYNAMIC */
        if (CANIF_TX_PDU_TYPE_DYNAMIC == CanIf_TxPduIdConfig[PduId].TxPduType)
        {
            /* Check added to resolve coverity error */
            if (CANIF_NUM_OF_TX_DYNAMIC_PDU > DynamicPduId)
            {
                /* Get CanId */
                CanIf_DynamicPduConfig[DynamicPduId].CanId = CanIf_TxPduIdConfig[PduId].TxPduCanId;
                /* Get CanIfTxSduId */
                CanIf_DynamicPduConfig[DynamicPduId].CanIfTxSduId = PduId;
                /* Get ReconfiguredSts */
                CanIf_DynamicPduConfig[DynamicPduId].ReconfiguredSts = FALSE;
                /* Increment DynamicPduId */
                DynamicPduId++;
            }
        }
    }
    #endif
    #if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
    CanIf_InitializeRxBuffer();
    #endif
    #if (CANIF_META_DATA_RX_SUPPORT == STD_ON)
    CanIf_UtilMemSet(&CanIf_RxBufferWithMeta[0],0U,CANIF_CFG_RX_MAXVALIDRXDLC);
    #endif
    #if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
    /* Initialize Rx Confirmation Notify status */
    for (PduId = 0U; PduId < CANIF_NUM_OF_RX_PDU; PduId++)
    {
        /* Initialize Notify status */
        CanIf_RxNotifyStatus[PduId] = CANIF_NO_NOTIFICATION;
    }
    #endif
    
}
/********************************************************************************************************************
*   @brief      De-initializes the CanIf module.
*   @ServiceID  0x01
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant.
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_DeInit(void)
{
    CanIf_InitStatus = FALSE;
}
/********************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for changing of
*               the CAN controller mode.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested
*               for mode transition.
*   @param[in]  ControllerMode Requested mode transition
*   @return     Std_ReturnType E_OK: Controller mode request has been accepted
*               E_NOT_OK: Controller mode request has not been accepted
*   @ServiceID  0x03
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant (Not for the same controller).
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerModeType CurrentControllerMode;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if ((CANIF_CS_STARTED != ControllerMode) &&
            (CANIF_CS_SLEEP != ControllerMode) &&
            (CANIF_CS_STOPPED != ControllerMode))
    {
        ErrorId = CANIF_E_PARAM_CTRLMODE;
    }
#endif
    else
    {
        CurrentControllerMode = CanIf_GetCurrentCtrlMode(ControllerId);
        if ((ControllerMode == CANIF_CS_STARTED) && (CurrentControllerMode == CANIF_CS_STARTED))
        {
            /* Do nothing, Controller mode is already set to requested mode */
            RetVal = E_OK;
        }
        else
        {
            /* Set requested Controller Mode */
            RetVal = CanIf_SetCanCtrlMode(ControllerId, ControllerMode);
        }      
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETCONTROLLERMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for obtaining the 
*               current status of the CAN controller
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested 
*               for current operation mode.
*   @param[out] ControllerModePtr Pointer to a memory location, where the current mode of the CAN controller 
*               will be stored.
*   @return     Std_ReturnType E_OK: Controller mode request has been accepted
*               E_NOT_OK: Controller mode request has not been accepted
*   @ServiceID  0x04
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA) ControllerModePtr
)
{
    /* Local Variables */
    Std_ReturnType RetVal= E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if (NULL_PTR == ControllerModePtr)
    {
        ErrorId = CANIF_E_PARAM_CTRLMODE;
    }
#endif
    else
    {
        /* Get Current Ctrl Mode */
        *ControllerModePtr = CanIf_GetCurrentCtrlMode(ControllerId);
        RetVal = E_OK;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETCONTROLLERMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Requests transmission of a PDU.
*   @param[in]  TxPduId Identifier of the PDU to be transmitted
*   @param[out] PduInfoPtr Length of and pointer to the PDU data and pointer to MetaData.
*   @return     Std_ReturnType E_OK: Transmit request has been accepted. 
*               E_NOT_OK: Transmit request has not been accepted.
*   @ServiceID  0x049
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
)
{
    /* Local Variables */
    CanIf_PduModeType CanIfPduMode;
    Can_ReturnType CanIfTransferSts;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerModeType CanIfCtrlMode;
    CanIf_ControllerIdType CanIfCtrlId = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= CanIfTxSduId)
    {
        ErrorId = CANIF_E_INVALID_TXPDUID;
    }
    else if (NULL_PTR == CanIfTxInfoPtr)
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Controller Index */
        CanIfCtrlId = CanIf_GetCtrlId(CanIfTxSduId);
        /* Get Controller Mode */
        CanIfCtrlMode = CanIf_GetCurrentCtrlMode(CanIfCtrlId);
        /* Get Pdu Mode */
        CanIfPduMode = CanIf_GetCurrentPduMode(CanIfCtrlId);
        /* Check PduMode and CtrlMode of the requested controller */
        if (((CANIF_ONLINE == CanIfPduMode) || (CANIF_TX_OFFLINE_ACTIVE == CanIfPduMode)) &&
            (CANIF_CS_STARTED == CanIfCtrlMode))
        {
            /* Read Tx Pdu configuration */
            pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanIfTxSduId];
            /* Compare configured Pdu Length and requested Pdu Length */
            #if (CANIF_META_DATA_TX_SUPPORT == STD_ON)
            if ((pCanIfTxPduIdConfig -> TxPduLength + pCanIfTxPduIdConfig -> TxMetaDataLength) < (CanIfTxInfoPtr -> SduLength))
            #else
            if ((pCanIfTxPduIdConfig -> TxPduLength) < (CanIfTxInfoPtr -> SduLength))
            #endif
            {
                #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
                /* Exceeding the maximum length of the PDU referenced by CanIfTxSduId */
                ErrorId = CANIF_E_DATA_LENGTH_MISMATCH;
                #endif
            }
            /* Initiate Transfer request */
            CanIfTransferSts = CanIf_InitiateTransfer(CanIfTxSduId, CanIfTxInfoPtr);
            /* Write command has been accepted */
            if (CAN_OK == CanIfTransferSts)
            {
                RetVal = E_OK;
            }
        }
        #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
        else
        {
            /* ErrorId = CANIF_E_STOPPED */
        }
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_TRANSMIT_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service sets the requested mode at the L-PDUs of a predefined logical PDU channel.
*   @param[in]  ControllerId All PDUs of the own ECU connected to the corresponding CanIf ControllerId, which is 
*               assigned to a physical CAN controller are addressed.
*   @param[in]  PduModeRequest Requested PDU mode change 
*   @return     Std_ReturnType E_OK: Request for mode transition has been accepted.
*               E_NOT_OK: Request for mode transition has not been accepted.
*   @ServiceID  0x09
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType PduModeRequest)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    /* CanIf_ControllerModeType CanIfCtrlMode */

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if (CANIF_ONLINE < PduModeRequest)
    {
        ErrorId = CANIF_E_PARAM_PDU_MODE;
    }
#endif
    else
    {
        /* Get Current Ctrl Mode TODO Check and update*/
        /* CanIfCtrlMode = CanIf_GetCurrentCtrlMode(ControllerId); */
        /* if (CANIF_CS_STARTED == CanIfCtrlMode) */
        /* { */
            /* Update requested Pdu Mode */
            CanIf_UpdateCurrentPduMode(ControllerId, PduModeRequest);
            RetVal = E_OK;
        /* } */
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETPDUMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service reports the current mode of a requested PDU channel
*   @param[in]  ControllerId All PDUs of the own ECU connected to the corresponding CanIf ControllerId, which is 
*               assigned to a physical CAN controller are addressed
*   @param[out] PduModePtr Pointer to a memory location, where the current mode of the logical PDU channel will be 
*               stored.
*   @return     Std_ReturnType E_OK: PDU mode request has been accepted.
*               E_NOT_OK: PDU mode request has not been accepted
*   @ServiceID  0x0A
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (Not for the same channel)
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType,AUTOMATIC,CANIF_APPL_DATA) PduModePtr
)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if (NULL_PTR == PduModePtr)
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Current Pdu Mode */
        *PduModePtr = CanIf_GetCurrentPduMode(ControllerId);
        RetVal = E_OK;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETPDUMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#if (CANIF_VERSION_INFO_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service returns the version information of the called CAN Interface module.
*   @param[out] VersionInfo Pointer to where to store the version information of this module.
*   @ServiceID  0x0B
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,CANIF_APPL_DATA) VersionInfo
)
{
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
#endif

#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    /* Check if parameter VersionInfo is valid */
    if ( NULL_PTR == VersionInfo )
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
    else
#endif
    {
        VersionInfo->vendorID         = CANIF_VENDOR_ID;
        VersionInfo->moduleID         = CANIF_MODULE_ID;
        VersionInfo->sw_major_version = CANIF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANIF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANIF_SW_PATCH_VERSION;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
      CanIf_Det_ReportError(CANIF_GETVERSIONINFO_API, ErrorId);
    }
#endif
}
#endif
/********************************************************************************************************************
*   @brief      This service confirms a previously successfully processed transmission of a CAN TxPDU.
*   @param[in]  CanTxPduId L-PDU handle of CAN L-PDU successfully transmitted. This ID specifies the corresponding 
*               CAN L-PDU ID and implicitly the CAN Driver instance as well as the corresponding CAN controller device.
*   @ServiceID  0x13
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    /* Local Variables */
    CanIf_PduModeType CanIfPduMode;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    PduIdType CanIfUpperPduIdRef = 0U;
    CanIf_ControllerModeType CanIfCtrlMode;
    CanIf_ControllerIdType CanIfCtrlId = 0U;
    CanIf_TxConfirmationFunctIdType CanIfTxCallbackIndex = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    P2CONST(CanIf_TxConfirmationFunctType,AUTOMATIC,CANIF_APPL_CONST) pCanIf_TxConfirmationFunc;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= CanTxPduId)
    {
        ErrorId = CANIF_E_PARAM_LPDU;
    }
#endif
    else
    {
        /* Get Controller Index */
        CanIfCtrlId = CanIf_GetCtrlId(CanTxPduId);
        /* Get Controller Mode */
        CanIfCtrlMode = CanIf_GetCurrentCtrlMode(CanIfCtrlId);
        /* Get Pdu Mode */
        CanIfPduMode = CanIf_GetCurrentPduMode(CanIfCtrlId);
        if (((CANIF_ONLINE == CanIfPduMode) || (CANIF_TX_OFFLINE_ACTIVE == CanIfPduMode)) &&
            (CANIF_CS_UNINIT != CanIfCtrlMode))
        {
            /* Read Tx Pdu Configuration */
            pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanTxPduId];
            #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
            /* Get Tx Hth Index */
            if (CANIF_NUM_OF_MAILBOX >  pCanIfTxPduIdConfig -> TxPduHTHId)
            {
            	/* Process the buffer if any message is pending */
				CanIf_TxBufferDispacth(CanIf_MailBoxConfig[pCanIfTxPduIdConfig -> TxPduHTHId].TxBufferId);
            }
            #endif
            /* Get Tx confirmation function Index */
            CanIfTxCallbackIndex = pCanIfTxPduIdConfig -> TxConfirmationFunctId;
            /* Check whether call back function Index is valid */
            if (CANIF_NUM_OF_TX_CONFIRMATION_FUNCTION > CanIfTxCallbackIndex)
            {
                /* Get Upper module Pdu Reference */
                CanIfUpperPduIdRef = pCanIfTxPduIdConfig -> UpperPduId;
                /* Read Tx Confirmation function array */
                pCanIf_TxConfirmationFunc = &CanIf_TxConfirmationFunctConfig[CanIfTxCallbackIndex];
                /* Check Whether call back function is not equal to NULL_PTR */
                if (NULL_PTR != (*pCanIf_TxConfirmationFunc))
                {
                    /* Invoke Callback Function */
                    (*pCanIf_TxConfirmationFunc) (CanIfUpperPduIdRef,TRUE);
                }
                #if ((CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON) || \
                    (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON))
                /* Update Notify status */
                CanIf_TxNotifyStatus[CanTxPduId] = CANIF_TX_RX_NOTIFICATION;
                #endif
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_TXCONFIRMATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service indicates a successful reception of a received CAN Rx LPDU to the CanIf after passing 
*               all filters and validation checks
*   @param[in]  Mailbox Identifies the HRH and its corresponding CAN Controller
*   @param[in]  PduInfoPtr Pointer to the received L-PDU
*   @ServiceID  0x14
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType,AUTOMATIC,CANIF_APPL_CONST) Mailbox,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) PduInfoPtr
)
{
    /* Local Variables */
    PduIdType CanIfRxPduId = 0U;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    PduIdType CanIfUpperPduIdRef = 0U;
    CanIf_ControllerModeType CanIfCtrlMode;
    CanIf_ControllerIdType CanIfCtrlId = 0U;
    CanIf_RxNotificationFunctIdType CanIfRxCallbackIndex = 0U;
    P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfRxPduIdConfig;
    P2CONST(CanIf_RxNotificationFunctType,AUTOMATIC,CANIF_APPL_CONST) pCanIfRxIndicationFunc;
    PduInfoType CanIfPduInfo;
	#if(STD_ON == CANIF_META_DATA_RX_SUPPORT)
	Can_IdType RxCanId;
	PduLengthType	RxMetaIdx=0U;
	#endif

    /* Check CanIf Init status */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    /* Check function Input Pointers */
    else if ((NULL_PTR == Mailbox) || (NULL_PTR == PduInfoPtr))
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
    /* Check if parameter Hrh is valid */
    else if (CANIF_NUM_OF_MAILBOX <= Mailbox -> Hoh)
    {
        ErrorId = CANIF_E_PARAM_HOH;
    }
    /* Check if parameter CanDlc is valid */
    else if (CANIF_CFG_RX_MAXVALIDRXDLC < PduInfoPtr -> SduLength)
    {
        ErrorId = CANIF_E_INVALID_DLC;
    }
#endif
    else
    {
        /* Check whether Acceptance Filter is getting TRUE */
        if (TRUE == CanIf_AcceptanceFilter(Mailbox, &CanIfRxPduId))
        {
            /* Get Controller Index */
            CanIfCtrlId = CanIf_MailBoxConfig[Mailbox->Hoh].CanControllerId;
            /* Get Controller Mode */
            CanIfCtrlMode = CanIf_GetCurrentCtrlMode(CanIfCtrlId);
            /* Check whether Rx Indication is raised in Controller Active state */
            if (CANIF_CS_SLEEP != CanIfCtrlMode)
            {
                /* Check whether the PduId is valid */
                if (CANIF_NUM_OF_RX_PDU > CanIfRxPduId)
                {
                    /* Get Rx Pdu Configuration */
                    pCanIfRxPduIdConfig = &CanIf_RxPduIdConfig[CanIfRxPduId];
                    CanIfPduInfo.SduLength = PduInfoPtr->SduLength;
                    CanIfPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
                    #if(CANIF_PRIVATE_DLC_CHECK == STD_ON)
                    /* SWS_CANIF_00026 Accept frames which are received greater than or equal to the 
                    configured length */
                    if(PduInfoPtr -> SduLength < pCanIfRxPduIdConfig->RxPduDlc)
                    {
                        ErrorId = CANIF_E_INVALID_DLC;
                    }
                    #endif
                    #if(STD_ON == CANIF_META_DATA_RX_SUPPORT)
                    if ((pCanIfRxPduIdConfig->RxMetaDataLength > 0u) 
                        #if(CANIF_PRIVATE_DLC_CHECK == STD_ON)
                        && (CANIF_E_NO_ERROR == ErrorId) 
                        #endif
                        )
                    {
                        if ((PduLengthType)CANIF_CFG_RX_MAXVALIDRXDLC >= 
                            (PduInfoPtr->SduLength + pCanIfRxPduIdConfig->RxMetaDataLength))
                        {
                            /* Update CanId in the meta data position */
                            RxCanId = ((Mailbox -> CanId) & (~CANIF_CANID_MASK));
                            for(RxMetaIdx=PduInfoPtr -> SduLength;
                                ((RxMetaIdx<(PduInfoPtr -> SduLength+pCanIfRxPduIdConfig->RxMetaDataLength)) &&
                                 (RxMetaIdx< CANIF_CFG_RX_MAXVALIDRXDLC));RxMetaIdx++)
                            {
                                CanIf_RxBufferWithMeta[RxMetaIdx] = (uint8)(RxCanId & 0xFFU);
                                RxCanId = RxCanId >> 8u;
                            }
                            /* Copy msg data */
                            CanIf_UtilMemCpy(&CanIf_RxBufferWithMeta[0],PduInfoPtr->SduDataPtr,PduInfoPtr->SduLength);
                            /* update the infoptr with meta data length */
                            CanIfPduInfo.SduLength = PduInfoPtr->SduLength+pCanIfRxPduIdConfig->RxMetaDataLength;
                            CanIfPduInfo.SduDataPtr = &CanIf_RxBufferWithMeta[0];
                        }
                        else
                        {
                            ErrorId = CANIF_E_DATA_LENGTH_MISMATCH;
                        }
                    }
                    #endif
                    #if((STD_ON == CANIF_PRIVATE_DLC_CHECK ) || (STD_ON == CANIF_META_DATA_RX_SUPPORT))
					if(CANIF_E_NO_ERROR == ErrorId)
					#endif
					{
                        /* Get Index for Rx Call back function */
                        CanIfRxCallbackIndex = pCanIfRxPduIdConfig -> RxNotificationFunctId;
                        /* Check Whether Rx Indication call back Index is valid */
                        if (CANIF_NUM_OF_RX_NOTIFICATION_FUNCTION > CanIfRxCallbackIndex)
                        {
                            /* Get Upper module Pdu Ref Id */
                            CanIfUpperPduIdRef = pCanIfRxPduIdConfig -> UpperPduId;
                            /* Get Rx Call back config Array */
                            pCanIfRxIndicationFunc = &CanIf_RxNotificationFunctConfig[CanIfRxCallbackIndex];
                            /* Check Whether call back function is not equal to NULL_PTR */
                            if (NULL_PTR != (*pCanIfRxIndicationFunc))
                            {
                                /* Invoke Rx Indication API */
                                (*pCanIfRxIndicationFunc) (CanIfUpperPduIdRef, &CanIfPduInfo);
                            }
                            #if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
                            /* Update Notify status */
                            CanIf_RxNotifyStatus[CanIfRxPduId] = CANIF_TX_RX_NOTIFICATION;
                            #endif
                        }
                        #if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
                        if (CANIF_MAX_RX_BUFFER_SIZE <= CanIf_RxBufferIndex)
                        {
                            /* Reset Buffer Index */
                            CanIf_RxBufferIndex = 0;
                        }
                        /* Enter Critical section */
                        CanIf_EnterCriticalSection();
                        /* Copy Pdu Id */
                        CanIf_RxBuffer[CanIf_RxBufferIndex].CanIfRxPduId = CanIfRxPduId;
                        /* Copy Sdu Length */
                        CanIf_RxBuffer[CanIf_RxBufferIndex].CanIfSduLength = PduInfoPtr -> SduLength;
                        /* Copy SduDataPtr */
                        CanIf_UtilMemCpy((CanIf_RxBuffer[CanIf_RxBufferIndex].CanIfRxPduBuffer), 
                                        (PduInfoPtr -> SduDataPtr), (PduInfoPtr -> SduLength));
                        /* Exit Critical section */
                        CanIf_ExitCriticalSection();
                        /* Increment Buffer Index */
                        CanIf_RxBufferIndex++;
                        #endif
                    }/* (CANIF_E_NO_ERROR == ErrorId) */
                }/*(CANIF_NUM_OF_RX_PDU > CanIfRxPduId) */
            }/* (CANIF_CS_SLEEP != CanIfCtrlMode) */
            /* Indication given due to wakeup message, Validate wakeup if enabled */
            #if ((CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON) && \
                 (CANIF_WAKEUP_SUPPORT == STD_ON))
            else
            {
                /* Only NM messages are considered for wakeup */
                #if (CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM == STD_ON)
                /* Check whether NM message is received */
                if (CANIF_NM_RX_PDUID == CanIfRxPduId)
                {
                    /* Rx PduId is matching with NM message */
                    CanIf_WakeupDetected[CanIfCtrlId] = TRUE;
                }
                #else
                /* All Can messages are considered for wakeup */
                CanIf_WakeupDetected[CanIfCtrlId] = TRUE;
                #endif
            }
            #endif
        }
        #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
        else
        {
            /* Report invalid value to DET */
            /* ErrorId = CANIF_E_PARAM_CANID */
        }
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_RXINDICATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service indicates a Controller BusOff event referring to the corresponding CAN Controller with 
*               the abstract CanIf ControllerId
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, where a BusOff 
*               occured
*   @ServiceID  0x16
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId)
{
    uint8 ErrorId = CANIF_E_NO_ERROR;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
#endif
    else
    {
        /* Check If Current Ctrl Mode is CANIF_CS_UNINIT */
        if (CANIF_CS_UNINIT != CanIf_GetCurrentCtrlMode(ControllerId))
        {
            /* Initialize PDU mode */
            (void) CanIf_SetPduMode(ControllerId, CANIF_TX_OFFLINE);
            /* Initialize controller mode */
            (void) CanIf_SetControllerMode(ControllerId, CANIF_CS_STOPPED);
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
            CanIf_TxInitializeBuffer(ControllerId);
#endif
            /* Get User Callback Configuration */
            pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
            /* Check Whether Bus off function pointer is not equal to NULL_PTR */
            if (NULL_PTR != (pCanIfUserCallbackConfig -> UserControllerBusOffFunctPtr))
            {
                /* Notify Bus off event to CanSM */
                (*(pCanIfUserCallbackConfig -> UserControllerBusOffFunctPtr)) (ControllerId);
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CONTROLLERBUSOFF_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service indicates a controller state transition referring to the corresponding CAN controller
*               with the abstract CanIf ControllerId.
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, which state has
*               been transitioned.
*   @param[in]  ControllerMode Mode to which the CAN controller transitioned
*   @ServiceID  0x17
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    uint8 ErrorId = CANIF_E_NO_ERROR;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
#endif
    else
    {
        /* Check whether Current Ctrl Mode is CANIF_CS_UNINIT */
        if ((CANIF_CS_UNINIT != CanIf_GetCurrentCtrlMode(ControllerId)) &&
            (CANIF_CS_SLEEP >= ControllerMode))
        {
            /* Update Current Ctrl Mode */
            CanIf_UpdateCurrentCtrlMode(ControllerId, ControllerMode);
            /* Get User Callback Configuration */
            pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
            /* Check Whether Mode Indication function pointer is not equal to NULL_PTR */
            if (NULL_PTR != (pCanIfUserCallbackConfig -> UserControllerModeIndicationFunctPtr))
            {
                /* Notify Controller Mode change to CanSM */
                (*(pCanIfUserCallbackConfig -> UserControllerModeIndicationFunctPtr)) (ControllerId, ControllerMode);
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CONTROLLERMODEINDICATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#if (CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Requests cancellation of an ongoing transmission of a PDU in a lower layer communication module
*   @param[in]  TxPduId Identification of the PDU to be cancelled.
*   @return     Std_ReturnType E_OK: Cancellation was executed successfully by the destination module.
*               E_NOT_OK: Cancellation was rejected by the destination module.
*   @ServiceID  0x04a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId.
********************************************************************************************************************/
FUNC(Std_ReturnType,CANIF_CODE) CanIf_CancelTransmit(PduIdType TxPduId)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;

    CANIF_UNUSED_PARAMETER(TxPduId);
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= TxPduId)
    {
        ErrorId = CANIF_E_INVALID_TXPDUID;
    }
#endif
    else
    {
        /* The service CanIf_CancelTransmit() has no functionality and is called by
            the AUTOSAR PduR to achieve bus diagnostic behavior. */
        RetVal = E_OK;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CANCELTRANSMIT_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service provides the Data Length and the received data of the requested CanIfRxSduId to the 
*               calling upper layer.
*   @param[in]  CanIfRxSduId Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the 
*               CAN Driver instance as well as the corresponding CAN controller device.
*   @param[out] CanIfRxInfoPtr Contains the length (SduLength) of the received PDU, a pointer to a buffer (SduDataPtr) 
*               containing the PDU, and the MetaData related to this PDU.
*   @return     Std_ReturnType E_OK: Request for L-SDU data has been accepted
*               E_NOT_OK: No valid data has been received
*   @ServiceID  0x06
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanIfRxSduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) CanIfRxInfoPtr
)
{
    /* Local Variables */
    uint8 BufferIndex = 0U;
    CanIf_ControllerIdType CanIfCtrlId;
    CanIf_ControllerModeType CanIfCtrlMode;
    CanIf_PduModeType CanIfPduMode;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_RX_PDU <= CanIfRxSduId)
    {
        ErrorId = CANIF_E_INVALID_RXPDUID;
    }
    else if (NULL_PTR == CanIfRxInfoPtr)
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Controller Index */
        CanIfCtrlId = CanIf_GetCtrlId(CanIfRxSduId);
        /* Get Controller Mode */
        CanIfCtrlMode = CanIf_GetCurrentCtrlMode(CanIfCtrlId);
        /* Get Pdu Mode */
        CanIfPduMode = CanIf_GetCurrentPduMode(CanIfCtrlId);
        /* Check PduMode and CtrlMode of the requested controller */
        if ((CANIF_ONLINE == CanIfPduMode) && (CANIF_CS_STARTED == CanIfCtrlMode))
        {
            for (BufferIndex = 0; BufferIndex < CANIF_MAX_RX_BUFFER_SIZE; BufferIndex++)
            {
                if (CanIf_RxBuffer[BufferIndex].CanIfRxPduId == CanIfRxSduId)
                {
                    /* Enter Critical section */
                    CanIf_EnterCriticalSection();
                    /* Get Received Data Length Code for this Pdu */
                    CanIfRxInfoPtr -> SduLength = CanIf_RxBuffer[BufferIndex].CanIfSduLength;
                    /* Get Received Sdu data for this Pdu */
                    CanIf_UtilMemCpy((CanIfRxInfoPtr ->SduDataPtr), (CanIf_RxBuffer[BufferIndex].CanIfRxPduBuffer),
                                    (CanIf_RxBuffer[BufferIndex].CanIfSduLength));
                    /* Exit Critical section */
                    CanIf_ExitCriticalSection();
                    /* Update return value */
                    RetVal = E_OK;
                    break;
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_READRXPDUDATA_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service returns the confirmation status (confirmation occurred or not) of a specific static or 
*               dynamic CAN Tx L-PDU, requested by the CanIfTxSduId.
*   @param[in]  CanIfTxSduId L-SDU handle to be transmitted. This handle specifies the corresponding CAN LSDU ID and 
*               implicitly the CAN Driver instance as well as the corresponding CAN controller device
*   @return     CanIf_NotifStatusType Current confirmation status of the corresponding CAN Tx L-PDU.
*   @ServiceID  0x07
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId)
{
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_NotifStatusType NotifyStatus = CANIF_NO_NOTIFICATION;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= CanIfTxSduId)
    {
        /* out of range or no status information was configured for this CAN Tx L-SDU */
        ErrorId = CANIF_E_INVALID_TXPDUID;
    }
#endif
    else
    {
        /* Get the Tx Notify status */
        NotifyStatus = CanIf_TxNotifyStatus[CanIfTxSduId];
        #if (CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API == STD_ON)
        /* Reset Notify status */
        CanIf_TxNotifyStatus[CanIfTxSduId] = CANIF_NO_NOTIFICATION;
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_READTXNOTIFSTATUS_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return NotifyStatus;
}
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service returns the indication status (indication occurred or not) of a
*               specific CAN Rx L-PDU, requested by the CanIfRxSduId.
*   @param[in]  CanIfRxSduId Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the CAN 
*               Driver instance as well as the corresponding CAN controller device.
*   @return     CanIf_NotifStatusType Current indication status of the corresponding CAN Rx L-PDU.
*   @ServiceID  0x08
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId)
{
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_NotifStatusType NotifyStatus = CANIF_NO_NOTIFICATION;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_RX_PDU <= CanIfRxSduId)
    {
        /* out of range or no status information was configured for this CAN Tx L-SDU */
        ErrorId = CANIF_E_INVALID_RXPDUID;
    }
#endif
    else
    {
        /* Get the Tx Notify status */
        NotifyStatus = CanIf_RxNotifyStatus[CanIfRxSduId];
        #if (CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API == STD_ON)
        /* Reset Notify status */
        CanIf_RxNotifyStatus[CanIfRxSduId] = CANIF_NO_NOTIFICATION;
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_READRXNOTIFSTATUS_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return NotifyStatus;
}
#endif
#if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU.
*   @param[in]  CanIfTxSduId L-SDU handle to be transmitted. This handle specifies the corresponding CAN LSDU
*               ID and implicitly the CAN Driver instance as well as the corresponding CAN controller device
*   @param[in]  CanId Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD or conventional 
*               CAN frame.
*   @ServiceID  0x0C
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanIfTxSduId, Can_IdType CanId)
{
	uint32 TxCanIdMask=0U;
    PduIdType DynamicPduId = 0U;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_MailBoxConfigIdType CanIfTxPduHTHId = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    P2CONST(CanIf_MailBoxConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfMailBoxConfig;

    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= CanIfTxSduId)
    {
        ErrorId = CANIF_E_INVALID_TXPDUID;
    }
#endif
    else
    {
        /* Read Tx Pdu configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanIfTxSduId];
        /* Check whether the requested Pdu is configured as DYNAMIC PDU */
        if (CANIF_TX_PDU_TYPE_DYNAMIC == pCanIfTxPduIdConfig -> TxPduType)
        {
            /* Get TxPduHTHId */
            CanIfTxPduHTHId = pCanIfTxPduIdConfig -> TxPduHTHId;
            /* Check added to resolve coverity error */
            if ((CANIF_NUM_OF_TX_PDU > CanIfTxPduHTHId) &&
				(CANIF_NUM_OF_TX_CAN_ID_MASKS > pCanIfTxPduIdConfig->TxCanIdMaskIdx))
            {
				TxCanIdMask = CanIf_TxCanIdMaskConfig[pCanIfTxPduIdConfig->TxCanIdMaskIdx];
                /* Read Mailbox Configuration */
                pCanIfMailBoxConfig = &CanIf_MailBoxConfig[CanIfTxPduHTHId];
                /* Check whether Can Id is valid */
                if (((CANIF_CANID_TYPE_STANDARD == pCanIfMailBoxConfig -> CanIdType) && (CANIF_STD_CAN_ID_MAX_VAL >= CanId)) ||
                ((CANIF_CANID_TYPE_EXTENDED == pCanIfMailBoxConfig -> CanIdType) && (CANIF_STD_EXT_ID_MAXVAL >= CanId)))
                {
                    /* Check whether the requested CanIfTxSduId is valid */
                    for (DynamicPduId = 0; DynamicPduId < CANIF_NUM_OF_TX_DYNAMIC_PDU; DynamicPduId++)
                    {
                        /* Check whether requested CanId is equal to stored CanId */
                        if (CanIfTxSduId == CanIf_DynamicPduConfig[DynamicPduId].CanIfTxSduId)
                        {
                            /* Update CanIf_DynamicPduConfig CanId */
                            CanIf_DynamicPduConfig[DynamicPduId].CanId = (CanId & TxCanIdMask);
                            /* Update CanIf_DynamicPduConfig ReconfiguredSts */
                            CanIf_DynamicPduConfig[DynamicPduId].ReconfiguredSts = TRUE;
                        }
                    }
                }
                #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
                else
                {
                    /* Invalid Can Id */
                    ErrorId = CANIF_E_PARAM_CANID;
                }
                #endif
            }
        }
        #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
        else
        {
            /* Invalid request */
            ErrorId = CANIF_E_INVALID_TXPDUID;
        }
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETDYNAMICTXID_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
#if (CANIF_TRCV_HANDLING == STD_ON)
/********************************************************************************************************************
*   @brief      This service changes the operation mode of the tansceiver TransceiverId, via calling the 
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver, which is 
*               requested for mode transition
*   @param[in]  TransceiverMode Requested mode transition
*   @return     Std_ReturnType E_OK: Transceiver mode request has been accepted.
*               E_NOT_OK: Transceiver mode request has not been accepted.
*   @ServiceID  0x0D
*   @Sync/Async Asynchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        /* Module is not Initialized */
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
    else if ((CANTRCV_TRCVMODE_NORMAL != TransceiverMode) &&
             (CANTRCV_TRCVMODE_STANDBY != TransceiverMode) &&
             (CANTRCV_TRCVMODE_SLEEP != TransceiverMode))
    {
        /* TransceiverMode has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCVMODE;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_SETTRCVMODE_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvSetOpModeFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvSetOpModeFunctPtr)
                {
                    /* Set requested TRCV mode */
                    RetVal = (*(pCanIfTrcvDrvFunctConfig -> CanTrcvSetOpModeFunctPtr)) (TransceiverId, TransceiverMode);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETTRCVMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service changes the operation mode of the tansceiver TransceiverId, via calling the 
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is requested for current operation mode
*   @param[out] TransceiverModePtr Requested mode of requested network the Transceiver is connected to
*   @return     Std_ReturnType E_OK: Transceiver mode request has been accepted.
*               E_NOT_OK: Transceiver mode request has not been accepted.
*   @ServiceID  0x0E
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    P2VAR(CanTrcv_TrcvModeType,AUTOMATIC,CANIF_APPL_DATA) TransceiverModePtr,
    uint8 TransceiverId
)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
    else if (NULL_PTR == TransceiverModePtr)
    {
        /* TransceiverMode has an invalid value */
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_GETTRCVMODE_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvGetOpModeFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvGetOpModeFunctPtr)
                {
                    /* Get TRCV mode */
                    RetVal = (*(pCanIfTrcvDrvFunctConfig->CanTrcvGetOpModeFunctPtr))(TransceiverId,TransceiverModePtr);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETTRCVMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service returns the reason for the wake up of the transceiver TransceiverId, via calling the
*               corresponding CAN Transceiver Driver service
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId, which is assigned to a CAN transceiver, which is 
*               requested for wake up reason.
*   @param[out] TrcvWuReasonPtr provided pointer to where the requested transceiver wake up reason shall be returned
*   @return     Std_ReturnType E_OK: Transceiver wake up reason request has been accepted.
*               E_NOT_OK: Transceiver wake up reason request has not been accepted.
*   @ServiceID  0x0F
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA) TrcvWuReasonPtr
)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
    else if (NULL_PTR == TrcvWuReasonPtr)
    {
        /* TransceiverMode has an invalid value */
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_GETTRCVWAKEUPREASON_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvGetBusWuReasonFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvGetBusWuReasonFunctPtr)
                {
                    /* Get TRCV wakeup Reason */
                    RetVal=(*(pCanIfTrcvDrvFunctConfig->CanTrcvGetBusWuReasonFunctPtr))(TransceiverId,TrcvWuReasonPtr);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETTRCVWAKEUPREASON_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This function shall call CanTrcv_SetTrcvWakeupMode.
*   @param[in]  TransceiverId Abstracted CanIf TransceiverId,which is requested for wake up notification mode
*               transition.
*   @param[in]  TrcvWakeupMode Requested transceiver wake up notification mode
*   @return     Std_ReturnType E_OK: Will be returned, if the wake up notifications state has been changed to the
*               requested mode. E_NOT_OK: Will be returned, if the wake up notifications state change has failed 
*               or the parameter is out of the allowed range. The previous state has not been changed.
*   @ServiceID  0x10
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
    else if ((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode) &&
            (CANTRCV_WUMODE_CLEAR != TrcvWakeupMode))
    {
        /* TransceiverMode has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCVWAKEUPMODE;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_SETTRCVWAKEUPMODE_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvSetWakeupModeFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvSetWakeupModeFunctPtr)
                {
                    /* Set requested TRCV wakeup mode */
                    RetVal = (*(pCanIfTrcvDrvFunctConfig->CanTrcvSetWakeupModeFunctPtr))(TransceiverId,TrcvWakeupMode);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETTRCVWAKEUPMODE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANIF_PUBLIC_PN_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service indicates that the transceiver is running in PN communication mode referring to the 
*               corresponding CAN transceiver with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, which was 
*               checked for PN availability.
*   @ServiceID  0x1a
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_CONFIRMPNAVAILABILITY_API))
            #endif
            {
                /* Get User Call back configuration */
                pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
                /* Check whether UserConfirmPnAvailabilityFunctPtr is valid */
                if (NULL_PTR != pCanIfUserCallbackConfig -> UserConfirmPnAvailabilityFunctPtr)
                {
                    /* Invoke user Indication Call back */
                    (*(pCanIfUserCallbackConfig -> UserConfirmPnAvailabilityFunctPtr)) (TrcvCtrlId);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CONFIRMPNAVAILABILITY_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Requests the CanIf module to clear the WUF flag of the designated CAN transceiver.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver
*   @return     Std_ReturnType E_OK: Request has been accepted E_NOT_OK: Request has not been accepted
*   @ServiceID  0x1E
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different CAN transceivers
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_CLEARTRCVWUFFLAG_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvClearTrcvWufFlagFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvClearTrcvWufFlagFunctPtr)
                {
                    /* Clear Trcv WUF Flag*/
                    RetVal = (*(pCanIfTrcvDrvFunctConfig -> CanTrcvClearTrcvWufFlagFunctPtr)) (TransceiverId);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CLEARTRCVWUFFLAG_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      Requests the CanIf module to check the Wake flag of the designated CAN transceiver.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver
*   @return     Std_ReturnType E_OK: Request has been accepted E_NOT_OK: Request has not been accepted
*   @ServiceID  0x1F
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant for different CAN transceivers
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckTrcvWakeFlag(uint8 TransceiverId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvDrvFunctConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_CHECKTRCVWAKEFLAG_API))
            #endif
            {
                /* Get TRCV Configuration Pointer */
                pCanIfTrcvDrvFunctConfig = &CanIf_CanTrcvFunctConfig[TrcvCtrlId];
                /* Check whether TRCV CanTrcvCheckTrcvWakeFlagFunctPtr is valid */
                if (NULL_PTR != pCanIfTrcvDrvFunctConfig -> CanTrcvCheckTrcvWakeFlagFunctPtr)
                {
                    /* Check TRCV WUF Flag */
                    RetVal = (*(pCanIfTrcvDrvFunctConfig -> CanTrcvCheckTrcvWakeFlagFunctPtr)) (TransceiverId);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CHECKTRCVWAKEFLAG_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This service indicates that the transceiver has cleared the WufFlag referring to the corresponding 
*               CAN transceiver with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, for which 
*               this function was called
*   @ServiceID  0x20
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_CLEARTRCVWUFFLAGINDICATION_API))
            #endif
            {
                /* Get User Call back configuration */
                pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
                /* Check UserClearTrcvWufFlagIndicationFunctPtr is not null */
                if (NULL_PTR != pCanIfUserCallbackConfig -> UserClearTrcvWufFlagIndicationFunctPtr)
                {
                    /* Invoke user Indication Call back */
                    (*(pCanIfUserCallbackConfig -> UserClearTrcvWufFlagIndicationFunctPtr)) (TrcvCtrlId);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CLEARTRCVWUFFLAGINDICATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
/********************************************************************************************************************
*   @brief      This service indicates that the check of the transceiver’s wake-up flag has been finished by the 
*               corresponding CAN transceiver with the abstract CanIf TransceiverId. This indication is used to cope
*               with the asynchronous transceiver communication
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, for which 
*               this function was called
*   @ServiceID  0x21
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_CHECKTRCVWAKEFLAGINDICATION_API))
            #endif
            {
                /* Get User Call back configuration */
                pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
                /* Check UserCheckTrcvWakeFlagIndicationFunctPtr is not null */
                if (NULL_PTR != pCanIfUserCallbackConfig -> UserCheckTrcvWakeFlagIndicationFunctPtr)
                {
                    /* Invoke user Indication Call back */
                    (*(pCanIfUserCallbackConfig -> UserCheckTrcvWakeFlagIndicationFunctPtr)) (TrcvCtrlId);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CHECKTRCVWAKEFLAGINDICATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
#endif
/********************************************************************************************************************
*   @brief      This service indicates a transceiver state transition referring to the corresponding CAN transceiver 
*               with the abstract CanIf TransceiverId.
*   @param[in]  TransceiverId Abstract CanIf TransceiverId, which is assigned to a CAN transceiver, which state has 
*               been transitioned.
*   @param[in]  TransceiverMode Mode to which the CAN transceiver transitioned
*   @ServiceID  0x22
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_TRANSCEIVERS < TransceiverId)
    {
        /* TransceiverId has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCV;
    }
    else if ((CANTRCV_TRCVMODE_NORMAL != TransceiverMode) &&
             (CANTRCV_TRCVMODE_STANDBY != TransceiverMode) &&
             (CANTRCV_TRCVMODE_SLEEP != TransceiverMode))
    {
        /* TransceiverMode has an invalid value */
        ErrorId = CANIF_E_PARAM_TRCVMODE;
    }
#endif
    else
    {
        /* Get TRCV Ctrl Id */
        TrcvCtrlId = CanIf_GetTrcvCtrlId(TransceiverId);
        /* Check whether requested TRCV id is valid */
        if (CANIF_NO_CAN_TRANSCEIVER_ID != TrcvCtrlId)
        {
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Check whether Ctrl Id is valid */
            if (E_OK == CanIf_ValidateCtrlId(TrcvCtrlId, CANIF_TRCVMODEINDICATION_API))
            #endif
            {
                /* Get User Call back configuration */
                pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
                /* Check UserTrcvModeIndicationFunctPtr is not null */
                if (NULL_PTR != pCanIfUserCallbackConfig -> UserTrcvModeIndicationFunctPtr)
                {
                    /* Invoke user Indication Call back */
                    (*(pCanIfUserCallbackConfig -> UserTrcvModeIndicationFunctPtr)) (TrcvCtrlId, TransceiverMode);
                }
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_TRCVMODEINDICATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif
#if (CANIF_WAKEUP_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service checks, whether an underlying CAN driver or a CAN transceiver driver already signals a 
*               wakeup event.
*   @param[in]  WakeupSource Source device, which initiated the wake up event: CAN controller or CAN transceiver
*   @return     Std_ReturnType E_OK: Will be returned, if the check wake up request has been accepted
*               E_NOT_OK: Will be returned, if the check wake up request has not been accepted
*   @ServiceID  0x11
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)

{
    /* Local Variables */
#if (CANIF_TRCV_HANDLING == STD_ON)
    uint8 TrcvIndex = 0U;
    CanIf_ControllerIdType TrcvCtrlId = 0U;
    P2CONST(CanIf_TrcvDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTrcvFuncConfig;
#endif
    uint8 CanDrvFunctIndex = 0U;
    uint8 WakeupSrcIndex = 0U;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    boolean WakeupSrcIndentified = FALSE;
    P2CONST(CanIf_WakeUpConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfWakeupConfig;
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
    else
    {
        /* Validate all the Wakeup sources */
        for (WakeupSrcIndex = 0; WakeupSrcIndex < CANIF_CFG_MAX_WAKEUPSOURCES; WakeupSrcIndex++)
        {
            /* Get Wakeup configuration related to wakeup source */
            pCanIfWakeupConfig = &CanIf_WakeUpConfig[WakeupSrcIndex];
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Validate Ctrl Id */
            if (E_OK == CanIf_ValidateCtrlId((pCanIfWakeupConfig -> WakeupCtrlId), CANIF_CHECKWAKEUP_API))
            #endif
            {
                /* Check whether requested wakeup source Id is matching with configured src Id */
                if ((pCanIfWakeupConfig -> WakeupSrcId) == WakeupSource)
                {
                    /* Requested wakeup source is valid */
                    WakeupSrcIndentified = TRUE;
                    /* Check whether the requested Ctrl mode is in Sleep state */
                    if (CANIF_CS_SLEEP == CanIf_GetCurrentCtrlMode(pCanIfWakeupConfig -> WakeupCtrlId))
                    {
                        /* Check whether the target Module is Can */
                        if (CANIF_WAKEUPREQUEST_CAN == (pCanIfWakeupConfig -> WakeupTargetModuleConfig))
                        {
                            /* Get Can Driver Function Mapping Index */
                            CanDrvFunctIndex = CanIf_CtrlIdtoCanDrvFunctMapConfig[(pCanIfWakeupConfig -> WakeupCtrlId)].CanDrvFunctId;
                            /* Check added to resolve coverity error */
                            if (CANIF_NUM_OF_CAN_DRIVERS > CanDrvFunctIndex)
                            {
                                /* Get Can Controller Function Index*/
                                pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanDrvFunctIndex];
                                /* Check whether CanDrvCheckWakeupFunctPtr is not NULL_PTR */
                                if (NULL_PTR != pCanIfCanDrvFuncConfig -> CanDrvCheckWakeupFunctPtr)
                                {
                                    /* Invoke CAN Check Wakeup API */
                                    RetVal = (*(pCanIfCanDrvFuncConfig -> CanDrvCheckWakeupFunctPtr))((pCanIfWakeupConfig -> WakeupCtrlId));
                                }
                            }
                        }
                        #if (CANIF_TRCV_HANDLING == STD_ON)
                        /* Check whether the target Module is TRCV */
                        else if (CANIF_WAKEUPREQUEST_TRCV == (pCanIfWakeupConfig -> WakeupTargetModuleConfig))
                        {
                            /* Check the TRCV is associated with which ctrl */
                            for (TrcvIndex = 0; TrcvIndex < CANIF_NUM_OF_TRANSCEIVER_DRIVERS; TrcvIndex++)
                            {
                                /* Get TRCV Ctrl Id */
                                TrcvCtrlId = CanIf_GetTrcvCtrlId(TrcvIndex);
                                /* Check the ctrl Id is equal to requested ctrl Id */
                                if (TrcvCtrlId == (pCanIfWakeupConfig -> WakeupCtrlId))
                                {
                                    /* Get Trcv Function configuration */
                                    pCanIfTrcvFuncConfig = &CanIf_CanTrcvFunctConfig[TrcvIndex];
                                    /* check whether CanTrcvCheckWakeupFunctPtr is not NULL_PTR */
                                    if (NULL_PTR != pCanIfTrcvFuncConfig -> CanTrcvCheckWakeupFunctPtr)
                                    {
                                        /* Invoke CanTrcv check Wakeup API */
                                        RetVal = (*(pCanIfTrcvFuncConfig -> CanTrcvCheckWakeupFunctPtr))((pCanIfWakeupConfig -> WakeupCtrlId));
                                    }
                                }
                            }
                        }
                        #endif
                        else
                        {
                            /* do nothing */
                        }
                    }
                }
            }
        }
        #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
        if (FALSE == WakeupSrcIndentified)
        {
            /* Requested wakeup source is Invalid */
            ErrorId = CANIF_E_PARAM_WAKEUPSOURCE;
        }
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CHECKWAKEUP_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#if (CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service is performed to validate a previous wakeup event.
*   @param[in]  WakeupSource Source device which initiated the wake-up event and which has to be validated: CAN 
*               controller or CAN transceiver
*   @return     Std_ReturnType E_OK: Will be returned, if the check validation request has been accepted.
*               E_NOT_OK: Will be returned, if the check validation request has not been accepted.
*   @ServiceID  0x12
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource)
{
    /* Local Variables */
    uint8 WakeupSrcIndex = 0U;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    boolean WakeupSrcIndentified = FALSE;
    P2CONST(CanIf_WakeUpConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfWakeupConfig;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
    else
    {
        /* Validate all the Wakeup sources */
        for (WakeupSrcIndex = 0; WakeupSrcIndex < CANIF_CFG_MAX_WAKEUPSOURCES; WakeupSrcIndex++)
        {
            /* Get Wakeup configuration related to wakeup source */
            pCanIfWakeupConfig = &CanIf_WakeUpConfig[WakeupSrcIndex];
            #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
            /* Validate Ctrl Id */
            if (E_OK == CanIf_ValidateCtrlId((pCanIfWakeupConfig -> WakeupCtrlId), CANIF_CHECKVALIDATION_API))
            #endif
            {
                /* Check whether requested wakeup source Id is matching with configured src Id */
                if ((pCanIfWakeupConfig -> WakeupSrcId) == WakeupSource)
                {
                    /* Requested wakeup source is valid */
                    WakeupSrcIndentified = TRUE;
                    /* Check whether wakeup is detected for this Ctrl Id */
                    if (TRUE == CanIf_WakeupDetected[(pCanIfWakeupConfig -> WakeupCtrlId)])
                    {
                        /* Update return Value */
                        RetVal = E_OK;
                        /* Get User Call back Configuration */
                        pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
                        /* Check whether UserValidateWakeupEventFunctPtr is not NULL_PTR */
                        if (NULL_PTR != pCanIfUserCallbackConfig -> UserValidateWakeupEventFunctPtr)
                        {
                            /* Invoke User Callback function */
                            (*(pCanIfUserCallbackConfig -> UserValidateWakeupEventFunctPtr))(WakeupSource);
                        }
                    }
                }
            }
        }
        #if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
        if (FALSE == WakeupSrcIndentified)
        {
            /* Requested wakeup source is Invalid */
            ErrorId = CANIF_E_PARAM_WAKEUPSOURCE;
        }
        #endif
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CHECKVALIDATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif
#endif
#if (CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service reports, if any TX confirmation has been done for the whole CAN controller since the 
*               last CAN controller start.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller
*   @return     CanIf_NotifStatusType Combined TX confirmation status for all TX PDUs of the CAN controller
*   @ServiceID  0x19
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant (Not for the same controller)
********************************************************************************************************************/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId)
{
    /* Local Variables */
    PduIdType TxPduId = 0U;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    CanIf_NotifStatusType NotifyStatus = CANIF_NO_NOTIFICATION;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        /* Module is not Initialized */
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        /* out of range or no status information was configured for this CAN Tx L-SDU */
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if (CANIF_CS_UNINIT == CanIf_GetCurrentCtrlMode(ControllerId))
    {
        /* Ctrl is not Initialized */
        ErrorId = CANIF_E_UNINIT;
    }
#endif
    else
    {
        /* Check all the Tx Pdus configured for the requested Controller Id */
        for (TxPduId = 0; TxPduId < CANIF_NUM_OF_TX_PDU; TxPduId++)
        {
            /* Check Whether Configured Ctrl Id is matching with requested Ctrl Id */
            if (ControllerId == CanIf_GetCtrlId(TxPduId))
            {
                /* Get Pdu Tx confirmation Notification status */
                NotifyStatus = CanIf_TxNotifyStatus[TxPduId];
            }
            /* Check whether NotifyStatus is CANIF_TX_RX_NOTIFICATION */
            if (CANIF_TX_RX_NOTIFICATION == NotifyStatus)
            {
                break;
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETTXCONFIRMATIONSTATE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return NotifyStatus;
}
#endif
#if (CANIF_SET_BAUD_RATE_API == STD_ON)
/********************************************************************************************************************
*   @brief      This service shall set the baud rate configuration of the CAN controller. Depending on necessary 
*               baud rate modifications the controller might have to reset
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, whose baud rate 
*               shall be set.
*   @param[in]  BaudRateConfigID references a baud rate configuration by ID
*   @return     Std_ReturnType E_OK: Service request accepted, setting of (new) baud rate started
*               E_NOT_OK: Service request not accepted
*   @ServiceID  0x1E
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different ControllerIds. Non reentrant for the same ControllerId.
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID)
{
    /* Local Variables */
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;
    P2CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvConfig;
    uint8 CanIfCanDriveMapIndex = 0U;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
#endif
    else
    {
        /* Get Can Driver Mapping Array */
        pCanIfCanDrvConfig = &CanIf_CtrlIdtoCanDrvFunctMapConfig[ControllerId];
        /* Get CanDriver Mapping Index */
        CanIfCanDriveMapIndex = pCanIfCanDrvConfig -> CanDrvFunctId;
        /* check whether Can driver config index is valid */
        if (CANIF_NUM_OF_CAN_DRIVERS > CanIfCanDriveMapIndex)
        {
            /* Get Can Driver function Mapping array */
            pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanIfCanDriveMapIndex];
            /* Check Whether CanDrvSetBaudrateFunctPtr is not equal to NULL */
            if (NULL_PTR != pCanIfCanDrvFuncConfig -> CanDrvSetBaudrateFunctPtr)
            {
                /* Invoke CanDrvSetBaudrateFunctPtr API */
                /* The parameter BaudRateConfigID of CanIf_SetBaudrate() is not checked
                    by CanIf. This has to be done by responsible CanDrv. */
                RetVal = (*(pCanIfCanDrvFuncConfig -> CanDrvSetBaudrateFunctPtr)) (ControllerId, BaudRateConfigID);
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETBAUDRATE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif

#if (CANIF_TRIGGER_TRANSMIT_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      Within this API, the upper layer module (called module) shall check whether the available data fits 
*               into the buffer size reported by PduInfoPtr->SduLength. If it fits, it shall copy its data into 
*               the buffer provided by PduInfoPtr->SduDataPtr and update the length of the actual copied data
*               in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
*   @param[in]  TxPduId ID of the SDU that is requested to be transmitted.
*   @param[in,out] PduInfoPtr Contains a pointer to a buffer (SduDataPtr) to where the SDU data shall be copied, and 
*               the available buffer size in SduLengh. On return, the service will indicate the length of the copied 
*               SDU data in SduLength.
*   @return     Std_ReturnType E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
*               E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may contain a NULL
*               pointer or point to invalid data.
*   @ServiceID  0x41
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant for different PduIds. Non reentrant for the same PduId 
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr
)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;
    CanIf_TxTriggerTransmitFunctIdType TriggerTransmitIndex = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    P2CONST(CanIf_TxTriggerTransmitFunctType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxTriggerTransmitConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        /* Module is not Initialized */
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_TX_PDU <= TxPduId)
    {
        /* out of range or no status information was configured for this CAN Tx L-SDU */
        ErrorId = CANIF_E_INVALID_TXPDUID;
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Tx Pdu Configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[TxPduId];
        /* Get Trigger transmit function Index */
        TriggerTransmitIndex = pCanIfTxPduIdConfig -> TxTriggerTransmitFunctId;
        /* Check added to resolve coverity out of bound warning */
        if (CANIF_NUM_OF_TX_TRIGGER_TRANSMIT > TriggerTransmitIndex)
        {
            /* Get Trigger transmit Configuration */
            pCanIfTxTriggerTransmitConfig = &CanIf_TxTriggerTransmitFunctConfig[TriggerTransmitIndex];
            /* Check whether TxTriggerTransmitFunctId is not NULL_PTR */
            if (NULL_PTR != (*pCanIfTxTriggerTransmitConfig))
            {
                /* Invoke trigger transmit Callback to Upper Module */
                RetVal = (*pCanIfTxTriggerTransmitConfig) (TxPduId, PduInfoPtr);
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_TRIGGERTRANSMIT_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}
#endif
#if (CANIF_PUBLIC_ICOM_SUPPORT == STD_ON)
/********************************************************************************************************************
*   @brief      This service shall change the Icom Configuration of a CAN controller to the requested one..
*   @param[in]  ControllerId Abstracted CanIf Controller Id which is assigned to a CAN controller
*   @param[in]  ConfigurationId Requested Configuration
*   @return     Std_ReturnType E_OK: Request accepted E_NOT_OK: Request denied
*   @ServiceID  0x25
*   @Sync/Async Asynchronous
*   @Reentrancy Reentrant only for different controller Ids
********************************************************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
)
{
/* Local Variables */
    uint8 CanIfCanDriveMapIndex = 0U;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;
    P2CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
#endif
    else
    {
        /* Get Can Driver Mapping Array */
        pCanIfCanDrvConfig = &CanIf_CtrlIdtoCanDrvFunctMapConfig[ControllerId];
        /* Get CanDriver Mapping Index */
        CanIfCanDriveMapIndex = pCanIfCanDrvConfig -> CanDrvFunctId;
        /* check whether Can driver config index is valid */
        if (CANIF_NUM_OF_CAN_DRIVERS > CanIfCanDriveMapIndex)
        {
            /* Get Can Driver function Mapping array */
            pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanIfCanDriveMapIndex];
            /* Check Whether CanDrvSetIcomConfigurationFunctPtr is not equal to NULL */
            if (NULL_PTR != pCanIfCanDrvFuncConfig -> CanDrvSetIcomConfigurationFunctPtr)
            {
                /* Invoke CanDrvSetIcomConfigurationFunctPtr API */
                RetVal = (*(pCanIfCanDrvFuncConfig->CanDrvSetIcomConfigurationFunctPtr))(ControllerId,ConfigurationId);
            }
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_SETICOMCONFIGURATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
    return RetVal;
}

/********************************************************************************************************************
*   @brief      This service shall inform about the change of the Icom Configuration of a CAN controller using the 
*               abstract CanIf ControllerId.
*   @param[in]  ControllerId Abstract CanIf ControllerId which is assigned to a CAN controller, which informs about
*               the Configuration Id.
*   @param[in]  ConfigurationId Active Configuration Id.
*   @param[in]  Error ICOM_SWITCH_E_OK: No Error 
*               ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
*   @ServiceID  0x26
*   @Sync/Async Synchronous
*   @Reentrancy Reentrant only for different controller Ids 
********************************************************************************************************************/
FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{
    uint8 ErrorId = CANIF_E_NO_ERROR;
    P2CONST(CanIf_UserCallbackConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfUserCallbackConfig;

    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
#endif
    else
    {
        /* Get User Callback Configuration */
        pCanIfUserCallbackConfig = &CanIf_UserCallbackConfig;
        /* Check Whether UserCurrentIcomConfigurationFunctPtr is not equal to NULL_PTR */
        if (NULL_PTR != (pCanIfUserCallbackConfig -> UserCurrentIcomConfigurationFunctPtr))
        {
            /* Notify Controller Mode change to CanSM */
            (*(pCanIfUserCallbackConfig -> UserCurrentIcomConfigurationFunctPtr))(ControllerId,ConfigurationId,Error);
        }
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_CURRENTICOMCONFIGURATION_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif
}
#endif

#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
/********************************************************************************************************************
*   @brief      This service calls the corresponding CAN Driver service for obtaining the error state of the 
*               CAN controller.
*   @param[in]  ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested 
*               for ErrorState
*   @param[out]  ErrorStatePtr Pointer to a memory location, where the error state of the CAN controller 
*                will be stored.
*   @return     Std_ReturnType - Return status
*               E_OK: Error state request has been accepted.
*               E_NOT_OK: Error state request has not been accepted.
*   @ServiceID  0x4B
*   @Sync/Async Synchronous
*   @Reentrancy Non Reentrant for the same ControllerId
********************************************************************************************************************/
Std_ReturnType CanIf_GetControllerErrorState
(
    uint8 ControllerId, 
    P2VAR(Can_ErrorStateType,AUTOMATIC,CANIF_APPL_DATA) ErrorStatePtr
)
{
    uint8   CanIfCanDriveMapIndex;
    Std_ReturnType RetVal = E_NOT_OK;
    uint8 ErrorId = CANIF_E_NO_ERROR;
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;
    P2CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvConfig;
    /* Check whether Module is initialized */
    if (FALSE == CanIf_InitStatus)
    {
        ErrorId = CANIF_E_UNINIT;
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    else if (CANIF_NUM_OF_CAN_CONTROLLERS <= ControllerId)
    {
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if(NULL_PTR == ErrorStatePtr)
    {
        ErrorId = CANIF_E_PARAM_POINTER;
    }
#endif
    else
    {
        /* Get Can Driver Mapping Array */
        pCanIfCanDrvConfig = &CanIf_CtrlIdtoCanDrvFunctMapConfig[ControllerId];
        /* Get CanDriver Mapping Index */
        CanIfCanDriveMapIndex = pCanIfCanDrvConfig -> CanDrvFunctId;
        /* check whether Can driver config index is valid */
        if (CANIF_NUM_OF_CAN_DRIVERS > CanIfCanDriveMapIndex)
        {
            /* Get Can Driver function Mapping array */
            pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanIfCanDriveMapIndex];
            /* Check Whether Can error state function Ptr is not equal to NULL */
            if (NULL_PTR != pCanIfCanDrvFuncConfig -> CanGetCtrlErrorStateFunctPtr)
            {
                /* Invoke Can Driver API */
                RetVal = (*(pCanIfCanDrvFuncConfig -> CanGetCtrlErrorStateFunctPtr)) (ControllerId, ErrorStatePtr);
            }
        }    
    }
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(CANIF_GETCONTROLLERERRORSTATE_API, ErrorId);
    }
#else
    CANIF_DUMMY_STATEMENT(ErrorId);
#endif    
    return RetVal;
}
#endif
/********************************************************************************************************************
*  PRIVATE FUNCTION IMPLEMENTATION                                                                                  *
********************************************************************************************************************/
/********************************************************************************************************************
*   @brief      This method used to get the controller id for the Tx PduId
*   @param[in]  CanTxPduId  Tx Pdu Id.
*   @return     CanIf_ControllerIdType Returns the controller id of the Tx PduId
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerIdType,CANIF_CODE) CanIf_GetCtrlId(PduIdType CanTxPduId)
{
    /* Local Variables */
    uint16 MailBoxIndex = 0U;
    CanIf_ControllerIdType CtrlId = CANIF_NO_CAN_CONTROLLER_ID;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    P2CONST(CanIf_MailBoxConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfMailBoxConfig;

    /* Check Whether Pdu Id is valid */
    if (CANIF_NUM_OF_TX_PDU > CanTxPduId)
    {
        /* Read Tx Pdu Configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanTxPduId];
        /* Get MailBox Index */
        MailBoxIndex = pCanIfTxPduIdConfig -> TxPduHTHId;
        /* Check Whether Mail Box Index is valid */
        if (CANIF_NUM_OF_MAILBOX > MailBoxIndex)
        {
            /* Read Mailbox Configuration */
            pCanIfMailBoxConfig = &CanIf_MailBoxConfig[MailBoxIndex];
            /* Get Controller Index */
            CtrlId = pCanIfMailBoxConfig -> CanControllerId;
        }
    }
    /* return Ctrl Id */
    return CtrlId;
}
/********************************************************************************************************************
*   @brief      This method used to get the current controller mode
*   @param[in]  CtrlId  controller Id.
*   @return     CanIf_ControllerModeType Returns the controller mode
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerModeType,CANIF_CODE) CanIf_GetCurrentCtrlMode(CanIf_ControllerIdType CtrlId)
{
    /* Local Variables */
    CanIf_ControllerModeType CtrlMode = CANIF_CS_UNINIT;

    /* Check Whether CtrlId is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > CtrlId)
    {
        /* Get Current Ctrl Mode */
        (void)Can_GetControllerMode(CtrlId, &CtrlMode);
        /* Enter Critical section */
        CanIf_EnterCriticalSection();
        CanIf_CtrlInfo[CtrlId].CurrentCtrlMode = CtrlMode;
        /* Exit Critical section */
        CanIf_ExitCriticalSection();
    }
    /* return Current Ctrl Mode */
    return CtrlMode;
}
/********************************************************************************************************************
*   @brief      This method used to set the current controller mode
*   @param[in]  CtrlId  controller Id.
*   @param[in]  CtrlMode  controller mode to be set.
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UpdateCurrentCtrlMode
(
    CanIf_ControllerIdType CtrlId,
    CanIf_ControllerModeType CtrlMode
)
{
    /* Check Whether Ctrl Id is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > CtrlId)
    {
        /* Enter Critical section */
        CanIf_EnterCriticalSection();
        /* Update Ctrl Mode */
        CanIf_CtrlInfo[CtrlId].CurrentCtrlMode = CtrlMode;
        /* Exit Critical section */
        CanIf_ExitCriticalSection();
    }
}
/********************************************************************************************************************
*   @brief      This method used to get the current Pdu mode
*   @param[in]  CtrlId  controller Id.
*   @return     CanIf_PduModeType Returns the Pdu mode
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_PduModeType,CANIF_CODE) CanIf_GetCurrentPduMode(CanIf_ControllerIdType CtrlId)
{
    /* Local Variables */
    CanIf_PduModeType PduMode = CANIF_OFFLINE;

    /* Check Whether Ctrl Id is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > CtrlId)
    {
        /* Enter Critical section */
        CanIf_EnterCriticalSection();
        /* Get Current Pdu Mode */
        PduMode = CanIf_CtrlInfo[CtrlId].CurrentPduMode;
        /* Exit Critical section */
        CanIf_ExitCriticalSection();
    }
    /* return current Pdu Mode */
    return PduMode;
}
/********************************************************************************************************************
*   @brief      This method used to set the current Pdu mode
*   @param[in]  CtrlId  controller Id.
*   @param[in]  PduMode  pdu mode to be set.
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UpdateCurrentPduMode(CanIf_ControllerIdType CtrlId, CanIf_PduModeType PduMode)
{
    /* Check Whether Ctrl Id is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > CtrlId)
    {
        /* Enter Critical section */
        CanIf_EnterCriticalSection();
        /* Update Pdu Mode */
        CanIf_CtrlInfo[CtrlId].CurrentPduMode = PduMode;
        /* Exit Critical section */
        CanIf_ExitCriticalSection();
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
        if ((CANIF_TX_OFFLINE == PduMode) || (CANIF_OFFLINE == PduMode))
        {
            CanIf_TxInitializeBuffer(CtrlId); 
        }
#endif
    }
}
/********************************************************************************************************************
*   @brief      This method used to get the CanId of the Tx Sdu Id
*   @param[in]  CanIfTxSduId  the Tx Sdu Id
*   @return     Can_IdType returns the Can id
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_IdType,CANIF_CODE) CanIf_GetCanIdentifier(PduIdType CanIfTxSduId)
{
    /* Local Variables */
    Can_IdType CanIfCanId = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    #if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
    PduIdType DynamicPduId = 0U;
    boolean ReconfigSts = FALSE;
    #endif

    /* Check Whether Tx PduId is valid */
    if (CANIF_NUM_OF_TX_PDU > CanIfTxSduId)
    {
        /* Read Tx Pdu configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanIfTxSduId];
        #if (CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API == STD_ON)
        if (CANIF_TX_PDU_TYPE_DYNAMIC == pCanIfTxPduIdConfig -> TxPduType)
        {
            for (DynamicPduId = 0; DynamicPduId < CANIF_NUM_OF_TX_DYNAMIC_PDU; DynamicPduId++)
            {
                /* Check whether requested CanId is equal to stored CanId */
                if (CanIfTxSduId == CanIf_DynamicPduConfig[DynamicPduId].CanIfTxSduId)
                {
                    /* check whether PduId reconfigured */
                    if (TRUE == CanIf_DynamicPduConfig[DynamicPduId].CanIfTxSduId)
                    {
                        ReconfigSts = TRUE;
                        break;
                    }
                }
            }
            if ((TRUE == ReconfigSts) && (DynamicPduId < CANIF_NUM_OF_TX_DYNAMIC_PDU))
            {
                /* Get the updated Can Id */
                CanIfCanId = ((pCanIfTxPduIdConfig -> TxPduCanId) | (CanIf_DynamicPduConfig[DynamicPduId].CanId));
            }
            else
            {
                /* Get Configured Can Id */
                CanIfCanId = pCanIfTxPduIdConfig -> TxPduCanId;
            }
        }
        else
        {
            /* Get Configured Can Id */
            CanIfCanId = pCanIfTxPduIdConfig -> TxPduCanId;
        }
        #else
        /* Get Configured Can Id */
        CanIfCanId = pCanIfTxPduIdConfig -> TxPduCanId;
        #endif
        /* check whether TxPduCanIdType is support for Extended Can Identifier */
        if ((CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType) ||
            (CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType))
        {
            /* Update Extended Identifier bit */
            CanIfCanId = ((CanIfCanId) | (CANIF_CANID_EXTENDED_CAN));
        }
        /* Ckeck whether TxPduCanIdType is support for FD Can */
        if ((CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType) ||
            (CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType))
        {
            /* Update Can FD support bit */
            CanIfCanId = ((CanIfCanId) | (CANIF_CANID_FD_CAN));
        }
    }
    return CanIfCanId;
}
/********************************************************************************************************************
*   @brief      This method used to get the PduLength of the received Pdu
*   @param[in]  CanIfTxSduId  the Tx Sdu Id
*   @param[in]  CanIfTxInfoPtr  the pdu info
*   @return     PduLengthType returns the pdu length for the tx
********************************************************************************************************************/
CANIF_LOCAL FUNC(PduLengthType,CANIF_CODE) CanIf_GetPduLength
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
)
{
    /* Local Variables */
    PduLengthType CanIfPduLength = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;

    /* Check Whether Tx PduId is valid */
    if (CANIF_NUM_OF_TX_PDU > CanIfTxSduId)
    {
        /* Read Tx Pdu configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanIfTxSduId];
        /* Check whether requested Pdu Length and configured Pdu Length */
        if ((pCanIfTxPduIdConfig -> TxPduLength) < (CanIfTxInfoPtr -> SduLength))
        {
            /* CanIf shall transmit as much data as possible and discard the rest. */
            CanIfPduLength = pCanIfTxPduIdConfig -> TxPduLength;
        }
        else
        {
            /* Proceed with requested data length */
            CanIfPduLength = CanIfTxInfoPtr -> SduLength;
        }
    }
    return CanIfPduLength;
}
/********************************************************************************************************************
*   @brief      This method used to set the Can controller mode
*   @param[in]  ControllerId  controller Id.
*   @param[in]  ControllerMode  controller mode to be set.
*   @return     Std_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetCanCtrlMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    /* Local Variables */
    Std_ReturnType RetVal = E_NOT_OK;
    #if (!((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U)))
    CanIf_ControllerModeType CurrentCtrlMode;
    #endif
    uint8 CanIfCtrlCanDrvMapIndex = 0U;
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;
    P2CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCtrlCanDrvMapConfig;

    #if (!((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U)))
    /* Get Current Controller Mode */
    CurrentCtrlMode = CanIf_GetCurrentCtrlMode(ControllerId);
    #endif
    /* Check Whether ControllerId is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > ControllerId)
    {
        /* Get Can Driver mapping array */
        pCanIfCtrlCanDrvMapConfig = &CanIf_CtrlIdtoCanDrvFunctMapConfig[ControllerId];
        /* Array Index */
        CanIfCtrlCanDrvMapIndex = pCanIfCtrlCanDrvMapConfig -> CanDrvFunctId;
        /* Check Whether Can Driver function Id is valid */
        if ((CANIF_NUM_OF_CAN_DRIVERS > CanIfCtrlCanDrvMapIndex) &&
            (CANIF_CS_SLEEP >= ControllerMode))

        {
            /* Get Can Driver function Index */
            pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanIfCtrlCanDrvMapIndex];
            #if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION >= 4U) && (CANIF_CFG_AR_RELEASE_MINOR_VERSION >= 3U))
            RetVal = (*(pCanIfCanDrvFuncConfig -> CanDrvSetControllerModeFunctPtr))(ControllerId, ControllerMode);
            #else
            switch(ControllerMode)
            {
                case CANIF_CS_STOPPED:
                    if(CANIF_CS_SLEEP == CurrentCtrlMode)
                    {
                        if (CAN_OK == (*(pCanIfCanDrvFuncConfig -> CanDrvSetControllerModeFunctPtr))(ControllerId, CAN_T_WAKEUP))
                        {
                            RetVal = E_OK;
                        }
                    }
                    else if ((CANIF_CS_STARTED == CurrentCtrlMode) ||
                            (CANIF_CS_STOPPED == CurrentCtrlMode))
                    {
                        if (CAN_OK == (*(pCanIfCanDrvFuncConfig -> CanDrvSetControllerModeFunctPtr))(ControllerId, CAN_T_STOP))
                        {
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
                        	CanIf_TxInitializeBuffer(ControllerId);
#endif
                            RetVal = E_OK;
                        }
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                break;
                case CANIF_CS_STARTED:
                    if ((CANIF_CS_STARTED == CurrentCtrlMode) ||
                        (CANIF_CS_STOPPED == CurrentCtrlMode))
                    {
                        if (CAN_OK == (*(pCanIfCanDrvFuncConfig -> CanDrvSetControllerModeFunctPtr))(ControllerId, CAN_T_START))
                        {
                            RetVal = E_OK;
                        }
                    }
                break;
                default:
                    if ((CANIF_CS_STOPPED == CurrentCtrlMode) ||
                        (CANIF_CS_SLEEP == CurrentCtrlMode))
                    {
                        if (CAN_OK == (*(pCanIfCanDrvFuncConfig -> CanDrvSetControllerModeFunctPtr))(ControllerId, CAN_T_SLEEP))
                        {
                            RetVal = E_OK;
                        }
                    }
                break;
            }
            #endif
        }
    }
    return RetVal;
}
/********************************************************************************************************************
*   @brief      This method used initiate the transmit request 
*   @param[in]  CanIfTxSduId  Can Tx Sdu Id
*   @param[in]  CanIfTxInfoPtr  pointer to Pdu information 
*   @return     Can_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_ReturnType,CANIF_CODE) CanIf_InitiateTransfer
(
    PduIdType CanIfTxSduId,
    P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_CONST) CanIfTxInfoPtr
)
{
    /* Local Variables */
    uint8 CanIfCtrlId = 0U;
    Can_PduType CanIfPduInfo;
    Can_HwHandleType CanIfTxHandle = 0U;
    P2CONST(CanIf_TxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfTxPduIdConfig;
    #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
    boolean CanWriteReq=TRUE;
    CanIf_TxBufferIdType TxBufferId;
    P2CONST(CanIf_TxBufferConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferConfig;
    #endif
    #if (CANIF_META_DATA_TX_SUPPORT == STD_ON)
    Can_IdType TxCanId;
    PduLengthType TxIdStartPos=0U;
    PduLengthType TxIdEndPos=0U;
    #endif
    Can_ReturnType CanIfWriteSts = CAN_BUSY;

    /* Check Whether Tx PduId is valid */
    if ((CANIF_NUM_OF_TX_PDU > CanIfTxSduId) &&
       (NULL_PTR != CanIfTxInfoPtr))
    {
        /* Read Tx Pdu configuration */
        pCanIfTxPduIdConfig = &CanIf_TxPduIdConfig[CanIfTxSduId];
        /* Get Tx HwHandleId */
        CanIfTxHandle = pCanIfTxPduIdConfig -> TxPduHTHId;
        /* Check added to resolve coverity out of bound warning */
        if (CANIF_NUM_OF_MAILBOX > CanIfTxHandle)
        {
            #if (CANIF_META_DATA_TX_SUPPORT == STD_ON)
            /* check it the PduId doesn't supports Meta data */
            if (pCanIfTxPduIdConfig->TxMetaDataLength > 0U)
            {
                TxCanId = 0U;
                TxIdEndPos = CanIfTxInfoPtr->SduLength;
                /* check if the length is greater than the configured length */
                if (CanIfTxInfoPtr->SduLength >= (pCanIfTxPduIdConfig->TxMetaDataLength))
                {
                    TxIdStartPos = CanIfTxInfoPtr->SduLength-1U;
                    TxIdEndPos  = TxIdEndPos - pCanIfTxPduIdConfig->TxMetaDataLength;
                    /* update the code , id starts at last byte */
                    while(TxIdStartPos > TxIdEndPos)
                    {
                        TxCanId = (Can_IdType)((TxCanId | (Can_IdType)CanIfTxInfoPtr->SduDataPtr[TxIdStartPos]) << 8U);
                        TxIdStartPos--;
                    }
                    TxCanId |= (Can_IdType)CanIfTxInfoPtr->SduDataPtr[TxIdEndPos];
                    /* check whether TxPduCanIdType is support for Extended Can Identifier */
                    if ((CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType) ||
                        (CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType))
                    {
                        /* Update Extended Identifier bit */
                        TxCanId = ((TxCanId) | (CANIF_CANID_EXTENDED_CAN));
                    }
                    /* Ckeck whether TxPduCanIdType is support for FD Can */
                    if ((CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType) ||
                        (CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN == pCanIfTxPduIdConfig -> TxPduCanIdType))
                    {
                        /* Update Can FD support bit */
                        TxCanId = ((TxCanId) | (CANIF_CANID_FD_CAN));
                    }
                }
                /* Get Can Identifier */
                CanIfPduInfo.id = TxCanId;
                /* Get Pdu Length */
                CanIfPduInfo.length = (uint8)TxIdEndPos;
            }
            else
            {
                /* Get Can Identifier */
                CanIfPduInfo.id = CanIf_GetCanIdentifier(CanIfTxSduId);
                /* Get Pdu Length */
                CanIfPduInfo.length = CanIf_GetPduLength(CanIfTxSduId, CanIfTxInfoPtr);
            }
            #else 
            /* Get Can Identifier */
            CanIfPduInfo.id = CanIf_GetCanIdentifier(CanIfTxSduId);
            /* Get Pdu Length */
            CanIfPduInfo.length = CanIf_GetPduLength(CanIfTxSduId, CanIfTxInfoPtr);
            #endif
            /* Sdu Data Pointer */
            CanIfPduInfo.sdu = CanIfTxInfoPtr -> SduDataPtr;
            /* Pdu Handle Id */
            CanIfPduInfo.swPduHandle = CanIfTxSduId;
            /* Get Ctrl Id */
            CanIfCtrlId = CanIf_GetCtrlId(CanIfTxSduId);
            #if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            /*Check if the Transmit handle has buffer type fifo */
            TxBufferId = CanIf_MailBoxConfig[CanIfTxHandle].TxBufferId;
            if (CANIF_NUM_OF_TX_BUFFERS > TxBufferId)
            {
                pTxBufferConfig = &CanIf_TxBufferConfig[TxBufferId];
                /* If the fifo is free then transmit message to HW , else
                 * update the tranmit element to the fifo.
                 */
                if (CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType )
                {
                    if (TRUE != CanIf_TxCheckFifoEmpty(pTxBufferConfig->TxBufferId))
                    {
                        CanWriteReq = FALSE;
                    }
                }
            }
            if (FALSE != CanWriteReq )
            #endif
            {
                /* Invoke Write Pdu API */
                CanIfWriteSts = CanIf_WritePdu(CanIfCtrlId, CanIfTxHandle, &CanIfPduInfo);
            }
            #if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
            /* Check whether CanIfWriteSts is CAN_BUSY */
            if (CAN_BUSY == CanIfWriteSts)
            {
                /* Check whether Tx Buffer is enabled for this Pdu */
                if (CANIF_NUM_OF_TX_BUFFERS > TxBufferId)
                {
                    CanIfWriteSts = CanIf_TxBusyResponseHandler(CanIfTxHandle,&CanIfPduInfo);
                }
            }
            #endif
        }
    }
    /* return write request status */
    return CanIfWriteSts;
}
/********************************************************************************************************************
*   @brief      This method used to transmit the pdu 
*   @param[in]  CtrlId  controller Id
*   @param[in]  CanIfTxHandle  Can If HTH handle
*   @param[in]  PduInfo  pointer to Pdu information 
*   @return     Can_ReturnType  status of the request.
********************************************************************************************************************/
CANIF_LOCAL FUNC(Can_ReturnType,CANIF_CODE) CanIf_WritePdu
(
    CanIf_ControllerIdType CtrlId,
    Can_HwHandleType CanIfTxHandle,
    P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_CONST) PduInfo
)
{
    /* Local variables */
    uint8 CanIfCanDriveMapIndex = 0U;
    Can_ReturnType CanIfWriteSts = CAN_NOT_OK;
    P2CONST(CanIf_CtrlIdtoCanDrvFunctMapConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvConfig;
    P2CONST(CanIf_CanDrvFunctConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfCanDrvFuncConfig;

    /* Check Whether Ctrl Id is Valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS > CtrlId)
    {
        /* Get Can Driver Mapping Array */
        pCanIfCanDrvConfig = &CanIf_CtrlIdtoCanDrvFunctMapConfig[CtrlId];
        /* Get CanDriver Mapping Index */
        CanIfCanDriveMapIndex = pCanIfCanDrvConfig -> CanDrvFunctId;
        /* check whether Can driver config index is valid */
        if (CANIF_NUM_OF_CAN_DRIVERS > CanIfCanDriveMapIndex)
        {
            /* Get Can Driver function Mapping array */
            pCanIfCanDrvFuncConfig = &CanIf_CanDrvFunctConfig[CanIfCanDriveMapIndex];
            /* Check Whether Can Write function Ptr is not equal to NULL */
            if (NULL_PTR != pCanIfCanDrvFuncConfig -> CanDrvWriteFunctPtr)
            {
                /* Invoke Write API */
                CanIfWriteSts = (*(pCanIfCanDrvFuncConfig -> CanDrvWriteFunctPtr)) (CanIfTxHandle, PduInfo);
            }
        }
    }
    return CanIfWriteSts;
}
/********************************************************************************************************************
*   @brief      This method used to process the filtering of the received can id , SW filtering
*   @param[in]  Mailbox  Mailbox id
*   @param[in]  CanIfRxPduId  Can If HRH handle
*   @param[in]  PduInfo  pointer to Pdu information 
*   @return     boolean  TRUE if received CanId is valid , FALSE if received CanId is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_AcceptanceFilter
(
    P2CONST(Can_HwType,AUTOMATIC,CANIF_APPL_CONST) Mailbox,
    P2VAR(uint16,AUTOMATIC,CANIF_APPL_DATA) CanIfRxPduId
)
{
    /* Local Variables */
    CanIf_PduModeType CanIfPduMode;
    uint32 CanIfConfigMaskVal = 0UL;
    Can_IdType CanIfReceiveCanId = 0U;
    Can_IdType CanIfConfigCanId = 0U;
    Can_HwHandleType CanIfReceiveHohId = 0U;
    boolean CanIfFilterAcceptSts = FALSE;
    CanIf_ControllerIdType CanIfCtrlId = 0U;
	CanIf_RxSearchParamType CanIfRxSearchParam;
    P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfRxPduIdConfig;
    P2CONST(CanIf_MailBoxConfigType,AUTOMATIC,CANIF_APPL_CONST) pCanIfMailBoxConfig;

    /* Get HoH Configuration */
    CanIfReceiveHohId = Mailbox -> Hoh;
    /* Check whether Hoh Id is valid */
    if (CANIF_NUM_OF_MAILBOX > CanIfReceiveHohId)
    {
        /* Get Mail box Configuration */
        pCanIfMailBoxConfig = &CanIf_MailBoxConfig[CanIfReceiveHohId];
        /* Get Controller Id */
        CanIfCtrlId = pCanIfMailBoxConfig -> CanControllerId;
        /* Get Pdu Mode */
        CanIfPduMode = CanIf_GetCurrentPduMode(CanIfCtrlId);
        /* Check whether Pdu mode is ONLINE and requestd HOH is configured for Receive Operation*/
        if ((CANIF_OFFLINE != CanIfPduMode) &&
            (CANIF_CAN_OBJECT_TYPE_RECEIVE == pCanIfMailBoxConfig -> CanObjectType))
        {
            /* Get Can Id */
            CanIfReceiveCanId =  ((Mailbox -> CanId) & (~CANIF_CANID_MASK));
            /* Check whether CanHandleType is CANIF_CAN_HANDLE_TYPE_FULL_CAN */
            if (CANIF_CAN_HANDLE_TYPE_FULL_CAN == pCanIfMailBoxConfig -> CanHandleType)
            {
                /* Check added to resolve coverity out of bound warning */
                if (CANIF_NUM_OF_RX_PDU > pCanIfMailBoxConfig -> PduStartId)
                {
                    /* Get Rx Pdu Configuration */
                    pCanIfRxPduIdConfig = &CanIf_RxPduIdConfig[pCanIfMailBoxConfig -> PduStartId];
                    /* Get Configured Can Id */
                    CanIfConfigCanId = pCanIfRxPduIdConfig -> RxPduCanId;
                    /* Get Configuration Mask Value */
                    CanIfConfigMaskVal = CanIf_RxGetCanIdMask(pCanIfRxPduIdConfig->RxCanIdMaskIdx);
                    /* Check if the requested canId is associated with HoH */
                    if (CanIfReceiveCanId == (CanIfConfigCanId & CanIfConfigMaskVal))
                    {
                        *CanIfRxPduId = pCanIfMailBoxConfig -> PduStartId;
                        /* Set CanId availability Status */
                        CanIfFilterAcceptSts = TRUE;
                    }
                }
            }
            else
            {				
				CanIfRxSearchParam.RxStartPduId = pCanIfMailBoxConfig -> PduStartId;
				CanIfRxSearchParam.RxEndPduId =pCanIfMailBoxConfig -> PduEndId;
				CanIfRxSearchParam.RcvdCanId = CanIfReceiveCanId;
				CanIfRxSearchParam.RcvdRxPduId = 0U;
                /*Search whether the requested CanId is present in HOH List */
				#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
				/* linear Search */
				CanIfFilterAcceptSts=CanIf_RxMessageLinearSearch(&CanIfRxSearchParam);	
				#elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
				/* Binary Search */
				CanIfFilterAcceptSts=CanIf_RxMessageBinarySearch(&CanIfRxSearchParam);
				#elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
				/* Double Hash */
				CanIfFilterAcceptSts=CanIf_RxMessageDoubleHashSearch(&CanIfRxSearchParam);
				#elif (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
				/* Double Hash */
				CanIfFilterAcceptSts=CanIf_RxMessageIndexSearch(&CanIfRxSearchParam);
				#else
				CanIfFilterAcceptSts = FALSE;
				#endif
				if (TRUE == CanIfFilterAcceptSts)
				{
					*CanIfRxPduId = CanIfRxSearchParam.RcvdRxPduId;
				}
            }
        }
    }
    return CanIfFilterAcceptSts;
}

#if (CANIF_TRCV_HANDLING == STD_ON)
/********************************************************************************************************************
*   @brief      This method used to get the controller id mapped to the transceiver
*   @param[in]  TransceiverId  the transceiver id
*   @return     CanIf_ControllerIdType returns the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(CanIf_ControllerIdType,CANIF_CODE) CanIf_GetTrcvCtrlId(uint8 TransceiverId)
{
    /* Local Variables */
    CanIf_ControllerIdType CtrlIndex = 0U;
    CanIf_ControllerIdType CtrlId = CANIF_NO_CAN_TRANSCEIVER_ID;

    for (CtrlIndex = 0U; CtrlIndex < CANIF_NUM_OF_CAN_CONTROLLERS; CtrlIndex++)
    {
        if (TransceiverId == CanIf_CtrlIdtoTrcvDrvMapConfig[CtrlIndex].TrcvDrvFunctId)
        {
            /* Update Ctrl Index */
            CtrlId = CtrlIndex;
            break;
        }
    }
    /* return Ctrl Id */
    return CtrlId;
}
#endif
#if (((CANIF_TRCV_HANDLING == STD_ON) || (CANIF_WAKEUP_SUPPORT == STD_ON)) && \
    (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON))
/********************************************************************************************************************
*   @brief      This method used to validate the controller id
*   @param[in]  CtrlId  the controller id
*   @param[in]  ApiId  the Api id which called for validation
*   @return     CanIf_ControllerIdType returns the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(Std_ReturnType,CANIF_CODE) CanIf_ValidateCtrlId(CanIf_ControllerIdType CtrlId, uint8 ApiId)
{
    /* Local Variables */
    uint8 ErrorId = CANIF_E_NO_ERROR;
    Std_ReturnType RetVal = E_NOT_OK;

    /* Check whether Ctrl Id is valid */
    if (CANIF_NUM_OF_CAN_CONTROLLERS <= CtrlId)
    {
        /* Invalid Controller Id */
        ErrorId = CANIF_E_PARAM_CONTROLLERID;
    }
    else if (CANIF_CS_UNINIT == CanIf_GetCurrentCtrlMode(CtrlId))
    {
        /* Ctrl is not Initialized */
        ErrorId = CANIF_E_UNINIT;
    }
    else
    {
        /* Ctrl Id is valid */
        RetVal = E_OK;
    }
    /* Check whether any development error is reported */
    if (CANIF_E_NO_ERROR != ErrorId)
    {
        CanIf_Det_ReportError(ApiId, ErrorId);
    }
    return RetVal;
}
#endif
#if (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)
/********************************************************************************************************************
*   @brief      This method used to intialize the receive buffer
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_InitializeRxBuffer(void)
{
    /* Local Variables */
    uint8 RxBufferId = 0U;

    /* Initialize Buffer Index */
    CanIf_RxBufferIndex = 0U;
    /* Initialize all Rx buffer */
    for (RxBufferId  = 0U; RxBufferId < CANIF_MAX_RX_BUFFER_SIZE; RxBufferId++)
    {
        /* Initialize Pdu Id */
        CanIf_RxBuffer[RxBufferId].CanIfRxPduId = 0U;
        /* Initialize Sdu Length */
        CanIf_RxBuffer[RxBufferId].CanIfSduLength = 0U;
        /* Assign Local Memory Pointer */
        CanIf_RxBuffer[RxBufferId].CanIfRxPduBuffer = &CanIf_RxReceiveBuffer[(RxBufferId * CANIF_CFG_RX_MAXVALIDRXDLC)];
        /* Initialize SduDataPtr */
        CanIf_UtilMemSet((CanIf_RxBuffer[RxBufferId].CanIfRxPduBuffer), 0u, CANIF_CFG_RX_MAXVALIDRXDLC);
    }
}
#endif
#if (CANIF_PUBLIC_TX_BUFFERING == STD_ON)
/********************************************************************************************************************
*   @brief      This method used to intialize the transmit buffers
*   @param[in]  ControllerId  the controller id
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_TxInitializeBuffer(uint8 ControllerId)
{
	uint16 Index;
	P2CONST(CanIf_TxBufferConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferConfig;
	/* Initialize the buffers */
	for (Index=0u;Index < CANIF_NUM_OF_TX_BUFFERS ; Index++)
	{
		/* get buffer configuration */
		pTxBufferConfig = &CanIf_TxBufferConfig[Index];
		if(ControllerId == pTxBufferConfig->CanCtrlId)
		{
			if ((CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType ) &&
				(CANIF_NUM_OF_TX_FIFO > pTxBufferConfig->TxBufferId))
			{
				/* Initialize the fifo status */
				CanIf_TxBufferFifoStatus[Index].WriteIdx = 0U;
				CanIf_TxBufferFifoStatus[Index].ReadIdx = 0U;
				CanIf_TxBufferFifoStatus[Index].BufferCounter = 0U;
			}
		}
	}
}

/********************************************************************************************************************
*   @brief      This method used to check if FIFO is empty
*   @param[in]  TxBufferFifoId  fifo id
*   @return     boolean return status , TRUE if fifo is empty . FALSE if fifo is not empty
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_TxCheckFifoEmpty(CanIf_TxBufferIdType TxBufferFifoId)
{
	boolean ReturnStatus = FALSE;
	if (CANIF_NUM_OF_TX_FIFO > TxBufferFifoId)
	{
		/* Return True if the bufferCounter is zero. Indicates no element present */
		if (0u == CanIf_TxBufferFifoStatus[TxBufferFifoId].BufferCounter)
		{
			ReturnStatus =  TRUE;
		}
	}
	return ReturnStatus;
}
/********************************************************************************************************************
*   @brief      This method used to transmit the available message in the transmit buffer to the CanDriver
*   @param[in]  TxBufferId  Tx buffer id
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_TxBufferDispacth(CanIf_TxBufferIdType TxBufferId)
{
	uint16 ReadIdx;
	Can_PduType PduInfo;
	Can_ReturnType TxStatus;
	P2CONST(CanIf_TxBufferConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferConfig;
	P2VAR(CanIf_TxBufferFifoElementType,AUTOMATIC,CANIF_APPL_DATA) pTxBufferFifoElement;
	P2VAR(CanIf_TxBufferFifoStatusType,AUTOMATIC,CANIF_APPL_DATA) pTxBufferFifoStatus;
    P2CONST(CanIf_TxBufferFifoConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferFifoConfig;

	if (CANIF_NUM_OF_TX_BUFFERS > TxBufferId)
	{
		/* get the tx buffer config */
		pTxBufferConfig = &CanIf_TxBufferConfig[TxBufferId];
		if (CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType )
		{
			if (CANIF_NUM_OF_TX_FIFO > pTxBufferConfig->TxBufferId)
			{
				pTxBufferFifoStatus = &CanIf_TxBufferFifoStatus[pTxBufferConfig->TxBufferId];
				pTxBufferFifoConfig = &CanIf_TxBufferFifoConfig[pTxBufferConfig->TxBufferId];
				ReadIdx = pTxBufferFifoStatus->ReadIdx+pTxBufferFifoConfig->TxFifoElementStartId;
				/* Check if buffer has any elements */
				if ((0u!= pTxBufferFifoStatus->BufferCounter) &&
					(CANIF_NUM_OF_TX_FIFO_ELEMENTS > ReadIdx))
				{
					pTxBufferFifoElement = &CanIf_TxBufferFifoElement[ReadIdx];
					/* copy the data from the fifo */
					PduInfo.id = pTxBufferFifoElement->CanId;
					PduInfo.length = (uint8)pTxBufferFifoElement->Dlc;
					PduInfo.swPduHandle = pTxBufferFifoElement->CanIfPduId;
					PduInfo.sdu = pTxBufferFifoElement->TxBuffer;
					/* Request can driver for message transmission */
					TxStatus = CanIf_WritePdu(pTxBufferFifoElement->CanCtrlId,pTxBufferFifoElement->TxHohId,&PduInfo);

					if (CAN_OK == TxStatus)
					{
						/* If transmission successful, remove the element from the fifo */
						 pTxBufferFifoStatus->ReadIdx++;
						 if (pTxBufferFifoConfig->TxFifoElementSize == pTxBufferFifoStatus->ReadIdx )
						 {
							 pTxBufferFifoStatus->ReadIdx = 0;
						 }
						 if ( pTxBufferFifoStatus->BufferCounter > 0u)
						 {
							 pTxBufferFifoStatus->BufferCounter--;
						 }
					} /* CAN_E_OK == TxStatus */
				} /* 0u!= pTxBufferFifoStatus->BufferCounter */
			} /* CANIF_NUM_OF_TX_FIFO > pTxBufferConfig->TxBufferId */
		}/* CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType */
	} /* CANIF_NUM_OF_TX_BUFFERS > TxBufferId */
}

/*****************************************************************************************************************
** Service Name     : CanIf_TxBusyResponseHandler
** Service ID       : Local_Function
** Sync/Async       : Synchronous
** Reentrancy       : Non Reentrant
** Parameters [in]  : TxBufferId transmit buffer id
** Parameters [in]  : pPduInfo	 pointer to the PduInfo to be stored in the buffer .
** Parameters [out] : None
** Return value     : None
** Description      : This service will transmit the message in the transmit buffer to the CanDriver.
*****************************************************************************************************************/
static Can_ReturnType CanIf_TxBusyResponseHandler(Can_HwHandleType CanHohId,Can_PduType const *pPduInfo)
{
	uint16 WriteIdx;
	CanIf_TxBufferIdType TxBufferId;
	Can_ReturnType ReturnStatus = CAN_NOT_OK;
	P2CONST(CanIf_MailBoxConfigType,AUTOMATIC,CANIF_APPL_CONST) pMailBoxConfig;
	P2CONST(CanIf_TxBufferConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferConfig;
	P2VAR(CanIf_TxBufferFifoStatusType,AUTOMATIC,CANIF_APPL_DATA) pTxBufferFifoStatus;
	P2VAR(CanIf_TxBufferFifoElementType,AUTOMATIC,CANIF_APPL_DATA) pTxBufferFifoElement;
	P2CONST(CanIf_TxBufferFifoConfigType,AUTOMATIC,CANIF_APPL_CONST) pTxBufferFifoConfig;

	if (CANIF_NUM_OF_MAILBOX > CanHohId)
	{
		pMailBoxConfig = &CanIf_MailBoxConfig[CanHohId];
		/* get buffer Id */
		TxBufferId = pMailBoxConfig->TxBufferId;
		if (CANIF_NUM_OF_TX_BUFFERS > TxBufferId)
		{
			pTxBufferConfig = &CanIf_TxBufferConfig[TxBufferId];
			/* Fifo type buffer handling */
			if (CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType )
			{
				if (CANIF_NUM_OF_TX_FIFO > pTxBufferConfig->TxBufferId)
				{
					pTxBufferFifoStatus = &CanIf_TxBufferFifoStatus[ pTxBufferConfig->TxBufferId];
					pTxBufferFifoConfig = &CanIf_TxBufferFifoConfig[pTxBufferConfig->TxBufferId];
					WriteIdx = pTxBufferFifoStatus->WriteIdx + pTxBufferFifoConfig->TxFifoElementStartId;
					/* check if the fifo is available */
					if ((pTxBufferConfig->TxBufferSize > pTxBufferFifoStatus->BufferCounter) &&
						(CANIF_NUM_OF_TX_FIFO_ELEMENTS > WriteIdx))
					{
						pTxBufferFifoElement = &CanIf_TxBufferFifoElement[WriteIdx];
						/* update the PduInfo in the fifo */
						pTxBufferFifoElement->CanId =pPduInfo->id;
						pTxBufferFifoElement->Dlc =pPduInfo->length;
						pTxBufferFifoElement->CanIfPduId =pPduInfo->swPduHandle;
						pTxBufferFifoElement->CanCtrlId =pMailBoxConfig->CanControllerId;
						pTxBufferFifoElement->TxHohId = CanHohId;
						/* copy data to queue buffer */
						if (pPduInfo->length <= CANIF_TX_FIFO_DATA_SIZE_MAX)
						{
							CanIf_UtilMemCpy(pTxBufferFifoElement->TxBuffer,pPduInfo->sdu,pPduInfo->length);
						}
						/* Increment the counter */
						pTxBufferFifoStatus->WriteIdx++;
						if (pTxBufferFifoStatus->WriteIdx == pTxBufferFifoConfig->TxFifoElementSize)
						{
							pTxBufferFifoStatus->WriteIdx = 0u;
						}
						pTxBufferFifoStatus->BufferCounter++;
						ReturnStatus = CAN_OK;
					} /* pTxBufferConfig->TxBufferSize > pTxBufferFifoStatus->BufferCounter */
					else
					{
						/* Buffer full  TODO: Enable DET if required */
					}
				} /* CANIF_NUM_OF_TX_FIFO > TxBufferFifoId */
			} /* CANIF_TX_BUFFER_HANDLING_TYPE_FIFO == pTxBufferConfig->TxBufferHandlingType */
		} /* CANIF_NUM_OF_TX_BUFFERS > TxBufferId */
	}/* CANIF_NUM_OF_MAILBOX > CanIfTxHandle */
	return ReturnStatus;
}

#endif
#if ((CANIF_PUBLIC_TX_BUFFERING == STD_ON) || \
    (CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)|| \
    (CANIF_META_DATA_TX_SUPPORT == STD_ON) || \
    (CANIF_META_DATA_RX_SUPPORT == STD_ON))
/********************************************************************************************************************
*   @brief      This method is used to byte copy
*   @param[in]  DestPtr pointer to destination buffer 
*   @param[in]  SrcPtr pointer to source buffer 
*   @param[in]  Length length to tbe copied
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UtilMemCpy
(
    P2VAR(uint8,AUTOMATIC,CANIF_APPL_DATA) DestPtr,
    CONSTP2CONST(uint8,AUTOMATIC,CANIF_APPL_CONST) SrcPtr,
    PduLengthType Length
)
{
    PduLengthType Idx = 0U;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = SrcPtr[Idx];
    }
}
#endif
#if ((CANIF_PUBLIC_READ_RX_PDU_DATA_API == STD_ON)|| (CANIF_META_DATA_RX_SUPPORT == STD_ON))
/********************************************************************************************************************
*   @brief      This method is used to initialize the buffer with init value
*   @param[in]  DestPtr pointer to destination buffer 
*   @param[in]  Value init value 
*   @param[in]  Length length to tbe set
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_UtilMemSet
(
    P2VAR(uint8,AUTOMATIC,CANIF_APPL_DATA) DestPtr,
    uint8 Value,
    PduLengthType Length
)
{
    PduLengthType Idx = 0U;
    /* copy number of bytes from [pSrc] to [pDest]. */
    for (Idx = 0U; Idx < Length; Idx++)
    {
        DestPtr[Idx] = Value;
    }
}
#endif
#if (CANIF_PUBLIC_DEV_ERROR_DETECT == STD_ON)
/********************************************************************************************************************
*   @brief      This method is used to report error to DET
*   @param[in]  ApiId Api Id 
*   @param[in]  ErrorId error id 
********************************************************************************************************************/
CANIF_LOCAL FUNC(void,CANIF_CODE) CanIf_Det_ReportError(uint8 ApiId, uint8 ErrorId)
{
    /* Development Error Report */
    (void)Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, ApiId, ErrorId);
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_LINEAR)
/********************************************************************************************************************
*   @brief      This method is uses linear filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageLinearSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
)
{
	Can_IdType ConfigCanId;
	uint32 ConfigMaskVal=0;
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxPduIdx = 0U;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	/*Search whether the requested CanId is present in HOH List */
	for (RxPduIdx = pRxSearchParam->RxStartPduId; 
		((RxPduIdx <= pRxSearchParam->RxEndPduId) && (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId) && (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxEndPduId) && (FALSE == RxFilterAcceptSts));
		RxPduIdx++)
	{
		/* Get Rx Pdu Configuration */
		pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduIdx];
		/* Get Configured Can Id */
		ConfigCanId = pRxPduIdConfig -> RxPduCanId;
		/* Get Configuration Mask Value */
		ConfigMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
		/* Check if the requested canId is associated with HoH */
		if ((pRxSearchParam->RcvdCanId & ConfigMaskVal) == (ConfigCanId & ConfigMaskVal))
		{
			pRxSearchParam->RcvdRxPduId = RxPduIdx;
			/* Set CanId availability Status */
			RxFilterAcceptSts = TRUE;
		}
	}
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_BINARY)
/********************************************************************************************************************
*   @brief      This method is uses binary filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageBinarySearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
)
{
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxPduStartIdx=0U;
	CanIf_PduIdConfigIdType RxPduMidIdx=0U;
	CanIf_PduIdConfigIdType RxPduEndIdx=0U;
	Can_IdType RxConfigStartCanId,RxConfigEndCanId;
	uint32 RxConfigStartMaskVal=0U,RxConfigEndMaskVal=0U,RxConfigMidMaskVal=0U;
    P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	
	/* Intialize start and end id */
	RxPduStartIdx = pRxSearchParam->RxStartPduId;
	RxPduEndIdx = pRxSearchParam->RxEndPduId;
    if ((CANIF_NUM_OF_RX_PDU > RxPduStartIdx) &&
        (CANIF_NUM_OF_RX_PDU > RxPduEndIdx))
    {
        /* Initialize start Id mask */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduStartIdx];
        RxConfigStartCanId = pRxPduIdConfig -> RxPduCanId;
        RxConfigStartMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
        /* Initialize end Id mask */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduEndIdx];
        RxConfigEndCanId = pRxPduIdConfig -> RxPduCanId;
        RxConfigEndMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
        while((RxPduEndIdx-RxPduStartIdx)>1U)
        {
            /* Get the Middle pduId */
            RxPduMidIdx = (RxPduStartIdx+RxPduEndIdx)/2U;
            
            /* Get Rx Pdu Configuration */
            pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduMidIdx];
            /* Get Mask Value */
            RxConfigMidMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
            /* if Configured CanId is less than the received ID neglect the elements before mid element,
               else neglect the elements after mid element */
            if((pRxPduIdConfig -> RxPduCanId &  RxConfigMidMaskVal) < \
               (pRxSearchParam -> RcvdCanId & RxConfigMidMaskVal))
            {
                RxPduStartIdx = RxPduMidIdx+1U;
                if (CANIF_NUM_OF_RX_PDU > RxPduStartIdx)
                {
                    pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduStartIdx];
                    /* Get Configured Can Id */
                    RxConfigStartCanId = pRxPduIdConfig -> RxPduCanId;
                    /* Get Configuration Mask Value */
                    RxConfigStartMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
                }
                else
                {
                    /* invalid id configuration ,then exit the search */
                    break;
                }
            }
            else 
            {
                RxPduEndIdx = RxPduMidIdx;
                pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduEndIdx];
                /* Get Configured Can Id */
                RxConfigEndCanId = pRxPduIdConfig -> RxPduCanId;
                /* Get Configuration Mask Value */
                RxConfigEndMaskVal = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
            }
        }
        /* if Id match with start or End then the received id is found else it is not found */
        if ((pRxSearchParam->RcvdCanId & RxConfigStartMaskVal) == (RxConfigStartCanId & RxConfigStartMaskVal))
                
        {
            pRxSearchParam->RcvdRxPduId = RxPduStartIdx;
            /* Set CanId availability Status */
            RxFilterAcceptSts = TRUE;
        }
        else if (((pRxSearchParam->RcvdCanId) & RxConfigEndMaskVal) == (RxConfigEndCanId & RxConfigEndMaskVal))
        {
            pRxSearchParam->RcvdRxPduId = RxPduEndIdx;
            /* Set CanId availability Status */
            RxFilterAcceptSts = TRUE;
        }
        else
        {
            RxFilterAcceptSts = FALSE;
        }
    }
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_TABLE)
/********************************************************************************************************************
*   @brief      This method is uses double hash filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageDoubleHashSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
)
{
	uint32 RxCanIdMask=0U;
	Can_IdType RxHashValue=0U;
	CanIf_RxHashTableSizeType RxHashOffset=0U;
	boolean RxFilterAcceptSts=FALSE,RxIsSearchValid=TRUE;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;
	P2CONST(CanIf_RxHashTableType,AUTOMATIC,CANIF_APPL_CONST) pRxHashTableRef;  
	P2CONST(CanIf_RxHashTableConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxHashTableConfig;
	
    if (CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId)
    {
        pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxSearchParam->RxStartPduId];
        if (CANIF_RX_NUM_OF_HASH_TABLE> pRxPduIdConfig->RxHashTableId)
        {
            pRxHashTableConfig = &CanIf_RxHashTableConfig[pRxPduIdConfig->RxHashTableId];
            
            do
            {
                /* Calculate the Hash Index */
                RxHashValue = ((CANIF_UTILGETHASH1(pRxSearchParam->RcvdCanId,pRxHashTableConfig->RxHashTableSize)) + \
                            (RxHashOffset * (CANIF_UTILGETHASH2(pRxSearchParam->RcvdCanId,
                             pRxHashTableConfig->RxHash2PrimeNum))))% pRxHashTableConfig->RxHashTableSize;
                            
                if (pRxHashTableConfig->RxHashTableSize > RxHashValue)
                {
                    pRxHashTableRef = &(pRxHashTableConfig->pRxRxHashTableRef[RxHashValue]);
                    /* If the Id is available in the Hash Index , then update the return status as TRUE and
                       Update the received RxPduId */
                    if (pRxHashTableRef->RxCanId != pRxHashTableConfig->RxHashTableEmptyValue )
                    {
                        if((pRxHashTableRef->RxCanId == pRxSearchParam->RcvdCanId) &&
                            (CANIF_NUM_OF_RX_PDU > pRxHashTableRef->RxPduId))
                        {
                            pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxHashTableRef->RxPduId];
                            RxCanIdMask = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx);
                            if ((pRxHashTableRef->RxCanId & RxCanIdMask) == \
                                (pRxPduIdConfig->RxPduCanId & RxCanIdMask))
                            {
                                pRxSearchParam->RcvdRxPduId = pRxHashTableRef->RxPduId;
                                RxFilterAcceptSts = TRUE;
                            }
                            /* msg found , hence exit from search */
                            RxIsSearchValid = FALSE;
                        }
                    }
                    else
                    {
                        /* Empty value reached in the hash */
                        RxIsSearchValid = FALSE;
                    }
                }
                else
                {
                    /* Invalid hash value/configuration exit the loop */
                    RxIsSearchValid = FALSE;
                }
                /* If Id is not there , increase the offset and check in the next slot */
                RxHashOffset++;
            }while((RxHashOffset < pRxHashTableConfig->RxHashTableSize)&& (FALSE != RxIsSearchValid));
        }/* (CANIF_RX_NUM_OF_HASH_TABLE> pRxPduIdConfig->RxHashTableId) */
    }/* ((CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId) */        
	return RxFilterAcceptSts;
}
#endif

#if (CANIF_PRIVATE_SOFTWARE_FILTER_TYPE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE_INDEX)
/********************************************************************************************************************
*   @brief      This method is uses index search filter algo to do SW filtering of the received can id
*   @param[in]  pRxSearchParam pointer to the search parmaters
*   @return     boolean returns tbe status . TRUE if can id is valid , FALSE if can id is invalid
********************************************************************************************************************/
CANIF_LOCAL FUNC(boolean,CANIF_CODE) CanIf_RxMessageIndexSearch
(
    CONSTP2VAR(CanIf_RxSearchParamType,AUTOMATIC,CANIF_APPL_DATA) pRxSearchParam
)
{
    uint32 RxCanIdMask=0U;
	boolean RxFilterAcceptSts=FALSE;
	CanIf_PduIdConfigIdType RxSubGrpIdx=0u,RxPduIdx=0U;
	CanIf_PduIdConfigIdType RxNumOfPduIds=0u,RxNumOfSubGrp=0u;
	CanIf_PduIdConfigIdType RxNextSubGrpStartIdx=0u,RxNextSubGrpEndIdx=0U;
	P2CONST(CanIf_RxPduIdConfigType,AUTOMATIC,CANIF_APPL_CONST) pRxPduIdConfig;

    if ( CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId)
    {
        /*Search whether the requested CanId is present in HOH List */
        pRxPduIdConfig = &CanIf_RxPduIdConfig[pRxSearchParam->RxStartPduId];
        RxNumOfPduIds = ((pRxSearchParam->RxEndPduId)-(pRxSearchParam->RxStartPduId))+1U;
        /* Find the number of subgroups based on the group number */
        if(0U == (RxNumOfPduIds%CANIF_INDEX_FILTER_GROUP_NUMBER))
        {
            RxNumOfSubGrp = RxNumOfPduIds/CANIF_INDEX_FILTER_GROUP_NUMBER;
        }
        else
        {
            RxNumOfSubGrp = (RxNumOfPduIds/CANIF_INDEX_FILTER_GROUP_NUMBER)+1U;
        }		
        /* Process if the received Id is greater than the first subgroup Can Id*/
        if (pRxSearchParam->RcvdCanId >= pRxPduIdConfig->RxPduCanId)
        {
            for (RxSubGrpIdx=0;((RxSubGrpIdx<RxNumOfSubGrp) && 
                (RxFilterAcceptSts == FALSE));RxSubGrpIdx++)
            {
                /* update the subgroup start idx */
                RxNextSubGrpStartIdx = pRxSearchParam->RxStartPduId+(RxSubGrpIdx*CANIF_INDEX_FILTER_GROUP_NUMBER);
                /* Calculate End Group PduId */
                if (pRxSearchParam->RxEndPduId >= (RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER))
                {
                    RxNextSubGrpEndIdx = RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER-1U;
                }
                else
                {
                    if (((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx) == 0u)
                    {
                         RxNextSubGrpEndIdx += ((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx+1U);
                    }
                    else
                    {
                        RxNextSubGrpEndIdx += ((pRxSearchParam->RxEndPduId)-RxNextSubGrpEndIdx);
                    }
                } /*(pRxSearchParam->RxEndPduId >= (RxNextSubGrpStartIdx+CANIF_INDEX_FILTER_GROUP_NUMBER)) */
                /* Get sub group RxPdu configuration*/ 
                if (CANIF_NUM_OF_RX_PDU > RxNextSubGrpEndIdx)
                {
                    pRxPduIdConfig = &CanIf_RxPduIdConfig[RxNextSubGrpEndIdx];
                    if (pRxSearchParam->RcvdCanId <= pRxPduIdConfig->RxPduCanId)
                    {
                        /* Do Sequencial search in the subgroup for the received ID */
                        for(RxPduIdx=RxNextSubGrpStartIdx;RxPduIdx<=RxNextSubGrpEndIdx;RxPduIdx++)
                        {
                            pRxPduIdConfig = &CanIf_RxPduIdConfig[RxPduIdx];
                            RxCanIdMask = CanIf_RxGetCanIdMask(pRxPduIdConfig->RxCanIdMaskIdx); 
                            /* If Id found update the RxPduId and update the return status */
                            if((pRxSearchParam->RcvdCanId & RxCanIdMask) == \
                                (pRxPduIdConfig->RxPduCanId & RxCanIdMask))
                            {
                                pRxSearchParam->RcvdRxPduId = RxPduIdx;
                                RxFilterAcceptSts = TRUE;
                                break;
                            }
                        }
                    }/*(pRxSearchParam->RcvdCanId <= pRxPduIdConfig->RxPduCanId) */
                }
                else
                {
                    /* Invalid configuration */
                    break;
                }
            } /* sub group loop */
        }	/* (pRxSearchParam->RcvdCanId >= pRxPduIdConfig->RxPduCanId) */
    } /* CANIF_NUM_OF_RX_PDU > pRxSearchParam->RxStartPduId */
	return RxFilterAcceptSts;
}
#endif

/********************************************************************************************************************
*   @brief      This method is used to get the CanId mask.
*   @param[in]  CanIf_RxCanIdMaskIdx mask index value 
*   @return     uint32 returns the mask status
********************************************************************************************************************/
CANIF_LOCAL FUNC(uint32,CANIF_CODE) CanIf_RxGetCanIdMask( CanIf_RxCanIdMaskIdxType CanIf_RxCanIdMaskIdx)
{
	uint32 RxCanIdMask = 0U;
	
	/* find the mask from the configuration */
	if (CANIF_NUM_OF_RX_CAN_ID_MASKS > CanIf_RxCanIdMaskIdx)
	{
		RxCanIdMask = CanIf_RxCanIdMaskConfig[CanIf_RxCanIdMaskIdx];
	}
	else
	{
		RxCanIdMask = 0U;
	}
	
	return RxCanIdMask;
}


#define CANIF_STOP_SEC_CODE
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
*  @date    14-Jul-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

