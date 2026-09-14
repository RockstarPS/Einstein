
#include <stdio.h>
#include "mml_gdc_driver_api.h"

#include "mm_types.h"
#include "sm_util.h"
#include "ut_compatibility.h"

#include "mml_gdc_sysinit.h"
#include "mml_gdc_config.h"

#include "iris_eng.h"

#include <malloc.h>
#include <memory.h>
#include <assert.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Display

MM_ERROR CyGfx_DispCommit(MML_GDC_DISPLAY display)
{
  return MML_OK;
}

MM_ERROR CyGfx_DispDitherCtrl(MML_GDC_DISPLAY display,
  MML_GDC_DISP_DITHER_ENABLE enable,
  MML_GDC_DISP_DITHER_MODE mode,
  MML_GDC_DISP_DITHER_RANGE range,
  MML_GDC_DISP_DITHER_FORMAT format)
{
  return MML_OK;
}


CYGFX_EXTERN CYGFX_ERROR CyGfx_DispOpenDisplay(const CYGFX_DISP_PROPERTIES_S* mode,
  CYGFX_DISP* display,
  CYGFX_CAP_CTX                  capCtx)
{
  IRIS2_Display* pDisplay;

  *display = (MML_GDC_DISPLAY)malloc(sizeof(MML_GDC_DISPLAY));
  pDisplay = IrisEng_CreateDsp(*display);

  pDisplay->width = mode->timing.Hact;
  pDisplay->height = mode->timing.Vact;
  pDisplay->pWindowList = 0;

  return MML_OK;
}

MM_ERROR CyGfx_DispSetAttribute(MML_GDC_DISPLAY display,
  MML_GDC_DISP_ATTR pname,
  CYGFX_U32 param)
{
  //assert(pname == MML_GDC_DISP_ATTR_GAMMA || pname == MML_GDC_DISP_ATTR_BACKGROUND_COLOR);
  return MML_OK;
}

MM_ERROR CyGfx_DispCloseDisplay(MML_GDC_DISPLAY display)
{
  assert(0);
  return MML_OK;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Window
MM_ERROR CyGfx_WinGetSync(MML_GDC_DISP_WINDOW win,
  MML_GDC_SYNC sync)
{
  // TODO:
  return MML_OK;
}


MM_ERROR CyGfx_WinWaitSync(MML_GDC_DISP_WINDOW win,
  MML_GDC_SYNC sync)
{
  // TODO:
  return MML_OK;
}

MM_ERROR CyGfx_DispGetSync(MML_GDC_DISPLAY display, MML_GDC_SYNC sync)           /* PRQA S 3673 */   /* <msr id=10> */
{
  // TODO:
  return MML_OK;
}

MM_ERROR CyGfx_DispWaitSync(MML_GDC_DISPLAY display, MML_GDC_SYNC sync)            /* PRQA S 3673 */   /* <msr id=10> */
{
  // TODO:
  return MML_OK;
}

/*NOT AVAILABLE IN TRAVEO2 DRIVER*/
MM_ERROR CyGfx_WinGetAttribute(MML_GDC_DISP_WINDOW win,
  MML_GDC_DISP_WIN_ATTR pname,
  CYGFX_U32* pParam)
{
  IRIS2_Window* pWindow = IrisEng_CreateWnd(win);

  switch (pname)
  {
  case MML_GDC_DISP_WIN_ATTR_TOPLEFT_X:
    *pParam = pWindow->x;
    break;
  case MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y:
    *pParam = pWindow->y;
    break;
  case MML_GDC_DISP_WIN_ATTR_WIDTH:
    *pParam = pWindow->width;
    break;
  case MML_GDC_DISP_WIN_ATTR_HEIGHT:
    *pParam = pWindow->height;
    break;
  case MML_GDC_DISP_WIN_ATTR_TILE_MODE:
    *pParam = pWindow->tileMode;
    break;
  case MML_GDC_DISP_WIN_ATTR_COLOR:
    *pParam = pWindow->color;
    break;
  case MML_GDC_DISP_WIN_ATTR_LAYER_ID:
    *pParam = pWindow->layer;
    break;
  case MML_GDC_DISP_WIN_ATTR_SUB_LAYER_ID:
    *pParam = pWindow->subLayer;
    break;
  case MML_GDC_DISP_WIN_ATTR_FEATURE:
    *pParam = pWindow->features;
    break;
  case MML_GDC_DISP_WIN_ATTR_DISABLE:
    *pParam = pWindow->isDisabled;
    break;
  case MML_GDC_DISP_WIN_ATTR_SCREEN:
  case MML_GDC_DISP_WIN_ATTR_SWAP_INTERVAL:
  case MML_GDC_DISP_WIN_ATTR_MAX_BUFFER:
  case MML_GDC_DISP_WIN_ATTR_FILTER:
  case MML_GDC_DISP_WIN_ATTR_GAMMA:
  default:
    assert(0);
    return MML_OK;
  }

  return MML_OK;
}

MM_ERROR CyGfx_WinDestroy(MML_GDC_DISP_WINDOW win)
{
  IRIS2_Window* pWindow;
  IRIS2_Window** pNext;

  pWindow = IrisEng_CreateWnd(win);
  pNext = &(pWindow->pDisplay->pWindowList);

  while (*pNext != 0)
  {
    if (*pNext == pWindow)
    {
      // already inside the list
      break;
    }

    pNext = &((*pNext)->pNext);
  }

  if (*pNext != 0)
  {
    *pNext = pWindow->pNext;
  }
  IrisEng_DestroyWnd(win);
  free(win);

  return MML_OK;
}

MM_ERROR CyGfx_WinSetSurface(MML_GDC_DISP_WINDOW win,
  CYGFX_U32 target,
  MML_GDC_SURFACE surf)
{
  IRIS2_Window* pWindow = IrisEng_CreateWnd(win);
  pWindow->pSurface = IrisEng_CreateSurf(surf);
  return MML_OK;
}


MM_ERROR CyGfx_WinSetAttribute(MML_GDC_DISP_WINDOW win,
  MML_GDC_DISP_WIN_ATTR pname,
  CYGFX_U32 param)
{
  IRIS2_Window* pWindow = IrisEng_CreateWnd(win);

  switch (pname)
  {
  case MML_GDC_DISP_WIN_ATTR_TOPLEFT_X:
    pWindow->x = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y:
    pWindow->y = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_WIDTH:
    pWindow->width = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_HEIGHT:
    pWindow->height = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_TILE_MODE:
    pWindow->tileMode = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_COLOR:
    pWindow->color = param;
    break;
  case MML_GDC_DISP_WIN_ATTR_DISABLE:
    pWindow->isDisabled = param;
    break;

  case MML_GDC_DISP_WIN_ATTR_SCREEN:
  case MML_GDC_DISP_WIN_ATTR_SWAP_INTERVAL:
  case MML_GDC_DISP_WIN_ATTR_MAX_BUFFER:
  case MML_GDC_DISP_WIN_ATTR_FILTER:
  case MML_GDC_DISP_WIN_ATTR_FEATURE:
  case MML_GDC_DISP_WIN_ATTR_GAMMA:
  case MML_GDC_DISP_WIN_ATTR_LAYER_ID:
  case MML_GDC_DISP_WIN_ATTR_SUB_LAYER_ID:
  default:
    return MML_OK;
  }

  return MML_OK;
}


MM_ERROR CyGfx_WinSetBlendMode(MML_GDC_DISP_WINDOW win,
  CYGFX_U32 blend_mode)
{
  IRIS2_Window* pWindow = IrisEng_CreateWnd(win);
  pWindow->blendMode = blend_mode;

  return MML_OK;
}


CYGFX_ERROR CyGfx_DispWinCreate(CYGFX_DISP display,
  const CYGFX_DISP_WINDOW_PROPERTIES_S* properties,
  CYGFX_WINDOW* pWin)
{
  IRIS2_Window** pNext;
  IRIS2_Window* pWindow;
  IRIS2_Display* pDisplay = IrisEng_CreateDsp(display);
  *pWin = (MML_GDC_DISP_WINDOW)malloc(sizeof(MML_GDC_DISP_WINDOW));
  pWindow = IrisEng_CreateWnd(*pWin);

  pWindow->pDisplay = pDisplay;
  pWindow->layer = properties->layerId;
  pWindow->subLayer = properties->sub_layerId;
  pWindow->pNext = 0;
  pWindow->pSurface = 0;
  pWindow->features = properties->features;
  pWindow->blendMode = 0;

  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TOPLEFT_X, properties->topLeftX);
  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y, properties->topLeftY);
  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_WIDTH, properties->width);
  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_HEIGHT, properties->height);
  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TILE_MODE, MML_GDC_DISP_TILE_MODE_ZERO);
  CyGfx_WinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_DISABLE, 0); // by default its 0

  // insert the window inside its display list (its sorted by layer)
  pNext = &(pWindow->pDisplay->pWindowList);
  while (*pNext != 0)
  {
    if (*pNext == pWindow)
    {
      // already inside the list
      return MML_OK;
    }

    if ((*pNext)->layer > pWindow->layer ||
      ((*pNext)->layer == pWindow->layer && (*pNext)->subLayer > pWindow->subLayer))
    {
      break;
    }

    pNext = &((*pNext)->pNext);
  }
  pWindow->pNext = *pNext;
  *pNext = pWindow;

  return MML_OK;
}

