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
///---------------------------------------------------------------------------------------------------------------------
#include "UclILSched_Impl.h"
#include "UclILAdapter.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclDL.h"

#define UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX (0u)
#define UCLILSCHED_MSG_SCHED_LOCAL_TIMER_IDX (1u)

#define UCLILSCHED_SET_MSG_STATUS(p, f, s) UclILSched_Impl_UpdateFlags((p), &((f)->pWork->flags), TRUE, ((EUclILMsgDbTxMsgStatus)s))
#define UCLILSCHED_CLR_MSG_STATUS(p, f, s) UclILSched_Impl_UpdateFlags((p), &((f)->pWork->flags), FALSE, ((EUclILMsgDbTxMsgStatus)s))
#define UCLILSCHED_CHK_MSG_STATUS(f, s) (((f)->pWork->flags) & ((EUclILMsgDbTxMsgStatus)s))

#define UCLILSCHED_SET_DL_LINK_STATUS(p, d, s) ((p)->pCfg->pDLCfg[(d)].pData->linkStatus = (s))
#define UCLILSCHED_GET_DL_LINK_STATUS(p, d) ((p)->pCfg->pDLCfg[(d)].pData->linkStatus)

#define UCLILSCHED_INIT_TIMER(p, t, cb) \
    ((p)->localTimers[(t)] = 0u);        \
    ((p)->localTimersCbk[(t)] = (cb))

#define UCLILSCHED_START_TIMER(p, t, to) ((p)->localTimers[(t)] = ((uint32)(to) / (p)->pCfg->timerTaskPeriodicityMs))
#define UCLILSCHED_STOP_TIMER(p, t) ((p)->localTimers[(t)] = 0)
#define UCLILSCHED_DEC_TIMER(p, t) ((p)->localTimers[(t)]--)
#define UCLILSCHED_IS_RUNNING_TIMER(p, t) (0u < (p)->localTimers[(t)])
#define UCLILSCHED_IS_ELAPSED_TIMER(p, t) (0u == (p)->localTimers[(t)])
#define UCLILSCHED_CALL_EXPIRY_FUNC(p, t) ((((p)->localTimersCbk[(t)]))(p))

static void *UclILSched_Impl_TimerTask ( void *pData );
static void UclILSched_Impl_ProcessTransmitPeriodicMessages ( SUclILSchedInst *pInst );
static Ucl_ReturnType UclILSched_Impl_GetDLIdxForDestNode ( SUclILSchedInst *pInst, uint16 DestNode, uint8 *pDLIdx );
static Ucl_ReturnType UclILSched_Impl_PrepareTransmitMessage ( SUclILSchedInst *pInst, const SUclILMsgDbTx *pTxMsg, uint8 *pMsgBuff,
        uint16 *pLength );
static Ucl_ReturnType UclILSched_Impl_TransmitMessage ( SUclILSchedInst *pInst, uint8 DLIdx, const SUclILMsgDbTx *pTxMsg, uint8 *pMsgBuff,
        uint16 Length );
static void UclILSched_Impl_UpdateFlags ( SUclILSchedInst *pInst, EUclILMsgDbTxMsgStatus *pFlags, uint8 bSet, EUclILMsgDbTxMsgStatus Bits );
static Ucl_ReturnType UclILSched_Impl_GetDLIndex ( SUclILSchedInst *pInst, uint8 DLInstId, uint8 *DLIndex );
static Ucl_ReturnType UclILSched_Impl_WriteMessageToPrioQueue ( SUclILSchedInst *pInst, uint8 DLIdx, EUclILMsgDbPriorityLevel Prio,
        uint16 MsgIdx );
static void UclILSched_Impl_RunMessageScheduler ( SUclILSchedInst *pInst );
static void UclILSched_Impl_RunFixedPrioScheduler ( SUclILSchedInst *pInst, uint8 DLIdx );
static Ucl_ReturnType UclILSched_Impl_FixedPrioSchedGetNextMessage ( SUclILSchedInst *pInst, uint8 DLIdx, uint16 *pMsgIdx );

