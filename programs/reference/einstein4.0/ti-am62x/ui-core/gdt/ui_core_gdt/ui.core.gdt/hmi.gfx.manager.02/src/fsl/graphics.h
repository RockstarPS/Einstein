/**
  Copyright (c) 2009 Freescale Semiconductor

  \file       Graphics.h
  \brief      This is the Graphics Header Driver File
  \brief      Provides functionality to mirror, rotate, sub-scale and copy images
  \author     Freescale Semiconductor
  \author     Automotive Systems Solutions Engineering
  \author     Ioseph Martinez, b06623
  \version    1.1
  \date       19/May/2009

  * History:  20/August/2008 - Initial Version
              13/May/2009 - MISRA Check. Release

* Copyright (c) 2009, Freescale, Inc.  All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*

*/


#ifndef     _GRAPHICS_H_
#define     _GRAPHICS_H_

#include     "jdp.h"
#include     "ports.h"
#include     "common.h"
#if defined(GFX_MGR02_KEPLER) || defined(GFX_MGR02_FARADAY)
 #include     "dma.handler.h"
#endif
#include     "DCU.h"

/************************** Data Types ***************************************/


typedef  enum
{
    GRAPHICS_CODING_RAWINT = 0,
    GRAPHICS_CODING_RLEINT,
    GRAPHICS_CODING_RAWEXT,
    GRAPHICS_CODING_RLEEXT
} Graphics_Coding_t;

typedef  void  ( * Graphics_CallbackType )( void  );


#define     GRAPHICS_422YCBCR      (14u)
#define     GRAPHICS_16APAL8       (13u)
#define     GRAPHICS_4444ARGB      (12u)
#define     GRAPHICS_1555ARGB      (11u)
#define     GRAPHICS_L8BPP         (10u)
#define     GRAPHICS_L4BPP         (9u)
#define     GRAPHICS_T8BPP         (8u)
#define     GRAPHICS_T4BPP         (7u)
#define     GRAPHICS_32BPP         (6u)
#define     GRAPHICS_24BPP         (5u)
#define     GRAPHICS_565RGB        (4u)
#define     GRAPHICS_8BPP          (3u)
#define     GRAPHICS_4BPP          (2u)
#define     GRAPHICS_2BPP          (1u)
#define     GRAPHICS_1BPP          (0u)

typedef  enum
{
    GRAPHICS_ERROR_OK,
    GRAPHICS_ERROR_FAIL
} Graphics_ErrorType;

typedef  struct
{
    uint32_t  address;          /*  < Address in memory >                 */
    uint16_t  width;            /*  < W Dimension of sprite in pixels >           */
    uint16_t  height;           /*  < H Dimension of sprite in pixels >           */
    uint32_t  *CLUT;            /*  < Source address of CLUT >            */
    uint16_t  CLUTsize;         /*  < Number of bytes in CLUT >               */
    uint16_t  CLUTOffset;       /*  < CLUT offset in palette memory >             */
    uint8_t   BPP;          /*  < Bits per pixel coding >             */
    uint8_t   initialAlpha;         /*  < Initial alpha value >               */
    uint32_t  initialChromaMax;     /*  < Initial chroma setting                          */
    uint32_t  initialChromaMin;     /*  < Initial chroma setting                          */
    Graphics_Coding_t   coding;     /*  < If RLE is used or not. (0 = not used) >     */
    int16_t x;          /*  < Initial position in x >     */
    int16_t y;          /*  < Initial position in y >     */
} Graphics_Object_t;

/*--------------------------------------------------------------------------*/
/* FIFO interface for RLE module                                            */
/*--------------------------------------------------------------------------*/
#define _RLEinFIFO  (0x90004080)
#define _RLEoutFIFO (0x900040C0)
#define _RLE_FIFO_TXFR_SIZE (28)  /* valid range is up to 60 */

/************************ Public Functions ***********************************/

void            Graphics_Init(void);
Graphics_ErrorType  Graphics_BlankArea(uint8_t eDMAChannel, const Graphics_Object_t*  g_object, uint32_t value, Graphics_CallbackType callback);

void Graphics_CopyGraphicObject(const Graphics_Object_t *source, Graphics_Object_t *target);

Graphics_ErrorType  Graphics_SubCopy
(
    uint8_t  eDMAChannel,
    Graphics_Object_t*  Source,
    Graphics_Object_t*  Target,
    uint16_t xi,
    uint16_t yi,
    uint16_t xf,
    uint16_t yf,
    Graphics_CallbackType callback
);

Graphics_ErrorType Graphics_Paste
(
    uint8_t  eDMAChannel,
    Graphics_Object_t*  Source,
    Graphics_Object_t*  Target,
    uint16_t xi,
    uint16_t yi,
    Graphics_CallbackType callback
);

Graphics_ErrorType  Graphics_Downscale
(
    uint8_t eDMAChannel,
    Graphics_Object_t* Source,
    Graphics_Object_t* Target,
    uint8_t Factor_W,
    uint8_t Factor_H,
    Graphics_CallbackType callback
);

Graphics_ErrorType  Graphics_Rotate90( uint8_t  eDMAChannel, Graphics_Object_t* Source, Graphics_Object_t*  Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_Rotate180( uint8_t eDMAChannel, Graphics_Object_t* Source, Graphics_Object_t* Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_Rotate270(uint8_t eDMAChannel, Graphics_Object_t* Source, Graphics_Object_t* Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_MirrorV(uint8_t eDMAChannel, Graphics_Object_t * Source, Graphics_Object_t * Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_MirrorH( uint8_t  eDMAChannel, Graphics_Object_t*  Source, Graphics_Object_t*  Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_Rotate90MirrorV( uint8_t  eDMAChannel, Graphics_Object_t*  Source, Graphics_Object_t*  Target, Graphics_CallbackType callback);
Graphics_ErrorType  Graphics_Rotate90MirrorH( uint8_t  eDMAChannel, Graphics_Object_t*  Source, Graphics_Object_t*  Target, Graphics_CallbackType callback);
void                Graphics_Decode8bits(uint8_t *buf, const uint8_t *compressed, int32_t len);
void                Graphics_Decode8bitsDMA(uint8_t eDMAChannel, uint8_t *buf, const uint8_t *compressed, int32_t len);

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
Graphics_ErrorType Graphics_RleDmaSource(UINT32 p_source_addr, UINT32 height, UINT32 width);
Graphics_ErrorType Graphics_RleDmaDestination(UINT32 p_dest_addr, UINT32 height, UINT32 width);
void Graphics_Initialize_RleImageDecoder(UINT32 p_rle_format, UINT32 p_size,
                                         UINT32 p_rle_height, UINT32 p_rle_width,
                                         UINT32 p_sp_x, UINT32 p_sp_y,
                                         UINT32 p_ep_x, UINT32 p_ep_y
                                         );
void Graphics_Start_RleImageDecoder(void);
#endif

/******************* Public Macros Function-alike *****************************/



/********************** Private Data, DO NOT MODIFY ***************************************************************/

/* libsys.a abs funciton prototype to comply MISRA */
extern int abs( int  x );

#endif
