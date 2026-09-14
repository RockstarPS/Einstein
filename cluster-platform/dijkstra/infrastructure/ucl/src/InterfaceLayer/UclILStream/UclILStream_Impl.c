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
///---------------------------------------------------------------------------------------------------------------------
#include "UclILStream_Impl.h"
#include "UclILStreamAdapter.h"
#include "UclBufferPool.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclDL.h"

#define UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX (0u)
#define UCLILSTREAM_MSG_SCHED_LOCAL_TIMER_IDX (1u)

#define UCLILSTREAM_SET_DL_LINK_STATUS(p, d, s) ((p)->pCfg->pDLCfg[(d)].pData->linkStatus = (s))
#define UCLILSTREAM_GET_DL_LINK_STATUS(p, d) ((p)->pCfg->pDLCfg[(d)].pData->linkStatus)

#define UCLILSTREAM_INIT_TIMER(p, t, cb) \
    ((p)->localTimers[(t)] = 0u);        \
    ((p)->localTimersCbk[(t)] = (cb))

#define UCLILSTREAM_START_TIMER(p, t, to) ((p)->localTimers[(t)] = ((uint32)(to) / (p)->pCfg->timerTaskPeriodicityMs))
#define UCLILSTREAM_STOP_TIMER(p, t) ((p)->localTimers[(t)] = 0u)
#define UCLILSTREAM_DEC_TIMER(p, t) ((p)->localTimers[(t)]--)
#define UCLILSTREAM_IS_RUNNING_TIMER(p, t) (0u < (p)->localTimers[(t)])
#define UCLILSTREAM_IS_ELAPSED_TIMER(p, t) (0u == (p)->localTimers[(t)])
#define UCLILSTREAM_CALL_EXPIRY_FUNC(p, t) ((((p)->localTimersCbk[(t)]))(p))

#define UCLILSTREAM_MSG_CHID_GET(CHID) (((CHID) >> 8u) & 0x00FFu)
#define UCLILSTREAM_MSG_RID_GET(CHID)  ((CHID) & 0x00FFu)

static void *UclILStream_Impl_TimerTask ( void *pData );
static void UclILStream_Impl_FdDeQueueTask ( SUclILStreamInst *pInst );
static void UclILStream_Impl_RunMessageScheduler ( SUclILStreamInst *pInst );
static void UclILStream_Impl_RunFixedPrioScheduler ( SUclILStreamInst *pInst, uint8 DLIdx );
static Ucl_ReturnType UclILStream_Impl_FixedPrioSchedGetNextMessage ( SUclILStreamInst *pInst, uint8 DLIdx, uint8 *pMsgInfo );
static Ucl_ReturnType UclILStream_Impl_TransmitMessage ( SUclILStreamInst *pInst, uint8 DLIdx, SUclPriorityQueueElement_t *pMsgInfo,
        uint8 *pMsgBuff, uint16 Length );
static Ucl_ReturnType UclILStream_Impl_WriteMessageToPrioQueue ( SUclILStreamInst *pInst, uint8 DLIdx, EUclILMsgPriorityLevel Prio, uint8 *pData, uint16 size );
static uint8 UclILStream_Impl_GenerateRID ( void );
static Ucl_ReturnType UclILStream_Impl_ProcessReceivedMessage ( SUclILStreamInst *pInst, EUclDLRxStatus Status, SUclDLMsg *pMsg );
static Ucl_ReturnType UclILStream_Impl_GetDLIndex ( SUclILStreamInst *pInst, uint8 DLInstId, uint8 *DLIndex );