Ucl_ReturnType UclILSched_Impl_IUclILSched_Initialize ( SUclILSchedInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;
    SUclILSchedDLCfg *pDLCfg;
    SUclILSchedDLData *pDLData;
    uint8 i, j;
    uint16 MsgIdx;
    const SUclILMsgDbTx *pTxMsg;
    uint8 DLIdx;

    pInst->isInitialized = FALSE;
    // Create Timer
    Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclILSched_Impl_TimerTask, ( void * ) pInst,
                    eUclOsTimerType_Periodic );

    // Create Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->msgStatusFlagsMutexId );
    }

    // Create Message Scheduler Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->msgSchedulerMutexId );
    }

    // Initialize local pooled timers
    UCLILSCHED_INIT_TIMER ( pInst, UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX,
            UclILSched_Impl_ProcessTransmitPeriodicMessages );
    UCLILSCHED_INIT_TIMER ( pInst, UCLILSCHED_MSG_SCHED_LOCAL_TIMER_IDX, UclILSched_Impl_RunMessageScheduler );

    // Initialize Data Layer Instances
    if ( Ret == UCL_E_OK )
    {
        for ( i = 0; i < pInst->numIUclDL; i++ )
        {
            // Initialize Link Status
            UCLILSCHED_SET_DL_LINK_STATUS ( pInst, i, eUclDLLinkStatus_Down );

            Ret = UclDL_Initialize ( pInst->pIUclDL[i] );

            if ( UCL_E_OK == Ret )
            {
                // Create per DL instance resources
                for ( j = 0; j < eUclILMsgDbPriorityLevel_Last; j++ )
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
	
    //Initialize  TxMsgDb Variables
    for ( MsgIdx = 0; MsgIdx < pInst->pCfg->numMsgDbTxMsgs; MsgIdx++ )
    {
        pTxMsg = & ( pInst->pCfg->pMsgDbTx[MsgIdx] );

        if ( pTxMsg->pWork != NULL )
        {
            pTxMsg->pWork->flags = eUclILMsgDbTxMsgStatus_Idle;
            pTxMsg->pWork->timeStampMs = 0;

            if ( TRUE == pTxMsg->sendOnInit)
            {
	            // Find DL Instance to route the message to
                Ret = UclILSched_Impl_GetDLIdxForDestNode ( pInst, ( uint16 ) pTxMsg->destNodeId, &DLIdx );
                if ( UCL_E_OK == Ret)
                {
                    // Add it to the appropriate priority queue
                    Ret = UclILSched_Impl_WriteMessageToPrioQueue ( pInst, DLIdx, pTxMsg->priorityLevel, MsgIdx );
                    if ( UCL_E_OK == Ret)
                    {
                        pTxMsg->pWork->flags = eUclILMsgDbTxMsgStatus_SendOnInit;
                    }
                }
            }
        }

    }

    // Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->timerTaskPeriodicityMs );
    }

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclILSched_Impl", "IUclILSched_Initialize: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclILSched_Impl", "IUclILSched_Initialize: Success %d", pInst->timerTaskId );
        pInst->isInitialized = TRUE;
    }

    return Ret;
}

Ucl_ReturnType UclILSched_Impl_IUclILSched_Shutdown ( SUclILSchedInst *pInst, uint8 InstId )
{
    SUclILSchedDLCfg *pDLCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i, j;

    pInst->isInitialized = FALSE;
	
	Ret = UclALOs_TimerStop ( 0, pInst->timerTaskId );
    
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
    }

    for ( i = 0; i < pInst->numIUclDL; i++ )
    {
        Ret = UclDL_Shutdown ( pInst->pIUclDL[i] );

        if ( UCL_E_OK == Ret )
        {
            for ( j = 0; j < eUclILMsgDbPriorityLevel_Last; j++ )
            {
                pDLCfg = &pInst->pCfg->pDLCfg[i];
                Ret = UclALOs_MutexDestroy ( 0, pDLCfg->pData->prioQueueLocks[j] );

                if ( UCL_E_OK != Ret )
                {
                    break;
                }
            }

            // Initialize Link Status
            UCLILSCHED_SET_DL_LINK_STATUS ( pInst, i, eUclDLLinkStatus_Down );
        }
        else
        {
            break;
        }
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexDestroy ( 0, pInst->msgStatusFlagsMutexId );
    }

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexDestroy ( 0, pInst->msgSchedulerMutexId );
    }


    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclILSched_Impl", "IUclILSched_Shutdown: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclILSched_Impl", "%s", "IUclILSched_Shutdown: Success" );
    }

    return Ret;
}

