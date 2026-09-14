/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2012. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**============================================================================
**
** Name:           hmi_gfx_mgr02_types.h
**
** Description:    
**
** Organization:   GUI Software Section, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_TYPES_H
#define HMI_GFX_MGR02_TYPES_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#if defined(GFX_MGR02_OPEN_VG)
#include "VG\openvg.h"
#endif

#if defined(GFX_MGR02_FUJITSU)
#include "iris_drv.h"
#endif

#include "hmi_language_interface.h"

#if defined (GFX_MGR02_TRAVEO2)
#include "cygfx_driver_api.h"
#endif

#if defined (GFX_MGR02_AMBER) || defined (GFX_MGR02_AMBER_IRIS)|| defined (GFX_MGR02_TRAVEO2)
#include "mml_gdc_driver_api.h"
typedef float         VGfloat;
typedef unsigned char VGubyte;
#endif

#if defined (GFX_MGR02_IMXRT) ||	defined (GFX_MGR02_IMXRT_PXP)
#include "fsl_pxp.h"
//#include "fsl_cache.h"
#endif

#if defined (GFX_MGR02_VGLITE)
#include "vg_lite.h"
#endif

#if defined(GFX_MGR02_USE_TIDSS)
#include <drivers/dss.h>
#include <drivers/fvid2.h>
#endif

#ifndef GFX_MGR02_NULL_PTR
#define GFX_MGR02_NULL_PTR        ((void *) 0)
#endif

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

  /*
  ** WARNING!! - Any update to any of the below structures shall be followed up
  ** with changes in PrintDataStructureMemoryUsage() of GDT coder so that the
  ** memory usage information is rightly populated by the coder.
  */


  /* ----------------------------------------------------------------------------
  **                                BASE DEFINITIONS
  ** --------------------------------------------------------------------------*/

#ifdef GFX_MGR02_16BIT_TARGET
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#define GFX_MULTI_LINE_INVALID_LENGTH 0XFFFFU
#endif
  typedef UINT16 u_gx_flocal;
  typedef SINT16 s_gx_flocal;
#else
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
#define GFX_MULTI_LINE_INVALID_LENGTH 0XFFFFFFFFUL
#endif
  typedef UINT32 u_gx_flocal;
  typedef SINT32 s_gx_flocal;
#endif


  /*
  ** Basic data types
  */
  typedef float  GFX_FLOAT;
  typedef double GFX_DOUBLE;
  typedef unsigned int GFX_UINT;

  /*
  ** Volatile data types 
  */
  typedef volatile signed long GFX_VSINT32;
  typedef volatile unsigned long GFX_VUINT32;

  typedef float GFX_MGR02_FSIZE_W_T;
  typedef float GFX_MGR02_FSIZE_X_T;
  typedef float GFX_MGR02_FSIZE_H_T;
  typedef float GFX_MGR02_FSIZE_Y_T;

  typedef UINT16 GFX_MGR02_ISIZE_W_T;
  typedef SINT16 GFX_MGR02_ISIZE_X_T;
  typedef UINT16 GFX_MGR02_ISIZE_H_T;
  typedef SINT16 GFX_MGR02_ISIZE_Y_T;

  typedef struct
  {
    GFX_MGR02_FSIZE_W_T width;
    GFX_MGR02_FSIZE_H_T height;
  }GFX_MGR02_FDIM_DATA;  /* Object dimension (float) */

  typedef struct
  {
    GFX_MGR02_FSIZE_X_T x;
    GFX_MGR02_FSIZE_Y_T y;
  }GFX_MGR02_FLOC_DATA; /* Object location (float) */

  typedef struct
  {
    GFX_MGR02_FSIZE_X_T x;
    GFX_MGR02_FSIZE_X_T y;
    GFX_MGR02_FSIZE_W_T width;
    GFX_MGR02_FSIZE_H_T height;
  }GFX_MGR02_FAREA_DATA; /* Object Area (float) */

  typedef struct
  {
    SINT16 x;
    SINT16 y;
    UINT16 width;
    UINT16 height;
  }GFX_MGR02_IAREA_DATA; /* Object Area (integer) */

  typedef struct
  {
    SINT16 sx;
    SINT16 sy;
    SINT16 ex;
    SINT16 ey;
  }GFX_MGR02_VISIBLE_AREA;

  typedef struct
  {
    UINT16 width;
    UINT16 height;
  }GFX_MGR02_IDIM_DATA; /* Object dimension (integer) */

  typedef struct
  {
    SINT16 x;
    SINT16 y;
  }GFX_MGR02_ILOC_DATA;  /* Object location (integer) */

#if GFX_MGR02_PIX_FORMAT > GFX_MGR02_PIX_FORMAT_8BPP
  typedef UINT32 GFX_MGR02_COLOR;
#else
  typedef UINT8  GFX_MGR02_COLOR;
#endif
  typedef UINT8  GFX_MGR02_ALPHA;

#if defined(GFX_MGR02_OPEN_VG) ||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
  /* ----------------------------------------------------------------------------
  **          OPENVG SPECIFIC DEFINITIONS TO SUPPORT VECTOR OBJECTS
  **              (More details refer openvg 1.1 specification)
  ** --------------------------------------------------------------------------*/

  /*
  ** Color definition in RGBA format
  ** rgba[0] = Red   component, range ==> 0.0f to 1.0f
  ** rgba[1] = green component, range ==> 0.0f to 1.0f
  ** rgba[2] = blue  component, range ==> 0.0f to 1.0f
  ** rgba[3] = alpha component, range ==> 0.0f to 1.0f
  */
  typedef struct
  {
    VGfloat rgba[4];
  }GFX_MGR02_OVG_COLOR_DEF_T;

  /*
  ** Linear gradient definition
  ** bbox[]        - Bounding box
  ** matrix[]      - color transformation matrix
  ** stop_length   - stop table length 
  ** stop_table_fp - pointer to stop table
  */
  typedef struct
  {
    VGfloat         bbox[4];
    VGfloat         matrix[9];
    UINT32          stop_length;
    VGfloat const * stop_table_fp;
  }GFX_MGR02_OVG_LGRAD_DEF_T;

  /*
  ** Radial gradient definition
  ** bbox[]        - Bounding box
  ** matrix[]      - color transformation matrix
  ** stop_length   - stop table length 
  ** stop_table_fp - pointer to stop table
  */
  typedef struct
  {
    VGfloat         bbox[5];
    VGfloat         matrix[9];
    UINT32          stop_length;
    VGfloat const * stop_table_fp;
  }GFX_MGR02_OVG_RGRAD_DEF_T;

  /*
  ** attribute bitmask definitions for GFX_MGR02_OVG_PATH_DEF_T
  */
#define GFX_MGR02_PATH_PROP_FILL_RULE_NONZERO     (0x0000)
#define GFX_MGR02_PATH_PROP_FILL_ENABLED          (0x0001)
#define GFX_MGR02_PATH_PROP_FILL_RULE_EVENODD     (0x0002)
#define GFX_MGR02_PATH_PROP_STROKE_ENABLED        (0x0004)
#define GFX_MGR02_PATH_PROP_BLEND_ENABLED         (0x0008)

#define GFX_MGR02_PATH_PROP_LINE_CAP              (0x0030)
#define GFX_MGR02_PATH_PROP_LINE_CAP_BUTT         (0x0000)
#define GFX_MGR02_PATH_PROP_LINE_CAP_ROUND        (0x0010)
#define GFX_MGR02_PATH_PROP_LINE_CAP_SQUARE       (0x0020)

#define GFX_MGR02_PATH_PROP_LINE_JOIN             (0x00C0)
#define GFX_MGR02_PATH_PROP_LINE_JOIN_MITER       (0x0000)
#define GFX_MGR02_PATH_PROP_LINE_JOIN_ROUND       (0x0040)
#define GFX_MGR02_PATH_PROP_LINE_JOIN_BEVEL       (0x0080)

#define GFX_MGR02_PATH_PROP_FILL_PAINT            (0x0300)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_COLOR      (0x0000)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_LGRAD      (0x0100)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_RGRAD      (0x0200)

#define GFX_MGR02_PATH_PROP_STROKE_PAINT          (0x0C00)
#define GFX_MGR02_PATH_PROP_STROKE_PAINT_COLOR    (0x0000)
#define GFX_MGR02_PATH_PROP_STROKE_PAINT_LGRAD    (0x0400)
#define GFX_MGR02_PATH_PROP_STROKE_PAINT_RGRAD    (0x0800)

#define GFX_MGR02_PATH_PROP_FILL_SPREAD           (0x3000)
#define GFX_MGR02_PATH_PROP_FILL_SPREAD_PAD       (0x0000)
#define GFX_MGR02_PATH_PROP_FILL_SPREAD_REPEAT    (0x1000)
#define GFX_MGR02_PATH_PROP_FILL_SPREAD_REFLECT   (0x2000)

#define GFX_MGR02_PATH_PROP_STROKE_SPREAD         (0xC000)
#define GFX_MGR02_PATH_PROP_STROKE_SPREAD_PAD     (0x0000)
#define GFX_MGR02_PATH_PROP_STROKE_SPREAD_REPEAT  (0x4000)
#define GFX_MGR02_PATH_PROP_STROKE_SPREAD_REFLECT (0x8000)

  /*
  ** OpenVG path definition
  ** attributes        - attribute definitions as specified above
  ** numSegments       - Number of path segments in path_segments_u8p array
  ** mitter_limit      - mitter limit 
  ** stroke_width      - Stroke width
  ** fill_paint_vp     - Pointer to fill paint (COLOR/LGRAD/RGRAD)
  ** stroke_paint_vp   - Pointer to stroke paint (COLOR/LGRAD/RGRAD)
  ** path_segments_u8p - Pointer to path segment table
  ** path_data_fp      - Pointer to path data table
  */
  typedef struct
  {
    UINT16          attributes;
    UINT16          numSegments;
    VGfloat         mitter_limit;
    VGfloat         stroke_width;
    void    const * fill_paint_vp;
    void    const * stroke_paint_vp;
    VGubyte const * path_segments_u8p;
    VGfloat const * path_data_fp;
  }GFX_MGR02_OVG_PATH_DEF_T;

  /*
  ** Base entry for a vector object
  ** num_paths      - number of paths in the object
  ** bounds[4]      - bounding box for the object (X,Y,Width,Height)
  ** path_array_sap - pointer to path array
  */
  typedef struct
  {
    GFX_UINT                           num_paths:15;  /* TODO:check memory allocation for this*/
    GFX_UINT                           opeque   :1;
    UINT16                           clip_index;
    VGfloat                          bounds[4];
    GFX_MGR02_OVG_PATH_DEF_T const * path_array_sap;
  }GFX_MGR02_OVG_OBJECT_T;

  /*
  ** Dynamic property for openVG objects.
  */
  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    GFX_MGR02_ILOC_DATA coord;
    VGfloat             matrix[9];
    GFX_MGR02_FLOC_DATA pivot;
  }GFX_MGR02_OVG_DYN_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    UINT16              base_id;
    GFX_MGR02_ILOC_DATA coord;
    VGfloat             matrix[9];
    GFX_MGR02_FLOC_DATA pivot;
  }GFX_MGR02_OVG_PROPERTY;
#endif /* #if defined(GFX_MGR02_OPEN_VG) */

#if defined(GFX_MGR02_VGLITE)

