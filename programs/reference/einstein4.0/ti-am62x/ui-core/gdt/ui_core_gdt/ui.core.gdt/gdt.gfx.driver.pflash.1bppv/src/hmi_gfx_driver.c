/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               * 
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************

File Name        :  hmi_gfx_driver.c
Module Short Name:  Driver
VOBName          :  sw_hmi_ss
Author           :  tvijayas             
Description      :  Graphics Driver

Organization     :  Driver Information Software Section,
                    Visteon Corporation
List the compiler name with the version number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :  
Target Processor :  
******************************************************************************/
#define HMI_GFX_DRIVER_C

#include "hmi_gfx_driver.h"

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
  #include "hmi_gfx_mgr_font.rom"
  #if defined (GFX_MGR01_DEFAULT_FONT) && (GFX_MGR01_NUM_OF_FONT_GROUPS > 0)
    #ifndef GFX_DEFAULT_CHAR_TABLE_PRESENT
      #error "Default char should be selected when GFX_MGR01_NUM_OF_FONT_GROUPS > 0 and GFX_MGR01_DEFAULT_FONT is defined"
    #endif
  #endif
#endif

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
//#undef GFX_COMPILE_SPEED_OPTIMIZE
#define GFX_DRIVER_LAYER0_BUFFER1_INDEX (0)
#define GFX_DRIVER_LAYER0_BUFFER2_INDEX (1)
#define GFX_WHITE_COLOUR                 (0xFFU)
#if GFX_PIX_FORMAT == GFX_4BPP
  #define LCD_SIZE_MUL_FACTOR 2
  #define PMSK(val)  ((val) & 0x0F)
  #define BMASKL     (0xF0)
  #define BMASKR     (0x0F)
#elif GFX_PIX_FORMAT == GFX_2BPP
  #define LCD_SIZE_MUL_FACTOR 1
  #define PMSK(val)  ((val) & 0x03)
#else
  #define LCD_SIZE_MUL_FACTOR 0
  #define PMSK(val)  ((val) & 0x01)
#endif


#if GFX_ROTATED_IMAGES != 0
  #define LCD_XSIZE                     (GFX_MAX_W_LENGTH<<LCD_SIZE_MUL_FACTOR)
  #define LCD_YSIZE                     (GFX_MAX_H_LENGTH)
#else
  #define LCD_XSIZE                     (GFX_MAX_W_LENGTH)
  #define LCD_YSIZE                     (GFX_MAX_H_LENGTH<<LCD_SIZE_MUL_FACTOR)
#endif

#define LCD_BYTES_PER_COLOUMN           ((LCD_YSIZE+7) / 8)
#define LCD_BYTES_PER_ROW               ((LCD_XSIZE+7) / 8)

/*
** Status encodings for l_fb_status_U8A
*/
#define FB_STATUS_FREE    (0)
#define FB_STATUS_READY   (1)
#define FB_STATUS_LOCKED  (2)

#if GFX_SCROLABLE_TEXT_SUPPORT == YES
  #if (GFX_DRIVER_NEED_BMP_CLIPPING == NO)
     #error "GFX_DRIVER_NEED_BMP_CLIPPING needs to be enabled if scrolling text support is required."
  #endif
#endif

#if defined(GFX_MGR_CLIP_TEXT_ENABLE)
  #if MAX_TEXT_LENGTH <= GFX_MGR_APPEND_CHAR_CNT
    #error "MAX_TEXT_LENGTH should be > GFX_MGR_APPEND_CHAR_CNT"
  #endif
#endif
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#if NB_LAYERS > 1
  #if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
     #define GFX_DRV_GET_WORKING_FB_PTR(layer)  (l_layer_fb_pointer_table_U8AP[layer][l_layer_working_fb_index_U8A[layer]])
  #else
     #define GFX_DRV_GET_WORKING_FB_PTR(layer)  (l_layer_fb_pointer_table_U8AP[layer][0])
  #endif
  #define GFX_DRV_SET_FB_STATUS(layer, status)  (l_fb_status_U8A[layer] = status)
  #define GFX_DRV_GET_FB_STATUS(layer)          (l_fb_status_U8A[layer])
#else
  #if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
     #define GFX_DRV_GET_WORKING_FB_PTR(layer)  (l_layer_fb_pointer_table_U8AP[0][l_layer_working_fb_index_U8A[0]])
  #else
     #define GFX_DRV_GET_WORKING_FB_PTR(layer)  (l_layer_fb_pointer_table_U8AP[0][0])
  #endif
  #define GFX_DRV_SET_FB_STATUS(layer, status)  (l_fb_status_U8A[0] = (status))
  #define GFX_DRV_GET_FB_STATUS(layer)          (l_fb_status_U8A[0])
#endif

/*
** SR - Shift Right
** SL - Shift Left
** FB - Points to next Frame buffer location
** GET_FBP - Returns the Frame buffer pointer to the passed xy location
** NEXT_FBP_LINE - Points to the next line of the frame buffer
*/
#if (GFX_BIT_ORDER_LSB_FIRST==1)
  #define SR(data, count)  ((data) >> (count))
  #define SL(data, count)  ((data) << (count))
#else
  #define SR(data, count)  ((data) << (count))
  #define SL(data, count)  ((data) >> (count))
#endif

/* SEGMENT CHANGES MERGE  */
#if (GFX_PIX_FORMAT == GFX_1BPP)||(GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
  #define GFX_GET_SET_COLOR_MASK(color_mask,color) (UINT8)(~(color_mask))
#elif (GFX_PIX_FORMAT == GFX_2BPP) || (GFX_PIX_FORMAT == GFX_4BPP)
  #define GFX_GET_SET_COLOR_MASK(color_mask,color) (UINT8)((UINT8)(~(color_mask))& (color))
#else
  #error "No Bits Per Pixel selected"
#endif





#if GFX_ROTATED_IMAGES != 0
    #if GFX_ROTATED_DISPLAY == 0 
      /* Horizontal Packing, Vertical filling */
      #define FB(ptr, index)     ((ptr)[(index)*LCD_BYTES_PER_ROW])
      #define GET_FBP(ptr, x, y) (&ptr[((y) >> 3) + (LCD_BYTES_PER_ROW * (x))])
      #define NEXT_FBP_LINE(ptr) (&ptr[1])
      #define SOFFS(y)           (y & 0x07)
      #define NLINES(h)          (h >> 3)
    #else
      /* Horizontal Packing, Horizontal filling */
      #define FB(ptr, index)     ((ptr)[index])
      #define GET_FBP(ptr, x, y) (&(ptr)[((((y) >> 3) * LCD_YSIZE) + (x))])
      #define NEXT_FBP_LINE(ptr) (&((ptr)[(LCD_YSIZE)]))
      #define SOFFS(y)           ((y) & 0x07)
      #define NLINES(h)          ((h) >> 3)
    #endif

#else 
    #if GFX_ROTATED_DISPLAY == 0 
      /* Vertical Packing, Horizontal filling */
      #define FB(ptr, index)     ((ptr)[(index)])
      #define GET_FBP(ptr, x, y) (&(ptr)[((((y) >> 3) * LCD_XSIZE) + (x))])
      #define NEXT_FBP_LINE(ptr) (&(ptr)[LCD_XSIZE])
      #define SOFFS(y)           ((y) & 0x07)
      #define NLINES(h)          ((h) >> 3)
    #else
      /* Vertical Packing, Vertical filling */
      #define FB(ptr, index)     ((ptr)[(index) * LCD_BYTES_PER_COLOUMN])
      #define GET_FBP(ptr, x, y) (&((ptr)[((y)>>3) + (LCD_BYTES_PER_COLOUMN * (x))]))
      #define NEXT_FBP_LINE(ptr) (&((ptr)[1]))
      #define SOFFS(y)           ((y) & 0x07)
      #define NLINES(h)          ((h) >> 3)
    #endif
#endif

/* SEGMENT CHANGES MERGE  */
#ifndef GFX_SEG_VERTICAL_PACKING
#define GET_FBP_SEG(ptr, x, y) (&(ptr)[((LCD_XSIZE * (y))/8) + ((x)>>3)])
#else	
#define GET_FBP_SEG(ptr, x, y) (&((ptr)[((y)>>3) + (LCD_BYTES_PER_COLOUMN * (x))]))
#endif
#if (GFX_DRIVER_WAIT_SCHEDULING==YES)
   #define GFX_DRIVER_SCHED_WAIT()  GfxDriverShedWait()
#else
   #define GFX_DRIVER_SCHED_WAIT()
#endif


#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
#define GET_FBP_MULTI_SEG(ptr, x, y) (&(ptr)[((LCD_YSIZE >> 1) * (x)) + ((y)>>1)])
#endif 
/*
** Text Clip Info.
*/
#define GFX_DRIVER_TEXT_CLIP            (0x01U)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#if GFX_COMPRESSED_IMAGES > 0
typedef struct
{
   UINT8 const * bmp_data;
   UINT8   flag;
   UINT8   data;
   UINT16   count;
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
#if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
static UINT8 l_layer_working_fb_index_U8A[NB_LAYERS];
#endif

#if NB_LAYERS > 1
extern UINT8 gl_active_layer_id_U8;
#else
   #define fl_lid_U8 (0)
#endif

#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
static void GfxDriverGetSegmentCharBitmak(const GFX_SEG_FONT   * const p_font_info_P,UINT8 p_unicode, GFX_CHAR_BIT_MASK_VAL *p_bitmak_data);
#endif


static UINT8 l_fb_status_U8A[NB_LAYERS];

#if defined(GFX_CLIPPED_WIDGETS_ENABLED) || (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
static RECTANGLE_DEF_T  l_clip_area_S[1];
#endif

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
static GFX_SIZE_X_T l_element_offset_x_S32;
static GFX_SIZE_Y_T l_element_offset_y_S32;
#endif

static GFX_SIZE_X_T l_widget_offset_x_S32;
static GFX_SIZE_Y_T l_widget_offset_y_S32;
static UINT8        l_widget_alpha_U8;

#if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
  /* Stores the selection index of the font groups.  By default selection index will be 0 */
  /* When font index is selected dynamically by the application then value is stored here */
  static UINT8 l_gfx_mgr01_font_grp_prop_S[GFX_MGR01_NUM_OF_FONT_GROUPS];
  #ifdef GFX_MGR01_DEFAULT_FONT
    static GFX_FONT const * GfxDriverGetGrpDefaultFontPtr(GFX_ELEMENT_ID_T p_font_id);
    static UINT8 GfxDriverGetGrpSelFontId(GFX_ELEMENT_ID_T p_font_id);
  #endif
#endif

#if (GFX_DRIVER_WAIT_SCHEDULING==YES)
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
   UINT16 fl_cwidth_U16 = 0;                                      \
   UINT16 fl_cheight_U16 = 0;                                     \
   if(x < l_clip_area_S[0].x)                                     \
   {                                                              \
      fl_cwidth_U16 = (l_clip_area_S[0].x-x);                     \
      fl_copy_sindex_U16 += fl_cwidth_U16;                        \
      x  = l_clip_area_S[0].x;                                    \
      if(fl_copy_width_U16 > fl_cwidth_U16)                       \
      {                                                           \
         fl_copy_width_U16 -= fl_cwidth_U16;                      \
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
         fl_copy_width_U16 = width - fl_copy_sindex_U16;          \
         x = 0;                                                   \
      }                                                           \
   }                                                              \
   fl_cwidth_U16 = (l_clip_area_S[0].x+l_clip_area_S[0].w);       \
   if((x+fl_copy_width_U16) > fl_cwidth_U16)                      \
   {                                                              \
      fl_copy_width_U16 = (fl_cwidth_U16 - x);                    \
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
         fl_copy_height_U16 = height - fl_copy_y_U16;             \
         y = 0;                                                   \
      }                                                           \
   }                                                              \
   fl_cheight_U16 = (l_clip_area_S[0].y+l_clip_area_S[0].h);      \
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
            bmp_data = &bmp_data[width];				                              \
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
#if GFX_COMPRESSED_IMAGES > 0
#if !defined GFX_COMPILE_SPEED_OPTIMIZE
static void GfxDriverRLEonline(GFX_ONLINE_RLE * p_rle_online);
static void GfxDriverRLEonlineNLine(GFX_ONLINE_RLE * p_rle_online, UINT16 p_width);
#endif
void GfxDriverCopyRLEImage(SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   UINT8 alpha
                           #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                         #endif                         
                          );


#endif

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
static GFX_FONT const * GfxDriverGetFontTable(GFX_ELEMENT_ID_T p_font_id);
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImage( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
	UINT8 alpha
    #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    #endif                         
    );
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageTrans( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif                         
    );
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageInv( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif
    );
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageTransInv( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif
    );
