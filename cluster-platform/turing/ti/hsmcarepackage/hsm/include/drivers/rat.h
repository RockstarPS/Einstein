/*
 * { TBD/FIXME: module name}
 *
 * { TBD/FIXME: module description}
 *
 * Copyright (C) 2022-2023 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

#ifndef RAT_H
#define RAT_H

#include "short_types.h"
#include <lib/io_internal.h>

/** \brief Virtual address for index 0 */
#define RAT_ADDR0_VIRTUAL_ADDR  (0x60000000U)
/** \brief Physical address for index 0 */
#define RAT_ADDR0_PHYSICAL_ADDR (0x00000000ULL)
/** \brief Virtual address for index 1 */
#define RAT_ADDR1_VIRTUAL_ADDR  (0x80000000U)
/** \brief Physical address for index 1 */
#define RAT_ADDR1_PHYSICAL_ADDR (0x20000000ULL)
/** \brief Virtual address for index 2 */
#define RAT_ADDR2_VIRTUAL_ADDR  (0xa0000000U)
/** \brief Physical address for index 2 */
#define RAT_ADDR2_PHYSICAL_ADDR (0x40000000ULL)
/** \brief Virtual address for index 3 */
#define RAT_ADDR3_VIRTUAL_ADDR  (0xC0000000U)
/** \brief Physical address for index 3 */
#define RAT_ADDR3_PHYSICAL_ADDR rat3_phy_addr
/** \brief Virtual address for index 4 */
#define RAT_ADDR4_VIRTUAL_ADDR  (0xD0000000U)
/** \brief Physical address for index 4 */
#define RAT_ADDR4_PHYSICAL_ADDR (0x60000000U)

/** \brief Virtual address for RAT free window */
#define RAT_FREE_WINDOW_VIRTUAL_ADDR  (0xc0000000U)

#define FREE_MAP_UNUSED (0x0U)
#define FREE_MAP_USED (0x1U)

void rat_set_mapping(u32 window, u32 base, u64 address, u32 order);
void rat_disable_mapping(u32 window);
extern s32 rat_init(void);

/**
 * \brief Get the tmp rat mapped address range of the low and high address
 *
 * \param lowAddr Lower address value of the TMP mapped region
 * \param highAddr Higher address region of the TMP mapped region
 * \return SUCCESS if the values are populated correctly.
 *         -EBUSY  if the TMP mapped address is not used.
 */
s32 rat_get_free_map_addr_range(u64 *lowAddr, u64 *highAddr);

/**
 * \brief Get the tmp rat mapped address range of the low and high address. user callable
 *
 * \param lowAddr Lower address value of the TMP mapped region
 * \param highAddr Higher address region of the TMP mapped region
 * \return SUCCESS if the values are populated correctly.
 *         -EBUSY  if the TMP mapped address is not used.
 */

s32 rat_get_free_map_addr_range_user(u64 *lowAddr, u64 *highAddr);



s32 rat_map_tmp_region(u64 addr, u32 *mapped_addr);
/**
 * \brief Free and disable a mapping done by rat_map_tmp_region
 *
 * Objective of this API is a limited usage scenario where there is absolutely
 * no chance of contention. There are no lock protection mechanisms provided.
 *
 * \param addr provide the exact address parameter provided to rat_map_tmp_region
 *
 * \return SUCCESS if all went fine, else returns corresponding error value.
 */
s32 rat_unmap_tmp_region(u64 addr);

#define RAT_TMP_REGION_INVAL_ADDR_MASK  (0x1FFFFFFFU)

#endif