/*
** attribute bit-mask definitions for GFX_MGR02_OVG_PATH_DEF_T
*/
#define GFX_MGR02_PATH_PROP_FILL_ENABLED          ((UINT16)0x0001)
#define GFX_MGR02_PATH_PROP_FILL_RULE             ((UINT16)0x0002)
#define GFX_MGR02_PATH_PROP_FILL_RULE_NONZERO     ((UINT16)0x0000)
#define GFX_MGR02_PATH_PROP_FILL_RULE_EVENODD     ((UINT16)0x0002)
#define GFX_MGR02_PATH_PROP_BLEND_ENABLED         ((UINT16)0x0008)
#define GFX_MGR02_PATH_PROP_FILL_PAINT            ((UINT16)0x0300)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_COLOR      ((UINT16)0x0000)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_LGRAD      ((UINT16)0x0100)
#define GFX_MGR02_PATH_PROP_FILL_PAINT_RGRAD      ((UINT16)0x0200)

  typedef struct
  {
    UINT16           attributes;
    UINT16           numSegments;
    void             const * fill_paint_vp;
    UINT8            const * path_segments_u8p;
    vg_lite_float_t  const * path_data_fp;
  }GFX_MGR02_OVG_PATH_DEF_T;

  typedef struct
  {
    GFX_UINT                             num_paths :15;
    GFX_UINT                             opeque    :1;
    UINT16                               clip_index;
    vg_lite_float_t                      bounds[4];
    GFX_MGR02_OVG_PATH_DEF_T const *     path_array_sap;
  }GFX_MGR02_OVG_OBJECT_T;

  typedef struct
  {
    GFX_MGR02_ALPHA              alpha;
    UINT16                       base_id;
    GFX_MGR02_ILOC_DATA          coord;
    vg_lite_float_t              matrix[9];
    GFX_MGR02_FLOC_DATA          pivot;
  }GFX_MGR02_OVG_PROPERTY;

  typedef struct
  {
     GFX_MGR02_ALPHA             alpha;
     GFX_MGR02_ILOC_DATA         coord;
     vg_lite_float_t             matrix[9];
     GFX_MGR02_FLOC_DATA         pivot;
  }GFX_MGR02_OVG_DYN_PROPERTY;


  typedef struct
  {
    vg_lite_color_t color;
  }GFX_MGR02_OVG_COLOR_DEF_T;


#endif

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
  /* ----------------------------------------------------------------------------
  **                         DEFINITIONS TO SUPPORT TOUCH OBJECTS
  ** --------------------------------------------------------------------------*/

  /*
  ** Available touch events
  */
#define GFX_MGR02_MOUSE_MOVE_EV     (0)
#define GFX_MGR02_MOUSE_DOWN_EV     (1)
#define GFX_MGR02_MOUSE_UP_EV       (3)
#define GFX_MGR02_MOUSE_CANCEL_EV   (GFX_MGR02_MOUSE_UP_EV|GFX_MGR02_MOUSE_OUTOF_BOUND)

#define GFX_MGR02_MOUSE_EVENT_MASK          (0x000000FF)
#define GFX_MGR02_MOUSE_OUTOF_BOUND         (0x80000000U)
#define GFX_MGR02_MOUSE_FREEZE              (0x40000000)
#define GFX_MGR02_GET_MOUSE_EV(e)           ((e) & GFX_MGR02_MOUSE_EVENT_MASK)
#define GFX_MGR02_IS_MOUSE_OUTSIDE_BOUND(e) (((e) & GFX_MGR02_MOUSE_OUTOF_BOUND) != 0)
#define GFX_MGR02_IS_MOUSE_FREEZE(e)        (((e) & GFX_MGR02_MOUSE_FREEZE) != 0)


  /* 
  ** identifies a touch event that is received from touch driver 
  */
  typedef struct
  {
    SINT32 x;
    SINT32 y;
    UINT32 event;
    GFX_MGR02_EXT_TOUCH_DATA ext; 
	UINT8  finger; /*Output from Graphics manager to application. 0 for finger1 and 1 for finger2 and so on.*/ 
  }GFX_MGR02_TOUCH_QDATA;
#endif /* #if GFX_TOUCH_SCREEN_ENABLED > 0 */

  /* ----------------------------------------------------------------------------
  **                                WARPING DEFINITIONS
  ** --------------------------------------------------------------------------*/

#if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED)

  /* Reference to data which describe warping parameters*/
  typedef UINT8 GFX_MGR02_WARP_ID;

  /* Reference to invalid (not existent) warping data */
#define GFX_MGR02_INVALID_WARP ((GFX_MGR02_WARP_ID)0xFF)

#endif /* #if defined(GFX_MGR02_LAYER_WARPING_ENABLED) || defined(GFX_MGR02_WIDGET_WARPING_ENABLED) */

  /* ----------------------------------------------------------------------------
  **                                HISTOGRAM DEFINITIONS  
  ** --------------------------------------------------------------------------*/

#if defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_USER_LAYERS > 0)
    #define GFX_MGR02_FORMAT_HISTOGRAM ((UINT8)255)
    
    typedef struct
    {
        GFX_FLOAT hg_line_width;
        UINT32 hg_draw_color_red:8;
        UINT32 hg_draw_color_green:8;
        UINT32 hg_draw_color_blue:8; 
        UINT32 hg_draw_color_alpha:8;
        UINT16 hg_num_data_points;
        SINT16 hg_y_max;
        SINT16 hg_y_min;
        SINT16 const * hg_y_data;
    }GFX_MGR02_HISTOGRAM_DATA;    
#endif

  /* ----------------------------------------------------------------------------
  **                         DEFINITIONS GRAPHICS OBJECTS
  ** --------------------------------------------------------------------------*/
  /* Legacy interfaces */
  typedef struct
  {
    UINT16 hor_size;
    UINT16 ver_size;
  }GFX_MGR02_TILE_DATA;

  typedef struct
  {
    UINT16 start_line;
    UINT16 num_lines;
  }GFX_MGR02_VCLIP_DATA;

  typedef struct
  {
    SINT16 start_column;
    UINT16 num_columns;
  }GFX_MGR02_HCLIP_DATA;

#define GFX_MGR02_ANIM_RESET_POSX   0x00000001
#define GFX_MGR02_ANIM_RESET_POSY   0x00000002
#define GFX_MGR02_ANIM_RESET_POS    0x00000003
#define GFX_MGR02_ANIM_RESET_ALPHA  0x00000004
#define GFX_MGR02_ANIM_RESET_ALL    0xFFFFFFFFU
#define GFX_MGR02_ANIM_PARAM_RESET  UINT32
#define GFX_MGR02_INVALID_ANIM_ELEM_ID   0

  typedef struct
  {
#if defined (GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
    /* CLUT ptr  */ UINT8 const * CLUT;
#else
    /* CLUT ptr  */ UINT32 const * CLUT;
#endif
    /* CLUT size */ UINT16 CLUTsize;
    /* Padding   */ UINT16 padding;
  }GFX_MGR02_CLUT_DATA;

  /* 
  ** Fillscreen object   
  ** GFX_MGR02_PATTERN_DEF_T     - base object for a pattern fill
  ** GFX_MGR02_FILL_DEF_T        - base object for a color fill
  ** GFX_MGR02_FILL_PROPERTY     - static property for the used instance
  ** GFX_MGR02_FILL_DYN_PROPERTY - dynamic property for the used instance
  */
  typedef struct
  {
    GFX_MGR02_IDIM_DATA dim;               /* Dimention of pattern         */
    UINT16              id;                /* Bitmap object id to be tiled */
  }GFX_MGR02_TILE_DEF_T;

  typedef struct
  {
    GFX_MGR02_ILOC_DATA coord;            /* xy location of fill       */
    GFX_MGR02_IDIM_DATA dim;              /* Dimention for fill area   */
  }GFX_MGR02_VIDEO_DEF_T;


  typedef struct
  {
    GFX_MGR02_IDIM_DATA dim;            /* Dimention for fill area                  */
#if defined(GFX_MGR02_KEPLER)
    UINT16              id;             /* in case of kepler id of the image object */
#endif
    GFX_MGR02_COLOR     color;          /* Fill color                               */
  }GFX_MGR02_FILL_DEF_T;

  /* 
  ** Dynamic property for fill screen object ( to be used when animation
  ** property is set to true
  */
  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;              /* alpha to be used for fill */
    GFX_MGR02_COLOR     color;              /* fill color                */
    GFX_MGR02_ILOC_DATA coord;            /* xy location of fill       */
    GFX_MGR02_IDIM_DATA dim;              /* Dimention for fill area   */
  }GFX_MGR02_FILL_DYN_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;              /* alpha to be used for fill */
    GFX_MGR02_ILOC_DATA coord;            /* xy location of fill       */
    GFX_MGR02_IDIM_DATA dim;              /* Dimention for fill area   */
  }GFX_MGR02_TILE_DYN_PROPERTY;

  /*
  ** Static properties for a fillscreen. Created for every fillscreen usage
  ** instance regardless of animation = true/false. For animation case this
  ** will used as the default configuration and non animation case it will
  ** be the current property to be used to build the instance
  */
  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;            /* color to be used for fill      */
    UINT16              base_id;
    GFX_MGR02_ILOC_DATA coord;            /* xy location of fill            */
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_VGLITE)
    GFX_FLOAT               matrix[9];        /* transformation matrix          */
#endif
#if defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
    MM_FLOAT             matrix[9];
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)|| defined(GFX_MGR02_VGLITE)
    GFX_MGR02_FLOC_DATA pivot;            /* pivot point for transformation */
#endif
  }GFX_MGR02_FILL_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;            /* color to be used for fill      */
    UINT16              base_id;
    GFX_MGR02_ILOC_DATA coord;            /* xy location of fill            */
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)
    GFX_FLOAT               matrix[9];        /* transformation matrix          */
#endif
#if defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
    MM_FLOAT             matrix[9];
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
    GFX_MGR02_FLOC_DATA pivot;            /* pivot point for transformation */
#endif
  }GFX_MGR02_TILE_PROPERTY;

  /*
  ** Text element definitions
  ** GFX_MGR02_TEXT_DEF_T        - base object
  ** GFX_MGR02_TEXT_PROPERTY     - static property for the used instance
  ** GFX_MGR02_TEXT_DYN_PROPERTY - dynamic property for the used instance
  */
  /*
  ** alignment property
  */
#define GFX_MGR02_TP_ALIGN_LEFT    (0x00U)
#define GFX_MGR02_TP_ALIGN_RIGHT   (0x01U)
#define GFX_MGR02_TP_ALIGN_CENTRE  (0x02U)
#define GFX_MGR02_TP_ALIGN_MASK    (0x03U)
#define GFX_MGR02_TP_ALIGN_NOCHANGE (0x04U)
  /*
  ** draw_mode property
  ** 0 - FIll the text area with BG color and draw the text using draw color
  ** 1 - Fill the text area with Draw Color and Draw the text using BG color
  ** 2 - Just draw the text using draw color on existing background (no bg fill)
  */
#define GFX_MGR02_TP_DRAW_NORMAL   (0x00U)
#define GFX_MGR02_TP_DRAW_REVERSE  (0x01U)
#define GFX_MGR02_TP_DRAW_TRANSP   (0x02U)
#define GFX_MGR02_TP_DRAW_NOCHANGE   (0x03U)
  
  /* 
  ** clip_mode property
  ** 0 - String is clipped to the specified rectangle.
  ** 1 - String is clipped but char will be removed if they cannot be fully shown
  ** 2 - When the string is not fully fit in the specified rectangle, a specified string 
  **     is appended to show that clipping is performed. Eg. Tripcomputer can be 
  **     displayed as Tripcomp...
  ** 3 - No clipping is performed. String is displayed as is (Not supported at the moment) 
  ** 4 - When the string is not fully fitting in the specified rectangle, first, it is shrunk based on 
  **     the app inputs (i.e., max shrink percentage). If after shrinking also, string 
  **     is not fitting in the textbox, then a specified string (usually ellipsis "...")
  **     is appended to show that clipping is performed.  
  */
#define GFX_MGR02_TP_CLIP_NORMAL   (0x00U)  
#define GFX_MGR02_TP_CLIP_FIT      (0x01U)  
#define GFX_MGR02_TP_CLIP_APPEND   (0x02U)  
#define GFX_MGR02_TP_NO_CLIP       (0x03U)  
#define GFX_MGR02_TP_CLIP_SHRINK_FIT    (0x04U)
#define GFX_MGR02_TP_CLIP_NOCHANGE     (0x05U)
  
  /* 
  ** orientation property
  ** 0 - Printed horizontally
  ** 1 - Printed vertically
  */
#define GFX_MGR02_TO_HORIZONTAL    (0x00U)
#define GFX_MGR02_TO_VERTICAL      (0x01U)

  /* 
  ** dynamic property 
  */
#define GFX_MGR02_TP_STATIC_STRING  (0x00U)
#define GFX_MGR02_TP_DYNAMIC_STRING (0x01U)

  /*
  ** Scroll enable / disable property
  */
#define GFX_MGR02_TP_SCROLL_DISABLE    (0x00U)
#define GFX_MGR02_TP_SCROLL_ENABLE     (0x01U)

  /* 
  ** cache_char enable/disable 
  ** Enable:  char caching
  ** Disable: String Caching
  */
