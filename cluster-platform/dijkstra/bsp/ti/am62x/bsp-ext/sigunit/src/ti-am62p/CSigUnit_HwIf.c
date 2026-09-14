/********************************************************************************************
 **
 **  \file CSigUnit_HwIf.c
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides functional defines for a Signature Unit module
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
 **==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>
#include <sys/mman.h>
#include <hw/inout.h>

#include "dk_logger.h"
#include "CSigUnit_HwIf.h"
//#include "CSigUnit_Registers.h"
#include "DSSRegisters.h"

LOG_IMPORT_CONTEXT ( gResMgrSigUnitLogContext );
#define TI_MISR    1

// Windows setup macros
static ts_SSigUnitEvalWinReg_t win_setup_reg_sa[]= { \
    { DSS_SAFETY_ATTRIBUTES_0_OFFSET, DSS_SAFETY_POSITION_0_OFFSET, DSS_SAFETY_REF_SIGNATURE_0_OFFSET, DSS_SAFETY_SIZE_0_OFFSET, DSS_SAFETY_LFSR_SEED_OFFSET}, \
    { DSS_SAFETY_ATTRIBUTES_1_OFFSET, DSS_SAFETY_POSITION_1_OFFSET, DSS_SAFETY_REF_SIGNATURE_1_OFFSET, DSS_SAFETY_SIZE_1_OFFSET, DSS_SAFETY_LFSR_SEED_OFFSET}, \
    { DSS_SAFETY_ATTRIBUTES_2_OFFSET, DSS_SAFETY_POSITION_2_OFFSET, DSS_SAFETY_REF_SIGNATURE_2_OFFSET, DSS_SAFETY_SIZE_2_OFFSET, DSS_SAFETY_LFSR_SEED_OFFSET}, \
    { DSS_SAFETY_ATTRIBUTES_3_OFFSET, DSS_SAFETY_POSITION_3_OFFSET, DSS_SAFETY_REF_SIGNATURE_3_OFFSET, DSS_SAFETY_SIZE_3_OFFSET, DSS_SAFETY_LFSR_SEED_OFFSET}, \

};

static void sigunit_set_port32(uintptr_t reg_addr, uint32_t data);
static uint32_t sigunit_get_port32(uintptr_t reg_addr);
static uint32_t sigunit_get_win_crc_r(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
#ifndef TI_MISR
static uint32_t sigunit_get_eval_win_status(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
static void sigunit_lock(const ts_sigunit_dev_t *pDev);
static uint32_t sigunit_get_win_crc_g(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
static uint32_t sigunit_get_win_crc_b(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8);
static void sigunit_unlock(const ts_sigunit_dev_t *pDev);
#endif
static ts_SSigUnitCheck_t sigunit_flag[SIG_UNIT_MAX];
static ts_SSigUnitEvalWinCheck_t evalwin_flag[SIG_UNIT_EVAL_WIN_MAX];

/*!**************************************************************************************************************
    * \fn         void sigunit_set_port32(uintptr_t reg_addr, uint32_t data)
    * \brief      Function to write a register.
    * \param      offset  Register address.
    * \param      data Data to be written into a register.
    * \details    requirement ID 744947
 ****************************************************************************************************************/
static void sigunit_set_port32(uintptr_t reg_addr, uint32_t data)
{
    out32(reg_addr, data); 
}
/*!**************************************************************************************************************
    * \fn         uint32_t sigunit_get_port32(uintptr_t reg_addr)
    * \brief      Function to read a register.
    * \param      offset  Register address.
    * \param      data Data to be read from a register.
    * \details    requirement ID 744947
 ****************************************************************************************************************/
