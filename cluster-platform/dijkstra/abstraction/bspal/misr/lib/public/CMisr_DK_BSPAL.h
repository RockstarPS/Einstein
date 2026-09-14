/*============================================================================
 **
 **  \file CMisr_DK_BSPAL.h
 **
 **  \brief Interface to interact with the Misr of HD
 **
 **  This file provides functional defines for a Misr module
 **
 **  Component Name: Misr
 **  Archive:
 **  Date: Mar 18 2022
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
#ifndef CMISR_DK_BSPAL_H_
#define CMISR_DK_BSPAL_H_

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "CMisr_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* -------------- SIG0 and SIG1 unit  -------------- */
/*!
@brief  Initializes the Sig unit#0 or #1
@param  sig_unit_id - Signature Unit Identifier
@param  p_setup - pointer to SSigUnitCfg_t
@retval int32_t Initialization status
 */
extern int32_t dk_bspal_sigunit_initialize(uint8_t sig_unit_id, ts_SSigUnitCfg_t * p_sig_cfg_SP);

/*!
@brief  Shutdown/Uninitializes the Sig units (#0 or #1)
@param  sig_unit_id - Signature Unit Identifier
@retval int32_t Shutdown status
 */
extern int32_t dk_bspal_sigunit_shutdown( void );

/*!
@brief  programs the windows configuration setup in to shadow registers of Sig units (#0 or #1)
@param  win_id      - Evaluation Window Identifier
@param  p_swconf pointer to SSigUnitWinCfg_t Evaluation Window Configuration
@retval void
 */
extern int32_t dk_bspal_sigunit_eval_win_setup(uint8_t win_id, ts_SSigUnitWinCfg_t * p_swconf_SP);

/*
 ** Inspection APIs (neednot be invoked with in unlock() lock() pair)
 */
/*!
@brief 	This method is used to start the evaluation of window
@param  win_id      - Evaluation Window Identifier
@return int32_t Status of the start request
 */
extern int32_t dk_bspal_sigunit_eval_win_start(uint8_t eval_win_id);

/*!
@brief 	This method is used to stop the evaluation of window
@param  win_id      - Evaluation Window Identifier
@return int32_t Status of the stop request
 */
extern int32_t dk_bspal_sigunit_eval_win_stop(uint8_t eval_win_id);

/*!
@brief 	This method is used to commit the changes
@return int32_t Status of the commit request
 */
extern int32_t dk_bspal_sigunit_eval_win_commit( void );

/*!
@brief 	Read the CRC for RED GREEN BLUE channel(#0 or #1)
@param  win_id      - Evaluation Window Identifier
@retval Structure  Status of the evaluation request
 */
extern ts_SSigUnitGetWinStatus_t dk_bspal_sigunit_get_win_crc_sts(uint8_t eval_win_id);

#ifdef __cplusplus
}
#endif


#endif



