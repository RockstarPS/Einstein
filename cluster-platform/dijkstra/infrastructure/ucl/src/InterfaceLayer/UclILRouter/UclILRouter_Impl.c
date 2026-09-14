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
#include "UclILRouter_Impl.h"
#include "UclILAdapter.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclSys.h"

#define UCLILROUTER_SET_MSG_STATUS(p, f, s) UclILRouter_Impl_UpdateFlags((p), &((f)->pWork->flags), TRUE, ((EUclILMsgDbRxMsgStatus)s))
#define UCLILROUTER_CLR_MSG_STATUS(p, f, s) UclILRouter_Impl_UpdateFlags((p), &((f)->pWork->flags), FALSE, ((EUclILMsgDbRxMsgStatus)s))
#define UCLILROUTER_CHK_MSG_STATUS(f, s) (((f)->pWork->flags) & ((EUclILMsgDbRxMsgStatus)s))

#define UCLILROUTER_PERIOIDC_MSG_CHK_LOCAL_TIMER_IDX (0u)

#define UCLILROUTER_INIT_TIMER(p, t, cb) \
    ((p)->localTimers[(t)] = 0u);         \
    ((p)->localTimersCbk[(t)] = (cb))
#define UCLILROUTER_START_TIMER(p, t, to) ((p)->localTimers[(t)] = ((uint32)(to) / (p)->pCfg->timerTaskPeriodicityMs))
#define UCLILROUTER_STOP_TIMER(p, t) ((p)->localTimers[(t)] = 0u)
#define UCLILROUTER_DEC_TIMER(p, t) ((p)->localTimers[(t)]--)
#define UCLILROUTER_IS_RUNNING_TIMER(p, t) (0u < (p)->localTimers[(t)])
#define UCLILROUTER_IS_ELAPSED_TIMER(p, t) (0u == (p)->localTimers[(t)])
#define UCLILROUTER_CALL_EXPIRY_FUNC(p, t) ((((p)->localTimersCbk[(t)]))(p))

static void *UclILRouter_Impl_TimerTask ( void *pData );
static void UclILRouter_Impl_ProcessPeriodicMessage ( SUclILRouterInst *pInst );
static void UclILRouter_Impl_UpdateFlags ( SUclILRouterInst *pInst, EUclILMsgDbRxMsgStatus *pFlags, uint8 bSet, EUclILMsgDbRxMsgStatus Bits );
static Ucl_ReturnType UclILRouter_Impl_ProcessReceivedMessage ( SUclILRouterInst *pInst, EUclDLRxStatus Status, SUclDLMsg *pMsg );
static Ucl_ReturnType UclILRouter_Impl_ProcessReceivedDataUnits ( SUclILRouterInst *pInst, const SUclILMsgDbRx *pRxMsg, SUclDLMsg *pMsg );

Ucl_ReturnType UclILRouter_Impl_IUclILRouter_Initialize ( SUclILRouterInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    // Create Timer
    Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclILRouter_Impl_TimerTask, ( void * ) pInst,
                    eUclOsTimerType_Periodic );

    // Create Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->msgStatusFlagsMutexId );
    }

    // Initialize local pooled timers
    UCLILROUTER_INIT_TIMER ( pInst, UCLILROUTER_PERIOIDC_MSG_CHK_LOCAL_TIMER_IDX,
            UclILRouter_Impl_ProcessPeriodicMessage );

    // Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->timerTaskPeriodicityMs );
    }

    // Start Local Timers
    UCLILROUTER_START_TIMER ( pInst, UCLILROUTER_PERIOIDC_MSG_CHK_LOCAL_TIMER_IDX,
            pInst->pCfg->periodicMsgCheckPeriodicityMs );

    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclILRouter_Impl", "IUclILRouter_Initialize: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclILRouter_Impl", "IUclILRouter_Initialize: Success %d", pInst->timerTaskId );
    }

    return Ret;
}

Ucl_ReturnType UclILRouter_Impl_IUclILRouter_Shutdown ( SUclILRouterInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;

    // Stop Local Timers
    UCLILROUTER_STOP_TIMER ( pInst, UCLILROUTER_PERIOIDC_MSG_CHK_LOCAL_TIMER_IDX );

    Ret = UclALOs_TimerStop ( 0, pInst->timerTaskId );

    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerDestroy ( 0, pInst->timerTaskId );
    }
    
    if ( Ret != UCL_E_OK )
    {
        LOGE ( 0, "UclILRouter_Impl", "IUclILRouter_Shutdown: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclILRouter_Impl", "%s", "IUclILRouter_Shutdown: Success" );
    }

    return Ret;
}

void UclILRouter_Impl_IUclDLCbk_MsgReceived ( SUclILRouterInst *pInst, uint8 InstId, EUclDLRxStatus Status,
        SUclDLMsg *pMsg )
{
    Ucl_ReturnType Ret;

    // Verify if the message is for us
    if ( pInst->pCfg->nodeId == UCLDL_MSG_GET_DESTNODE_ID ( pMsg->MsgHdr ) )
    {
        Ret = UclILRouter_Impl_ProcessReceivedMessage ( pInst, Status, pMsg );

        if ( UCL_E_OK != Ret )
        {
            LOGW ( 0, "UclILRouter_Impl", "IUclDLCbk_MsgReceived Unknown message ID received 0x%04x %d", pMsg->MsgId, pMsg->Size );
        }
    }
}

