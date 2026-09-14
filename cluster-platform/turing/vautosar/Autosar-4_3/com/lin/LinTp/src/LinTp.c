//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
/*****************************************************************************
* File Name         :  LinTp.c                                               *
* Module Short Name :  LinIf                                                 *
* Description       :  Contains LinTp Funtional Implementations              *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :  Turing C                                               *
*                                                                            *
*****************************************************************************/
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#ifndef LINTP_C
#define LINTP_C

#include "LinTp.h"
#include "LinIf.h"
//# include "PduR_LinTp.h"
# include "PduR_LinIf.h"
#include "LinIf_Cfg.h"
#include "Lin_Tp_Cfg.h"
#include "LinTp_Par_Cfg.h"

/********************************************************************************************************************
*  VERSION CHECK                                                                                                    *
********************************************************************************************************************/
/* Software Version Check */
#if ((LINTP_SW_MAJOR_VERSION != LINTP_CFG_SW_MAJOR_VERSION) || \
    (LINTP_SW_MINOR_VERSION != LINTP_CFG_SW_MINOR_VERSION) || \
    (LINTP_SW_PATCH_VERSION != LINTP_CFG_SW_PATCH_VERSION))
# error "Software version is inconsistent between source files and Configuration files!"
#endif
/* Autosar Version Check */
#if ((LINTP_AR_RELEASE_MAJOR_VERSION != LINTP_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (LINTP_AR_RELEASE_MINOR_VERSION != LINTP_CFG_AR_RELEASE_MINOR_VERSION) || \
    (LINTP_AR_RELEASE_REVISION_VERSION != LINTP_CFG_AR_RELEASE_REVISION_VERSION))
# error "Autosar version is inconsistent between source files and Configuration files!"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LINTP_FUNCTIONAL_REQ_ID 0x7Eu

/*! Initialization check variables for LinTP*/
#  define LINTP_INIT                            ((uint8)0x00u)

/* List of TP frame types */
#define LinTp_FrameType_SF                          ((uint8)0x00u)
#define LinTp_FrameType_FF                          ((uint8)0x10u)
#define LinTp_FrameType_CF                          ((uint8)0x20u)






/**********************************************************************************************************************
 * PduR_LinTpRxIndication
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the LinTp to indicate the complete reception of a LinTp I-PDU or to\n
 *           report an error that occurred during reception. The PDU Router evaluates the LinTp I-PDU handle and\n
 *           performs appropriate handle and port conversion. The call is routed to an upper Tp module using the\n
 *           appropriate I-PDU handle of the destination layer.
 * \param    id                              ID of the received LinTp I-PDU
 * \param    result                          Result of the TP reception\n
 *           E_OK                            The TP transmission has been completed successfully.\n
 *           E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                           or the LinTpTxPduId is not valid\n
 *                                           or the LinTpTxPduId is not forwarded in this identity\n
 *                                           or the request was not accepted by the destination upper layer.\n
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_LinTpRxIndication calls for the same LinTpRxPduId.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-674, SPEC-38409
 * \note     The function is called by LinTp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LinTpRxIndication(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 * PduR_LinTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the LinTp to confirm the complete transmission of a LinTp I-PDU or to\n
 *           report an error that occurred during reception. The PDU Router evaluates the LinTp I-PDU handle and\n
 *           performs appropriate handle and port conversion.The call is routed to an upper Tp module using the\n
 *           appropriate I-PDU handle of the destination layer.
 * \param    id                              ID of the transmitted LinTp I-PDU
 * \param    result                          Result of the TP transmission\n
 *           E_OK                            The TP transmission has been completed successfully.\n
 *           E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                           or the LinTpTxPduId is not valid\n
 *                                           or the LinTpTxPduId is not forwarded in this identity\n
 *                                           or the request was not accepted by the destination upper layer.\n
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_LinTpTxConfirmation calls for the same LinTpTxPduId.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666
 * \note     The function is called by LinTp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LinTpTxConfirmation(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
 * PduR_LinTpStartOfReception
 *********************************************************************************************************************/
/*!
 * \brief    This function will be called by the LinTp at the start of a I-PDU reception.\n
 *           The I-PDU might be fragmented into multiple N-PDUs\n
 *           (FF with one or more following CFs) or might consist of a single N-PDU (SF).\n
 *           The PDU Router evaluates the LinTp I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *           destination layer.
 * \param    id                ID of the LinTp I-PDU that will be received
 * \param    info              Pointer to the buffer with meta data if the meta data feature is used (SduDataPtr) \n 
 *                             length empty (use configured length) \n
 * \param    TpSduLength       Length of the entire the LinTp SDU which will be received
 * \param    bufferSizePtr     Pointer to the receive buffer in the receiving module.\n
 *                             This parameter will be used to compute Block Size (BS) in the transport protocol module.
 * \return   BufReq_ReturnType\n
 *           BUFREQ_OK         Connection has been accepted. bufferSizePtr indicates the available receive buffer.\n
 *           BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                             or the id is not valid\n
 *                             or the id is not forwarded in this identity\n
 *                             or the request was not accepted by the destination layer.\n
 *                             or no buffer is available.\n
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_LinTpStartOfReception calls for the same id.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38410
 * \note     The function is called by LinTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
 * PduR_LinTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \brief    This function is called by the LinTp if data has to be to copied to the receiving module.\n
 *           Each call to this function copies the next part of the received data.\n
 *           Several calls may be made during transportation of an I-PDU.\n
 *           The PDU Router evaluates the LinTp I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *           destination layer.
 * \param    id                ID of the LinTp I-PDU that will be received
 * \param    info              Pointer to the buffer (SduDataPtr) and its length (SduLength)\n
 *                             containing the data to be copied by PDU Router module in case of gateway\n
 *                             or upper layer module in case of reception.\n
 *                             A copy size of 0 can be used to poll the available buffer size.
 * \param    bufferSizePtr     Available receive buffer after data has been copied.
 * \return   BufReq_ReturnType\n
 *           BUFREQ_OK         Buffer request accomplished successful\n
 *           BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                             or the id is not valid\n
 *                             or the id is not forwarded in this identity\n
 *                             or the infois not valid\n
 *                             or the request was not accepted by the destination layer\n
 *                             or no buffer is available.\n
 *           BUFREQ_E_OVFL     The upper TP module is not able to receive the number of bytes.\n
 *                             The request was not accepted by the destination layer.
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_LinTpCopyRxData calls for the same id.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38432
 * \note     The function is called by LinTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
 * PduR_LinTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \brief    This function is called by the LinTp to query the transmit data of an I-PDU segment.\n
 *           Each call to this function copies the next part of the transmit data.\n
 *           The PDU Router evaluates the LinTp I-PDU handle and identifies the destination(s) of the PDU.
 *           The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *           destination layer.
 * \param    id                ID of the LinTp I-PDU that will be transmitted
 * \param    info              Pointer to the destination buffer and the number of bytes to copy.\n
 *                             In case of gateway the PDU Router module will copy otherwise the source \n
 *                             upper layer module will copy the data. If not enough transmit data is available,\n
 *                             no data is copied.\n
 *                             A copy size of 0 can be used to poll the available Tx data.
 * \param    retry             retry not supported yet. Is not used.
 * \param    availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.\n
 *                             availableDataPtr can be used by TP modules that support dynamic payload lengths\n
 *                             (e.g. Iso FrTp) to determine the size of the following CFs.
 * \return   BufReq_ReturnType\n
 *           BUFREQ_OK         The data has been copied to the transmit buffer successful\n
 *           BUFREQ_E_BUSY     Request could not be fulfilled, because the required amount of \n
 *                             Tx data is not available. The LoTp module can either retry the request \n
 *           BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                             or the id is not valid\n
 *                             or the id is not forwarded in this identity\n
 *                             or the info pointer is not valid\n
 *                             or the request was not accepted by the destination layer\n
 *                             or the request length to copy is greater than the remaining buffer size.
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_LinTpCopyTxData calls for the same id.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38401
 * \note     The function is called by LinTp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LinTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);





/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
/*! Initialization check variable for LinTp. Must be set after reset*/
uint8 LinTp_Dev_InitDetect  = LINTP_INIT;

/***********************************************************************************************************************
 *  LinTp_TxCloseConnection
 **********************************************************************************************************************/
/*! \brief       Closes a Tp Tx connection.
 *  \details     Resets a Tx connection back to idle and notifies the PduR. It does not check if a Tx
 *               connection is active.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \pre         A Tx connection shall be active.
 **********************************************************************************************************************/
static void LinTp_TxCloseConnection(LinTp_ControlType* const LinTp_CtrlPtr);


/***********************************************************************************************************************
 *  LinTp_RxCloseConnection
 **********************************************************************************************************************/
/*! \brief       Closes a Tp Rx connection.
 *  \details     Resets a Rx connection back to idle and notifies the PduR. Does not check if an Rx
 *               connection is active.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \pre         An Rx connection shall be active.
 **********************************************************************************************************************/
