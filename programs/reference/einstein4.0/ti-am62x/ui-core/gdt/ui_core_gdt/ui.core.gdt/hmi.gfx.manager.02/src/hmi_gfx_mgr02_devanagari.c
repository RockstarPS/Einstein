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
 ** Name:           hmi_gfx_mgr02_devanagari.c
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
#define HMI_GFX_MGR02_DEVANAGARI_C

#include "hmi_gfx_mgr02_generic.h"
#if defined (GFX_MGR02_FONT_GSUB_TABLE_ENABLED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_devanagari.h"

#define HMI_G_N_ELEMENTS(arr)		(sizeof (arr) / sizeof ((arr)[0]))

/* Characters that get refered to by name... */
#define HMI_C_SIGN_ZWNJ     0x200C
#define HMI_C_SIGN_ZWJ      0x200D
#define HMI_C_DOTTED_CIRCLE 0x25CC

/*
 * Character class values
 */
typedef enum
{
  HMI_CC_RESERVED,
  HMI_CC_MODIFYING_MARK_ABOVE,
  HMI_CC_MODIFYING_MARK_POST,
  HMI_CC_INDEPENDENT_VOWEL,
  HMI_CC_CONSONANT,
  HMI_CC_CONSONANT_WITH_NUKTA,
  HMI_CC_NUKTA,
  HMI_CC_DEPENDENT_VOWEL,
  HMI_CC_VIRAMA,
  HMI_CC_ZERO_WIDTH_MARK,
  HMI_CC_AL_LAKUNA,
  HMI_CC_COUNT
} hmi_IndicOTCharClassValues;

/*
 * Character class flags
 */
#define HMI_CF_CLASS_MASK   0x0000FFFFU

#define HMI_CF_CONSONANT    0x80000000U

#define HMI_CF_REPH         0x40000000U
#define HMI_CF_VATTU        0x20000000U
#define HMI_CF_BELOW_BASE   0x10000000U
#define HMI_CF_POST_BASE    0x08000000U

#define HMI_CF_MATRA_PRE    0x04000000U
#define HMI_CF_MATRA_BELOW  0x02000000U
#define HMI_CF_MATRA_ABOVE  0x01000000U
#define HMI_CF_MATRA_POST   0x00800000U
#define HMI_CF_LENGTH_MARK  0x00400000U

#define HMI_CF_INDEX_MASK   0x000F0000U
#define HMI_CF_INDEX_SHIFT  16


/*
 * Script flags
 */
#define HMI_SF_MATRAS_AFTER_BASE    0x80000000U
#define HMI_SF_REPH_AFTER_BELOW     0x40000000U
#define HMI_SF_EYELASH_RA           0x20000000U
#define HMI_SF_MPRE_FIXUP           0x10000000U
#define HMI_SF_PROCESS_ZWJ          0x08000000U

#define HMI_SF_POST_BASE_LIMIT_MASK 0x0000FFFFU
#define HMI_SF_NO_POST_BASE_LIMIT   0x00007FFFU

/*
 * Bit flags for the indic feature tags
 */
enum hmi_indic_glyph_feature
{
  nukt = 0x0001,
  akhn = 0x0002,
  rphf = 0x0004,
  blwf = 0x0008,
  half = 0x0010,
  pstf = 0x0020,
  vatu = 0x0040,
  pres = 0x0080,
  blws = 0x0100,
  abvs = 0x0200,
  psts = 0x0400,
  haln = 0x0800,
  blwm = 0x1000,
  abvm = 0x2000,
  dist = 0x4000,
  junk = 0x8000,
  init = 0x10000
};

/*
 * Complement of the feature flags that
 * will be assigned to specific glyphs.
 *
 * The names come from the ICU implementation,
 * which listed the actual tags in an order
 * such that tags could be assigned using the
 * address of the first one: &tags[0], &tags[1],
 * &tags[2], &tags[3]. The name of each set here
 * is the name of the first tag in the ICU list.
 */
enum hmi_indic_glyph_property
{
  rphf_p = (junk | dist | init),
  blwf_p = (junk | dist | init | rphf),
  half_p = (junk | dist | init | rphf | blwf),
  pstf_p = (junk | dist | init | rphf | blwf | half),
  nukt_p = (junk | dist | init | rphf | blwf | half | pstf)
};

/*
 * Macros to test the charClass flags for various things.
 */