static uint32_t sigunit_get_port32(uintptr_t reg_addr)
{
    uint32_t l_read_value_U32 = 1;
    l_read_value_U32 = in32(reg_addr);
    return l_read_value_U32;
}
#ifndef TI_MISR
/*!**************************************************************************************************************
    * \fn         uint32_t sigunit_get_eval_win_status(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
    * \brief      Function to get evaluation window status
    * \return     l_status_U32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/
static uint32_t sigunit_get_eval_win_status(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    uint32_t l_status_U32 = 0U;
    uint32_t l_sig_win_bit_U32 = 0U;
    uint32_t l_eval_win_error_status_U32 = 0U;

    l_sig_win_bit_U32 = (uint32_t)((uint8_t)0xFF & ((uint8_t) 1 << eval_win_id_U8 ));
    
    l_eval_win_error_status_U32 = sigunit_get_port32(pDev->regbase + (uintptr_t)DISENG_SIG_STATUS);
    //LOGI(&gResMgrSigUnitLogContext,"Eval Win ID %d & Eval Win Error Status %d", eval_win_id_U8, l_eval_win_error_status_U32);
    l_status_U32 = (l_eval_win_error_status_U32 & l_sig_win_bit_U32);

    if (l_status_U32 == l_sig_win_bit_U32)
    {
        l_status_U32 = 0x1;
        LOGE(&gResMgrSigUnitLogContext,"error status is set active on Window ID %d", eval_win_id_U8 );
    }
    else
    {
        l_status_U32 = 0x0;
        //LOGD(&gResMgrSigUnitLogContext,"No error on Window ID %d", eval_win_id_U8 );

    }
    return l_status_U32;
}
#endif
/*!**************************************************************************************************************
    * \fn         uint32_t sigunit_get_win_crc_r(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8) 
    * \brief      Function to get crc value for red region for user passed eval window
    * \return     l_ret_value_crc_r_U32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/
static uint32_t sigunit_get_win_crc_r(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    /* All Windows RED CRC registers */
    static const uintptr_t sig_crc_red_a[] = {  DSS_SAFETY_CAPT_SIGNATURE_0_OFFSET,
    DSS_SAFETY_CAPT_SIGNATURE_1_OFFSET,
    DSS_SAFETY_CAPT_SIGNATURE_2_OFFSET,
    DSS_SAFETY_CAPT_SIGNATURE_3_OFFSET
    };

    uint32_t l_ret_value_crc_r_U32 = 0;

    l_ret_value_crc_r_U32 = sigunit_get_port32( pDev->regbase + sig_crc_red_a[eval_win_id_U8]);
    LOGD(&gResMgrSigUnitLogContext,"CRC RGB Register val 0x%x Address for Window ID %d: 0x%x\n", l_ret_value_crc_r_U32, eval_win_id_U8, (pDev->regbase + sig_crc_red_a[eval_win_id_U8]));

    return l_ret_value_crc_r_U32;
}
#ifndef TI_MISR
/*!**************************************************************************************************************
    * \fn         uint32_t sigunit_get_win_crc_g(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
    * \brief      Function to get crc value for green region for user passed eval window
    * \return     l_ret_value_crc_g_U32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/
static uint32_t sigunit_get_win_crc_g(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    /* All Windows GREEN CRC registers */
    static const uintptr_t sig_crc_green_a[] = { DISENG_SIG_SIGCRCGREEN0, DISENG_SIG_SIGCRCGREEN1, DISENG_SIG_SIGCRCGREEN2, \
                                         DISENG_SIG_SIGCRCGREEN3, DISENG_SIG_SIGCRCGREEN4, DISENG_SIG_SIGCRCGREEN5, \
                                         DISENG_SIG_SIGCRCGREEN6, DISENG_SIG_SIGCRCGREEN7
                                       };

    uint32_t l_ret_value_crc_g_U32 = 0;

    l_ret_value_crc_g_U32 = sigunit_get_port32( pDev->regbase + sig_crc_green_a[eval_win_id_U8]);

    return l_ret_value_crc_g_U32;
}

/*!**************************************************************************************************************
    * \fn         uint32_t sigunit_get_win_crc_b(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
    * \brief      Function to get crc value for blue region for user passed eval window
    * \return     l_ret_value_crc_b_U32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/
static uint32_t sigunit_get_win_crc_b(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    /* All Windows BLUE CRC registers */
    static const uintptr_t sig_crc_blue_a[] = { DISENG_SIG_SIGCRCBLUE0, DISENG_SIG_SIGCRCBLUE1, DISENG_SIG_SIGCRCBLUE2, \
                                         DISENG_SIG_SIGCRCBLUE3, DISENG_SIG_SIGCRCBLUE4, DISENG_SIG_SIGCRCBLUE5, \
                                         DISENG_SIG_SIGCRCBLUE6, DISENG_SIG_SIGCRCBLUE7
                                       };


    uint32_t l_ret_value_crc_b_U32 = 0;

    l_ret_value_crc_b_U32 = sigunit_get_port32( pDev->regbase + sig_crc_blue_a[eval_win_id_U8]);

    return l_ret_value_crc_b_U32;
}
/*!**************************************************************************************************************
    * \fn         void sigunit_unlock(const ts_sigunit_dev_t *pDev)
    * \brief      Function to unlock signature unit
    * \return     void
    * \details    requirement ID 744947
 ****************************************************************************************************************/
