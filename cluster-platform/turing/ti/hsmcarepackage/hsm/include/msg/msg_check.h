/*
 * System Firmware OSAL Messaging layer
 *
 * Integrity check for messages received over secure transport
 *
 * Copyright (C) 2018-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef OSAL_MSG_CHECK_H
#define OSAL_MSG_CHECK_H

#include <types/short_types.h>
#include <tisci_protocol.h>

/**
 * \brief check the integrity of the message received against the
 * secure header received along with it.
 *
 * \param msg pointer to the message. Integrity check is performed for
 * the maximum length of the buffer.
 *
 * \param sec_hdr pointer to the secure header.
 *
 * \return 0 on success, error code otherwise.
 */
s32 osal_check_integrity(u32 *msg, struct tisci_sec_header *sec_hdr);

/**
 * \brief calculate the integrity check value of the given message
 * and populate it in the secure header
 *
 * \param msg pointer to the message. Integrity check calculation
 * is performed for the maximum length of the buffer.
 *
 * \param sec_hdr pointer to the secure header.
 *
 * \return 0 on success, error code otherwise.
 */
s32 osal_calc_integrity(u32 *msg, struct tisci_sec_header *sec_hdr);

#endif
