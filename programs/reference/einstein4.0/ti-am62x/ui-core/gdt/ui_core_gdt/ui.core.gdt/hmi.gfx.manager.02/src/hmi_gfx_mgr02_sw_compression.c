/****************************************************************************
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
*****************************************************************************
**
** Name:           hmi_gfx_mgr02_sw_compression.c
**
** Description:    Module for Software compression related logic
**
** Organization:   GUI Software Section, Visteon
**
*****************************************************************************/

/************************** Start of Module *********************************/

/*****************************************************************************
                            Module Name
*****************************************************************************/
#define HMI_GFX_MGR02_SW_COMPRESSION_C
/*****************************************************************************
                            Include files
*****************************************************************************/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
#include "hmi_gfx_mgr02_sw_compression.h"
/*****************************************************************************
                            Macro Definitions
*****************************************************************************/

/*****************************************************************************
                            Type Definitions
*****************************************************************************/
typedef struct
{
    UINT8 const *   bmp_data;     /*  Compressed image data address */
    UINT32          data;              /*  Decompressed image data */
    UINT8           count;             /*  Number of times the same data to be repeated */
    UINT8           flag;              /*  If flag is 1 means, repeat the data, (count) number of times */         
}GFX_ONLINE_RLE;

/*****************************************************************************
                            Static Variable Declarations
*****************************************************************************/


/*****************************************************************************
                            Static Function Declarations
*****************************************************************************/

static void hmi_gfx_mgr02_compression_rle_online_decompress(GFX_ONLINE_RLE * p_rle_online, UINT8 p_bpp);

/*****************************************************************************
                            Function Definitions
*****************************************************************************/

/****************************************************************************
Function Name        : hmi_gfx_mgr02_comp_decompr_argb8888
Description          : Perform Decompression of Image with Format ARGB8888.
Invocation           : imxrt-pxp or vglite
Return Value         : none
Critical Section     : none
Parameters           : Image definition and frame buffer ptr
******************************************************************************/
void hmi_gfx_mgr02_comp_decompr_32bpp(GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP, UINT32* p_frame_buff_U32P)
{
    GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
    GFX_MGR02_ISIZE_H_T  fl_image_height;
    GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
    UINT32* fl_frame_buff_U32P = p_frame_buff_U32P;

    fl_image_width = p_elem_def_SP->width;
    fl_image_height = p_elem_def_SP->height;
    fl_rle_cur_s.bmp_data = (UINT8*)p_elem_def_SP->pixel_data;

    while (0u != fl_image_height)
    {
        fl_image_height--;
        fl_cur_x_size = fl_image_width;
        while (0u != fl_cur_x_size)
        {
            UINT32 fl_bmp_data_U32;
            fl_cur_x_size--;
            if (fl_rle_cur_s.count == (UINT8)0)
            {
                hmi_gfx_mgr02_compression_rle_online_decompress(&fl_rle_cur_s, 32U);
            }
            
            /* Although Count will never be zero, below if check is needed to avoid warnings */
            if (fl_rle_cur_s.count > (UINT8)0)
            {
                fl_rle_cur_s.count--;
            }
            if (fl_rle_cur_s.flag == (UINT8)FALSE)
            {
                fl_bmp_data_U32 = *fl_rle_cur_s.bmp_data++;
                fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data));
                fl_rle_cur_s.bmp_data++;
                fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data));
                fl_rle_cur_s.bmp_data++;
                fl_bmp_data_U32 = fl_bmp_data_U32 << 8U;
                fl_bmp_data_U32 = (fl_bmp_data_U32 | (*fl_rle_cur_s.bmp_data));
                fl_rle_cur_s.bmp_data++;
            }
            else
            {
                fl_bmp_data_U32 = fl_rle_cur_s.data;
            }
            
            *fl_frame_buff_U32P = fl_bmp_data_U32;
            fl_frame_buff_U32P += 1;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_comp_decompr_16bpp