void UclILSched_Impl_IUclILSched_NotifyMessageUpdate ( SUclILSchedInst *pInst, uint8 InstId, uint16 MsgIdx, uint16 DuIdx, uint8 *pBuffer, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 DLIdx;
    const SUclILSchedCfg *pCfg = pInst->pCfg;
    const SUclILMsgDbTx *pTxMsg;  //potential_overrun: Index MsgIdx may be outside the bounds of pCfg->pMsgDbTx
    uint64 timeNow;
    uint8 bSend = TRUE;
    uint64 nextSchedTime  = 0;


    if ( ( TRUE == pInst->isInitialized ) && ( MsgIdx < pCfg->numMsgDbTxMsgs ) )
    {
        pTxMsg = &pCfg->pMsgDbTx[MsgIdx];

        if ( DuIdx < pTxMsg->numDataUnits )
        {
            timeNow = UclALOs_GetSystemTimeMs ( 0u );

            if ( 0u < pTxMsg->periodictyMs )
            {
                // Minimum timeout not met, defer the message
                if ( timeNow < ( pTxMsg->pWork->timeStampMs ) )
                {
                    bSend = FALSE;
					
					//Critical Section Lock
					Ret = UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId );

					if ( UCL_E_OK == Ret )
					{
						// Mark message as deferred
						UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Deferred );
						
						//Critical Section UnLock
						( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
					}
					else
					{
						LOGE ( 0, "UclILSched_Impl", "%s", "PrepareTransmitMessage: msgStatusFlagsMutex Lock Failed!!! " );
					}
                }
            }

            if ( TRUE == bSend )
            {
                // Find DL Instance to route the message to
                Ret = UclILSched_Impl_GetDLIdxForDestNode ( pInst, ( uint16 ) pTxMsg->destNodeId, &DLIdx );

				if ( UCL_E_OK == Ret )
				{
					//Critical Section Lock
					Ret = UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId );
								
					if ( UCL_E_OK == Ret )
					{
						// Add it to the appropriate priority queue
						Ret = UclILSched_Impl_WriteMessageToPrioQueue ( pInst, DLIdx, pTxMsg->priorityLevel, MsgIdx );
						
						// Is Successfully added to queue?
						if ( UCL_E_OK == Ret )
						{
							// Mark message as Ready to send
							UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_ReadyToSend );

							nextSchedTime = ( pTxMsg->pWork->timeStampMs + pTxMsg->periodictyMs );

							if ( timeNow > nextSchedTime )
							{
								nextSchedTime = ( timeNow + pTxMsg->periodictyMs );
							}

							pTxMsg->pWork->timeStampMs = nextSchedTime;
						}
						// Is Priority Queue FULL? Defer the message for delayed schedule
						else if (UCL_E_BUFFER_FULL == Ret )
						{
							UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Deferred );
							LOGE ( 0, "UclILSched_Impl", "IUclILSched_NotifyMessageUpdate: Prior Q %d FULL!!! MsgIdx %d Deferred", MsgIdx, pTxMsg->priorityLevel );
						}
						else
						{
							LOGE ( 0, "UclILSched_Impl", "IUclILSched_NotifyMessageUpdate: Priority Q %d Write Failed for MsgIdx - %d ", pTxMsg->priorityLevel, MsgIdx );
						}
						
						//Critical Section UnLock
						( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
					}
					else
					{
						LOGE ( 0, "UclILSched_Impl", "%s", "IUclILSched_NotifyMessageUpdate: msgStatusFlagsMutex Lock Failed!!! " );
					}
				}
            }
        }
        else
        {
            LOGE ( 0, "UclILSched_Impl", "IUclILSched_NotifyMessageUpdate: Invalid MsgIdx %d or DuIdx %d", MsgIdx, DuIdx );
        }
    }
    else
    {
        LOGE ( 0, "UclILSched_Impl", "IUclILSched_NotifyMessageUpdate: Invalid Invocation %d", pInst->isInitialized );
    }

    return;
}

void UclILSched_Impl_IUclDLCbk_FatalError ( SUclILSchedInst *pInst, uint8 InstId, uint8 Status )
{
}

void UclILSched_Impl_IUclDLCbk_MsgReceived ( SUclILSchedInst *pInst, uint8 InstId, EUclDLRxStatus Status, SUclDLMsg *pMsg )
{
    Ucl_ReturnType Ret;
    uint8 DLIdx;

    // Verify if the message is not for us
    if ( pInst->pCfg->nodeId != UCLDL_MSG_GET_DESTNODE_ID ( pMsg->MsgHdr ) )
    {
        // get DL index for dest. node
        Ret = UclILSched_Impl_GetDLIdxForDestNode ( pInst, UCLDL_MSG_GET_DESTNODE_ID ( pMsg->MsgHdr ), &DLIdx );

        if ( UCL_E_OK == Ret )
        {
            Ret = UclDL_Send ( pInst->pIUclDL[DLIdx], pMsg );

            if ( UCL_E_OK != Ret )
            {
                LOGE ( 0, "UclILSched_Impl", "CbkMsgReceived: Failed: %d DLIdx: %d ", Ret, DLIdx );
            }
        }
    }
}

void UclILSched_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILSchedInst *pInst, uint8 InstId, uint16 MsgId,
        EUclDLAckStatus Status )
{
    const SUclILSchedCfg *pCfg = pInst->pCfg;
    const SUclILMsgDbTx *pTxMsg = pCfg->pMsgDbTx;
    uint16 it = 0;
    sint32 ackStatus = UCL_E_MSG_NACK;
	Ucl_ReturnType Ret;

    // Verify if the message is not for us
    while ( it < pCfg->numMsgDbTxMsgs )
    {
        pTxMsg = &pCfg->pMsgDbTx[it];
	        
        if ( MsgId == pTxMsg->msgId )
		{
			//Critical Section Lock
			Ret = UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId );

			if ( UCL_E_OK == Ret )
			{
				if ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, eUclILMsgDbTxMsgStatus_WaitForAck ) )
				{
					// Clear Wait For Ack status and any error status
					UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg,
							( eUclILMsgDbTxMsgStatus_WaitForAck | eUclILMsgDbTxMsgStatus_Error ) );

					if ( eUclDLAckStatus_Ok != Status )
					{
						// Ack Error. Set for Retry
						UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Retry );
					}

					//Critical Section UnLock
					//Note: Critical Section UnLock should be done before MessageTransmitStatus Notify to avoid Dead Lock.
					( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
					
					// Generate Notification, if configured
					if ( FALSE != pTxMsg->notifyTxStatus )
					{
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
								LOGE ( 0, "UclILSched_Impl", "MsgTransmitStatus: Invalid AckStatus %d Rcvd for Msg %d DLInst: %d ", Status, MsgId, InstId );
								break;
						}

						UCLILAdapter_MessageTransmitStatus ( MsgId, ackStatus );
					}

					break;
				}
				else
				{
					//Critical Section UnLock
					( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
				}
			}
			else
			{
				LOGE ( 0, "UclILSched_Impl", "%s", "MsgTransmitStatus: msgStatusFlagsMutex Lock Failed!!! " );
			}
		}
        // Process next entry
        it++;
    }
}

