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
/// UCL Interface Layer Implementation for Stream API's. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
///
#ifndef UCL_ILSTREAM_IMPL_CHANNEL_H
#define UCL_ILSTREAM_IMPL_CHANNEL_H

#include "UclILStream_Channel_Types.h"
#include "UclILStream_Impl_Fd.h"
#include "UclCmnRingBuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

//Channel Configurations
#define INVALID_CH_ID                   0xFF
typedef struct
{
    uint8 rId;
    uint16      mId; //mId =  cId + rId+

    uint16 isFree;    ///< Specifies if the slot is free
    sint32 bId;
    ucl_fd_t fId;
    uint64 timeMs;
} SUclChnQueueElement_t;

typedef struct
{
    ucl_ch_t    chnId;
    sint32      bId;
    uint16      mId; //mId =  cId + rId
} SUclPriorityQueueElement_t;

typedef struct
{
    SUclChnQueueElement_t *pData;
    uint16 size;
} SUclChnQueueBuffer_t;

typedef struct
{
    uint32 tx_bytes;              ///< Number of bytes transmitted
    uint32 rx_bytes;              ///< Number of bytes received
    uint32 tx_msgs;               ///< Number of messages transmitted
    uint32 rx_msgs;               ///< Number of messages received
    uint32 tx_kbps;               ///< Average transmit speed in kbps
    uint32 rx_kbps;               ///< Average receive speed in kbps
    uint32 avg_ack_latency;       ///< Average latency for acknowledgement
} SUclChnStats_t;

typedef struct
{
    ucl_ch_t mChId;                 ///< Channel Id
    uint8 priority_level;               ///< Channel priority level
    uint8 security_level;               ///< Channel security level
    uint16 time_to_live_ms;             ///< Channel time-to-live in ms
} SUclChnAttr_t;

typedef struct
{
    uint8 isActive;                     ///< Channel Status
    uint8 useCount;                     ///< Count of Channel users
    uint8 isShared;                     ///< Channel sharing permission
    SUclChnAttr_t mAttr;                ///< Channel specific configurations
    SUclChnStats_t stats;               ///< Channel data transfer stats
} SUclChnInfo_t;

typedef struct
{
    uint32 chnQueueLockMutexId;
    uint16 chnQueuesize;
    SUclChnQueueElement_t *mChnQueue;
} SUclChnQueue_t;

typedef struct
{
    SUclChnQueueBuffer_t *mpBufferList;
    SUclChnQueue_t  *mpQueueList; //work data
} SUclChnQueueCfg_t;

typedef struct
{
    SUclChnQueueCfg_t   *mpChnQueueList;
    SUclChnInfo_t       *mpChnAttrList;
    uint16 maxChn;
    //uint32 chnAttrListLockMutexId;    //Mutex to lock Channel Attribute list
} SUclChnCfg_t;

typedef struct
{
    SUclChnCfg_t *mpCfg;
    uint16 mActiveChn;
} SUclChn_t;

///
/// @brief This method is used to initialize the UclILChannel Instance
///
/// @param InstId Instance Id to initialize
///
/// @return UCL_E_OK    Initialization Success
/// @return UCL_E_NOK   Initialization Failed
///
Ucl_ReturnType UclILStream_Impl_ChnInitialize ( SUclChn_t *pChnList, SUclChnCfg_t *pBChnfg );
///
/// @brief This method is used to shutdown the UclILChannel Instance
///
/// @param InstId Instance Id to shutdown
///
/// @return UCL_E_OK    Shutdown Success
/// @return UCL_E_NOK   Shutdown Failed
///

Ucl_ReturnType UclILStream_Impl_ChnShutdown ( SUclChn_t *pChnList );
///
/// @brief  Open an UCL Channel
///
/// @param InstId Instance Id to Open
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return > 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///

Ucl_ReturnType UclILStream_Impl_ChnOpen ( SUclChn_t *ChnList, ucl_ch_t chId, uint16 flags, uint32 *pChnIndex );
///
/// @brief  Close an UCL Channel
///
/// @param InstId Instance Id to Close
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///

Ucl_ReturnType UclILStream_Impl_ChnClose ( SUclChn_t *pChnList, uint32 chnIndex );
///
/// @brief  Read data from the UCL channel
///
/// @param InstId Instance Id to Read
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes read
/// @return < 0 @ref UCL_ERR
///

Ucl_ReturnType UclILStream_Impl_ChnQueueRead ( SUclChn_t *pChnList, uint32 chnIndex, uint32 readIdx, SUclChnQueueElement_t *pBuffer );
///
/// @brief  Write data to the UCL channel
///
/// @param InstId Instance Id to Write
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///

Ucl_ReturnType UclILStream_Impl_ChnQueueWrite ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnQueueElement_t *pBuffer );
///
///
/// @brief  UCL Input/Output Control API to configure channel parameters
///
/// @param InstId Instance Id to Ioctl
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  request @ref UCL_IOCTL
/// @param[in]  pData   Pointer to the structure corresponding to the request
/// @param[in]  size    Size of the structure
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_ChnGetAttr ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnAttr_t *pAttr );
Ucl_ReturnType UclILStream_Impl_ChnSetAttr ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnAttr_t *pAttr );
Ucl_ReturnType UclILStream_Impl_ChnGetIdx ( SUclChn_t *pChnList, ucl_ch_t chid, uint32 *chnIndex );
Ucl_ReturnType UclILStream_Impl_RemoveChnElement ( SUclChn_t *pChnList, uint32 chnIndex, uint32 eIdx );
/// @}
#ifdef __cplusplus
}
#endif
#endif //UCL_IL_CHANNEL_H
