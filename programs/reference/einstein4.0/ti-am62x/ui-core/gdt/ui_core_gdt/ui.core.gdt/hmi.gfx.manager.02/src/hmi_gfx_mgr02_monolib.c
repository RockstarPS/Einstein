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
 ** Name:           hmi_gfx_mgr02_monolib.c
 **
 ** Description:    
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_MONOLIB_C
#define HMI_GFX_MGR02_PRIV_C 

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_MONOTFT)
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_monolib.h"
#include "hmi_gfx_mgr02_text.h"
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/



typedef struct
{
   GFX_MGR02_ISIZE_X_T x;
   GFX_MGR02_ISIZE_Y_T y;
   GFX_MGR02_ISIZE_W_T w;
   GFX_MGR02_ISIZE_H_T h;
   GFX_MGR02_ISIZE_W_T x_offset;
   GFX_MGR02_ISIZE_H_T y_offset;
}GFX_MGR02_CLIP_IMAGE_DATA;
/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/
#define GFX_COMPILE_SPEED_OPTIMIZE

/* Veritical Packing - GFX_ROTATED_IMAGES = 0 /Horizontal Packing GFX_ROTATED_IMAGES = 1 */

#define GFX_DRIVER_LAYER0_BUFFER1_INDEX (0)
#define GFX_DRIVER_LAYER0_BUFFER2_INDEX (1)

#define GFX_WHITE_COLOUR                 (0xff)
#if GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP
  #define LCD_SIZE_MUL_FACTOR 2
  #define PMSK(val)  (val & 0x0F)
  #define BMASKL     (0xF0)
  #define BMASKR     (0x0F)
#elif GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP
  #define LCD_SIZE_MUL_FACTOR 1
  #define PMSK(val)  (val & 0x03)
#else
  #define LCD_SIZE_MUL_FACTOR 0
  #define PMSK(val)  (val & 0x01)
#endif

/*
** Status encodings for l_fb_status_U8A
*/
#define FB_STATUS_FREE    (0)
#define FB_STATUS_READY   (1)
#define FB_STATUS_LOCKED  (2)


#if defined(GFX_MGR_CLIP_TEXT_ENABLE)
  #if MAX_TEXT_LENGTH <= GFX_MGR_APPEND_CHAR_CNT
    #error "MAX_TEXT_LENGTH should be > GFX_MGR_APPEND_CHAR_CNT"
  #endif
#endif
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
 static HMI_CHAR l_ovglib_clip_text_str[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
/*
** SR - Shift Right
** SL - Shift Left
** FB - Points to next Frame buffer location
** GET_FBP - Returns the Frame buffer pointer to the passed xy location
** NEXT_FBP_LINE - Points to the next line of the frame buffer
*/
#if (GFX_MGR02_BIT_ORDER_LSB_FIRST==1)
  #define SR(data, count)  ((data) >> (count))
  #define SL(data, count)  ((data) << (count))
#else
  #define SR(data, count)  ((data) << (count))
  #define SL(data, count)  ((data) >> (count))
#endif

/* SEGMENT CHANGES MERGE  */
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_1BPP) 
#define GFX_GET_SET_COLOR_MASK(color_mask,color) (UINT8)((color_mask))
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)
  #define GFX_GET_SET_COLOR_MASK(color_mask,color) (UINT8)(~(color_mask))
#elif (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP) || (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
  #define GFX_GET_SET_COLOR_MASK(color_mask,color) (UINT8)((UINT8)(~(color_mask))& (color))
#else
  #error "No Bits Per Pixel selected"
#endif

#if GFX_MGR02_HOR_PACKING != 0
    #if GFX_ROTATED_DISPLAY == 0 
      /* Horizontal Packing, Vertical filling */
      #define FB(ptr, index,layer)     ((ptr)[(index)*lc_pixel_def_S[layer].lcd_bytes_per_row])
      #define GET_FBP(ptr, x, y,layer) (&ptr[((y) >> 3) + (lc_pixel_def_S[layer].lcd_bytes_per_row * (x))])
      #define NEXT_FBP_LINE(ptr, layer)(&ptr[1])
      #define SOFFS(y)                 (y & 0x07)
      #define NLINES(h)                (h >> 3)
    #else
      /* Horizontal Packing, Horizontal filling */
      #define FB(ptr, index,layer)     ((ptr)[index])
      #define GET_FBP(ptr, x, y,layer) (&(ptr)[((((y) >> 3) * lc_pixel_def_S[layer].lcd_ysize) + (x))])  
      #define NEXT_FBP_LINE(ptr,layer) (&((ptr)[(lc_pixel_def_S[layer].lcd_ysize)])) 
      #define SOFFS(y)           ((y) & 0x07)
      #define NLINES(h)          ((h) >> 3)
    #endif

#else 
    #if GFX_ROTATED_DISPLAY == 0 
      /* Vertical Packing, Horizontal filling */
      #define FB(ptr, index, layer)     ((ptr)[index])
      #define GET_FBP(ptr, x, y,layer)  (&(ptr)[((((y) >> 3) * lc_pixel_def_S[layer].lcd_xsize) + (x))])  
      #define NEXT_FBP_LINE(ptr,layer)  (&(ptr)[lc_pixel_def_S[layer].lcd_xsize])
      #define SOFFS(y)                  ((y) & 0x07)
      #define NLINES(h)                 ((h) >> 3)
    #else
      /* Vertical Packing, Vertical filling */
      #define FB(ptr, index, layer)     ((ptr)[(index) * lc_pixel_def_S[layer].lcd_bytes_per_col])
      #define GET_FBP(ptr, x, y, layer) (&((ptr)[((y)>>3) + (lc_pixel_def_S[layer].lcd_bytes_per_col * (x))]))
      #define NEXT_FBP_LINE(ptr,layer)  (&((ptr)[1]))
      #define SOFFS(y)                  ((y) & 0x07)
      #define NLINES(h)                 ((h) >> 3)
    #endif
#endif

#if defined(GFX_DRIVER_WAIT_SCHEDULING)
#define GFX_DRIVER_SCHED_WAIT()  GfxDriverShedWait()
#else
   #define GFX_DRIVER_SCHED_WAIT()
#endif
/*
** Text Clip Info.
*/


/*
** Allocate the frame buffer memory and create the framebuffer pointer table
** static GFX_MGR02_COLOR * const l_layer1_buffers_U8[GFX_MGR02_NUM_LAYERS][1] if double 
** buffering is disabled.
** static GFX_MGR02_COLOR * const l_layer1_buffers_U8[GFX_MGR02_NUM_LAYERS][2] if double 
** buffering is enabled.
** NOTE!!!! Make sure the allocation happens with in #ifdef HMI_GFX_DRIVER_C
**          to prevent multiple memory allocations. Below allocation is for 
**			sample only. Modify this as necessary.
*/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#if defined GFX_MGR02_COMPRESSION_ENABLED
typedef struct
{
   UINT8 const * bmp_data;
   UINT16   count;
   UINT8   flag;
   UINT8   data;
}GFX_ONLINE_RLE;
#endif

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#if defined(GFX_DRIVER_USE_DOUBLE_BUFFERING)
static UINT8 l_layer_working_fb_index_U8A[GFX_MGR02_NUM_LAYERS];
#endif

#if GFX_MGR02_NUM_LAYERS > 1
extern UINT8 gl_active_layer_id_U8;
#else
   #define fl_lid_U8 (0)
#endif



static GFX_MGR02_IAREA_DATA  l_clip_area_S[1];


#if defined(GFX_DRIVER_WAIT_SCHEDULING)
  UINT16 curr_sched_counter_U16;
#endif
#if defined GFX_COMPILE_SPEED_OPTIMIZE
#define FL_RLE_CUR_BMP_DATA	  fl_rle_cur_bmp_data
#define FL_RLE_CUR_COUNT	  fl_rle_cur_count
#define FL_RLE_CUR_FLAG		  fl_rle_cur_flag
#define FL_RLE_CUR_DATA		  fl_rle_cur_data

#define FL_RLE_NLN_BMP_DATA	  fl_rle_nln_bmp_data
#define FL_RLE_NLN_COUNT 	  fl_rle_nln_count
#define FL_RLE_NLN_FLAG 	  fl_rle_nln_flag
#define FL_RLE_NLN_DATA		  fl_rle_nln_data

#define FL_RLE_CLIP_BMP_DATA  fl_rle_clip_bmp_data
#define FL_RLE_CLIP_COUNT 	  fl_rle_clip_count
#define FL_RLE_CLIP_FLAG 	  fl_rle_clip_flag
#define FL_RLE_CLIP_DATA	  fl_rle_clip_data

