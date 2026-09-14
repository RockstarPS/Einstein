/*-*- c -*-*******************************************************************
 *
 *  Freescale Confidential Proprietary
 *
 ****************************************************************************/
/** \addtogroup Dil
 *  @{
 ****************************************************************************/
/**
 *
 *  \file      dil.c
 *  \author    Stefan Schwarz
 *  \date      \$Date: 2005/12/05 15:10:08 $
 *
 *  \internal
 *   language  C
 ****************************************************************************/
#include "dil.h"
#include "dcu.h"
//#include "dculite.h"
#include <stdlib.h>
#include <malloc.h>

/*****************************************************************************
 *  local defines
 ****************************************************************************/


/*****************************************************************************
 *  local types
 ****************************************************************************/


/*****************************************************************************
 *  local prototypes
 ****************************************************************************/
static int fSurfIsValid(Dil_tSurface *surf);
static void fDcuInitLayer(Dil_tLayerNum layer, int width, int height, int bpp);
static void fDcuUpdateLayer(Dil_tLayerNum lay, Dil_tLayer *pL);
void fDcuResetLayer(Dil_tLayerNum lay);
static void Dil_DcuLiteIntHandler(void);

/*****************************************************************************
 *  exported variables
 ****************************************************************************/


/*****************************************************************************
 *  local variables
 ****************************************************************************/
/* Pointer array to surface structures */
static Dil_tSurface *lSurfs[DIL_MAX_SURFS] = {0};

/* Pointer array to layer structures */
static Dil_tLayer *lLays[DIL_MAX_LAYERS] = {0};

/*****************************************************************************
 *  exported functions
 ****************************************************************************/

/****************************************************************************/
/** Initialize DIL
 *
 * \param
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 ****************************************************************************/
Dil_tBool Dil_Init(void)
{
  //DCULITE_SetCallbackVSYNC(Dil_DcuLiteIntHandler);
  DCU_Init(0);
  //DCULITE_Init(0);
  return DIL_TRUE;
}

/****************************************************************************/
/** Create a DIL surface containing the specified number of pbuffer surfaces.
 *
 * \param	dpy	EGL display
 * \param	config	EGL config
 * \param	attrLst	Attributes used to generate pbuffer surface
 * \param	type	DIL surface type, number of pbuffer surfaces
 *			to generate.
 *
 * \return	DIL surf.
 ****************************************************************************/
Dil_tSurface *Dil_CreateSurface(EGLDisplay dpy,
                                EGLConfig  config,
				                const EGLint * attrLst,
				                Dil_tSurfaceType type)
{
  Dil_tSurface *surf = (Dil_tSurface *)-1;
  int sid, i;
  EGLPbufferDimFSL	dim;

  /* get empty surface slot */
  for (sid = 0; sid<DIL_MAX_SURFS; sid++)
  {
    surf = lSurfs[sid];
    if (!surf)
      break;
  }
  if (surf)
    return NULL;

  /* create surface structure */
  surf = (Dil_tSurface *)malloc(sizeof(Dil_tSurface));
  memset(surf, 0, sizeof(Dil_tSurface));

  /* create the number of requested egl Pbuffer surfaces */
  for(i=0;i<type;i++)
  {
     surf->surf[i] = eglCreatePbufferSurface(dpy, config, attrLst);
	 surf->buf[i] = ((EGLSURFACE *)surf->surf[i])->pbuff;
	 surf->dim.Width = ((EGLSURFACE *)surf->surf[i])->width;
	 surf->dim.Height = ((EGLSURFACE *)surf->surf[i])->height;
	 switch(((EGLSURFACE *)surf->surf[i])->pix_format)
	 {
	     case VG_sRGB_565:
		 {
			 surf->dim.PixelFormat = DCU_FMT_RGB565;
		 }
		 break;
	     case VG_sARGB_1555:
		 {
			 surf->dim.PixelFormat = DCU_FMT_ARGB1555;
		 }
		 break;
	     case VG_sARGB_4444:
		 {
			 surf->dim.PixelFormat = DCU_FMT_ARGB4444;
		 }
		 break;
	     case VG_lARGB_8888:
		 {
			 surf->dim.PixelFormat = DCU_FMT_ARGB8888;
		 }
		 break;
	 }
  }

  /* set DIL surface parameters */
  surf->cnt = type;
  surf->rendId = 0;
  lSurfs[sid] = surf;

  return surf;
}