#if ((NB_DYN_TEXTS > 0) || (NB_STATIC_TEXTS > 0)) && (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static GFX_FONT_CHAR_CONFIG const * GfxDriverGetCharConfigPtr(GFX_CHAR fl_char, GFX_FONT const * p_font_tbl_P);
#endif
#if (GFX_PIX_FORMAT == GFX_4BPP)
UINT8 bmp_alpha_merge[256] = 
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

const UINT8 alpha_blend[256] = 
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

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/****************************************************************************
Function Name        : GfxDriverInitialize
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverInitialize(void)
{
#if NB_LAYERS > 1
    UINT8 fl_lid_U8;
    //l_active_layer_U8 = NB_LAYERS;
    for(fl_lid_U8 = 0; fl_lid_U8 < NB_LAYERS; fl_lid_U8++)
#endif
    {
        GFX_DRV_SET_FB_STATUS(fl_lid_U8, FB_STATUS_FREE);
    #if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
        l_layer_working_fb_index_U8A[fl_lid_U8] = 0;
    #endif
	    
    }
#if (GFX_DRIVER_WAIT_SCHEDULING==YES)
    curr_sched_counter_U16=0;
#endif
#if defined(GFX_CLIPPED_WIDGETS_ENABLED) || (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
    l_clip_area_S[0].x = 0;
    l_clip_area_S[0].x = 0;
    l_clip_area_S[0].w = GFX_MAX_W_LENGTH;
    l_clip_area_S[0].h = GFX_MAX_H_LENGTH;
#endif

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
    l_element_offset_x_S32 = 0;
    l_element_offset_y_S32 = 0;
#endif

   l_widget_offset_x_S32 = 0;
    l_widget_offset_y_S32 = 0;
    l_widget_alpha_U8 = GFX_PIX_FORMAT_ALPHA;
    
#if (EXTERNAL_FONT_FLASH_ENABLED == YES)
	/* Initialisation operations if EXTERNAL_FONT_FLASH_ENABLED is set */
	EXTERNAL_FONT_FLASH_INIT();
#endif
}

#if (GFX_DRIVER_WAIT_SCHEDULING==YES)
/****************************************************************************
Function Name        : GfxDriverShedWait
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static void GfxDriverShedWait(void)
{
    curr_sched_counter_U16++;
    if(curr_sched_counter_U16 >= GFX_DRIVER_WAIT_THRESHOLD_COUNT)
    {
        curr_sched_counter_U16 = 0;
        GFX_DRIVER_EXECUTE_EVENT_WAIT();
        /*Task Wait enabled*/
    }
}
#endif

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
		 *ptr_fl_copy_width_U16 = width - *ptr_fl_copy_sindex_U16;
		 *ptr_x = 0;
      }   
   }   
   fl_cwidth_U16 = (l_clip_area_S[0].x+l_clip_area_S[0].w);
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
		 *ptr_fl_copy_height_U16 = height - *ptr_fl_copy_y_U16;
		 *ptr_y = 0;
      }  
   }
   fl_cheight_U16 = (l_clip_area_S[0].y+l_clip_area_S[0].h);
   if((*ptr_y+*ptr_fl_copy_height_U16) > fl_cheight_U16)
   {
      *ptr_fl_copy_height_U16 = (fl_cheight_U16 - *ptr_y);
   }
}
#endif
#if GFX_COMPRESSED_IMAGES > 0
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
#undef GFX_TRANSPARENT
#undef GFX_TEXT_ON_GREY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#define GFX_RLE_SUPPORT
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif 
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) && (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif

/****************************************************************************
Function Name        : GfxDriverCopyRLEImage
Description          : Decodes the RLE compressed image online without 
                       requiring an intermediate buffer.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverCopyRLEImage(SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   UINT8 alpha
                           #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                         #endif                         
                          )
{
    #include "hmi_gfx_driver_cp_image.inc"
}
#if NB_COLORTRANSBITMAP > 0
#undef GFX_TEXT_ON_GREY
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#define GFX_RLE_SUPPORT
#define GFX_TRANSPARENT
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif 
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) && (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
/****************************************************************************
Function Name        : GfxDriverCopyRLETransImage
Description          : Decodes the RLE compressed image online without 
                       requiring an intermediate buffer.
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverCopyRLETransImage(SINT16 x,
                           SINT16 y,
                           const GFX_COLOR_T * bmp_data,
                           UINT16 height,
                           UINT16 width,
						   UINT8 alpha,
                           GFX_COLOR_T trans_color
                           #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
                           ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
                           ,UINT16 p_clip_length   /* how much to copy                                       */
                         #endif                         
                          )
{
	#include "hmi_gfx_driver_cp_image.inc"
}
 #endif //#if NB_COLORTRANSBITMAP > 0
#endif

/****************************************************************************
Function Name        : GfxDriverCopyImage
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
#undef  GFX_TEXT_ON_GREY
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) && (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
#define IMG_CP_OP(op,val) ((op)=(val))
#define IMG_PR_OP(op,val) ((op)=(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImage( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
	UINT8 alpha
    #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
    #endif                         
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}

#if NB_COLORTRANSBITMAP > 0
/****************************************************************************
Function Name        : GfxDriverMakeImageTransparent
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
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif 
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) && (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
#define IMG_PR_OP(op,val) ((op)=(val))
#define IMG_CP_OP(op,val) ((op)=(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverMakeImageTransparent( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha,
	GFX_COLOR_T trans_color
    #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
    ,UINT16 p_clip_start    /* Copy start location in the x direction ( 0 to width-1) */
    ,UINT16 p_clip_length   /* how much to copy                                       */
 #endif                         
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}
#endif
#if (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)  
/****************************************************************************
Function Name        : GfxDriverCopyImageTransparent
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
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) &&  (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
#define IMG_PR_OP(op,val) ((op)=(val))
#define IMG_CP_OP(op,val) ((op)|=(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageTrans( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif                         
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}
#endif

/****************************************************************************
Function Name        : GfxDriverCopyImageInverted
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
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) &&  (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
#undef  GFX_TRANSPARENT
#define IMG_PR_OP(op,val)  ((op) =~(val))
#define IMG_CP_OP(op,val)  ((op) =(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageInv( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}

#if (GFX_PIX_FORMAT == GFX_2BPP)||(GFX_PIX_FORMAT == GFX_4BPP)  
/****************************************************************************
Function Name        : GfxDriverBuildTextData
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
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#undef  GFX_IMAGE_BLEND_USING_ARRAY
#else
#undef GFX_ALPHA_BLEND
#endif 
#if GFX_TEXT_ON_GREY_SUPPORT == YES
#define GFX_TEXT_ON_GREY
#endif
#define IMG_PR_OP(op,val)  ((op)=(val))
#define IMG_CP_OP(op,val)  ((op)=(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static 
#endif
void GfxDriverBuildTextData( UINT8 drawcolour, 
	SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}
#endif

#if (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)  
/****************************************************************************
Function Name        : GfxDriverCopyImageTransInv
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
#if (GFX_PIX_FORMAT == GFX_4BPP)
#define GFX_ALPHA_BLEND
#else
#undef GFX_ALPHA_BLEND
#endif
#if defined(GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT) &&  (GFX_IMAGE_BLEND_USING_ARRAY_SUPPORT == YES)
#define  GFX_IMAGE_BLEND_USING_ARRAY
#endif
#define IMG_PR_OP(op,val)  ((op)=~(val))
#define IMG_CP_OP(op,val)  ((op)&=(val))
#if (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
static
#endif
void GfxDriverCopyImageTransInv( SINT16 x,
    SINT16 y,
    const GFX_COLOR_T * bmp_data,
    UINT16 height,
    UINT16 width,
    UINT8 alpha
 #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   ,UINT16 p_clip_start  /* Copy start location in the x direction ( 0 to width-1) */
   ,UINT16 p_clip_length /* how much to copy                                       */
 #endif
    )
{
    #include "hmi_gfx_driver_cp_image.inc"
}
#endif

#if NB_BITMAPS > 0
/****************************************************************************
Function Name        : GfxDriverBuildBitmapImage
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildBitmapImage(COORDINATE_DEF_T const * p_coord_def_SP, BITMAP_DEF_T const * pc_bitmap_def_SP)
{
    SINT16 x,y;
  
    x = p_coord_def_SP->x;
    y = p_coord_def_SP->y;

#if GFX_COMPRESSED_IMAGES > 0
    if(pc_bitmap_def_SP->info != GFX_IMAGE_COMPRESSION_NONE)
    {
        GfxDriverCopyRLEImage(
            x, 
            y, 
            pc_bitmap_def_SP->bmp_data, 
            pc_bitmap_def_SP->h, 
            pc_bitmap_def_SP->w,
            p_coord_def_SP->alpha
        #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
            ,0
            ,pc_bitmap_def_SP->w
        #endif
            );
    }
    else
#endif
    {
        GfxDriverCopyImage(
            x, 
            y, 
            pc_bitmap_def_SP->bmp_data, 
            pc_bitmap_def_SP->h, 
            pc_bitmap_def_SP->w,
            p_coord_def_SP->alpha
        #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
            ,0
            ,pc_bitmap_def_SP->w
        #endif
            );
    }
}
#endif /*#if NB_BITMAPS > 0*/ 

#if NB_COLORTRANSBITMAP > 0
/****************************************************************************
Function Name        : GfxDriverBuildColorTransBitMapImage
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildColorTransBitMapImage(COORDINATE_DEF_T const * p_coord_def_SP, COLORTRANSMAP_DEF_T const * pc_bitmap_def_SP)
{
	SINT16 x,y;
  
    x = p_coord_def_SP->x;
    y = p_coord_def_SP->y;

#if GFX_COMPRESSED_IMAGES > 0
    if(pc_bitmap_def_SP->info != GFX_IMAGE_COMPRESSION_NONE)
    {
        GfxDriverCopyRLETransImage(
            x, 
            y, 
            pc_bitmap_def_SP->bmp_data, 
            pc_bitmap_def_SP->h, 
            pc_bitmap_def_SP->w,
            p_coord_def_SP->alpha,
            pc_bitmap_def_SP->color
        #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
            ,0
            ,pc_bitmap_def_SP->w
        #endif
            );
    }
    else
#endif
    {
        GfxDriverMakeImageTransparent(
            x, 
            y, 
            pc_bitmap_def_SP->bmp_data, 
            pc_bitmap_def_SP->h, 
            pc_bitmap_def_SP->w,
            p_coord_def_SP->alpha,
            pc_bitmap_def_SP->color
        #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
            ,0
            ,pc_bitmap_def_SP->w
        #endif
            );
    }
}
#endif  /*#if NB_COLORTRANSBITMAP > 0*/