#define GFX_MGR02_TEXT_CACHE_DISABLE   (0x00U) 
#define GFX_MGR02_TEXT_CACHE_ENABLE	   (0x01U)


#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP)
#define GFX_MGR02_PIX_FORMAT_ALPHA 0x01
#define GFX_MGR02_PIX_ALPHA_SHFT   0x01
#define GFX_MGR02_PIX_MAX_COLOR    0x01
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
#define GFX_MGR02_PIX_FORMAT_ALPHA 0x03
#define GFX_MGR02_PIX_ALPHA_SHFT   0x02
#define GFX_MGR02_PIX_MAX_COLOR    0x03
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
#define GFX_MGR02_PIX_FORMAT_ALPHA 0x0F
#define GFX_MGR02_PIX_ALPHA_SHFT   0x04
#define GFX_MGR02_PIX_MAX_COLOR    0x0F
#else
#define GFX_MGR02_PIX_FORMAT_ALPHA 0xFF
#define GFX_MGR02_PIX_ALPHA_SHFT   0x08
#define GFX_MGR02_PIX_MAX_COLOR    0xFF
#endif
  typedef enum
  {
    GFX_MGR02_WRAP_NONE,
    GFX_MGR02_WRAP_WORD
  }GFX_MGR02_WRAP_MODE;

  typedef enum
  {
    GFX_MGR02_SCROLL_PIXEL,
    GFX_MGR02_SCROLL_LINE	
  }GFX_MGR02_SCROLL_MODE;

  /*
  ** Bitmap format definition (for openvg version the formats are as specified by VGImageFormat)
  ** GFX_MGR02_IMAGE_DEF_T        - base object
  ** GFX_MGR02_IMAGE_PROPERTY     - static property for the used instance
  ** GFX_MGR02_IMAGE_DYN_PROPERTY - dynamic property for the used instance
  */
#if !defined(GFX_MGR02_OPEN_VG)  && !defined(_OPENVG_H)  && !defined(GFX_MGR02_SUPPORT_OPENVG_BMPFONT_FOR_SCALING)
  /*
  ** Supported type for software rendering (define only if not already defined by OVG)
  */
#define VG_A_4        (0x0E) /* alpha map    */
#define VG_RGB_888    (0x0F) /* RGB888       */
#define VG_A_8        (0x0B) /* alpha map    */
#define VG_sRGB_565   (0x03) /* RGB565       */
#define VG_sXRGB_8888 (0x40) /* bitmap       */
#define VG_sARGB_8888 (0x41) /* alpha bitmap */
#define VG_sARGB_4444 (0x45) /* ARGB4444     */
#define VG_sARGB_1555 (0x44) /* ARGB1555     */
/* 
VG_sRGBA_8888_VIV =  1 | (1 << 5) | (1 << 6) | (1 << 7)
Added newly. Not from vglib file.
This format should be used only for direct capture. 
Not for loading from image file
*/
#define VG_sRGBA_8888_VIV (0xE1) 
#endif
  /*
  ** Define the various BPP values to be used with the "format" member
  ** of the GFX_MGR02_IMAGE_DEF_T structure incase of DCU target.
  */
#define GFX_MGR02_1BPP                    (0)
#define GFX_MGR02_2BPP                    (1)
#define GFX_MGR02_4BPP                    (2)
#define GFX_MGR02_8BPP                    (3)
#define GFX_MGR02_16BPP_RGB565            (4)
#define GFX_MGR02_24BPP                   (5)
#define GFX_MGR02_32BPP                   (6)
#define GFX_MGR02_4BPP_TRANSPARENCY       (7)
#define GFX_MGR02_8BPP_TRANSPARENCY       (8)
#define GFX_MGR02_4BPP_LUMINANCE          (9)
#define GFX_MGR02_8BPP_LUMINANCE          (10)
#define GFX_MGR02_16BPP_ARGB1555          (11)
#define GFX_MGR02_16BPP_ARGB4444          (12)
#define GFX_MGR02_16BPP_APAL8             (13)
#define GFX_MGR02_MONO_NORMAL             (14)
#define GFX_MGR02_MONO_TRANSPARENT        (15)
#define GFX_MGR02_MAX_BPP                 (16)

  /*
  ** Supported compression types
  */
#define GFX_MGR02_IMAGE_COMPRESSION_NONE  (0x00U)
#define GFX_MGR02_IMAGE_COMPRESSION_SWRLE (0x01U)
#define GFX_MGR02_IMAGE_COMPRESSION_HWRLE (0x02U)
#define GFX_MGR02_IMAGE_COMPRESSION_JPEG  (0x03U)
#define GFX_MGR02_IMAGE_COMPRESSION_IRLE  (0x04U)
#define GFX_MGR02_IMAGE_COMPRESSION_IRLA  (0x05U)
#define GFX_MGR02_IMAGE_COMPRESSION_IRLD  (0x06U)

  /*
  ** chroma_key settings for image
  */
#define GFX_MGR02_IMAGE_CHROMA_KEY_NONE   (0x00U)
#define GFX_MGR02_IMAGE_CHROMA_KEY_YES    (0x01U)
  /*
  ** For 'format' == GFX_MGR02_4BPP_TRANSPARENCY, GFX_MGR02_8BPP_TRANSPARENCY
  **                 GFX_MGR02_4BPP_LUMINANCE or GFX_MGR02_8BPP_LUMINANCE   
  **       if(chroma_key != 0) then it means blending mode to be set to
  **       remove background (transparent background)     
  **       if(chroma_key == 0) then it means blending mode to be set to
  **       keep background (opeque background) and the background color
  **       to be used will be in 'color' element    
  ** For all other formats
  **       if(chroma_key != 0) then it means blending mode to be set to
  **       enable chroma key and the transparent color will be in 'color' element
  **       if(chroma_key == 0) then it means blending mode to be set to
  **       disable chroma key. 
  */
  typedef struct
  {
#if defined(GFX_MGR02_OPEN_VG)  || \
  defined(GFX_MGR02_SOFTWARE) || \
  defined(GFX_MGR02_OPEN_GL)  || \
  defined(GFX_MGR02_FUJITSU)  || \
  defined(GFX_MGR02_AMBER)	|| \
  defined(GFX_MGR02_AMBER_IRIS)||\
  defined(GFX_MGR02_IMXRT)	|| \
  defined(GFX_MGR02_IMXRT_PXP)	|| \
  defined(GFX_MGR02_TRAVEO2) || \
  defined(GFX_MGR02_VGLITE)
    UINT8                format;
    GFX_UINT                compression:7;
#else
    GFX_UINT                format     :4;  
    GFX_UINT                compression:2;
#endif
    GFX_UINT                chroma_key :1;
    UINT8                vaoa_index;
    UINT16               clut;
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
    UINT32               comp_size;
#endif
#if defined(GFX_MGR02_VGLITE)
    UINT8                padding;
#endif
    GFX_MGR02_ISIZE_W_T  width;      /* width of the image    */
    GFX_MGR02_ISIZE_H_T  height;     /* height of the image   */
    GFX_MGR02_COLOR      color;      /* transparent color incase of choroma_key = 1, else bg color */
#if defined(GFX_MGR02_USE_FILESYSTEM)
    char const         * pixel_data; /* file name of the image data */
#else
    void const         * pixel_data; /* pointer to image data */
#endif
  }GFX_MGR02_IMAGE_DEF_T;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    UINT16              clut;
    GFX_MGR02_COLOR     fg_color;
    GFX_MGR02_ILOC_DATA coord;
  }GFX_MGR02_IMAGE_DYN_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    UINT16              base_id;
    GFX_MGR02_ILOC_DATA coord;
    GFX_MGR02_COLOR     fg_color;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_VGLITE)
    GFX_FLOAT               matrix[9];
#endif
#if defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
    MM_FLOAT             matrix[9];
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE)
    GFX_MGR02_FLOC_DATA pivot;
#endif
  }GFX_MGR02_IMAGE_PROPERTY;

  /*
  ** Widget object definitions
  ** GFX_MGR02_WIDGET_DEF_T        - base widget object
  ** GFX_MGR02_WIDGET_PROPERTY     - static property for the used instance
  ** GFX_MGR02_WIDGET_DYN_PROPERTY - dynamic property for the used instance
  **                                 only valid if the animation = true  
  */
  /* alignment */
#define GFX_MGR02_WP_ALIGN_LEFT    (0x00U)
#define GFX_MGR02_WP_ALIGN_RIGHT   (0x01U)
#define GFX_MGR02_WP_ALIGN_CENTRE  (0x02U)
#define GFX_MGR02_WP_ALIGN_NONE    (0x03U)
  /* clip_mode */
#define GFX_MGR02_WP_CLIP_NONE     (0x00U)
#define GFX_MGR02_WP_CLIP_STATIC   (0x01U)
#define GFX_MGR02_WP_CLIP_DYNAMIC  (0x02U)
  /* rr_engine */
#define GFX_MGR02_RT_DEFAULT       (0U)
#define GFX_MGR02_RT_OPENVG        (1U)
#define GFX_MGR02_RT_SOFTWARE      (2U)
#define GFX_MGR02_RT_VGLITE        (3U)

#define GFX_MGR02_INVALID_CLIENT_ID    (0xFFFFU)
#define GFX_MGR02_INVALID_FB_GROUP_ID  (0xFFU)

#define GFX_MGR02_MASK_WIDGET_DISABLED  (0x00U)
#define GFX_MGR02_MASK_WIDGET_NORMAL    (0x01U)
#define GFX_MGR02_MASK_WIDGET_INVERTED  (0x02U)
  
  typedef struct
  {
    GFX_UINT           clip_mode :2;
    GFX_UINT           alignment :2;
    GFX_UINT           merge     :1;          /* If true then need to merge all children in GRAM incase of Kepler */
#if defined(GFX_MGR02_MULTI_COLOR_WDG_PRESENT)
    GFX_UINT           multicolor:1;          /* If true then need indicates a multicolor widget in Kepler */
#endif
    UINT8              inter_element_space;      /* inter element space incase of alignemnt != NONE */
#if defined(GFX_MGR02_WIDGET_WARPING_ENABLED) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
    GFX_MGR02_WARP_ID    warp_id;             /* Reference to the warping parameters */
#endif
    UINT16          clip_index;               /* index in to a clip area array                   */
#if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER) ||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
    UINT16          image_id;                 /* in case of kepler id of the image object        */
    UINT16          client_id;                /* client id for root merge widgets */
    UINT8           rr_engine;                /* rendering engine to be used */
    UINT8           fb_format;                /* frame buffer pix format     */
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG) && (GFX_MGR02_NUM_AMBER_MERGE_WIDGETS>0)
    UINT8           use_extram;               /* use external RAM for rendering*/
#endif
    GFX_MGR02_COLOR bg_fill_color;             /* Background fill color       */
#endif
#if (GFX_MGR02_NUM_MASK_WIDGETS>0)
    UINT8           mask_mode;                 /* frame buffer pix format     */
#endif
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)
    UINT8           fb_group_id;                   /* frame buffer group id used when widget fb memory is allocated statically */
#endif
#if defined(GFX_MGR02_TRAVEO2)  
    UINT32          priority;
    UINT16          wdg_height;
    UINT8           render_mode; 
    UINT8           num_of_cops;
#endif
  }GFX_MGR02_WIDGET_DEF_T;

  typedef struct
  {
    GFX_MGR02_ALPHA      alpha;
    UINT16               clut;
#if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
    GFX_MGR02_COLOR      fg_color;
#endif
    GFX_MGR02_ILOC_DATA  coord;
    GFX_MGR02_IAREA_DATA clip;
  }GFX_MGR02_WIDGET_DYN_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    UINT16              base_id;
#if defined(GFX_MGR02_KEPLER)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_IMXRT)
    GFX_MGR02_COLOR     fg_color;
#endif
    GFX_MGR02_ILOC_DATA coord;
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_VGLITE)
    GFX_FLOAT               matrix[9];
#endif
#if defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
    MM_FLOAT             matrix[9];
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)|| defined (GFX_MGR02_VGLITE)
    GFX_MGR02_FLOC_DATA pivot;
