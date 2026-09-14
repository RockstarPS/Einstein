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
 ** Name:           hmi_gfx_reg.h
 **
 ** Description:    Kepler/Faraday processor DCU/DMA register mapping.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#ifndef HMI_GFX_MGR02_REG_H
#define HMI_GFX_MGR02_REG_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#if !defined(GFX_MGR02_FARADAY) || defined(WIN32)
 #include "mcu_preg.h"
#else
 #include "typedefs.h"
#endif

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#if defined(GFX_MGR02_FARADAY) && !defined(WIN32)
struct TCON_tag
{
   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t RSDS_MODE:1;
         vuint32_t RGB_PADDING:1;
         vuint32_t RGB_PADDING_EN:1;
         vuint32_t COLOR_DEPTH:1;
         vuint32_t VSYNC_INV:1;
         vuint32_t HSYNC_INV:1;
         vuint32_t VLEN:2;
         vuint32_t H_REF_SEL:2;
         vuint32_t V_REF_SEL:3;
         vuint32_t INIT_DELAY:3;
         vuint32_t TCON0_INV:1;
         vuint32_t TCON1_INV:1;
         vuint32_t TCON2_INV:1;
         vuint32_t TCON3_INV:1;
         vuint32_t TCON4_INV:1;
         vuint32_t TCON5_INV:1;
         vuint32_t TCON6_INV:1;
         vuint32_t TCON7_INV:1;
         vuint32_t TCON8_INV:1;
         vuint32_t TCON9_INV:1;
         vuint32_t TCON10_INV:1;
         vuint32_t TCON11_INV:1;
         vuint32_t DATA_INV_EN:1;
         vuint32_t TCON_BYPASS:1;
         vuint32_t:1;
         vuint32_t TCON_EN:1;

      }B;
   }CTRL1;                      /* Control 1 Register */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t BIT_SWAP:1;
         vuint32_t BIT_ORDER:1;
         vuint32_t COLOR_ORDER:3;
         vuint32_t CLK_POS:5;
         vuint32_t:22;
      }B;
   }BMC;                        /* Comparator Register */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t COMP_VALUE:12;
          vuint32_t:19;
          vuint32_t FUNC_SEL:1;
      }B;
   }COMP[4];                    /* Comparator Mask Register */

   union
   {
      vuint32_t R;
      struct 
      {
         vuint32_t MASK:12;
         vuint32_t:20;
      }B;
   }COMP_MSK[4];                /* Bit map control Register */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t RESET:12;
         vuint32_t:2;
         vuint32_t COMPARATOR_SEL:2;
         vuint32_t SET:12;
         vuint32_t:2;
         vuint32_t FUNC_SEL:2;
      }B;
   }PULSE[6];                   /* Pulse Register */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t RESETMASK:12;
         vuint32_t:4;
         vuint32_t SETMASK:12;
         vuint32_t:4;
      }B;
   }PULSE_MSK[6];               /* Pulse mask Register */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t X_SEL:5;
          vuint32_t Y_SEL:5;
          vuint32_t:10;
          vuint32_t INDEX0_SEL:3;
          vuint32_t INDEX1_SEL:3;
          vuint32_t INDEX2_SEL:3;
          vuint32_t INDEX3_SEL:3;
      }B1;
   }SMX[14];                    /* Multiplexer control Register */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t TCON0:5;
          vuint32_t TCON1:5;
          vuint32_t TCON2:5;
          vuint32_t TCON3:5;
          vuint32_t TCON4:5;
          vuint32_t TCON5:5;
          vuint32_t:2;
      }B;
   }OMUX_LOW;                   /* Output MUX Low Register */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t TCON6:5;
          vuint32_t TCON7:5;
          vuint32_t TCON8:5;
          vuint32_t TCON9:5;
          vuint32_t TCON10:5;
          vuint32_t TCON11:5;
          vuint32_t:2;
      }B;
   }OMUX_HIGH;                  /* Output MUX high Register */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t LUT:32;
      } B;
   }LUT[14];                    /* Look up table Registers */
#if 0
   union/*endianess not changed*/
   {
      vuint32_t R;
      struct
      {
         vuint32_t:16;
         vuint32_t POL:1;
         vuint32_t:2;
         vuint32_t OSUFINE2:1;
         vuint32_t OSUFINE1:1;
         vuint32_t OSUCRSE2:1;
         vuint32_t OSUCRSE1:1;
         vuint32_t OSDFINE:1;
         vuint32_t SKEWOPT:8;
      }B;
   }DLY[13];                    /* Look up table Registers */