Ucl_ReturnType UclILStream_Impl_IUclILStream_Initialize ( SUclILStreamInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    const SUclILStreamCfg *pStreamCfg = pInst->pCfg;
    uint8 i, j;
    SUclILStreamDLCfg *pDLCfg;
    SUclILStreamDLData *pDLData;

    pInst->isInitialized = FALSE;

    //UclBufferPool_Initialize
    Ret = UclBufferPool_Initialize ( &pInst->mBufferPool, pStreamCfg->pBufferPoolCfg );

    //FD Queue Initialize
    if ( UCL_E_OK == Ret )
    {
        Ret = UclILStream_Impl_FdInitialize ( &pInst->mFDQueueList, pStreamCfg->pFdCfg );
    }

    //Channel Queue Initialize
    if ( UCL_E_OK == Ret )
    {
        Ret = UclILStream_Impl_ChnInitialize ( &pInst->mChannelList, pStreamCfg->pChnCfg );
    }

    // Create Timer
    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclILStream_Impl_TimerTask, ( void * ) pInst,
                        eUclOsTimerType_Periodic );
    }

    // Create Scheduler Timer Task Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->uclTimerTaskProtectMutexId );
    }

    // Initialize local pooled timers
    UCLILSTREAM_INIT_TIMER ( pInst, UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX,
            UclILStream_Impl_FdDeQueueTask );
    UCLILSTREAM_INIT_TIMER ( pInst, UCLILSTREAM_MSG_SCHED_LOCAL_TIMER_IDX,
            UclILStream_Impl_RunMessageScheduler );

    // Initialize Data Layer Instances
    if ( Ret == UCL_E_OK )
    {
        for ( i = 0; i < pInst->numIUclDL; i++ )
        {
            // Initialize Link Status
            UCLILSTREAM_SET_DL_LINK_STATUS ( pInst, i, eUclDLLinkStatus_Down );

            Ret = UclDL_Initialize ( pInst->pIUclDL[i] );

            if ( UCL_E_OK == Ret )
            {
                // Create per DL instance resources
                for ( j = 0; j < eUclILMsgPriorityLevel_Last; j++ )
                {
                    pDLCfg = &pInst->pCfg->pDLCfg[i];
                    pDLData = pDLCfg->pData;

                    // Initialize Prio Queues
                    Ret = UclCmnRingBuffer_Initialize ( & ( pDLData->prioQueue[j] ), pDLCfg->prioQueueCfg[j].pData,
                                    pDLCfg->prioQueueCfg[j].size );

                    // Create Queue Locks
                    if ( UCL_E_OK == Ret )
                    {
                        Ret = UclALOs_MutexCreate ( 0, &pDLData->prioQueueLocks[j] );
                    }

                    if ( UCL_E_OK != Ret )
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }

    // Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->timerTaskPeriodicityMs );
    }

    if ( Ret == UCL_E_OK )
    {
        LOGI ( 0, "UclILStream_Impl", "%s", "IUclILStream_Initialize: Success" );
        pInst->isInitialized = TRUE;
    }
    else
    {
        LOGE ( 0, "UclILStream_Impl", "IUclILStream_Initialize: Failed %d", Ret );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Shutdown ( SUclILStreamInst *pInst, uint8 InstId )
{
    SUclILStreamDLCfg *pDLCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i, j;

    for ( i = 0; i < pInst->numIUclDL; i++ )
    {
        Ret = UclDL_Shutdown ( pInst->pIUclDL[i] );

        if ( UCL_E_OK == Ret )
        {
            for ( j = eUclILMsgPriorityLevel_Critical ; j < eUclILMsgPriorityLevel_Last ; j++ )
            {
                pDLCfg = &pInst->pCfg->pDLCfg[i];
                Ret = UclALOs_MutexDestroy ( 0, pDLCfg->pData->prioQueueLocks[j] );

                if ( UCL_E_OK != Ret )
                {
                    break;
                }
            }

            // Initialize Link Status
            UCLILSTREAM_SET_DL_LINK_STATUS ( pInst, i, eUclDLLinkStatus_Down );
        }
        else
        {
            break;
        }
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStop ( 0, pInst->timerTaskId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexDestroy ( 0, pInst->uclTimerTaskProtectMutexId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_ChnShutdown ( &pInst->mChannelList );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret =  UclILStream_Impl_FdShutdown ( &pInst->mFDQueueList );
        UclBufferPool_Shutdown ( &pInst->mBufferPool );

    }

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclILStream_Impl", "UclILStream_Shutdown: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclILStream_Impl", "%s", "UclILStream_Shutdown: Success" );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Open ( SUclILStreamInst *pInst, uint8 InstId, ucl_ch_t chnId, uint16 flags )
{
    uint32 ChnIndex = 0;
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( pInst->isInitialized == TRUE )
    {
        Ret = UclILStream_Impl_ChnOpen ( &pInst->mChannelList, chnId, flags, &ChnIndex );

        if ( Ret == UCL_E_OK )
        {
            // Allocate a file descriptor
            Ret = UclILStream_Impl_FdGet ( &pInst->mFDQueueList, ChnIndex, flags );

            if ( Ret < UCL_E_OK )
            {
                //Release Allocated Channel
                ( void ) UclILStream_Impl_ChnClose ( &pInst->mChannelList, ChnIndex );
                LOGE ( 0, "IUclILStream_Open", " Failed for Channel Id ", chnId );
            }
            else
            {
                LOGI ( 0, "UclILStream_Open", " FD = %d ## chId = %d  ## ChnIndex = %d ", Ret, chnId, ChnIndex );
            }
        }
    }
    else
    {
        LOGE ( 0, "UclILStream_Open", "%s", " Invalid Invocation " );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Close ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd )
{
    SUclFileDescAttr_t attr = {0x0};
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclTxFdQueueElement_t readData = {0x0};
    uint16 readSize;
    SUclRxFdQueueElement_t getData = {0x0};
    SUclChnQueueElement_t chQueueElement;
    SUclChnCfg_t *pChnCfg = pInst->mChannelList.mpCfg;
    SUclChnQueue_t *pChnQueue;
    uint16 index;

    if ( pInst->isInitialized == TRUE )
    {
        //Get the Channel Index
        Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &attr );

        if ( Ret == UCL_E_OK )
        {
            //Read all the Elements in Txq and Rxq and clear the buffer
            readSize = ( uint16 ) sizeof ( SUclTxFdQueueElement_t );

            while ( UclILStream_Impl_FdReadFromTxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &readData, &readSize )
                    == UCL_E_OK )
            {
                ( void ) UclBufferPool_Put ( &pInst->mBufferPool, readData.bId );
            }

            readSize = ( uint16 ) sizeof ( SUclRxFdQueueElement_t );

            while ( UclILStream_Impl_FdReadFromRxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &getData, &readSize,
                            eUclFileDescReadFdRxq_Read ) == UCL_E_OK )
            {
                ( void ) UclBufferPool_Put ( &pInst->mBufferPool, getData.bId );

            }


            if ( attr.mChnIndex < pChnCfg->maxChn )
            {
                pChnQueue = &pChnCfg->mpChnQueueList->mpQueueList[attr.mChnIndex];

                for ( index = 0; index < pChnQueue->chnQueuesize; index++ )
                {
                    Ret = UclILStream_Impl_ChnQueueRead ( &pInst->mChannelList, attr.mChnIndex, index, &chQueueElement );

                    if ( ( chQueueElement.fId == fd ) && ( Ret == UCL_E_OK ) )
                    {
                        ( void ) UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, attr.mChnIndex, index );
                        ( void ) UclBufferPool_Put ( &pInst->mBufferPool, chQueueElement.bId );

                    }
                }

                // Flush Rx & Tx queue
                ( void ) UclILStream_Impl_FdFlushTxq ( &pInst->mFDQueueList, fd );
                ( void ) UclILStream_Impl_FdFlushRxq ( &pInst->mFDQueueList, fd );
                //Release FD Queue
                UclILStream_Impl_FdRelease ( &pInst->mFDQueueList, fd );
                //Release Channel
                Ret = UclILStream_Impl_ChnClose ( &pInst->mChannelList, attr.mChnIndex );
                //buffer scan
            }
            else
            {
                LOGI ( 0, "IUclILStream_Close", " Fd not Released : Invalid ChnIndex %d", attr.mChnIndex );
            }
        }
    }
    else
    {
        LOGE ( 0, "UclILStream_Close", "%s", " Invalid Invocation " );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Read ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_INVALID_STATE;
    SUclRxFdQueueElement_t getData = { 0x0 };
    SUclFileDescAttr_t attr;
    uint16 readLen = 0;
    sint32 payloadLen = -1;

    if ( pInst->isInitialized == TRUE )
    {
        //Get the Channel Index
        Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &attr );
    }

    if ( Ret == UCL_E_OK )
    {
        //Get the Rcv FD Queue Element
        readLen = ( uint16 ) sizeof ( getData );
        Ret = UclILStream_Impl_FdReadFromRxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &getData, &readLen,  eUclFileDescReadFdRxq_Read );

        if ( Ret == UCL_E_OK )
        {
            if ( readLen == ( uint16 ) sizeof ( getData ) )
            {
                //Read the Payload from Buffer Pool
                payloadLen = UclBufferPool_Read ( &pInst->mBufferPool, getData.bId, pBuffer, size );

                if ( payloadLen > 0 )
                {
                    Ret = UclBufferPool_Put ( &pInst->mBufferPool, getData.bId );
                }
            }
            else
            {
                LOGE ( 0, "UclILStream_Read", "FD RxQ Read returned lesser length %d ", readLen );
            }
        }
    }

    if ( payloadLen > 0 )
    {
        Ret = payloadLen;
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Write ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_LINK_DOWN;
    SUclTxFdQueueElement_t writeData;
    SUclFileDescAttr_t fdAttr;
    SUclChnAttr_t chnAttr;

    //Check the Link Status
    if ( eUclDLLinkStatus_Up == UCLILSTREAM_GET_DL_LINK_STATUS ( pInst, 0 ) )
    {
        Ret = UCL_E_OK;
    }

    //Check the UCL Initialization status
    if ( ( Ret == UCL_E_OK ) && ( pInst->isInitialized != TRUE ) )
    {
        Ret = UCL_E_INVALID_STATE;
    }

    //Get the Fd Type
    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );
    }

    //Get the Channel ID Mapped to this FD
    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
    }

    //Get the Buffer Pool Id
    if ( Ret == UCL_E_OK )
    {
        Ret = UclBufferPool_Get ( &pInst->mBufferPool, size );

        if ( Ret >= 0 )
        {
            writeData.bId = Ret;

            //Write the Payload to Buffer Pool
            Ret = UclBufferPool_Write ( &pInst->mBufferPool, writeData.bId, pBuffer, size );

            //Add the Message Info to Tx FDQ
            if ( Ret == ( sint32 ) size )
            {
                writeData.rId = UclILStream_Impl_GenerateRID();
                writeData.chnId = chnAttr.mChId;
                writeData.timeMs = UclALOs_GetSystemTimeMs ( 0u );
                Ret = UclILStream_Impl_FdWriteToTxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &writeData,
                                ( uint16 ) sizeof ( writeData ) );

                if ( Ret == UCL_E_OK )
                {
                    Ret = ( sint32 ) size;
                }
            }

            if ( Ret != ( sint32 ) size )
            {
                //Release Buffer acquired on failure
            	Ret = UCL_E_FD_Q_FULL;
                (void) UclBufferPool_Put ( &pInst->mBufferPool, writeData.bId );
                LOGE ( 0, "UclILStream_Write", "%s", "Write Failed " );
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_WriteEx ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 reqId, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_LINK_DOWN;
    SUclTxFdQueueElement_t writeData;
    SUclFileDescAttr_t fdAttr;
    SUclChnAttr_t chnAttr;

    //Check the Link Status
    if ( eUclDLLinkStatus_Up == UCLILSTREAM_GET_DL_LINK_STATUS ( pInst, 0 ) )
    {
        Ret = UCL_E_OK;
    }

    // Check for Req id
    if ( reqId >= UCL_OWNED_REQID_START )
    {
        Ret = UCL_E_INVALID_ARGS;
    }

    //Check the UCL Initialization status

    if ( ( Ret == UCL_E_OK ) && ( pInst->isInitialized != TRUE ) )
    {
        Ret = UCL_E_INVALID_STATE;
    }

    //Get the Fd Type
    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );
    }

    //Get the Channel ID Mapped to this FD
    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
    }

    //Get the Buffer Pool Id
    if ( Ret == UCL_E_OK )
    {
        Ret = UclBufferPool_Get ( &pInst->mBufferPool, size );

        if ( Ret >= 0 )
        {
            writeData.bId = Ret;

            //Write the Payload to Buffer Pool
            Ret = UclBufferPool_Write ( &pInst->mBufferPool, writeData.bId, pBuffer, size );

            //Add the Message Info to Tx FDQ
            if ( Ret == ( sint32 ) size )
            {
                writeData.rId = reqId;
                /// Inspect the channel index and verify the request Id is
                writeData.chnId = chnAttr.mChId;
                writeData.timeMs = UclALOs_GetSystemTimeMs ( 0u );
                Ret = UclILStream_Impl_FdWriteToTxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &writeData,
                                ( uint16 ) sizeof ( writeData ) );

                if ( Ret == UCL_E_OK )
                {
                    Ret = ( sint32 ) size;
                }
            }

            if ( Ret != ( sint32 ) size )
            {
                //Release Buffer acquired on failure
                Ret = UclBufferPool_Put ( &pInst->mBufferPool, writeData.bId );
                LOGE ( 0, "UclILStream_Write", "%s", " Failed " );
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Poll ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint32 timeout )
{
    Ucl_ReturnType Ret = UCL_E_INVALID_STATE;
    SUclRxFdQueueElement_t getData = { 0x0 };
    SUclFileDescAttr_t fdAttr;
    uint16 readLen = 0;
    sint32 payloadLen = -1;

    if ( pInst->isInitialized == TRUE )
    {
        Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );

        if ( Ret == UCL_E_OK )
        {
            readLen = ( uint16 ) sizeof ( getData );
            Ret = UclILStream_Impl_FdReadFromRxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &getData, &readLen, eUclFileDescReadFdRxq_Poll );
        }

        if ( Ret == UCL_E_OK )
        {
            if ( readLen == ( uint16 ) sizeof ( getData ) )
            {
                //Read the Payload from Buffer Pool
                payloadLen = UclBufferPool_Read ( &pInst->mBufferPool, getData.bId, NULL, 0 );

                if ( payloadLen > 0 )
                {
                    Ret = payloadLen;
                }
            }
            else
            {
                LOGE ( 0, "UclILStream_Poll", "FD RxQ Read returned lesser length %d ", readLen );
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_IUclILStream_PollEx ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint8 reqId, uint32 *pStatus, uint32 timeout )
{
    return UCL_E_OK;

}

Ucl_ReturnType UclILStream_Impl_IUclILStream_Ioctl ( SUclILStreamInst *pInst, uint8 InstId, sint32 fd, uint16 request, void *pData, uint16 size )
{

    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnAttr_t chnAttr;
    SUclFileDescAttr_t fdAttr;
    ucl_ioctl_channel_param_t ioCtlChParam;
    ucl_ioctl_channel_stats_t ioCtlChStatus;
    SUclDLStats getDLStats;
    SUclTxFdQueueElement_t readData = {0x0};
    uint16 readSize;
    SUclRxFdQueueElement_t getData = {0x0};
    SUclChnQueueElement_t chQueueElement;
    SUclChnCfg_t *pChnCfg = pInst->mChannelList.mpCfg;
    SUclChnQueue_t *pChnQueue;
    uint16 index;

    switch ( request )
    {
        case UCL_IOCTL_SET_CHANNEL_PARAM:

            // Copy the Payload
            if ( size == ( uint16 ) sizeof ( ucl_ioctl_channel_param_t ) )
            {
                ( void ) UclALOs_Memcpy ( 0, &ioCtlChParam, pData, size );
                // Get channel attribute based on fd
                Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );

                //Get the Channel ID Mapped to this FD
                if ( Ret == UCL_E_OK )
                {
                    //Get Channel Attribute
                    Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
                }

                if ( Ret == UCL_E_OK )
                {
                    // Update Channel parameters
                    chnAttr.priority_level = ioCtlChParam.priority_level;
                    chnAttr.security_level = ioCtlChParam.security_level;
                    chnAttr.time_to_live_ms = ioCtlChParam.time_to_live_ms;
                    Ret = UclILStream_Impl_ChnSetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
                }
            }

            break;

        case UCL_IOCTL_GET_CHANNEL_PARAM:

            if ( size == ( uint16 ) sizeof ( ucl_ioctl_channel_param_t ) )
            {
                // Get channel attribute based on fd
                Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );

                if ( Ret == UCL_E_OK )
                {
                    Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
                }

                if ( Ret == UCL_E_OK )
                {
                    ioCtlChParam.priority_level = chnAttr.priority_level;
                    ioCtlChParam.security_level = chnAttr.security_level;
                    ioCtlChParam.time_to_live_ms = chnAttr.time_to_live_ms;
                    ( void ) UclALOs_Memcpy ( 0, pData, &ioCtlChParam, sizeof ( ioCtlChParam ) );
                }

            }

            break;

        case UCL_IOCTL_GET_LINK_STATUS:

            if ( pData != NULL )
            {

                Ret = UCL_E_OK;

                if ( eUclDLLinkStatus_Up == UCLILSTREAM_GET_DL_LINK_STATUS ( pInst, 0 ) )
                {
                    * ( ( sint32 * ) pData ) = UCL_E_LINK_UP;
                }
                else if ( eUclDLLinkStatus_Down == UCLILSTREAM_GET_DL_LINK_STATUS ( pInst, 0 ) )
                {
                    * ( ( sint32 * ) pData ) = UCL_E_LINK_DOWN;
                }
                else
                {
                    * ( ( sint32 * ) pData ) = UCL_E_NOK;
                }
            }

            break;

        case UCL_IOCTL_GET_STATS:

            if ( size == ( uint16 ) sizeof ( ioCtlChStatus ) )
            {
                Ret = UclDL_GetStats ( 0, &getDLStats );

                if ( Ret == UCL_E_OK )
                {
                    ioCtlChStatus.dl.tx_bytes = getDLStats.txBytes;
                    ioCtlChStatus.dl.rx_bytes = getDLStats.rxBytes;
                    ioCtlChStatus.dl.tx_msgs = getDLStats.txMsgs;
                    ioCtlChStatus.dl.rx_msgs = getDLStats.rxMsgs;
                    ioCtlChStatus.dl.tx_kbps = getDLStats.txBps;
                    ioCtlChStatus.dl.rx_kbps = getDLStats.rxBps;
                    ioCtlChStatus.dl.avg_ack_latency = getDLStats.avgAckLatency;
                    ioCtlChStatus.il.num_open_channels = pInst->mChannelList.mActiveChn;
                    ioCtlChStatus.il.num_open_fds = pInst->mFDQueueList.mActiveFds;

                    ( void ) UclALOs_Memcpy ( 0, pData, &ioCtlChStatus, sizeof ( ioCtlChStatus ) );
                }
            }

            break;

        case UCL_IOCTL_FLUSH_TX_QUEUE:

            Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );

            //Read FD attribute was sucessful
            if ( Ret == UCL_E_OK )
            {
                readSize = ( uint16 ) sizeof ( SUclTxFdQueueElement_t );

                while ( UclILStream_Impl_FdReadFromTxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &readData, &readSize )
                        == UCL_E_OK )
                {
                    ( void ) UclBufferPool_Put ( &pInst->mBufferPool, readData.bId );
                }

                if(fdAttr.mChnIndex < pChnCfg->maxChn )
                {
                    pChnQueue = &pChnCfg->mpChnQueueList->mpQueueList[fdAttr.mChnIndex];

                    for ( index = 0; index < pChnQueue->chnQueuesize; index++ )
                    {
                        Ret = UclILStream_Impl_ChnQueueRead ( &pInst->mChannelList, fdAttr.mChnIndex, index,
                                        &chQueueElement );

                        if ( ( chQueueElement.fId == fd ) && ( Ret == UCL_E_OK ) )
                        {
                            ( void ) UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, fdAttr.mChnIndex, index );
                            ( void ) UclBufferPool_Put ( &pInst->mBufferPool, chQueueElement.bId );
                        }
                    }

                    Ret = UclILStream_Impl_FdFlushTxq ( &pInst->mFDQueueList, fd );
                }
                else
                {
                    Ret = UCL_E_NOK;
                }
            }

            break;

        case UCL_IOCTL_FLUSH_RX_QUEUE:

            Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, fd, &fdAttr );

            if ( Ret == UCL_E_OK )
            {
                readSize = ( uint16 ) sizeof ( SUclRxFdQueueElement_t );

                while ( UclILStream_Impl_FdReadFromRxq ( &pInst->mFDQueueList, fd, ( uint8 * ) &getData, &readSize,
                                eUclFileDescReadFdRxq_Read ) == UCL_E_OK )
                {
                    ( void ) UclBufferPool_Put ( &pInst->mBufferPool, getData.bId );

                }

                Ret = UclILStream_Impl_FdFlushRxq ( &pInst->mFDQueueList, fd );
            }

            break;

        case UCL_IOCTL_SET_NOTIFY_INFO:
            Ret =UCL_E_NOK;
            break;

        case UCL_IOCTL_GET_NOTIFY_INFO:
            Ret =UCL_E_NOK;
            break;

        default:
            Ret =UCL_E_NOK;
            break;
    }

    return Ret;
}

