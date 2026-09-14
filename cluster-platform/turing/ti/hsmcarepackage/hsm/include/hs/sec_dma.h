/*
 * Copyright (C) 2017-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_dma.h
 *
 * \brief DMA APIs for security module internal use
 *
 */
#ifndef SEC_DMA_H_
#define SEC_DMA_H_

#include <types/fterr.h>
#include <types/short_types.h>
#include <types/address_types.h>
#include <sec_dma_bootcfg.h>
#include <udmap_pkt_descr.h>
#include <config.h>

/**
 * \brief Secure DMA module init
 *
 * \return EFTOK if successful
 */
fterr sec_dma_init(void);

/**
 * \brief Reset the state of the firewall
 *
 * \return EFTOK if successful
 */
fterr sec_dma_reset(void);

/**
 * \brief Secure memcpy using DMA
 *
 * Secure memcpy uses caller's security attributes for read and write and is
 * used to securely access pointers provided by processing entities who call
 * into DMSC firmware with their own security attributes.
 *
 * \param to Destination soc physical address
 * \param from Source soc physical address
 * \param len Length of data to transfer
 * \param read_host Host ID for read access
 * \param write_host Host ID for write access
 *
 * \return EFTOK if successful
 */
fterr sec_dma_memcpy(soc_phys_addr_t to, soc_phys_addr_t from, u32 len, u8 read_host, u8 write_host);

/**
 * \brief Try to grab DMA resources and descriptor memory
 *
 * \param read_host Host ID for read access
 * \param write_host Host ID for write access
 * \param via_sa2ul Is the DMA going via SA2UL
 * \param tx_descr Pointer to the Tx descriptor returned if DMA is free
 * \param rx_descr Pointer to the Rx descriptor returned if DMA is free
 *
 * \return EFTOK if successful
 */
fterr sec_dma_grab(u8 read_host, u8 write_host, ftbool via_sa2ul, local_phys_addr_t *tx_descr, local_phys_addr_t *rx_descr);

/**
 * \brief Release DMA resources held by a previous call to \ref sec_dma_grab
 *
 * \param force_teardown Force a teardown of channels. This should be set
 *                       there were any errors during a data transfer
 *
 * \return EFTOK if successful
 */
fterr sec_dma_release(ftbool force_teardown);

/**
 * \brief push Rx & Tx descriptors to start the DMA
 *
 * This function assumes that descriptors are already setup.
 *
 * \ref sec_dma_grab must be called before calling this function and the tx
 * and rx descriptors must be populated with valid data.
 *
 * \return EFTOK if successful
 */
fterr sec_dma_push_pkt(void);

/**
 * \brief Wait for DMA transfer completion
 *
 * \ref sec_dma_push_pkt must be called before calling this function
 *
 * \param tmout_us Transfer timeout value in micro seconds to wait
 *
 * \return -ETIMEDOUT if timed out waiting for reply
 * \return EFTOK if successful
 */
fterr sec_dma_wait_for_pkt(u32 tmout_us);

/**
 * \brief function to clear and setup a base host packet descriptor
 *        with one buffer for Tx.
 *
 * \param txdescr - Pointer to host descriptor
 *
 * \param from - Physical address of the packet buffer
 *
 * \param len - Packet length
 *
 * \param einfo_present  Extended packet information is present
 *
 * \param psdata_wcnt - Protocol specific data length in words (word count)
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr sec_dma_init_tx_descr(struct udmap_descr_host *txdescr, soc_phys_addr_t from, u32 len, ftbool einfo_present, u32 psdata_wcnt);

/**
 * \brief open firewalls necessary for validating board cfg
 */
fterr sec_dma_open_fwls_pre_boardcfg(void);

/**
 * \brief Release SA2UL-related DMA resources
 *
 * This function disables and unpairs all PSIL threads to the SA2UL which are
 * used by SYSFW.
 *
 * \ref sec_dma_init must be rerun after this function has been called in order
 * to guarantee that SYSFW is able to clean up and reclaim resources for use.
 *
 * \return EFTOK if successful
 */
fterr sec_dma_release_sa2ul_resources(void);

#endif /* SEC_DMA_H_ */