#endif
   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t:7;
          vuint32_t CLK_OFFSET:9;
          vuint32_t:8;
          vuint32_t DIV_RATIO:8;
      }B;
   }CTRL2;                      /* Control 2 Register */
};

struct DCU_FG_tag 
{
   union 
   {
      vuint32_t R;
      struct 
      {
         vuint32_t:8;
         vuint32_t COLOR:24;
      }B;
   }F;                           /* Transparency layer foreground color */
   union 
   {
      vuint32_t R;
      struct
      {
         vuint32_t:8;
         vuint32_t COLOR:24;
      }B;
   }B;                           /* Transparency layer foreground color */
};

struct DCU_LAYER_tag 
{
   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t WIDTH:11;
         vuint32_t:5;
         vuint32_t HEIGHT:11;
         vuint32_t:5;
      } B;
   } CTRLDESCL1;                  /* LAYER[X].CTRLDESCL1 */

   union 
   {
      vuint32_t R;
      struct
      {
         vint32_t POSX:12;
         vint32_t:4;
         vint32_t POSY:12;
         vint32_t:4;
      }B;
   }CTRLDESCL2;                  /* LAYER[X].CTRLDESCL2 */

   union
   {
      vuint32_t R;
      struct
      {
        vuint32_t ADDR:32;
      } B;
   }CTRLDESCL3;                  /* LAYER[X].CTRLDESCL3 */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t AB:2;
         vuint32_t BB:1;
         vuint32_t:1;
         vuint32_t LUOFFS:11;
         vuint32_t RLE_EN:1;
         vuint32_t BPP:4;
         vuint32_t TRANS:8;
         vuint32_t SAFETY_EN:1;
         vuint32_t DATA_SEL:1;
         vuint32_t TILE_EN:1;
         vuint32_t EN:1;
      }B;
   }CTRLDESCL4;                  /* LAYER[X].CTRLDESCL4 */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t CKMAX_B:8;
         vuint32_t CKMAX_G:8;
         vuint32_t CKMAX_R:8;
         vuint32_t:8;
      } B;
   } CTRLDESCL5;                  /* LAYER[X].CTRLDESCL5 */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t CKMIN_B:8;
          vuint32_t CKMIN_G:8;
          vuint32_t CKMIN_R:8;
          vuint32_t:8;
       }B;
   }CTRLDESCL6;                  /* LAYER[X].CTRLDESCL6 */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t TILE_HOR_SIZE:7;
          vuint32_t:9;
          vuint32_t TILE_VER_SIZE:11;
          vuint32_t:5;
      }B;
   } CTRLDESCL7;                  /* LAYER[X].CTRLDESCL7 */
   struct DCU_FG_tag FG;
   vuint32_t DCU_reserved1[7];
};                                 /* end of DCU_LAYER_tag */

struct DCU_tag 
{
        union {
            vuint32_t R;
            struct {
                vuint32_t WIDTH:11;
                  vuint32_t:5;
                vuint32_t HEIGHT:11;
                  vuint32_t:5;
            } B;
        } CTRLDESCCURSOR1;             /* Control Descriptor Cursor_1 Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t POSX:11;
                  vuint32_t:5;
                vuint32_t POSY:11;
                  vuint32_t:5;
            } B;
        } CTRLDESCCURSOR2;             /* Control Descriptor Cursor_2 Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t CURSOR_DEFAULT_COLOR:24;
                  vuint32_t:7;
                vuint32_t CUR_EN:1;
            } B;
        } CTRLDESCCURSOR3;             /* Control Descriptor Cursor_3 Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t HWC_BLINK_ON:8;
                vuint32_t EN_BLINK:1;
                  vuint32_t:7;
                vuint32_t HWC_BLINK_OFF:8;
                  vuint32_t:8;
            } B;
        } CTRLDESCCURSOR4;             /* Control Descriptor Cursor_4 Register */

        union {
            vuint32_t R;
            struct {