MM_ERROR CyGfx_WinCommit(MML_GDC_DISP_WINDOW win)
{
  return MML_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Surface

MM_ERROR utSmGenSurfaceObjects(CYGFX_U32 uCnt, MML_GDC_SURFACE* pSurfaces)
{
  IRIS2_Surface* pSurf;
  while (uCnt > 0)
  {
    uCnt--;

    pSurfaces[uCnt] = (MML_GDC_SURFACE)malloc(sizeof(MML_GDC_SURFACE));

    pSurf = IrisEng_CreateSurf(pSurfaces[uCnt]);
    memset(pSurf, 0, sizeof(IRIS2_Surface));

    CyGfx_SmResetSurfaceObject(pSurfaces[uCnt]);
  }
  return MML_OK;
}

MM_ERROR CyGfx_SmGetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, CYGFX_U32* puValue)
{
  IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

  switch (eName)
  {
  case MML_GDC_SURF_ATTR_WIDTH:
    *puValue = pSurface->width;
    break;
  case MML_GDC_SURF_ATTR_HEIGHT:
    *puValue = pSurface->height;
    break;
  case MML_GDC_SURF_ATTR_STRIDE:
    *puValue = pSurface->stride;
    break;
  case MML_GDC_SURF_ATTR_BASE_ADDRESS:
    *puValue = (CYGFX_U32)pSurface->pBuffer;
    break;
  case MML_GDC_SURF_ATTR_COMPRESSION_FORMAT:
    *puValue = pSurface->compression;
    break;
  case MML_GDC_SURF_ATTR_BITPERPIXEL:
    *puValue = pSurface->bitperpixel;
    break;
  case MML_GDC_SURF_ATTR_COLORBITS:
    *puValue = pSurface->colorbits;
    break;
  case MML_GDC_SURF_ATTR_COLORSHIFT:
    *puValue = pSurface->colorshift;
    break;
  case MML_GDC_SURF_ATTR_COLOR_SPACE:
    *puValue = pSurface->colorspace;
    break;
  case MML_GDC_SURF_ATTR_COLOR_FORMAT:
    *puValue = pSurface->colorformat;
    break;
  case MML_GDC_SURF_ATTR_SIZEINBYTES:
    if (pSurface->compression == MML_GDC_SURF_COMP_NON)
    {
      if (pSurface->stride != 0)
      {
        *puValue = pSurface->height * pSurface->stride;
      }
      else
      {
        *puValue = pSurface->height * ((pSurface->width * pSurface->bitperpixel + 7) / 8);
      }
    }
    else
    {
      *puValue = pSurface->sizeinbytes;
    }
    break;
  case MML_GDC_SURF_ATTR_PHYS_ADDRESS:
  case MML_GDC_SURF_ATTR_RLAD_MAXCOLORBITS:
  case MML_GDC_SURF_ATTR_SURF_FORMAT:
    return MML_OK;

    /*case MML_GDC_SURF_ATTR_CLUTBITPERPIXEL:
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORBITS:
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORSHIFT:
        break;
    case MML_GDC_SURF_ATTR_CLUTMODE:
    case MML_GDC_SURF_ATTR_CLUTCOUNT:
    case MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS:
    case MML_GDC_SURF_ATTR_CLUTBUFFER_PHYS_ADDRESS:*/
  }
  return MML_OK;
}

