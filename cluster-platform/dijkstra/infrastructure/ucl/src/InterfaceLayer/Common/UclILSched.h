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
/// @file
/// @ingroup UclIL
/// UCL Interface Layer Scheduler Interface APIs.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILSCHED_H
#define UCLILSCHED_H

#include "UclILSched_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C" {
#endif

///
/// @brief This method is used to initialize the UclILSched Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK 	Initialization Success
///	@return	UCL_E_NOK 	Initialization Failed
///
Ucl_ReturnType UclILSched_Initialize(uint8 InstId);

///
/// @brief This method is used to shutdown the UclILSched Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK 	Shutdown Success
///	@return	UCL_E_NOK 	Shutdown Failed
///
Ucl_ReturnType UclILSched_Shutdown(uint8 InstId);

///
/// @brief This method implements the Notification API for the UclILSched Interface
///				 The Adapter must call this API to push the message into the send queue
///
/// @param InstId 	Instance Id of the UclILSched Instance
/// @param MsgIdx 	Message index in the transmit database
/// @param DuIdx    DataUnit index in the transmit message
/// @param pBuffer  Pointer to the buffer (Valid for message based interface)
/// @param Size     Size of the buffer (Valid for message based interface)
///
/// @return None
///
void UclILSched_NotifyMessageUpdate(uint8 InstId, uint16 MsgIdx, uint16 DuIdx, uint8 *pBuffer, uint16 Size);

#ifdef __cplusplus
}
#endif
#endif //UCLILSCHED_H