                vuint32_t DCU_MODE:2;
                vuint32_t EN_GAMMA:1;
                vuint32_t TEST:1;
                vuint32_t PDI_SYNC:1;
                vuint32_t SIG_EN:1;
                vuint32_t TAG_EN:1;
                vuint32_t PDI_SLAVE_MODE:1;
                vuint32_t PDI_MODE:2;
                vuint32_t PDI_NARROW_MODE:1;
                vuint32_t PDI_DE_MODE:1;
                vuint32_t PDI_BYTE_REV:1;
                vuint32_t PDI_EN:1;
                vuint32_t RASTER_EN:1;
                vuint32_t PDI_INTERPOL_EN:1;
                vuint32_t PDI_SYNC_LOCK:4;
                vuint32_t BLEND_ITER:3;
                vuint32_t DDR_MODE:1;
                vuint32_t ADDR:2;
                vuint32_t ADDG:2;
                vuint32_t ADDB:2;
                vuint32_t EN_DITHER:1;
                vuint32_t DCU_SW_RESET:1;
            } B;
        } DCU_MODE;                    /* DCU Mode Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t BGND_B:8;
                vuint32_t BGND_G:8;
                vuint32_t BGND_R:8;
                vuint32_t:8;
            } B;
        } BGND;                        /* BGND Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t DELTA_X:7;
                  vuint32_t:9;
                vuint32_t DELTA_Y:11;
                  vuint32_t:5;
            } B;
        } DISP_SIZE;                   /* DISP_SIZE Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t FP_H:9;
                  vuint32_t:2;
                vuint32_t PW_H:9;
                  vuint32_t:2;
                vuint32_t BP_H:9;
                  vuint32_t:1;
            } B;
        } HSYN_PARA;                   /* HSYNPARA Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t FP_V:9;
                  vuint32_t:2;
                vuint32_t PW_V:9;
                  vuint32_t:2;
                vuint32_t BP_V:9;
                  vuint32_t:1;
            } B;
        } VSYN_PARA;                   /* VSYNPARA Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t INV_HS:1;
                vuint32_t INV_VS:1;
                vuint32_t INV_CS:1;
                vuint32_t BP_HS:1;
                vuint32_t BP_VS:1;
                vuint32_t NEG:1;
                vuint32_t INV_PXCK:1;
                vuint32_t INV_PDI_CLK:1;
                vuint32_t INV_PDI_VS:1;
                vuint32_t INV_PDI_HS:1;
                vuint32_t INV_PDI_DE:1;
                  vuint32_t:21;
            } B;
        } SYN_POL;                     /* SYNPOL Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t OUT_BUF_LOW:8;
                vuint32_t OUT_BUF_HIGH:8;
                vuint32_t LS_BF_VS:11;
                  vuint32_t:5;
            } B;
        } THRESHOLD;                   /* Threshold Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t VSYNC:1;
                vuint32_t UNDRUN:1;
                vuint32_t LS_BF_VS:1;
                vuint32_t VS_BLANK:1;
                vuint32_t CRC_READY:1;
                vuint32_t CRC_OVERFLOW:1;
                vuint32_t P1_FIFO_LO_FLAG:1;
                vuint32_t P1_FIFO_HI_FLAG:1;
                vuint32_t P2_FIFO_LO_FLAG:1;
                vuint32_t P2_FIFO_HI_FLAG:1;
                vuint32_t PROG_END:1;
                vuint32_t IPM_ERROR:1;
                 vuint32_t LYR_TRANS_FINISH:1;
                 vuint32_t:1;
                vuint32_t DMA_TRANS_FINISH:1;
                  vuint32_t:1;
                vuint32_t P3_FIFO_LO_FLAG:1;
                vuint32_t P3_FIFO_HI_FLAG:1;
                vuint32_t P4_FIFO_LO_FLAG:1;
                vuint32_t P4_FIFO_HI_FLAG:1;
                vuint32_t P5_FIFO_LO_FLAG:1;
                vuint32_t P5_FIFO_HI_FLAG:1;
                vuint32_t P6_FIFO_LO_FLAG:1;
                vuint32_t P6_FIFO_HI_FLAG:1;
                vuint32_t:2;
                vuint32_t P1_EMPTY:1;
                vuint32_t P2_EMPTY:1;
                vuint32_t P3_EMPTY:1;
                vuint32_t P4_EMPTY:1;
                vuint32_t P5_EMPTY:1;
                vuint32_t P6_EMPTY:1;
            } B;
        } INT_STATUS;                    /* Interrupt Status Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t M_VSYNC:1;
                vuint32_t M_UNDRUN:1;
                vuint32_t M_LS_BF_VS:1;
                vuint32_t M_VS_BLANK:1;
                vuint32_t M_CRC_READY:1;
                vuint32_t M_CRC_OVERFLOW:1;
                vuint32_t M_P1_FIFO_LO_FLAG:1;
                vuint32_t M_P1_FIFO_HI_FLAG:1;
                vuint32_t M_P2_FIFO_LO_FLAG:1;
                vuint32_t M_P2_FIFO_HI_FLAG:1;
                vuint32_t M_PROG_END:1;
                vuint32_t M_IPM_ERROR:1;
                 vuint32_t M_LYR_TRANS_FINISH:1;
                 vuint32_t:1;
                vuint32_t M_DMA_TRANS_FINISH:1;
                  vuint32_t:1;
                vuint32_t M_P3_FIFO_LO_FLAG:1;
                vuint32_t M_P3_FIFO_HI_FLAG:1;
                vuint32_t M_P4_FIFO_LO_FLAG:1;
                vuint32_t M_P4_FIFO_HI_FLAG:1;
                vuint32_t M_P5_FIFO_LO_FLAG:1;
                vuint32_t M_P5_FIFO_HI_FLAG:1;
                vuint32_t M_P6_FIFO_LO_FLAG:1;
                vuint32_t M_P6_FIFO_HI_FLAG:1;
                vuint32_t:2;
                vuint32_t M_P1_EMPTY:1;
                vuint32_t M_P2_EMPTY:1;
                vuint32_t M_P3_EMPTY:1;
                vuint32_t M_P4_EMPTY:1;
                vuint32_t M_P5_EMPTY:1;
                vuint32_t M_P6_EMPTY:1;
            } B;
        } INT_MASK;                    /* Interrupt Mask Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t COLBAR_B:8;
                vuint32_t COLBAR_G:8;
                vuint32_t COLBAR_R:8;
                  vuint32_t:8;
            } B;
        } COLBAR[8];                   /* COLBAR 1-8 Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t DIV_RATIO:8;
                  vuint32_t:24;
            } B;
        } DIV_RATIO;                   /* Clock Divider Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t SIG_HOR_SIZE:11;
                  vuint32_t:5;
                vuint32_t SIG_VER_SIZE:11;
                  vuint32_t:5;
            } B;
        } SIGN_CALC_1;                 /* CRC size configuration */

