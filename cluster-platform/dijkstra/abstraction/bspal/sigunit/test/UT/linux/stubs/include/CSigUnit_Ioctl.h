
/*============================================================================
 **
 **  \file CSigUnit_Cfg.h
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module.
 **  The file is shared between kernel and user space.
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: August 2022
 **  Author: Lidiya Nikolova
 **
 ** Copyright 2022 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 ** @Version
 ** 21OCT2024   | SSOMASU1,PKRISH12  |  TFDCX32348-50216 | Ported for TIAM62P - Linux platform. 
 **==========================================================================*/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef CSIGUNIT_CFG_H
#define CSIGUNIT_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#ifdef __KERNEL__
    #include <linux/types.h>  
#else
    #include <stdint.h> 
	#include <stdbool.h>
#endif

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/
#define EOK 0 


/**********************************************************************************************************************
 *  STRUCTURE
 *********************************************************************************************************************/
/*!
 * \struct       ts_SSigUnitCrcRgb_t
 * \brief        To get evaluation window status
 *  
 *  \var         ts_SSigUnitCrcRgb_t::red_U32
 *  \brief       variable to get crc value for red region for user passed eval window
 *  
 *  \var         ts_SSigUnitCrcRgb_t::green_U32
 *  \brief       variable to get crc value for green region for user passed eval window
 *
 *  \var         ts_SSigUnitCrcRgb_t::blue_U32
 *  \brief       variable to get crc value for blue region for user passed eval window
 */
typedef struct
{
    uint32_t red_U32;/**< final MISR combined CRC calculated by MISR_DSS module */
    uint32_t green_U32;
    uint32_t blue_U32;
} ts_SSigUnitCrcRgb_t;

/*!
 * \struct        ts_SSigUnitCfg_t
 * \brief         To config the error and reset
 *
 * \var           ts_SSigUnitCfg_t::error_threshold_U8
 * \brief         To config the error
 * 
 * \var           ts_SSigUnitCfg_t::reset_threshold_U8
 * \brief         To config reset
 */
typedef struct
{
    uint8_t  error_threshold_U8;
    uint8_t  reset_threshold_U8;
    uint32_t panic_rgba_U32;           /**< configures the lfsr_seed [initial value] of the MISR. Otherwise, the MISR is initialized with 0xFFFF_FFFF */
} ts_SSigUnitCfg_t;


 /*! 
 * \struct      ts_SSigUnitWinCfg_t(SIG_UNIT_DCMD_EVAL_WIN_SETUP)
 * \brief       Structure for setting up eval window with DCMD commands
 *  
 * \var         ts_SSigUnitWinCfg_t::eval_win_id_U8     
 * \brief       Eval window ID
 * 
 * \var         ts_SSigUnitWinCfg_t::upperleft_x_U16
 * \brief       Upper left X-coordinate of the evaluation window
 * 
 * \var         ts_SSigUnitWinCfg_t::upperleft_y_U16
 * \brief       Upper left Y-coordinate of the evaluation window
 * 
 * \var         ts_SSigUnitWinCfg_t::lowerright_x_U16
 * \brief       Lower right X-coordinate of the evaluation window
 * 
 * \var         ts_SSigUnitWinCfg_t::lowerright_y_U16
 * \brief       Lower right Y-coordinate of the evaluation window
 * 
 * \var         ts_SSigUnitWinCfg_t::alpha_U8
 * \brief       Evaluation window alpha handling
 * 
 * \var         ts_SSigUnitWinCfg_t::action_U8
 * \brief       Action to be take in case of CRC mismatch
 * 
 * \var         ts_SSigUnitWinCfg_t::ref_crc
 * \brief       Reference CRC for comparison
 */