#define HMI_IS_VM_ABOVE(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_MODIFYING_MARK_ABOVE)
#define HMI_IS_VM_POST(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_MODIFYING_MARK_POST)
#define HMI_IS_CONSONANT(charClass) (((charClass) & HMI_CF_CONSONANT) != (UINT32)0)
#define HMI_IS_REPH(charClass) (((charClass) & HMI_CF_REPH) != (UINT32)0)
#define HMI_IS_NUKTA(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_NUKTA)
#define HMI_IS_VIRAMA(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_VIRAMA)
#define HMI_IS_AL_LAKUNA(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_AL_LAKUNA)
#define HMI_IS_VATTU(charClass) (((charClass) & HMI_CF_VATTU) != (UINT32)0)
#define HMI_IS_MATRA(charClass) (((charClass) & HMI_CF_CLASS_MASK) == (UINT32)HMI_CC_DEPENDENT_VOWEL)
#define HMI_IS_SPLIT_MATRA(charClass) (((charClass) & HMI_CF_INDEX_MASK) != (UINT32)0)
#define HMI_IS_M_PRE(charClass) (((charClass) & HMI_CF_MATRA_PRE) != (UINT32)0)
#define HMI_IS_M_BELOW(charClass) (((charClass) & HMI_CF_MATRA_BELOW) != (UINT32)0)
#define HMI_IS_M_ABOVE(charClass) (((charClass) & HMI_CF_MATRA_ABOVE) != (UINT32)0)
#define HMI_IS_M_POST(charClass) (((charClass) & HMI_CF_MATRA_POST) != (UINT32)0)
#define HMI_IS_LENGTH_MARK(charClass) (((charClass) & HMI_CF_LENGTH_MARK) != (UINT32)0)
#define HMI_HAS_POST_OR_BELOW_BASE_FORM(charClass) (((charClass) & (HMI_CF_POST_BASE | HMI_CF_BELOW_BASE)) != (UINT32)0)
#define HMI_HAS_POST_BASE_FORM(charClass) (((charClass) & HMI_CF_POST_BASE) != (UINT32)0)
#define HMI_HAS_BELOW_BASE_FORM(charClass) (((charClass) & HMI_CF_BELOW_BASE) != (UINT32)0)


/*
 * Split matra table indices
 */
#define hmi_x1 (1 << HMI_CF_INDEX_SHIFT)
#define hmi_x2 (2 << HMI_CF_INDEX_SHIFT)
#define hmi_x3 (3 << HMI_CF_INDEX_SHIFT)
#define hmi_x4 (4 << HMI_CF_INDEX_SHIFT)
#define hmi_x5 (5 << HMI_CF_INDEX_SHIFT)
#define hmi_x6 (6 << HMI_CF_INDEX_SHIFT)
#define hmi_x7 (7 << HMI_CF_INDEX_SHIFT)
#define hmi_x8 (8 << HMI_CF_INDEX_SHIFT)
#define hmi_x9 (9 << HMI_CF_INDEX_SHIFT)

/*
 * Simple classes
 */
#define hmi_xx (HMI_CC_RESERVED)
#define hmi_ma (HMI_CC_MODIFYING_MARK_ABOVE)
#define hmi_mp (HMI_CC_MODIFYING_MARK_POST)
#define hmi_iv (HMI_CC_INDEPENDENT_VOWEL)
#define hmi_ct (HMI_CC_CONSONANT | HMI_CF_CONSONANT)
#define hmi_cn (HMI_CC_CONSONANT_WITH_NUKTA | HMI_CF_CONSONANT)
#define hmi_nu (HMI_CC_NUKTA)
#define hmi_dv (HMI_CC_DEPENDENT_VOWEL)
#define hmi_dl (hmi_dv | HMI_CF_MATRA_PRE)
#define hmi_db (hmi_dv | HMI_CF_MATRA_BELOW)
#define hmi_da (hmi_dv | HMI_CF_MATRA_ABOVE)
#define hmi_dr (hmi_dv | HMI_CF_MATRA_POST)
#define hmi_lm (hmi_dv | HMI_CF_LENGTH_MARK)
#define hmi_vr (HMI_CC_VIRAMA)
#define hmi_al (HMI_CC_AL_LAKUNA)

/*
 * Split matras
 */
#define hmi_s1 (hmi_dv | hmi_x1)
#define hmi_s2 (hmi_dv | hmi_x2)
#define hmi_s3 (hmi_dv | hmi_x3)
#define hmi_s4 (hmi_dv | hmi_x4)
#define hmi_s5 (hmi_dv | hmi_x5)
#define hmi_s6 (hmi_dv | hmi_x6)
#define hmi_s7 (hmi_dv | hmi_x7)
#define hmi_s8 (hmi_dv | hmi_x8)
#define hmi_s9 (hmi_dv | hmi_x9)

/*
 * consonants with special forms
 * NOTE: this assumes that no consonants with nukta have
 * special forms... (Bengali RA?)
 */
#define hmi_bb (hmi_ct | HMI_CF_BELOW_BASE)
#define hmi_pb (hmi_ct | HMI_CF_POST_BASE)
#define hmi_vt (hmi_bb | HMI_CF_VATTU)
#define hmi_rv (hmi_vt | HMI_CF_REPH)
#define hmi_rp (hmi_pb | HMI_CF_REPH)
#define hmi_rb (hmi_bb | HMI_CF_REPH)

static const UINT32 hmi_devaCharClasses[] =
{
    hmi_xx, hmi_ma, hmi_ma, hmi_mp, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, /* 0900 - 090F */
    hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_iv, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, /* 0910 - 091F */
    hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_cn, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, /* 0920 - 092F */
    hmi_rv, hmi_cn, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_xx, hmi_xx, hmi_nu, hmi_xx, hmi_dr, hmi_dl, /* 0930 - 093F */
    hmi_dr, hmi_db, hmi_db, hmi_db, hmi_db, hmi_da, hmi_da, hmi_da, hmi_da, hmi_dr, hmi_dr, hmi_dr, hmi_dr, hmi_vr, hmi_xx, hmi_xx, /* 0940 - 094F */
    hmi_xx, hmi_xx, hmi_db, hmi_da, hmi_da, hmi_xx, hmi_xx, hmi_xx, hmi_cn, hmi_cn, hmi_cn, hmi_cn, hmi_cn, hmi_cn, hmi_cn, hmi_cn, /* 0950 - 095F */
    hmi_iv, hmi_iv, hmi_db, hmi_db, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, /* 0960 - 096F */
    hmi_xx, hmi_xx, hmi_iv, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_xx, hmi_ct, hmi_ct, hmi_ct, hmi_ct, hmi_ct  /* 0970 - 097F */
};

