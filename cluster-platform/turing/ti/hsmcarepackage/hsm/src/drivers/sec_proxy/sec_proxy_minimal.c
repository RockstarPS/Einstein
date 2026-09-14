/*
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#include<string.h>
#include "sec_proxy_minimal.h"
#include "io_internal.h"
#include "hosts.h"
#include"config.h"


#define SPROXY_THREAD_OFFSET(tid) (0x1000 * (tid))

#define SPROXY_THREAD_DATA_ADDRESS(tid) (HSM_SEC_PROXY_TARGET_ADDRESS + SPROXY_THREAD_OFFSET(tid) + 4)
#define SPROXY_THREAD_DATA_ADDRESS_END(tid) (SPROXY_THREAD_DATA_ADDRESS(tid) + 14 * 4)

#define SPROXY_THREAD_STATUS(tid) (HSM_SEC_PROXY_RT_ADDRESS + SPROXY_THREAD_OFFSET(tid))

#define SPROXY_STATUS_ERR       BIT(31)
#define SPROXY_STATUS_CNT_MASK  0xFF

#define SPROXY_SEND             0
#define SPROXY_GET              1

void delay_1us(void)
{
	
	/* This while-loop takes 2 instructions. Assume M4 runs @333MHz */
	/* counter x = freq (Hz) * 1us / 2 */
	unsigned long x = 333000 / 2000;

	while (x--) {
		asm ("");
	}
}

static u32 spt_map_region(u32 phy_addr)
{
	return ((u32) (phy_addr & 0xFFFFFFFFU)) + 0x60000000U;
}

static s32 trans_message(u8 is_rx, u8 thread_id, void *msg, u32 len)
{
	u32 start_addr = spt_map_region(SPROXY_THREAD_DATA_ADDRESS(thread_id));
	u32 end_addr = spt_map_region(SPROXY_THREAD_DATA_ADDRESS_END(thread_id));
	u32 *raw = (u32 *) msg;
	u32 status;
	u32 word;
	u32 mask;
	u32 i;
	struct tisci_header *hdr;

	hdr = (struct tisci_header *) msg;

	if (start_addr + len > end_addr) {
		return -EINVAL;
	}

	for (i = 0; i < RETRY_CNT_10ms; i += 1) {
		status = readl(SPROXY_THREAD_STATUS(thread_id));
		if (status & SPROXY_STATUS_ERR) {
			return -EFAIL;
		}

		if (status & SPROXY_STATUS_CNT_MASK) {
			break;
		}
		if (i < RETRY_CNT_10ms - 1) {
			delay_1us();
		} else {
			return -110;
		}
	}

	/**
	 * NOTE: The Secure Messaging header is not processed by System Firmware on a GP device.
	 * So the host sending the TISCI request can populate the Secure Messaging Header with zeros.
	 * To maintain API compatiblity between GP and HS devices, all messages sent or received from System Firmware
	 * via a secure transport must include the Secure Messaging Header
	 *
	 * For all the messages via secure threads, the first 4 bytes will be allocated to secure header
	 * For write operation, 0 is written these bytes
	 * incase of read operation we read from start_addr+4 bytes.
	*/
	if (!is_rx) {
		writel(0, start_addr);
		start_addr += 4;
	} else {
		start_addr += 4;
	}

	/**
	  * while sending message from HSM to TIFS set the host id flag to 253
	 */
	if (!is_rx) {
		hdr->host = HOST_ID_HSM;
	}

	for (i = 0; i < len / 4; i++, start_addr += 4) {
		if (is_rx) {
			*raw++ = readl(start_addr);
		} else {
			writel(*raw++, start_addr);
		}
	}

	if (len % 4) {
		if (!is_rx) {
			mask = ~0UL >> ((4 - (len % 4)) * 8);
			word = (*raw) & mask;
			writel(word, start_addr);
		} else {
			word = readl(start_addr);
			/* let memcpy deal with the alignment stuff */
			memcpy(raw, &word, len % 4);
		}
	}

	/* flush out the transfer */
	if (is_rx) {
		(void) readl(end_addr);
	} else {
		writel(0x0, end_addr);
	}

	return 0;
}

s32 sproxy_send_msg(void *msg, u32 len, u32 tx_thread)
{
	return trans_message(SPROXY_SEND, tx_thread, msg, len);
}

s32 sproxy_receive_msg(void *msg, u32 len)
{
	/**
	 * RX thread for HSM is always 0
	 */
	return trans_message(SPROXY_GET, SEC_PROXY_MSG_RX_TID, msg, len);
}
