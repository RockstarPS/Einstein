/*
 * Copyright (c) 2022, BlackBerry Limited. All rights reserved.
 *
 * BlackBerry Limited and its licensors retain all intellectual property and
 * proprietary rights in and to this software and related documentation. Any
 * use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from BlackBerry Limited
 * is strictly prohibited.
 */

#ifndef _I2C_COMMON_H_
#define _I2C_COMMON_H_

#include <hw/inout.h>
#include <hw/i2c.h>

#include "common.h"

int i2c_init(const char *i2c_path);
int i2c_write(int fd, uint8_t dev_addr, uint8_t reg_addr, uint8_t data);
int i2c_read(int fd, uint8_t dev_addr, uint8_t reg_addr, uint8_t *data);

#endif /* _I2C_COMMON_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/i2c-common.h $ $Rev: 964147 $")
#endif
