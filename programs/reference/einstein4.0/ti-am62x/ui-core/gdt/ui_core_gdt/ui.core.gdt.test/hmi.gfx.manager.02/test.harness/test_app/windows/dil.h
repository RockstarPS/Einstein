/*-*- c -*-*******************************************************************
 *
 *  Freescale Confidential Proprietary
 *
 ****************************************************************************/
/** \addtogroup Dil
 *  The DCU Integration Layer basically is a convenience API which integrates
 *  EGL surface setup, DCU (Display Control Unit) and render/display
 *  synchronization.
 *  The DIL API provides function calls to convenently generate up to triple
 *  buffered EGL Pbuffer surfaces (which natively are single buffered). The
 *  synchronization between rendering and displaying a frame buffer is handled
 *  by the API.
 *  The API allows to "attach" so called DCU layers to a surface. The layer
 *  will be configured with parameters set by the DIL surface, e.g. dimension
 *  and color format. Surfaces may be attached to multiple layers. On top the
 *  DIL API may be used to update DCU layer parameters, like x/y-position,
 *  transparency and others.
 *  @{
 ****************************************************************************/
/**
 *
 *  \file      dil.h
 *  \author    Stefan Schwarz
 *  \date      \$Date: 2005/12/05 15:10:08 $
 *
 *  \internal
 *   language  C
 ****************************************************************************/

#ifndef DIL_H
#define DIL_H

#include "EGL/egl.h"
#include "EGL\eglfsl.h"
#include "VG/openvg.h"
#include "basic.h"
#include "dcu.h"
//#include "dculite.h"

/*****************************************************************************
 *  defines
 ****************************************************************************/
#define DIL_MAX_BP_SURFS  3	/**< Max num of render buffers per egl surf */
#define DIL_MAX_SURFS	 20	/**< Max number of DIL surfaces */
#define DIL_MAX_LAYERS	 20	/**< Max number of available layers */

/*****************************************************************************
 *  types
 ****************************************************************************/
/** DIL Surface Types, basically the count of allocated pbuffers */
typedef enum {
  DIL_SURF_TYPE_SINGLE = 1,	/**< Single buffered surface */
  DIL_SURF_TYPE_DOUBLE = 2,	/**< Double buffered surface */
  DIL_SURF_TYPE_TRIPLE = 3	/**< Triple buffered surface */
} Dil_tSurfaceType;

/** DIL egl surface buffer status */
typedef enum {
  DIL_SRFSTAT_EMPTY = 0,	/**< Render buffer is empty */
  DIL_SRFSTAT_REND  = 1,	/**< Render buffer is being rendered */
  DIL_SRFSTAT_FULL  = 2,	/**< Render buffer full, queued for display */
  DIL_SRFSTAT_DISP  = 3		/**< Render buffer is being displayed */
} Dil_tSrfStat;

/** DIL enumeration for DCU3 and DCUlite layers */
typedef  enum {
  /* located in DCU3 */
  DIL_LAYER0 = 0,		/**< DCU3 layer 0 */
  DIL_LAYER1,			/**< DCU3 layer 1 */
  DIL_LAYER2,			/**< DCU3 layer 2 */
  DIL_LAYER3,			/**< DCU3 layer 3 */
  DIL_LAYER4,			/**< DCU3 layer 4 */
  DIL_LAYER5,			/**< DCU3 layer 5 */
  DIL_LAYER6,			/**< DCU3 layer 6 */
  DIL_LAYER7,			/**< DCU3 layer 7 */
  DIL_LAYER8,			/**< DCU3 layer 8 */
  DIL_LAYER9,			/**< DCU3 layer 9 */
  DIL_LAYER10,			/**< DCU3 layer 10 */
  DIL_LAYER11,			/**< DCU3 layer 11 */
  DIL_LAYER12,			/**< DCU3 layer 12 */
  DIL_LAYER13,			/**< DCU3 layer 13 */
  DIL_LAYER14,			/**< DCU3 layer 14 */
  DIL_LAYER15,			/**< DCU3 layer 15 */
  /* located in DCU lite */
  DIL_LAYER16,			/**< DCUlite layer 0 */
  DIL_LAYER17,			/**< DCUlite layer 1 */
  DIL_LAYER18,			/**< DCUlite layer 2 */
  DIL_LAYER19			/**< DCUlite layer 3 */
} Dil_tLayerNum;

/** DIL Surface Structure */
typedef struct {
  EGLSurface            surf[DIL_MAX_BP_SURFS];	/**< Egl surfaces */
  volatile Dil_tSrfStat stat[DIL_MAX_BP_SURFS];	/**< Egl surface buffer status */
  u32	                buf[DIL_MAX_BP_SURFS];	/**< Buffer addresses */
  EGLPbufferDimFSL      dim;		            /**< Render buffer parameters */
  int		            cnt;		            /**< Number of egl surfaces */
  int		            rendId;		            /**< Current egl surface render ID */
  int		            dispId;		            /**< Current dcu surface display ID */
}Dil_tSurface;


/** DIL Layer structure */
typedef struct {
  Dil_tSurface	*surf;		/**< Pointer to attached surface */
  u32		     addr;		/**< Layer address */
  u32		     posX;		/**< Layer x-position */
  u32		     posY;		/**< Layer y-position */
  u32		     cmax;		/**< Max chroma value */
  u32		     cmin;		/**< Min chroma value */
  u32		     coff;		/**< CLUT offset */
  u32		     alpha;		/**< Alpha value */
  bool		     updLayer;	/**< Layer parameter update flag */
} Dil_tLayer;

/** DIL API return types */
typedef enum {
  DIL_FALSE = 0,
  DIL_TRUE = 1
} Dil_tBool;

/** Layer configuration parameter types */
typedef enum {
  DIL_LAYER_XPOS  = 0,		/**< X-position */
  DIL_LAYER_YPOS  = 1,		/**< Y-position */
  DIL_LAYER_CMAX  = 2,		/**< Max chroma parameter */
  DIL_LAYER_CMIN  = 3,		/**< Min chroma parameter */
  DIL_LAYER_COFF  = 4,		/**< CLUT offset */
  DIL_LAYER_ALPHA = 5,		/**< Layer alpha value */
  DIL_LAYER_NOAT  = 6		/**< End of config list identifier */
} Dil_tLattrib;

/** Layer Configuration List Element */
typedef struct {
  Dil_tLattrib	attrib;		/**< DCU layer parameter */
  u32		val;		/**< Value related to parameter */
} Dil_tLayerCfg;

/*****************************************************************************
 *  exported variables
 ****************************************************************************/


/*****************************************************************************
 *  exported functions
 ****************************************************************************/
Dil_tSurface *Dil_CreateSurface(EGLDisplay dpy, EGLConfig config,
				const EGLint * attrLst,
				Dil_tSurfaceType type);

Dil_tBool Dil_AttachLayerToSurface(Dil_tLayerNum layer, Dil_tSurface *surf);

Dil_tBool Dil_UpdateLayerParameters(Dil_tLayerNum layer,
			      const Dil_tLayerCfg * cfgList);

Dil_tBool Dil_MakeCurrent(EGLDisplay dpy, Dil_tSurface *surf, EGLContext ctx);

Dil_tBool Dil_NextRenderBuffer(EGLDisplay dpy, Dil_tSurface *surf,
			       EGLContext ctx);
Dil_tBool Dil_DestroySurface(EGLDisplay dpy, Dil_tSurface *surf);
Dil_tBool Dil_Init(void);
DCU_PixFmt_t Dil_Ovg2DcuPixFormat(VGImageFormat fmt);

#endif /* DIL_H */