MM_ERROR CyGfx_SmSetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, CYGFX_U32 uValue)
{
  IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

  switch (eName)
  {
  case MML_GDC_SURF_ATTR_WIDTH:
    pSurface->width = uValue;
    pSurface->DispSize = (pSurface->width) * (pSurface->height);
    break;
  case MML_GDC_SURF_ATTR_HEIGHT:
    pSurface->height = uValue;
    pSurface->DispSize = (pSurface->width) * (pSurface->height);
    break;
  case MML_GDC_SURF_ATTR_SURF_FORMAT:
  {
    CYGFX_U32 bitsperpixels = 0;
    CYGFX_U32 colorbits = 0;
    CYGFX_U32 colorshift = 0;
    CYGFX_U32 colorformat = MML_GDC_SURF_COLOR_FORMAT_RGBA;
    CYGFX_U32 colorspace = MML_GDC_SURF_COLOR_SPACE_RGB;
    pSurface->ClutMode = eNoClut;
    pSurface->imgformat = uValue;

    switch (uValue)
    {
    case MML_GDC_SURF_FORMAT_R8G8B8A8:
      bitsperpixels = 32;
      colorbits = 0x08080808;
      colorshift = 0x18100800;
      break;
    case MML_GDC_SURF_FORMAT_A8R8G8B8:
      bitsperpixels = 32;
      colorbits = 0x08080808;
      colorshift = 0x10080018;
      break;
    case MML_GDC_SURF_FORMAT_R5G6B5:
      bitsperpixels = 16;
      colorbits = 0x05060500;
      colorshift = 0x0B050000;
      break;
    case MML_GDC_SURF_FORMAT_R6G6B6:
      bitsperpixels = 18;
      colorbits = 0x06060600;
      colorshift = 0x0C060000;
      break;
    case MML_GDC_SURF_FORMAT_R8G8B8:
      bitsperpixels = 24;
      colorbits = 0x08080800;
      colorshift = 0x10080000;
      break;
    case MML_GDC_SURF_FORMAT_A8:
      bitsperpixels = 8;
      colorbits = 0x00000008;
      colorshift = 0x00000000;
      break;
    case MML_GDC_SURF_FORMAT_R4G4B4A4:
      bitsperpixels = 16;
      colorbits = 0x04040404;
      colorshift = 0x0C080400;
      break;
    case MML_GDC_SURF_FORMAT_A4R4G4B4:
      bitsperpixels = 16;
      colorbits = 0x04040404;
      colorshift = 0x0804000C;
      break;
    case MML_GDC_SURF_FORMAT_A8B8G8R8:
      bitsperpixels = 32;
      colorbits = 0x08080808;
      colorshift = 0x00081018;
      break;
    case MML_GDC_SURF_FORMAT_RGB8:
      //< 8 bpp, RGB8 can be used for gray or indexed image buffers.
      // For the second use case an indexed color lookup table must be defined in the surface. 
      bitsperpixels = 8;
      colorbits = 0x08000000;
      colorshift = 0x00000000;
      break;
    case MML_GDC_SURF_FORMAT_A4:
      bitsperpixels = 4;
      colorbits = 0x00000004;
      colorshift = 0x00000000;
      break;
      /*case MML_GDC_SURF_FORMAT_A1:
        bitsperpixels = 1;
        colorbits = 0x00000001;
        colorshift = 0x00000000;
        break;*/
    case MML_GDC_SURF_FORMAT_RGB1:
    case MML_GDC_SURF_FORMAT_A1:
      bitsperpixels = 1;
      colorbits = 0x00000000;
      colorshift = 0x00000000;
      break;
    case MML_GDC_SURF_FORMAT_A8RGB8:
      bitsperpixels = 16;
      colorbits = 0x08000008;
      colorshift = 0x00000008;
      break;
    case MML_GDC_SURF_FORMAT_A1R5G5B5:
      bitsperpixels = 16;
      colorbits = 0x05050501;
      colorshift = 0x0A05000F;
      break;

    case MML_GDC_SURF_FORMAT_B8G8R8A8:
    case MML_GDC_SURF_FORMAT_R8G8B8X8:
    case MML_GDC_SURF_FORMAT_X8B8G8R8:
    case MML_GDC_SURF_FORMAT_X8R8G8B8:
    case MML_GDC_SURF_FORMAT_B8G8R8:
    case MML_GDC_SURF_FORMAT_R5G5B5A1:
    case MML_GDC_SURF_FORMAT_A1B5G5R5:
    case MML_GDC_SURF_FORMAT_B5G5R5A1:
    case MML_GDC_SURF_FORMAT_A4RGB4:
    case MML_GDC_SURF_FORMAT_A2:
    case MML_GDC_SURF_FORMAT_YVYU422:
    case MML_GDC_SURF_FORMAT_VYUY422:
    case MML_GDC_SURF_FORMAT_YUV420:
    default:
      break;
    }

    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_BITPERPIXEL,  bitsperpixels);
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_COLORBITS,    colorbits);
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_COLORSHIFT,   colorshift);
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_COLOR_FORMAT, colorformat);
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_COLOR_SPACE,  colorspace);
  }
  break;
  case MML_GDC_SURF_ATTR_STRIDE:
    pSurface->stride = uValue;
    break;
  case MML_GDC_SURF_ATTR_BASE_ADDRESS:
    pSurface->pBuffer = (unsigned char*)uValue;
    break;
  case MML_GDC_SURF_ATTR_COMPRESSION_FORMAT:
    pSurface->compression = uValue;
    break;
  case MML_GDC_SURF_ATTR_BITPERPIXEL:
    pSurface->bitperpixel = uValue;
    break;
  case MML_GDC_SURF_ATTR_COLORBITS:
    pSurface->colorbits = uValue;
    break;
  case MML_GDC_SURF_ATTR_COLORSHIFT:
    pSurface->colorshift = uValue;
    break;
  case MML_GDC_SURF_ATTR_COLOR_SPACE:
    pSurface->colorspace = uValue;
    break;
  case MML_GDC_SURF_ATTR_COLOR_FORMAT:
    pSurface->colorformat = uValue;
    break;
  case MML_GDC_SURF_ATTR_SIZEINBYTES:
    pSurface->sizeinbytes = uValue;
    break;
  case MML_GDC_SURF_ATTR_PHYS_ADDRESS:
    pSurface->pBuffer = (unsigned char*)uValue;
    break;
  case MML_GDC_SURF_ATTR_RLAD_MAXCOLORBITS:
    return MML_OK;

    /*case MML_GDC_SURF_ATTR_CLUTBITPERPIXEL:
        pSurface->ClutBitPerPixel = uValue;
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORBITS:
        pSurface->ClutColorBits = uValue;
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORSHIFT:
        pSurface->ClutColorShift = uValue;
        break;

    case MML_GDC_SURF_ATTR_CLUTMODE:
    case MML_GDC_SURF_ATTR_CLUTCOUNT:
    case MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS:
    case MML_GDC_SURF_ATTR_CLUTBUFFER_PHYS_ADDRESS:
        return MML_OK;*/
  }

  return MML_OK;
}

