/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2013. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_irislib.c
 **
 ** Description:    FUJITSU(IRIS HW) library interface routines to perform drawing
 **                 operations for graphics manager 02.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define GUI_GFX_MANAGER_IRISLIB_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_FUJITSU)
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_irislib.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_clut_table.h"
#include "sm_util.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/


#define GFX_MGR02_IRISLIB_FLUSH_PENDING     (0x01)
#define GFX_MGR02_IRISLIB_FB_UPDATED        (0x02)
#define MML_GDC_NUM_SURF_FORMAT             (0x13)

#define GM2_IRIS_R(argb)  ((MM_U08)(((argb) >> 16) & ((MM_U32)0xFF)))
#define GM2_IRIS_G(argb)  ((MM_U08)(((argb) >>  8) & ((MM_U32)0xFF)))
#define GM2_IRIS_B(argb)  ((MM_U08)(((argb) >>  0) & ((MM_U32)0xFF)))
#define GM2_IRIS_A(argb)  ((MM_U08)(((argb) >> 24) & ((MM_U32)0xFF)))

#ifdef GFX02_DEBUG_FUJITSU
 #define gfx_debug_iris gfx_debug
#else
 #define gfx_debug_iris
#endif


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/
static void hmi_gfx_mgr02_iris_get_matrix(MM_FLOAT * p_dst_matrix,MM_FLOAT const * p_src_matrix);
/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

static  MM_U08   l_irislib_draw_sts;
#ifdef GFX02_MGR02_IRIS_METRICS
static MM_U32 l_instr_bf_size,l_instr_bf_size_max;
#endif


typedef struct {
    MM_U32  ColorComponentBits; /* Defines the number of bits for each color component in the form 0xRRGGBBAA */
    MM_U32  ColorComponentShift; /* Defines bits position for each color component in the form 0xRRGGBBAA */
    /*    MM_U16  strideInByte; */  /* Stride in size */
    MM_U08   totalBits;      /* Number of bits used for one pixel */
    MML_GDC_SURF_FORMAT surf_format; /* Defines the image format 0xRRGGBBAA */

}MML_GDC_IMAGE_T;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
 static HMI_CHAR l_irislib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif

#ifdef GFX_MGR02_IRIS_PIXEL_POKING
static GFX_MGR02_SET_PIXEL_DATA l_iris_SetPixelDataBuffer[MAX_NO_OF_SET_PIXEL_BUFFERS];
static void hmi_gfx_mgr02_irislib_buffer_data_updation(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
#endif

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_init(void)
{
    l_irislib_draw_sts = (MM_U08)0;
    #ifdef GFX_MGR02_IRIS_PIXEL_POKING
      hmi_gfx_mgr02_irislib_init_pixel_buffer();
    #endif
    return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
    MM_S32 ret = MML_OK;
    l_irislib_draw_sts = (MM_U08)0;

#ifdef GFX_MGR02_DRIVER_SINGLE_FB
    UTIL_SUCCESS(ret, mmlGdcSyncForDispFrameEnd());
#else
    UTIL_SUCCESS(ret, mmlGdcSyncForDispReady());
#endif
   GFX_MGR02_UNUSED_PTR(p_cntx_SP);
    return((s_gx_flocal)TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP,
    GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
    MM_S32 ret = MML_OK;
    MM_U32 fl_fg_color;
    MM_U16 fl_alpha_temp;
    MM_U08 fl_rgba[4];
    MM_FLOAT fl_matrix1[6], fl_matrix2[6], fl_cntx_matrix[6];
    MML_GDC_SURFACE_CONTAINER     fl_mml_gdc_src_surf_c;
    MML_GDC_SURFACE               fl_mml_gdc_src_surf;
	BOOLEAN fl_ret_sts;

    if(p_cntx_SP->state.invisible == (UINT8)0)
    {

        fl_mml_gdc_src_surf =&fl_mml_gdc_src_surf_c;
        UTIL_SUCCESS(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_src_surf));

        UTIL_SUCCESS(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_src_surf, (MM_U32)p_elem_def_SP->width, (MM_U32)p_elem_def_SP->height, (MML_GDC_SURF_FORMAT)p_elem_def_SP->format, (void *)p_elem_def_SP->pixel_data,(MM_U32) 0));

        #if GFX_MGR02_NUM_OF_CLUTS > 0
        if(p_elem_def_SP->clut!=(UINT16)GFX_MGR02_NUM_OF_CLUTS)
        {
            GFX_MGR02_CLUT_DATA const * fl_elem_clut_SP = &lc_gfx_mgr02_clut_array[p_elem_def_SP->clut];

            UTIL_SUCCESS(ret, mmlGdcSmAssignClut(fl_mml_gdc_src_surf,MML_GDC_SURF_CLM_LUT,(MM_U32)fl_elem_clut_SP->CLUTsize,(MML_GDC_SURF_CLF)0,(void *)fl_elem_clut_SP->CLUT));

            UTIL_SUCCESS(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_CLUTBITPERPIXEL, (MM_U32)0x20));
            UTIL_SUCCESS(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_CLUTCOLORBITS, (MM_U32)0x08080808));
            UTIL_SUCCESS(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_CLUTCOLORSHIFT, (MM_U32)0x10080018)); /*A8R8G8B8 Format data input in CLut table*/
        }
        #endif
        if(p_elem_def_SP->format == (UINT8)MML_GDC_SURF_FORMAT_R4G4B4A4)
        {
            UTIL_SUCCESS(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (MM_U32)0x0804000C));
        }

        if(p_elem_def_SP->format == (UINT8)MML_GDC_SURF_FORMAT_RGB8A8)
        {
            UTIL_SUCCESS(ret, mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (MM_U32)0x00000008));
        }

        fl_fg_color =p_cntx_SP->rprop.fg_color;
        fl_rgba[0]=GM2_IRIS_R(fl_fg_color);  /* R */
        fl_rgba[1]=GM2_IRIS_G(fl_fg_color);  /* G */
        fl_rgba[2]=GM2_IRIS_B(fl_fg_color);  /* B */
        fl_rgba[3]=GM2_IRIS_A(fl_fg_color);  /* A */

     #if 0
        if(p_elem_def_SP->format == (UINT8)MML_GDC_SURF_FORMAT_A8L)
        {

            mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORBITS, (MM_U32)0x08080808);
            mmlGdcSmSetAttribute(fl_mml_gdc_src_surf, MML_GDC_SURF_ATTR_COLORSHIFT, (MM_U32)0x00000000);
            mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_DST, fl_mml_gdc_src_surf);
            mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC | MML_GDC_PE_STORE, p_cntx_SP->rprop.pe_tsurf);

        }
        else
     #endif
        {
            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_mml_gdc_src_surf));
            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_DST | MML_GDC_PE_STORE, p_cntx_SP->rprop.pe_tsurf));
        }

        // prepare matrix array for surfaces
        Mat3x2LoadIdentity(fl_matrix1);
        Mat3x2Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
        hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,&p_cntx_SP->state.matrix[0]);
        Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
        Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));

      #if 0
        if(p_elem_def_SP->format==MML_GDC_SURF_FORMAT_A8L)
        {
            fl_alpha_temp = (MM_U16)(fl_rgba[3]*p_cntx_SP->state.alpha);
            fl_rgba[3] =(MM_U08)(fl_alpha_temp/0xFF);

          
          UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_DST, fl_matrix2));
          UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx,MML_GDC_PE_DST, 0, 0, 0, fl_rgba[3]));
              UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx,MML_GDC_PE_SRC, 0, 0, 0, 255));

              UTIL_SUCCESS(ret, mmlGdcPeBlendMode(p_cntx_SP->rprop.pe_ctx,
                MML_GDC_PE_BM_VG_BLEND_MULTIPLY, \
                MML_GDC_PE_BM_VG_BLEND_MULTIPLY, \
                MML_GDC_PE_BM_VG_BLEND_MULTIPLY, \
                MML_GDC_PE_BM_VG_BLEND_MULTIPLY));

        }
        else
      #endif
        {
            UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_matrix2));
        }

        if((p_cntx_SP->state.alpha<255)||(fl_rgba[3]<255)||(p_elem_def_SP->format==MML_GDC_SURF_FORMAT_A8)||(p_elem_def_SP->format==MML_GDC_SURF_FORMAT_A1))
        {
            fl_alpha_temp = (((MM_U16)fl_rgba[3])*((MM_U16)p_cntx_SP->state.alpha));
            fl_rgba[3] =(MM_U08)(fl_alpha_temp/((MM_U16)0xFF));

            UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx,MML_GDC_PE_SRC, fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]));

            UTIL_SUCCESS(ret, mmlGdcPeBlendMode(p_cntx_SP->rprop.pe_ctx,
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD));

                UTIL_SUCCESS(ret, mmlGdcPeBlendFunc(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA));

            UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_COLORMULTI, (MM_U32)MM_TRUE));
            UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_ALPHAMULTI, (MM_U32)MM_TRUE));
        }


        UTIL_SUCCESS(ret, mmlGdcPeBlt(p_cntx_SP->rprop.pe_ctx, (MM_FLOAT)0,(MM_FLOAT)0));
        l_irislib_draw_sts = (MM_U08)(GFX_MGR02_IRISLIB_FLUSH_PENDING|GFX_MGR02_IRISLIB_FB_UPDATED);

    }

    if(ret==MML_OK)
	{	
		fl_ret_sts = (BOOLEAN)TRUE;
    }
	else
	{
        fl_ret_sts = (BOOLEAN)FALSE; 
	}
	return((s_gx_flocal)fl_ret_sts);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_build_fill