#if (NB_FILL_SCREENS > 0) || (NB_DYN_FILL_SCREENS > 0) || (NB_STATIC_TEXTS > 0) || (NB_DYN_TEXTS > 0)
/****************************************************************************
Function Name        : GfxDriverBuildFillScreen
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildFillScreen(COORDINATE_DEF_T const * pc_coord_SP, FILL_SCREEN_DEF_T const * pc_fill_screen_def_SP)
{
   SINT32 tot_width;
   SINT32 tot_height;
#if defined GFX_LAYER_XY_OFFSET_ENABLED && (GFX_LAYER_XY_OFFSET_ENABLED == YES)
   SINT16  x = pc_coord_SP->x + GFX_LAYER_X_OFFSET;
   SINT16  y = pc_coord_SP->y + GFX_LAYER_Y_OFFSET;
#else
   SINT16  x = pc_coord_SP->x;
   SINT16  y = pc_coord_SP->y;
#endif

   UINT8   alpha          = pc_coord_SP->alpha;
   UINT16 scr_height      = pc_fill_screen_def_SP->height;
   UINT16 scr_width       = pc_fill_screen_def_SP->width;
   UINT8  inversion       = pc_fill_screen_def_SP->color;

   #if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   UINT16 fl_copy_sindex_U16 = 0;
   UINT16 fl_copy_width_U16  = scr_width;
   UINT16 fl_copy_y_U16      = 0;
   UINT16 fl_copy_height_U16 = scr_height; 
   x += l_element_offset_x_S32;
   y += l_element_offset_y_S32;
   #endif
   
     x += l_widget_offset_x_S32;
     y += l_widget_offset_y_S32;
     alpha = (alpha * l_widget_alpha_U8) /GFX_PIX_FORMAT_ALPHA;

    inversion = (inversion * alpha)/GFX_PIX_FORMAT_ALPHA;

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
   #ifdef GFX_COMPILE_SPEED_OPTIMIZE   
   GfxDriverClipCalculate(x,y,fl_copy_sindex_U16,fl_copy_y_U16,fl_copy_width_U16,fl_copy_height_U16, scr_width, scr_height);   
   #else
   GfxDriverClipCalculate(&x,&y,&fl_copy_sindex_U16,&fl_copy_y_U16,&fl_copy_width_U16,&fl_copy_height_U16, scr_width, scr_height); 
   #endif
#endif

#if GFX_DRIVER_NEED_BMP_CLIPPING == YES
   scr_width =  fl_copy_width_U16;
   scr_height = fl_copy_height_U16;
#endif
   
   tot_height = (SINT32)(y+scr_height);
   tot_width  = (SINT32)(x+scr_width);

   if(tot_height >= GFX_MAX_H_LENGTH)
   {
      scr_height = scr_height - (tot_height - GFX_MAX_H_LENGTH);
      tot_height = GFX_MAX_H_LENGTH;
   }

   if(tot_width >= GFX_MAX_W_LENGTH)
   {
      scr_width = scr_width - (tot_width - GFX_MAX_W_LENGTH); 
      tot_width = GFX_MAX_W_LENGTH;
   }

if ((scr_height != 0U) &&
     (scr_width  != 0U) &&
     ((x + scr_width) <= GFX_MAX_W_LENGTH) &&
     ((y + scr_height) <= GFX_MAX_H_LENGTH) &&
     (tot_height > 0) &&
     (tot_width  > 0))
   {
      GFX_COLOR_T * fl_fb_U8AP;
      GFX_COLOR_T * fl_temp_fb_U8AP;
      UINT16        fl_cwidth_U8;
      UINT8         fl_start_offset_U8;
      UINT8         fl_end_offset_U8;
      UINT8         fl_smask_U8;
      UINT8         fl_cmask_U8;
      UINT16        fl_nb_lines_U16;
      UINT8         fl_start_height_U8;
      UINT16        fl_count_U16;

   #if NB_DYN_FILL_SCREENS > 0
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
   #if GFX_ROTATED_IMAGES > 0
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
      fl_temp_fb_U8AP    = GFX_DRV_GET_WORKING_FB_PTR(gl_active_layer_id_U8);
      fl_fb_U8AP         = GET_FBP(fl_temp_fb_U8AP, x, y);

      if((fl_start_offset_U8+scr_height) >= 8U)
      {
         if(fl_start_offset_U8 == 0U)
         {
            /*
            ** aligned to byte boundary.
            */
            fl_nb_lines_U16 = NLINES(scr_height);
            while(fl_nb_lines_U16 != 0U)
            {
               fl_cwidth_U8 = scr_width;
               for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
               {
                  FB(fl_fb_U8AP, fl_count_U16) = inversion;
                  GFX_DRIVER_SCHED_WAIT();
               }
               fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP);
               fl_nb_lines_U16--;
            }
            fl_end_offset_U8 = SOFFS(scr_height);
            if(fl_end_offset_U8 != 0U)
            {
               /*
               ** Copy the unaligned end pixels. if any
               */
               fl_cmask_U8  = (UINT8)SL((UINT8)0xFF , fl_end_offset_U8);
               fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
               fl_cwidth_U8 = scr_width;
               if(inversion == 0U)
               {
                  for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                  {
                     FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
                     GFX_DRIVER_SCHED_WAIT();
                  }
               }
               else if(inversion == GFX_WHITE_COLOUR)
               {
                  for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                  {
                     FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
                     GFX_DRIVER_SCHED_WAIT();
                  }
               }
               else
               {
                 for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                 {
                   FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
                   FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
                   GFX_DRIVER_SCHED_WAIT();
                 }
               }
            }
         }
         else
         {
            fl_start_height_U8 = 8U-fl_start_offset_U8;
            fl_cmask_U8        = (UINT8)SR((UINT8)0xFF ,fl_start_height_U8);
            fl_smask_U8        = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
            fl_cwidth_U8       = scr_width;

            if(inversion == 0)
            {
               for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
               {
                  FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
                  GFX_DRIVER_SCHED_WAIT();
               }
            }
           else if(inversion == GFX_WHITE_COLOUR)
           {
              for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
              {
                 FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
                 GFX_DRIVER_SCHED_WAIT();
              }
           }
           else
           {
             for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
             {
               FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
               FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
               GFX_DRIVER_SCHED_WAIT();
             }
           }

            fl_fb_U8AP        = NEXT_FBP_LINE(fl_fb_U8AP);
            fl_nb_lines_U16   = scr_height-(UINT16)fl_start_height_U8;
            fl_end_offset_U8  = (UINT8)(fl_nb_lines_U16 & 0x07U);
            fl_nb_lines_U16 >>= 3;

            while(fl_nb_lines_U16 != 0U)
            {
               fl_cwidth_U8 = scr_width;
               for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
               {
                  FB(fl_fb_U8AP, fl_count_U16) = inversion;
               }
               fl_fb_U8AP = NEXT_FBP_LINE(fl_fb_U8AP);
               fl_nb_lines_U16--;
               GFX_DRIVER_SCHED_WAIT();
            }
            
            if(fl_end_offset_U8 != 0U)
            {
               fl_cwidth_U8 = scr_width;
               fl_cmask_U8  = (UINT8)SL((UINT8)0xFF , fl_end_offset_U8);
               fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
               if(inversion == 0U)
               {
                  for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                  {
                     FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
                     GFX_DRIVER_SCHED_WAIT();
                  }
               }
               else if(inversion == GFX_WHITE_COLOUR)
               {
                 for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                 {
                   FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
                   GFX_DRIVER_SCHED_WAIT();
                 }
               }
               else
               {
                 for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
                 {
                   FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
                   FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
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
         fl_cmask_U8  = (UINT8)SL((UINT8)0xFF , (fl_start_offset_U8+scr_height));
         fl_smask_U8  = (UINT8)SR((UINT8)0xFF , (8U-fl_start_offset_U8));
         fl_cmask_U8 += fl_smask_U8;
         fl_smask_U8  = GFX_GET_SET_COLOR_MASK(fl_cmask_U8,inversion);
         fl_cwidth_U8 = scr_width;
         if(inversion == 0)
         {
            for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
            {
               FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
               GFX_DRIVER_SCHED_WAIT();
            }
         }
         else if(inversion == GFX_WHITE_COLOUR)
         {
           for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
           {
             FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
             GFX_DRIVER_SCHED_WAIT();
           }
         }
         else
         {
           for(fl_count_U16 = 0;fl_count_U16<fl_cwidth_U8;fl_count_U16++)
           {
             FB(fl_fb_U8AP, fl_count_U16) &= fl_cmask_U8;
             FB(fl_fb_U8AP, fl_count_U16) |= fl_smask_U8;
             GFX_DRIVER_SCHED_WAIT();
           }
         }
      }
   }
}
#endif /*#if NB_FILL_SCREENS > 0*/

#if ((NB_DYN_TEXTS > 0) || (NB_STATIC_TEXTS > 0)) && (GFX_DRIVER_CUSTOM_TEXT_RENDERING == NO)
/****************************************************************************
Function Name        : GfxDriverGetCharConfigPtr
Description          : Returns the character configuration for the passed char by searching.
Invocation           : By GfxDriverGetCharConfigInfo
Parameters           : character, font table, font id
Return Value         : GFX_FONT_CHAR_CONFIG const *
Critical Section     : 
External Interfaces  : 
******************************************************************************/
static GFX_FONT_CHAR_CONFIG const * GfxDriverGetCharConfigPtr(GFX_CHAR fl_char, 
                                                               GFX_FONT const * p_font_tbl_P)
{
    GFX_FONT_LUT         const * fl_font_lut_SP  = (GFX_FONT_LUT const*)p_font_tbl_P->f.lut_ptr;
    GFX_FONT_CHAR_CONFIG const * fl_font_base_SP = (GFX_FONT_CHAR_CONFIG const * )NULL;

#if (EXTERNAL_FONT_FLASH_ENABLED == YES)
  /* Get the data if external font flash is enabled */
  fl_font_base_SP = GFX_GET_FONT_DATA(fl_char);
  /* If the received data is valid proceed with the data */
  if(fl_font_base_SP != ((void *)0))
  {
  /* Do nothing */
  }
  /* If the received data is not valid */
  else
#endif
#if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID) || (GFX_CHAR_SEARCH_MODE == GFX_LUP_LINEAR)
 #if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID)
    if(p_font_tbl_P->size_table <= 8 )
 #endif
        {
        GFX_CHAR                     fl_base_char_code;
        GFX_CHAR                     fl_linear_temp_cnt;
        fl_linear_temp_cnt           = 0;
        while( fl_linear_temp_cnt<p_font_tbl_P->size_table)
        {
            fl_linear_temp_cnt++;
            if(fl_char == fl_font_lut_SP->ch_code)
            {
                fl_font_base_SP = fl_font_lut_SP->fcc_ptr;
                break;
            }
            else if(fl_char > fl_font_lut_SP->ch_code)
            {
                if((fl_font_lut_SP->attributes & GFX_FONT_SEARCH_MODE_TLUP) == GFX_FONT_SEARCH_MODE_TLUP)
                {
                    fl_font_base_SP    = fl_font_lut_SP->fcc_ptr;
                    fl_base_char_code = fl_font_lut_SP->ch_code;
                    fl_font_lut_SP++;
                    if(fl_char <= fl_font_lut_SP->ch_code)
                    {
                        if(fl_char == fl_font_lut_SP->ch_code)/*Sudheer changes for :*/
                        {
                            fl_font_base_SP = fl_font_lut_SP->fcc_ptr;
                        }
                        else if(fl_char != fl_font_lut_SP->ch_code)
                        {
                            fl_font_base_SP = &fl_font_base_SP[fl_char - fl_base_char_code];
                        }
                        else
                        {
                           /* Do Nothing */  
                        }
                        break;
                    }
                    /* When the passed char is not less than the searched char code in TLUP, then  fl_font_base_SP pointer
                       is loaded with the first char code of the lookup table. If the passed char code is less than 
                       the next searched char code , then algorithm breaks but the fl_font_base_SP pointer holds the value.
                       Hence it should be cleared. */  
                    else
                    {
                        fl_font_base_SP = 0; 
                    }
                    fl_linear_temp_cnt++;
                }
                else
                {
                    fl_font_base_SP = 0;          /* Added for RTC Defect: 140950 */
                }
            }
            else
            {
                break;
            }
            fl_font_lut_SP++;
        }
    }
#endif
#if GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID
    else
#endif
#if (GFX_CHAR_SEARCH_MODE == GFX_LUP_HYBRID) || (GFX_CHAR_SEARCH_MODE == GFX_LUP_BINARY)
        {
        UINT16 fl_high_U16 = p_font_tbl_P->size_table - 1;
        UINT16 fl_low_U16  = 0;
        UINT16 fl_mid_U16;

        while(fl_high_U16 > fl_low_U16)
        {
            fl_mid_U16 = (UINT16)((fl_high_U16 - fl_low_U16))>>1;
            if(fl_mid_U16 != 0)
            {
                if(fl_font_lut_SP[fl_low_U16 + fl_mid_U16].ch_code <= fl_char)
                {
                    fl_low_U16 = fl_low_U16 + fl_mid_U16;
                }
                else
                {
                    fl_high_U16 = fl_high_U16 - fl_mid_U16;
                }
            }
            else
            {
                if((fl_font_lut_SP[fl_low_U16].attributes & GFX_FONT_SEARCH_MODE_TLUP) == GFX_FONT_SEARCH_MODE_TLUP)
                {
                    if(fl_char >= fl_font_lut_SP[fl_low_U16].ch_code)
                    {
                        if((fl_high_U16 == fl_low_U16)||
                            (fl_char < fl_font_lut_SP[fl_high_U16].ch_code))
                        {
                            fl_font_base_SP    = fl_font_lut_SP[fl_low_U16].fcc_ptr;
                            fl_font_base_SP    = &fl_font_base_SP[fl_char - fl_font_lut_SP[fl_low_U16].ch_code];
                        }
                        else if(fl_char < fl_font_lut_SP[fl_high_U16 + 1].ch_code)
                        {
                            fl_font_base_SP    = fl_font_lut_SP[fl_high_U16].fcc_ptr;
                            fl_font_base_SP    = &fl_font_base_SP[fl_char - fl_font_lut_SP[fl_high_U16].ch_code];
                        }
                        else
                        {

                        }
                    }
                }
                else
                {
                    if(fl_char == fl_font_lut_SP[fl_low_U16].ch_code)
                    {
                        fl_font_base_SP = fl_font_lut_SP[fl_low_U16].fcc_ptr;
                        fl_font_base_SP = &fl_font_base_SP[0];
                    }
                    else if(fl_char == fl_font_lut_SP[fl_high_U16].ch_code)
                    {
                        fl_font_base_SP = fl_font_lut_SP[fl_high_U16].fcc_ptr;
                        fl_font_base_SP = &fl_font_base_SP[0];
                    }
                    else
                    {

                    }
                }
                break;
            }
        }
    }
#endif
    return(fl_font_base_SP);
}
/****************************************************************************
Function Name        : GfxDriverGetCharConfigInfo
Description          : Returns the character configuration for the passed char.
                      When the passed character is not found in the font table,
                      if the passsed Id is a group font id then searches for the
                      character in the default index of the group font id.  Still 
                      if the passed character is not found then returns the default
                      char configuration.
Invocation           : By Driver
Parameters           : character, font table, font id
Return Value         : GFX_FONT_CHAR_CONFIG const *
Critical Section     : 
External Interfaces  : 
******************************************************************************/
GFX_FONT_CHAR_CONFIG const * GfxDriverGetCharConfigInfo(GFX_CHAR p_char, 
                                                               GFX_FONT const * fl_font_tbl_P
                                                               #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT
                                                               ,UINT8 fl_font_id_u8
                                                               #endif
                                                               )
{
    GFX_FONT_CHAR_CONFIG const * fl_font_base_P = (GFX_FONT_CHAR_CONFIG const * )NULL;

    fl_font_base_P = GfxDriverGetCharConfigPtr(p_char,fl_font_tbl_P);

    #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT
    if(fl_font_base_P == NULL)
    {
      #if defined(GFX_MGR01_DEFAULT_FONT) && (GFX_MGR01_NUM_OF_FONT_GROUPS > 0)
      GFX_FONT             const * fl_font_SP;
      fl_font_SP = GfxDriverGetGrpDefaultFontPtr(fl_font_id_u8);
      if(fl_font_SP != NULL)
      {
      fl_font_base_P = GfxDriverGetCharConfigPtr(p_char,fl_font_SP);
      if(fl_font_base_P == NULL)
      {
        UINT8 fl_grp_font_id;
        fl_grp_font_id = GfxDriverGetGrpSelFontId(fl_font_id_u8);
        fl_font_base_P = lc_default_char_config_SPA[fl_grp_font_id];
      }
      }
      else
      #endif
      {
      fl_font_base_P = lc_default_char_config_SPA[fl_font_id_u8];
      }
    }
    #endif
    return(fl_font_base_P);
}
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
/****************************************************************************
Function Name        : GfxDriverSegmentUpdateColor
Description          : This function sets the appropriate nibbles with 
                       text color value passed 
Invocation           : When ever needed.
Return Value         : None.
Critical Section     : None.
External Interfaces  : None.
******************************************************************************/
UINT8 GfxDriverSegmentUpdateColor(UINT8 p_current_byte, GFX_SEG_COLOR p_color, UINT8 p_val)
{
  UINT8 fl_new_byte;
  UINT8 fl_pixel_select = p_val % 2u;

  if (fl_pixel_select == 0u)
  {
    fl_new_byte = (p_current_byte & 0xF0) | (p_color & 0x0F);
  }
  else
  {
    fl_new_byte = (p_current_byte & 0x0F) | (UINT8)((p_color & 0x0F) << 4u);
  }

  return fl_new_byte;
}
#endif
#if (GFX_PIX_FORMAT == GFX_1BPP_SEG) || (GFX_PIX_FORMAT == GFX_SEG)
/****************************************************************************
Function Name        : GfxDriverSegmentBuildIcon
Description          : 
Invocation           : 
Parameters           : 
Return Value         :                    
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverSegmentBuildIcon(UINT16 com, 
                               UINT16 seg, 
#if defined(GFX_MGR01_MULTI_COLOR_SUPPORT)
                               GFX_SEG_COLOR status
#else
                               BOOLEAN status
#endif
)
{
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
  UINT8 fl_current_byte = 0u;
  UINT8 fl_new_byte = 0u;
#else
    GFX_FB_COLOR_T fl_bit_mask;
#endif
  GFX_FB_COLOR_T *fl_fb_AP;
  GFX_COLOR_T *fl_temp_fb_U8AP;

  if ((com < GFX_MAX_W_LENGTH) && (seg < GFX_MAX_H_LENGTH))
  {
    fl_temp_fb_U8AP = GFX_DRV_GET_WORKING_FB_PTR(gl_active_layer_id_U8);
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
    fl_fb_AP = GET_FBP_MULTI_SEG(fl_temp_fb_U8AP, com, seg);
    fl_current_byte = *fl_fb_AP;
    fl_new_byte = GfxDriverSegmentUpdateColor(fl_current_byte, status, seg);
    *fl_fb_AP = fl_new_byte;
#else
    fl_fb_AP = GET_FBP(fl_temp_fb_U8AP, com, seg);
#if ((GFX_ROTATED_IMAGES != 0) || (GFX_ROTATED_DISPLAY != 0))
    fl_bit_mask = SL(1, (com & 0x07U));
#else
    fl_bit_mask = SL(1, (seg & 0x07U));
#endif
#if GFX_PIX_FORMAT == GFX_SEG
    fl_fb_AP = (GFX_FB_COLOR_T *)GET_FBP_SEG(fl_temp_fb_U8AP, com, seg);
#ifdef GFX_SEG_VERTICAL_PACKING
    fl_bit_mask = SL(1, (seg & 0x07));
#else	
#ifdef GFX_BIG_ENDIAN
    fl_bit_mask = (1 << (com));
#else
    fl_bit_mask = (1 << ((GFX_MAX_BACK_PLANES - 1U) - com));
#endif
#if GFX_MAX_BACK_PLANES > 4
    if ((seg % 2U) != 0U)
#else
    if ((seg % 2U) == 0U)
#endif
    {
      fl_bit_mask = fl_bit_mask << GFX_MAX_BACK_PLANES;
    }
#endif
#endif
    if (status != 0U)
    {
      *fl_fb_AP |= fl_bit_mask;
    }
    else
    {
      *fl_fb_AP &= ~fl_bit_mask;
    }
#endif
  }
}
/****************************************************************************
Function Name        : GfxDriverSegmentBuildText
Description          : 
Invocation           : 
Parameters           : 
Return Value         :                    
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverSegmentBuildText(DYN_TEXT_DEF_T const * pc_dyn_text_def_SP)
{
  const GFX_FONT       * const fl_font_tbl_P   = &lc_gfx_seg_font_table[pc_dyn_text_def_SP->font_id];
  const GFX_SEG_FONT   * const fl_font_info_P = (GFX_SEG_FONT *)fl_font_tbl_P->f.ptr; 
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
  GFX_SEG_COLOR fl_color_value = *(pc_dyn_text_def_SP->seg_color);  
#endif
  
  /*Segmented Display*/
  if(fl_font_tbl_P->size_table == 0U)
  {
    GFX_FB_COLOR_T *  fl_fb_AP;
    GFX_COLOR_T *  fl_temp_fb_U8AP;
    UINT8          fl_no_of_char_U8;
    UINT8          fl_seg_U8;
    const UINT16 * pos = fl_font_info_P->char_pos_U8P;

    fl_temp_fb_U8AP    = GFX_DRV_GET_WORKING_FB_PTR(gl_active_layer_id_U8);

    for(fl_no_of_char_U8 = 0; fl_no_of_char_U8<fl_font_info_P->no_of_char_U8 ;fl_no_of_char_U8++)
    {
      UINT8  char_indx;
      HMI_SEG fl_char_mask_data;
      GFX_CHAR_BIT_MASK_VAL  fl_char_mask = {0
#if GFX_MGR01_MAX_SEGMENTS > 32
        ,0
#endif
      };

      char_indx       = pc_dyn_text_def_SP->data_ptr[fl_no_of_char_U8];
      GfxDriverGetSegmentCharBitmak(fl_font_info_P,char_indx, &fl_char_mask);
      fl_char_mask_data = fl_char_mask.lower_32_seg_val;

      for(fl_seg_U8 = 0;fl_seg_U8 < fl_font_info_P->seg_per_char_U8 ;fl_seg_U8++)
      {
        UINT16 com;
        UINT16 seg;		
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
        UINT8 fl_current_byte = 0u;
        UINT8 fl_new_byte = 0u;
#else
        HMI_SEG fl_seg_mask_data;
#endif
        com      = *pos++;
        seg      = *pos++;
#if GFX_MGR01_MAX_SEGMENTS > 32
        if(fl_seg_U8 == 32)
        {
          fl_char_mask_data = fl_char_mask.higher_32_seg_val;
        }
#endif
        if((com < GFX_MAX_W_LENGTH) && (seg <= GFX_MAX_H_LENGTH))
        {
			
#ifdef GFX_MGR01_MULTI_COLOR_SUPPORT
          fl_fb_AP = GET_FBP_MULTI_SEG(fl_temp_fb_U8AP, com, seg);
          fl_current_byte = *fl_fb_AP;

          if (fl_char_mask_data & ((HMI_SEG)1u << fl_seg_U8))
          {
             fl_new_byte = GfxDriverSegmentUpdateColor(fl_current_byte, fl_color_value, seg);	  
            *fl_fb_AP = fl_new_byte;
          }
		  else
          {
             fl_new_byte = GfxDriverSegmentUpdateColor(fl_current_byte, GFX_SEG_DEFAULT, seg);  
           *fl_fb_AP = fl_new_byte;
          }

#else
          GFX_FB_COLOR_T fl_bit_mask;

#if GFX_PIX_FORMAT != GFX_SEG
          fl_fb_AP = GET_FBP(fl_temp_fb_U8AP, com, seg);

#if ((GFX_ROTATED_IMAGES != 0) || (GFX_ROTATED_DISPLAY != 0))
          fl_bit_mask = SL(1,(com & 0x07));
#else
          fl_bit_mask = SL(1,(seg & 0x07));
#endif
#endif
#if GFX_PIX_FORMAT == GFX_SEG
        fl_fb_AP = (GFX_FB_COLOR_T *)GET_FBP_SEG(fl_temp_fb_U8AP, com, seg);
#ifdef GFX_SEG_VERTICAL_PACKING
        fl_bit_mask = SL(1, (seg & 0x07));
#else
	    #ifdef GFX_BIG_ENDIAN
          fl_bit_mask = (1<<(com));
	    #else
	      fl_bit_mask = 1<<((GFX_MAX_BACK_PLANES-1U)-com);
	    #endif
        #if GFX_MAX_BACK_PLANES > 4
          if((seg%2U) != 0U)
        #else
          if((seg%2U) == 0U)
        #endif
          {
            fl_bit_mask = fl_bit_mask<<GFX_MAX_BACK_PLANES;
          } 
#endif
#endif

  #if GFX_MGR01_MAX_SEGMENTS > 32
          if(fl_seg_U8 >= 32)
          {
            /* Since the compiler doesn't have the support of 64-bit variable
            ** we have to reset it to "0" so that we can do bit mask for 
            ** higher 32-segments
            */
            fl_seg_mask_data = (fl_seg_U8 - 32);
            fl_seg_mask_data =  (HMI_SEG)(((HMI_SEG)1)<<((HMI_SEG)fl_seg_mask_data));
          }
          else
  #endif
          {
            fl_seg_mask_data =  (HMI_SEG)(((HMI_SEG)1)<<((HMI_SEG)fl_seg_U8));
          }
          if((fl_char_mask_data & fl_seg_mask_data) != 0U)
          {
            *fl_fb_AP |=  fl_bit_mask;
          }
          else
          {
            *fl_fb_AP &= ~fl_bit_mask;
          } 
#endif		  
        }
      }
    } 
  } 
}
/****************************************************************************
Function Name        : GfxDriverGetSegmentCharBitmak
Description          : Will gives the passed unincode corresponding bitmask value
Invocation           : Internally
Parameters           : 
Return Value         : Update GFX_CHAR_BIT_MASK_VAL *p_bitmak_data parameter
Critical Section     : None
External Interfaces  : 
******************************************************************************/
static void GfxDriverGetSegmentCharBitmak(const GFX_SEG_FONT   * const p_font_info_P,UINT8 p_unicode, GFX_CHAR_BIT_MASK_VAL *p_bitmak_data)
{
  if(p_font_info_P->actual_char_entries > 0U)
  {
    UINT8              fl_table_size = p_font_info_P->actual_char_entries;
    GFX_CHAR_BIT_MASK  const   *fl_char_bitmask_ptr = p_font_info_P->char_bit_mask_ptr;
    UINT8 fl_first = 0; 
    UINT8 fl_last  = fl_table_size-1U;
    UINT8 fl_middle= (fl_first+fl_last)/2U;

    while ((fl_first <= fl_last) && (fl_middle < fl_table_size))
    {
      if (fl_char_bitmask_ptr[fl_middle].ch_unicode < p_unicode)
      {
        fl_first = fl_middle + 1U;
      }
      else if (fl_char_bitmask_ptr[fl_middle].ch_unicode == p_unicode) 
      {
        GFX_CHAR_BIT_MASK_VAL *fl_char_bitmask_data = (GFX_CHAR_BIT_MASK_VAL *)fl_char_bitmask_ptr[fl_middle].ch_bit_mask_data;
        p_bitmak_data->lower_32_seg_val = fl_char_bitmask_data->lower_32_seg_val;
#if GFX_MGR01_MAX_SEGMENTS > 32
        p_bitmak_data->higher_32_seg_val = fl_char_bitmask_data->higher_32_seg_val;
#endif
        break;
      }
      else
      {
        fl_last = fl_middle - 1U;
      }
      fl_middle = (fl_first + fl_last)/2U;
    }
  }
  /*if (fl_first > fl_last)
  printf("Not found! %d Unicode is not present in the Table.\n", p_unicode);*/
}
#endif
/****************************************************************************
Function Name        : GfxDriverBuildText
Description          : 
Invocation           : 
Parameters           : 
Return Value         :                    
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverBuildText(GFX_TEXT_PROPERTY const * pc_text_prop_SP, DYN_TEXT_DEF_T const * pc_dyn_text_def_SP)
{

    GFX_SIZE_X_T           fl_start_x            = pc_text_prop_SP->coord.x;
    const GFX_SIZE_Y_T     fl_start_y            = pc_text_prop_SP->coord.y;
    GFX_CHAR             * fl_disp_string_temp_P = pc_dyn_text_def_SP->data_ptr;
    GFX_CHAR             * fl_disp_string_P      = pc_dyn_text_def_SP->data_ptr;
    const GFX_FONT       * const fl_font_tbl_P   = GfxDriverGetFontTable(pc_dyn_text_def_SP->font_id);
    GFX_FONT_CHAR_CONFIG const * fl_font_P       = ( GFX_FONT_CHAR_CONFIG const * )NULL;
    GFX_SIZE_X_T           fl_x_size_temp        = pc_dyn_text_def_SP->width;
    GFX_SIZE_X_T           fl_x_size             = 0;
    GFX_SIZE_Y_T           fl_cur_y;
#if (GFX_SCROLABLE_TEXT_SUPPORT == YES) || (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
   GFX_SIZE_X_T           fl_cur_x;
#endif
   GFX_COLOR_T            fl_draw_color;
#if GFX_SCROLABLE_TEXT_SUPPORT == YES
   SINT16                 fl_scroll_offset_temp_S16;
#endif
   SINT16                 fl_scroll_offset_S16 = 0;
#if (EXTERNAL_FONT_FLASH_ENABLED == YES)
	GFX_CHAR p_char;
#endif
	GFX_TEXT_WIDTH_INFO_DEF_T fl_txt_info_S;

#if GFX_SCROLABLE_TEXT_SUPPORT == YES
    /*
    ** Retrive the scroll offset in pixels information from end of the
    ** text string buffer.
    */
    fl_txt_info_S.getTotalStringWidth = (UINT8)YES;
    fl_txt_info_S.input_str_ptr = pc_dyn_text_def_SP->data_ptr;
    fl_txt_info_S.tot_available_width = pc_dyn_text_def_SP->width;
    GfxDriverGetTextFitWidth(&fl_txt_info_S,pc_dyn_text_def_SP); 
    if(((pc_dyn_text_def_SP->properties & GFX_TEXT_PROPERTY_SCROLABLE) != 0) &&
        (fl_txt_info_S.disp_width > fl_txt_info_S.tot_available_width))
    {
   #if GFX_UNICODE_ENABLED
        fl_scroll_offset_S16 = fl_disp_string_temp_P[pc_dyn_text_def_SP->length+1];
   #else
        /* Combine MSB and LSB for non-unicode */
        fl_scroll_offset_S16 = (fl_disp_string_temp_P[pc_dyn_text_def_SP->length+1]<<8);
        fl_scroll_offset_S16+= fl_disp_string_temp_P[pc_dyn_text_def_SP->length+2];
   #endif
        if(fl_scroll_offset_S16 < 0)
        {
            fl_scroll_offset_S16 = -fl_scroll_offset_S16;
            if(fl_scroll_offset_S16 < fl_x_size_temp)
            {
                fl_x_size_temp -= fl_scroll_offset_S16;
                if(GFX_TEXT_PROPERTY_IS_ALIGN_RIGHT(pc_dyn_text_def_SP->properties))
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
#elif (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
    fl_scroll_offset_S16 = 0;
#endif
    if(fl_font_tbl_P != 0)
    {
      if((fl_x_size_temp > 0) && (*fl_disp_string_P != 0U))
      {
          /*
          ** Find the width of string that could be fitted in the configured 
          ** width for the dynamic text. For example if the configured width
          ** is 100pixels and the passed string requires, 120pixels then 
          ** remove char from left/right side of the string based on the alignment
          ** right/left respectively. 
          */
          if(GFX_TEXT_PROPERTY_IS_ALIGN_RIGHT(pc_dyn_text_def_SP->properties))
          {
            if(fl_scroll_offset_S16 != 0)
            {
             #if GFX_SCROLABLE_TEXT_SUPPORT == YES
               fl_scroll_offset_S16 = 0;
            #endif
              while(*fl_disp_string_P != 0U)
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
                  fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P,fl_font_tbl_P
                                                         #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                           , pc_dyn_text_def_SP->font_id
                                                         #endif
                                                         );
                  if(fl_font_P != NULL)
                  {
              #if GFX_SCROLABLE_TEXT_SUPPORT == YES   
                      if(fl_scroll_offset_temp_S16 >= fl_font_P->owidth)
                      {
                          fl_scroll_offset_temp_S16 -= fl_font_P->owidth;
                      }
                      else
              #endif
                      {
                 #if GFX_SCROLABLE_TEXT_SUPPORT == YES
                        if(fl_x_size == 0)
                        {
                            fl_x_size                 = (fl_font_P->owidth-fl_scroll_offset_temp_S16);
                            fl_scroll_offset_temp_S16 = 0;
                        }
                        else
               #endif
                        {
                          fl_x_size += fl_font_P->owidth;
                        }
                        if (fl_x_size == fl_x_size_temp)
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
                  #if (GFX_SCROLABLE_TEXT_SUPPORT == YES) || (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
                            if(GFX_TEXT_PROPERTY_IS_CLIP_NORMAL(pc_dyn_text_def_SP->properties))
                            {
                                fl_scroll_offset_S16 = (fl_x_size-fl_x_size_temp);
                                fl_x_size            = fl_x_size_temp;
                            }
                            else
                  #endif
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
		      fl_txt_info_S.getTotalStringWidth = (UINT8)NO;
			  fl_txt_info_S.input_str_ptr = pc_dyn_text_def_SP->data_ptr;
			  GfxDriverGetTextFitWidth(&fl_txt_info_S,pc_dyn_text_def_SP); 
			  fl_x_size = fl_txt_info_S.disp_width;
			  fl_disp_string_P = fl_txt_info_S.disp_str_ptr;
		   }
           if(fl_x_size > 0)
           {
             fl_x_size_temp = fl_x_size;
             fl_x_size_temp--;
             if(fl_start_x > fl_x_size_temp)
             {
               fl_start_x -= fl_x_size_temp;
             }
             else
             {
               fl_start_x  = 0;
             }
          }
        }
        else
        {
            /* Centre or Left aligned */
		  if(fl_scroll_offset_S16 != 0)
		  {
            while(*fl_disp_string_temp_P != 0U)
            {
                fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_temp_P,fl_font_tbl_P
                                                       #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                         , pc_dyn_text_def_SP->font_id
                                                       #endif
                                                       );
                if(fl_font_P != NULL)
                {
            #if GFX_SCROLABLE_TEXT_SUPPORT == YES   
                    if(fl_scroll_offset_temp_S16 >= fl_font_P->owidth)
                    {
                        fl_scroll_offset_temp_S16 -= fl_font_P->owidth;
                    }
                    else
            #endif
                        {
               #if GFX_SCROLABLE_TEXT_SUPPORT == YES   
                        if(fl_x_size == 0)
                        {
                            fl_disp_string_P          = fl_disp_string_temp_P;
                            fl_x_size                 = (fl_font_P->owidth-fl_scroll_offset_temp_S16);
                            fl_scroll_offset_S16      = fl_scroll_offset_temp_S16;
                            fl_scroll_offset_temp_S16 = 0;
                        }
                        else
               #endif
                        {
                            fl_x_size += fl_font_P->owidth;
                        }
                        if(fl_x_size == fl_x_size_temp)
                        {
                            break;
                        }
                        else if(fl_x_size > fl_x_size_temp)
                        {
                  #if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)   
                            if(GFX_TEXT_PROPERTY_IS_CLIP_NORMAL(pc_dyn_text_def_SP->properties))
                            {
                                /* In normal clipping mode we can display partial chars. */
                                fl_x_size  = fl_x_size_temp;
                            }
                            else
                  #endif
                            {
                                /* cannot accomodate the last char in given width, so remove it fully. */
                                fl_x_size -= fl_font_P->owidth;
                            }
                            break;
                        }
                        else
                        {
                          /*do nothing*/
                        }
                    }
                }
                fl_disp_string_temp_P++;
              }
          }
          else
          {
          fl_txt_info_S.getTotalStringWidth = (UINT8)NO;
          fl_txt_info_S.input_str_ptr = pc_dyn_text_def_SP->data_ptr;
          GfxDriverGetTextFitWidth(&fl_txt_info_S,pc_dyn_text_def_SP);
          fl_x_size = fl_txt_info_S.disp_width;
          fl_disp_string_P = fl_txt_info_S.disp_str_ptr;
          }
           if(GFX_TEXT_PROPERTY_IS_ALIGN_CENTRE(pc_dyn_text_def_SP->properties))
           {
              fl_x_size_temp = fl_x_size>>1;
              if(fl_start_x > fl_x_size_temp)
              {
                fl_start_x -= fl_x_size_temp;
              }
              else
              {
                fl_start_x  = 0;
              }
            }
        }

        fl_draw_color = pc_text_prop_SP->draw_color;
        if(GFX_TEXT_PROPERTY_IS_DRAW_TRANSP(pc_dyn_text_def_SP->properties) == 0)
        {
           FILL_SCREEN_DEF_T fl_fill_screen_def_S;
           COORDINATE_DEF_T  fl_coord_def_S;
           fl_coord_def_S.x            = fl_start_x;
           fl_coord_def_S.y            = fl_start_y;
           fl_fill_screen_def_S.height = fl_font_tbl_P->p.height;
           fl_fill_screen_def_S.width  = fl_x_size;
           if(fl_draw_color != 0U)
           {
             fl_draw_color = 0xFFU;
           }
           if(GFX_TEXT_PROPERTY_IS_DRAW_REVERSE(pc_dyn_text_def_SP->properties))
           {
              fl_fill_screen_def_S.color  = fl_draw_color;
              fl_draw_color = (GFX_COLOR_T)(~fl_draw_color);
           }
           else
           {
              fl_fill_screen_def_S.color = (GFX_COLOR_T)(~fl_draw_color);
           }
           GfxDriverBuildFillScreen(&fl_coord_def_S, &fl_fill_screen_def_S);
        }

        #ifdef GFX_DRIVER_NEED_HORIZONTAL_SCAN
        if((GFX_HOR_SCAN_BUILD_TEXT(pc_text_prop_SP,pc_dyn_text_def_SP)) == YES)
        {
        #endif

        while((*fl_disp_string_P != 0U) && (fl_x_size > 0))
        {
        #if (EXTERNAL_FONT_FLASH_ENABLED == YES)
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
                fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P,fl_font_tbl_P
                                                       #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                         , pc_dyn_text_def_SP->font_id
                                                       #endif
                                                       );
            }
            if(fl_font_P != NULL)
            {
                fl_cur_y        = fl_start_y + fl_font_P->y_soffset;
         #if (GFX_SCROLABLE_TEXT_SUPPORT == YES) || (GFX_DRIVER_NEED_BMP_CLIPPING == YES)   
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
                }
                fl_cur_x      = fl_start_x;
                fl_start_x   += fl_x_size_temp;
                if(fl_x_size_temp == fl_font_P->owidth)
                {
                    /* No clipping necessary */
                    fl_cur_x       += fl_font_P->x_soffset;
                    fl_x_size_temp  = fl_font_P->width;
                }
                else
                {
                    /* Clipping is required, so recalculate the copy width and start offset */
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

                if(GFX_TEXT_PROPERTY_IS_DRAW_TRANSP(pc_dyn_text_def_SP->properties))
                {
#if (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)                   
                   if(fl_draw_color != 0)
                   {
                      GfxDriverCopyImageTrans( 
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                   else
                   {
                      GfxDriverCopyImageTransInv( 
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
#else
                      GfxDriverBuildTextData(
                        fl_draw_color,
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
#endif  /* (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP) */
                }
                else
                {
                   if(fl_draw_color != 0)
                   {
                      GfxDriverCopyImage( 
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                   else
                   {
                      GfxDriverCopyImageInv( 
                        fl_cur_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha,
                        fl_scroll_offset_S16,
                        fl_x_size_temp);
                   }
                }
                fl_scroll_offset_S16 = 0;
         #else
                fl_start_x += fl_font_P->x_soffset;

                if(GFX_TEXT_PROPERTY_IS_DRAW_TRANSP(pc_dyn_text_def_SP->properties))
                {
#if (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)
                   if(fl_draw_color != 0U)
                   {
                      GfxDriverCopyImageTrans( 
                            fl_start_x,
                            fl_cur_y,
                            fl_font_P->fdata,
                            fl_font_P->height,
                            fl_font_P->width,
                            pc_text_prop_SP->coord.alpha
                            );
                   }
                   else
                   {
                      GfxDriverCopyImageTransInv( 
                            fl_start_x,
                            fl_cur_y,
                            fl_font_P->fdata,
                            fl_font_P->height,
                            fl_font_P->width,
                            pc_text_prop_SP->coord.alpha
                            );
                   }
#else
                   GfxDriverBuildTextData(
                        fl_draw_color,
                        fl_start_x,
                        fl_cur_y,
                        fl_font_P->fdata,
                        fl_font_P->height,
                        fl_font_P->width,
                        pc_text_prop_SP->coord.alpha);
#endif  /* (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP) */

                }
                else
                {
                   if(fl_draw_color != 0U)
                   {
                      GfxDriverCopyImage( 
                            fl_start_x,
                            fl_cur_y,
                            fl_font_P->fdata,
                            fl_font_P->height,
                            fl_font_P->width,
                        pc_text_prop_SP->coord.alpha
                            );
                   }
                   else
                   {
                      GfxDriverCopyImageInv( 
                            fl_start_x,
                            fl_cur_y,
                            fl_font_P->fdata,
                            fl_font_P->height,
                            fl_font_P->width,
                            pc_text_prop_SP->coord.alpha
                            );
                   }
                }
                fl_start_x += fl_font_P->x_eoffset;
                if(fl_x_size >= fl_font_P->owidth)
                {
                    fl_x_size -= fl_font_P->owidth;
                }
                else
                {
                    fl_x_size  = 0;
                }
         #endif
            }
            fl_disp_string_P++;
        }
        #ifdef GFX_DRIVER_NEED_HORIZONTAL_SCAN
        }
        #endif
      }
    }
}


/****************************************************************************
Function Name        : GfxDriverGetTextFitWidth
Description          : Returns the width of the text that can be fitted in
                       the text box.  If the text cant be fit then clip flag 
                       will be set and actual length that can be fitted will 
                       be returned. If the getTotalStringWidth flag is set
                       then the total width of the passed text is calculated
                       without considering the actual width of the text box.
Invocation           : By application when required.
Parameters           : *pc_text_info_SP, *pc_dyn_text_def_SP.
Return Value         : void. (Fills the pc_text_info_SP with calculated values)                  
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverGetTextFitWidth(GFX_TEXT_WIDTH_INFO_DEF_T *pc_text_info_SP, 
                              DYN_TEXT_DEF_T const * pc_dyn_text_def_SP)
{
   GFX_CHAR              *fl_disp_string_temp_P = pc_text_info_SP->input_str_ptr;
   GFX_CHAR              *fl_disp_string_P      = pc_text_info_SP->input_str_ptr;
   GFX_CHAR              *fl_str_ptr;
   const GFX_FONT        *const fl_font_tbl_P   = GfxDriverGetFontTable(pc_dyn_text_def_SP->font_id);
   GFX_FONT_CHAR_CONFIG   const *fl_font_P;
   GFX_SIZE_X_T           fl_x_size_temp        = pc_dyn_text_def_SP->width;
   GFX_SIZE_X_T           fl_x_size             = 0;
   GFX_SIZE_X_T           fl_disp_str_len       = 0;
   GFX_SIZE_X_T           fl_dest_length;
   UINT8                  fl_clip_flag_U8       = 0;
   UINT16                 fl_avail_width;
   #if defined(GFX_MGR_CLIP_TEXT_APPEND_ENABLE)
   UINT16                 fl_append_str_width   = 0;
   #endif
   #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
   GFX_CLIP_INFO          fl_clip_info;
   #endif

   if(fl_font_tbl_P != 0)    
   {
     while(*fl_disp_string_temp_P != 0U)
     {
       fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_temp_P,fl_font_tbl_P
                                                         #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                           , pc_dyn_text_def_SP->font_id
                                                         #endif
                                                         );
       if(fl_font_P != 0)
       {
         fl_x_size += fl_font_P->owidth;
       }
       fl_disp_str_len++;
       fl_disp_string_temp_P++;
     }
     pc_text_info_SP->disp_width = fl_x_size;
     pc_text_info_SP->disp_len = fl_disp_str_len;
   
     if((fl_x_size > pc_dyn_text_def_SP->width) && (pc_text_info_SP->getTotalStringWidth != YES))
     {
         fl_clip_flag_U8 = GFX_DRIVER_TEXT_CLIP;
         fl_avail_width = pc_dyn_text_def_SP->width;
       #if defined(GFX_MGR_CLIP_TEXT_APPEND_ENABLE)
         fl_font_P = GfxDriverGetCharConfigInfo(GFX_MGR_APPEND_CHAR,fl_font_tbl_P
                                               #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                 , pc_dyn_text_def_SP->font_id
                                               #endif
                                                );
         if(fl_font_P != 0)
         {
           fl_append_str_width = (GFX_MGR_APPEND_CHAR_CNT * fl_font_P->owidth);
           if((fl_append_str_width > 0) && (fl_append_str_width < pc_dyn_text_def_SP->width))
           {
             fl_avail_width  -= fl_append_str_width;
           }
         }
      #endif
     }
     /* getTotalStringWidth flag is NO */
     if(pc_text_info_SP->getTotalStringWidth != YES)
     {
       if((fl_x_size_temp > 0) && (*fl_disp_string_P != 0U))
       {
          fl_str_ptr = pc_text_info_SP->disp_str_ptr;
          /*
          ** Find the width of string that could be fitted in the configured 
          ** width for the dynamic text. For example if the configured width
          ** is 100pixels and the passed string requires, 120pixels then 
          ** remove char from left/right side of the string based on the alignment
          ** right/left respectively. 
          */
          /* Assume input string is "ABCDEFGH" */
          #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
          /* Get the clipping side info from application. */
          fl_clip_info = GFX_MGR_GET_CLIP_INFO(pc_text_info_SP->input_str_ptr, fl_disp_str_len, fl_clip_flag_U8);
          if(fl_clip_info >= CLIP_MAX)
          {
            /* Assigning clip info based on the text box alignment if the returned value from application is invalid. */
            if(GFX_TEXT_PROPERTY_IS_ALIGN_RIGHT(pc_dyn_text_def_SP->properties))
            {
              fl_clip_info = LEFT_CLIP;
            }
            else
            {
              fl_clip_info = RIGHT_CLIP;
            }
          }
          if(fl_clip_info == LEFT_CLIP)
          #else  
          if(GFX_TEXT_PROPERTY_IS_ALIGN_RIGHT(pc_dyn_text_def_SP->properties))
          #endif
          {
            if(fl_clip_flag_U8 == GFX_DRIVER_TEXT_CLIP)
            {
               fl_disp_string_P = pc_text_info_SP->input_str_ptr;
               while(*fl_disp_string_P != 0U)
               {
                 fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P,fl_font_tbl_P
                                                         #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                           , pc_dyn_text_def_SP->font_id
                                                         #endif
                                                         );
                 fl_disp_string_P++;
                 if(fl_font_P != 0)
                 {
                   fl_x_size -= fl_font_P->owidth;
                   fl_disp_str_len--;
                   if(fl_x_size <= fl_avail_width)
                   {
                     #if defined(GFX_MGR_CLIP_TEXT_APPEND_ENABLE)
                     if(fl_append_str_width > 0)
                     {
                       if(fl_disp_str_len >= (MAX_TEXT_LENGTH-GFX_MGR_APPEND_CHAR_CNT-1))
                       {
                         /*
                         ** We are now OK to fit the width of the string but
                         ** if the p_string cannot accomodate the string characters yet
                         ** we have to remove more characters..
                         */
                         continue;
                       }
                       else
                       {
                         UINT8 fl_append_str_index_U8;
                         for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < GFX_MGR_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                         {
                           *fl_str_ptr++ = GFX_MGR_APPEND_CHAR;
                         }
                         while(*fl_disp_string_P != 0)
                         {
                           *fl_str_ptr++ = *fl_disp_string_P++;
                         }
                         *fl_str_ptr = '\0';        /* Null character is added at the end */
                         fl_x_size   += fl_append_str_width;
                         fl_disp_str_len += GFX_MGR_APPEND_CHAR_CNT;
                         /* Final output string may be "...BCDEFGH" or "...CDEFGH" */
                       }
                     }
                     else
                     {
                       if(fl_disp_str_len >= MAX_TEXT_LENGTH)
                       {
                         fl_disp_str_len = MAX_TEXT_LENGTH-1;
                       }
                       fl_dest_length = fl_disp_str_len;
                       while(fl_dest_length != 0)
                       {
                         *fl_str_ptr++ = *fl_disp_string_P++;
                         fl_dest_length--;
                       }
                       *fl_str_ptr = '\0';        /* Null character is added at the end */
                       /* Final output string will be "BCDEFGH" or "CDEFGH" */
                     }
                   #else
                     while(*fl_disp_string_P != 0U)
                     {
                       *fl_str_ptr++ = *fl_disp_string_P++;
                     }
                     *fl_str_ptr = '\0';        /* Null character is added at the end */
                     /* Final output string may be "BCDEFGH" or "CDEFGH" */
                   #endif
                     break;
                   }
                 }
               }
             }
             else
             {
               fl_disp_string_P = pc_text_info_SP->input_str_ptr;
               if(fl_disp_str_len >= MAX_TEXT_LENGTH)
               {
                 fl_disp_str_len = MAX_TEXT_LENGTH-1;
               }
               fl_dest_length = fl_disp_str_len;
               while(fl_dest_length != 0)
               {
                 *fl_str_ptr++ = *fl_disp_string_P++;
                  fl_dest_length--;
               }
               *fl_str_ptr = '\0';        /* Null character is added at the end */
               /* Final output string may be "ABCDEFGH" */
             }
          }
          else
          {
             /* Centre or Left aligned */
            if(fl_clip_flag_U8 == GFX_DRIVER_TEXT_CLIP)
            {
               fl_disp_string_P = fl_disp_string_temp_P-1;
               while(fl_disp_string_P > pc_text_info_SP->input_str_ptr)
               {
                 fl_font_P = GfxDriverGetCharConfigInfo(*fl_disp_string_P,fl_font_tbl_P
                                                         #ifdef GFX_DEFAULT_CHAR_TABLE_PRESENT								
                                                           , pc_dyn_text_def_SP->font_id
                                                         #endif
                                                         );
                 fl_disp_string_P--;
                 if(fl_font_P != 0)
                 {
                   fl_x_size -= fl_font_P->owidth;
                   fl_disp_str_len--;
                   if(fl_x_size <= fl_avail_width)
                   {
                     #if defined(GFX_MGR_CLIP_TEXT_APPEND_ENABLE)
                     if(fl_append_str_width > 0)
                     {
                       if(fl_disp_str_len >= (MAX_TEXT_LENGTH-GFX_MGR_APPEND_CHAR_CNT-1))
                       {
                         /*
                         ** We are now OK to fit the width of the string but
                         ** if the p_string cannot accomodate the string characters yet
                         ** we have to remove more characters..
                         */
                         continue;
                       }
                       else
                       {
                         UINT8 fl_append_str_index_U8;
                         fl_dest_length = fl_disp_str_len;
                         fl_disp_string_P = pc_text_info_SP->input_str_ptr;
                         while(fl_dest_length != 0)
                         {
                           *fl_str_ptr++ = *fl_disp_string_P++;
                            fl_dest_length--;
                         }
                         for(fl_append_str_index_U8 = 0; fl_append_str_index_U8 < GFX_MGR_APPEND_CHAR_CNT; fl_append_str_index_U8++)
                         {
                           *fl_str_ptr++ = (GFX_CHAR)GFX_MGR_APPEND_CHAR;
                         }
                         *fl_str_ptr = '\0';        /* Null character is added at the end */
                         fl_x_size   += fl_append_str_width;
                         fl_disp_str_len += GFX_MGR_APPEND_CHAR_CNT;
                         /* Final output string may be "ABCDEF..." or "ABCDEFG..." */
                       }
                     }
                     else
                     {
                       fl_disp_string_P = pc_text_info_SP->input_str_ptr;
                       if(fl_disp_str_len >= MAX_TEXT_LENGTH)
                       {
                         fl_disp_str_len = MAX_TEXT_LENGTH-1;
                       }
                       fl_dest_length = fl_disp_str_len;
                       while(fl_dest_length != 0)
                       {
                         *fl_str_ptr++ = *fl_disp_string_P++;
                         fl_dest_length--;
                       }
                       *fl_str_ptr = '\0';        /* Null character is added at the end */
                       /* Final output string may be "ABCDEFG" or "ABCDEF" */
                     }
                   #else
                     fl_disp_string_P = pc_text_info_SP->input_str_ptr;
                     if(fl_disp_str_len >= MAX_TEXT_LENGTH)
                     {
                       fl_disp_str_len = MAX_TEXT_LENGTH-1;
                     }
                     fl_dest_length = fl_disp_str_len;
                     while(fl_dest_length != 0)
                     {
                       *fl_str_ptr++ = *fl_disp_string_P++;
                       fl_dest_length--;
                     }
                    *fl_str_ptr = '\0';        /* Null character is added at the end */
                    /* Final output string may be "ABCDEFG" or "ABCDEF" */
                   #endif
                   break;
                   }
                  }
                 }
                }
             else
             {
               fl_disp_string_P = pc_text_info_SP->input_str_ptr;
               if(fl_disp_str_len >= MAX_TEXT_LENGTH)
               {
                 fl_disp_str_len = MAX_TEXT_LENGTH-1;
               }
               fl_dest_length = fl_disp_str_len;
               while(fl_dest_length != 0)
               {
                 *fl_str_ptr++ = *fl_disp_string_P++;
                  fl_dest_length--;
               }
               *fl_str_ptr = '\0';        /* Null character is added at the end */
               /* Final output string may be "ABCDEFGH" */
             }
          }
          pc_text_info_SP->disp_width = fl_x_size;
          pc_text_info_SP->disp_len = fl_disp_str_len;
          pc_text_info_SP->text_clip_flag = fl_clip_flag_U8;
        }
     }
   }
}
#endif /*#if NB_DYN_TEXTS > 0*/



/****************************************************************************
Function Name        : GfxDriverCheckBusyStatus(void){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
UINT8 GfxDriverCheckBusyStatus(UINT8 fl_lid_U8)
#else
UINT8 GfxDriverCheckBusyStatus(void)
#endif
{
    UINT8 fl_driver_busy_status_U8 = TRUE;
    /* 
    ** Wait until the current buffer is copied on to working buffer 
    */
 #if NB_LAYERS > 1
    if(fl_lid_U8 < NB_LAYERS)
 #endif
        {
        if(GFX_DRV_GET_FB_STATUS(fl_lid_U8) != FB_STATUS_LOCKED)
        {
            fl_driver_busy_status_U8 = FALSE;
        }
    }
    return(fl_driver_busy_status_U8);
}
/****************************************************************************
Function Name        : GfxDriverBeginUpdate(void){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
void GfxDriverBeginUpdate(UINT8 fl_lid_U8)
#else
void GfxDriverBeginUpdate(void)
#endif
{

}
/****************************************************************************
Function Name        : GfxDriverEndUpdate(void){}
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
#if NB_LAYERS > 1
void GfxDriverEndUpdate(UINT8 fl_lid_U8)
#else
void GfxDriverEndUpdate(void)
#endif
{
    UINT8 fl_status_U8;
 #if NB_LAYERS > 1
    UINT8 fl_layer_no_U8;
    for(fl_layer_no_U8=0; fl_layer_no_U8 <NB_LAYERS;fl_layer_no_U8++)
 #else
    if(fl_lid_U8 < NB_LAYERS)
 #endif
    {
        #if NB_LAYERS > 1
        if((fl_lid_U8 & (1<<fl_layer_no_U8)) != 0)
        #endif
        {         
           /*
           ** Lock the buffer and begin the transmission to LCD driver.
           */
		    #if NB_LAYERS > 1
           fl_status_U8 = GFX_DRIVER_START_LCD_UPDATE(fl_layer_no_U8, GFX_DRV_GET_WORKING_FB_PTR(fl_layer_no_U8));
		   #else
		   fl_status_U8 = GFX_DRIVER_START_LCD_UPDATE(0, GFX_DRV_GET_WORKING_FB_PTR(0));
		   #endif
           if( fl_status_U8 != FALSE)
           {
             #if defined DISABLE_BUFFER_LOCK && (DISABLE_BUFFER_LOCK==NO)
              GFX_DRV_SET_FB_STATUS(fl_layer_no_U8, FB_STATUS_LOCKED);//tvijayas
             #endif
           }
           #if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
           else
           {
              GFX_DRV_SET_FB_STATUS(fl_layer_no_U8, FB_STATUS_READY);
           }
           #endif
        }
    }
}

