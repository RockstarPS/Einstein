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
#include "Ucl_Types.h"
#include "UclILStream_Impl_Fd.h"
#include "UclALOs.h"
#include "UclALDebug.h"

static Ucl_ReturnType UclILStream_Impl_FdGetQueue ( SUclFileDescCfg_t *pCfg, uint16 *qIndex );
static Ucl_ReturnType UclILStream_Impl_FdReleaseQueue ( SUclFileDescCfg_t *pCfg, uint16 qIndex );

Ucl_ReturnType UclILStream_Impl_FdInitialize ( SUclFileDesc_t *fdList, SUclFileDescCfg_t *pFDCfg )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg;
    SUclFileDescBuffer_t *pFdBuf;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;
    uint32 i;

    fdList->mpCfg = pFDCfg;
    fdList->mActiveFds = 0;

    pCfg = fdList->mpCfg;

    for ( i = 0; i < pCfg->mMaxQs; i++ )
    {
        // Initialize FD Queues
        pFdQ = &pCfg->mpFdQueueList->mpQueueList[i];
        pFdBuf = &pCfg->mpFdQueueList->mpBufferList[i];
        Ret = UclCmnRingBuffer_Initialize ( & ( pFdQ->mFileDescQueue ), pFdBuf->pData, pFdBuf->size );

        // Create FD Queue Locks
        if ( UCL_E_OK == Ret )
        {
            Ret = UclALOs_MutexCreate ( 0, &pFdQ->queueLockMutexId );
        }

        if ( UCL_E_OK == Ret )
        {
            pFdQ->isAvailable = TRUE;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        for ( i = 0; i < pCfg->mMaxFds; i++ )
        {
            // Initialize FD Attributes
            pFdAttr = &pCfg->mpFdAttrList[i];
            pFdAttr->mAttr.mChnIndex = INVALID_CH_INDEX;
            pFdAttr->mAttr.mOFlags = 0;
            pFdAttr->mTxQueueId = INVALID_FDQ_INDEX;
            pFdAttr->mRxQueueId = INVALID_FDQ_INDEX;
        }
    }
    else
    {
        LOGE ( 0, "UclILFd", "%s", "Initialize Failed" );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdShutdown ( SUclFileDesc_t *fdList )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;
    uint32 i;

    for ( i = 0; i < pCfg->mMaxQs; i++ )
    {
        // Get FD Queue Index
        pFdQ = &pCfg->mpFdQueueList->mpQueueList[i];

        // Destroy FD Queue Locks
        Ret = UclALOs_MutexDestroy ( 0, pFdQ->queueLockMutexId );

        if ( UCL_E_OK == Ret )
        {
            pFdQ->isAvailable = TRUE;
        }
    }

    if ( UCL_E_OK == Ret )
    {
        for ( i = 0; i < pCfg->mMaxFds; i++ )
        {
            // Initialize FD Attributes
            pFdAttr = &pCfg->mpFdAttrList[i];
            pFdAttr->mAttr.mChnIndex = INVALID_CH_INDEX;
            pFdAttr->mAttr.mOFlags = 0;
            pFdAttr->mTxQueueId = INVALID_FDQ_INDEX;
            pFdAttr->mRxQueueId = INVALID_FDQ_INDEX;
        }
    }
    else
    {
        LOGE ( 0, "UclILFd", "%s", "Shutdown Failed" );
    }

    return Ret;
}

ucl_fd_t UclILStream_Impl_FdGet ( SUclFileDesc_t *fdList, uint32 chnIdx, uint16 flags )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueueAttr_t *pFdAttr;
    ucl_fd_t uclFd = INVALID_FID;
    uint16 qIndex = INVALID_FDQ_INDEX;
    uint32 i;

    for ( i = 0; i < pCfg->mMaxFds; i++ )
    {
        pFdAttr = &pCfg->mpFdAttrList[i];

        //Check if Channel is In-Active
        if ( INVALID_CH_INDEX == pFdAttr->mAttr.mChnIndex )
        {
            if ( CHECK_FLAG_STATUS ( flags, ( UCL_O_WRONLY | UCL_O_RDWR ) ) > 0u )
            {
                //Get Tx FD Queue
                Ret = UclILStream_Impl_FdGetQueue ( fdList->mpCfg, &qIndex );

                if ( UCL_E_OK == Ret )
                {
                    pFdAttr->mTxQueueId = qIndex;
                }
            }

            if ( ( CHECK_FLAG_STATUS ( flags, ( UCL_O_RDONLY | UCL_O_RDWR ) ) ) > 0u )
            {
                //Get Rx FD Queue
                Ret = UclILStream_Impl_FdGetQueue ( fdList->mpCfg, &qIndex );

                if ( UCL_E_OK == Ret )
                {
                    pFdAttr->mRxQueueId = qIndex;
                }
                else
                {
                    //Release the Tx Queue Allocated if Rx Queue Get Failed for RDWR Chn
                    if ( ( ( CHECK_FLAG_STATUS ( flags, UCL_O_RDWR ) ) > 0u ) && ( pFdAttr->mTxQueueId != INVALID_FDQ_INDEX ) )
                    {
                        ( void ) UclILStream_Impl_FdReleaseQueue ( fdList->mpCfg, pFdAttr->mTxQueueId );
                    }
                }
            }

            if ( UCL_E_OK == Ret )
            {
                pFdAttr->mAttr.mChnIndex = chnIdx;
                pFdAttr->mAttr.mOFlags = flags;
                fdList->mActiveFds++;
                uclFd = ( ucl_fd_t ) i;
                break;
            }
            else
            {
                LOGE ( 0, "UclILStream_Impl_FdGet", " Failed for channel Idx", chnIdx );
            }
        }
    }

    return uclFd;
}