void UclILStream_Impl_IUclDLCbk_FatalError ( SUclILStreamInst *pInst, uint8 InstId, uint8 Status )
{
    sint32 errStatus = UCL_E_NOK;

    if ( ( EUclDLError ) Status == eUclDLError_FatalError )
    {
        errStatus = UCL_E_FATAL;
    }
    else if ( ( EUclDLError ) Status == eUclDLError_SecurityTSCError )
    {
        errStatus = UCL_E_SEC_TSC;
    }
    else if ( ( EUclDLError ) Status == eUclDLError_SecurityCMACError )
    {
        errStatus = UCL_E_SEC_CMAC;
    }
    else if ( ( EUclDLError ) Status == eUclDLError_SecurityNegoError )
    {
        errStatus = UCL_E_SEC_NEGO;
    }
    else
    {
        // No code required
    }

    UCLILAdapter_ErrorNotification ( InstId, errStatus );

    return;
}

void UclILStream_Impl_IUclDLCbk_MsgReceived ( SUclILStreamInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg )
{

    Ucl_ReturnType Ret;

    //  Message receive handled in i.e UclILStream_Impl
    //  if (pInst->pCfg->nodeId == UCLDL_MSG_GET_DESTNODE_ID(pMsg->MsgHdr)) (Not supporting multiInstance UCL */
    {
        Ret = UclILStream_Impl_ProcessReceivedMessage ( pInst, Status, pMsg );

        if ( UCL_E_OK != Ret )
        {
            LOGW ( 0, "UclILStream_Impl", "IUclDLCbk_MsgReceived Unknown message ID received 0x%04x %d", pMsg->MsgId,
                    pMsg->Size );

        }
    }

    return;
}

