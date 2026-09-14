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
#include "UclILStream_Impl_Channel.h"
#include "UclALOs.h"
#include "UclALDebug.h"

Ucl_ReturnType UclILStream_Impl_ChnInitialize ( SUclChn_t *pChnList, SUclChnCfg_t *pBChnfg )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg;
    SUclChnInfo_t *pChnInfo;
    SUclChnQueue_t *pChnQueue;
    SUclChnQueueBuffer_t *pChnBufList;
    uint32 i, j;

    pChnList->mpCfg = pBChnfg;
    pChnList->mActiveChn = 0;

    pCfg = pChnList->mpCfg;

    for ( i = 0; i < pCfg->maxChn; i++ )
    {
        // Initialize Channel Queues
        pChnQueue = &pCfg->mpChnQueueList->mpQueueList[i];
        pChnBufList = &pCfg->mpChnQueueList->mpBufferList[i];

        //Assign the buffer to channel queue
        pChnQueue->mChnQueue = pChnBufList->pData;
        pChnQueue->chnQueuesize = pChnBufList->size;

        // Create Channel Queue Locks
        Ret = UclALOs_MutexCreate ( 0, &pChnQueue->chnQueueLockMutexId );

        for ( j = 0; j < pChnQueue->chnQueuesize; j++ )
        {
            pChnQueue->mChnQueue[j].isFree = TRUE;
            pChnQueue->mChnQueue[j].mId = 0xFFFFu;
            pChnQueue->mChnQueue[j].fId = -1;
            pChnQueue->mChnQueue[j].bId = -1;
            pChnQueue->mChnQueue[j].rId = 0u;
            pChnQueue->mChnQueue[j].timeMs= 0u;
        }

        //Initialize Channel Attribute List
        if ( UCL_E_OK == Ret )
        {
            pChnInfo = &pCfg->mpChnAttrList[i];
            pChnInfo->isActive = FALSE;
            pChnInfo->isShared = FALSE;
            pChnInfo->useCount = 0;
            pChnInfo->mAttr.mChId = INVALID_CH_ID;
            pChnInfo->mAttr.priority_level = UCL_PRIORITY_LEVEL_LOW;
            pChnInfo->mAttr.security_level = UCL_SECURITY_LEVEL_UNSECURE;
            pChnInfo->mAttr.time_to_live_ms = 0;
        }
    }

    //Create Channel Attribute List Lock
    if ( UCL_E_OK != Ret )
    {
        LOGE ( 0, "UclChn_Initialize", "%s", "Initialize Failed" );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnShutdown ( SUclChn_t *pChnList )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnQueueCfg_t *pChnQ = pCfg->mpChnQueueList;
    SUclChnInfo_t *pChnInfo;
    SUclChnQueue_t *pChnQueue;
    uint32 i, j;

    for ( i = 0; i < pCfg->maxChn; i++ )
    {
        // Get Channel Queue Index
        pChnQueue = &pChnQ->mpQueueList[i];

        // Destroy FD Queue Locks
        Ret = UclALOs_MutexDestroy ( 0, pChnQueue->chnQueueLockMutexId );

        for ( j = 0; j < pChnQueue->chnQueuesize; j++ )
        {
            pChnQueue->mChnQueue[j].isFree = TRUE;
            pChnQueue->mChnQueue[j].mId = 0xFFFFu;
            pChnQueue->mChnQueue[j].fId = -1;
            pChnQueue->mChnQueue[j].bId = -1;
            pChnQueue->mChnQueue[j].rId = 0u;
            pChnQueue->mChnQueue[j].timeMs= 0u;
        }

        if ( UCL_E_OK == Ret )
        {
            pChnInfo = &pCfg->mpChnAttrList[i];
            pChnInfo->isActive = FALSE;
            pChnInfo->isShared = FALSE;
            pChnInfo->mAttr.mChId = INVALID_CH_ID;
            pChnInfo->mAttr.priority_level = UCL_PRIORITY_LEVEL_LOW;
            pChnInfo->mAttr.security_level = UCL_SECURITY_LEVEL_UNSECURE;
            pChnInfo->mAttr.time_to_live_ms = 0;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        pChnList->mActiveChn = 0;
    }
    else
    {
        LOGE ( 0, "UclChn_Shutdown", "%s", "Shutdown Failed" );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnOpen ( SUclChn_t *ChnList, ucl_ch_t chId, uint16 flags, uint32 *pChnIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = ChnList->mpCfg;
    SUclChnInfo_t *pChnInfo;
    uint16 i;
    sint32 getChnSlot = -1;

    //Check if the channel is already opened.
    for ( i = 0; i < pCfg->maxChn; i++ )
    {
        pChnInfo = &pCfg->mpChnAttrList[i];

        if ( ( TRUE == pChnInfo->isActive ) && ( pChnInfo->mAttr.mChId == chId ) )
        {
            // If the channel already opened with shared permission
            if ( TRUE == pChnInfo->isShared )
            {
                pChnInfo->useCount++;
                getChnSlot = ( sint32 ) i;
                Ret = UCL_E_OK;
            }
            // If the channel already opened without shared permission
            else
            {
                Ret = UCL_E_NOT_SUPPORTED;
                LOGE ( 0, "UclChn_Open", "Channel Sharing not allowed for channel %d", chId );
            }

            break;
        }

        if ( ( getChnSlot < 0 ) && ( FALSE == pChnInfo->isActive ) )
        {
            getChnSlot = ( sint32 ) i;
        }
    }

    //Open a new channel if not opened already
    if ( ( Ret == UCL_E_NOK ) && ( getChnSlot != -1 ) )
    {
        pChnInfo = &pCfg->mpChnAttrList[getChnSlot];
        pChnInfo->mAttr.mChId = chId;
        pChnInfo->isActive = TRUE;
        pChnInfo->useCount++;

        if ( CHECK_FLAG_STATUS ( flags, UCL_O_SHARED ) > 0u )
        {
            pChnInfo->isShared = TRUE;
        }

        //Increment the Active Channel Count only for new channel
        ChnList->mActiveChn++;
        Ret = UCL_E_OK;
    }

    if ( Ret == UCL_E_OK )
    {
        *pChnIndex = ( uint32 ) getChnSlot;
    }
    else if ( Ret == UCL_E_NOK )
    {
        LOGE ( 0, "UclChn_Open", "Reached Max Chn Count. Could not allocate new Chn" );
    }
    else
    {
        // No Code required
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnClose ( SUclChn_t *pChnList, uint32 chnIndex )
{

    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnInfo_t *pChnInfo;

    // Check if CHID is Valid
    if ( chnIndex < pCfg->maxChn )
    {
        pChnInfo = &pCfg->mpChnAttrList[chnIndex];

        //Check if Channel is Active
        if ( pChnInfo->isActive == TRUE )
        {
            Ret = UCL_E_OK;
            pChnInfo->useCount--;

            if ( 0u == pChnInfo->useCount )
            {
                pChnInfo->isActive = FALSE;
                pChnInfo->mAttr.mChId = INVALID_CH_ID;
                pChnList->mActiveChn--;
            }
        }
        else
        {
            LOGE ( 0, "UclChn_Close", " Invoked for In-Active Chn Index %d", chnIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclChn_Close", " Invoked with Invalid Chn Index %d", chnIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnQueueRead ( SUclChn_t *pChnList, uint32 chnIndex, uint32 readIdx, SUclChnQueueElement_t *pBuffer )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnQueueCfg_t *pChnQ = pCfg->mpChnQueueList;
    SUclChnInfo_t *pChnInfo;
    SUclChnQueue_t *pChnQueue;

    // Check if CHID is Valid
    if (  chnIndex < pCfg->maxChn  )
    {
        pChnInfo = &pCfg->mpChnAttrList[chnIndex];

        //Check if Channel is Active
        if ( pChnInfo->isActive == TRUE )
        {
            // Get Channel Queue Index
            pChnQueue = &pChnQ->mpQueueList[chnIndex];
            //Lock the Channel Queue
            Ret = UclALOs_MutexLock ( 0, pChnQueue->chnQueueLockMutexId );

            if (( UCL_E_OK == Ret ) && ( readIdx < pChnQueue->chnQueuesize))
            {
                //Read from Chn Queue
                pBuffer->isFree = pChnQueue->mChnQueue[readIdx].isFree;
                pBuffer->bId = pChnQueue->mChnQueue[readIdx].bId;
                pBuffer->rId = pChnQueue->mChnQueue[readIdx].rId;
                pBuffer->fId = pChnQueue->mChnQueue[readIdx].fId;
                pBuffer->mId = pChnQueue->mChnQueue[readIdx].mId;
                ( void ) UclALOs_MutexUnlock ( 0, pChnQueue->chnQueueLockMutexId );
            }
            else
            {
               LOGE ( 0, "UclChn_ReadChnQ", " Invoked with Invalid Chn Queue Index / Mutex Not Avail ChQIndex %d",readIdx);
            }
        }
        else
        {
            LOGE ( 0, "UclChn_ReadChnQ", " Invoked for In-Active Chn Index %d", chnIndex );
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnQueueWrite ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnQueueElement_t *pBuffer )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    Ucl_ReturnType isNewMsgId = UCL_E_OK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnQueueCfg_t *pChnQ = pCfg->mpChnQueueList;
    SUclChnInfo_t *pChnInfo;
    SUclChnQueue_t *pChnQueue;
    uint16 i;

    // Check if CHID is Valid
    if ( ( chnIndex < pCfg->maxChn ) && ( pBuffer != NULL ) )
    {
        pChnInfo = &pCfg->mpChnAttrList[chnIndex];

        //Check if Channel is Active
        if ( pChnInfo->isActive == TRUE )
        {
            // Get Channel Queue Index
            pChnQueue = &pChnQ->mpQueueList[chnIndex];

            //Lock the Channel Queue
            Ret = UclALOs_MutexLock ( 0, pChnQueue->chnQueueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                // check for retundant Message Ids
                Ret = UCL_E_NOK;

                for ( i = 0; i < pChnQueue->chnQueuesize; i++ )
                {
                    if ( pChnQueue->mChnQueue[i].mId == pBuffer->mId )
                    {
                        isNewMsgId = UCL_E_NOK;
                        Ret = UCL_E_MSG_PENDING;
                        break;
                    }
                }

                if ( isNewMsgId == UCL_E_OK )
                {
                    for ( i = 0; i < pChnQueue->chnQueuesize; i++ )
                    {
                        if ( pChnQueue->mChnQueue[i].isFree == TRUE )
                        {
                            //Write to Chn Queue
                            pChnQueue->mChnQueue[i].isFree = FALSE;
                            pChnQueue->mChnQueue[i].bId = pBuffer->bId;
                            pChnQueue->mChnQueue[i].rId = pBuffer->rId;
                            pChnQueue->mChnQueue[i].fId = pBuffer->fId;
                            pChnQueue->mChnQueue[i].mId = pBuffer->mId;
                            Ret = UCL_E_OK;
                            break;
                        }
                    }
                }

                ( void ) UclALOs_MutexUnlock ( 0, pChnQueue->chnQueueLockMutexId );
            }
        }
        else
        {
            LOGE ( 0, "UclChn_WriteChnQ", " Invoked for In-Active Chn Index %d", chnIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclChn_WriteChnQ", " Invoked with Invalid Chn Index %d", chnIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnGetAttr ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnAttr_t *pAttr )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnInfo_t *pChInfo;

    if ( chnIndex < pCfg->maxChn )
    {
        pChInfo = &pCfg->mpChnAttrList[chnIndex];

        if ( pChInfo->isActive == TRUE )
        {
            pAttr->mChId = pChInfo->mAttr.mChId;
            pAttr->priority_level = pChInfo->mAttr.priority_level;
            pAttr->security_level = pChInfo->mAttr.security_level;
            pAttr->time_to_live_ms = pChInfo->mAttr.time_to_live_ms;
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE ( 0, "UclChn_GetChnAttr", " Invoked for In-Active CHID %d", chnIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclChn_GetChnAttr", " Invoked with Invalid CHID %d", chnIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnSetAttr ( SUclChn_t *pChnList, uint32 chnIndex, SUclChnAttr_t *pAttr )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnInfo_t *pChInfo;

    if ( chnIndex < pCfg->maxChn )
    {
        pChInfo = &pCfg->mpChnAttrList[chnIndex];

        if ( pChInfo->isActive == TRUE )
        {
            pChInfo->mAttr.priority_level = pAttr->priority_level;
            pChInfo->mAttr.security_level = pAttr->security_level;
            pChInfo->mAttr.time_to_live_ms = pAttr->time_to_live_ms;
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE ( 0, "UclChn_ChnSetAttr", " Invoked for In-Active CHID %d", chnIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclChnChnSetAttr", " Invoked with Invalid CHID %d", chnIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_ChnGetIdx ( SUclChn_t *pChnList, ucl_ch_t chid, uint32 *chnIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnInfo_t *pChInfo;
    uint16 i;

    for ( i = 0; i < pCfg->maxChn; i++ )
    {
        pChInfo = &pCfg->mpChnAttrList[i];

        if ( pChInfo->isActive == TRUE )
        {
            if ( pChInfo->mAttr.mChId == chid )
            {
                *chnIndex = i;
                Ret = UCL_E_OK;
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_RemoveChnElement ( SUclChn_t *pChnList, uint32 chnIndex, uint32 eIdx )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclChnCfg_t *pCfg = pChnList->mpCfg;
    SUclChnQueueCfg_t *pChnQ = pCfg->mpChnQueueList;
    SUclChnInfo_t *pChnInfo;
    SUclChnQueue_t *pChnQueue;

    // Check if CHID is Valid
    if ( chnIndex < pCfg->maxChn )
    {
        pChnInfo = &pCfg->mpChnAttrList[chnIndex];

        //Check if Channel is Active
        if ( pChnInfo->isActive == TRUE )
        {
            // Get Channel Queue Index
            pChnQueue = &pChnQ->mpQueueList[chnIndex];
            //Lock the Channel Queue
            Ret = UclALOs_MutexLock ( 0, pChnQueue->chnQueueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                if ( eIdx < pChnQueue->chnQueuesize )
                {
                    //Write to Chn Queue
                    pChnQueue->mChnQueue[eIdx].rId=0u;
                    pChnQueue->mChnQueue[eIdx].isFree = TRUE;
                    pChnQueue->mChnQueue[eIdx].bId= -1;
                    pChnQueue->mChnQueue[eIdx].fId = -1;
                    pChnQueue->mChnQueue[eIdx].mId = 0xFFFFu;
                    pChnQueue->mChnQueue[eIdx].timeMs = 0u;
                }

                ( void ) UclALOs_MutexUnlock ( 0, pChnQueue->chnQueueLockMutexId );
            }
        }
        else
        {
            LOGE ( 0, "UclChn_RemoveChnElement", " Invoked for In-Active Chn Index %d", chnIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclChn_RemoveChnElement", " Invoked with Invalid Chn Index %d", chnIndex );
    }

    return Ret;
}
