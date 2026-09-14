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
#include "types.h"
#include "string.h"
#include "ucl_channel.h"
#include "uclILStream_Channel_Types.h"
#include "UclILStreamAdapter.h"
#include "UclILStream.h"
#include "UclILStream_Cfg.h"
#include "os_if.h"

static uclVliteAppCbk IUclILStreamVliteAppCbkHandlerInst[NO_OF_CLIENTS];
static ucl_ioctl_notify_info_t IUclILStreamVliteIoCtlInfoNotify[NO_OF_CLIENTS];

/// @defgroup UCL_CHN_FUNC UCL Channel APIs
/// @brief UCL Channel based APIs
/// @{
///
/// @brief  Open an UCL Channel
///
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return > 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///
ucl_fd_t ucl_open( ucl_ch_t chId, uint16 flags )
{
    ucl_fd_t fd;

    fd = UclILStream_Open( 0, chId, flags );

    if ((fd >= 0) && (fd < NO_OF_CLIENTS))
    {
        (void) memset( (uint8 *) &IUclILStreamVliteIoCtlInfoNotify[fd], 0X0, sizeof(ucl_ioctl_notify_info_t) );

        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_LinkStatusChanged = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_MessageTransmitStatus = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_DataReceivedNotification = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_ErrorNotification = NULL;
    }
    return fd;
}

///
/// @brief  Close an UCL Channel
///
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///
sint32 ucl_close( ucl_fd_t fd )
{
    sint32 ret;

    ret = UclILStream_Close( 0, fd );

    if (ret == UCL_E_OK)
    {
        (void) memset( (uint8 *) &IUclILStreamVliteIoCtlInfoNotify[fd], 0X0, sizeof(ucl_ioctl_notify_info_t) );

        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_LinkStatusChanged = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_MessageTransmitStatus = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_DataReceivedNotification = NULL;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_ErrorNotification = NULL;
    }
    return ret;
}

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
sint32 ucl_read( ucl_fd_t fd, uint8 *pBuffer, uint32 size )
{
    sint32 sizeRead;

    sizeRead = UclILStream_Read( 0, fd, pBuffer, size );

    return sizeRead;
}

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
sint32 ucl_write( ucl_fd_t fd, uint8 *pBuffer, uint32 size )
{
    sint32 byteSent;

    byteSent = UclILStream_Write( 0, fd, pBuffer, size );

    return byteSent;
}

///
/// @brief  Poll the UCL channel to check for receive data
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @return > 0 number of bytes waiting to be read
/// @return < 0 @ref UCL_ERR
///
sint32 ucl_poll( ucl_fd_t fd, uint32 timeout )
{
    sint32 byteRead;

    byteRead = UclILStream_Poll( 0, fd, timeout );

    return byteRead;
}

///
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
sint32 ucl_write_ex( ucl_fd_t fd, uint8 reqId, uint8 *pBuffer, uint32 size )
{
    sint32 byteSent;

    byteSent = UclILStream_WriteEx( 0, fd, reqId, pBuffer, size );

    return byteSent;

}

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
sint32 ucl_poll_ex( ucl_fd_t fd, uint8 reqId, uint32 timeout )
{
    sint32 Ret = UCL_E_OK;

    return Ret;
}

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
sint32 ucl_ioctl( ucl_fd_t fd, uint16 request, void *pData, uint16 size )
{
    sint32 Ret = -1;

    if (request == UCL_IOCTL_SET_NOTIFY_INFO)
    {
        if ((size == sizeof(ucl_ioctl_notify_info_t)) && (fd >= 0) && (fd < NO_OF_CLIENTS))
        {
            (void) memcpy( (uint8 *) &IUclILStreamVliteIoCtlInfoNotify[fd], (uint8 *)pData, sizeof(ucl_ioctl_notify_info_t) );
            Ret = 0;
        }

    }

    else if (request == UCL_IOCTL_GET_NOTIFY_INFO)
    {
        if ((size == sizeof(ucl_ioctl_notify_info_t)) && (fd >= 0) && (fd < NO_OF_CLIENTS))
        {
            (void) memcpy( (uint8 *) pData, (uint8 *) &IUclILStreamVliteIoCtlInfoNotify[fd], sizeof(ucl_ioctl_notify_info_t) );
            Ret = 0;
        }
    }
    else
    {
        Ret = UclILStream_Ioctl( 0u, fd, request, pData, (uint16) size );
    }
    return Ret;
}

///
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  callback Subscribe callback for the interface
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
/// @return