static Ucl_ReturnType UclILStream_Impl_ProcessReceivedMessage ( SUclILStreamInst *pInst, EUclDLRxStatus Status,
        SUclDLMsg *pMsg )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    ucl_ch_t chnId;
    uint32 chIndex;
    sint32 byteSent;
    sint32 bId;
    uint8 index;
    SUclRxFdQueueElement_t rxDataFdInfo = {0x0};
    ucl_fd_t *pfdlist = pInst->pCfg->prxFdlist;
    uint16 numFds = pInst->pCfg->maxFds;

    // Get the channel ID
    chnId = ( ucl_ch_t ) UCLILSTREAM_MSG_CHID_GET ( pMsg->MsgId );
    //Get the channel index
    Ret = UclILStream_Impl_ChnGetIdx ( &pInst->mChannelList, chnId, &chIndex );

    // Get the Channel Listeners list
    if ( Ret == UCL_E_OK )
    {
        Ret = UclILStream_Impl_FdGetRxFdList ( &pInst->mFDQueueList, chIndex, pfdlist, &numFds );
    }

    if ( Ret == UCL_E_OK )
    {
        if ( eUclDLRxStatus_Ok == Status )
        {
            //Get the buffer id
            bId = UclBufferPool_Get ( &pInst->mBufferPool, pMsg->Size );

            if ( bId >= 0 )
            {
                byteSent = UclBufferPool_Write ( &pInst->mBufferPool, bId, pMsg->pPayload, pMsg->Size );

                if ( byteSent > 0 )
                {
                    // Update the buffer id
                    rxDataFdInfo.bId = bId;

                    // Increment buffer reference: if there is more than 1 fd/channel*/
                    for ( index = 0; index < numFds; index++ )
                    {
                        // Update the buffer id
                        if ( index < ( numFds - 1u ) )
                        {
                            ( void ) UclBufferPool_AddRef ( &pInst->mBufferPool, bId );
                        }
                        // Write data into Rxqueue
                        Ret = UclILStream_Impl_FdWriteToRxq ( &pInst->mFDQueueList, pfdlist[index], ( uint8 * ) &rxDataFdInfo, ( uint16 ) sizeof ( rxDataFdInfo ) );

						if(Ret != UCL_E_OK )
                        {
						    (void) UclBufferPool_Put ( &pInst->mBufferPool, bId );
						    UCLILAdapter_QueueFullNotification( pfdlist[index] , UCL_NOTIFY_DATA_LOSS);
							LOGE ( 0, "UclILStream_Impl_ProcessReceivedMessage", " Buffer Flushed : Write to Rxq Failed for  bId %d ## chId %d ## fid %d ## MsgId = %d ## MsgSize = %d", bId, chnId,  pfdlist[index], pMsg->MsgId, pMsg->Size );
                        }

                        UCLILAdapter_DataReceived( pfdlist[index] );
                    }
                }
                else
                {
                    LOGE ( 0, "UclILStream_Impl_ProcessReceivedMessage", " Buffer flushed : Buffer Pool Write Failed for bId %d ## chId %d ## MsgId = %d ## MsgSize = %d", bId, chnId, pMsg->MsgId, pMsg->Size );
                    //Release Buffer Id
                    Ret = UclBufferPool_Put ( &pInst->mBufferPool, bId );
                }
            }
			else
			{
				for (index = 0; index < numFds; index++)
				{
					UCLILAdapter_QueueFullNotification( pfdlist[index] , UCL_NOTIFY_DATA_LOSS);
					LOGE( 0, "UclILStream_Impl_ProcessReceivedMessage", " Buffer Not available Write Failed for  chId %d ## MsgId = %d ## MsgSize = %d", chnId, pfdlist[index], pMsg->MsgId, pMsg->Size );
				}

			}
        }
        else
        {
            LOGE ( 0, "UclILStream_Impl_ProcessReceivedMessage", " Rcvd Msg with status %d", Status );
        }
    }
    else
    {
        LOGE ( 0, "UclILStream_Impl_ProcessReceivedMessage", "No Listener for Channel %d", chnId );
    }

    return Ret;
}

