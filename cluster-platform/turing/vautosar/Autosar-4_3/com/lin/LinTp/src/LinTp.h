//---------------------------------------------------------------------------------------------------------------------
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
* File Name         :  LinTp.h                                               *
* Module Short Name :  LinIf                                                 *
* Description       :  Contains LinIp Funtional declarations                 *
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
#ifndef LINTP_H
#define LINTP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "LinTp_Types.h"
// #include "LinIf.h"
#include "LinIf_Types.h"
#include "Lin_GeneralTypes.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Component version information (decimal version of ALM implementation package) */
# define LINTP_SW_MAJOR_VERSION                     (1u)
# define LINTP_SW_MINOR_VERSION                     (0u)
# define LINTP_SW_PATCH_VERSION                     (0u)

/* Vendor and module identification */
# define LINTP_VENDOR_ID                            (0u)
# define LINTP_MODULE_ID                            (0u)
/** @name Service id's */

/* Autosar Release */
/*! Defines the AUTOSAR LinTp Release major version */
#define LINTP_AR_RELEASE_MAJOR_VERSION                4U
/*! Defines the AUTOSAR LinTp Release major version */
#define LINTP_AR_RELEASE_MINOR_VERSION                3U
/*! Defines the AUTOSAR LinTp Release patch version */
#define LINTP_AR_RELEASE_REVISION_VERSION             1U

#define PDUR_CODE

/* LIN TP sub channel state engine */
/* @brief This macro is used to indicate that no diagnostic communication is active TP channel */
# define LINTP_CHANNEL_IDLE                       ((uint8)0x00u) /*  */

/* @brief This macro is used to indicate the transmission data currently not available, pending */
# define LINTP_CHANNEL_BUSY_TX_INVALID            ((uint8)0x10u) 

/* @brief This macro is used to indicate the transmission ongoing */
# define LINTP_CHANNEL_BUSY_TX_VALID              ((uint8)0x11u) 

/* @brief This macro is used to indicate the reception ongoing */
# define LINTP_CHANNEL_BUSY_RX                    ((uint8)0x20u) 

/* @brief This macro is used to indicate the currently no buffer for reception available suppress SRF header transmission */
# define LINTP_CHANNEL_BUSY_RX_SUSPENDED          ((uint8)0x21u) 

/* @brief This macro is used to indicate the a new reception is started but PduR not informed yet */
# define LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START     ((uint8)0x22u) 

/* @brief This macro is used to indicate the schedule next SRF header but poll for receive buffer after reception */
# define LINTP_CHANNEL_BUSY_RX_POLLBUFFER         ((uint8)0x23u) 

# define LINTP_CHANNEL_TX_MSK                     ((uint8)0x10u)
# define LINTP_CHANNEL_RX_MSK                     ((uint8)0x20u)

/* @brief The bbelow set of macros describe the different states to notify the PduR layer from TP*/
#define LinTp_PduRNotificationIdle                  ((uint8)0x00u)
#define LinTp_PduRNotificationTx                    ((uint8)0x01u)
#define LinTp_PduRNotificationTxTm                  ((uint8)0x02u)
#define LinTp_PduRNotificationRx                    ((uint8)0x10u)
#define LinTp_PortNotificationIdle                  ((uint8)0xFFu)

/* @brief API Service IDs*/
# define LINTP_SID_INIT                             (0x40u)
# define LINTP_SID_TRANSMIT                         (0x41u)
# define LINTP_SID_GETVERSIONINFO                   (0x42u)
# define LINTP_SID_SHUTDOWN                         (0x43u)
# define LINTP_SID_CHANGEPARAMETER                  (0x44u)
# define LINTP_SID_CANCELTRANSMIT                   (0x46u)
# define LINTP_SID_CANCELRECEIVE                    (0x47u)
/***********************************************************************************************************************
 *  LinTp_Init()
 **********************************************************************************************************************/
/*! \brief       Initializes component LinTp.
 *  \details     Initializes all component variables and sets the component state to initialized.
 *  \param[in]   ConfigPtr               Pointer to LinTp configuration structure
 **********************************************************************************************************************/
void LinTp_Init(const LinTp_ConfigType* ConfigPtr);

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
Std_ReturnType LinTp_Transmit(PduIdType LinTpTxSduId, const PduInfoType* LinTpTxInfoPtr);

#  if ( LINTP_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  LinTp_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  versioninfo               Pointer to location to store the version information. Parameter must not be NULL.
 *  \config      LINIF_TP_SUPPORTED and LINTP_VERSION_INFO_API
 **********************************************************************************************************************/
void LinTp_GetVersionInfo (Std_VersionInfoType* versioninfo);
#  endif /* LINIF_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 *  LinTp_Shutdown()
 **********************************************************************************************************************/
/*! \brief       Shutdowns the component.
 *  \details     Closes all pending transport protocol connection, frees all resources and sets the module into
 *               uninitialized state.
 *  \config      LINIF_TP_SUPPORTED
 **********************************************************************************************************************/
void LinTp_Shutdown(void);

#  if ( LINTP_CANCEL_TRANSMIT_SUPPORTED == STD_ON )
/***********************************************************************************************************************
 *  LinTp_CancelTransmit()
 **********************************************************************************************************************/
