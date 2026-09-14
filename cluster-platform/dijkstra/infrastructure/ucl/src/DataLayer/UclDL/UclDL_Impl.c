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
#include "UclDL_Impl.h"
#include "UclALOs.h"
#include "UclALDebug.h"
#include "UclALPhy.h"
#include "UclALPhyCbk.h"
#include "UclALCrypto.h"
#include "UclDLCbk.h"
#include "UclCrc.h"

#define UCLDL_MSG_TYPE_GET(Hdr) ((Hdr) & 0x0003u)
#define UCLDL_MSG_TYPE_NORMAL (0u)
#define UCLDL_MSG_TYPE_P2P (1u)
#define UCLDL_MSG_TYPE_N2N (2u)

#define UCLDL_P2PMSG_TYPE_SET(Hdr, Type) ((Hdr) = ((Hdr) | ((uint16)(Type) << 2) | UCLDL_MSG_TYPE_P2P))
#define UCLDL_P2PMSG_TYPE_GET(Hdr) (((Hdr) >> 2) & 0x07u)
#define UCLDL_P2P_MSG_TYPE_HEARTBEAT (0u)
#define UCLDL_P2P_MSG_TYPE_SECURITY (1u)
#define UCLDL_P2P_MSG_SECURITY_RS1 (0u)
#define UCLDL_P2P_MSG_SECURITY_RS2 (1u)
#define UCLDL_P2P_MSG_SECURITY_KVV_REQ (2u)
#define UCLDL_P2P_MSG_SECURITY_KVV_RES (3u)

#define UCLDL_N2NMSG_TYPE_SET(Hdr, Type) ((Hdr) = ((Hdr) | ((uint16)(Type) << 2) | UCLDL_MSG_TYPE_N2N))
#define UCLDL_N2NMSG_TYPE_GET(Hdr) (((Hdr) >> 2) & 0x07u)
#define UCLDL_N2N_MSG_TYPE_ACK (0u)

#define UCLDL_MSG_HEADER_SIZE (2u)
#define UCLDL_MSG_MSGID_SIZE (2u)
#define UCLDL_MSG_TSC_SIZE (2u)
#define UCLDL_MSG_CHKSUM_SIZE (2u)
#define UCLDL_MSG_CMAC_SIZE (4u)
#define UCLDL_MSG_DELIM_SIZE (1u)
#define UCLDL_MSG_SEED_SIZE (8u)
#define UCLDL_MSG_MIN_SIZE (UCLDL_MSG_HEADER_SIZE + UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_CHKSUM_SIZE)
#define UCLDL_SEC_MSG_MIN_SIZE (UCLDL_MSG_HEADER_SIZE + UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_CMAC_SIZE + UCLDL_MSG_TSC_SIZE)

#define UCLDL_FRAME_DELIM (0u)

#define UCLDL_DEFAULT_PHY_INST_ID (0u)

#define UCLDL_TX_CRY_INST_ID (0u)
#define UCLDL_RX_CRY_INST_ID (1u)
#define UCLDL_MAX_CRY_INST_ID (2u)

#define UCLDL_ACK_SUCCESS (0x5Au)
#define UCLDL_ACK_ERROR (0x5Bu)
#define UCLDL_ACK_SIZE (1u)

#define UCLDL_RX_PROCESS_SCHEDULED (0u)
#define UCLDL_RX_PROCESS_ONDEMAND (1u)

#define UCLDL_HB_PATTERN (0xA5A5u)

#define UCLDL_KVV_RESP_SIZE (2u)
#define UCLDL_KVV_RESP_OK (0xA5A5u)
#define UCLDL_KVV_RESP_FAIL (0x0000u)

#define UCLDL_HB_LOCAL_TIMER_IDX (0u)
#define UCLDL_LD_LOCAL_TIMER_IDX (1u)
#define UCLDL_BPS_LOCAL_TIMER_IDX (2u)
#define UCLDL_SEC_LOCAL_TIMER_IDX (3u)

#define UCLDL_1000MS (1000u)

#define UCLDL_PHY_RECOVERY_INFINITE (255u)

#define UCLDL_INIT_TIMER(p, t, cb) \
    ((p)->localTimers[(t)] = 0u);  \
    ((p)->localTimersCbk[(t)] = (cb))

#define UCLDL_START_TIMER(p, t, to) ((p)->localTimers[(t)] = ((uint32)(to) / (p)->pCfg->timerTaskPeriodicityMs))
#define UCLDL_STOP_TIMER(p, t) ((p)->localTimers[(t)] = 0u)
#define UCLDL_DEC_TIMER(p, t) ((p)->localTimers[(t)]--)
#define UCLDL_IS_RUNNING_TIMER(p, t) (0u < (p)->localTimers[(t)])
#define UCLDL_IS_ELAPSED_TIMER(p, t) (0u == (p)->localTimers[(t)])
#define UCLDL_CALL_EXPIRY_FUNC(p, t) ((((p)->localTimersCbk[(t)]))(p))

static void UclDL_Impl_LinkDownTimerExpired ( SUclDLInst *pInst );
static void UclDL_Impl_HeartBeatTimerExpired ( SUclDLInst *pInst );
static void UclDL_Impl_BpsTimerExpired ( SUclDLInst *pInst );
static void UclDL_Impl_SecurityTimerExpired ( SUclDLInst *pInst );
static void *UclDL_Impl_TimerTask ( void *pData );
static void UclDL_Impl_ProcessReceive ( SUclDLInst *pInst );
static void UclDL_Impl_ProcessAck ( SUclDLInst *pInst, uint16 MsgId, uint8 AckStatus );
static void UclDL_Impl_ProcessAckTimer ( SUclDLInst *pInst );
static uint16 UclDL_Impl_GetCRC ( const uint8 *pData, uint16 Size );
static uint16 UclDL_Impl_CobsEncode ( uint8 *d, uint16 dsize, const uint8 *s, uint16 ssize );
static uint16 UclDL_Impl_CobsDecode ( uint8 *d, uint16 dsize, const uint8 *s, uint16 ssize );
static Ucl_ReturnType UclDL_Impl_GetFreeSlot ( SUclDLInst *pInst, uint16 MsgId, uint8 *pSlotId );
static Ucl_ReturnType UclDL_Impl_ReInitPhy ( SUclDLInst *pInst );
static Ucl_ReturnType UclDL_Impl_GetCMAC ( SUclDLInst *pInst, uint8 CryInst, EUclALCryptoKeyType KeyType, uint8 *pData, uint16 DataSize,
        uint8 *pResult, uint16 ResultSize );
static Ucl_ReturnType UclDL_Impl_Encrypt ( SUclDLInst *pInst, uint8 CryInst, uint8 *pIV, uint8 *pData, uint16 Size );
static Ucl_ReturnType UclDL_Impl_Decrypt ( SUclDLInst *pInst, uint8 CryInst, uint8 *pIV, uint8 *pData, uint16 Size );
static void UclDL_Impl_SendAck ( SUclDLInst *pInst, uint16 MsgId,  uint16 DestNode, uint8 AckStatus );
static Ucl_ReturnType UclDL_Impl_SendHeartBeat ( SUclDLInst *pInst );
static Ucl_ReturnType UclDL_Impl_SendN2NMessage ( SUclDLInst *pInst, uint8 N2NMsgType, uint16 MsgId, uint16 DestNode,
        uint8 *pPayload, uint16 Size );
static Ucl_ReturnType UclDL_Impl_SendP2PMessage ( SUclDLInst *pInst, uint8 P2PMsgType, uint16 MsgId, uint8 *pPayload, uint16 Size );
static Ucl_ReturnType UclDL_Impl_SendMessage ( SUclDLInst *pInst, uint8 phyInstId, uint8 *pData, uint16 Size );
static void UclDL_Impl_SecurityStartKeyNegotiation ( SUclDLInst *pInst );
static Ucl_ReturnType UclDL_Impl_SecurityGenerateSessionKey ( SUclDLInst *pInst );
static void UclDL_Impl_SecurityRecvSeed ( SUclDLInst *pInst, uint16 SeedType, uint8 *pData, uint16 Size );
static Ucl_ReturnType UclDL_Impl_SecuritySendSeed ( SUclDLInst *pInst, uint16 SecMsgId, uint8 *pSeedBuffer, uint16 Size );
static void UclDL_Impl_SecurityRecvKVVRequest ( SUclDLInst *pInst, uint8 *pData, uint16 Size );
static Ucl_ReturnType UclDL_Impl_SecuritySendKVVRequest ( SUclDLInst *pInst );
static Ucl_ReturnType UclDL_Impl_SecurityValidateKVVRequest ( SUclDLInst *pInst, uint8 *pData, uint16 Size );
static void UclDL_Impl_SecurityRecvKVVResponse ( SUclDLInst *pInst, uint8 *pData, uint16 Size );
static Ucl_ReturnType UclDL_Impl_SecuritySendKVVResponse ( SUclDLInst *pInst, uint16 Response );
static Ucl_ReturnType UclDL_Impl_SecurityValidateKVVResponse ( SUclDLInst *pInst, uint8 *pData, uint16 Size );
static void UclDL_Impl_NofityErrorCallback ( SUclDLInst *pInst, EUclDLError Status );
static void UclDL_Impl_NofityMsgReceived ( SUclDLInst *pInst, EUclDLRxStatus Status, SUclDLMsg *pMsg );
static void UclDL_Impl_NotifyMsgTransmitStatus ( SUclDLInst *pInst, uint16 MsgId, EUclDLAckStatus Status );
static void UclDL_Impl_NofityLinkStatusChanged ( SUclDLInst *pInst, EUclDLLinkStatus Status );
static Ucl_ReturnType UclDL_Impl_SecurityValidateTSC ( SUclDLInst *pInst, uint16 RxTSC );

