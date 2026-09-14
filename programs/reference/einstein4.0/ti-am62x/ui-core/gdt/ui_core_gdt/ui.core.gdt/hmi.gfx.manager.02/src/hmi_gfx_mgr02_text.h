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
** Name:           hmi_gfx_mgr02_text.h
**
** Description:    Interface header for the graphics manager for the
**                 Kepler Spectrum/RainbowLite Platform.
**
** Organization:   Driver Information Software Section,
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_GFX_MGR02_TEXT_H
#define HMI_GFX_MGR02_TEXT_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "hmi_gfx_mgr02_types.h"
#include "hmi_gfx_mgr02_context.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif

#define ARABIC_SET1_LOW      (HMI_CHAR)0x0600 /* Arabic Character set1 Start(1536) */
#define ARABIC_SET1_HIGH     (HMI_CHAR)0x06FF /* Arabic Character set1 End(1791)   */
#define ARABIC_PRESENTATION_FORMS_A_START   (HMI_CHAR)0xFB50 /* Arabic Character set3 Start(64336) */
#define ARABIC_PRESENTATION_FORMS_A_END     (HMI_CHAR)0xFDFF /* Arabic Character set3 End(65023)   */
#define ARABIC_PRESENTATION_FORMS_B_START   (HMI_CHAR)0xFE70 /* Arabic Character set4 Start(65136) */
#define ARABIC_PRESENTATION_FORMS_B_END     (HMI_CHAR)0xFEFF /* Arabic Character set4 End(65279)   */

//U+0590..U+05FF (112 code points)
#define HEBREW_START         (HMI_CHAR)0x0590 /* Hebrew Character Start(1424)   */
#define HEBREW_END           (HMI_CHAR)0x05FF /* Hebrew Character End(1535)   */

//Devanagari Range: 0900097F 
#define DEVANAGARI_START         (HMI_CHAR)0x0900 /* Hindi Character Start(2304)   */
#define DEVANAGARI_END           (HMI_CHAR)0x097F /* Hindi Character End(2431)   */

#define BENGALI_START         (HMI_CHAR)0x0980  
#define BENGALI_END           (HMI_CHAR)0x09FF 
#define MARATHI_START         (HMI_CHAR)0x0900  
#define MARATHI_END           (HMI_CHAR)0x097F 
#define TELUGU_START          (HMI_CHAR)0x0C00  
#define TELUGU_END            (HMI_CHAR)0x0C7F 
#define TAMIL_START           (HMI_CHAR)0x0B80   
#define TAMIL_END             (HMI_CHAR)0x0BFF  
#define GUJARATI_START        (HMI_CHAR)0x0A80  
#define GUJARATI_END          (HMI_CHAR)0x0AFF 
#define KANNADA_START         (HMI_CHAR)0x0C80  
#define KANNADA_END           (HMI_CHAR)0x0CFF 
#define ODIA_START            (HMI_CHAR)0x0B00  
#define ODIA_END              (HMI_CHAR)0x0B7F 
#define MALAYALAM_START       (HMI_CHAR)0x0D00  
#define MALAYALAM_END         (HMI_CHAR)0x0D7F 
#define PUNJABI_START         (HMI_CHAR)0x0A00  
#define PUNJABI_END           (HMI_CHAR)0x0A7F 
#define LRE_UNICODE          (HMI_CHAR)0x202A  /* Unicode for LRE */
#define RLE_UNICODE          (HMI_CHAR)0x202B  /* Unicode for RLE */
#define PDF_UNICODE          (HMI_CHAR)0x202C  /* Unicode for PDF */
#define LRO_UNICODE          (HMI_CHAR)0x202D  /* Unicode for LRO */
#define RLO_UNICODE          (HMI_CHAR)0x202E  /* Unicode for RLO */
#define LRM_UNICODE          (HMI_CHAR)0x200E  /* Unicode for LRM */
#define RLM_UNICODE          (HMI_CHAR)0x200F  /* Unicode for RLM */


#define THAI_CONSONANT_START (HMI_CHAR)0x0E01  /* Unicode  */
#define THAI_CONSONANT_END   (HMI_CHAR)0x0E2E  /* Unicode  */
#define THAI_SIGN_SYMBL      (HMI_CHAR)0x0E2F  /* Unicode  */
#define THAI_SET1_START      (HMI_CHAR)0x0E30  /* Unicode  */ 
#define THAI_SET1_END        (HMI_CHAR)0x0E3A  /* Unicode  */ 
#define THAI_CURRENCY_SYMBL  (HMI_CHAR)0x0E3F  /* Unicode  */ 
#define THAI_SET2_START      (HMI_CHAR)0x0E40  /* Unicode  */
#define THAI_SET2_END        (HMI_CHAR)0x0E5B  /* Unicode  */