#endif
  }GFX_MGR02_WIDGET_PROPERTY;

  typedef struct GFX_MGR02_ELEM_LIST_T_
  {
    UINT16 base_id;                                  /* Base element property table index            */
    UINT16 num_child_elements;                       /* Number of childrens in child array           */
    UINT32 obj_id;                                   /* object ID as detailed above                  */
    struct GFX_MGR02_ELEM_LIST_T_ const * child; /* Pointer to child table, NULL if no childrens */
  }GFX_MGR02_ELEM_LIST_T;


#define GFX_MGR02_TOUCH_PATH_END (0xFF)
  typedef struct
  {
    UINT8         priority;              /* Priority of the screen      */
    UINT8         anim_index;
#if GFX_MGR02_NUM_LAYERS > 1
    UINT8         layerid;               /* Layer it belongs to         */
#endif
    UINT8         num_child_elements;    /* Number of child elements    */
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
    UINT8          no_touch_points;      /* Number of touch points      */
    UINT8 const * const * touch_points_table;   /* Touch point config table    */
#endif
    UINT32        bg_color;              /* background color for screen */
    GFX_MGR02_ELEM_LIST_T const * child; /* pointer to child table      */
  }GFX_MGR02_SCREEN_DEF_T;

#if GFX_MGR02_NUM_OF_SCREENS <= 255
  typedef UINT8  GFX_MGR02_SCREEN_ID_T;
#else
  typedef UINT16 GFX_MGR02_SCREEN_ID_T;
#endif

  typedef struct
  {
    UINT8                   nb_priority;  /* Number of priority for this layer */
    UINT8                   pix_format;   /* Pixel format for this layer       */
    UINT8                   target;       /* Target option for this layer      */
#if    defined(GFX_MGR02_LAYER_WARPING_ENABLED) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_TRAVEO2))
    GFX_MGR02_WARP_ID       warp_id;      /* Reference to the warping parameters */
#endif
    GFX_MGR02_IAREA_DATA    area;         /* Area of this layer                */
    GFX_MGR02_SCREEN_ID_T * prio_stack;   /* Pointer to prioity screen stack   */
  }GFX_MGR02_LAYER_DEF_T;

#if defined(GFX_MGR02_MONOTFT)
#ifndef YES
  #define YES (0x01)
#endif
#ifndef NO
  #define NO  (0x00)
#endif

  typedef struct
  {
    UINT16                   lcd_xsize;   /* lcd_xsize of layer */
    UINT16                   lcd_ysize;   /* lcd_ysize of layer */
    UINT16                   lcd_bytes_per_row;
    UINT16                   lcd_bytes_per_col;
    UINT16                   lcd_size_mul_factor;
    UINT8                    lcd_pmask;
  }GFX_MGR02_PIXEL_DEF_T;
#endif

  /*
  ** Possible states for the is_transparent element in GFX_MGR02_ELEMENT_AREA
  ** GFX_MGR02_OPEQUE       - Element is fully opeque
  ** GFX_MGR02_SEETHROUGH   - Element is not fully opeque
  ** GFX_MGR02_TRANSPARENT  - Element is fully transparent and therefore not visible.
  */
#define GFX_MGR02_OPEQUE                   (0)
#define GFX_MGR02_SEETHROUGH               (1)
#define GFX_MGR02_TRANSPARENT              (2)

  /*
  ** Possible states for the sx element in GFX_MGR02_VISIBLE_AREA
  ** GFX_MGR02_OFFSET_SEETHROUGH   - Element is not fully opeque
  ** GFX_MGR02_OFFSET_TRANSPARENT  - Element is fully transparent and therefore not visible.
  ** Any other values are considered as valid values
  */
#define GFX_MGR02_OFFSET_SEETHROUGH        (-2)
#define GFX_MGR02_OFFSET_TRANSPARENT       (-1)


  typedef struct
  {
    GFX_FLOAT matrix[9];
    GFX_MGR02_FLOC_DATA pivot;
  }GFX_MGR02_OVG_EXTENDED_PROPERTY;

  typedef enum
  {
    GFX_MGR02_BITMAP_TYPE_E,
    GFX_MGR02_VECTOR_TYPE_E,
    GFX_MGR02_FPAINT_TYPE_COLOR_E,
    GFX_MGR02_FPAINT_TYPE_LGRAD_E,
    GFX_MGR02_FPAINT_TYPE_RGRAD_E,
    GFX_MGR02_SPAINT_TYPE_COLOR_E,
    GFX_MGR02_SPAINT_TYPE_LGRAD_E,
    GFX_MGR02_SPAINT_TYPE_RGRAD_E,
    GFX_MGR02_INVALID_TYPE_E
  }GFX_MGR02_VG_OBJ_TYPES;

  typedef struct
  {
    void const *           obj_def_SP;
    UINT32                 obj_handle;
    GFX_MGR02_VG_OBJ_TYPES obj_type;
    UINT8                  live_count;
#ifdef GFX_MGR02_THEME_ENABLED
    UINT32                 theme_id;
#endif
#if defined(GFX_MGR02_USE_FILESYSTEM) && defined(FSL_CONST_IMAGES)
    UINT8 *                pixel_data;
#endif
  }GFX_MGR02_VG_CACHE;

  typedef struct
  {
    UINT32               vg_ctx_cache_size;
    GFX_MGR02_VG_CACHE * const vg_ctx_cache_buf_SP;
  }GFX_MGR02_VG_CACHE_CONFIG;

  /* ----------------------------------------------------------------------------
  **                                FONT DEFINITIONS
  ** --------------------------------------------------------------------------*/

  /*
  ** Typedefinition for a single character ROM image. Character image will
  ** be generated only for the non transparent area. Transparent area anound
  ** a character will be stripped to save ROM and a start x,y offset is stored
  ** specify where the char has to start.
  ** x_soffset  - x start offset from where the char has to be drawn
  ** x_eoffset  - x end offset where the character will end
  ** y_soffset  - y start offset from where the char has to be drawn
  ** owidth     - actual width of the character including transparent area
  ** oheight    - actual height of the character including transparent area
  ** width      - width of the non transparent area 
  ** height     - Height of the non transparent area
  ** fdata      - Bitmap data for this character
  ** Refer \ui.core.gdt.doc\hmi.gfx.manager.02\design\font_metrics_generation.docx
  ** for a visual representation
  */
  typedef struct
  {
    SINT8 x_soffset;
    SINT8 x_eoffset;
    SINT8 y_soffset;
    UINT8 owidth;
    UINT8 width;
    UINT8 height;
    UINT8 const * fdata;
  }GFX_MGR02_FONT_CHAR_CONFIG;

  typedef struct
  {
    SINT8 x_soffset;
    SINT8 y_soffset;
    UINT8 width;
    UINT8 height;
    UINT8 owidth;
    UINT8 oheight;
  }GFX_MGR02_FONT_CHAR_METRICS;

  /*
  ** GFX_MGR02_FONT_LUT attribute definitions
  **
  ** Bits 0-1
  ** GFX_MGR02_FONT_SEARCH_MODE_TLUP   - indicates that we can perform a table look for
  **                                     fcc_ptr[] from ch_code to next (ch_code-1) to
  **                                     get corresponding GFX_MGR02_FONT_CHAR_CONFIG
  ** GFX_MGR02_FONT_SEARCH_MODE_DIRECT - indicates that the GFX_MGR02_FONT_CHAR_CONFIG
  **                                     info for the ch_code can be directly taken from
  **                                     fcc_ptr
  ** For the below example it means we can perform table look for code 0x0020 to 0x007D
  ** in lc_Default_Font_lut[0].fcc_ptr 
  ** And for char code 0x007E we can use a direct index to lc_Default_Font_lut[1].fcc_ptr
  ** GFX_FONT_LUT const lc_Default_Font_lut[]=
  ** {
  **   {0x0020, GFX_FONT_ENCODING_4BPP|GFX_FONT_SEARCH_MODE_TLUP  , &lc_Default_Font_fcc[0]},
  **   {0x007E, GFX_FONT_ENCODING_4BPP|GFX_FONT_SEARCH_MODE_DIRECT, &lc_Default_Font_fcc[94]},
  ** };
  **
  ** Bits 2-4
  ** GFX_MGR02_FONT_ENCODING_1BPP - indicates that the char images pointed by fcc_ptr is
  **                                1BPP encoded.
  ** GFX_MGR02_FONT_ENCODING_2BPP - indicates that the char images pointed by fcc_ptr is
  **                                2BPP encoded.
  ** GFX_MGR02_FONT_ENCODING_4BPP - indicates that the char images pointed by fcc_ptr is
  **                                4BPP encoded.
  ** 
  */
#define GFX_MGR02_FONT_SEARCH_MODE_TLUP   ((UINT8)(0x01))
#define GFX_MGR02_FONT_SEARCH_MODE_DIRECT ((UINT8)(0x02))

#define GFX_MGR02_FONT_ENCODING_1BPP      ((UINT8)(0U << 2U))
#define GFX_MGR02_FONT_ENCODING_2BPP      ((UINT8)(1U << 2U))
#define GFX_MGR02_FONT_ENCODING_4BPP      ((UINT8)(2U << 2U))
#define GFX_MGR02_FONT_ENCODING_8BPP      ((UINT8)(3U << 2U))
#define GFX_MGR02_FONT_ENCODING_OVG       ((UINT8)(4 << 2))

#define GFX_MGR02_GET_BPP(attrib)             ((UINT8)((attrib) & 0x1CU))
#define GFX_MGR02_GET_SEARCH_TYPE(attrib)     ((attrib) & 0x03U)

  /*
  ** Typedefinition to specify a character range look up table.
  ** A character range can be formed with the a single or continous range of 
  ** character codes with same BPP encoding
  ** ch_code    - Incase of a range specifies that start code
  ** attributes - See above description for attributes
  ** fcc_ptr    - Pointer to GFX_MGR03_FONT_CHAR_CONFIG definition table
  */
  typedef struct
  {
    HMI_CHAR                           ch_code;
    UINT8                              attributes;
    GFX_MGR02_FONT_CHAR_CONFIG const * fcc_ptr;
  }GFX_MGR02_FONT_LUT;

#if defined(GFX_MGR02_OPEN_VG)
  typedef struct
  {
    SINT32          x_advance;
    UINT32          num_p_segs;
    VGubyte const * path_segments_u8p;
    VGshort const * path_data_s16p;
  }GFX_MGR02_OVG_GLYPH_DEF_T;

  typedef struct
  {
    UINT16                     bmsize;
    UINT16                     ptsize;
    SINT16                     acent;
    SINT16                     decent;
    GFX_MGR02_FONT_LUT const * lut_ptr;
  }GFX_MGR02_OVG_FONT_T;
#endif

  /*
  ** Different font engine options
  */
#define GFX_MGR02_BMPFONT  (0)
#define GFX_MGR02_FREETYPE (1)
#define GFX_MGR02_DIGITYPE (2)
#define GFX_MGR02_MONOTYPE (3)
#define GFX_MGR02_SPANSION_FT2 (4)
#define GFX_MGR02_DIGI_OR_MONO_TYPE (5)

/*
** Different shape engine options
*/
#define GFX_MGR02_DEFAULT   (0)
#define GFX_MGR02_WORLDTYPE (1)
#define GFX_MGR02_HARFBUZZ  (2)