static void sigunit_unlock(const ts_sigunit_dev_t *pDev)
{
    int8_t l_ret_sigunit_lock = 0;
    sigunit_set_port32( pDev->regbase + (uintptr_t)DISENG_SIG_LOCKUNLOCK, (uint32_t) DISENG_SIG_LOCKUNLOCK_unlock_key);
    return (void) l_ret_sigunit_lock;
}
/*!**************************************************************************************************************
    * \fn         void sigunit_lock(const ts_sigunit_dev_t *pDev)
    * \brief      Function to lock signature unit
    * \return     void
    * \details    requirement ID 744947
 ****************************************************************************************************************/
static void sigunit_lock(const ts_sigunit_dev_t *pDev)
{
    int8_t l_ret_sigunit_unlock = 0;
    sigunit_set_port32( pDev->regbase + (uintptr_t)DISENG_SIG_LOCKUNLOCK, (uint32_t) DISENG_SIG_LOCKUNLOCK_lock_key);
    return (void) l_ret_sigunit_unlock;
}
#endif
/*!**************************************************************************************************************
    * \fn         sigunit_initialize(const ts_sigunit_dev_t *pDev, const ts_SSigUnitCfg_t *p_SigUnitCfg_SP)
    * \brief      Function to initialize signature unit
    * \return     l_sigInit_status_S32
    * \details    requirement ID 744947,744957
 ****************************************************************************************************************/
int32_t sigunit_initialize(const ts_sigunit_dev_t *pDev, const ts_SSigUnitCfg_t *p_SigUnitCfg_SP)
{
#ifndef TI_MISR
    uint32_t l_reset_U32 = (uint32_t) p_SigUnitCfg_SP->reset_threshold_U8;
    uint32_t l_error_U32 = (uint32_t) p_SigUnitCfg_SP->error_threshold_U8;
    uint32_t l_threshold_U32 = (l_reset_U32 << 24) | (l_error_U32 << 16) | (uint32_t) 0x01;
#endif
    int32_t l_sigInit_status_S32 = EOK;
    if(SIG_UNIT_MAX > pDev->devnum_U8)
    {
        LOGD(&gResMgrSigUnitLogContext,"Initialize SigUnit:%d, error_threshold: %d, reset_threshold: %d, panic_rgba:%d",
                 pDev->devnum_U8, p_SigUnitCfg_SP->error_threshold_U8, p_SigUnitCfg_SP->reset_threshold_U8, p_SigUnitCfg_SP->panic_rgba_U32);
        /* Check if seedSelectEnable is 1 before setting the LFSR seed */		 
        if ( p_SigUnitCfg_SP->panic_rgba_U32 != 0)
        {
        // Writing the LFSR seed value for the entire MISR0
        sigunit_set_port32(pDev->regbase + (uintptr_t)DSS_SAFETY_LFSR_SEED_OFFSET, p_SigUnitCfg_SP->panic_rgba_U32);
        LOGD(&gResMgrSigUnitLogContext,"sigunit_misr_setup LFSR Seed Address 0x%x and value 0x%x\n",
        pDev->regbase + DSS_SAFETY_LFSR_SEED_OFFSET, p_SigUnitCfg_SP->panic_rgba_U32);
        }
#ifndef TI_MISR
        /* To unlock the Signature Unit*/
//        sigunit_unlock(pDev);
        /*Set the input Source Select point for signature unit#0 as after Frame Generator*/
         sigunit_set_port32(dev->regbase + (uintptr_t)DISENG_DISENGCFG_SRCSELECT0, (p_sig_setup->sig_setup.source & SIG_SOURCE_MASK));
        /*Set panic RGBA colour values.*/
        sigunit_set_port32(pDev->regbase + (uintptr_t)DISENG_SIG_PANICCOLOR, (p_SigUnitCfg_SP->panic_rgba_U32 & SIG_PANIC_COLOR_MASK));
        /*Set ShdEn(Bit0) and ShdLdSel(Bit4) as LOCAL(0-default) in Static Control Register along with threshold values.*/
        sigunit_set_port32(pDev->regbase + (uintptr_t)DISENG_SIG_STATICCONTROL, l_threshold_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)DISENG_SIG_CONTINUOUSMODE, (uint32_t) 0u);
#endif
        sigunit_flag[pDev->devnum_U8].flag_sigunit_BOOL = true;
        /* To lock the Signature Unit*/
//        sigunit_lock(pDev);
    }
    else
    {
        l_sigInit_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid SigUnit ID %d", pDev->devnum_U8 );
    }
    return l_sigInit_status_S32;
}
/*!**************************************************************************************************************
    * \fn         int32_t sigunit_shutdown(const ts_sigunit_dev_t *pDev)
    * \brief      Function to shutdown signature unit
    * \return     l_sigshutdown_status_S32
    * \details    requirement ID 744947,744953
 ****************************************************************************************************************/