Ucl_ReturnType UclDL_Impl_IUclDL_Initialize ( SUclDLInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret;
    uint8 it;
    pInst->instId = InstId;

    //Set state as initializing
    pInst->state = eUclDLState_Initializing;
    pInst->linkStatus = eUclDLLinkStatus_Down;
    pInst->authState = eUclDLAuthState_UnAuthenticated;
    pInst->tscCounter = 0u;

    //Initialize the ACK Queue
    for ( it = 0; it < pInst->pCfg->maxTxAckQueueSize; it++ )
    {
        pInst->pCfg->pAckQueue[it].isFree = TRUE;
    }

    //Calculate the encoding overhead based on MaxMsgLength
    pInst->txCobsOverheadBytes = ( uint8 ) ( ( pInst->pCfg->maxTxMsgLength / ( uint16 ) 254u ) + ( uint16 ) 1u );
    pInst->rxCobsOverheadBytes = ( uint8 ) ( ( pInst->pCfg->maxRxMsgLength / ( uint16 ) 254u ) + ( uint16 ) 1u );

    //Initialize TimerTask
    Ret = UclALOs_TimerCreate ( 0, &pInst->timerTaskId, UclDL_Impl_TimerTask, ( void * ) pInst, eUclOsTimerType_Periodic );

    //Initialize local timers
    UCLDL_INIT_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX, UclDL_Impl_HeartBeatTimerExpired );
    UCLDL_INIT_TIMER ( pInst, UCLDL_LD_LOCAL_TIMER_IDX, UclDL_Impl_LinkDownTimerExpired );
    UCLDL_INIT_TIMER ( pInst, UCLDL_BPS_LOCAL_TIMER_IDX, UclDL_Impl_BpsTimerExpired );
    UCLDL_INIT_TIMER ( pInst, UCLDL_SEC_LOCAL_TIMER_IDX, UclDL_Impl_SecurityTimerExpired );

    //Start TimerTask
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_TimerStart ( 0, pInst->timerTaskId, pInst->pCfg->timerTaskPeriodicityMs );
    }

    //Initialize crypto. Need two crypto instances for Tx and Rx paths
    if ( ( Ret == UCL_E_OK ) && ( 0u < pInst->numIUclALCrypto ) )
    {
        if ( UCLDL_MAX_CRY_INST_ID == pInst->numIUclALCrypto )
        {
            for ( it = 0u; it < pInst->numIUclALCrypto; it++ )
            {
                Ret = UclALCrypto_Initialize ( pInst->pIUclALCrypto[it] );
            }
        }
        else
        {
            LOGE ( 0, "UclDL_Impl", "Require two crypto instances %d", Ret );
            Ret = UCL_E_NOK;
        }
    }

    // Create DL send Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->sendMutexId );
    }

    // Create Ack_Q Protect Mutex
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALOs_MutexCreate ( 0, &pInst->ackQueueProtectMutexId );
    }

    //Initialize physical transport
    if ( Ret == UCL_E_OK )
    {
        Ret = UclALPhy_Initialize ( pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID] );
    }

    //Move state to shutdown in initialize failed
    if ( Ret == UCL_E_NOK )
    {
        pInst->state = eUclDLState_Shutdown;

        LOGE ( 0, "UclDL_Impl", "UclDL_Initialize: Inst %d Failed %ld", pInst->instId, Ret );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "UclDL_Initialize:Inst %d Success %d", pInst->instId, pInst->timerTaskId );
    }

    return Ret;
}

Ucl_ReturnType UclDL_Impl_IUclDL_Shutdown ( SUclDLInst *pInst, uint8 InstId )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint8 it = 0;

    if ( eUclDLState_Shutdown != pInst->state )
    {
        pInst->state = eUclDLState_Shutdown;

        ( void ) UclALOs_TimerStop ( 0, pInst->timerTaskId );
        //Note: Don't destroy DL Timer inorder to successfully self destroy UCL process on UCL Fatal Error.

        for ( it = 0; it < pInst->numIUclALCrypto; it++ )
        {
            ( void ) UclALCrypto_Shutdown ( pInst->pIUclALCrypto[it] );
        }

        pInst->authState = eUclDLAuthState_UnAuthenticated;
        pInst->tscCounter = 0u;

        Ret = UclALPhy_Shutdown ( pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID] );

        ( void ) UclALOs_MutexDestroy ( 0, pInst->sendMutexId );
        ( void ) UclALOs_MutexDestroy ( 0, pInst->ackQueueProtectMutexId );

    }

    LOGI ( 0, "UclDL_Impl", "UclDL_Shutdown:InstId %d Status %d", InstId, Ret );

    return Ret;
}

Ucl_ReturnType UclDL_Impl_IUclDL_Send ( SUclDLInst *pInst, uint8 InstId, SUclDLMsg *pMsg )
{
    Ucl_ReturnType Ret;
    const SUclDLCfg *pCfg = pInst->pCfg;
    uint8 *pTxWorkBuffer = NULL;
    uint8 TxSlot = 0U;
    uint16 txWorkBufferSize = 0U;
    uint16 EncLen;
    uint16 MsgSize = 0U;
    uint16 MsgStartIdx = 0U;
    uint16 ChkSum;
    uint16 it;
    uint8 IsSrc = FALSE;

    // TODO: Check if frame size is legal
    // Validate Inputs
    if ( ( NULL == pMsg ) || ( NULL == pMsg->pPayload ) || ( 0u == pMsg->Size ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    // Validate state. For secure messages, check if we are authenticated
    else if ( ( eUclDLState_Active != pInst->state ) ||
              ( ( UCLDL_MSG_SEC_LEVEL_0 < UCLDL_MSG_SEC_LEVEL_GET ( pMsg->MsgHdr ) ) && ( TRUE == pCfg->enableSecurity ) && ( eUclDLAuthState_Authenticated != pInst->authState ) ) )
    {
        Ret = UCL_E_INVALID_STATE;
    }
    else if ( UCLDL_MSG_SEC_LEVEL_RSVD == UCLDL_MSG_SEC_LEVEL_GET ( pMsg->MsgHdr ) )
    {
        Ret = UCL_E_INVALID_ARGS;
    }
    else
    {
        Ret = UCL_E_OK;
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALOs_MutexLock ( 0, pInst->sendMutexId );
    }

    if ( UCL_E_OK == Ret )
    {
        //Add only messages originating from this node to ack queue
        if ( pCfg->nodeId == UCLDL_MSG_GET_SRCNODE_ID ( pMsg->MsgHdr ) )
        {
            Ret = UclDL_Impl_GetFreeSlot ( pInst, pMsg->MsgId, &TxSlot );
            IsSrc = TRUE;
        }

        if ( UCL_E_OK == Ret )
        {
            MsgSize = 0;

            // Leave space for SoF Delimiter and COBS Overhead
            MsgStartIdx = UCLDL_MSG_DELIM_SIZE + ( uint16 ) pInst->txCobsOverheadBytes;

            pTxWorkBuffer = pCfg->pTxWorkBuffer;
            txWorkBufferSize = pCfg->txWorkBufferSize;

            if ( txWorkBufferSize > ( ( 2u * UCLDL_MSG_DELIM_SIZE ) + UCLDL_SEC_MSG_MIN_SIZE + pMsg->Size + pInst->txCobsOverheadBytes ) ) // Potential Overrun
            {
                // Prepare the message
                pTxWorkBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( pMsg->MsgHdr >> 8u );
                pTxWorkBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( pMsg->MsgHdr & 0x00FFu );
                MsgSize += UCLDL_MSG_HEADER_SIZE;

                pTxWorkBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( pMsg->MsgId >> 8u );
                pTxWorkBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( pMsg->MsgId & 0x00FFu );
                MsgSize += UCLDL_MSG_MSGID_SIZE;

                if ( TRUE == pCfg->enableTSC )
                {
                    pTxWorkBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( pInst->tscCounter >> 8u );
                    pTxWorkBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( pInst->tscCounter & 0x00FFu );
                    MsgSize += UCLDL_MSG_TSC_SIZE;
                }

                // Copy the Payload
                ( void ) UclALOs_Memcpy ( 0, &pTxWorkBuffer[MsgStartIdx + MsgSize], pMsg->pPayload, pMsg->Size );
                MsgSize += pMsg->Size;

                if ( UCLDL_MSG_SEC_LEVEL_0 == UCLDL_MSG_SEC_LEVEL_GET ( pMsg->MsgHdr ) )
                {
                    // Compute Checksum for MsgId + Payload
                    ChkSum = UclDL_Impl_GetCRC ( &pTxWorkBuffer[MsgStartIdx], MsgSize );

                    // Append to the message
                    pTxWorkBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( ChkSum >> 8u );
                    pTxWorkBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( ChkSum & 0x00FFu );
                    MsgSize += UCLDL_MSG_CHKSUM_SIZE;
                }
                else
                {
                    // Compute CMAC
                    Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_TX_CRY_INST_ID, eUclALCryptoKeyType_SK,
                                               &pTxWorkBuffer[MsgStartIdx],
                                               MsgSize, &pTxWorkBuffer[MsgStartIdx + MsgSize],
                                               UCLDL_MSG_CMAC_SIZE );

                    if ( UCL_E_OK == Ret )
                    {
                        if ( UCLDL_MSG_SEC_LEVEL_2 == UCLDL_MSG_SEC_LEVEL_GET ( pMsg->MsgHdr ) )
                        {
                            // Prepare Initialization Vector
                            for ( it = 0; it < UCLDL_MSG_CMAC_SIZE; it++ )
                            {
                                ( void ) UclALOs_Memcpy ( 0, &pCfg->pTransmitIVBuffer[it * UCLDL_MSG_CMAC_SIZE],
                                                          &pTxWorkBuffer[MsgStartIdx + MsgSize],
                                                          UCLDL_MSG_CMAC_SIZE );
                            }

                            // Encrypt Payload
                            Ret = UclDL_Impl_Encrypt ( pInst, UCLDL_TX_CRY_INST_ID, pCfg->pTransmitIVBuffer,
                                                       &pTxWorkBuffer[MsgStartIdx + ( UCLDL_MSG_HEADER_SIZE + UCLDL_MSG_MSGID_SIZE )],
                                                       ( MsgSize - ( UCLDL_MSG_HEADER_SIZE + UCLDL_MSG_MSGID_SIZE ) ) );
                        }

                        MsgSize += UCLDL_MSG_CMAC_SIZE;
                    }
                }
            }
            else
            {
                LOGE ( 0, "UclDL_Impl", " Invalid I/P Buffer Configuration %d %d", txWorkBufferSize, pMsg->Size );
                Ret = UCL_E_NOK;
            }
        }

        // Encode the message
        if ( UCL_E_OK == Ret )
        {
            EncLen = UclDL_Impl_CobsEncode ( &pTxWorkBuffer[UCLDL_MSG_DELIM_SIZE],
                                             ( txWorkBufferSize - ( 2u * UCLDL_MSG_DELIM_SIZE ) ), &pTxWorkBuffer[MsgStartIdx], MsgSize );

            if ( 0u < EncLen )
            {
                pTxWorkBuffer[0] = UCLDL_FRAME_DELIM;
                pTxWorkBuffer[EncLen + 1u] = UCLDL_FRAME_DELIM;

                // Add SoF and EoF
                MsgSize = EncLen + ( 2u * UCLDL_MSG_DELIM_SIZE );
            }
            else
            {
                Ret = UCL_E_NOK;
            }
        }

        // Send it over the wire
        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_MutexLock ( 0, pInst->ackQueueProtectMutexId );

            if ( UCL_E_OK == Ret )
            {
                Ret = UclDL_Impl_SendMessage ( pInst, pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID], pTxWorkBuffer, MsgSize );

                // Add to ACK queue
                if ( UCL_E_OK == Ret )
                {
                    // Add to ACK queue only if the Msg originate from this Node
                    if ( IsSrc == TRUE )
                    {
                        pInst->pCfg->pAckQueue[TxSlot].timestamp = UclALOs_GetSystemTimeMs ( 0 );
                        pInst->pCfg->pAckQueue[TxSlot].msgId = pMsg->MsgId;
                        pInst->pCfg->pAckQueue[TxSlot].isFree = FALSE;
                    }
                }
                else
                {
                    pInst->stats.txSendFail++;
                    LOGE ( 0, "UclDL_Impl", "UclDL_Send: Failed %d", Ret );
                }
            }

            ( void ) UclALOs_MutexUnlock ( 0, pInst->ackQueueProtectMutexId );
        }

        ( void ) UclALOs_MutexUnlock ( 0, pInst->sendMutexId );
    }

    return Ret;
}