#else
#define FL_RLE_CUR_BMP_DATA	  fl_rle_cur.bmp_data
#define FL_RLE_CUR_COUNT	  fl_rle_cur.count
#define FL_RLE_CUR_FLAG		  fl_rle_cur.flag
#define FL_RLE_CUR_DATA		  fl_rle_cur.data

#define FL_RLE_NLN_BMP_DATA	  fl_rle_nln.bmp_data
#define FL_RLE_NLN_COUNT 	  fl_rle_nln.count
#define FL_RLE_NLN_FLAG 	  fl_rle_nln.flag 
#define FL_RLE_NLN_DATA		  fl_rle_nln.data

#define FL_RLE_CLIP_BMP_DATA fl_rle_clip.bmp_data
#define FL_RLE_CLIP_COUNT 	 fl_rle_clip.count
#define FL_RLE_CLIP_FLAG 	 fl_rle_clip.flag 
#define FL_RLE_CLIP_DATA	 fl_rle_clip.data

#endif

#ifdef GFX_COMPILE_SPEED_OPTIMIZE

#define GfxDriverClipCalculate(x,y,fl_copy_sindex_U16,fl_copy_y_U16,fl_copy_width_U16,fl_copy_height_U16, width, height)                                  \
  {                                                               \
   UINT16 fl_clip_width_U16 = 0;                                  \
   UINT16 fl_cheight_U16 = 0;                                     \
   if(x < l_clip_area_S[0].x)                                     \
   {                                                              \
      fl_clip_width_U16 = (l_clip_area_S[0].x-x);                 \
      fl_copy_sindex_U16 += fl_clip_width_U16;                    \
      x  = l_clip_area_S[0].x;                                    \
      if(fl_copy_width_U16 > fl_clip_width_U16)                   \
      {                                                           \
         fl_copy_width_U16 -= fl_clip_width_U16;                  \
      }                                                           \
      else                                                        \
      {                                                           \
         fl_copy_width_U16 = 0;                                   \
      }                                                           \
   }                                                              \
   else                                                           \
   {                                                              \
      if(x < 0)                                                   \
      {                                                           \
         fl_copy_sindex_U16 = -x;                                 \
      }                                                           \
	  if(fl_copy_sindex_U16 != 0)                                 \
      {                                                           \
         fl_copy_width_U16 = width - fl_copy_sindex_U16;          \
      }                                                           \
      if(x <= 0)                                                  \
      {                                                           \
         x = 0;                                                   \
      }                                                           \
   }                                                              \
   fl_clip_width_U16 = (l_clip_area_S[0].x+l_clip_area_S[0].width); \
   if((x+fl_copy_width_U16) > fl_clip_width_U16)                  \
   {                                                              \
      fl_copy_width_U16 = (fl_clip_width_U16 - x);                \
   }                                                              \
   if(y < l_clip_area_S[0].y)                                     \
   {                                                              \
      fl_cheight_U16 = (l_clip_area_S[0].y-y);                    \
      fl_copy_y_U16 += fl_cheight_U16;                            \
      y  = l_clip_area_S[0].y;                                    \
      if(fl_copy_height_U16 > fl_cheight_U16)                     \
      {                                                           \
         fl_copy_height_U16 -= fl_cheight_U16;                    \
      }                                                           \
      else                                                        \
      {                                                           \
         fl_copy_height_U16 = 0;                                  \
      }                                                           \
   }                                                              \
   else                                                           \
   {                                                              \
      if(y < 0)                                                   \
      {                                                           \
         fl_copy_y_U16 = -y;                                      \
      }                                                           \
      fl_copy_height_U16 = height - fl_copy_y_U16;                \
      if(y <= 0)                                                  \
      {                                                           \
         y = 0;                                                   \
      }                                                           \
   }                                                              \
   fl_cheight_U16 = (l_clip_area_S[0].y+l_clip_area_S[0].height); \
   if((y+fl_copy_height_U16) > fl_cheight_U16)                    \
   {                                                              \
      fl_copy_height_U16 = (fl_cheight_U16 - y);                  \
   }                                                              \
}                                                                

#define GfxDriverRLEonline(bmp_data,count,flag,data)              \
do{                                                               \
  count = *(bmp_data);                                            \
  if((count & 0x80) == 0)                                         \
  {                                                               \
      flag = 0;                                                   \
  }                                                               \
  else                                                            \
  {                                                               \
      count &= 0x7F;                                              \
      flag   = 1;                                                 \
      (bmp_data)++;                                               \
      data  = *(bmp_data);                                        \
  }													              \
  (bmp_data)++;                                                   \
}while(0)

#define GfxDriverRLEonlineNLine(bmp_data,count,flag,data, width)                  \
do{                                                                               \
   while(width > 0)                                                               \
   {															              	  \
      if(count == 0)								              	              \
      {															              	  \
         count = *(bmp_data);                                                     \
         if((count & 0x80) == 0)                                                  \
         {                                                                        \
            flag = 0;                                                             \
         }                                                                        \
         else                                                                     \
         {                                                                        \
            count &= 0x7F;                                                        \
            flag   = 1;                                                           \
            (bmp_data)++;                                                         \
            data  = *(bmp_data);                                                  \
         }													                      \
         (bmp_data)++;                                                            \
      }																			  \
      if(count >= width)											              \
      {																			  \
         if(flag == FALSE)											              \
         {																		  \
            bmp_data = &bmp_data[width];				                          \
         }																		  \
         count -= width;											              \
         width = 0;																  \
      }																			  \
      else																		  \
      {																			  \
         width -= count;											              \
         if(flag == FALSE)											              \
         {																		  \
            bmp_data = &bmp_data[count];	                                      \
         }																		  \
         count = 0;													              \
      }																			  \
   }																			  \
}while(0)
#endif

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/
#if defined GFX_MGR02_COMPRESSION_ENABLED
#if !defined GFX_COMPILE_SPEED_OPTIMIZE
static void GfxDriverRLEonline(GFX_ONLINE_RLE * p_rle_online);
static void GfxDriverRLEonlineNLine(GFX_ONLINE_RLE * p_rle_online, UINT8 p_width);
#endif
void GfxDriverCopyRLEImage(SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   UINT8 alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          );

static void hmi_gfx_mgr02_monolib_normal_rle_image_normal(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          );
static void hmi_gfx_mgr02_monolib_normal_rle_image_blend(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          );




#endif
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)
UINT8 l_bmp_alpha_merge[256] = 
{
0,	0,	0,	0,  0,  0,  0,	0,  0,	0,	0,	0,  0,  0,  0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	3,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  1,	2,	3,  4,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	3,  4,	5,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	3,  4,	5,	6,
0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	3,  4,	5,	6,  7,
0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	3,  4,	5,	6,  7,	8,
0,	0,	0,	0,	0,	0,	0,  1,	2,	3,  4,	5,	6,  7,	8,	9,
0,	0,	0,	0,	0,	0,	1,	2,	3,  4,	5,	6,  7,	8,	9,	10,
0,	0,	0,	0,	0,	1,	2,	3,  4,	5,	6,  7,	8,	9,	10,	11,
0,	0,	0,	0,	1,	2,	3,  4,	5,	6,  7,	8,	9,	10,	11,	12,
0,	0,	0,	1,	2,	3,  4,	5,	6,  7,	8,	9,	10,	11,	12,	13,
0,	0,  1,	2,	3,  4,	5,	6,  7,	8,	9,	10,	11,	12,	13,	14,
0,  1,	2,	3,  4,	5,	6,  7,	8,	9,	10,	11,	12,	13,	14,	15,
};
#endif