void UclILStream_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILStreamInst *pInst, uint8 InstId, uint16 msgID, EUclDLAckStatus Status )
{
    uint16 index = 0;
    Ucl_ReturnType Ret = UCL_E_NOK;
    ucl_ch_t chnId;
    uint8 reqId;
    uint32 chIndex;
    SUclChnQueueElement_t chQueueElement = { 0x0 };
    SUclChnAttr_t chnAttr;
    SUclPriorityQueueElement_t chPrQElement;
    uint8 reqIdFound = FALSE;
    Ucl_ReturnType ackStatus = UCL_E_MSG_NACK;
    SUclChnCfg_t *pChnCfg = pInst->mChannelList.mpCfg;
    SUclChnQueue_t *pChnQueue;
    uint64 timeNow;

    // Update the channel id
    chnId = ( ucl_ch_t ) UCLILSTREAM_MSG_CHID_GET ( msgID );
    // Update the request id
    reqId = ( uint8 ) UCLILSTREAM_MSG_RID_GET ( msgID );

    // Get the channel index
    Ret = UclILStream_Impl_ChnGetIdx ( &pInst->mChannelList, chnId, &chIndex );

    // Get the channel id parameters
    if ( ( Ret == UCL_E_OK ) && ( chIndex < pInst->mChannelList.mpCfg->maxChn ) )
    {
        pChnQueue = &pChnCfg->mpChnQueueList->mpQueueList[chIndex];

        for ( index = 0; index < pChnQueue->chnQueuesize; index++ )
        {
            Ret = UclILStream_Impl_ChnQueueRead ( &pInst->mChannelList, chIndex, index, &chQueueElement );

            if ( Ret != UCL_E_OK )
            {
                LOGE ( 0, "UclILStream_Impl_IUclDLCbk_MsgTransmitStatus", " Read from ChQ failed ##chIndex %d ", chIndex );
            }

            if ( chQueueElement.mId == msgID )
            {
                reqIdFound = TRUE;
                break;

            }
        }
    }

    if ( reqIdFound == TRUE )
    {
        // If Pos Ack  : free the buffer
        if ( Status == eUclDLAckStatus_Ok )
        {
            // Call channel API and release the resource
            ( void ) UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, chIndex, index );

            // Call buffer ID and release the resource
            ( void ) UclBufferPool_Put ( &pInst->mBufferPool, chQueueElement.bId );

        }
        else
        {
            // get the channel attribute
            Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, chIndex, &chnAttr );

            // Get the os time event
            timeNow = UclALOs_GetSystemTimeMs ( 0u );

            if ( Ret == UCL_E_OK )
            {
                Ret = UCL_E_NOK;

                if ( ( ( timeNow - chQueueElement.timeMs ) < chnAttr.time_to_live_ms ) || ( chnAttr.time_to_live_ms == 0u ) )
                {
                    chPrQElement.bId = chQueueElement.bId;
                    chPrQElement.chnId = chnId;
                    chPrQElement.mId = msgID;
                    // Reschedule the Message
                    Ret = UclILStream_Impl_WriteMessageToPrioQueue ( pInst, 0, ( EUclILMsgPriorityLevel ) chnAttr.priority_level,
                                    ( uint8 * ) &chPrQElement, ( uint16 ) sizeof ( chPrQElement ) );

                    if ( Ret != UCL_E_OK )
                    {
                        LOGE ( 0, "UclILStream_Impl_IUclDLCbk_MsgTransmitStatus", " Re-Write to Priority Queue failed ##bId %d ## chnId %d ## MsgId = %d",
                                chPrQElement.bId, chPrQElement.chnId, chPrQElement.mId );
                    }
                }
            }

            // Clear the buffer if unable to write in Priority Queue or transmit timeout elapsed
            if ( Ret != UCL_E_OK )
            {
                // Call channel API and release the resource
                ( void ) UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, chIndex, index );

                // Call buffer ID and release the resource
                ( void ) UclBufferPool_Put ( &pInst->mBufferPool, chQueueElement.bId );

                LOGE ( 0, "UclILStream_Impl_IUclDLCbk_MsgTransmitStatus", " Buffer Released  ##bId %d", chQueueElement.bId  );
            }
        }

        switch ( Status )
        {
            case eUclDLAckStatus_Ok:
                ackStatus = UCL_E_MSG_ACK;
                break;

            case eUclDLAckStatus_Error:
                ackStatus = UCL_E_MSG_NACK;
                break;

            case eUclDLAckStatus_Timeout:
                ackStatus = UCL_E_MSG_ACK_TMO;
                break;

            default:
                LOGE ( 0, "UclILStream_Impl_IUclDLCbk_MsgTransmitStatus", " Invalid Status : %d", Status );
                break;
        }

        if ( reqId < UCL_OWNED_REQID_START )
        {
            UCLILAdapter_MessageTransmitStatus ( chQueueElement.fId, reqId, ackStatus );
        }
    }

    return;
}