void UclILSched_Impl_IUclDLCbk_LinkStatusChanged ( SUclILSchedInst *pInst, uint8 InstId, EUclDLLinkStatus Status )
{
    uint8 it;
    uint8 DLIdx;

    // Update DL status flags
    if ( UCL_E_OK == UclILSched_Impl_GetDLIndex ( pInst, InstId, &DLIdx ) )
    {
        UCLILSCHED_SET_DL_LINK_STATUS ( pInst, DLIdx, Status );
    }

    if ( eUclDLLinkStatus_Up == Status )
    {
        // Start processing if one of the DL instance is up
        if ( FALSE == UCLILSCHED_IS_RUNNING_TIMER ( pInst, UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX ) )
        {
            UCLILSCHED_START_TIMER ( pInst, UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX,
                    pInst->pCfg->periodicMsgPeriodicityMs );
            UCLILSCHED_START_TIMER ( pInst, UCLILSCHED_MSG_SCHED_LOCAL_TIMER_IDX, pInst->pCfg->schedulerPeriodicityMs );
        }
    }
    else
    {
        // Check if all DL instances are down
        for ( it = 0; it < pInst->numIUclDL; it++ )
        {
            if ( eUclDLLinkStatus_Up == UCLILSCHED_GET_DL_LINK_STATUS ( pInst, it ) )
            {
                break;
            }
        }

        // All DL instances are down. Stop processing.
        if ( it == pInst->numIUclDL )
        {
            UCLILSCHED_STOP_TIMER ( pInst, UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX );
            UCLILSCHED_STOP_TIMER ( pInst, UCLILSCHED_MSG_SCHED_LOCAL_TIMER_IDX );
        }
    }
}

static void *UclILSched_Impl_TimerTask ( void *pData )
{
    SUclILSchedInst *pInst = ( SUclILSchedInst * ) pData;
    uint8 it;
	
	// Process Local timers
	for ( it = 0; it < UCLILSCHED_IMPL_MAX_LOCAL_TIMERS; it++ )
	{
		if ( UCLILSCHED_IS_RUNNING_TIMER ( pInst, it ) )
		{
			UCLILSCHED_DEC_TIMER ( pInst, it );

			if ( UCLILSCHED_IS_ELAPSED_TIMER ( pInst, it ) )
			{
				UCLILSCHED_CALL_EXPIRY_FUNC ( pInst, it );
			}
		}
	}

    return NULL;
}

static void UclILSched_Impl_ProcessTransmitPeriodicMessages ( SUclILSchedInst *pInst )
{
    const SUclILSchedCfg *pCfg = pInst->pCfg;
    const SUclILMsgDbTx *pTxMsg;
    Ucl_ReturnType Ret;
    uint8 DLIdx = 0U;
    uint16 it;
    uint64 nextSchedTime  = 0U;
    uint64 timeNow = UclALOs_GetSystemTimeMs ( 0u );

    for ( it = 0; it < pCfg->numMsgDbTxMsgs; it++ )
    {
        // Get the message definition
        pTxMsg = &pCfg->pMsgDbTx[it];
		
		//Critical Section Lock
		Ret = UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId );

		if ( UCL_E_OK == Ret )
		{
			if ( ( eUclILMsgDbSchedAttrib_Periodic == pTxMsg->schedAttrib ) ||
				 ( ( 0u == UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, ( eUclILMsgDbTxMsgStatus_ReadyToSend | eUclILMsgDbTxMsgStatus_WaitForAck ) ) ) &&
				 ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, ( eUclILMsgDbTxMsgStatus_Deferred | eUclILMsgDbTxMsgStatus_Retry ) ) ) ) )
			{
				// Deferred messages

				// Is Timer expired?
				if ( timeNow >= ( pTxMsg->pWork->timeStampMs ) )
				{
					// Find DL Instance to route the message to
					Ret = UclILSched_Impl_GetDLIdxForDestNode ( pInst, ( uint16 ) pTxMsg->destNodeId, &DLIdx );
					
					if ( eUclDLLinkStatus_Up == UCLILSCHED_GET_DL_LINK_STATUS ( pInst, DLIdx ) )
					{
						// Add it to the appropriate priority queue
						if ( UCL_E_OK == Ret )
						{
							Ret = UclILSched_Impl_WriteMessageToPrioQueue ( pInst, DLIdx, pTxMsg->priorityLevel, it );
							if ( UCL_E_NOK == Ret )
							{
								LOGE ( 0, "UclILSched_Impl", "ProcessTransmitPeriodicMessages: Priority Q %d Write Failed for MsgIdx - %d ", pTxMsg->priorityLevel, it );
							}
							else
							{
								//Do Nothing
							}
						}

						// Is Successfully added to queue?
						if ( UCL_E_OK == Ret )
						{
							// Mark message as Ready to send
							UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_ReadyToSend );
							// Clear deferred status
							UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Deferred );

							nextSchedTime = ( pTxMsg->pWork->timeStampMs + pTxMsg->periodictyMs );

							if ( timeNow >= nextSchedTime )
							{
								nextSchedTime = ( timeNow + pTxMsg->periodictyMs );
							}

							//Update the next Schedule time
							pTxMsg->pWork->timeStampMs = nextSchedTime;
						}
					}
					else
					{
						LOGE ( 0, "UclILSched", "%s", "ProcessTransmitPeriodicMessages: LINK DOWN!!! DO NOT Schedule Periodic Message " );
					}
				}
			}
			
			//Critical Section UnLock
			( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
		}
		else
		{
			LOGE ( 0, "UclILSched_Impl", "%s", "ProcessTransmitPeriodicMessages: msgStatusFlagsMutex Lock Failed!!! " );
		}
	}

    // Reschedule timer
    UCLILSCHED_START_TIMER ( pInst, UCLILSCHED_TX_PERIOIDC_MSG_LOCAL_TIMER_IDX, pInst->pCfg->periodicMsgPeriodicityMs );
}

