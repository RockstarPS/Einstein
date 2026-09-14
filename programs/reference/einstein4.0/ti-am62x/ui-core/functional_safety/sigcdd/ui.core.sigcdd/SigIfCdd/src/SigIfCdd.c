/******************************************************************************
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
** Name:           SigIfCdd.c
**
** Description:    This hardware abstraction layer of the Signature CDD.
**
** Organization:   GUI Software Section, Visteon
**
*******************************************************************************
**
*******************************************************************************/
 
/************************** Start of Module ***********************************/

/******************************************************************************
                            Module Name
*******************************************************************************/

#define SIGIFCDD_C

/******************************************************************************
                            Include files
******************************************************************************/

#include "Rte_CSigCdd.h"
#include "SigCdd_Cfg.h"
#include "SigIfCdd.h"

#if defined(GFX_USE_INFINEON_DRIVER)
#include "CyFssig_Types.h"
#include "CyFssig.h"
#elif defined(GFX_USE_TIDSS_DRIVER)
#include <drivers/dss.h>
#include <drivers/fvid2.h>
#include <kernel/dpl/AddrTranslateP.h>
#include "ti_drivers_open_close.h"
#include "ti_drivers_config.h"
#endif

/*****************************************************************************
                            Type Definitions
*****************************************************************************/

/*****************************************************************************
                            Static Variable Declarations
*****************************************************************************/

/*****************************************************************************
                            Function Definitions
*****************************************************************************/

void SigIf_sig_init(void)
{
#if defined(GFX_USE_INFINEON_DRIVER)
    const cyfssig_pb_config_type pbData =
    {
        .tagPbConfig_Pre = CYFSSIG_PB_CFG_PRE_TAG,
        .tconChecksum =
        {
           0xEA74566C,
           0x0UL
        },
        .tagPbConfig_Post = CYFSSIG_PB_CFG_POST_TAG
    };
    (void)CyFssig_DrvInit(&pbData);
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    const cyfssig_sig_error_threshold_type errThres1 =
    {
        .resetThreshold = SIG0_ERROR_THRESHOLD_RESET_VALUE,
        .setThreshold = SIG0_ERROR_THRESHOLD_VALUE
    };
    (void)CyFssig_SigSetErrorThreshold(CYFSSIG_DISPLAY_STREAM_ID_0, &errThres1);
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    const cyfssig_sig_error_threshold_type errThres2 =
    {
        .resetThreshold = SIG1_ERROR_THRESHOLD_RESET_VALUE,
        .setThreshold = SIG1_ERROR_THRESHOLD_VALUE
    };
    (void)CyFssig_SigSetErrorThreshold(CYFSSIG_DISPLAY_STREAM_ID_1, &errThres2);
    #endif
#elif defined(GFX_USE_TIDSS_DRIVER)  
    #if (SIGNATURE_UNITS_TO_USE == 0)
        uint8_t fl_sig_unit = SIG_UNIT0;
    #elif (SIGNATURE_UNITS_TO_USE == 1)
        uint8_t fl_sig_unit = SIG_UNIT1;
    #else
        for (uint8_t fl_sig_unit = 0U; fl_sig_unit < MAX_SIG_UNITS; fl_sig_unit++)
    #endif
        {
            /* The initialization of the TIDSS driver is managed by Gfx_Mgr02 (GDT Engine)
            ** Therefore, the only required action here is to start window evaluation for CRC 
            */
            
            Dss_Object *fl_DssObjPtr = &gDssObjects[fl_sig_unit];   /* DSS Object Pointer */
            
            for (uint8_t fl_pipelineId = 0U; fl_pipelineId < (uint8_t)gDssConfigPipelineParams.numTestPipes; fl_pipelineId++)
            {
                if (gDssConfigPipelineParams.safetyCheck[fl_pipelineId] == (uint8_t)TRUE)
                {
                    Dss_DispPipeSafetyChkParams *flPipeSafetyParams = &fl_DssObjPtr->instObj[fl_pipelineId].safetyParams;
                    Dss_dispPipeSafetyChkParamsInit(flPipeSafetyParams);
                    
                    flPipeSafetyParams->safetyChkCfg.safetyChkMode      = CSL_DSS_SAFETY_CHK_DATA_INTEGRITY;
                    flPipeSafetyParams->safetyErrCbFxn                  = NULL;
                }
            }
            
            for (uint8_t fl_vp_subregion = 0U; fl_vp_subregion < MAX_WINDOWS; fl_vp_subregion++)
            {
                Dss_DctrlVpSafetyChkParams *flVPSafetyParams = (Dss_DctrlVpSafetyChkParams*)&fl_DssObjPtr->vpSafetyParams[fl_vp_subregion];
                Dss_dctrlVpSafetyChkParamsInit(flVPSafetyParams);
                
                flVPSafetyParams->vpId                                             = gDssVpParams.vpId;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.safetyChkMode    = CSL_DSS_SAFETY_CHK_DATA_INTEGRITY;
                flVPSafetyParams->regionSafetyChkCfg.regionId                      = fl_vp_subregion;
                flVPSafetyParams->safetyErrCbFxn                                   = NULL;
            }
        }
#else
#if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    SIG_SETUP_T StaticCfg;
    iris_sigdrv_sig0_unlock();
    StaticCfg.source          = SIG_UNIT0_INPUT;
    StaticCfg.panic_rgba      = SIG0_PANIC_COLOUR;
    StaticCfg.error_threshold = SIG0_ERROR_THRESHOLD_VALUE;
    StaticCfg.reset_threshold = SIG0_ERROR_THRESHOLD_RESET_VALUE;
    StaticCfg.unused          = (uint8_t)0;
    iris_sigdrv_sig0_initialize(((SIG_SETUP_T const *)&StaticCfg));
    iris_sigdrv_sig0_lock();
#elif (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    iris_sigdrv_sig1_unlock(SIG_UNIT1);
    StaticCfg.source          = SIG_UNIT1_INPUT;
    StaticCfg.panic_rgba      = SIG1_PANIC_COLOUR;
    StaticCfg.error_threshold = SIG1_ERROR_THRESHOLD_VALUE;
    StaticCfg.reset_threshold = SIG1_ERROR_THRESHOLD_RESET_VALUE;
    StaticCfg.unused          = (uint8_t)0;
    iris_sigdrv_sig1_initialize(((SIG_SETUP_T const *)&StaticCfg));
    iris_sigdrv_sig1_lock();
#endif
#endif
}