void UclDL_Impl_IUclALPhyCbk_FatalError ( SUclDLInst *pInst, uint8 InstId, uint8 status )
{
    LOGE ( 0, "UclDL_Impl", "UclALPhyCbk_FatalError: %d", status );

    // Attempt recovery
    pInst->state = eUclDLState_Recovery;
}

void UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable ( SUclDLInst *pInst, uint8 InstId )
{

    if ( UCLDL_RX_PROCESS_ONDEMAND == pInst->pCfg->receiveProcessingMode )
    {
        UclDL_Impl_ProcessReceive ( pInst );
    }
}

void UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged ( SUclDLInst *pInst, uint8 InstId, EUclALPhyPeerReadyStatus status )
{

    if ( eUclDLState_Shutdown != pInst->state )
    {
        if ( eUclALPhyPeerReadyStatus_Ready == status )
        {
            // Peer Ready. Move to Active. Can do Transmit and Receive.
            pInst->state = eUclDLState_Active;
            pInst->linkStatus = eUclDLLinkStatus_Up;
            pInst->phyReInitCounter = ( ( pInst->pCfg->phyRetryTimeIntervalMs / pInst->pCfg->timerTaskPeriodicityMs ) + 1u );

            // Update Time since link up
            pInst->stats.linkUpTime = UclALOs_GetSystemTimeMs ( 0 );

            // Send Heart beat
            ( void ) UclDL_Impl_SendHeartBeat ( pInst );

            // Start Timers
            UCLDL_START_TIMER ( pInst, UCLDL_BPS_LOCAL_TIMER_IDX, UCLDL_1000MS );
            UCLDL_START_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX, pInst->pCfg->heartBeatTimerPeriodicityMs );
            UCLDL_START_TIMER ( pInst, UCLDL_LD_LOCAL_TIMER_IDX, pInst->pCfg->linkDownTimerPeriodicityMs );

            LOGI ( 0, "UclDL_Impl", "Inst %d PeerReady: Link UP ", InstId );
            // Start Session Key Negotiation
            UclDL_Impl_SecurityStartKeyNegotiation ( pInst );
        }
        else if ( eUclALPhyPeerReadyStatus_NotReady == status )
        {
            // Peer NOT Ready. Move to RxOnly. Can only Receive.
            pInst->state = eUclDLState_RxOnly;
            pInst->linkStatus = eUclDLLinkStatus_Down;

            pInst->stats.linkDropCntr++;

            // Stop Timers
            UCLDL_STOP_TIMER ( pInst, UCLDL_BPS_LOCAL_TIMER_IDX );
            UCLDL_STOP_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX );
            UCLDL_STOP_TIMER ( pInst, UCLDL_LD_LOCAL_TIMER_IDX );
        }
        else
        {
            // Do nothing.
        }

        // Notify subscribers
        UclDL_Impl_NofityLinkStatusChanged ( pInst, pInst->linkStatus );
    }
}

static void *UclDL_Impl_TimerTask ( void *pData )
{
    SUclDLInst *pInst = ( SUclDLInst * ) pData;
    uint8 it;

    if ( ( eUclDLState_Active == pInst->state ) || ( eUclDLState_RxOnly == pInst->state ) )
    {
        if ( UCLDL_RX_PROCESS_SCHEDULED == pInst->pCfg->receiveProcessingMode )
        {
            UclDL_Impl_ProcessReceive ( pInst );
        }

        // Process ACK Timers
        UclDL_Impl_ProcessAckTimer ( pInst );

        // Process Local timers
        for ( it = 0; it < UCLDL_IMPL_MAX_LOCAL_TIMERS; it++ )
        {
            if ( UCLDL_IS_RUNNING_TIMER ( pInst, it ) )
            {
                UCLDL_DEC_TIMER ( pInst, it );

                if ( UCLDL_IS_ELAPSED_TIMER ( pInst, it ) )
                {
                    UCLDL_CALL_EXPIRY_FUNC ( pInst, it );
                }
            }
        }

        // Increment TSC Counter
        pInst->tscCounter++;
    }
    else if ( eUclDLState_Recovery == pInst->state )
    {
        if ( ( pInst->phyReInitCounter-- ) == 0u )
        {
            pInst->phyReInitCounter = ( ( pInst->pCfg->phyRetryTimeIntervalMs / pInst->pCfg->timerTaskPeriodicityMs ) + 1u );

            if ( pInst->numPhyRecoveryAttempts < pInst->pCfg->maxPhyRecoveryAttempts )
            {
                LOGE ( 0, "UclDL_Impl", "TimerTask: Recovery Attempt: %d", pInst->numPhyRecoveryAttempts );

                ( void ) UclDL_Impl_ReInitPhy ( pInst );
            }
            else
            {
                // Notify subscribers about Fatal error
                if ( UCLDL_PHY_RECOVERY_INFINITE == pInst->numPhyRecoveryAttempts )
                {
                    pInst->numPhyRecoveryAttempts = 0;
                }
                else
                {
                    LOGE ( 0, "UclDL_Impl", "TimerTask: Notify Fatal Error after %d Retries", pInst->numPhyRecoveryAttempts );
                    UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_FatalError );
                }
            }
        }
        else
        {
            // Do Nothing
        }
    }
    else
    {
        //Do Nothing
    }

    return NULL;
}

static void UclDL_Impl_HeartBeatTimerExpired ( SUclDLInst *pInst )
{
    Ucl_ReturnType Ret;

    if ( eUclDLState_Active == pInst->state )
    {
        // Send Heart beat
        Ret = UclDL_Impl_SendHeartBeat ( pInst );

        if ( UCL_E_OK != Ret )
        {
            // Log Error
            LOGE ( 0, "UclDL_Impl", "HeartBeatTimerExpired: UclDL_Impl_SendHeartBeat Failed %d", Ret );
        }

        // Schedule next Heart beat message
        UCLDL_START_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX, pInst->pCfg->heartBeatTimerPeriodicityMs );
    }

    return;
}

static void UclDL_Impl_BpsTimerExpired ( SUclDLInst *pInst )
{
    pInst->stats.txBps = ( ( pInst->txBytesBps ) * 8u );
    pInst->stats.rxBps = ( ( pInst->rxBytesBps ) * 8u );

    pInst->txBytesBps = 0;
    pInst->rxBytesBps = 0;
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## Tx Msgs : %d", pInst->instId, pInst->stats.txMsgs );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## TxA Msgs : %d", pInst->instId, pInst->stats.txAckMsgs );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## TxA TO : %d", pInst->instId, pInst->stats.txAckTmo );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## Rx Msgs : %d", pInst->instId, pInst->stats.rxMsgs );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## Rx HB Msgs : %d", pInst->instId, pInst->stats.rxHbMsgs );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## Tx Bps : %d", pInst->instId, pInst->stats.txBps );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d ## Rx Bps : %d", pInst->instId, pInst->stats.rxBps );
    LOGI ( 0, "UclDL_Impl", "Inst Id : %d  ## Avg Ack Latency : %d", pInst->instId, pInst->stats.avgAckLatency );

    UCLDL_START_TIMER ( pInst, UCLDL_BPS_LOCAL_TIMER_IDX, UCLDL_1000MS );

    return;
}

static void UclDL_Impl_LinkDownTimerExpired ( SUclDLInst *pInst )
{
    LOGE ( 0, "UclDL_Impl", "%s", "LinkDownTimerExpired" );

    // Link Down Timer Expired
    pInst->linkStatus = eUclDLLinkStatus_Down;
    pInst->stats.linkDropCntr++;

    // Notify subscribers
    UclDL_Impl_NofityLinkStatusChanged ( pInst, eUclDLLinkStatus_Down );

    // Perform Recovery
    pInst->state = eUclDLState_Recovery;

    return;
}