#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || \
       (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||  \
       (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
	#if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
	  #define GFX_MGR02_SHAPE_ENGINE_ENABLED
    #endif	/* #if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ) */
  #endif  /* #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) */
#endif	/* #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE	*/

#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))
  #if defined(GFX_MGR02_TEXT_SEPCIAL_EFFECTS) && (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
    /*
    ** Different text special effects
    */
    #define GFX_MGR02_TXT_BOLD_EFFECT              (0U)
    #define GFX_MGR02_TXT_SOFTEND_EFFECT           (1U)
    #define GFX_MGR02_TXT_OTL_UNFILL_EFFECT       (2U)
    #define GFX_MGR02_TXT_EMBOSSED_EFFECT          (3U)
    #define GFX_MGR02_TXT_ENGRAVED_EFFECT          (4U)
    #define GFX_MGR02_TXT_OTL_UNFILL_GLOW_EFFECT  (5U)
    #define GFX_MGR02_TXT_NORMAL_GLOW_EFFECT       (6U)
    #define GFX_MGR02_TXT_DROP_SHADOW_EFFECT       (7U)
    #define GFX_MGR02_TXT_INVALID_EFFECT           (8U)

    /* Default text effect properties */
    #define DEFAULT_TXT_INVALID_EFFECT             (GFX_MGR02_TXT_INVALID_EFFECT)
    #define DEFAULT_TXT_BOLD_PERCENTAGE            (0.0f)
    #define DEFAULT_TXT_OTL_WIDTH                  (1)
    #define DEFAULT_TXT_OTL_OPACITY                (1.0f)
    #define DEFAULT_TXT_SHADOW_COLOR               (0xFF969696U)
    #define DEFAULT_TXT_SHADOW_X                   (0U)
    #define DEFAULT_TXT_SHADOW_Y                   (0U)

    #define	VALID_TXT_BOLD_PERCENTAGE_RANGE_START  (0.0f)
    #define	VALID_TXT_BOLD_PERCENTAGE_RANGE_END    (1.0f)
    #define	VALID_TXT_OTL_WIDTH_RANGE_START        (1U)
    #define	VALID_TXT_OTL_WIDTH_RANGE_END          (10U)
    #define	VALID_TXT_OTL_OPACITY_RANGE_START      (1U)
    #define	VALID_TXT_OTL_OPACITY_RANGE_END        (10U)
    #define	VALID_TXT_SHADOW_COLOR                 (0xFF000000U)
    #define	VALID_TXT_SHADOW_XY_RANGE_START        (-10)
    #define	VALID_TXT_SHADOW_XY_RANGE_END          (10)

    #define GFX_MGR02_TXT_EFFECTS_ENABLED
    #define GFX_MGR02_DEFAULT_BOLD_WEIGHT          (0x0AAAU)
    typedef struct
    {				       
      UINT8            effect_type;
	  /* valid bold percentage range is 0.0 to 1.0 */
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)
      GFX_FLOAT        bold_percentage;
	  /* valid width range is 1 to 10 */
	    UINT16           otl_width; 
	  /* valid opacity range is 1.0 to 10.0 */
	    GFX_FLOAT        otl_opacity;
	  /* Background color for shadow effect */
      GFX_MGR02_COLOR  shadow_bg_col;
	  /* valid shadow x,y range is -10 to 10 */ 
      SINT16           shadow_x;
      SINT16           shadow_y;
#endif
  }GFX_MGR02_TXT_SPECIAL_EFFECTS;
  #endif
#endif

#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
typedef struct
{
   void *shaper_out_ptr;
}GFX_MGR02_SHAPE_INFO;

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))

#define GFX_STR_INVALID_INDEX  (0xFFFF)

typedef struct
  {
    SINT16     delta_pixels_x;
    SINT16     delta_pixels_y;
  }GFX_MGR02_SHAPE_DELTA;

typedef struct
{
   HMI_CHAR input_string[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
   GFX_MGR02_SHAPE_DELTA delta_val[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
   UINT8 is_character[GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U];
}GFX_MGR02_SHAPE_ML_DATA;

typedef struct
  {
    HMI_CHAR     char_unicode;
    HMI_CHAR     char_glyphid;
  }GFX_MGR02_SHAPE_CMAP;

typedef struct
  {
    GFX_MGR02_SHAPE_CMAP const *ml_cmap;
	UINT8 num_chars;
  }GFX_MGR02_SHAPE_CMAP_TABLE;

typedef struct
  {
    UINT8 char_flag;
	UINT8 complexity_flag;
	UINT8 unique_fntid_flag;
	UINT16 current_str_index;
  }GFX_MGR02_SHAPE_FLAGS;

#endif
#endif

#ifdef GFX_MGR02_FONT_GSUB_TABLE_ENABLED


  typedef struct
  {				       
    HMI_CHAR         * langsys_tag;
    UINT16 		    lookuporder;
    UINT16 		    reqfeatureindex;
    UINT16 		    lang_feature_cnt;
    UINT16        *  lang_feature_index;
  }HMI_FONT_GSUB_LANGSYS_TABLE;

  typedef struct
  {				       
    HMI_FONT_GSUB_LANGSYS_TABLE * defaultlang_tbl;
    UINT16                        langsys_cnt;
    HMI_FONT_GSUB_LANGSYS_TABLE * langsys_tbl;
  }HMI_FONT_GSUB_SCRIPT_TABLE;


  typedef struct
  {
    HMI_CHAR                   * script_tag;
    HMI_FONT_GSUB_SCRIPT_TABLE * script_tbl;
  }HMI_FONT_GSUB_SCRIPT_REC;


  typedef struct
  {
    UINT16                 script_cnt;
    HMI_FONT_GSUB_SCRIPT_REC * script_rec;
  }HMI_FONT_GSUB_SCRIPT_LIST;




  typedef struct
  {				       
    HMI_CHAR       * feature_tag;
    UINT16 		featureparams;
    UINT16 		    feature_lkup_cnt;
    HMI_CHAR 		  * feature_lkup_index;
  }HMI_FONT_GSUB_FEATURE_TABLE;


  typedef struct
  {				       
    UINT16    		             feature_cnt;
    HMI_FONT_GSUB_FEATURE_TABLE * feature_tbl;
  }HMI_FONT_GSUB_FEATURE_LIST;




  typedef struct
  {
    HMI_CHAR          ligature;
    UINT16            num_seq;
    HMI_CHAR const *  seq;
  }HMI_FONT_GSUB_LIG_TABLE;

  typedef struct
  {
    HMI_CHAR                        start_code;
    UINT16                          num_ligatures;
    HMI_FONT_GSUB_LIG_TABLE const * p_ligature;
  }HMI_FONT_GSUB_LIG_SET_TABLE;

  typedef struct
  {
    UINT16                              num_gsub;
    HMI_FONT_GSUB_LIG_SET_TABLE const * gsub;
  }HMI_FONT_GSUB_LIGATURE_SUBST_TABLE;

  typedef struct
  {
    UINT16                    coverage_format;  	 
    UINT16                    coverage_count;
    HMI_CHAR const          * coverage_gids;
  }HMI_FONT_GSUB_COVERAGE;

  typedef struct
  {
    UINT16                   sequence_id;
    UINT16                   lookup_id;
  }HMI_FONT_GSUB_SUBST_LOOKUP_RECORD;

  typedef struct
  {
    UINT16                   src_ptr_inc_val;
    UINT16                   dst_ptr_inc_val;
  }HMI_FONT_GSUB_CC_OUT;

  typedef struct
  {
    UINT16  ClassValue;
  }HMI_FONT_GSUB_SEQ;

  typedef struct
  {
    UINT16  startVal;
    UINT16  endVal;
    UINT16  classVal;
  }HMI_FONT_GSUB_RANGEREC;

  typedef struct
  {
    UINT16         format;
    UINT16         startglyph;
    UINT16         Count;
    union
    {
      HMI_FONT_GSUB_SEQ       const * bktrack_seq;
      HMI_FONT_GSUB_RANGEREC  const * range_rec;  
    }val;
  }HMI_FONT_GSUB_BKTRACK_CLASSDEF;

  typedef struct
  {
    UINT16         format;
    UINT16         startglyph;
    UINT16         Count;
    union
    {
      HMI_FONT_GSUB_SEQ       const * input_seq;
      HMI_FONT_GSUB_RANGEREC  const * range_rec;  
    }val;
  }HMI_FONT_GSUB_INPUT_CLASSDEF;


  typedef struct
  {
    UINT16         format;
    UINT16         startglyph;
    UINT16         Count;
    union
    {
      HMI_FONT_GSUB_SEQ       const * look_ahead_seq;
      HMI_FONT_GSUB_RANGEREC  const * range_rec;  
    }val;
  }HMI_FONT_GSUB_LA_CLASSDEF;



  typedef struct
  {
    UINT16                                backtrackglyphcount;
    HMI_FONT_GSUB_COVERAGE         const * backtrack_coverage;
    UINT16                                inputglyphcount;
    HMI_FONT_GSUB_COVERAGE         const     * input_coverage;
    UINT16                                lookheadglyphcount;
    HMI_FONT_GSUB_COVERAGE         const    * lookhead_coverage;
    UINT16                                substcount;
    HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const   * substlookuprec;
  }HMI_FONT_GSUB_CHAIN_SUBST3_TABLE;

  typedef struct
  {
    UINT16  lookaheadglyph;
  }HMI_FONT_GSUB_CHAIN_SUBCLASS_LOOKAHEAD_SEQ;

  typedef struct
  {
    UINT16  backtrackglyph;
  }HMI_FONT_GSUB_CHAIN_SUBCLASS_BKTRACK_SEQ;

  typedef struct
  {
    UINT16  backtrackGlyphCount;
    HMI_FONT_GSUB_CHAIN_SUBCLASS_BKTRACK_SEQ   const   *  backtrackseq;
    UINT16  inputGlyphCount;
    UINT16  lookaheadGlyphCount;
    HMI_FONT_GSUB_CHAIN_SUBCLASS_LOOKAHEAD_SEQ const   *  lookaheadSeq;
    UINT16  substitutionCount;
    HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const   * substlookuprec;
  }HMI_FONT_GSUB_CHAIN_SUBCLASS_RULETABLE;

  typedef struct
  {
    UINT16 chainSubClassRuleCount;
    HMI_FONT_GSUB_CHAIN_SUBCLASS_RULETABLE  const * ruleTable;
  }HMI_FONT_GSUB_CHAIN_SUBCLASS_SET;

  typedef struct
  {
    HMI_FONT_GSUB_COVERAGE         const * input_coverage;
    HMI_FONT_GSUB_BKTRACK_CLASSDEF const * bktrack_classDef;
    HMI_FONT_GSUB_INPUT_CLASSDEF   const * IP_classDef;
    HMI_FONT_GSUB_LA_CLASSDEF      const * la_classDef;
    UINT16  chainSubClassSetCount;
    HMI_FONT_GSUB_CHAIN_SUBCLASS_SET const *subclassDef;
  }HMI_FONT_GSUB_CHAIN_SUBST2_TABLE;

  typedef struct
  {    
    UINT16  startVal;
    UINT16  endVal;
    UINT16  classVal;
  }HMI_FONT_GSUB_CLASSDEF;


  typedef struct
  {
     UINT16 format;
	 UINT16 count;
	 HMI_FONT_GSUB_RANGEREC         const * range_rec;
  }HMI_FONT_GSUB_RANGERECORDS;
  
  typedef struct
  {
    /*      UINT16                    coverage_format;  	 
    UINT16                    coverage_count;
    HMI_CHAR const          * coverage_gids;*/

    UINT16          glyphCount; 
    UINT16          substitutionCount; 
    UINT16          const    *inputSequence; 
    HMI_FONT_GSUB_SUBST_LOOKUP_RECORD const   * substlookuprec;
  }HMI_FONT_GSUB_SUB_CLASS_RULE;

  typedef struct
  {
    UINT16          subClassRuleCount; 
    HMI_FONT_GSUB_SUB_CLASS_RULE  const * subClassRuleOffsets;
  }HMI_FONT_GSUB_SUB_CLASS_SET;


  typedef struct
  {
    /*union
    {
      HMI_FONT_GSUB_COVERAGE         const * subs_coverage_gids;
	  HMI_FONT_GSUB_RANGERECORDS         const * range_rec;
    }val;*/
    HMI_FONT_GSUB_COVERAGE           const  * input_coverage;
    UINT16                           ClassdefCount;
    HMI_FONT_GSUB_CLASSDEF           const * classDef;
    UINT16                           subClassCount;
    HMI_FONT_GSUB_SUB_CLASS_SET      const * subClassPtr;
  }HMI_FONT_GSUB_CONTEXT_SUBST2_TABLE;

  typedef struct
  {
    HMI_FONT_GSUB_COVERAGE     const  * single_sbt2_input_gid;
    UINT16                              single_sbt2_subst_gid_count;
    HMI_CHAR                   const  * single_sbt2_subst_gid;
  }HMI_FONT_GSUB_SINGLE_SUBST2_TABLE;

  typedef struct
  {
    HMI_FONT_GSUB_COVERAGE     const * single_sbt1_input_gid;
    UINT16                        single_sbt1_delta_glyph_id;
  }HMI_FONT_GSUB_SINGLE_SUBST1_TABLE;

  typedef struct
  {
    HMI_FONT_GSUB_COVERAGE             const  * input_coverage;
    UINT16                                      num_tables;
    HMI_FONT_GSUB_COVERAGE             const  * subs_coverage;
  }HMI_FONT_GSUB_MULTIPLE_SUBST_TABLE;
  
  typedef struct
  {
    UINT16                                  type;      /* check type is required here*/
    UINT16                                  format;
    union
    {
      HMI_FONT_GSUB_CHAIN_SUBST3_TABLE   const * chain_subst3;
      HMI_FONT_GSUB_CONTEXT_SUBST2_TABLE const * context_subst2;
      HMI_FONT_GSUB_CHAIN_SUBST2_TABLE   const * chain_subst2;     
      HMI_FONT_GSUB_LIGATURE_SUBST_TABLE const * lig;
      HMI_FONT_GSUB_SINGLE_SUBST1_TABLE  const * single_subst1;
      HMI_FONT_GSUB_SINGLE_SUBST2_TABLE  const * single_subst2;
      HMI_FONT_GSUB_MULTIPLE_SUBST_TABLE const * multiple_subst;
    }val;
  }HMI_FONT_GSUB_SUBTABLE;

  typedef struct lookup_table
  {
    UINT16                           type;
    UINT16                           flag;
    UINT16                           count;
    HMI_FONT_GSUB_SUBTABLE   const * subtable;
    UINT16		                    MarkFileringSet;
  }HMI_FONT_GSUB_LOOKUP_TABLE;

  typedef struct
  {
    char                        const       * script_tag;
    UINT16                                     script_lkup_cnt;
    UINT16                       const       * script_lkup_index;
  }HMI_FONT_GSUB_SCRIPT_LOOKUP_TBL;
#endif

  typedef struct
  {
    GFX_FLOAT     gpos_delta_pixels_x;
    GFX_FLOAT     gpos_delta_pixels_y;
  }GFX_MGR02_GPOS_DELTA;
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
  typedef enum
  {
    GFX_MGR02_CLASS0,
    GFX_MGR02_CLASS1
  }GFX_MGR02_GPOS_CLASS;


  typedef struct
  {
    SINT32     anch_x;
    SINT32     anch_y;
  }GFX_MGR02_CLASS_ANCH_POINTS;

  typedef struct
  {
    HMI_CHAR     unicode;
	UINT8        count;
	GFX_MGR02_CLASS_ANCH_POINTS const * class_anch;	
  }GFX_MGR02_GPOS_BASE_TABLE;
  typedef struct
  {
    HMI_CHAR     unicode;
    GFX_MGR02_CLASS_ANCH_POINTS class_anch;
    UINT8 class_select;
  }GFX_MGR02_GPOS_MARK_TABLE;

  typedef struct
  {
    GFX_MGR02_CLASS_ANCH_POINTS class0_anch;
    GFX_MGR02_CLASS_ANCH_POINTS class1_anch;
  }GFX_MGR02_GPOS_LIG_COMP_TABLE;
  typedef struct
  {
    GFX_MGR02_GPOS_LIG_COMP_TABLE const *anch_ptr;
  }GFX_MGR02_GPOS_COMPONENT;
  typedef struct
  {
    HMI_CHAR     unicode;
    UINT8        components_size;
    GFX_MGR02_GPOS_COMPONENT const *components;
  }GFX_MGR02_GPOS_LIGATURE_TABLE;
  typedef struct
  {
    GFX_MGR02_GPOS_MARK_TABLE const *gpos_MtoB_mark_ptr;
    HMI_CHAR                         mark_MtoB_table_size;
    GFX_MGR02_GPOS_BASE_TABLE const *gpos_MtoB_base_ptr;
    HMI_CHAR                         base_MtoB_table_size;
  }GFX_MGR02_GPOS_M2B_TABLE;

  typedef struct
  {
    GFX_MGR02_GPOS_MARK_TABLE const *gpos_MtoM_mark1_ptr;
    HMI_CHAR                         gpos_MtoM_mark1_size;
    GFX_MGR02_GPOS_BASE_TABLE const *gpos_MtoM_mark2_ptr;
    HMI_CHAR                         gpos_MtoM_mark2_size;
  }GFX_MGR02_GPOS_M2M_TABLE;

  typedef struct
  {
    GFX_MGR02_GPOS_LIGATURE_TABLE const *gpos_MtoL_ligature_ptr;
    HMI_CHAR                             ligature_table_size;
    GFX_MGR02_GPOS_MARK_TABLE const     *gpos_MtoL_mark_ptr;
    HMI_CHAR                             mark_MtoL_table_size;
  }GFX_MGR02_GPOS_M2L_TABLE;

  typedef struct
  {
    GFX_MGR02_GPOS_M2B_TABLE const *mark_to_base_tbl_ptr;
    HMI_CHAR                        mark_to_base_tbl_size;

    GFX_MGR02_GPOS_M2L_TABLE const *mark_to_ligature_tbl_ptr;
    HMI_CHAR                        mark_to_ligature_tbl_size;

    GFX_MGR02_GPOS_M2M_TABLE const *mark_to_mark_tbl_ptr;
    HMI_CHAR                        mark_to_mark_tbl_size;
  }GFX_MGR02_GPOS_TABLE;
#endif  /* #if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED) */

  /*
  ** Base definition for a font size.
  ** size_table - Size of GFX_MGR03_FONT_LUT table pointed by lut_ptr
  ** is_group   - If this is 0 or FALSE then f.lut_ptr will point to 
  **              GFX_MGR02_FONT_LUT for this font
  **              p.height will be the height of the font in pixels
  **              in this case.
  ** is_group   - If this is != 0 or TRUE then f.grp_ptr will point to 
  **              another GFX_MGR02_FONT array of size 'size_table' 
  **              height property is invalid in this case
  **              This indicates that it is a font group. 
  **              p.group_sel_index indiactes an index to font group
  **              selection array (l_gfx_mgr02_font_grp_prop_S[].group_selection)
  **              which indicates the font to be selected. 
  */
  typedef struct
  {
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))))
    UINT32                     extfontsize;