int32_t sigunit_shutdown(const ts_sigunit_dev_t *pDev)
{
    int32_t l_sigshutdown_status_S32 = EOK;
    if(SIG_UNIT_MAX > pDev->devnum_U8)
    {
        /* coverity[memory_access] : FALSE */
        if(true == sigunit_flag[pDev->devnum_U8].flag_sigunit_BOOL)
        {
            LOGD(&gResMgrSigUnitLogContext,"Shutdown SigUnit : %d ", pDev->devnum_U8);
#ifndef TI_MISR
            /* To unlock the Signature Unit*/
            sigunit_unlock(pDev);
            sigunit_set_port32(pDev->regbase + (uintptr_t)DISENG_SIG_CONTINUOUSMODE, (uint32_t) 0u);
            /*Poll StsSigIdle status field until unit is idle.
               StsSigIdle(Bit#20) = 1: Signature is in Idle state(default). StsSigIdle = 0: Signature runs.
             */
            while ((sigunit_get_port32(pDev->regbase + (uintptr_t)DISENG_SIG_STATUS) & (uintptr_t)SIG_IDLE_STATUS_MASK) == (uint32_t) 0)
            {
                ;
            }
            /* coverity[memory_access] : FALSE */
            sigunit_flag[pDev->devnum_U8].flag_sigunit_BOOL = false;
            /* To lock the Signature Unit*/
//            sigunit_lock(pDev);
#endif
        }
        else
        {
            l_sigshutdown_status_S32 = -1;
            LOGW(&gResMgrSigUnitLogContext,"Signature Unit %d has not initialized ",pDev->devnum_U8);
        }
    }
    else
    {
        l_sigshutdown_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid SigUnit ID %d", pDev->devnum_U8 );
    }
    return l_sigshutdown_status_S32;
}
/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_setup(const ts_sigunit_dev_t *pDev, const ts_SSigUnitWinCfg_t *p_SigUnitWinCfg_SP)
    * \brief      Function to setup and evaluation window
    * \return     l_winsetup_status_S32
    * \details    requirement ID 744947,744958
 ****************************************************************************************************************/