MM_ERROR CyGfx_SmAssignBuffer(MML_GDC_SURFACE surf, CYGFX_U32 uWidth, CYGFX_U32 uHeight, MML_GDC_SURF_FORMAT eFormat, void* pBufferAddress, CYGFX_U32 uRleWords)
{
  CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_WIDTH, uWidth);
  CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_HEIGHT, uHeight);
  CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS, (CYGFX_U32)pBufferAddress);
  CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_SURF_FORMAT, eFormat);

  if (uRleWords > 0)
  {
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_SIZEINBYTES, uRleWords);
  }
  else
  {
    CyGfx_SmSetAttribute(surf, MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, MML_GDC_SURF_COMP_NON);
  }

  // TODO:
  return MML_OK;
}

MM_ERROR CyGfx_SmResetSurfaceObject(MML_GDC_SURFACE surf)
{
  IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

  pSurface->compression = MML_GDC_SURF_COMP_NON;
  pSurface->stride = 0;
  pSurface->pBuffer = 0;
  pSurface->sizeinbytes = 0;

  return MML_OK;
}

MM_ERROR utSmDeleteSurfaceObjects(CYGFX_U32 uCnt, MML_GDC_SURFACE* pSurfaces)
{
  CYGFX_U32 i;
  for (i = 0; i < uCnt; i++)
  {
    IrisEng_DestroySurf(pSurfaces[i]);
    free(pSurfaces[i]);
  }
  return MML_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                        PE context                                                                 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MM_ERROR utPeGenContext(MML_GDC_PE_CONTEXT* pPectx)
{
  IRIS2_PECtx* pCtx;
  *pPectx = (MML_GDC_PE_CONTEXT)malloc(sizeof(MML_GDC_PE_CONTEXT));
  pCtx = IrisEng_CreatePeCtx(*pPectx);

  CyGfx_BeResetContext(*pPectx);
  return MML_OK;
}

CYGFX_ERROR CyGfx_BeResetContext(CYGFX_BE_CONTEXT beCtx)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(beCtx);
  memset(pCtx, 0, sizeof(IRIS2_PECtx));

  // default values ========
  pCtx->blend.func_blue_dst = pCtx->blend.func_green_dst = pCtx->blend.func_red_dst = CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA;
  pCtx->blend.func_blue_src = pCtx->blend.func_green_src = pCtx->blend.func_red_src = CYGFX_BE_BF_GL_SRC_ALPHA;

  pCtx->blend.func_alpha_dst = CYGFX_BE_BF_GL_ONE_MINUS_SRC_ALPHA;
  pCtx->blend.func_alpha_src = CYGFX_BE_BF_GL_ONE;

  pCtx->blend.mode_alpha = pCtx->blend.mode_blue = pCtx->blend.mode_green = pCtx->blend.mode_red = CYGFX_BE_BM_GL_FUNC_ADD;


  // ======================

  return CYGFX_OK;
}

void utPeDeleteContext(MML_GDC_PE_CONTEXT pectx)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
  free(pCtx);
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeFill(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 x, CYGFX_U32 y, CYGFX_U32 w, CYGFX_U32 h)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  IrisEng_PixEng_Fill(pCtx, x, y, w, h);

  return MML_OK;
}

