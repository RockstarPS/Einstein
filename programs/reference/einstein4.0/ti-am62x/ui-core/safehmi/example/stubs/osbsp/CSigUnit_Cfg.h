
/*============================================================================
 **
 **  \file CSigUnit_Cfg.h
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: May 11 2020
 **  Author: Dinakar Babu
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


#ifndef CSIGUNIT_CFG_H
#define CSIGUNIT_CFG_H

#include <stdint.h>

typedef struct SSigUnitCrcRgb
{
    uint32_t red_U32;
    uint32_t green_U32;
    uint32_t blue_U32;
} ts_SSigUnitCrcRgb_t;

typedef struct SSigUnitCfg
{
    uint8_t  error_threshold_U8;
    uint8_t  reset_threshold_U8;
    uint32_t panic_rgba_U32;
} ts_SSigUnitCfg_t;

/** Structure for setting up eval window with DCMD commands:
 *              - SIG_UNIT_DCMD_EVAL_WIN_SETUP
 */
typedef struct SSigUnitWinCfg
{
    uint8_t eval_win_id_U8;           /**< Eval window ID */
    uint16_t upperleft_x_U16;           /**< Upper left X-coordinate of the evaluation window */
    uint16_t upperleft_y_U16;           /**< Upper left Y-coordinate of the evaluation window */
    uint16_t lowerright_x_U16;          /**< Lower right X-coordinate of the evaluation window */
    uint16_t lowerright_y_U16;          /**< Lower right Y-coordinate of the evaluation window */
    uint8_t alpha_U8;                 /**< Evaluation window alpha handling */
    uint8_t action_U8;                /**< Action to be take in case of CRC mismatch */
    ts_SSigUnitCrcRgb_t ref_crc;      /**< Reference CRC for comparison */
} ts_SSigUnitWinCfg_t;


typedef struct SSigUnitCheck
{
    bool flag_sigunit_BOOL;
} ts_SSigUnitCheck_t;

typedef struct SSigUnitEvalWinCheck
{
    bool flag_evalwin_BOOL;
    bool flag_contmode_on_flag_BOOL;
} ts_SSigUnitEvalWinCheck_t;


/** Structure for getting eval window status with DCMD commands:
 *              - SIG_UNIT_DCMD_EVAL_WIN_GET_STS
 */
typedef struct SSigUnitGetWinStatus
{
    uint8_t eval_win_id;           /**< Eval window ID */
    uint32_t err_status_U32;            /**< Error Status. EOK - No Error */
    ts_SSigUnitCrcRgb_t crc;          /**< Calcuated CRC for RGB Channels */
} ts_SSigUnitGetWinStatus_t;

#define SIG_UNIT_DCMD_INITIALIZE       __DIOT (_DCMD_MISC, 1, ts_SSigUnitCfg_t)
#define SIG_UNIT_DCMD_SHUTDOWN         __DION (_DCMD_MISC, 2)

#define SIG_UNIT_DCMD_EVAL_WIN_SETUP   __DIOT (_DCMD_MISC, 3, ts_SSigUnitWinCfg_t)
#define SIG_UNIT_DCMD_EVAL_WIN_START   __DIOT (_DCMD_MISC, 4, uint8_t)
#define SIG_UNIT_DCMD_EVAL_WIN_STOP    __DIOT (_DCMD_MISC, 5, uint8_t)
#define SIG_UNIT_DCMD_EVAL_WIN_GET_STS __DIOTF(_DCMD_MISC, 6, ts_SSigUnitGetWinStatus_t)

/** @} */ /* end of sigunit */
#endif /* SIGUNIT_H_ */