int32_t sigunit_eval_win_setup(const ts_sigunit_dev_t *pDev, const ts_SSigUnitWinCfg_t *p_SigUnitWinCfg_SP)
{
    int32_t l_winsetup_status_S32 = EOK;
    uint32_t l_eval_ctrl_U32 = 0;
    uint16_t l_width_U16 = 0;
    uint16_t l_height_U16 = 0;
#ifndef TI_MISR
    uint32_t l_ret_value_crc_size_U32 = 0;
    /* Eval_control registers cfg */
    static const uint32_t sig_action_crtl[3] = { 0x0, 0x10002, 0x20002};
    static const uint32_t sig_alpha_crtl[3] = { 0x0, 0x100, 0x200};
    uint32_t l_eval_ctrl_U32 = (SIG_ENABLE_EVWIN | SIG_ENABLE_CRC | SIG_ENABLE_ALPHAMASK
                                | SIG_ENABLE_ALPHAINV | SIG_ENABLE_LOCALPANIC | SIG_ENABLE_GLOBALPANIC);
    l_eval_ctrl_U32 &= (sig_alpha_crtl[p_SigUnitWinCfg_SP->alpha_U8] | sig_action_crtl[p_SigUnitWinCfg_SP->action_U8]);
    // Set the ENABLE, CAPTUREMODE, and SEEDSELECT bits using ATTRIBUTE_MASK
    l_eval_ctrl_U32 |= (p_SigUnitWinCfg_SP->safetyChkEnable_U8 & ATTRIBUTE_MASK) << 0; // ENABLE at bit 0
    l_eval_ctrl_U32 |= (p_SigUnitWinCfg_SP->safetyChkMode_U8 & ATTRIBUTE_MASK) << 1; // CAPTUREMODE at bit 1
    l_eval_ctrl_U32 |= (p_SigUnitWinCfg_SP->seedSelectEnable_U8 & ATTRIBUTE_MASK) << 2; // SEEDSELECT at bit 2
#endif
    // Set the FRAMESKIP bits
    l_eval_ctrl_U32 |= (p_SigUnitWinCfg_SP->action_U8 & FRAMESKIP_MASK) << 11; // FRAMESKIP at bits 12-11
    // Set the THRESHOLD bits
    l_eval_ctrl_U32 |= (p_SigUnitWinCfg_SP->alpha_U8 & THRESHOLD_MASK) << 3; // THRESHOLD at bits 10-3
    l_width_U16 = p_SigUnitWinCfg_SP->lowerright_x_U16 - p_SigUnitWinCfg_SP->upperleft_x_U16;
    l_height_U16 = p_SigUnitWinCfg_SP->lowerright_y_U16 - p_SigUnitWinCfg_SP->upperleft_y_U16;
    if(p_SigUnitWinCfg_SP->eval_win_id_U8 < SIG_UNIT_EVAL_WIN_MAX)
    {
        LOGD(&gResMgrSigUnitLogContext,"Setup Eval Window SigUnit:%d, WinId: %d, Co-ordinates: (%d, %d), (%d, %d), alpha_U8: 0x%x, action_U8: %d",
                pDev->devnum_U8, p_SigUnitWinCfg_SP->eval_win_id_U8, p_SigUnitWinCfg_SP->upperleft_x_U16, p_SigUnitWinCfg_SP->upperleft_y_U16, p_SigUnitWinCfg_SP->lowerright_x_U16,
                p_SigUnitWinCfg_SP->lowerright_y_U16, p_SigUnitWinCfg_SP->alpha_U8, p_SigUnitWinCfg_SP->action_U8);
        //LOG_INFO("safetyChkEnable_U8: 0x%x, safetyChkMode_U8: 0x%x, seedSelectEnable_U8: 0x%x",		
        //p_SigUnitWinCfg_SP->safetyChkEnable_U8, p_SigUnitWinCfg_SP->safetyChkMode_U8, p_SigUnitWinCfg_SP->seedSelectEnable_U8);
        LOGD(&gResMgrSigUnitLogContext,"ref_crc.red_U32: 0x%x, ref_crc.green_U32: 0x%x, ref_crc.blue_U32: 0x%x",
                 p_SigUnitWinCfg_SP->ref_crc.red_U32, p_SigUnitWinCfg_SP->ref_crc.green_U32, p_SigUnitWinCfg_SP->ref_crc.blue_U32);
        /* Write to the evaluation control register */
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_attr_U32, l_eval_ctrl_U32);
        LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup sig_eval_control_U32 Address 0x%x and value 0x%x\n", 
                  pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_attr_U32, 
                  l_eval_ctrl_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_pos_U32,
                           ((((uint32_t) p_SigUnitWinCfg_SP->upperleft_y_U16 & SIG_WIN_CORDINATE_MASK) << 16) |
                            ((uint32_t) p_SigUnitWinCfg_SP->upperleft_x_U16 & SIG_WIN_CORDINATE_MASK)));
        LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup sig_eval_win_pos_U32 Address 0x%x and value 0x%x\n", pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_pos_U32,
                           ((((uint32_t) p_SigUnitWinCfg_SP->upperleft_y_U16 & SIG_WIN_CORDINATE_MASK) << 16) |
                            ((uint32_t) p_SigUnitWinCfg_SP->upperleft_x_U16 & SIG_WIN_CORDINATE_MASK)));
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_size_U32,
                           ((((uint32_t) l_height_U16 & SIG_WIN_CORDINATE_MASK)<< 16)  |
                            ((uint32_t) l_width_U16 & SIG_WIN_CORDINATE_MASK)));
        LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup sig_eval_win_size_U32 Address 0x%x and value 0x%x\n", pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_size_U32,
                           ((((uint32_t) l_height_U16 & SIG_WIN_CORDINATE_MASK) << 16) |
                            ((uint32_t) l_width_U16 & SIG_WIN_CORDINATE_MASK)));
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_r_ref_U32, p_SigUnitWinCfg_SP->ref_crc.red_U32);
        LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup sig_crc_r_ref_U32 Address 0x%x and value 0x%x\n",
                  pDev->regbase + win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_r_ref_U32,
                  p_SigUnitWinCfg_SP->ref_crc.red_U32);
        /* Mark eval window ready to start  */
        evalwin_flag[p_SigUnitWinCfg_SP->eval_win_id_U8].flag_evalwin_BOOL = true;
