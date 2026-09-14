/**
  Copyright (c) 2009 Freescale Semiconductor

  \file       DCU.h
  \brief      This is the DCU Driver Header File
  \brief      Configures Freq. and Activates DCU and layers on xPC560xS (SPECTRUM)
  \author     Freescale Semiconductor
  \author     Automotive Systems Solutions Engineering
  \author     Ioseph Martinez, b06623
  \version    1.1
  \date       19/May/2009

  * History:  10/July/2008 - Initial Version
              13/May/2009 - MISRA Check

* Copyright (c) 2009, Freescale, Inc.  All rights reserved.
*
*
* No part of this document must be reproduced in any form - including copied,
* transcribed, printed or by any electronic means - without specific written
* permission from Freescale Semiconductor.
*

*/


#ifndef     _DCU_H_
#define     _DCU_H_

#include     "jdp.h"
#include     "Common.h"

/* Data Types */

typedef  enum
{
    DCU_VSYNC,
    DCU_VBLANK,
    DCU_LSBFVS,
    DCU_UNKNOWN
}DCU_Timing_t;

typedef  enum
{
    DCU_PLANE0 = 0,
    DCU_PLANE1,
    DCU_PLANE2,
    DCU_PLANE3,
    DCU_PLANE4,
    DCU_PLANE5,
    DCU_PLANE6,
    DCU_PLANE7,
    DCU_PLANE8,
    DCU_PLANE9,
    DCU_PLANE10,
    DCU_PLANE11,
    DCU_PLANE12,
    DCU_PLANE13,
    DCU_PLANE14,
    DCU_PLANE15
} DCU_Plane_t;

#define DCU_CHROMMA_ON      (1u)
#define DCU_CHROMMA_OFF     (0u)

#define DCU_ALPHA_OFF       (0u)
#define DCU_ALPHACHROMMA_ON (1u)
#define DCU_ALPHAALL_ON     (2u)
typedef enum {
  DCU_FMT_1BPP          = 0,
  DCU_FMT_2BPP          = 1,
  DCU_FMT_4BPP          = 2,
  DCU_FMT_8BPP          = 3,
  DCU_FMT_RGB565        = 4,
  DCU_FMT_RGB888        = 5,
  DCU_FMT_ARGB8888      = 6,
  DCU_FMT_TM4           = 7,    /* transparency mode 4bpp */
  DCU_FMT_TM8           = 8,    /* transparency mode 8bpp */
  DCU_FMT_OM4           = 9,    /* offset mode 4bpp */
  DCU_FMT_OM8           = 10,   /* offset mode 8bpp */
  DCU_FMT_ARGB1555      = 11,
  DCU_FMT_ARGB4444      = 12,
  DCU_FMT_APAL8         = 13,
  DCU_FMT_YCBCR422      = 14,
  DCU_FMT_RESERVED2     = 15,
} DCU_PixFmt_t;

typedef  void  ( * DCU_CallbackType )( void  );

/* Configuration Parameters */
#define         DCU_LCD                 DCU_HITACHI_TX09
/* DCU_SHARP_LQ043 */
#define         DCU_WIDTH_ATOMICITY     (1)
#define         DCU_WIDTH_ATOMICITY2    (16)
#define         DCU_MAXLAYERS           (16)

/* Public Functions */
void DCU_Init( uint32_t  freq );
void DCU_SetChroma(DCU_Plane_t layer, uint32_t max, uint32_t min);
void DCU_SetCallbackVSBLANK( DCU_CallbackType Callback );
void DCU_SetCallbackLSBFVS( DCU_CallbackType Callback );
void DCU_SetCallbackVSYNC( DCU_CallbackType Callback );
void DCU_SetCallbackProgDone( DCU_CallbackType Callback);


/* Public Macros Function-alike */
#define     DCU_LayerEnable( Layer )        DCU.LAYER [ ( Layer ) ].CTRLDESCL4.B.EN = 1u
#define     DCU_LayerDisable( Layer )       DCU.LAYER [ ( Layer ) ].CTRLDESCL4.B.EN = 0u
#define     DCU_LayerIsEnabled( Layer )     (DCU.LAYER [ ( Layer ) ].CTRLDESCL4.B.EN)
#define     DCU_LayerAddress( Layer )       (DCU.LAYER [ ( Layer ) ].CTRLDESCL3.R)

