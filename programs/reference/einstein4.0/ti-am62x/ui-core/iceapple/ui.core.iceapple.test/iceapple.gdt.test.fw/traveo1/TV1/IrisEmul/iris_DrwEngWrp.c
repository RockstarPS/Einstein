


#include <stdio.h>
#include "mml_gdc_driver_api.h"

#include "mm_types.h"
#include "sm_util.h"
#include "ut_compatibility.h"

#include "mml_gdc_sysinit.h"
#include "mml_gdc_config.h"

#include "iris_eng.h"
#include "iris_DrwEng.h"

#include <malloc.h>
#include <memory.h>
#include <assert.h>

#include "pe_matrix.h"
#include "ut_memman.h"

 char __ghsbegin_FT2HEAP[2000000];
 char __ghsend_FT2HEAP[1];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Drawing engine

 MM_GDC_EXTERN MM_ERROR mmlGdcDeSetAlphaBuffer(MM_U32 width,
                                              MM_U32 height,
                                              MM_U32 bpp,
                                              void* bufferAddress,
                                              MM_U32 bufferSize)
{
    // TODO:

    return MML_OK;
}                                              


MM_GDC_EXTERN MM_ERROR mmlGdcDeDraw(MML_GDC_PE_CONTEXT pectx,
                                     MM_FLOAT x,
                                     MM_FLOAT y)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    
    DrwEng_Draw(pCtx, x, y);
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcDeGetAttribute(MML_GDC_PE_CONTEXT pectx,
                                             MML_GDC_DE_ATTR eName,
                                             MM_U32 *pValue )
{
    assert(0);
    return MML_OK;
}


MM_GDC_EXTERN MM_ERROR mmlGdcDeAppendPathData(MML_GDC_PE_CONTEXT pectx,
                                               MM_U32 numSegments,
                                               const MM_U08 *pPathSegments,
                                               const void *pPathData)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    DrwEng_PrepareAddPoint(pCtx, numSegments, pPathSegments, pPathData);

    return MML_OK;
}


//Set an attribute for Draw Engine operations. Possible values:
//MML_GDC_DE_DATA_FORMAT_S16_6 Default: 32 bit Integer representing a signed fixed point s26.6 notation.
//MML_GDC_DE_DATA_FORMAT_FLOAT 32 bit float.
//MML_GDC_DE_DATA_FORMAT_S32 32 bit signed Integer.
//MML_GDC_DE_DATA_FORMAT_S16 16 bit signed Integer.
//MML_GDC_DE_DATA_FORMAT_S08 8 bit signed Integer.
MM_GDC_EXTERN MM_ERROR mmlGdcDeSetAttribute(MML_GDC_PE_CONTEXT pectx,
                                             MML_GDC_DE_ATTR eName,
                                             MM_U32 value )
{
    if(MML_GDC_DE_ATTR_DATA_FORMAT !=eName)
    {
        assert(0);
    }
    else
    {
        IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
        pCtx->epPathDataSize = (tMML_GDC_DE_DATA_FORMAT)value;
    }
    return MML_OK;
}



MM_GDC_EXTERN MM_ERROR mmlGdcDeSetPathBuffer(MML_GDC_PE_CONTEXT pectx,
                                              void* address,
                                              MM_U32 size)
{
    // TODO:
    return MML_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Misc
void mmlOsLibcFree(void * _Memory)
{
    free(_Memory);
}
void *mmlOsLibcMalloc(size_t _Size)
{
    return malloc(_Size);
}

void * mmlGdcVideoAlloc( MM_U32 size, MM_U32 alignment, MM_ADDR *pAddr )
{
    void* pBuffer = malloc(size);
    return pBuffer;
}

void mmlGdcVideoFree( void* addr )
{
    // todo: the free should be done later when the buffer is already in cache
    //free(addr);
}

MM_ERROR mmlGdcSyncCreate(MM_U32 uCnt, MML_GDC_SYNC* pSyncObjects)
{
    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcSyncDelete(MM_U32 uCnt, MML_GDC_SYNC* pSyncObjects)
{
    return MML_OK;
}


MM_ERROR mmlGdcSyncWait(MML_GDC_SYNC sync, MM_S32 timeout)
{
    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcSysSetInstructionBuffer(void* address, MM_U32 size)
{
    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcSysInitializeDriver(MML_GDC_SYSINIT_INFO *pDriverInitInfo)
{
    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcSysUninitializeDriver(void)
{
//    assert(0);
    return MML_OK;
}


MM_ERROR mmlGdcConfigGetAttribute( MML_GDC_CONFIG_ATTR pname, MM_U32 *pParam )
{

    switch (pname)
    {
    case MML_GDC_CONFIG_ATTR_CURRENT_INSTRUCTION_BUFFER:
        // temporary skip the mmlGdcPeSync and mmlGdcSyncWait, which are currently empty
        *pParam=2048;
        break;


    case MML_GDC_CONFIG_ATTR_MAJOR_VERSION:
    case MML_GDC_CONFIG_ATTR_MINOR_VERSION:
    
    case MML_GDC_CONFIG_ATTR_BUILD_VERSION:
    case MML_GDC_CONFIG_ATTR_BUILD_TYPE:
    case MML_GDC_CONFIG_ATTR_IPIDENTIFIER:
    case MML_GDC_CONFIG_ATTR_DISPLAY_NOBLOCK:
    case MML_GDC_CONFIG_ATTR_MIN_INSTRUCTION_BUFFER:
    default:
        // TODO
        break;
    }
    
    return MML_OK;
}

void mmdGdcInterruptHandler(void)
{
    assert(0);
}

MM_ERROR utMmanReset(void)
{
    return MML_OK;
}

MML_GDC_2D_MATRIX_API void utMat3x2Multiply(Mat3x2 dst, const Mat3x2 src1, const Mat3x2 src2){}
MML_GDC_2D_MATRIX_API void utMat3x2LoadIdentity(Mat3x2 m){}
MML_GDC_2D_MATRIX_API void utMat3x2Copy(Mat3x2 dst, const Mat3x2 src){}
MML_GDC_2D_MATRIX_API void utMat3x2Scale(Mat3x2 m, MM_FLOAT x, MM_FLOAT y){}
MML_GDC_2D_MATRIX_API void utMat3x2Translate(Mat3x2 m, MM_FLOAT x, MM_FLOAT y){}

