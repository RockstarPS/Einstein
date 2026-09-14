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
** Name:           hmi_gfx_mgr02_sw_compression.h
**
** Description:    Header files for sw compression logic
**
** Organization:   GUI Software Section, Visteon
**
*******************************************************************************/

#ifndef HMI_GFX_MGR02_SW_COMPRESSION_H
#define HMI_GFX_MGR02_SW_COMPRESSION_H
/*******************************************************************************
                            Module Name
*******************************************************************************/

#if defined(GFX_MGR02_COMPRESSION_ENABLED)
/*******************************************************************************
                            Macro Definitions
*******************************************************************************/
#ifdef HMI_GFX_MGR02_SW_COMPRESSION_C
#define GFX_COMP_EXTERN
#else
#define GFX_COMP_EXTERN     extern
#endif
/*******************************************************************************
                            Extern Function Declarations
*******************************************************************************/

GFX_COMP_EXTERN void hmi_gfx_mgr02_comp_decompr_8bpp(GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP, UINT8 *p_frame_buff_U08P);
GFX_COMP_EXTERN void hmi_gfx_mgr02_comp_decompr_16bpp(GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP, UINT16 *p_frame_buff_U16P);
GFX_COMP_EXTERN void hmi_gfx_mgr02_comp_decompr_32bpp(GFX_MGR02_IMAGE_DEF_T const *p_elem_def_SP, UINT32 *p_frame_buff_U32P);

#endif /* #if defined(GFX_MGR02_COMPRESSION_ENABLED) */

#endif /* #ifndef HMI_GFX_MGR02_SW_COMPRESSION_H */