Description          : Builds a fill object
Invocation           : Invoked internally
Parameters           : element definition and dimention of fill area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
    GFX_MGR02_FILL_DEF_T const * p_elem_def_SP,
    GFX_MGR02_IDIM_DATA  const * p_dim)
{
    MM_S32 ret = MML_OK;
    MM_U32 fl_fg_color;
    MM_U16 fl_alpha_temp;
    MM_U08 fl_rgba[4];
    MM_FLOAT fl_matrix1[6], fl_matrix2[6], fl_cntx_matrix[6];
    MML_GDC_SURFACE_CONTAINER     fl_mml_gdc_src_surf_c;
    MML_GDC_SURFACE               fl_mml_gdc_src_surf;
	BOOLEAN fl_ret_sts;

    if(p_cntx_SP->state.invisible == 0)
    {
        fl_fg_color =p_cntx_SP->rprop.fg_color;
        fl_rgba[0]=GM2_IRIS_R(fl_fg_color); /* R */
        fl_rgba[1]=GM2_IRIS_G(fl_fg_color); /* G */
        fl_rgba[2]=GM2_IRIS_B(fl_fg_color); /* B */
        fl_rgba[3]=GM2_IRIS_A(fl_fg_color); /* A */


        fl_mml_gdc_src_surf =&fl_mml_gdc_src_surf_c;
        UTIL_SUCCESS(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_src_surf));

        UTIL_SUCCESS(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_src_surf, (MM_U32)p_elem_def_SP->dim.width, (MM_U32)p_elem_def_SP->dim.height, MML_GDC_SURF_FORMAT_A8B8G8R8, 0, (MM_U32)0));

        UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_mml_gdc_src_surf));


        // prepare matrix array for surfaces
        Mat3x2LoadIdentity(fl_matrix1);
        Mat3x2Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
        hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,&p_cntx_SP->state.matrix[0]);
        Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
        Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
        UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_matrix2));

        if((p_cntx_SP->state.alpha<255)||(fl_rgba[3]<255))
        {
            fl_alpha_temp = (((MM_U16)fl_rgba[3])*((MM_U16)p_cntx_SP->state.alpha));
            fl_rgba[3] =(MM_U08)(fl_alpha_temp/((MM_U16)255));
            UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]));

            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_STORE | MML_GDC_PE_DST, p_cntx_SP->rprop.pe_tsurf));

            UTIL_SUCCESS(ret, mmlGdcPeBlendMode(p_cntx_SP->rprop.pe_ctx,
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD, \
                MML_GDC_PE_BM_GL_FUNC_ADD));

            UTIL_SUCCESS(ret, mmlGdcPeBlendFunc(p_cntx_SP->rprop.pe_ctx,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ONE));
        }
        else
        {
            UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]));
            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_STORE, p_cntx_SP->rprop.pe_tsurf));
        }

        UTIL_SUCCESS(ret, mmlGdcPeBlt(p_cntx_SP->rprop.pe_ctx,(MM_FLOAT)0,(MM_FLOAT)0));
        l_irislib_draw_sts = (MM_U08)(GFX_MGR02_IRISLIB_FLUSH_PENDING|GFX_MGR02_IRISLIB_FB_UPDATED);

    }
    if(ret==MML_OK)
	{	
		fl_ret_sts = (BOOLEAN)TRUE;
    }
	else
	{
        fl_ret_sts = (BOOLEAN)FALSE; 
	}
   GFX_MGR02_UNUSED_PTR(p_dim);
	return((s_gx_flocal)fl_ret_sts);
}
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_build_tile
Description          : Builds a tile object
Invocation           : Invoked internally
Parameters           : element definition and dimention of tile area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_build_tile(GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
    GFX_MGR02_TILE_DEF_T const * p_elem_def_SP,
    GFX_MGR02_IDIM_DATA  const * p_dim)
{
    BOOLEAN fl_ret_sts = (BOOLEAN)TRUE;
    MM_S32 ret;
    MM_U32 fl_fg_color;
    MM_U16 fl_alpha_temp;
    MM_U16 fl_img_width, fl_img_height, fl_img_draw_x, fl_img_draw_y, fl_tile_end_x, fl_tile_end_y;
    MM_U08 fl_rgba[4];
    MM_U08 fl_format_index_u8;
    MM_FLOAT fl_matrix1[6], fl_matrix2[6], fl_cntx_matrix[6];
    MML_GDC_SURFACE_CONTAINER     fl_mml_gdc_src_surf_c;
    MML_GDC_SURFACE               fl_mml_gdc_src_surf;

    if(p_cntx_SP->state.invisible == 0)
    {

        GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP = &lc_image_layer_def_S[p_elem_def_SP->id];

        fl_mml_gdc_src_surf =&fl_mml_gdc_src_surf_c;
        mmlGdcSmResetSurfaceObject(fl_mml_gdc_src_surf);

        UTIL_SUCCESS(ret, mmlGdcSmAssignBuffer(fl_mml_gdc_src_surf, fl_element_def_SP->width, fl_element_def_SP->height, fl_element_def_SP->format, (void *)fl_element_def_SP->pixel_data, 0));

        if(ret==MML_OK)
        {

            fl_fg_color =p_cntx_SP->rprop.fg_color;
            fl_rgba[0]=GM2_IRIS_R(fl_fg_color);  /* R */
            fl_rgba[1]=GM2_IRIS_G(fl_fg_color);  /* G */
            fl_rgba[2]=GM2_IRIS_B(fl_fg_color);  /* B */
            fl_rgba[3]=GM2_IRIS_A(fl_fg_color);  /* A */
            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_mml_gdc_src_surf));

            // prepare matrix array for surfaces
            Mat3x2LoadIdentity(fl_matrix1);
            Mat3x2Translate(fl_matrix1, (GFX_FLOAT)p_cntx_SP->state.loc.x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
            hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,(void *)&p_cntx_SP->state.matrix[0]);
            Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
            Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
            UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_matrix2));


            if((p_cntx_SP->state.alpha<255)||(fl_rgba[3]<255)||(fl_element_def_SP->format==MML_GDC_SURF_FORMAT_A8)||(fl_element_def_SP->format==MML_GDC_SURF_FORMAT_A1))
            {
                fl_alpha_temp = (MM_U16)(fl_rgba[3]*p_cntx_SP->state.alpha);
                fl_rgba[3] =(MM_U08)(fl_alpha_temp/0xFF);

                UTIL_SUCCESS(ret, mmlGdcPeSurfColor(p_cntx_SP->rprop.pe_ctx,MML_GDC_PE_SRC, fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]));

                UTIL_SUCCESS(ret, mmlGdcPeBlendMode(p_cntx_SP->rprop.pe_ctx,
                    MML_GDC_PE_BM_GL_FUNC_ADD, \
                    MML_GDC_PE_BM_GL_FUNC_ADD, \
                    MML_GDC_PE_BM_GL_FUNC_ADD, \
                    MML_GDC_PE_BM_GL_FUNC_ADD));

                UTIL_SUCCESS(ret, mmlGdcPeBlendFunc(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                    MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA));

                UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_COLORMULTI, MM_TRUE));
                UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_ALPHAMULTI, MM_TRUE));

            }

            UTIL_SUCCESS(ret, mmlGdcPeSelectArea(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_STORE));

            fl_tile_end_x = p_cntx_SP->state.loc.x + p_elem_def_SP->dim.width;
            fl_tile_end_y = p_cntx_SP->state.loc.y + p_elem_def_SP->dim.height;
            fl_img_height = fl_element_def_SP->height;

            for (fl_img_draw_y = p_cntx_SP->state.loc.y; fl_img_draw_y < (fl_tile_end_y); fl_img_draw_y+= fl_img_height)
            {

                fl_img_width = fl_element_def_SP->width;

                if(fl_img_height <=(fl_tile_end_y - fl_img_draw_y))
                {
                    fl_img_height = fl_img_height;
                }
                else
                {
                    fl_img_height = fl_tile_end_y - fl_img_draw_y;

                }

                for (fl_img_draw_x = p_cntx_SP->state.loc.x; fl_img_draw_x < (fl_tile_end_x); fl_img_draw_x+= fl_img_width)

                {

                    if(fl_img_width <= (fl_tile_end_x - fl_img_draw_x))
                    {
                        fl_img_width = fl_img_width;
                    }
                    else
                    {
                        fl_img_width = fl_tile_end_x - fl_img_draw_x;

                    }
                    UTIL_SUCCESS(ret, mmlGdcPeActiveArea(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_STORE, fl_img_draw_x, fl_img_draw_y, fl_img_width, fl_img_height));

                    // prepare matrix array for surfaces
                    Mat3x2LoadIdentity(fl_matrix1);
                    Mat3x2LoadIdentity(fl_matrix2);
                    Mat3x2Translate(fl_matrix1, (GFX_FLOAT)fl_img_draw_x,(GFX_FLOAT)fl_img_draw_y);
                    hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,(void *)&p_cntx_SP->state.matrix[0]);
                    Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
                    Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
                    UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(p_cntx_SP->rprop.pe_ctx, MML_GDC_PE_SRC, fl_matrix2));

                    UTIL_SUCCESS(ret, mmlGdcPeBlt(p_cntx_SP->rprop.pe_ctx, 0,0));
                }
            }
            l_irislib_draw_sts = (GFX_MGR02_IRISLIB_FLUSH_PENDING|GFX_MGR02_IRISLIB_FB_UPDATED);
        }
        else
        {
            gfx_debug_iris("irislib - Image Tile elem =%08X surface image buffer couldnot be assigned\n", p_elem_def_SP);
        }
    }
    else
    {
        gfx_debug_iris("Irislib - Tile elem =%08X skipped\n", p_elem_def_SP);
    }
	if(ret!=MML_OK)
    {	
	  fl_ret_sts = (BOOLEAN)FALSE;
    }
	return((s_gx_flocal)fl_ret_sts);
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_build_text
Description          : Builds a text object
Invocation           : Invoked internally
Parameters           : element definition and pointer to string
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
    GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP,
    HMI_CHAR             const * p_string,
    u_gx_flocal                  p_text_actual_width)
{
    GFX_MGR02_FONT const * fl_font_SP;
    MM_U16                 fl_str_length;
    MM_U16                 fl_text_width;
    MM_U16 fl_alpha_temp;
    MM_S32 ret = MML_OK;
    MM_U16 fl_glyph_width, fl_glyph_height;
    MM_S16 fl_glyph_draw_x, fl_glyph_draw_y, fl_txtbox_strt_x;
    MML_GDC_IMAGE_T        fl_char_data;
    HMI_CHAR       const * fl_string_ptr;
    HMI_CHAR       const * fl_print_str;
    MM_U08                 fl_text_BPP;
    MM_FLOAT fl_matrix1[6], fl_matrix2[6], fl_cntx_matrix[6];
	BOOLEAN fl_ret_sts;

    if(p_cntx_SP->state.invisible == 0)
    {

        fl_font_SP = hmi_gfx_mgr02_get_font_pointer((UINT32)p_elem_def_SP->font_id);
        if(fl_font_SP != GFX_MGR02_NULL_PTR)
        {
            GFX_MGR02_TEXT_INFO fl_text_info_S;
            fl_text_info_S.print_str_P         = p_string;
            fl_text_info_S.max_available_width = p_cntx_SP->rprop.width;
       #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
         fl_text_info_S.append_str = TRUE;
         l_irislib_clip_text_str[0] = 0;
       #else
         fl_text_info_S.append_str = (UINT8)FALSE;
       #endif
         #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
         fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
         #endif
		 fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
         hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                          (UINT32)p_cntx_SP->rprop.font_id,
                                          (UINT32)p_cntx_SP->rprop.clip_mode,
                                          (UINT32)p_cntx_SP->rprop.alignment
                                      #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                         ,l_irislib_clip_text_str
                                      #endif
                                         );

       #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
         fl_print_str = l_irislib_clip_text_str;
       #else
         fl_print_str = fl_text_info_S.print_str_P;
       #endif
         fl_string_ptr = fl_print_str;
            fl_text_width = fl_text_info_S.print_width;
            fl_str_length = (MM_U16)fl_text_info_S.print_length_U8;
            fl_text_BPP = GFX_MGR02_GET_BPP(fl_font_SP->f.lut_ptr->attributes);

        }
        else
        {
            fl_text_width = (MM_U16)0;
        }


        if(fl_text_width > 0)
        {
            MML_GDC_PE_CONTEXT_CONTAINER  fl_mml_gdc_pixeng_text_ctx_c;
            MML_GDC_SURFACE_CONTAINER     fl_mml_gdc_txt_surf_c;
            MML_GDC_PE_CONTEXT            fl_mml_gdc_pixeng_text_ctx;
            MML_GDC_SURFACE               fl_mml_gdc_txt_surf;
            GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
            MM_S16 fl_start_x;
            MM_U32 fl_fg_color;
            MM_U32 fl_bg_color;
            MM_U08 fl_bgfill_color[4];
            MM_U08 fl_draw_color[4];
            MM_U08 fl_draw_mode;

            fl_mml_gdc_pixeng_text_ctx=&fl_mml_gdc_pixeng_text_ctx_c;
            fl_mml_gdc_txt_surf= &fl_mml_gdc_txt_surf_c;

            UTIL_SUCCESS(ret, mmlGdcPeResetContext(fl_mml_gdc_pixeng_text_ctx));
            UTIL_SUCCESS(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_txt_surf));

            UTIL_SUCCESS(ret, mmlGdcPeAttribute(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_ATTR_ZERO_POINT, MML_GDC_PE_ATTR_ZERO_UP_LEFT));

            fl_draw_mode =p_cntx_SP->rprop.draw_mode;

            if (fl_draw_mode ==GFX_MGR02_TP_DRAW_REVERSE)
            {
                fl_bg_color      = p_cntx_SP->rprop.fg_color;
                fl_fg_color      = p_cntx_SP->rprop.bg_color;

            }
            else        // if((fl_draw_mode ==GFX_MGR02_TP_DRAW_TRANSP)||(fl_draw_mode ==GFX_MGR02_TP_DRAW_NORMAL))
            {
                fl_bg_color      = p_cntx_SP->rprop.bg_color;
                fl_fg_color      = p_cntx_SP->rprop.fg_color;

            }

            fl_bgfill_color[0]=GM2_IRIS_R(fl_bg_color); /* R */
            fl_bgfill_color[1]=GM2_IRIS_G(fl_bg_color); /* G */
            fl_bgfill_color[2]=GM2_IRIS_B(fl_bg_color); /* B */
            fl_bgfill_color[3]=GM2_IRIS_A(fl_bg_color); /* A */


            if((p_cntx_SP->state.alpha<255)||(fl_bgfill_color[3]<255))
            {
                fl_alpha_temp = (((MM_U16)fl_bgfill_color[3])*((MM_U16)p_cntx_SP->state.alpha));
                fl_bgfill_color[3] =(MM_U08)(fl_alpha_temp/((MM_U16)255));
            }

            if(fl_text_width > p_cntx_SP->rprop.width)
            {
                fl_text_width = p_cntx_SP->rprop.width;
            }

            if((p_elem_def_SP->alignment & (GFX_MGR02_TP_ALIGN_RIGHT)) != 0)
            {
                fl_start_x = (MM_S16)fl_text_width;
                --fl_start_x;
                fl_txtbox_strt_x = (MM_S16)p_cntx_SP->rprop.width;
            }
            else if((p_elem_def_SP->alignment & (GFX_MGR02_TP_ALIGN_CENTRE)) != 0)
            {
                fl_start_x = (((MM_S16)fl_text_width) >> 1);
                fl_txtbox_strt_x = (((MM_S16)p_cntx_SP->rprop.width) >> 1);
            }
            else
            {
                fl_start_x =  0;
                fl_txtbox_strt_x = 0;
            }

            fl_start_x = (p_cntx_SP->state.loc.x-fl_start_x);
            fl_txtbox_strt_x = (p_cntx_SP->state.loc.x-fl_txtbox_strt_x);

            if (fl_draw_mode !=GFX_MGR02_TP_DRAW_TRANSP)
            {
              mmlGdcSmAssignBuffer(fl_mml_gdc_txt_surf, (MM_U32)p_elem_def_SP->width, (MM_U32)fl_font_SP->p.height, MML_GDC_SURF_FORMAT_A8B8G8R8, 0, (MM_U32)0);
              UTIL_SUCCESS(ret, mmlGdcPeBindSurface(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_mml_gdc_txt_surf));

              if((p_cntx_SP->state.alpha<255)||(fl_bgfill_color[3]<255))
              {
                fl_alpha_temp = (((MM_U16)fl_bgfill_color[3])*((MM_U16)p_cntx_SP->state.alpha));
                fl_bgfill_color[3] =(MM_U08)(fl_alpha_temp/((MM_U16)255));
                UTIL_SUCCESS(ret, mmlGdcPeSurfColor(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_bgfill_color[0], fl_bgfill_color[1], fl_bgfill_color[2], fl_bgfill_color[3]));

                UTIL_SUCCESS(ret, mmlGdcPeBindSurface(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_STORE | MML_GDC_PE_DST, p_cntx_SP->rprop.pe_tsurf));

                UTIL_SUCCESS(ret, mmlGdcPeBlendMode(fl_mml_gdc_pixeng_text_ctx,
                             MML_GDC_PE_BM_GL_FUNC_ADD, \
                             MML_GDC_PE_BM_GL_FUNC_ADD, \
                             MML_GDC_PE_BM_GL_FUNC_ADD, \
                             MML_GDC_PE_BM_GL_FUNC_ADD));

                UTIL_SUCCESS(ret, mmlGdcPeBlendFunc(fl_mml_gdc_pixeng_text_ctx,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                MML_GDC_PE_BF_GL_ONE, MML_GDC_PE_BF_GL_ONE));
              }
              else
              {
                UTIL_SUCCESS(ret, mmlGdcPeSurfColor(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_bgfill_color[0], fl_bgfill_color[1], fl_bgfill_color[2], fl_bgfill_color[3]));
                UTIL_SUCCESS(ret, mmlGdcPeBindSurface(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_STORE, p_cntx_SP->rprop.pe_tsurf));
              }

              // prepare matrix array for surfaces
              Mat3x2LoadIdentity(fl_matrix1);
              Mat3x2LoadIdentity(fl_matrix2);
              Mat3x2Translate(fl_matrix1, (GFX_FLOAT)fl_txtbox_strt_x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
              hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,&p_cntx_SP->state.matrix[0]);
              Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
              Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
              UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_matrix2));

              UTIL_SUCCESS(ret, mmlGdcPeBlt(fl_mml_gdc_pixeng_text_ctx, (MM_FLOAT)0,(MM_FLOAT)0));
            }

            fl_draw_color[0]=GM2_IRIS_R(fl_fg_color); /* R */
            fl_draw_color[1]=GM2_IRIS_G(fl_fg_color); /* G */
            fl_draw_color[2]=GM2_IRIS_B(fl_fg_color); /* B */
            fl_draw_color[3]=GM2_IRIS_A(fl_fg_color); /* A */

            if((p_cntx_SP->state.alpha<255)||(fl_draw_color[3]<255))
            {
              fl_alpha_temp = (((MM_U16)fl_draw_color[3])*((MM_U16)p_cntx_SP->state.alpha));
              fl_draw_color[3] =(MM_U08)(fl_alpha_temp/((MM_U16)255));
            }

            switch(fl_text_BPP)
            {

            case GFX_MGR02_FONT_ENCODING_1BPP:

                fl_char_data.ColorComponentBits = (MM_U32)0x00000001;
                fl_char_data.ColorComponentShift = (MM_U32)0x00000000;
                fl_char_data.totalBits = (MM_U08)0x01;
                fl_char_data.surf_format =MML_GDC_SURF_FORMAT_A1;

                break;
            case GFX_MGR02_FONT_ENCODING_2BPP:
                fl_char_data.ColorComponentBits = (MM_U32)0x00000002;
                fl_char_data.ColorComponentShift = (MM_U32)0x00000000;
                fl_char_data.totalBits = (MM_U08)0x02;
                fl_char_data.surf_format =MML_GDC_SURF_FORMAT_A8;

                break;
            case GFX_MGR02_FONT_ENCODING_4BPP:
                fl_char_data.ColorComponentBits = (MM_U32)0x00000004;
                fl_char_data.ColorComponentShift = (MM_U32)0x00000000;
                fl_char_data.totalBits = (MM_U08)0x04;
                fl_char_data.surf_format =MML_GDC_SURF_FORMAT_A8;

                break;
            case GFX_MGR02_FONT_ENCODING_8BPP:
                fl_char_data.ColorComponentBits = (MM_U32)0x00000008;
                fl_char_data.ColorComponentShift = (MM_U32)0x00000000;
                fl_char_data.totalBits = (MM_U08)0x08;
                fl_char_data.surf_format =MML_GDC_SURF_FORMAT_A8;

                break;
            default:
            {
            	/*For MISRA warning fix.*/
            }
                break;

            }

            fl_glyph_draw_x = fl_start_x;
            fl_glyph_draw_y = p_cntx_SP->state.loc.y;

            UTIL_SUCCESS(ret, mmlGdcSmResetSurfaceObject(fl_mml_gdc_txt_surf));

            UTIL_SUCCESS(ret, mmlGdcPeBindSurface(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_STORE|MML_GDC_PE_DST, p_cntx_SP->rprop.pe_tsurf));
            UTIL_SUCCESS(ret, mmlGdcPeSelectArea(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_STORE));

            while(fl_str_length > (MM_U16)0)
            {
                fl_str_length--;
                fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.lut_ptr, (UINT32)fl_font_SP->size_table, 
                                                   #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                                                       p_elem_def_SP->font_id,
                                                   #endif
                                                       (UINT32)FALSE);
                if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
                {
                    MM_S16 fl_font_x_soffset = (MM_S16)fl_font_fcc_SP->x_soffset;
                    MM_S16 fl_font_y_soffset = (MM_S16)fl_font_fcc_SP->y_soffset;
					MM_S16 fl_font_x_eoffset = (MM_S16)(fl_font_fcc_SP->x_eoffset);					
					
                    fl_glyph_width = fl_font_fcc_SP->width;
                    fl_glyph_height = fl_font_fcc_SP->height;

					fl_glyph_draw_x = fl_glyph_draw_x + fl_font_x_soffset;
                    fl_glyph_draw_y = fl_glyph_draw_y + fl_font_y_soffset;

                    if(fl_font_fcc_SP->fdata != 0)
                    {

                        mmlGdcSmAssignBuffer(fl_mml_gdc_txt_surf, (MM_U32)fl_glyph_width, (MM_U32)fl_glyph_height, fl_char_data.surf_format, (void*)fl_font_fcc_SP->fdata, (MM_U32)0);
                        mmlGdcSmSetAttribute(fl_mml_gdc_txt_surf, MML_GDC_SURF_ATTR_BITPERPIXEL, (MM_U32)fl_char_data.totalBits);
                        mmlGdcSmSetAttribute(fl_mml_gdc_txt_surf, MML_GDC_SURF_ATTR_COLORBITS, fl_char_data.ColorComponentBits);
                        mmlGdcSmSetAttribute(fl_mml_gdc_txt_surf, MML_GDC_SURF_ATTR_COLORSHIFT, fl_char_data.ColorComponentShift);

                        UTIL_SUCCESS(ret, mmlGdcPeBindSurface(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_mml_gdc_txt_surf));

                        UTIL_SUCCESS(ret, mmlGdcPeSurfColor( fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_draw_color[0], fl_draw_color[1], fl_draw_color[2], fl_draw_color[3]));

                        if(fl_draw_color[3]<255)
                        {
                            UTIL_SUCCESS(ret, mmlGdcPeBlendMode(fl_mml_gdc_pixeng_text_ctx,
                                MML_GDC_PE_BM_GL_FUNC_ADD, \
                                MML_GDC_PE_BM_GL_FUNC_ADD, \
                                MML_GDC_PE_BM_GL_FUNC_ADD, \
                                MML_GDC_PE_BM_GL_FUNC_ADD));

                            UTIL_SUCCESS(ret, mmlGdcPeBlendFunc(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA,
                                MML_GDC_PE_BF_GL_SRC_ALPHA, MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA));

                            UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_COLORMULTI, (MM_U32)MM_TRUE));
                            UTIL_SUCCESS(ret, mmlGdcPeSurfAttribute(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, MML_GDC_PE_SURF_ATTR_ALPHAMULTI, (MM_U32)MM_TRUE));

                        }

                        UTIL_SUCCESS(ret, mmlGdcPeActiveArea(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_STORE, (MM_S32)fl_glyph_draw_x, (MM_S32)fl_glyph_draw_y, (MM_U32)fl_glyph_width, (MM_U32)fl_glyph_height));

                        // prepare matrix array for surfaces
                        Mat3x2LoadIdentity(fl_matrix1);
                        Mat3x2LoadIdentity(fl_matrix2);
                        Mat3x2Translate(fl_matrix1, (GFX_FLOAT)fl_glyph_draw_x,(GFX_FLOAT)fl_glyph_draw_y);
                        hmi_gfx_mgr02_iris_get_matrix(fl_cntx_matrix,&p_cntx_SP->state.matrix[0]);
                        Mat3x2Multiply(fl_matrix2,fl_matrix1,fl_cntx_matrix);
                        Mat3x2Translate(fl_matrix2, (GFX_FLOAT)(-p_cntx_SP->rprop.pivot.x),(GFX_FLOAT)(-p_cntx_SP->rprop.pivot.y));
                        UTIL_SUCCESS(ret, mmlGdcPeSetMatrix(fl_mml_gdc_pixeng_text_ctx, MML_GDC_PE_SRC, fl_matrix2));

                        UTIL_SUCCESS(ret, mmlGdcPeBlt(fl_mml_gdc_pixeng_text_ctx, (MM_FLOAT)0,(MM_FLOAT)0));

                    }
                    else
                    {

                    }
				   fl_glyph_draw_x = fl_glyph_draw_x + fl_font_x_eoffset;
				   fl_glyph_draw_y = fl_glyph_draw_y - fl_font_y_soffset;
                   fl_string_ptr++;
              }
            }
            l_irislib_draw_sts = (MM_U08)(GFX_MGR02_IRISLIB_FLUSH_PENDING|GFX_MGR02_IRISLIB_FB_UPDATED);
        }
    }
    if(ret==MML_OK)
	{	
		fl_ret_sts = (BOOLEAN)TRUE;
    }
	else
	{
        fl_ret_sts = (BOOLEAN)FALSE; 
	}
   GFX_MGR02_UNUSED_VAR(p_text_actual_width);
	return((s_gx_flocal)fl_ret_sts);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_get_bound
