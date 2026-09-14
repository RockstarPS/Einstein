/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2013. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mar02_safety.c
 **
 ** Description:    Interface file for safety features.
 **
 ** Organization:   Driver Information Software Section,
 **                 Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_SAFETY_C

#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_safety.h"

#ifdef GFX_MGR02_IRIS_SIG_UNIT_ENABLED
#include "iris_drv.h"
#include "sm_util.h"
#include "os.h"


/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/
  
static GFX_MGR02_SIGNATURE_INFO l_active_signature_info;
static UINT8                    l_active_signature_id_ref_changed;
static UINT8                    l_active_signature_unit_init;
/* Hold Iris NMI interrupts status globally */
volatile MM_U32 intGfxNMI = MML_GDC_INTERRUPT_NMI_NONE;


/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/
/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_init
** Visibility:       global
** Description:      Interface to init safety unit
** Invocation:       hmi_gfx_mgr02_layout.c	
** Inputs/Outputs:   void
**                   
** Critical Section: None.
** Created:          12-May-2015 by csakthiv
** Updated:          
**==========================================================================*/
void hmi_gfx_mgr02_safety_init(void)
{
   l_active_signature_id_ref_changed              = (UINT8)FALSE;
   l_active_signature_unit_init                   = (UINT8)FALSE;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_set_signature_id_reference
** Visibility:       global
** Description:      Interface to set the reference value for differnt signature id.
** Invocation:       Application	
** Inputs/Outputs:   Signature reference values.
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_id_reference(GFX_MGR02_SIGNATURE_ID_REF_T const* p_signature_SP)
{
   l_active_signature_info.sig_reference_r        = p_signature_SP->sig_reference_r;
   l_active_signature_info.sig_reference_g        = p_signature_SP->sig_reference_g;
   l_active_signature_info.sig_reference_b        = p_signature_SP->sig_reference_b;
   l_active_signature_info.sig_disp_inhibit       = p_signature_SP->sig_disp_inhibit;				 
   l_active_signature_id_ref_changed              = (UINT8)TRUE;
   return GUI_GFX_MGR_NO_ERROR;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_get_signature_error_cnt
** Visibility:       global
** Description:      Interface to get the signature error count
** Invocation:       
** Inputs/Outputs:   Return the error count.
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
UINT32 hmi_gfx_mgr02_safety_get_signature_error_cnt(void)
{
   UINT32 fl_error_cnt_U32 ;
   fl_error_cnt_U32 = mmlGdcSigGetErrors(MML_GDC_SIG_UNIT_0);
   return fl_error_cnt_U32;
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_get_signature_result
** Visibility:       global
** Description:      Interface to get the signature result ie., checksum for Signature B
** Invocation:       
** Inputs/Outputs:   Return the signature result
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
void hmi_gfx_mgr02_safety_get_signature_result(GFX_MGR02_SIGNATURE_RESULT_T * p_signature_result_SP)
{
   p_signature_result_SP->sig_b_red_channel	  = mmlGdcSigGetTypeBMonitoringResult(MML_GDC_SIG_UNIT_0,MML_GDC_SIG_COLOR_CHANNEL_R);
   p_signature_result_SP->sig_b_green_channel = mmlGdcSigGetTypeBMonitoringResult(MML_GDC_SIG_UNIT_0,MML_GDC_SIG_COLOR_CHANNEL_G);
   p_signature_result_SP->sig_b_blue_channel  = mmlGdcSigGetTypeBMonitoringResult(MML_GDC_SIG_UNIT_0,MML_GDC_SIG_COLOR_CHANNEL_B);
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_set_signature_eval_window
** Visibility:       global
** Description:      Interface to set the evalution window size
** Invocation:       
** Inputs/Outputs:   evaluation window size
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_eval_window(GFX_MGR02_SIGNATURE_EVAL_WND_T const* p_signature_SP)
{
   l_active_signature_info.sig_eval_wnd_x             = p_signature_SP->sig_eval_wnd_x_upper_left;
   l_active_signature_info.sig_eval_wnd_y			  = p_signature_SP->sig_eval_wnd_y_upper_left;
   l_active_signature_info.sig_eval_wnd_width         = p_signature_SP->sig_eval_wnd_x_lower_right-p_signature_SP->sig_eval_wnd_x_upper_left;
   l_active_signature_info.sig_eval_wnd_width++;
   l_active_signature_info.sig_eval_wnd_height        = p_signature_SP->sig_eval_wnd_y_lower_right-p_signature_SP->sig_eval_wnd_y_upper_left;
   l_active_signature_info.sig_eval_wnd_height++;
   l_active_signature_unit_init                       = (UINT8)TRUE;
   return GUI_GFX_MGR_NO_ERROR;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_set_signature_mask
** Visibility:       global
** Description:      Function to set mask window size
** Invocation:       Application
** Inputs/Outputs:   mask window size
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_mask(GFX_MGR02_SIGNATURE_MASK_T const* p_signature_SP)
{
   l_active_signature_info.sig_mask_x             = p_signature_SP->sig_mask_x_upper_left;
   l_active_signature_info.sig_mask_y			  = p_signature_SP->sig_mask_y_upper_left;
   l_active_signature_info.sig_mask_width         = p_signature_SP->sig_mask_x_lower_right-p_signature_SP->sig_mask_x_upper_left;
   l_active_signature_info.sig_mask_width++;
   l_active_signature_info.sig_mask_height        = p_signature_SP->sig_mask_y_lower_right-p_signature_SP->sig_mask_y_upper_left;
   l_active_signature_info.sig_mask_height++;
   l_active_signature_unit_init                   = (UINT8)TRUE;
   return GUI_GFX_MGR_NO_ERROR;
}
/*============================================================================
** Function Name:    hmi_gfx_mgr02_safety_set_signature_ref_threshold
** Visibility:       global
** Description:      Function to set the signature b reference threshold
** Invocation:       Application
** Inputs/Outputs:   signature B threshold values
**                   
** Critical Section: None.
** Created:          15-April-2015 by csakthiv
** Updated:          
**==========================================================================*/
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_ref_threshold(GFX_MGR02_SIGNATURE_REF_THRESHOLD_T const* p_signature_SP)
{
   l_active_signature_info.sig_ref_threshold_red             = p_signature_SP->sig_ref_threshold_red;
   l_active_signature_info.sig_ref_threshold_green			 = p_signature_SP->sig_ref_threshold_green;
   l_active_signature_info.sig_ref_threshold_blue            = p_signature_SP->sig_ref_threshold_blue;
   l_active_signature_unit_init                              = (UINT8)TRUE;
   return GUI_GFX_MGR_NO_ERROR;
}


/****************************************************************************
Function Name        : hmi_gfx_mgr02_irislib_manage_signature_unit()
Description          : Interface to do signature check 
Invocation           : Invoked by context.c
Return Value         : void
Parameters           : void
******************************************************************************/
void hmi_gfx_mgr02_safety_manage_signature_unit(void)
{
   MM_S32 ret = MML_OK;
   if(l_active_signature_id_ref_changed == TRUE)
   {
	  l_active_signature_id_ref_changed = (UINT8)FALSE;
	  if (mmlGdcSigIsKeyProtectionLocked(MML_GDC_SIG_UNIT_0)!= MM_FALSE)
	  {
	  	UTIL_SUCCESS(ret, mmlGdcSigSetKeyProtection(MML_GDC_SIG_UNIT_0, MM_FALSE));
	  }

	  /* start: setup sig basic*/
	  if(l_active_signature_unit_init == TRUE)
	  {
	      l_active_signature_unit_init = (UINT8)FALSE;
	      /* SIG: enable checksum A, enable checksum B */
    	  UTIL_SUCCESS(ret, mmlGdcSigEnableChecksum(MML_GDC_SIG_UNIT_0, MM_FALSE, MM_TRUE));


    	  /* SIG: set threshold for checksum type B for each channel */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetThresholdTypeB(MML_GDC_SIG_UNIT_0, l_active_signature_info.sig_ref_threshold_red, l_active_signature_info.sig_ref_threshold_green, l_active_signature_info.sig_ref_threshold_blue));

    	  /* SIG: set threshold for error frames */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetErrThreshold(MML_GDC_SIG_UNIT_0, (MM_U32)GFX_MGR02_SIG_UNIT_THRESHOLD_ERR_CNT));
    	  /*if threshold reset set to zero, then there is no reset for error counter value*/
    	  /*error counter value will reset on calling triggermonitoring interface */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetErrThreshReset(MML_GDC_SIG_UNIT_0, (MM_U32)GFX_MGR02_SIG_UNIT_THRESHOLD_ERR_RST_CNT));

    	  /* start: setup sig evaluation window and reference values */

    	  /* SIG: set SIG evaluation window params */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetEvalWindow(MML_GDC_SIG_UNIT_0, (MM_U32)l_active_signature_info.sig_eval_wnd_x, (MM_U32)l_active_signature_info.sig_eval_wnd_y,
    			       (MM_U32)l_active_signature_info.sig_eval_wnd_width, (MM_U32)l_active_signature_info.sig_eval_wnd_height));
    	  #if 0
    	  /* SIG: set reference values for checksum generation */
    	  UTIL_SUCCESS(ret, mmlGdcSigReferenceValues(MML_GDC_SIG_UNIT_0, 0, 0, 0,
    	  l_active_signature_info.sig_reference_r, l_active_signature_info.sig_reference_g, l_active_signature_info.sig_reference_b));
    	  #endif
    	  /* SIG: set mask for evaluation window and for pixels */
    	  /* SIG: no mask */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetEvalMaskMode(MML_GDC_SIG_UNIT_0, GFX_MGR02_SIG_UNIT_VERTICAL_MASK_MODE,
    			GFX_MGR02_SIG_UNIT_HORIZONTAL_MASK_MODE));
    		/* SIG: set mask window params */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetEvalMaskWindow(MML_GDC_SIG_UNIT_0,(MM_U32)l_active_signature_info.sig_mask_x,
    	     	(MM_U32)l_active_signature_info.sig_mask_y,
    			(MM_U32)l_active_signature_info.sig_mask_width,
    			(MM_U32)l_active_signature_info.sig_mask_height));
    		/* SIG: alpha=ON -> every pixel will be evaluated */
    	  UTIL_SUCCESS(ret, mmlGdcSigSetEvalPixelMaskMode(MML_GDC_SIG_UNIT_0, MML_GDC_SIG_ALPHA_MODE_ON));

    	  /* end: setup  */
	  }
	  /* SIG: set reference values for checksum generation */
	  UTIL_SUCCESS(ret, mmlGdcSigReferenceValues(MML_GDC_SIG_UNIT_0, (MM_U32)0, (MM_U32)0, (MM_U32)0,
	  l_active_signature_info.sig_reference_r, l_active_signature_info.sig_reference_g, l_active_signature_info.sig_reference_b));

		/* Enable SIG unit */
	  UTIL_SUCCESS(ret, mmlGdcSigTriggerMonitoring(MML_GDC_SIG_UNIT_0,
	        MML_GDC_SIG_TRIGGER_MODE_CYCLIC, (MM_BOOL)l_active_signature_info.sig_disp_inhibit));

		/* Lock SIG unit */
	  UTIL_SUCCESS(ret, mmlGdcSigSetKeyProtection(MML_GDC_SIG_UNIT_0, (MM_BOOL)MM_TRUE));
   }
}

/****************************************************************************
Function Name        : GFX_SignatureUnit_NMIHandler()
Description          : Interrupt handler for GFXNIM signature error interrupt.
Invocation           : Invoked by Micro
Return Value         : void
Parameters           : 
******************************************************************************/
void GFX_SignatureUnit_NMIHandler(void)
{
  /* Iris NMI interrupt occurred , read current NMI interrupt status */
  /* interrupts get cleared internally */
  intGfxNMI = mmlGdcInterruptNMIHandler();
  GFX_MGR02_UNUSED_VAR(intGfxNMI);
}
#endif

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
** CMS Rev 1.3     02-NOV-2016    APERUMAL
** 735553: Porsche Misra warning Fix
**
** CMS Rev 1.2     28-JULY-2016    SSIGAMAN
** 656417: Porsche Display Dead Issue: Removed ISR_NATIVE from GFX_SignatureUnit_NMIHandler()
** With this macro, VIP display is dead.
**
** CMS Rev 1.1     08-JULY-2016    SSIGAMAN
** 639042: Porsche Misra warning Fix
**
** CMS Rev 1.0     28-April-2015    CSAKTHIV
** Intial Version.
**
**==========================================================================*/
