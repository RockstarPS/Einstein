/*
 * $QNXLicenseC:
 * Copyright 2019, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#ifndef HDRINCL_WFDCFG_J7
#define HDRINCL_WFDCFG_J7

#include <stdint.h>
#include <wfdqnx/wfdcfg.h>

/** Currently the pixel clock frequency is set by startup. This exention specifies the pixel clock
 * frequency startup has set in kilohertz.  This is a port extension.
 *   .p must be NULL
 *   .i give the pixel clock speed in kilohertz.
 */
#define WFDCFG_EXT_PIXEL_CLOCK_KHZ "pixel_clock_khz"

#define DPI_NO_CONNECTION	0
#define DPI_VP1_CONNECTION	1
#define DPI_VP2_CONNECTION	2
#define DPI_VP3_CONNECTION	4
#define DPI_VP4_CONNECTION	8

#define WFDCFG_EXT_DPI0_CONNECTION "dpi0_connection"
/* Define the VP connected to DPI-0 output (default VP2)
 * This is a device extension
 *   .p must be NULL
 *   .i specify DPI_### connection defined above
 */

#define WFDCFG_EXT_DPI1_CONNECTION "dpi1_connection"
/* Define the VP connected to DPI-1 output (default NC)
 * This is a device extension
 *   .p must be NULL
 *   .i specify DPI_### connection defined above
 */

#define WFDCFG_EXT_DISPLAY_PORT_ID "display_port_id"
/* Define a port ID that will output display port (default 0 - no DP)
 * This is a device extension
 *   .p must be NULL
 *   .i specify WFD port ID (default 0 to disable display port)
 */

/* TDM Configuration definitions */
/* DssVpTdmUnusedBitsLevel - State of unused bits in TDM mode for the VP output */
#define DSS_VP_TDM_UNUSED_BITS_LEVEL_LOW       0 /* Low level */
#define DSS_VP_TDM_UNUSED_BITS_LEVEL_HIGH      1 /* High level */
#define DSS_VP_TDM_UNUSED_BITS_LEVEL_UNCHANGED 2 /* Unchanged level */

/* DssVpTdmCycleFormat - TDM Cycle format */
#define DSS_VP_TDM_CYCLE_1PERPIXEL        0 /* 1 cycle per pixel */
#define DSS_VP_TDM_CYCLE_2PERPIXEL        1 /* 2 cycles per pixel */
#define DSS_VP_TDM_CYCLE_3PERPIXEL        2 /* 3 cycles per pixel */
#define DSS_VP_TDM_CYCLE_3PER2PIXEL       3 /* 3 cycles per 2 pixels */

/* DssVpTdmParallelMode - Output interface width in TDM mode */
#define DSS_VP_TDM_PARALLEL_OUTPUT_8BIT          0 /* 8-bit parallel output interface selected */
#define DSS_VP_TDM_PARALLEL_OUTPUT_9BIT          1 /* 9-bit parallel output interface selected */
#define DSS_VP_TDM_PARALLEL_OUTPUT_12BIT         2 /* 12-bit parallel output interface selected */
#define DSS_VP_TDM_PARALLEL_OUTPUT_16BIT         3 /* 16-bit parallel output interface selected */

/* LCD Configuration for Time Division Multiplexing */
typedef struct
{
    uint32_t tdmEnable; /* Enable the multiple cycle format for the VP output *   FALSE: Disable TDM *   TRUE:  Enable TDM */
    uint32_t tdmUnusedBitsLevel; /* State of unused bits (TDM mode only) for the VP output. */
    uint32_t tdmCycleFormat; /* Cycle format (TDM mode only) for the VP output. */
    uint32_t tdmParallelMode; /* Output interface width (TDM mode only) for the VP output. */
    uint32_t numBitsPixel1Cycle0; /* Number of bits from the pixel 1 for cycle 0(value from 0 to 16 bits). The values from 17 to 31 are invalid */
    uint32_t numBitsPixel1Cycle1; /* Number of bits from the pixel 1 for cycle 1(value from 0 to 16 bits). The values from 17 to 31 are invalid */
    uint32_t numBitsPixel1Cycle2; /* Number of bits from the pixel 1 for cycle 2(value from 0 to 16 bits). The values from 17 to 31 are invalid */
    uint32_t bitAlignPixel1Cycle0; /* Alignment of the bits from pixel 1 for cycle0 on the output interface */
    uint32_t bitAlignPixel1Cycle1; /* Alignment of the bits from pixel 1 for cycle1 on the output interface */
    uint32_t bitAlignPixel1Cycle2; /* Alignment of the bits from pixel 1 for cycle2 on the output interface */
    uint32_t numBitsPixel2Cycle0; /* Number of bits from the pixel 2 for cycle 0(value from 0 to 16 bits).  The values from 17 to 31 are invalid */
    uint32_t numBitsPixel2Cycle1; /* Number of bits from the pixel 2 for cycle 1(value from 0 to 16 bits). The values from 17 to 31 are invalid */
    uint32_t numBitsPixel2Cycle2; /* Number of bits from the pixel 2 for cycle 2(value from 0 to 16 bits). The values from 17 to 31 are invalid */
    uint32_t bitAlignPixel2Cycle0; /* Alignment of the bits from pixel 2 for cycle 0 on the output interface */
    uint32_t bitAlignPixel2Cycle1; /* Alignment of the bits from pixel 2 for cycle 1 on the output interface */
    uint32_t bitAlignPixel2Cycle2; /* Alignment of the bits from pixel 2 for cycle 2 on the output interface */
} vp_tdm_cfg_t;

