///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
/// @defgroup UclDL
/// @brief UCL Data Layer handles protocol, security, ACK/NAK, Recovery and Link Health.
/// @file UclDL.h
/// @ingroup UclDL
///
/// UCL Data Layer Interface APIs. APIs to send/receive UCL frames over the Physical transport.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLDL_H
#define UCLDL_H
#ifdef __cplusplus
extern "C" {
#endif

#include "UclDL_Types.h"

///
/// @brief This method is used to initialize the UclDL Instance
///
/// Initializes the DL Instance and the associated Physical Layer.
/// Allocates OS resources and prepares the DL instance to send
/// and receive UCL messages.
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclDL_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclDL Instance
///
/// Shutdown the DL Instance and the associated Physical Layer.
/// Frees up the OS resources and does not allow to send
/// and receive UCL messages.
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclDL_Shutdown(uint8 InstId);

///
/// @brief This method is used to send an Ucl Message
///
/// Request the DL to send an UCL message.
/// To make sure if the message is actually received by the
/// peer node, subscribe to the transmit notifications.
///
/// @param InstId UclDL Instance Id
/// @param pMsg   Pointer to the Ucl Message
///
/// @return UCL_E_OK 	Message accepted for transmission
///	@return	UCL_E_NOK 	Message Rejected
///
/// @note Do not use this API if you are configured to use UCL Interface layer
///
/// @warning Make sure the UclDL_Initialize is invoked before using this API
///
Ucl_ReturnType UclDL_Send(uint8 InstId, SUclDLMsg *pMsg);

///
/// @brief This method is used to Get an Ucl DL statistics
///
/// Request the DL to update the DL statistics.
/// Request DL to update its relevant parameters
///
/// @param InstId UclDL Instance Id
/// @param pDLStats Pointer to the Ucl DLstatics
///
/// @return UCL_E_OK    Request to update DL statistics is accepted
/// @return UCL_E_NOK   Request rejected.
///
/// @note Do not use this API if you are configured to use UCL Interface layer
///
///
Ucl_ReturnType UclDL_GetStats(uint8 InstId, SUclDLStats *pDLStats);

#ifdef __cplusplus
}
#endif
#endif //UCLDL_H