static void LinTp_RxCloseConnection(LinTp_ControlType* const LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling
 **********************************************************************************************************************/
/*! \brief       Handles the received data and passes it to PduR.
 *  \details     Passes pending local received data to PduR and performs delayed buffer retry handling.
 *  \param[in]   LinTp_CtrlPtr         Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr       Source pointer (SRF buffer), provide null at repeated call to work on local buffer
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling(LinTp_ControlType* const  LinTp_CtrlPtr, const uint8 *LinTp_LinSduPtr);

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling_StartOfReception()
 **********************************************************************************************************************/
/*! \brief       Handles the interface with PduR for setting up a receive connection.
 *  \details     Initiates a Tp receive connection to PduR.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling_StartOfReception(LinTp_ControlType* const  LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling_CopyRxData()
 **********************************************************************************************************************/
/*! \brief       Handles the interface with PduR for reception data.
 *  \details     Provides PduR with TP reception data and handles internal buffer states.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling_CopyRxData(LinTp_ControlType* const  LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_RxIndication_SF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a single frame N-PDU.
 *  \details     This function processes a received SRF containing a single frame. Terminates a possible ongoing reception
 *               on the same channel, performs response pending frame handling if necessary and initiates a new receive
 *               connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
static void LinTp_RxIndication_SF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr);

/***********************************************************************************************************************
 *  LinTp_GetP2MaxTime() 
 **********************************************************************************************************************/
/*! \brief       Provides  the P2 timer maximum count
 *  \details     Returns P2 timer maximum count for reloading the timer
 *  \param[in]   NULL
 **********************************************************************************************************************/
static uint16 LinTp_GetP2MaxTime(void);

/***********************************************************************************************************************
 *  LinTp_RxIndication_FF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a first frame N-PDU.
 *  \details     This function processes a received SRF containing a first frame. Terminates a possible ongoing reception
 *               on the same channel and initiates a new receive connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
static void LinTp_RxIndication_FF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr);

/***********************************************************************************************************************
 *  LinTp_RxIndication_CF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a consecutive frame N-PDU.
 *  \details     This function processes a received SRF containing a first frame. Check for a valid sequence number and
 *               passes received data to buffer handling on active connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
static void LinTp_RxIndication_CF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr);

/***********************************************************************************************************************
 *  LinTp_Init()
 **********************************************************************************************************************/
/*! \brief       Initializes component LinTp.
 *  \details     Initializes all component variables and sets the component state to initialized.
 *  \param[in]   ConfigPtr               Pointer to LinTp configuration structure
 **********************************************************************************************************************/
void LinTp_Init(const LinTp_ConfigType* ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8                                               linIfChannelTmp;
  /* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  uint8                                               errorId;
  
  /*Initiliaze error ID as No Error*/
  errorId = LINIF_E_NO_ERROR;

  /*  Check if LinTp component is already initialized */
  if ( LinTp_Dev_InitDetect == LINTP_INIT )
  {
    /*Update the error ID as Already initialized and report to DET*/
    errorId = LINIF_E_ALREADY_INITIALIZED;
  }
  else
# endif
    /* Check validity of parameter ConfigPtr */
    if (ConfigPtr == (LinTp_ConfigType*) NULL_PTR)
    {
/* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
      /*Update error with the Pointer parameter, since it is NULL without any valid data*/
      errorId = LINIF_E_PARAMETER_POINTER;
#  endif
    }
    else
    {
/* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
        /* Set LinTp initialization flag to INIT */
        LinTp_Dev_InitDetect  = LINTP_INIT;
# endif
        /* Initialize all channel dependent transport protocol variables for all channels */
        for (linIfChannelTmp = 0x00u; linIfChannelTmp < LinTp_GetSizeOfCtrl(); linIfChannelTmp++ )
        {
          /*Set the TP channel to IDLE state initially to start the communication*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_Ch_State            = LINTP_CHANNEL_IDLE; 
          /*Clear NAD of request */
          LinTp_GetCtrl(linIfChannelTmp).LinTp_NAD_Requested       = 0u; 
          /*Initialize the P2 timer value on  INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_P2Timer             = 0u; 
          /*Reset the Response pending counter on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_RespPendingCounter  = 0u; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          /*Initialize the communcation mode for Functional request */
          LinTp_GetCtrl(linIfChannelTmp).LinTp_ComModeRestore      = LINTP_APPLICATIVE_SCHEDULE; 
          /*Initialize the functional request state as IDLE on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_FuncRequest         = LINTP_FUNC_REQUEST_IDLE; 
# endif
          /*Initialize TP port notification as IDLE on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_PortNotification    = LinTp_PortNotificationIdle; 
          /*Initialize TP Timer with zero on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_Timer               = 0u; 
          /*Initialize the sequence number of CF as zero on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_SN                  = 0u; 
          /*Initialize TP PduR notification as IDLE on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_PduRNotification    = LinTp_PduRNotificationIdle; 
          /*Initialize the Currently received ID as zero on INIT*/
          LinTp_GetCtrl(linIfChannelTmp).LinTp_Curr_Rx_Id          = 0u; 
        }
      }
/* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
      /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_INIT, errorId);
  }
# endif
} 

/***********************************************************************************************************************
 *  LinTp_Transmit()
 **********************************************************************************************************************/
/*! \brief       Requests the transmission of diagnostic data using transport protocol.
 *  \details     Request the transfer of segmented data over the LIN bus using master request frames.
 *  \param[in]   LinTpTxSduId            Unique N-SDU identifier of LIN N-SDU to be transmitted.
 *  \param[in]   LinTpTxInfoPtr          Pointer to LIN N-SDU related data containing DLC and pointer to LIN n-SDU buffer.
 *  \return      E_OK                    Request was accepted and can be started successfully.
 *  \return      E_NOT_OK                Request was not accepted and cannot be started.
 **********************************************************************************************************************/
Std_ReturnType LinTp_Transmit(PduIdType LinTpTxSduId, const PduInfoType* LinTpTxInfoPtr)
{
  /*Declare the required local variables*/
  LinTp_ControlType* tpCtrlTmp;
  Std_ReturnType retVal;
  
  /*Iniitalize return value as E_NOT_OK by default*/
  retVal = (Std_ReturnType)E_NOT_OK;
  /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
 
  /* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  uint8                                               errorId;
  /*Initiliaze error ID as No Error*/
  errorId = LINIF_E_NO_ERROR;

  /* Check validity of parameter LinTpTxInfoPtr */
  if ( LinTpTxInfoPtr == (PduInfoType)NULL_PTR )
  {
      /*Update error with the Pointer parameter, since it is NULL without any valid data*/
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  /* Check validity of parameter LinTpTxSduId */
  else if ( LinTpTxSduId >= LinTp_GetNumberOfLinTpTxNSdu() )
  {
      /*Update error with parameter since received SduId doesn't match with the configured  value*/
    errorId = LINIF_E_PARAMETER;
  }
  /* at this point LinTpTxSduId is valid, so the LinIfChannel belonging to this Pdu is guaranteed to be valid and used by LinTp */
  else
# endif
  {
    /*Get the Lin TP control pointer data*/
    tpCtrlTmp = LinTp_GetAddrCtrl (LinTp_TxNSdu[LinTpTxSduId].CtrlIdxOfTxNSdu);

# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
    /* If requested Nsdu is a valid functional request */
    if ( (LinTp_TxNSdu[(LinTpTxSduId)].NADOfTxNSdu == LINTP_FUNCTIONAL_REQ_ID) && (LinTpTxInfoPtr->SduLength <= 6u) )
    {
      /* If length is valid (SF), set functional request flag and trigger diagnostic schedule table */
      /* postpone buffer request of functional request until MRF is actually triggered to be transmitted, just store length of request here */
      tpCtrlTmp->LinTp_FuncPduInfoPtr.SduLength = LinTpTxInfoPtr->SduLength; 
      /* request appropriate schedule */
      tpCtrlTmp->LinTp_PortNotification         = LINTP_DIAG_REQUEST; 
      /* store NSdu of functional request */
      tpCtrlTmp->LinTp_Curr_Func_NSdu_Id        = LinTp_TxNSdu[(LinTpTxSduId)].UpperLayerPduIdOfTxNSdu;
      tpCtrlTmp->LinTp_FuncRequest              = LINTP_FUNC_REQUEST_PENDING; 
      retVal                                    = (Std_ReturnType)E_OK;
    }
    /*Otherwise: (physical request) */
    else
# endif
    {
      /* Abort possibly ongoing Tp Rx connection, if it is active */
      if ( ( tpCtrlTmp->LinTp_Ch_State & LINTP_CHANNEL_RX_MSK ) == LINTP_CHANNEL_RX_MSK )
      { 
        /* direct notification to PduR */
        PduR_LinTpRxIndication(tpCtrlTmp->LinTp_Curr_UL_NSdu_Id, E_NOT_OK); 
        /*Reset TP timer*/
        tpCtrlTmp->LinTp_Timer                = 0u; 
        /*Reset P2 timer*/
        tpCtrlTmp->LinTp_P2Timer              = 0u; 
        /*Reset TP channel state as IDLE upon receiving Physical request*/
        tpCtrlTmp->LinTp_Ch_State             = LINTP_CHANNEL_IDLE; 
        /* request applicative schedule here, overwritten below if request is accepted */
        tpCtrlTmp->LinTp_PortNotification     = LINTP_APPLICATIVE_SCHEDULE; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
        tpCtrlTmp->LinTp_ComModeRestore       = LINTP_APPLICATIVE_SCHEDULE; 
# endif
      }

      /*An ongoing Tp Tx connection should not be interfered, the new request is rejected in this case */
      /*So check whether TP channel is in IDLE state*/
      if ( tpCtrlTmp->LinTp_Ch_State == LINTP_CHANNEL_IDLE )
      {
        /* Prepare frame: setup connection, init local buffer */
        /* Save current N-SDU */
        tpCtrlTmp->LinTp_Curr_UL_NSdu_Id          = LinTp_TxNSdu[(LinTpTxSduId)].UpperLayerPduIdOfTxNSdu;
        /* Save internal ID of corresponding RxNSdu */
        tpCtrlTmp->LinTp_Curr_Rx_Id               = LinTp_TxNSdu[(LinTpTxSduId)].AssociatedRxNSduIdOfTxNSdu;

        /* Save buffer to local TP buffer */
        tpCtrlTmp->LinTp_Tx_Rx_Buffer[0]          = LinTp_TxNSdu[(LinTpTxSduId)].NADOfTxNSdu; 
        /*Store the actual length of Sdu to iterate for remaining length checks in next level of buffer handling*/
        tpCtrlTmp->LinTp_RemainingLength          = LinTpTxInfoPtr->SduLength; 

        /* Prepare frame: Set PCI information depending on the frame type */
        /*Check whether it is a Single Frame Request based on the length of Sdu received*/
        if (LinTpTxInfoPtr->SduLength <= 6u)
        {
          tpCtrlTmp->LinTp_Tx_Rx_Buffer[1]        = (uint8)(LinTpTxInfoPtr->SduLength & 0x07u); 
          /*Update the Tx Data buffer's index so that data is filled from the Index finished without over writing */
          tpCtrlTmp->LinTp_Tx_Rx_Buffer_Idx       = 2u; 
          /* prepare pdu structure for buffer request */
          tpCtrlTmp->LinTp_PduInfoPtr.SduDataPtr  = &tpCtrlTmp->LinTp_Tx_Rx_Buffer[2]; 
          tpCtrlTmp->LinTp_PduInfoPtr.SduLength   = LinTpTxInfoPtr->SduLength; 
        }
        /* Multi-Frame request */
        else
        {
          /* set FF token and upper nibble of data length */
          tpCtrlTmp->LinTp_Tx_Rx_Buffer[1]        = (uint8)(((LinTpTxInfoPtr->SduLength & 0x0F00u) >> 8u) | LinTp_FrameType_FF); 
          /* set lower data length byte */
          tpCtrlTmp->LinTp_Tx_Rx_Buffer[2]        = (uint8)  (LinTpTxInfoPtr->SduLength & 0x00FFu); 
          /*Update the Tx Data buffer's index so that data is filled from the Index finished without over writing */
          tpCtrlTmp->LinTp_Tx_Rx_Buffer_Idx       = 3u; 
          /* init sequence number, this number will be incremented after FF transmission for correct CF start value 1 */
          tpCtrlTmp->LinTp_SN                     = 0u; 
          /* prepare pdu structure for buffer request */
          tpCtrlTmp->LinTp_PduInfoPtr.SduDataPtr  = &tpCtrlTmp->LinTp_Tx_Rx_Buffer[3]; 
          tpCtrlTmp->LinTp_PduInfoPtr.SduLength   = 5u; 
        }

        /* Request PduR to provide transmission data */
        retVal = LinTp_TxDataRequest(tpCtrlTmp); 
        /* If request is rejected, close Tp connection */
        if (E_NOT_OK == retVal)
        { /* unable to obtain data from PduR - permanent failure, inform PduR directly */
          PduR_LinTpTxConfirmation(tpCtrlTmp->LinTp_Curr_UL_NSdu_Id, E_NOT_OK);
          /*reset the channel to IDLE upon request rejection*/
          tpCtrlTmp->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; 
        }
        /* Otherwise: save NAD, activate Tp timer, trigger diagnostic request schedule */
        else
        {
            /*Set port notification as Diagnostic request to continue the Tx process*/
          tpCtrlTmp->LinTp_PortNotification       = LINTP_DIAG_REQUEST; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          tpCtrlTmp->LinTp_ComModeRestore         = LINTP_DIAG_REQUEST; 
# endif
          /* load SF/FF confirmation timeout */
          tpCtrlTmp->LinTp_Timer                  = LinTp_TxNSdu[(LinTpTxSduId)].NasOfTxNSdu;
          /* next timeout reload value refers to CFs */
          tpCtrlTmp->LinTp_TimerReload            = LinTp_TxNSdu[(LinTpTxSduId)].NcsOfTxNSdu;
          /* save current NAD - only matching responses are accepted */
          tpCtrlTmp->LinTp_NAD_Requested          = LinTp_TxNSdu[(LinTpTxSduId)].NADOfTxNSdu; 
          /* clear response pending counter */
          tpCtrlTmp->LinTp_RespPendingCounter     = 0u; 
          /* clear P2 timer */
          tpCtrlTmp->LinTp_P2Timer                = 0u; 
        }
      }
    }
  }

/* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
    /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_TRANSMIT, errorId);
  }
# endif

  return retVal;
} 

#  if ( LINTP_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  LinTp_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo               Pointer to location to store the version information. Parameter must not be NULL.
 *  \config       LINTP_VERSION_INFO_API
 **********************************************************************************************************************/
void LinTp_GetVersionInfo (Std_VersionInfoType* versioninfo)
{
  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
/* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
  errorId = LINIF_E_NO_ERROR;
  /* Check validity of parameter versioninfo. Note: no uninit check is performed */
  if ( versioninfo == (Std_VersionInfoType) NULL_PTR )
  {
    /*Update error with the Pointer parameter, since it is NULL without any valid data*/  
    errorId = LINIF_E_PARAMETER_POINTER;
  }
  else
#  endif
  {
    /* Set versioninfo parameter with component information */
    versioninfo->vendorID           = (uint16)LINIF_VENDOR_ID; 
    versioninfo->moduleID           = (uint16)LINIF_MODULE_ID; 
    versioninfo->sw_major_version   = (uint8)LINIF_SW_MAJOR_VERSION; 
    versioninfo->sw_minor_version   = (uint8)LINIF_SW_MINOR_VERSION; 
    versioninfo->sw_patch_version   = (uint8)LINIF_SW_PATCH_VERSION; 
  }

  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
    /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_GETVERSIONINFO, errorId);
  }
#  endif
}
# endif /* LINIF_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 *  LinTp_Shutdown()
 **********************************************************************************************************************/
/*! \brief       Shutdowns the component.
 *  \details     Closes all pending transport protocol connection, frees all resources and sets the module into
 *               uninitialized state.
 *  \config      LINIF_DEV_ERROR_DETECT
 **********************************************************************************************************************/
void LinTp_Shutdown(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  LinTp_ControlType* tpCtrlTmp;
  uint8_least linIfChannelTmp;

  /* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  uint8 errorId;
  /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
  errorId = LINIF_E_NO_ERROR;
  /* Check if component is initialized */
  if ( (LinTp_Dev_InitDetect != LINTP_INIT) )
  {
    /*Update the error ID as uninitialized since shutdown can be done only if initalized and report to DET*/
    errorId = LINIF_E_UNINIT;
  }
  else
# endif
  {
    /* Clear/Reset all LIN TP resources */
    /*  Reset all transport protocol variables and connections for all LinIf channels */
    for (linIfChannelTmp = 0x00u; linIfChannelTmp < LinTp_GetSizeOfCtrl(); linIfChannelTmp++ )
    {
      tpCtrlTmp = LinTp_GetAddrCtrl(linIfChannelTmp);
      /*Reset TP timer*/
      tpCtrlTmp->LinTp_Timer            = 0u;
      /*Reset TP channel state as IDLE upon receiving Physical request*/
      tpCtrlTmp->LinTp_Ch_State         = LINTP_CHANNEL_IDLE;
      /*Clear NAD of request */
      tpCtrlTmp->LinTp_NAD_Requested    = 0u;
      /* stop session timer */
      tpCtrlTmp->LinTp_P2Timer          = 0u;

# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
      if( (tpCtrlTmp->LinTp_FuncRequest == LINTP_FUNC_REQUEST_PENDING)  ||
          (tpCtrlTmp->LinTp_FuncRequest == LINTP_FUNC_REQUEST_TRANSMITTED) )
      {
        /*Reset function request state to IDLE on SHUTDOWN*/
        tpCtrlTmp->LinTp_FuncRequest = LINTP_FUNC_REQUEST_IDLE;
      }
      if (tpCtrlTmp->LinTp_ComModeRestore != LINTP_APPLICATIVE_SCHEDULE)
      { /* release schedule Request */
        tpCtrlTmp->LinTp_PortNotification  = LINTP_APPLICATIVE_SCHEDULE;
      }
# endif
    }
    
/* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_DETECT == STD_ON )
/* Set LinTp initialization flag to UNINIT due to SHUTDOWN request*/
    LinTp_Dev_InitDetect = LINTP_INIT;
# endif
  }

/* If Development error Checks are enabled, check for below use cases */
# if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
    /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_SHUTDOWN, errorId);
  }
# endif
}