typedef  enum
{
     GFX_MGR02_FONT_WRITE_ACTIVE
    ,GFX_MGR02_FONT_ERROR_FAIL
  } GFX_MGR02_FONT_CODE_T;

#if (defined(GFX_MGR02_KEPLER) && (defined(GFX_MGR02_HORIZONTAL_SCROLL_ENABLED)))
  typedef enum
  {
    CALLBCK_FRM_GRAPHICS_SUBCOPY,
    CALLBCK_FRM_GRAPHICS_PASTE
  }GFX_MGR02_GRAPHICS_TRANSFORMATION_CB_T;
#endif

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
  typedef enum
  {
    GFX_MGR02_LANG_READ_DIR_LTR,    /* Language read from Left to Right like English, Thai  */	
    GFX_MGR02_LANG_READ_DIR_RTL     /* Language read from Right to Left like Arabic, Hebrew */
  }GFX_MGR02_LANG_READ_DIR;														 
#endif

  typedef struct
  {
    UINT8                  font_id;           /* Font id for the text. */
    UINT8                  num_chars;         /* number of text chars. */
    GFX_UINT                  alignment:2;       /* text alignment  */
    GFX_UINT                  orientation:2;     /* text draw mode  */
    GFX_UINT                  clip_mode:3;       /* text clip mode  */
    GFX_MGR02_ILOC_DATA    loc;               /* Text Loc Offset */
    GFX_MGR02_ISIZE_W_T    width;             /* text width      */
    GFX_MGR02_ISIZE_H_T    height;            /* text height     */
    GFX_MGR02_ISIZE_H_T    src_height;        /* source height   */
    void *                 text_pointer;      /* Pointer to text buffer */
    UINT32                 text_dest_address; /* Text Frame buffer address. */
  }GFX_MGR02_TEXT_T;

  typedef  void  ( * hmi_gfx_mgr02_font_callback_type )( void);

  /*============================================================================
  ** D A T A   A C C E S S   S E R V I C E S
  **==========================================================================*/

  /*============================================================================
  ** E N T R Y   P O I N T S
  **==========================================================================*/
  void hmi_gfx_mgr02_font_init(void);
  GFX_MGR02_FONT_CHAR_CONFIG const * hmi_gfx_mgr02_get_fcc(HMI_CHAR p_char,
    GFX_MGR02_FONT_LUT const * p_font_lut_SP,
    UINT32 p_table_size,
#if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
    UINT32 p_font_id,
#endif
    UINT32 p_vg_font);
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
  UINT16 hmi_gfx_mgr02_get_arabic_char_count(HMI_CHAR const *In_Str, UINT16 p_count);
#define GFX_MGR02_ARABIC_VOWEL_START        (0x64BU)
#define GFX_MGR02_ARABIC_VOWEL_END          (0x658U)
#define GFX_MGR02_IS_ARABIC_VOWEL(char_unicode)    ((((char_unicode) >= GFX_MGR02_ARABIC_VOWEL_START) && ((char_unicode) <= GFX_MGR02_ARABIC_VOWEL_END)) ? 1U:0U)
#endif
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
  /*  ref: https:\\en.wikipedia.org\wiki\Thai_Industrial_Standard_620-2533  */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE1_START (0x0E31) /* 3633 */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE1_END   (0x0E31) /* 3633 */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE2_START (0x0E34) /* 3636 */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE2_END   (0x0E3A) /* 3642 */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE3_START (0x0E47) /* 3655 */
#define GFX_MGR02_THAI_JOIN_CHAR_RANGE3_END   (0x0E4E) /* 3662 */
#define GFX_MGR02_IS_THAI_JOIN_CHAR(char_unicode)   (((((char_unicode) >= GFX_MGR02_THAI_JOIN_CHAR_RANGE1_START) && ((char_unicode) <= GFX_MGR02_THAI_JOIN_CHAR_RANGE1_END)) || (((char_unicode) >= GFX_MGR02_THAI_JOIN_CHAR_RANGE2_START) && ((char_unicode) <= GFX_MGR02_THAI_JOIN_CHAR_RANGE2_END))  || (((char_unicode) >= GFX_MGR02_THAI_JOIN_CHAR_RANGE3_START) && ((char_unicode) <= GFX_MGR02_THAI_JOIN_CHAR_RANGE3_END))) ? 1U:0U)
  UINT16 hmi_gfx_mgr02_get_thai_char_count(HMI_CHAR const *In_Str, UINT16 p_count);
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */

#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE1_START (0x0941U) /* 2369 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE1_END   (0x0948U) /* 2376 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE2_START (0x0951U) /* 2385 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE2_END   (0x0957U) /* 2391 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE3_START (0x0900U) /* 2304 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE3_END   (0x0902U) /* 2306 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE4_START (0x093AU) /* 2362 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE4_END   (0x093AU) /* 2362 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE5_START (0x094DU) /* 2381 */
#define GFX_MGR02_DEVA_ZW_CHAR_RANGE5_END   (0x094DU) /* 2381 */
#define GFX_MGR02_DEVA_ZW_CHAR(char_unicode)   (((((char_unicode) >= GFX_MGR02_DEVA_ZW_CHAR_RANGE1_START) && ((char_unicode) <= GFX_MGR02_DEVA_ZW_CHAR_RANGE1_END)) || \
                                               (((char_unicode) >= GFX_MGR02_DEVA_ZW_CHAR_RANGE2_START) && ((char_unicode) <= GFX_MGR02_DEVA_ZW_CHAR_RANGE2_END))  || \
                                               (((char_unicode) >= GFX_MGR02_DEVA_ZW_CHAR_RANGE3_START) && ((char_unicode) <= GFX_MGR02_DEVA_ZW_CHAR_RANGE3_END))  || \
                                               (((char_unicode) >= GFX_MGR02_DEVA_ZW_CHAR_RANGE4_START) && ((char_unicode) <= GFX_MGR02_DEVA_ZW_CHAR_RANGE4_END))  || \
                                               (((char_unicode) >= GFX_MGR02_DEVA_ZW_CHAR_RANGE5_START) && ((char_unicode) <= GFX_MGR02_DEVA_ZW_CHAR_RANGE5_END))) ? 1U:0U)

  UINT16 hmi_gfx_mgr02_get_devanagari_char_count(HMI_CHAR const* In_Str, UINT16 p_count);
#endif /* GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED */

#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
/*Reference: http:\\unicode.org\charts\PDF\U0590.pdf*/
#define GFX_MGR02_HEBREW_CANTILLATION_START      (0x0591U)
#define GFX_MGR02_HEBREW_CANTILLATION_END        (0x05AFU)

#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG1_START    (0x05B0U)
#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG1_END      (0x05BDU)

#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG2_START    (0x05BFU)
#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG2_END      (0x05BFU)

#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG3_START    (0x05C1U)
#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG3_END      (0x05C2U)

#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG4_START    (0x05C4U)
#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG4_END      (0x05C5U)

#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG5_START    (0x05C7U)
#define GFX_MGR02_HEBREW_PTS_PUNCT_RNG5_END      (0x05C7U)

#define GFX_MGR02_IS_HEBREW_VOWEL(char_unicode)   (((((char_unicode) >= GFX_MGR02_HEBREW_CANTILLATION_START) && ((char_unicode) <= GFX_MGR02_HEBREW_CANTILLATION_END)) ||\
  (((char_unicode) >= GFX_MGR02_HEBREW_PTS_PUNCT_RNG1_START) && ((char_unicode) <= GFX_MGR02_HEBREW_PTS_PUNCT_RNG1_END))  ||\
  (((char_unicode) >= GFX_MGR02_HEBREW_PTS_PUNCT_RNG2_START) && ((char_unicode) <= GFX_MGR02_HEBREW_PTS_PUNCT_RNG2_END))  ||\
  (((char_unicode) >= GFX_MGR02_HEBREW_PTS_PUNCT_RNG3_START) && ((char_unicode) <= GFX_MGR02_HEBREW_PTS_PUNCT_RNG3_END))  ||\
  (((char_unicode) >= GFX_MGR02_HEBREW_PTS_PUNCT_RNG4_START) && ((char_unicode) <= GFX_MGR02_HEBREW_PTS_PUNCT_RNG4_END))  ||\
  (((char_unicode) >= GFX_MGR02_HEBREW_PTS_PUNCT_RNG5_START) && ((char_unicode) <= GFX_MGR02_HEBREW_PTS_PUNCT_RNG5_END))) ? 1U:0U)
  UINT16 hmi_gfx_mgr02_get_hebrew_char_count(HMI_CHAR const *In_Str, UINT16 p_count);
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */


