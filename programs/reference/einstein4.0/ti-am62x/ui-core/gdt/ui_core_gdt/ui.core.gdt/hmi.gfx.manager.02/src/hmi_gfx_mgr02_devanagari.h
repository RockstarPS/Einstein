/*=============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_devanagari.h
 **
 ** Description:    Implements logic to process the GSUB table data for
 **                 devanagari scripts
 **                 
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/

#ifndef HMI_GFX_MGR02_DEVANAGARI_H
#define HMI_GFX_MGR02_DEVANAGARI_H

#include "system.h"
#include "hmi_gfx_mgr02_types.h"


typedef UINT32 hmi_IndicOTScriptFlags;
/*
 * Character class: a character class value
 * ORed with character class flags.
 */
typedef UINT32 hmi_IndicOTCharClass;

/*
 * The characters that a split matra splits into.
 * Unused characters will be zero.
 */
typedef HMI_CHAR hmi_IndicOTSplitMatra[3];

struct hmi_deva_FixupData
{
    SINT32 fBaseIndex;
    SINT32 fMPreIndex;
};

typedef struct hmi_deva_FixupData hmi_FixupData;

struct hmi_deva_MPreFixups {
  SINT32		fFixupCount;
  hmi_FixupData	*fFixupData;
};

typedef struct hmi_deva_MPreFixups hmi_MPreFixups;

struct hmi_deva_IndicOTClassTable
{
  HMI_CHAR	      firstChar;
  HMI_CHAR	      lastChar;
  SINT32		      worstCaseExpansion;
  hmi_IndicOTScriptFlags  scriptFlags;

  const hmi_IndicOTCharClass  *charClasses;
  const hmi_IndicOTSplitMatra *splitMatraTable;
};

typedef struct hmi_deva_IndicOTClassTable hmi_IndicOTClassTable;

#ifndef HMI_GFX_MGR02_DEVANAGARI_C
  extern const hmi_IndicOTClassTable hmi_deva_class_table;
#endif

SINT32 hmi_indic_ot_reorder(HMI_CHAR                * chars,
                      const SINT32              * utf8_offsets,
                      SINT32                      char_count,
                      const hmi_IndicOTClassTable * class_table,
                      HMI_CHAR                  * out_chars,
                      SINT32                    * char_indices,
                      UINT32                    * char_tags,
                      hmi_MPreFixups             ** outMPreFixups);

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
** CMS Rev 1.0      -----
** Creation.
** Algorithm to use the GSUB data devanagari scripts
**==========================================================================*/
