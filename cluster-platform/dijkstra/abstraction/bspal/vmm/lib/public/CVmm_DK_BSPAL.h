/*============================================================================
 **
 **  \file CVmm_DK_BSPAL.h
 **
 **  \brief Interface to interact with the VMM of QCOM
 **
 **  This file provides functional defines for a vmm module
 **
 **  Component Name: Vmm
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
#ifndef CVMM_DK_BSPAL_H_
#define CVMM_DK_BSPAL_H_

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "CVmm_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*!
@brief  Register clinet to vmm_service
@param  void
@retval int32_t Initialization status
 */
int32_t dk_bspal_vmm_init( void );

/*!
@brief  Deregister clinet to vmm_service
@param  void
@retval int32_t Deinitialization status
 */
int32_t dk_bspal_vmm_deinit( void );

/*!
@brief  Start specified vmm
@param  vmm_id - vmm id to be started
@retval int32_t Initialization status
 */
int32_t dk_bspal_vmm_start(uint8_t vmm_id);

/*!
@brief  Shutdown specified vmm
@param  vmm_id - vmm id to be started
@retval int32_t Shutdown status
 */
int32_t dk_bspal_vmm_stop(uint8_t vmm_id);

/*!
@brief  Get status of specified vmm
@param  vmm_id - vmm id to be started
@retval int32_t vmm status
 */
int32_t dk_bspal_vmm_getstatus(uint8_t vmm_id);


#ifdef __cplusplus
}
#endif


#endif