#  if ( LINTP_CANCEL_TRANSMIT_SUPPORTED == STD_ON )
/***********************************************************************************************************************
 *  LinTp_CancelTransmit()
 **********************************************************************************************************************/
/*! \brief       This is a dummy method introduced for interface compatibility.
 *  \details     This function has no functionality.
 *  \param[in]   LinTpTxSduId            Unique N-SDU identifier of LIN Tx N-SDU which transfer shall be cancelled.
 *  \return      E_NOT_OK                Cancellation request is always rejected.
 *  \config      LINIF_DEV_ERROR_DETECT and LINTP_CANCEL_TRANSMIT_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_CancelTransmit(PduIdType LinTpTxSduId)
{
  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
  errorId = LINIF_E_NO_ERROR;
  /* Check if component is initialized */
  if ((LinTp_Dev_InitDetect != LINTP_INIT) )
  {
      /*Update the error ID as uninitialized since Txcancellation can be done only if initalized and report to DET*/
     errorId = LINIF_E_UNINIT;
  }
  /* Check validity of parameter LinTpTxSduId */
  else if ( LinTpTxSduId >= LinTp_GetNumberOfLinTpTxNSdu() )
  {
      /*Update error with parameter since received SduId doesn't match with the configured  value*/
    errorId = LINIF_E_PARAMETER;
  }
  else if ( LinTp_GetChannelOfLinIfToLinTpChannel(LinTp_TxNSdu[LinTpTxSduId].CtrlIdxOfTxNSdu) == LinTp_Channel_Invalid )
  { 
      /* LinTp is not configured on requested LinIf channel */
    errorId = LINIF_E_PARAMETER;
  }
  else
#  endif
  {
    /*Function does nothing, just return E_NOT_OK */
  }

  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
      /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_CANCELTRANSMIT, errorId);
  }
#else
  /* cancellation request is always rejected */
  return E_NOT_OK;
#  endif
}
# endif /* LINTP_CANCEL_TRANSMIT_SUPPORTED */

#  if ( LINTP_CHANGE_PARAMETER_SUPPORTED == STD_ON )
/***********************************************************************************************************************
 *  LinTp_ChangeParameterr()
 **********************************************************************************************************************/
/*! \brief       This is a dummy method introduced for interface compatibility.
 *  \details     This function has no functionality.
 *  \param[in]   id                      ID of the connection for whose channel the change shall be done.
 *  \param[in]   parameter               Selects the parameter that the request shall change (STmin).
 *  \param[in]   value                   New value of the parameter.
 *  \return      E_NOT_OK                Request is always rejected.
 *  \config      LINIF_DEV_ERROR_DETECT and LINTP_CHANGE_PARAMETER_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_ChangeParameter(PduIdType id, TPParameterType parameter,uint16 value)
{
  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
  /* ----- Local Variables ---------------------------------------------- */
  uint8                                     errorId;
    /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
  errorId = LINIF_E_NO_ERROR;

  /* Check if component is initialized */
  if ( (LinTp_Dev_InitDetect != LINTP_INIT) )
  {
     /*Update the error ID as uninitialized since shutdown can be done only if initalized and report to DET*/
     errorId = LINIF_E_UNINIT;
  }
  else if ( id >= LinTp_GetNumberOfLinTpRxNSdu() )
  {
    errorId = LINIF_E_PARAMETER;
  }
  else if ( LinTp_GetChannelOfLinIfToLinTpChannel(LinTp_GetCtrlIdxOfRxNSdu(id)) == LinTp_Channel_Invalid )
  { /* LinTp is not configured on requested LinIf channel */
    errorId = LINIF_E_PARAMETER;
  }
  else
