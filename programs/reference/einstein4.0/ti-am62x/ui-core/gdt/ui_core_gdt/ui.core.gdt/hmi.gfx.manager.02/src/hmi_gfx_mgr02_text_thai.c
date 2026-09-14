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
** Name:           hmi_gfx_mgr02_text_thai.c
**
** Description:    Main graphics manager 02 text print module
**
** Organization:   Driver Information Software Section,
**                 Visteon
**
**============================================================================
**
**==========================================================================*/ 
 #define HMI_GFX_MGR02_TEXT_THAI
/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) 
#define THAI_DIACRITICS_START 0x0E31U
#define THAI_DIACRITICS_END   0x0E4EU
#define THAI_DIACRITICS_ENTRIES (1U + THAI_DIACRITICS_END - THAI_DIACRITICS_START)
	
#define GFX_CHAR_THAI_VOWEL_SIGN_SARA_AA     0x0E32U  /* THAI VOWEL SIGN SARA AA     */
#define GFX_CHAR_THAI_VOWEL_SIGN_SARA_AM     0x0E33U  /* THAI VOWEL SIGN SARA AM     */
#define GFX_CHAR_THAI_NIKKHAHIT              0x0E4DU  /* THAI NIKKHAHIT              */

static UINT8 GET_THAI_DIACRITIC_SORT_ORDER(UINT32 p_index);
static void hmi_gfx_mgr02_swap_chars(HMI_CHAR *p_string, UINT32 index1, UINT32 index2);
static void hmi_gfx_mgr02_sortrun_thai_diacritics(HMI_CHAR *p_string, UINT32 p_start_index, UINT32 p_end_index);
void hmi_gfx_mgr02_reorder_thai_diacritics(HMI_CHAR *p_string);
BOOLEAN hmi_gfx_mgr02_normalize_Thai_SaraAm(HMI_CHAR const *p_src_P,HMI_CHAR * p_dst_P);

static const UINT8 hmi_gfx_mgr02_thai_diacritics_sortorder_table[THAI_DIACRITICS_ENTRIES] =
{
    3, /* VowelAbove - 0x0E31 THAI CHARACTER MAI HAN-AKAT */
    0, /*              0x0E32                             */
    0, /*              0x0E33                             */
    3, /* VowelAbove - 0x0E34 THAI CHARACTER SARA I       */
    3, /* VowelAbove - 0x0E35 THAI CHARACTER SARA II      */
    3, /* VowelAbove - 0x0E36 THAI CHARACTER SARA UE      */
    3, /* VowelAbove - 0x0E37 THAI CHARACTER SARA UEE     */
    1, /* VowelBelow - 0x0E38 THAI CHARACTER SARA U       */
    1, /* VowelBelow - 0x0E39 THAI CHARACTER SARA UU      */
    1, /* VowelBelow - 0x0E3A THAI CHARACTER PHINTHU      */
    0, /*              0x0E3B                             */
    0, /*              0x0E3C                             */
    0, /*              0x0E3D                             */
    0, /*              0x0E3E                             */
    0, /*              0x0E3F                             */
    0, /*              0x0E40                             */
    0, /*              0x0E41                             */
    0, /*              0x0E42                             */
    0, /*              0x0E43                             */
    0, /*              0x0E44                             */
    0, /*              0x0E45                             */
    0, /*              0x0E46                             */
    3, /* VowelAbove - 0x0E47 THAI CHARACTER MAITAIKHU    */
    4, /* ToneMark   - 0x0E48 THAI CHARACTER MAI EK       */
    4, /* ToneMark   - 0x0E49 THAI CHARACTER MAI THO      */
    4, /* ToneMark   - 0x0E4A THAI CHARACTER MAI TRI      */
    4, /* ToneMark   - 0x0E4B THAI CHARACTER MAI CHATTAWA */
    5, /* Sign       - 0x0E4C THAI CHARACTER THANTHAKHAT  */
    2, /* Nikhahit   - 0x0E4D THAI CHARACTER NIKHAHIT     */
    5, /* Sign       - 0x0E4E THAI CHARACTER YAMAKKAN     */
};
static UINT8 GET_THAI_DIACRITIC_SORT_ORDER(UINT32 p_index)
{
    UINT8 fl_return_value;    
    if(((p_index < THAI_DIACRITICS_START) || (p_index > THAI_DIACRITICS_END)))
    { 
       fl_return_value = 0u;
    }
    else 
    {
       fl_return_value =  (UINT8)hmi_gfx_mgr02_thai_diacritics_sortorder_table[p_index - THAI_DIACRITICS_START];
    }
	return fl_return_value;
}