void UclILStream_Impl_FdRelease ( SUclFileDesc_t *fdList, ucl_fd_t fid )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueueAttr_t *pFdAttr;

    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if Channel is In-Active
        if ( INVALID_CH_INDEX != pFdAttr->mAttr.mChnIndex )
        {
            if ( CHECK_FLAG_STATUS ( pFdAttr->mAttr.mOFlags, ( UCL_O_WRONLY | UCL_O_RDWR ) ) > 0u )
            {
                ( void ) UclILStream_Impl_FdReleaseQueue ( fdList->mpCfg, pFdAttr->mTxQueueId );
                pFdAttr->mTxQueueId = INVALID_FDQ_INDEX;
                Ret = UCL_E_OK;
            }

            if ( CHECK_FLAG_STATUS ( pFdAttr->mAttr.mOFlags, ( UCL_O_RDONLY | UCL_O_RDWR ) ) > 0u )
            {
                ( void ) UclILStream_Impl_FdReleaseQueue ( fdList->mpCfg, pFdAttr->mRxQueueId );
                pFdAttr->mRxQueueId = INVALID_FDQ_INDEX;
                Ret = UCL_E_OK;
            }

            pFdAttr->mAttr.mChnIndex = INVALID_CH_INDEX;
            pFdAttr->mAttr.mOFlags = 0x0u;     // Clear the flag settings
            fdList->mActiveFds--;

            if ( UCL_E_NOK == Ret )
            {
                LOGE ( 0, "UclILFd_ReleaseFd", " Invoked for FID %d CHID %d has Invalid flag %d", fid, pFdAttr->mAttr.mChnIndex, pFdAttr->mAttr.mOFlags );
            }
        }
        else
        {
            LOGE ( 0, "UclILFd_ReleaseFd", " Invoked for FID %d with Invalid CHID", fid );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd_ReleaseFd", " Invoked with Invalid FID %d", fid );
    }
}

Ucl_ReturnType UclILStream_Impl_FdReadFromTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Tx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mTxQueueId ) && ( pFdAttr->mTxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mTxQueueId];

            //Read from Tx FD Queue
            Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                Ret = UclCmnRingBuffer_Read ( & ( pFdQ->mFileDescQueue ), pBuffer, pSize );
                ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );
            }
        }
        else
        {
            LOGE ( 0, "UclILFd_ReadTxFd", " Invoked with FID %d has Invalid QID %d", fid, pFdAttr->mTxQueueId );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd_ReadTxFd", " Invoked with Invalid FID %d", fid );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdWriteToTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Tx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mTxQueueId ) && ( pFdAttr->mTxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mTxQueueId];

            //Write to Tx FD Queue
            Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                Ret = UclCmnRingBuffer_Write ( & ( pFdQ->mFileDescQueue ), pBuffer, size );
                ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );

                if ( UCL_E_BUFFER_FULL == Ret )
                {
                    LOGE ( 0, "UclILFd_WriteTxFd", "FD Queue %d FULL", fid );
                }
            }
        }
        else
        {
            LOGE ( 0, "UclILFd_WriteTxFd", " Invoked with FID %d has Invalid QID %d", fid, pFdAttr->mTxQueueId );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd_WriteTxFd", " Invoked with Invalid FID %d", fid );
    }

    return Ret;
}