#  endif
  {
    /* Function does nothing, just return E_NOT_OK */
  }

  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
      /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_CHANGEPARAMETER, errorId);
  }
#else

  return E_NOT_OK;
#  endif


}
# endif /* LINTP_CHANGE_PARAMETER_SUPPORTED */

#  if ( LINTP_CANCEL_RECEIVE_SUPPORTED == STD_ON )
/***********************************************************************************************************************
 *  LinTp_CancelReceive()
 **********************************************************************************************************************/
/*! \brief       This is a dummy method introduced for interface compatibility.
 *  \details     This function has no functionality.
 *  \param[in]   LinTpRxSduId            Unique N-SDU identifier of LIN Rx N-SDU which transfer has to be cancelled.
 *  \return      E_NOT_OK                Cancellation request is always rejected.
 *  \config      LINIF_DEV_ERROR_DETECT and LINTP_CANCEL_RECEIVE_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_CancelReceive(PduIdType LinTpRxSduId)
{
    /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_DETECT == STD_ON )
/* ----- Local Variables ---------------------------------------------- */
  uint8              errorId;
  /*Iniitalize error ID as LINIF_E_NO_ERROR by default*/
  errorId = LINIF_E_NO_ERROR;
  /* Check if component is initialized */
  if ( (LinTp_Dev_InitDetect != LINTP_INIT) )
  {
      /*Update the error ID as uninitialized since  RxCanceellation can be done only if initalized and report to DET*/
     errorId = LINIF_E_UNINIT;
  }
  /* Check validity of parameter LinTpRxSduId */
 if ( LinTpRxSduId >= LinTp_GetNumberOfLinTpRxNSdu() )
  {
    errorId = LINIF_E_PARAMETER;
  }
  else if ( LinTp_GetChannelOfLinIfToLinTpChannel(LinTp_GetCtrlIdxOfRxNSdu(LinTpRxSduId)) == LinTp_Channel_Invalid )
  { /* LinTp is not configured on requested LinIf channel */
    errorId = LINIF_E_PARAMETER;
  }
  else
#  endif
  {
    /* Function does nothing, just return E_NOT_OK */
  }

  /* If Development error Checks are enabled, check for below use cases */
#  if ( LINIF_DEV_ERROR_REPORT == STD_ON )
/* Check whether TP initilaization done without any errors */
  if ( errorId != LINIF_E_NO_ERROR )
  {
      /*Report the error analyzed to DET*/
    (void)Det_ReportError(LINIF_MODULE_ID, LINIF_INSTANCE_ID_DET, LINTP_SID_CANCELRECEIVE, errorId);
  }
#else
  /* cancellation request is always rejected */
  return E_NOT_OK;
# endif 
}
/* LINTP_CANCEL_RECEIVE_SUPPORTED */
#endif

/***********************************************************************************************************************
 *  LinTp_TxScheduleProcessing() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Prepares a MRF for transmission used by transport protocol.
 *  \details     Checks whether TP transmission data is available for a connection on given channel and prepares the given
 *               LIN PDU.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_IfChannelDataPtr    Pointer to current channel data
 *  \param[in]   LinTp_LinPduPtr           Pointer to Lin PDU to be passed to driver
 *  \Note for Integration with IF - LinTp_LinPduPtr->SduPtr to be provided with the address of LIN IF Data buffer for Tx
 *  \Invoke on - Master request frame: Forward to LinTp if supported, otherwise skip MRF transmission
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
boolean LinTp_TxScheduleProcessing(LinTp_ControlType* const LinTp_CtrlPtr, LinIf_ChannelDataType* const LinTp_IfChannelDataPtr, Lin_PduType* const LinTp_LinPduPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean sendHeaderFlag;
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
  BufReq_ReturnType bufferReqRetVal;
  PduLengthType remainingPduRBufferSize;
# endif
  /* By default, MRF header shall be transmitted */
  sendHeaderFlag = TRUE;  

  /* If a functional request is pending for transmission */
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
  if ( LinTp_CtrlPtr->LinTp_FuncRequest == LINTP_FUNC_REQUEST_PENDING )
  {
    /* abuse the LinIf buffer for a functional MRF because this is handled in one cycle  */
    LinTp_LinPduPtr->SduPtr = &(LinTp_IfChannelDataPtr->LinIf_TxData[0]); 

    /* prepare buffer */
    LinTp_LinPduPtr->SduPtr[0] = LINTP_FUNCTIONAL_REQ_ID; 
    LinTp_LinPduPtr->SduPtr[1] = (uint8)LinTp_CtrlPtr->LinTp_FuncPduInfoPtr.SduLength; 
    LinTp_CtrlPtr->LinTp_FuncPduInfoPtr.SduDataPtr = &(LinTp_LinPduPtr->SduPtr[2]); 

    /* Request PduR to copy transmission data into provided local Tp buffer */
    bufferReqRetVal = PduR_LinTpCopyTxData(LinTp_CtrlPtr->LinTp_Curr_Func_NSdu_Id, &(LinTp_CtrlPtr->LinTp_FuncPduInfoPtr), 
                                                  NULL_PTR, &remainingPduRBufferSize);
    /* If transmission data is successfully provided */
    if (bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK)
    {
      /* Stuff unused payload bytes with fill value if necessary */
      uint8 i;
      uint8 LinTp_LinPduPtr_Start = LinTp_LinPduPtr->SduPtr[1] + 2u;
      if(LinTp_LinPduPtr_Start<LINIF_LINPDU_SIZE)
      {
        for (i = LinTp_LinPduPtr_Start ; i < LINIF_LINPDU_SIZE; i++)
      {
        LinTp_LinPduPtr->SduPtr[i] = 0xFFu; 
        }
      }
      LinTp_CtrlPtr->LinTp_FuncRequest = LINTP_FUNC_REQUEST_TRANSMITTED; 
    }
    /* Otherwise: request for transmission data not successful */
    else
    {
      /* Abort functional request if data cannot be provided at this point */
      sendHeaderFlag                                = FALSE;
      LinTp_CtrlPtr->LinTp_FuncRequest              = LINTP_FUNC_REQUEST_IDLE; 
      /* reject attempt and free buffer */
      LinTp_CtrlPtr->LinTp_PduRNotification        |= LinTp_PduRNotificationTxTm; 
      /* result is always E_NOT_OK for TxTm notification */
      LinTp_CtrlPtr->LinTp_PduRNSduIdTm             = LinTp_CtrlPtr->LinTp_Curr_Func_NSdu_Id; 
    }
  }
  /* Otherwise if transmission data for physical request already available in local buffer, transmit MRF */
  else if ( LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_TX_VALID )
# else
  if ( LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_TX_VALID )
# endif
  {
    /* Update provided Lin Pdu with transmission data */
    LinTp_LinPduPtr->SduPtr = (uint8*)(&(LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[0])); 
  }
  /* Otherwise: Skip transmission of MRF frame */
  else
  {
    sendHeaderFlag = FALSE;
  }

  return sendHeaderFlag;
}

/***********************************************************************************************************************
 *  LinTp_CloseActiveConnection() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Terminates an ongoing Rx or Tx connection.
 *  \details     Aborts an active TP connection on given channel and notify upper layer. Afterwards, the TP channel state
 *               is idle.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
void LinTp_CloseActiveConnection(LinTp_ControlType* const LinTp_CtrlPtr)
{
  /*Terminating ongoing Tx or Rx connection is possible when channel is not in IDLE state*/
  if ( LinTp_CtrlPtr->LinTp_Ch_State != LINTP_CHANNEL_IDLE ) 
  {
    /* If Tx connection is active, abort Tp connection and inform PduR */
    if ( (LinTp_CtrlPtr->LinTp_Ch_State & LINTP_CHANNEL_TX_MSK ) == LINTP_CHANNEL_TX_MSK )
    {
      LinTp_TxCloseConnection(LinTp_CtrlPtr); 
    }
    /* If Rx connection is active, abort Tp connection and inform PduR */
    else
    { /* not idle and no Tx connection implies Rx connection */
      LinTp_RxCloseConnection(LinTp_CtrlPtr); 
    }
  }
}

/***********************************************************************************************************************
 *  LinTp_TxCloseConnection
 **********************************************************************************************************************/
/*! \brief       Closes a Tp Tx connection.
 *  \details     Resets a Tx connection back to idle and notifies the PduR. It does not check if a Tx
 *               connection is active.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \pre         A Tx connection shall be active.
 **********************************************************************************************************************/
static void LinTp_TxCloseConnection(LinTp_ControlType* const LinTp_CtrlPtr)
{
  /* Disable TP timer and set channel state to idle */
  LinTp_CtrlPtr->LinTp_Timer                  = 0u; 
  LinTp_CtrlPtr->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; 
  /* Inform PduR about connection abortion and request applicative schedule from BswM */
  LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationTx; 
  LinTp_CtrlPtr->LinTp_PduRNotifyResultTx     = E_NOT_OK; 
  LinTp_CtrlPtr->LinTp_PduRNSduIdTx           = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
  LinTp_CtrlPtr->LinTp_PortNotification       = LINTP_APPLICATIVE_SCHEDULE; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
  LinTp_CtrlPtr->LinTp_ComModeRestore         = LINTP_APPLICATIVE_SCHEDULE; 
# endif
}

/***********************************************************************************************************************
 *  LinTp_RxCloseConnection
 **********************************************************************************************************************/