/*
 * Script Flags
 */

/*
 * FIXME: post 'GSUB' reordering of MATRA_PRE's for Malayalam and Tamil
 * FIXME: reformed Malayalam needs to reorder VATTU to before base glyph...
 * FIXME: eyelash RA only for Devanagari??
 */
#define HMI_DEVA_SCRIPT_FLAGS (HMI_SF_EYELASH_RA | HMI_SF_NO_POST_BASE_LIMIT)

/*
 * Indic Class Tables
 */
/* Add a little macro to compute lastChar based on size of the charClasses * table */
#define HMI_INDIC_OT_CLASS_TABLE_DEFINE(name, firstChar, worstCaseExpansion, scriptFlags, charClasses, splitMatraTable, lastChar) \
	hmi_IndicOTClassTable name = {firstChar, lastChar, worstCaseExpansion, scriptFlags, charClasses, splitMatraTable}

    /*const hmi_IndicOTClassTable name = {firstChar, firstChar + HMI_G_N_ELEMENTS (charClasses) - 1, \
				  worstCaseExpansion, scriptFlags, charClasses, splitMatraTable, lastChar}*/

#define HMI_DEV_RRA 0x0931 /* 0930 + 093c */
#define HMI_DEV_QA 0x0958 /* 0915 + 093c */
#define HMI_DEV_YA 0x095F /* 092f + 003c */
#define HMI_DEV_KHHA 0x0959
#define HMI_DEV_GHHA 0x095A
#define HMI_DEV_ZA 0x095B
#define HMI_DEV_DDDHA 0x095C
#define HMI_DEV_RHA 0x095D
#define HMI_DEV_FA 0x095E
#define HMI_DEV_YYA 0x095F

#define HMI_IS_COMPOSITE_WITH_BRAHMI_NUKTA(c) ( \
	(c >= HMI_DEV_QA  && c <= HMI_DEV_YA) || (c == HMI_DEV_RRA) || (c >= HMI_DEV_KHHA  && c <= HMI_DEV_YYA) || \
	FALSE)

struct Output_S
{
    SINT32 fOutIndex;
    SINT32 fOutDstBufLength;

    const SINT32   *fOriginalOffsets;

    HMI_CHAR *fOutChars;
    SINT32   *fCharIndices;
    UINT32  *fCharTags;

    HMI_CHAR fMpre;
    HMI_CHAR fMbelow;
    HMI_CHAR fMabove;
    HMI_CHAR fMpost;
    HMI_CHAR fLengthMark;
    HMI_CHAR fAlLakuna; /* to handle Al-Lakuna in sinhala split matras */
    SINT32    fMatraIndex;
    UINT32    fMatraTags;
    SINT32    fMatraWordStart;
    SINT32    fMPreOutIndex;

    hmi_MPreFixups *fMPreFixups;
};

typedef struct Output_S Output;

static const SINT8 stateTable[][HMI_CC_COUNT] =
{
/*   xx  ma  mp  iv  ct  cn  nu  dv  vr  zw  al */
    { 1,  1,  1,  5,  3,  2,  1,  1,  1,  1,  1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  6,  1, -1, -1, -1, -1,  5,  4, -1, -1},
    {-1,  6,  1, -1, -1, -1,  2,  5,  4, 10,  9},
    {-1, -1, -1, -1,  3,  2, -1, -1, -1,  8, -1},
    {-1,  6,  1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  7,  1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1,  3,  2, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1,  8, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1,  8, -1,  8}

};

const hmi_IndicOTSplitMatra *hmi_indic_ot_get_split_matra(const hmi_IndicOTClassTable *class_table, hmi_IndicOTCharClass char_class);

hmi_IndicOTCharClass hmi_indic_ot_get_char_class(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);