void UclILStream_Impl_IUclDLCbk_LinkStatusChanged ( SUclILStreamInst *pInst, uint8 InstId, EUclDLLinkStatus Status )
{
    uint8 it;
    uint8 DLIdx = 0;
    Ucl_ReturnType linkStatus;

    // Update DL status flags
    if(UCL_E_OK == UclILStream_Impl_GetDLIndex ( pInst, InstId, &DLIdx ) )
    {
        if(DLIdx < pInst->numIUclDL)
        {
            UCLILSTREAM_SET_DL_LINK_STATUS ( pInst, DLIdx, Status );
        }
    }

    if ( eUclDLLinkStatus_Up == Status )
    {
        // Start processing if one of the DL instance is up
        if ( ! UCLILSTREAM_IS_RUNNING_TIMER ( pInst, UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX ) )
        {
            UCLILSTREAM_START_TIMER ( pInst, UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX, pInst->pCfg->fdDeQueueTaskMs );
            UCLILSTREAM_START_TIMER ( pInst, UCLILSTREAM_MSG_SCHED_LOCAL_TIMER_IDX, pInst->pCfg->priorityMsgSchedulerMs );
        }
    }
    else
    {
        // Check if all DL instances are down
        for ( it = 0u; it < pInst->numIUclDL; it++ )
        {
            if ( eUclDLLinkStatus_Up == UCLILSTREAM_GET_DL_LINK_STATUS ( pInst, it ) )
            {
                break;
            }
        }

        // All DL instances are down. Stop processing.
        if ( it == pInst->numIUclDL )
        {
            UCLILSTREAM_STOP_TIMER ( pInst, UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX );
            UCLILSTREAM_STOP_TIMER ( pInst, UCLILSTREAM_MSG_SCHED_LOCAL_TIMER_IDX );
        }
    }

    switch ( Status )
    {
        case eUclDLLinkStatus_Up:
            linkStatus = UCL_E_LINK_UP;
            break;

        case eUclDLLinkStatus_Down:
            linkStatus = UCL_E_LINK_DOWN;
            break;

        default:
            linkStatus = UCL_E_NOK;
            break;
    }

    UCLILAdapter_LinkStatusChanged ( InstId, linkStatus );
}

static void *UclILStream_Impl_TimerTask ( void *pData )
{

    SUclILStreamInst *pInst = ( SUclILStreamInst * ) pData;
    uint8 it;
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclALOs_MutexTryLock ( 0, pInst->uclTimerTaskProtectMutexId );

    if ( Ret == UCL_E_OK )
    {
        // Process Local timers
        for ( it = 0; it < UCLILSTREAM_IMPL_MAX_LOCAL_TIMERS; it++ )
        {
            if ( UCLILSTREAM_IS_RUNNING_TIMER ( pInst, it ) )
            {
                UCLILSTREAM_DEC_TIMER ( pInst, it );

                if ( UCLILSTREAM_IS_ELAPSED_TIMER ( pInst, it ) )
                {
                    UCLILSTREAM_CALL_EXPIRY_FUNC ( pInst, it );
                }
            }
        }

        ( void ) UclALOs_MutexUnlock ( 0, pInst->uclTimerTaskProtectMutexId );
    }
    else
    {
        LOGW ( 0, "UclILStream", "%s", "Timer Task TryLock Failed " );
    }

    return NULL ;
}

static void UclILStream_Impl_FdDeQueueTask ( SUclILStreamInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescAttr_t fdAttr;
    SUclChnAttr_t chnAttr;
    SUclTxFdQueueElement_t readData = {0x0};
    SUclPriorityQueueElement_t addPriQMsg;
    SUclChnQueueElement_t addChnQMsg;
    SUclChnQueueElement_t chQueueElement;
    ucl_fd_t *pfidList = pInst->pCfg->ptxFdlist;
    uint16 size = ( uint16 ) pInst->pCfg->maxFds;
    uint16 index;
    uint16 i;
    uint16 txQElementSize = ( uint16 ) sizeof ( SUclTxFdQueueElement_t );
    uint16 readSize;
    uint16 msgId;
    Ucl_ReturnType chQWriteSucess;
    SUclChnCfg_t *pChnCfg = pInst->mChannelList.mpCfg;
    SUclChnQueue_t *pChnQueue;
    uint64 timeNow;

    //Get Active Tx Fd List
    Ret = UclILStream_Impl_FdGetActiveTxFds ( &pInst->mFDQueueList, pfidList, &size );

    if ( ( Ret == UCL_E_OK ) && ( size > 0u ) )
    {
        for ( index = 0u; index < size; index++ )
        {
            readSize = txQElementSize;

            //Read all the Elements in this FDQ before iterating to next FDQ
            while ( UclILStream_Impl_FdReadFromTxq ( &pInst->mFDQueueList, pfidList[index], ( uint8 * ) &readData,  &readSize ) == UCL_E_OK )
            {
                chQWriteSucess = UCL_E_INVALID_STATE;

                if ( readSize == txQElementSize )
                {
                    //Get the Channel Mapped to this FD
                    Ret = UclILStream_Impl_FdGetAttr ( &pInst->mFDQueueList, pfidList[index], &fdAttr );

                    if ( Ret == UCL_E_OK )
                    {
                        //Get the Channel Priority
                        Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, fdAttr.mChnIndex, &chnAttr );
                    }

                    if ( Ret == UCL_E_OK )
                    {
                        timeNow = UclALOs_GetSystemTimeMs ( 0u );
                        Ret = UCL_E_NOK;

                        if ( ( ( timeNow - readData.timeMs ) < chnAttr.time_to_live_ms ) || ( chnAttr.time_to_live_ms == 0u ) )
                        {
                            msgId = ( ( ( ( uint16 ) readData.chnId ) << 8u ) | readData.rId );
                            addChnQMsg.bId = readData.bId;
                            addChnQMsg.rId = readData.rId;
                            addChnQMsg.mId = msgId;
                            addChnQMsg.fId =  pfidList[index] ;
                            addChnQMsg.timeMs = readData.timeMs;
                            chQWriteSucess = UCL_E_BUSY;
                            Ret = UclILStream_Impl_ChnQueueWrite ( &pInst->mChannelList, fdAttr.mChnIndex, &addChnQMsg );

                        }
                        else
                        {
                            LOGI ( 0, "UclILStream_Impl_FdDeQueueTask", " Discard data from FDQueue " );
                        }

                    }

                    //Schedule the Message in Priority Queue
                    if ( Ret == UCL_E_OK )
                    {
                        chQWriteSucess = UCL_E_OK;
                        addPriQMsg.chnId = readData.chnId;
                        addPriQMsg.bId = readData.bId;
                        addPriQMsg.mId = msgId;

                        Ret = UclILStream_Impl_WriteMessageToPrioQueue ( pInst, 0, ( EUclILMsgPriorityLevel ) chnAttr.priority_level, ( uint8 * ) &addPriQMsg, \
                                        (uint16) sizeof( addPriQMsg ) );
                    }

                    if ( Ret != UCL_E_OK )
                    {
                        // Remove element from Channel queue if Write to Priority Queue Failed
                        if (( chQWriteSucess == UCL_E_OK )&& (fdAttr.mChnIndex < pChnCfg->maxChn))
                        {
                            pChnQueue = &pChnCfg->mpChnQueueList->mpQueueList[fdAttr.mChnIndex];

                            for ( i = 0; i < pChnQueue->chnQueuesize; i++ )
                            {
                                Ret = UclILStream_Impl_ChnQueueRead ( &pInst->mChannelList, fdAttr.mChnIndex, i, &chQueueElement );

                                if ( Ret != UCL_E_OK )
                                {
                                    LOGE ( 0, "UclILStream_Impl_FdDeQueueTask", " Read from ChQ failed ##mChnIndex %d ", fdAttr.mChnIndex );
                                }

                                if ( chQueueElement.mId == addChnQMsg.mId )
                                {
                                    Ret = UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, fdAttr.mChnIndex, i );

                                    if ( Ret != UCL_E_OK )
                                    {
                                        LOGE ( 0, "UclILStream_Impl_FdDeQueueTask", " Remove ChnElement failed ##mChnIndex %d ", fdAttr.mChnIndex );
                                    }

                                    break;
                                }
                            }
                        }

                        // Reschedule the messsage, if write to Channel queue / priority queue failed
                        if ( chQWriteSucess != UCL_E_INVALID_STATE )
                        {
                        	LOGI ( 0, "UclILStream_Impl_FdDeQueueTask", " Reschedule the Message in Priority Queue ##Buffer Id %d ##m ChnId %d ", readData.bId, readData.chnId );
                            Ret = UclILStream_Impl_FdWriteToTxq ( &pInst->mFDQueueList, pfidList[index], ( uint8 * ) &readData, txQElementSize );

                            if ( Ret != UCL_E_OK )
                            {
                                ( void ) UclBufferPool_Put ( &pInst->mBufferPool, readData.bId );
                                LOGE ( 0, "UclILStream_Impl_FdDeQueueTask", " Buffer Released ##Buffer Id %d ##m ChnId %d ", readData.bId, readData.chnId );
                            }

                            break;
                        }
                    }
                }

                readSize = txQElementSize;
            }
        }
    }

    // Reschedule timer
    UCLILSTREAM_START_TIMER ( pInst, UCLILSTREAM_SCAN_FDQ_MSG_LOCAL_TIMER_IDX, pInst->pCfg->fdDeQueueTaskMs );


}

