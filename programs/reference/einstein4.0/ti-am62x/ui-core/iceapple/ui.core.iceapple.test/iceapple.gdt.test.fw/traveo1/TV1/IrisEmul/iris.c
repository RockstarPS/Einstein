
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

MM_ERROR mmlGdcDispCommit( MML_GDC_DISPLAY display )
{
    return MML_OK;
}

MM_ERROR mmlGdcDispDitherCtrl( MML_GDC_DISPLAY display,
                               MML_GDC_DISP_DITHER_ENABLE enable,
                               MML_GDC_DISP_DITHER_MODE mode,
                               MML_GDC_DISP_DITHER_RANGE range,
                               MML_GDC_DISP_DITHER_FORMAT format )
{
    return MML_OK;
}


MM_ERROR mmlGdcDispOpenDisplay( MML_GDC_DISP_PROPERTIES *mode,
                                MML_GDC_DISPLAY* display )
{
    IRIS2_Display* pDisplay;

    *display = (MML_GDC_DISPLAY)malloc(sizeof(MML_GDC_DISPLAY));
    pDisplay = IrisEng_CreateDsp(*display);

    pDisplay->width = mode->xResolution;
    pDisplay->height = mode->yResolution;
    pDisplay->pWindowList = 0;

    return MML_OK;
}

MM_ERROR mmlGdcDispSetAttribute( MML_GDC_DISPLAY display,
                                 MML_GDC_DISP_ATTR pname,
                                 MM_U32 param )
{
    //assert(pname == MML_GDC_DISP_ATTR_GAMMA || pname == MML_GDC_DISP_ATTR_BACKGROUND_COLOR);
    return MML_OK;
}

