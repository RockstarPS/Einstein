/*============================================================================
 **
 **  \file CVmm_Cfg.h
 **
 **  \brief Interface to interact with the VMM of QCOM
 **
 **  This file provides functional defines for a vmm module
 **
 **  Component Name: Misr
 **  Archive:
 **  Date: May 18 2022
 **  Author: SKOPPISE
 **
 ** Copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 **==========================================================================*/


#ifndef CVMM_CFG_H
#define CVMM_CFG_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define VMM_START    (1u)
#define VMM_STOP     (0u)
#define PATH_LEN     (100u)
#define BUF_MAX      (15u)
#define VMM_PATH     "/dev/vmm"

extern int32_t bspal_register_to_vmm(void);
extern int32_t bspal_unregister_from_vmm( void);
extern int32_t bspal_read_status(int32_t vmm_id);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif 