static Ucl_ReturnType UclILStream_Impl_WriteMessageToPrioQueue ( SUclILStreamInst *pInst, uint8 DLIdx,
        EUclILMsgPriorityLevel Prio, uint8 *pData, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclILStreamDLData *pDLData;

    if (( Prio < eUclILMsgPriorityLevel_Last ) && (DLIdx < pInst->numIUclDL))
    {
        pDLData = pInst->pCfg->pDLCfg[DLIdx].pData;

        Ret = UclALOs_MutexLock ( 0, pDLData->prioQueueLocks[Prio] );

        if ( UCL_E_OK == Ret )
        {
            Ret = UclCmnRingBuffer_Write ( &pDLData->prioQueue[Prio], pData, size );
            ( void ) UclALOs_MutexUnlock ( 0, pDLData->prioQueueLocks[Prio] );

            if ( UCL_E_BUFFER_FULL == Ret )
            {
                LOGE ( 0, "UclILStream_Impl_WriteMessageToPrioQueue", "Priority Queue %d FULL", Prio );
            }
        }
    }
    else
    {
        LOGE ( 0, "UclILStream_Impl_WriteMessageToPrioQueue", " Invalid Priority level  %d", Prio );
    }

    return Ret;
}

static void UclILStream_Impl_RunMessageScheduler ( SUclILStreamInst *pInst )
{
    uint8 it;

    for ( it = 0; it < pInst->numIUclDL; it++ )
    {
        // Run priority arbitration for all DL instances
        UclILStream_Impl_RunFixedPrioScheduler ( pInst, it );
    }

    //Reschedule timer
    UCLILSTREAM_START_TIMER ( pInst, UCLILSTREAM_MSG_SCHED_LOCAL_TIMER_IDX, pInst->pCfg->priorityMsgSchedulerMs );
}