#endif
    GFX_FLOAT                     height_pts;
    UINT16                        unitsPerEm;
    HMI_CHAR                      size_table;
    GFX_UINT                      is_group:1;
    GFX_UINT                      is_vfont:1;
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
    GFX_UINT                      is_ffile:1;
    GFX_UINT                      is_autohint:1;
#else
    GFX_UINT                      unused:2;
#endif
#if (defined(GFX_MGR02_EXT_FONT_ENGINE) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)))
    UINT8                      bpp;
#endif
    UINT8                        char_space;
    union
    {
      UINT8                   height;
      UINT8                   group_sel_index;
    }p;
#if defined (GFX_MGR02_DEFAULT_FONT)
    UINT8                      default_index;
#else
    UINT8                      unused_index;
#endif
#if (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2))
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)))
    UINT8                      unique_id;   /* common font files will hold same id */
#endif
#endif
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
    GFX_MGR02_GPOS_TABLE const *gpos_table_ptr;
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))) && defined(GFX_MGR02_OPEN_VG)
    GFX_FLOAT                  baseline_offset;
	
#endif
    union
    {
      void                 const * ptr;
      GFX_MGR02_FONT_LUT   const * lut_ptr;
      UINT8                const * grp_ptr;
#if defined(GFX_MGR02_OPEN_VG)
      GFX_MGR02_OVG_FONT_T const * ovg_ptr;
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE))))
      UINT8                 const * ffile_name; 
#else
      char                 const * ffile_name;
#endif
    }f;
#ifdef GFX_MGR02_FONT_GSUB_TABLE_ENABLED
    UINT16                                     gsub_lookup_cnt;
    UINT16                                     gsub_script_cnt;
    HMI_FONT_GSUB_LOOKUP_TABLE const       *   gsub_lookup_list;
    HMI_FONT_GSUB_SCRIPT_LOOKUP_TBL const  *   gsub_script_lookup;
#endif
  }GFX_MGR02_FONT;

  typedef struct
  {
    GFX_UINT group_selection:7;
    GFX_UINT right2left:1;
  }GFX_MGR02_FNT_GRP_DYN_PROP;

#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))) && (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
  typedef struct {
    UINT8   height;
    UINT8   point_size;
  } GFX_MGR02_FONT_SIZE_T;
#endif /* #ifdef GFX_MGR02_AMBER */

  /*
  ** Text object definition
  ** GFX_MGR02_TEXT_DEF_T        - base properties
  ** GFX_MGR02_TEXT_DYN_PROPERTY - properties that can be animated
  ** GFX_MGR02_TEXT_PROPERTY     - default proerty for a usage instance
  */
  typedef struct
  {
    UINT32        string_index;    /* index to display string array*/
    GFX_MGR02_ISIZE_W_T width;     /* width of text area in pixels */
    UINT8         num_chars;       /* max length of characters     */
    UINT8         font_id;         /* defaule font id to be used   */
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
    UINT8         num_of_display_lines;  /* Number of lines to be displayed */
    SINT8         inter_line_spacing; /* Spacing between multi lines     */
    UINT16        max_num_of_lines;      /* Max no of display lines         */
  #if defined(GFX_MGR02_SHAPE_ENGINE_ENABLED)
	UINT32        ml_string_index;    /* index to display string array*/
  #endif
#endif
    GFX_UINT         alignment    :2; /* see above macro definitions  */
    GFX_UINT         orientation  :2; /* see above macro definitions  */
    GFX_UINT         draw_mode    :2; /* see above macro definitions  */
    GFX_UINT         clip_mode    :3; /* see above macro definitions  */
#if defined(GFX_MGR02_OPEN_GL) && (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    UINT8            glow_radius;	  /* radius/length value to be used for blur */
    GFX_FLOAT        glow_sigma;      /* sigma/weight/intensity value to be used for blur */
    GFX_UINT         glow_effect  :1; /* Enable/Disable Text glow effect for this element */
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
    GFX_UINT         scroll_mode  :1; /* Scroll mode as line/pixel       */
    GFX_UINT         wrap_mode    :1; /* Wrap mode as word wrap or none  */
#endif
    GFX_UINT         dynamic      :1; /* see above macro definitions     */
    GFX_UINT         scroll       :1; /* Enable/Disable Text Scroll      */

#if defined(GFX_MGR02_OPEN_GL) && (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
    GFX_UINT      text_cache   :1; /* cache_char enable/disable. Enable: char caching;Disable: String Caching*/
#endif
   UINT32         anim_id;         /* If animation property is enabled, this be valid text anim id else invalid text anim id */
  }GFX_MGR02_TEXT_DEF_T;

  typedef struct
  {
    GFX_UINT               alignment:2;
    GFX_UINT               draw_mode:2;
    GFX_UINT               clip_mode:3;
    GFX_UINT               unused1  :1;
    UINT8               font_id;
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)|| defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2) || defined(GFX_MGR02_VGLITE))
    UINT8                        font_pt_size;
#endif
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0) && (defined(GFX_MGR02_OPEN_VG)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_TRAVEO2))
    UINT8               num_of_display_lines;
    SINT8               inter_line_spacing; /* Spacing between multi lines     */
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
	UINT8               complex_script;
  #endif
#endif
    GFX_FLOAT           scroll_offset;
    GFX_MGR02_ISIZE_W_T width;        /* width of text area in pixels */
    GFX_MGR02_ALPHA     alpha;        /* alpha value                  */
    GFX_MGR02_COLOR     color;        /* draw color                   */
    GFX_MGR02_ILOC_DATA coord;        /* draw co ordinate             */
  #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
	  GFX_MGR02_TXT_SPECIAL_EFFECTS  txt_special_effects;
  #endif
  #if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
    UINT8            max_shrink;      /* Max percentage of shrink to be allowed*/
  #endif
  }GFX_MGR02_TEXT_DYN_PROPERTY;

  typedef struct
  {
    GFX_MGR02_ALPHA     alpha;
    UINT16              base_id;
    GFX_MGR02_ILOC_DATA coord;        /* draw co ordinate     */
    GFX_MGR02_COLOR     color;        /* draw color           */
    GFX_MGR02_COLOR     bg_color;     /* bg color             */
#if ((defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined (GFX_MGR02_TRAVEO2)) && defined(GFX_MGR02_CLIP_TEXT_ENABLE))
    UINT8               max_shrink;      /* Max percentage of shrink to be allowed*/
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL)||defined(GFX_MGR02_VGLITE)
    GFX_FLOAT               matrix[9];    /* transformation matrx */
#endif
#if defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)
    MM_FLOAT             matrix[9];