void SigIf_sig_deinit(void)
{
#if defined(GFX_USE_INFINEON_DRIVER)
    (void)CyFssig_DrvDeInit();
#elif defined(GFX_USE_TIDSS_DRIVER)
    #if (SIGNATURE_UNITS_TO_USE == 0)
    uint8_t fl_sig_unit = 0U;
    #elif (SIGNATURE_UNITS_TO_USE == 1)
    uint8_t fl_sig_unit = 1U;
    #else
    for (uint8_t fl_sig_unit = 0U; fl_sig_unit < MAX_SIG_UNITS; fl_sig_unit++)
    #endif
    {
        
        /* The deinitialization of the TIDSS driver is managed by Gfx_Mgr02.
        ** Therefore, the only required action here is to stop window evaluation for CRC 
        */
        
        SigIf_sig_stop_evaluation(fl_sig_unit);
    }
#else
#if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    iris_sigdrv_sig0_uninitialize();
#elif (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    iris_sigdrv_sig1_uninitialize();
#endif
#endif
}

/*
** New Dynamic Configurations are ready. 
** So, Update the Signature Unit and their windows registers accordingly.
*/
Std_ReturnType_t SigIf_sig_set_ev_window(SIG_WIN_SETUP_T const *EvWindow, uint8_t p_sig_unit, uint8_t p_window)
{
    Std_ReturnType_t Ret = E_OK_t;
#if defined(GFX_USE_INFINEON_DRIVER)
    SigIf_sig_setup_win(((SIG_WIN_SETUP_T const *)EvWindow), p_sig_unit, p_window);
    /*
      SigIf_sig_ldcfg_win is not required for Infineon driver
      Shadow load enabled during commit in infineon driver
      CyFssig_DrvCommit->
        CyFssig_SigInternalCommit->
          CyFssig_RaSigRequestShadowLoad --> Set shadow load enabled for all windows
    */
#elif defined(GFX_USE_TIDSS_DRIVER)
    SigIf_sig_setup_win(((SIG_WIN_SETUP_T const *)EvWindow), p_sig_unit, p_window);
#else  
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    if(p_sig_unit == SIG_UNIT0)
    {
        iris_sigdrv_sig0_unlock();
        iris_sigdrv_sig0_clear_cnt_mode();
        SigIf_sig_setup_win(((SIG_WIN_SETUP_T const *)EvWindow),p_sig_unit,p_window);
        SigIf_sig_ldcfg_win(p_sig_unit,p_window);
        iris_sigdrv_sig0_set_cnt_mode();
        iris_sigdrv_sig0_lock();
    }
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 2)
    else
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    {
        iris_sigdrv_sig1_unlock();
        iris_sigdrv_sig1_clear_cnt_mode();
        SigIf_sig_setup_win(EvWindows,p_sig_unit,p_window);
        SigIf_sig_ldcfg_win(p_sig_unit,p_window);
        iris_sigdrv_sig1_set_cnt_mode();
        iris_sigdrv_sig1_lock();
    }
    #endif
