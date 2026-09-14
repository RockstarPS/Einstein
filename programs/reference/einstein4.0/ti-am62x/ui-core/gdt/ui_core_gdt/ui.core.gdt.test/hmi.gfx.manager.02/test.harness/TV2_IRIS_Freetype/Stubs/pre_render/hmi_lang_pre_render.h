#ifndef HMI_LANG_PRE_RENDER_H
#define HMI_LANG_PRE_RENDER_H
#include "hmi_language_identifiers.h"
#include "hmi_lang_pre_render_cfg.h"


typedef struct
{
  LANG_SID_T sid;
  UINT32 index;
}HMI_SID_MAPPING;

extern HMI_SID_MAPPING const lc_sid_map[HMI_PRE_RENDER_SIDS];
#endif