#if defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED)
UINT16 hmi_gfx_mgr02_get_regional_char_count(HMI_CHAR const *In_Str, UINT16 p_count);
#endif

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
  GFX_MGR02_GPOS_MARK_TABLE const* hmi_gfx_mgr02_get_mark_anch_points(HMI_CHAR p_char, GFX_MGR02_GPOS_MARK_TABLE const *p_gpos_mark_ptr, HMI_CHAR  p_mark_table_size);
  GFX_MGR02_GPOS_BASE_TABLE const* hmi_gfx_mgr02_get_base_anch_points(HMI_CHAR p_char, GFX_MGR02_GPOS_BASE_TABLE const *p_gpos_base_ptr, HMI_CHAR  p_base_table_size);
  GFX_MGR02_GPOS_LIGATURE_TABLE const* hmi_gfx_mgr02_get_ligature_anch_points(HMI_CHAR p_char, GFX_MGR02_GPOS_LIGATURE_TABLE const *p_gpos_lig_ptr, HMI_CHAR p_lig_table_size);
  UINT8 hmi_gfx_mgr02_get_gpos_delta_pixels(GFX_MGR02_GPOS_DELTA * p_delta_pixels, 
    HMI_CHAR const* p_string_ptr,
    SINT32 p_str_index,
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && defined(GFX_MGR02_USE_EXT_FONT_ENGINE)
    UINT32 p_font_id,
#else
    GFX_MGR02_FONT const * p_font_SP,
#endif
    GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
    GFX_MGR02_LANG_READ_DIR p_lang_read_dir);
#endif

#if defined(GFX_MGR02_KEPLER)
  GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_font_kepler_dma_print(GFX_MGR02_TEXT_T * p_text_context, hmi_gfx_mgr02_font_callback_type p_callback);
  GFX_MGR02_FONT_CODE_T hmi_gfx_mgr02_font_fsl_edma_print(GFX_MGR02_TEXT_INFO  const        * p_text_context, 
    hmi_gfx_mgr02_font_callback_type  p_callback,
    UINT32                            p_dest_address,
    UINT32                            p_dest_width,
    UINT32                            p_text_y_sclip,
    UINT32                            p_text_height_cap);
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
  void hmi_gfx_mgr02_font_char_cpu_print(GFX_MGR02_FONT_CHAR_CONFIG const *p_font_fcc_SP
#if defined(GFX_MGR02_CPU_ARABIC_JOINING_PATCH)
    , HMI_CHAR p_char
#endif
    );
#endif
#if defined(GFX_MGR02_DMA_CPU_RENDER) && (GFX_MGR02_TEXT_ROTATION_SUPPORT_ENABLED == 0)
  UINT32 CheckArabicCharRange(HMI_CHAR p_char);
#endif
#endif

  GFX_MGR02_FONT const * hmi_gfx_mgr02_get_font_pointer(UINT32 p_font_id);

  UINT32 hmi_gfx_mgr02_get_font_id(UINT32 p_font_id);
#if defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
#if defined(GFX_MGR02_TXT_EFFECTS_ENABLED) && defined (GFX_MGR02_SHAPE_ENGINE_ENABLED)
  SINT16 hmi_gfx_mgr02_embold_glyph_advance(FT_GlyphSlot p_slot, SINT16 p_x_advance);
#endif
UINT32 hmi_gfx_mgr02_get_ft_char_width(FT_Face p_face, HMI_CHAR p_char, BOOLEAN p_autohint_bool
                                              #ifdef GFX_MGR02_AMBER_FT2_CACHE_ENABLED
                                              , UINT8 p_font_size
                                              , UINT32 p_font_id
                                              #endif
                                              #if defined(GFX_MGR02_TXT_EFFECTS_ENABLED)
                                              ,GFX_MGR02_TXT_SPECIAL_EFFECTS const* p_txt_special_prop_SP
                                              #endif
                                              #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
                                              ,UINT8 p_complex_script
                                              ,hb_buffer_content_type_t p_content_type
                                              , SINT16 p_x_advance
                                              #endif
                                              );