/*! \brief       Closes a Tp Rx connection.
 *  \details     Resets a Rx connection back to idle and notifies the PduR. Does not check if an Rx
 *               connection is active.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \pre         An Rx connection shall be active.
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
static void LinTp_RxCloseConnection(LinTp_ControlType* const LinTp_CtrlPtr)
{
  /* Disable TP and P2 Timer, reset NAD, set channel state to idle */
  LinTp_CtrlPtr->LinTp_Timer                  = 0u; 
  LinTp_CtrlPtr->LinTp_NAD_Requested          = 0u; /* reset requested NAD - only one response accepted for each request */ 
  LinTp_CtrlPtr->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; 
  /* clear P2 timer */
  LinTp_CtrlPtr->LinTp_P2Timer                = 0u; 
  /* Inform PduR about connection abortion, request applicative schedule from BswM */
  LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationRx; 
  LinTp_CtrlPtr->LinTp_PduRNotifyResultRx     = E_NOT_OK; 
  LinTp_CtrlPtr->LinTp_PduRNSduIdRx           = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
  if ( LinTp_CtrlPtr->LinTp_PortNotification == LinTp_PortNotificationIdle ) 
  { /* No new functional request pending */
    LinTp_CtrlPtr->LinTp_PortNotification     = LINTP_APPLICATIVE_SCHEDULE; 
  }
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
  LinTp_CtrlPtr->LinTp_ComModeRestore         = LINTP_APPLICATIVE_SCHEDULE; 
# endif
}

/***********************************************************************************************************************
 *  LinTp_BufferPolling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Requests data from PduR for current Tp connection, both Rx and Tx.
 *  \details     Polls for suspended buffer handling. Handles Rx and Tx connections.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \note        Function can be polled.
 *  \Invoke on - Request periodically PduR for transmission data or reception buffer
 **********************************************************************************************************************/
void LinTp_BufferPolling(LinTp_ControlType* const LinTp_CtrlPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* If TX connection active but not sufficient data for transmission available */
  if ( LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_TX_INVALID)
  {
    /* Request transmission data from PduR (-> LinTp_TxDataRequest() ) */
    retVal = LinTp_TxDataRequest(LinTp_CtrlPtr); 

    /* If PduR request is denied, abort TX connection */
    if (E_NOT_OK == retVal)
    { /* unable to obtain data from PduR - permanent failure */
      LinTp_TxCloseConnection(LinTp_CtrlPtr); 
    }
  }
  /* Otherwise if RX connection active but not sufficient reception buffer previously indicated by PduR */
  else if ( (LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX_SUSPENDED ) || (LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START) )
  {
    /* Poll PduR again if receive buffer is available (-> LinTp_RxDataBufferHandling() ) */
    /* provide NULL pointer as second argument as the buffer handling is performed on existing local buffer */
    LinTp_RxDataBufferHandling(LinTp_CtrlPtr, NULL_PTR); 
  }
  else
  {
    /* No TP connection active or data available, nothing to do */
  }
}

/***********************************************************************************************************************
 *  LinTp_TxDataRequest - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the transmission data retrieval from PduR.
 *  \details     Requests data from PduR and store it to local LinTp buffer.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \return      E_OK                      Data retrieved or request pending, connection to PduR is alive
 *  \return      E_NOT_OK                  Data request denied, PduR has aborted current connection
 *  \Invoke on - 1. Initial invocation will be done by LinTp_Transmit which will ignite the call of this function in 
 *               LinTpBufferPolling
 *               2. Invoke this function whenever IF wants to send MRF
 **********************************************************************************************************************/
Std_ReturnType LinTp_TxDataRequest(LinTp_ControlType* const LinTp_CtrlPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  BufReq_ReturnType bufferReqRetVal;
  uint8 byteIndex;
  /* dummy variable for call, not used till now */
  PduLengthType remainingPduRBufferSize;  
  /*Initialize with E_OK status*/
  retVal = (Std_ReturnType)E_OK;
  /*Update channel state to be invalid updn the init of TxData transmission request */
  LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_TX_INVALID; 

  /* Request PduR to copy transmission data into provided local Tp buffer */
  bufferReqRetVal = PduR_LinTpCopyTxData(LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id, &(LinTp_CtrlPtr->LinTp_PduInfoPtr), NULL_PTR, &remainingPduRBufferSize); 

  /* If transmission data is successfully provided */
  if ( bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK )
  { /* all requested data was copied into local buffer */

    /* In case it's the last frame in current connection, stuff frame will fill bytes */
    LinTp_CtrlPtr->LinTp_RemainingLength = LinTp_CtrlPtr->LinTp_RemainingLength - LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength; 
    if (LinTp_CtrlPtr->LinTp_RemainingLength == 0u)
    {
      /* SF or last CF - check if stuffing is necessary */
      if ((LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx + LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength) < 8u)
      {
        /* stuff with fill bytes */
        for (byteIndex = (uint8)(LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx + LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength); byteIndex < 8u; byteIndex++)
        {
          LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[byteIndex]  = 0xFFu; 
        }
      }
      /*Upon completion of filling unused bytes with 0xFF, lets reset the length to avoid confusion*/
      LinTp_CtrlPtr->LinTp_RemainingLength                = 0u; 
    }
    /* else: more frames to come */
    /* Change channel state since TP's Tx valid buffer id ready to be transmitted*/
    LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_TX_VALID; 
  }
  /* Otherwise if PduR does not accept request, abort or delay transmission */
  else
  {
    if ( bufferReqRetVal == (BufReq_ReturnType)BUFREQ_E_BUSY )
    {
      /* retry in next main cycle, return E_OK to not abort request */
    }
    else /* (BufReq_ReturnType)BUFREQ_E_NOT_OK ) */
    {
      /* abort transmission */
      retVal = (Std_ReturnType)E_NOT_OK;
    }
  }

  return(retVal);
}

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling
 **********************************************************************************************************************/
/*! \brief       Handles the received data and passes it to PduR.
 *  \details     Passes pending local received data to PduR and performs delayed buffer retry handling.
 *  \param[in]   LinTp_CtrlPtr         Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr       Source pointer (SRF buffer), provide null at repeated call to work on local buffer
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling(LinTp_ControlType* const LinTp_CtrlPtr, const uint8 *LinTp_LinSduPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType bufferReqRetVal;
  uint8_least byteIndex;
  PduLengthType remainingPduRBufferSize = 0u;

  /* Check if a PduR notification is already pending in this cycle */
  if ( (LinTp_CtrlPtr->LinTp_PduRNotification & LinTp_PduRNotificationRx) == LinTp_PduRNotificationIdle )
  { /* no PduR event to notify in this cycle, proceed with normal handling */

    /* If reception handling to PduR not yet started, initiate connection (->LinTp_RxDataBufferHandling_StartOfReception()) */
    if (LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START)
    { /* actual start of PduR reception handling */
      LinTp_RxDataBufferHandling_StartOfReception(LinTp_CtrlPtr); 
    }

    /* If start of reception handling succeeded or connection already established, update local buffer */
    if ( ( LinTp_LinSduPtr == NULL_PTR ) || ( LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_IDLE ) )
    {
      /* repeated call or StartOfReception call failed, thus SduDataPtr already point to local buffer or receive data not needed */
    }
    else
    {
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length; 
      /* copy data to local buffer in any case for data consistency, important for delayed handling */
      for (byteIndex = 0u; byteIndex < LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length; byteIndex++)
      {
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[byteIndex] = LinTp_LinSduPtr[(LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx + byteIndex) & \
                                                                      LINTP_LOCAL_BUFFER_SIZE_MASK]; 
      }
      /* set pdu pointer given to PduR to local received data - note that directly point to LinTp_LinSduPtr is not consistent as it may get overwritten(!) */
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduDataPtr = &LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[0]; 
    }

    /* delayed reception buffer handling */
    /* If temporarily no sufficient receive buffer is available */
    if ( (LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX_SUSPENDED) || (LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX_POLLBUFFER) )
    {
      /* Poll PduR for current buffer size (by passing 0 as length) */
      /* continue reception if data can be copied in the next call */
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength         = 0u; 
      bufferReqRetVal = PduR_LinTpCopyRxData( LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id, &LinTp_CtrlPtr->LinTp_PduInfoPtr, \
                                              &remainingPduRBufferSize); 
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength         = LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length; 

      /* If PduR indicates sufficient buffer, continue normal reception handling, otherwise transit to suspended state */
      if ( (bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK) && (remainingPduRBufferSize >= LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length) )
      {
        /* buffer available, provide below the received data to PduR */
        LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX; 
      }
      else
      {
        /* If we reach this location in state LINTP_CHANNEL_BUSY_RX_POLLBUFFER, LinTp_LinSduPtr is never NULL.
           The SRF response has just been received, however local TP buffer occupied and no Pdur buffer available, suppress further SRF header */
        LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX_SUSPENDED; 
      }
    }

    /* If receive buffer available, provide received data to PduR (-> LinTp_RxDataBufferHandling_CopyRxData() ) */
    if ( LinTp_CtrlPtr->LinTp_Ch_State == LINTP_CHANNEL_BUSY_RX )
    { /* valid state, provide receive data to upper layer */
      LinTp_RxDataBufferHandling_CopyRxData(LinTp_CtrlPtr); 
    }
  }
  /* Otherwise: PduR notification pending, postpone buffer handling till next cycle */
  else
  {
    /* postpone buffer handling till next cycle in order to not overwrite post notification */
    if (LinTp_LinSduPtr != NULL_PTR)
    {
      /* prepare pdu info structure */
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length; 
      LinTp_CtrlPtr->LinTp_PduInfoPtr.SduDataPtr = &LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[0]; 
      for (byteIndex = 0u; byteIndex < LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length; byteIndex++)
      {
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[byteIndex] = LinTp_LinSduPtr[(LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx + byteIndex) & LINTP_LOCAL_BUFFER_SIZE_MASK];
      }
    }
  }
}

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling_StartOfReception()
 **********************************************************************************************************************/
