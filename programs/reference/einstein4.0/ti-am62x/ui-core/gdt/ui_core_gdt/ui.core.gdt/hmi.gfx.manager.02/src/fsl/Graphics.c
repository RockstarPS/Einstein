/**
  Copyright (c) 2009 Freescale Semiconductor

  \file       Graphics.c
  \brief      This is the Graphcis Driver File
  \brief      Provides functionality to mirror, rotate, sub-scale and copy images
  \author     Freescale Semiconductor
  \author     Automotive Systems Solutions Engineering
  \author     Ioseph Martinez, b06623
  \version    1.1
  \date       19/May/2009

  * History:  20/August/2008 -  Initial Version
          26/September/2008 De-machined, state machines only were adding overhead
          9/March/2009 - Converting functions to non-blocking
          10/March/2009 - Adding combined rotation with mirror operations
          13/May/2009 - MISRA Check. Release

  * MISRA VIOLATIONS:
    - [ MISRA 16.9 ]

* Copyright (c) 2009, Freescale, Inc.  All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*

*/
#include "hmi_gfx_mgr02_layout.h"
#include "graphics.h"


uint32_t Graphics_BlankValue32[8];
uint8_t  Graphics_BlankValueIdx;

Graphics_CallbackType Graphics_TCB[DMA_MAXIMUM_SUPPORTED_CHANNELS];

static void Graphics_Pixel2Bytes(uint8_t BPP, uint32_t *size);
static void Graphics_TransformationCallback(dma_handler_app_resp_struct * p_app_resp_S);

/**
* \brief    Graphics_Init - Initializes the graphics library control variables
* \brief    IT HAS NO FUNCTIONALITY YET
* \author   IM, b06623
* \param    void
* \return   void
* \todo
*/
void Graphics_Init(void)
{
  Graphics_BlankValueIdx = 0;
}

/**
* \brief    Graphics_BlankArea - Blanks a memory area with the selected value.
* \brief    To correctly fill 32bpp areas, destination must be aligned to 32bits
* \author   IM, b06623
* \param    uint8_t Channel, it is the DMA channel to be initialized.
* \param    const Graphics_Object_t* g_object: Is the graphic object info to initialize the layer
* \param    uint32_t value: This is the filling value, this pattern will be used to fill the memory
* \return   DMA_ErrorType, possible resutls: GRAPHICS_ERROR_OK, GRAPHICS_ERROR_FAIL
* \todo
*/
Graphics_ErrorType Graphics_BlankArea(uint8_t eDMAChannel, const Graphics_Object_t*  g_object, uint32_t value, Graphics_CallbackType callback)
{
    dma_handler_type   fl_dma_parameters;
    Graphics_ErrorType error1;
    uint32_t           size;

    size  = (uint32_t)(g_object->height * (uint32_t)g_object->width);
    Graphics_Pixel2Bytes(g_object->BPP, &size);

    if(size < 4u)
    {
        /* size is not > 4bytes */
        error1 = GRAPHICS_ERROR_FAIL;
    }
    else
    {
        Graphics_BlankValueIdx++;
        Graphics_BlankValue32[Graphics_BlankValueIdx&7] = value;

	    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32          = (uint32_t)&(Graphics_BlankValue32[Graphics_BlankValueIdx&7]);        
	    fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32     = (g_object->address & (uint32_t)~0x03);
	    fl_dma_parameters.dma_drv_channel_parameters.source_size_E		        = SIZE_4BYTE;
	    fl_dma_parameters.dma_drv_channel_parameters.destination_size_E	        = SIZE_4BYTE;
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32       = (size &(uint32_t)~0x03);
	    fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16       = 1;
	    fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16          = 0;
 	    fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16     = 4;    
	    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32 = 0;
	    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32   = 0;  
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8   = 0; 
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8  = 0;
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32      = 0;     
	    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16          = (DMA_SR_ALWAYS_ENB_0+eDMAChannel);
	    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E      = DMA_MUX_ALWAYS_ENB_REQUEST;
	    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8          = GFX_MGR02_EDMA_BWC_NORMAL_RENDERING;        
	    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8      = 1;
	    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8   = 1;
        fl_dma_parameters.dma_channel_num                                       = (dma_channel_num_type)eDMAChannel;
	    fl_dma_parameters.dma_callback                                          = Graphics_TransformationCallback;

		Graphics_TCB[eDMAChannel] =  callback;

        if(DMA_Handler_InitiateRequest(&fl_dma_parameters) == DMA_NO_ERROR)
        {
           error1 = GRAPHICS_ERROR_OK;
        }
        else
        {
           error1 = GRAPHICS_ERROR_FAIL;
        }
    }
    return error1;
}