const UINT8 l_alpha_blend[256] = 
{
0,	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	11,	12,	13,	14,	15,
1,	2,	3,	4,	5,	6,	7,	8,	8,	9,	10,	11,	12,	13,	14,	15,
2,	3,	4,	5,	5,	6,	7,	8,	9,	10,	11,	12,	12,	13,	14,	15,
3,	4,	5,	5,	6,	7,	8,	9,	9,	10,	11,	12,	13,	13,	14,	15,
4,	5,	5,	6,	7,	8,	8,	9,	10,	11,	11,	12,	13,	14,	14,	15,
5,	6,	6,	7,	8,	8,	9,	10,	10,	11,	12,	12,	13,	14,	14,	15,
6,	7,	7,	8,	8,	9,	10,	10,	11,	11,	12,	13,	13,	14,	14,	15,
7,	8,	8,	9,	9,	10,	10,	11,	11,	12,	12,	13,	13,	14,	14,	15,
8,	8,	9,	9,	10,	10,	11,	11,	12,	12,	13,	13,	14,	14,	15,	15,
9,	9,	10,	10,	11,	11,	11,	12,	12,	13,	13,	13,	14,	14,	15,	15,
10,	10,	11,	11,	11,	12,	12,	12,	13,	13,	13,	14,	14,	14,	15,	15,
11,	11,	12,	12,	12,	12,	13,	13,	13,	13,	14,	14,	14,	14,	15,	15,
12,	12,	12,	13,	13,	13,	13,	13,	14,	14,	14,	14,	14,	15,	15,	15,
13,	13,	13,	13,	14,	14,	14,	14,	14,	14,	14,	14,	15,	15,	15,	15,
14,	14,	14,	14,	14,	14,	14,	14,	15,	15,	15,	15,	15,	15,	15,	15,
15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,	15,
}; 


/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

#if !defined GFX_COMPILE_SPEED_OPTIMIZE
static void GfxDriverClipCalculate(SINT16 * p_x,
                            SINT16 * p_y,
                            UINT16 * p_fl_copy_sindex_U16,
                            UINT16 * p_fl_copy_y_U16,
                            UINT16 * p_fl_copy_width_U16,
                            UINT16 * p_fl_copy_height_U16,
                            UINT16 width,
							UINT16 height
);
#endif

#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_1bpp_trans_text(GFX_MGR02_COLOR* fb_data_ptr,
  UINT8 layer,
  SINT16 x,
  SINT16 y,
  const GFX_MGR02_COLOR* bmp_data,
  UINT16 height,
  UINT16 width,
  GFX_MGR02_ALPHA alpha
  , UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
  , UINT16 p_clip_length /* how much to copy                                       */
);


#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_1bpp_trans_inv_text(GFX_MGR02_COLOR* fb_data_ptr,
  UINT8 layer,
  SINT16 x,
  SINT16 y,
  const GFX_MGR02_COLOR* bmp_data,
  UINT16 height,
  UINT16 width,
  GFX_MGR02_ALPHA alpha
  , UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
  , UINT16 p_clip_length /* how much to copy                                       */
); 

#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif
void hmi_gfx_mgr02_monolib_normal_image_text_normal(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    );
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif    
void hmi_gfx_mgr02_monolib_normal_image_text_blend(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    );
#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)||(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)  
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif    
void hmi_gfx_mgr02_monolib_4bpp_8bpp_trans_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    UINT8 drawcolour, 
	SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    );
#endif 
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif    
void hmi_gfx_mgr02_monolib_normal_inv_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    );
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif    
void hmi_gfx_mgr02_monolib_trans_image(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer, 
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha,
	GFX_MGR02_COLOR trans_color
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    );
/*===========================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{

	if(p_cntx_SP->state.invisible == 0)
	{
		l_clip_area_S[0].x = p_cntx_SP->state.clip.sx;
		l_clip_area_S[0].y = p_cntx_SP->state.clip.sy;
		l_clip_area_S[0].width = p_cntx_SP->state.clip.ex - p_cntx_SP->state.clip.sx;
		l_clip_area_S[0].height = p_cntx_SP->state.clip.ey - p_cntx_SP->state.clip.sy;
		
	  if(p_elem_def_SP->chroma_key==1)
		{
	#if defined GFX_MGR02_COMPRESSION_ENABLED
			if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
			{
			   hmi_gfx_mgr02_monolib_trans_rle_image(
			    	p_cntx_SP->rprop.fb_P,
			    	p_cntx_SP->rprop.layer_id,
			    	p_cntx_SP->state.loc.x, 
			    	p_cntx_SP->state.loc.y, 
			    	p_elem_def_SP->pixel_data, 
			    	p_elem_def_SP->height, 
			    	p_elem_def_SP->width,
			    	p_cntx_SP->state.alpha,
			    	p_cntx_SP->rprop.fg_color
			    	,0
			    	,p_elem_def_SP->width
			    	);
			}
			else
	#endif
			{
				hmi_gfx_mgr02_monolib_trans_image(
					p_cntx_SP->rprop.fb_P,
					p_cntx_SP->rprop.layer_id,
					p_cntx_SP->state.loc.x, 
					p_cntx_SP->state.loc.y, 
					p_elem_def_SP->pixel_data, 
					p_elem_def_SP->height, 
					p_elem_def_SP->width,
					p_cntx_SP->state.alpha,
					p_cntx_SP->rprop.fg_color
					,0
					,p_elem_def_SP->width
					);
			}
		}
		else
		{
	#if defined GFX_MGR02_COMPRESSION_ENABLED
			if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
			{
			    if(p_elem_def_SP->format == GFX_MGR02_MONO_NORMAL)
				{
			    	hmi_gfx_mgr02_monolib_normal_rle_image_normal(
			    		p_cntx_SP->rprop.fb_P,
			    		p_cntx_SP->rprop.layer_id,
			    		p_cntx_SP->state.loc.x, 
			    		p_cntx_SP->state.loc.y, 
			    		p_elem_def_SP->pixel_data, 
			    		p_elem_def_SP->height, 
			    		p_elem_def_SP->width,
			    		p_cntx_SP->state.alpha
			    		,0
			    		,p_elem_def_SP->width
			    		);
			    }
				else if(p_elem_def_SP->format == GFX_MGR02_MONO_TRANSPARENT)
				{
			    	hmi_gfx_mgr02_monolib_normal_rle_image_blend(
			    		p_cntx_SP->rprop.fb_P,
			    		p_cntx_SP->rprop.layer_id,
			    		p_cntx_SP->state.loc.x, 
			    		p_cntx_SP->state.loc.y, 
			    		p_elem_def_SP->pixel_data, 
			    		p_elem_def_SP->height, 
			    		p_elem_def_SP->width,
			    		p_cntx_SP->state.alpha
			    		,0
			    		,p_elem_def_SP->width
			    		);
				}
				else
				{
				 /*For MISRA warning Fix*/
				}  
			}
			else
	#endif
			{
			    if(p_elem_def_SP->format == GFX_MGR02_MONO_NORMAL)
				{

			    	hmi_gfx_mgr02_monolib_normal_image_text_normal(
			    		p_cntx_SP->rprop.fb_P,
			    		p_cntx_SP->rprop.layer_id,
			    		p_cntx_SP->state.loc.x, 
			    		p_cntx_SP->state.loc.y, 
			    		p_elem_def_SP->pixel_data, 
			    		p_elem_def_SP->height, 
			    		p_elem_def_SP->width,
			    		p_cntx_SP->state.alpha
			    		,0
			    		,p_elem_def_SP->width
			    		);
				}
				else if(p_elem_def_SP->format == GFX_MGR02_MONO_TRANSPARENT)
				{
				    hmi_gfx_mgr02_monolib_normal_image_text_blend(
			    		p_cntx_SP->rprop.fb_P,
			    		p_cntx_SP->rprop.layer_id,
			    		p_cntx_SP->state.loc.x, 
			    		p_cntx_SP->state.loc.y, 
			    		p_elem_def_SP->pixel_data, 
			    		p_elem_def_SP->height, 
			    		p_elem_def_SP->width,
			    		p_cntx_SP->state.alpha
			    		,0
			    		,p_elem_def_SP->width
			    		);
				}
				else
				{
					/*For MISRA warning Fix*/
                }

			}

		}
	} /*if(p_cntx_SP->state.invisible == 0)*/
	return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_build_fill