#ifndef TI_MISR
        /* To unlock the Signature Unit*/
        sigunit_unlock(pDev);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_control_U32, l_eval_ctrl_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_red_ref_U32, p_SigUnitWinCfg_SP->ref_crc.red_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_green_ref_U32, p_SigUnitWinCfg_SP->ref_crc.green_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_blue_ref_U32, p_SigUnitWinCfg_SP->ref_crc.blue_U32);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_crc_rgb_ref_U32, p_SigUnitWinCfg_SP->ref_crc.rgb_crc_U32);
        LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup value 0x%x Address 0x%x\n", sigunit_get_port32( pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_pos_U32),pDev->regbase + (uintptr_t)win_setup_reg_sa[p_SigUnitWinCfg_SP->eval_win_id_U8].sig_eval_win_pos_U32 );
        /* To lock the Signature Unit*/
        sigunit_lock(pDev);
#endif
    }
    else
    {
        l_winsetup_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid Window ID %d", p_SigUnitWinCfg_SP->eval_win_id_U8);
    }
    return l_winsetup_status_S32;
}
/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_start(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
    * \brief      Function to start and evaluation window
    * \return     l_winstart_status_S32
    * \details    requirement ID 744947,744959
 ****************************************************************************************************************/
int32_t sigunit_eval_win_start(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    int32_t l_status_S32 = EOK;
    uint8_t l_win_id_U8 = 0;

    if(eval_win_id_U8 < SIG_UNIT_EVAL_WIN_MAX)
    {
        if( true == evalwin_flag[eval_win_id_U8].flag_evalwin_BOOL )
        {
            LOGI(&gResMgrSigUnitLogContext,"Start Evaluation Window SigUnit:%d, WinId: %d", pDev->devnum_U8, eval_win_id_U8);
            sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[l_win_id_U8].sig_eval_attr_U32,
                               (ATTRIBUTE_MASK << 0) | (ATTRIBUTE_MASK << 1)); // Set bits 0 and 1
            LOGD(&gResMgrSigUnitLogContext,"sigunit_eval_win_setup sig_eval_control_U32 Address 0x%x and value 0x%x\n",pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_attr_U32,
                               (ATTRIBUTE_MASK << 0) | (ATTRIBUTE_MASK << 1));
            (void)usleep(10);
#ifndef TI_MISR
            uint8_t l_shadow_load_req_U8 = 0;
            /* To unlock the Signature Unit*/
            sigunit_unlock(pDev);

            /* coverity[cert_int30_c_violation] : FALSE */
            sigunit_set_port32((pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_control_U32), sigunit_get_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_control_U32) | (uint32_t) 0x1);
            /* coverity[cert_int31_c_violation] : FALSE */
            l_shadow_load_req_U8 = ((uint8_t)0xFF & ((uint8_t) 1 << eval_win_id_U8 ));
            /* coverity[cert_int30_c_violation] : FALSE */
            sigunit_set_port32(pDev->regbase + (uintptr_t) DISENG_SIG_SHADOWLOAD, (uint32_t) l_shadow_load_req_U8);
            /* coverity[cert_int30_c_violation] : FALSE */
            sigunit_set_port32((pDev->regbase) + (uintptr_t)(DISENG_SIG_CONTINUOUSMODE), (uint32_t) 1u);
            evalwin_flag[eval_win_id_U8].flag_contmode_on_flag_BOOL = true;
#endif
            evalwin_flag[eval_win_id_U8].flag_evalwin_BOOL = false;
            /* To lock the Signature Unit*/
//            sigunit_lock(pDev);
        }
        else
        {
            l_status_S32 = -1;
            LOGE(&gResMgrSigUnitLogContext,"Window of ID%d has not setup ", eval_win_id_U8);
        }
    }
    else if(eval_win_id_U8 == 0xFFU)
    {
        //sigunit_unlock(pDev);
        for( l_win_id_U8 = 0; l_win_id_U8 < SIG_UNIT_EVAL_WIN_MAX; l_win_id_U8++ )
        {
            if( true == evalwin_flag[l_win_id_U8].flag_evalwin_BOOL )
            {
                LOGI(&gResMgrSigUnitLogContext,"Start Evaluation Window SigUnit:%d, WinId: %d", pDev->devnum_U8, l_win_id_U8);
                sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_attr_U32, 
                               (ATTRIBUTE_MASK << 0) | (ATTRIBUTE_MASK << 1)); // Set bits 0 and 1
                (void)usleep(10);
                evalwin_flag[l_win_id_U8].flag_evalwin_BOOL = false;
#ifndef TI_MISR
            sigunit_set_port32((pDev->regbase + (uintptr_t)win_setup_reg_sa[l_win_id_U8].sig_eval_control_U32), sigunit_get_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[l_win_id_U8].sig_eval_control_U32) | (uint32_t) 0x1);
             l_shadow_load_req_U8 = (l_shadow_load_req_U8 | ((uint8_t)1 << l_win_id_U8));
             evalwin_flag[l_win_id_U8].flag_contmode_on_flag_BOOL = true;
             /* coverity[cert_int30_c_violation] : FALSE */
             sigunit_set_port32((pDev->regbase) + (uintptr_t)(DISENG_SIG_CONTINUOUSMODE), (uint32_t) 1u);
             /* coverity[cert_int30_c_violation] : FALSE */
             sigunit_set_port32(pDev->regbase + (uintptr_t) DISENG_SIG_SHADOWLOAD, (uint32_t) l_shadow_load_req_U8);
#endif
            }
        }