#endif
  UINT32 hmi_gfx_mgr02_get_text_width(GFX_MGR02_TEXT_INFO * p_clip_text_info_SP,
    UINT32                p_font_id,  
    UINT32                p_clip_mode,
    UINT32                p_alignment
  #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
    ,HMI_CHAR            * p_string
  #endif
  #ifdef GFX_MGR02_SHAPE_ENGINE_ENABLED
    ,GFX_MGR02_SHAPE_INFO  *p_shaper_info
  #endif
    );
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)))&& (defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)||defined(GFX_MGR02_VGLITE))
  void hmi_gfx_mgr02_set_font_size(UINT32 p_font_id, UINT8 p_fnt_pt_size);
#endif
#if GFX_MGR02_NUM_OF_FONT_GROUPS > 0
  GFX_MGR02_FNT_GRP_DYN_PROP * hmi_gfx_mgr02_get_gfont_prop(UINT32 p_font_id);
  UINT32 hmi_gfx_mgr02_select_gfont(UINT32 p_font_id, UINT32 p_selection_index, UINT32 p_right2left);
  UINT32 hmi_gfx_mgr02_get_gfont_alignment(UINT32 p_font_id, UINT32 p_alignment);
#if defined (GFX_MGR02_DEFAULT_FONT)
  GFX_MGR02_FONT const * hmi_gfx_mgr02_get_grp_default_font_ptr(UINT32 p_font_id);
#endif
#define GFX_MGR02_GALIGNMENT(_fid, _a) (hmi_gfx_mgr02_get_gfont_alignment((_fid),(_a)))
#else
#define GFX_MGR02_GALIGNMENT(_fid, _a) ((_a))
#endif

#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  BOOLEAN hmi_gfx_mgr02_is_autohint_enabled(UINT32 p_font_id);
#endif
  void hmi_gfx_mgr02_get_string_reverse(HMI_CHAR* p_rev_str, UINT16 p_count);

#ifdef  __cplusplus
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
** CMS Rev 1.82     19-Jan-2018     ARAJASE2
** 1035451: GPOS X Position update for Thai Language
** hmi_gfx_mgr02_get_gpos_delta_pixels function prototype changed to return the status of
** GPOS table availability for the given characters
**
** CMS Rev 1.11     30-Nov-2017    ARAJASE2
** 1005357: Graphics Manager update for Hebrew Text rendering
** Added new function hmi_gfx_mgr02_get_hebrew_char_count to check the hebrew character range
**
** CMS Rev 1.10     21-Aug-2017    CSAKTHIV
** RTC 939063:
** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
**
** CMS Rev 1.9     04/08/17    ADEVI
** 924879 : Monotype Font Integration in Kepler I.
**
** CMS Rev 1.8     06-Jan-2017    SSIGAMAN
** 774561: Removed the conditional compilation macro GFX_MGR02_NUM_OF_DTEXTS
** for hmi_gfx_mgr02_get_font_id().
**
** CMS Rev 1.7     15-Sep-2016    SBOLLAM
** 695578: GPOS handling through mono type font engine.
**
** CMS Rev 1.6     27-JULY-2016    SANAND2
** 641381: Arabic multi line implementation.
**
** CMS Rev 1.5     08-JULY-2016    SSIGAMAN
** 639042: Porsche Misra warning Fix
**
** CMS Rev 1.4     28-Apr-2016    ADEVI
** 578262: Add dynamic change of size of the used TTF fonts
** Added hmi_gfx_mgr02_set_font_size() API.
**
** CMS Rev 1.3     24-Mar-2016    SSIGAMAN
** 554985: Amber:AutoHint status update changes
** Added hmi_gfx_mgr02_is_autohint_enabled() API.
**
** CMS Rev 1.2    22-Aug-2015    APERUMAL
** Ref RTC# 405974
** QA C warnings fix
**
** CMS Rev 1.1    19-Jan-2015    ADEVI
** Ref RTC# 270611, 259720.
** Horizontal scroll implementation done for DCU(4/8BPP) with rotation disabled.
** Enum GFX_MGR02_GRAPHICS_TRANSFORMATION_CB_T introduced.
**
** CMS Rev 1.0      06-Feb-13    ASHEKHAR
** Creation.
**==========================================================================*/

/* end of file =============================================================*/
#endif
