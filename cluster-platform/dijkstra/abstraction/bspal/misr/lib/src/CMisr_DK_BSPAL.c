/*============================================================================
 **
 **  \file CMisr_DK_BSPAL.c
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
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <devctl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>

#include "CMisr_Cfg.h"
#include "CMisr_DK_BSPAL_Debug.h"

ts_SDiscomGetWinStatus_t discom_temp_sts_S = { 0 };

int32_t discom_fd_U32;

#if 0
static int32_t sigunit_open( void );
static int32_t sigunit_close( void );

/**********************************************************************************
  @brief API to open DISCOM dev node
  @param[in] void

  @return EOK on Success.
 ***********************************************************************************/
static int32_t sigunit_open()
{
    int32_t l_status_discomopen_S32 = EOK;

    discom_fd_U32 = open((char *) DISCOM_DEV_NAME, O_RDONLY);

    if(discom_fd_U32 != -1)
    {
        l_status_discomopen_S32 = EOK;
    }
    else
    {
        l_status_discomopen_S32 = -1;
        LOG_ERROR("Failed to open '%s' ", DISCOM_DEV_NAME);
    }

    return l_status_discomopen_S32;
}

/**********************************************************************************
  @brief API to close DISCOM dev node
  @param[in] void

  @return EOK on Success.
 ***********************************************************************************/
static int32_t sigunit_close( void )
{
    int32_t l_status_discomclose_S32 = EOK;

    if(0 == close(discom_fd_U32))
    {
        l_status_discomclose_S32 = EOK;
    }

    return l_status_discomclose_S32;
}
#endif
/**********************************************************************************
  @brief API to initialize DISCOM module
  @param[in] sig_unit_id    Not used, to maintain signature same sigunit bspal.
  @param[in] p_sig_cfg_SP    Not used, to maintain signature same sigunit bspal.

  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_initialize(uint8_t sig_unit_id, ts_SSigUnitCfg_t * p_sig_cfg_SP)
{
    int32_t l_status_attach_S32 = EOK;

    l_status_attach_S32 = qcom_misr_init();
    if ( EOK != l_status_attach_S32)
    {
        l_status_attach_S32 = -1;
        LOG_ERROR("Error qcom_misr_init");
        qcom_misr_terminate();
    }

    return l_status_attach_S32;
}

/**********************************************************************************
  @brief API to detach DISCOM module
  @param[in] void

  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_shutdown( void )
{
    int32_t l_status_detach_S32 = EOK;
    l_status_detach_S32 = qcom_misr_terminate();
    if ( EOK != l_status_detach_S32)
    {
        l_status_detach_S32 = -1;
        LOG_ERROR("Error on qcom_misr_terminate");
    }
    return l_status_detach_S32;
}

/**********************************************************************************
  @brief API to setup ROI for DISCOM module
  @param[in] win_id    Not used, to maintain signature same sigunit bspal.
  @param[in] p_swconf_SP    struct ptr with ROI data.

  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_eval_win_setup(uint8_t win_id, ts_SSigUnitWinCfg_t * p_swconf_SP)
{
    int32_t l_status_winsetup_S32 = EOK;

    l_status_winsetup_S32 = qcom_misr_set_roi_crc(win_id,p_swconf_SP);
    if ( EOK != l_status_winsetup_S32)
    {
        l_status_winsetup_S32 = -1;
        LOG_ERROR("Error in qcom_misr_set_roi_crc");
        qcom_misr_terminate();
    }

    return l_status_winsetup_S32;
}

/**********************************************************************************
  @brief API commit the configuration in DISCOM module
  @param[in] eval_win_id    Not used, to maintain signature same sigunit bspal.
  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_eval_win_commit( void )
{
    int32_t l_status_wincommit_S32 = EOK;
    l_status_wincommit_S32 = qcom_misr_commit();
    if ( EOK != l_status_wincommit_S32)
    {
        l_status_wincommit_S32 = -1;
        LOG_ERROR("Error on qcom_misr_commit");
        qcom_misr_terminate();
    }
    return l_status_wincommit_S32;
}

/**********************************************************************************
  @brief API start execution of DISCOM module
  @param[in] eval_win_id    Not used, to maintain signature same sigunit bspal.

  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_eval_win_start(uint8_t eval_win_id)
{
    int32_t l_status_winstart_S32 = EOK;
#if 0
    l_status_winstart_S32 = qcom_misr_get_roi_info();
    if ( EOK != l_status_winstart_S32)
    {
        l_status_winstart_S32 = -1;
        LOG_ERROR("Error on qcom_misr_get_roi_info");
    }
#endif
    return l_status_winstart_S32;
}

/**********************************************************************************
  @brief API stop execution of DISCOM module
  @param[in] eval_win_id    Not used, to maintain signature same sigunit bspal.

  @return EOK on Success.
 ***********************************************************************************/
int32_t dk_bspal_sigunit_eval_win_stop(uint8_t eval_win_id)
{
    int32_t l_status_winstop_S32 = EOK;
    l_status_winstop_S32 = qcom_misr_stop(eval_win_id);
    if ( EOK != l_status_winstop_S32)
    {
        l_status_winstop_S32 = -1;
        LOG_ERROR("Error on stop phase: %s", strerror ( l_status_winstop_S32 ));
    }
    return l_status_winstop_S32;
}

/**********************************************************************************
  @brief API read the calulated CRC from DISCOM module.
  @param[in] eval_win_id    Not used, to maintain signature same sigunit bspal.

  @return ts_SSigUnitGetWinStatus_t struct with calulated CRC data.
 ***********************************************************************************/
ts_SSigUnitGetWinStatus_t dk_bspal_sigunit_get_win_crc_sts(uint8_t eval_win_id)
{
    int32_t l_status_crc_sts_S32 = EOK;
    ts_SSigUnitGetWinStatus_t sts;

    l_status_crc_sts_S32 = qcom_misr_get_roi_crc(eval_win_id);
    if ( EOK == l_status_crc_sts_S32)
    {
        LOG_ERROR("Error on qcom_misr_get_roi_crc");
    }
    else
    {
        sts.err_status_U32  = EOK;
        sts.crc.rgb_crc_U32 = l_status_crc_sts_S32;
    }

    return sts;
}