#endif /* GFX_USE_INFINEON_DRIVER */
    return Ret;
}

/*! 
\brief programs the win0 configurations in to shadow registers of Sig unit
\param p_swconf pointer to 	SIG_WIN_SETUP_T
\retval void
*/
void SigIf_sig_setup_win(SIG_WIN_SETUP_T const * const p_swconf, uint8_t p_sig_unit, uint8_t p_window)
{
#if defined(GFX_USE_INFINEON_DRIVER)
  const cyfssig_sig_win_position_type winPos =
  {
      .topLeftX = p_swconf->winsx,
      .topLeftY = p_swconf->winsy,
      .width    = (p_swconf->winex - p_swconf->winsx),
      .height   = (p_swconf->winey - p_swconf->winsy)
  };

  if ((winPos.width > 0U) && (winPos.height > 0U))
  {
    /* Reference checksum: should match the window size and the background color. */
    const cyfssig_sig_signature_type refSig =
    {
      .sigRed   = p_swconf->crc_ref_r,
      .sigGreen = p_swconf->crc_ref_g,
      .sigBlue  = p_swconf->crc_ref_b
    };
    //CyFssig_SigEnableWinEvaluation - CYFSSIG_RA_SIG_ENEVALWIN_MASK, CYFSSIG_RA_SIG_ENCRC_MASK
    if ((p_swconf->control & SIG_ENABLE_EVWIN) == SIG_ENABLE_EVWIN)
      (void)CyFssig_SigEnableWinEvaluation(p_sig_unit, p_window);
    else
      (void)CyFssig_SigDisableWinEvaluation(p_sig_unit, p_window);

    //CyFssig_SigSetWinAlphaMaskMode - CYFSSIG_RA_SIG_ALPHAMASK_MASK, CYFSSIG_RA_SIG_ALPHAINV_MASK
    if ((p_swconf->control & SIG_ENABLE_ALPHAMASK) == SIG_ENABLE_ALPHAMASK)
      (void)CyFssig_SigSetWinAlphaMaskMode(p_sig_unit, p_window, TRUE);
    else
      (void)CyFssig_SigSetWinAlphaMaskMode(p_sig_unit, p_window, FALSE);

    (void)CyFssig_SigSetWinPosition(p_sig_unit, p_window, &winPos);
    (void)CyFssig_SigSetWinRefSignature(p_sig_unit, p_window, &refSig);
  }
#elif defined(GFX_USE_TIDSS_DRIVER)
    Dss_Object *fl_DssObjPtr = &gDssObjects[p_sig_unit];   /* DSS Object Pointer */
    
    if (((p_swconf->control & SIG_EV_WIN_TYPE_MASK) == SIG_EV_WIN_VID) || \
        ((p_swconf->control & SIG_EV_WIN_TYPE_MASK) == SIG_EV_WIN_VIDL))
    {
        uint8_t fl_pipelineId;
        
        /* fl_pipeWinType => Safety Window that is located at Pipeline End
         * 0: VID Pipe Win, 1: VIDL Pipe Win */
        uint8_t fl_pipeWinType = (uint8_t)(((p_swconf->control & SIG_EV_WIN_TYPE_MASK) >> 4U) - 1U); 

        if (gDssConfigPipelineParams.numTestPipes == 1U)
        {
            fl_pipelineId = (gDssConfigPipelineParams.pipeId[0] == fl_pipeWinType) ? (0U) : ((uint8_t)gDssConfigPipelineParams.numTestPipes);
        }
        else if (gDssConfigPipelineParams.numTestPipes == 2U)
        {
            fl_pipelineId = fl_pipeWinType;
        }
        else
        {
            fl_pipelineId = (uint8_t)gDssConfigPipelineParams.numTestPipes;
        }
        
        if ((fl_pipelineId < (uint8_t)gDssConfigPipelineParams.numTestPipes) && \
            (gDssConfigPipelineParams.safetyCheck[fl_pipelineId] == (uint8_t)TRUE))
        {
            Dss_DispPipeSafetyChkParams *flPipeSafetyParams     = &fl_DssObjPtr->instObj[fl_pipelineId].safetyParams;
            
            if((p_swconf->control & SIG_EV_WIN_ENABLED) == SIG_EV_WIN_ENABLED)
            {
                flPipeSafetyParams->safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_ENABLED;
                flPipeSafetyParams->safetyChkCfg.regionPos.startX   = p_swconf->winsx;
                flPipeSafetyParams->safetyChkCfg.regionPos.startY   = p_swconf->winsy;
                flPipeSafetyParams->safetyChkCfg.regionSize.width   = (p_swconf->winex > p_swconf->winsx) ? ((uint32_t)p_swconf->winex - (uint32_t)p_swconf->winsx) : (0U);
                flPipeSafetyParams->safetyChkCfg.regionSize.height  = (p_swconf->winey > p_swconf->winsy) ? ((uint32_t)p_swconf->winey - (uint32_t)p_swconf->winsy) : (0U);
                flPipeSafetyParams->referenceSign                   = (uint32_t)p_swconf->ref_crc;
            }
            else /* SIG_EV_WIN_DISABLED */
            {
                flPipeSafetyParams->safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_DISABLED;
                flPipeSafetyParams->safetyChkCfg.regionPos.startX   = 0;
                flPipeSafetyParams->safetyChkCfg.regionPos.startY   = 0;
                flPipeSafetyParams->safetyChkCfg.regionSize.width   = 0U;
                flPipeSafetyParams->safetyChkCfg.regionSize.height  = 0U;
                flPipeSafetyParams->referenceSign                   = 0U; 
            }

            (void) Fvid2_control(fl_DssObjPtr->instObj[fl_pipelineId].drvHandle, 
                                        IOCTL_DSS_DISP_SET_PIPE_SAFETY_CHK_PARAMS, 
                                        flPipeSafetyParams, NULL);
        }
    }
    else if ((p_swconf->control & SIG_EV_WIN_TYPE_MASK) == SIG_EV_WIN_VP)
    {
        uint8_t fl_vp_subregion = p_window;
        
        if (fl_vp_subregion < MAX_WINDOWS)
        {
            Dss_DctrlVpSafetyChkParams *flVPSafetyParams = (Dss_DctrlVpSafetyChkParams*)&fl_DssObjPtr->vpSafetyParams[fl_vp_subregion];
            
            if((p_swconf->control & SIG_EV_WIN_ENABLED) == SIG_EV_WIN_ENABLED)
            {
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_ENABLED;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startX   = p_swconf->winsx;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startY   = p_swconf->winsy;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.width   = (p_swconf->winex > p_swconf->winsx) ? ((uint32_t)p_swconf->winex - (uint32_t)p_swconf->winsx) : (0U);
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.height  = (p_swconf->winey > p_swconf->winsy) ? ((uint32_t)p_swconf->winey - (uint32_t)p_swconf->winsy) : (0U);
                flVPSafetyParams->regionSafetyChkCfg.referenceSign                   = (uint32_t)p_swconf->ref_crc;
            }
            else /* SIG_EV_WIN_DISABLED */
            {
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_DISABLED;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startX   = 0;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startY   = 0;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.width   = 0U;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.height  = 0U;
                flVPSafetyParams->regionSafetyChkCfg.referenceSign                   = 0U; 
            }
            
            (void) Fvid2_control(fl_DssObjPtr->dctrlHandle, IOCTL_DSS_DCTRL_SET_VP_SAFETY_CHK_PARAMS, flVPSafetyParams, NULL);
        }
    }
    else
    {
        /* Invalid Configuration passed by the application for safety window type */
    }
#else
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    /* Signature unit - 0 and their evaluation windows */
    if(p_sig_unit == SIG_UNIT0)
    {
         if(p_window == WINDOW0)
         {
           iris_sigdrv_sig0_setup_win0(p_swconf);
         }
         else if(p_window == WINDOW1)
         {
           iris_sigdrv_sig0_setup_win1(p_swconf);
         }
         else if(p_window == WINDOW2)
         {
           iris_sigdrv_sig0_setup_win2(p_swconf);
         }
         else if(p_window == WINDOW3)
         {
           iris_sigdrv_sig0_setup_win3(p_swconf);
         }
         else if(p_window == WINDOW4)
         {
           iris_sigdrv_sig0_setup_win4(p_swconf);
         }
         else if(p_window == WINDOW5)
         {
           iris_sigdrv_sig0_setup_win5(p_swconf);
         }
         else if(p_window == WINDOW6)
         {
           iris_sigdrv_sig0_setup_win6(p_swconf);
         }
         else if(p_window == WINDOW7)
         {
           iris_sigdrv_sig0_setup_win7(p_swconf);
         }
         else
         {
           /* Do nothing */
         }
    }
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 2)
    else
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    {
         /* Signature unit - 1 and their evaluation windows */
         if(p_window == WINDOW0)
         {
           iris_sigdrv_sig1_setup_win0(p_swconf);
         }
         else if(p_window == WINDOW1)
         {
           iris_sigdrv_sig1_setup_win1(p_swconf);
         }
         else if(p_window == WINDOW2)
         {
           iris_sigdrv_sig1_setup_win2(p_swconf);
         }
         else if(p_window == WINDOW3)
         {
           iris_sigdrv_sig1_setup_win3(p_swconf);
         }
         else if(p_window == WINDOW4)
         {
           iris_sigdrv_sig1_setup_win4(p_swconf);
         }
         else if(p_window == WINDOW5)
         {
           iris_sigdrv_sig1_setup_win5(p_swconf);
         }
         else if(p_window == WINDOW6)
         {
           iris_sigdrv_sig1_setup_win6(p_swconf);
         }
         else if(p_window == WINDOW7)
         {
           iris_sigdrv_sig1_setup_win7(p_swconf);
         }
         else
         {
           /* Do nothing */
         }
    }
    #endif 
