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
 ** Name:           SigMgrCdd.c
 **
 ** Description:
 **
 **
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
/************************** Start of Module *********************************/

/*****************************************************************************
                            Module Name
*****************************************************************************/

#define SIGMGRCDD_C

/*****************************************************************************
                            Include files
*****************************************************************************/
#include "SigCdd_Cfg.h"
#include "SigMgrCdd_cfg.h"
#include "SigMgrCdd.h"
#include "SigIfCdd.h"

/*****************************************************************************
                            Macro & Type Definitions
*****************************************************************************/
     
#ifdef GFX_USE_TIDSS_DRIVER
#define SIG_EV_WIN_INIT     {0U, 0U, 0U, 0U, 0U, 0U}
#else
#define SIG_EV_WIN_INIT     {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
#endif   

/*****************************************************************************
                            Static Variable Declarations
*****************************************************************************/
static uint8_t l_eval_is_enabled;
#ifndef GFX_USE_TIDSS_DRIVER
#if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
/* windows violation status*/
static uint8_t l_sig0_prev_win_status;
#endif
#if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
/* windows violation status*/
static uint8_t l_sig1_prev_win_status;
#endif
#endif

/*****************************************************************************
                            Static Function Declarations
*****************************************************************************/

static void SigMgr_sig_reset_config(SIG_WIN_SETUP_T* p_EvWindow);

/*****************************************************************************
                            Function Definitions
*****************************************************************************/
void SigMgr_sig_init(void)
{
    /*
    ** Update the static Configurations of the Signature unit here.
    */
    l_eval_is_enabled = (uint8_t)FALSE;
    #ifndef GFX_USE_TIDSS_DRIVER
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    /* initialize windows violation status with 0 */
    l_sig0_prev_win_status = 0U;
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    /* initialize windows violation status with 0 */
    l_sig1_prev_win_status = 0U;
    #endif
    #endif
    SigIf_sig_init();
}

void SigMgr_sig_deinit(void)
{
    SigIf_sig_deinit();
}

