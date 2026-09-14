/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#ifndef _TCA6424_H_
#define _TCA6424_H_

#include "common.h"

#define TCA6424_I2C_PATH				"/dev/i2c1"
#define TCA6424_I2C_ADDR				0x22

#define TCA6424_CMD_AUTO_INC            0x80

/* Input register */
#define TCA6424_REG_INPUT0              0x00
#define TCA6424_REG_INPUT1              0x01
#define TCA6424_REG_INPUT2              0x02

/* Output register to change state of output BIT set to 1, output set HIGH */
#define TCA6424_REG_OUTPUT0             0x04
#define TCA6424_REG_OUTPUT1             0x05
#define TCA6424_REG_OUTPUT2             0x06

/* Polarity inversion registers to change polarity of output BIT set to 1,
 * polarity is inverted */
#define TCA6424_REG_POLARITY0           0x08
#define TCA6424_REG_POLARITY1           0x09
#define TCA6424_REG_POLARITY2           0x0A

/* Configuration register. BIT = '1' sets port to input, BIT = '0' sets
 * port to output */
#define TCA6424_REG_CONFIG0             0x0C
#define TCA6424_REG_CONFIG1             0x0D
#define TCA6424_REG_CONFIG2             0x0E

#define TCA6424_GPIO_HDMI_RST			(1 << 4)

bool am62x_hdmi_reset(void);

#endif /* _TCA6424_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/tca6424.h $ $Rev: 964147 $")
#endif
