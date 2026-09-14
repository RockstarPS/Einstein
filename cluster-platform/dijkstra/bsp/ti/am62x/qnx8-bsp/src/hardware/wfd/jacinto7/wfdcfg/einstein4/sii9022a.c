/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#include "i2c-common.h"
#include "sii9022a.h"

#define CHK(condition,...)	if ((condition) != EOK){ goto err;}

// Left here for future investigation JI:2922423
#if 0
static uint8_t hdmi_infoframe_checksum(const uint8_t *ptr, size_t size)
{
	uint8_t csum = 0;
	size_t i;

	/* compute checksum */
	for (i = 0; i < size; i++) {
		csum += ptr[i];
	}

	return 256 - csum;
}

static void hdmi_infoframe_set_checksum(void *buffer, size_t size)
{
	uint8_t *ptr = buffer;

	ptr[3] = hdmi_infoframe_checksum(buffer, size);
}

bool set_avi_info_frame(int fd)
{
	#define BIT(x) (1 << (x));

	#define HDMI_INFOFRAME_HEADER_SIZE  4
	#define HDMI_AVI_INFOFRAME_SIZE    13
	#define HDMI_INFOFRAME_SIZE (HDMI_INFOFRAME_HEADER_SIZE + HDMI_AVI_INFOFRAME_SIZE)

	enum hdmi_infoframe_type {
		HDMI_INFOFRAME_TYPE_VENDOR = 0x81,
		HDMI_INFOFRAME_TYPE_AVI    = 0x82,
		HDMI_INFOFRAME_TYPE_SPD    = 0x83,
		HDMI_INFOFRAME_TYPE_AUDIO  = 0x84,
		HDMI_INFOFRAME_TYPE_DRM    = 0x87,
	};

	enum hdmi_colorspace {
		HDMI_COLORSPACE_RGB,
		HDMI_COLORSPACE_YUV422,
		HDMI_COLORSPACE_YUV444,
		HDMI_COLORSPACE_YUV420,
		HDMI_COLORSPACE_RESERVED4,
		HDMI_COLORSPACE_RESERVED5,
		HDMI_COLORSPACE_RESERVED6,
		HDMI_COLORSPACE_IDO_DEFINED,
	};

	enum hdmi_scan_mode {
		HDMI_SCAN_MODE_NONE,
		HDMI_SCAN_MODE_OVERSCAN,
		HDMI_SCAN_MODE_UNDERSCAN,
		HDMI_SCAN_MODE_RESERVED,
	};

	enum hdmi_colorimetry {
		HDMI_COLORIMETRY_NONE,
		HDMI_COLORIMETRY_ITU_601,
		HDMI_COLORIMETRY_ITU_709,
		HDMI_COLORIMETRY_EXTENDED,
	};

	enum hdmi_picture_aspect {
		HDMI_PICTURE_ASPECT_NONE,
		HDMI_PICTURE_ASPECT_4_3,
		HDMI_PICTURE_ASPECT_16_9,
		HDMI_PICTURE_ASPECT_64_27,
		HDMI_PICTURE_ASPECT_256_135,
		HDMI_PICTURE_ASPECT_RESERVED,
	};

	enum hdmi_active_aspect {
		HDMI_ACTIVE_ASPECT_16_9_TOP = 2,
		HDMI_ACTIVE_ASPECT_14_9_TOP = 3,
		HDMI_ACTIVE_ASPECT_16_9_CENTER = 4,
		HDMI_ACTIVE_ASPECT_PICTURE = 8,
		HDMI_ACTIVE_ASPECT_4_3 = 9,
		HDMI_ACTIVE_ASPECT_16_9 = 10,
		HDMI_ACTIVE_ASPECT_14_9 = 11,
		HDMI_ACTIVE_ASPECT_4_3_SP_14_9 = 13,
		HDMI_ACTIVE_ASPECT_16_9_SP_14_9 = 14,
		HDMI_ACTIVE_ASPECT_16_9_SP_4_3 = 15,
	};

	const uint8_t length = HDMI_INFOFRAME_SIZE;
	uint8_t type = HDMI_INFOFRAME_TYPE_AVI;
	uint8_t colorspace = HDMI_COLORSPACE_RGB;
	uint8_t scan_mode = HDMI_SCAN_MODE_UNDERSCAN;
	uint8_t colorimetry = HDMI_COLORIMETRY_NONE;
	uint8_t picture_aspect = HDMI_PICTURE_ASPECT_NONE;
	uint8_t active_aspect = HDMI_ACTIVE_ASPECT_PICTURE;

	uint8_t buffer[length];
	uint8_t *ptr = buffer;

	ptr[0] = type;
	ptr[1] = 0x02; //version
	ptr[2] = HDMI_AVI_INFOFRAME_SIZE;
	ptr[3] = 0x00; //checksum

	/* start infoframe payload */
	ptr += HDMI_INFOFRAME_HEADER_SIZE;
	ptr[0] = ((colorspace & 0x3) << 5) | (scan_mode & 0x3);

	/* Data byte 1, bit 4 has to be set if we provide the active format aspect ratio */
	if (active_aspect & 0xf) {
		ptr[0] |= BIT(4);
	}

	ptr[1] = ((colorimetry & 0x3) << 6) | ((picture_aspect & 0x3) << 4) | (active_aspect & 0xf);
	ptr[2] = 0x00;
	ptr[3] = 0x00;
	ptr[4] = 0x00;
	ptr[5] = 0x00;
	ptr[6] = 0x00;
	ptr[7] = 0x00;
	ptr[8] = 0x00;
	ptr[9] = 0x00;
	ptr[10] = 0x00;
	ptr[11] = 0x00;
	ptr[12] = 0x00;

	hdmi_infoframe_set_checksum(buffer, length);

	//Setup AVI Infoframe (13 bytes) + CRC
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x0C, buffer[3]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x0D, buffer[4]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x0E, buffer[5]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x0F, buffer[6]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x10, buffer[7]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x11, buffer[8]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x12, buffer[9]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x13, buffer[10]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x14, buffer[11]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x15, buffer[12]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x16, buffer[13]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x17, buffer[14]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x18, buffer[15]));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, 0x19, buffer[16]));

	return true;

