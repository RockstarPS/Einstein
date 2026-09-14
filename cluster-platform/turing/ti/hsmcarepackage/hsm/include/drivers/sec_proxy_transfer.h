/*
 * Secure Proxy Transfer APIs
 *
 * Copyright (C) 2017-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_proxy_transfer.h
 *
 * \brief Secure Proxy Transfer (Messaging) APIs
 */

#ifndef SEC_PROXY_TRANSFER_H
#define SEC_PROXY_TRANSFER_H

#include <types/short_types.h>
#include <secure_proxy_description.h>

/**************************************************************************
 * Receive APIs
 **************************************************************************/

/**
 * \brief Check to see if a message is pending on a Rx sec proxy thread
 *
 * \param rx_config_id - Index into soc_secure_proxy_rx_configurations
 *
 * \return 0 if there is pending message, else returns corresponding error
 * result.
 */
s32 sproxy_msg_is_pending(u16 rx_config_id);

/**
 * \brief Find the Sender's Host ID for a pending message
 *
 * Since every Tx thread is mapped to an Rx thread, when we get a message,
 * the hardware mechanisms allow us to identify the tx thread that send
 * the original message. This allows a lookup into what the exact host ID
 * should have been for the transmitting party. This, in conjunction with
 * appropriate firewall settings, should detect a spoof message being
 * send on a secure proxy thread that is incorrect.
 *
 * \param rx_config_id - Index into soc_secure_proxy_rx_configurations
 * \param sender_host_id - Returns the host ID from SoC database
 *
 * \return 0 if there was a pending message and sender_host_id is valid,
 * else, returns corresponding error value.
 */
s32 sproxy_msg_get_sender_host_id(u16 rx_config_id, u32 *sender_host_id);

/**
 * \brief read a message (but dont ack)
 *
 * This reads a message from a Rx secure proxy thread, without notifying the
 * hardware doorbell register that the message read is complete.
 *
 * \param rx_config_id - Index into soc_secure_proxy_rx_configurations
 * \param rx_buff - Rx buffer
 * \param rx_num_words - number of words to read (sizeof(u32) elements)
 *
 * \return 0 if there was a pending message and the rx_buff now has
 * rx_num_words of data read from the secure proxy, else returns corresponding
 * error.
 */
s32 sproxy_msg_read(u16 rx_config_id, u32 *rx_buff, u32 rx_num_words);

/**
 * \brief read a portion of the message (but dont ack)
 *
 * This is a companion API to \ref sproxy_msg_read. It can be used to read
 * specific portions of the message from Rx secure proxy thread without always starting at offset 0.
 *
 * \param rx_config_id - Index into soc_secure_proxy_rx_configurations
 * \param rx_buff - Rx buffer
 * \param rx_num_words - number of words to read (sizeof(u32) elements)
 * \param offset - word offset from which we need to read the message.
 *
 * \return 0 if there was a pending message and the rx_buff now has
 * rx_num_words of data read from the secure proxy, else returns corresponding
 * error.
 */
s32 sproxy_msg_read_at_offset(u16 rx_config_id, u32 *rx_buff, u32 rx_num_words, u32 offset);

/**
 * \brief acknowledge receipt of message to hardware
 *
 * *if* there was a pending message, let secure proxy hardware know that the
 * message has been consumed and to make the next message available (if any).
 *
 * \param rx_config_id - Index into soc_secure_proxy_rx_configurations
 *
 * \return 0 if there was a pending message and has been successfully acked,
 * else return corresponding error.
 */
s32 sproxy_msg_ack(u16 rx_config_id);

/**************************************************************************
 * Transmit APIs
 **************************************************************************/

/**
 * \brief Check to see if we can indeed transmit a message
 *
 * Check secure proxy thread to see if we have enough credits to be able to
 * send at least 1 message.
 *
 * \param tx_config_id - Index into soc_secure_proxy_tx_configurations
 *
 * \return 0 if we have space for at least 1 message, however, if we have
 * used up all hardware credits or error conditions, return corresponding
 * error value.
 */
s32 sproxy_msg_can_send(u16 tx_config_id);