/****************************************************************************
Function Name        : GfxDriverLcdUpdateComplete(void){}

Description          : 

Invocation           : 

Parameters           : 

Return Value         : 

Critical Section     : 

External Interfaces  : 

******************************************************************************/
#if NB_LAYERS > 1
void GfxDriverLcdUpdateComplete(UINT8 fl_lid_U8)
#else
void GfxDriverLcdUpdateComplete(void)
#endif
{
 #if NB_LAYERS > 1
    if(fl_lid_U8 < NB_LAYERS)
 #endif
        {
   #if GFX_DRIVER_USE_DOUBLE_BUFFERING > 0
        if(GFX_DRV_GET_FB_STATUS(fl_lid_U8) == FB_STATUS_READY)
        {
            if(GFX_DRIVER_START_LCD_UPDATE(fl_lid_U8, GFX_DRV_GET_WORKING_FB_PTR(fl_lid_U8)) != FALSE)
            {
                GFX_DRV_SET_FB_STATUS(fl_lid_U8, FB_STATUS_LOCKED);
            }
        }
        else if(GFX_DRV_GET_FB_STATUS(fl_lid_U8) == FB_STATUS_LOCKED)
        {
            /*
            ** Swap the working buffer and then copy the active buffer content to 
            ** working buffer.
            */
            l_layer_working_fb_index_U8A[fl_lid_U8]++;
            l_layer_working_fb_index_U8A[fl_lid_U8] &= 0x01;
            GFX_DRV_SET_FB_STATUS(fl_lid_U8, FB_STATUS_FREE);
        }
        else
        {
        }
   #else
        GFX_DRV_SET_FB_STATUS(fl_lid_U8, FB_STATUS_FREE);
   #endif
    }
}
#ifdef GFX_CLIPPED_WIDGETS_ENABLED
/****************************************************************************
Function Name        : GfxDriverSetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverSetClipArea(RECTANGLE_DEF_T const * p_clip_area_SP)
{
    l_clip_area_S[0].x = p_clip_area_SP->x;
    l_clip_area_S[0].y = p_clip_area_SP->y;
    l_clip_area_S[0].w = p_clip_area_SP->w;
    l_clip_area_S[0].h = p_clip_area_SP->h;
}
/****************************************************************************
Function Name        : GfxDriverGetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverGetClipArea(RECTANGLE_DEF_T * p_clip_area_SP)
{
    p_clip_area_SP->x = l_clip_area_S[0].x;
    p_clip_area_SP->y = l_clip_area_S[0].y;
    p_clip_area_SP->w = l_clip_area_S[0].w;
    p_clip_area_SP->h = l_clip_area_S[0].h;
}
/****************************************************************************
Function Name        : GfxDriverReSetClipArea
Description          : 
Invocation           : 
Parameters           : 
Return Value         : 
Critical Section     : 
External Interfaces  : 
******************************************************************************/
void GfxDriverReSetClipArea(void)
{
    l_clip_area_S[0].x = 0;
    l_clip_area_S[0].x = 0;
    l_clip_area_S[0].w = LCD_XSIZE;
    l_clip_area_S[0].h = LCD_YSIZE;
}
#endif /*#ifdef GFX_CLIPPED_WIDGETS_ENABLED*/