        union {
            vuint32_t R;
            struct {
                vuint32_t SIG_HOR_POS:11;
                  vuint32_t:5;
                vuint32_t SIG_VER_POS:11;
                  vuint32_t:5;
            } B;
        } SIGN_CALC_2;                 /* CRC position configuration */

        union {
            vuint32_t R;
            struct {
                vuint32_t CRC_VAL:32;
            } B;
        } CRC_VAL;                     /* CRC Result register */

        union {
            vuint32_t R;
            struct {
                vuint32_t PDI_CLK_DET:1;
                vuint32_t PDI_CLK_LOST:1;
                vuint32_t PDI_DE_DET:1;
                vuint32_t PDI_HSYNC_DET:1;
                vuint32_t PDI_VSYNC_DET:1;
                vuint32_t PDI_LOCK_DET:1;
                vuint32_t PDI_LOCK_LOST:1;
                vuint32_t PDI_ECC_ERR1:1;
                vuint32_t PDI_ECC_ERR2:1;
                vuint32_t PDI_BLANKING_ERR:1;
                  vuint32_t:22;
            } B;
        } PDI_STATUS;                  /* PDI status Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t M_PDI_CLK_DET:1;
                vuint32_t M_PDI_CLK_LOST:1;
                vuint32_t M_PDI_DE_DET:1;
                vuint32_t M_PDI_HSYNC_DET:1;
                vuint32_t M_PDI_VSYNC_DET:1;
                vuint32_t M_PDI_LOCK_DET:1;
                vuint32_t M_PDI_LOCK_LOST:1;
                vuint32_t M_PDI_ECC_ERR1:1;
                vuint32_t M_PDI_ECC_ERR2:1;
                vuint32_t M_PDI_BLANKING_ERR:1;
                  vuint32_t:22;
            } B;
        } MASK_PDI_STATUS;             /* PDI Status Mask Register */
        struct L_PAR_ERROR_S
        {
           vuint32_t L_PAR_ERR_031;
           vuint32_t L_PAR_ERR_3163;
        }PARR_ERR_STATUS1;
        vuint32_t DCU_reserved1[2];
        union {
            vuint32_t R;
            struct {
                vuint32_t DISP_ERR:1;
                vuint32_t SIG_ERR:1;
                vuint32_t HWC_ERR:1;
                  vuint32_t:29;
            } B;
        } PARR_ERR_STATUS2;             /* Parameter error status Register */
        
