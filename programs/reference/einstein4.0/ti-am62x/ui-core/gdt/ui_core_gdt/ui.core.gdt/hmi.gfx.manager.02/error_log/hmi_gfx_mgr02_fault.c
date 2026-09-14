/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *                       
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************

File Name        :  hmi_gfx_mgr02_fault.c
Module Short Name:  hmi_gfx_mgr02_fault
VOBName          :  ui.core.gdt
Author           :  ashekhar
Description      :  For fault handling
Organization     :  Visteon Technical And Services Centre
                    Visteon Corporation

----------------------------------------------------------------------------
Compiler Name    :  IAR Workbench
Target Hardware  :  Vybrids
******************************************************************************/
#define HMI_GFX_MGR02_FAULT_C
/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#include "hmi_gfx_mgr02.cfg"
//#if defined(HMI_GFX_MGR02_ARCH04)
#if defined(GFX_OVG_FAULT_HANDLE)
#include "hmi_gfx_mgr02_fault.h"
//#include "os_if.h"
//#include "util_mem_if.h"
/******************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static const UINT32 lc_one_to_one_ovg_error[8] = {                                         \
	                                              GFX_MGR02_VG_HANDLE_FAULT,              \
                                                  GFX_MGR02_VG_ILLEGAL_ARGUMENT_FAULT,    \
                                                  GFX_MGR02_VG_OUT_OF_MEMORY_FAULT,       \
                                                  GFX_MGR02_VG_PATH_CAPABILITY_FAULT,     \
                                                  GFX_MGR02_VG_UNSUP_IMAGE_FAULT,         \
                                                  GFX_MGR02_VG_UNSUP_PATH_FMT_FAULT,      \
                                                  GFX_MGR02_VG_IMAGE_IN_USE_FAULT,        \
                                                  GFX_MGR02_VG_NO_CONTEXT_FAULT           \
                                                };

static UINT8 l_app_current_state;
static UINT32 l_gfx_ovg_errors_mask_U32;

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/
/****************************************************************************
Function Name     : hmi_gfx_mgr02_fault_cold_init

Description       : This function provided to clear all fault bits of the 
					Graphics Manager 02.

Invocation	      : System Init.

Parameters        : None.

Return Type       : None.
******************************************************************************/
void hmi_gfx_mgr02_fault_cold_init(void)
{
  l_gfx_ovg_errors_mask_U32 = 0x0U;
}

/****************************************************************************
Function Name     : hmi_gfx_mgr02_get_actual_error
Description       : This function is provided the actual configured error
                    which is equivalent to the ovg api set error code.
Invocation	      : As Required
Parameters        : OVG API's error code index and error value
Return Type       : None.
******************************************************************************/
UINT32 hmi_gfx_mgr02_fault_convert_error_code(UINT16 p_vg_error_code)
{
   UINT32 fl_return_error;
    
   fl_return_error = (UINT32)(p_vg_error_code & (UINT32)0x07);
   if((fl_return_error == (UINT32)0) && (p_vg_error_code == (UINT16)0))                     
   {                                                         
     fl_return_error = GFX_MGR02_VG_NO_ERROR;                             
   }                                                         
   else                                                      
   {                                                         
     fl_return_error = lc_one_to_one_ovg_error[fl_return_error];                       
   }
   return fl_return_error;                                                         
}
/****************************************************************************
Function Name     : hmi_gfx_mgr02_fault_set
Description       : This function is provided to set the bit in hmi_gfx_mgr02_fault_data 
                    corresponding to the Graphics Manager fault.
Invocation	      : As Required
Parameters        : Fault ID
Return Type       : None.
******************************************************************************/
void hmi_gfx_mgr02_fault_set(const UINT32 p_fault_id_32)
{
  ((l_gfx_ovg_errors_mask_U32) |=  (p_fault_id_32));
}
/****************************************************************************
Function Name     : hmi_gfx_mgr02_fm_clear_error_log
Description       : Clear the all recorded errors
Invocation	      : As Required
Parameters        : Fault ID
Return Type       : None.
******************************************************************************/
void hmi_gfx_mgr02_fault_clearall(void)
{
  l_gfx_ovg_errors_mask_U32 = 0x0U;
}
/****************************************************************************
Function Name     : hmi_gfx_mgr02_fault_get
Description       : This function is provided to get the bit in hmi_gfx_mgr02_fault_data 
                    corresponding to the Graphics Manager fault.
Invocation	      : As Required
Parameters        : Fault ID
Return Type       : None.
******************************************************************************/
UINT32 hmi_gfx_mgr02_fault_get(void)
{
  return l_gfx_ovg_errors_mask_U32;
}
/****************************************************************************
Function Name     : hmi_gfx_mgr02_get_any_critical_error
Description       : This function is provided to check are there any
                    critical errors exist in hmi_gfx_mgr02_fault_data 
                    corresponding to OVG api's.
Invocation	      : As Required
Parameters        : None
Return Type       : None.
******************************************************************************/
UINT8 hmi_gfx_mgr02_fault_check_critical_error(void)
{
  UINT8 fl_return = FALSE;

  if((l_gfx_ovg_errors_mask_U32 & GFX_CFG_MONITOR_CRITICAL_ERROR_MASK)!= (UINT32)0x00)
  {
    fl_return = TRUE;
  }
  return fl_return;
}

#if defined(GFX_OVG_LOG_PRINT_AVAILABLE)
void log_print(UINT32 rc, char const *function, char const*file, UINT32 line)
{
    printf("Error 0x%08x in %s (%s line %d)\n", rc, function, file, line);
}
#endif
#endif
/*End of File*/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/*============================================================================
** Date              :  04/08/2017
** Traceability      :  RTC ID: 924879
** cdsId             :  adevi
** Change Description:  Monotype Font Integration in Kepler I.
**==========================================================================*/
/*============================================================================
** Date              :  27/10/2016
** Traceability      :  RTC ID: 731511
** cdsId             :  ashekhar
** Change Description:  Add temporary error logging capability to Ui Core.
**==========================================================================*/
/*============================================================================
** Date              :  16/12/2016
** Traceability      :  RTC ID: 756979
** cdsId             :  VGAJJI
** Change Description:  B515 Coverity Warning Fix - Coverity ID:226831
**==========================================================================*/
/*============================================================================
** Date              :  07/02/2016
** Traceability      :  RTC ID: 750237
** cdsId             :  sbollam
** Change Description:  Updated error logging capability and added
**                      OVG software recovery capability                         
**==========================================================================*/
