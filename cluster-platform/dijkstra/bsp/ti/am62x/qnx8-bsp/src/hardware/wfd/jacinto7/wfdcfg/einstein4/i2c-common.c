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

/* I2C bus speed (in Hz)*/
#define I2C_BUS_SPEED 100000

int i2c_init(const char *i2c_path)
{

	int fd = open(i2c_path, O_RDWR);
	if (fd == -1) {
		SLOG_ERROR("I2C: could not open device %s (%s)", i2c_path, strerror(errno));
		return -1;
	}

	uint32_t bus_speed = I2C_BUS_SPEED;
	if (devctl(fd, DCMD_I2C_SET_BUS_SPEED, &bus_speed, sizeof(bus_speed), NULL)) {
		SLOG_ERROR("I2C: could not set bus speed to %d, %s: (%s)", bus_speed, i2c_path, strerror(errno));
		close(fd);
		return -1;
	}

	return fd;
}

int i2c_write(int fd, uint8_t dev_addr, uint8_t reg_addr, uint8_t data)
{
	struct send_recv
	{
		i2c_send_t hdr;
		uint8_t buf[2];
	} i2c_msg;

	int err = EOK;

	i2c_msg.buf[0]         = reg_addr;
	i2c_msg.buf[1]         = data;
	i2c_msg.hdr.len        = 2;
	i2c_msg.hdr.slave.addr = dev_addr;
	i2c_msg.hdr.slave.fmt  = I2C_ADDRFMT_7BIT;
	i2c_msg.hdr.stop       = 1;

	int attempts = 0;
	while (attempts < 3) {
		err = devctl(fd, DCMD_I2C_SEND, &i2c_msg, sizeof (i2c_msg), NULL);
		if (err == EOK)  {
			break;
		}
		delay(1);
		attempts++;
	}
	if (attempts >= 3) {
		SLOG_ERROR("I2C: failed to write dev_addr=0x%02X, reg_addr=0x%02X, data=0x%02X (%s)", dev_addr, reg_addr, data, strerror(err));
	}

	return err;
}

int i2c_read(int fd, uint8_t dev_addr, uint8_t reg_addr, uint8_t *data)
{
	struct send_recv
	{
		i2c_sendrecv_t hdr;
		uint8_t buf[1];
	} i2c_msg;

	int bytes;
	int err = EOK;

	i2c_msg.buf[0]         = reg_addr;
	i2c_msg.hdr.send_len   = 1;
	i2c_msg.hdr.recv_len   = 1;
	i2c_msg.hdr.slave.addr = dev_addr;
	i2c_msg.hdr.slave.fmt  = I2C_ADDRFMT_7BIT;
	i2c_msg.hdr.stop       = 1;

	int attempts = 0;
	while (attempts < 3) {
		err = devctl(fd, DCMD_I2C_SENDRECV, &i2c_msg, sizeof (i2c_msg), &bytes);
		if (err == EOK && bytes == 1) {
			break;
		}
		delay(1);
		attempts++;
	}
	if (attempts >= 3) {
		SLOG_ERROR("I2C: failed to read dev_addr=0x%02X, reg_addr=0x%02X, bytes=%d (%s)", dev_addr, reg_addr, bytes, strerror(err));
	} else {
		*data = i2c_msg.buf[0];
	}

	return err;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/graphics/branches/release-3.x.x/hardware/wfd/jacinto7/wfdcfg/am62x-evm/i2c-common.c $ $Rev: 964147 $")
#endif