//sigunit_lock(pDev);
    }
    else
    {
        l_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid Window ID %d, ", eval_win_id_U8);
    }

    return l_status_S32;
}

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_stop(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
    * \brief      Function to stop evaluation window by disabling continous mode
    * \return     l_winstop_status_S32
    * \details    requirement ID 744947,744960
 ****************************************************************************************************************/

int32_t sigunit_eval_win_stop(const ts_sigunit_dev_t *pDev, uint8_t eval_win_id_U8)
{
    int32_t l_status_S32 = EOK;
    if(eval_win_id_U8 < SIG_UNIT_EVAL_WIN_MAX)
    {
        LOGI(&gResMgrSigUnitLogContext,"Stop Evaluation Window SigUnit:%d, WinId: %d", pDev->devnum_U8, eval_win_id_U8);

        /* To unlock the Signature Unit */
        // sigunit_unlock(pDev);
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_win_pos_U32, 0);
        
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_win_size_U32, 0);
        // Clear both ENABLE bit (bit 0) and CAPTUREMODE bit (bit 1)
        uint32_t current_val = sigunit_get_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_attr_U32);
        uint32_t cleared_val = current_val & ~((ATTRIBUTE_MASK << 0) | (ATTRIBUTE_MASK << 1)); // Clear bits 0 and 1

        // Write back the cleared value
        sigunit_set_port32(pDev->regbase + (uintptr_t)win_setup_reg_sa[eval_win_id_U8].sig_eval_attr_U32, cleared_val);

        evalwin_flag[eval_win_id_U8].flag_evalwin_BOOL = false;
        /* To lock the Signature Unit */
        // sigunit_lock(pDev);
    }
    else
    {
        l_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid Window ID %d", eval_win_id_U8);
    }

    return l_status_S32;
}