/**
 * \brief send a message (stage it, but don't complete transmissions)
 *
 * This stages a message for transmission on a Tx secure proxy thread, without
 * notifying the hardware doorbell register that the message is ready to be
 * transmitted. So there is a very good chance that you may overwrite a staged
 * message with another staged message if \ref sproxy_msg_finish was failed to
 * be called in the middle.
 *
 * This API does not provide mutual exclusion for threads or against race against
 * \ref sproxy_msg_finish
 *
 * \param tx_config_id - Index into soc_secure_proxy_tx_configurations
 * \param tx_buff - Transmit buffer
 * \param tx_num_words - number of words to write (sizeof(u32) elements)
 *
 * \return 0 if message has been successfully been staged (NOTE: credit
 * is not decremented until confirmed), else returns corresponding error
 */
s32 sproxy_msg_send(u16 tx_config_id, u32 *tx_buff, u32 tx_num_words);


/**
 * \brief send a message (stage it, but don't complete transmissions)
 *
 * This is a companion API to \ref sproxy_msg_send. It can be used to construct
 * a secure proxy message in parts as opposed to \ref sproxy_msg_send which always
 * overwrites the existing data.
 *
 * The parameter offset can be used to control where we start writing to into the
 * secure proxy data registers. When offset is 0, this function is equivalent to
 * \ref sproxy_msg_send.
 *
 * This API does not provide mutual exclusion for threads or against race against
 * \ref sproxy_msg_finish
 *
 * \param tx_config_id - Index into soc_secure_proxy_tx_configurations
 * \param tx_buff - Transmit buffer
 * \param tx_num_words - number of words to write (sizeof(u32) elements)
 * \param offset - number of words to index into the secure proxy registers when writing.
 *
 * \return 0 if message has been successfully been staged (NOTE: credit
 * is not decremented until confirmed), else returns corresponding error
 */
s32 sproxy_msg_send_at_offset(u16 tx_config_id, u32 *tx_buff, u32 tx_num_words, u32 offset);

/**
 * \brief Confirm to hardware to transmit a staged message.
 *
 * NOTE: This API does not verify to make sure an actual data was made
 * available in the secure proxy via \ref sproxy_msg_send. Any call to this
 * API will result in reduction by 1 of available credits.
 *
 * This API does not provide mutual exclusion for threads
 *
 * \param tx_config_id - Index into soc_secure_proxy_tx_configurations
 *
 * \return 0 if message has been successfully transmitted, else return
 * corresponding message.
 */
s32 sproxy_msg_finish(u16 tx_config_id);

/**
 * \brief Retrieve the Tx thread config ID for response to a host ID
 *
 * Retrieve a Tx thread Config ID for a valid Host ID
 *
 * \param host_id - valid host id for the SoC
 * \param tx_config_id - returns if valid a corresponding tx config id
 *
 * \return 0  if the host id is valid and *tx_config_id is valid, else
 * returns corresponding error value
 */
s32 sproxy_get_response_conf_id(u16 host_id, u16 *tx_config_id);

/**
 * \brief Retrieve the Tx thread config ID for notification to a host ID
 *
 * Retrieve a Tx thread Config ID for a valid Host ID
 *
 * \param host_id - valid host id for the SoC
 * \param tx_config_id - returns if valid a corresponding tx config id
 *
 * \return 0  if the host id is valid and *tx_config_id is valid, else
 * returns corresponding error value
 */
s32 sproxy_get_notify_conf_id(u16 host_id, u16 *tx_config_id);

/**
 * \brief Function to trivially verify if the provided host_id is a valid ID
 *
 * \param host_id - Host ID to verify
 *
 * \return
 *  -EVINAL if the host ID is not valid
 *  SUCCESS if the host ID is valid
 */
s32 sproxy_msg_validate_host_id(u16 host_id);

/**
 * \brief Raw register read/write on a specific thread of a secure proxy
 *
 * This API provides full flexibility to read/write a message at an offset
 * on a particular thread id of the chosen secure proxy.
 *
 * \param is_tx - STRUE for write operation, SFALSE for read operation
 * \param sproxy - secure proxy config pointer
 * \param thread_id - thread id to read/write
 * \param buf - message buffer to read/write
 * \param buf_num_words - number of words to read/write
 * \param offset - number of words to index into the secure proxy registers
 */
void sproxy_msg_trans_raw(sbool is_tx, const struct secure_proxy *sproxy, u16 thread_id, u32 *buf, u32 buf_num_words, u32 offset);

#endif