/*Read */
/*Poll */

Ucl_ReturnType UclILStream_Impl_FdReadFromRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 *pSize,
        EUclFileDescReadFdRxq type )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Rx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mRxQueueId ) && ( pFdAttr->mRxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mRxQueueId];

            //Read from Rx FD Queue
            Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                if ( eUclFileDescReadFdRxq_Read == type )
                {
                    Ret = UclCmnRingBuffer_Read ( & ( pFdQ->mFileDescQueue ), pBuffer, pSize );
                }
                else
                {
                    Ret = UclCmnRingBuffer_Poll ( & ( pFdQ->mFileDescQueue ), pBuffer, pSize );
                }

                ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );
            }
        }
        else
        {
            LOGE ( 0, "UclILFd_ReadRxFd", " Invoked with FID %d has Invalid QID %d", fid, pFdAttr->mRxQueueId );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd_ReadRxFd", " Invoked with Invalid FID %d", fid );
    }

    return Ret;
}


Ucl_ReturnType UclILStream_Impl_FdWriteToRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Rx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mRxQueueId ) && ( pFdAttr->mRxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mRxQueueId];

            //Write to Rx FD Queue
            Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

            if ( UCL_E_OK == Ret )
            {
                Ret = UclCmnRingBuffer_Write ( & ( pFdQ->mFileDescQueue ), pBuffer, size );
                ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );

                if ( UCL_E_BUFFER_FULL == Ret )
                {
                    LOGE ( 0, "UclILFd_WriteRxFd", "FD Queue %d FULL", fid );
                }
            }
        }
        else
        {
            LOGE ( 0, "UclILFd_WriteRxFd", " Invoked with FID %d has Invalid QID %d", fid, pFdAttr->mRxQueueId );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd_WriteRxFd", " Invoked with Invalid FID %d", fid );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdGetAttr ( SUclFileDesc_t *fdList, ucl_fd_t fid, SUclFileDescAttr_t *pAttr )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueueAttr_t *pFdAttr;

    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        pFdAttr = &pCfg->mpFdAttrList[fid];
        pAttr->mChnIndex = pFdAttr->mAttr.mChnIndex;
        pAttr->mOFlags = pFdAttr->mAttr.mOFlags;
        if( pFdAttr->mAttr.mChnIndex != INVALID_CH_INDEX )
        {
        	Ret = UCL_E_OK;
        }
    }
    else
    {
        LOGE ( 0, "UclFd_GetFdAttr", " Invoked with Invalid FID %d", fid );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdGetRxFdList ( SUclFileDesc_t *fdList, uint32 chnIndex, ucl_fd_t *pData, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueueAttr_t *pFdAttr;
    uint32 i;
    uint16 writeIdx = 0;

    if ( ( pData != NULL ) && ( *pSize > 0u ) )
    {
        for ( i = 0; i < pCfg->mMaxFds; i++ )
        {
            pFdAttr = &pCfg->mpFdAttrList[i];

            if ( ( pFdAttr->mAttr.mChnIndex == chnIndex ) && ( ( CHECK_FLAG_STATUS ( pFdAttr->mAttr.mOFlags, ( UCL_O_RDONLY | UCL_O_RDWR ) ) > 0u ) && ( writeIdx < *pSize ) ) )
            {
                pData[writeIdx] = ( ucl_fd_t ) i;
                writeIdx++;

            }
        }

        if ( writeIdx > 0u )
        {
            *pSize = writeIdx;
            Ret = UCL_E_OK;
        }
    }
    else
    {
        LOGE ( 0, "UclFd_GetActiveRxFds", " Invoked with Invalid size for ChIdx ", chnIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdGetActiveTxFds ( SUclFileDesc_t *fdList, ucl_fd_t *txFdList, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueueAttr_t *pFdAttr;
    uint16 i, j = 0;

    if ( ( txFdList != NULL ) && ( pSize != NULL ) && ( *pSize > 0u ) )
    {
        for ( i = 0; i < pCfg->mMaxFds; i++ )
        {
            pFdAttr = &pCfg->mpFdAttrList[i];

            if ( ( ( CHECK_FLAG_STATUS ( pFdAttr->mAttr.mOFlags, ( UCL_O_WRONLY | UCL_O_RDWR ) ) > 0u ) && ( j < *pSize ) ) )
            {
                txFdList[j] = ( ucl_fd_t ) i;
                j++;
                Ret = UCL_E_OK;
            }
        }

        if ( UCL_E_OK == Ret )
        {
            *pSize = j;
        }
    }
    else
    {
        LOGE ( 0, "UclFd_GetActiveTxFds", "%s", " Invoked with Invalid Args " );
    }

    return Ret;
}

static Ucl_ReturnType UclILStream_Impl_FdGetQueue ( SUclFileDescCfg_t *pCfg, uint16 *qIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescQueue_t *pFdQ;
    uint16 i;

    for ( i = 0; i < pCfg->mMaxQs; i++ )
    {
        pFdQ = &pCfg->mpFdQueueList->mpQueueList[i];

        if ( pFdQ->isAvailable == TRUE )
        {
            *qIndex = i;
            pFdQ->isAvailable = FALSE;
            Ret = UCL_E_OK;
            break;
        }
    }

    if ( UCL_E_NOK == Ret )
    {
        Ret = UCL_E_FD_Q_EMPTY;
        LOGE ( 0, "UclILFd", "%s", "In-Sufficient FD Queue." );
    }

    return Ret;
}

static Ucl_ReturnType UclILStream_Impl_FdReleaseQueue ( SUclFileDescCfg_t *pCfg, uint16 qIndex )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescQueue_t *pFdQ;

    if ( qIndex < pCfg->mMaxQs )
    {
        pFdQ = &pCfg->mpFdQueueList->mpQueueList[qIndex];

        if ( FALSE == pFdQ->isAvailable )
        {
            pFdQ->isAvailable = TRUE;
            Ret = UCL_E_OK;
        }
        else
        {
            LOGE ( 0, "UclILFd", "UCL FD Queue Release Invoked for In-Active Queue %d", qIndex );
        }
    }
    else
    {
        LOGE ( 0, "UclILFd", "UCL FD Queue Release Invoked for Invalid QID %d", qIndex );
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdFlushTxq ( SUclFileDesc_t *fdList, ucl_fd_t fid )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Rx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mTxQueueId ) && ( pFdAttr->mTxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mTxQueueId];

            if ( pFdQ->isAvailable == FALSE )
            {
                //Read from Rx FD Queue
                Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

                if ( UCL_E_OK == Ret )
                {
                    Ret = UclCmnRingBuffer_Reset ( & ( pFdQ->mFileDescQueue ) );
                    ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );
                }
            }
        }
    }

    return Ret;
}

