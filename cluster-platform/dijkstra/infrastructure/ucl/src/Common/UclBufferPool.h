#ifndef UCL_BUFFER_POOL_H
#define UCL_BUFFER_POOL_H

#include "Ucl_Types.h"

typedef struct
{
    uint16 mSize;
	uint16 mDataSize;
    uint8 *mpData;
    uint8 mRefCount;
} SUclBufferPoolItem_t;

typedef struct
{
    SUclBufferPoolItem_t *mpBPList;
    uint16 mNumBP;
} SUclBufferPoolCfg_t;

typedef struct
{
    SUclBufferPoolCfg_t *mpCfg;
    uint32 mMutex;
} SUclBufferPool_t;

sint32 UclBufferPool_Initialize( SUclBufferPool_t *pBP, SUclBufferPoolCfg_t *pBPCfg );
void UclBufferPool_Shutdown( SUclBufferPool_t *pBP );
sint32 UclBufferPool_Get( SUclBufferPool_t *pBP, uint16 size );
sint32 UclBufferPool_AddRef( SUclBufferPool_t *pBP, sint32 id );
sint32 UclBufferPool_Put( SUclBufferPool_t *pBP, sint32 id );
sint32 UclBufferPool_Write( SUclBufferPool_t *pBP, sint32 id, uint8 *pData, uint16 size );
sint32 UclBufferPool_Read( SUclBufferPool_t *pBP, sint32 id, uint8 *pData, uint16 size );

#endif //UCL_BUFFER_POOL_H
