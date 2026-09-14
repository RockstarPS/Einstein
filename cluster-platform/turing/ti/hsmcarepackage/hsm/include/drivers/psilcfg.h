/*
 * System Firmware NAVSS PSILCFG Library
 *
 * Copyright (C) 2017-2022 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file psilcfg.h
 *
 * \brief Include file for the description of psilcfg
 *	  private use of drivers
 */

#ifndef PSILCFG_H
#define PSILCFG_H

#include <types/fterr.h>
#include <types/short_types.h>
#include <types/address_types.h>

/**
 * \brief Describes a psilcfg instance
 * \param cfg_proxy - Base address for psil configuration proxy
 *
 * This structure describes an instance of psilcfg in the SoC.
 * Addresses provided here are physical addresses from the perspective
 * of SoC base address map.
 */
struct psilcfg {
	soc_phys_addr_t cfg_proxy;
};

/** Instances of psilcfg */
extern const struct psilcfg soc_psilcfg_instances[];
/** Num of psilcfg instances */
extern const u8 soc_psilcfg_instances_num;

/**
 * \brief function to create a PSIL route from source thread ID to destination
 *        thread ID (create a thread pairing) and enable threads
 *
 * \param id - PSIL IP instance number
 *
 * \param src_thread_id - Source thread ID
 *
 * \param dest_thread_id - Destination thread ID
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr psilcfg_create_route_and_enable(u8 id, u16 src_thread_id, u16 dest_thread_id);

/**
 * \brief function to teardown a PSIL source thread
 *
 * \param id - PSIL IP instance number
 *
 * \param src_thread_id - Source thread ID
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr psilcfg_teardown(u8 id, u16 src_thread_id);

/**
 * \brief function to unpair PSIL threads
 *
 * \param id - PSIL IP instance number
 *
 * \param src_thread_id - Source thread ID
 *
 * \param dest_thread_id - Destination thread ID
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr psilcfg_unpair_threads(u8 id, u16 src_thread_id, u16 dest_thread_id);

/**
 * \brief function to disable a psil thread
 *
 * \param id - PSIL IP instance number
 *
 * \param thread_id - Thread ID
 *
 * \return EFTOK if all went fine, else return corresponding error
 */
fterr psilcfg_disable(u8 id, u32 thread_id);

#endif