#endif
}

#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
/*! 
\brief trigger a load requst for window confifurations of Sig unit
\param p_sw_info pointer to 	SIG_WIN_INFO_T
\retval void
*/
void SigIf_sig_ldcfg_win(uint8_t p_sig_unit, uint8_t p_window)
{ 
 #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
   /* Signature unit - 0 and their evaluation windows */
   if(p_sig_unit == SIG_UNIT0)
   {
     if(p_window == WINDOW0)
	 {
	   iris_sigdrv_sig0_ldcfg_win0();
	 }
	 else if(p_window == WINDOW1)
	 {
	   iris_sigdrv_sig0_ldcfg_win1();
	 }
	 else if(p_window == WINDOW2)
	 {
	   iris_sigdrv_sig0_ldcfg_win2();
	 }
	 else if(p_window == WINDOW3)
	 {
	   iris_sigdrv_sig0_ldcfg_win3();
	 }
	 else if(p_window == WINDOW4)
	 {
	   iris_sigdrv_sig0_ldcfg_win4();
	 }
	 else if(p_window == WINDOW5)
	 {
	   iris_sigdrv_sig0_ldcfg_win5();
	 }
	 else if(p_window == WINDOW6)
	 {
	   iris_sigdrv_sig0_ldcfg_win6();
	 }
	 else if(p_window == WINDOW7)
	 {
	   iris_sigdrv_sig0_ldcfg_win7();
	 }
	 else
	 {
	   /* Do nothing */
	 }
   }
 #endif
 #if (SIGNATURE_UNITS_TO_USE == 2)
   else
 #endif
 #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
   {
     /* Signature unit - 1 and their evaluation windows */
     if(p_window == WINDOW0)
	 {
	   iris_sigdrv_sig1_ldcfg_win0();
	 }
	 else if(p_window == WINDOW1)
	 {
	   iris_sigdrv_sig1_ldcfg_win1();
	 }
	 else if(p_window == WINDOW2)
	 {
	   iris_sigdrv_sig1_ldcfg_win2();
	 }
	 else if(p_window == WINDOW3)
	 {
	   iris_sigdrv_sig1_ldcfg_win3();
	 }
	 else if(p_window == WINDOW4)
	 {
	   iris_sigdrv_sig1_ldcfg_win4();
	 }
	 else if(p_window == WINDOW5)
	 {
	   iris_sigdrv_sig1_ldcfg_win5();
	 }
	 else if(p_window == WINDOW6)
	 {
	   iris_sigdrv_sig1_ldcfg_win6();
	 }
	 else if(p_window == WINDOW7)
	 {
	   iris_sigdrv_sig1_ldcfg_win7();
	 }
	 else
	 {
	   /* Do nothing */
	 }
   }
  #endif
}
#endif

