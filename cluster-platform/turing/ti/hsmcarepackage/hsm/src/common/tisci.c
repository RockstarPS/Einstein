/*
 * System Firmware TISCI Messaging Core
 *
 * TISCI Common Core Layer for managing TISCI message handlers
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <tisci_protocol.h>

void tisci_msg_clear_flags(struct tisci_header *hdr)
{
	hdr->flags = 0;
}

void tisci_msg_set_ack_resp(struct tisci_header *hdr)
{
	hdr->flags |= TISCI_MSG_FLAG_ACK;
}

void tisci_msg_set_nak_resp(struct tisci_header *hdr)
{
	hdr->flags &= (~TISCI_MSG_FLAG_ACK);
}
