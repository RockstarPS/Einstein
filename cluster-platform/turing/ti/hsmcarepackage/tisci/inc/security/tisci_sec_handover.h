/*
 * System Firmware
 *
 * TISCI Data structures and macros for security handover message
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef TISCI_SEC_HANDOVER_H_
#define TISCI_SEC_HANDOVER_H_

#include <short_types.h>
#include <tisci_protocol.h>

/**
 * \brief Request for security handover message
 *
 * This message can only be sent by the host
 * specified in security board configuration.
 *
 * \param hdr Generic TISCI message header.
 */
struct tisci_msg_security_handover_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for security handover message
 *
 * \param hdr Generic TISCI message header.
 *      ACK response indicates that security handover is successful
 *      NACK response indicates that security handover has failed
 */
struct tisci_msg_security_handover_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

#endif