static void UclILSched_Impl_RunMessageScheduler ( SUclILSchedInst *pInst )
{
    uint8 it;
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclALOs_MutexTryLock ( 0, pInst->msgSchedulerMutexId );

    if ( Ret == UCL_E_OK )
    {
        for ( it = 0; it < pInst->numIUclDL; it++ )
        {
            // Run priority arbitration for all DL instances
            UclILSched_Impl_RunFixedPrioScheduler ( pInst, it );
        }

        // Reschedule timer
        UCLILSCHED_START_TIMER ( pInst, UCLILSCHED_MSG_SCHED_LOCAL_TIMER_IDX, pInst->pCfg->schedulerPeriodicityMs );
        ( void ) UclALOs_MutexUnlock ( 0, pInst->msgSchedulerMutexId );
    }
    else
    {
        LOGI ( 0, "UclILSched", "%s", "Schedule TryLock: Failed " );
    }
}

static Ucl_ReturnType UclILSched_Impl_PrepareTransmitMessage ( SUclILSchedInst *pInst, const SUclILMsgDbTx *pTxMsg,
        uint8 *pMsgBuff, uint16 *pLength )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    const SUclILMsgDbTxDataUnit *pDataUnitList;
    const SUclILMsgDbTxSignal *pSignal;
    uint16 MsgLen = 0;
    uint16 SigLen = 0;
    uint16 DuLen = 0;
    uint16 Du = 0;
    uint16 Sig = 0;
    uint8 MsgUpdated;
    EUclILAdapterDataType adapterType;
    uint16 BuffLen = *pLength;

	//Note: Critical Section Lock Not Required. Since this section is already protected	
	if ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, eUclILMsgDbTxMsgStatus_SendOnInit ) )
	{
		adapterType = eUclILAdapterDataType_SendOnInit;
	 }
	else if ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, eUclILMsgDbTxMsgStatus_Retry ) )
	{
		adapterType = eUclILAdapterDataType_Retry;
	}
	else if ( eUclILMsgDbSchedAttrib_OnChange == pTxMsg->schedAttrib )
	{
		adapterType = eUclILAdapterDataType_OnChange;
	}
	else
	{
		adapterType = eUclILAdapterDataType_Always;
	}

    // TODO: Check buffer overflow
    // Process Data Units
    for ( Du = 0; ( Du < pTxMsg->numDataUnits ) && ( MsgLen < BuffLen ); Du++ ) // potential_overrun: Index MsgLen may be outside the bounds of pMsgBuff.
    {
        if ( NULL != pTxMsg->pDataUnitList )
        {
            pDataUnitList = &pTxMsg->pDataUnitList[Du];

            // Insert Data Unit ID
            pMsgBuff[MsgLen] = ( uint8 ) ( ( pDataUnitList->dataUnitId >> 8u ) & 0x00FFu );
            pMsgBuff[MsgLen + 1u] = ( uint8 ) ( pDataUnitList->dataUnitId & 0x00FFu );
            MsgLen = MsgLen + 2u;

            MsgUpdated = FALSE;

            // Process signal entries
            if ( ( 0u < pDataUnitList->numSignals ) && ( NULL != pDataUnitList->pSignalList ) )
            {
                for ( Sig = 0; Sig < pDataUnitList->numSignals; Sig++ )
                {
                    pSignal = &pDataUnitList->pSignalList[Sig];

                    // Call the adapter to populate the data
                    if ( ( NULL != pSignal->pAdapterFunc ) && ( MsgLen < BuffLen ) ) // potential_overrun: Index MsgLen may be outside the bounds of pMsgBuff.
                    {
                        SigLen = 0;

                        if ( FALSE != ( pSignal->pAdapterFunc ) ( &pMsgBuff[MsgLen + 1u], &SigLen, adapterType ) )
                        {
                            pMsgBuff[MsgLen] = pSignal->signalId;
                            MsgLen += SigLen + 1u;
                            MsgUpdated = TRUE;
                        }

                    }
                }
            }
            else if ( ( pDataUnitList->pMsgAdapterFunc != NULL ) && ( 0u < pDataUnitList->msgSize ) && ( MsgLen < BuffLen ) ) // potential_overrun: Index MsgLen may be outside the bounds of pMsgBuff.
            {
                // Call the adapter to populate the data
                DuLen = 0;

                if ( FALSE != ( pDataUnitList->pMsgAdapterFunc ) ( &pMsgBuff[MsgLen], &DuLen, adapterType ) )
                {
                    MsgLen = MsgLen + DuLen;
                    MsgUpdated = TRUE;
                }
            }
            else
            {
                LOGE ( 0, "UclILSched", "Prepare_TransmitMessage: InValid DU Configuration for Msg %d ", pTxMsg->msgId );
                // Do nothing
            }

            // Data Unit not ready to send, roll back insertion Data Unit ID
            if ( TRUE != MsgUpdated )
            {
                MsgLen = MsgLen - 2u;
            }
        }
        else
        {
            LOGE ( 0, "UclILSched", "Prepare_TransmitMessage: No Dus for Msg %d ", pTxMsg->msgId );
            Ret = UCL_E_NOK;
            break;
        }
    }

    if ( Ret == UCL_E_OK )
    {
        *pLength = MsgLen;
    }
    else
    {
        *pLength = 0;
    }

    return Ret;
}