err:
	SLOG_INFO("[SiI9022A] setting registers failed.");
	return false;
}
#endif

// Left here for debugging
#if 0
bool get_sii9022a_regs_dump(int fd)
{
	int i, j;
	uint8_t val = 0;
	uint16_t reg = 0;

	for (i = 0; i <= 0xf0; i = i + 0x10) {
		for (j = 0; j <= 0xf; j++) {
			reg = i | j;
			CHK(i2c_read(fd, SII9022A_I2C_ADDR, reg, &val));
			SLOG_DEBUG("reg[0x%02X]=0x%02X", reg, val);
		}
	}

	return true;

err:
	SLOG_INFO("[SiI9022A] getting registers dump failed.");
	return false;
}
#endif

int am62x_hdmi_init(const struct wfdcfg_timing* timings)
{
	SLOG_INFO("[SiI9022A] starting HDMI transmitter configuration.");

	int fd = i2c_init(SII9022A_I2C_PATH);
	if (fd == -1) {
		SLOG_ERROR("[SiI9022A] i2c_init() failed");
		return 1;
	}

	uint8_t val = 0;

	/* Enable TPI transmitter mode */
	//NOTE: For TPI operation, always write register offset 0xC7 = 0x00 as the first step after hardware reset.
	val = SII902X_TPI_TRANS_MODE_ENABLE;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_TRANS_MODE_REG, val));

	/* Waiting when the TMDS clock will become stable */
	{
		int attempts = 0;

		CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SET_PAGE_REG, SII902X_TPI_SET_PAGE0));
		CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SET_OFFSET_REG, SII902X_TPI_TMDS_CLOCK_STATUS_REG));
		do {
			/* Monitor TCLK STABLE interrupt bit 1 of indexed register 0x72. */
			CHK(i2c_read(fd, SII9022A_I2C_ADDR, SII902X_TPI_RW_ACCESS_REG, &val));
			delay(1);
			attempts++;
		} while (!(val & SII902X_TPI_TMDS_TCLK_IS_STABLE) && (attempts <= 5));

		if (attempts > 5) {
			SLOG_ERROR("[SiI9022A] TMDS clock is still unstable after resset!");
			goto err;
		} else {
			/* Clear the clock change indicator */
			val = SII902X_TPI_TMDS_TCLK_IS_STABLE;
			CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_RW_ACCESS_REG, val));
		}
	}

	/* Check chip ID */
	//NOTE: When TPI 0x1B can be read correctly, the TPI subsystem is ready.
	CHK(i2c_read(fd, SII9022A_I2C_ADDR, SII902X_CHIPID_REG(0), &val));
	if (val != 0xB0) {
		SLOG_ERROR("[SiI9022A] invalid chip id: %02x (expecting 0xB0)", val);
		goto err;
	}

	/* Clear all pending interrupts */
	CHK(i2c_read(fd, SII9022A_I2C_ADDR, SII902X_INT_STATUS_REG, &val));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_INT_STATUS_REG, val));

	/* Power up transmitter, enter into D0 state, full operation */
	CHK(i2c_read(fd, SII9022A_I2C_ADDR, SII902X_TPI_PWR_STATE_REG, &val));
	val &= ~SII902X_TPI_PWR_STATE_MASK;
	val |= SII902X_TPI_PWR_STATE_D(0);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_PWR_STATE_REG, val));

	/* Enable source termination */
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SET_PAGE_REG, SII902X_TPI_SET_PAGE0));
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SET_OFFSET_REG, SII902X_TPI_SRC_TERMINATION_REG));
	CHK(i2c_read(fd, SII9022A_I2C_ADDR, SII902X_TPI_RW_ACCESS_REG, &val));
	val |= SII902X_TPI_RW_EN_SRC_TERMIN;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_RW_ACCESS_REG, val));

	/* Set TPI system control */
	//Write TPI 0x1A[4]=1 to start the resolution change process.
	uint8_t sys_ctrl_reg = SII902X_TPI_SYS_TMDS_OUTPUT_OFF | SII902X_TPI_SYS_AV_MUTE | SII902X_TPI_SYS_HDMI_MODE;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SYS_CTRL_REG, sys_ctrl_reg)); /*Output Mode = HDMI, TMDS Off */

	// The datasheet says to wait at least 128ms to allow control InfoFrames to pass through to the sink device.
	delay(150); //Make it 150ms to be sure.

	/* Set pixel clock */
	uint16_t pixel_clock = timings->pixel_clock_kHz / 10;
	val = (uint8_t)(pixel_clock & 0xFF);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_PIXEL_CLK_LSB_REG, val));
	val = (uint8_t)(pixel_clock >> 8);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_PIXEL_CLK_MSB_REG, val));

	/* Set pixels per line */
	val = (uint8_t)(timings->hpixels & 0xFF);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TOTAL_PIXELS_LSB_REG, val));
	val = (uint8_t)(timings->hpixels >> 8);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TOTAL_PIXELS_MSB_REG, val));
	uint16_t total_pixels = timings->hpixels + timings->hfp + timings->hsw + timings->hbp;

	/* Set lines */
	val = (uint8_t)(timings->vlines & 0xFF);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TOTAL_LINES_LSB_REG, val));
	val = (uint8_t)(timings->vlines >> 8);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TOTAL_LINES_MSB_REG, val));
	uint16_t total_lines = timings->vlines + timings->vfp + timings->vsw + timings->vbp;

	/* Set vertical frequency in Hz */
	uint16_t refresh_rate = (timings->pixel_clock_kHz * 1000) / (total_pixels * total_lines);
	val = (uint8_t)(refresh_rate & 0xFF);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_VERT_FREQ_LSB_REG, val));
	val = (uint8_t)(refresh_rate >> 8);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_VERT_FREQ_MSB_REG, val));

	SLOG_INFO("[SiI9022A] graphics mode %dx%d@%d [htotal:%d, vtotal:%d, pclk:%dKHz]",
		timings->hpixels, timings->vlines, refresh_rate, total_pixels, total_lines, timings->pixel_clock_kHz);