static void UclDL_Impl_ProcessReceive ( SUclDLInst *pInst )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    uint8 it;
    uint8 MsgVerifyOk;
    uint16 MsgHdr;
    uint8 ComputedCmac[UCLDL_MSG_CMAC_SIZE];
    uint16 MsgId;
    uint16 MsgIndex;
    uint16 MsgRawLen;   // COBS Encoded Frame
    uint16 MsgDecLen;   // MsgId + Payload + Checksum
    uint16 MsgSize;     // MsgId + Payload
    uint16 PayloadSize; // Payload
    uint16 ComputedChksum;
    uint16 ReceivedChksum;
    uint16 RxTSC;
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclDLMsg rxMsg;

    if ( pCfg->rxWorkBufferSize > pInst->rxCobsOverheadBytes ) //potential_overrun: Index pInst->rxCobsOverheadBytes may be outside the bounds of pCfg->pRxWorkBuffer
    {
        // Process all received frames
        MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;

        while ( UCL_E_OK == UclALPhy_Read ( pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID],
                                            &pCfg->pRxWorkBuffer[pInst->rxCobsOverheadBytes],
                                            &MsgRawLen ) )
        {

            if ( UCLDL_MSG_MIN_SIZE > MsgRawLen )
            {
                // Spurious frame. Drop the packet and process next packet
                MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;
                continue;
            }

            // Decode the COBS Frame into IPCL Frame
            MsgDecLen = UclDL_Impl_CobsDecode ( &pCfg->pRxWorkBuffer[0], pCfg->rxWorkBufferSize,
                                                &pCfg->pRxWorkBuffer[pInst->rxCobsOverheadBytes + UCLDL_MSG_DELIM_SIZE],
                                                ( MsgRawLen - ( 2u * UCLDL_MSG_DELIM_SIZE ) ) );

            if ( UCLDL_MSG_MIN_SIZE > MsgDecLen )
            {
                LOGE ( 0, "UclDL_Impl", "%s", " Decoding error in rcvd msg." );
                // Decoding error. Drop the packet and process next packet
                MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;
                continue;
            }

            ///< Check for reinit counter 
            if( pInst->numPhyRecoveryAttempts > 0 )
            {
                pInst->numPhyRecoveryAttempts  = 0;
            }

            // Reset Link Down Timer
            UCLDL_START_TIMER ( pInst, UCLDL_LD_LOCAL_TIMER_IDX, pCfg->linkDownTimerPeriodicityMs );

            MsgIndex = 0;

            // Extract Header
            MsgHdr = ( ( uint16 ) ( ( ( uint16 ) pCfg->pRxWorkBuffer[MsgIndex] ) << 8u ) | ( uint16 ) ( pCfg->pRxWorkBuffer[MsgIndex + 1u] ) );
            MsgIndex += UCLDL_MSG_HEADER_SIZE;

            // Extract Message ID
            MsgId = ( ( uint16 ) ( ( ( uint16 ) pCfg->pRxWorkBuffer[MsgIndex] ) << 8u ) | ( uint16 ) ( pCfg->pRxWorkBuffer[MsgIndex + 1u] ) );
            MsgIndex += UCLDL_MSG_MSGID_SIZE;
            MsgVerifyOk = FALSE;

            if ( UCLDL_MSG_SEC_LEVEL_0 == UCLDL_MSG_SEC_LEVEL_GET ( MsgHdr ) )
            {
                // Calculate Checksum
                MsgSize = MsgDecLen - UCLDL_MSG_CHKSUM_SIZE;

                ComputedChksum = UclDL_Impl_GetCRC ( &pCfg->pRxWorkBuffer[0], MsgSize );

                ReceivedChksum = ( ( uint16 ) ( ( ( uint16 ) pCfg->pRxWorkBuffer[MsgSize] ) << 8u ) | ( uint16 ) ( pCfg->pRxWorkBuffer[MsgSize + 1u] ) );

                // Check if Checksum match
                if ( ComputedChksum == ReceivedChksum )
                {
                    MsgVerifyOk = TRUE;
                    Ret = UCL_E_OK;
                }
            }
            else
            {
                if ( UCLDL_SEC_MSG_MIN_SIZE > MsgDecLen )
                {
                    LOGE ( 0, "UclDL_Impl", "%s", " Decoding error in rcvd secure msg." );
                    // Decoding error. Drop the packet and process next packet
                    MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;
                    continue;
                }

                MsgSize = MsgDecLen - UCLDL_MSG_CMAC_SIZE;
                Ret = UCL_E_OK;

                if ( 0u < pInst->numIUclALCrypto )
                {
                    // Decrypt message
                    if ( UCLDL_MSG_SEC_LEVEL_2 == UCLDL_MSG_SEC_LEVEL_GET ( MsgHdr ) )
                    {
                        // Prepare Initialization Vector
                        for ( it = 0; it < UCLDL_MSG_CMAC_SIZE; it++ )
                        {
                            ( void ) UclALOs_Memcpy ( 0, &pCfg->pReceiveIVBuffer[it * UCLDL_MSG_CMAC_SIZE],
                                                      &pCfg->pRxWorkBuffer[MsgSize], UCLDL_MSG_CMAC_SIZE );
                        }

                        // Decrypt Payload
                        Ret = UclDL_Impl_Decrypt ( pInst, UCLDL_RX_CRY_INST_ID, pCfg->pReceiveIVBuffer,
                                                   &pCfg->pRxWorkBuffer[MsgIndex], ( MsgSize - ( UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_HEADER_SIZE ) ) );
                    }

                    if ( UCL_E_OK == Ret )
                    {
                        ( void ) UclALOs_Memset ( 0, ComputedCmac, 0, UCLDL_MSG_CMAC_SIZE );

                        // Calculate CMAC
                        Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_RX_CRY_INST_ID, eUclALCryptoKeyType_SK, pCfg->pRxWorkBuffer,
                                                   MsgSize,
                                                   ComputedCmac,
                                                   UCLDL_MSG_CMAC_SIZE );

                        if ( ( ComputedCmac[0u] == pCfg->pRxWorkBuffer[MsgSize] ) && ( ComputedCmac[1u] == pCfg->pRxWorkBuffer[MsgSize + 1u] ) && ( ComputedCmac[2u] == pCfg->pRxWorkBuffer[MsgSize + 2u] ) && ( ComputedCmac[3u] == pCfg->pRxWorkBuffer[MsgSize + 3u] ) )
                        {
                            MsgVerifyOk = TRUE;
                        }
                        else
                        {
                            Ret = UCL_E_NOK;
                        }
                    }
                }
                else
                {
                    //Invalid Crypto Configuration. Drop the packet and process next packet
                    LOGE ( 0, "UclDL_Impl", "Crypto Message Received. No Crypto Instance Configured %d / Invalid MsgSize %d rcvd", pInst->numIUclALCrypto, MsgSize );
                    MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;
                    continue;
                }
            }

            // Message Verified
            if ( TRUE == MsgVerifyOk )
            {
                // Increment stats
                pInst->stats.rxMsgs++;
                pInst->stats.rxBytes += MsgDecLen;
                pInst->rxBytesBps += MsgDecLen;

                // Process P2P messages
                if ( UCLDL_MSG_TYPE_P2P == UCLDL_MSG_TYPE_GET ( MsgHdr ) )
                {
                    PayloadSize = MsgSize - (uint16)(UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_HEADER_SIZE);

                    switch ( UCLDL_P2PMSG_TYPE_GET ( MsgHdr ) )
                    {
                    case UCLDL_P2P_MSG_TYPE_HEARTBEAT:
                        pInst->stats.rxHbMsgs++;
                        break;

                    case UCLDL_P2P_MSG_TYPE_SECURITY:
                        if ( TRUE == pCfg->enableSecurity )
                        {
                            switch ( MsgId )
                            {
                            case UCLDL_P2P_MSG_SECURITY_RS1:

                            // Fall through
                            case UCLDL_P2P_MSG_SECURITY_RS2:
                                UclDL_Impl_SecurityRecvSeed ( pInst, MsgId, &pCfg->pRxWorkBuffer[MsgIndex],
                                                              PayloadSize );
                                break;

                            case UCLDL_P2P_MSG_SECURITY_KVV_REQ:
                                UclDL_Impl_SecurityRecvKVVRequest ( pInst, &pCfg->pRxWorkBuffer[MsgIndex],
                                                                    PayloadSize );
                                break;

                            case UCLDL_P2P_MSG_SECURITY_KVV_RES:
                                UclDL_Impl_SecurityRecvKVVResponse ( pInst, &pCfg->pRxWorkBuffer[MsgIndex],
                                                                     PayloadSize );
                                break;

                            default:
                                break;
                            }
                        }

                        break;

                    default:
                        break;
                    }
                }
                else if ( UCLDL_MSG_TYPE_N2N == UCLDL_MSG_TYPE_GET ( MsgHdr ) )
                {
                    PayloadSize = MsgSize - (uint16)(UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_HEADER_SIZE);

                    if ( pCfg->nodeId == UCLDL_MSG_GET_DESTNODE_ID ( MsgHdr ) )
                    {
                        switch ( UCLDL_N2NMSG_TYPE_GET ( MsgHdr ) )
                        {
                        case UCLDL_N2N_MSG_TYPE_ACK:
                            UclDL_Impl_ProcessAck ( pInst, MsgId, pCfg->pRxWorkBuffer[MsgIndex] );
                            pInst->stats.rxAckMsgs++;
                            break;

                        default:
                            LOGE ( 0, "UclDL_Impl", "Invalid Msg Type %d Rcvd in Msg Hdr %d", UCLDL_N2NMSG_TYPE_GET ( MsgHdr ), MsgHdr );
                            break;
                        }
                    }
                    else
                    {

                        // Notify Clients
                        rxMsg.MsgHdr = MsgHdr;
                        rxMsg.MsgId = MsgId;
                        rxMsg.pPayload = &pCfg->pRxWorkBuffer[MsgIndex];
                        rxMsg.Size = PayloadSize;
                        UclDL_Impl_NofityMsgReceived ( pInst, eUclDLRxStatus_Ok, &rxMsg );
                    }
                }
                // Process Normal messages
                else
                {
                    // Process TSC Counter
                    if ( TRUE == pCfg->enableTSC )
                    {
                        RxTSC = ( uint16 ) ( ( ( uint16 ) pCfg->pRxWorkBuffer[MsgIndex] << 8u ) | ( uint16 ) pCfg->pRxWorkBuffer[MsgIndex + 1u] );
                        PayloadSize = MsgSize - (uint16)(UCLDL_MSG_TSC_SIZE + UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_HEADER_SIZE);
                        MsgIndex += UCLDL_MSG_TSC_SIZE;

                        Ret = UclDL_Impl_SecurityValidateTSC ( pInst, RxTSC );

                        if ( UCL_E_NOK == Ret )
                        {
                            UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_SecurityTSCError );
                        }
                    }
                    else
                    {
                        PayloadSize = MsgSize - (uint16)(UCLDL_MSG_MSGID_SIZE + UCLDL_MSG_HEADER_SIZE);
                    }

                    if ( UCL_E_OK == Ret )
                    {
                        // Send Positive Acknowledgment only if the msg is destined to this node
                        if ( pCfg->nodeId == UCLDL_MSG_GET_DESTNODE_ID ( MsgHdr ) )
                        {
                            UclDL_Impl_SendAck ( pInst, MsgId, UCLDL_MSG_GET_SRCNODE_ID ( MsgHdr ), UCLDL_ACK_SUCCESS );
                        }

                        // Notify Clients
                        rxMsg.MsgHdr = MsgHdr;
                        rxMsg.MsgId = MsgId;
                        rxMsg.pPayload = &pCfg->pRxWorkBuffer[MsgIndex];
                        rxMsg.Size = PayloadSize;

                        UclDL_Impl_NofityMsgReceived ( pInst, eUclDLRxStatus_Ok, &rxMsg );

                    }
                }
            }
            else
            {
                if ( pCfg->nodeId == UCLDL_MSG_GET_DESTNODE_ID ( MsgHdr ) )
                {
                    if ( UCLDL_MSG_SEC_LEVEL_0 == UCLDL_MSG_SEC_LEVEL_GET ( MsgHdr ) )
                    {
                        pInst->stats.rxChksumErr++;
                    }
                    else
                    {
                        pInst->stats.rxCmacErr++;
                        UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_SecurityCMACError );
                    }

                    // Send Negative Acknowledgment even if this msg is not destined to this node
                    UclDL_Impl_SendAck ( pInst, MsgId, UCLDL_MSG_GET_SRCNODE_ID ( MsgHdr ), UCLDL_ACK_ERROR );

                    // Notify Clients
                    rxMsg.MsgHdr = MsgHdr;
                    rxMsg.MsgId = MsgId;
                    rxMsg.pPayload = NULL;
                    rxMsg.Size = 0;
                    UclDL_Impl_NofityMsgReceived ( pInst, eUclDLRxStatus_Error, &rxMsg );
                    LOGE ( 0, "UclDL_Impl", "ProcessReceive: Msg Verification Error in Node %d for Msg %d to Dest Node %d", pInst->pCfg->nodeId, MsgId, UCLDL_MSG_GET_DESTNODE_ID ( MsgHdr ) );
                }
                else
                {
                    LOGE ( 0, "UclDL_Impl", "ProcessReceive: Msg Verification Error in Node %d for Msg %d to Dest Node %d", pInst->pCfg->nodeId, MsgId, UCLDL_MSG_GET_DESTNODE_ID ( MsgHdr ) );
                }
            }

            MsgRawLen = pCfg->rxWorkBufferSize - pInst->rxCobsOverheadBytes;
        }
    }
}