/*! \brief       Handles the interface with PduR for setting up a receive connection.
 *  \details     Initiates a Tp receive connection to PduR.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling_StartOfReception(LinTp_ControlType* const  LinTp_CtrlPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType bufferReqRetVal;
  PduLengthType remainingPduRBufferSize = 0u;

  /* Start actual reception handling with PduR (->PduR_LinTpStartOfReception()) */
  bufferReqRetVal = PduR_LinTpStartOfReception(LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id, NULL_PTR, LinTp_CtrlPtr->LinTp_RemainingLength, &remainingPduRBufferSize);

  /* If request is accepted and available buffer size sufficient, proceed */
  if ( (bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK) && (remainingPduRBufferSize >= LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length ) )
  {
    /* sufficient buffer can be provided for first frame, just proceed */
    LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX; 
  }
  /* Otherwise: */
  else
  {
    /* Reset TP connection */
    LinTp_CtrlPtr->LinTp_Timer = 0u; 
    LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_IDLE; 
    LinTp_CtrlPtr->LinTp_NAD_Requested = 0u; 
    if ( LinTp_CtrlPtr->LinTp_PortNotification == LinTp_PortNotificationIdle ) 
    { /* No new functional request pending */
      LinTp_CtrlPtr->LinTp_PortNotification = LINTP_APPLICATIVE_SCHEDULE; 
    }
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
    LinTp_CtrlPtr->LinTp_ComModeRestore = LINTP_APPLICATIVE_SCHEDULE; 
# endif
    /* clear P2 timer */
    LinTp_CtrlPtr->LinTp_P2Timer = 0u; 

    /* Report termination of reception if request was not rejected but provided buffer is too small */
    if ( (bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK) || (bufferReqRetVal == (BufReq_ReturnType)BUFREQ_E_BUSY) )
    {
      /* report abort of reception to PduR, e.g. if the provided buffer is too small.
          Actually this should never happen - would be a configuration fault in PduR */
      LinTp_CtrlPtr->LinTp_PduRNotification    |= LinTp_PduRNotificationRx; 
      LinTp_CtrlPtr->LinTp_PduRNotifyResultRx   = E_NOT_OK; 
      LinTp_CtrlPtr->LinTp_PduRNSduIdRx         = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
    }
    /* else: nothing to report to PduR, no connection was established */

  }
}

/***********************************************************************************************************************
 *  LinTp_RxDataBufferHandling_CopyRxData()
 **********************************************************************************************************************/
/*! \brief       Handles the interface with PduR for reception data.
 *  \details     Provides PduR with TP reception data and handles internal buffer states.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
static void LinTp_RxDataBufferHandling_CopyRxData(LinTp_ControlType* const  LinTp_CtrlPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType bufferReqRetVal;
  PduLengthType remainingPduRBufferSize = 0u;
  PduLengthType succFramePayloadSize;

  /* Request PduR to copy provided reception data (->PduR_LinTpCopyRxData() ) */
  bufferReqRetVal = PduR_LinTpCopyRxData( LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id, &LinTp_CtrlPtr->LinTp_PduInfoPtr, \
                                          &remainingPduRBufferSize); 

  /* If request is accepted */
  if ( bufferReqRetVal == (BufReq_ReturnType)BUFREQ_OK )
  {
    /* Rx data copied by PduR */
    /* If all expected data of whole message is received*/
    LinTp_CtrlPtr->LinTp_RemainingLength = (LinTp_CtrlPtr->LinTp_RemainingLength -  \
                                            LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength); 
    /* Close TP connection and inform PduR about completed successful reception */
    if (LinTp_CtrlPtr->LinTp_RemainingLength == 0u)
    {
      LinTp_CtrlPtr->LinTp_Timer                  = 0u; 
      LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationRx; 
      LinTp_CtrlPtr->LinTp_PduRNotifyResultRx     = E_OK; 
      LinTp_CtrlPtr->LinTp_PduRNSduIdRx           = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
      LinTp_CtrlPtr->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; 

      /* reset requested NAD and change schedule only if previous received frame was not a response pending */
     /* no response pending frame */
        LinTp_CtrlPtr->LinTp_NAD_Requested = 0u; 

        if ( LinTp_CtrlPtr->LinTp_PortNotification == LinTp_PortNotificationIdle ) 
        { /* No new functional request pending */
          LinTp_CtrlPtr->LinTp_PortNotification   = LINTP_APPLICATIVE_SCHEDULE; 
        }
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
        LinTp_CtrlPtr->LinTp_ComModeRestore       = LINTP_APPLICATIVE_SCHEDULE; 
# endif
        /* clear P2 timer */
        LinTp_CtrlPtr->LinTp_P2Timer              = 0u; 
    }
    /* Otherwise: more frames expected */
    else
    {
      /* Calculate payload size of next frame */
      if ( LinTp_CtrlPtr->LinTp_RemainingLength < 6u )
      {
        succFramePayloadSize = LinTp_CtrlPtr->LinTp_RemainingLength;
      }
      else
      {
        succFramePayloadSize = 6u;
      }

      /* If next frame fits in remaining PduR buffer just proceed, otherwise enter pending state (poll buffer, no SRF header will be transmitted) */
      if ( remainingPduRBufferSize >= succFramePayloadSize)
      {
        /* next frame can be stored, just proceed */
        LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX; 
      }
      else
      {
        /* next frame cannot be stored, however local buffer is empty in any case, so schedule next header */
        /* This case is only entered when a FF or CF was handled, received data was successfully given to PduR
            but the remaining buffer size is too small to store the following CF. For efficiency, the next CF
            header is scheduled anyway but remember to check PduR for reception buffer:
            - either there will be enough free buffer available so the handling is as usual (but no header
              transmission delay was introduced!)
            - or still not sufficient buffer available, then transit to LINTP_CHANNEL_BUSY_RX_SUSPENDED state */
        LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX_POLLBUFFER; 
      }
    }
  }
  /* Otherwise: */
  else
  {
    /* Quit reception and report abortion to PduR */
    LinTp_RxCloseConnection(LinTp_CtrlPtr); 
  }
}

/***********************************************************************************************************************
 *  LinTp_Timer_Handling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the TP Timer working
 *  \details     Runs the Lin TP timer and handles the timeout consequential actions.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
void LinTp_Timer_Handling(LinTp_ControlType* LinTp_CtrlPtr)
{
    /* Lin Tp timeout handling */
    if (LinTp_CtrlPtr->LinTp_Timer > 0u)
    {
      LinTp_CtrlPtr->LinTp_Timer--; 
      if (LinTp_CtrlPtr->LinTp_Timer == 0u)
      { /* timeout on running transmission / reception occurred check current state */
        LinTp_CloseActiveConnection(LinTp_CtrlPtr); 
      }
    }
}

/***********************************************************************************************************************
 *  LinTp_P2_Timer_Handling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the P2 timer working
 *  \details     Runs the Lin P2 timer and handles the timeout consequential actions.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   Channel             Channel nummber
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
void LinTp_P2_Timer_Handling(LinTp_ControlType* LinTp_CtrlPtr, uint8 Channel)
{
      LinTp_ControlType* Tmp_CtrlPtr = LinTp_CtrlPtr;
      if (Tmp_CtrlPtr->LinTp_P2Timer > 0u)
      {
        Tmp_CtrlPtr->LinTp_P2Timer--; 
        if (Tmp_CtrlPtr->LinTp_P2Timer == 0u)
        { /* timeout occurred - indicate release */
          Tmp_CtrlPtr->LinTp_PortNotification        = LINTP_APPLICATIVE_SCHEDULE; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          Tmp_CtrlPtr->LinTp_ComModeRestore          = LINTP_APPLICATIVE_SCHEDULE; 
# endif
          /* clear request NAD to prevent further reception after timeout */
          Tmp_CtrlPtr->LinTp_NAD_Requested           = 0u; 
        }
      }
}

/***********************************************************************************************************************
 *  LinTp_MainPostProcessing() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Notifies the upper layers after each main processing function cycle of the LIN TP
 *  \details     LinTp post notification to the PduR of last transmitted/ received TP message
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \When to Invoke - After IF main processing done for LIN TP's Tx or Rx service
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
void LinTp_MainPostProcessing(LinTp_ControlType* LinTp_CtrlPtr, uint8 Channel)
{
    /* Inform PduR about transmitted diagnostic frame */
    if ( (LinTp_CtrlPtr->LinTp_PduRNotification & LinTp_PduRNotificationTx) != LinTp_PduRNotificationIdle )
    { /* report transmitted frame to PduR with enabled interrupts */
      PduR_LinTpTxConfirmation(LinTp_CtrlPtr->LinTp_PduRNSduIdTx, LinTp_CtrlPtr->LinTp_PduRNotifyResultTx);
    }

    if ( (LinTp_CtrlPtr->LinTp_PduRNotification & LinTp_PduRNotificationRx) != LinTp_PduRNotificationIdle )
    { /* report received frame to PduR with enabled interrupts */
      PduR_LinTpRxIndication(LinTp_CtrlPtr->LinTp_PduRNSduIdRx, LinTp_CtrlPtr->LinTp_PduRNotifyResultRx);
    }

# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
    /**********************************************************
    / LinTp post notification to the PduR of last requested TP message of LinTp_Transmit
    **********************************************************/
    /* Inform PduR about received diagnostic frame */
    if ( (LinTp_CtrlPtr->LinTp_PduRNotification & LinTp_PduRNotificationTxTm) != LinTp_PduRNotificationIdle )
    { /* report transmitted frame to PduR with enabled interrupts */
      PduR_LinTpTxConfirmation(LinTp_CtrlPtr->LinTp_PduRNSduIdTm, E_NOT_OK);
    }
# endif

    /* clear pending notification to PduR if set */
    LinTp_CtrlPtr->LinTp_PduRNotification       = LinTp_PduRNotificationIdle; 
}