/**
* \brief    Graphics_SubCopy - Takes Copies a section (equal or lesser)
* \brief    from graphic object to another graphic object
* \brief    IMPORTANT: Target with must be the same than delta 'x'
* \author   IM, b06623
* \param    uint8_t Channel, it is the DMA channel to be used.
* \param    const Graphics_Object_t* Source: Is the graphic object Source to be copied
* \param    const Graphics_Object_t* target: Is the graphic object Destination
* \param    uint16_t xi: It is the first x coordinate.
* \param    uint16_t yi: It is the first y coordinate.
* \param    uint16_t xf: It is the final x coordinate.
* \param    uint16_t yf: It is the final y coordinate.
* \return   DMA_ErrorType, possible resutls: GRAPHICS_ERROR_OK, GRAPHICS_ERROR_FAIL
* \todo
*/
Graphics_ErrorType Graphics_SubCopy
(
    uint8_t               eDMAChannel,
    Graphics_Object_t   * Source,
    Graphics_Object_t   * Target,
    uint16_t              xi,
    uint16_t              yi,
    uint16_t              xf,
    uint16_t              yf,
    Graphics_CallbackType callback
)
{
    dma_handler_type   fl_dma_parameters;
    Graphics_ErrorType error1;
    uint32_t           tmp;

    if(((xi >= xf) || (yi >= yf) ) || ((xf - xi) != Target->width))
    {
        error1 = GRAPHICS_ERROR_FAIL;
    }
    else if(Target->BPP != Source->BPP)
    {
        error1 = GRAPHICS_ERROR_FAIL;
    }
    else
    {
        tmp = 8u;
        Graphics_Pixel2Bytes(Target->BPP, &tmp);

	    fl_dma_parameters.dma_drv_channel_parameters.source_size_E		        = SIZE_1BYTE;
	    fl_dma_parameters.dma_drv_channel_parameters.destination_size_E	        = SIZE_1BYTE;
	    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16          = (DMA_SR_ALWAYS_ENB_0+eDMAChannel);
	    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E      = DMA_MUX_ALWAYS_ENB_REQUEST;
	    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8          = GFX_MGR02_EDMA_BWC_NORMAL_RENDERING;        
	    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8      = 1;
	    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8   = 1;
        fl_dma_parameters.dma_channel_num                                       = (dma_channel_num_type)eDMAChannel;
	    fl_dma_parameters.dma_callback                                          = Graphics_TransformationCallback;

	    fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16          = 1;
 	    fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16     = 1;    
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32       = ((uint32_t)xf - (uint32_t)xi);
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32      *= tmp;
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32      /= 8u;
	    fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16       = (uint16_t)(yf - yi);
	    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32 = 0;
	    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32   = 0;  
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8  = 0;
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8   = 1; 
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32      = ( int32_t )Source->width - ((int32_t)xf - (int32_t)xi);
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32     *= tmp;
	    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32     /= 8u;
	    fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32     = Target->address;
	    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32          = (xi + (yi*( uint32_t )Source->width));
	    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32         *= tmp;
	    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32         /= 8;
	    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32         += Source->address;

        Graphics_TCB[eDMAChannel] =  callback;

        if(DMA_Handler_InitiateRequest(&fl_dma_parameters) == DMA_NO_ERROR)
        {
            error1 = GRAPHICS_ERROR_OK;
        }
        else
        {
            error1 = GRAPHICS_ERROR_FAIL;
        }
    }

    return error1;
}