/**************************************************************************/
/** A DIL layer is assigned the specified layer. Basic layer
 *		  parameters are configured. Once a surface is attached to
 *		  a layer, the layer address will be updated automatically
 *		  whenever Dil_NextRenderBuffer() is called. The content of
 *		  a render buffer attached to a particular layer will be
 *		  displayed for the first time as soon as
 *		  Dil_NextRenderBuffer() is called for the first time.
 *
 * \param	layer	Layer number to which surface shall be attached.
 * \param	surf	DIL surface that shall be attached.
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 **************************************************************************/
Dil_tBool Dil_AttachLayerToSurface(Dil_tLayerNum layer, Dil_tSurface *surf)
{
  /* make sure surf is valid */
  if (fSurfIsValid(surf) == DIL_MAX_SURFS)
    return DIL_FALSE;

  /* layer structure */
  if (!lLays[layer]) {
    lLays[layer] = (Dil_tLayer *)malloc(sizeof(Dil_tLayer));
  }
  memset(lLays[layer], 0, sizeof(Dil_tLayer));

  /* default value for transparency */
  lLays[layer]->alpha = 0xff;

  /* attach surface */
  lLays[layer]->surf = surf;

  /* disable layer, and init with surface parameters */
  fDcuInitLayer(layer, surf->dim.Width, surf->dim.Height,
                   surf->dim.PixelFormat);
  return DIL_TRUE;
}

/**************************************************************************/
/** Update parameters related to a layer. Parameters will
 *		  take effect in subsequent frame. The parameters are
 *		  passed in a list of value pairs. The first member of a
 *		  pair being the parameter identifier, the second value
 *		  the actual parameter value.
 *
 * \param	layer	Number of layer that shall be updated.
 * \param	cfgList	List of configuration parameters, terminated by
 *		element with DIL_LAYER_NONE attribute.
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 **************************************************************************/
Dil_tBool Dil_UpdateLayerParameters(Dil_tLayerNum layer,
			      const Dil_tLayerCfg * cfgList)
{
  int i = 0;
  Dil_tLayer *pL;

  /* layer structure */
  if (!lLays[layer]) {
    lLays[layer] = (Dil_tLayer *)malloc(sizeof(Dil_tLayer));
    memset(lLays[layer], 0, sizeof(Dil_tLayer));
  }
  pL = lLays[layer];

  /* go through list of attributes to be changed */
  for (i = 0; i < DIL_LAYER_NOAT; i++) {
    if (cfgList[i].attrib == DIL_LAYER_NOAT)
      break;
    switch (cfgList[i].attrib) {
      case DIL_LAYER_XPOS:  pL->posX =  cfgList[i].val; break;
      case DIL_LAYER_YPOS:  pL->posY =  cfgList[i].val; break;
      case DIL_LAYER_CMAX:  pL->cmax =  cfgList[i].val; break;
      case DIL_LAYER_CMIN:  pL->cmin =  cfgList[i].val; break;
      case DIL_LAYER_COFF:  pL->coff =  cfgList[i].val; break;
      case DIL_LAYER_ALPHA: pL->alpha = cfgList[i].val; break;
      case DIL_LAYER_NOAT:  break;
      default: break;
    }
  }
  pL->updLayer = TRUE;


  return DIL_TRUE;
}

/****************************************************************************/
/** Makes current the actual drawing context with related
 *		  surface.
 *
 * \param	dpy	EGL display.
 * \param	surf	DIL surface that shall be attached.
 * \param	ctx	EGL context.
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 ****************************************************************************/
Dil_tBool Dil_MakeCurrent(EGLDisplay dpy, Dil_tSurface *surf, EGLContext ctx)
{
  int ret = 0;
  EGLSurface eglSurf;

  (void)ret;	/* formally referenced in case MUST's are disabled */

  /* make sure surf is available */
  if (fSurfIsValid(surf) == DIL_MAX_SURFS)
    return DIL_FALSE;

  /* make actual Pbuffer surface current */
  eglSurf = surf->surf[surf->rendId];
  ret = eglMakeCurrent(dpy, eglSurf, eglSurf, ctx);

  surf->stat[surf->rendId] = DIL_SRFSTAT_REND;

  return DIL_TRUE;
}

