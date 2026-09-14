/*
 * System Firmware TISCI Messaging Core
 *
 * TISCI Secure Core Layer for managing TISCI message handlers
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#include <lib/container_of.h>
#include <osal_halt.h>
#include <tisci_provider/tisci.h>
#include <tisci_protocol.h>

static struct map *secure_client_map;

s32 tisci_common_process_response(u32 *mesg, s32 ret)
{
	struct tisci_header *hdr = (struct tisci_header *) mesg;
	s32 r = -EFAIL;

	if (ret == -EFAILVERIFY) {
		/*
		 * Halt here and do not send a response
		 */
		osal_system_halt(ret);
	} else if (hdr->flags & TISCI_MSG_FLAG_AOP) {
		if (ret == EFTOK) {
			tisci_msg_set_ack_resp(hdr);
		} else {
			tisci_msg_set_nak_resp(hdr);
		}

	} else {
		r = SUCCESS;
	}

	return r;
}
s32 tisci_secure_client_register(u16 id, struct tisci_client *client)
{
	sbool duplicate = SFALSE;
	struct map *mapp;
	struct map_node *n;
	s32 ret = 0;

	/* Accept duplicate registrations for same client */
	n = u32map_get(secure_client_map, id);
	if (n && n == &client->node) {
		duplicate = STRUE;
	}
	if (!duplicate) {
		mapp = u32map_add(secure_client_map, id, &client->node);
		if (!mapp) {
			ret = -EBUSY;
		}

		secure_client_map = mapp;
	} else {
		client = container_of(n, struct tisci_client, node);
		client->flags &= ~TISCI_CLIENT_FLAG_UNREGISTERED;
	}

	return ret;
}

s32 tisci_secure_client_unregister(u16 id)
{
	struct tisci_client *client;
	struct map_node *n;
	s32 ret = 0;

	n = u32map_get(secure_client_map, id);
	if (!n) {
		ret = -EINVAL;
	}
	if (!ret) {
		client = container_of(n, struct tisci_client, node);
		client->flags |= TISCI_CLIENT_FLAG_UNREGISTERED;
	}

	return ret;
}

s32 tisci_secure_lookup_client(u16 id, struct tisci_client **client)
{
	struct map_node *n;
	s32 ret = 0;

	n = u32map_get(secure_client_map, id);
	if (!n) {
		ret = -EINVAL;
	}

	if (!ret) {
		*client = container_of(n, struct tisci_client, node);
		/*  If a message has been unregistered, behave as message entry does not exist  */
		if ((((*client)->flags) & TISCI_CLIENT_FLAG_UNREGISTERED) != 0U) {
			*client = NULL;
			ret = -EINVAL;
		}
	} else {
		*client = NULL;
	}

	return ret;
}