#ifdef GFX_USE_INFINEON_DRIVER
uint8_t SigIf_sig_get_evaluation_status(uint8_t p_sig_unit)
{
  /* Variable to receive evaluation window status information. */
  uint8_t win_status = 0U;
  cyfssig_sig_status_type sigStat = { {CYFSSIG_SIG_EVAL_DISABLED}, {CYFSSIG_SIG_SIGNATURE_NO_VIOLATION} };
  (void)CyFssig_SigGetEvaluationStatus(p_sig_unit, &sigStat);
  for (uint8_t i = 0U; i < MAX_WINDOWS; i++)
  {
    if ((sigStat.evaluationState[i] == CYFSSIG_SIG_EVAL_DONE) ||
      (sigStat.evaluationState[i] == CYFSSIG_SIG_EVAL_DISABLED))
      win_status |= (1UL << i);
  }
  return win_status;
}
#endif

#ifndef GFX_USE_TIDSS_DRIVER
uint32_t SigIf_sig_get_windows_status(uint8_t p_sig_unit)
{
    uint32_t win_status = 0U;
#if defined(GFX_USE_INFINEON_DRIVER)
    /* Variable to receive evaluation window status information. */
    cyfssig_sig_status_type sigStat = { {CYFSSIG_SIG_EVAL_DISABLED}, {CYFSSIG_SIG_SIGNATURE_NO_VIOLATION} };
    (void)CyFssig_SigGetEvaluationStatus(p_sig_unit, &sigStat);
    for (uint8_t i = 0U; i < MAX_WINDOWS; i++)
    {
        if ((sigStat.evaluationState[i] == CYFSSIG_SIG_EVAL_DONE) &&
      (sigStat.signatureResult[i] == CYFSSIG_SIG_SIGNATURE_VIOLATION))
            win_status |= (1UL << i);
    }
#else
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    /* Signature unit - 0 and their evaluation windows */
    if(p_sig_unit == SIG_UNIT0)
    {
        win_status = iris_sigdrv_sig0_get_win_status();
    }
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 2)
    else
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    {
        win_status = iris_sigdrv_sig1_get_win_status();
    }
    #endif
