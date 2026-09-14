/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
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

File Name        :  hmi_gfx_mgr02_gsub.h
Module Short Name:  GFX_MGR
VOBName          :  sw_hmi_ss
Author           :  csakthiv
Description      :  Implements logic to process the GSUB table data provided by IGDT
Organization     :  Driver Information Software Section,
                    Visteon Corporation
******************************************************************************/
#ifndef HMI_GFX_GUSB_H
#define HMI_GFX_GSUB_H

#include "system.h"
#include "hmi_gfx_mgr02_types.h"

enum
{
   SINGLE=1,
   MULTIPLE,
   ALTERNATEC,
   LIGATURE,
   CONTEXTC,
   CHAINING_CONTEXT,
   EXT_SUBST,
   REV_CHAINING_CONTEXT_SINGLE
};

typedef struct
{
    HMI_FONT_GSUB_SCRIPT_LOOKUP_TBL const * i_script_lookup;
    HMI_FONT_GSUB_LOOKUP_TABLE      const * i_lookup;
    UINT16                                  i_lookup_count;
    UINT16                                  i_script_count;
    HMI_CHAR                              * i_src;
    HMI_CHAR                              * o_dst;
    UINT16                                  i_src_len;
    UINT16                                  o_dst_len;
    char                            const * i_script;
}HMI_GFX_DEVN_REORDER_INFO;


void hmi_gfx_mgr02_gsub_process(HMI_GFX_DEVN_REORDER_INFO * p_reoder_info_SP, UINT32 p_num_chars_cpy);
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
  void hmi_gfx_mgr02_reorder_thai_diacritics(HMI_CHAR *p_string);
  BOOLEAN hmi_gfx_mgr02_normalize_Thai_SaraAm(HMI_CHAR const *p_src_P,HMI_CHAR * p_dst_P);
#endif
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
** CMS Rev #        Date            By
** CMS Rev X.X      dd-mmm-yyyy     CDSID
**
**============================================================================
**
** CMS Rev 1.0      01-Jun-2016     csakthiv
** Creation.
** Algorithm to use the GSUB data provided font. Currently used for Thai language
**==========================================================================*/