static Ucl_ReturnType UclILSched_Impl_TransmitMessage ( SUclILSchedInst *pInst, uint8 DLIdx, const SUclILMsgDbTx *pTxMsg,
        uint8 *pMsgBuff, uint16 Length )
{
    SUclILSchedDLCfg *pDLCfg;
    SUclDLMsg DLMsg;
    Ucl_ReturnType Ret = UCL_E_OK;

    pDLCfg = &pInst->pCfg->pDLCfg[DLIdx];

    // Link Up?
    if ( eUclDLLinkStatus_Up == pDLCfg->pData->linkStatus )
    {
        // Prepare UclDL message
        DLMsg.MsgHdr = 0x0;

        switch (pTxMsg->securityLevel)
        {
            case eUclILMsgDbSecurityLevel_Authenticated:
                UCLDL_MSG_SEC_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_SEC_LEVEL_1 );
                break;
            case eUclILMsgDbSecurityLevel_Encrypted:
                UCLDL_MSG_SEC_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_SEC_LEVEL_2 );
                break;
            default:
				//Do Nothing
                break;
        }

        switch (pTxMsg->priorityLevel)
        {
            case eUclILMsgDbPriorityLevel_Low:
                UCLDL_MSG_PRI_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_0 );
                break;
            case eUclILMsgDbPriorityLevel_Medium:
                UCLDL_MSG_PRI_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_1 );
                break;
            case eUclILMsgDbPriorityLevel_High:
                UCLDL_MSG_PRI_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_2 );
                break;
            case eUclILMsgDbPriorityLevel_Critical:
                UCLDL_MSG_PRI_LEVEL_SET( DLMsg.MsgHdr, UCLDL_MSG_PRI_LEVEL_3 );
                break;
            default:
                Ret = UCL_E_NOK;
                break;
        }

        if ( UCL_E_OK == Ret )
        {
            UCLDL_MSG_SET_DESTNODE_ID ( DLMsg.MsgHdr, pTxMsg->destNodeId );
            UCLDL_MSG_SET_SRCNODE_ID ( DLMsg.MsgHdr, pInst->pCfg->nodeId );

            DLMsg.MsgId = pTxMsg->msgId;
            DLMsg.pPayload = pMsgBuff;
            DLMsg.Size = Length;

            // Send the message
            Ret = UclDL_Send ( pInst->pIUclDL[DLIdx], &DLMsg );
        }
    }
    else
    {
        LOGE ( 0, "UclILSched_Impl", "%s", "TransmitMessage: DL Link Down" );
        Ret = UCL_E_NOK;
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclILSched_Impl", "TransmitMessage: Failed %d", Ret );
    }

    return Ret;
}

static Ucl_ReturnType UclILSched_Impl_GetDLIdxForDestNode ( SUclILSchedInst *pInst, uint16 DestNode, uint8 *pDLIdx )
{
    SUclILSchedDLCfg *pDLCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 i, j;

    for ( i = 0; i < pInst->numIUclDL; i++ )
    {
        pDLCfg = &pInst->pCfg->pDLCfg[i];

        for ( j = 0; j < pDLCfg->numDestNodes; j++ )
        {
            if ( pDLCfg->pDestNodeIds[j] == DestNode )
            {
                *pDLIdx = i;
                Ret = UCL_E_OK;
                break;
            }
        }
    }

    return Ret;
}

