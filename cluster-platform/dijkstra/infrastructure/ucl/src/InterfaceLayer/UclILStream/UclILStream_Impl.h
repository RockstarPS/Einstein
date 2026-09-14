///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2018] Visteon Corporation
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
/// UCL Interface Layer Implementation for Stream Based Message.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILSTREAM_IMPL_H
#define UCLILSTREAM_IMPL_H

#include "UclBufferPool.h"
#include "UclILStream.h"
#include "UclDLCbk_Types.h"
#include "UclCmnRingBuffer.h"
#include "UclIL_Types.h"

#define UCLILSTREAM_IMPL_MAX_LOCAL_TIMERS (2u)

typedef struct SUclILStreamInst_t SUclILStreamInst;
///
/// @brief Callback function type for local timers
///
typedef void ( *TUclILStreamLocalTimerCbk ) ( SUclILStreamInst *pInst );

///
/// @brief Work data DL instances managed by UclILSched_Impl.
///
/// The SUclILStreamDLData structure defines the work data for DL instances.
///
typedef struct
{
    EUclDLLinkStatus linkStatus;                                ///< Link status of the DL Instance
    uint32 prioQueueLocks[eUclILMsgPriorityLevel_Last];       /// < Priority Queue Locks
    SUclCmnRingBuffer prioQueue[eUclILMsgPriorityLevel_Last]; /// < Priority Message Queues
} SUclILStreamDLData;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILStreamPrioQueueCfg structure defines the constant configuration data for Priority queues.
///
typedef struct
{
    uint8 *pData;
    uint16 size;
} SUclILStreamPrioQueueCfg;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILStreamDLCfg structure defines the constant configuration data for DL layers.
///
typedef struct
{
    uint8 numDestNodes;                                                  ///< Number of items in the Destination Node IDs list
    uint8 *pDestNodeIds;                                                 ///< Destination Node IDs list
    SUclILStreamPrioQueueCfg prioQueueCfg[eUclILMsgPriorityLevel_Last]; ///< Priority Queue Configurations
    SUclILStreamDLData *pData;                                            ///< Work data for the DL Instance
    uint16 txWorkBufferSize;                                             ///< Size of the Transmit work buffer
    uint8 *pTxWorkBuffer;                                                ///< Work Buffer for Transmit Messages
} SUclILStreamDLCfg;

///
/// @brief Configuration data for UclILSched_Impl.
///
/// The SUclILStreamCfg structure defines the constant configuration data for UclILSched_Impl class.
///

typedef struct
{
    uint8 nodeId;                          ///< Node ID
    uint8 maxFds;                         ////< max Fds
    ucl_fd_t *ptxFdlist;                     ///< Tx fd list
    ucl_fd_t *prxFdlist;                     ///< Rx fd list
    SUclBufferPoolCfg_t *pBufferPoolCfg;      ///< Buffer Pool Config
    SUclFileDescCfg_t *pFdCfg;          ///< Fd Queue Config
    SUclChnCfg_t *pChnCfg;              ///< Channel Queue Config
    uint16 timerTaskPeriodicityMs;      ///< Periodicity of Base timer task
    uint16 fdDeQueueTaskMs;             ///< Periodicity of FD Queue scan task
    uint16 priorityMsgSchedulerMs;      ///< Periodicity of Periodic message processing task
    SUclILStreamDLCfg *pDLCfg;          ///< Configuration data for DL instances
} SUclILStreamCfg;

///
/// @brief Private instance data for UclILSched_Impl. \n
/// @ingroup UclIL
///
/// The SUclILStreamInst structure defines the private instance data for UclILSched_Impl class.
///
struct SUclILStreamInst_t
{
    uint8 isInitialized;
    const SUclILStreamCfg *pCfg; ///< Configuration for the UclILSched_Impl instance
    uint8 numIUclDL; ///< Number of connected UclDL instances
    uint8 *pIUclDL;  ///< Instance ID of the connected UclDL instances
    SUclBufferPool_t mBufferPool;
    SUclFileDesc_t mFDQueueList;
    SUclChn_t mChannelList;
    uint32 uclTimerTaskProtectMutexId;
    uint32 timerTaskId;                                                        ///< Id for the TimerTask
    uint32 localTimers[UCLILSTREAM_IMPL_MAX_LOCAL_TIMERS];                      ///< Array of local timers
    TUclILStreamLocalTimerCbk localTimersCbk[UCLILSTREAM_IMPL_MAX_LOCAL_TIMERS]; ///< Array of local timers callbacks
};

