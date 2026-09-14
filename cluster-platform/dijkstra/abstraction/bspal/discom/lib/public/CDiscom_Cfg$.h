/*============================================================================
 **
 **  \file CDiscom_Cfg.h
 **
 **  \brief Interface to interact with the Discom of rcar-gen3
 **
 **  This file provides functional defines for a Discom module
 **
 **  Component Name: Discom
 **  Archive:
 **  Date: Feb 9 2022
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


#ifndef CDISCOM_CFG_H
#define CDISCOM_CFG_H

#include <stdint.h>
#include <stdbool.h>

#define  DISCOM_DEV_NAME "/dev/discom/dpy-1"         /* dev node for display id 1 */
#define  PIPELINE 2         /* pipeline for display id 1 */

#if 0
/* resmgr name */
#define RESMGR_NAME                     "discom/dpy-"
#define DEV_NAME                        "/dev/" RESMGR_NAME
#endif

/*============================================================================
 ** DISCOM D A T A   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

typedef struct {
    uint32_t    discom_hor_off;    // the horizontal offset
    uint32_t    discom_ver_off;    // the vertical offset
    uint32_t    discom_hor_size;   // the horizontal size
    uint32_t    discom_ver_size;   // the vertical size
} ts_SDiscomWinCfg_t;                   // the CRC calculation area in the image


typedef struct
{
    int         pipe;
    ts_SDiscomWinCfg_t      src;
    uint32_t    exp_crc;        // the expectation value of the CRC code
    uint32_t    cur_crc;        // the CRC value of current image
    bool       compare_result;    // the compare result of the CRC code
} ts_SDiscomGetWinStatus_t;

/*============================================================================
 ** SIGUNIT D A T A   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
typedef struct SSigUnitCrcRgb
{
    uint32_t red_U32;
    uint32_t green_U32;
    uint32_t blue_U32;
    uint32_t rgb_crc_U32;          /**< DISCOM combined CRC calculated by DISCOM module */
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

#define _DCMD_DISCOM                    _DCMD_MISC
#define DCMD_DISCOM_ATTACH              __DIOT (_DCMD_DISCOM, 1, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_DETACH              __DIOT (_DCMD_DISCOM, 2, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_SET_EXPECTED_CRC    __DIOT (_DCMD_DISCOM, 3, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_GET_CURRENT_CRC     __DIOTF (_DCMD_DISCOM, 4, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_COMPARE_VALUE       __DIOTF (_DCMD_DISCOM, 5, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_SOURCE_RECTANGLE    __DIOT (_DCMD_DISCOM, 6, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_START               __DIOT (_DCMD_DISCOM, 7, ts_SDiscomGetWinStatus_t)
#define DCMD_DISCOM_STOP                __DIOT (_DCMD_DISCOM, 8, ts_SDiscomGetWinStatus_t)

/** @} */ /* end of discom */
#endif /* DISCOM_H_ */
