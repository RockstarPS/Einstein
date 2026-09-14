/********************************************************************************
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
*******************************************************************************
**
** Name:           hmi_gfx_mgr02_tidss_dispif.h
**
** Description:    Header file for tidss driver interfaces
**
** Organization:   HMI Core Software Section, Visteon
**
*******************************************************************************/

/*******************************************************************************
                            Module Name
*******************************************************************************/

#ifndef HMI_GFX_MGR02_TIDSS_DISPIF_H
#define HMI_GFX_MGR02_TIDSS_DISPIF_H

/*******************************************************************************
                            Includes
*******************************************************************************/

#include <stdint.h>

/*******************************************************************************
                            Macro Definitions
*******************************************************************************/
#ifdef HMI_GFX_MGR02_TIDSS_DISPIF_C
#define GFX_TIDSS_EXTERN
#else
#define GFX_TIDSS_EXTERN     extern
#endif

#ifdef GFX_MGR02_TIDSS_DEBUG 
/* below code for debugging purposes only */ 
#define GFX_TIDSS_DISPIF_ERR_TRAP(rv, execute) \
{ \
    (rv) = (execute); \
    if ((rv) != FVID2_SOK) \
    { \
      while(1==1); \
    } \
}
#else
#define GFX_TIDSS_DISPIF_ERR_TRAP(rv, execute)    (rv) = (execute);
#endif

/*******************************************************************************
                            Extern Function Declarations
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

GFX_TIDSS_EXTERN int32_t hmi_gfx_mgr02_tidss_dispif_init(uint8_t p_disp_id);
GFX_TIDSS_EXTERN int32_t hmi_gfx_mgr02_tidss_dispif_update(uint8_t p_disp_id);
GFX_TIDSS_EXTERN int32_t hmi_gfx_mgr02_tidss_dispif_dequeue(uint8_t p_disp_id);
GFX_TIDSS_EXTERN int32_t hmi_gfx_mgr02_tidss_dispif_shutdown(uint8_t p_disp_id);

GFX_TIDSS_EXTERN int32_t hmi_gfx_mgr02_tidss_dispif_set_pipeline_alpha(uint8_t p_disp_id, uint8_t p_pipeline_id, uint8_t p_alpha);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef HMI_GFX_MGR02_tidss_if_H */