static void hmi_gfx_mgr02_swap_chars(HMI_CHAR *p_string, UINT32 index1, UINT32 index2)
{
    UINT32 fl_strLength = HMI_STRLEN(p_string);
    if ((index1 < fl_strLength) && (index2 < fl_strLength))
    {
      HMI_CHAR fl_char;
      /* swap the unicodes */
      fl_char = p_string[index1];
      p_string[index1] = p_string[index2];
      p_string[index2] = fl_char;
    }
}
static void hmi_gfx_mgr02_sortrun_thai_diacritics(HMI_CHAR *p_string, UINT32 p_start_index, UINT32 p_end_index)
{
    UINT32 fl_outer_index, fl_inner_index;
    UINT8 fl_sort_order1, fl_sort_order2;

    for(fl_outer_index=p_end_index; fl_outer_index != p_start_index; fl_outer_index -= 1U)
    {
        for (fl_inner_index=p_start_index; fl_inner_index != fl_outer_index; fl_inner_index += 1U)
        {
            fl_sort_order1 = GET_THAI_DIACRITIC_SORT_ORDER(p_string[fl_inner_index]);
            fl_sort_order2 = GET_THAI_DIACRITIC_SORT_ORDER(p_string[fl_inner_index + 1U]);
            if (fl_sort_order1 > fl_sort_order2)
            {
                hmi_gfx_mgr02_swap_chars(p_string, fl_inner_index, (fl_inner_index+1U));
            }
        }
    }
}
void hmi_gfx_mgr02_reorder_thai_diacritics(HMI_CHAR *p_string)
{
    UINT32 fl_index;
    UINT32 fl_start_index, fl_end_index;
    UINT16 endIndex = (UINT16)wcslen(p_string);
    fl_index = 0U;
    while (fl_index != (endIndex + (UINT32)1))
    {
        if((GET_THAI_DIACRITIC_SORT_ORDER(p_string[fl_index])) != 0U)
        {
            fl_start_index = fl_index;
            /* find end of run of diacritics */
            while((fl_index != (endIndex + (UINT32)1)) && (GET_THAI_DIACRITIC_SORT_ORDER(p_string[fl_index]) != 0u))
            {
                fl_index += 1U;
            }
            fl_index -= 1U;
            fl_end_index = fl_index;
            hmi_gfx_mgr02_sortrun_thai_diacritics(p_string, fl_start_index, fl_end_index);
        }
        fl_index += 1U;
    }
}

/*============================================================================
** Function Name:    hmi_gfx_mgr02_normalize_Thai_SaraAm
** Visibility:       global
** Description:      Interface to process the GSUB table data.
** Invocation:       Invoked by hmi_gfx_mgr02_gsub_process
** Inputs/Outputs:   None.
** Critical Section: None.
** Description:      This is done to specially handle the SARA_AM character 0xE33. 
**	   The aim of this function is to split 0xE33 to 0xE4D and 0xE32 so that 
**	   we can properly position the 0xE4D character along with any other marks 
**	   present than when it is combined as a single character as 0xE33. 
**     hmi_gfx_mgr02_normalize_Thai_SaraAm() does the conversion:
**            [mark char] SARA_AM -> [mark char] NIKHAHIT SARA_AA
**     hmi_gfx_mgr02_reorder_thai_diacritics() does the reordering:
**            [mark char] NIKHAHIT SARA_AA -> NIKHAHIT [markchar] SARA_AA 
**==========================================================================*/
BOOLEAN hmi_gfx_mgr02_normalize_Thai_SaraAm(HMI_CHAR const *p_src_P,HMI_CHAR * p_dst_P)
{
    HMI_CHAR const * fl_src_P  = p_src_P;
    HMI_CHAR * fl_dst_P  = p_dst_P;
    BOOLEAN    fl_result = FALSE;

    while((*fl_src_P != 0U))
    {
        if (*fl_src_P == GFX_CHAR_THAI_VOWEL_SIGN_SARA_AM)
        {
            *fl_dst_P = GFX_CHAR_THAI_NIKKHAHIT;
             fl_dst_P++;
            *fl_dst_P = GFX_CHAR_THAI_VOWEL_SIGN_SARA_AA;
             fl_result = TRUE;
        }
        else
        {
            *fl_dst_P = *fl_src_P;
        }
        fl_src_P++;
        fl_dst_P++;
    }
    return fl_result;
}


#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */

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
 ** CMS Rev 1.0      07-Aug-2018     kkubendi
 ** Creation.
 ** Algorithm to handle Thai unicodes reordering
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