MM_ERROR mmlGdcDispCloseDisplay( MML_GDC_DISPLAY display )
{
    assert(0);
    return MML_OK;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Window

MM_ERROR mmlGdcDispWinSync( MML_GDC_DISP_WINDOW win,
                            MML_GDC_SYNC sync )
{
    // TODO:
    return MML_OK;
}


MM_ERROR mmlGdcDispWinWaitSync( MML_GDC_DISP_WINDOW win,
                                MML_GDC_SYNC sync)
{
    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcDispSync(MML_GDC_DISPLAY display, MML_GDC_SYNC sync)           /* PRQA S 3673 */   /* <msr id=10> */
{
	// TODO:
    return MML_OK;
}

MM_ERROR mmlGdcDispWaitSync(MML_GDC_DISPLAY display, MML_GDC_SYNC sync)            /* PRQA S 3673 */   /* <msr id=10> */
{
	// TODO:
    return MML_OK;
}


MM_ERROR mmlGdcDispWinGetAttribute( MML_GDC_DISP_WINDOW win,
                                    MML_GDC_DISP_WIN_ATTR pname,
                                    MM_U32 *pParam )
{
    IRIS2_Window* pWindow = IrisEng_CreateWnd(win);

    switch(pname)
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


MM_ERROR mmlGdcDispWinDestroy( MML_GDC_DISP_WINDOW win )
{
    IRIS2_Window* pWindow;
    IRIS2_Window** pNext;

    pWindow = IrisEng_CreateWnd(win);
    pNext = &(pWindow->pDisplay->pWindowList);

    while(*pNext != 0)
    {
        if(*pNext == pWindow)
        { 
            // already inside the list
            break;
        }

        pNext = &((*pNext)->pNext);
    }

    if(*pNext != 0)
    {
        *pNext = pWindow->pNext;
    }
    IrisEng_DestroyWnd(win);
    free(win);

    return MML_OK;
}


MM_ERROR mmlGdcDispWinSetSurface( MML_GDC_DISP_WINDOW win,
                                  MM_U32 target,
                                  MML_GDC_SURFACE surf )
{
    IRIS2_Window* pWindow = IrisEng_CreateWnd(win);
    pWindow->pSurface = IrisEng_CreateSurf(surf);
    return MML_OK;
}


MM_ERROR mmlGdcDispWinSetAttribute( MML_GDC_DISP_WINDOW win,
                                    MML_GDC_DISP_WIN_ATTR pname,
                                    MM_U32 param )
{
    IRIS2_Window* pWindow = IrisEng_CreateWnd(win);

    switch(pname)
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


MM_ERROR mmlGdcDispWinSetBlendMode( MML_GDC_DISP_WINDOW win,
                                    MM_U32 blend_mode)
{
    IRIS2_Window* pWindow = IrisEng_CreateWnd(win);
    pWindow->blendMode = blend_mode;

    return MML_OK;
}


MM_ERROR mmlGdcDispWinCreate( MML_GDC_DISPLAY display,
                              MML_GDC_DISP_WINDOW_PROPERTIES *properties,
                              MML_GDC_DISP_WINDOW *pWin )
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

    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TOPLEFT_X, properties->topLeftX);
    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TOPLEFT_Y, properties->topLeftY);
    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_WIDTH, properties->width);
    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_HEIGHT, properties->height);
    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_TILE_MODE, MML_GDC_DISP_TILE_MODE_ZERO);
    mmlGdcDispWinSetAttribute(*pWin, MML_GDC_DISP_WIN_ATTR_DISABLE, 0); // by default its 0
    
    // insert the window inside its display list (its sorted by layer)
    pNext = &(pWindow->pDisplay->pWindowList);
    while(*pNext != 0)
    {
        if(*pNext == pWindow)
        { 
            // already inside the list
            return MML_OK;
        }

        if((*pNext)->layer > pWindow->layer || 
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

MM_ERROR mmlGdcDispWinCommit( MML_GDC_DISP_WINDOW win )
{
    return MML_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Surface

MM_ERROR mmlGdcSmGenSurfaceObjects(MM_U32 uCnt, MML_GDC_SURFACE *pSurfaces)
{
    IRIS2_Surface* pSurf;
    while(uCnt > 0)
    {
        uCnt--;

        pSurfaces[uCnt] = (MML_GDC_SURFACE)malloc(sizeof(MML_GDC_SURFACE));
        
        pSurf = IrisEng_CreateSurf(pSurfaces[uCnt]);
        memset(pSurf, 0, sizeof(IRIS2_Surface));

        mmlGdcSmResetSurfaceObject(pSurfaces[uCnt]);
    }
    return MML_OK;
}

MM_ERROR mmlGdcSmGetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 *puValue)
{
    IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);
    
    switch(eName)
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
        *puValue = (MM_U32)pSurface->pBuffer;
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
        if(pSurface->compression == MML_GDC_SURF_COMP_NON)
        {
            if(pSurface->stride != 0)
            {
                *puValue = pSurface->height * pSurface->stride;
            }
            else
            {
                *puValue = pSurface->height * ((pSurface->width * pSurface->bitperpixel  + 7) / 8);
            }
        }
        else
        {
            *puValue = pSurface->sizeinbytes;
        }
        break;


    case MML_GDC_SURF_ATTR_CLUTBITPERPIXEL:

        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORBITS:
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORSHIFT:
        break;
    case MML_GDC_SURF_ATTR_PHYS_ADDRESS:
    case MML_GDC_SURF_ATTR_RLAD_MAXCOLORBITS:


    case MML_GDC_SURF_ATTR_CLUTMODE:
    case MML_GDC_SURF_ATTR_CLUTCOUNT:
    case MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS:
    case MML_GDC_SURF_ATTR_CLUTBUFFER_PHYS_ADDRESS:
    case MML_GDC_SURF_ATTR_SURF_FORMAT:
        return MML_OK;
    }
    

    return MML_OK;
}