#endif /* GFX_USE_INFINEON_DRIVER */
    return win_status;
}
#endif

#if !(defined(GFX_USE_INFINEON_DRIVER) || defined(GFX_USE_TIDSS_DRIVER))
uint32_t SigIf_sig_get_win_status(SIG_WIN_INFO_T const * p_sw_info)
{
   uint32_t win_status = 0U;
 #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
   /* Signature unit - 0 and their evaluation windows */
   if(p_sw_info->sig_unit == SIG_UNIT0)
   {
     if(p_sw_info->window == WINDOW0)
	 {
	   win_status = iris_sigdrv_sig0_get_win0_status();
	 }
	 else if(p_sw_info->window == WINDOW1)
	 {
	   win_status = iris_sigdrv_sig0_get_win1_status();
	 }
	 else if(p_sw_info->window == WINDOW2)
	 {
	   win_status = iris_sigdrv_sig0_get_win2_status();
	 }
	 else if(p_sw_info->window == WINDOW3)
	 {
	   win_status = iris_sigdrv_sig0_get_win3_status();
	 }
	 else if(p_sw_info->window == WINDOW4)
	 {
	   win_status = iris_sigdrv_sig0_get_win4_status();
	 }
	 else if(p_sw_info->window == WINDOW5)
	 {
	   win_status = iris_sigdrv_sig0_get_win5_status();
	 }
	 else if(p_sw_info->window == WINDOW6)
	 {
	   win_status = iris_sigdrv_sig0_get_win6_status();
	 }
	 else if(p_sw_info->window == WINDOW7)
	 {
	   win_status = iris_sigdrv_sig0_get_win7_status();
	 }
	 else
	 {
	   /* Do nothing */
	 }
   }
 #endif
 #if (SIGNATURE_UNITS_TO_USE == 2)
   else
 #endif
 #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
   {
     /* Signature unit - 1 and their evaluation windows */
     if(p_sw_info->window == WINDOW0)
	 {
	   win_status = iris_sigdrv_sig1_get_win0_status();
	 }
	 else if(p_sw_info->window == WINDOW1)
	 {
	   win_status = iris_sigdrv_sig1_get_win1_status();
	 }
	 else if(p_sw_info->window == WINDOW2)
	 {
	   win_status = iris_sigdrv_sig1_get_win2_status();
	 }
	 else if(p_sw_info->window == WINDOW3)
	 {
	   win_status = iris_sigdrv_sig1_get_win3_status();
	 }
	 else if(p_sw_info->window == WINDOW4)
	 {
	   win_status = iris_sigdrv_sig1_get_win4_status();
	 }
	 else if(p_sw_info->window == WINDOW5)
	 {
	   win_status = iris_sigdrv_sig1_get_win5_status();
	 }
	 else if(p_sw_info->window == WINDOW6)
	 {
	   win_status = iris_sigdrv_sig1_get_win6_status();
	 }
	 else if(p_sw_info->window == WINDOW7)
	 {
	   win_status = iris_sigdrv_sig1_get_win7_status();
	 }
	 else
	 {
	   /* Do nothing */
	 }
   }
  #endif
   if(win_status > (uint32_t)0)
   {
     win_status = (uint32_t)1 ;
   }
   return(win_status); 
}
#endif

