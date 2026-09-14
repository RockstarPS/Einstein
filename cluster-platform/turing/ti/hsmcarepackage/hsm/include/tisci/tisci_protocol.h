/*
 * System Firmware TISCI Messaging Core
 *
 * TISCI Protocol Definitions
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef TISCI_PROTOCOL_H
#define TISCI_PROTOCOL_H

#include <lib/bitops.h>

/**
 * This flag is reserved and not to be used.
 */
#define TISCI_MSG_FLAG_RESERVED0    BIT(0)

/**
 * ACK on Processed: Send a response to a message after it has been processed
 * with TISCI_MSG_FLAG_ACK set if the processing succeeded, or a NAK otherwise.
 * This response contains the complete response to the message with the result
 * of the actual action that was requested.
 */
#define TISCI_MSG_FLAG_AOP    BIT(1)

/** Indicate that this message is marked secure */
#define TISCI_MSG_FLAG_SEC    BIT(2)

/**
 * Response flag for a message that indicates success. If this flag is NOT
 * set then that is to be interpreted as a NAK.
 */
#define TISCI_MSG_FLAG_ACK    BIT(1)

/**
 * \brief Header that prefixes all TISCI messages.
 *
 * \param type Type of message identified by a TISCI_MSG_* ID
 * \param host Host of the message.
 * \param seq Message identifier indicating a transfer sequence.
 * \param flags TISCI_MSG_FLAG_* for the message.
 * \param payload Placeholder pointer that can be used to access the raw message body.
 */
struct tisci_header {
	u16	type;
	u8	host;
	u8	seq;
	u32	flags;
	u8	payload[];
};

/*
 * Messages sent via secure transport need an additional field for integrity
 * check in addition to the fields of a TISCI message. The below data structure
 * is used to enhance the standard TISCI message header with a field for
 * integrity check and a reserved field for future use.
 *
 * The below defined header is placed before the \ref tisci_header when
 * transmitting a message via a secure transport.
 *
 * For more information, please refer to the TISCI documentation.
 */

/**
 * \brief Header that prefixes all TISCI messages sent via secure transport.
 *
 * \param integ_check This field should always be initialized to zero on GP
 * devices. The mechanism to calculate the integrity check for HS devices
 * is under definition.
 *
 * \param rsvd Reserved field for future use. Initialize to zero.
 *
 */
struct tisci_sec_header {
	u16	integ_check;
	u16	rsvd;
};

// /* TISCI Message IDs */
#define TISCI_MSG_SET_DEVICE                    (0x0200U)

/** Message to set a firewall region configuration */
#define TISCI_MSG_SET_FWL_REGION                (0x9000U)

/** Message to derive a KEK and return it via TISCI */
#define TISCI_MSG_SA2UL_GET_DKEK                (0x9029U)

/** Message to derive a SMEK and return it via TISCI */
#define TISCI_MSG_SA2UL_GET_DSMEK               (0x9036U)

/**
 * \brief Set the desired state of the device.
 *
 * Certain flags can also be set to alter the device state:
 * TISCI_MSG_FLAG_DEVICE_WAKE_ENABLED, TISCI_MSG_FLAG_DEVICE_RESET_ISO,
 * TISCI_MSG_FLAG_DEVICE_EXCLUSIVE
 *
 * \param hdr TISCI header
 *
 * \param id
 * Indicates which device to modify
 *
 * \param reserved
 * Field is ignored
 *
 * \param state
 * The desired state of the device.
 */

struct tisci_msg_set_device_req {
    struct tisci_header    hdr;
    u32            id;
    u32            reserved;
    u8            state;
} __attribute__((__packed__));

/**
 * \brief Empty response for TISCI_MSG_SET_DEVICE
 *
 * Although this message is essentially empty and contains only a header
 * a full data structure is created for consistency in implementation.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */

struct tisci_msg_set_device_resp {
    struct tisci_header hdr;
} __attribute__((__packed__));



#endif /* TISCI_PROTOCOL_H */
