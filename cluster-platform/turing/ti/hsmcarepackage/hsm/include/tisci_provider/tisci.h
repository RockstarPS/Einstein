/*
 * System Firmware TISCI Messaging Core
 *
 * TISCI Core Layer for managing TISCI message handlers
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef TISCI_H
#define TISCI_H

#include <lib/bitops.h>
#include <types/map.h>
#include <types/short_types.h>
#include <types/fterr.h>
#include <msg/msg_private.h>

/**
 * \brief Message is valid to be processed before Board Config has been
 *	  received.
 */
#define TISCI_CLIENT_FLAG_PRECONFIG                             BIT(0)

/**
 * \brief Message has been unregistered and should no longer be processed
 */
#define TISCI_CLIENT_FLAG_UNREGISTERED                          BIT(4)

struct tisci_header;

typedef s32 (*tisci_handler_func_t)(u32 *msg_recv, struct msg_data *md);

/**
 * \brief Contains data need to process an incoming TISCI message.
 *
 * \param handler Pointer to an tisci handler function that is provided with a
 *		raw buffer containing the incoming message and
 *		an empty buffer that is to be filled with the
 *		raw response.
 * \param flags Bit field to contain flags giving any information needed by the
 *	      the caller of handler.
 * \param subsystem Identifier used with SUBSYSTEM_* macros to indicate which subsystem
 *		  this message belongs to. Message will not be processed until the
 *		  subsystem selected here is initialized.
 * \param valid_hosts Bit field that is to contain information representing which
 *		    are valid callers of this message. Possibly only enforced
 *		    for secure messages.
 * \param node Struct used in map implementation.
 */
struct tisci_client {
	tisci_handler_func_t	handler;
	u32			flags;
	u32			subsystem;
	u32			valid_hosts;
	struct map_node		node;
};

/**
 * \brief Helper to take the passed tisci_header and clear all flags.
 *
 * \returns 0 always on success.
 */
void tisci_msg_clear_flags(struct tisci_header *hdr);

/**
 * \brief Helper to take the passed tisci_header and set MSG_FLAG_ACK.
 *
 * \returns 0 always on success.
 */
void tisci_msg_set_ack_resp(struct tisci_header *hdr);

/**
 * \brief Helper to take the passed tisci_header and clear MSG_FLAG_ACK.
 *
 * \returns 0 always on success.
 */
void tisci_msg_set_nak_resp(struct tisci_header *hdr);

/**
 * \brief Register a secure tisci_client to handle all messages with id
 *
 * This function stores the tisci_client in a map that is keyed on the TISCI
 * id. It is only able to be called from secure context and uses a map that is
 * placed in secure memory as well.
 *
 * \param id TISCI ID to be handled by the client that is provided.
 * \param client Pointer to a static struct containing configuration for this
 *		 TISCI client.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_secure_client_register(u16 id, struct tisci_client *client);

/**
 * \brief Lookup and return an tisci_client that was registered with an id
 *
 * This function uses a map stored in secure memory so it can only be called
 * from secure context to lookup a message registered using
 * tisci_secure_client_register.
 *
 * \param id TISCI ID to return an tisci_client for.
 * \param client Pointer to an tisci_client passed by reference to be populated
 *		 with tisci_client that was found, or NULL if none was
 *		 registered for id.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_secure_lookup_client(u16 id, struct tisci_client **client);

/**
 * \brief Register a user tisci_client to handle all messages with id
 *        WARNING: Only call this function from a secure context.
 *
 * This function stores the tisci_client in a map that is keyed on the TISCI
 * id. It can be called from any context and uses a map stored in user memory.
 *
 * \param id TISCI ID to be handled by the client that is provided.
 * \param client Pointer to a static struct containing configuration for this
 *		 TISCI client.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_user_client_register_core(u16 id, struct tisci_client *client);

/**
 * \brief Escalate privilege then register a user tisci_client to handle all
 *        messages with id
 *
 * This function stores the tisci_client in a map that is keyed on the TISCI
 * id. It can be called from any context and uses a map stored in user memory.
 *
 * \param id TISCI ID to be handled by the client that is provided.
 * \param client Pointer to a static struct containing configuration for this
 *		 TISCI client.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_user_client_register(u16 id, struct tisci_client *client);

/**
 * \brief Lookup and return a user tisci_client that was registered with an id
 *
 * This function uses a map stored in user memory so it can be called from any
 * context to lookup a message registered using tisci_user_client_register.
 *
 * \param id TISCI ID to return an tisci_client for.
 * \param client Pointer to an tisci_client passed by reference to be populated
 *		 with tisci_client that was found, or NULL if none was
 *		 registered for id.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_user_lookup_client(u16 id, struct tisci_client **client);

/**
 * \brief Check the return value from the internal processing function and
 *        send a response
 *
 * \param mesg Message to send in respose
 * \param ret Return value from the internal function
 * \param reply_size Size of the message to send in reply
 * \param md Message data sent through the message handler
 *
 * \return SUCCESS upon success, error code defined in types/errno.h otherwise
 */
s32 tisci_common_process_response(u32 *mesg, s32 ret);


/* Subsystem Init Calls */

/**
 * \brief Initialize and register core messages.
 *
 * \return 0 on success or error code otherwise.
 */
s32 core_message_init(void);

/**
 * \brief Send a TISCI_MSG_BOOT_NOTIFICATION message to desired host.
 *
 * Although this message is essentially empty and contains only a header
 * a full data structure is created for consistency in implementation.
 *
 * \param host_id Host ID to send the message to.
 *
 * \return 0 on success or error code otherwise.
 */
s32 tisci_msg_send_boot_notification(u8 host_id);

/**
 * \brief Mark a client as unregistered in the secure message map
 *
 * This function does not modified the message tree.
 * it only modifies the flags field in the tisci_client
 * data structure
 *
 * \param id TISCI message ID to be marked as unregistered
 *
 * \return 0 on success or error code if message ID is not found
 * in map.
 */
s32 tisci_secure_client_unregister(u16 id);

/**
 * \brief Mark a client as unregistered in the user message map
 *
 * This function does not modified the message tree.
 * it only modifies the flags field in the tisci_client
 * data structure
 *
 * \param id TISCI message ID to be marked as unregistered
 *
 * \return 0 on success or error code if message ID is not found
 * in map.
 */
s32 tisci_user_client_unregister(u16 id);

#endif /* TISCI_H */