void SigIf_sig_get_win_crc_data(SIG_WIN_INFO_T const * p_sw_info, SIG_WIN_CRC_RGB_T * p_sw_crc_rgb)
{
#if defined(GFX_USE_INFINEON_DRIVER)
    /* Actual signature calculated by the hardware. */
    cyfssig_sig_signature_type actSig = { 0 };
    (void)CyFssig_SigGetWinCalSignature(p_sw_info->sig_unit, p_sw_info->window, &actSig);
    p_sw_crc_rgb->crc_r = actSig.sigRed;
    p_sw_crc_rgb->crc_g = actSig.sigGreen;
    p_sw_crc_rgb->crc_b = actSig.sigBlue;
#elif defined(GFX_USE_TIDSS_DRIVER)
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    #if (SIGNATURE_UNITS_TO_USE == 2)
    if(p_sw_info->sig_unit == SIG_UNIT0)
    #endif
    {
        if(p_sw_info->window == WINDOW0)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3020A090);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else if(p_sw_info->window == WINDOW1)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3020A094);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else if(p_sw_info->window == WINDOW2)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3020A098);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else /* (p_sw_info->window == WINDOW3) */
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3020A09C);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
    }
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    #if (SIGNATURE_UNITS_TO_USE == 2)
    else /* (p_sw_info->sig_unit == SIG_UNIT1) */
    #endif
    {
        if(p_sw_info->window == WINDOW0)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3022A090);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else if(p_sw_info->window == WINDOW1)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3022A094);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else if(p_sw_info->window == WINDOW2)
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3022A098);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
        else /* (p_sw_info->window == WINDOW3) */
        {
            uint32_t* reg_addr = (uint32_t*) AddrTranslateP_getLocalAddr(0x3022A09C);
            p_sw_crc_rgb->crc = CSL_REG32_RD(reg_addr);
        }
    }
    #endif        
#else
     #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
       /* Signature unit - 0 and their evaluation windows */
       if(p_sw_info->sig_unit == SIG_UNIT0)
       {
         if(p_sw_info->window == WINDOW0)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win0_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win0_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win0_crc_b();
         }
         else if(p_sw_info->window == WINDOW1)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win1_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win1_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win1_crc_b();
         }
         else if(p_sw_info->window == WINDOW2)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win2_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win2_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win2_crc_b();
         }
         else if(p_sw_info->window == WINDOW3)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win3_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win3_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win3_crc_b();
         }
         else if(p_sw_info->window == WINDOW4)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win4_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win4_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win4_crc_b();
         }
         else if(p_sw_info->window == WINDOW5)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win5_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win5_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win5_crc_b();
         }
         else if(p_sw_info->window == WINDOW6)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win6_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win6_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win6_crc_b();
         }
         else if(p_sw_info->window == WINDOW7)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig0_get_win7_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig0_get_win7_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig0_get_win7_crc_b();
         }
         else
         {
           /* Do nothing */
         }
       }
     #endif
     #if (SIGNATURE_UNITS_TO_USE == 2)
       else
     #endif
     #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
       {
         /* Signature unit - 1 and their evaluation windows */
         if(p_sw_info->window == WINDOW0)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win0_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win0_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win0_crc_b();
         }
         else if(p_sw_info->window == WINDOW1)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win1_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win1_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win1_crc_b();
         }
         else if(p_sw_info->window == WINDOW2)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win2_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win2_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win2_crc_b();
         }
         else if(p_sw_info->window == WINDOW3)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win3_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win3_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win3_crc_b();
         }
         else if(p_sw_info->window == WINDOW4)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win4_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win4_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win4_crc_b();
         }
         else if(p_sw_info->window == WINDOW5)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win5_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win5_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win5_crc_b();
         }
         else if(p_sw_info->window == WINDOW6)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win6_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win6_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win6_crc_b();
         }
         else if(p_sw_info->window == WINDOW7)
         {
           p_sw_crc_rgb->crc_r = iris_sigdrv_sig1_get_win7_crc_r();
           p_sw_crc_rgb->crc_g = iris_sigdrv_sig1_get_win7_crc_g();
           p_sw_crc_rgb->crc_b = iris_sigdrv_sig1_get_win7_crc_b();
         }
         else
         {
           /* Do nothing */
         }
       }
      #endif
#endif
}