/**
* \brief    Graphics_Paste - Paste a GO where indicated. The source.width must be smaller than the target's
* \author   IM, b06623
* \param    uint8_t Channel, it is the DMA channel to be used.
* \param    const Graphics_Object_t* Source: Is the graphic object Source to be copied
* \param    const Graphics_Object_t* target: Is the graphic object Destination
* \param    uint16_t xi: It is the first x coordinate.
* \param    uint16_t yi: It is the first y coordinate.
* \return   DMA_ErrorType, possible resutls: GRAPHICS_ERROR_OK, GRAPHICS_ERROR_FAIL
* \todo
*/
Graphics_ErrorType Graphics_Paste
(
    uint8_t               eDMAChannel,
    Graphics_Object_t   * Source,
    Graphics_Object_t   * Target,
    uint16_t              xi,
    uint16_t              yi,
    Graphics_CallbackType callback
)
{
    dma_handler_type   fl_dma_parameters;
    Graphics_ErrorType error1;
    uint32_t           tmp;
    uint32_t           tmp0;

    /* Calculate pixel size */
    tmp = 8u;
    Graphics_Pixel2Bytes(Target->BPP, &tmp);

    if(Source->width > Target->width)
    {
        error1 = GRAPHICS_ERROR_FAIL;
    }
    else if((tmp < 4u) || (tmp == 24u))
    {
        error1 = GRAPHICS_ERROR_FAIL;
    }
    else
    {
	    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16          = (DMA_SR_ALWAYS_ENB_0+eDMAChannel);
	    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E      = DMA_MUX_ALWAYS_ENB_REQUEST;
	    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8          = GFX_MGR02_EDMA_BWC_NORMAL_RENDERING;        
	    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8      = 1;
	    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8   = 1;
        fl_dma_parameters.dma_channel_num                                       = (dma_channel_num_type)eDMAChannel;
	    fl_dma_parameters.dma_callback                                          = Graphics_TransformationCallback;
        Graphics_TCB[eDMAChannel] =  callback;


        if(tmp == 4u)
        {
            fl_dma_parameters.dma_drv_channel_parameters.destination_size_E = SIZE_1BYTE;
            fl_dma_parameters.dma_drv_channel_parameters.source_size_E      = SIZE_1BYTE;
            tmp  = 1u;
            tmp0 = 2u;
        }
        else if(tmp == 8u)
        {
            fl_dma_parameters.dma_drv_channel_parameters.destination_size_E = SIZE_1BYTE;
            fl_dma_parameters.dma_drv_channel_parameters.source_size_E      = SIZE_1BYTE;
            tmp  = 1u;
            tmp0 = 1u;
        }
        else if(tmp == 16u)
        {
            fl_dma_parameters.dma_drv_channel_parameters.destination_size_E = SIZE_2BYTE;
            fl_dma_parameters.dma_drv_channel_parameters.source_size_E      = SIZE_2BYTE;
            tmp  = 2u;
            tmp0 = 1u;
        }
        else /* if(tmp == 32) */
        {
            fl_dma_parameters.dma_drv_channel_parameters.destination_size_E = SIZE_4BYTE;
            fl_dma_parameters.dma_drv_channel_parameters.source_size_E      = SIZE_4BYTE;
            tmp  = 4u;
            tmp0 = 1u;
        }

        fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16          = (int16_t)tmp;
        fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16     = (int16_t)tmp;
        fl_dma_parameters.dma_drv_channel_parameters.source_address_U32         = Source->address;
        fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8   = 0u;
        fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8  = 1u;
	    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32 = 0;
	    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32   = 0;  

        if(tmp0 == 2)
        {
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32    = (uint32_t)(Source->width/tmp0);
            fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 = Target->address + ((xi + (yi*Target->width))/tmp0);
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32   = ((int32_t)Target->width/(int32_t)tmp0) - (int32_t)fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32;
        }
        else
        {
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32    = (uint32_t)Source->width*tmp;
            fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32 = Target->address + ((xi + (yi*Target->width))*tmp);
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32   = ((int32_t)Target->width - (int32_t)Source->width);//
            fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32   = fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32*(int32_t)tmp;
        }
        
        if(fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32 >= 1024)
        {
           fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8  = 0u;
           fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8 = 0u;        
        }
                
        if( Target->height < Source->height )
        {
            fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16 = Target->height;
        }
        else
        {
            fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16 = Source->height;
        }

        if(DMA_Handler_InitiateRequest(&fl_dma_parameters) == DMA_NO_ERROR)
        {
			error1 = GRAPHICS_ERROR_OK;
        }
        else
        {
            error1 = GRAPHICS_ERROR_FAIL;
        }
    }
    return error1;
}