static void UclILStream_Impl_RunFixedPrioScheduler ( SUclILStreamInst *pInst, uint8 DLIdx )
{
    const SUclILStreamCfg *pCfg = pInst->pCfg;
    SUclILStreamDLCfg *pDLCfg = &pCfg->pDLCfg[DLIdx];
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ucl_ReturnType priorityQReWrite, chQStatus = UCL_E_NOK;
    SUclPriorityQueueElement_t getMessageInfo = {0x0};
    SUclChnQueueElement_t ChnQMsg;
    uint32 chnIndex = 0x0;
    SUclChnAttr_t chnAttr;
    uint16 index = 0x0;
    SUclChnQueue_t *pChnQueue;
    SUclChnCfg_t *pChnCfg = pInst->mChannelList.mpCfg;

    do
    {
        // Get the next eligible message for transmission
        Ret = UclILStream_Impl_FixedPrioSchedGetNextMessage ( pInst, DLIdx, ( uint8 * ) &getMessageInfo );

        if ( UCL_E_OK == Ret )
        {
            // Send the message
            Ret = UclILStream_Impl_TransmitMessage ( pInst, DLIdx, &getMessageInfo, pDLCfg->pTxWorkBuffer,
                            pDLCfg->txWorkBufferSize );

            if ( Ret != UCL_E_OK )
            {
                Ret = UclILStream_Impl_ChnGetIdx ( &pInst->mChannelList, getMessageInfo.chnId, &chnIndex );

                if ( Ret == UCL_E_OK )
                {
                    Ret = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, chnIndex, &chnAttr );
                }

                if ( Ret == UCL_E_OK )
                {
                    priorityQReWrite = UclILStream_Impl_WriteMessageToPrioQueue ( pInst, 0, ( EUclILMsgPriorityLevel ) chnAttr.priority_level,
                                    ( uint8 * ) &getMessageInfo, ( uint16 ) sizeof ( getMessageInfo ) );

                    if (( priorityQReWrite != UCL_E_OK )&&(chnIndex < pChnCfg->maxChn ))
                    {
                        LOGE ( 0, "UclILStream_Impl_RunFixedPrioScheduler", "Unable to ReWrite in Priority Queue %d FULL", chnAttr.priority_level );
                        ( void ) UclBufferPool_Put ( &pInst->mBufferPool, getMessageInfo.bId );
                        LOGE ( 0, "UclILStream_Impl_RunFixedPrioScheduler", " Buffer Released ##Buffer Id %d ##m ChnId %d ", getMessageInfo.bId, getMessageInfo.chnId );
                        pChnQueue = &pChnCfg->mpChnQueueList->mpQueueList[chnIndex];

                        for ( index = 0; index < pChnQueue->chnQueuesize; index++ )
                        {
                            chQStatus = UclILStream_Impl_ChnQueueRead ( &pInst->mChannelList, chnIndex, index, &ChnQMsg );

                            if ( ( ChnQMsg.mId ==  getMessageInfo.mId ) && ( chQStatus == UCL_E_OK ) )
                            {
                                ( void ) UclILStream_Impl_RemoveChnElement ( &pInst->mChannelList, chnIndex, index );
                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }
    }
    while ( UCL_E_OK == Ret ); // if DL send fails  exit and try in the next cycle

}

static Ucl_ReturnType UclILStream_Impl_FixedPrioSchedGetNextMessage ( SUclILStreamInst *pInst, uint8 DLIdx, uint8 *pMsgInfo )
{
    Ucl_ReturnType Ret;
    uint16 ReadSize;
    uint8 Prio;
    SUclILStreamDLData *pDLData;

    pDLData = pInst->pCfg->pDLCfg[DLIdx].pData;
    Prio = eUclILMsgPriorityLevel_Critical;

    do
    {
        Ret = UclALOs_MutexLock ( 0, pDLData->prioQueueLocks[Prio] );

        if ( UCL_E_OK == Ret )
        {
            ReadSize = ( uint16 ) sizeof ( SUclPriorityQueueElement_t );
            Ret = UclCmnRingBuffer_Read ( &pDLData->prioQueue[Prio], pMsgInfo, &ReadSize );

            ( void ) UclALOs_MutexUnlock ( 0, pDLData->prioQueueLocks[Prio] );

            if ( ( UCL_E_OK == Ret ) && ( ReadSize > 0u ) )
            {
                break;
            }
        }

        Prio++;
    }
    while ( eUclILMsgPriorityLevel_Last > Prio );

    return Ret;
}


static Ucl_ReturnType UclILStream_Impl_TransmitMessage ( SUclILStreamInst *pInst, uint8 DLIdx, SUclPriorityQueueElement_t *pMsgInfo,
        uint8 *pMsgBuff, uint16 Length )
{
    SUclILStreamDLCfg *pDLCfg = &pInst->pCfg->pDLCfg[DLIdx] ;
    SUclDLMsg DLMsg = {0x0};
    Ucl_ReturnType Ret = UCL_E_OK;
    Ucl_ReturnType isValidInput = UCL_E_OK;
    Ucl_ReturnType isDataOk = UCL_E_NOK;
    uint16 bufferlen = 0x0;
    SUclChnAttr_t chnAttr = {0x0};
    uint32 chnIndex;

    //Get the Payload from buffer pool
    isDataOk = UclBufferPool_Read ( &pInst->mBufferPool, pMsgInfo->bId, pMsgBuff, Length );

    if ( isDataOk > 0 )
    {
        bufferlen = ( uint16 ) isDataOk;
        //Get Channel Index
        isDataOk = UclILStream_Impl_ChnGetIdx ( &pInst->mChannelList, pMsgInfo->chnId, &chnIndex );

        if ( UCL_E_OK == isDataOk )
        {
            //Get Chn Attributes
            isDataOk = UclILStream_Impl_ChnGetAttr ( &pInst->mChannelList, chnIndex, &chnAttr );
        }
    }
    else
    {
        LOGE ( 0, "UclILStream_Impl_TransmitMessage", "Invalid Buffer : Discard the Message  %d", isDataOk );
    }

    // Link Up?
    if ( ( UCL_E_OK == isDataOk ) && ( eUclDLLinkStatus_Up == pDLCfg->pData->linkStatus ) )
    {
        // Prepare UclDL message
        DLMsg.MsgHdr = 0x0u;

        switch ( chnAttr.security_level )
        {

            case eUclILMsgSecurityLevel_Unsecure:
            	 UCLDL_MSG_SEC_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_SEC_LEVEL_0 );
            	break;
            case eUclILMsgSecurityLevel_Authenticated:
                UCLDL_MSG_SEC_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_SEC_LEVEL_1 );
                break;

            case eUclILMsgSecurityLevel_Encrypted:
                UCLDL_MSG_SEC_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_SEC_LEVEL_2 );
                break;

            default:
                isValidInput =UCL_E_NOK;
                // Remove the element from Channel queue
                LOGE ( 0, "UclILStream_Impl_TransmitMessage", "Invalid Security level : Discard the Message  %d", isValidInput );
                break;
        }

        if( isValidInput == UCL_E_OK )
        {
            switch ( chnAttr.priority_level )
            {
                case eUclILMsgPriorityLevel_Low:
                    UCLDL_MSG_PRI_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_0 );
                    break;

                case eUclILMsgPriorityLevel_Medium:
                    UCLDL_MSG_PRI_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_1 );
                    break;

                case eUclILMsgPriorityLevel_High:
                    UCLDL_MSG_PRI_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_2 );
                    break;

                case eUclILMsgPriorityLevel_Critical:
                    UCLDL_MSG_PRI_LEVEL_SET ( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_3 );
                    break;

                default:
                    isValidInput =UCL_E_NOK;
                    LOGE ( 0, "UclILStream_Impl_TransmitMessage", "Invalid Priority  level : Discard the Message  %d", isValidInput );
                    break;
            }
        }

        if(( isValidInput == UCL_E_OK) && (DLIdx < pInst->numIUclDL))
        {

            UCLDL_MSG_SET_DESTNODE_ID ( DLMsg.MsgHdr, pInst->pCfg->pDLCfg->pDestNodeIds[0] );
            UCLDL_MSG_SET_SRCNODE_ID ( DLMsg.MsgHdr, pInst->pCfg->nodeId );

            DLMsg.MsgId = pMsgInfo->mId;
            DLMsg.pPayload = pMsgBuff;
            DLMsg.Size = bufferlen;

            // Send the message
            Ret = UclDL_Send ( pInst->pIUclDL[DLIdx], &DLMsg );
        }
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclILStream_Impl_TransmitMessage", "TransmitMessage: Failed %d", Ret );
    }

    return Ret;
}

static uint8 UclILStream_Impl_GenerateRID( void )
{
    static uint8 reqId = UCL_OWNED_REQID_START;

    if ( reqId == UCL_OWNED_REQID_END )
    {
        reqId = UCL_OWNED_REQID_START;
    }
    else
    {
        reqId++;
    }

    return reqId;
}

static Ucl_ReturnType UclILStream_Impl_GetDLIndex ( SUclILStreamInst *pInst, uint8 DLInstId, uint8 *DLIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 it;

    for ( it = 0u; it < pInst->numIUclDL; it++ )
    {
        if ( DLInstId == pInst->pIUclDL[it] )
        {
            *DLIndex = it;
            Ret = UCL_E_OK;
            break;
        }
    }

    return Ret;
}

