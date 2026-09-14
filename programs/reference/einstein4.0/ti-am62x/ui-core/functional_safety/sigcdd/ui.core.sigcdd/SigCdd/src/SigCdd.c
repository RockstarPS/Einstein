/*****************************************************************************
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
*******************************************************************************
**
** Name:           SigCdd.c
**
** Description:    This module maps the RTE interfaces to the Sevice layer interfaces.
**                 Also this implements the live cycle management of the CDD.
**
** Organization:   GUI Software Section, Visteon
**
*******************************************************************************
**
*****************************************************************************/
 
/*****************************************************************************
                            Include files
*****************************************************************************/
#include "Rte_CSigCdd.h"
#include "CmpLib.h"
#include "SigCdd_Cfg.h"
#include "SigMgrCdd.h"
#include <Os.h>

CMPLIB_INSTANCE(SigCdd)

/*****************************************************************************
                            Function Definitions
*****************************************************************************/
static Std_ReturnType CmpInit ( void )
{
    #ifndef SIGUNIT_INIT_ON_CMP_ACTIVATION
    SigMgr_sig_init();
    #endif
    return E_OK;
}

static Std_ReturnType CmpDeInit ( void )
{
	SigMgr_sig_deinit();
    return E_OK;
}

static Std_ReturnType CmpActive ( void )
{
    SigMgr_sig_task();
    return E_OK;
}

static Std_ReturnType CmpActivation ( void )
{
    #ifdef SIGUNIT_INIT_ON_CMP_ACTIVATION
    SigMgr_sig_init();
    #endif
    return E_OK;
}

static Std_ReturnType CmpDeActivation ( void )
{
    return E_OK;
}

#ifdef CMPLIB_WAKEUP_STATE_SUPPORT
#if (CMPLIB_WAKEUP_STATE_SUPPORT == 0x01)
static Std_ReturnType CmpWakeUp ( void )
{
    /*
    ** Update the static Configurations of the Signature unit here.
    */
    SigMgr_sig_init();
    return E_OK;
}
#endif
#endif

static Std_ReturnType CmpDiag ( void )
{
    return E_OK;
}

static Std_ReturnType CmpDiagReturn ( void )
{
    return E_OK;
}

/* RTE Call/Runnable for CRC data */
void CSigCdd_Impl_sig_get_win_crc_data(const SIG_WIN_INFO_T * p_sw_info, SIG_WIN_CRC_RGB_T * p_sw_crc_rgb)
{
    SigMgr_sig_get_win_crc_data(p_sw_info, p_sw_crc_rgb);
}


//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
// C M S    R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
//
// For each change to this file, be sure to record:
// 1.  Who made the change and when the change was made.
// 2.  Why the change was made and the intended result.
//
// CMS Rev #        Date            By
// CMS Rev X.X      dd-mmm-yyyy     CDSID
//
//---------------------------------------------------------------------------------------------------------------------
// 
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
