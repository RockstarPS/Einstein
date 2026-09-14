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
 ** Name:           hmi_gfx_mgr02_shape_engine.c
 **
 ** Description:    This is a wrapper layer between gfx_mgr and
 **                 shape engines, which will handles all the text shaping
 **                 and positioning related requestes.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_SHAPE_ENGINE_C
/*=============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_generic.h"
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
  #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) || \
      (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||   \
      (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2))
		#if (defined(GFX_MGR02_SHAPE_ENGINE) && ((GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)))
		#include "hmi_gfx_mgr02_shape_engine.h"
		#include "hmi_gfx_mgr02_context.h"
		#include "hmi_gfx_mgr02_text.h"
	  #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)	&& (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)
		/* MonoType(iType) font engine */
		#include "fs_itype.h"
		/* include the WorldType Shaper API core header file                        */
        #include "tsshaperapi.h"
	  #endif
	  #if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
	       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))
        #include "hb.h"
        #include "hb-ft.h"
        #include "linebreak.h"
	  #endif

#ifdef  __cplusplus
extern "C" {
#endif
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
#include "hmi_lang_pre_render.h"
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE) && (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE)

/* Maximum heap allowed for the MonoType WorldShaper Engine */
#ifndef GFX_MGR02_EXT_SHAPER_MAX_HEAP
  /* A value of 256k is a large general heap for shaping */
  #define GFX_MGR02_EXT_SHAPER_MAX_HEAP 0x40000
#endif

/*! structure that is a container for the WT Shaper objects and font engine  */
typedef struct
{
  FS_STATE *iType;
  TsShaper *shaper;
  TsShaperFont *shaperFont;
  TsShaperText *shaperText;
  TsOtLayoutManager *otlm;
  UINT8  const *font_ffile_name;
} WTShaperWrapper;
			 
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/******************************************************************************
 * Forward declarations
*****************************************************************************/


static TsBool shape_engine_otfont_compare_equal(void *v1, void *v2);
static WTShaperWrapper * shape_engine_otfont_doNothingCopyHandle(WTShaperWrapper *wtshaper);
static void shape_engine_otfont_doNothingReleaseHandle(WTShaperWrapper *wtshaper);
static void * shape_engine_otfont_getTable(void *data, TsTag tag);
static TsResult shape_engine_otfont_releaseTable(void *data, void *table);
static TsBool shape_engine_getGPOSscale(void *data, TsUInt16 glyphID, TsUInt16 *du,
                                 TsMatrix *matrix, TsFixed *xppm, TsFixed *yppm);
static TsBool shape_engine_getGPOSpoint(void *data, TsUInt16 glyphID, TsUInt16 pointIndex,
                                 TsFixed26_6 *x, TsFixed26_6 *y);
static TsResult shape_engine_mapChar(void *data, TsInt32 charID, TsInt32 *glyphID);
static TsResult shape_engine_mapCharVariant(void *data, TsInt32 charID, TsInt32 varSelector, TsInt32 *glyphID);
static TsOtLayout * shape_engine_findOtLayout(void *data, TsTag script, TsTag langSys);
static TsBool shape_engine_getBoolMetric(void *data, TsShaperFontMetric metric);
static TsResult shape_engine_getKerning(void *data, TsInt32 glyphID_1, TsInt32 glyphID_2, TsFixed *dx, TsFixed *dy);
static void shape_engine_units2Pixels(void *data, TsFixed dupem, TS_CONST TsMatrix *m,
                               TsInt16 x_du, TsInt16 y_du, TsFixed *x_pix, TsFixed *y_pix);
static BOOLEAN meetc_nop_criteria(const TsTextProcessInfo* p_textInfo);
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

static WTShaperWrapper l_wtshaper;
static TsMemMgr *l_wtmemmgr = NULL;
static UINT32 l_iType_validation;


/* Array of function pointers that is passed to TsShaperFont_new */
static TS_CONST TsShaperFontFuncs l_shaperFuncs =
{
  shape_engine_units2Pixels,
  shape_engine_getGPOSpoint,
  shape_engine_mapChar,
  shape_engine_mapCharVariant,
  NULL,
  shape_engine_findOtLayout,
  shape_engine_getBoolMetric,
  shape_engine_getKerning,
  shape_engine_getGPOSscale,
  shape_engine_otfont_getTable,
  shape_engine_otfont_releaseTable
};

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/******************************************************************************
 * Private Functions
 *****************************************************************************/

/* The following functions are used by WorldShaper to get font data from iType.
 * They are used to fill in the members of the TsOtFont structure.
 */
static TsBool shape_engine_otfont_compare_equal(void *v1, void *v2)
{
  TS_UNUSED_PARAMETER(v1);
  TS_UNUSED_PARAMETER(v2);
  return (TsBool)TRUE;
}

static WTShaperWrapper * shape_engine_otfont_doNothingCopyHandle(WTShaperWrapper *wtshaper)
{
  return (wtshaper);
}

static void shape_engine_otfont_doNothingReleaseHandle(WTShaperWrapper *wtshaper)
{
  TS_UNUSED_PARAMETER(wtshaper);
}

static void * shape_engine_otfont_getTable(void *data, TsTag tag)
{
  void *table;
  if (data == NULL)
  {
    table = NULL;
  }
  else
  {
    FS_ULONG len = 0UL;
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
    table = FS_get_table(wtshaper->iType, tag, TBL_EXTRACT, &len);
  }
  return table;
}

static TsResult shape_engine_otfont_releaseTable(void *data, void *table)
{
  TsResult fl_ret_status;

  if (data == NULL)
  {
    fl_ret_status = (TS_ERR_ARGUMENT_IS_NULL_PTR);
  }
  else
  {
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;

    if (NULL == table)
    {
      fl_ret_status = (TS_OK);
    }
    else
    {
      if (FS_free_table(wtshaper->iType, table) != SUCCESS)
      {
        fl_ret_status = (TS_ERR_FM_RELEASE_TABLE_FAILED);
      }
      else
      {
        fl_ret_status = (TS_OK);
      }
    }
  }

  return (fl_ret_status);
}

/* The following functions are used by the WorldShaper to perform character
 * layout and positioning.  They are used to fill in the TsShaperFontFuncs
 * structure.
 */

static TsBool shape_engine_getGPOSscale(void *data, TsUInt16 glyphID, TsUInt16 *du,
                                 TsMatrix *matrix, TsFixed *xppm, TsFixed *yppm)
{
  TsBool fl_ret_status;
  if (data != NULL)
  {
    FS_LONG err;
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
#if ((MAJOR_VERSION * 1000) + MINOR_VERSION) < 5102
    TTF_HEAD head;
    TS_UNUSED_PARAMETER(glyphID);
    err = FS_get_table_structure(wtshaper->iType, TAG_head, &head);
    if (SUCCESS != err)
    {
      fl_ret_status = (TsBool)FALSE;
    }
    else
    {
      *du = head.unitsPerEm;

      err = FS_get_scale(wtshaper->iType, &matrix->a, &matrix->b, &matrix->c, &matrix->d);
      if (SUCCESS != err)
      {
        fl_ret_status = (TsBool)FALSE;
      }
      else
      {
        *xppm = matrix->a;
        *yppm = matrix->d;
        fl_ret_status = (TsBool)TRUE;
      }
    }
#else
    FS_USHORT idRangeStart = 0U;
    FS_USHORT idRangeEnd = 0U;

    err = FS_get_gpos_scale(wtshaper->iType, glyphID, du, &matrix->a,
                            &matrix->b, &matrix->c, &matrix->d, xppm, yppm,
                            &idRangeStart, &idRangeEnd);
    if (SUCCESS != err)
    {
      fl_ret_status = (TsBool)FALSE;
    }
    else
    {
      fl_ret_status = (TsBool)TRUE;
    }
#endif
  }
  else
  {
    fl_ret_status = (TsBool)FALSE;
  }
  return fl_ret_status;
}

static TsBool shape_engine_getGPOSpoint(void *data, TsUInt16 glyphID, TsUInt16 pointIndex,
                                        TsFixed26_6 *x, TsFixed26_6 *y)
{
  TsBool fl_ret_status;
  if (data != NULL)
  {
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
    FS_LONG err = FS_get_gpos_pts(wtshaper->iType, glyphID, 1, &pointIndex,
                                  (FS_LONG *)x, (FS_LONG *)y);
    if (SUCCESS != err)
    {
      fl_ret_status = (TsBool)FALSE;
    }
    else
    {
      fl_ret_status = (TsBool)TRUE;
    }
  }
  else
  {
    fl_ret_status = (TsBool)FALSE;
  }

  return fl_ret_status;
}