/***********************************************************************************************************************
 *  LinTp_RxIndication - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a SRF.
 *  \details     This function processes a received SRF containing transport protocol data.
 *  \param[in]   LinIf_LinIfChannel        Local LinIf channel identifier
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
void LinTp_RxIndication(NetworkHandleType LinIf_LinIfChannel,const uint8* LinTp_LinSduPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  LinTp_ControlType* tpCtrlTmp;
  
  /*Get the Control data pointer of the corresponding channel*/
  tpCtrlTmp = LinTp_GetAddrCtrl(LinIf_LinIfChannel);
  if(LinTp_LinSduPtr != NULL_PTR)
  {
  /*  Preprocess NAD: inspect if Strict-NAD check is disabled and received frame is valid SF or FF */
  if( ( (LinTp_LinSduPtr[1] & 0xF0u) == LinTp_FrameType_SF) ||  \
        ( (LinTp_LinSduPtr[1] & 0xF0u) == LinTp_FrameType_FF) )  
  { /* NAD check disabled; an unexpected NAD is only expected for new reception (SF or FF); during a multi frame reception a new NAD is discarded */

    /* To avoid further 'Is NAD check option enabled' case distinctions, fake further comparisons by setting requested NAD to received one */
    tpCtrlTmp->LinTp_NAD_Requested = LinTp_LinSduPtr[0]; 

    /*  If received NAD belongs to a configured RxNSdu */
    /* If actual received slave response does not match with Rx NSdu reference stored during transmission request of TxNSdu
       or no prior transmission request handled at all, search for the correct RxNSdu. */
    if ( LinTp_GetNADOfRxNSdu(tpCtrlTmp->LinTp_Curr_Rx_Id) != LinTp_LinSduPtr[0] ) 
    {
      uint8_least sduIdx;
      for (sduIdx = 0u; sduIdx < TP_MAX_RXNSDU; sduIdx++) 
      {
        if ( (LinTp_RxNSdu[sduIdx].NADOfRxNSdu == LinTp_LinSduPtr[0]) &&
             (LinTp_RxNSdu[(sduIdx)].CtrlIdxOfRxNSdu == LinIf_LinIfChannel) ) 
        {
          /* If RxNSdu found, reception of frame is accepted */
          tpCtrlTmp->LinTp_Curr_Rx_Id = (PduIdType)sduIdx; 
          break;
        }
      }
      /* If no RxNSdu found, skip processing of frame */
      /* processing is skipped below */
    }
  }

  /* If no transmission is active and received NAD is accepted (only if Strict-NAD check enabled) */
  /* a possible active Rx connection is handled below */
  if ( ((tpCtrlTmp->LinTp_Ch_State & LINTP_CHANNEL_TX_MSK ) == 0u) && \
        (tpCtrlTmp->LinTp_NAD_Requested == LinTp_LinSduPtr[0]) )
  {
    /* Test frame type for valid PCI */
    switch (LinTp_LinSduPtr[1] & 0xF0u)
    {

    /***********************************************************************************************************
     *  LinTp_FrameType_SF
     ***********************************************************************************************************/
    case LinTp_FrameType_SF:
      /* Single frame received (-> LinTp_RxIndication_SF() ) */
      LinTp_RxIndication_SF(tpCtrlTmp, LinTp_LinSduPtr); 
      break;

    /***********************************************************************************************************
     *  LinTp_FrameType_FF
     ***********************************************************************************************************/
    case LinTp_FrameType_FF:
      /* First frame received (-> LinTp_RxIndication_FF() ) */
      LinTp_RxIndication_FF(tpCtrlTmp, LinTp_LinSduPtr); 
      break;

    /***********************************************************************************************************
     *  LinTp_FrameType_CF
     ***********************************************************************************************************/
    case LinTp_FrameType_CF:
      /* Consecutive frame received (-> LinTp_RxIndication_CF() ) */
      LinTp_RxIndication_CF(tpCtrlTmp, LinTp_LinSduPtr); 
      break;

    default:
      /* PDUs with unexpected PCI types shall be ignored (according to LIN standard) */
      break;
    }

  }
  /* Otherwise if invalid NAD received and reception active, close Rx connection */
  else
  {
    /* stop of reception and notification to PduR is only performed if channel state is not idle, thus frames with
       unknown NADs are ignored if they do not interfere an ongoing reception. Furthermore, if no connection is
       established there is no upper layer PduId to report anyway */
    if ( ( tpCtrlTmp->LinTp_Ch_State & LINTP_CHANNEL_RX_MSK ) != 0u )
    { /* Unexpected NAD received - stop receiving Tp message */
      LinTp_RxCloseConnection(tpCtrlTmp); 
    }
  }
  }
  /*Coverity fix - Else - Close connection if Null Ptr is received*/
   
  
}

/***********************************************************************************************************************
 *  LinTp_RxIndication_SF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a single frame N-PDU.
 *  \details     This function processes a received SRF containing a single frame. Terminates a possible ongoing reception
 *               on the same channel, performs response pending frame handling if necessary and initiates a new receive
 *               connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
static void LinTp_RxIndication_SF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean proceedHandlingFlag;

  if(LinTp_LinSduPtr != NULL_PTR)
  {
  /* Check if NAD of response match the NAD of request */
  if ( LinTp_GetNADOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id) == LinTp_LinSduPtr[0] ) 
  {
        
    /* Check if length information in SF is valid */
    if ( (LinTp_LinSduPtr[1] > 0x00u) && (LinTp_LinSduPtr[1] <= 0x06u) )
    {
      proceedHandlingFlag = TRUE;

      /* If RX connection already active on channel, abort it and inform PduR */
      if( ( LinTp_CtrlPtr->LinTp_Ch_State & LINTP_CHANNEL_RX_MSK) != 0u )
      { /* Indicate error and restart reception with new SF */
        LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationRx; 
        LinTp_CtrlPtr->LinTp_PduRNotifyResultRx     = E_NOT_OK; 
        /* Upper layer ID of currently active connection */ 
        LinTp_CtrlPtr->LinTp_PduRNSduIdRx           = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
      }
      /* Otherwise if received frame is a response pending frame (in this case channel state always idle) */
      else if ( (LinTp_LinSduPtr[1] == 0x03u) &&
                (LinTp_LinSduPtr[2] == 0x7Fu) &&
                (LinTp_LinSduPtr[4] == 0x78u) )
      { /* response pending frame */

        /* Update RP counter and check if maximum allowed number of response pending frames received */
        LinTp_CtrlPtr->LinTp_RespPendingCounter++; 
        if (LinTp_CtrlPtr->LinTp_RespPendingCounter > LinTp_MaxRespPendingFrames_Config())
        {
          /* reset requested NAD - only one response accepted for each request */
          LinTp_CtrlPtr->LinTp_NAD_Requested          = 0u; 
          /* important to abort timeout handling */ 
          LinTp_CtrlPtr->LinTp_P2Timer                = 0u; 
          LinTp_CtrlPtr->LinTp_PortNotification       = LINTP_APPLICATIVE_SCHEDULE; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          LinTp_CtrlPtr->LinTp_ComModeRestore         = LINTP_APPLICATIVE_SCHEDULE; 
# endif
          /* no further handling required */
          proceedHandlingFlag = FALSE;
        }
        else
        {
          /* Reinitialize P2 timeout with P2Max */
          LinTp_CtrlPtr->LinTp_P2Timer = LinTp_GetP2MaxTime(); 
        }
      /* Otherwise: Normal SF received */
      }
      else
      { /* reset RP counter to trigger schedule change request in LinTp_Rx_Fill_Buffer */
        LinTp_CtrlPtr->LinTp_RespPendingCounter = 0u; 
      }

      if ( proceedHandlingFlag == TRUE )
      {
        /* Initialize new RX connection */
        LinTp_CtrlPtr->LinTp_Timer                       = LinTp_GetNcrOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 
        LinTp_CtrlPtr->LinTp_TimerReload                 = LinTp_GetNcrOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 
        LinTp_CtrlPtr->LinTp_RemainingLength             = (uint16)(LinTp_LinSduPtr[1]); 
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length         = (uint8)(LinTp_CtrlPtr->LinTp_RemainingLength); 
        /* index of the buffer copied from - SF:2 */
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx            = 2u;  
        LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id             = LinTp_GetUpperLayerPduIdOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 

        /* Reset P2 timer */
# if ( LINTP_FORWARD_RESPONSEPENDING_TO_PDUR == STD_ON )
# else
        /* stop P2 timer after receiving start of response */
        LinTp_CtrlPtr->LinTp_P2Timer                     = 0u; 
# endif

        LinTp_CtrlPtr->LinTp_Ch_State                    = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START; 

        /* Start receive buffer handling (-> LinTp_RxDataBufferHandling() ) */
        /* do buffer handling in any case, on suspended state data is copied to local buffer */
           
      }
    }
    /* else: ignore SF with invalid length */
	}
    /* else: NULL ptr received */
  }
  /* else: entered only for unknown (not configured) NAD and Strict NAD check disabled - ignore frame */

} 

/***********************************************************************************************************************
 *  LinTp_GetP2MaxTime() 
 **********************************************************************************************************************/
/*! \brief       Provides  the P2 timer maximum count
 *  \details     Returns P2 timer maximum count for reloading the timer
 *  \param[in]   NULL
 **********************************************************************************************************************/
static uint16 LinTp_GetP2MaxTime(void)
{
    return LIN_TP_P2_MAX_COUNT;
}