static void UclDL_Impl_SendAck ( SUclDLInst *pInst, uint16 MsgId, uint16 DestNode, uint8 AckStatus )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclDL_Impl_SendN2NMessage ( pInst, UCLDL_N2N_MSG_TYPE_ACK, MsgId, DestNode, &AckStatus, UCLDL_ACK_SIZE );

    if ( UCL_E_OK == Ret )
    {
        pInst->stats.txAckMsgs++;
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "SendAck: Failed %d", Ret );
    }
}

static Ucl_ReturnType UclDL_Impl_SendHeartBeat ( SUclDLInst *pInst )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclDL_Impl_SendP2PMessage ( pInst, UCLDL_P2P_MSG_TYPE_HEARTBEAT,
                                      UCLDL_HB_PATTERN, NULL, 0 );

    if ( UCL_E_OK == Ret )
    {
        pInst->stats.txHbMsgs++;
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "SendHeartBeat: Failed %d", Ret );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SendN2NMessage ( SUclDLInst *pInst, uint8 N2NMsgType, uint16 MsgId, uint16 DestNode, uint8 *pPayload,
        uint16 Size )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 ChkSum;
    uint16 EncLen;
    uint16 MsgHdr = 0;
    uint8 MsgStartIdx;
    uint8 *pMsgBuffer = NULL;
    uint16 MsgSize;
    uint16 MsgBufferSize = 0;

    MsgStartIdx = 2u; // Leave space for delimiter and cobs overhead
    MsgSize = 0u;

    switch ( N2NMsgType )
    {
    case UCLDL_N2N_MSG_TYPE_ACK:
        pMsgBuffer = pInst->ackMsgScratchBuffer;
        MsgBufferSize = UCLDL_IMPL_ACK_MSG_SIZE;
        break;

    default:
          //Do Nothing
          ;
        break;
    }

    if ( NULL != pMsgBuffer )
    {
        // Prepare Message Header Message
        UCLDL_N2NMSG_TYPE_SET ( MsgHdr, N2NMsgType );
        UCLDL_MSG_SET_DESTNODE_ID ( MsgHdr, DestNode );
        UCLDL_MSG_SET_SRCNODE_ID ( MsgHdr, pCfg->nodeId );

        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( MsgHdr >> 8u );
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( MsgHdr & 0x00FFu );
        MsgSize += UCLDL_MSG_HEADER_SIZE;

        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( MsgId >> 8u );
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( MsgId & 0x00FFu );
        MsgSize += UCLDL_MSG_MSGID_SIZE;

        if ( 0u < Size )
        {
            ( void ) UclALOs_Memcpy ( 0, &pMsgBuffer[MsgStartIdx + MsgSize], pPayload, Size );
            MsgSize += Size;
        }

        // Append Checksum
        ChkSum = UclDL_Impl_GetCRC ( &pMsgBuffer[MsgStartIdx], MsgSize );

        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( ChkSum >> 8u );
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( ChkSum & 0x00FFu );

        MsgSize += UCLDL_MSG_CHKSUM_SIZE;

        // Encode the message
        EncLen = UclDL_Impl_CobsEncode ( &pMsgBuffer[1u], ( MsgBufferSize - ( 2u * UCLDL_MSG_DELIM_SIZE ) ),
                                         &pMsgBuffer[MsgStartIdx], MsgSize );

        // Send it over the wire
        if ( 0u < EncLen )
        {
            pMsgBuffer[0u] = UCLDL_FRAME_DELIM;
            pMsgBuffer[EncLen + 1u] = UCLDL_FRAME_DELIM;

            Ret = UclDL_Impl_SendMessage ( pInst, pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID], pMsgBuffer,
                                           ( EncLen + ( 2u * UCLDL_MSG_DELIM_SIZE ) ) );
        }
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SendN2NMessage: DL Inst %d Failed %d", pInst->instId, Ret );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SendP2PMessage ( SUclDLInst *pInst, uint8 P2PMsgType, uint16 MsgId, uint8 *pPayload,
        uint16 Size )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 ChkSum;
    uint16 EncLen;
    uint16 MsgHdr = 0;
    uint8 MsgStartIdx;
    uint8 *pMsgBuffer = NULL;
    uint16 MsgSize;
    uint16 MsgBufferSize = 0;

    MsgStartIdx = 2u; // Leave space for delimiter and cobs overhead
    MsgSize = 0u;

    switch ( P2PMsgType )
    {
    case UCLDL_P2P_MSG_TYPE_HEARTBEAT:
        pMsgBuffer = pInst->hbMsgScratchBuffer;
        MsgBufferSize = UCLDL_IMPL_ACK_MSG_SIZE;
        break;

    case UCLDL_P2P_MSG_TYPE_SECURITY:
        pMsgBuffer = pCfg->pCryMsgScratchBuffer;
        MsgBufferSize = UCLDL_IMPL_SEC_MSG_SIZE;
        break;

    default:
        //Do Nothing
        break;
    }

    if ( NULL != pMsgBuffer )
    {
        // Prepare Message Header Message
        UCLDL_P2PMSG_TYPE_SET ( MsgHdr, P2PMsgType );
        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( MsgHdr >> 8u );;
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( MsgHdr & 0x00FFu );
        MsgSize += UCLDL_MSG_HEADER_SIZE;

        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( MsgId >> 8u );
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( MsgId & 0x00FFu );
        MsgSize += UCLDL_MSG_MSGID_SIZE;

        if ( 0u < Size )
        {
            ( void ) UclALOs_Memcpy ( 0, &pMsgBuffer[MsgStartIdx + MsgSize], pPayload, Size );
            MsgSize += Size;
        }

        // Append Checksum
        ChkSum = UclDL_Impl_GetCRC ( &pMsgBuffer[MsgStartIdx], MsgSize );

        pMsgBuffer[MsgStartIdx + MsgSize] = ( uint8 ) ( ChkSum >> 8u );
        pMsgBuffer[MsgStartIdx + MsgSize + 1u] = ( uint8 ) ( ChkSum & 0x00FFu );

        MsgSize += UCLDL_MSG_CHKSUM_SIZE;

        // Encode the message
        EncLen = UclDL_Impl_CobsEncode ( &pMsgBuffer[1u], ( MsgBufferSize - ( 2u * UCLDL_MSG_DELIM_SIZE ) ),
                                         &pMsgBuffer[MsgStartIdx], MsgSize );

        // Send it over the wire
        if ( 0u < EncLen )
        {
            pMsgBuffer[0u] = UCLDL_FRAME_DELIM;
            pMsgBuffer[EncLen + 1u] = UCLDL_FRAME_DELIM;

            Ret = UclDL_Impl_SendMessage ( pInst, pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID], pMsgBuffer,
                                           ( EncLen + ( 2u * UCLDL_MSG_DELIM_SIZE ) ) );
        }

        if ( UCL_E_OK != Ret )
        {
            LOGE ( 0, "UclDL_Impl", "SendP2PMessage:  DL Inst %d Failed %d Buff Size %d Msg Size %d",  pInst->instId, Ret, MsgBufferSize, Size );
        }
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "SendP2PMessage:  DL Inst %d Invalid P2P Msg %d", pInst->instId, P2PMsgType );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SendMessage ( SUclDLInst *pInst, uint8 phyInstId, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret;

    Ret = UclALPhy_Write ( phyInstId, pData, Size );

    if ( UCL_E_OK == Ret )
    {
        // Increment stats
        pInst->stats.txMsgs++;
        pInst->stats.txBytes += Size;
        pInst->txBytesBps += Size;

        // Reset HeartBeat Timer
        UCLDL_START_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX, pInst->pCfg->heartBeatTimerPeriodicityMs );
    }

    return Ret;
}