sint32 ucl_ioctl_registerCallback( ucl_fd_t fd, const uclVliteAppCbk *pInst )
{
    sint32 Ret = -1;

    /* then use callback registration */
    if ((fd >= 0) && (fd < NO_OF_CLIENTS) && (pInst != NULL ))
    {
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_LinkStatusChanged =pInst->pCbk_UclILStreamVlite_LinkStatusChanged;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_MessageTransmitStatus = pInst->pCbk_UclILStreamVlite_MessageTransmitStatus;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_DataReceivedNotification = pInst->pCbk_UclILStreamVlite_DataReceivedNotification;
        IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_ErrorNotification =pInst->pCbk_UclILStreamVlite_ErrorNotification;
        Ret = UCL_E_OK;
    }

    return Ret;
}

void UclILStream_Adapter_ErrorNotification( uint8 DLInst, sint32 ErrorCode )
{
    uint16 index;
    task_id_type cmpId;
    event_mask_type eventMask;

    for (index = 0u; index < (uint16)NO_OF_CLIENTS; index++)
    {
        if (IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_FATAL_ERROR].enabled > 0u)
        {
            cmpId = (task_id_type)IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_FATAL_ERROR].comp_id;
            eventMask = IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_FATAL_ERROR].event_mask;
            os_event_set( cmpId, eventMask );
        }
        else
        {
            if (IUclILStreamVliteAppCbkHandlerInst[index].pCbk_UclILStreamVlite_ErrorNotification != NULL )
            {
                IUclILStreamVliteAppCbkHandlerInst[index].pCbk_UclILStreamVlite_ErrorNotification( index, ErrorCode );
            }
        }
    }
}


void UclILStream_Adapter_QueueFullNotification( sint32 fd ,sint32 ErrorCode )
{
	task_id_type cmpId;
	event_mask_type eventMask;

    if ((fd >= 0) && (fd < NO_OF_CLIENTS))
    {
		if (IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_FATAL_ERROR].enabled > 0u)
		{
			cmpId = (task_id_type)IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_FATAL_ERROR].comp_id;
			eventMask = IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_FATAL_ERROR].event_mask;
			os_event_set( cmpId, eventMask );
		}
		else
		{
			if (IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_ErrorNotification != NULL )
			{
				IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_ErrorNotification( fd, ErrorCode );
			}
		}
    }
}


void UclILStream_Adapter_LinkStatusChanged( uint8 DLInst, sint32 Status )
{
    uint16 index;
    task_id_type cmpId;
    event_mask_type eventMask;

    for (index = 0u; index < (uint16) NO_OF_CLIENTS; index++)
    {
        if (IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_LINK_STATUS_CHANGE].enabled  > 0u)
        {
            cmpId = (task_id_type)IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_LINK_STATUS_CHANGE].comp_id;
            eventMask = IUclILStreamVliteIoCtlInfoNotify[index].event_info[UCL_NOTIFY_LINK_STATUS_CHANGE].event_mask;
            os_event_set( cmpId, eventMask );
        }
        else
        {
            if (IUclILStreamVliteAppCbkHandlerInst[index].pCbk_UclILStreamVlite_LinkStatusChanged != NULL )
            {
                IUclILStreamVliteAppCbkHandlerInst[index].pCbk_UclILStreamVlite_LinkStatusChanged( index, Status );

            }
        }
    }
}

void UclILStream_Adapter_MessageTransmitStatus( sint32 fd, uint8 reqId, sint32 Status )
{
    task_id_type cmpId;
    event_mask_type eventMask;

    if ((fd >= 0) && (fd < NO_OF_CLIENTS))
    {
        if (IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_TRANSMIT_CONFIRM].enabled > 0u )
        {
            cmpId = (task_id_type)IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_TRANSMIT_CONFIRM].comp_id;
            eventMask = IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_TRANSMIT_CONFIRM].event_mask;
            os_event_set( cmpId, eventMask );
        }

        else
        {
            if (IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_MessageTransmitStatus != NULL )
            {
                IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_MessageTransmitStatus( fd, reqId, Status );
            }

        }

    }
}

void UclILStream_Adapter_DataReceived( sint32 fd )
{
    task_id_type cmpId;
    event_mask_type eventMask;

    if ((fd >= 0) && (fd < NO_OF_CLIENTS))
    {
        if (IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_DATA_RECEIVED].enabled > 0u)
        {
            cmpId = (task_id_type)IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_DATA_RECEIVED].comp_id;
            eventMask = IUclILStreamVliteIoCtlInfoNotify[fd].event_info[UCL_NOTIFY_DATA_RECEIVED].event_mask;
            os_event_set( cmpId, eventMask );
        }
        else
        {
            if (IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_DataReceivedNotification != NULL )
            {
                IUclILStreamVliteAppCbkHandlerInst[fd].pCbk_UclILStreamVlite_DataReceivedNotification( fd );
            }

        }

    }
}
