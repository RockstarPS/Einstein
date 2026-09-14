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
/// UCL Interface Layer Implementation for FD API's. APIs in this file are not to be called directly by the users
///
///---------------------------------------------------------------------------------------------------------------------
///

#ifndef UCL_IL_FD_H
#define UCL_IL_FD_H

#include "UclILStream_Channel_Types.h"
#include "UclCmnRingBuffer.h"

#define INVALID_FDQ_INDEX       0xFFFFu
#define INVALID_CH_INDEX        0xFFFFu
#define INVALID_FID             -1

#define CHECK_FLAG_STATUS(f, s) ((f) & (s))

#define UCL_OWNED_REQID_START               (0x80u)
#define UCL_OWNED_REQID_END                 (0XFFu)
typedef struct
{
    ucl_ch_t    chnId;
    uint8       rId;
    sint32      bId;
    uint64 timeMs;
} SUclTxFdQueueElement_t;

typedef struct
{
    ucl_ch_t  dummychnId;
    uint8  dummyRid;
    sint32 bId;
    uint64 dummyTimeMs;
} SUclRxFdQueueElement_t;

typedef struct
{
    uint8 *pData;
    uint16 size;
} SUclFileDescBuffer_t;

typedef struct
{
    uint8 isAvailable;
    uint32 queueLockMutexId;
    SUclCmnRingBuffer mFileDescQueue;
} SUclFileDescQueue_t;

typedef struct
{
    uint32 mChnIndex;
    uint16 mOFlags;
} SUclFileDescAttr_t;

typedef struct
{
    SUclFileDescAttr_t mAttr;
    uint16 mTxQueueId;
    uint16 mRxQueueId;
} SUclFileDescQueueAttr_t;

typedef struct
{
    SUclFileDescBuffer_t *mpBufferList;
    SUclFileDescQueue_t *mpQueueList; //work data
} SUclFileDescQueueCfg_t;

typedef struct
{
    SUclFileDescQueueCfg_t *mpFdQueueList;
    uint16 mMaxQs;
    SUclFileDescQueueAttr_t *mpFdAttrList; //work data
    uint16 mMaxFds;
} SUclFileDescCfg_t;

typedef struct
{
    SUclFileDescCfg_t *mpCfg;
    uint16 mActiveFds;
} SUclFileDesc_t;

///
/// @brief UCL Message Priority Level Definitions
///
typedef enum
{
    eUclFileDescReadFdRxq_Poll, ///< After read, Element is not removed from queue
    eUclFileDescReadFdRxq_Read,     ///<  After read, it Removes element from queue
} EUclFileDescReadFdRxq;


Ucl_ReturnType UclILStream_Impl_FdInitialize ( SUclFileDesc_t *fdList, SUclFileDescCfg_t *pFDCfg );
Ucl_ReturnType UclILStream_Impl_FdShutdown ( SUclFileDesc_t *fdList );
ucl_fd_t UclILStream_Impl_FdGet ( SUclFileDesc_t *fdList, uint32 chnIdx, uint16 flags );
void UclILStream_Impl_FdRelease ( SUclFileDesc_t *fdList, ucl_fd_t fid );
Ucl_ReturnType UclILStream_Impl_FdReadFromTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 *pSize );
Ucl_ReturnType UclILStream_Impl_FdWriteToTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 size );
Ucl_ReturnType UclILStream_Impl_FdReadFromRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 *pSize, \
        EUclFileDescReadFdRxq type );
Ucl_ReturnType UclILStream_Impl_FdWriteToRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 size );
Ucl_ReturnType UclILStream_Impl_FdGetAttr ( SUclFileDesc_t *fdList, ucl_fd_t fid, SUclFileDescAttr_t *pAttr );
Ucl_ReturnType UclILStream_Impl_FdGetRxFdList ( SUclFileDesc_t *fdList, uint32 chnIndex, ucl_fd_t *pData, uint16 *pSize );
Ucl_ReturnType UclILStream_Impl_FdGetActiveTxFds ( SUclFileDesc_t *fdList, ucl_fd_t *txFdList, uint16 *pSize );
Ucl_ReturnType UclILStream_Impl_FdFlushTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid );
Ucl_ReturnType UclILStream_Impl_FdFlushRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid );

#endif //UCL_IL_FD_H
