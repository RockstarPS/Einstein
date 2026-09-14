


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

CYGFX_EXTERN CYGFX_ERROR CyGfx_DeSetAlphaBuffer(CYGFX_U32 width,
  CYGFX_U32 height,
  CYGFX_U32 bpp,
  void* bufferAddress,
  CYGFX_U32 bufferSize)
{
  // TODO:

  return CYGFX_OK;
}


CYGFX_EXTERN CYGFX_ERROR CyGfx_DeDraw(CYGFX_BE_CONTEXT beCtx,
  CYGFX_FLOAT      x,
  CYGFX_FLOAT      y)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(beCtx);

  DrwEng_Draw(pCtx, x, y);
  return CYGFX_OK;
}

CYGFX_EXTERN CYGFX_ERROR CyGfx_DeGetAttribute(CYGFX_BE_CONTEXT beCtx,
  CYGFX_DE_ATTR    eName,
  CYGFX_U32* pValue)
{
  assert(0);
  return CYGFX_OK;
}


CYGFX_EXTERN CYGFX_ERROR CyGfx_DeAppendPathData(CYGFX_BE_CONTEXT beCtx,
  CYGFX_U32        numSegments,
  const CYGFX_U08* pPathSegments,
  const void* pPathData)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(beCtx);

  DrwEng_PrepareAddPoint(pCtx, numSegments, pPathSegments, pPathData);

  return CYGFX_OK;
}


//Set an attribute for Draw Engine operations. Possible values:
//MML_GDC_DE_DATA_FORMAT_S16_6 Default: 32 bit Integer representing a signed fixed point s26.6 notation.
//MML_GDC_DE_DATA_FORMAT_FLOAT 32 bit float.
//MML_GDC_DE_DATA_FORMAT_S32 32 bit signed Integer.
//MML_GDC_DE_DATA_FORMAT_S16 16 bit signed Integer.
//MML_GDC_DE_DATA_FORMAT_S08 8 bit signed Integer.
CYGFX_EXTERN CYGFX_ERROR CyGfx_DeSetAttribute(CYGFX_BE_CONTEXT beCtx,
  CYGFX_DE_ATTR    eName,
  CYGFX_U32        value)
{
  if (MML_GDC_DE_ATTR_DATA_FORMAT != eName)
  {
    assert(0);
  }
  else
  {
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(beCtx);
    pCtx->epPathDataSize = (tMML_GDC_DE_DATA_FORMAT)value;
  }
  return CYGFX_OK;
}



CYGFX_EXTERN CYGFX_ERROR CyGfx_DeSetPathBuffer(CYGFX_BE_CONTEXT beCtx,
  void* address,
  CYGFX_U32        size)
{
  // TODO:
  return CYGFX_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Misc
void utOsLibcFree(void* _Memory)
{
  free(_Memory);
}
void* utOsLibcMalloc(size_t _Size)
{
  return malloc(_Size);
}

void* utVideoAlloc(CYGFX_U32 size, CYGFX_U32 alignment, CYGFX_ADDR* pAddr)
{
  void* pBuffer = malloc(size);
  return pBuffer;
}

void utVideoFree(void* addr)
{
  // todo: the free should be done later when the buffer is already in cache
  //free(addr);
}

/*Required to implement*//*Invoked from hmi_gfx_mgr02_initialize*/
CYGFX_ERROR utSyncCreate(CYGFX_U32 uCnt, CYGFX_SYNC* pSyncObjects)
{
  // TODO:
  return CYGFX_OK;
}

CYGFX_ERROR utSyncDelete(CYGFX_U32 uCnt, CYGFX_SYNC* pSyncObjects)
{
  return CYGFX_OK;
}
CYGFX_EXTERN CYGFX_ERROR CyGfx_DispGetVSync(CYGFX_DISP display,
  CYGFX_SYNC sync,
  CYGFX_S32  vsyncCnt)
{
  return CYGFX_OK;
}
CYGFX_ERROR CyGfx_SyncWaitSync(CYGFX_SYNC sync,
  CYGFX_S32  timeout)
{
  // TODO:
  return CYGFX_OK;
}

/* Already available in mml_gdc_sysinit.h */
#if 0
MM_ERROR mmlGdcSysSetInstructionBuffer(void* address, MM_U32 size)
{
  // TODO:
  return MML_OK;
}

MM_ERROR mmlGdcSysInitializeDriver(MML_GDC_SYSINIT_INFO* pDriverInitInfo)
{
  // TODO:
  return MML_OK;
}
#endif

MM_ERROR mmlGdcSysUninitializeDriver(void)
{
  //    assert(0);
  return MML_OK;
}


CYGFX_ERROR CyGfx_BeGetAttribute(CYGFX_BE_CONTEXT  beCtx,
  CYGFX_BE_CTX_ATTR pname,
  CYGFX_U32* pParam)
{
  switch (pname)
  {
  case MML_GDC_CONFIG_ATTR_CURRENT_INSTRUCTION_BUFFER:
    // temporary skip the mmlGdcPeSync and mmlGdcSyncWait, which are currently empty
    *pParam = 2048;
    break;


  case CYGFX_CONFIG_ATTR_MAJOR_VERSION:
  case CYGFX_CONFIG_ATTR_MINOR_VERSION:

  case CYGFX_CONFIG_ATTR_BUILD_VERSION:
  case CYGFX_CONFIG_ATTR_BUILD_TYPE:
  case CYGFX_CONFIG_ATTR_IPIDENTIFIER:
  case CYGFX_CONFIG_ATTR_DISPLAY_NOBLOCK:
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

UT_2D_MATRIX_API void utMat3x2Multiply(Mat3x2 dst, const Mat3x2 src1, const Mat3x2 src2) {}
UT_2D_MATRIX_API void utMat3x2LoadIdentity(Mat3x2 m) {}
UT_2D_MATRIX_API void utMat3x2Copy(Mat3x2 dst, const Mat3x2 src) {}
UT_2D_MATRIX_API void utMat3x2Scale(Mat3x2 m, MM_FLOAT x, MM_FLOAT y) {}
UT_2D_MATRIX_API void utMat3x2Translate(Mat3x2 m, MM_FLOAT x, MM_FLOAT y) {}