void SigMgr_sig_task(void)
{

    /*
    **  1. The input for Signature unit is Framegen o/p or Dither o/p or Gamma Correction o/p.
    **     The rendering o/p will be available in CmpActive state only.
    **     So, we can start the evaluation in this state.
    */
    
    EventMaskType EventMask = (EventMaskType)0;
    (void)GetEvent(SIG_OS_TASK, &EventMask);
    if ((EventMaskType)0 != (EventMask & Sig_Ev_NewConfigReady))
    {
        SIG_WIN_SETUP_T EvWindow = SIG_EV_WIN_INIT;

        #if (SIGNATURE_UNITS_TO_USE == 0)
        uint8_t fl_sig_unit = SIG_UNIT0;
        #elif (SIGNATURE_UNITS_TO_USE == 1)
        uint8_t fl_sig_unit = SIG_UNIT1;
        #else
        for (uint8_t fl_sig_unit = 0U; fl_sig_unit < MAX_SIG_UNITS; fl_sig_unit++)
        #endif
        {
            #ifdef GFX_USE_TIDSS_DRIVER
            #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
            #if (SIGNATURE_UNITS_TO_USE == 2)
            if (fl_sig_unit == SIG_UNIT0)
            #endif
            {
                /* Set Safety Window Config for VID Pipeline */
                SigMgr_sig_reset_config(&EvWindow);
                GET_SIG0_VID_WIN0_CONFIG_INPUT(&EvWindow);
                (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, 0U);
                
                /* Set Safety Window Config for VIDL Pipeline */
                SigMgr_sig_reset_config(&EvWindow);
                GET_SIG0_VIDL_WIN0_CONFIG_INPUT(&EvWindow);
                (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, 0U);
                
                /* Set Safety Window Config for Video Port */
                for (uint8_t fl_window = 0U; fl_window < MAX_WINDOWS; fl_window++)
                { 
                    SigMgr_sig_reset_config(&EvWindow);
                    #if (MAX_WINDOWS >= 4)
                    if (fl_window == WINDOW3)
                    {
                        GET_SIG0_VP_WIN3_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    #endif
                    #if (MAX_WINDOWS >= 3)
                    if (fl_window == WINDOW2)
                    {
                        GET_SIG0_VP_WIN2_CONFIG_INPUT(&EvWindow);
                    }
                    else                    
                    #endif    
                    #if (MAX_WINDOWS >= 2)
                    if (fl_window == WINDOW1)
                    {
                        GET_SIG0_VP_WIN1_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    #endif    
                    #if (MAX_WINDOWS >= 1)
                    { /* WINDOW0 */
                        GET_SIG0_VP_WIN0_CONFIG_INPUT(&EvWindow);   
                    }
                    #endif    
                    (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, fl_window);
                }
            }
            #endif
            #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
            #if (SIGNATURE_UNITS_TO_USE == 2)
            else /* (fl_sig_unit == SIG_UNIT1) */
            #endif
            {
                /* Set Safety Window Config for VID Pipeline */
                SigMgr_sig_reset_config(&EvWindow);
                GET_SIG1_VID_WIN0_CONFIG_INPUT(&EvWindow);
                (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, 0U);
                
                /* Set Safety Window Config for VIDL Pipeline */
                SigMgr_sig_reset_config(&EvWindow);
                GET_SIG1_VIDL_WIN0_CONFIG_INPUT(&EvWindow);
                (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, 0U);
                
                /* Set Safety Window Config for Video Port */
                for (uint8_t fl_window = 0U; fl_window < MAX_WINDOWS; fl_window++)
                {
                    SigMgr_sig_reset_config(&EvWindow);
                    #if (MAX_WINDOWS >= 4)
                    if (fl_window == WINDOW3)
                    {
                        GET_SIG1_VP_WIN3_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    #endif
                    #if (MAX_WINDOWS >= 3)
                    if (fl_window == WINDOW2)
                    {
                        GET_SIG1_VP_WIN2_CONFIG_INPUT(&EvWindow);
                    }
                    else                    
                    #endif    
                    #if (MAX_WINDOWS >= 2)
                    if (fl_window == WINDOW1)
                    {
                        GET_SIG1_VP_WIN1_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    #endif    
                    #if (MAX_WINDOWS >= 1)
                    { /* WINDOW0 */
                        GET_SIG1_VP_WIN0_CONFIG_INPUT(&EvWindow);   
                    }
                    #endif
                    (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, fl_window);
                }
            }
            #endif
            #else
            uint8_t fl_window;
            for (fl_window = 0U; fl_window < MAX_WINDOWS; fl_window++)
            {
                #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
                /* Signature unit - 0 and their evaluation windows */
                #if (SIGNATURE_UNITS_TO_USE == 2)
                if (fl_sig_unit == SIG_UNIT0)
                #endif
                {
                    if (fl_window == WINDOW0)
                    {
                        GET_SIG0_WIN0_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW1)
                    {
                        GET_SIG0_WIN1_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW2)
                    {
                        GET_SIG0_WIN2_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW3)
                    {
                        GET_SIG0_WIN3_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW4)
                    {
                        GET_SIG0_WIN4_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW5)
                    {
                        GET_SIG0_WIN5_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW6)
                    {
                        GET_SIG0_WIN6_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    {
                        /* (fl_window == WINDOW7) */
                        GET_SIG0_WIN7_CONFIG_INPUT(&EvWindow);
                    }
                }
                #endif
                #if (SIGNATURE_UNITS_TO_USE == 2)
                else
                #endif
                #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
                {
                    /* Signature unit - 1 and their evaluation windows */
                    if (fl_window == WINDOW0)
                    {
                        GET_SIG1_WIN0_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW1)
                    {
                        GET_SIG1_WIN1_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW2)
                    {
                        GET_SIG1_WIN2_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW3)
                    {
                        GET_SIG1_WIN3_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW4)
                    {
                        GET_SIG1_WIN4_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW5)
                    {
                        GET_SIG1_WIN5_CONFIG_INPUT(&EvWindow);
                    }
                    else if (fl_window == WINDOW6)
                    {
                        GET_SIG1_WIN6_CONFIG_INPUT(&EvWindow);
                    }
                    else
                    {
                        /* (fl_window == WINDOW7) */
                        GET_SIG1_WIN7_CONFIG_INPUT(&EvWindow);
                    }
                }
                #endif

                //---------------------------------------------------------------------------------------------------------------------
                //  @brief  See SigMgr description
                //  num_windows  --> How many evalution windows need to be setup
                //  SIG_WIN_SETUP_T **EvWindows  --> Array of Windows configurations
                //  if more than one signature unit is enabled then
                //  sig_unit  --> Which is the unit     
                //---------------------------------------------------------------------------------------------------------------------
                (void)SigIf_sig_set_ev_window((SIG_WIN_SETUP_T const *)&EvWindow, fl_sig_unit, fl_window);
                SigMgr_sig_reset_config(&EvWindow);
            }
            #ifdef GFX_USE_INFINEON_DRIVER
            (void)SigIf_sig_driver_commit(fl_sig_unit);
            #endif
            #endif
        }
        
        /* Atleast one evaluation window is configured hence enable below flag */
        l_eval_is_enabled = (uint8_t)TRUE;
        
        /* A new evaluation windows cfgs has been recieved, so clear the event Sig_Ev_NewConfigReady */
        (void)ClearEvent(EventMask & (Sig_Ev_NewConfigReady));
    }
    
    #ifndef GFX_USE_TIDSS_DRIVER
    if (l_eval_is_enabled != (uint8_t)FALSE)
    {
        #if (SIGNATURE_UNITS_TO_USE == 0)
        uint8_t fl_sig_unit = 0U;
        #elif (SIGNATURE_UNITS_TO_USE == 1)
        uint8_t fl_sig_unit = 1U;
        #endif
        #if (SIGNATURE_UNITS_TO_USE == 2)
        uint8_t fl_num_sig_units = MAX_SIG_UNITS;
        uint8_t fl_sig_unit = 0U;
        #endif
        uint8_t fl_windows_status;
        #ifdef GFX_USE_INFINEON_DRIVER
        (void)SigIf_sig_driver_monitoring();
        #endif
        /*
        ** See any windows violated the signatures
        */
        #if (SIGNATURE_UNITS_TO_USE == 2)
        for (; fl_sig_unit < fl_num_sig_units; fl_sig_unit++)
        #endif
        {
            #ifdef GFX_USE_INFINEON_DRIVER
            if(SigIf_sig_get_evaluation_status(fl_sig_unit) == 0xFFU)
            #endif
            {
                fl_windows_status = (uint8_t)SigIf_sig_get_windows_status(fl_sig_unit);
                #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
                #if (SIGNATURE_UNITS_TO_USE == 2)
                if (fl_sig_unit == SIG_UNIT0)
                #endif
                {
                    /* violation occur for some window, write data onto RTE and set an event */
                    if (fl_windows_status != l_sig0_prev_win_status)
                    {
                        SET_SIG0_WIN_VIOLATION_OUTPUT(fl_windows_status);
                        l_sig0_prev_win_status = fl_windows_status;
                    }
                }
                #endif
                #if (SIGNATURE_UNITS_TO_USE == 2)
                else
                #endif
                #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
                {
                    /* violation occur for some window, write data onto RTE and set an event */
                    if (fl_windows_status != l_sig1_prev_win_status)
                    {
                        SET_SIG1_WIN_VIOLATION_OUTPUT(fl_windows_status);
                        l_sig1_prev_win_status = fl_windows_status;
                    }
                }
                #endif
            }
        }
    }
    #endif
}

static void SigMgr_sig_reset_config(SIG_WIN_SETUP_T* p_EvWindow)
{
    p_EvWindow->control   = 0U;
    p_EvWindow->winsx     = 0U;
    p_EvWindow->winsy     = 0U;
    p_EvWindow->winex     = 0U;
    p_EvWindow->winey     = 0U;
    
    #ifdef GFX_USE_TIDSS_DRIVER
    p_EvWindow->control   = (SIG_EV_WIN_INVALID|SIG_EV_WIN_DISABLED);
    p_EvWindow->ref_crc   = 0U;
    #else
    p_EvWindow->control   = 0U;
    p_EvWindow->crc_ref_r = 0U;
    p_EvWindow->crc_ref_g = 0U;
    p_EvWindow->crc_ref_b = 0U;
    #endif
}

#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
uint32_t SigMgr_sig_get_win_status(SIG_WIN_INFO_T const* p_sw_info)
{
  uint32_t fl_status;

  if (p_sw_info != NULL)
  {
    if ((p_sw_info->sig_unit < MAX_SIG_UNITS) && (p_sw_info->window < MAX_WINDOWS))
    {
      fl_status = SigIf_sig_get_win_status(p_sw_info);
    }
    else
    {
      fl_status = 0U;
    }
  }
  else
  {
    fl_status = 0U;
  }
  return fl_status;
}
#endif

void SigMgr_sig_get_win_crc_data(SIG_WIN_INFO_T const * p_sw_info, SIG_WIN_CRC_RGB_T* p_sw_crc_rgb)
{
    if ((l_eval_is_enabled != (uint8_t)FALSE) && (p_sw_info != NULL) && (p_sw_crc_rgb != NULL))
    {
        if ((p_sw_info->sig_unit < MAX_SIG_UNITS) && (p_sw_info->window < MAX_WINDOWS))
        {
            SigIf_sig_get_win_crc_data(p_sw_info, p_sw_crc_rgb);
        }
    }
}

Std_ReturnType SigMgr_sig_stop_evaluation(uint8_t p_sig_unit)
{
    Std_ReturnType Ret = E_OK;

    if (p_sig_unit < MAX_SIG_UNITS)
    {
#if (SIGNATURE_UNITS_TO_USE == 0)
        SigIf_sig_stop_evaluation(0U);
#elif (SIGNATURE_UNITS_TO_USE == 1)
        SigIf_sig_stop_evaluation(1U);
#else
        SigIf_sig_stop_evaluation(p_sig_unit);
        l_eval_is_enabled = (uint8_t)FALSE;
#endif
    }
    else
    {
        Ret = E_NOT_OK;
    }
    
    return Ret;
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
