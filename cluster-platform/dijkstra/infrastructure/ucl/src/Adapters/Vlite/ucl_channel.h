#ifndef UCL_CHANNEL_H
#define UCL_CHANNEL_H
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
/// @mainpage UCL Channel Based APIs
///
/// @section intro Introduction
///
/// @section features Features
///
/// @section api API Reference
///
/// <a href="modules.html">Modules</a>
///
/// @file ucl_channel.h UCL Channel
///
///

#include "ucl_types.h"
#include "uclILStream_Channel_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/// @defgroup uclVliteAppCbk
/// @brief Callback to be registered per client
/// @{
/// @param[1]  pCbk_UclILStreamVlite_LinkStatusChanged : Callback to notify link status
/// @param[2]  pCbk_UclILStreamVlite_DataReceivedNotification: Callback to notify data received
/// @param[3]  pCbk_UclILStreamVlite_MessageTransmitStatus: Callback to notify message transmit status
/// @param[4]  pCbk_UclILStreamVlite_ErrorNotification: Callback to notify error
/// @}
///
typedef struct uclVliteAppCbk_t
{
    void (*pCbk_UclILStreamVlite_LinkStatusChanged)( sint32 fd, sint32 linkStatus );
    void (*pCbk_UclILStreamVlite_DataReceivedNotification)( sint32 fd );
    void (*pCbk_UclILStreamVlite_MessageTransmitStatus)( sint32 fd, uint8 reqId, sint32 txStatus );
    void (*pCbk_UclILStreamVlite_ErrorNotification)( sint32 fd, sint32 errorCode );

} uclVliteAppCbk;

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief UCL Channel based APIs
/// @{

///
/// @brief  Open an UCL Channel
///
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return >= 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///
ucl_fd_t ucl_open( ucl_ch_t chId, uint16 flags );

///
/// @brief  Close an UCL Channel
///
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///
sint32 ucl_close( ucl_fd_t fd );

///
/// @brief  Read data from the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes read
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_read( ucl_fd_t fd, uint8 *pBuffer, uint32 size );

///
/// @brief  Write data to the UCL channel
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_write( ucl_fd_t fd, uint8 *pBuffer, uint32 size );

///
/// @brief  Poll the UCL channel to check for receive data
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @return > 0 number of bytes waiting to be read
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_poll( ucl_fd_t fd, uint32 timeout );

///
/// @brief  Poll the UCL channel to check for transmit confirmation
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID used in the ucl_write_ex call
/// @param[in]  timeout Timeout to wait for the confirmation
///
/// @return @ref UCL_E_OK   Successfully sent
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_poll_ex( ucl_fd_t fd, uint8 reqId, uint32 timeout );
/// @brief  Write data to the UCL channel along with the request id
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID to be associated with this write request
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_write_ex( ucl_fd_t fd, uint8 reqId, uint8 *pBuffer, uint32 size );

///
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  request @ref UCL_IOCTL
/// @param[in]  pData   Pointer to the structure corresponding to the request
/// @param[in]  size    Size of the structure
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
///
sint32 ucl_ioctl( ucl_fd_t fd, uint16 request, void *pData, uint16 size );

///
/// @brief  Ucl Callback registry
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  callback Subscribe callback for the interface
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
/// @return

sint32 ucl_ioctl_registerCallback( ucl_fd_t fd, const uclVliteAppCbk *pInst );

/// @}
#ifdef __cplusplus
}
#endif

#endif //UCL_CHANNEL_H