static Ucl_ReturnType UclILSched_Impl_GetDLIndex ( SUclILSchedInst *pInst, uint8 DLInstId, uint8 *DLIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 it;

    for ( it = 0; it < pInst->numIUclDL; it++ )
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

static void UclILSched_Impl_UpdateFlags ( SUclILSchedInst *pInst, EUclILMsgDbTxMsgStatus *pFlags, uint8 bSet, EUclILMsgDbTxMsgStatus Bits )
{
        if ( TRUE == bSet )
        {
            *pFlags |= Bits;
        }
        else
        {
            *pFlags &= ~Bits;
        }

}

static void UclILSched_Impl_RunFixedPrioScheduler ( SUclILSchedInst *pInst, uint8 DLIdx )
{
    const SUclILSchedCfg *pCfg = pInst->pCfg;
    SUclILSchedDLCfg *pDLCfg = &pCfg->pDLCfg[DLIdx];
    const SUclILMsgDbTx *pTxMsg;
    Ucl_ReturnType Ret;
    uint16 PayloadLen;
    uint16 MsgIdx = 0u;
    uint16 idx = 0;
    uint16 it = 0;
	
	if(  UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId ) == UCL_E_OK )
	{
		do
		{
			// Get the next eligible message for transmission
			Ret = UclILSched_Impl_FixedPrioSchedGetNextMessage ( pInst, DLIdx, &MsgIdx );

			if ( ( UCL_E_OK == Ret ) && ( pCfg->numMsgDbTxMsgs > MsgIdx ) )
			{
				pTxMsg = &pCfg->pMsgDbTx[MsgIdx];
				
				//Critical Section Lock

				// Message read to send or marked for retry or Send On Init and NOT waiting for ACK?
				if ( ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, ( eUclILMsgDbTxMsgStatus_ReadyToSend | eUclILMsgDbTxMsgStatus_Retry | eUclILMsgDbTxMsgStatus_SendOnInit) ) ) && ( 0u == UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, eUclILMsgDbTxMsgStatus_WaitForAck ) ) )
				{
					PayloadLen = pDLCfg->txWorkBufferSize;

					Ret = UclILSched_Impl_PrepareTransmitMessage ( pInst, pTxMsg, pDLCfg->pTxWorkBuffer, &PayloadLen );

					if ( UCL_E_OK == Ret )
					{
						if ( 0u < PayloadLen )
						{
							// Send the message
							Ret = UclILSched_Impl_TransmitMessage ( pInst, DLIdx, pTxMsg, pDLCfg->pTxWorkBuffer, PayloadLen );

							if ( UCL_E_OK == Ret )
							{
								// Clear ready to send / retry / Send On Init status flags
								UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg,
										( eUclILMsgDbTxMsgStatus_ReadyToSend | eUclILMsgDbTxMsgStatus_Retry | eUclILMsgDbTxMsgStatus_SendOnInit) );
								// Sent Successfully. Mark as wait for Ack
								UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_WaitForAck );

							}
							else
							{
								// Clear ready to send
								UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_ReadyToSend );
								// Retry in next iteration
								UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Retry );
													
								if( UCL_E_BUSY == Ret )
								{
									// Break RunFixedPrioScheduler if DL ACK queue is FULL.
									Ret = UCL_E_NOK;
									LOGE ( 0, "UclILSched_Impl", "%s", "RunFixedPrioScheduler: DL Bandwidth exhausted." );
								}
							}
						}
						else
						{
							// Clear ready to send
							UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_ReadyToSend );
							// Do Nothing. None of the signals are ready to send.
						}
					}
					else
					{
						// Clear ready to send
						UCLILSCHED_CLR_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_ReadyToSend );
						UCLILSCHED_SET_MSG_STATUS ( pInst, pTxMsg, eUclILMsgDbTxMsgStatus_Error );
					}
				}
				else if ( 0u != UCLILSCHED_CHK_MSG_STATUS ( pTxMsg, eUclILMsgDbTxMsgStatus_WaitForAck ) )
				{
					//Add the msg to the Msg In Progress List
					if ( idx < pCfg->schedMsgRetryScratchBufferSize )
					{
						pCfg->pSchedMsgRetryScratchBuffer[idx] = ( uint8 ) ( MsgIdx >> 8u );
						pCfg->pSchedMsgRetryScratchBuffer[idx + 1u] = ( uint8 ) ( MsgIdx & 0x00FFu );
						idx = idx + 2u;
					}
					else
					{
						LOGE ( 0, "UclILSched_Impl", "Invalid Sched Msg Retry Scratch Buffer Size %d", pCfg->schedMsgRetryScratchBufferSize );
					}
				}
			}
			
		} while ( UCL_E_OK == Ret );

    //Schedule the In-transit msgs for next schedule time
    while ( it < idx )
    {
        MsgIdx = ( ( uint16 ) ( ( ( uint16 ) pCfg->pSchedMsgRetryScratchBuffer[it] ) << 8u ) | ( uint16 ) ( pCfg->pSchedMsgRetryScratchBuffer[it + 1u] ) );

        if ( pCfg->numMsgDbTxMsgs > MsgIdx )
        {
            pTxMsg = &pCfg->pMsgDbTx[MsgIdx];

            // Add the msg to the appropriate priority queue
            Ret = UclILSched_Impl_WriteMessageToPrioQueue ( pInst, DLIdx, pTxMsg->priorityLevel, MsgIdx );

            if ( UCL_E_NOK == Ret )
            {
                LOGE ( 0, "UclILSched_Impl", "RunFixedPrioScheduler: Priority Queue %d Write Failed", pTxMsg->priorityLevel );
            }
        }

			it = it + 2u;
	    }
		
		//Critical Section UnLock
		if((UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId  )!= UCL_E_OK))
		{
			LOGI ( 0, "UclILSched_Impl", "%s", "RunFixedPrioScheduler: msgStatusFlagsMutex unlock Failed!!! " );
		}
	}
		
	else
	{
		LOGE ( 0, "UclILSched_Impl", "%s", "RunFixedPrioScheduler: msgStatusFlagsMutex Lock Failed!!! " );
	}
}

