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
 ** @Name           CSigUnit_DK_BSAPAL.c
 **
 ** @Description    This module will be useful to Read/Write the Signature
 **                 Unit related registers.
 **
 ** @Organization   GUI Software Section, Visteon
 **
 ** @Author         Nandakumar Elumalai
 **
 ** @Version
 ** 21OCT2024   | PKRISH12 |  TFDCX32348-50216 | Ported for TIAM62P - Linux platform. 
 **============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifdef LINUX_PLATFORM
#include <sys/ioctl.h>
#elif defined(QNX_PLATFORM)
#include <devctl.h>
#endif
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>

#include "dk_logger.h"
#include "CSigUnit_DK_BSPAL.h"

int32_t sig_fd;

LOG_DECLARE_CONTEXT ( g_log_bspal_sigunit );

static int32_t sigunit_open(uint8_t sig_unit_id);
static int32_t sigunit_close( void );

static int32_t sigunit_open(uint8_t sig_unit_id)
{
    uint8_t  devname_al_U8_[PATH_MAX + 1];
    int32_t l_status_sigopen_S32 = EOK;

    (void) snprintf((char *) devname_al_U8_, PATH_MAX, "/dev/sig%d", sig_unit_id);

    sig_fd = open((char *) devname_al_U8_, O_RDONLY);

    if(sig_fd != -1)
    {
        l_status_sigopen_S32 = EOK;
    }
    else
    {
        l_status_sigopen_S32 = -1;
        LOGE(&g_log_bspal_sigunit,"Failed to open '%d' ", sig_fd);
    }
    
    return l_status_sigopen_S32;
}

static int32_t sigunit_close( void )
{
    int32_t l_status_sigclose_S32 = EOK;

    if(0 == close(sig_fd))
    {
        l_status_sigclose_S32 = EOK;
    }

    return l_status_sigclose_S32;
}

int32_t dk_bspal_sigunit_initialize(uint8_t sig_unit_id, ts_SSigUnitCfg_t * p_sig_cfg_SP)
{
    int32_t l_status_siginit_S32 = EOK;

    LOG_REGISTER_CONTEXT ( g_log_bspal_sigunit, "BSPALSigUnit", "BSPAL_SIGUNIT_CONTEXT", DLT_LOG_VERBOSE );

    l_status_siginit_S32 = sigunit_open(sig_unit_id);
    if ( EOK != l_status_siginit_S32)
    {
        l_status_siginit_S32 = -1;
        LOGE(&g_log_bspal_sigunit,"Error with open() on /dev/sig%d.  Make sure it exists.", sig_unit_id);
    }
    else
    {
#ifdef LINUX_PLATFORM
		l_status_siginit_S32 = ioctl(sig_fd, SIG_UNIT_IOCTL_INITIALIZE, p_sig_cfg_SP); 
#elif defined(QNX_PLATFORM)
        l_status_siginit_S32 = devctl(sig_fd, SIG_UNIT_DCMD_INITIALIZE, p_sig_cfg_SP, sizeof(ts_SSigUnitCfg_t), NULL);
#endif
        if ( EOK != l_status_siginit_S32)
        {
            
            LOGE(&g_log_bspal_sigunit,"Error on Initialization Phase: %s", strerror( l_status_siginit_S32 ));
            l_status_siginit_S32 = -1;
        }
        else
        {
            /*MISRA*/
        }
    }
    return l_status_siginit_S32;
}


int32_t dk_bspal_sigunit_shutdown( void )
{
    int32_t l_status_sigshut_S32 = EOK;

#ifdef LINUX_PLATFORM	
	l_status_sigshut_S32 = ioctl(sig_fd, SIG_UNIT_IOCTL_SHUTDOWN);	
#elif defined(QNX_PLATFORM)	
    l_status_sigshut_S32 = devctl(sig_fd, SIG_UNIT_DCMD_SHUTDOWN, &l_status_sigshut_S32, sizeof(l_status_sigshut_S32), NULL);
#endif
    if ( EOK != l_status_sigshut_S32)
    {
        
        LOGE(&g_log_bspal_sigunit,"Error on Shutdown phase: %s", strerror ( l_status_sigshut_S32 ));
		l_status_sigshut_S32 = -1;
    }
    else
    {
        l_status_sigshut_S32 = sigunit_close();
    }

    LOG_UNREGISTER_CONTEXT ( g_log_bspal_sigunit );

    return l_status_sigshut_S32;
}