/*NOT AVAILABLE IN TRAVEO2*/
MM_GDC_EXTERN MM_ERROR CyGfx_PeColor(MML_GDC_PE_CONTEXT pectx, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  pCtx->color.r = red;
  pCtx->color.g = green;
  pCtx->color.b = blue;
  pCtx->color.a = alpha;

  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeActiveArea(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target, MM_S32 x, MM_S32 y, CYGFX_U32 w, CYGFX_U32 h)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  if (target & MML_GDC_PE_MASK)
  {
    pCtx->maskRectArea.isAcive = 1;
    pCtx->maskRectArea.x = x;
    pCtx->maskRectArea.y = y;
    pCtx->maskRectArea.w = w;
    pCtx->maskRectArea.h = h;
  }

  if (target & MML_GDC_PE_SRC)
  {
    pCtx->srcRectArea.isAcive = 1;
    pCtx->srcRectArea.x = x;
    pCtx->srcRectArea.y = y;
    pCtx->srcRectArea.w = w;
    pCtx->srcRectArea.h = h;
  }

  if (target & MML_GDC_PE_DST)
  {
    pCtx->dstRectArea.isAcive = 1;
    pCtx->dstRectArea.x = x;
    pCtx->dstRectArea.y = y;
    pCtx->dstRectArea.w = w;
    pCtx->dstRectArea.h = h;
  }

  if (target & MML_GDC_PE_STORE)
  {
    pCtx->storeRectArea.isAcive = 1;
    pCtx->storeRectArea.x = x;
    pCtx->storeRectArea.y = y;
    pCtx->storeRectArea.w = w;
    pCtx->storeRectArea.h = h;
  }
  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeSelectArea(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
  pCtx->selectedArea = target;

  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeSetSurfAttribute(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target, MML_GDC_PE_SURF_ATTR pname, CYGFX_U32 param)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  switch (pname)
  {
  case MML_GDC_PE_SURF_ATTR_COLORMULTI:
    if (target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.COLORMULTI = param;
    if (target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.COLORMULTI = param;
    if (target & MML_GDC_PE_DST) pCtx->dstSurfAttr.COLORMULTI = param;
    if (target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.COLORMULTI = param;
    break;
  case MML_GDC_PE_SURF_ATTR_ALPHAMULTI:
    if (target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.ALPHAMULTI = param;
    if (target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.ALPHAMULTI = param;
    if (target & MML_GDC_PE_DST) pCtx->dstSurfAttr.ALPHAMULTI = param;
    if (target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.ALPHAMULTI = param;
    break;
  case MML_GDC_PE_SURF_ATTR_TILE_MODE:
    if (target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.TILE_MODE = param;
    if (target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.TILE_MODE = param;
    if (target & MML_GDC_PE_DST) pCtx->dstSurfAttr.TILE_MODE = param;
    if (target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.TILE_MODE = param;
    break;
  case MML_GDC_PE_SURF_ATTR_USE_CLIPPING:
    if (target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.USE_CLIPPING = param;
    if (target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.USE_CLIPPING = param;
    if (target & MML_GDC_PE_DST) pCtx->dstSurfAttr.USE_CLIPPING = param;
    if (target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.USE_CLIPPING = param;
    break;
  case MML_GDC_PE_SURF_ATTR_TRANSPARENT:
    break;
    /*ADDED BY BHARIHA1 FOR TV2 ->*/
  case CYGFX_BE_SURF_ATTR_COLOR:
    if (target & MML_GDC_PE_DST)
    {
      pCtx->surfDstColor.r = (param >> 24) & 0xff;
      pCtx->surfDstColor.g = (param >> 16) & 0xff;
      pCtx->surfDstColor.b = (param >> 8) & 0xff;
      pCtx->surfDstColor.a = (param) & 0xff;
    }
    if (target & MML_GDC_PE_SRC)
    {
      pCtx->surfSrcColor.r = (param >> 24) & 0xff;
      pCtx->surfSrcColor.g = (param >> 16) & 0xff;
      pCtx->surfSrcColor.b = (param >> 8) & 0xff;
      pCtx->surfSrcColor.a = (param) & 0xff;
    }

    if (target & MML_GDC_PE_MASK)
    {
      pCtx->surfMaskColor.r = (param >> 24) & 0xff;
      pCtx->surfMaskColor.g = (param >> 16) & 0xff;
      pCtx->surfMaskColor.b = (param >> 8) & 0xff;
      pCtx->surfMaskColor.a = (param) & 0xff;
    }

    if (target & MML_GDC_PE_STORE)
    {
      pCtx->surfStoreColor.r = (param >> 24) & 0xff;
      pCtx->surfStoreColor.g = (param >> 16) & 0xff;
      pCtx->surfStoreColor.b = (param >> 8) & 0xff;
      pCtx->surfStoreColor.a = (param) & 0xff;
    }
    break;
    /*<- ADDED BY BHARIHA1 FOR TV2*/
  default:
    assert(0);
  }
  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeBindSurface(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target, MML_GDC_SURFACE surface)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
  IRIS2_Surface* pSurface = IrisEng_CreateSurf(surface);

  if (target & MML_GDC_PE_STORE)
  {
    pCtx->pStore = pSurface;
    memset(&(pCtx->storeSurfAttr), 0, sizeof(pCtx->storeSurfAttr));
    memset(&(pCtx->storeMatrix), 0, sizeof(pCtx->storeMatrix));
    memset(&(pCtx->storeRectArea), 0, sizeof(pCtx->storeRectArea));
    memset(&(pCtx->surfStoreColor), 0, sizeof(pCtx->surfStoreColor));
  }

  if (target & MML_GDC_PE_DST)
  {
    pCtx->pDst = pSurface;
    memset(&(pCtx->dstSurfAttr), 0, sizeof(pCtx->dstSurfAttr));
    memset(&(pCtx->dstMatrix), 0, sizeof(pCtx->dstMatrix));
    memset(&(pCtx->dstRectArea), 0, sizeof(pCtx->dstRectArea));
    memset(&(pCtx->surfDstColor), 0, sizeof(pCtx->surfDstColor));
  }

  if (target & MML_GDC_PE_SRC)
  {
    pCtx->pSrc = pSurface;
    memset(&(pCtx->srcSurfAttr), 0, sizeof(pCtx->srcSurfAttr));
    memset(&(pCtx->srcMatrix), 0, sizeof(pCtx->srcMatrix));
    memset(&(pCtx->srcRectArea), 0, sizeof(pCtx->srcRectArea));
    memset(&(pCtx->surfSrcColor), 0, sizeof(pCtx->surfSrcColor));
  }

  if (target & MML_GDC_PE_MASK)
  {
    pCtx->pMask = pSurface;
    memset(&(pCtx->maskSurfAttr), 0, sizeof(pCtx->maskSurfAttr));
    memset(&(pCtx->maskMatrix), 0, sizeof(pCtx->maskMatrix));
    memset(&(pCtx->maskRectArea), 0, sizeof(pCtx->maskRectArea));
    memset(&(pCtx->surfMaskColor), 0, sizeof(pCtx->surfMaskColor));
  }

  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeSetAttribute(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_CTX_ATTR pname, CYGFX_U32 param)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  switch (pname)
  {
  case MML_GDC_PE_CTX_ATTR_DITHER_COLOR:
    pCtx->attributes.DITHER_COLOR = param;
    break;
  case MML_GDC_PE_CTX_ATTR_DITHER_ALPHA:
    pCtx->attributes.DITHER_ALPHA = param;
    break;
  case MML_GDC_PE_CTX_ATTR_DITHER_OFFSET:
    pCtx->attributes.DITHER_OFFSET = param;
    break;
  case MML_GDC_PE_CTX_ATTR_FILTER:
    pCtx->attributes.FILTER = param;
    break;
  case MML_GDC_PE_CTX_ATTR_GAMMA:
    pCtx->attributes.GAMMA = param;
    break;
  case MML_GDC_PE_ATTR_ZERO_POINT:
    pCtx->attributes.ZERO_POINT = param;
    break;

    /*ADDED BY BHARIHA1 FOR TV2 ->*/
  case CYGFX_BE_CTX_ATTR_RENDER_MODE:
    (void)CyGfx_BeFlush(pectx);
    pCtx->render_mode = param;
    break;

  case CYGFX_BE_CTX_ATTR_TASK:
    pCtx->task = param;
    break;
    /*<-ADDED BY BHARIHA1 FOR TV2*/

  }
  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeBlendFunc(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BF func_red_src, MML_GDC_PE_BF func_red_dst,
  MML_GDC_PE_BF func_green_src, MML_GDC_PE_BF func_green_dst, MML_GDC_PE_BF func_blue_src, MML_GDC_PE_BF func_blue_dst,
  MML_GDC_PE_BF func_alpha_src, MML_GDC_PE_BF func_alpha_dst)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  pCtx->blend.func_alpha_dst = func_alpha_dst;
  pCtx->blend.func_alpha_src = func_alpha_src;

  pCtx->blend.func_red_dst = func_red_dst;
  pCtx->blend.func_red_src = func_red_src;

  pCtx->blend.func_green_dst = func_green_dst;
  pCtx->blend.func_green_src = func_green_src;

  pCtx->blend.func_blue_dst = func_blue_dst;
  pCtx->blend.func_blue_src = func_blue_src;

  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeBlendMode(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BM mode_red, MML_GDC_PE_BM mode_green, MML_GDC_PE_BM mode_blue, MML_GDC_PE_BM mode_alpha)
{
  IRIS2_PECtx* pCtx;

  if (pectx == NULL) return MML_OK;

  pCtx = IrisEng_CreatePeCtx(pectx);

  pCtx->blend.mode_alpha = mode_alpha;
  pCtx->blend.mode_blue = mode_blue;
  pCtx->blend.mode_green = mode_green;
  pCtx->blend.mode_red = mode_red;

  return MML_OK;
}

/*NOT AVAILABLE IN TRAVEO2*/
MM_GDC_EXTERN MM_ERROR CyGfx_PeSurfColor(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha)
{
  IRIS2_PECtx* pCtx;

  if (pectx == NULL) return MML_OK;

  pCtx = IrisEng_CreatePeCtx(pectx);

  if (target & MML_GDC_PE_DST)
  {
    pCtx->surfDstColor.r = red;
    pCtx->surfDstColor.g = green;
    pCtx->surfDstColor.b = blue;
    pCtx->surfDstColor.a = alpha;
  }
  if (target & MML_GDC_PE_SRC)
  {
    pCtx->surfSrcColor.r = red;
    pCtx->surfSrcColor.g = green;
    pCtx->surfSrcColor.b = blue;
    pCtx->surfSrcColor.a = alpha;
  }

  if (target & MML_GDC_PE_MASK)
  {
    pCtx->surfMaskColor.r = red;
    pCtx->surfMaskColor.g = green;
    pCtx->surfMaskColor.b = blue;
    pCtx->surfMaskColor.a = alpha;
  }

  if (target & MML_GDC_PE_STORE)
  {
    pCtx->surfStoreColor.r = red;
    pCtx->surfStoreColor.g = green;
    pCtx->surfStoreColor.b = blue;
    pCtx->surfStoreColor.a = alpha;
  }

  return MML_OK;
}

static void helper_copyMat(struct PE_CTX_Matrix* pDestMap, const MM_FLOAT* pSrcMatrix, MML_GDC_PE_GEO_MATRIX_FORMAT format)
{
  if (format == MML_GDC_PE_GEO_MATRIX_FORMAT_3X2)
  {
    pDestMap->mat[0][0] = pSrcMatrix[0];
    pDestMap->mat[1][0] = pSrcMatrix[2];
    pDestMap->mat[2][0] = pSrcMatrix[4];

    pDestMap->mat[0][1] = pSrcMatrix[1];
    pDestMap->mat[1][1] = pSrcMatrix[3];
    pDestMap->mat[2][1] = pSrcMatrix[5];

    pDestMap->mat[0][2] = 0.0f;
    pDestMap->mat[1][2] = 0.0f;
    pDestMap->mat[2][2] = 1.0f;
  }
  else
  {
    pDestMap->mat[0][0] = pSrcMatrix[0];
    pDestMap->mat[1][0] = pSrcMatrix[3];
    pDestMap->mat[2][0] = pSrcMatrix[6];

    pDestMap->mat[0][1] = pSrcMatrix[1];
    pDestMap->mat[1][1] = pSrcMatrix[4];
    pDestMap->mat[2][1] = pSrcMatrix[7];

    pDestMap->mat[0][2] = pSrcMatrix[2];
    pDestMap->mat[1][2] = pSrcMatrix[5];
    pDestMap->mat[2][2] = pSrcMatrix[8];
  }

  pDestMap->isActive = 1;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeSetGeoMatrix(MML_GDC_PE_CONTEXT pectx, CYGFX_U32 target, MML_GDC_PE_GEO_MATRIX_FORMAT format, const MM_FLOAT* fMatrix)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  if (target & MML_GDC_PE_DST) helper_copyMat(&(pCtx->dstMatrix), fMatrix, format);
  if (target & MML_GDC_PE_SRC) helper_copyMat(&(pCtx->srcMatrix), fMatrix, format);
  if (target & MML_GDC_PE_MASK) helper_copyMat(&(pCtx->maskMatrix), fMatrix, format);
  if (target & MML_GDC_PE_STORE) helper_copyMat(&(pCtx->storeMatrix), fMatrix, format);

  return MML_OK;
}

MM_GDC_EXTERN MM_ERROR CyGfx_BeBlt(MML_GDC_PE_CONTEXT pectx, MM_FLOAT offsetx, MM_FLOAT offsety)
{
  IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

  if (pCtx->pStore->width == 0 || pCtx->pStore->height == 0)
  {
    // do nothing
    pCtx->pStore->width = 0;
  }
  else
  {
    IrisEng_PixEng_Blit(pCtx, offsetx, offsety);
  }
  return MML_OK;
}

CYGFX_ERROR CyGfx_BeFinish(CYGFX_BE_CONTEXT beCtx)
{
  return MML_OK;
}

/* Already available in mml_gdc_pixeng.h */
#if 0
MM_GDC_EXTERN MM_ERROR mmlGdcPeSync(MML_GDC_SYNC sync)
{
  return MML_OK;
}
#endif
#if 0
MM_ERROR mmlGdcSmAssignClut(MML_GDC_SURFACE surf, MML_GDC_SURF_CLM eMode, CYGFX_U32 uCount, MML_GDC_SURF_CLF eFormat, void* pBufferAddress)
{
  IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

  if ((eMode == MML_GDC_SURF_CLM_NEUTRAL) || (uCount == 0) || (pBufferAddress == NULL))
  {
    pSurface->ClutMode = eNoClut;
  }
  else
  { // MML_GDC_SURF_CLM_INDEX_RGB or MML_GDC_SURF_CLM_INDEX_RGBA
    pSurface->pClutBufferAddress = pBufferAddress;
    pSurface->ClutMode = eMode;
    pSurface->ClutCount = uCount;
    pSurface->ClutFormat = eFormat;
  }

  return MML_OK;
}
#endif

MM_ERROR CyGfx_WinSetWarpBuffer(MML_GDC_DISP_WINDOW win,
  const MML_GDC_WARP_PARAM* pWarpParam,
  const void* pAdd,
  const void* pPhyAdd)
{
  // todo
  return MML_OK;
}

MM_ERROR utVideoGetFreeTotal(CYGFX_U32* size)
{
  *size = 5000000;
  // todo
  return MML_OK;
}


/**********************************************/
/*************ADDED BY BHARIHA1****************/
/**********************************************/

CYGFX_ERROR CyGfx_BeSetTaskInstructionBuffer(CYGFX_BE_TASK task,
  void* address,
  CYGFX_U32     size)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_BeSetTaskCopses(CYGFX_BE_TASK task,
  CYGFX_U32     size)
{
  return CYGFX_OK;
}

/*Required to implement*//*Invoked from hmi_gfx_mgr02_initialize*/
CYGFX_ERROR utDispGetPll(CYGFX_FLOAT pixelClock, CYGFX_U08 displayMode, CYGFX_U08* divider, CYGFX_U32* pll)
{
  return CYGFX_OK;
}

/*Required to implement*//*Invoked from hmi_gfx_mgr02_initialize*/
CYGFX_ERROR utDispEnablePll(CYGFX_FLOAT pixelClock, CYGFX_U08 displayMode, CYGFX_U32 displayChannel)
{
  return CYGFX_OK;
}

/*Required to implement*//*Invoked from hmi_gfx_mgr02_initialize*/
CYGFX_ERROR utDispEnableFpdLink(CYGFX_U08 pllDivider, CYGFX_U08 displayMode, CYGFX_U08 fpdLink)
{
  return CYGFX_OK;
}

/*Required to implement*//*Invoked from hmi_gfx_mgr02_initialize*/
CYGFX_ERROR CyGfx_SysInitializeDriver(const CYGFX_SYSINIT_INFO_S* pDriverInitInfo)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_BeGetSync(CYGFX_BE_CONTEXT beCtx,
  CYGFX_SYNC       sync)
{
  return CYGFX_OK;
}
CYGFX_ERROR CyGfx_BeFlush(CYGFX_BE_CONTEXT beCtx)
{
  return CYGFX_OK;
}
CYGFX_ERROR CyGfx_CmSetClutData(CYGFX_CM_HANDLE      pHandle,
  CYGFX_CM_CLUT_UNIT   unit,
  CYGFX_CM_CLUT_FORMAT format,
  const CYGFX_S16* pRed,
  const CYGFX_S16* pGreen,
  const CYGFX_S16* pBlue)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_BeWaitSync(CYGFX_BE_CONTEXT beCtx,
  CYGFX_SYNC       sync)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_ConfigGetAttribute(CYGFX_CONFIG_ATTR pname,
  CYGFX_U32* pParam)
{
  return CYGFX_OK;
}

/////////////////////////////////////////////////////////////////
//                    Palette APIs                             //
/////////////////////////////////////////////////////////////////

CYGFX_ERROR CyGfx_PaletteReset(CYGFX_PALETTE palette)
{
  if (palette == NULL)
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }
  else
  {
    IRIS2_Palette* pPal = IrisEng_CreatePalette(palette);
    
    pPal->PhysAdd     = NULL;
    pPal->Count       = 0u;
    pPal->BitPerPixel = 0u;
    pPal->ColorBits   = 0u;
    pPal->ColorShift  = 0u;
    pPal->HwBitWidth  = 0u;
    pPal->Format      = 0u;
  }
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_PaletteAssign(CYGFX_PALETTE        palette,
                                CYGFX_PALETTE_FORMAT eFormat,
                                CYGFX_U16            count,
                                const void*          pBufferAddress)
{
  if (palette == NULL)
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }
  if (pBufferAddress == NULL)
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }
  if ((count < CYGFX_MIN_PALETTE_ENTRIES) || (count > CYGFX_MAX_PALETTE_ENTRIES))
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }

  IRIS2_Palette* pPal = IrisEng_CreatePalette(palette);

  pPal->PhysAdd = (void*)pBufferAddress;
  pPal->Count = count;
  pPal->Format = eFormat;
  pPal->HwBitWidth = 1;

  while ((1uL << pPal->HwBitWidth) < pPal->Count)
  {
    pPal->HwBitWidth++;
  }
  

  switch (eFormat)
  {
  case CYGFX_PALETTE_FORMAT_X8R8G8B8:
    pPal->BitPerPixel = 32;
    pPal->ColorBits = 0x08080800u;
    pPal->ColorShift = 0x10080000u;
    break;
  case CYGFX_PALETTE_FORMAT_R8G8B8:
    pPal->BitPerPixel = 24;
    pPal->ColorBits = 0x08080800u;
    pPal->ColorShift = 0x10080000u;
    break;
  case CYGFX_PALETTE_FORMAT_B8G8R8:
    pPal->BitPerPixel = 24;
    pPal->ColorBits = 0x08080800u;
    pPal->ColorShift = 0x00081000u;
    break;
  case CYGFX_PALETTE_FORMAT_R5G5B5:
    pPal->BitPerPixel = 16;
    pPal->ColorBits = 0x05050500u;
    pPal->ColorShift = 0x0a050000u;
    break;
  case CYGFX_PALETTE_FORMAT_A1R5G5B5:
    pPal->BitPerPixel = 16;
    pPal->ColorBits = 0x05050501u;
    pPal->ColorShift = 0x0a05000fu;
    break;
  case CYGFX_PALETTE_FORMAT_A4R4G4B4:
    pPal->BitPerPixel = 16;
    pPal->ColorBits = 0x04040404u;
    pPal->ColorShift = 0x0804000cu;
    break;
  default:
    return CYGFX_ERP_ERR_PAL_INVALID_FORMAT;
  }

  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_PaletteGetAttribute(const CYGFX_PALETTE palette,
  CYGFX_PALETTE_ATTR  eName,
  CYGFX_U32* puValue)
{
  CYGFX_ERROR ret = CYGFX_OK;

  if (palette == NULL)
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }
  if (puValue == NULL)
  {
    return CYGFX_ERP_ERR_PAL_INVALID_PARAMETER;
  }

  IRIS2_Palette* pPal = IrisEng_CreatePalette(palette);

  switch (eName)
  {
  case CYGFX_PALETTE_ATTR_VIRT_ADDRESS:
  case CYGFX_PALETTE_ATTR_PHYS_ADDRESS:
    *puValue = (CYGFX_U32)pPal->PhysAdd;
    break;
  case CYGFX_PALETTE_ATTR_COUNT:
    *puValue = pPal->Count;
    break;
  case CYGFX_PALETTE_ATTR_BITPERPIXEL:
    *puValue = pPal->BitPerPixel;
    break;
  case CYGFX_PALETTE_ATTR_COLORBITS:
    *puValue = pPal->ColorBits;
    break;
  case CYGFX_PALETTE_ATTR_COLORSHIFT:
    *puValue = pPal->ColorShift;
    break;
  default:
    ret = CYGFX_ERP_ERR_PAL_INVALID_ATTRIBUTE;
    break;
  }
  return ret;
}

CYGFX_ERROR CyGfx_PaletteAlloc(CYGFX_PALETTE        palette,
  CYGFX_PALETTE_REGION region)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_PaletteFree(CYGFX_PALETTE        palette,
  CYGFX_PALETTE_REGION region)
{
  return CYGFX_OK;
}

CYGFX_ERROR CyGfx_SmPaletteAssign(CYGFX_SURFACE       surf,
  const CYGFX_PALETTE palette)
{
  
  IRIS2_Palette* pPal = IrisEng_CreatePalette(palette);
  IRIS2_Surface* pSurf = IrisEng_CreateSurf(surf);

  if (pPal == NULL)
  {
    pSurf->ClutBitPerPixel = 0u;
    pSurf->ClutColorBits = 0u;
    pSurf->ClutColorShift = 0u;
    pSurf->ClutFormat = 0u;
    pSurf->ClutCount = 0;
    pSurf->ClutMode = eNoClut;
    pSurf->pClutBufferAddress = NULL;
  }
  else
  {
    if ((pPal->HwBitWidth == 0u) || (pPal->ColorBits == 0u))
    {
      return CYGFX_ERP_ERR_SURF_INVALID_PARAMETER;
    }
    
    pSurf->ClutBitPerPixel    = pPal->HwBitWidth;
    pSurf->ClutColorBits      = pPal->ColorBits;
    pSurf->ClutColorShift     = pPal->ColorShift;
    pSurf->ClutFormat         = pPal->Format;
    pSurf->pClutBufferAddress = pPal->PhysAdd;
    pSurf->ClutCount          = pPal->Count;
    pSurf->ClutMode           = eRGBClut;
  }

  return CYGFX_OK;
}