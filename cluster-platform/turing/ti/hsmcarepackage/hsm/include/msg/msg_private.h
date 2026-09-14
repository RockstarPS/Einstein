/*
 * System Firmware OSAL Messaging layer
 *
 * OSAL Core Messaging layer internal APIs
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_MSG_PRIVATE_H
#define OSAL_MSG_PRIVATE_H

#include <types/short_types.h>

/**
 * \brief Message forwarding info
 *
 * \param msg pointer to forward message
 *
 * \param msg_fwd Flag to forward message to another service provider
 *
 * \param msg_local Flag to process message locally
 *
 * \param msg_local Flag to indicate message was from a forward response
 *
 * \param req_msg_size Size of TISCI message
 *
 * \param resp_msg_size Size of TISCI message response
 */
struct msg_fwd_info {
	u32	*msg;
	u8	hw_host;
	sbool	msg_fwd;
	sbool	msg_local;
	sbool	msg_resp;
	u32	req_msg_size;
	u32	resp_msg_size;
};

/**
 * \struct msg_data
 * \brief Contains data about the message needed to idetify the sender and
 *	  route the message response back to the proper location.
 *
 * \param host The host id representing the sender of the message.
 * \param irq_num Hardware interrupt number
 * \param is_pending Value that indicates whether or not a message is pending
 *		     for the buffer corresponding to the msg_data struct.
 * \param is_secure Determines whether the message is from a secure or
 *                  non-secure queue
 */
struct msg_data {
	u8	host;
	u32	irq_num;
	sbool	is_pending;
	sbool	is_secure;
};

/**
 * \brief Populate the provided msg_data struct with passed data
 *
 * \param md The struct to populate with other passed msg data.
 * \param host The host id to staore as data about the currently received message.
 * \param irq_num Hardware interrupt number
 * \param is_secure Determines whether the message is from a secure or
 *                  non-secure queue
 *
 */
void set_current_msg_data(struct msg_data *md, u8 host, u32 irq_num, sbool is_secure);

#endif /* OSAL_MSG_PRIVATE_H */