        struct L_M_PAR_ERROR_S
        {
           vuint32_t L_M_PAR_ERR_031;
           vuint32_t L_M_PAR_ERR_3163;
        }MASK_PARR_ERR_STATUS1;
        vuint32_t DCU_reserved2[2];
        union {
            vuint32_t R;
            struct {
                vuint32_t M_DISP_ERR:1;
                vuint32_t M_SIG_ERR:1;
                vuint32_t M_HWC_ERR:1;
                  vuint32_t:29;
            } B;
        }MASK_PARR_ERR_STATUS2;        /* Parameter error mask Register */
        union {
            vuint32_t R;
            struct {
                vuint32_t INP_BUF_P1_LO:8;
                vuint32_t INP_BUF_P1_HI:8;
                vuint32_t INP_BUF_P2_LO:8;
                vuint32_t INP_BUF_P2_HI:8;
            } B;
        } THRESHOLD_INP1;              /* Threshold Input Buffer Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t INP_BUF_P3_LO:8;
                vuint32_t INP_BUF_P3_HI:8;
                vuint32_t INP_BUF_P4_LO:8;
                vuint32_t INP_BUF_P4_HI:8;
            } B;
        } THRESHOLD_INP2;              /* Threshold Input Buffer Register */
        union {
            vuint32_t R;
            struct {
                vuint32_t INP_BUF_P5_LO:8;
                vuint32_t INP_BUF_P5_HI:8;
                vuint32_t INP_BUF_P6_LO:8;
                vuint32_t INP_BUF_P6_HI:8;
            } B;
        } THRESHOLD_INP3;              /* Threshold Input Buffer Register */
        union {
            vuint32_t R;
            struct {
                vuint32_t Y_BLUE:10;
                  vuint32_t:1;
                vuint32_t Y_GREEN:10;
                  vuint32_t:1;
                vuint32_t Y_RED:10;
            } B;
        } LUMA_COMP;                   /* Luminance component Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t CB_RED:12;
                  vuint32_t:4;
                vuint32_t CR_RED:11;
                  vuint32_t:5;
            } B;
        } CHROMA_RED;                  /* Red component Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t CB_GREEN:12;
                  vuint32_t:4;
                vuint32_t CR_GREEN:11;
                  vuint32_t:5;
            } B;
        } CHROMA_GREEN;                /* Green component Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t CB_BLUE:12;
                  vuint32_t:4;
                vuint32_t CR_BLUE:11;
                  vuint32_t:5;
            } B;
        } CHROMA_BLUE;                 /* Blue component Register */

        union {
            vuint32_t R;
            struct {
                vuint32_t CRC_POS:32;
            } B;
        } CRC_POS;                     /* CRC Position Register */

        vuint32_t LYR_INTPOL_EN;
        vuint32_t LYR_LUMA_COMP;

        vuint32_t LYR_CHRM_RED;
        vuint32_t LYR_CHRM_GRN;
        vuint32_t LYR_CHRM_BLUE;

        vuint32_t COMP_IMSIZE;
        vuint32_t UPDATE_MODE;
        vuint32_t UNDERRUN;
        vuint32_t DCU_reserved3[75];
        struct DCU_LAYER_tag LAYER[64];

        vuint32_t DCU0_reserved1[896];

        vuint32_t CLUT[0x4000];        /* CLUT-Pallete memory + Tile memory = 2k * 32bit */
        vuint32_t GAMMARED[0x400];     /* Gamma red table = 256 * 32bit */
        vuint32_t GAMMAGREEN[0x400];   /* Gamma green table = 256 * 32bit */
        vuint32_t GAMMABLUE[0x400];    /* Gamma blue table = 256 * 32bit */
        vuint32_t CURSOR[0x0400];      /* Hardware Cursor = 256 * 32bit */

};                                 /* end of DCU_tag */

struct DMAMUX_tag
{
    union 
	{
        vuint8_t R;
        struct 
		{
            vuint8_t SOURCE:6;
            vuint8_t TRIG:1;
            vuint8_t ENBL:1;
        } B;
    } CHCONFIG[16];                /* DMA Channel Configuration Register */
};                                 /* end of DMAMUX_tag */

struct EDMA_TCD_STD_tag 
{
    vuint32_t SADDR;               /* source address */

    vint16_t SOFF;                 /* signed source address offset */
    vuint16_t DSIZE:3;             /* destination transfer size */
    vuint16_t DMOD:5;              /* destination address modulo */
    vuint16_t SSIZE:3;             /* source transfer size */
    vuint16_t SMOD:5;              /* source address modulo */

    union 
    {
       vuint32_t R;
       struct
       {
          vuint32_t NBYTES:10;
          int32_t   MLOFF:20;
          vuint32_t DMLOE:1;
          vuint32_t SMLOE:1;
        } B;
    }NBYTESu;                     /* Region Descriptor Alternate Access Control n */

    vint32_t SLAST;                /* last destination address adjustment, or
                                      scatter/gather address (if e_sg = 1) */
    vuint32_t DADDR;               /* destination address */

    vint16_t DOFF;                 /* signed destination address offset */
    vuint16_t CITER:15;
    vuint16_t CITERE_LINK:1;

    vint32_t DLAST_SGA;
    