Description          : Builds a fill object
Invocation           : Invoked internally
Parameters           : element definition and dimention of fill area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_build_fill(GFX_MGR02_CONTEXT_T  const * p_context_SP, 
                                            GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{

	if(p_context_SP->state.invisible == 0)
	{
		SINT32 tot_width;
		SINT32 tot_height;
		UINT16 height;
		UINT16 width;
#if defined(GFX_LAYER_XY_OFFSET_ENABLED) && defined(GFX_LAYER_XY_OFFSET_ENABLED)
		SINT16  x = p_context_SP->state.loc.x + GFX_LAYER_X_OFFSET;
		SINT16  y = p_context_SP->state.loc.y + GFX_LAYER_Y_OFFSET;
#else
		SINT16  x = p_context_SP->state.loc.x;
		SINT16  y = p_context_SP->state.loc.y;
#endif
        UINT8   alpha          = p_context_SP->state.alpha;
		UINT16 scr_height      = p_dim->height;
		UINT16 scr_width       = p_dim->width;
		UINT8  fl_layer        = p_context_SP->rprop.layer_id;

        UINT8  inversion = p_context_SP->rprop.fg_color;

   UINT16 fl_copy_sindex_U16 = 0;
   UINT16 fl_copy_width_U16  = scr_width;
   UINT16 fl_copy_y_U16      = 0;
   UINT16 fl_copy_height_U16 = scr_height; 

		l_clip_area_S[0].x = p_context_SP->state.clip.sx;
		l_clip_area_S[0].y = p_context_SP->state.clip.sy;
		l_clip_area_S[0].width = p_context_SP->state.clip.ex - p_context_SP->state.clip.sx;
		l_clip_area_S[0].height = p_context_SP->state.clip.ey - p_context_SP->state.clip.sy;

   
     if(alpha != 0xFF)
     {
        UINT8 fl_temp_inversion = 0;
        alpha = alpha >> GFX_MGR02_PIX_ALPHA_SHFT;
        inversion = inversion >> GFX_MGR02_PIX_ALPHA_SHFT;
        inversion = (inversion * alpha)/GFX_MGR02_PIX_FORMAT_ALPHA;
        fl_temp_inversion = inversion << GFX_MGR02_PIX_ALPHA_SHFT;
        inversion = inversion | fl_temp_inversion;
     }

	height = scr_height;
	width  = scr_width;

   #ifdef GFX_COMPILE_SPEED_OPTIMIZE   
   GfxDriverClipCalculate(x,y,fl_copy_sindex_U16,fl_copy_y_U16,fl_copy_width_U16,fl_copy_height_U16, width, height);   
   #else
   GfxDriverClipCalculate(&x,&y,&fl_copy_sindex_U16,&fl_copy_y_U16,&fl_copy_width_U16,&fl_copy_height_U16, width, height); 
   #endif

   scr_width =  fl_copy_width_U16;
   scr_height = fl_copy_height_U16;
   tot_height = (SINT32)(y+scr_height);
   tot_width  = (SINT32)(x+scr_width);


		if(tot_height >= p_context_SP->rprop.fb_h)
		{
			scr_height = scr_height - (tot_height - p_context_SP->rprop.fb_h);
			tot_height = p_context_SP->rprop.fb_h;
		}

		if(tot_width >= p_context_SP->rprop.fb_w)
		{
			scr_width = scr_width - (tot_width - p_context_SP->rprop.fb_w);
			tot_width = p_context_SP->rprop.fb_w;
		}

		if((scr_height != 0) &&
			(scr_width  != 0) &&
			(x + scr_width <= p_context_SP->rprop.fb_w) &&
			(y + scr_height <= p_context_SP->rprop.fb_h)&&
			(tot_height > 0) &&
			(tot_width  > 0))
		{
			GFX_MGR02_COLOR * fl_fb_U8AP;
			GFX_MGR02_COLOR * fl_temp_fb_U8AP;
			UINT16        fl_cwidth_U8;
			UINT8         fl_start_offset_U8;
			UINT8         fl_end_offset_U8;
			UINT8         fl_smask_U8;
			UINT8         fl_cmask_U8;
			UINT16        fl_nb_lines_U16;
			UINT8         fl_start_height_U8;
			UINT16        fl_count_U16;

   #if GFX_MGR02_NUM_OF_FILLS > 0
      if(x < 0)
	  {
	    scr_width = tot_width;
        x = 0;
	  }
      if(y < 0)
	  {
	    scr_height = tot_height;
        y = 0;
	  }
   #endif
   #if GFX_MGR02_HOR_PACKING > 0
      fl_count_U16 = x;
      x        = y;
      y        = fl_count_U16;
      fl_count_U16 = scr_width;
			scr_width    = scr_height;
			scr_height   = fl_count_U16;
   #endif

   #if LCD_SIZE_MUL_FACTOR > 0
      y          <<= LCD_SIZE_MUL_FACTOR;
      scr_height <<= LCD_SIZE_MUL_FACTOR;
   #endif

      fl_start_offset_U8 = SOFFS(y);
			fl_temp_fb_U8AP    = p_context_SP->rprop.fb_P;

			fl_fb_U8AP         = GET_FBP(fl_temp_fb_U8AP, x, y, fl_layer);

			if((fl_start_offset_U8+scr_height) >= 8)
			{
				if(fl_start_offset_U8 == 0)
				{
					/*
					** aligned to byte boundary.
					*/
					fl_nb_lines_U16 = NLINES(scr_height);
					while(fl_nb_lines_U16 != 0)
					{
						fl_cwidth_U8 = scr_width;
						for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
						{
							FB(fl_fb_U8AP, fl_count_U16,fl_layer) = inversion;
							GFX_DRIVER_SCHED_WAIT();
						}
						fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP, fl_layer);
						fl_nb_lines_U16--;
					}
					fl_end_offset_U8 = SOFFS(scr_height);
					if(fl_end_offset_U8 != 0)
					{
						/*
						** Copy the unaligned end pixels. if any
						*/
						fl_cmask_U8  = SL((UINT8)0xFF , fl_end_offset_U8);
						fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
						fl_cwidth_U8 = scr_width;
						if(inversion == 0)
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
						else if(inversion == GFX_WHITE_COLOUR)
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
						else
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
					}
				}
				else
				{
					fl_start_height_U8 = (8-fl_start_offset_U8);
					fl_cmask_U8        = (UINT8)SR((UINT8)0xFF ,fl_start_height_U8);
					fl_smask_U8        = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
					fl_cwidth_U8       = scr_width;

					if(inversion == 0)
					{
						for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
						{
							FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
							GFX_DRIVER_SCHED_WAIT();
						}
					}
					else if(inversion == GFX_WHITE_COLOUR)
					{
						for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
						{
							FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
							GFX_DRIVER_SCHED_WAIT();
						}
					}
					else
					{
						for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
						{
							FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
							FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
							GFX_DRIVER_SCHED_WAIT();
						}
					}

					fl_fb_U8AP        = NEXT_FBP_LINE(fl_fb_U8AP,fl_layer);
					fl_nb_lines_U16   = (scr_height-(UINT16)fl_start_height_U8);
					fl_end_offset_U8  = (UINT8)(fl_nb_lines_U16 & 0x07);
					fl_nb_lines_U16 >>= 3;

					while(fl_nb_lines_U16 != 0)
					{
						fl_cwidth_U8 = scr_width;
						for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
						{
							FB(fl_fb_U8AP, fl_count_U16, fl_layer) = inversion;
						}
						fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP, fl_layer);
						fl_nb_lines_U16--;
						GFX_DRIVER_SCHED_WAIT();
					}

					if(fl_end_offset_U8 != 0)
					{
						fl_cwidth_U8 = scr_width;
						fl_cmask_U8  = SL((UINT8)0xFF , fl_end_offset_U8);
						fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
						if(inversion == 0)
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
						else if(inversion == GFX_WHITE_COLOUR)
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
						else
						{
							for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
							{
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
								FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
								GFX_DRIVER_SCHED_WAIT();
							}
						}
					}
				}
			}
			else
			{
				/*
				** Just one line to clear
				*/
				fl_cmask_U8  = SL((UINT8)0xFF , (fl_start_offset_U8+scr_height));
				fl_smask_U8  = (UINT8)SR((UINT8)0xFF , (8-fl_start_offset_U8));
				fl_cmask_U8 += fl_smask_U8;
				fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
				fl_cwidth_U8 = scr_width;
				if(inversion == 0)
				{
					for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
					{
						FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
						GFX_DRIVER_SCHED_WAIT();
					}
				}
				else if(inversion == GFX_WHITE_COLOUR)
				{
					for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
					{
						FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
						GFX_DRIVER_SCHED_WAIT();
					}
				}
				else
				{
					for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
					{
						FB(fl_fb_U8AP, fl_count_U16, fl_layer) &= fl_cmask_U8;
						FB(fl_fb_U8AP, fl_count_U16, fl_layer) |= fl_smask_U8;
						GFX_DRIVER_SCHED_WAIT();
					}
				}
			}
		}
		GFX_MGR02_UNUSED_PTR(p_elem_def_SP);
	}
	return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_build_text
Description          : Builds a text object
Invocation           : Invoked internally
Parameters           : element definition and pointer to string
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                            HMI_CHAR             const * p_string,
                                            u_gx_flocal                  p_text_actual_width)