int32_t dk_bspal_sigunit_eval_win_setup(uint8_t win_id, ts_SSigUnitWinCfg_t * p_swconf_SP)
{
    int32_t l_status_winsetup_S32 = EOK;

    p_swconf_SP->eval_win_id_U8 = win_id;
#ifdef LINUX_PLATFORM	
	l_status_winsetup_S32 = ioctl(sig_fd, SIG_UNIT_IOCTL_EVAL_WIN_SETUP, p_swconf_SP);     
#elif defined(QNX_PLATFORM)	
	l_status_winsetup_S32 = devctl(sig_fd, SIG_UNIT_DCMD_EVAL_WIN_SETUP, p_swconf_SP, sizeof(ts_SSigUnitWinCfg_t), NULL);
#endif	
    if ( EOK != l_status_winsetup_S32)
    {
        
        LOGE(&g_log_bspal_sigunit,"Error in window%d setup phase: %s", win_id, strerror ( l_status_winsetup_S32 ));
		l_status_winsetup_S32 = -1;
    }

    return l_status_winsetup_S32;
}

int32_t dk_bspal_sigunit_eval_win_start(uint8_t eval_win_id)
{
    int32_t l_status_winstart_S32 = EOK;
#ifdef LINUX_PLATFORM	
	l_status_winstart_S32 = ioctl(sig_fd, SIG_UNIT_IOCTL_EVAL_WIN_START, &eval_win_id); 
#elif defined(QNX_PLATFORM)	
    l_status_winstart_S32 = devctl (sig_fd, SIG_UNIT_DCMD_EVAL_WIN_START, &eval_win_id, sizeof(eval_win_id), NULL);
#endif	
    if ( EOK != l_status_winstart_S32)
    {
      
        LOGE(&g_log_bspal_sigunit,"Error on window%d setup phase: %s", eval_win_id, strerror ( l_status_winstart_S32 ));
		l_status_winstart_S32 = -1;
    }

    return l_status_winstart_S32;
}

int32_t dk_bspal_sigunit_eval_win_stop(uint8_t eval_win_id)
{
    int32_t l_status_winstop_S32 = EOK;

#ifdef LINUX_PLATFORM	
	l_status_winstop_S32 = ioctl(sig_fd, SIG_UNIT_IOCTL_EVAL_WIN_STOP, &eval_win_id);	
#elif defined(QNX_PLATFORM)	
    l_status_winstop_S32 = devctl (sig_fd, SIG_UNIT_DCMD_EVAL_WIN_STOP, &eval_win_id, sizeof(eval_win_id), NULL);
#endif	
    if ( EOK != l_status_winstop_S32)
    {
  
        LOGE(&g_log_bspal_sigunit,"Error on window%d stop phase: %s", eval_win_id, strerror (l_status_winstop_S32));
		l_status_winstop_S32 = -1;
    }

    return l_status_winstop_S32;
}

ts_SSigUnitGetWinStatus_t dk_bspal_sigunit_get_win_crc_sts(uint8_t eval_win_id)
{
    int32_t l_status = EOK;
    ts_SSigUnitGetWinStatus_t sts = {0};
    sts.eval_win_id = eval_win_id;

#ifdef LINUX_PLATFORM	
	l_status = ioctl(sig_fd, SIG_UNIT_IOCTL_EVAL_WIN_GET_STS, &sts);
#elif defined(QNX_PLATFORM)	
    l_status = devctl (sig_fd, SIG_UNIT_DCMD_EVAL_WIN_GET_STS, &sts, sizeof(ts_SSigUnitGetWinStatus_t), NULL);
#endif
    if ( EOK != l_status)
    {
        LOGE(&g_log_bspal_sigunit,"Error on Status Phase: %s", strerror ( l_status ));
    }

    return sts;
}