/***********************************************************************************************************************
 *  LinTp_RxIndication_FF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a first frame N-PDU.
 *  \details     This function processes a received SRF containing a first frame. Terminates a possible ongoing reception
 *               on the same channel and initiates a new receive connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
static void LinTp_RxIndication_FF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr)
{
  /*Coverity fix*/
  if(LinTp_LinSduPtr != NULL_PTR)
  {
  /* Check if NAD of response match the NAD of request */
  if ( LinTp_GetNADOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id) == LinTp_LinSduPtr[0] ) 
  {
    /* Check if length information in FF is valid */
    if ( ( ((uint16)(LinTp_LinSduPtr[1] & 0x0Fu) << 8u) | (LinTp_LinSduPtr[2]) ) > 6u)
    { /* valid FF length */

      /* If RX connection already active on channel, abort it and inform PduR */
      if( ( LinTp_CtrlPtr->LinTp_Ch_State & LINTP_CHANNEL_RX_MSK) != 0u )
      { /* Indicate error and postpone actual reception handling of FF to next cycle */
        LinTp_CtrlPtr->LinTp_Timer = 0u; 
        LinTp_CtrlPtr->LinTp_PduRNotification |= LinTp_PduRNotificationRx; 
        LinTp_CtrlPtr->LinTp_PduRNotifyResultRx = E_NOT_OK; 
        LinTp_CtrlPtr->LinTp_PduRNSduIdRx = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
      }

      /* Initialize new RX connection */
      LinTp_CtrlPtr->LinTp_Timer = LinTp_GetNcrOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 
      LinTp_CtrlPtr->LinTp_TimerReload = LinTp_GetNcrOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 
      LinTp_CtrlPtr->LinTp_RemainingLength = (uint16)( ((uint16)(LinTp_LinSduPtr[1] & 0x0Fu) << 8u) | (LinTp_LinSduPtr[2]) ); 
      LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length = 5u; 
      /* index of the buffer copied from - FF:3 */
      LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx = 3u;  
      LinTp_CtrlPtr->LinTp_SN = 1u; 
      LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id = LinTp_GetUpperLayerPduIdOfRxNSdu(LinTp_CtrlPtr->LinTp_Curr_Rx_Id); 
      /* Reset P2 timer */
      /* stop P2 timer after receiving start of response */
      LinTp_CtrlPtr->LinTp_P2Timer                     = 0u; 
      /* reset RP counter after receiving start of response to trigger schedule change request */
      LinTp_CtrlPtr->LinTp_RespPendingCounter          = 0u;
      LinTp_CtrlPtr->LinTp_Ch_State = LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START; 
      /* Start receive buffer handling (-> LinTp_RxDataBufferHandling() ) */
      LinTp_RxDataBufferHandling(LinTp_CtrlPtr, LinTp_LinSduPtr); 
    }
    /* else: ignore FF with invalid length - conform to LIN standard but not fully to LINIF652, see bugzilla 52237 */
  }
  }
}


/***********************************************************************************************************************
 *  LinTp_RxIndication_CF()
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a consecutive frame N-PDU.
 *  \details     This function processes a received SRF containing a first frame. Check for a valid sequence number and
 *               passes received data to buffer handling on active connection.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
static void LinTp_RxIndication_CF(LinTp_ControlType* const LinTp_CtrlPtr, const uint8* LinTp_LinSduPtr)
{
  /* Check if consecutive frame is expected */
  if (LinTp_CtrlPtr->LinTp_RemainingLength > 0u)
  { /* CF awaited, note that NAD is already checked */

    /* Check if sequence number is correct */
    if ( LinTp_CtrlPtr->LinTp_SN == (uint8)(LinTp_LinSduPtr[1] & 0x0Fu) )
    {
      /* Update sequence number and Tp timeout counter */
      LinTp_CtrlPtr->LinTp_SN    = (uint8)((LinTp_CtrlPtr->LinTp_SN + 1u) & 0x0Fu); 
      LinTp_CtrlPtr->LinTp_Timer = LinTp_CtrlPtr->LinTp_TimerReload; 

      /* Continue with receive buffer handling (-> LinTp_RxDataBufferHandling() ) */
      /* check for end condition */
      if (LinTp_CtrlPtr->LinTp_RemainingLength < 6u)
      {
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length    = (uint8)(LinTp_CtrlPtr->LinTp_RemainingLength); 
      }
      else
      {
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Length    = 6u; 
      }

      LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx         = 2u; /* index of the buffer copied from - CF:2 */ 
      LinTp_RxDataBufferHandling(LinTp_CtrlPtr, LinTp_LinSduPtr); 
    }
    /* Otherwise: Invalid sequence number in CF */
    else
    {
      /* Abort connection and inform PduR */
      LinTp_RxCloseConnection(LinTp_CtrlPtr); 
    }
  }
  /* else: ignore unexpected consecutive frames */
}

/***********************************************************************************************************************
 *  LinTp_TxMessageProcessing()
 **********************************************************************************************************************/
/*! \brief       Post-processes the transmission of a MRF containing transport protocol data.
 *  \details     Closes connection after transmission of last frame of connection, otherwise prepares next consecutive
 *               frame for transmission.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinStatus           Status value from driver for transmitted MRF
 *  \config      LINTP_FUNCTIONAL_REQUEST_SUPPORTED 
 **********************************************************************************************************************/
void LinTp_TxMessageProcessing(LinTp_ControlType* const  LinTp_CtrlPtr, Lin_StatusType LinTp_LinStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType                                              retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* If MRF is successfully transmitted */
  if ( LinTp_LinStatus == (Lin_StatusType)LIN_TX_OK )
  {
    /* If MRF is a functional request, confirm it by notifying PduR and reset schedule request to previous schedule */
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
    if (LinTp_CtrlPtr->LinTp_FuncRequest == LINTP_FUNC_REQUEST_TRANSMITTED)
    { /* functional request transmitted - reset schedule request to previous schedule */
      LinTp_CtrlPtr->LinTp_FuncRequest            = LINTP_FUNC_REQUEST_IDLE; 
      LinTp_CtrlPtr->LinTp_PortNotification       = LinTp_CtrlPtr->LinTp_ComModeRestore; 
      LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationTx; 
      LinTp_CtrlPtr->LinTp_PduRNotifyResultTx     = E_OK; 
      LinTp_CtrlPtr->LinTp_PduRNSduIdTx           = LinTp_CtrlPtr->LinTp_Curr_Func_NSdu_Id; 
    }
    /* Otherwise a physical Tx connection is active */
    /* Note that an ongoing transmission cannot be cancelled, also not by another transmit request */
    else
# endif
    {
      /* If complete Tp message is finished */
      if (LinTp_CtrlPtr->LinTp_RemainingLength == 0u)
      {
        /* Tp request transmitted successfully, close connection and inform PduR */
        LinTp_CtrlPtr->LinTp_Timer                  = 0u; 
        LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationTx; 
        LinTp_CtrlPtr->LinTp_PduRNotifyResultTx     = E_OK; 
        LinTp_CtrlPtr->LinTp_PduRNSduIdTx           = LinTp_CtrlPtr->LinTp_Curr_UL_NSdu_Id; 
        LinTp_CtrlPtr->LinTp_Ch_State               = LINTP_CHANNEL_IDLE; 

        /*  If request is a broadcast request */
# if ( LINTP_BROADCAST_REQUEST_HANDLING == STD_ON )
        if ( LinTp_CtrlPtr->LinTp_NAD_Requested == 0x7Fu ) 
        {
          /* Broadcast request transmitted, switch directly back to applicative schedule */
          LinTp_CtrlPtr->LinTp_NAD_Requested        = 0u; 
          LinTp_CtrlPtr->LinTp_PortNotification     = LINTP_APPLICATIVE_SCHEDULE; 
#  if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          LinTp_CtrlPtr->LinTp_ComModeRestore       = LINTP_APPLICATIVE_SCHEDULE; 
#  endif
        }
        else
# endif
        {
          /* Normal physical request transmitted, switch to response schedule and activate P2 timeout observation */
          LinTp_CtrlPtr->LinTp_PortNotification     = LINTP_DIAG_RESPONSE; 
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
          LinTp_CtrlPtr->LinTp_ComModeRestore       = LINTP_DIAG_RESPONSE; 
# endif
          /* set up P2 time */
          LinTp_CtrlPtr->LinTp_P2Timer              = LinTp_GetP2Time(); 
        }
      }
      /* Otherwise: more frames to be transmitted for current request */
      else
      {
        /* Prepare buffer for next CF */
        LinTp_CtrlPtr->LinTp_SN                     = (uint8)((LinTp_CtrlPtr->LinTp_SN + 1u) & 0x0Fu); 
        /* set PCI */
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[1]        = (uint8)(LinTp_FrameType_CF | LinTp_CtrlPtr->LinTp_SN); 
        LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer_Idx       = 2u; 
        /* prepare pdu structure for buffer request */
        LinTp_CtrlPtr->LinTp_PduInfoPtr.SduDataPtr  = &LinTp_CtrlPtr->LinTp_Tx_Rx_Buffer[2]; 
        if ( LinTp_CtrlPtr->LinTp_RemainingLength <= 6u)
        {
          LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength = LinTp_CtrlPtr->LinTp_RemainingLength; 
        }
        else
        {
          LinTp_CtrlPtr->LinTp_PduInfoPtr.SduLength = 6u; 
        }

        /* Request new transmit data (-> LinTp_TxDataRequest() ) */
        retVal = LinTp_TxDataRequest(LinTp_CtrlPtr); 
        if (E_NOT_OK == retVal)
        {
          /* If request is denied, close connection and inform PduR - permanent failure */
          LinTp_TxCloseConnection(LinTp_CtrlPtr); 
        }
        else
        {
          /* Request accepted, reload timer with CF timeout value */
          LinTp_CtrlPtr->LinTp_Timer                  = LinTp_CtrlPtr->LinTp_TimerReload; 
        }
      }
    }
  }
  /* Otherwise: MRF transmission failed */
  else
  {
    /* If MRF is a functional request, inform PduR and request change to previous schedule */
# if ( LINTP_FUNCTIONAL_REQUEST_SUPPORTED == STD_ON )
    if (LinTp_CtrlPtr->LinTp_FuncRequest == LINTP_FUNC_REQUEST_TRANSMITTED)
    {
      LinTp_CtrlPtr->LinTp_FuncRequest            = LINTP_FUNC_REQUEST_IDLE; 
      LinTp_CtrlPtr->LinTp_PortNotification       = LinTp_CtrlPtr->LinTp_ComModeRestore; 
      LinTp_CtrlPtr->LinTp_PduRNSduIdTx           = LinTp_CtrlPtr->LinTp_Curr_Func_NSdu_Id; 
      LinTp_CtrlPtr->LinTp_PduRNotification      |= LinTp_PduRNotificationTx; 
      LinTp_CtrlPtr->LinTp_PduRNotifyResultTx     = E_NOT_OK; 
    }
    /* Otherwise (physcial request): Close connection and request change to application schedule */
    else
# endif
    {
      LinTp_TxCloseConnection(LinTp_CtrlPtr); 
    }
  }
} 

#endif
/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**============================================================================
**Date               : 26-APRIL-2020
**CDSID              : LMAHENDR
**Traceability       : RTC 
**Change Description : Static Analysis Code fix done.
**============================================================================
**Date               : 15-APRIL-2020
**CDSID              : LMAHENDR
**Traceability       : RTC 
**Change Description : Initial version
**============================================================================
*/