/****************************************************************************/
/** Mark current render buffer as full and step to the next
 *		  available render buffer allocated for surf (DIL surface).
 * 		  Make the next available buffer current. The function will
 *		  block if the subsequent render buffer is not ready, e.g
 *		  contains a frame that is currently being displayed.
 *
 * \param	dpy	EGL display.
 * \param	surf	DIL surface that shall be attached.
 * \param	ctx	EGL context.
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 ****************************************************************************/
Dil_tBool Dil_NextRenderBuffer(EGLDisplay dpy, Dil_tSurface *surf,
			       EGLContext ctx)
{
  int ret = 0;
  int nextBufId;

  (void)ret;	/* formally referenced in case MUST's are disabled */

  /* make sure surf exists in surface list */
  if (fSurfIsValid(surf) == DIL_MAX_SURFS)
    return DIL_FALSE;

  /* mark current buffer as full */
  //MUST(surf->stat[surf->rendId] == DIL_SRFSTAT_REND);
  surf->stat[surf->rendId] = DIL_SRFSTAT_FULL;
  /*
  ** Copy from VG buffer to EGL surface buffer
  */
  eglCopyVGtoSurface();
  Dil_CheckForLayerUpdate();

  nextBufId = (surf->rendId+1)%surf->cnt;

  if (surf->cnt != DIL_SURF_TYPE_SINGLE) {
    /* wait for subsequent buffer to get available, TBD: time out */
    while (surf->stat[nextBufId] != DIL_SRFSTAT_EMPTY) ;

    /* update buffer id and make current */
    surf->rendId = nextBufId;
    ret = Dil_MakeCurrent(dpy, surf, ctx);
    surf->stat[nextBufId] = DIL_SRFSTAT_REND;
  }

  return DIL_TRUE;
}


/****************************************************************************/
/** Go through list of layers, and check the attached
 *		  surfaces if an update of the layer address is needed.
 *		  Check at the same time for updated parameters and update
 *		  them accordingly.
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 ****************************************************************************/
Dil_tBool Dil_CheckForLayerUpdate(void)
{
  int ln, sn;
  Dil_tSurface *surf;
  Dil_tLayer *layer;
  int currentDispId, nextDispId;

  /* walk through all surfaces and update if required */
  for (sn = 0; sn < DIL_MAX_SURFS; sn ++) {
    /* if surface is enabled */
    if ((surf = lSurfs[sn])) {
      currentDispId = surf->dispId;
      nextDispId    = (currentDispId+1)%surf->cnt;
      if (surf->stat[currentDispId] == DIL_SRFSTAT_FULL) {
        surf->stat[currentDispId] = DIL_SRFSTAT_DISP;
      }
      else if (surf->stat[nextDispId] == DIL_SRFSTAT_FULL) {
        surf->stat[currentDispId] = DIL_SRFSTAT_EMPTY;
        surf->stat[nextDispId] = DIL_SRFSTAT_DISP;
        surf->dispId = nextDispId;
      }
      else {
        /* do nothing */
      }
    }
  }

  /* walk through all layers, update buffer addresses and parameters */
  for (ln = 0; ln<DIL_MAX_LAYERS; ln++) {
    /* if layer is enabled */
    if ((layer = lLays[ln])) {
      /* if surface is attached */
      if ((surf = layer->surf)) {
        if (surf->stat[surf->dispId] == DIL_SRFSTAT_DISP) {
          layer->addr = surf->buf[surf->dispId];
          fDcuUpdateLayer((Dil_tLayerNum)ln , layer);
        }
      }
    }
  }

  return DIL_TRUE;
}

/****************************************************************************/
/** Destroy all egl surfaces (Pbuffers) related with the DIL
 *		  surface. Destroy all layer structures attached to DIL
 *		  surface and disable layers.
 *
 * \param	dpy	EGL display
 * \param	surf	DIL surface
 *
 * \return	Success: DIL_PASS, fail: DIL_FAIL
 ****************************************************************************/
