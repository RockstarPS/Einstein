#include "system.h"
#include "hmi_gfx_mgr02_layout.h"

 #pragma ghs section rodata=".prerender1"
 #include "hmi_language_identifiers.h"
#include "hmi_lang_pre_render.h"
//#include "hmi_lang_pre_render_buffer.inc"
 //#include "gpos_data_20.inc"
 #include "hmi_language_identifiers.h"
 #include "hmi_sid_mapping.inc"

#pragma ghs section rodata=default

HMI_FONT_GPOS_MAP const lc_gpos_size_map[HMI_PRE_RENDER_FONT_SIZE_COUNT] = {
    {20, lc_pre_render_gpos_20}
  
  };

UINT32 const lc_pre_render_glyph_index[7] = {
    0,
    10,
    20,
    30,
    40,
    50,
    60
};
HMI_CHAR const lc_pre_render_buffer[60]={
0x00E3, 0x00F9, 0x0128, 0x00ED, 0x0177, 0x0133, 0x010A, 0x00ED, 0x0104, 0x013D, 0x012D, 
/* tamil, sid_0625*/
0x010A, 0x00ED, 0x0104, 0x013D, 0x014D, 0x0129, 0x00DA, 0x00FF, 0x00FE, 0x0105, 0x00ED, 0x0104, 0x012D, 0x014F, 0x00F4, 0x0137, 
/* tamil, sid_0631_1*/
0x00E0, 0x010A, 0x00F7, 0x0128, 0x00F2, 0x00FA, 0x0105, 0x00DA, 0x00F5, 0x0181, 0x010B, 0x00FC, 0x018E, 
/* tamil, sid_0631_2*/
0x0160, 0x012D, 0x00F2, 0x010B, 0x00F8, 0x0128, 0x00ED, 0x00FF, 0x0104, 0x01A1, 
/* tamil, sid_0632_1*/
0x00E1, 0x010B, 0x00F8, 0x0132, 0x015E, 0x00ED, 0x0138, 
/* tamil, sid_0632_2*/
0x0160, 0x012D, 0x00F2
};

extern HMI_PRE_RENDER_GPOS_INFO const lc_pre_render_gpos_20[60] = {


{0,0,23}, {0,0,13}, {0,0,17}, {0,0,12}, 
/* tamil, sid_0723*/
{0,0,14}, {0,0,12}, {0,0,6}, {0,0,12}, {0,0,11}, {0,0,5}, {0,0,18}, {0,0,15}, {0,0,14}, {0,0,11}, 
/* tamil, sid_0729*/
{0,0,16}, {0,0,23}, {0,0,13}, {0,0,14}, {0,0,5}, {0,0,5}, {0,0,15}, {0,0,5}, {0,0,14}, {0,0,11}, {0,0,16}, 
/* tamil, sid_0730*/
{0,0,22}, {0,0,13}, {0,0,16}, {0,0,16}, {0,0,15}, {0,0,15}, {0,0,13}, {0,0,13}, {0,0,21}, 
/* tamil, sid_0733_1*/
{0,0,17}, {0,0,17}, {0,0,22}, {0,0,15}, {0,0,15}, {0,0,17}, {0,0,16}, {0,0,16}, {0,0,5}, {0,0,24}, 
/* tamil, sid_0733_2*/
{0,0,19}, {0,0,21}, {0,0,5}, {0,0,5}, {0,0,15}, {0,0,5}, {0,0,17}, {0,0,17}, 
/* tamil, sid_0734*/
{0,0,17}, {0,0,17}, {0,0,22}, {0,0,15}, {0,0,15}, {0,0,17}, {0,0,16}, {0,0,16}
};