static Ucl_ReturnType UclILSched_Impl_WriteMessageToPrioQueue ( SUclILSchedInst *pInst, uint8 DLIdx,
        EUclILMsgDbPriorityLevel Prio, uint16 MsgIdx )
{
    Ucl_ReturnType Ret;
    SUclILSchedDLData *pDLData;
	uint16 FillCnt = 0U;
	uint16 PrioQMsgIdx = 0U;
	uint16 ReadSize;
	uint16 Index = 0U;

    pDLData = pInst->pCfg->pDLCfg[DLIdx].pData;

    Ret = UclALOs_MutexLock ( 0u, pDLData->prioQueueLocks[Prio] );
	
	//Check if MsgIdx exist in the Priority Queue
	if ( UCL_E_OK == Ret )
    {
		//Get the current Fill Cnt of the Queue
		(void) UclCmnRingBuffer_GetFillCnt ( &pDLData->prioQueue[Prio], &FillCnt );
	
		if( FillCnt > 1U )
		{
			do
			{
				ReadSize = sizeof ( uint16 );
				(void) UclCmnRingBuffer_IndexedRead ( &pDLData->prioQueue[Prio], ( uint8 * ) &PrioQMsgIdx, &ReadSize, Index );
				
				if( PrioQMsgIdx == MsgIdx )
				{ 
					Ret = UCL_E_MSG_PENDING;
				}
				else
				{
					FillCnt -= ReadSize;
					Index += ReadSize;
				}				
			}while ( ( UCL_E_OK == Ret ) && ( FillCnt > 0U ) );
			
			if( UCL_E_OK != Ret )
			{
				( void ) UclALOs_MutexUnlock ( 0u, pDLData->prioQueueLocks[Prio] );
			}
		}
	}
	
    if ( UCL_E_OK == Ret )
    {
        Ret = UclCmnRingBuffer_Write ( &pDLData->prioQueue[Prio], ( uint8 * ) &MsgIdx, ( uint16 ) sizeof ( uint16 ) );
        ( void ) UclALOs_MutexUnlock ( 0u, pDLData->prioQueueLocks[Prio] );

        if ( UCL_E_BUFFER_FULL == Ret )
        {
            LOGE ( 0u, "UclILSched_Impl", "WriteMessageToPrioQueue: Priority Queue %d (%d) FULL", Prio, MsgIdx );
        }
    }

    return Ret;
}

static Ucl_ReturnType UclILSched_Impl_FixedPrioSchedGetNextMessage ( SUclILSchedInst *pInst, uint8 DLIdx, uint16 *pMsgIdx )
{
    Ucl_ReturnType Ret;
    uint16 ReadSize;
    EUclILMsgDbPriorityLevel Prio;
    SUclILSchedDLData *pDLData;

    pDLData = pInst->pCfg->pDLCfg[DLIdx].pData;
    Prio = eUclILMsgDbPriorityLevel_Critical;

    do
    {
        Ret = UclALOs_MutexLock ( 0, pDLData->prioQueueLocks[Prio] );

        if ( UCL_E_OK == Ret )
        {
            ReadSize = sizeof ( uint16 );
            Ret = UclCmnRingBuffer_Read ( &pDLData->prioQueue[Prio], ( uint8 * ) pMsgIdx, &ReadSize );

            ( void ) UclALOs_MutexUnlock ( 0, pDLData->prioQueueLocks[Prio] );

            if ( ( UCL_E_OK == Ret ) && ( ReadSize > 0u ) )
            {
                break;
            }
        }

        Prio++;
    }
    while ( eUclILMsgDbPriorityLevel_Last > Prio );

    return Ret;
}