/*!**************************************************************************************************************
    * \fn         int32_t sigunit_eval_win_status(const ts_sigunit_dev_t *pDev, ts_SSigUnitGetWinStatus_t *p_SigUnitWinStatus_SP)
    * \brief      Function to get status of evaluation window
    * \return     l_winstatus_status_S32
    * \details    requirement ID 744947,744961
 ****************************************************************************************************************/

int32_t sigunit_eval_win_status(const ts_sigunit_dev_t *pDev, ts_SSigUnitGetWinStatus_t *p_SigUnitWinStatus_SP)
{
    int32_t l_winstatus_status_S32 = EOK;
    // Log the function entry and parameters
    LOGD(&gResMgrSigUnitLogContext,"Entering sigunit_eval_win_status. SigUnit: %d, EvalWinID: %d", pDev->devnum_U8, p_SigUnitWinStatus_SP->eval_win_id);
    if(p_SigUnitWinStatus_SP->eval_win_id < SIG_UNIT_EVAL_WIN_MAX)
    {
#ifndef TI_MISR
        /* coverity[memory_access] : FALSE */
        if(true == evalwin_flag[p_SigUnitWinStatus_SP->eval_win_id].flag_contmode_on_flag_BOOL)
        {
           LOGD(&gResMgrSigUnitLogContext,"Get Evaluation Window Status SigUnit:%d, WinId: %d", pDev->devnum_U8, p_SigUnitWinStatus_SP->eval_win_id);
           p_SigUnitWinStatus_SP->err_status_U32 =  (uint32_t)sigunit_get_eval_win_status(pDev, p_SigUnitWinStatus_SP->eval_win_id);
           p_SigUnitWinStatus_SP->crc.red_U32 = (uint32_t)sigunit_get_win_crc_r(pDev, p_SigUnitWinStatus_SP->eval_win_id);
            /* coverity[memory_access] : FALSE */
           p_SigUnitWinStatus_SP->crc.green_U32 = (uint32_t)sigunit_get_win_crc_g(pDev, p_SigUnitWinStatus_SP->eval_win_id);
            /* coverity[memory_access] : FALSE */
           p_SigUnitWinStatus_SP->crc.blue_U32 = (uint32_t)sigunit_get_win_crc_b(pDev, p_SigUnitWinStatus_SP->eval_win_id);
           LOGD(&gResMgrSigUnitLogContext,"win_sts: 0x%x, crc.red_U32: 0x%x, crc.green_U32: 0x%x, crc.blue_U32: 0x%x", p_SigUnitWinStatus_SP->err_status_U32,
           p_SigUnitWinStatus_SP->crc.red_U32, p_SigUnitWinStatus_SP->crc.green_U32, p_SigUnitWinStatus_SP->crc.blue_U32); 
        }
        else
        {
           l_winstatus_status_S32 = -1;
           LOGE(&gResMgrSigUnitLogContext,"Eval Window not started with continous mode %d", p_SigUnitWinStatus_SP->eval_win_id );
        }
        
        // Retrieve and log CRC values from the hardware
           p_SigUnitWinStatus_SP->err_status_U32 = (uint32_t)sigunit_get_eval_win_status(pDev, p_SigUnitWinStatus_SP->eval_win_id);
#endif
        LOGD(&gResMgrSigUnitLogContext,"Get Evaluation Window Status SigUnit:%d, WinId: %d", pDev->devnum_U8, p_SigUnitWinStatus_SP->eval_win_id);
        p_SigUnitWinStatus_SP->crc.red_U32 = (uint32_t)sigunit_get_win_crc_r(pDev, p_SigUnitWinStatus_SP->eval_win_id);

        // Final log before returning
        LOGI(&gResMgrSigUnitLogContext,"Final Combined RGB: 0x%x",p_SigUnitWinStatus_SP->crc.red_U32);
    }
    else
    {
        l_winstatus_status_S32 = -1;
        LOGE(&gResMgrSigUnitLogContext,"Invalid Window ID %d", p_SigUnitWinStatus_SP->eval_win_id );
    }
    return l_winstatus_status_S32;
}