MM_ERROR mmlGdcSmSetAttribute(const MML_GDC_SURFACE surf, MML_GDC_SURF_ATTR eName, MM_U32 uValue)
{
    IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);
    
    switch(eName)
    {
    case MML_GDC_SURF_ATTR_WIDTH:
        pSurface->width = uValue;
        pSurface->DispSize = (pSurface->width)*(pSurface->height);
        break;
    case MML_GDC_SURF_ATTR_HEIGHT:
        pSurface->height = uValue;
        pSurface->DispSize = (pSurface->width)*(pSurface->height);
        break;
    case MML_GDC_SURF_ATTR_SURF_FORMAT:
        {
            MM_U32 bitsperpixels = 0;
            MM_U32 colorbits = 0;
            MM_U32 colorshift = 0;
            MM_U32 colorformat = MML_GDC_SURF_COLOR_FORMAT_RGBA;
            MM_U32 colorspace = MML_GDC_SURF_COLOR_SPACE_RGB;
            pSurface->ClutMode = eNoClut;

            switch(uValue)
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
                colorbits =  0x08080808;
                colorshift = 0x00081018;
                break;
            case MML_GDC_SURF_FORMAT_RGB8:
            //< 8 bpp, RGB8 can be used for gray or indexed image buffers.
            // For the second use case an indexed color lookup table must be defined in the surface. 
                bitsperpixels = 8;
                colorbits =  0x03020300;
                colorshift = 0x05030000;
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
                bitsperpixels = 1;
                colorbits = 0x00000000;
                colorshift = 0x00000000;
                break;
			case MML_GDC_SURF_FORMAT_A8RGB8:
				bitsperpixels = 16;
                colorbits = 0x08080808;
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
            case MML_GDC_SURF_FORMAT_A1:
            

            case MML_GDC_SURF_FORMAT_YVYU422:
            case MML_GDC_SURF_FORMAT_VYUY422:
            default:
                assert(0);
            }
  
            mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_BITPERPIXEL, bitsperpixels);
            mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_COLORBITS, colorbits);
            mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_COLORSHIFT, colorshift);
            mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_COLOR_FORMAT, colorformat);
            mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_COLOR_SPACE, colorspace);

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


    case MML_GDC_SURF_ATTR_CLUTBITPERPIXEL:
        pSurface->ClutBitPerPixel = uValue;
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORBITS:
        pSurface->ClutColorBits = uValue;
        break;
    case MML_GDC_SURF_ATTR_CLUTCOLORSHIFT:
        pSurface->ClutColorShift = uValue;
        break;

    case MML_GDC_SURF_ATTR_RLAD_MAXCOLORBITS:
    case MML_GDC_SURF_ATTR_CLUTMODE:
    case MML_GDC_SURF_ATTR_CLUTCOUNT:
    case MML_GDC_SURF_ATTR_CLUTBUFFERADDRESS:
    case MML_GDC_SURF_ATTR_CLUTBUFFER_PHYS_ADDRESS:
        return MML_OK;
    }

    return MML_OK;
}

MM_ERROR mmlGdcSmAssignBuffer(MML_GDC_SURFACE surf, MM_U32 uWidth, MM_U32 uHeight, MML_GDC_SURF_FORMAT eFormat, void *pBufferAddress, MM_U32 uRleWords)
{
    mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_WIDTH, uWidth);
    mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_HEIGHT, uHeight);
    mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_BASE_ADDRESS, (MM_U32)pBufferAddress);
    mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_SURF_FORMAT, eFormat);

    if(uRleWords > 0)
    {
        mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_SIZEINBYTES, uRleWords);
    }
    else
    {
        mmlGdcSmSetAttribute(surf, MML_GDC_SURF_ATTR_COMPRESSION_FORMAT, MML_GDC_SURF_COMP_NON);
    }

    // TODO:
    return MML_OK;
}

MM_ERROR mmlGdcSmResetSurfaceObject(MML_GDC_SURFACE surf)
{
    IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

    pSurface->compression = MML_GDC_SURF_COMP_NON;
    pSurface->stride = 0;
    pSurface->pBuffer = 0;
    pSurface->sizeinbytes = 0;

    return MML_OK;
}