#ifdef GFX_USE_INFINEON_DRIVER
uint8_t SigIf_sig_driver_commit(uint8_t p_sig_unit)
{
  uint8_t fl_result          = (BOOLEAN)(FALSE);
  const uint32_t commitSig[] = { CYFSSIG_COMMITFLAG_SIG_0, CYFSSIG_COMMITFLAG_SIG_1 };
  if (p_sig_unit < CYFSSIG_MAXIMUM_DISPLAY_NUMBER)
  {
    cyfssig_return_type        result;
    cyfssig_commit_status_type status;

    (void)CyFssig_DrvCommit(commitSig[p_sig_unit]);
    result = CyFssig_DrvGetCommitStatus(commitSig[p_sig_unit], &status);
    if ((CYFSSIG_OK == result) && (CYFSSIG_COMMIT_ONGOING == status))
    {
      fl_result = (BOOLEAN)(TRUE);
    }
    else
    {
      fl_result = (BOOLEAN)(FALSE);
    }
  }
  return fl_result;
}

void SigIf_sig_driver_monitoring(void)
{
  CyFssig_DrvMainHandling();
}
#endif

void SigIf_sig_stop_evaluation(uint8_t p_sig_unit)
{
#if defined(GFX_USE_INFINEON_DRIVER)
  for (uint8_t fl_window = 0; fl_window < CYFSSIG_MAXIMUM_EVALWIN_NUMBER; fl_window++)
    (void)CyFssig_SigDisableWinEvaluation(p_sig_unit, fl_window);
  (void)SigIf_sig_driver_commit(p_sig_unit);
#elif defined(GFX_USE_TIDSS_DRIVER)  
        Dss_Object *fl_DssObjPtr = &gDssObjects[p_sig_unit];
        
        for (uint8_t fl_pipelineId = 0U; fl_pipelineId < (uint8_t)gDssConfigPipelineParams.numTestPipes; fl_pipelineId++)
        {
            Dss_DispPipeSafetyChkParams *flPipeSafetyParams = &fl_DssObjPtr->instObj[fl_pipelineId].safetyParams;
            
            if (gDssConfigPipelineParams.safetyCheck[fl_pipelineId] == (uint8_t)TRUE)
            {
                if (flPipeSafetyParams->safetyChkCfg.safetyChkEnable == SIG_EV_WIN_ENABLED)
                {                    
                    flPipeSafetyParams->safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_DISABLED;
                    flPipeSafetyParams->safetyChkCfg.regionPos.startX   = 0;
                    flPipeSafetyParams->safetyChkCfg.regionPos.startY   = 0;
                    flPipeSafetyParams->safetyChkCfg.regionSize.width   = 0U;
                    flPipeSafetyParams->safetyChkCfg.regionSize.height  = 0U; 
                    flPipeSafetyParams->referenceSign                   = 0U; 
                        
                    (void) Fvid2_control(fl_DssObjPtr->instObj[fl_pipelineId].drvHandle, \
                                    IOCTL_DSS_DISP_SET_PIPE_SAFETY_CHK_PARAMS, flPipeSafetyParams, NULL);
                }
            }
        }
        
        for(uint8_t fl_vp_subregion = 0U; fl_vp_subregion < MAX_WINDOWS; fl_vp_subregion++)
        {
            Dss_DctrlVpSafetyChkParams *flVPSafetyParams = (Dss_DctrlVpSafetyChkParams*)&fl_DssObjPtr->vpSafetyParams[fl_vp_subregion];
            
            if (flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.safetyChkEnable == SIG_EV_WIN_ENABLED)
            {                   
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.safetyChkEnable    = SIG_EV_WIN_DISABLED;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startX   = 0;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionPos.startY   = 0;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.width   = 0U;
                flVPSafetyParams->regionSafetyChkCfg.safetyChkCfg.regionSize.height  = 0U;
                flVPSafetyParams->regionSafetyChkCfg.referenceSign                   = 0U; 
            
                (void) Fvid2_control(fl_DssObjPtr->dctrlHandle, IOCTL_DSS_DCTRL_SET_VP_SAFETY_CHK_PARAMS, \
                                    flVPSafetyParams, NULL);
            }
        }  
#else
    #if (SIGNATURE_UNITS_TO_USE == 0) || (SIGNATURE_UNITS_TO_USE == 2)
    if(p_sig_unit == SIG_UNIT0)
    {
        iris_sigdrv_sig0_unlock();
        iris_sigdrv_sig0_clear_cnt_mode();
        iris_sigdrv_sig0_lock();
    }
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 2)
    else
    #endif
    #if (SIGNATURE_UNITS_TO_USE == 1) || (SIGNATURE_UNITS_TO_USE == 2)
    {
        iris_sigdrv_sig1_unlock();
        iris_sigdrv_sig1_clear_cnt_mode();
        iris_sigdrv_sig1_lock();
    }
    #endif
    SIGCDD_UNUSED_VAR(p_sig_unit);
#endif
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