static void Graphics_Pixel2Bytes(uint8_t BPP, uint32_t *size)
{
    switch(BPP)
    {
    case GRAPHICS_1BPP:
        *size = *size/8u;
        break;
    case GRAPHICS_2BPP:
        *size = *size/4u;
        break;
    case GRAPHICS_4BPP:
    case GRAPHICS_T4BPP:
    case GRAPHICS_L4BPP:
        *size = *size/2u;
        break;
    case GRAPHICS_565RGB:
    case GRAPHICS_1555ARGB:
    case GRAPHICS_4444ARGB:
    case GRAPHICS_16APAL8:
        *size = *size*2u;
        break;
    case GRAPHICS_24BPP:
        *size = *size*3u;
        break;
    case GRAPHICS_32BPP:
        *size = *size*4u;
        break;
    case GRAPHICS_8BPP:
    case GRAPHICS_T8BPP:
    case GRAPHICS_L8BPP:
    case GRAPHICS_422YCBCR:
    default:
        /* Do nothing */
        break;
    }
}

static void Graphics_TransformationCallback(dma_handler_app_resp_struct * p_app_resp_S)
{
    if(Graphics_TCB[p_app_resp_S->fl_dma_channel_num_U8] != NULL_PTR)
    {
        Graphics_TCB[p_app_resp_S->fl_dma_channel_num_U8]();
    }
}

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
/*============================================================================
 ** Function Name:    Graphics_RleDmaSource
 ** Visibility:       local
 ** Description:      Invoked by hmi_gfx_mgr02_dcu.c to configure the dma for
 **                   fetching the compressed data into rle module rx fifo
 ** Invocation:       By hmi_gfx_mgr02_dcu.c
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          06-Nov-2013 by NKRISHN9
 ** Updated:          06-Nov-2013 by NKRISHN9
 **==========================================================================*/
Graphics_ErrorType Graphics_RleDmaSource(UINT32 p_source_addr, UINT32 height, UINT32 width)
{
    dma_handler_type fl_dma_parameters;
    Graphics_ErrorType	error_status;

    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32=p_source_addr;          /* Source Address */
    fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32=_RLEinFIFO;        /* Dest Address */

    fl_dma_parameters.dma_drv_channel_parameters.source_size_E=SIZE_4BYTE;                  /* Source Size */
    fl_dma_parameters.dma_drv_channel_parameters.destination_size_E=SIZE_4BYTE;             /* Dest Size */

    fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16=4;                       /* Source Offset SOFF=4 in RLE*/
    fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16=0;                  /* Dest Offset DOFF=0*/
    
    fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16=(UINT16)1;            /* Major loop count BITER=1*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32=_RLE_FIFO_TXFR_SIZE;                   /* NBytes .NBYTESu.R= 0x0000 0028 in RLE*/

    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8=3;                       /* Bandwidth control In RLE BWC=0*/

    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32=0;              /* Last Source Adjustment SLAST=0*/
    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32=0;                /* Last Dest Adjustment DLAST_SGA=0*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32=0;                   /* Minor loop offset NBYTESu.R= 0x0000 0028 in RLE*/
    
    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16=DMA_SR_RLE_Rx_FIFO;      /* DMA Mux Source NumberDMAMUX.CHCONFIG[Channel].B.SOURCE=RLE_IN_SOURCE*/
    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E=DMA_MUX_HW_REQUEST;  /* Channel Service request type */

    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8=0;                /* Enable/Disable Minor loop offset for Source NBYTESu.R= 0x0000 0028 in RLE (SMLOE)*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8=0;               /* Enable/Disable Minor loop offset for Dest NBYTESu.R= 0x0000 0028 in RLE (SMLOE)*/

    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8=0;                   /* 1 - Disable HW Request when the outer major loop is complete, otherwise 0 D_REQ=0*/
    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8=0;                /* 1 - Enable outer major loop interrupt, 0 - Disable outer major loop interrupt INT_MAJ*/

    fl_dma_parameters.dma_callback = NULL_PTR;
    fl_dma_parameters.dma_channel_num = (dma_channel_num_type)GFX_MGR02_DMA_CHANNEL;

    if(DMA_Handler_InitiateRequest(&fl_dma_parameters) == DMA_NO_ERROR)
    {
        error_status = GRAPHICS_ERROR_OK;
    }
    else
    {
        error_status = GRAPHICS_ERROR_FAIL;
    }
	GFX_MGR02_UNUSED_VAR(height);
	GFX_MGR02_UNUSED_VAR(width);
    return(error_status);
}