MM_ERROR mmlGdcSmDeleteSurfaceObjects(MM_U32 uCnt, MML_GDC_SURFACE *pSurfaces)
{
    MM_U32 i;
    for(i = 0; i < uCnt; i++)
    {
        IrisEng_DestroySurf(pSurfaces[i]);
        free(pSurfaces[i]);
    }
    return MML_OK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PE context

MM_ERROR mmlGdcPeGenContext(MML_GDC_PE_CONTEXT *pPectx)
{
    IRIS2_PECtx* pCtx;
    *pPectx = (MML_GDC_PE_CONTEXT)malloc(sizeof(MML_GDC_PE_CONTEXT));
    pCtx = IrisEng_CreatePeCtx(*pPectx);

	mmlGdcPeResetContext(*pPectx);
    return MML_OK;
}
MM_GDC_EXTERN MM_ERROR mmlGdcPeResetContext(MML_GDC_PE_CONTEXT pectx)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    memset(pCtx, 0, sizeof(IRIS2_PECtx));

    // default values ========
    pCtx->blend.func_blue_dst = pCtx->blend.func_green_dst = pCtx->blend.func_red_dst = MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA;
    pCtx->blend.func_blue_src = pCtx->blend.func_green_src = pCtx->blend.func_red_src = MML_GDC_PE_BF_GL_SRC_ALPHA;

    pCtx->blend.func_alpha_dst = MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA;
    pCtx->blend.func_alpha_src = MML_GDC_PE_BF_GL_ONE;

    pCtx->blend.mode_alpha = pCtx->blend.mode_blue = pCtx->blend.mode_green = pCtx->blend.mode_red = MML_GDC_PE_BM_GL_FUNC_ADD;


    // ======================

    return MML_OK;
}


