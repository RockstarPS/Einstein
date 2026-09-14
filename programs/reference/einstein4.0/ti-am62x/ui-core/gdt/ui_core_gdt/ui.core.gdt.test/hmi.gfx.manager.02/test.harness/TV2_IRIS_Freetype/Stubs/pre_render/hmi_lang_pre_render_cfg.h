#ifndef HMI_LANG_PRE_RENDER_CFG_H
#define HMI_LANG_PRE_RENDER_CFG_H
typedef struct
{
  SINT8 xOffset;
  SINT8 yOffset;
  SINT8 xAdvance;
}HMI_PRE_RENDER_GPOS_INFO;

typedef struct
{
  UINT8 fontSize;
  const HMI_PRE_RENDER_GPOS_INFO *gpos;
}HMI_FONT_GPOS_MAP;

/* Language ID Macros */
#define ARABIC                                  0U
#define HEBREW                                  1U
#define HINDI                                   2U
#define BENGALI                                 3U
#define MARATHI                                 4U
#define TELUGU                                  5U
#define TAMIL                                   6U
#define GUJARATI                                7U
#define KANNADA                                 8U
#define ODIA                                    9U
#define MALAYALAM                               10U
#define PUNJABI                                 11U

#define HMI_NUM_LANGUAGES                         41
#define HMI_PRE_RENDERED_LANG_COUNT               12
#define HMI_PRE_RENDER_SIDS                       5875
#define HMI_PRE_RENDER_BUFFER_SIZE                571078
#define HMI_PRE_RENDER_FONT_SIZE_COUNT            1
#define HMI_PRE_RENDER_SIDS_COUNT                 70500


extern HMI_PRE_RENDER_GPOS_INFO const lc_pre_render_gpos_20[60];

extern UINT8 const lc_prerender_lang_index[HMI_NUM_LANGUAGES];
extern HMI_CHAR const lc_pre_render_buffer[60];
extern HMI_FONT_GPOS_MAP const lc_gpos_size_map[HMI_PRE_RENDER_FONT_SIZE_COUNT];
extern UINT32 const lc_pre_render_glyph_index[7];
#endif