///
/// @brief This method implements the Initialize API for the IUclILStream Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Initialization Success
/// @return UCL_E_NOK   Initialization Failed
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Initialize ( SUclILStreamInst *pInst, uint8 InstId );

///
/// @brief This method implements the Shutdown API for the IUclILStream Interface
///
/// @param pInst    Pointer to the Instance
/// @param InstId   Instance Id of the callee
///
/// @return UCL_E_OK    Shutdown Success
/// @return UCL_E_NOK   Shutdown Failed
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Shutdown ( SUclILStreamInst *pInst, uint8 InstId );

///
/// @brief This method implements the Open API for the IUclILStream Interface
///
/// @param[in]  chId    Channel Identifier
/// @param[in]  flags   @ref UCL_O_FLAGS
///
/// @return > 0 File descriptor to be used
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Open ( SUclILStreamInst *pInst, uint8 InstId, ucl_ch_t chnId, uint16 flags );

///
/// @brief This method implements the Close API for the IUclILStream Interface
///
/// @param[in]  fd  File descriptor returned by the open call
///
/// @return @ref UCL_E_OK   Successfully closed the channel
/// @return @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Close ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd );

///
/// @brief This method implements the Read API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[out] pBuffer Buffer to return the received data
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes read
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Read ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 *pBuffer, uint16 size );

///
/// @brief This method implements the Write API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Write ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 *pBuffer, uint16 size );

///
/// @brief This method implements the Poll API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  timeout Timeout to wait for data
///
/// @return > 0 number of bytes waiting to be read
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Poll ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint32 timeout );

///
/// @brief This method implements the PollEx API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID used in the ucl_write_ex call
/// @param[out] pStatus Transmit status of the message
/// @param[in]  timeout Timeout to wait for the confirmation
///
/// @return @ref UCL_E_OK   Status returned successfully
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_PollEx ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 reqId, uint32 *pStatus, uint32 timeout );

///
/// @brief This method implements the WriteEx API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  reqId   Request ID to be associated with this write request
/// @param[in]  pBuffer Buffer that contains the data to be sent
/// @param[in]  size    Size of the buffer
///
/// @return > 0 number of bytes sent
/// @return < 0 @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_WriteEx ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 reqId, uint8 *pBuffer, uint16 size );

///
/// @brief This method implements the Ioctl API for the IUclILStream Interface
///
/// @param[in]  fd      File descriptor returned by the open call
/// @param[in]  request @ref UCL_IOCTL
/// @param[in]  pData   Pointer to the structure corresponding to the request
/// @param[in]  size    Size of the structure
///
/// @return @ref UCL_E_OK   Success
/// @return @ref UCL_ERR
///
Ucl_ReturnType UclILStream_Impl_IUclILStream_Ioctl ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint16 request, void *pData, uint16 size );

///
/// @brief  This method will be called when UclDL encounters any
///         Fatal Error
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the Fatal Error
///
void UclILStream_Impl_IUclDLCbk_FatalError ( SUclILStreamInst *pInst, uint8 InstId, uint8 Status );

///
/// @brief  This method will be called when UclDL receive a new
///         Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param pMsg   Pointer to the received Ucl Message
///
void UclILStream_Impl_IUclDLCbk_MsgReceived ( SUclILStreamInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg );

///
/// @brief  This method will be called by the UclDL to notify
///         about the transmit status of the Ucl Message
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the requested transmission
///
void UclILStream_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILStreamInst *pInst, uint8 InstId, uint16 msgID, EUclDLAckStatus Status );

///
/// @brief  This method will be called by the UclDL to notify
///         about the change in the Link Status
///
/// @param InstId Instance Id of the class that implements UclDLCbk
/// @param Status Status of the UclDL Link
///
void UclILStream_Impl_IUclDLCbk_LinkStatusChanged ( SUclILStreamInst *pInst, uint8 InstId, EUclDLLinkStatus Status );

#endif //UCL_STREAM_IMPL_H
