/*
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef SEC_PROXY_MINIMAL_H
#define SEC_PROXY_MINIMAL_H

#include "short_types.h"
#include "tisci_protocol.h"

#define SEC_PROXY_MSG_RX_TID    (0U)
#define HSM_SEC_PROXY_RT_ADDRESS (0x44880000U)
#define HSM_SEC_PROXY_TARGET_ADDRESS (0x43600000U)
#define RETRY_CNT_10ms          (1000 * 10)
/**
 * \brief Send a Secure Proxy message
 * \param msg message buffer pointer pointing to the message to be send
 * \param len length of the message in bytes
 * \param tx_thread secure proxy thread used for transmission from HSM
 */
s32 sproxy_send_msg(void *msg, u32 len, u32 tx_thread);
/**
 * \brief Receive a Secure Proxy message
 * \param msg buffer pointer pointing to the buffer to store the message
 * \param len length of the message in bytes
 */
s32 sproxy_receive_msg(void *msg, u32 len);

#endif /* SEC_PROXY_MINIMAL_H */