/* Timing configuration defintions */
/* Video Interface Width - Output aligned on the LSB of the pixel data interface */
#define DATA_WIDTH_12_BIT	0
#define DATA_WIDTH_16_BIT	1
#define DATA_WIDTH_19_BIT	2
#define DATA_WIDTH_24_BIT	3
#define DATA_WIDTH_30_BIT	4
#define DATA_WIDTH_36_BIT	5

/* options for cscRange */
#define DSS_CSC_RANGE_LIMITED                   ((uint32_t) 0x0U)
#define DSS_CSC_RANGE_FULL                      ((uint32_t) 0x1U)

/* options for Digital output format - dvoFormat */
#define DVO_BT656_EMBSYNC                 ((uint32_t) 0x00U) /* Video format is BT656 with embedded sync */
#define DVO_BT1120_EMBSYNC                ((uint32_t) 0x01U) /* Video format is BT1120 with embedded sync */
#define DVO_GENERIC_DISCSYNC              ((uint32_t) 0x02U) /* Video format is for any discrete sync */

/* options for deltaLinesPerPixel */
#define DELTA_LPP_SAME	0	/* odd field and even field are same size */
#define DELTA_LPP_ODD_SIZE_BIGGER	/* odd size is even size + 1 */
#define DELTA_LPP_ODD_SIZE_SMALLER	/* odd size is even size - 1 */

typedef struct
{
    struct wfdcfg_timing wfd_timing; /* video timing parameters - see wfdcfg.h for details */
    uint32_t dvoFormat; /* Digital output format */
    uint32_t cscRange;	/* CSC Range */
    uint32_t videoIfWidth; /* Video interface Width */
    uint32_t deltaLinesPerPanel; /* Delta size of the odd field compared to the even field */
} vp_timing_cfg_t;

enum {
        J7_VP1_IDX = 0,
        J7_VP2_IDX,
        J7_VP3_IDX,
        J7_VP4_IDX,
	J7_NUMBER_VP
};

/* Structure containing Video Port (VP) information */
typedef struct
{
    uint32_t vpIdx; /* Video Port Id */
    vp_timing_cfg_t timingCfg; /* Timing configuration for the LCD output. */
    vp_tdm_cfg_t tdmCfg; /* LCD TDM Configuration */
} vp_params_t;

/*
 * VP parameters - This is a device extension
 *  .p is a pointer to a structure of vp_params_t
 *  .i is not used
 */
#define WFDCFG_EXT_VP1_PARAMS "vp1_params"
#define WFDCFG_EXT_VP2_PARAMS "vp2_params"
#define WFDCFG_EXT_VP3_PARAMS "vp3_params"
#define WFDCFG_EXT_VP4_PARAMS "vp4_params"

#define CSITX_FORMAT_RGB888	1
#define CSITX_FORMAT_UYVY	2
/* This exention specifies the pixel format that CSI-TX module should output
 * using data frames from DSS writeback pipeline.
 * There can only be one instance of CSI-TX so this is a device extension.
 *   .p must be NULL
 *   .i specify the pixel format
 *   Support formats are:
 *   CSITX_FORMAT_RGB888
 *   CSITX_FORMAT_UYVY
 */
#define WFDCFG_EXT_CSITX_FORMAT "csitx_format"

#define DSS_WB_FORMAT_ARGB32_8888	0x7
#define DSS_WB_FORMAT_ABGR32_8888	0x8
#define DSS_WB_FORMAT_RGBA32_8888	0x9
#define DSS_WB_FORMAT_BGRA32_8888	0xA
#define DSS_WB_FORMAT_XRGB8888		0x27 // default for CSITX_FORMAT_RGB888
#define DSS_WB_FORMAT_XBGR8888		0x28
#define DSS_WB_FORMAT_RGBX8888		0x29
#define DSS_WB_FORMAT_BGRX8888		0x2A
#define DSS_FORMAT_YUV422_YUV2		0x3E
#define DSS_FORMAT_YUV422_UYVY		0x3F // default for CSI_TX_FORMAT_UYVY

/* This exention specifies the pixel format that DSS writeback pipeline will write
 * data frames to memory.
 * There can only be one instance of CSI-TX so this is a device extension.
 *   .p must be NULL
 *   .i specify one the pixel formats defined above
 */
#define WFDCFG_EXT_CSITX_WB_FORMAT "csitx_wb_format"

/*
 * External warm reset.
 * This extension function is used with BT601 output to perform warm reset
 * of the DSS to synchronize the multiple VP units used for BT601 output
 *  .p is a pointer to a function of type wfdcfg_ext_fn_bt601_reset
 *  .i must be zero
 */
#define WFDCFG_EXT_FN_BT601_RESET "bt601_reset"
typedef int (wfdcfg_ext_fn_bt601_reset_t)(struct wfdcfg_port*);

/** This exention specifies if there is an LVDS hw attached.
 *   .p must be NULL
 *   .i give 0(default, no HW attached), 1 (hw attached)
 */
#define WFDCFG_EXT_LVDS_HW_ATTACH "lvds_hw_attach"

/** This exention specifies the type of LVDS used.
 *   .p must be NULL
 *   .i defines: type[A-F] where A=0, B=1, .., F=5
 */
#define WFDCFG_EXT_LVDS_CONFIG_MAP_TYPE "lvds_config_map_type"

/** This exention specifies the lvds dualmoode sync.
 *   .p must be NULL
 *   .i defines: 1: enable, 0: disable
 */
#define WFDCFG_EXT_LVDS_DUALMODE_SYNC "lvds_dualmode_sync"

#endif // HDRINCL_WFDCFG_J7

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/public/wfdqnx/wfdcfg_jacinto7.h $ $Rev: 997578 $")
#endif