static void UclDL_Impl_ProcessAck ( SUclDLInst *pInst, uint16 MsgId, uint8 AckStatus )
{
    uint32 AckLatency;
    uint8 it;
    uint8 Found = FALSE;
    Ucl_ReturnType Ret;

    Ret = UclALOs_MutexLock ( 0, pInst->ackQueueProtectMutexId );

    if ( UCL_E_OK == Ret )
    {
        //for (it = 0; (FALSE == Found) && (it < UCLDL_IMPL_MAX_ACK_Q_SIZE); it++)
        for ( it = 0; ( it < pInst->pCfg->maxTxAckQueueSize ); it++ ) //misra_violation: The expression Found used in the for loop clauses is modified in the loop body
        {
            // Check if valid message waiting for ACK
            if ( ( FALSE == pInst->pCfg->pAckQueue[it].isFree ) && ( pInst->pCfg->pAckQueue[it].msgId == MsgId ) )
            {
                // Find out the latency
                AckLatency = ( uint32 ) ( UclALOs_GetSystemTimeMs ( 0 ) - pInst->pCfg->pAckQueue[it].timestamp );

                // Calculate Average Latency
                pInst->stats.avgAckLatency = ( ( pInst->stats.avgAckLatency + AckLatency ) / 2u );

                // Remove the item
                pInst->pCfg->pAckQueue[it].isFree = TRUE;
                Found = TRUE;
                break;
            }
        }

        ( void ) UclALOs_MutexUnlock ( 0, pInst->ackQueueProtectMutexId );
    }

    if ( Found == FALSE )
    {
        LOGE ( 0, "UclDL_Impl", "ProcessAck: DLInst %d Rcvd_Ack %d not in Ack_Q \n", pInst->instId, MsgId );
    }

    // Let all the listeners know about the status
    if ( TRUE == Found )
    {
        if ( UCLDL_ACK_SUCCESS == AckStatus )
        {
            UclDL_Impl_NotifyMsgTransmitStatus ( pInst, MsgId, eUclDLAckStatus_Ok );
        }
        else
        {
            UclDL_Impl_NotifyMsgTransmitStatus ( pInst, MsgId, eUclDLAckStatus_Error );
        }
    }
}

static void UclDL_Impl_ProcessAckTimer ( SUclDLInst *pInst )
{
    uint64 TimeNow;
    uint8 it;
    Ucl_ReturnType Ret;

    TimeNow = UclALOs_GetSystemTimeMs ( 0 );
    for ( it = 0u; it < pInst->pCfg->maxTxAckQueueSize; it++ )
    {
        // Check if valid message waiting for ACK
        if ( TRUE != pInst->pCfg->pAckQueue[it].isFree )
        {
            // Check if ACK Timer expired
            if ( TimeNow > ( pInst->pCfg->pAckQueue[it].timestamp + pInst->pCfg->maxAckTimeoutMs ) )
            {
                Ret = UclALOs_MutexLock ( 0, pInst->ackQueueProtectMutexId );

                if(Ret == UCL_E_OK )
                {
                    // Remove the item
                    pInst->pCfg->pAckQueue[it].isFree = TRUE;
                    pInst->pCfg->pAckQueue[it].timestamp = 0u;
                    pInst->stats.txAckTmo++;
                    ( void ) UclALOs_MutexUnlock ( 0, pInst->ackQueueProtectMutexId );
                }
                UclDL_Impl_NotifyMsgTransmitStatus ( pInst, pInst->pCfg->pAckQueue[it].msgId, eUclDLAckStatus_Timeout );
            }
        }
    }
}