#if (GFX_DRIVER_NEED_BMP_CLIPPING == YES)
/****************************************************************************
Function Name        : GfxDriverSetElementOffset
Description          : Sets the element offset to be applied while building the
                       elements of a screen.
Invocation           : By Graphics manager
Parameters           : x and y offset
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverSetWidgetOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y, UINT8 alpha)
{
    l_widget_offset_x_S32 = p_pos_x;
    l_widget_offset_y_S32 = p_pos_y;
    l_widget_alpha_U8 = alpha;
}
/****************************************************************************
Function Name        : GfxDriverAddWidgetOffset
Description          : Add the passed x,y,alpha to existing offsets.
Invocation           : By Graphics manager
Parameters           : x , y offset and alpha
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverAddWidgetOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y, UINT8 alpha)
{
    l_widget_offset_x_S32 = l_widget_offset_x_S32 + p_pos_x;
    l_widget_offset_y_S32 = l_widget_offset_y_S32 + p_pos_y;
    alpha = (alpha * l_widget_alpha_U8) / GFX_PIX_FORMAT_ALPHA;  
    l_widget_alpha_U8 = alpha;
}

void GfxDriverSetElementOffset(GFX_SIZE_X_T p_pos_x, GFX_SIZE_Y_T p_pos_y)
{
    l_element_offset_x_S32 = p_pos_x;
    l_element_offset_y_S32 = p_pos_y;
}

/****************************************************************************
Function Name        : GfxDriverGetElementOffset
Description          : Gets the element offset to be applied while building the
                       elements of a screen.
Invocation           : By Graphics manager
Parameters           : Pointer to x and y offset
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverGetWidgetOffset(GFX_SIZE_X_T * p_pos_x, GFX_SIZE_Y_T * p_pos_y, UINT8 * alpha)
{
    *p_pos_x = l_widget_offset_x_S32;
    *p_pos_y = l_widget_offset_y_S32;
    *alpha   = l_widget_alpha_U8;
}
void GfxDriverGetElementOffset(GFX_SIZE_X_T * p_pos_x, GFX_SIZE_Y_T * p_pos_y)
{
    *p_pos_x = l_element_offset_x_S32;
    *p_pos_y = l_element_offset_y_S32;
}

/****************************************************************************
Function Name        : GfxDriverAddElementOffset
Description          : Adds the element offset to be applied while building the
                       elements of a screen with the passed parameters.
Invocation           : By Graphics manager
Parameters           : Pointer to x and y offset
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void GfxDriverAddElementOffset(GFX_SIZE_X_T * p_pos_x, GFX_SIZE_Y_T * p_pos_y)
{
    *p_pos_x += l_element_offset_x_S32;
    *p_pos_y += l_element_offset_y_S32;
}
#endif /*(GFX_DRIVER_NEED_BMP_CLIPPING == YES)*/