static TsResult shape_engine_mapChar(void *data, TsInt32 charID, TsInt32 *glyphID)
{

  TsResult result = TS_OK;

  if (data == NULL)
  {
    result = TS_ERR_ARGUMENT_IS_NULL_PTR;
    *glyphID = 0;
  }
  else
  {
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
    if (charID < 0)
    {
      result = TS_ERR_FM_INVALID_CHARID;
      *glyphID = 0;
    }
    else if (TsUnicode_NOP == charID)
    {
      *glyphID = TsGlyphID_NOP;
    }
    else
    {
      *glyphID = (TsInt32)FS_map_char(wtshaper->iType, (FS_ULONG)charID);
      if (l_iType_validation != FALSE)
      {
        if (FS_error(wtshaper->iType) != SUCCESS)
        {
          result = TS_ERR_FM_MAPCHAR_FAILED;
        }
      }
    }
  }
  return result;
}

static TsResult shape_engine_mapCharVariant(void *data, TsInt32 charID, TsInt32 varSelector, TsInt32 *glyphID)
{
  TsResult result = TS_OK;
#if MAJOR_VERSION >= 5
  if (data == NULL)
  {
     result = TS_ERR_ARGUMENT_IS_NULL_PTR;
    *glyphID = 0;
  }
  else
  {
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;

    if (charID < 0)
    {
      result = TS_ERR_FM_INVALID_CHARID;
      *glyphID = 0;
    }
    else if (TsUnicode_NOP == charID)
    {
      *glyphID = TsGlyphID_NOP;
    }
    else
    {
      *glyphID = (TsInt32)FS_map_char_variant(wtshaper->iType, (FS_ULONG)charID, (FS_ULONG)varSelector);
      if (l_iType_validation != FALSE)
      {
        if (FS_error(wtshaper->iType) != SUCCESS)
        {
          result = TS_ERR_FM_MAPCHAR_FAILED;
        }
      }
    }
  }
#else
  TS_UNUSED_PARAMETER(data);
  TS_UNUSED_PARAMETER(charID);
  TS_UNUSED_PARAMETER(varSelector);
  *glyphID = TsGlyphID_MissingGlyph;
#endif
  return result;
}

static TsOtLayout * shape_engine_findOtLayout(void *data, TsTag script, TsTag langSys)
{ 
  TsOtLayout* fl_layout;
  if (data == NULL)
  {
    fl_layout = NULL;
  }
  else
  {
    WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
    TsOtFont otFont;

    otFont.fontData = wtshaper;
    otFont.holdHandle = (void (*)(void *fontData))shape_engine_otfont_doNothingCopyHandle;
    otFont.releaseHandle = (void (*)(void *fontData))shape_engine_otfont_doNothingReleaseHandle;
    otFont.compare = shape_engine_otfont_compare_equal;
    otFont.getTable = shape_engine_otfont_getTable;
    otFont.releaseTable = shape_engine_otfont_releaseTable;
    fl_layout = TsOtLayoutManager_findOtLayout(wtshaper->otlm, &otFont, script, langSys);
  }
  return (fl_layout);
}

static TsBool shape_engine_getBoolMetric(void *data, TsShaperFontMetric metric)
{
  TsBool result;
  switch (metric)
  {
  case TS_SHAPER_FONT_IS_PAIRWISE_KERNING_SUPPORTED:
  {
    if (data != NULL)
    {
      WTShaperWrapper *wtshaper = (WTShaperWrapper *)data;
      FS_ULONG len = 0UL;
      FS_BYTE *table;
      table = FS_get_table(wtshaper->iType, TsMakeTag((FS_ULONG)('k'), (FS_ULONG)('e'), (FS_ULONG)('r'), (FS_ULONG)('n')), TBL_EXTRACT, &len);
      if (NULL != table)
      {
        result = (TsBool)TRUE;
        (void)FS_free_table(wtshaper->iType, table);
      }
      else
      {
        result = (TsBool)FALSE;
      }
    }
    else
    {
      result = (TsBool)FALSE;
    }
  }
  break;

  case TS_SHAPER_FONT_IS_THAI_PRIVATE_USE_AREA_POPULATED:
  {
    /* This routine should only return TRUE for a Thai font that does NOT
     * have OpenType tables for Thai, but which does have glyphs for Thai
     * presentation forms assigned to the Unicode Private Use Area range
     * U+F700..U+F71D. If you are unsure about this, return FALSE.
     */
    result = (TsBool)FALSE;
  }
  break;

  default:
  {
    result = (TsBool)FALSE;
  }
  break;
  }

  return result;
}

static TsResult shape_engine_getKerning(void *data, TsInt32 glyphID_1, TsInt32 glyphID_2, TsFixed *dx, TsFixed *dy)
{
  WTShaperWrapper *wtshaper;
  TsResult result;

  wtshaper = (WTShaperWrapper *)data;

  result = (TsResult)FS_get_kerning(wtshaper->iType, (FS_ULONG)glyphID_1, (FS_ULONG)glyphID_2, dx, dy);

  return result;
}

/* This is a utility function used by the OpenType layout module, specifically
 * the GPOS and GDEF code, to convert from design units to pixels.  The only
 * reason it is here is for picking up the fixed point divide and multiply
 * routines.
 */
static void shape_engine_units2Pixels(void *data, TsFixed dupem, TS_CONST TsMatrix *m,
                               TsInt16 x_du, TsInt16 y_du, TsFixed *x_pix, TsFixed *y_pix)
{
  TsFixed x_scaled, y_scaled;

  TS_UNUSED_PARAMETER(data);

  x_scaled = FixDiv(TsFixed_init(x_du), dupem);
  y_scaled = FixDiv(TsFixed_init(y_du), dupem);

  *x_pix = FixMul(m->a, x_scaled) + FixMul(m->b, y_scaled);
  *y_pix = FixMul(m->c, x_scaled) + FixMul(m->d, y_scaled);
}


/****************************************************************************
Function Name        : hmi_gfx_mgr02_shape_engine_initialize
Description          : Initialize the shape engine
Invocation           : 
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_shape_engine_initialize(void)
{
  UINT32 fl_ret_status = FALSE;
  /* By default iType validation check is not required, becuase
  ** shape engine can still shape it without support of iType
  ** this validation required only when it comes to get
  ** GPOS table information
  */
  l_iType_validation = FALSE;

  /* Initialize font file name pointer */
  l_wtshaper.font_ffile_name = NULL;
  /* Initialize world shaper structure */
  (void)memset(&l_wtshaper, 0, sizeof(l_wtshaper));

  /* Create WorldShaper private memory manager */
  l_wtmemmgr = TsMemMgr_newex(NULL, GFX_MGR02_EXT_SHAPER_MAX_HEAP);
  /* Create the TsShaper object */
  l_wtshaper.shaper = TsShaper_new(l_wtmemmgr);
  if (NULL != l_wtshaper.shaper)
  {
    /* initialize the internal bidi algorithm */
    TsShaper_bidiInit(l_wtshaper.shaper);

    /* Configure shaper base character.
    ** The TsShaper_optionsSet can be used for additional options.
    */
    (void)TsShaper_optionsSetBaseChar(l_wtshaper.shaper, (TsUInt32)GFX_MGR02_DEFAULT_CHAR);

    /* create the TsShaperFont object
     *
     * We do not pass in a memory manager because we have our own.
     * The function pointer table is provided.
     * A pointer global shaper structure is used as a context.
     */
    l_wtshaper.shaperFont = TsShaperFont_new(l_wtmemmgr,&l_shaperFuncs,(void *)&l_wtshaper);
    if (NULL != l_wtshaper.shaperFont)
    {
      /* create the TsShaperText object */
      l_wtshaper.shaperText = TsShaperText_new(l_wtmemmgr);
      if (NULL != l_wtshaper.shaperText)
      {
        /* initialize the TsShaperText object
         *
         * We initialize to a character capacity of 
         * GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH/GFX_MGR02_MAX_TEXT_LENGTH+1 
         * as a starting point.
         * If during shaping, the array length exceeds this capacity due to
         * insertion of glyphs, the array would be grown automatically.
         * However, if a string to be shaped were larger than this, we will
         * need to either call TsShaperText_done followed by TsShaperText_init
         * with the new size or increase the object's capacity using
         * TsShaperText_grow.
         */
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
        if (TS_OK == TsShaperText_init(l_wtshaper.shaperText, (TsLength)(GFX_MGR02_MAX_MULTI_LINE_TEXT_LENGTH+1U)))
#else
        if (TS_OK == TsShaperText_init(l_wtshaper.shaperText, (TsLength)(GFX_MGR02_MAX_TEXT_LENGTH+1U)))
#endif
        {
          fl_ret_status = TRUE; 
        }
        else
        {
          /* Failed -- delete the text shaper so valid() will return false */
          TsShaperText_delete(l_wtshaper.shaperText);
          l_wtshaper.shaperText = NULL;
#ifdef GFX02_DEBUG_INFO
          gfx_debug("Could not initialize shaping text buffer\n") ;
#endif
        }
      }
      else
      {
#ifdef GFX02_DEBUG_INFO
        gfx_debug("Could not initialize shaping text interface\n");
#endif
      }
    }
    else
    {
#ifdef GFX02_DEBUG_INFO
      gfx_debug("Could not initialize shaping font interface\n");
#endif
    }
  }
  else
  {
#ifdef GFX02_DEBUG_INFO
    gfx_debug("Could not initialize shaping engine\n");
#endif
  }
  return fl_ret_status;
}

