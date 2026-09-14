/*
 * Copyright (C) 2019-2021 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file sec_proxy_fwl_ids.h
 *
 * \brief Header for sec proxy UT SOC info
 */
#ifndef SEC_PROXY_FWL_ID_H
#define SEC_PROXY_FWL_ID_H

#include <types/short_types.h>

#define MAX_NUM_SEC_PROXY_CNT (2U)

/** indicates the number of sec proxies in the system */
extern const u32 ut_sec_proxy_count;

/**
 * Array containing ID of the secure proxy channelized firewalls
 * for target data for the current SOC
 *
 * Index 0 corresponds to the main domain.
 * Index 1 corresponds to the MCU domain
 */
extern const u16 sproxy_target_data_fwl_ids[MAX_NUM_SEC_PROXY_CNT];

/**
 * Array containing ID of the secure proxy channelized firewalls
 * for RT region for the current SOC
 *
 * Index 0 corresponds to the main domain.
 * Index 1 corresponds to the MCU domain
 */
extern const u16 sproxy_rt_fwl_ids [MAX_NUM_SEC_PROXY_CNT];

/** indicates the index for MCU Sec proxy in the sproxy_rt_fwl_ids array */
extern const u32 ut_mcu_sec_proxy_index;
#endif