SINT32 hmi_indic_ot_is_vm_above(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_vm_post(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_consonant(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_reph(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_virama(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_al_lakuna(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_nukta(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_vattu(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_matra(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_split_matra(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_m_pre(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_m_below(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_m_above(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_m_post(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_is_length_mark(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_has_post_or_below_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_has_post_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_has_below_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch);
SINT32 hmi_indic_ot_find_syllable(const hmi_IndicOTClassTable *class_table, HMI_CHAR *chars, SINT32 prev, SINT32 char_count);
void hmi_initOutput(Output *output, const SINT32 *originalOffsets, HMI_CHAR *outChars, SINT32 *charIndices, UINT32 *charTags, hmi_MPreFixups *mpreFixups, SINT32 dst_buffer_length);
static void hmi_saveMatra(Output *output, HMI_CHAR matra, hmi_IndicOTCharClass matraClass);
void hmi_initMatra(Output *output, SINT32 matraIndex, UINT32 matraTags, SINT32 wordStart);
static SINT32 hmi_noteMatra(Output *output, const hmi_IndicOTClassTable *classTable, HMI_CHAR matra);
void hmi_noteBaseConsonant(Output *output);
void hmi_writeChar(Output *output, HMI_CHAR ch, SINT32 charIndex, UINT32 charTags);
void hmi_writeMpre(Output *output);
void hmi_writeMbelow(Output *output);
void hmi_writeMabove(Output *output);
void hmi_writeMpost(Output *output);
void hmi_writeLengthMark(Output *output);
static SINT32 hmi_getOutputIndex( const Output *output);
void hmi_writeAlLakuna(Output *output);

HMI_INDIC_OT_CLASS_TABLE_DEFINE (hmi_deva_class_table, 0x0900, 2, HMI_DEVA_SCRIPT_FLAGS, hmi_devaCharClasses, NULL, 0x097F);

SINT32 hmi_indic_ot_reorder(HMI_CHAR * chars, const SINT32 *utf8_offsets, SINT32 char_count, const hmi_IndicOTClassTable *class_table, HMI_CHAR *out_chars, SINT32 *char_indices, UINT32 *char_tags, hmi_MPreFixups **outMPreFixups)
{
    hmi_MPreFixups *mpreFixups = NULL;
    Output output;
    SINT32 i, prev = 0;
    SINT32 last_in_word = (SINT32)FALSE;
    UINT16 fl_op_index=0U;
    UINT16 fl_ip_index=0U;
    UINT16 fl_op_string_length;
    UINT16 fl_ip_string_length;

#if 0   /* sbollam - not sure about its purpose */
	if (outMPreFixups && (class_table->scriptFlags & HMI_SF_MPRE_FIXUP)) {
	mpreFixups = indic_mprefixups_new (char_count);   /* structure */
    }
#endif

  #if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
     hmi_initOutput(&output, utf8_offsets, out_chars, char_indices, char_tags, mpreFixups, GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH);
  #else
     hmi_initOutput(&output, utf8_offsets, out_chars, char_indices, char_tags, mpreFixups, GFX_MGR02_MAX_TEXT_LENGTH);
  #endif
    //hmi_initOutput(&output, utf8_offsets, out_chars, char_indices, char_tags, mpreFixups, char_count);

    while (prev < char_count) {
	SINT32 syllable = hmi_indic_ot_find_syllable(class_table, chars, prev, char_count);
    SINT32 matra, vmabove, vmpost = syllable;

	while ((vmpost > prev) && (hmi_indic_ot_is_vm_post(class_table, chars[vmpost - 1])!=(SINT32)FALSE)) {
	    vmpost -= 1;
	}

	vmabove = vmpost;
	while ((vmabove > prev) && (hmi_indic_ot_is_vm_above(class_table, chars[vmabove - 1])!=(SINT32)FALSE)) {
	    vmabove -= 1;
	}

	matra = vmabove - 1;
	hmi_initMatra(&output, prev, (UINT32)blwf_p, (SINT32)!last_in_word);
	while ((hmi_noteMatra(&output, class_table, chars[matra])!= (SINT32)FALSE) &&
	       (matra != prev))
	{
	    matra--;
	}
	last_in_word = (SINT32)TRUE;
	switch (hmi_indic_ot_get_char_class(class_table, chars[prev]) & HMI_CF_CLASS_MASK) {
	case (UINT32)HMI_CC_RESERVED:
	    last_in_word = (SINT32)FALSE;
	    /* Fall through */
	case (UINT32)HMI_CC_INDEPENDENT_VOWEL:
	case (UINT32)HMI_CC_ZERO_WIDTH_MARK:
	    for (i = prev; i < syllable; i += 1) {
		hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)blwf_p);
	    }

	    break;

	case (UINT32)HMI_CC_MODIFYING_MARK_ABOVE:
	case (UINT32)HMI_CC_MODIFYING_MARK_POST:
	case (UINT32)HMI_CC_NUKTA:
	case (UINT32)HMI_CC_VIRAMA:
#if 0 ////sbollam
		/* patch for rendering fix for Malayalam SAMVRUTHOKARA by suresh */
	    if (chars[prev - 1] == 0x0D41) {
	       	 hmi_writeChar(&output, chars[prev], prev, (UINT32)blwf_p);
		 break;
	    }
	    /* end patch */
#endif
	case (UINT32)HMI_CC_AL_LAKUNA:
	    hmi_writeChar(&output, HMI_C_DOTTED_CIRCLE, prev, (UINT32)blwf_p);
	    hmi_writeChar(&output, chars[prev], prev, (UINT32)blwf_p);
	    break;

	case (UINT32)HMI_CC_DEPENDENT_VOWEL:
	    hmi_writeMpre(&output);
	    hmi_writeChar(&output, HMI_C_DOTTED_CIRCLE, prev, (UINT32)blwf_p);
	    hmi_writeMbelow(&output);
	    hmi_writeMabove(&output);
	    hmi_writeMpost(&output);
	    hmi_writeLengthMark(&output);
	    hmi_writeAlLakuna(&output);
	    break;

	case (UINT32)HMI_CC_CONSONANT:
	case (UINT32)HMI_CC_CONSONANT_WITH_NUKTA:
	{
	    UINT32 length = (vmabove - prev);
	    SINT32 lastConsonant = vmabove - 1;
	    SINT32 baseLimit = prev;
	    SINT32 baseConsonant, postBase, postBaseLimit;
	    SINT32 seenVattu, seenBelowBaseForm, supressVattu;
	    SINT32 bcSpan;

	    /* Check for REPH at front of syllable */
	    if ((length > (UINT32)2) &&(hmi_indic_ot_is_reph(class_table, chars[prev])!=(SINT32)FALSE) && (hmi_indic_ot_is_virama(class_table, chars[prev + 1])!=(SINT32)FALSE)) {
		baseLimit += 2;

		/* Check for eyelash RA, if the script supports it */
		if (((class_table->scriptFlags & HMI_SF_EYELASH_RA) != (UINT32)0) &&
		    (chars[baseLimit] == (HMI_CHAR)HMI_C_SIGN_ZWJ)) {
		    if (length > (UINT32)3) {
			baseLimit += 1;
		    } else {
			baseLimit -= 2;
		    }
		}
	    }

	    while ((lastConsonant > baseLimit) && !(hmi_indic_ot_is_consonant(class_table, chars[lastConsonant])!=(SINT32)FALSE)) {
		lastConsonant -= 1;
	    }

	    baseConsonant = lastConsonant;
	    postBase = lastConsonant + 1;

	    postBaseLimit = (class_table->scriptFlags & HMI_SF_POST_BASE_LIMIT_MASK);
	    seenVattu = (SINT32)FALSE;
	    seenBelowBaseForm = (SINT32)FALSE;
	    supressVattu = (SINT32)TRUE;

	    while (baseConsonant > baseLimit) {
		hmi_IndicOTCharClass charClass = hmi_indic_ot_get_char_class(class_table, chars[baseConsonant]);

		if (HMI_IS_CONSONANT(charClass)) {
		    if ((postBaseLimit == 0) || (seenVattu != (SINT32)FALSE) ||
			((baseConsonant > baseLimit) && !(hmi_indic_ot_is_virama(class_table, chars[baseConsonant - 1])!=(SINT32)FALSE)) ||
			!HMI_HAS_POST_OR_BELOW_BASE_FORM(charClass)) {
			break;
		    }

		    seenVattu = ((SINT32)HMI_IS_VATTU(charClass));

		    if (HMI_HAS_POST_BASE_FORM(charClass)) {
			if (seenBelowBaseForm !=(SINT32)FALSE) {
			    break;
			}

			postBase = baseConsonant;
		    } else if (HMI_HAS_BELOW_BASE_FORM(charClass)) {
			seenBelowBaseForm = (SINT32)TRUE;
		    }else{
		    	/*For Fixing MISRA warning.*/
		    }

		    postBaseLimit -= 1;
		}

		baseConsonant -= 1;
	    }

	    /* not sure about its purpose - kcsarava */
		/* Write Mpre */
	    hmi_writeMpre(&output);       /* used to write the saved matras */

	    /* Write eyelash RA */
	    /* NOTE: baseLimit == prev + 3 iff eyelash RA present... */
	    if (baseLimit == (prev + 3)) {
		hmi_writeChar(&output, chars[prev], prev, (UINT32)half_p);
		hmi_writeChar(&output, chars[prev + 1], prev /*+ 1*/, (UINT32)half_p);
		hmi_writeChar(&output, chars[prev + 2], prev /*+ 2*/, (UINT32)half_p);
	    }

	    /* write any pre-base consonants */
	    supressVattu = (SINT32)TRUE;

	    for (i = baseLimit; i < baseConsonant; i += 1) {
		HMI_CHAR ch = chars[i];
		/* Applying blwf to the first consonant doesn't makes sense
		 * since the below-form follows the consonant that it is
		 * put under */
		UINT32 tag = (UINT32)((i == baseLimit) ? half_p : blwf_p);
		hmi_IndicOTCharClass charClass = hmi_indic_ot_get_char_class(class_table, ch);

		if (HMI_IS_CONSONANT(charClass)) {
		    if (((HMI_IS_VATTU(charClass) && (supressVattu != (SINT32)FALSE))) || (((i + 2) < baseConsonant) && (chars[i + 2] == (HMI_CHAR)HMI_C_SIGN_ZWNJ)))
            {
			  tag = (UINT32)nukt_p;
		    }
		    supressVattu = ((SINT32)HMI_IS_VATTU(charClass));
		} else if (HMI_IS_VIRAMA(charClass) && (chars[i + 1] == (HMI_CHAR)HMI_C_SIGN_ZWNJ))
		{
		    tag = (UINT32)nukt_p;
		}
		else{
			/*To Fix MISRA warning.*/
		}

		hmi_writeChar(&output, ch, /*i*/ prev, tag);
	    }

	    bcSpan = baseConsonant + 1;

	    if ((bcSpan < vmabove) && (hmi_indic_ot_is_nukta(class_table, chars[bcSpan])!= (SINT32)FALSE)) {
		bcSpan += 1;
	    }

	    if ((baseConsonant == lastConsonant) && (bcSpan < vmabove) && (hmi_indic_ot_is_virama(class_table, chars[bcSpan])!=(SINT32)FALSE)) {
		bcSpan += 1;

		if ((bcSpan < vmabove) && (chars[bcSpan] == (HMI_CHAR)HMI_C_SIGN_ZWNJ)) {
		    bcSpan += 1;
		}
	    }

	    /* note the base consonant for post-GSUB fixups */
	    hmi_noteBaseConsonant(&output);

	    /* write base consonant */
	    for (i = baseConsonant; i < bcSpan; i += 1) {
		hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)nukt_p);
	    }

	    if ((class_table->scriptFlags & HMI_SF_MATRAS_AFTER_BASE) != (UINT32)0) {
		SINT32 is_for_0C48 = (SINT32)FALSE;
		if (output.fOutChars != NULL) {  /*for 0x0C48 of Telugu*/
		    SINT32 t;
		    for (t = prev; t < syllable; t++) {
			if (chars[t] == (HMI_CHAR)0x0C48) {
			    hmi_writeMabove(&output);
			    hmi_writeMbelow(&output);
			    hmi_writeMpost(&output);

			    is_for_0C48 = (SINT32)TRUE;
			    break;
			}
		    }
		}

		if (is_for_0C48 == (SINT32)FALSE) {
		    hmi_writeMbelow(&output);
		    hmi_writeMabove(&output);
		    hmi_writeMpost(&output);
		}
	    }

	    /* write below-base consonants */
	    if (baseConsonant != lastConsonant) {
		for (i = bcSpan + 1; i < postBase; i += 1) {
		    hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)blwf_p);
		}

		if (postBase > lastConsonant) {
		    /* write halant that was after base consonant */
		    hmi_writeChar(&output, chars[bcSpan], /*bcSpan*/ prev, (UINT32)blwf_p);
		}
	    }

	    /* write Mbelow, Mabove */
	    if ((class_table->scriptFlags & HMI_SF_MATRAS_AFTER_BASE) == (UINT32)0) {
		hmi_writeMbelow(&output);
		hmi_writeMabove(&output);
	    }

	   if ((class_table->scriptFlags & HMI_SF_REPH_AFTER_BELOW) != (UINT32)0) {
		if (baseLimit == (prev + 2)) {
		    hmi_writeChar(&output, chars[prev], prev, (UINT32)rphf_p);
		    hmi_writeChar(&output, chars[prev + 1], prev /*+ 1*/, (UINT32)rphf_p);
		}

		/* write VMabove */
		for (i = vmabove; i < vmpost; i += 1) {
		    hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)blwf_p);
		}
	    }

	    /* write post-base consonants */
	    if (baseConsonant != lastConsonant) {
		if (postBase <= lastConsonant) {
		    for (i = postBase; i <= lastConsonant; i += 1) {
			hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)pstf_p);
		    }

		    /* write halant that was after base consonant */
		    hmi_writeChar(&output, chars[bcSpan], /*bcSpan*/ prev, (UINT32)blwf_p);
		}

		/* write the training halant, if there is one */
		if ((lastConsonant < matra) && (hmi_indic_ot_is_virama(class_table, chars[matra])!=(SINT32)FALSE)) {
		    hmi_writeChar(&output, chars[matra], /*matra*/ prev, (UINT32)nukt_p);
		}
	    }

	    /* write Mpost */
	    if ((class_table->scriptFlags & HMI_SF_MATRAS_AFTER_BASE) == (UINT32)0) {
		hmi_writeMpost(&output);
	    }

	    hmi_writeLengthMark(&output);
	    hmi_writeAlLakuna(&output);

	    /* write reph */
	    if ((class_table->scriptFlags & HMI_SF_REPH_AFTER_BELOW) == (UINT32)0) {
		if (baseLimit == (prev + 2)) {
		    hmi_writeChar(&output, chars[prev], prev, (UINT32)rphf_p);
		    hmi_writeChar(&output, chars[prev + 1], prev /*+ 1*/, (UINT32)rphf_p);
		}

		/* write VMabove */
		for (i = vmabove; i < vmpost; i += 1) {
		    hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)blwf_p);
		}
	    }

	    /* write VMpost */
	    for (i = vmpost; i < syllable; i += 1) {
		hmi_writeChar(&output, chars[i], /*i*/ prev, (UINT32)blwf_p);
	    }

	    break;
	}

	default:
		/*To Resolve MISRA warning.*/
	    break;
	}


	prev = syllable;
    }

    if (outMPreFixups) {
	*outMPreFixups = mpreFixups;
    }
    fl_op_string_length  = (UINT16)HMI_STRLEN(out_chars);
    fl_ip_string_length  = (UINT16)HMI_STRLEN(chars);

    /* consonant 0x930, nukta 0x94D have to swap based on its sequence order */
    while(fl_op_index < fl_op_string_length)
    {
      if(out_chars[fl_op_index] == 0x94DU)
      {
        while(fl_ip_index < fl_ip_string_length)
        {
          if(chars[fl_ip_index] == 0x94DU)
          {
            /* Check whether nukta is first and next consonant 0x930 */
            if(chars[fl_ip_index+1U] == 0x930U)
            {
             /*if in input string 0x94D ra nukta comes first and followed by 
             ** consonant 0x930 'R', that means ra sounding should be
             ** second. ex: 
             ** [0x0]	0x0936
             ** [0x1]	0x0941
             ** [0x2]	0x0915
             ** [0x3]	0x094d
             ** [0x4]	0x0930
             ** [0x5]	0x0935
             ** [0x6]	0x093e
             ** [0x7]	0x0930
             ** [0x8]	0x0000
             ** 
             ** Here this word is pronounce as "Shukrvaar" but output of the
             ** this algorithm gives as
             ** [0x0]	0x0936
             ** [0x1]	0x0941
             ** [0x2]	0x0915
             ** [0x3]	0x0930
             ** [0x4]	0x094d
             ** [0x5]	0x0935
             ** [0x6]	0x093e
             ** [0x7]	0x0930
             ** [0x8]	0x0000
             ** 
             ** if we won't swap index 3 and 4 the final word pronounce as
             ** "Shurkvaar, which is wrong and it should be k(ka) sound
             ** first and then r(ra) sencond
             ** so correct word is "Shukrvaar"
             */
              HMI_CHAR ip_temp_char = out_chars[fl_op_index-1U];
              out_chars[fl_op_index] = ip_temp_char;
              out_chars[fl_op_index-1U] = 0x94DU;
            }
            fl_ip_index++;
            break;
          }
          fl_ip_index++;
        }
      }
      fl_op_index++;
    }
    return hmi_getOutputIndex(&output);
}

hmi_IndicOTCharClass hmi_indic_ot_get_char_class(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
    hmi_IndicOTCharClass fl_cls_ret;

    if (ch == (HMI_CHAR)HMI_C_SIGN_ZWJ) {
	fl_cls_ret = (HMI_CF_CONSONANT | ((UINT32)HMI_CC_ZERO_WIDTH_MARK));
    }
    else if (ch == (HMI_CHAR)HMI_C_SIGN_ZWNJ) {
	fl_cls_ret = (UINT32)HMI_CC_ZERO_WIDTH_MARK;
    }
    else if ((ch < class_table->firstChar) || (ch > class_table->lastChar)) {
	fl_cls_ret = (UINT32)HMI_CC_RESERVED;
    }
    else {
    fl_cls_ret = class_table->charClasses[ch - class_table->firstChar];
    }
    return fl_cls_ret;
}

SINT32 hmi_indic_ot_find_syllable(const hmi_IndicOTClassTable *class_table, HMI_CHAR *chars, SINT32 prev, SINT32 char_count)
{
    SINT32 cursor = prev;
    SINT8 state = 0;

    while (cursor < char_count) {
	hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, chars[cursor]);

	state = stateTable[state][char_class & HMI_CF_CLASS_MASK];

 	if (state < 0) {
	    break;
	}

	cursor += 1;
    }

    return cursor;
}

//hmi_initOutput(Output *output, const SINT32 *originalOffsets, UINT32 *outChars, SINT32 *charIndices, unsigned SINT32 *charTags, hmi_MPreFixups *mpreFixups)
void hmi_initOutput(Output *output, const SINT32 *originalOffsets, HMI_CHAR *outChars, SINT32 *charIndices, UINT32 *charTags, hmi_MPreFixups *mpreFixups, SINT32 dst_buffer_length)
{
    output->fOriginalOffsets = originalOffsets;

    output->fOutChars    = outChars;
    output->fCharIndices = charIndices;
    output->fCharTags    = charTags;

    output->fOutIndex    = 0;
    output->fMatraTags   = 0;

    output->fMpre = 0;
    output->fMbelow = 0;
    output->fMabove = 0;
    output->fMpost = 0;
    output->fLengthMark = 0;
    output->fAlLakuna = 0;

    output->fMPreOutIndex = -1;
    output->fOutDstBufLength = dst_buffer_length;
    //output->fMPreFixups = mpreFixups;
}

static void hmi_saveMatra(Output *output, HMI_CHAR matra, hmi_IndicOTCharClass matraClass)
{
    /* FIXME: check if already set, or if not a matra... */
    if (HMI_IS_M_PRE(matraClass)) {
	output->fMpre = matra;
    } else if (HMI_IS_M_BELOW(matraClass)) {
	output->fMbelow = matra;
    } else if (HMI_IS_M_ABOVE(matraClass)) {
	output->fMabove = matra;
    } else if (HMI_IS_M_POST(matraClass)) {
	output->fMpost = matra;
    } else if (HMI_IS_LENGTH_MARK(matraClass)) {
	output->fLengthMark = matra;
    } else if (HMI_IS_AL_LAKUNA(matraClass)) {
	output->fAlLakuna = matra;
    }
    else{
    	/*To resolve MISRA warning.*/
    }
}

void hmi_initMatra(Output *output, SINT32 matraIndex, UINT32 matraTags, SINT32 wordStart)
{
    output->fMpre = 0;
    output->fMbelow = 0;
    output->fMabove = 0;
    output->fMpost = 0;
    output->fLengthMark = 0;
    output->fAlLakuna = 0;
    output->fMPreOutIndex = -1;
    output->fMatraIndex = matraIndex;
    output->fMatraTags = matraTags;
    output->fMatraWordStart = wordStart;
}

static SINT32 hmi_noteMatra(Output *output, const hmi_IndicOTClassTable *classTable, HMI_CHAR matra)
{
    SINT32 fl_status_ret = (SINT32)FALSE;

    hmi_IndicOTCharClass matraClass = hmi_indic_ot_get_char_class(classTable, matra);

    if (HMI_IS_MATRA(matraClass))
	{
		if (HMI_IS_SPLIT_MATRA(matraClass))
		{
			const hmi_IndicOTSplitMatra *splitMatra = hmi_indic_ot_get_split_matra(classTable, matraClass);
			SINT32 i;

			for (i = 0; ((i < 3) && ((*splitMatra)[i] != 0U)); i += 1) {
			HMI_CHAR piece = (*splitMatra)[i];
			hmi_IndicOTCharClass pieceClass = hmi_indic_ot_get_char_class(classTable, piece);

			hmi_saveMatra(output, piece, pieceClass);
			}
		}
		else
		{
			hmi_saveMatra(output, matra, matraClass);
		}
        fl_status_ret = (SINT32)TRUE;
    }
	return fl_status_ret;
}

void hmi_noteBaseConsonant(Output *output)
{
 #if 0
    /* Commented becuase of coverity warning, anyhow we are not doing anything at here */
    if (output->fMPreFixups && output->fMPreOutIndex >= 0)
	{
		//indic_mprefixups_add(output->fMPreFixups, output->fOutIndex, output->fMPreOutIndex);
    }
 #endif
}

void hmi_writeChar(Output *output, HMI_CHAR ch, SINT32 charIndex, UINT32 charTags)
{
    if ((output->fOutChars != NULL) && (output->fOutIndex < output->fOutDstBufLength))
	{
		output->fOutChars[output->fOutIndex]    = ch;
		//output->fCharIndices[output->fOutIndex] = output->fOriginalOffsets[charIndex];
		//output->fCharTags[output->fOutIndex]    = charTags;
     output->fOutIndex += 1;
    }
    
}

void hmi_writeMpre(Output *output)
{
    if (output->fMpre != (HMI_CHAR)0)
	{
		UINT32 tags = output->fMatraTags;
		if (output->fMatraWordStart != (SINT32)FALSE){
			tags &= (UINT32)(~((UINT32)init));
		}
		output->fMPreOutIndex = output->fOutIndex;
		hmi_writeChar(output, output->fMpre, output->fMatraIndex, tags);
    }
}

void hmi_writeMbelow(Output *output)
{
    if (output->fMbelow != (HMI_CHAR)0)
	{
		hmi_writeChar(output, output->fMbelow, output->fMatraIndex, output->fMatraTags);
    }
}

void hmi_writeMabove(Output *output)
{
    if (output->fMabove !=(HMI_CHAR)0)
	{
		hmi_writeChar(output, output->fMabove, output->fMatraIndex, output->fMatraTags);
    }
}

void hmi_writeMpost(Output *output)
{
    if (output->fMpost != (HMI_CHAR)0)
	{
		hmi_writeChar(output, output->fMpost, output->fMatraIndex, output->fMatraTags);
    }
}

void hmi_writeLengthMark(Output *output)
{
    if (output->fLengthMark != (HMI_CHAR) 0)
	{
		hmi_writeChar(output, output->fLengthMark, output->fMatraIndex, output->fMatraTags);
    }
}

static SINT32 hmi_getOutputIndex(const Output *output)
{
    return output->fOutIndex;
}

const hmi_IndicOTSplitMatra *hmi_indic_ot_get_split_matra(const hmi_IndicOTClassTable *class_table, hmi_IndicOTCharClass char_class)
{
    SINT32 index = ((char_class & HMI_CF_INDEX_MASK) >> HMI_CF_INDEX_SHIFT);

    return &class_table->splitMatraTable[index - 1];
}

SINT32 hmi_indic_ot_is_vm_above(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_VM_ABOVE(char_class));
}