static UINT32 shape_engine_checkBuffers(UINT32 p_size)
{
   UINT32 fl_ret_status = (UINT32)TRUE;
   /* Check memory exists and is properly sized */
   /* Grow the shaping array */
   if (TS_OK != TsShaperText_grow((void *)l_wtshaper.shaperText, (TsLength)p_size))
   {
    /* Out of memory */
    fl_ret_status = (UINT32)FALSE;
   }
   /* Success */
   return fl_ret_status;
}
/// checks if the passed TsTextProcessInfo meets NOP criteria
/// used to decide if a character can be skipped from rendering or not.
static BOOLEAN meetc_nop_criteria(const TsTextProcessInfo* p_textInfo)
{
  return(
    ((p_textInfo->character == (TsUInt32)TS_CHAR_SOFT_HYPHEN) ||
    (p_textInfo->character == (TsUInt32)TS_CHAR_TAB) ||
    ((p_textInfo->boundaryFlags & (TsUInt16)TS_REQUIRED_LINE_END) != 0U) ||
    ((p_textInfo->glyphID == (TsUInt16)TsGlyphID_NOP) && (p_textInfo->posDelta.indexType != TS_POSADJ_LIGACARET)) ||
    ((p_textInfo->character >= 0x180BU) && (p_textInfo->character <= 0x180EU)) || /* FVS1, FVS2, FVS3, & MVS */
    ((p_textInfo->character >= 0xFE00U) && (p_textInfo->character <= 0xFE0FU)) ||
    ((p_textInfo->character >= 0xE0100U) && (p_textInfo->character <= 0xE01EFU)) ||
    ((p_textInfo->character != (TsUInt32)TsUnicode_NOP) &&
      !((p_textInfo->glyphID != (TsUInt16)TsGlyphID_MissingGlyph) &&
        (((p_textInfo->character >= 0x0600U) && /* Arabic subtending & enclosing marks */
          (p_textInfo->character <= 0x0603U)) ||
          (p_textInfo->character == 0x06DDU))) &&
      !TsUnicode_isPrint(p_textInfo->character))) ? TRUE : FALSE);
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_shape_engine_get_gpos
Description          : Shape the passed string and gives the GPOS delta values
Invocation           : rendering engine
Parameters           : p_font_id - font id, p_string - input string.
Return Value         : TsShaperText * - GPOS delta values 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
TsShaperText * hmi_gfx_mgr02_shape_engine_get_gpos(UINT32 p_font_id, 
  UINT32 const* p_string,
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
  HMI_CHAR const* p_string_u16,
  BOOLEAN p_use_u16_ptr,
#endif
  UINT32 p_str_len,
  FS_STATE * p_client_state)
{
  TsShaperText *fl_ret_result = NULL;
  UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_font_id);
  GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
  BOOLEAN fl_valid_string = FALSE;

#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
  if (p_use_u16_ptr == TRUE)
  {
    fl_valid_string = (BOOLEAN)(NULL != p_string_u16);
  }
  else
#endif
  {
    fl_valid_string = (BOOLEAN)(NULL != p_string);
  }
  if ((fl_valid_string == TRUE) && (NULL != fl_font_SP))
  {
    UINT32 fl_str_inlen = p_str_len;
    if (fl_str_inlen > 0u)
    {
      TsLength fl_index;
      UINT16 readLength = 0;
      TsInt32 growth;
      TsUInt8 baseLevel;
      TsBool bidiNeeded;
      TsResult result;
      TsBool doOffsetMath = (TsBool)FALSE;
      /* Start of this paragraph */
      UINT16 startPos = readLength;
      FS_STATE * face;
      FS_STATE* fl_face = p_client_state;

      /* while rendering of the text it is required to validate iType */
      l_iType_validation = TRUE;

      if (p_client_state == NULL)
      {
        SINT32 ret = MML_OK;
        GFX_FLOAT font_height_pts_temp = fl_font_SP->height_pts * 65536.0f;
        GFX_MGR02_CONTEXT_T const* p_cntx_SP = hmi_gfx_mgr02_context_get_ptr();
        fl_face = hmi_gfx_mgr02_get_mt_client_handler();
        (void)FS_set_font(fl_face, (FILECHAR*)p_cntx_SP->rprop.mt_font_name[fl_font_id]);
        (void)FS_set_scale(fl_face, (FS_LONG)(font_height_pts_temp), 0, 0, (FS_LONG)(font_height_pts_temp));
        IRIS_API_CHECK(ret, FS_set_cmap(fl_face, (FS_USHORT)3, (FS_USHORT)10));
        if (ret != SUCCESS)
        {
          IRIS_API_CHECK(ret, FS_set_cmap(fl_face, (FS_USHORT)3, (FS_USHORT)1));
          if (ret != SUCCESS)
          {
            IRIS_API_CHECK(ret, FS_set_cmap(fl_face, (FS_USHORT)1, (FS_USHORT)0));
          }
        }
        (void)FS_set_flags(fl_face, FLAGS_CMAP_OFF);
      }

      /* Get the face for this font */
   	   face = fl_face;

      /* Ensure we have sufficient buffer space */
      if (FALSE != shape_engine_checkBuffers(fl_str_inlen))
      {
        /* The layout manager cannot be reused for different fonts */
        /* Currently commenting below check, since while using linked fonts,
        ** it is creating some issues, like gpos info is not giving properly
        ** have to check with Monotype.
        */ 
        /*if(l_wtshaper.font_ffile_name != fl_font_SP->f.ffile_name)*/
        {
          /* Need to clean the layout manager so it can properly use the new face */
          if (NULL != l_wtshaper.otlm)
          {
            TsOtLayoutManager_delete(l_wtshaper.otlm);
            l_wtshaper.otlm = NULL;
          }
        }
        /* Assign font face*/
        l_wtshaper.iType = face;
        /* Create the TsOtLayoutManager object if it doesn't exist */
        if (NULL == l_wtshaper.otlm)
        {
          l_wtshaper.otlm = TsOtLayoutManager_new(l_wtmemmgr);
          l_wtshaper.font_ffile_name = fl_font_SP->f.ffile_name;
        }
        if (NULL != l_wtshaper.otlm)
        { 
          l_wtshaper.shaperText->textInfoArrayLen = (TsLength)fl_str_inlen;

          /* clear the array -- this is important to avoid reuse of stale data */
          (void)TS_MEMSET(l_wtshaper.shaperText->textInfoArray, 0, 
            (sizeof(TsTextProcessInfo) * (TsUInt32)l_wtshaper.shaperText->textInfoArrayLen));

          /* Move logical text into the shaper data structure */
          for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
          {
            TsIndex sourceIndex = fl_index + (TsInt32)startPos;
            /* Move character into the shaper data */
#if (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS > 0)
            if (p_use_u16_ptr == TRUE)
            {
              l_wtshaper.shaperText->textInfoArray[fl_index].character = (TsUInt32)p_string_u16[sourceIndex];
            }
            else
#endif
            {
              l_wtshaper.shaperText->textInfoArray[fl_index].character = (TsUInt32)p_string[sourceIndex];
            }
            l_wtshaper.shaperText->textInfoArray[fl_index].sourceIndex   = sourceIndex;
          }

          /* call TsShaper_bidiSetLevels()
          * -- this sets the bidi levels of the text for use by
          *    TsShaper_bidiMirrorChars and TsShaper_bidiReorder()
          * -- if bidiNeeded is FALSE, then no further bidi calls are needed
          */
          result = TsShaper_bidiSetLevels(l_wtshaper.shaper, l_wtshaper.shaperText, 0,
            l_wtshaper.shaperText->textInfoArrayLen - 1,
            &baseLevel, &bidiNeeded,
            TS_NEUTRAL_DIRECTION);
          if (result == TS_OK)
          {
            /* call TsShaper_markBoundaries()
            * -- this sets grapheme and word boundaries
            * -- it also marks line break opportunities
            */
            result = TsShaper_markBoundaries(l_wtshaper.shaper, l_wtshaper.shaperText,
              NULL, 0,
              l_wtshaper.shaperText->textInfoArrayLen - 1,
              &growth);
            if (result == TS_OK)
            {
              /* call TsShaper_bidiMirrorChars()
              * -- this mirrors right-to-left punctuation characters
              * -- e.g. "(" -> ")"
              */
              if ((TsBool)FALSE != bidiNeeded)
              {
                result = TsShaper_bidiMirrorChars(l_wtshaper.shaper, l_wtshaper.shaperText, 0,
                  l_wtshaper.shaperText->textInfoArrayLen - 1);
              }
              if (result == TS_OK)
              {
                /* call TsShaper_shape()
                    * -- this gets the contextual glyph forms for each character
                    * -- it also gets OpenType GPOS position deltas
                    */
                result = TsShaper_shape(l_wtshaper.shaper, l_wtshaper.shaperFont,
                  l_wtshaper.shaperText, 0,
                  l_wtshaper.shaperText->textInfoArrayLen - 1,
                  NULL, &growth);
                if (result == TS_OK)
                {
                  for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
                  {
                    // mark the glyphs that are non printable to NOP to skip
                    // them from rendering.
                    if (meetc_nop_criteria(&l_wtshaper.shaperText->textInfoArray[fl_index]) == TRUE)
                    {
                      l_wtshaper.shaperText->textInfoArray[fl_index].glyphID = (TsUInt16)(TsGlyphID_NOP);
                    }
                  }
                  /* call TsShaper_bidiReorder()
                  * -- this reorders the RTL runs from logical to displayable order
                  * -- can be performed only on lines (not multiple paragraphs)
                  */
                  if ((TsBool)FALSE != bidiNeeded)
                  {
                    result = TsShaper_bidiReorder(l_wtshaper.shaper, l_wtshaper.shaperText, 0,
                      l_wtshaper.shaperText->textInfoArrayLen - 1,
                      baseLevel);
                  }
                  if (result == TS_OK)
                  {
                    /* Check buffers size */
                    if (FALSE != shape_engine_checkBuffers(((UINT32)l_wtshaper.shaperText->textInfoArrayLen + startPos)))
                    {
                      /* Check if we have any character offsets.  If we do then an expensive
                      ** calculation operation is required.
                      **
                      ** As part of this loop, assign the NOP glyph which is required for
                      ** future processing regardless of the offset requirement.
                      */
                      for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
                      {
                        TsTextProcessInfo * textInfo = &l_wtshaper.shaperText->textInfoArray[fl_index];
                        /* Check offsets */
                        if ((0 != textInfo->posDelta.u.place.xPlacement) || (0 != textInfo->posDelta.u.place.yPlacement))
                        {
                          doOffsetMath = (TsBool)TRUE;
                        }
                      }

                      if ((TsBool)FALSE != doOffsetMath)
                      {
                        SINT32 posX = 0;
                        SINT32 posY = 0;
                        TsInt32 delta_x = 0;
                        TsInt32 delta_y = 0;
                        /* Compute positions using multiple computation passes:
                        **
                        **    1. Compute absolute positions using character advance
                        **    2. Adjust position from LTR using relative adjustments from leftward characters
                        **    3. Adjust position from RTL using relative adjustments from righward characters
                        **    4. Convert from absolute to relative positions
                        */
                        /* Pass 1 -- Compute absolute position (reuse advance member of text info) */
                        for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
                        {
                          TsTextProcessInfo * textInfo = &l_wtshaper.shaperText->textInfoArray[fl_index];

                          /* Store position (static) - y1 was already set to zero in the
                          ** TS_MEMSET operation at the start of the shaping loop. */
                          textInfo->boundingBox.x1 = posX;

                          /* Store position (dynamic) */
                          textInfo->advance.x = posX + delta_x;
                          textInfo->advance.y = posY - delta_y;

                          /* Skip invalid glyphs (previously assigned the NOP value) */
                          if ((TsUInt16)TsGlyphID_NOP != textInfo->glyphID)
                          {
                            /* Compute next position */
                            FS_SHORT i_dx, i_dy;
                            FS_FIXED dx, dy;
                            /* Use glyphID's instead of unicodes while shaping */
                            if (SUCCESS == FS_get_advance(face, textInfo->glyphID, 
                              ((UINT16)FS_MAP_GRAYMAP8 | (UINT16)FS_MAP_EDGE_GRAYMAP8), 
                              &i_dx, &i_dy, &dx, &dy))
                            {
                              posX += i_dx;
                              posY = i_dy;
                              delta_x += textInfo->posDelta.u.place.xAdvance;
                              delta_y = textInfo->posDelta.u.place.yAdvance;
                            }
                          }
                        }
                        /* Pass 2 -- adjust using leftward characters */
                        for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
                        {
                          TsTextProcessInfo * textInfo = &l_wtshaper.shaperText->textInfoArray[fl_index];
                          if (textInfo->posDelta.index <= 0)
                          {
                            switch(textInfo->posDelta.indexType)
                            {
                            case TS_POSADJ_LIGACARET: /* ligature caret */
                            case TS_POSADJ_COMBINING: /* mark to base, mark, or ligature */
                            case TS_POSADJ_CONNECTED: /* cursive attachment */
                            {
                                                        TsTextProcessInfo * src = &l_wtshaper.shaperText->textInfoArray[fl_index + textInfo->posDelta.index];
                                                        textInfo->advance.x = src->advance.x + textInfo->posDelta.u.place.xPlacement;
                                                        textInfo->advance.y = src->advance.y + textInfo->posDelta.u.place.yPlacement;
                            }
                              break;

                              //case TS_POSADJ_NONE:
                            default:
                              textInfo->advance.x += textInfo->posDelta.u.place.xPlacement;
                              textInfo->advance.y += textInfo->posDelta.u.place.yPlacement;
                              break;
                            }
                          }
                        }

                        /* Pass 3 -- adjust using rightward characters */
                        for (fl_index = (l_wtshaper.shaperText->textInfoArrayLen - 1); fl_index >= 0; fl_index--)
                        {
                          TsTextProcessInfo * textInfo = &l_wtshaper.shaperText->textInfoArray[fl_index];
                          if (textInfo->posDelta.index > 0)
                          {
                            switch(textInfo->posDelta.indexType)
                            {
                            case TS_POSADJ_LIGACARET: /* ligature caret */
                            case TS_POSADJ_COMBINING: /* mark to base, mark, or ligature */
                            case TS_POSADJ_CONNECTED: /* cursive attachment */
                            {
                                                        TsTextProcessInfo * src = &l_wtshaper.shaperText->textInfoArray[fl_index + textInfo->posDelta.index];
                                                        textInfo->advance.x = src->advance.x + textInfo->posDelta.u.place.xPlacement;
                                                        textInfo->advance.y = src->advance.y + textInfo->posDelta.u.place.yPlacement;
                            }
                              break;

                              //case TS_POSADJ_NONE:
                            default:
                              textInfo->advance.x += textInfo->posDelta.u.place.xPlacement;
                              textInfo->advance.y += textInfo->posDelta.u.place.yPlacement;
                              break;
                            }
                          }
                        }
                      }
                      /* Store glyphs (with offsets) - includes pass 4 computation for relative position */
                      for (fl_index = 0; fl_index < l_wtshaper.shaperText->textInfoArrayLen; fl_index++)
                      {
                        TsTextProcessInfo * textInfo = &l_wtshaper.shaperText->textInfoArray[fl_index];
                        /* Skip invalid glyphs (previously assigned the NOP value) */
                        if ((TsUInt16)TsGlyphID_NOP != textInfo->glyphID)
                        {
                          /* Offsets */
                          if (doOffsetMath)
                          {
                            /* textInfo->advance.x and textInfo->advance.y will contains final GPOS delta values */
                            textInfo->advance.x = (textInfo->advance.x - textInfo->boundingBox.x1);
                            textInfo->advance.y = (textInfo->advance.y - textInfo->boundingBox.y1);
                          }
                          else
                          {
                            textInfo->advance.x = 0;
                            textInfo->advance.y = 0;
                          }
                        }
                      }
                      fl_ret_result = l_wtshaper.shaperText;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if(p_client_state == NULL)
      {
        /* set the flag so that get_glyph functions will turn ON cmap      */
        (void)FS_set_flags(fl_face, FLAGS_CMAP_ON);
      }
    }
  }
  return fl_ret_result;
}



/****************************************************************************
Function Name        : void hmi_gfx_mgr02_shape_engine_shutdown()
Description          : Shutdowning of shape engine
Invocation           : When ever generic context needs to be shutdown
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_shape_engine_shutdown(void)
{
  if (NULL != l_wtshaper.shaperFont)
  {
     TsShaperFont_delete(l_wtshaper.shaperFont);
     l_wtshaper.shaperFont = NULL;
  }
  if (NULL != l_wtshaper.shaper)
  {
     TsShaper_delete(l_wtshaper.shaper);
     l_wtshaper.shaper = NULL;
  }
  if (NULL != l_wtshaper.shaperText)
  {
     TsShaperText_delete(l_wtshaper.shaperText);
     l_wtshaper.shaperText = NULL;
  }
  if (NULL != l_wtshaper.otlm)
  {
     TsOtLayoutManager_delete(l_wtshaper.otlm);
     l_wtshaper.otlm = NULL;
  }
  /* Delete WorldShaper private memory manager */
  if (NULL != l_wtmemmgr)
  {
    TsMemMgr_delete(l_wtmemmgr);
    l_wtmemmgr = NULL;
  }
}

#endif /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)	&& (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) */

/*************************************************************************************
 *********************** HARFBUZZ SHAPER ********************************************
*/

#if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) && \
	       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ))

/* Macro definitions */
#define GFX_INVALID_GLYPHID   (0xFFFEU)

/* Static variables */
static hb_buffer_t* l_hb_buffer;
static GFX_MGR02_HB_SHAPE_WORD_INFO l_hb_shape_word_info;
static GFX_MGR02_HB_SHAPE_INFO l_hb_shape_info;
static UBiDi *l_ubidi;
static UBiDiDirection l_ubidi_text_direction;
static UINT32 l_ubidi_text_length;
static UINT32 l_ubidi_start_offset;
static HMI_CHAR *l_ubidi_reordered_text;
static int32_t l_ubidi_processed_length;
static HMI_CHAR const *l_ubidi_text;
static UINT8 l_ubidi_segment_index;
static UINT8 l_last_string_dir;
static GFX_MGR02_HB_SHAPE_WORD_INFO* hmi_gfx_mgr02_process_ubidi_segment(UINT32 p_font_id, HMI_CHAR const* p_string, UINT32 p_strlen, UINT8 p_RTL);

#if 0
/* Static Functions */
static FT_ULong hmi_gfx_mgr02_shape_engine_get_unicode(FT_Face p_face, FT_UInt p_glyph_id);

/****************************************************************************
Function Name        : hmi_gfx_mgr02_shape_engine_get_unicode()
Description          : Gives the Unicode of passed glyph_id
Invocation           : Internal to shape engine
Return Value         : Unicode of a passed glyph_id
Critical Section     : None
Parameters           : None
******************************************************************************/
static FT_ULong hmi_gfx_mgr02_shape_engine_get_unicode(FT_Face p_face, FT_UInt p_glyph_id)
{
  /*  It is little overhead process since for each and every glyph_id 
      we have to run but still have to do it, need to think about it
	  to optimize it.
  */  
  FT_ULong fl_unicode = GFX_INVALID_GLYPHID, fl_charcode;
  FT_UInt fl_gindex;

  fl_charcode = FT_Get_First_Char(p_face, &fl_gindex);

  while(fl_gindex != 0)
  {			
    if(p_glyph_id == fl_gindex)
    {
      /* Found the Unicode of a given glyph_id */
      fl_unicode = fl_charcode;
      break;
    }
    fl_charcode = FT_Get_Next_Char(p_face,fl_charcode,&fl_gindex);		  
  } 
  return fl_unicode; 		
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_shape_engine_initialize
Description          : Initialize the shape engine
Invocation           : 
Parameters           : None.
Return Value         : Initialization status, False-success, True-Fail
Critical Section     : None
External Interfaces  : None
******************************************************************************/
UINT32 hmi_gfx_mgr02_shape_engine_initialize(void)
{
  UINT32 fl_ret_status = FALSE;
  
  /* Create a buffer which uses by the HB shaper */
  l_hb_buffer = hb_buffer_create();  
  if(hb_buffer_allocation_successful(l_hb_buffer) != TRUE)
  {
    fl_ret_status = TRUE;
#ifdef GFX02_DEBUG_INFO
    gfx_debug("buffer memory allocation failed\n");
#endif
  }
  l_hb_shape_word_info.glyph_info = NULL;
  l_hb_shape_word_info.gpos_info = NULL;
  l_hb_shape_word_info.glyph_count = 0;
  l_hb_shape_word_info.content_type = HB_BUFFER_CONTENT_TYPE_INVALID;
  return fl_ret_status;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_process_ubidi_segment
Description          : Shape the passed string and gives the GPOS delta values
Invocation           : rendering engine
Parameters           : p_font_id - font id, p_string - input string.
Return Value         : hb_glyph_position_t * - GPOS delta values 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_MGR02_HB_SHAPE_WORD_INFO * hmi_gfx_mgr02_process_ubidi_segment(UINT32 p_font_id, HMI_CHAR const * p_string, UINT32 p_strlen, UINT8 p_RTL)
{
  hb_glyph_position_t *fl_glyph_pos=NULL;
  hb_glyph_info_t *fl_glyph_info=NULL;
  GFX_MGR02_HB_SHAPE_WORD_INFO *fl_hb_shape_word_info=NULL;
  UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_font_id);
  GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);

  if ((NULL != p_string) && (NULL != fl_font_SP))
  {
    if((p_strlen > 0) && (fl_font_SP->is_ffile != (UINT8)0))
    {
      GFX_UINT fl_glyph_count;
      hb_font_t *fl_hb_font;
      GFX_MGR02_CONTEXT_T const* fl_context_SP = hmi_gfx_mgr02_context_get_ptr();

      /* Reset the buffer */
      hb_buffer_reset(l_hb_buffer);
      /* put the input text into the buffer */
      hb_buffer_add_utf16(l_hb_buffer, p_string, p_strlen, 0, p_strlen);
      /* Guess the script, language and direction of the buffer */
      hb_buffer_guess_segment_properties(l_hb_buffer);
      if(p_RTL > 0U)
      {
        hb_buffer_set_direction(l_hb_buffer, HB_DIRECTION_RTL);
        hb_buffer_reverse(l_hb_buffer);
      }
      /* Create a font, using FreeType font face. */
      fl_hb_font = hb_ft_font_create_referenced(fl_context_SP->rprop.ft2_faceprop[fl_font_id].ft2_face);
      /* Harfbuzz main Shaping */
      /**
        * hb_shape: parameters
      * 1)@fl_hb_font: an #hb_font_t to use for shaping
      * 2)@l_hb_buffer: an #hb_buffer_t to shape
      * 3)NULL:@features: (array length=num_features) (allow-none): an array of user
      *    specified #hb_feature_t or %NULL
      * 4)0:@num_features: the length of @features array
      *
      * Shapes @buffer using @font turning its Unicode characters content to
      * positioned glyphs. If @features is not %NULL, it will be used to control the
      * features applied during shaping.
      *
      **/
      hb_shape(fl_hb_font, l_hb_buffer, NULL, 0);
      /* Get the glyph's information */
      fl_glyph_info = hb_buffer_get_glyph_infos(l_hb_buffer, &fl_glyph_count);
      /* Get the glyph position information	*/
      fl_glyph_pos = hb_buffer_get_glyph_positions(l_hb_buffer, &fl_glyph_count);
      if((fl_glyph_info != NULL)&&(fl_glyph_pos != NULL)&&(fl_glyph_count != 0U))
      {
        l_hb_shape_word_info.glyph_info = fl_glyph_info;
        l_hb_shape_word_info.gpos_info = fl_glyph_pos;
        l_hb_shape_word_info.glyph_count = fl_glyph_count;
        l_hb_shape_word_info.content_type = hb_buffer_get_content_type(l_hb_buffer);

        fl_hb_shape_word_info = &l_hb_shape_word_info;
      }
      hb_font_destroy(fl_hb_font);
    }
  }
  return fl_hb_shape_word_info;
}
#if 0
/****************************************************************************
Function Name        : hmi_gfx_mgr02_shape_engine_shapedtext
Description          : Shape the passed input string
Invocation           : Global
Parameters           : p_font_id - font id, p_string - input string.
Return Value         : UINT8 - status whether shaping done pass or fail
                     : p_string - processed output string will be strored
					 : in same input buffer
Critical Section     : None
External Interfaces  : None
******************************************************************************/
SINT8 hmi_gfx_mgr02_shape_engine_shapedtext(UINT32 p_font_id, HMI_CHAR * p_string)
{
  SINT8 fl_ret_status = 1;
  UINT32 fl_font_id = hmi_gfx_mgr02_get_font_id((UINT32)p_font_id);
  GFX_MGR02_FONT const * fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
  if ((NULL != p_string) && (NULL != fl_font_SP))
  {
    UINT32 fl_str_inlen = HMI_STRLEN(p_string);
    if((fl_str_inlen > 0) && (fl_font_SP->is_ffile != (UINT8)0)) 
    {
      UINT32 fl_glyph_count,fl_index;
      hb_font_t *fl_hb_font;
      HMI_CHAR * fl_string = p_string; 
      hb_glyph_info_t *fl_glyph_info=NULL;
      GFX_MGR02_CONTEXT_T const* fl_context_SP = hmi_gfx_mgr02_context_get_ptr();

      /* Reset the buffer */
      hb_buffer_reset(l_hb_buffer);
      /* put the input text into the buffer */
      hb_buffer_add_utf16(l_hb_buffer, fl_string, fl_str_inlen, 0, fl_str_inlen);
      /* Guess the script, language and direction of the buffer */
      hb_buffer_guess_segment_properties(l_hb_buffer);
      /* Create a font, using FreeType font face. */
      fl_hb_font = hb_ft_font_create(fl_context_SP->rprop.ft2_faceprop[fl_font_id].ft2_face, NULL);
      /* Harfbuzz main Shaping */
      /**
        * hb_shape: parameters
        * 1)@fl_hb_font: an #hb_font_t to use for shaping
        * 2)@l_hb_buffer: an #hb_buffer_t to shape
        * 3)NULL:@features: (array length=num_features) (allow-none): an array of user
        *    specified #hb_feature_t or %NULL
        * 4)0:@num_features: the length of @features array
        *
        * Shapes @buffer using @font turning its Unicode characters content to
        * positioned glyphs. If @features is not %NULL, it will be used to control the
        * features applied during shaping.
        *
        **/
      hb_shape(fl_hb_font, l_hb_buffer, NULL, 0);

      /* Get the glyph's information */
      fl_glyph_info = hb_buffer_get_glyph_infos(l_hb_buffer, &fl_glyph_count);
      for (fl_index = 0U; fl_index < fl_glyph_count; ++fl_index) 
      {
        fl_string[fl_index] = hmi_gfx_mgr02_shape_engine_get_unicode(fl_context_SP->rprop.ft2_faceprop[fl_font_id].ft2_face, fl_glyph_info[fl_index].codepoint);
      }
      fl_string[fl_index] = 0; /* Terminate out string with null */
      fl_ret_status = 0;
    }
  }
  return fl_ret_status;
}
#endif
void hmi_gfx_mgr02_shape_engine_shutdown(void) 
{
  if(l_hb_buffer != NULL)
  {
    hb_buffer_destroy(l_hb_buffer);
  }
}
static void hmi_gfx_mgr02_reset_ubidi_data(void)
{
  l_ubidi = GFX_MGR02_NULL_PTR;
  l_ubidi_text_direction = UBIDI_RTL;
  l_ubidi_start_offset = 0U;
  l_ubidi_reordered_text = GFX_MGR02_NULL_PTR;
  l_ubidi_processed_length = 0U;
  l_ubidi_text = GFX_MGR02_NULL_PTR;
  l_ubidi_text_length = 0U;
  l_ubidi_segment_index = 0U;
}
static void hmi_gfx_mgr02_reset_hb_shape_info(void)
{
  l_hb_shape_info.glyph_count = 0U;
  (void)memset(l_hb_shape_info.x_offset, 0, sizeof(l_hb_shape_info.x_offset));
  (void)memset(l_hb_shape_info.y_offset, 0, sizeof(l_hb_shape_info.y_offset));
  (void)memset(l_hb_shape_info.x_advance, 0, sizeof(l_hb_shape_info.x_advance));
  (void)memset(l_hb_shape_info.code_point, 0, sizeof(l_hb_shape_info.code_point));
  (void)memset(l_hb_shape_info.content_type, 0, sizeof(l_hb_shape_info.content_type));
  (void)memset(l_hb_shape_info.unicode, 0, sizeof(l_hb_shape_info.unicode));
}

static void bidi_process_sub_string(HMI_CHAR const* p_string, UINT32 p_strlen, UINT8 p_lang_dir_RTL, UINT32 p_font_id, BOOLEAN isSpace)
{
  UINT16 fl_segment_char_index = 0U;
  SINT16 fl_shaper_segment_cpy_dst_index = 0;

  if (hmi_gfx_mgr02_init_ubidi(p_string, p_strlen, p_lang_dir_RTL)== TRUE)
  {
    UINT8 fl_segment_count = hmi_gfx_mgr02_get_ubidi_segment_count();

    GFX_MGR02_HB_SHAPE_WORD_INFO* fl_segment_shaper_ptr = GFX_MGR02_NULL_PTR;
    for (UINT8 fl_segment_index = 0; fl_segment_index < fl_segment_count; fl_segment_index++)
    {
      HMI_CHAR* fl_segment_txt = hmi_gfx_mgr02_get_ubidi_next_segment();
      if (fl_segment_txt != GFX_MGR02_NULL_PTR)
      {
        UINT8 fl_RTL = hmi_gfx_mgr02_get_ubidi_last_segment_RTL_status();
        UINT32 fl_strlen = (UINT32)HMI_STRLEN(fl_segment_txt);
        fl_segment_shaper_ptr = (GFX_MGR02_HB_SHAPE_WORD_INFO*)hmi_gfx_mgr02_process_ubidi_segment(p_font_id, fl_segment_txt, fl_strlen, fl_RTL);
        if (fl_segment_shaper_ptr != GFX_MGR02_NULL_PTR)
        {
          if (isSpace)
          {
            fl_RTL = l_last_string_dir;
          }
          fl_shaper_segment_cpy_dst_index = (SINT16)l_hb_shape_info.glyph_count;
           
          for (fl_segment_char_index = 0; fl_segment_char_index < fl_segment_shaper_ptr->glyph_count; fl_segment_char_index++)
          {
            // Append the word info into string info
            if (fl_shaper_segment_cpy_dst_index < GFX_MGR02_MAX_TEXT_LENGTH)
            {
              l_hb_shape_info.x_offset[fl_shaper_segment_cpy_dst_index] = (fl_segment_shaper_ptr->gpos_info[fl_segment_char_index].x_offset/64);
              l_hb_shape_info.y_offset[fl_shaper_segment_cpy_dst_index] = (fl_segment_shaper_ptr->gpos_info[fl_segment_char_index].y_offset/64);
              l_hb_shape_info.x_advance[fl_shaper_segment_cpy_dst_index] = (fl_segment_shaper_ptr->gpos_info[fl_segment_char_index].x_advance/64);
              l_hb_shape_info.content_type[fl_shaper_segment_cpy_dst_index] = fl_segment_shaper_ptr->content_type;
              l_hb_shape_info.code_point[fl_shaper_segment_cpy_dst_index] = fl_segment_shaper_ptr->glyph_info[fl_segment_char_index].codepoint;
              l_hb_shape_info.glyph_count++;
              fl_shaper_segment_cpy_dst_index++;
            }
          }
        }
        free(fl_segment_txt);
        l_last_string_dir = fl_RTL;
      }
    }
  }
  if (l_ubidi != GFX_MGR02_NULL_PTR)
  {
    hmi_gfx_mgr02_close_ubidi();
  }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_process_ubidi
Description          : Shape the passed input string
Invocation           : Global
Parameters           : p_string - input string
                       p_strlen - input string length
                       p_lang_dir_RTL - is string a RTL
                       p_font_id - font id
                       p_out_shaped_str  - out string with processed input unicode sequence - can be null
Return Value         : GFX_MGR02_HB_SHAPE_INFO - structure with all processed details of input string
Critical Section     : None
External Interfaces  : None
******************************************************************************/
GFX_MGR02_HB_SHAPE_INFO* hmi_gfx_mgr02_process_ubidi(HMI_CHAR const* p_string, UINT32 p_strlen, UINT8 p_lang_dir_RTL, UINT32 p_font_id, HMI_CHAR* p_out_shaped_str
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
  , UINT32 p_pre_render_index
#endif
)
{
  GFX_MGR02_HB_SHAPE_INFO* fl_shaper_ptr = GFX_MGR02_NULL_PTR;
  hmi_gfx_mgr02_reset_hb_shape_info(); //clear the buffer before start processing
  if (p_string != 0U)
  {
#if defined(GFX_MGR02_TRAVEO2) && defined (HMI_LANG_PRE_RENDER)
    if (p_pre_render_index < (HMI_PRE_RENDER_SIDS_COUNT - 1))
    {
      UINT32 fl_font_id    = hmi_gfx_mgr02_get_font_id(p_font_id);
      GFX_MGR02_FONT const* fl_font_SP = hmi_gfx_mgr02_get_font_pointer(fl_font_id);
      if (fl_font_SP != NULL)
      {
        HMI_PRE_RENDER_GPOS_INFO const* fl_gpos_data = NULL;
        for (UINT8 fl_index = 0U; fl_index < HMI_PRE_RENDER_FONT_SIZE_COUNT; fl_index++)
        {
          if (lc_gpos_size_map[fl_index].fontSize == fl_font_SP->height_pts)
          {
            fl_gpos_data = lc_gpos_size_map[fl_index].gpos;
            break;
          }
        }
        if (fl_gpos_data != NULL)
        {
          UINT32 fl_startIndex = lc_pre_render_glyph_index[p_pre_render_index];
          UINT32 fl_endIndex   = lc_pre_render_glyph_index[p_pre_render_index + 1];
          UINT32 glyph_count   = (fl_endIndex - fl_startIndex);
          for (UINT8 fl_index = 0U; fl_index < glyph_count; fl_index++)
          {
            if (fl_startIndex < HMI_PRE_RENDER_BUFFER_SIZE)
            {
              l_hb_shape_info.code_point[fl_index]   = lc_pre_render_buffer[fl_startIndex];
              l_hb_shape_info.content_type[fl_index] = HB_BUFFER_CONTENT_TYPE_GLYPHS;
              l_hb_shape_info.x_offset[fl_index]     = fl_gpos_data[fl_startIndex].xOffset;
              l_hb_shape_info.y_offset[fl_index]     = fl_gpos_data[fl_startIndex].yOffset;
              l_hb_shape_info.x_advance[fl_index]     = fl_gpos_data[fl_startIndex].xAdvance;
              l_hb_shape_info.glyph_count++;
              fl_startIndex++;
            }
          }
        }
      }
    }
    if(l_hb_shape_info.glyph_count == 0U)//Data not taken from pre-render
#endif
    {
      char fl_linebreak[GFX_MGR02_MAX_TEXT_LENGTH] = { 0 };
      UINT32 fl_linebreak_length = 0;
      UINT8 fl_prev_start_index = 0;
      UINT8 fl_lb_segment_length = 0;
      HMI_CHAR* fl_lb_cur_string = GFX_MGR02_NULL_PTR;
      BOOLEAN fl_LTR = FALSE;
      set_linebreaks_utf16(p_string, p_strlen + 1U, GFX_MGR02_NULL_PTR, fl_linebreak);
#if defined(GFX_MGR02_REGIONAL_LANG_SUPPORT_NEEDED)
      if (hmi_gfx_mgr02_get_regional_char_count(p_string, (UINT16)p_strlen) != 0U)
      {
        fl_LTR = TRUE;
      }
#endif
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
      if (hmi_gfx_mgr02_get_thai_char_count(p_string, (UINT16)p_strlen) != 0U)
      {
        fl_LTR = TRUE;
      }
#endif
#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
      if (hmi_gfx_mgr02_get_devanagari_char_count(p_string, (UINT16)p_strlen) != 0U)
      {
        fl_LTR = TRUE;
      }
#endif

      if (fl_LTR == TRUE)
      {
        UINT8 i = 0;
        while (fl_linebreak[i] != 0)
        {
          i++;
        }
        if (i < (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
        {
          fl_linebreak_length = i;
        }
        else
        {
          fl_linebreak_length = (UINT32)GFX_MGR02_MAX_TEXT_LENGTH;
        }
        for (i = 0; i <= fl_linebreak_length; i++)
        {
          if (i < (UINT32)GFX_MGR02_MAX_TEXT_LENGTH)
          {
            if ((fl_linebreak[i] == LINEBREAK_NOBREAK) || ((fl_linebreak[i] == LINEBREAK_ALLOWBREAK) && (i == 0)) || ((fl_linebreak[i] == LINEBREAK_MUSTBREAK) && (i == 0)))
            {
              continue;
            }
            else if ((i > 0U) && ((fl_linebreak[i] == LINEBREAK_ALLOWBREAK) || (fl_linebreak[i] == LINEBREAK_MUSTBREAK)))
            {
              fl_lb_segment_length = i - fl_prev_start_index;
              fl_lb_cur_string = (HMI_CHAR*)malloc(sizeof(HMI_CHAR) * (fl_lb_segment_length + 1U));
              if (fl_lb_cur_string != GFX_MGR02_NULL_PTR)
              {
                (void)HMI_STRNCPY(fl_lb_cur_string, p_string + fl_prev_start_index, fl_lb_segment_length);
                fl_lb_cur_string[fl_lb_segment_length] = 0;
                fl_lb_segment_length = i - fl_prev_start_index;
                bidi_process_sub_string(fl_lb_cur_string, fl_lb_segment_length, p_lang_dir_RTL, p_font_id, FALSE);
                fl_prev_start_index = i;

                if (i < p_strlen)
                {
                  fl_lb_cur_string[0] = p_string[i];
                  fl_lb_cur_string[1] = 0;
                  bidi_process_sub_string(fl_lb_cur_string, 1U, p_lang_dir_RTL, p_font_id, TRUE);
                  i++;
                  fl_prev_start_index = i;
                }
                free(fl_lb_cur_string);
              }
            }
            else
            {
              break;
            }
          }
        }
      }
      else
      {
        bidi_process_sub_string(p_string, p_strlen, p_lang_dir_RTL, p_font_id, FALSE); //Pass entire input string as single string without line break algorithm
      }
    }

    //Fill the out string, if it is valid pointer. out string should be allocated with enough memory to hold the processed char sequences
    //It is caller's resposibility to allocate and free this memory
    if (p_out_shaped_str != 0U)
    {
      UINT16 fl_glyph_index = 0U;
      for (fl_glyph_index = 0; fl_glyph_index < l_hb_shape_info.glyph_count; fl_glyph_index++)
      { 
        if(l_hb_shape_info.code_point[fl_glyph_index] != 0U)
        {
          p_out_shaped_str[fl_glyph_index] = l_hb_shape_info.code_point[fl_glyph_index];
        }
        else
        {
          l_hb_shape_info.content_type[fl_glyph_index] = HB_BUFFER_CONTENT_TYPE_UNICODE;
          l_hb_shape_info.unicode[fl_glyph_index] = p_string[fl_glyph_index];
          p_out_shaped_str[fl_glyph_index] =  p_string[fl_glyph_index];
        }
      }
      p_out_shaped_str[fl_glyph_index] = 0U;
    }

    if (l_hb_shape_info.glyph_count > 0U)
    {
      fl_shaper_ptr = &l_hb_shape_info;
    }
  }
  return fl_shaper_ptr;
}


BOOLEAN hmi_gfx_mgr02_init_ubidi(HMI_CHAR const * p_string, UINT32 p_strlen, UINT8 p_lang_dir_RTL) 
{
  UINT8 fl_return = FALSE;
  hmi_gfx_mgr02_reset_ubidi_data();
  if (p_lang_dir_RTL == (UINT8)TRUE)
  {
    /*This direction check is required to match with RenderCore logic.
    * Few Arabic+English strings has LTR as base direction
    */
    l_ubidi_text_direction =  ubidi_getBaseDirection(p_string, p_strlen); 
    #ifdef GFX02_DEBUG_INFO
    if (l_ubidi_text_direction != UBIDI_RTL)
    {
      printf("Text direction is not RTL");
    }
    #endif
  }
  else
  {
    l_ubidi_text_direction = UBIDI_LTR;
  }

  if(l_ubidi == GFX_MGR02_NULL_PTR)
  {
    l_ubidi = ubidi_open();
  }
  
  if(l_ubidi != GFX_MGR02_NULL_PTR)
  {
    l_ubidi_text = p_string;
    l_ubidi_reordered_text = (HMI_CHAR *)malloc(sizeof(HMI_CHAR) * (p_strlen+1U));
    if((l_ubidi_text != GFX_MGR02_NULL_PTR) && (l_ubidi_reordered_text != GFX_MGR02_NULL_PTR))
    {
      (void)HMI_STRNCPY(l_ubidi_reordered_text,p_string,p_strlen);
      l_ubidi_reordered_text[p_strlen] = 0U;
      l_ubidi_text_length = p_strlen;
      fl_return = TRUE;
    }
  }
  return fl_return;
} 
void hmi_gfx_mgr02_close_ubidi(void)
{ 
  ubidi_close(l_ubidi);
  if (l_ubidi_reordered_text != GFX_MGR02_NULL_PTR)
  {
    free(l_ubidi_reordered_text);
    l_ubidi_reordered_text = GFX_MGR02_NULL_PTR;
  }
  hmi_gfx_mgr02_reset_ubidi_data();
}

UINT8 hmi_gfx_mgr02_get_ubidi_segment_count(void)
{
  UINT8 fl_count = 0U;
  UErrorCode fl_bidi_err = U_ZERO_ERROR;
  l_ubidi_processed_length = 0U;
  int32_t fl_outstrlen = 0U;
  #ifdef GFX02_DEBUG_INFO
  HMI_CHAR fl_reordered_text2[256];
  #endif
  if(l_ubidi != GFX_MGR02_NULL_PTR)
  {
    ubidi_setReorderingMode(l_ubidi, UBIDI_REORDER_DEFAULT); 
    ubidi_setPara(l_ubidi, l_ubidi_text, l_ubidi_text_length, l_ubidi_text_direction, NULL, &fl_bidi_err);
    if(U_SUCCESS(fl_bidi_err) != 0U)
    {
      l_ubidi_processed_length = ubidi_getProcessedLength(l_ubidi);
      if((l_ubidi_reordered_text != GFX_MGR02_NULL_PTR) && (l_ubidi_processed_length > 0U))
      {
        UINT16 fl_option = 0U;
#if 0
        if(l_ubidi_text_direction == GFX_MGR02_UBIDI_TXT_DIR_RTL)
        {
          fl_option = 0U;
        }
        else
        {
          //Apply mirroring for RTL runs.
          fl_option = (UINT16)UBIDI_DO_MIRRORING;
        }
#endif
        #ifdef GFX02_DEBUG_INFO
        wcscpy(fl_reordered_text2, l_ubidi_reordered_text);
        #endif
        fl_outstrlen = ubidi_writeReordered(l_ubidi, l_ubidi_reordered_text, l_ubidi_processed_length, fl_option, &fl_bidi_err);
        #ifdef GFX02_DEBUG_INFO
        if(wcscmp(fl_reordered_text2, l_ubidi_reordered_text) != 0U)
        {
          printf("String updated");
        }
        #endif

        if(fl_bidi_err == U_STRING_NOT_TERMINATED_WARNING)
        {
          // its OK as we dont need null termination..
          fl_bidi_err = U_ZERO_ERROR;
        }
        if (fl_outstrlen > l_ubidi_processed_length)
        {
          //Not an expected condition
        }
        else if (fl_outstrlen < l_ubidi_processed_length)
        {
          l_ubidi_processed_length = fl_outstrlen;
        }
        else
        {
          //nothingtodo, if same
        }
        
        if (U_SUCCESS(fl_bidi_err) != 0U)
        {
          if (l_ubidi_processed_length > 0U)
          {
            fl_count = ubidi_countRuns(l_ubidi, &fl_bidi_err);
            if (U_FAILURE(fl_bidi_err) != 0U)
            {
              fl_count = 0U;
            }
            else if (fl_outstrlen < 0U)
            {
              //invalid string length
            }
            else
            {
              //empty string..
            }
          }
        }
      }
    }
  }
  return(fl_count);
}

UINT8 hmi_gfx_mgr02_get_ubidi_last_segment_RTL_status(void)
{
  UINT8 fl_return = 0U;
  if(l_ubidi_text_direction == UBIDI_RTL)
  {
    fl_return = 1U;
  }
  return fl_return;
}

HMI_CHAR * hmi_gfx_mgr02_get_ubidi_next_segment(void)
{
  UBiDiLevel fl_bidi_level;
  int32_t fl_string_length = 0U;
  int32_t fl_logical_start = 0U;
  HMI_CHAR * fl_segment_string = GFX_MGR02_NULL_PTR;
  fl_bidi_level = ubidi_getVisualRun(l_ubidi, l_ubidi_segment_index, &fl_logical_start, &fl_string_length);
  if (fl_string_length > 0U)
  {
    UINT32 fl_length = (fl_string_length + l_ubidi_start_offset);
    if ((fl_length > 0U) && (fl_length <= l_ubidi_text_length))
    {
      UINT16 fl_index=0;
      HMI_CHAR * fl_visual_string = GFX_MGR02_NULL_PTR;
      if ((fl_bidi_level & 1U) == 0U)
      {
        l_ubidi_text_direction = UBIDI_LTR;
      }
      else
      {
        l_ubidi_text_direction = UBIDI_RTL;
      }
      fl_visual_string = &l_ubidi_reordered_text[l_ubidi_start_offset];
      l_ubidi_start_offset += fl_string_length;
      fl_segment_string = (HMI_CHAR *)malloc(sizeof(HMI_CHAR) * (fl_string_length+1));
      if(fl_segment_string != NULL)
      {
        for(fl_index=0;fl_index <fl_string_length;fl_index++)
        {
          fl_segment_string[fl_index] = fl_visual_string[fl_index];
        }
        fl_segment_string[fl_index] = 0U;
      }
    }
    else
    {
        //String buffer overflow
    }
  }
  l_ubidi_segment_index++;
  return fl_segment_string;
}

#endif /* #if (((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) &&
	       (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ)) */

#ifdef  __cplusplus
}
#endif

    #endif	/* #if (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_WORLDTYPE) || (GFX_MGR02_SHAPE_ENGINE == GFX_MGR02_HARFBUZZ) */
  #endif  /* #if ((GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_MONOTYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)||(GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_SPANSION_FT2)) */
#endif	/* #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE	*/

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
** CMS Rev 1.1      19-Dec-2017     sbollam
** Added Harfbuzz shape engine support.
** Ref Task : 978896
** WTLE Shape engine support for MMC 978896
** CMS Rev 1.0      20-Nov-2017     sbollam
** Creation.
** WTLE Shape engine support for MMC 978896
**==========================================================================*/
/* end of file =============================================================*/
