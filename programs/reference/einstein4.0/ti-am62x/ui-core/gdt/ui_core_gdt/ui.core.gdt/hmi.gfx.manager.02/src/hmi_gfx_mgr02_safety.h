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
** Name:           hmi_gfx_mgr02_safety.h
**
** Description:    Interface header for the graphics manager for the
**                 Kepler Spectrum/RainbowLite Platform.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_SAFETY_H
#define HMI_GFX_MGR02_SAFETY_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_mgr02_layout.h"
#ifdef GFX_MGR02_IRIS_SIG_UNIT_ENABLED
#include "hmi_gfx_mgr02_safety.cfg"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#define GFX_MGR02_SIG_DISP_BLANK_ENABLE       0x01
#define GFX_MGR02_SIG_DISP_BLANK_DISABLE      0x00

typedef struct
{
   UINT32                       sig_reference_r;				
   UINT32                       sig_reference_g;
   UINT32                       sig_reference_b;
   UINT8                        sig_disp_inhibit:1;
}GFX_MGR02_SIGNATURE_ID_REF_T;

typedef struct
{
   UINT16                       sig_eval_wnd_x_upper_left;
   UINT16                       sig_eval_wnd_x_lower_right;
   UINT16                       sig_eval_wnd_y_upper_left;
   UINT16                       sig_eval_wnd_y_lower_right;
}GFX_MGR02_SIGNATURE_EVAL_WND_T;

typedef struct
{
   UINT16                       sig_mask_x_upper_left;
   UINT16                       sig_mask_x_lower_right;
   UINT16                       sig_mask_y_upper_left;
   UINT16                       sig_mask_y_lower_right;
}GFX_MGR02_SIGNATURE_MASK_T;

typedef struct
{
   UINT32                       sig_ref_threshold_red;
   UINT32                       sig_ref_threshold_green;
   UINT32                       sig_ref_threshold_blue;
}GFX_MGR02_SIGNATURE_REF_THRESHOLD_T;

typedef struct
{
   UINT32                       sig_b_red_channel;
   UINT32                       sig_b_green_channel;
   UINT32                       sig_b_blue_channel;
}GFX_MGR02_SIGNATURE_RESULT_T;

typedef struct
{
   UINT32                       sig_reference_r;				
   UINT32                       sig_reference_g;
   UINT32                       sig_reference_b;
   UINT16                       sig_eval_wnd_x;
   UINT16                       sig_eval_wnd_y;
   UINT16                       sig_eval_wnd_width;
   UINT16                       sig_eval_wnd_height;
   UINT16                       sig_mask_x;
   UINT16                       sig_mask_y;
   UINT16                       sig_mask_width;
   UINT16                       sig_mask_height;
   UINT32                       sig_ref_threshold_red;
   UINT32                       sig_ref_threshold_green;
   UINT32                       sig_ref_threshold_blue;
   UINT8                        sig_disp_inhibit:1;
}GFX_MGR02_SIGNATURE_INFO;



/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
void hmi_gfx_mgr02_safety_init(void);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_id_reference(GFX_MGR02_SIGNATURE_ID_REF_T const* p_signature_id);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_eval_window(GFX_MGR02_SIGNATURE_EVAL_WND_T const* p_signature_SP);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_mask(GFX_MGR02_SIGNATURE_MASK_T const* p_signature_SP);
GUI_GFX_MGR_ERROR_CODE_T hmi_gfx_mgr02_safety_set_signature_ref_threshold(GFX_MGR02_SIGNATURE_REF_THRESHOLD_T const* p_signature_SP);
UINT32 hmi_gfx_mgr02_safety_get_signature_error_cnt(void);
void hmi_gfx_mgr02_safety_get_signature_result(GFX_MGR02_SIGNATURE_RESULT_T * p_signature_result_SP);
void hmi_gfx_mgr02_safety_manage_signature_unit(void);
#endif

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

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
**
** CMS Rev 1.0     28-April-2015    CSAKTHIV
** Intial Version.
**
**==========================================================================*/
#ifdef  __cplusplus
}
#endif

/* end of file =============================================================*/
#endif