/*============================================================================
 ** Function Name:    Graphics_RleDmaDestination
 ** Visibility:       local
 ** Description:      Invoked by hmi_gfx_mgr02_dcu.c to configure the dma for
 **                   fetching the uncompressed data into rle module tx fifo
 ** Invocation:       By hmi_gfx_mgr02_dcu.c
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          06-Nov-2013 by NKRISHN9
 ** Updated:          06-Nov-2013 by NKRISHN9
 **==========================================================================*/
Graphics_ErrorType Graphics_RleDmaDestination(UINT32 p_dest_addr, UINT32 height, UINT32 width)
{
    dma_handler_type fl_dma_parameters;
    Graphics_ErrorType	error_status;

    fl_dma_parameters.dma_drv_channel_parameters.source_address_U32=_RLEoutFIFO;            /* Source Address */
    fl_dma_parameters.dma_drv_channel_parameters.destination_address_U32=p_dest_addr;       /* Dest Address */

    fl_dma_parameters.dma_drv_channel_parameters.source_size_E=SIZE_4BYTE;                  /* Source Size     EDMA.TCD[Channel].DSIZE  = 2*/
    fl_dma_parameters.dma_drv_channel_parameters.destination_size_E=SIZE_4BYTE;             /* Dest Size       EDMA.TCD[Channel].DSIZE  = 2*/

    fl_dma_parameters.dma_drv_channel_parameters.source_offset_U16=0;                       /* Source Offset SOFF=0 in RLE*/
    fl_dma_parameters.dma_drv_channel_parameters.destination_offset_U16=4;                  /* Dest Offset DOFF=0*/

    fl_dma_parameters.dma_drv_channel_parameters.major_loop_count_U16=(UINT16)1;            /* Major loop count BITER=1*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_count_U32=_RLE_FIFO_TXFR_SIZE;                    /* NBytes .NBYTESu.R= 0x0000 0028 in RLE*/

    fl_dma_parameters.dma_drv_channel_parameters.bandwidth_ctrl_U8=3;                       /* Bandwidth control In RLE BWC=0*/

    fl_dma_parameters.dma_drv_channel_parameters.last_source_adjustment_U32=0;              /* Last Source Adjustment SLAST=0*/
    fl_dma_parameters.dma_drv_channel_parameters.last_dest_adjustment_U32=0;                /* Last Dest Adjustment DLAST_SGA=0*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_U32=0;                   /* Minor loop offset NBYTESu.R= 0x0000 0028 in RLE*/

    fl_dma_parameters.dma_drv_channel_parameters.source_number_U16=DMA_SR_RLE_Tx_FIFO;      /* DMA Mux Source Number DMAMUX.CHCONFIG[Channel].B.SOURCE=RLE_OUT_SOURCE*/
    fl_dma_parameters.dma_drv_channel_parameters.source_request_type_E=DMA_MUX_HW_REQUEST;  /* Channel Service request type */

    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_src_U8=0;                /* Enable/Disable Minor loop offset for Source NBYTESu.R= 0x0000 0028 in RLE (SMLOE)*/
    fl_dma_parameters.dma_drv_channel_parameters.minor_loop_offset_dest_U8=0;               /* Enable/Disable Minor loop offset for Dest NBYTESu.R= 0x0000 0028 in RLE (SMLOE)*/

    fl_dma_parameters.dma_drv_channel_parameters.disable_hw_request_U8=0;                   /* 1 - Disable HW Request when the outer major loop is complete, otherwise 0 D_REQ=0*/
    fl_dma_parameters.dma_drv_channel_parameters.enable_completion_isr_U8=0;                /* 1 - Enable outer major loop interrupt, 0 - Disable outer major loop interrupt INT_MAJ*/

    fl_dma_parameters.dma_callback = NULL_PTR;
    fl_dma_parameters.dma_channel_num = (dma_channel_num_type)GFX_MGR02_DMA_RLE_READ_CHANNEL;                     /* EDMA.SERQ.R */

    if(DMA_Handler_InitiateRequest(&fl_dma_parameters) == DMA_NO_ERROR)
    {
        error_status = GRAPHICS_ERROR_OK;
    }
    else
    {
        error_status = GRAPHICS_ERROR_FAIL;
    }
	GFX_MGR02_UNUSED_VAR(height);
	GFX_MGR02_UNUSED_VAR(width);	
    return(error_status);
}

