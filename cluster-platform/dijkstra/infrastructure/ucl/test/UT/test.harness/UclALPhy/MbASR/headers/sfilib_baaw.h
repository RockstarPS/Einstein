/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of
 * SAMSUNG ELECTRONICS ("Confidential Information").
 *
 * You shall not disclose such Confidential Information and shall use it
 * only in accordance with the terms of the license agreement
 * you entered into with SAMSUNG ELECTRONICS.
 *
 * SAMSUNG make no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular
 * purpose, or non-infringement. SAMSUNG shall not be liable for any
 * damages suffered by licensee as a result of using, modifying or
 * distributing this software or its derivatives.
 */
/**
 *  @file sfilib_baaw.h
 *  @brief This file is a header file for Base Address remapper and Access Window(BAAW).
 *  @ingroup SfiLib
 */
#ifndef SFILIB_BAAW_H
#define SFILIB_BAAW_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 * Defines / Macros
 **********************************************************************************************************************/
/* --------------------------- */
/* BAAW Window Remap Status    */
/* --------------------------- */
#define BAAW_RET_REMAP_OFF          (0u)
#define BAAW_RET_REMAP_ON           (1u)

/* --------------------------- */
/* DRAM Region IDs             */
/* --------------------------- */
#define BAAW_DRAM_RGN_ID_0          (0u)
#define BAAW_DRAM_RGN_ID_1          (1u)
#define BAAW_DRAM_RGN_ID_2          (2u)
#define BAAW_DRAM_RGN_ID_3          (3u)
#define BAAW_DRAM_RGN_ID_MAX        (4u)

/**********************************************************************************************************************
 * Type Definitions
 **********************************************************************************************************************/
typedef uint8                       baaw_ret_type;

/**********************************************************************************************************************
 * Extern Functions
 **********************************************************************************************************************/
/**
 * @fn baaw_ret_type baaw_map_dram(uint32 dram_id, uint32 sys_base, uint32 size)
 * @brief This function maps SFI's DRAM region to DRAM's system address.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @param [in] sys_base System target address to remap to each DRAM region. The address should be 4K-aligned.
 * @param [in] size Region size to remap. The size should be 4K-aligned.
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern baaw_ret_type baaw_map_dram(uint32 dram_id, uint32 sys_base, uint32 size);

/**
 * @fn baaw_ret_type baaw_unmap_dram(uint32 dram_id)
 * @brief This function unmaps SFI's DRAM region to DRAM's system address.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern baaw_ret_type baaw_unmap_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_sysbase_dram(uint32 dram_id)
 * @brief This function returns the base address of remapped DRAM 0 region in Safety Island's view.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return On success, Remapped system base address of DRAM 0 region is returned. On failure, zero is returned.
 */
extern uint32 baaw_sysbase_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_syslimit_dram(uint32 dram_id)
 * @brief This function returns the limit address of remapped DRAM 0 region in Safety Island's view.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return On success, Remapped system limit address of DRAM 0 region is returned. On failure, zero is returned.
 */
extern uint32 baaw_syslimit_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_sfibase_dram(uint32 dram_id)
 * @brief This function returns the base address of remapped DRAM 0 region in Safety Island's view.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return On success, Remapped SFI base address of DRAM 0 region is returned. On failure, zero is returned.
 */
extern uint32 baaw_sfibase_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_sfilimit_dram(uint32 dram_id)
 * @brief This function returns the limit address of remapped DRAM 0 region in Safety Island's view.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return On success, Remapped SFI limit address of DRAM 0 region is returned. On failure, zero is returned.
 */
extern uint32 baaw_sfilimit_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_stat_dram(uint32 dram_id)
 * @brief This function returns window status of BAAW, which is allocated DRAM 0 region.
 * @param [in] dram_id ID of DRAM region which is named from as zero of low address's region
 * @return The status if window is enabled or disabled.
 */
extern uint32 baaw_stat_dram(uint32 dram_id);

/**
 * @fn uint32 baaw_translate_dram_to_sys(uint32 addr)
 * @brief This function translates DRAM address in SFI's memory view to DRAM address of system's memory view. The DRAM
 *        address of Safety Island should belong to one of Safety Island's DRAM regions. In addition, the window status
 *        of corresponding region should be enabled.
 * @param [in] addr Address which belong to SFI's DRAM region
 * @return On success, translated DRAM address is returned. On failure, zero is returned.
 */
extern uint32 baaw_translate_dram_to_sys(uint32 addr);

#endif /* SFILIB_BAAW_H */