/****************************************************************************
Function Name        : GfxDriverGetFontTable
Description          : Gets the font table of the selected index for the passed
                       group font ID or the font table of the passed font ID.
Invocation           : By Graphics manager/Driver
Parameters           : Font ID
Return Value         : Font table
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_FONT const * GfxDriverGetFontTable(GFX_ELEMENT_ID_T p_font_id)
{
    GFX_FONT                    const * fl_font = ((void *) 0);
    if(p_font_id < (GFX_ELEMENT_ID_T)GFX_MGR01_NUM_OF_FONTS)
    {
      fl_font = &lc_gfx_seg_font_table[p_font_id];
      #if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
      if(fl_font->is_group != 0)
      {
        UINT8 fl_gfont_id = fl_font->p.group_sel_index;
        if(fl_gfont_id < GFX_MGR01_NUM_OF_FONT_GROUPS)
        {
          UINT8 fl_font_index = l_gfx_mgr01_font_grp_prop_S[fl_gfont_id];
          fl_font = GfxDriverGetFontTable(fl_font->f.grp_ptr[fl_font_index]);
        }
      }
      #endif
    }
    return fl_font;
}

#if GFX_MGR01_NUM_OF_FONT_GROUPS > 0
/****************************************************************************
Function Name        : GfxDriverSetGroupFontIndex
Description          : Sets the selection index for the passed
                       group font ID.
Invocation           : By Graphics manager/Driver
Parameters           : Group Font ID, Selection index
Return Value         : TRUE if selection index is valid.  FALSE if invalid.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT8 GfxDriverSetGroupFontIndex(GFX_ELEMENT_ID_T p_font_id, GFX_ELEMENT_DATA_T p_selection_index)
{
    UINT8                 fl_ret_sts = FALSE;
    GFX_FONT                    const * fl_font;
    UINT8                       fl_gfont_id;
    UINT8                       fl_font_index;
    if(p_font_id < GFX_MGR01_NUM_OF_FONTS)
    {
      fl_font = &lc_gfx_seg_font_table[p_font_id];
      if(fl_font->is_group != 0)
      {
        fl_gfont_id = fl_font->p.group_sel_index;
        if(fl_gfont_id < GFX_MGR01_NUM_OF_FONT_GROUPS)
        {
          fl_font_index = l_gfx_mgr01_font_grp_prop_S[fl_gfont_id];
          if(fl_font_index != p_selection_index)
          {
						UINT8 fl_font_id = fl_font->f.grp_ptr[p_selection_index];
						if(fl_font_id < GFX_MGR01_NUM_OF_FONTS)
						{
							l_gfx_mgr01_font_grp_prop_S[fl_gfont_id] = p_selection_index;
              fl_ret_sts = TRUE;
						}
          }
        }
      }
    }
  return(fl_ret_sts);
}

/****************************************************************************
Function Name        : GfxDriverGetGrpSelFontId
Description          : Returns the font ID of selected index of the passed
                       group font ID.
Invocation           : By Driver
Parameters           : Group Font ID
Return Value         : Font ID.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT8 GfxDriverGetGrpSelFontId(GFX_ELEMENT_ID_T p_font_id)
{
    UINT8   fl_font_id = 0;
    GFX_FONT const * fl_font = ((void *) 0);
    UINT8   fl_gfont_id;

    if(p_font_id < GFX_MGR01_NUM_OF_FONTS)
    {
      fl_font = &lc_gfx_seg_font_table[p_font_id];
      if(fl_font->is_group != 0)
      {
        fl_gfont_id = fl_font->p.group_sel_index;
        if(fl_gfont_id < GFX_MGR01_NUM_OF_FONT_GROUPS)
        {
          UINT8 fl_font_index;
          fl_font_index = l_gfx_mgr01_font_grp_prop_S[fl_gfont_id];
          fl_font_id = fl_font->f.grp_ptr[fl_font_index];
        }
      }
    }
    return fl_font_id;
}
#endif

#if defined (GFX_MGR01_DEFAULT_FONT) && (GFX_MGR01_NUM_OF_FONT_GROUPS > 0)
/****************************************************************************
Function Name        : GfxDriverGetGrpDefaultFontPtr
Description          : Returns the font pointer of default font for the passed
                       group font ID.
Invocation           : By Driver
Parameters           : Group Font ID
Return Value         : Font pointer.
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_FONT const * GfxDriverGetGrpDefaultFontPtr(GFX_ELEMENT_ID_T p_font_id)
{
    GFX_FONT                    const * fl_font = ((void *) 0);
    if(p_font_id < GFX_MGR01_NUM_OF_FONTS)
    {
      fl_font = &lc_gfx_seg_font_table[p_font_id];
      if(fl_font->is_group != 0)
      {
          fl_font = GfxDriverGetFontTable(fl_font->f.grp_ptr[fl_font->default_index]);
      }
    }
    return fl_font;
}
#endif


/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------

Date              :  20-Sep-2024
By                :  aperumal
Traceability      :  HYUND32598-12826
Change Description:  Multicolor support for segmented displays 

Date              :  25-Sep-2018
By                :  arajase2
Traceability      :  1201732: Gfx Mgr01 - Segmented display related code to be protected
Change Description:  Protection added for the below structures to avoid the inclusion in non segmented code
                     void GfxDriverSegmentBuildIcon(UINT16 com,UINT16 seg,UINT8 status)
                     void GfxDriverSegmentBuildText(DYN_TEXT_DEF_T const * pc_dyn_text_def_SP)
                     static void GfxDriverGetSegmentCharBitmak(const GFX_SEG_FONT   * const p_font_info_P,
                      UINT8 p_unicode, GFX_CHAR_BIT_MASK_VAL *p_bitmak_data)
Date              :  29-Jan-2018
By                :  sbollam
Traceability      :  1039129
Change Description:  Extend no'of segments to 64/char and no'of back planes to 8.

Date              :  25-MAY-2017
By                :  adevi
Traceability      :  873769
Change Description:  Signed values of x and y are not rendered properly.

Date              :  25-MAY-2017
By                :  adevi
Traceability      :  873771
Change Description:  Fill screen rendering issue for negative values of x and y. 

Date              :  24-APR-2017
By                :  kkubendi
Traceability      :  848393
Change Description:  Graphics Manager 01: Issue fix and review comment update for XY and Alpha animation 

Date              :  14-APR-2017
By                :  kkubendi
Traceability      :  791443
Change Description:  GFX01/HyundaiQxC: Update Graphics Manager 01 to support XY,Alpha animation, 
					 Alpha and Image blending.

Date              :  09-AUG-2016
By                :  sbollam
Traceability      :  660802
Change Description:  Newton2.0 - 32bit segment support
Date              :  02-AUG-2016
By                :  adevi
Traceability      :  660538
Change Description:  S101 Issue - Wait event not getting scheduled properly

Date              :  19-MAY-2016
By                :  adevi
Traceability      :  598753
Change Description:  Disabling buffer lock configuration enabled and FB locked
                     based on configuration.

Date              :  09-MAY-2016
By                :  adevi
Traceability      :  589518
Change Description:  S101 compiler warning fixes.

Date              :  04-MAY-2016
By                :  adevi
Traceability      :  580752
Change Description:  Scroll offset applied only when given text does not fit.

Date              :  8-APR-2015
By                :  aperumal
Traceability      :  567771
Change Description:  Moved the inclusion of hmi_gfx_mgr_font to hmi_gfx_driver.h 
                     to fix the compiler error for Hyundai DE 

Date              :  16-MAR-2015
By                :  adevi
Traceability      :  491346
Change Description:  Horizontal scan support for Hyundai DE for open vg integration.

Date              :  04-FEB-2015
By                :  adevi
Traceability      :  516224
Change Description:  Issue fix in font search algorithm.

Date              :  19-JAN-2015
By                :  adevi
Traceability      :  491345
Change Description:  Font grouping and dynamic font id change.

Date              :  13-JAN-2015
By                :  sanand2
Traceability      :  491347
Change Description:  Append string feature update.

Date              :  28-DEC-2015
By                :  adevi
Traceability      :  489987
Change Description:  Dynamic screen position changes done.

Date              :16/10/2015
By                :sbollam
Traceability      :RTC 444367
Change Description:Appending string feature implementation

Date              :17/7/2015
By                :adevi
Traceability      :RTC 368488, 344552, 344565
Change Description:For horizontal packing, horizontal scroll, horizontal clipping
                   and vertical clipping implemented.  For vertical packing, both
                   types of clipping implemented. 

Date              :  25-Mar-2015
By                :  adevi
Traceability      :  RTC 314644
Change Description:  Added const before bmp_data in GFX_ONLINE_RLE.
                     Added arguments while calling GfxDriverCopyRLETransImage.
 
Date              :  27-Feb-2015
By                :  adevi
Traceability      :  RTC 
Change Description:  Grey text support implemented in hmi_gfx_driver_cp_image.inc.
                     File hmi_gfx_driver_build_text_data.inc removed.

Date              :  06-Feb-2015
By                :  arajase2
Traceability      :
Change Description:  QAC 8.1.2 Warnings resolved.

Date              :  12-Dec-2014
By                :  adevi
Traceability      :
Change Description:  Compiler warnings resolved by checking #if NB_COLORTRANSBITMAP > 0.
                     Datatype declaration corrected in GfxDriverBuildColorTransBitMapImage.

Date              :  30-Oct-2014
By                :  adevi
Traceability      :
Change Description:  1. GfxDriverCopyRLEImage arguments added for horizontal bmp
                        clipping support.
                     2. GfxDriverGetTextFitWidth function modified to caculate the
                        total width of the text element passed based on value of 
                        getTotalStringWidth flag set by the user.
                     3. hmi_gfx_driver_cp_image.inc modified to support bmp clipping
                        and clipping of rle images.
                     4. hmi_gfx_driver_build_text_data.inc modified to support bmp clipping.                        

Date              :  21-Oct-2014
By                :  sbollam
Traceability      :  RTC task id : 226310 
Change Description:  Added a new funtions to implement the RTC task id : 226310 
                     GfxDriverMakeImageTransparent and GfxDriverCopyRLETransImage
                     also fixed the compiler error related to dyanamic fillscreen ( by adevi)

Date              :  28-Aug-2014
By                :  adevi
Traceability      :
Change Description:  Check for (GFX_PIX_FORMAT != GFX_2BPP)&&(GFX_PIX_FORMAT != GFX_4BPP)
                     added to avoid compiler warning.

Date              :  27-Aug-2014
By                :  adevi
Traceability      :
Change Description:  GfxDriverBuildFillScreen function modified to support
                     2 BPP pixel format(Light and dark grey fill screen).

Date              :  12-Aug-2014
By                :  adevi
Traceability      :
Change Description:  1. Text support on gray background implemented for 2BPP.

Date              :  24-Jul-2014
By                :  adevi
Traceability      :
Change Description:  1. GFX_UNICODE_ENABLED macro usage for chinese font support
                      removed.  EXTERNAL_FONT_FLASH_ENABLED used for external font
                      support.  Support for rotated display enabled through macro 
                      GFX_ROTATED_DISPLAY.
                      2. QAC fixes.  Typecasting done.
                      3. In GfxDriverGetTextFitWidth() clip flag is set when input
                      exceeds MAX_TEXT_LENGTH or when actual width allowed is reached.

Date              :  10-Jul-2014
By                :  adevi
Traceability      :
Change Description:  Segment display related implementation merged.

Date              :  19-Jun-2014
By                :  kcsarava
Traceability      :  Updated for RTC Defect: 140950
Change Description:  Invalid range of characters are not displyed as expected and 
                     it displays as Blank

Date              :  16-Jun-2014
By                :  kcsarava
Traceability      :  Updated for Task: 165420
Change Description:  SPI implementation is moved out of GfxDriverGetCharConfigInfo
                     as per the comments given by Manoj to avoid os_event_wait 
                     handling inside the GfxDriverGetCharConfigInfo.
                     It is also tracked as PR defects in the PR ID: 76698

Date              :  30-May-2014
By                :  kcsarava
Traceability      :  Updated for PR ID: 76698;
Change Description:  Added text_clip_flag to indicate whether a clipping
                     happened or not. This will be used to apps to decide whether
                     to append ...
                     Also have the fix for raised PR defects

Date              :  26-May-2014
By                :  kcsarava
Traceability      :
Change Description:  Added function GfxDriverGetTextFitWidth() to get the total
                     number of characters that can be displayed with in the
                     available display width for the respective element and given
                     input text

Date              :  4-Jun-14
By                :  emanoj1
Traceability      :  request from C490
Change Description:  Updated the support for online RLE decode to make it
                     functional.

Date              :  4-Sep-12
By                :  tvijayas
Traceability      :  
Change Description:  Added support for segmented display and combination of
                     segmented and dot matrix.
                     GfxDriverSegmentBuildIcon()  and GfxDriverSegmentBuildText()
                     are created to update the icons and text for segmented display.
                     GFX_LAYER_XY_OFFSET_ENABLED acts as offset to frame buffer
                     where combination of dotmatrix and segmented is used.

Date              :  23-Sep-11
By                :  tvijayas
Traceability      :  
Change Description:  Issue in Binary search corrected.

Date              :  5-July-10
By                :  tvijayas
Traceability      :  
Change Description:  decompression logic for RLE added.

Date              :  11-March-10
By                :  tvijayas
Traceability      :  
Change Description:  Transparency support added for 2bb(only for text).

Date              :  04-March-10
By                :  tvijayas/emanoj1
Traceability      :  
Change Description:  Updated to support 2BPP display by considering it as a 
                     double width 1BPP (width * 2).

Date              :  22-July-09
By                :  tvijayas
Traceability      :  
Change Description:  Alignment fix done for GfxDriverCopyImage() moved to
                     GfxDriverCopyImageInverted() .
                     shedule wait macro GFX_DRIVER_SCHED_WAIT()placed at 
                     the end of loops.

Date              :  14-July-09
By                :  tvijayas
Traceability      :  
Change Description:  Schedule wait feature added.
                      
Date              :  03-July-09
By                :  tvijayas
Traceability      :  
Change Description:  added support for filling the  display buffer vertically.
                     Horizontal buffer fill - #define GFX_DRIVER_FB_HORIZONTAL_FILL YES 
                     Vertical buffer fill   - #define GFX_DRIVER_FB_HORIZONTAL_FILL NO 

Date              :  17-Jun-09
By                :  emanoj1
Traceability      :  
Change Description:  Modified to handle multiple layers and double buffering.

Date              :  12-Jun-09
By                :  tvijayas
Traceability      :  
Change Description:  Initial version.
-----------------------------------------------------------------------------*/