void UclILRouter_Impl_IUclDLCbk_LinkStatusChanged ( SUclILRouterInst *pInst, uint8 InstId, EUclDLLinkStatus Status )
{
    sint32 linkStatus = UCL_E_LINK_DOWN;

    // Generate Notification to Adapter
    switch ( Status )
    {
        case eUclDLLinkStatus_Down:
            linkStatus = UCL_E_LINK_DOWN;
            break;

        case eUclDLLinkStatus_Up:
            linkStatus = UCL_E_LINK_UP;
            break;

        default:
            //Do Nothing
            break;
    }

    UCLILAdapter_LinkStatusChanged ( InstId, linkStatus );
}

void UclILRouter_Impl_IUclDLCbk_FatalError ( SUclILRouterInst *pInst, uint8 InstId, uint8 Status )
{
    sint32 errStatus = UCL_E_FATAL;

    // Generate Notification to Adapter
    switch ( Status )
    {
        case eUclDLError_FatalError:
            errStatus = UCL_E_FATAL;
            break;

        case eUclDLError_SecurityTSCError:
            errStatus = UCL_E_SEC_TSC;
            break;

        case eUclDLError_SecurityCMACError:
            errStatus = UCL_E_SEC_CMAC;
            break;

        case eUclDLError_SecurityNegoError:
            errStatus = UCL_E_SEC_NEGO;
            break;

        default:
            //Do Nothing
            break;
    }

    UCLILAdapter_ErrorNotification ( InstId, errStatus );

    if ( errStatus == UCL_E_FATAL )
    {
        LOGE ( 0, "UclILRouter_Impl", "%s", "IUclDLCbk_FatalError: UCL is Shuting Down. Restart UCL for Communication to Resume." );
        ( void ) UclSys_Shutdown ( InstId );
    }
}

void UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus ( SUclILRouterInst *pInst, uint8 InstId, uint16 MsgId,
        EUclDLAckStatus Status )
{
    // Unhandled
}

static void *UclILRouter_Impl_TimerTask ( void *pData )
{
    SUclILRouterInst *pInst = ( SUclILRouterInst * ) pData;
    uint8 it;
   
   // Process Local timers
	for ( it = 0; it < UCLILROUTER_IMPL_MAX_LOCAL_TIMERS; it++ )
	{
		if ( UCLILROUTER_IS_RUNNING_TIMER ( pInst, it ) )
		{
			UCLILROUTER_DEC_TIMER ( pInst, it );

			if ( UCLILROUTER_IS_ELAPSED_TIMER ( pInst, it ) )
			{
				UCLILROUTER_CALL_EXPIRY_FUNC ( pInst, it );
			}
		}
	}

    return NULL;
}

static Ucl_ReturnType UclILRouter_Impl_ProcessReceivedMessage ( SUclILRouterInst *pInst, EUclDLRxStatus Status,
        SUclDLMsg *pMsg )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    const SUclILMsgDbRx *pRxMsg = NULL;
    const SUclILMsgDbRx *pRxDB = NULL;
    uint16 it;

    pRxDB = pInst->pCfg->pMsgDbRx;

    // Find the matching message entry
    for ( it = 0; it < pInst->pCfg->numMsgDbRxMsgs; it++ )
    {
        pRxMsg = &pRxDB[it];

        if ( pRxMsg->msgId == pMsg->MsgId )
        {
            Ret = UCL_E_OK;
            break;
        }
    }

    if ( ( eUclDLRxStatus_Ok == Status ) && ( UCL_E_OK == Ret ) )
    {
        // Update status flags
        UCLILROUTER_CLR_MSG_STATUS ( pInst, pRxMsg, ( eUclILMsgDbRxMsgStatus_Missing | eUclILMsgDbRxMsgStatus_Error ) );
        UCLILROUTER_SET_MSG_STATUS ( pInst, pRxMsg, eUclILMsgDbRxMsgStatus_Recvd );

        // Update Last Received time
        pRxMsg->pWork->timeStampMs = UclALOs_GetSystemTimeMs ( 0u );

        // Process Data Units
        if ( UCL_E_NOK == UclILRouter_Impl_ProcessReceivedDataUnits ( pInst, pRxMsg, pMsg ) )
        {
            LOGE ( 0, "UclILRouter_Impl", "Processing Failure for Msg 0x%02x", pMsg->MsgId );
        }
    }
    else
    {
        if (NULL != pRxMsg)
        {
            UCLILROUTER_SET_MSG_STATUS ( pInst, pRxMsg, eUclILMsgDbRxMsgStatus_Error );
        }

    }
    // Restart local timer
    UCLILROUTER_START_TIMER ( pInst, UCLILROUTER_PERIOIDC_MSG_CHK_LOCAL_TIMER_IDX,
            pInst->pCfg->periodicMsgCheckPeriodicityMs );

    return Ret;
}

