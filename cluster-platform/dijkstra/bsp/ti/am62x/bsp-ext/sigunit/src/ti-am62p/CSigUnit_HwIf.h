/*****************************************************************************/
/**
 * 
 *  \file CSigUnit_HwIf.h
 **
 ** \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
 **
 **  Component Name: Signature Unit
 **  Archive:
 **  Date: May 11 2020
 **  \author:
 **  
 **  | Date       | Author   |Description                                              |
 **  |------------|----------|--------------------------------                          |
 **  | 2020-08-02 |  RBABU9  | Create Initial Module.
 **  | 2023-09-13 | damudhar | Added Doxygen document
 **  | 2024-09-10 | damudhar | updated according to TI misr
 **
 ** \copyright 2019 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **
 ************************************************************************************/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef SIGUNIT_HWIF_H
#define SIGUNIT_HWIF_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CSigUnit_RM.h"
#include "CSigUnit_Cfg.h"

#define MISR_UNIT_0            (0U)
#define MISR_UNIT_1            (1U)
#define MISR_UNIT_2            (2U)
#define MISR_UNIT_3            (3U)
#define SIG_UNIT_MAX           (4U)
#define SIG_UNIT_EVAL_WIN_MAX  (4U)
#define SIG_PANIC_COLOR_MASK   (0xFFFFFF80U)/*!< Panic Colour Register is 25bits from MSB */
#define SIG_IDLE_STATUS_MASK   ((uint32_t)0x00100000)
#define SIG_ENABLE_EVWIN       ((uint32_t)0x01)      /*!<Bitmask for EnEvalWin)*/
#define SIG_ENABLE_CRC         ((uint32_t)0x02)      /*!<Bitmask for EnCRC*/
#define SIG_ENABLE_ALPHAMASK   ((uint32_t)0x100)     /*!<Bitmask for Alphamask*/
#define SIG_ENABLE_ALPHAINV    ((uint32_t)0x200)     /*!<Bitmask for AlphaInv*/
#define SIG_ENABLE_LOCALPANIC  ((uint32_t)0x10000)   /*!<Bitmask for EnLocalPanic*/
#define SIG_ENABLE_GLOBALPANIC ((uint32_t)0x20000)   /*!<Bitmask for EnGlobalPanic*/
#define SIG_WIN_CORDINATE_MASK ((uint16_t)0xFFF)     /*!< 14LSBs*/
#define ATTRIBUTE_MASK         ((uint32_t)0x1)       /*!< Mask for ENABLE at bit 0 */  /*!< Mask for CAPTUREMODE at bit 1 */ /*!< Mask for SEEDSELECT at bit 2 */ 
#define FRAMESKIP_MASK         ((uint32_t)0x3)       /*!< Mask for FRAMESKIP at bits 12-11 */
#define THRESHOLD_MASK         ((uint32_t)0xFF)      /*!< Mask for THRESHOLD at bits 10-3 */
/**********************************************************************************************************************
 *  STRUCTURE
 *********************************************************************************************************************/
/*!
 * \struct       ts_SSigUnitEvalWinReg_t
 * \brief        For Windows setup macros
 *  
 *  \var         ts_SSigUnitEvalWinReg_t::sig_eval_control_U32
 *  \brief       Eval_control registers cfg
 *  
 *  \var         ts_SSigUnitEvalWinReg_t::sig_eval_uppper_left_U32
 *  \brief       eval upper and left registers cfg
 *
 *  \var         ts_SSigUnitEvalWinReg_t::sig_eval_lower_right_U32
 *  \brief       eval lower and right registers cfg
 *  
 *  \var         ts_SSigUnitEvalWinReg_t::sig_crc_red_ref_U32
 *  \brief       To setup all windows to red crc register
 * 
 *  \var         ts_SSigUnitEvalWinReg_t::sig_crc_green_ref_U32
 *  \brief       To setup all windows to green crc register
 * 
 *  \var         ts_SSigUnitEvalWinReg_t::sig_crc_blue_ref_U32
 *  \brief       To setup all windows to blue crc register
 */
typedef struct
{
    uint32_t sig_eval_attr_U32;
    uint32_t sig_eval_win_pos_U32;
    uint32_t sig_crc_r_ref_U32;
    uint32_t sig_eval_win_size_U32;
    uint32_t sig_eval_lfsr_seed_U32;
} ts_SSigUnitEvalWinReg_t;


/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/
/*!**************************************************************************************************************
    * \fn         int32_t sigunit_initialize(const ts_sigunit_dev_t *pDev, const ts_SSigUnitCfg_t *p_SigUnitCfg_SP); 
    * \brief      Function to initialize signature unit
    * \return     l_sigInit_status_S32
    * \details    requirement ID 744947,744957
 ****************************************************************************************************************/

int32_t sigunit_initialize(const ts_sigunit_dev_t *pDev, const ts_SSigUnitCfg_t *p_SigUnitCfg_SP);

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_shutdown(const ts_sigunit_dev_t *pDev); 
    * \brief      Function to shutdown signature unit
    * \return     l_sigshutdown_status_S32
    * \details    requirement ID 744947,744953
 ****************************************************************************************************************/

int32_t sigunit_shutdown(const ts_sigunit_dev_t *pDev);

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_setup(const ts_sigunit_dev_t *pDev,  const ts_SSigUnitWinCfg_t *p_SigUnitWinCfg_SP);
    * \brief      Function to setup and evaluation window
    * \return     l_winsetup_status_S32
    * \details    requirement ID 744947,744958
 ****************************************************************************************************************/

int32_t sigunit_eval_win_setup(const ts_sigunit_dev_t *pDev,  const ts_SSigUnitWinCfg_t *p_SigUnitWinCfg_SP);

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_start(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
    * \brief      Function to start and evaluation window
    * \return     l_winstart_status_S32
    * \details    requirement ID 744947,744959
 ****************************************************************************************************************/

int32_t sigunit_eval_win_start(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_stop(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
    * \brief      Function to stop evaluation window by disabling continous mode
    * \return     l_winstop_status_S32
    * \details    requirement ID 744947,744960
 ****************************************************************************************************************/

int32_t sigunit_eval_win_stop(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_status(const ts_sigunit_dev_t *pDev, ts_SSigUnitGetWinStatus_t *p_SigUnitWinStatus_SP);
    * \brief      Function to get status of evaluation window
    * \return     l_winstatus_status_S32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/
int32_t sigunit_eval_win_status(const ts_sigunit_dev_t *pDev, ts_SSigUnitGetWinStatus_t *p_SigUnitWinStatus_SP);

bool sigunit_hw_init ( ts_sigunit_dev_t *p_sighwinit_SP );

bool sigunit_hw_fini ( const ts_sigunit_dev_t *p_sighwfini_SP );
#endif