static Ucl_ReturnType UclDL_Impl_GetFreeSlot ( SUclDLInst *pInst, uint16 MsgId, uint8 *pSlotId )
{
    Ucl_ReturnType Ret = UCL_E_BUSY;
    uint8 it = 0;

    *pSlotId = pInst->pCfg->maxTxAckQueueSize;

    Ret = UclALOs_MutexLock ( 0, pInst->ackQueueProtectMutexId );

    if ( UCL_E_OK == Ret )
    {
        Ret = UCL_E_BUSY;

        for ( it = 0; it < pInst->pCfg->maxTxAckQueueSize; it++ )
        {
            if ( TRUE == pInst->pCfg->pAckQueue[it].isFree )
            {
                /* Find an unused slot */
                if ( pInst->pCfg->maxTxAckQueueSize == *pSlotId )
                {
                    *pSlotId = it;
                    Ret = UCL_E_OK;
                }
            }
            // Check if any msg with same msg id waiting for ACK
            else if ( pInst->pCfg->pAckQueue[it].msgId == MsgId )
            {
                Ret = UCL_E_MSG_PENDING;
                break;
            }
            else
            {
                //Do Nothing
            }
        }

        ( void ) UclALOs_MutexUnlock ( 0, pInst->ackQueueProtectMutexId );
    }

    if ( Ret == UCL_E_BUSY )
    {
        LOGE ( 0, "UclDL_Impl", "%s", "Ack Q Exhausted." );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_ReInitPhy ( SUclDLInst *pInst )
{
    Ucl_ReturnType Ret;

    pInst->numPhyRecoveryAttempts++;

    // Stop Timers
    UCLDL_STOP_TIMER ( pInst, UCLDL_HB_LOCAL_TIMER_IDX );
    UCLDL_STOP_TIMER ( pInst, UCLDL_LD_LOCAL_TIMER_IDX );
    UCLDL_STOP_TIMER ( pInst, UCLDL_BPS_LOCAL_TIMER_IDX );

    // ReInit Phy
    Ret = UclALPhy_Shutdown ( pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID] );

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclDL_Impl ", " Reintialized for %d", pInst->numPhyRecoveryAttempts);
        Ret = UclALPhy_Initialize ( pInst->pIUclALPhy[UCLDL_DEFAULT_PHY_INST_ID] );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_Encrypt ( SUclDLInst *pInst, uint8 CryInst, uint8 *pIV, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BytesEncrypted = 0;
    uint16 BytesToEncrypt = 0;

    //    if(CryInst < pInst->numIUclALCrypto) // potential_overrun: Index CryInst may be outside the bounds of pInst->pIUclALCrypto.
    //  {
    Ret = UclALCrypto_CBC_Start ( pInst->pIUclALCrypto[CryInst], eUclALCryptoKeyType_SK, pIV,
                                  UCLDL_IMPL_SEC_KEY_SIZE );

    while ( ( UCL_E_OK == Ret ) && ( BytesEncrypted < Size ) )
    {
        if ( pInst->pCfg->encBufferSize < ( Size - BytesEncrypted ) )
        {
            BytesToEncrypt = pInst->pCfg->encBufferSize;
        }
        else
        {
            BytesToEncrypt = ( Size - BytesEncrypted );
        }

        Ret = UclALCrypto_CBC_Encrypt ( pInst->pIUclALCrypto[CryInst], &pData[BytesEncrypted], pInst->pCfg->pEncBuffer,
                                        BytesToEncrypt );

        if ( UCL_E_OK == Ret )
        {
            // Replace payload with encrypted block
            ( void ) UclALOs_Memcpy ( 0, &pData[BytesEncrypted], pInst->pCfg->pEncBuffer, BytesToEncrypt );
        }

        BytesEncrypted += BytesToEncrypt;
    }

    if ( UCL_E_OK == Ret )
    {
        Ret = UclALCrypto_CBC_Done ( pInst->pIUclALCrypto[CryInst] );
    }

    //  }
    //  else
    //  {
    //      LOGE(0, "UclDL_Impl", "Invalid Encrypt CryInst %d %d", CryInst, pInst->numIUclALCrypto);
    //  }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_Decrypt ( SUclDLInst *pInst, uint8 CryInst, uint8 *pIV, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BytesDecrypted = 0;
    uint16 BytesToDecrypt = 0;

    if ( CryInst < pInst->numIUclALCrypto ) // potential_overrun: Index CryInst may be outside the bounds of pInst->pIUclALCrypto.
    {
        Ret = UclALCrypto_CBC_Start ( pInst->pIUclALCrypto[CryInst], eUclALCryptoKeyType_SK, pIV,
                                      UCLDL_IMPL_SEC_KEY_SIZE );

        while ( ( UCL_E_OK == Ret ) && ( BytesDecrypted < Size ) )
        {
            if ( pInst->pCfg->decBufferSize < ( Size - BytesDecrypted ) )
            {
                BytesToDecrypt = pInst->pCfg->decBufferSize;
            }
            else
            {
                BytesToDecrypt = ( Size - BytesDecrypted );
            }

            Ret = UclALCrypto_CBC_Decrypt ( pInst->pIUclALCrypto[CryInst], &pData[BytesDecrypted], pInst->pCfg->pDecBuffer,
                                            BytesToDecrypt );

            if ( UCL_E_OK == Ret )
            {
                // Replace payload with decrypted block
                ( void ) UclALOs_Memcpy ( 0, &pData[BytesDecrypted], pInst->pCfg->pDecBuffer, BytesToDecrypt );
            }

            BytesDecrypted += BytesToDecrypt;
        }

        if ( UCL_E_OK == Ret )
        {
            Ret = UclALCrypto_CBC_Done ( pInst->pIUclALCrypto[CryInst] );
        }
        else
        {
            LOGE ( 0, "UclDL_Impl", "%s", "Msg Decrypt Error" );
        }
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "Decrypt:Invalid Crypto Inst %d %d", CryInst, pInst->numIUclALCrypto );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_GetCMAC ( SUclDLInst *pInst, uint8 CryInst, EUclALCryptoKeyType KeyType, uint8 *pData,
        uint16 DataSize, uint8 *pResult, uint16 ResultSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 CmacSize = ResultSize;

    if ( CryInst < pInst->numIUclALCrypto ) // potential_overrun: Index CryInst may be outside the bounds of pInst->pIUclALCrypto.
    {
        Ret = UclALCrypto_CMAC_Start ( pInst->pIUclALCrypto[CryInst], KeyType );

        if ( UCL_E_OK == Ret )
        {
            Ret = UclALCrypto_CMAC_Process ( pInst->pIUclALCrypto[CryInst], pData, DataSize );
        }

        if ( UCL_E_OK == Ret )
        {
            Ret = UclALCrypto_CMAC_Done ( pInst->pIUclALCrypto[CryInst], pResult, &CmacSize );
        }
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "GetCMAC: Invalid Cryto Inst %d %d", CryInst, pInst->numIUclALCrypto );
    }

    return Ret;
}

static uint16 UclDL_Impl_GetCRC ( const uint8 *pData, uint16 Size )
{
    uint16 Crc = 0x00;

    Crc = UclCrc_CalculateCRC16 ( pData, Size,  (uint16_t)1,  (bool)TRUE );

    return Crc;
}

static uint16 UclDL_Impl_CobsEncode ( uint8 *d, uint16 dsize, const uint8 *s, uint16 ssize )
{
    uint16 ri = 0u;
    uint16 wi = 1u;
    uint16 ci = 0u;
    uint16 len = 0u;
    uint8 code = 1u;

    while ( ( ri < ssize ) && ( wi < dsize ) )
    {
        if ( s[ri] == 0u )
        {
            d[ci] = code;
            code = 1u;
            ci = wi;
            wi++;
            ri++;
        }
        else
        {
            d[wi] = s[ri];
            ri++;
            wi++;
            code++;

            if ( code == 0xFFu )
            {
                d[ci] = code;
                code = 1u;
                ci = wi;
                wi++;
            }
        }
    }

    d[ci] = code;

    if ( ri == ssize )
    {
        len = wi;
    }

    return len;
}

static uint16 UclDL_Impl_CobsDecode ( uint8 *d, uint16 dsize, const uint8 *s, uint16 ssize )
{
    uint16 ri = 0u;
    uint16 wi = 0u;
    uint16 len = 0u;
    uint8 code;
    uint8 i;

    while ( ( ri < ssize ) && ( wi < dsize ) )
    {
        code = s[ri];

        if ( ( ( ri + code ) > ssize ) && ( code != 1u ) )
        {
            break;
        }

        ri++;

        for ( i = 1u; i < code; i++ )
        {
            d[wi] = s[ri];
            wi++;
            ri++;
        }

        if ( ( code != 0xFFu ) && ( ri != ssize ) )
        {
            d[wi] = 0u;
            wi++;
        }
    }

    if ( ri == ssize )
    {
        len = wi;
    }

    return len;
}

static void UclDL_Impl_SecurityStartKeyNegotiation ( SUclDLInst *pInst )
{
    LOGI ( 0, "UclDL_Impl", "SecurityStartKeyNegotiation: Auth State : %d", pInst->authState );

    if ( ( eUclDLState_Active == pInst->state ) && ( eUclDLAuthState_UnAuthenticated == pInst->authState ) && ( TRUE == pInst->pCfg->enableSecurity ) )
    {
        // Set state as wait for key negotiation
        pInst->authState = eUclDLAuthState_KeyNegotiation;

        // Start the timer
        UCLDL_START_TIMER ( pInst, UCLDL_SEC_LOCAL_TIMER_IDX, pInst->pCfg->keyNegotiationDelayMs );
    }
}

static Ucl_ReturnType UclDL_Impl_SecuritySendSeed ( SUclDLInst *pInst, uint16 SecMsgId, uint8 *pSeedBuffer, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclALCrypto_Random ( pInst->pIUclALCrypto[UCLDL_TX_CRY_INST_ID], pSeedBuffer, Size );

    if ( UCL_E_OK == Ret )
    {
        Ret = UclDL_Impl_SendP2PMessage ( pInst, UCLDL_P2P_MSG_TYPE_SECURITY, SecMsgId, pSeedBuffer, Size );
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SendSeed %d: Failed %d", SecMsgId, Ret );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "SendSeed %d: Success", SecMsgId );
    }

    return Ret;
}

static void UclDL_Impl_SecurityRecvSeed ( SUclDLInst *pInst, uint16 SeedType, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    LOGI ( 0, "UclDL_Impl", "SecurityRecvSeed: %d", SeedType );

    if ( UCLDL_P2P_MSG_SECURITY_RS1 == SeedType )
    {
        // Reset the authentication state
        pInst->authState = eUclDLAuthState_UnAuthenticated;

        // Store the received RS1
        if ( UCLDL_MSG_SEED_SIZE == Size )
        {
            ( void ) UclALOs_Memcpy ( 0, pInst->pCfg->pRS1Buffer, pData, Size );

            // Send RS2
            Ret = UclDL_Impl_SecuritySendSeed ( pInst, UCLDL_P2P_MSG_SECURITY_RS2, pInst->pCfg->pRS2Buffer,
                                                UCLDL_MSG_SEED_SIZE );

            // Generate Session Key
            if ( UCL_E_OK == Ret )
            {
                Ret = UclDL_Impl_SecurityGenerateSessionKey ( pInst );
            }

            if ( UCL_E_OK == Ret )
            {
                pInst->authState = eUclDLAuthState_KVVReq;

                UCLDL_START_TIMER ( pInst, UCLDL_SEC_LOCAL_TIMER_IDX, pInst->pCfg->securityStateTimeoutMs );
            }
        }
    }
    else if ( UCLDL_P2P_MSG_SECURITY_RS2 == SeedType )
    {
        if ( eUclDLAuthState_RS2 == pInst->authState )
        {
            // Store the received RS2
            if ( UCLDL_MSG_SEED_SIZE == Size )
            {
                ( void ) UclALOs_Memcpy ( 0, pInst->pCfg->pRS2Buffer, pData, Size );

                Ret = UclDL_Impl_SecurityGenerateSessionKey ( pInst );
            }

            if ( UCL_E_OK == Ret )
            {
                Ret = UclDL_Impl_SecuritySendKVVRequest ( pInst );
            }

            if ( UCL_E_OK == Ret )
            {
                pInst->authState = eUclDLAuthState_KVVResp;

                UCLDL_START_TIMER ( pInst, UCLDL_SEC_LOCAL_TIMER_IDX, pInst->pCfg->securityStateTimeoutMs );
            }
            else
            {
                pInst->authState = eUclDLAuthState_UnAuthenticated;
            }
        }
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "%s", "UclDL_Impl_SecurityRecvSeed: Authentication Failed" );
    }
}

static void UclDL_Impl_SecurityRecvKVVRequest ( SUclDLInst *pInst, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret;

    LOGI ( 0, "UclDL_Impl", "SecurityRecvKVVRequest: Auth State : %d", pInst->authState );

    if ( eUclDLAuthState_KVVReq == pInst->authState )
    {
        Ret = UclDL_Impl_SecurityValidateKVVRequest ( pInst, pData, Size );

        if ( UCL_E_OK == Ret )
        {
            Ret = UclDL_Impl_SecuritySendKVVResponse ( pInst, UCLDL_KVV_RESP_OK );
        }
        else
        {
            Ret = UclDL_Impl_SecuritySendKVVResponse ( pInst, UCLDL_KVV_RESP_FAIL );
            Ret = UCL_E_NOK;
        }

        if ( UCL_E_OK == Ret )
        {
            pInst->authState = eUclDLAuthState_Authenticated;

            LOGI ( 0, "UclDL_Impl", "%s", "SecurityRecvKVVRequest: Authentication Success" );
        }
        else
        {
            pInst->authState = eUclDLAuthState_UnAuthenticated;

            LOGE ( 0, "UclDL_Impl", "%s", "SecurityRecvKVVRequest: Authentication Failed" );
        }
    }
}

static Ucl_ReturnType UclDL_Impl_SecuritySendKVVRequest ( SUclDLInst *pInst )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;

    // Generate KVV
    ( void ) UclALOs_Memset ( 0, pCfg->pKVVReqBuffer, 0x11, UCLDL_IMPL_SEC_KVV_REQ_MSG_SIZE );

    Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_TX_CRY_INST_ID, eUclALCryptoKeyType_SK, pCfg->pKVVReqBuffer,
                               UCLDL_IMPL_SEC_KVV_REQ_MSG_SIZE, pCfg->pKVVReqBuffer, UCLDL_IMPL_SEC_KVV_REQ_MSG_SIZE );

    // Send KVV Req
    if ( UCL_E_OK == Ret )
    {
        Ret = UclDL_Impl_SendP2PMessage ( pInst, UCLDL_P2P_MSG_TYPE_SECURITY,
                                          UCLDL_P2P_MSG_SECURITY_KVV_REQ, pCfg->pKVVReqBuffer,
                                          UCLDL_IMPL_SEC_KVV_REQ_MSG_SIZE );
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SendKVVReq: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "%s", "SecuritySendKVVRequest: Success" );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SecurityValidateKVVRequest ( SUclDLInst *pInst, uint8 *pData, uint16 Size )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret;
    uint8 it;

    // Generate KVV
    ( void ) UclALOs_Memset ( 0, pCfg->pKVVReqBuffer, 0x11, UCLDL_IMPL_SEC_KEY_SIZE );

    Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_RX_CRY_INST_ID, eUclALCryptoKeyType_SK, pCfg->pKVVReqBuffer,
                               UCLDL_IMPL_SEC_KEY_SIZE, pCfg->pKVVReqBuffer,
                               UCLDL_IMPL_SEC_KEY_SIZE );

    if ( UCL_E_OK == Ret )
    {
        // Verify Received KVV
        for ( it = 0; ( it < UCLDL_IMPL_SEC_KEY_SIZE ); it++ )
        {
            if ( pCfg->pKVVReqBuffer[it] != pData[it] )
            {
                Ret = UCL_E_NOK;
                break;
            }
        }
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SecurityValidateKVVRequest: Failed %d", Ret );
        // Notify Security Error
        UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_SecurityNegoError );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "%s", "SecurityValidateKVVRequest: Success" );
    }

    return Ret;
}

static void UclDL_Impl_SecurityRecvKVVResponse ( SUclDLInst *pInst, uint8 *pData, uint16 Size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( eUclDLAuthState_KVVResp == pInst->authState )
    {
        Ret = UclDL_Impl_SecurityValidateKVVResponse ( pInst, pData, Size );

        if ( UCL_E_OK == Ret )
        {
            pInst->authState = eUclDLAuthState_Authenticated;

            LOGI ( 0, "UclDL_Impl", "%s", "SecurityRecvKVVRequest: Authentication Success" );
        }
        else
        {
            pInst->authState = eUclDLAuthState_UnAuthenticated;

            LOGE ( 0, "UclDL_Impl", "%s", "SecurityRecvKVVRequest: Authentication Failed" );
        }
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SecurityRecvKVVResponse: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "%s", "SecurityRecvKVVResponse: Success" );
    }
}