    vuint16_t START:1;             /* explicit channel start */    
    vuint16_t INT_MAJ:1;           /* interrupt on major loop completion */
    vuint16_t INT_HALF:1;          /* interrupt on citer = (biter >> 1) */
    vuint16_t D_REQ:1;             /* disable ipd_req when done */
    vuint16_t E_SG:1;              /* enable scatter/gather descriptor */
    vuint16_t MAJORE_LINK:1;       /* enable channel-to-channel link */
    vuint16_t ACTIVE:1;            /* channel active */
    vuint16_t DONE:1;              /* channel done */
    vuint16_t MAJORLINKCH:6;       /* enable channel-to-channel link */
    vuint16_t BWC:2;               /* bandwidth control */
    vuint16_t BITER:15;
    vuint16_t BITERE_LINK:1;       /* beginning ("major") iteration count */
};                                 /* end of EDMA_TCD_STD_tag */

/*for "channel link" format TCD (when EDMA.TCD[x].CITER.E_LINK==BITER.E_LINK=1)*/
struct EDMA_TCD_CHLINK_tag 
{
    vuint32_t SADDR;               /* source address */
    vuint16_t SMOD:5;              /* source address modulo */
    vuint16_t SSIZE:3;             /* source transfer size */
    vuint16_t DMOD:5;              /* destination address modulo */
    vuint16_t DSIZE:3;             /* destination transfer size */
    vint16_t SOFF;                 /* signed source address offset */

    union
    {
       vuint32_t R;
       struct 
       {
          vuint32_t NBYTES:10;
          int32_t   MLOFF:20;
          vuint32_t DMLOE:1;
          vuint32_t SMLOE:1;
       } B;
    }NBYTESu;                     /* Region Descriptor Alternate Access Control n */
    vint32_t SLAST;                /* last destination address adjustment, or
                                          scatter/gather address (if e_sg = 1) */

    vuint32_t DADDR;               /* destination address */
    vuint16_t CITERE_LINK:1;
    vuint16_t CITERLINKCH:6;
    vuint16_t CITER:9;
    vint16_t DOFF;                 /* signed destination address offset */
    vint32_t DLAST_SGA;
    vuint16_t BITERE_LINK:1;       /* beginning (“major”) iteration count */
    vuint16_t BITERLINKCH:6;
    vuint16_t BITER:9;
    vuint16_t BWC:2;               /* bandwidth control */
    vuint16_t MAJORLINKCH:6;       /* enable channel-to-channel link */
    vuint16_t DONE:1;              /* channel done */
    vuint16_t ACTIVE:1;            /* channel active */
    vuint16_t MAJORE_LINK:1;       /* enable channel-to-channel link */
    vuint16_t E_SG:1;              /* enable scatter/gather descriptor */
    vuint16_t D_REQ:1;             /* disable ipd_req when done */
    vuint16_t INT_HALF:1;          /* interrupt on citer = (biter >> 1) */
    vuint16_t INT_MAJ:1;           /* interrupt on major loop completion */
    vuint16_t START:1;             /* explicit channel start */
};                                 /* end of EDMA_TCD_CHLINK_tag */

