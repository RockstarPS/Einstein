/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2018. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** @defgroup      Dijkstra BSPAL
 **
 ** @file          CSigUnit_DK_BSAPAL.h
 **
 ** @brief         Interfaces for interaction with BSPAL Signature Unit Peripheral
 **
 ** @ingroup       Dijkstra BSPAL
 **
 ** @Organization  GUI Software Section, Visteon
 **============================================================================
 **
 **==========================================================================*/
#ifndef CSIGUNIT_DK_BSPAL_H_
#define CSIGUNIT_DK_BSPAL_H_

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "CSigUnit_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/*============================================================================
 ** D A T A   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

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
@brief 	Read the CRC for RED GREEN BLUE channel(#0 or #1)
@param  win_id      - Evaluation Window Identifier
@retval Structure  Status of the evaluation request
 */
extern ts_SSigUnitGetWinStatus_t dk_bspal_sigunit_get_win_crc_sts(uint8_t eval_win_id);

/*end of file =============================================================*/

#ifdef __cplusplus
}
#endif


#endif