SINT32 hmi_indic_ot_is_vm_post(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_VM_POST(char_class));
}

SINT32 hmi_indic_ot_is_consonant(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_CONSONANT(char_class));
}

SINT32 hmi_indic_ot_is_reph(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_REPH(char_class));
}

SINT32 hmi_indic_ot_is_virama(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)(HMI_IS_VIRAMA(char_class) || HMI_IS_AL_LAKUNA(char_class)));
}

SINT32 hmi_indic_ot_is_al_lakuna(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_AL_LAKUNA(char_class));
}

SINT32 hmi_indic_ot_is_nukta(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_NUKTA(char_class));
}

SINT32 hmi_indic_ot_is_vattu(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_VATTU(char_class));
}

SINT32 hmi_indic_ot_is_matra(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_MATRA(char_class));
}

SINT32 hmi_indic_ot_is_split_matra(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_SPLIT_MATRA(char_class));
}

SINT32 hmi_indic_ot_is_m_pre(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_M_PRE(char_class));
}

SINT32 hmi_indic_ot_is_m_below(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_M_BELOW(char_class));
}

SINT32 hmi_indic_ot_is_m_above(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_M_ABOVE(char_class));
}

SINT32 hmi_indic_ot_is_m_post(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_M_POST(char_class));
}

SINT32 hmi_indic_ot_is_length_mark(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_IS_LENGTH_MARK(char_class));
}

