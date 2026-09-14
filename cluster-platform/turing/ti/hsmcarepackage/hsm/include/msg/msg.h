/*
 * System Firmware OSAL Messaging layer
 *
 * OSAL Core Messaging layer APIs
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef OSAL_MSG_H
#define OSAL_MSG_H

#include <types/short_types.h>
#include <types/ftbool.h>
#include <types/sbool.h>
#include <config.h>
#include <msg/msg_private.h>

#ifdef CONFIG_OSAL_MSG_FORWARDING
/**
 * \brief Number of non-secure hosts in the system
 */
extern const u8 num_nonsec_hosts;

/**
 * \brief Non-secure host ACL for second-level Host ID check in forwarded
 *        message
 */
extern const u8 nonsec_host_acl[];
#endif

/**
 * \brief Retrieve message data associated with the current message being
 *	  processed by the current task.
 *
 * \param host Pointer to store the host for the message being processed.
 *
 * \param is_secure Pointer to flag indicating whether the current
 * message is received from current thread.
 *
 */
s32 osal_get_current_task_msg_data(u8 *host, u8 *is_secure);

/**
 * \brief Send a response back through the messaging hardware which will be
 *	  routed based on the OSALs knowledge of where the message came from.
 *
 * \param response Buffer containing the full TISCI response to send.
 * \param size Size of the message in bytes.
 * \param md Message data, including reply host and secure queue indicator
 *
 * \return 0 on success, error code otherwise.
 *
 */
s32 osal_msg_response(u32 *response, u32 size, struct msg_data *md);

/**
 * \brief Send a message directly ROM secure proxy's TX thread
 *
 * This API transfers a complete message (integrity check, tx message, and the
 * final hardware doorbell) on the ROM secure proxy TX thread
 *
 * \param msg Buffer containing the full TISCI message to send.
 * \param size Size of the message in bytes.
 * \param is_secure Boolean determining if the message is secure or not.
 *
 * \return 0 on success, error code otherwise.
 *
 */
s32 msg_rom_send(u32 *msg, u32 size, sbool is_secure);

/**
 * \brief Send a message directly to a host using the messaging hardware
 *	  using a notification queue.
 *
 * \param host A host ID indicating which host's notification queue to use.
 * \param msg Buffer containing the full TISCI message to send.
 * \param size Size of the message in bytes.
 *
 * \return 0 on success, error code otherwise.
 *
 */
s32 osal_msg_send_notification(u8 host, u32 *msg, u32 size);

/**
 * \brief Compare the header host id to a known host id.
 *
 * \param msg Buffer containing TISCI message to check the host.
 * \param known_host A trusted host id to compare to msg header host ID.
 *
  \return 0 if the host IDs match or an error code otherwise.
 */
s32 osal_msg_verify_host(u32 *msg, u8 known_host);

#ifdef CONFIG_OSAL_MSG_FORWARDING
/**
 * \brief Check if host ID belongs to the non-secure Access Control List.
 *
 *        DM-forwarded messages must be from a non-secure host in the system.
 *        Any attempt to process a forwarded message with a secure host ID is a
 *        clear spoofing attempt and must be blocked.
 *
 * \param host_id Host ID from the forwarded message request.
 *
 * \return ftbool on whether host is non-secure
 */
ftbool osal_check_host_in_nonsec_acl(u8 host_id);


/**
 * \brief Send a response back to dm through the messaging hardware. The
 *	  function can run in hwi handler; not restricted to run within tasks.
 *
 * \param response Buffer containing the full TISCI response to send.
 * \param size Size of the message in bytes.
 *
 * \return 0 on success, error code otherwise.
 *
 */
s32 osal_msg_dm_response(u32 *response, u32 size);

/**
 * \brief Send a message to a DM using the messaging hardware
 *	  using a high priority queue.
 *
 * \param tx_msg Buffer containing the full TISCI message to send.
 * \param tx_msg_size Size of the transfer message in bytes.
 *
 * \return 0 on success, error code otherwise.
 *
 */
s32 osal_msg_send_dm_message(u32 *tx_msg, u32 tx_msg_size);

#endif

#endif  /* OSAL_MSG_H */