/*============================================================================
 ** Function Name:    Graphics_Initialize_RleImageDecoder
 ** Visibility:       local
 ** Description:      Invoked to initialised the rle decoder before enable to un compress.
 ** Invocation:       By hmi_gfx_mgr02_dcu.c
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          06-Nov-2013 by NKRISHN9
 ** Updated:          06-Nov-2013 by NKRISHN9
 **==========================================================================*/
void Graphics_Initialize_RleImageDecoder(UINT32 p_rle_format, UINT32 p_size,\
                                         UINT32 p_rle_height, UINT32 p_rle_width,\
                                         UINT32 p_sp_x, UINT32 p_sp_y,\
                                         UINT32 p_ep_x, UINT32 p_ep_y\
                                         )
{
    RLE.MCR.B.MDIS = 1;
    RLE.ISR.R = 0xFFFFFFFFuL;

    RLE.ICR.B.WIDTH = p_rle_format;    /* Compressed Data (pixel) size */
    RLE.CISR.B.SIZE = p_size;          /* Compressed image size (bytes) */

    RLE.DICR.B.X    = p_rle_width;     /* decompressed image size */
    RLE.DICR.B.Y    = p_rle_height;

    RLE.SPCR.B.X    = p_sp_x;          /* Start pixel (top-left) - starts from 1 */
    RLE.SPCR.B.Y    = p_sp_y;
    RLE.EPCR.B.X    = p_ep_x;          /* End pixel (bottom-right) */
    RLE.EPCR.B.Y    = p_ep_y;
//    RLE.RIER.R=64;
    RLE.MCR.B.RX_FIFO_THRESHOLD=_RLE_FIFO_TXFR_SIZE+4;
    RLE.MCR.B.TX_FIFO_THRESHOLD=_RLE_FIFO_TXFR_SIZE+4;
    RLE.MCR.R |= 4;                    /* enable TX FIFO flush */
}

/*============================================================================
 ** Function Name:    Graphics_Start_RleImageDecoder
 ** Visibility:       local
 ** Description:      Invoked to start the image decoder to uncompress it.
 ** Invocation:       By hmi_gfx_mgr02_dcu.c
 ** Inputs/Outputs:
 ** Critical Section: None (this is called from ISR context).
 ** Created:          06-Nov-2013 by NKRISHN9
 ** Updated:          06-Nov-2013 by NKRISHN9
 **==========================================================================*/
void Graphics_Start_RleImageDecoder(void)
{
    /*----------------------------------------------------------------------*/
    /* Enable transmit finished interrupt. Will call rle_isr() when done    */
    /*----------------------------------------------------------------------*/
    RLE.RIER.B.TXDIE = 1;

    /*----------------------------------------------------------------------*/
    /* Enable the RLE decoder to start the transfer                         */
    /*----------------------------------------------------------------------*/
    RLE.MCR.B.MDIS   = 0;

}
#endif

/****************************************************************************
** CMS Rev 1.1     30-May-2017    SSIGAMAN
** RTC 845191: Content of text box in a screen gets disappears and recovers
**             only when new request with change in data for the text box is given.
** Rootcause : When the issue happens,Graphics_BlankArea is called with size 4Bytes
**             Which makes the minor_loop_count_U32 =0 and DMA initiated with it 
**             creates an issue. So, avoided the scenario of DMA transfer with 
**             minor loop count with 0.
**
** CMS Rev 1.0     06-Nov-2013    NKRISHN9
** Added functional interface to support RLE. 
****************************************************************************/