#define     DCU_LayerSetWidth( Layer, Width )   DCU.LAYER[ (Layer) ].CTRLDESCL1.B.WIDTH = ((Width)/DCU_WIDTH_ATOMICITY)
#define     DCU_LayerGetWidth( Layer )      (DCU.LAYER[ (Layer) ].CTRLDESCL1.B.WIDTH*DCU_WIDTH_ATOMICITY)
#define     DCU_LayerSetHeight( Layer, Height ) DCU.LAYER[ (Layer) ].CTRLDESCL1.B.HEIGHT = (Height)
#define     DCU_LayerGetHeight( Layer )     (DCU.LAYER[ (Layer) ].CTRLDESCL1.B.HEIGHT)

#define     DCU_LayerSetX( Layer, X )       DCU.LAYER[ (Layer) ].CTRLDESCL2.B.POSX = ((X)/DCU_WIDTH_ATOMICITY)
#define     DCU_LayerGetX( Layer )          (DCU.LAYER[ (Layer) ].CTRLDESCL2.B.POSX*DCU_WIDTH_ATOMICITY)
#define     DCU_LayerSetY( Layer, Y )       DCU.LAYER[ (Layer) ].CTRLDESCL2.B.POSY  = (Y)
#define     DCU_LayerGetY( Layer )          (DCU.LAYER[ (Layer) ].CTRLDESCL2.B.POSY)

#define     DCU_LayerBPP( Layer )           (DCU.LAYER[ (Layer) ].CTRLDESCL4.B.BPP)
#define     DCU_LayerAlpha( Layer )         (DCU.LAYER[ (Layer) ].CTRLDESCL4.B.TRANS)
#define     DCU_LayerOffset( Layer )        (DCU.LAYER[ (Layer) ].CTRLDESCL4.B.LUOFFS)
#define     DCU_LayerAlphaCfg( Layer )      (DCU.LAYER[ (Layer) ].CTRLDESCL4.B.AB)
#define     DCU_LayerChromaCfg( Layer )     (DCU.LAYER[ (Layer) ].CTRLDESCL4.B.BB)

#define     DCU_GetMaxY( )              (DCU.DSPSIZE.B.DELTAY)
#define     DCU_GetMaxX( )              (DCU.DSPSIZE.B.DELTAX*DCU_WIDTH_ATOMICITY2)
#define     DCU_Clut( idx )             (DCU.CLUT[ (idx) ])
#define     DCU_SetLinesBeforVSYNC( Lines )     (DCU.THRESHOLD.B.LS_BF_VS =(Lines))
#define     DCU_GetTimingStatus( )          (DCU_TimingStatus)

#define     DCU_HWCursorHeight( )           (DCU.CTRLDESCCURSOR1.B.HEIGHT)
#define     DCU_HWCursorWidth( )            (DCU.CTRLDESCCURSOR1.B.WIDTH)
#define     DCU_HWCursorX( )            (DCU.CTRLDESCCURSOR2.B.POSX)
#define     DCU_HWCursorY( )            (DCU.CTRLDESCCURSOR2.B.POSY)
#define     DCU_HWCursorDisable( )          DCU.CTRLDESCCURSOR3.B.CUR_EN = 0u
#define     DCU_HWCursorEnable( )           DCU.CTRLDESCCURSOR3.B.CUR_EN = 1u
#define     DCU_HWCursorSetColor( value )       DCU.CTRLDESCCURSOR3.B.CURSOR_DEFAULT_COLOR = (value)
#define     DCU_HWCursorBlinkEn( )          DCU.CTRLDESCCURSOR4.B.EN_BLINK = 1u
#define     DCU_HWCursorBlinkDis( )         DCU.CTRLDESCCURSOR4.B.EN_BLINK = 0u
#define     DCU_HWCursorSetBlinkONVal( value )  DCU.CTRLDESCCURSOR4.B.HWC_BLINK_ON = (value)
#define     DCU_HWCursorSetBlinkOFFVal( value ) DCU.CTRLDESCCURSOR4.B.HWC_BLINK_OFF = (value)
#define     DCU_Cursor( idx )           (DCU.CURSOR[ (idx) ])

#define     DCU_ForeGroundColor( Layer )        (DCU.FG[Layer].F.B.COLOR)
#define     DCU_BackGroundColor( Layer )        (DCU.FG[Layer].B.B.COLOR)

#define     DCU_Enable( )                   DCU.DCU_MODE.B.DCU_MODE = 1u

/* End of user modifiable parameters */


/********************** Private Data, DO NOT MODIFY ***************************************************************/

#define     DCU_HITACHI_TX09               0
#define     DCU_SHARP_LQ043                1

extern DCU_Timing_t DCU_TimingStatus;

void DCU_TIMING_ISR( void  );

#endif
