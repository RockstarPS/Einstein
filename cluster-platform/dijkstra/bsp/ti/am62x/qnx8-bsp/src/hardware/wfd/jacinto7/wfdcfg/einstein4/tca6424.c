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

#include "tca6424.h"
#include <time.h>

/* Busy-wait without thread blocking for a period of time (in microseconds) */
static void uspin(unsigned long us)
{
#define USEC_TO_NS(x) (UINT64_C(1000) * (x))
	struct timespec to;
	nsec2timespec(&to, USEC_TO_NS(us));

	errno_t err = nanospin(&to);
	if (err) {
		SLOG_ERROR("nanospin() failed : %s", strerror(err));
	}
#undef USEC_TO_NS
}

#define CHK(condition,...)	if ((condition) != EOK){ goto err;}

bool am62x_hdmi_reset(void)
{
	int fd = i2c_init(TCA6424_I2C_PATH);
	if (fd == -1) {
		SLOG_ERROR("[TCA6424] i2c_init() failed");
		return 1;
	}

	uint8_t val = 0;

	//GPIO_HDMI_RST is connected on port 1, 4 bit. Configure it as an output
	CHK(i2c_read(fd, TCA6424_I2C_ADDR, TCA6424_REG_CONFIG1, &val));
	val &= ~TCA6424_GPIO_HDMI_RST;
	CHK(i2c_write(fd, TCA6424_I2C_ADDR, TCA6424_REG_CONFIG1, val));

	//Active state - "LOW"
	CHK(i2c_read(fd, TCA6424_I2C_ADDR, TCA6424_REG_OUTPUT1, &val));
	val &= ~TCA6424_GPIO_HDMI_RST;
	CHK(i2c_write(fd, TCA6424_I2C_ADDR, TCA6424_REG_OUTPUT1, val));

	/* The datasheet says Treset-min = 100us. */
	uspin(150); //Make it 150us to be sure.

	//Default state - "HIGH"
	CHK(i2c_read(fd, TCA6424_I2C_ADDR, TCA6424_REG_OUTPUT1, &val));
	val |= TCA6424_GPIO_HDMI_RST;
	CHK(i2c_write(fd, TCA6424_I2C_ADDR, TCA6424_REG_OUTPUT1, val));

	SLOG_INFO("[TCA6424] HDMI transmitter reset completed.");

	close(fd);
	return true;

err:
	SLOG_ERROR("[TCA6424] HDMI transmitter reset failed.");

	close(fd);
	return false;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/tca6424.c $ $Rev: 964147 $")
#endif
