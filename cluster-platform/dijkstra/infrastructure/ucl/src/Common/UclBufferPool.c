#include "UclBufferPool.h"
#include "UclALOs.h"
#include "UclALDebug.h"

sint32 UclBufferPool_Initialize( SUclBufferPool_t *pBP, SUclBufferPoolCfg_t *pBPCfg )
{
    sint32 ret = UCL_E_OK;
    
    pBP->mpCfg = pBPCfg;

    ret = UclALOs_MutexCreate( 0, &pBP->mMutex );

    if (UCL_E_OK != ret)
    {
        ret = UCL_E_NOK;
        LOGE(0, "UclBufferPool", "%s", " Initialization Failed ");
    }

    return ret;
}

void UclBufferPool_Shutdown( SUclBufferPool_t *pBP )
{
    sint32 idx = 0;

    for (idx = 0; idx < (sint32)pBP->mpCfg->mNumBP; idx++)
    {
        pBP->mpCfg->mpBPList[idx].mRefCount = 0u;
        pBP->mpCfg->mpBPList[idx].mDataSize = 0u;
    }

    pBP->mpCfg = NULL;

    (void) UclALOs_MutexDestroy( 0, pBP->mMutex );
}

sint32 UclBufferPool_Get( SUclBufferPool_t *pBP, uint16 size )
{
    sint32 ret;
    sint32 idx;

    ret = UclALOs_MutexLock( 0, pBP->mMutex );
    if (UCL_E_OK == ret)
    {
        ret = UCL_E_BUFFER_FULL;
        for (idx = 0; idx < (sint32)pBP->mpCfg->mNumBP; idx++)
        {
            if ((size <= pBP->mpCfg->mpBPList[idx].mSize) && (0u == pBP->mpCfg->mpBPList[idx].mRefCount))
            {
                pBP->mpCfg->mpBPList[idx].mRefCount++;
                ret = idx;
                break;
            }
        }
        (void) UclALOs_MutexUnlock( 0, pBP->mMutex );

        if (UCL_E_BUFFER_FULL == ret)
        {
            LOGE(0, "UclBufferPool_Get", "%s", " No More Free Buffers Available. Increase the Buffer Pool Count ");
        }
    }
    return ret;
}

sint32 UclBufferPool_AddRef( SUclBufferPool_t *pBP, sint32 id )
{
    sint32 ret;

    ret = UclALOs_MutexLock( 0, pBP->mMutex );
    if (UCL_E_OK == ret)
    {
		ret= UCL_E_NOK;
        if (id < (sint32)pBP->mpCfg->mNumBP)
        {
            pBP->mpCfg->mpBPList[id].mRefCount++;
            ret = UCL_E_OK;
        }
        (void) UclALOs_MutexUnlock( 0, pBP->mMutex );
    }
    return ret;
}

sint32 UclBufferPool_Put( SUclBufferPool_t *pBP, sint32 id )
{
    sint32 ret;

    ret = UclALOs_MutexLock( 0, pBP->mMutex );
    if (UCL_E_OK == ret)
    {
		ret=UCL_E_NOK;
        if ((id < (sint32)pBP->mpCfg->mNumBP) && (pBP->mpCfg->mpBPList[id].mRefCount > 0u))
        {
            pBP->mpCfg->mpBPList[id].mRefCount--;
            ret = UCL_E_OK;
        }
		else
		{
		     LOGE(0, "UclBufferPool", "Attempt to close Unused Buffer ## Buffer Id :%d  Ref Count :%d",
		                                                       id ,pBP->mpCfg->mpBPList[id].mRefCount );
		}
		
        (void) UclALOs_MutexUnlock( 0, pBP->mMutex );
    }
    return ret;
}

sint32 UclBufferPool_Write( SUclBufferPool_t *pBP, sint32 id, uint8 *pData, uint16 size )
{
    sint32 ret;

    ret = UclALOs_MutexLock( 0, pBP->mMutex );
    if (UCL_E_OK == ret)
    {
    	ret = UCL_E_NOK;
        if ((id < (sint32)pBP->mpCfg->mNumBP) && (pData != NULL )&& (0u < pBP->mpCfg->mpBPList[id].mRefCount) &&
                        (size <= pBP->mpCfg->mpBPList[id].mSize))
        {
            ret = UclALOs_Memcpy( 0, pBP->mpCfg->mpBPList[id].mpData, pData, size );
			if (UCL_E_OK == ret)
			{
				pBP->mpCfg->mpBPList[id].mDataSize = size;
				ret = (sint32)size;
			}
		}

        (void) UclALOs_MutexUnlock( 0, pBP->mMutex );
    }

    if (ret != (sint32)size)
    {
        LOGE(0, "UclBufferPool_Write", " Failed - %d ", ret);
    }

    return ret;
}

sint32 UclBufferPool_Read( SUclBufferPool_t *pBP, sint32 id, uint8 *pData, uint16 size )
{
    sint32 ret;

    ret = UclALOs_MutexLock( 0, pBP->mMutex );
    if (UCL_E_OK == ret)
    {
    	ret = UCL_E_NOK;
        if ((id < (sint32)pBP->mpCfg->mNumBP) && (pData != NULL )&&
        (0u < pBP->mpCfg->mpBPList[id].mRefCount) && (size >= pBP->mpCfg->mpBPList[id].mDataSize))
        {
            ret = UclALOs_Memcpy( 0, pData, pBP->mpCfg->mpBPList[id].mpData, pBP->mpCfg->mpBPList[id].mDataSize );
            if (UCL_E_OK == ret)
            {
                ret = (sint32)pBP->mpCfg->mpBPList[id].mDataSize;
            }
        }

        // if Read buffer is set to Null, Update the size of the buffer alone
        else if ((id < (sint32)pBP->mpCfg->mNumBP) && (pData == NULL) &&
                        (0u < pBP->mpCfg->mpBPList[id].mRefCount) && (size == 0u))
        {
            ret = (sint32)pBP->mpCfg->mpBPList[id].mDataSize;

        }
        else
        {
            ret =  UCL_E_NOK;
        }
        (void) UclALOs_MutexUnlock( 0, pBP->mMutex );
    }
    return ret;
}