Description          : Calculates the transformed bounds of an elements passed
                       boundary
Invocation           : Invoked by generic manager
Parameters           : context, element def and elements bounds (un transformed).
Return Value         : Updates transformed bounds in to p_bound_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_get_bound(UINT32 p_obj_type, GFX_MGR02_CONTEXT_T const * p_cntx_SP, \
                                                GFX_FLOAT * p_bounds)
{
  /* p_bounds[0] = p_cntx_SP->state.loc;
   p_bounds[1] = 0;
   p_bounds[2] = 0;
   p_bounds[3] = 0;
    */
   GFX_MGR02_UNUSED_VAR(p_obj_type);
   GFX_MGR02_UNUSED_PTR(p_cntx_SP);
   GFX_MGR02_UNUSED_PTR(p_bounds);
   return ((s_gx_flocal)1);
}

#ifdef GFX_MGR02_IRIS_PIXEL_POKING
/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_init_pixel_buffer
Description          : Function to be called by the application for initialising 
pixel poking data.
Invocation           : Invoked by application and irisinit().
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_irislib_init_pixel_buffer(void)
{
   u_gx_flocal fl_buffer_count_U32;
   GFX_MGR02_PIXEL_DATA fl_invalid_pixel_data = GFX_MGR02_INVALID_PIXEL_DATA;

   for(fl_buffer_count_U32 = (u_gx_flocal)0; fl_buffer_count_U32 < (u_gx_flocal)MAX_NO_OF_SET_PIXEL_BUFFERS; fl_buffer_count_U32++)
   {
     l_iris_SetPixelDataBuffer[fl_buffer_count_U32].status     = (BOOLEAN)GFX_MGR02_SET_PIXEL_BUFFER_INACTIVE;
     l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data = fl_invalid_pixel_data;
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_set_pixel_data
Description          : Function to be called by the application for pixel
poking.
Invocation           : Invoked by application.
Parameters           : Pixel data and buffer id.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GFX_MGR02_PIXEL_POKING_STATUS hmi_gfx_mgr02_irislib_set_pixel_data(GFX_MGR02_PIXEL_DATA p_set_pixel_data, UINT32 p_buffer_id)
{
   GFX_MGR02_PIXEL_POKING_STATUS fl_ret_status = GFX_MGR02_PIXEL_POKING_NO_ERROR;

   if(p_buffer_id >= MAX_NO_OF_SET_PIXEL_BUFFERS)
   {
     fl_ret_status = GFX_MGR02_ERROR_INVALID_BUFFER;
   }   
   else if((p_set_pixel_data.pos_x_U16 >= GFX_MGR02_LAYERS_MAX_WIDTH) || (p_set_pixel_data.pos_y_U16 >= GFX_MGR02_LAYERS_MAX_HEIGHT))
   {
     GFX_MGR02_PIXEL_DATA fl_invalid_pixel_data        = GFX_MGR02_INVALID_PIXEL_DATA;
     l_iris_SetPixelDataBuffer[p_buffer_id].status     = (BOOLEAN)GFX_MGR02_SET_PIXEL_BUFFER_INACTIVE;
     l_iris_SetPixelDataBuffer[p_buffer_id].pixel_data = fl_invalid_pixel_data;
     fl_ret_status                                     = GFX_MGR02_ERROR_COORD_OUT_OF_RANGE;
   }
   else
   {
     l_iris_SetPixelDataBuffer[p_buffer_id].status      = (BOOLEAN)GFX_MGR02_SET_PIXEL_BUFFER_ACTIVE;
     l_iris_SetPixelDataBuffer[p_buffer_id].pixel_data  = p_set_pixel_data;
   }
   return fl_ret_status;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_buffer_data_updation
Description          : Function to be called after all building operation are
completed. This function will update the data set by the application for pixel
poking.
Invocation           : Invoked by hmi_gfx_mgr02_irislib_finish().
Parameters           : Context pointer
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_irislib_buffer_data_updation(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
   UINT8               fl_pix_format_U8;
   UINT8               fl_red_comp_U8;
   UINT8               fl_green_comp_U8;
   UINT8               fl_blue_comp_U8;
   GFX_MGR02_ISIZE_W_T fl_fb_width_U16;
   GFX_MGR02_ISIZE_H_T fl_fb_height_U16;
   void              * fl_fb_P = 0;
   UINT16              fl_x_U16 = (UINT16)0;
   UINT16              fl_y_U16 = (UINT16)0;
   u_gx_flocal         fl_buffer_count_U32;
   u_gx_flocal         fl_location_U32 = (u_gx_flocal)0;

   fl_fb_P           = p_cntx_SP->rprop.fb_P;
   fl_fb_width_U16   = p_cntx_SP->rprop.fb_w;
   fl_fb_height_U16  = p_cntx_SP->rprop.fb_h;
   fl_pix_format_U8  = lc_layer_def_S[p_cntx_SP->rprop.layer_id].pix_format;

   if(fl_fb_P != 0)
   {
     for(fl_buffer_count_U32 = (u_gx_flocal)0; fl_buffer_count_U32 < (u_gx_flocal)MAX_NO_OF_SET_PIXEL_BUFFERS; fl_buffer_count_U32++)
     {
       if(l_iris_SetPixelDataBuffer[fl_buffer_count_U32].status == GFX_MGR02_SET_PIXEL_BUFFER_ACTIVE)
       {
         fl_red_comp_U8        = l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data.red_component_U8;
         fl_green_comp_U8      = l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data.green_component_U8;
         fl_blue_comp_U8       = l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data.blue_component_U8;
         fl_x_U16              = l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data.pos_x_U16;
         fl_y_U16              = l_iris_SetPixelDataBuffer[fl_buffer_count_U32].pixel_data.pos_y_U16;

         if((fl_x_U16 < fl_fb_width_U16) && (fl_y_U16 < fl_fb_height_U16))
         {
           switch(fl_pix_format_U8)
           {
             case GFX_MGR02_PIX_FORMAT_RGB565:
             {
               UINT16  *fl_fb_U16P        = (UINT16*)fl_fb_P;
               UINT16   fl_pixel_data_U16 = (UINT16)0;
               fl_pixel_data_U16          = GFX_MGR02_RGB565(fl_red_comp_U8, fl_green_comp_U8, fl_blue_comp_U8);
               fl_location_U32            = ((((UINT32)fl_fb_width_U16) * ((UINT32)fl_y_U16)) + ((UINT32)fl_x_U16));
               fl_fb_U16P[fl_location_U32]= fl_pixel_data_U16;
             }
             break;
             case GFX_MGR02_PIX_FORMAT_RGB888:
             {
               UINT8  *fl_fb_U8P            = (UINT8*)fl_fb_P;
               UINT8 fl_bytes_per_pixel_U8  = (UINT8)3;
               fl_location_U32              = (((((UINT32)fl_fb_width_U16) * ((UINT32)fl_y_U16)) + ((UINT32)fl_x_U16)) * ((UINT32)fl_bytes_per_pixel_U8));
               fl_fb_U8P[fl_location_U32]   = fl_red_comp_U8;
               fl_location_U32++;
               fl_fb_U8P[fl_location_U32]   = fl_green_comp_U8;
               fl_location_U32++;
               fl_fb_U8P[fl_location_U32]   = fl_blue_comp_U8;
             }
             break;
             default:
             {
            	 /*For MISRA warning fix.*/
             }
             break;
           }
         }
       }
     }
   }
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_finish
Description          : Function to be called after all building operation are
completed. This will perform the VG flush to perform
any pending VG operations
Invocation           : Invoked by manage
r
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_irislib_finish(
                                         #ifdef GFX_MGR02_IRIS_PIXEL_POKING
                                         GFX_MGR02_CONTEXT_T const * p_cntx_SP
                                         #else
                                         void
                                         #endif
                                         )
{
   if((l_irislib_draw_sts & GFX_MGR02_IRISLIB_FLUSH_PENDING) != 0)
   {
   #ifdef GFX02_MGR02_IRIS_METRICS
      mmlGdcConfigGetAttribute( MML_GDC_CONFIG_ATTR_MIN_INSTRUCTION_BUFFER, &l_instr_bf_size );
      if( l_instr_bf_size_max<l_instr_bf_size)
      {
         l_instr_bf_size_max =l_instr_bf_size;
      }
   #endif
      MM_S32 ret = MML_OK;
      MML_GDC_SYNC_CONTAINER fl_mml_gdc_sync;
      UTIL_SUCCESS(ret, mmlGdcPeSync(&fl_mml_gdc_sync));
      /* sync wait to ensure the completion of all the previous build operations */
      while(mmlGdcSyncWait(&fl_mml_gdc_sync, 0) == MML_ERR_GDC_SYNC_TIMEOUT){}
      #ifdef GFX_MGR02_IRIS_PIXEL_POKING
      /* Function to upate the pixel data stored in buffer*/
      hmi_gfx_mgr02_irislib_buffer_data_updation(p_cntx_SP);
      #endif
      l_irislib_draw_sts &= (UINT8)(~GFX_MGR02_IRISLIB_FLUSH_PENDING);
   }
   return((s_gx_flocal)l_irislib_draw_sts);
}




/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_get_disp_pix_format
Description          : Function to map the Display pixel format( GDG02 format mapping to IRIS pixel format)
Invocation           : Invoked by manager( context initilize)
Parameters           : p_pix_format
Return Value         : MML_GDC_SURF_FORMAT
Critical Section     : None
External Interfaces  : None
******************************************************************************/
MML_GDC_SURF_FORMAT hmi_gfx_mgr02_irislib_get_disp_pix_format(u_gx_flocal p_pix_format)
{
    MML_GDC_SURF_FORMAT fl_gdc_pix_format;

    switch (p_pix_format)
    {
    case GFX_MGR02_PIX_FORMAT_RGB565:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_R5G6B5;
        break;
    case GFX_MGR02_PIX_FORMAT_RGB888:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_R8G8B8;
        break;
    case GFX_MGR02_PIX_FORMAT_ARGB8888:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_A8R8G8B8;
        break;
    case GFX_MGR02_PIX_FORMAT_ARGB1555:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_A1R5G5B5;
        break;
    case GFX_MGR02_PIX_FORMAT_ARGB4444:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_R4G4B4A4;
        break;
    default:
        fl_gdc_pix_format = MML_GDC_SURF_FORMAT_A8R8G8B8;
        break;
    }
    return(fl_gdc_pix_format);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_iris_get_matrix()
Description          : Function to return a 3*2 IRIS Geometry Matrix
Invocation           : Invoked by build object interfaces.
Return Value         : Mat3x2 matrix of 6 indices
Parameters           : property values
******************************************************************************/
static void hmi_gfx_mgr02_iris_get_matrix(MM_FLOAT * p_dst_matrix,MM_FLOAT const * p_src_matrix)
{
    p_dst_matrix[ 0] = p_src_matrix[ 0];
    p_dst_matrix[ 1] = p_src_matrix[ 1];
    p_dst_matrix[ 2] = p_src_matrix[ 3];
    p_dst_matrix[ 3] = p_src_matrix[ 4];
    p_dst_matrix[ 4] = p_src_matrix[ 6];
    p_dst_matrix[ 5] = p_src_matrix[ 7];

}
#endif /* #if defined(GFX_MGR02_FUJITSU) */

#ifdef  __cplusplus
}
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
 ** CMS Rev 6.7     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 6.6     02-NOV-2016    APERUMAL
 ** RTC 735553
 ** Porsche Misra warning fixes 
 **
 ** CMS Rev 6.5     01-oct-2015    APERUMAL
 ** RTC 434948
 ** Compiler warning fix for Porsche
 **
 ** CMS Rev 6.4     26-May-2015    ADEVI
 ** RTC 323189,346589,346614,346712,414135: Iris pixel poking review comment fix.
 **
 ** CMS Rev 6.3     25-May-2015    ADEVI
 ** RTC 323189: Implementation of iris pixel poking feature.
 **
 ** CMS Rev 6.2     5-Feb-2015    ADEVI
 ** Changes done to avoid compilation error.
 **
 ** CMS Rev 6.1      20-Jan-2015    EMANOJ1
 ** Moved all surface and context handling to context.c to handle the shutdown
 ** sequence for the titan  (RTC #256452)
 **
 ** CMS Rev 6.0      20-Feb-2014    CMUTHUSA
 ** APAL16 Format support added
 **
 ** CMS Rev 5.0      13-Nov-2013    CMUTHUSA
 ** CLUT processing implemented for indexed images.
 ** TODO: APAL16 Format not yet supported
 ** First version archived in RTC
 **
 ** CMS Rev 4.0      15-Oct-2013    CMUTHUSA
 ** Matrix operations implemented for all objects..
 **
 ** CMS Rev 3.0      13-Sep-2013    CMUTHUSA
 ** Alpha Image Blend & Global Alpha blend for Image/tile/Text implemented.
 **
 ** CMS Rev 2.0      30-Aug-2013    CMUTHUSA
 ** Text & Image Rendering Improvements with respect to context usage..
 **
 ** CMS Rev 1.0      14-Aug-2013    CMUTHUSA
 ** Creation.
 **==========================================================================*/
/* end of file =============================================================*/