void mmlGdcPeDeleteContext(MML_GDC_PE_CONTEXT pectx)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    free(pCtx);
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeFill (MML_GDC_PE_CONTEXT pectx, MM_U32 x, MM_U32 y, MM_U32 w, MM_U32 h)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    IrisEng_PixEng_Fill(pCtx, x, y, w, h);

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeColor(MML_GDC_PE_CONTEXT pectx, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    pCtx->color.r = red;
    pCtx->color.g = green;
    pCtx->color.b = blue;
    pCtx->color.a = alpha;

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeActiveArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_S32 x, MM_S32 y, MM_U32 w, MM_U32 h)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    if(target & MML_GDC_PE_MASK)
    {
        pCtx->maskRectArea.isAcive = 1;
        pCtx->maskRectArea.x = x;
        pCtx->maskRectArea.y = y;
        pCtx->maskRectArea.w = w;
        pCtx->maskRectArea.h = h;
    }

    if(target & MML_GDC_PE_SRC)
    {
        pCtx->srcRectArea.isAcive = 1;
        pCtx->srcRectArea.x = x;
        pCtx->srcRectArea.y = y;
        pCtx->srcRectArea.w = w;
        pCtx->srcRectArea.h = h;
    }

    if(target & MML_GDC_PE_DST)
    {
        pCtx->dstRectArea.isAcive = 1;
        pCtx->dstRectArea.x = x;
        pCtx->dstRectArea.y = y;
        pCtx->dstRectArea.w = w;
        pCtx->dstRectArea.h = h;
    }

    if(target & MML_GDC_PE_STORE)
    {
        pCtx->storeRectArea.isAcive = 1;
        pCtx->storeRectArea.x = x;
        pCtx->storeRectArea.y = y;
        pCtx->storeRectArea.w = w;
        pCtx->storeRectArea.h = h;
    }
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeSelectArea(MML_GDC_PE_CONTEXT pectx, MM_U32 target)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    pCtx->selectedArea = target;

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeSurfAttribute(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_PE_SURF_ATTR pname, MM_U32 param)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    
    switch(pname)
    {
    case MML_GDC_PE_SURF_ATTR_COLORMULTI:
        if(target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.COLORMULTI = param;
        if(target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.COLORMULTI = param;
        if(target & MML_GDC_PE_DST) pCtx->dstSurfAttr.COLORMULTI = param;
        if(target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.COLORMULTI = param;
        break;
    case MML_GDC_PE_SURF_ATTR_ALPHAMULTI:
        if(target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.ALPHAMULTI = param;
        if(target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.ALPHAMULTI = param;
        if(target & MML_GDC_PE_DST) pCtx->dstSurfAttr.ALPHAMULTI = param;
        if(target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.ALPHAMULTI = param;
        break;
    case MML_GDC_PE_SURF_ATTR_TILE_MODE:
        if(target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.TILE_MODE = param;
        if(target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.TILE_MODE = param;
        if(target & MML_GDC_PE_DST) pCtx->dstSurfAttr.TILE_MODE = param;
        if(target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.TILE_MODE = param;
        break;
    case MML_GDC_PE_SURF_ATTR_USE_CLIPPING:
        if(target & MML_GDC_PE_MASK) pCtx->maskSurfAttr.USE_CLIPPING = param;
        if(target & MML_GDC_PE_SRC) pCtx->srcSurfAttr.USE_CLIPPING = param;
        if(target & MML_GDC_PE_DST) pCtx->dstSurfAttr.USE_CLIPPING = param;
        if(target & MML_GDC_PE_STORE) pCtx->storeSurfAttr.USE_CLIPPING = param;
        break;
    case MML_GDC_PE_SURF_ATTR_TRANSPARENT:
        break;
    default:
        assert(0);
    }
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeBindSurface(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_SURFACE surface)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);
    IRIS2_Surface* pSurface = IrisEng_CreateSurf(surface);

    if(target & MML_GDC_PE_STORE)
    {
        pCtx->pStore = pSurface;
        memset(&(pCtx->storeSurfAttr), 0, sizeof(pCtx->storeSurfAttr));
        memset(&(pCtx->storeMatrix), 0, sizeof(pCtx->storeMatrix));
        memset(&(pCtx->storeRectArea), 0, sizeof(pCtx->storeRectArea));
        memset(&(pCtx->surfStoreColor), 0, sizeof(pCtx->surfStoreColor));
    }

    if(target & MML_GDC_PE_DST)
    {
        pCtx->pDst = pSurface;
        memset(&(pCtx->dstSurfAttr), 0, sizeof(pCtx->dstSurfAttr));
        memset(&(pCtx->dstMatrix), 0, sizeof(pCtx->dstMatrix));
        memset(&(pCtx->dstRectArea), 0, sizeof(pCtx->dstRectArea));
        memset(&(pCtx->surfDstColor), 0, sizeof(pCtx->surfDstColor));
    }
    
    if(target & MML_GDC_PE_SRC)
    {
        pCtx->pSrc = pSurface;
        memset(&(pCtx->srcSurfAttr), 0, sizeof(pCtx->srcSurfAttr));
        memset(&(pCtx->srcMatrix), 0, sizeof(pCtx->srcMatrix));
        memset(&(pCtx->srcRectArea), 0, sizeof(pCtx->srcRectArea));
        memset(&(pCtx->surfSrcColor), 0, sizeof(pCtx->surfSrcColor));
    }
    
    if(target & MML_GDC_PE_MASK)
    {
        pCtx->pMask = pSurface;
        memset(&(pCtx->maskSurfAttr), 0, sizeof(pCtx->maskSurfAttr));
        memset(&(pCtx->maskMatrix), 0, sizeof(pCtx->maskMatrix));
        memset(&(pCtx->maskRectArea), 0, sizeof(pCtx->maskRectArea));
        memset(&(pCtx->surfMaskColor), 0, sizeof(pCtx->surfMaskColor));
    }

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeAttribute (MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_CTX_ATTR pname, MM_U32 param)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    switch(pname)
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
    }
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeBlendFunc(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BF func_red_src, MML_GDC_PE_BF func_red_dst,
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

MM_GDC_EXTERN MM_ERROR mmlGdcPeBlendMode(MML_GDC_PE_CONTEXT pectx, MML_GDC_PE_BM mode_red, MML_GDC_PE_BM mode_green, MML_GDC_PE_BM mode_blue, MML_GDC_PE_BM mode_alpha)
{
    IRIS2_PECtx* pCtx;

	if(pectx==NULL) return MML_OK;

	pCtx = IrisEng_CreatePeCtx(pectx);

    pCtx->blend.mode_alpha = mode_alpha;
    pCtx->blend.mode_blue = mode_blue;
    pCtx->blend.mode_green = mode_green;
    pCtx->blend.mode_red = mode_red;

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeSurfColor(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MM_U08 red, MM_U08 green, MM_U08 blue, MM_U08 alpha)
{
    IRIS2_PECtx* pCtx;
	
	if(pectx == NULL) return MML_OK;

	pCtx = IrisEng_CreatePeCtx(pectx);

    if(target & MML_GDC_PE_DST) 
    {
        pCtx->surfDstColor.r = red;
        pCtx->surfDstColor.g = green;
        pCtx->surfDstColor.b = blue;
        pCtx->surfDstColor.a = alpha;
    }
    if(target & MML_GDC_PE_SRC)
    {
        pCtx->surfSrcColor.r = red;
        pCtx->surfSrcColor.g = green;
        pCtx->surfSrcColor.b = blue;
        pCtx->surfSrcColor.a = alpha;
    }
    
    if(target & MML_GDC_PE_MASK)
    {
        pCtx->surfMaskColor.r = red;
        pCtx->surfMaskColor.g = green;
        pCtx->surfMaskColor.b = blue;
        pCtx->surfMaskColor.a = alpha;
    }

    if(target & MML_GDC_PE_STORE)
    {
        pCtx->surfStoreColor.r = red;
        pCtx->surfStoreColor.g = green;
        pCtx->surfStoreColor.b = blue;
        pCtx->surfStoreColor.a = alpha;
    }

    

    return MML_OK;
}

static void helper_copyMat(struct PE_CTX_Matrix* pDestMap, const MM_FLOAT *pSrcMatrix, MML_GDC_PE_GEO_MATRIX_FORMAT format)
{
    if(format == MML_GDC_PE_GEO_MATRIX_FORMAT_3X2)
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

MM_GDC_EXTERN MM_ERROR mmlGdcPeSetMatrix(MML_GDC_PE_CONTEXT pectx, MM_U32 target, MML_GDC_PE_GEO_MATRIX_FORMAT format, const MM_FLOAT *fMatrix)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

    if(target & MML_GDC_PE_DST) helper_copyMat(&(pCtx->dstMatrix), fMatrix, format);
    if(target & MML_GDC_PE_SRC) helper_copyMat(&(pCtx->srcMatrix), fMatrix, format);
    if(target & MML_GDC_PE_MASK) helper_copyMat(&(pCtx->maskMatrix), fMatrix, format);
    if(target & MML_GDC_PE_STORE) helper_copyMat(&(pCtx->storeMatrix), fMatrix, format);

    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeBlt(MML_GDC_PE_CONTEXT pectx, MM_FLOAT offsetx, MM_FLOAT offsety)
{
    IRIS2_PECtx* pCtx = IrisEng_CreatePeCtx(pectx);

	if(pCtx->pStore->width==0 || pCtx->pStore->height==0)
	{
		// do nothing
		pCtx->pStore->width=0;
	}
	else
	{
		IrisEng_PixEng_Blit(pCtx, offsetx, offsety);
	}
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeFinish(void)
{
    return MML_OK;
}

MM_GDC_EXTERN MM_ERROR mmlGdcPeSync(MML_GDC_SYNC sync)
{
    return MML_OK;
}


MM_ERROR mmlGdcSmAssignClut(MML_GDC_SURFACE surf, MML_GDC_SURF_CLM eMode, MM_U32 uCount, MML_GDC_SURF_CLF eFormat, void *pBufferAddress)
{
    IRIS2_Surface* pSurface = IrisEng_CreateSurf(surf);

    if(( eMode == MML_GDC_SURF_CLM_NEUTRAL)||(uCount == 0)||(pBufferAddress == NULL))
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

MM_ERROR mmlGdcDispWinSetWarpBuffer( MML_GDC_DISP_WINDOW win,
                                     const MML_GDC_WARP_PARAM *pWarpParam,
                                     const void* pAdd,
                                     const void* pPhyAdd)
{
    // todo
    return MML_OK;
}

MM_ERROR mmlGdcVideoGetFreeTotal(MM_U32 *size)
{
    *size=5000000;
    // todo
    return MML_OK;
}