Dil_tBool Dil_DestroySurface(EGLDisplay dpy, Dil_tSurface *surf)
{
  int i;
  int sn, ln;

  /* make sure surf is valid */
  if ((sn = fSurfIsValid(surf)) == DIL_MAX_SURFS)
    return DIL_FALSE;

  /* destroy  all egl Pbuffer surfaces related to DIL surface */
  for(i=0;i<surf->cnt;i++){
    eglDestroySurface(dpy,surf->surf[i]);
  }

  /* destroy all layers connected to DIL surface */
  for (ln = 0; ln<DIL_MAX_LAYERS; ln++) {
    /* if DIL surface is attached destroy layer */
    if (lLays[ln]->surf == surf) {
      free(lLays[ln]);
      lLays[ln] = NULL;
      fDcuResetLayer((Dil_tLayerNum)ln);
    }
  }

  /* destroy DIL surface */
  free(surf);
  lSurfs[sn] = NULL;

  return DIL_TRUE;
}


/****************************************************************************/
/** Translate OpenVG pixel type to DCU pixel type
 *
 * \param	fmt	OpenVG pixel format enumeration
 *
 * \return	DCU pixel format enumeration
 ****************************************************************************/
DCU_PixFmt_t Dil_Ovg2DcuPixFormat(VGImageFormat fmt)
{
  DCU_PixFmt_t dcutype = DCU_FMT_RGB565;	/* default */

  switch (fmt) {
    /* RGB{A,X} channel ordering */
    case VG_sRGBX_8888:break; /* not supported by DCU */
    case VG_sRGBA_8888:break; /* not supported by DCU */
    case VG_sRGBA_8888_PRE:break; /* not supported by DCU */
    case VG_sRGB_565:		dcutype = DCU_FMT_RGB565;   break; /* 16-bit */
    case VG_sRGBA_5551:break; /* not supported by DCU */
    case VG_sRGBA_4444:break; /* not supported by DCU */
    case VG_sL_8:break; /* TBD */
    case VG_lRGBX_8888:break; /* not supported by DCU */
    case VG_lRGBA_8888:break; /* not supported by DCU */
    case VG_lRGBA_8888_PRE:break; /* not supported by DCU */
    case VG_lL_8:break; /* TBD */
    case VG_A_8:		dcutype = DCU_FMT_TM8;	    break; /*  8-bit */
    case VG_BW_1:		dcutype = DCU_FMT_1BPP;     break; /*  1-bit */
    case VG_A_1:break; /* not supported by DCU */
    case VG_A_4:		dcutype = DCU_FMT_TM4;	    break; /*  4-bit */

    /* {A,X}RGB channel ordering */
    case VG_sXRGB_8888:		dcutype = DCU_FMT_RGB888;   break; /* 24-bit */
    case VG_sARGB_8888:		dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_sARGB_8888_PRE:	dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_sARGB_1555:		dcutype = DCU_FMT_ARGB1555; break; /* 16-bit */
    case VG_sARGB_4444:		dcutype = DCU_FMT_ARGB4444; break; /* 16-bit */
    case VG_lXRGB_8888:		dcutype = DCU_FMT_RGB888;   break; /* 24-bit */
    case VG_lARGB_8888:		dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_lARGB_8888_PRE:	dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */

    /* BGR{A,X} channel ordering */
    case VG_sBGRX_8888:		dcutype = DCU_FMT_RGB888;   break; /* 24-bit */
    case VG_sBGRA_8888:		dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_sBGRA_8888_PRE:	dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_sBGR_565:break; /* not supported by DCU */
    case VG_sBGRA_5551:break; /* not supported by DCU */
    case VG_sBGRA_4444:break; /* not supported by DCU */
    case VG_lBGRX_8888:		dcutype = DCU_FMT_RGB888;   break; /* 24-bit */
    case VG_lBGRA_8888:		dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */
    case VG_lBGRA_8888_PRE:	dcutype = DCU_FMT_ARGB8888; break; /* 32-bit */

    /* {A,X}BGR channel ordering */
    case VG_sXBGR_8888:break; /* not supported by DCU */
    case VG_sABGR_8888:break; /* not supported by DCU */
    case VG_sABGR_8888_PRE:break; /* not supported by DCU */
    case VG_sABGR_1555:break; /* not supported by DCU */
    case VG_sABGR_4444:break; /* not supported by DCU */
    case VG_lXBGR_8888:break; /* not supported by DCU */
    case VG_lABGR_8888:break; /* not supported by DCU */
    case VG_lABGR_8888_PRE:break; /* not supported by DCU */
  }
  return dcutype;
}

/*****************************************************************************
 *  local functions
 ****************************************************************************/