static Ucl_ReturnType UclILRouter_Impl_ProcessReceivedDataUnits ( SUclILRouterInst *pInst, const SUclILMsgDbRx *pRxMsg, SUclDLMsg *pMsg )
{
    const SUclILMsgDbRxDataUnit *pDataUnitList;
    const SUclILMsgDbRxSignal *pSignal;
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 Du = 0;
    uint16 Sig = 0;
    uint16 DataUnitId;
    uint16 MsgLen = 0;

    if ( NULL != pRxMsg->pDataUnitList )
    {
        for ( Du = 0u; ( ( Du < pRxMsg->numDataUnits ) && ( MsgLen < pMsg->Size ) ); Du++ ) //potential_overrun: Index MsgLen may be outside the bounds of pMsg->pPayload
        {
            pDataUnitList = &pRxMsg->pDataUnitList[Du];

            DataUnitId = ( ( uint16 ) ( pMsg->pPayload[MsgLen] ) << 8 ) | pMsg->pPayload[MsgLen + 1u];

            if ( DataUnitId == pDataUnitList->dataUnitId )
            {
                // Found Matching Data Unit
                MsgLen = MsgLen + 2u;

                // Process Signal Entries
                if ( ( 0u < pDataUnitList->numSignals ) && ( NULL != pDataUnitList->pSignalList ) && ( MsgLen < pMsg->Size ) )
                {
                    for ( Sig = 0; Sig < pDataUnitList->numSignals; Sig++ )
                    {
                        pSignal = &pDataUnitList->pSignalList[Sig];

                        if ( pSignal->signalId == pMsg->pPayload[MsgLen] )
                        {
                            if ( NULL != pSignal->pAdapterFunc )
                            {
                                if ( TRUE != ( ( pSignal->pAdapterFunc ) ( &pMsg->pPayload[MsgLen + 1u], pSignal->size ) ) )
                                {
                                    LOGE ( 0, "UclILRouter_Impl", "Adapter failure for 0x%02x 0x%04x", pMsg->MsgId, pDataUnitList->dataUnitId );
                                }
                            }

                            MsgLen = MsgLen + pSignal->size + 1u;
                        }
                    }
                }
                // Process Message
                else if ( ( NULL != pDataUnitList->pMsgAdapterFunc ) && ( MsgLen < pMsg->Size ) )
                {
                    if ( TRUE != ( ( pDataUnitList->pMsgAdapterFunc ) ( &pMsg->pPayload[MsgLen], pDataUnitList->msgSize ) ) )
                    {
                        ( void ) UCLILAdapter_ErrorNotification ( 0, UCL_E_DATA_LOSS );
                        LOGE ( 0, "UclILRouter_Impl", "Adapter failure for 0x%02x", pMsg->MsgId );
                    }

                    MsgLen = MsgLen + pDataUnitList->msgSize;
                }
                else
                {
                    LOGE ( 0, "UclILRouter_Impl", "Check Message Configuration 0x%02x", pMsg->MsgId );
                }
            }
        }
    }

    return Ret;
}

static void UclILRouter_Impl_ProcessPeriodicMessage ( SUclILRouterInst *pInst )
{
    const SUclILRouterCfg *pCfg = pInst->pCfg;
    const SUclILMsgDbRx *pRxMsg;
    uint16 it;
    uint64 timeNow = UclALOs_GetSystemTimeMs ( 0u );
    uint64 lastSentTimeMs;

    for ( it = 0; it < pCfg->numMsgDbRxMsgs; it++ )
    {
        // Get the message definition
        pRxMsg = &pCfg->pMsgDbRx[it];

        // Check periodicity if it has non-zero value
        if ( 0u != pRxMsg->periodictyMs )
        {
            // Check if we are missing the message
            lastSentTimeMs = pRxMsg->pWork->timeStampMs;

            if ( timeNow > ( lastSentTimeMs + pRxMsg->periodictyMs ) )
            {
                // Update status flags
                UCLILROUTER_CLR_MSG_STATUS ( pInst, pRxMsg, eUclILMsgDbRxMsgStatus_Recvd );
                UCLILROUTER_SET_MSG_STATUS ( pInst, pRxMsg, eUclILMsgDbRxMsgStatus_Missing );

                // Notify Adapter
                if ( TRUE == pRxMsg->notifyRxMissingStatus )
                {
                    UCLILAdapter_ReceiveMissingStatus ( pRxMsg->msgId, UCL_E_MSG_MISSING );
                }
            }
        }
    }
}

static void UclILRouter_Impl_UpdateFlags ( SUclILRouterInst *pInst, EUclILMsgDbRxMsgStatus *pFlags, uint8 bSet, EUclILMsgDbRxMsgStatus Bits )
{
    Ucl_ReturnType Ret;

    Ret = UclALOs_MutexLock ( 0, pInst->msgStatusFlagsMutexId );

    if ( UCL_E_OK == Ret )
    {
        if ( TRUE == bSet )
        {
            *pFlags |= Bits;
        }
        else
        {
            *pFlags &= ~Bits;
        }

        ( void ) UclALOs_MutexUnlock ( 0, pInst->msgStatusFlagsMutexId );
    }
}