typedef struct
{
    uint8_t eval_win_id_U8;           /**< Eval window ID */
    uint16_t upperleft_x_U16;           /**< Upper left X-coordinate of the evaluation window */
    uint16_t upperleft_y_U16;           /**< Upper left Y-coordinate of the evaluation window */
    uint16_t lowerright_x_U16;          /**< Lower right X-coordinate of the evaluation window */
    uint16_t lowerright_y_U16;          /**< Lower right Y-coordinate of the evaluation window */
    uint8_t alpha_U8;                 /**< Evaluation window alpha handling */	/**< THRESHOLD */
    uint8_t action_U8;                /**< Action to be take in case of CRC mismatch */ /**< Indicates which frames to be skipped while doing FRAMEFREEZE or DATACHECK */
    ts_SSigUnitCrcRgb_t ref_crc;      /**< Reference CRC for comparison */
    //uint8_t safetyChkEnable_U8;            /**< safety check enable/disable */
   // uint8_t safetyChkMode_U8;            /**< safety mode FRAMESKIP/CAPTUREMODE */
   // uint8_t seedSelectEnable_U8;            /**< Initial seed selection control */                        
} ts_SSigUnitWinCfg_t;


typedef struct
{
    bool flag_sigunit_BOOL;
} ts_SSigUnitCheck_t;

typedef struct
{
    bool flag_evalwin_BOOL;
    bool flag_contmode_on_flag_BOOL;
} ts_SSigUnitEvalWinCheck_t;


/*! 
 * \struct      ts_SSigUnitGetWinStatus_t
 * \brief       Structure for getting eval window status with DCMD commands:
 *  
 * \var         ts_SSigUnitGetWinStatus_t::eval_win_id     
 * \brief       Eval window ID
 * 
 * \var         ts_SSigUnitGetWinStatus_t::err_status_U32
 * \brief       Error Status. EOK - No Error
 * 
 * \var         ts_SSigUnitGetWinStatus_t::crc
 * \brief       Calcuated CRC for RGB Channels
 */
typedef struct
{
    uint8_t eval_win_id;           /**< Eval window ID */
    uint32_t err_status_U32;            /**< Error Status. EOK - No Error */
    ts_SSigUnitCrcRgb_t crc;          /**< Calcuated CRC for RGB Channels */
} ts_SSigUnitGetWinStatus_t;

/* The 'magic' number for our driver.
 * It has to be verified against every new Linux release which is integrated for this OEM program.
 * Check the following file, check that this magic number still remains free.
 * Documentation/ioctl/ioctl-number.rst
 */
#define SIG_UNIT_IOCTL_MAGIC		0xC1

/** The maximum number of accepted ioctl commands:
 */
#define	SIG_UNIT_IOCTL_MAXIOCTL    7

#define SIG_UNIT_IOCTL_INITIALIZE       _IOW (SIG_UNIT_IOCTL_MAGIC, 1, ts_SSigUnitCfg_t)
#define SIG_UNIT_IOCTL_SHUTDOWN         _IO  (SIG_UNIT_IOCTL_MAGIC, 2)
#define SIG_UNIT_IOCTL_EVAL_WIN_SETUP   _IOW (SIG_UNIT_IOCTL_MAGIC, 3, ts_SSigUnitWinCfg_t)
#define SIG_UNIT_IOCTL_EVAL_WIN_START   _IOW (SIG_UNIT_IOCTL_MAGIC, 4, uint8_t)
#define SIG_UNIT_IOCTL_EVAL_WIN_STOP    _IOW (SIG_UNIT_IOCTL_MAGIC, 5, uint8_t)
#define SIG_UNIT_IOCTL_EVAL_WIN_GET_STS _IOWR(SIG_UNIT_IOCTL_MAGIC, 6, ts_SSigUnitGetWinStatus_t)
#define SIG_UNIT_IOCTL_SHDLDREQ_SET     _IOW (SIG_UNIT_IOCTL_MAGIC, 7, uint8_t)

/** @} */ /* end of sigunit */
#endif /* SIGUNIT_H_ */
