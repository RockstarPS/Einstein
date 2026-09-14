/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#ifndef _SII9022A_H_
#define _SII9022A_H_

#include "common.h"

#define SII9022A_I2C_PATH						"/dev/i2c1"
#define SII9022A_I2C_ADDR						0x3B

#define SII902X_PIXEL_CLK_LSB_REG				0x00
#define SII902X_PIXEL_CLK_MSB_REG				0x01
#define SII902X_VERT_FREQ_LSB_REG				0x02
#define SII902X_VERT_FREQ_MSB_REG				0x03
#define SII902X_TOTAL_PIXELS_LSB_REG			0x04
#define SII902X_TOTAL_PIXELS_MSB_REG			0x05
#define SII902X_TOTAL_LINES_LSB_REG				0x06
#define SII902X_TOTAL_LINES_MSB_REG				0x07

#define SII902X_TPI_INBUS_FMT_REG				0x08
#define SII902X_TPI_INBUS_CLK_RATIO_HALF		(0 << 6)
#define SII902X_TPI_INBUS_CLK_RATIO_1X			(1 << 6)
#define SII902X_TPI_INBUS_CLK_RATIO_2X			(2 << 6)
#define SII902X_TPI_INBUS_CLK_RATIO_4X			(3 << 6)
#define SII902X_TPI_INBUS_FULL_PIXEL_WIDE		(1 << 5)
#define SII902X_TPI_INBUS_RISING_EDGE			(1 << 4)

#define SII902X_TPI_INPUT_FMT_REG				0x09
#define SII902X_TPI_INPUT_BITMODE_12BIT			(1 << 7)
#define SII902X_TPI_INPUT_DITHER				(1 << 6)
#define SII902X_TPI_INPUT_BITMODE_8BIT			(0 << 6)
#define SII902X_TPI_INPUT_RANGE_LIMITED			(2 << 2)
#define SII902X_TPI_INPUT_RANGE_FULL			(1 << 2)
#define SII902X_TPI_INPUT_RANGE_AUTO			(0 << 2)
#define SII902X_TPI_INPUT_COLORSPACE_BLACK		(3 << 0)
#define SII902X_TPI_INPUT_COLORSPACE_YUV422		(2 << 0)
#define SII902X_TPI_INPUT_COLORSPACE_YUV444		(1 << 0)
#define SII902X_TPI_INPUT_COLORSPACE_RGB		(0 << 0)

#define SII902X_TPI_OUTPUT_FMT_REG				0x0A
#define SII902X_TPI_OUTPUT_BITMODE_8BIT			(0 << 6)
#define SII902X_TPI_OUTPUT_RANGE_AUTO			(0 << 2)
#define SII902X_TPI_OUTPUT_COLORSPACE_RGB		(0 << 0)

#define SII902X_TPI_SYS_CTRL_REG				0x1A
#define SII902X_TPI_SYS_TMDS_OUTPUT_ON			(0 << 4)
#define SII902X_TPI_SYS_TMDS_OUTPUT_OFF			(1 << 4)
#define SII902X_TPI_SYS_AV_NORAML				(0 << 3)
#define SII902X_TPI_SYS_AV_MUTE					(1 << 3)
#define SII902X_TPI_SYS_DVI_MODE				(0 << 0)
#define SII902X_TPI_SYS_HDMI_MODE				(1 << 0)

#define SII902X_CHIPID_REG(n)					(0x1B + (n))

#define SII902X_TPI_PWR_STATE_REG				0x1E
#define SII902X_TPI_PWR_STATE_MASK				(0x03)
#define SII902X_TPI_PWR_STATE_D(l)				((l) & SII902X_TPI_PWR_STATE_MASK)

#define SII902X_TPI_AUDIO_HANDING_REG			0x25

#define SII902X_TPI_AUDIO_INTF_REG				0x26
#define SII902X_TPI_AUDIO_CODING_STREAM_HEADER	(0 << 0)
#define SII902X_TPI_AUDIO_CODING_PCM			(1 << 0)
#define SII902X_TPI_AUDIO_CODING_AC3			(2 << 0)
#define SII902X_TPI_AUDIO_CODING_MPEG1			(3 << 0)
#define SII902X_TPI_AUDIO_CODING_MP3			(4 << 0)
#define SII902X_TPI_AUDIO_CODING_MPEG2			(5 << 0)
#define SII902X_TPI_AUDIO_CODING_AAC			(6 << 0)
#define SII902X_TPI_AUDIO_CODING_DTS			(7 << 0)
#define SII902X_TPI_AUDIO_CODING_ATRAC			(8 << 0)
#define SII902X_TPI_AUDIO_MUTE_DISABLE			(0 << 4)
#define SII902X_TPI_AUDIO_MUTE_ENABLE			(1 << 4)
#define SII902X_TPI_AUDIO_LAYOUT_2_CHANNELS		(0 << 5)
#define SII902X_TPI_AUDIO_LAYOUT_8_CHANNELS		(1 << 5)
#define SII902X_TPI_AUDIO_INTERFACE_DISABLE		(0 << 6)
#define SII902X_TPI_AUDIO_INTERFACE_SPDIF		(1 << 6)
#define SII902X_TPI_AUDIO_INTERFACE_I2S			(2 << 6)

#define SII902X_TPI_AUDIO_FREQ_REG				0x27

#define SII902X_INT_STATUS_REG					0x3D

#define SII902X_TPI_SET_PAGE_REG				0xBC
#define SII902X_TPI_SET_PAGE0					(0x01)
#define SII902X_TPI_SET_PAGE1					(0x02)

#define SII902X_TPI_SET_OFFSET_REG				0xBD

#define SII902X_TPI_RW_ACCESS_REG				0xBE

#define SII902X_TPI_MISC_INFOFRAME_BASE			0xBF

#define SII902X_TPI_TRANS_MODE_REG				0xC7
#define SII902X_TPI_TRANS_MODE_ENABLE			(0 << 7)

/* Indexed registers, access through 0XBC, 0XBD, 0XBE */
#define SII902X_TPI_TMDS_CLOCK_STATUS_REG		0x72
#define SII902X_TPI_TMDS_TCLK_IS_STABLE			(1 << 1)

#define SII902X_TPI_SRC_TERMINATION_REG			0x82
#define SII902X_TPI_RW_EN_SRC_TERMIN			(1 << 0)

int am62x_hdmi_init(const struct wfdcfg_timing* timings);

#endif /* _SII9022A_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/sii9022a.h $ $Rev: 964147 $")
#endif