SINT32 hmi_indic_ot_has_post_or_below_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_HAS_POST_OR_BELOW_BASE_FORM(char_class));
}

SINT32 hmi_indic_ot_has_post_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_HAS_POST_BASE_FORM(char_class));
}

SINT32 hmi_indic_ot_has_below_base_form(const hmi_IndicOTClassTable *class_table, HMI_CHAR ch)
{
  hmi_IndicOTCharClass char_class = hmi_indic_ot_get_char_class(class_table, ch);

  return ((SINT32)HMI_HAS_BELOW_BASE_FORM(char_class));
}

void hmi_writeAlLakuna(Output *output)
{
    if (output->fAlLakuna != 0U) {
	hmi_writeChar(output, output->fAlLakuna, output->fMatraIndex, output->fMatraTags);
    }
}

/*hmi_MPreFixups *indic_mprefixups_new(SINT32 char_count)
{
    hmi_MPreFixups *mprefixups = g_new (hmi_MPreFixups, 1);
    mprefixups->fFixupCount = 0;
    mprefixups->fFixupData = g_new (hmi_FixupData, char_count);

    return mprefixups;
}*/

#endif /* #if defined (GFX_MGR02_FONT_GSUB_TABLE_ENABLED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED) */

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
 ** CMS Rev 1.0      -------
 ** Creation.
 ** Algorithm to use the GSUB data devanagari scripts
 **==========================================================================*/
#ifdef  __cplusplus
}
#endif
/* end of file =============================================================*/