/*! \brief       This is a dummy method introduced for interface compatibility.
 *  \details     This function has no functionality.
 *  \param[in]   LinTpTxSduId            Unique N-SDU identifier of LIN Tx N-SDU which transfer shall be cancelled.
 *  \return      E_NOT_OK                Cancellation request is always rejected.
 *  \config      LINIF_TP_SUPPORTED and LINTP_CANCEL_TRANSMIT_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_CancelTransmit(PduIdType LinTpTxSduId);
#  endif

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
 *  \config      LINIF_TP_SUPPORTED and LINTP_CHANGE_PARAMETER_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_ChangeParameter(PduIdType id, TPParameterType parameter,uint16 value);
#  endif

#  if ( LINTP_CANCEL_RECEIVE_SUPPORTED == STD_ON )
/***********************************************************************************************************************
 *  LinTp_CancelReceive()
 **********************************************************************************************************************/
/*! \brief       This is a dummy method introduced for interface compatibility.
 *  \details     This function has no functionality.
 *  \param[in]   LinTpRxSduId            Unique N-SDU identifier of LIN Rx N-SDU which transfer has to be cancelled.
 *  \return      E_NOT_OK                Cancellation request is always rejected.
 *  \config      LINIF_TP_SUPPORTED and LINTP_CANCEL_RECEIVE_SUPPORTED
 **********************************************************************************************************************/
Std_ReturnType LinTp_CancelReceive(PduIdType LinTpRxSduId);
#  endif

/***********************************************************************************************************************
 *  LinTp_TxScheduleProcessing() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Prepares a MRF for transmission used by transport protocol.
 *  \details     Checks whether TP transmission data is available for a connection on given channel and prepares the given
 *               LIN PDU.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_IfChannelDataPtr    Pointer to current channel data
 *  \param[in]   LinTp_LinPduPtr           Pointer to Lin PDU to be passed to driver
 **********************************************************************************************************************/
boolean LinTp_TxScheduleProcessing(LinTp_ControlType* const LinTp_CtrlPtr, LinIf_ChannelDataType* const LinTp_IfChannelDataPtr, Lin_PduType* const LinTp_LinPduPtr);

/***********************************************************************************************************************
 *  LinTp_CloseActiveConnection() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Terminates an ongoing Rx or Tx connection.
 *  \details     Aborts an active TP connection on given channel and notify upper layer. Afterwards, the TP channel state
 *               is idle.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
void LinTp_CloseActiveConnection(LinTp_ControlType* const LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_BufferPolling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Requests data from PduR for current Tp connection, both Rx and Tx.
 *  \details     Polls for suspended buffer handling. Handles Rx and Tx connections.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \note        Function can be polled.
 *  \Invoke on - Request periodically PduR for transmission data or reception buffer
 **********************************************************************************************************************/
void LinTp_BufferPolling(LinTp_ControlType* const LinTp_CtrlPtr);

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
Std_ReturnType LinTp_TxDataRequest(LinTp_ControlType* const LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_Timer_Handling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the TP Timer working
 *  \details     Runs the Lin TP timer and handles the timeout consequential actions.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 **********************************************************************************************************************/
void LinTp_Timer_Handling(LinTp_ControlType* LinTp_CtrlPtr);

/***********************************************************************************************************************
 *  LinTp_P2_Timer_Handling() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the P2 timer working
 *  \details     Runs the Lin P2 timer and handles the timeout consequential actions.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   Channel             Channel nummber
 **********************************************************************************************************************/
void LinTp_P2_Timer_Handling(LinTp_ControlType* LinTp_CtrlPtr, uint8 Channel);

/***********************************************************************************************************************
 *  LinTp_MainPostProcessing() - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Notifies the upper layers after each main processing function cycle of the LIN TP
 *  \details     LinTp post notification to the PduR of last transmitted/ received TP message
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \When to Invoke - After IF main processing done for LIN TP's Tx or Rx service
 **********************************************************************************************************************/
void LinTp_MainPostProcessing(LinTp_ControlType* LinTp_CtrlPtr, uint8 Channel);

/***********************************************************************************************************************
 *  LinTp_RxIndication - ONLY FOR IF LAYER
 **********************************************************************************************************************/
/*! \brief       Handles the reception of a SRF.
 *  \details     This function processes a received SRF containing transport protocol data.
 *  \param[in]   LinIf_LinIfChannel        Local LinIf channel identifier
 *  \param[in]   LinTp_LinSduPtr           Pointer to receive buffer of slave response frame
 **********************************************************************************************************************/
void LinTp_RxIndication(NetworkHandleType LinIf_LinIfChannel,const uint8* LinTp_LinSduPtr);

/***********************************************************************************************************************
 *  LinTp_TxMessageProcessing()
 **********************************************************************************************************************/
/*! \brief       Post-processes the transmission of a MRF containing transport protocol data.
 *  \details     Closes connection after transmission of last frame of connection, otherwise prepares next consecutive
 *               frame for transmission.
 *  \param[in]   LinTp_CtrlPtr             Pointer to Tp channel control structure
 *  \param[in]   LinTp_LinStatus           Status value from driver for transmitted MRF
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
void LinTp_TxMessageProcessing(LinTp_ControlType* const  LinTp_CtrlPtr, Lin_StatusType LinTp_LinStatus);

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
**Date               : 15-APRIL-2020
**CDSID              : LMAHENDR
**Traceability       : RTC 
**Change Description : Initial version
**============================================================================
*/