#endif
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined (GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
    GFX_MGR02_FLOC_DATA pivot;        /* pivot point          */
#endif
  }GFX_MGR02_TEXT_PROPERTY;

  typedef struct
  {
    HMI_CHAR const * print_str_P;
    UINT16           max_available_width;
    UINT16           print_width;
    UINT8            print_length_U8;
    UINT8            print_sindex_U8;
    UINT8            target;
    UINT8            append_str;
    UINT8            font_id;
    UINT8            clip_mode;
    UINT8            alignment;
  }GFX_MGR02_TEXT_CLIP;

  typedef struct
  {
    GFX_MGR02_TEXT_DEF_T const * dyn_text_def_SP;
    HMI_CHAR             const * print_str_P;
    GFX_MGR02_ILOC_DATA          coord;
    UINT16                       max_available_width;
    UINT16                       print_width;
    UINT16                       num_chars_to_process;
    UINT8                        print_length_U8;
    UINT8                        print_sindex_U8;
    UINT8                        target;
    UINT8                        db_format;
    UINT8                        append_str;
    GFX_UINT                     scroll       :1; /* Enable/Disable Text Scroll*/
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) || (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) || ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_VGLITE)||defined(GFX_MGR02_TRAVEO2))
    UINT8                        font_pt_size;
#endif
#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
    UINT8                        get_dynamic_clipinfo;
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
    UINT32                       pre_render_index;
#endif
#ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
   UINT8 is_complex;
   UINT16 str_offset_idx;
   UINT8  is_ml_data_still_exist;
#endif
  }GFX_MGR02_TEXT_INFO;

  typedef struct
  {
    HMI_CHAR             const * iostring;
    UINT16                       owidth;
    UINT16                       num_chars_to_process;
    UINT8                        ostr_length;
    GFX_UINT                     ifont_id:8;
    GFX_UINT                     oclip_flag:1;
    #if defined(GFX_MGR02_TRAVEO2)
    UINT16                       imax_available_width;
    #endif
    UINT8                        target;
#if (defined(GFX_MGR02_AMBER) || defined(GFX_MGR02_AMBER_IRIS) || defined(GFX_MGR02_TRAVEO2))
    UINT8                        oshrink; 
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (defined(GFX_MGR02_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2) ||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)|| ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)&&(defined(GFX_MONOTYPE_DYNAMIC_FONT_HEIGHT_SUPPORT))))))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
    UINT8                        font_pt_size;
#endif
  }GFX_MGR02_TEXT_WIDTH_INFO;

#ifdef GFX_MGR_APPEND_BASEDON_APP_IP
  typedef enum
  {
    LEFT_CLIP = 0,
    RIGHT_CLIP
  }GFX_CLIP_INFO;
#endif
  /* ----------------------------------------------------------------------------
  **                                OTHER DEFINITIONS
  ** --------------------------------------------------------------------------*/
  typedef struct
  {
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
    GFX_MGR02_FILL_DYN_PROPERTY     fill_prop[GFX_MGR02_NUM_FILL_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) ||defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)|| defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY fill_ovg_prop[GFX_MGR02_NUM_FILL_ANIM_ELEMENTS];
#endif
#endif