struct EDMA_tag 
{
   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t EBW:1;
         vuint32_t EDBG:1;
         vuint32_t ERCA:1;
         vuint32_t ERGA:1;
         vuint32_t HOE:1;
         vuint32_t HALT:1;
         vuint32_t CLM:1;
         vuint32_t EMLM:1;
         vuint32_t GRP0PRI:2;
         vuint32_t GRP1PRI:2;
         vuint32_t GRP2PRI:2;
         vuint32_t GRP3PRI:2;
         vuint32_t ECX:1;
         vuint32_t CX:1;
         vuint32_t:14;
      } B;
   } CR;                          /* Control Register */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t DBE:1;
         vuint32_t SBE:1;
         vuint32_t SGE:1;
         vuint32_t NCE:1;
         vuint32_t DOE:1;
         vuint32_t DAE:1;
         vuint32_t SOE:1;
         vuint32_t SAE:1;
         vuint32_t ERRCHN:6;
         vuint32_t CPE:1;
         vuint32_t GPE:1;
         vuint32_t ECX:1;
         vuint32_t:14;
         vuint32_t VLD:1;
      }B;
   } ES;                          /* Error Status Register */

   int16_t EDMA_reserved1[3];     /* (0x0E - 0x08)/2 = 0x03 */

   union
   {
      vuint16_t R;
      struct
      {
         vuint16_t ERQ00:1;
         vuint16_t ERQ01:1;
         vuint16_t ERQ02:1;
         vuint16_t ERQ03:1;
         vuint16_t ERQ04:1;
         vuint16_t ERQ05:1;
         vuint16_t ERQ06:1;
         vuint16_t ERQ07:1;
         vuint16_t ERQ08:1;
         vuint16_t ERQ09:1;
         vuint16_t ERQ10:1;
         vuint16_t ERQ11:1;
         vuint16_t ERQ12:1;
         vuint16_t ERQ13:1;
         vuint16_t ERQ14:1;
         vuint16_t ERQ15:1;
      }B;
   }ERQL;                        /* DMA Enable Request Low */

   int16_t EDMA_reserved2[3];     /* (0x16 - 0x10)/2 = 0x03 */

   union
   {
      vuint16_t R;
      struct
      {
         vuint16_t EEI00:1;
         vuint16_t EEI01:1;
         vuint16_t EEI02:1;
         vuint16_t EEI03:1;
         vuint16_t EEI04:1;
         vuint16_t EEI05:1;
         vuint16_t EEI06:1;
         vuint16_t EEI07:1;
         vuint16_t EEI08:1;
         vuint16_t EEI09:1;
         vuint16_t EEI10:1;
         vuint16_t EEI11:1;
         vuint16_t EEI12:1;
         vuint16_t EEI13:1;
         vuint16_t EEI14:1;
         vuint16_t EEI15:1;
      }B;
   }EEIL;                        /* DMA Enable Error Interrupt Low */

   union
   {
      vuint8_t R;
      struct
      {
         vuint8_t CEEI:7;
         vuint8_t NOP:1;
      } B;
   }CEEI;                        /* DMA Clear Enable Error Interrupt Register */

   union
   {
      vuint8_t R;
      struct
      {
         vuint8_t SEEI:7;
         vuint8_t NOP:1;
      }B;
   }SEEI;                        /* DMA Set Enable Error Interrupt Register */

   union
   {
       vuint8_t R;
       struct 
       {
          vuint8_t CERQ:7;
          vuint8_t NOP:1;
       }B;
   } CERQ;                        /* DMA Clear Enable Request Register */

   union
   {
       vuint8_t R;
       struct
       {
          vuint8_t SERQ:7;
          vuint8_t NOP:1;
       }B;
   }SERQ;                        /* DMA Set Enable Request Register */


   union
   {
      vuint8_t R;
      struct
      {
         vuint8_t CDNE:7;
         vuint8_t NOP:1;
      } B;
   } CDNE;                        /* Clear Done Status Bit Register */
   union
   {
      vuint8_t R;
      struct
      {
          vuint8_t SSB:7;
          vuint8_t NOP:1;
      } B;
   } SSRT;                        /* Set Start Bit Register */
   union
   {
      vuint8_t R;
      struct
      {
          vuint8_t CER:7;
          vuint8_t NOP:1;
      }B;
   }CERR;                        /* DMA Clear error Register */

   union
   {
      vuint8_t R;
      struct
      {
         vuint8_t CINT:7;
         vuint8_t NOP:1;
      } B;
   } CINT;                        /* DMA Clear Interrupt Request Register */

   int16_t EDMA_reserved3[2];     /* (0x26 - 0x20)/2 = 0x03 */

   union
   {
      vuint32_t R;
      struct
      {
          vuint32_t INT00:1;
          vuint32_t INT01:1;
          vuint32_t INT02:1;
          vuint32_t INT03:1;
          vuint32_t INT04:1;
          vuint32_t INT05:1;
          vuint32_t INT06:1;
          vuint32_t INT07:1;
          vuint32_t INT08:1;
          vuint32_t INT09:1;
          vuint32_t INT10:1;
          vuint32_t INT11:1;
          vuint32_t INT12:1;
          vuint32_t INT13:1;
          vuint32_t INT14:1;
          vuint32_t INT15:1;
          vuint32_t INT16:1;
          vuint32_t INT17:1;
          vuint32_t INT18:1;
          vuint32_t INT19:1;
          vuint32_t INT20:1;
          vuint32_t INT21:1;
          vuint32_t INT22:1;
          vuint32_t INT23:1;
          vuint32_t INT24:1;
          vuint32_t INT25:1;
          vuint32_t INT26:1;
          vuint32_t INT27:1;
          vuint32_t INT28:1;
          vuint32_t INT29:1;
          vuint32_t INT30:1;
          vuint32_t INT31:1;
      }B;
   }INTL;                        /* DMA Interrupt Request Low */

   int16_t EDMA_reserved4[2];     /* (0x2E - 0x28)/2 = 0x03 */

   union
   {
      vuint32_t R;
      struct
      {
         vuint32_t ERR00:1;         
         vuint32_t ERR01:1;
         vuint32_t ERR02:1;
         vuint32_t ERR03:1;
         vuint32_t ERR04:1;
         vuint32_t ERR05:1;
         vuint32_t ERR06:1;
         vuint32_t ERR07:1;
         vuint32_t ERR08:1;
         vuint32_t ERR09:1;
         vuint32_t ERR10:1;
         vuint32_t ERR11:1;
         vuint32_t ERR12:1;
         vuint32_t ERR13:1;
         vuint32_t ERR14:1;
         vuint32_t ERR15:1;
         vuint32_t:16; 
      }B;
   }ERRL;                        /* DMA Error Low */

   int16_t EDMA_reserved5[3];     /* (0x36 - 0x30)/2 = 0x03 */

   union
   {
       vuint16_t R;
       struct
       {
          vuint16_t HRS00:1;
          vuint16_t HRS01:1;
          vuint16_t HRS02:1;
          vuint16_t HRS03:1;
          vuint16_t HRS04:1;
          vuint16_t HRS05:1;
          vuint16_t HRS06:1;
          vuint16_t HRS07:1;
          vuint16_t HRS08:1;
          vuint16_t HRS09:1;
          vuint16_t HRS10:1;
          vuint16_t HRS11:1;
          vuint16_t HRS12:1;
          vuint16_t HRS13:1;
          vuint16_t HRS14:1;
          vuint16_t HRS15:1;
       }B;
   }HRSL;                        /* DMA Hardware Request Status Low */

   uint32_t edma_reserved1[50];   /* (0x100 - 0x038)/4 = 0x32 */
   union
   {
       vuint8_t R;
       struct
       {
           vuint8_t CHPRI:4;
           vuint8_t GRPPRI:2;
           vuint8_t DPA:1;
           vuint8_t ECP:1;
       }B;
   }CPR[32];                     /* Channel n Priority */
   uint32_t edma_reserved2[952];  /* (0x1000 - 0x0110)/4 = 0x3BC */
    /* Select one of the following declarations depending on the DMA mode chosen */
    struct EDMA_TCD_STD_tag TCD[32];
    /* struct EDMA_TCD_CHLINK_tag TCD[16]; */
}; 