Ucl_ReturnType UclILStream_Impl_FdFlushRxq ( SUclFileDesc_t *fdList, ucl_fd_t fid )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    SUclFileDescCfg_t *pCfg = fdList->mpCfg;
    SUclFileDescQueue_t *pFdQ;
    SUclFileDescQueueAttr_t *pFdAttr;

    // Check if FID is Valid
    if ( ( fid >= 0 ) && ( ( uint16 ) fid < pCfg->mMaxFds ) )
    {
        //Get the qIndex
        pFdAttr = &pCfg->mpFdAttrList[fid];

        //Check if this FD is Rx Capable
        if ( ( INVALID_FDQ_INDEX != pFdAttr->mRxQueueId ) && ( pFdAttr->mRxQueueId < pCfg->mMaxQs ) )
        {
            pFdQ = &pCfg->mpFdQueueList->mpQueueList[pFdAttr->mRxQueueId];

            if ( pFdQ->isAvailable == FALSE )
            {
                //Read from Rx FD Queue
                Ret = UclALOs_MutexLock ( 0, pFdQ->queueLockMutexId );

                if ( UCL_E_OK == Ret )
                {
                    Ret = UclCmnRingBuffer_Reset ( & ( pFdQ->mFileDescQueue ) );
                    ( void ) UclALOs_MutexUnlock ( 0, pFdQ->queueLockMutexId );
                }
            }
        }
    }

    return Ret;
}