static Ucl_ReturnType UclDL_Impl_SecuritySendKVVResponse ( SUclDLInst *pInst, uint16 Response )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint8 MsgSize = 0;

    ( void ) UclALOs_Memset ( 0, pCfg->pKVVRespBuffer, 0, UCLDL_IMPL_SEC_KVV_RES_MSG_SIZE );

    pCfg->pKVVRespBuffer[MsgSize] = ( uint8 ) ( ( Response >> 8u ) & 0x00FFu );
    pCfg->pKVVRespBuffer[MsgSize + 1u] = ( uint8 ) ( Response & 0x00FFu );
    MsgSize += 2u;

    // Get Random Number for TSC Intial Value
    Ret = UclALCrypto_Random ( pInst->pIUclALCrypto[UCLDL_TX_CRY_INST_ID], &pCfg->pKVVRespBuffer[MsgSize],
                               UCLDL_MSG_TSC_SIZE );

    if ( UCL_E_OK == Ret )
    {
        // Set TSC value
        pInst->tscCounter = ( uint16 ) ( ( ( uint16 ) pCfg->pKVVRespBuffer[MsgSize] << 8u ) | ( uint16 ) pCfg->pKVVRespBuffer[MsgSize + 1u] );
        MsgSize += UCLDL_MSG_TSC_SIZE;

        // Generate CMAC for KVV Response
        Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_TX_CRY_INST_ID, eUclALCryptoKeyType_SK, pCfg->pKVVRespBuffer,
                                   UCLDL_IMPL_SEC_KEY_SIZE, &pCfg->pKVVRespBuffer[MsgSize], UCLDL_IMPL_SEC_KEY_SIZE );
        MsgSize += UCLDL_IMPL_SEC_KEY_SIZE;
    }

    // Send KVV Response
    if ( UCL_E_OK == Ret )
    {
        Ret = UclDL_Impl_SendP2PMessage ( pInst, UCLDL_P2P_MSG_TYPE_SECURITY,
                                          UCLDL_P2P_MSG_SECURITY_KVV_RES, pCfg->pKVVRespBuffer, MsgSize );
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "SecuritySendKVVResponse: Failed %d", Ret );
    }
    else
    {
        LOGI ( 0, "UclDL_Impl", "%s", "SecuritySendKVVResponse: Success" );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SecurityValidateKVVResponse ( SUclDLInst *pInst, uint8 *pData, uint16 Size )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 Response;
    uint8 it;
    uint8 DataSize;

    Response = ( uint16 ) ( ( ( uint16 ) pData[0] << 8 ) | ( uint16 ) pData[1u] );

    if ( UCLDL_KVV_RESP_OK == Response )
    {
        DataSize = UCLDL_KVV_RESP_SIZE + UCLDL_MSG_TSC_SIZE;

        ( void ) UclALOs_Memset ( 0, pCfg->pKVVRespBuffer, 0, UCLDL_IMPL_SEC_KVV_RES_MSG_SIZE );
        ( void ) UclALOs_Memcpy ( 0, pCfg->pKVVRespBuffer, pData, DataSize );

        // Generate CMAC for KVV Response
        Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_RX_CRY_INST_ID, eUclALCryptoKeyType_SK, pCfg->pKVVRespBuffer,
                                   UCLDL_IMPL_SEC_KEY_SIZE, &pCfg->pKVVRespBuffer[DataSize], UCLDL_IMPL_SEC_KEY_SIZE );

        if ( UCL_E_OK == Ret )
        {
            // Verify Received Message
            for ( it = DataSize; ( it < UCLDL_IMPL_SEC_KVV_RES_MSG_SIZE ); it++ )
            {
                if ( pCfg->pKVVRespBuffer[it] != pData[it] )
                {
                    Ret = UCL_E_NOK;
                    break;
                }
            }
        }
    }
    else
    {
        Ret = UCL_E_NOK;
    }

    if ( UCL_E_OK == Ret )
    {
        LOGI ( 0, "UclDL_Impl", "%s", "SecurityValidateKVVResponse: Success" );

        // Initialize TSC Counter
        pInst->tscCounter = ( uint16 ) ( ( ( uint16 ) pCfg->pKVVRespBuffer[UCLDL_KVV_RESP_SIZE] << 8u ) | ( uint16 ) ( pCfg->pKVVRespBuffer[UCLDL_KVV_RESP_SIZE + 1u] ) );
    }
    else
    {
        LOGE ( 0, "UclDL_Impl", "SecurityValidateKVVResponse: Failed %d", Ret );
        // Notify Security Error
        UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_SecurityNegoError );
    }

    return Ret;
}

static Ucl_ReturnType UclDL_Impl_SecurityGenerateSessionKey ( SUclDLInst *pInst )
{
    const SUclDLCfg *pCfg = pInst->pCfg;
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pCfg->pRS1Buffer ) && ( NULL != pCfg->pRS2Buffer ) )
    {
        // Prepare the Session Key generation input
        ( void ) UclALOs_Memcpy ( 0, pCfg->pSKBuffer, pCfg->pRS1Buffer, UCLDL_MSG_SEED_SIZE );
        ( void ) UclALOs_Memcpy ( 0, &pCfg->pSKBuffer[UCLDL_MSG_SEED_SIZE], pCfg->pRS2Buffer, UCLDL_MSG_SEED_SIZE );

        // Generate Session Key
        Ret = UclDL_Impl_GetCMAC ( pInst, UCLDL_TX_CRY_INST_ID, eUclALCryptoKeyType_EK, pCfg->pSKBuffer,
                                   UCLDL_IMPL_SEC_KEY_SIZE, pCfg->pSKBuffer, UCLDL_IMPL_SEC_KEY_SIZE );
    }

    // Set Session Key to Crypto AL
    if ( UCL_E_OK == Ret )
    {
        Ret = UclALCrypto_SetSessionKey ( pInst->pIUclALCrypto[UCLDL_TX_CRY_INST_ID], pCfg->pSKBuffer,
                                          UCLDL_IMPL_SEC_KEY_SIZE );
        Ret = UclALCrypto_SetSessionKey ( pInst->pIUclALCrypto[UCLDL_RX_CRY_INST_ID], pCfg->pSKBuffer,
                                          UCLDL_IMPL_SEC_KEY_SIZE );
    }

    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclDL_Impl", "GenerateSessionKey: Failed %d", Ret );
    }

    return Ret;
}

static void UclDL_Impl_SecurityTimerExpired ( SUclDLInst *pInst )
{
    Ucl_ReturnType Ret;

    LOGI ( 0, "UclDL_Impl", "SecurityTimerExpired: Auth State : %d", pInst->authState );

    switch ( pInst->authState )
    {
    case eUclDLAuthState_KeyNegotiation:
        // Send RS1
        Ret = UclDL_Impl_SecuritySendSeed ( pInst, UCLDL_P2P_MSG_SECURITY_RS1, pInst->pCfg->pRS1Buffer,
                                            UCLDL_MSG_SEED_SIZE );

        if ( UCL_E_OK == Ret )
        {
            pInst->authState = eUclDLAuthState_RS2;

            UCLDL_START_TIMER ( pInst, UCLDL_SEC_LOCAL_TIMER_IDX, pInst->pCfg->securityStateTimeoutMs );
        }
        else
        {
            pInst->authState = eUclDLAuthState_UnAuthenticated;
        }

        break;

    case eUclDLAuthState_RS2:

    // Fall through
    case eUclDLAuthState_KVVReq:

    // Fall through
    case eUclDLAuthState_KVVResp:
        // Fall through
        pInst->authState = eUclDLAuthState_UnAuthenticated;
        // Notify Security Error
        UclDL_Impl_NofityErrorCallback ( pInst, eUclDLError_SecurityNegoError );
        break;

    default:
        LOGE ( 0, "UclDL_Impl", " Invalid Auth State %d", pInst->authState );
        break;
    }
}

static Ucl_ReturnType UclDL_Impl_SecurityValidateTSC ( SUclDLInst *pInst, uint16 RxTSC )
{
    Ucl_ReturnType Ret = UCL_E_OK;
    uint16 deviation;
    uint8 IsRollover = FALSE;

    // Calculate deviation
    if ( RxTSC > pInst->tscCounter )
    {
        deviation = RxTSC - pInst->tscCounter;
    }
    else
    {
        deviation = pInst->tscCounter - RxTSC;
    }

    // Check if tolerance is exceeded */
    if ( deviation > pInst->pCfg->tscToleranceMs )
    {
        // Account for rollover
        deviation = 0xFFFFu - deviation;
        IsRollover = TRUE;
    }

    // Check if tolerance is exceeded
    if ( ( deviation > pInst->pCfg->tscToleranceMs ) && ( eUclDLAuthState_Authenticated == pInst->authState ) )
    {
        Ret = UCL_E_NOK;
    }

    // Synchronize TSC
    if ( FALSE == IsRollover )
    {
        // No rollover. Adjust TSC if incoming is bigger
        if ( RxTSC > pInst->tscCounter )
        {
            pInst->tscCounter = RxTSC;
        }
    }
    // Rollover. Adjust TSC if incoming is smaller
    else if ( RxTSC < pInst->tscCounter )
    {
        pInst->tscCounter = RxTSC;
    }
    else
    {
        //
    }

    return Ret;
}

Ucl_ReturnType UclDL_Impl_IUclDL_GetStats ( SUclDLInst *pInst, uint8 InstId, SUclDLStats *pDLStats )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    Ret = UclALOs_Memcpy ( 0, pDLStats, &pInst->stats, (uint32)sizeof ( SUclDLStats ) );

    return Ret;
}

static void UclDL_Impl_NofityMsgReceived ( SUclDLInst *pInst, EUclDLRxStatus Status, SUclDLMsg *pMsg )
{
    uint8 it;

    for ( it = 0; it < pInst->numIUclDLCbk; it++ )
    {
        UclDLCbk_MsgReceived ( pInst->pIUclDLCbk[it], Status, pMsg );
    }
}

static void UclDL_Impl_NofityErrorCallback ( SUclDLInst *pInst, EUclDLError Status )
{
    uint8 it;

    LOGE ( 0, "UclDL_Impl", "NofityErrorCallback %d", Status );

    for ( it = 0; it < pInst->numIUclDLCbk; it++ )
    {
        UclDLCbk_FatalError ( pInst->pIUclDLCbk[it], Status );
    }
}

static void UclDL_Impl_NotifyMsgTransmitStatus ( SUclDLInst *pInst, uint16 MsgId, EUclDLAckStatus Status )
{
    uint8 it;

    for ( it = 0; it < pInst->numIUclDLCbk; it++ )
    {
        UclDLCbk_MsgTransmitStatus ( pInst->pIUclDLCbk[it], MsgId, Status );
    }
}

static void UclDL_Impl_NofityLinkStatusChanged ( SUclDLInst *pInst, EUclDLLinkStatus Status )
{
    uint8 it;

    LOGI ( 0, "UclDL_Impl", "NofityLinkStatusChanged %d", Status );

    for ( it = 0; it < pInst->numIUclDLCbk; it++ )
    {
        UclDLCbk_LinkStatusChanged ( pInst->pIUclDLCbk[it], Status );
    }
}