// Left here for future investigation JI:
#if 0
	/* TPI: Set AVI InfoFrame */
	if (!set_avi_info_frame(fd)) {
		goto err;
	}
#endif

	/* Set TPI AVI Input format data */
	val = SII902X_TPI_INPUT_BITMODE_8BIT | SII902X_TPI_INPUT_RANGE_AUTO | SII902X_TPI_INPUT_COLORSPACE_RGB;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_INPUT_FMT_REG, val)); /* Input is RGB */

	/* Set TPI AVI Output format data */
	val = SII902X_TPI_OUTPUT_BITMODE_8BIT | SII902X_TPI_OUTPUT_RANGE_AUTO | SII902X_TPI_OUTPUT_COLORSPACE_RGB;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_OUTPUT_FMT_REG, val)); /* Output is RGB */

	/* Disable audio */
	val = SII902X_TPI_AUDIO_MUTE_ENABLE | SII902X_TPI_AUDIO_INTERFACE_DISABLE;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_AUDIO_INTF_REG, val)); /* Audio disabled */
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_MISC_INFOFRAME_BASE, 0x02)); /* Disable Sending of Audio-Infoframe */

	/* Set TPI system control */
	sys_ctrl_reg &= ~(SII902X_TPI_SYS_TMDS_OUTPUT_OFF | SII902X_TPI_SYS_AV_MUTE);
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_SYS_CTRL_REG, sys_ctrl_reg)); /* TMDS On */

	/* Configure TPI input bus and pixel repetition data */
	//NOTE: This setting must always be made after changing TPI 0x1A[4] from 1 to 0.
	val = SII902X_TPI_INBUS_CLK_RATIO_1X | SII902X_TPI_INBUS_FULL_PIXEL_WIDE;
	CHK(i2c_write(fd, SII9022A_I2C_ADDR, SII902X_TPI_INBUS_FMT_REG, val)); /* 24-bit input, TMDS Clock = Input Clock */

	SLOG_INFO("[SiI9022A] HDMI transmitter configuration finished.");

// Left here for debugging
#if 0
	get_sii9022a_regs_dump(fd);
#endif

	close(fd);
	return 0;

err:
	SLOG_ERROR("[SiI9022A] HDMI transmitter configuration failed.");

	close(fd);
	return 1;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/sii9022a.c $ $Rev: 964147 $")
#endif