{
   GFX_MGR02_FONT const * fl_font_SP;   UINT32 fl_clip_flag = 0;
    
    GFX_MGR02_TEXT_INFO fl_text_info_S;
    GFX_MGR02_ISIZE_X_T           fl_start_x            = p_cntx_SP->state.loc.x;
    const GFX_MGR02_ISIZE_Y_T     fl_start_y            = p_cntx_SP->state.loc.y;
    HMI_CHAR             const* fl_disp_string_temp_P = p_string;
    HMI_CHAR             const* fl_disp_string_P      = p_string;
    UINT32 fl_font_index = hmi_gfx_mgr02_get_font_id(p_elem_def_SP->font_id);



          GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_P       = ( GFX_MGR02_FONT_CHAR_CONFIG const * )NULL;
          GFX_MGR02_ISIZE_X_T           fl_x_size_temp        = p_elem_def_SP->width;
          GFX_MGR02_ISIZE_X_T           fl_x_size             = 0;
          GFX_MGR02_ISIZE_Y_T           fl_cur_y;
          GFX_MGR02_ISIZE_X_T           fl_cur_x;
          GFX_MGR02_COLOR            fl_draw_color;
          SINT16                 fl_scroll_offset_temp_S16;
          SINT16                 fl_scroll_offset_S16 = 0;
#if defined(EXTERNAL_FONT_FLASH_ENABLED)
       	HMI_CHAR p_char;
       #endif
  if(p_cntx_SP->state.invisible == 0)
  {

#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
	SINT16 fl_glyph_advance_x = 0;
	SINT32 fl_str_index = (SINT32)0;
	UINT32 fl_zw_char_exist_flag = FALSE;
	UINT8  fl_prev_char_owidth = 0;
	GFX_MGR02_ISIZE_X_T  fl_prev_char_x_size = 0;
#endif 
	UINT32 fl_last_char_clip_flag = FALSE;

    l_clip_area_S[0].x = p_cntx_SP->state.clip.sx;
    l_clip_area_S[0].y = p_cntx_SP->state.clip.sy;
    l_clip_area_S[0].width = p_cntx_SP->state.clip.ex - p_cntx_SP->state.clip.sx;
    l_clip_area_S[0].height = p_cntx_SP->state.clip.ey - p_cntx_SP->state.clip.sy;
    fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_index);

          fl_text_info_S.print_str_P = p_string;
          if(p_text_actual_width != 0)
          {
             fl_text_info_S.max_available_width = (UINT16)p_text_actual_width;
          }
          else
          {
             fl_text_info_S.max_available_width = p_cntx_SP->rprop.text_width;
          }
          fl_text_info_S.target = GFX_MGR02_TARGET_MONOTFT;



    /*
    ** Retrive the scroll offset in pixels information from end of the
    ** text string buffer.
    */

          #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
            fl_text_info_S.append_str = TRUE;
            l_ovglib_clip_text_str[0] = 0;
          #else
            fl_text_info_S.append_str = FALSE;
          #endif
            fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
            fl_clip_flag = hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                             p_cntx_SP->rprop.font_id,
                                             p_cntx_SP->rprop.clip_mode,
                                             p_cntx_SP->rprop.alignment
                                         #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                            ,l_ovglib_clip_text_str
                                         #endif
                                            );

    if((p_elem_def_SP->scroll ==  GFX_MGR02_TP_SCROLL_ENABLE) &&
        (fl_clip_flag != FALSE))
    {
	    fl_scroll_offset_S16 = p_cntx_SP->rprop.scroll_offset;
        if(fl_scroll_offset_S16 < 0)
        {
            fl_scroll_offset_S16 = -fl_scroll_offset_S16;
            if(fl_scroll_offset_S16 < fl_x_size_temp)
            {
                fl_x_size_temp -= fl_scroll_offset_S16;
        		if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_RIGHT)) != 0)
                {
                    fl_start_x -= fl_scroll_offset_S16;
                }
                else
                {
                    fl_start_x += fl_scroll_offset_S16;
                }
                fl_scroll_offset_S16 = 0;
            }
            else
            {
                fl_x_size_temp  = 0;
            }
        }
        fl_scroll_offset_temp_S16 = fl_scroll_offset_S16;
    }
    else
    {
        fl_scroll_offset_S16      = 0;
        fl_scroll_offset_temp_S16 = 0;
    }
    if(fl_font_SP != 0)
    {
      if((fl_x_size_temp > 0) && (*fl_disp_string_P != 0))
      {
          /*
          ** Find the width of string that could be fitted in the configured 
          ** width for the dynamic text. For example if the configured width
          ** is 100pixels and the passed string requires, 120pixels then 
          ** remove char from left/right side of the string based on the alignment
          ** right/left respectively. 
          */
		  if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_RIGHT)) != 0)
          {
            if(fl_scroll_offset_S16 != 0)
            {
               fl_scroll_offset_S16 = 0;
              while(*fl_disp_string_P != 0)
              {
                  /* 
                  ** Reach the end of the string as the right aligned one shall show
                  ** the last char on the right side.
                  */
                  fl_disp_string_P++;
              }
              while(fl_disp_string_P > fl_disp_string_temp_P)
              {
                  fl_disp_string_P--;
                  fl_font_P =  hmi_gfx_mgr02_get_fcc(*fl_disp_string_P, fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
																						 #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
																							 p_elem_def_SP->font_id,
																						  #endif
																							 TRUE);

                  if(fl_font_P != NULL)
                  {
                      if(fl_scroll_offset_temp_S16 >= fl_font_P->owidth)
                      {
                          fl_scroll_offset_temp_S16 -= fl_font_P->owidth;
                      }
                      else
                      {
                        if(fl_x_size == 0)
                        {
                            fl_x_size                 = (fl_font_P->owidth-fl_scroll_offset_temp_S16);
                            fl_scroll_offset_temp_S16 = 0;
                        }
                        else
                        {
                            fl_x_size += fl_font_P->owidth;
                        }
                        if(fl_x_size == fl_x_size_temp)
                        {
                            break;
                        }
                        else if(fl_x_size > fl_x_size_temp)
                        {
                            /*
                            ** We overshoot the available width. so if the clip configuration is
                            ** set to normal we can display the char partially but if clip is set
                            ** to other values, then we need to remove this char itself so that 
                            ** there are no partial display of char.
                            */
				            if((p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL) ||
				               (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_APPEND))
							{
                                fl_scroll_offset_S16 = (fl_x_size-fl_x_size_temp);
                                fl_x_size            = fl_x_size_temp;
                            }
                            else
                            {
                                /* Remove char as there is no partial display allowed */
                                fl_disp_string_P++;
                                fl_x_size -= fl_font_P->owidth;
                            }
                            break;
                        }
                        else
                        {
                            /*
                            ** We are with in the allowed width, so continue
                            */
                        }
                    }
                 }
              }
		    }
		    else
		    {
              fl_text_info_S.print_str_P = p_string;
              (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                             p_cntx_SP->rprop.font_id,
                                             p_cntx_SP->rprop.clip_mode,
                                             p_cntx_SP->rprop.alignment
                                         #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                            ,l_ovglib_clip_text_str
                                         #endif
                                            );


			  fl_x_size = fl_text_info_S.print_width;
			  fl_disp_string_P = fl_text_info_S.print_str_P;
		   }
           if(fl_x_size > 0)
           {
             fl_x_size_temp = fl_x_size;
             fl_x_size_temp--;
               fl_start_x -= fl_x_size_temp;
          }
        }
        else
        {
            /* Centre or Left aligned */
		  if(fl_scroll_offset_S16 != 0)
		  {
            while(*fl_disp_string_temp_P != 0)
            {
                fl_font_P =  hmi_gfx_mgr02_get_fcc(*fl_disp_string_temp_P, fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
																						 #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
																							 p_elem_def_SP->font_id,
																						  #endif
																							 TRUE);


                if(fl_font_P != NULL)
                {
                    if(fl_scroll_offset_temp_S16 >= fl_font_P->owidth)
                    {
                        fl_scroll_offset_temp_S16 -= fl_font_P->owidth;
                    }
                    else
                    { 
                        if(fl_x_size == 0)
                        {
                            fl_disp_string_P          = fl_disp_string_temp_P;
                            fl_x_size                 = (fl_font_P->owidth-fl_scroll_offset_temp_S16);
                            fl_scroll_offset_S16      = fl_scroll_offset_temp_S16;
                            fl_scroll_offset_temp_S16 = 0;
                        }
                        else
                        {
                            fl_x_size += fl_font_P->owidth;
                        }
                        if(fl_x_size == fl_x_size_temp)
                        {
                            break;
                        }
                        else if(fl_x_size > fl_x_size_temp)
                        {
				            if((p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_NORMAL) ||
				               (p_cntx_SP->rprop.clip_mode == GFX_MGR02_TP_CLIP_APPEND))
                            {
                                /* In normal clipping mode we can display partial chars. */
                                fl_x_size  = fl_x_size_temp;
                            }
                            else
                            {
                                /* cannot accomodate the last char in given width, so remove it fully. */
                                fl_x_size -= fl_font_P->owidth;
                            }
                            break;
                        }
                        else
                        {
                        	/*For MISRA warning Fix*/
                        }
                    }
                }
                fl_disp_string_temp_P++;
              }
          }
          else
          {
              fl_text_info_S.print_str_P = p_string;
              (void)hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                             p_cntx_SP->rprop.font_id,
                                             p_cntx_SP->rprop.clip_mode,
                                             p_cntx_SP->rprop.alignment
                                         #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                            ,l_ovglib_clip_text_str
                                         #endif
                                            );
              fl_x_size = fl_text_info_S.print_width;
              fl_disp_string_P = fl_text_info_S.print_str_P;
          }
          if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_CENTRE)
          {
              fl_x_size_temp = (fl_x_size>>1);
                fl_start_x -= fl_x_size_temp;
          }
        }

        fl_draw_color = p_cntx_SP->rprop.fg_color;
		if(p_cntx_SP->rprop.draw_mode != GFX_MGR02_TP_DRAW_TRANSP)
        {
		   GFX_MGR02_CONTEXT_T          fl_context_SP;
		   GFX_MGR02_IDIM_DATA          fl_dim;
		   fl_context_SP = *p_cntx_SP;
		   fl_dim.height              = fl_font_SP->p.height;
           fl_dim.width               = p_elem_def_SP->width;
           if(fl_draw_color != 0)
           {
             fl_draw_color = 0xFF;
           }
		   if(p_cntx_SP->rprop.draw_mode == (UINT8)GFX_MGR02_TP_DRAW_REVERSE)
           {
              fl_context_SP.rprop.fg_color  = fl_draw_color;
              fl_draw_color = ~fl_draw_color;
           }
           else
           {
              fl_context_SP.rprop.fg_color = ~fl_draw_color;
           }
           /* Reset the text box's X position to its original */
           if(fl_context_SP.rprop.alignment == (UINT8)GFX_MGR02_TP_ALIGN_CENTRE)
           {
             fl_context_SP.state.loc.x -= (fl_dim.width/2);
           }
           else if(fl_context_SP.rprop.alignment == (UINT8)GFX_MGR02_TP_ALIGN_RIGHT)
           {
             fl_context_SP.state.loc.x -= fl_dim.width;
           }
           else
           {
        	   /*For MISRA warning Fix*/
           }
		   hmi_gfx_mgr02_monolib_build_fill(&fl_context_SP,0, &fl_dim);
        }


	#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
		/* when rendering thai or hindi (LTR) based scripts, and if last char is zw then it is skipping, so handling this case */
		while(((*fl_disp_string_P != 0) && (fl_x_size > 0)) || (fl_zw_char_exist_flag == TRUE))
    #else
        while((*fl_disp_string_P != 0) && (fl_x_size > 0))
    #endif
        {
		   fl_last_char_clip_flag = FALSE;
         #if defined(EXTERNAL_FONT_FLASH_ENABLED)
            /* Get the data if external font flash is enabled */
            p_char = *fl_disp_string_P;
            fl_font_P = GFX_GET_FONT_DATA(p_char);
            /* If the received data is valid proceed with the data */
            if(fl_font_P != ((void *)0))
            {
            /* Do nothing */
            }
            /* If the received data is not valid */
            else
         #endif
            {
                fl_font_P =  hmi_gfx_mgr02_get_fcc(*fl_disp_string_P, fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
																						 #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
																							 p_elem_def_SP->font_id,
																						  #endif
																							 TRUE);


            }
            if(fl_font_P != NULL)
            {
                fl_cur_y        = (fl_start_y + fl_font_P->y_soffset);
                fl_x_size_temp  = fl_font_P->owidth;
                fl_x_size_temp -= fl_scroll_offset_S16;
                if(fl_x_size >= fl_x_size_temp)
                {
                    fl_x_size -= fl_x_size_temp;
                }
                else
                {
                    fl_x_size_temp       = fl_x_size;
                    fl_scroll_offset_S16 = 0;
                    fl_x_size            = 0;
					fl_last_char_clip_flag = TRUE;
                }
                fl_cur_x      = fl_start_x;
                fl_start_x   += fl_x_size_temp;

				if((fl_x_size_temp == 0) && (fl_x_size == 0))
				{
				  fl_last_char_clip_flag = TRUE;
				}
                if(((fl_x_size_temp == fl_font_P->owidth) && ((p_cntx_SP->rprop.scroll_offset) == 0)) ||
                   ((fl_x_size_temp == fl_font_P->owidth) && ((p_cntx_SP->rprop.scroll_offset) > 0) && (fl_last_char_clip_flag != TRUE)))
                {
                    /* No clipping necessary */
                    fl_cur_x       += fl_font_P->x_soffset;
                    fl_x_size_temp  = fl_font_P->width;
                }
                else
                {
                    /* Clipping is required, so recalculate the copy width and start offset */
                  if(fl_last_char_clip_flag != TRUE)
				  {
					/* Below code will take care of first character clipping in scroll */
                    if(fl_scroll_offset_S16 < fl_font_P->x_soffset)
                    {
                        fl_scroll_offset_S16 = (fl_font_P->x_soffset-fl_scroll_offset_S16);
                        if(fl_x_size_temp > fl_scroll_offset_S16)
                        {
                            fl_x_size_temp      -= fl_scroll_offset_S16;
                            fl_cur_x            += fl_scroll_offset_S16;
                            fl_scroll_offset_S16 = 0;
                            if(fl_x_size_temp > fl_font_P->width)
                            {
                                fl_x_size_temp = fl_font_P->width;
                            }
                        }
                        else
                        {
                            fl_x_size_temp = 0;
                        }
                    }
                    else
                    {
                        fl_scroll_offset_S16 -= fl_font_P->x_soffset;
                        if((fl_x_size_temp+fl_scroll_offset_S16) > fl_font_P->width)
                        {
                            fl_x_size_temp = (fl_font_P->width-fl_scroll_offset_S16);
                        }
                    }
				  }
				  else
				  {
				#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
					/* Below code will take care of last character clipping in scroll when there is no zw or overlapping characters*/
					if(fl_zw_char_exist_flag != TRUE)
					{
					  
					  fl_cur_x    += fl_font_P->x_soffset;
					  if(fl_font_P->owidth == 0)
					  {
						fl_x_size_temp = fl_font_P->width;
					  }
					  else
					  {
					    fl_x_size_temp -= fl_font_P->x_soffset;
					  }
					  if(fl_x_size_temp > fl_font_P->width)
                      {
                         fl_x_size_temp = fl_font_P->width;
                      }
					}
					else if((p_elem_def_SP->scroll ==  GFX_MGR02_TP_SCROLL_ENABLE) &&
                            (fl_clip_flag != FALSE) && ((p_cntx_SP->rprop.scroll_offset) > 0) && (fl_zw_char_exist_flag == TRUE))
					{
					  /* Below code will take care of last character clipping in scroll when there is any zw or overlapping characters*/
					  if((fl_prev_char_x_size <= fl_prev_char_owidth) && (fl_prev_char_x_size != 0))
					  {
						/* zw char can be render properly only when current position is at the advance of the base char,
						*  but in current case, base char it self is not fully renderd so x- position can not be at 
						*  advance of the base char.
						*  To overcome this issue, below expressoions will help
						*/
						fl_cur_x = fl_start_x;
						fl_cur_x = fl_cur_x + fl_font_P->x_soffset - fl_prev_char_x_size + fl_prev_char_owidth;
						fl_x_size_temp = fl_start_x - fl_cur_x;
						if(fl_x_size_temp < 0)
						{
						  /* This means current character is not falling under the scroll clear area,
						  *  so skip this character to render
                          */						  
						  fl_x_size_temp = 0;

						  fl_scroll_offset_S16 = 0;
						  fl_prev_char_owidth = 0;
						  fl_zw_char_exist_flag = FALSE;

						  continue;
						}
						if(fl_x_size_temp > fl_font_P->width)
                        {
                          fl_x_size_temp = fl_font_P->width;
                        }
						fl_scroll_offset_S16 = 0;
						fl_prev_char_owidth = 0;
						fl_zw_char_exist_flag = FALSE;
					  }
					}
                #else
					fl_x_size_temp -= fl_font_P->x_soffset;
					fl_cur_x    += fl_font_P->x_soffset;
					if(fl_x_size_temp > fl_font_P->width)
                    {
                      fl_x_size_temp = fl_font_P->width;
                    }
	            #endif
					fl_scroll_offset_S16 = 0;
				  }
                }

				if(fl_font_P->fdata != 0)
				{
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
					GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0f, 0.0f };
    #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
					GFX_MGR02_GPOS_DELTA fl_gpos_info = {0.0f, 0.0f};
					BOOLEAN fl_gpos_found = GFX_MGR02_GPOS_INVALID_TBL;
				#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
					if((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[0]) == 1U))
				#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
                    if(GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[0]) == 1U)
                #else
                    if(GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[0]) == 1U)
                #endif
					{
						(void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (fl_disp_string_P-1) , fl_str_index, fl_font_SP ,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
						/*X offset of the mark char should be positioned based on the previouse base char.
						For LTR languages, mark char will come after the base char. While rendering base char
						we are moving the x position based on owidth of the same. Hence the mark char
						position is adjusted based on previous base char position.
						Here fl_glyph_advance_x holds the owidth of the previous char*/
						fl_delta_pixels.gpos_delta_pixels_x -= (GFX_FLOAT)(fl_glyph_advance_x);
					}
					else
					{
						fl_glyph_advance_x = 0;
					}
					/*Store the owidth of the current char if is there any GPOS table found for the current and next char
					combination*/
					fl_gpos_found = hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_gpos_info, &fl_disp_string_P[0], fl_str_index, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
				#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
					if(( fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[1]) == 1U)) ||
                       ( fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL && (GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[1]) == 1U)))
				#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
                    if( fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[1]) == 1U))
                #else
                    if( fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL && (GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[1]) == 1U))
                #endif
					{
						fl_glyph_advance_x += fl_font_P->owidth;
					}
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED) 
					if (GFX_MGR02_IS_HEBREW_VOWEL(fl_disp_string_P[0]) == 1U)
					{
						(void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_disp_string_P[0], 0, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);

					}
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)					
					if (GFX_MGR02_IS_ARABIC_VOWEL(fl_disp_string_P[0]) == 1U)
					{
						(void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_disp_string_P[0], 0, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
					}
#endif
					fl_cur_x = (GFX_MGR02_ISIZE_X_T)fl_cur_x + fl_delta_pixels.gpos_delta_pixels_x;
					fl_cur_y = (GFX_MGR02_ISIZE_Y_T)fl_cur_y - fl_delta_pixels.gpos_delta_pixels_y;
#endif

		        if(p_cntx_SP->rprop.draw_mode == GFX_MGR02_TP_DRAW_TRANSP)
                {
#if (GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_2BPP)&&(GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_4BPP)                   
                   if(fl_draw_color != 0)
                   {
				      hmi_gfx_mgr02_monolib_1bpp_trans_text(
					    p_cntx_SP->rprop.fb_P,
					    p_cntx_SP->rprop.layer_id,
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
						p_cntx_SP->state.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                   else
                   {
  				      hmi_gfx_mgr02_monolib_1bpp_trans_inv_text(
					    p_cntx_SP->rprop.fb_P,
					    p_cntx_SP->rprop.layer_id,
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                       fl_font_P->width,
						           p_cntx_SP->state.alpha,
                       fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
#else
  				      hmi_gfx_mgr02_monolib_4bpp_8bpp_trans_text(
					    p_cntx_SP->rprop.fb_P,
					    p_cntx_SP->rprop.layer_id,
                        fl_draw_color,
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
						p_cntx_SP->state.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
#endif  /* (GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_2BPP)&&(GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_4BPP) */
                }
                else
                {
                   if(fl_draw_color != 0)
                   {
                      hmi_gfx_mgr02_monolib_normal_image_text_normal(
					    p_cntx_SP->rprop.fb_P,
                        p_cntx_SP->rprop.layer_id, 
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
               			p_cntx_SP->state.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                   else
                   {
					  hmi_gfx_mgr02_monolib_normal_inv_text(
					    p_cntx_SP->rprop.fb_P,
					    p_cntx_SP->rprop.layer_id,
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        p_cntx_SP->state.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                }
				}
                fl_scroll_offset_S16 = 0;
            }
            fl_disp_string_P++;
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
			fl_str_index++;
			if((*fl_disp_string_P != 0) && (fl_x_size == 0))
			{
			   if(fl_font_P->owidth != 0)
			   {
				 fl_prev_char_owidth = fl_font_P->owidth;
				 fl_prev_char_x_size = fl_x_size_temp;
			   }
			#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
			   if((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[0]) == 1U))
			#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
               if( (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_disp_string_P[0]) == 1U))
            #else
               if((GFX_MGR02_DEVA_ZW_CHAR(fl_disp_string_P[0]) == 1U))
            #endif
			   {
				   fl_zw_char_exist_flag = TRUE;
			   }
			   else
			   {
				   fl_font_P =  hmi_gfx_mgr02_get_fcc(*fl_disp_string_P, fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
																						 #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
																							 p_elem_def_SP->font_id,
																						  #endif
																							 TRUE);
				   if(fl_font_P != NULL)
				   {
				     if(fl_font_P->owidth == 0)
			         {
					   /* when character is last and it is a custom unicode and zero width character, then run loop one more time */
				       fl_zw_char_exist_flag = TRUE;
			         }
					 else
					 {
						/* This case can be occur, when previous character is a zw and text is scrolling */
						  fl_zw_char_exist_flag = FALSE;

						  if((p_elem_def_SP->scroll ==  GFX_MGR02_TP_SCROLL_ENABLE) && (fl_clip_flag != FALSE) && 
					         ((p_cntx_SP->rprop.scroll_offset) > 0) && (fl_font_P->x_soffset < 0))
						  {
							 fl_zw_char_exist_flag = TRUE;
						  }
					 }
				   }
			   }

			}
			else if((*fl_disp_string_P == 0) && (fl_x_size == 0))
			{
			   fl_zw_char_exist_flag = FALSE;
			}
			else
			{
			  /* Do nothing */
			}
#endif
        }
      }
    }
  }
  return 0;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_get_bound
Description          : Calculates the transformed bounds of an elements passed
                       boundary
Invocation           : Invoked by generic manager
Parameters           : context, element def and elements bounds (un transformed).
                       p_bounds index 0,1 (x,y) 2,3 (width,height)
Return Value         : Updates transformed bounds in to p_bound_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_get_bound(UINT32                p_obj_type,
                                           GFX_MGR02_CONTEXT_T const * p_cntx_SP,  /* QA C warning fix RTC : 405974 */
                                           GFX_FLOAT               * p_bounds)
{
   p_bounds[0] = p_cntx_SP->state.loc.x;
   p_bounds[1] = p_cntx_SP->state.loc.y;

   return 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_init(void)
{
   return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_shutdown(void)
{
   return(TRUE);

}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
   return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_finish
Description          : Function to be called after all building operation are
                       completed. This will perform the VG flush to perform
                       any pending VG operations 
Invocation           : Invoked by manager
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
                       drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_finish(void)
{
   return(TRUE);
}

#if !defined GFX_COMPILE_SPEED_OPTIMIZE
static void GfxDriverClipCalculate(SINT16 * ptr_x,
							SINT16 * ptr_y,
							UINT16 * ptr_fl_copy_sindex_U16,
							UINT16 * ptr_fl_copy_y_U16,
							UINT16 * ptr_fl_copy_width_U16,
							UINT16 * ptr_fl_copy_height_U16,
                            UINT16 width,
							UINT16 height
							)
{
   UINT16 fl_cwidth_U16 = 0;
   UINT16 fl_cheight_U16 = 0;
   
   if(*ptr_x < l_clip_area_S[0].x)
   {
      fl_cwidth_U16 = (l_clip_area_S[0].x-*ptr_x);
      *ptr_fl_copy_sindex_U16 += fl_cwidth_U16;
      *ptr_x  = l_clip_area_S[0].x;
      if(*ptr_fl_copy_width_U16 > fl_cwidth_U16)
      {
         *ptr_fl_copy_width_U16 -= fl_cwidth_U16;
      }
      else
      {
         *ptr_fl_copy_width_U16 = 0;
      }
   }
   else
   {
      if(*ptr_x < 0)
      {
         *ptr_fl_copy_sindex_U16 = -*ptr_x;
      }
      *ptr_fl_copy_width_U16 = width - *ptr_fl_copy_sindex_U16;
      if(*ptr_x <= 0)
      {
         *ptr_x = 0;
      }    
   }   
   fl_cwidth_U16 = (l_clip_area_S[0].x+l_clip_area_S[0].width);
   if((*ptr_x+*ptr_fl_copy_width_U16) > fl_cwidth_U16)
   {
      *ptr_fl_copy_width_U16 = (fl_cwidth_U16 - *ptr_x);
   }
   if(*ptr_y < l_clip_area_S[0].y)
   {
      fl_cheight_U16 = (l_clip_area_S[0].y-*ptr_y);
      *ptr_fl_copy_y_U16 += fl_cheight_U16;
      *ptr_y  = l_clip_area_S[0].y;
      if(*ptr_fl_copy_height_U16 > fl_cheight_U16)
      {
         *ptr_fl_copy_height_U16 -= fl_cheight_U16;
      }
      else
      {
         *ptr_fl_copy_height_U16 = 0;
      }
   }
   else
   {
      if(*ptr_y < 0)
      {
         *ptr_fl_copy_y_U16 = -*ptr_y;
      }
      *ptr_fl_copy_height_U16 = height - *ptr_fl_copy_y_U16;
      if(*ptr_y <= 0)
      {
         *ptr_y = 0;
      }    
   }
   fl_cheight_U16 = (l_clip_area_S[0].y+l_clip_area_S[0].height);
   if((*ptr_y+*ptr_fl_copy_height_U16) > fl_cheight_U16)
   {
      *ptr_fl_copy_height_U16 = (fl_cheight_U16 - *ptr_y);
   }
}
#endif


#if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
#ifdef WIN32
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ovglib_pre_copy_fb
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_monolib_pre_copy_fb(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)

{

#if GFX_MGR02_HOR_PACKING != 0
	memcpy(p_cntx_SP->rprop.fb_P, p_elem_def_SP->pixel_data, p_elem_def_SP->height*lc_pixel_def_S[p_cntx_SP->rprop.layer_id].lcd_bytes_per_row);
#else
   memcpy(p_cntx_SP->rprop.fb_P,p_elem_def_SP->pixel_data,p_elem_def_SP->width*lc_pixel_def_S[p_cntx_SP->rprop.layer_id].lcd_bytes_per_col);
#endif
   
   return 0;
}
#endif
#endif

#if defined GFX_MGR02_COMPRESSION_ENABLED
#undef GFX_TRANSPARENT
#undef GFX_TEXT_ON_GREY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#define GFX_RLE_SUPPORT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_normal_rle_image_normal
Description          : Decodes the RLE compressed image online without 
                       requiring an intermediate buffer.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void hmi_gfx_mgr02_monolib_normal_rle_image_normal(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
#undef GFX_TRANSPARENT
#undef GFX_TEXT_ON_GREY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#define GFX_RLE_SUPPORT
#define  GFX_IMAGE_BLEND_USING_ARRAY
#undef  GFX_IMAGE_BLEND_USING_FORMULA
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_normal_rle_image_blend
Description          : Decodes the RLE compressed image online without 
                       requiring an intermediate buffer.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void hmi_gfx_mgr02_monolib_normal_rle_image_blend(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}

#undef GFX_TEXT_ON_GREY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#define GFX_RLE_SUPPORT
#define GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_trans_rle_image
Description          : Decodes the RLE compressed image online without 
                       requiring an intermediate buffer.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void hmi_gfx_mgr02_monolib_trans_rle_image(GFX_MGR02_COLOR * fb_data_ptr,
                           UINT8 layer,
                           SINT16 x,
                           SINT16 y,
                           const GFX_MGR02_COLOR * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   GFX_MGR02_ALPHA alpha,
                           GFX_MGR02_COLOR trans_color
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                          )
{
	#include "hmi_gfx_mgr02_mono_driver.inc"
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_normal_image_text_normal
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_RLE_SUPPORT
#undef  GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_normal_image_text_normal(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_normal_image_text_blend
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_RLE_SUPPORT
#undef  GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#define GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_normal_image_text_blend(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}


/****************************************************************************
Function Name        : 

Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_TEXT_ON_GREY
#define GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_PR_OP(op,val) ((op)=(val))
#define IMG_CP_OP(op,val) ((op)=(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_trans_image(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer, 
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha,
	GFX_MGR02_COLOR trans_color
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
#if (GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_2BPP)&&(GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_4BPP)  
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_1bpp_trans_text
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_TEXT_ON_GREY
#undef GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_PR_OP(op,val) ((op)=(val))
#define IMG_CP_OP(op,val) ((op)|=(val))

#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_1bpp_trans_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_normal_inv_text
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_TEXT_ON_GREY
#undef  GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_PR_OP(op,val)  ((op) =~(val))
#define IMG_CP_OP(op,val)  ((op) =(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_normal_inv_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}

#if (GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_2BPP)&&(GFX_MGR02_PIX_FORMAT != GFX_MGR02_PIX_FORMAT_4BPP)  
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_1bpp_trans_inv_text
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef GFX_TRANSPARENT
#undef  GFX_TEXT_ON_GREY
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#define IMG_PR_OP(op,val)  ((op)=~(val))
#define IMG_CP_OP(op,val)  ((op)&=(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static
#endif
void hmi_gfx_mgr02_monolib_1bpp_trans_inv_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
#endif


#if (GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_2BPP)||(GFX_MGR02_PIX_FORMAT == GFX_MGR02_PIX_FORMAT_4BPP)  
/****************************************************************************
Function Name        : hmi_gfx_mgr02_monolib_4bpp_8bpp_trans_text
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#undef  IMG_CP_OP
#undef  IMG_PR_OP
#undef  GFX_TRANSPARENT
#undef  GFX_IMAGE_BLEND_USING_FORMULA
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#define GFX_TEXT_ON_GREY
#define IMG_PR_OP(op,val)  ((op)=(val))
#define IMG_CP_OP(op,val)  ((op)=(val))
#ifndef GFX_DRIVER_CUSTOM_TEXT_RENDERING
static 
#endif
void hmi_gfx_mgr02_monolib_4bpp_8bpp_trans_text(GFX_MGR02_COLOR * fb_data_ptr,
    UINT8 layer,
    UINT8 drawcolour, 
	SINT16 x,
    SINT16 y,
    const GFX_MGR02_COLOR * bmp_data,
    UINT16 height,
    UINT16 width,
	GFX_MGR02_ALPHA alpha
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
    )
{
    #include "hmi_gfx_mgr02_mono_driver.inc"
}
#endif


#if defined GFX_MGR02_COMPRESSION_ENABLED
#if !defined GFX_COMPILE_SPEED_OPTIMIZE
/****************************************************************************
Function Name        : GfxDriverRLEonline
Description          : Decodes the RLE sequence and fills the 
                         repeat flag  - p_rle_online->flag
                         repeat count - p_rle_online->count
                         repeat data  - p_rle_online->data
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverRLEonline(GFX_ONLINE_RLE * p_rle_online)
{
    p_rle_online->count = *p_rle_online->bmp_data;

    if((p_rle_online->count & 0x80) == 0)
    {
        p_rle_online->flag = FALSE;
    }
    else
    {
        p_rle_online->count &= 0x7F;
        p_rle_online->flag   = TRUE;
        p_rle_online->bmp_data++;
        p_rle_online->data  = (*p_rle_online->bmp_data);
    }
    p_rle_online->bmp_data++;
}
/****************************************************************************
Function Name        : GfxDriverRLEonlineNLine
Description          : Skips the current RLE decode sequence by number of 
                       pixels passed in p_width
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverRLEonlineNLine(GFX_ONLINE_RLE * p_rle_online, UINT16 p_width)
{
   while(p_width > 0)
   {
      if(p_rle_online->count == 0)
      {
         GfxDriverRLEonline(p_rle_online);
      }
      if(p_rle_online->count >= p_width)
      {
         if(p_rle_online->flag == FALSE)
         {
            p_rle_online->bmp_data = &p_rle_online->bmp_data[p_width];
         }
         p_rle_online->count -= p_width;
         p_width = 0;
      }
      else
      {
         p_width -= p_rle_online->count;
         if(p_rle_online->flag == FALSE)
         {
            p_rle_online->bmp_data = &p_rle_online->bmp_data[p_rle_online->count];
         }
         p_rle_online->count = 0;
      }
   }
}

#endif
#endif
#ifdef  __cplusplus
}
#endif
#endif /* #if defined(GFX_MGR02_MONOTFT) */

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
 **
 ** CMS Rev 1.0      09-Aug-2012    YSREEMAN
 ** Creation.
 **==========================================================================*/


/* end of file =============================================================*/