Description          : Perform Decompression of Image with Format ARGB4444/RGB565.
Invocation           : imxrt-pxp or vglite
Return Value         : none
Critical Section     : none
Parameters           : Image definition and frame buffer ptr
******************************************************************************/
void hmi_gfx_mgr02_comp_decompr_16bpp(GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP, UINT16* p_frame_buff_U16P)
{
    GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
    GFX_MGR02_ISIZE_H_T  fl_image_height;
    GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
    UINT16* fl_frame_buff_U16P = p_frame_buff_U16P;

    fl_image_width = p_elem_def_SP->width;
    fl_image_height = p_elem_def_SP->height;

    fl_rle_cur_s.bmp_data = (UINT8*)p_elem_def_SP->pixel_data;

    while (0u != fl_image_height)
    {
        fl_image_height--;
        fl_cur_x_size = fl_image_width;
        while (0u != fl_cur_x_size)
        {
            UINT16 fl_bmp_data_U16;
            fl_cur_x_size--;
            if (fl_rle_cur_s.count == (UINT8)0)
            {
                hmi_gfx_mgr02_compression_rle_online_decompress(&fl_rle_cur_s, 16U);
            }
            
            /* Although Count will never be zero, below if check is needed to avoid warnings */
            if (fl_rle_cur_s.count > (UINT8)0)
            {
                fl_rle_cur_s.count--;
            }
            if (fl_rle_cur_s.flag == (UINT8)FALSE)
            {
                fl_bmp_data_U16 = *fl_rle_cur_s.bmp_data;
                fl_rle_cur_s.bmp_data++;
                fl_bmp_data_U16 = (UINT16)(fl_bmp_data_U16 << 8U);
                fl_bmp_data_U16 = (fl_bmp_data_U16 | (*fl_rle_cur_s.bmp_data));
                fl_rle_cur_s.bmp_data++;
            }
            else
            {
                fl_bmp_data_U16 = (UINT16)fl_rle_cur_s.data;
            }

            *fl_frame_buff_U16P = fl_bmp_data_U16;
            fl_frame_buff_U16P += 1;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_comp_decompr_8bpp
Description          : Perform Decompression of Image with Format Alpha mask A8.
Invocation           : imxrt-pxp or vglite
Return Value         : none
Critical Section     : none
Parameters           : Image definition and frame buffer ptr
******************************************************************************/
void hmi_gfx_mgr02_comp_decompr_8bpp(GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP, UINT8* p_frame_buff_U08P)
{
    GFX_MGR02_ISIZE_W_T  fl_image_width, fl_cur_x_size;
    GFX_MGR02_ISIZE_H_T  fl_image_height;
    GFX_ONLINE_RLE fl_rle_cur_s = { NULL,(UINT32)0,(UINT8)0,(UINT8)0 };
    UINT8* fl_frame_buff_U08P = p_frame_buff_U08P;

    fl_image_width = p_elem_def_SP->width;
    fl_image_height = p_elem_def_SP->height;

    fl_rle_cur_s.bmp_data = (UINT8*)p_elem_def_SP->pixel_data;

    while (0u != fl_image_height)
    {
        fl_image_height--;
        fl_cur_x_size = fl_image_width;
        while (0u != fl_cur_x_size)
        {
            UINT8 fl_bmp_data_U08;
            fl_cur_x_size--;
            if (fl_rle_cur_s.count == (UINT8)0)
            {
                hmi_gfx_mgr02_compression_rle_online_decompress(&fl_rle_cur_s, 8U);
            }
            
            /* Although Count will never be zero, below if check is needed to avoid warnings */
            if (fl_rle_cur_s.count > (UINT8)0)
            {
                fl_rle_cur_s.count--;
            }
            if (fl_rle_cur_s.flag == (UINT8)FALSE)
            {
                fl_bmp_data_U08 = *fl_rle_cur_s.bmp_data;
                fl_rle_cur_s.bmp_data++;
            }
            else
            {
                fl_bmp_data_U08 = (UINT8)fl_rle_cur_s.data;
            }

            *fl_frame_buff_U08P = fl_bmp_data_U08;
            fl_frame_buff_U08P += 1;
        }
    }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_compression_rle_online_decompress
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
static void hmi_gfx_mgr02_compression_rle_online_decompress(GFX_ONLINE_RLE *p_rle_online, UINT8 p_bpp)
{
    p_rle_online->count = *p_rle_online->bmp_data;

    if ((p_rle_online->count & 0x80u) == 0U)
    {
       p_rle_online->flag = (UINT8)FALSE;
    }
    else
    {
        p_rle_online->count &= 0x7Fu;
        p_rle_online->flag = (UINT8)TRUE;
        p_rle_online->bmp_data++;
        switch (p_bpp)
        {
            case (UINT8)8:
            {
                p_rle_online->data = (UINT32)(*p_rle_online->bmp_data);
            }
            break;
            case (UINT8)16:
            {
                p_rle_online->data = (UINT32)(*p_rle_online->bmp_data);
                p_rle_online->data = p_rle_online->data << 8U;
                p_rle_online->bmp_data++;
                p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
            }
            break;
            case (UINT8)32:
            {
                p_rle_online->data = (UINT32)(*p_rle_online->bmp_data);
                p_rle_online->data = p_rle_online->data << 8U;
                p_rle_online->bmp_data++;
                p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
                p_rle_online->data = p_rle_online->data << 8U;
                p_rle_online->bmp_data++;
                p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
                p_rle_online->data = p_rle_online->data << 8U;
                p_rle_online->bmp_data++;
                p_rle_online->data = (p_rle_online->data | (*p_rle_online->bmp_data));
            }
            break;
            default:
            {
                /* If other formats are used, then the corresponding change has to be made.
                ** So, we are not expecting the control to reach here.
                ** If it reaches here, then it is considered as Alpha mask A8 image.
                */
                p_rle_online->data = (UINT32)(*p_rle_online->bmp_data);
            }
            break;
        }
    }
    p_rle_online->bmp_data++;
}

#endif /* #if defined(GFX_MGR02_COMPRESSION_ENABLED) */

/************************** End of Module *********************************/