#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
    GFX_MGR02_TILE_DYN_PROPERTY     tile_prop[GFX_MGR02_NUM_TILE_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
    GFX_MGR02_OVG_EXTENDED_PROPERTY tile_ovg_prop[GFX_MGR02_NUM_TILE_ANIM_ELEMENTS];
#endif
#endif

#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
    GFX_MGR02_TEXT_DYN_PROPERTY     text_prop[GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY text_ovg_prop[GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_OF_DTEXTS > 0
    HMI_CHAR const * dtext_str;
#endif

#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
    GFX_MGR02_WIDGET_DYN_PROPERTY   widget_prop[GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY widget_ovg_prop[GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS];
#endif
#endif

#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
    GFX_MGR02_IMAGE_DYN_PROPERTY    image_prop[GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY image_ovg_prop[GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS];
#endif
#endif

#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
    GFX_MGR02_OVG_DYN_PROPERTY svg_prop[GFX_MGR02_NUM_SVG_ANIM_ELEMENTS];
#endif

#if GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS > 0
    /*
    ** Animation data for Screens, Dynamic Images and Dynamic widgets.
    */
    GFX_MGR02_ALPHA     group_alpha[GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS];
    GFX_MGR02_ILOC_DATA group_loc[GFX_MGR02_NUM_GROUP_ANIM_ELEMENTS];
#endif

    GFX_MGR02_ILOC_DATA   layer_loc[GFX_MGR02_NUM_LAYERS];
    GFX_MGR02_ALPHA       layer_alpha[GFX_MGR02_NUM_LAYERS];
    GFX_MGR02_COLOR       layer_color[GFX_MGR02_NUM_LAYERS];

#if GFX_MGR02_NUM_USER_LAYERS > 0
    GFX_MGR02_IMAGE_DEF_T user_image_layer[GFX_MGR02_NUM_USER_LAYERS];
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
    GFX_MGR02_IMAGE_DYN_PROPERTY user_prop[GFX_MGR02_NUM_USER_ANIM_ELEMENTS];
#if defined(GFX_MGR02_OPEN_VG) || defined(GFX_MGR02_OPEN_GL) || defined(GFX_MGR02_FUJITSU)||defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE)
    GFX_MGR02_OVG_EXTENDED_PROPERTY user_ovg_prop[GFX_MGR02_NUM_USER_ANIM_ELEMENTS];
#endif
#endif
#endif
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
    GFX_MGR02_IMAGE_DEF_T mdl_3d_layer[GFX_MGR02_NUM_3D_MDL_LAYERS];
#endif
  }GFX_MGR02_ANIM_DATA_T;

#if defined(GFX_MGR02_FUJITSU) && defined(GFX_MGR02_IRIS_PIXEL_POKING)
  typedef struct
  {
    UINT16 pos_x_U16;
    UINT16 pos_y_U16; 
    UINT8  red_component_U8;
    UINT8  green_component_U8;
    UINT8  blue_component_U8;

  }GFX_MGR02_PIXEL_DATA;

  typedef struct
  {
    GFX_MGR02_PIXEL_DATA  pixel_data; 
    BOOLEAN               status;
  }GFX_MGR02_SET_PIXEL_DATA;

  typedef enum
  {
    GFX_MGR02_PIXEL_POKING_NO_ERROR,
    GFX_MGR02_ERROR_COORD_OUT_OF_RANGE,
    GFX_MGR02_ERROR_INVALID_BUFFER
  }GFX_MGR02_PIXEL_POKING_STATUS;

#define GFX_MGR02_SET_PIXEL_BUFFER_INACTIVE   (0x00)
#define GFX_MGR02_SET_PIXEL_BUFFER_ACTIVE     (0x01)
#define GFX_MGR02_RGB565(r, g, b)             (((UINT16)((UINT16)((UINT16)(((UINT16)r)>>3U))<<11U)) | ((UINT16)((UINT16)((UINT16)(((UINT16)g)>>2U))<<5U)) | ((UINT16)((UINT16)((UINT16)b)>>3U)))

#define GFX_MGR02_INVALID_PIXEL_DATA  {(UINT16)0xFFFF, /* X - COORD       */ \
  (UINT16)0xFFFF, /* Y - COORD       */ \
  (UINT8)0xFF,   /* Red Component   */ \
  (UINT8)0xFF,   /* Green Component */ \
  (UINT8)0xFF}   /* Blue Component  */ 



#endif

#define GFX_MGR02_IS_ELEM_CHANGED(flag_array, obj_id) ((((flag_array)[(UINT8)(((UINT16)(obj_id))>>3U)]) & ((UINT8)((UINT8)1<<((UINT8)(((UINT16)(obj_id))&0x07U))))) != (UINT8)0)

#define GFX_MGR02_INVALID_ID               (0xFFFFFFFFU)
#define GFX_MGR02_INVALID_TYPE             (0xFFFFFFFFU)
#define GFX_MGR02_INVALID_BASE_ID          (0xFFFFU)
#define GFX_NO_CLIP                        (0xFFFFU)

  
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
  #define GFX_MGR02_GPOS_M2M_TBL     (0U)
  #define GFX_MGR02_GPOS_M2B_TBL     (1U)
  #define GFX_MGR02_GPOS_M2L_TBL     (2U)
  #define GFX_MGR02_GPOS_INVALID_TBL (3U)
#endif 

#define IMXRT_1050_ELCDIF            0
#define IMXRT_1170_ELCDIF            1
#define IMXRT_1170_LCDIFV2           2


  /*============================================================================
  ** E N T R Y   P O I N T S
  **==========================================================================*/

#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
  extern void hmi_gfx_mgr02_app_touch_event_handler(UINT32 p_obj_id, GFX_MGR02_TOUCH_QDATA * p_event);
#endif

  /*============================================================================
  ** D A T A   A C C E S S   S E R V I C E S
  **==========================================================================*/

#if defined(GFX_MGR02_STEXTS_BUFFER_SIZE) && (GFX_MGR02_STEXTS_BUFFER_SIZE > 0)
  extern HMI_CHAR                  const lc_static_text_buffer[GFX_MGR02_STEXTS_BUFFER_SIZE];
#endif
#if GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_IMAGE_DEF_T     const* lc_image_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_IMAGE_DEF_T     const lc_image_layer_def_S[GFX_MGR02_NUM_OF_IMAGE_LAYERS];
#endif
#endif
#if GFX_MGR02_NUM_OF_TEXT_LAYERS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TEXT_DEF_T      const* lc_text_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TEXT_DEF_T      const lc_text_layer_def_S[GFX_MGR02_NUM_OF_TEXT_LAYERS];
#endif
#endif
#if GFX_MGR02_NUM_OF_SVGS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_OVG_OBJECT_T    const* lc_svg_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_OVG_OBJECT_T    const lc_svg_layer_def_S[GFX_MGR02_NUM_OF_SVGS];
#endif
#if GFX_MGR02_NUM_OF_SVG_CLIPS > 0
  extern GFX_MGR02_IAREA_DATA const lc_svg_clip_area_SA[GFX_MGR02_NUM_OF_SVG_CLIPS];
#endif
#endif
#if GFX_MGR02_NUM_OF_FILLS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_FILL_DEF_T      const* lc_fill_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_FILL_DEF_T      const lc_fill_layer_def_S[GFX_MGR02_NUM_OF_FILLS];
#endif
#endif
#if GFX_MGR02_NUM_OF_TILES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TILE_DEF_T      const* lc_tile_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TILE_DEF_T      const lc_tile_layer_def_S[GFX_MGR02_NUM_OF_TILES];
#endif
#endif
#if GFX_MGR02_NUM_OF_SWDGS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_WIDGET_DEF_T const* lc_swidget_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_WIDGET_DEF_T const lc_swidget_layer_def_S[GFX_MGR02_NUM_OF_SWDGS];
#endif
#endif
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_VISIBLE_AREA const* lc_elem_area_offset_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_VISIBLE_AREA const lc_elem_area_offset_SA[GFX_MGR02_NUM_VISIBLE_AREA];
#endif
#if GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_IMAGE_PROPERTY const* lc_img_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_IMAGE_PROPERTY const lc_img_anim_property_S[GFX_MGR02_NUM_IMAGE_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_SVG_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_OVG_PROPERTY const* lc_svg_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_OVG_PROPERTY const lc_svg_anim_property_S[GFX_MGR02_NUM_SVG_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_USER_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_IMAGE_PROPERTY const* lc_user_img_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_IMAGE_PROPERTY const lc_user_img_anim_property_S[GFX_MGR02_NUM_USER_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_FILL_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_FILL_PROPERTY const* lc_fill_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_FILL_PROPERTY const lc_fill_anim_property_S[GFX_MGR02_NUM_FILL_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_TILE_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TILE_PROPERTY const* lc_tile_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TILE_PROPERTY const lc_tile_anim_property_S[GFX_MGR02_NUM_TILE_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TEXT_PROPERTY const* lc_text_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TEXT_PROPERTY const lc_text_anim_property_S[GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_WIDGET_PROPERTY const* lc_widget_anim_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_WIDGET_PROPERTY const lc_widget_anim_property_S[GFX_MGR02_NUM_WIDGET_ANIM_ELEMENTS];
#endif
#endif
#if GFX_MGR02_NUM_SIMAGE_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_IMAGE_PROPERTY const* lc_img_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_IMAGE_PROPERTY const lc_img_const_property_S[GFX_MGR02_NUM_SIMAGE_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_FILL_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_FILL_PROPERTY const* lc_fill_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_FILL_PROPERTY const lc_fill_const_property_S[GFX_MGR02_NUM_FILL_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_TILE_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TILE_PROPERTY const* lc_tile_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TILE_PROPERTY const lc_tile_const_property_S[GFX_MGR02_NUM_TILE_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_TEXT_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_TEXT_PROPERTY const* lc_text_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_TEXT_PROPERTY const lc_text_const_property_S[GFX_MGR02_NUM_TEXT_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_SWDG_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_WIDGET_PROPERTY const* lc_swdg_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_WIDGET_PROPERTY const lc_swdg_const_property_S[GFX_MGR02_NUM_SWDG_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_SVG_INSTANCES > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_OVG_PROPERTY const* lc_svg_const_property_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_OVG_PROPERTY const lc_svg_const_property_S[GFX_MGR02_NUM_SVG_INSTANCES];
#endif
#endif
#if GFX_MGR02_NUM_OF_SCREENS > 0
  extern GFX_MGR02_SCREEN_DEF_T const lc_screen_def_S[GFX_MGR02_NUM_OF_SCREENS];
#endif
#if GFX_MGR02_NUM_LAYERS > 0
  extern GFX_MGR02_LAYER_DEF_T const lc_layer_def_S[GFX_MGR02_NUM_LAYERS];
#if defined(GFX_MGR02_MONOTFT)
  extern GFX_MGR02_PIXEL_DEF_T const lc_pixel_def_S[GFX_MGR02_NUM_LAYERS];
#endif
#endif
#if GFX_MGR02_NUM_USER_LAYERS > 0
#if defined(GFX_MGR02_DLAYOUT_ENABLED)
  extern GFX_MGR02_IMAGE_DEF_T const* lc_user_image_layer_def_SP[GFX_MGR02_NUM_OF_LAYOUTS];
#else
  extern GFX_MGR02_IMAGE_DEF_T const lc_user_image_layer_def_S[GFX_MGR02_NUM_USER_LAYERS];
#endif
#endif
#if GFX_MGR02_NUM_3D_MDL_LAYERS > 0
  extern GFX_MGR02_IMAGE_DEF_T const lc_3d_image_layer_def_S[GFX_MGR02_NUM_3D_MDL_LAYERS];
#endif

#if GFX_MGR02_NUM_VIDEO_LAYERS > 0
    extern GFX_MGR02_VIDEO_DEF_T const lc_video_layer_def_S;
#endif

#if GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS > 0
    extern  GFX_MGR02_IMAGE_DEF_T const lc_runtime_wdg_image_layer_def_S[GFX_MGR02_NUM_RUNTIME_WDG_IMG_LAYERS];
#endif

  /*============================================================================
  **
  **============================================================================
  ** C M S    R E V I S I O N    N O T E S
  **============================================================================
  **
  ** For each change to this file, be sure to record:
  ** 1.  Who made the change and when the change was made.
  ** 2.  Why the change was made and the intended result.
  **
  ** CMS Rev #        Date         By
  ** CMS Rev X.X      mm/dd/yy     CDSID
  **
  **============================================================================
  ** CMS Rev 1.46     19-Jan-2018     ARAJASE2
  ** 1035451: GPOS X Position update for Thai Language
  ** hmi_gfx_mgr02_get_gpos_delta_pixels function prototype changed to return the status of
  ** GPOS table availability for the given characters
  **
  ** CMS Rev 1.45      19-Dec-2017     sbollam
  ** Added Harfbuzz and WorldType shape engine support.
  ** Ref Task : 978896
  **
  ** CMS Rev 1.44     20-Dec-2017    ARAJASE2
  ** 1021315: Multiple GPOS table support in graphic manager
  ** GFX_MGR02_GPOS_TABLE structure modified to handle more than one GPOS table for the same type
  ** Below structures are added to represent differect GPOS table types
  **    GFX_MGR02_GPOS_M2L_TABLE – Mark To Ligature
  **    GFX_MGR02_GPOS_M2M_TABLE – Mark To Mark
  **    GFX_MGR02_GPOS_M2B_TABLE – Mark To Base
  **
  ** CMS Rev 1.43     18-Dec-2017    KKUBENDI
  ** RTC 985451:
  ** Updated GPOS_TABLE for Mark To Mark.
  ** CMS Rev 1.42     18-Sep-2017    ARAJASE2
  ** 921462: Dynamic Font update issue in Amber platform with External font
  ** GFX_MGR02_FONT_SIZE_T font_size member added in GFX_MGR02_TEXT_WIDTH_INFO and GFX_MGR02_TEXT_INFO structure
  **
  ** CMS Rev 1.41     21-Aug-2017    CSAKTHIV
  ** RTC 939063:
  ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
  **
  ** CMS Rev 1.40     08-Aug-2017    ARAJASE2
  ** New member inter_line_spacing added in GFX_MGR02_TEXT_DYN_PROPERTY structure 
  ** to support dynamic update of inter line spacing
  ** 922409: Dynamic Inter-line spacing for multi-line text
  **
  ** CMS Rev 1.39     04/08/17    ADEVI
  ** 924879 : Monotype Font Integration in Kepler I.
  **
  ** CMS Rev 1.38    24-Jul-2017    SBOLLAM
  ** RTC ID: 917605: Implemented GPOS- MarkToLigature table
  **
  ** CMS Rev 1.37    29-Jun-2017    SSRINI19
  ** 880883 : GM-CHUD QAC MISRA additional warning fixes
  **
  ** CMS Rev 1.36     06-JUL-2017    ADEVI
  ** RTC ID: 871825:  Changes to support MONOTFT Platform
  **
  ** CMS Rev 1.35     17-May-2017    ADEVI
  ** 868932: UI Core : Multi line max char support for 400char
  **
  ** CMS Rev 1.34     10-Feb-2017    KKUBENDI
  ** 800730: GfxMgr02/Luxoft: Change type of "string_index" in GFX_MGR02_TEXT_DEF_T from UINT16 to UINT32
  **
  ** CMS Rev 1.33     15-Dec-2016    SSIGAMAN
  ** 766753: BAIC:Provide option to allocate memory for frame buffer in HRAM
  ** Added use_extram in widget definition structure.
  ** 
  ** CMS Rev 1.32     15-Sep-16    SBOLLAM
  ** GPOS handling through mono type font engine
  ** Ref RTC# 695578.
  **
  ** CMS Rev 1.31     9-Sep-16    ADEVI
  ** Touch screen related application configurations moved to cfg file from types.h
  ** Ref RTC# 691077.
  **
  ** CMS Rev 1.30      22-Jul-2016    CMUTHUSA
  ** 642213: Coding and implementation in GDT simulation for Arabic Design Layout support in gfx mgr 02.
  **
  ** CMS Rev 1.29     08-JULY-2016    SSIGAMAN
  ** 639042: Porsche Misra warning Fix
  **
  ** CMS Rev 1.28     02-JUN-2016    CSAKTHIV
  ** 566848: Thai support using GSUB table
  **
  ** CMS Rev 1.27     28-Apr-2016    ADEVI
  ** 578262: Add dynamic change of size of the used TTF fonts
  ** Added GFX_MGR02_FONT_SIZE_T structure and font_size as member 
  ** for GFX_MGR02_TEXT_DYN_PROPERTY
  **
  ** CMS Rev 1.26     24-Mar-2016    SSIGAMAN
  ** 554985: Amber:AutoHint status update changes
  ** Added is_autohint as member for the GFX_MGR02_FONT structure.
  **
  ** CMS Rev 1.25     5-Feb-2015    APERUMAL
  ** RTC 512949:
  ** Compiler warnings fix for B515
  **
  ** CMS Rev 1.24     11-Jan-2016   SSIGAMAN
  ** Ref RTC#
  ** Warping Integration
  ** 
  ** CMS Rev 1.23     29-Jan-2015    APERUMAL
  ** RTC 507885:
  ** QAC warnings fix for Honda Thaa
  **
  ** CMS Rev 1.22     28-Dec-2015   CSAKTHIV
  ** Ref RTC# 490199
  ** Monotype Integration
  ** 
  ** CMS Rev 1.21     23-Nov-2015    CSAKTHIV      RTC 400575
  ** Text caching for std+ china 
  **
  ** CMS Rev 1.20     28-Oct-2015    ADEVI         RTC 412568
  ** Multi line text Implementation - Initial Version.
  **
  ** CMS Rev 1.19     01-Oct-2015   APERUMAL
  ** Ref RTC# 430225
  ** Included Property for Scrolling
  **
  ** CMS Rev 1.18     15-Sep-2015   SSIGAMAN
  ** Ref RTC# 370662.
  ** "extfontsize" is added as member in GFX_MGR02_FONT to support freetype font
  ** rendering using Draw Engine.
  **
  ** CMS Rev 1.17     07-Sep-2015   SBOLLAM
  ** Ref RTC# 404998.
  ** To support Text glow
  ** GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20
  **
  ** CMS Rev 1.16     07-Jul-2015   EMANOJ1
  ** Ref RTC# 373900.
  ** To support Gesture events
  ** 
  ** CMS Rev 1.15     25-May-2015    ADEVI
  ** RTC 323189: Implementation of iris pixel poking feature.
  **
  ** CMS Rev 1.14     11-Nov-2014    ADEVI
  ** Ref RTC# 204201.
  ** Variable scroll_offset is added in GFX_MGR02_TEXT_DYN_PROPERTY structure.
  **
  ** CMS Rev 1.13     10-Nov-2014    EMANOJ1
  ** Updated to add Amber image compression format configurations in to image def
  ** data structure.
  **
  ** CMS Rev 1.12     23-Oct-2014    EMANOJ1
  ** RTC #227329 : Added support for VG_sXRGB_8888
  **
  ** CMS Rev 1.11    16-Oct-2014    CSAKTHIV
  ** GFX_MGR02_MOUSE_FREEZE bit mask added for hmi_gfx_mgr02_layout_freeze_touch_event()
  **
  ** CMS Rev 1.10    25-Nov-2013    CMUTHUSA
  ** Fujitsu Platform modifications added to changeset base rel_UI.CORE.3.12.08 version
  **
  ** CMS Rev 1.9      19-Mar-2014    EMANOJ1
  ** Added GFX_MGR02_FONT_CHAR_METRICS type to return the char metrics to
  ** application
  **
  ** CMS Rev 1.8      19-Sep-2013    EMANOJ1
  ** Updated to support multi color text
  **
  ** CMS Rev 1.7      19-Aug-2013    EMANOJ1
  ** Added a target parameter for text width calculation and printing as the 
  ** eDMA based printing is updated to make odd widths to even widths when the 
  ** font BPP is set to 4BPP. This is done to prevent zero gap issue between
  ** character issue noted in Nissan P42
  **
  ** CMS Rev 1.6      20-Jun-2013    EMANOJ1
  ** Updated to add element opeque status bit to support element visibility
  ** check by DAR to speed up rendering by removal of invisible elements from 
  ** rendering.
  **
  ** CMS Rev 1.5      05-Jun-13    EMANOJ1
  ** Support for vector fonts added
  **
  ** CMS Rev 1.4      08-Apr-13    EMANOJ1
  ** Touch event handler is updated to pass the touch data structure pointer itself
  ** to allow application to read the touch co-ordinate information as well. To do
  ** this added a new application callback function prototype to pass the touch
  ** events "hmi_gfx_mgr02_app_touch_event_handler"
  ** A flag bit is added to mouse event value to indicate whether the touch point
  ** went out of bound after an element is touched. This is a sticky bit which 
  ** remains '1' from the point moves outof bound till the touch is released.
  ** New macro GFX_MGR02_GET_MOUSE_EV() added to just extract the mouse events
  ** from the encoded event
  ** 
  ** CMS Rev 1.3      21-Mar-13    VMUTHUSU
  ** Added GFX_MGR02_NULL_PTR
  **
  ** CMS Rev 1.2      18-Mar-13    EMANOJ1
  ** Updated to support clipping for SVG images
  **
  ** CMS Rev 1.1      20-Feb-13    ASHEKHAR
  ** Added legacy interface structure definitions.
  **
  ** CMS Rev 1.0      08-Aug-12    EMANOJ1
  ** Creation.
  **
  **==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