/*
 * DIL ISR for DCULite
 */
static void Dil_DcuLiteIntHandler(void)
{
  Dil_CheckForLayerUpdate();
}

/*
 * check if DIL surf exists
 */
static int fSurfIsValid(Dil_tSurface *surf)
{
  int sid;

  for (sid = 0; sid<DIL_MAX_SURFS; sid++) {
    if (surf == lSurfs[sid])
      break;
  }
  return sid;
}

/*
 * disable layer, init with basic parameters
 */
void fDcuInitLayer(Dil_tLayerNum lay, int width, int height, int bpp)
{
  int layer = lay;

  if (layer < DIL_LAYER16) {

    DCU_LayerDisable(layer);
    DCU_LayerSetWidth(layer, width);
    DCU_LayerSetHeight(layer, height);
    DCU_LayerSetX(layer, 0);
    DCU_LayerSetY(layer, 0);
    DCU_SetChroma((DCU_Plane_t)layer, 0, 0);
    DCU_LayerBPP(layer)    = bpp;
    DCU_LayerOffset(layer) = 0;
    DCU_LayerAlpha(layer)  = 0xff;
  }
  else {

    layer -= DIL_LAYER16;
#if 0
	DCULITE_LayerDisable(layer);
    DCULITE_LayerSetWidth(layer, width);
    DCULITE_LayerSetHeight(layer, height);
    DCULITE_LayerSetX(layer, 0);
    DCULITE_LayerSetY(layer, 0);
    DCULITE_SetChroma((DCULITE_Plane_t)layer, 0, 0);
    DCULITE_LayerBPP(layer)    = bpp;
    DCULITE_LayerOffset(layer) = 0;
    DCULITE_LayerAlpha(layer)  = 0xff;
#endif
  }
}

/*
 * update layer parameters, enable layer
 */
static void fDcuUpdateLayer(Dil_tLayerNum lay, Dil_tLayer *pL)
{
  int layer = lay;

  if (layer < DIL_LAYER16) {
    DCU_LayerSetX(layer, pL->posX);
    DCU_LayerSetY(layer, pL->posY);
    DCU_SetChroma((DCU_Plane_t)layer, pL->cmax, pL->cmin);
    DCU_LayerOffset(layer) = pL->coff;
    DCU_LayerAlpha(layer)  = pL->alpha;
    DCU_LayerAddress( layer ) = pL->addr;
    DCU_LayerEnable(layer);
  }
  else {
#if 0
    layer -= DIL_LAYER16;
    DCULITE_LayerSetX(layer, pL->posX);
    DCULITE_LayerSetY(layer, pL->posY);
    DCULITE_SetChroma((DCULITE_Plane_t)layer, pL->cmax, pL->cmin);
    DCULITE_LayerOffset(layer) = pL->coff;
    DCULITE_LayerAlpha(layer)  = pL->alpha;
    DCULITE_LayerAddress( layer ) = pL->addr;
    DCULITE_LayerEnable(layer);
#endif
  }
  pL->updLayer = FALSE;
}

/*
 * reset layer
 */
void fDcuResetLayer(Dil_tLayerNum lay)
{
  int layer = lay;

  if (layer < DIL_LAYER16) {
    DCU_LayerDisable(layer);
    DCU_LayerSetWidth(layer, 0);
    DCU_LayerSetHeight(layer, 0);
    DCU_LayerSetX(layer, 0);
    DCU_LayerSetY(layer, 0);
    DCU_SetChroma((DCU_Plane_t)layer, 0, 0);
    DCU_LayerBPP(layer)    = 0;
    DCU_LayerOffset(layer) = 0;
    DCU_LayerAlpha(layer)  = 0;
  }
  else {
#if 0
    layer -= DIL_LAYER16;
    DCULITE_LayerDisable(layer);
    DCULITE_LayerSetWidth(layer, 0);
    DCULITE_LayerSetHeight(layer, 0);
    DCULITE_LayerSetX(layer, 0);
    DCULITE_LayerSetY(layer, 0);
    DCULITE_SetChroma((DCULITE_Plane_t)layer, 0, 0);
    DCULITE_LayerBPP(layer)    = 0;
    DCULITE_LayerOffset(layer) = 0;
    DCULITE_LayerAlpha(layer)  = 0;
#endif
  }
}