#ifdef WIN32
 extern struct DCU_tag    dcu_reg;
 extern struct EDMA_tag   edma_reg;
 extern struct DMAMUX_tag dmamux_reg;
 #define DCU              dcu_reg
 #define EDMA             edma_reg
 #define DMAMUX           dmamux_reg
#else
 #define DCU                  (*(volatile struct DCU_tag    *)0x40058000UL)
 #define TCON                 (*(volatile struct TCON_tag   *)0x4003D000UL)
 #define EDMA                 (*(volatile struct EDMA_tag   *)0x40018000UL)
 #define DMAMUX               (*(volatile struct DMAMUX_tag *)0x40024000UL)
#endif

#define DCU_CLOCK_DIV()      (*(vuint32_t*)0x4006B01C) &= ~(0x07<<16);(*(vuint32_t*)0x4006B01C) |= (0x03<<16)
#define DCU_CLOCK_SEL()      (*(vuint32_t*)0x4006B010) |= (0x01<<28)
#define DCU_CLOCK_ENABLE()   (*(vuint32_t*)0x4006B01C) |= (1<<19) 
#define DCU_CLOCK_DISABLE()  (*(vuint32_t*)0x4006B01C) &= ~(1<<19)

#define RGB_PORT_CONFIG      ((vuint32_t*)(0x40048000 + 0x000001B8))
#define HSYNC_PORT_CONFIG(x) (*(vuint32_t*)(0x40048000 + 0x000001A4)) = x 
#define VSYNC_PORT_CONFIG(x) (*(vuint32_t*)(0x40048000 + 0x000001A8)) =  x
#define PCLK_PORT_CONFIG(x)  (*(vuint32_t*)(0x40048000 + 0x000001AC)) =  x
#define DE_PORT_CONFIG(x)    (*(vuint32_t*)(0x40048000 + 0x000001B4)) =  x

#endif /* GFX_MGR02_FARADAY */

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

#ifdef  __cplusplus
}
#endif

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
 ** CMS Rev #        Date            By
 ** CMS Rev X.X      dd-mmm-yyyy     CDSID
 **
 **============================================================================
 **
 ** CMS Rev 1.0      10-APR-2013     tvijayas
 ** Creation.
 ** This file is added to write the interfaces and logic required to build the 
 ** software platform screens.
**==========================================================================*/


/* end of file =============================================================*/
