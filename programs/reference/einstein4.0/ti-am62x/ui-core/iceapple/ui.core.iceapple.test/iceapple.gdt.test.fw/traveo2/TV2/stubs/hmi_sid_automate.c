/*============================================================================
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
 ** Name:          hmi_sid_automate.c
 **
 ** Description:   Implements the default init and schedular functionality
 **                for the simulation. Also  implements the default button
 **                handler
 **
 ** Organization:  GUI Software Sectioni
 **
 **============================================================================
 **
 **==========================================================================*/


 /*============================================================================
  ** I N C L U D E   F I L E S
  **==========================================================================*/

#ifdef TEXT_AUTOMATION
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_cfg.h"
#include "hmi_sid_automate.h"

extern void ChangeSID();
extern int IsLastSID();
extern const char* GetFolderName();
extern void ChangeLanguage();

int sidIndex = 0;
int langIndex = -1;
//#define ENABLE_LOG
void ChangeSID()
{
#ifdef ENABLE_LOG
  FILE* fptr;
  fptr = fopen("TestingSIDSLog.txt", "ab+");
  if (fptr == NULL)
  {
    printf("Error!");
    exit(1);
  }
#endif
  if (langIndex < NUM_LANGUAGES && langIndex != -1)
  {
    if (sidIndex < NUM_SIDS)
    {
      (void)hmi_language_if_set_current_language(language_array[langIndex]);
      (void)hmi_gfx_mgr02_if_set_sid(GFX_TXT_SID_TEST, sid_array[sidIndex]);
      (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_NAME, sid_names[sidIndex]);
     // (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_NAME, L"xcccccccccc");
#ifdef ENABLE_LOG
      GFX_MGR02_TEXT_WIDTH_INFO p_text_info;
      HMI_CHAR fl_text_A[GFX_MGR02_MAX_TEXT_LENGTH + 1];
      HMI_CHAR* fl_string_ptr;

      p_text_info.num_chars_to_process = GFX_MGR02_MAX_TEXT_LENGTH;
      p_text_info.ifont_id = 0;
      fl_text_A[0] = 0;
      hmi_language_if_get_string_ptr(sids_test[sidIndex], &fl_text_A[0], GFX_MGR02_MAX_TEXT_LENGTH);
      fl_string_ptr = &fl_text_A[0];
      p_text_info.iostring = fl_string_ptr;
      (void)hmi_gfx_mgr02_if_get_text_width(GFX_TXT_TOYOTA, &p_text_info);
      fprintf(fptr, "%s", "\n Printing width of ");
      fprintf(fptr, "%d", sidIndex);
      fprintf(fptr, "%s", "    :  ");
      fprintf(fptr, "%d", p_text_info.owidth);
#endif
      sidIndex++;
    }
    if (sidIndex == NUM_SIDS - 1)
    {
#ifdef ENABLE_LOG
      fprintf(fptr, "%s", "\n=========================================================\n");
#endif
    }
  }
}
void ChangeLanguage()
{
  sidIndex = 0;
  langIndex++;
  (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_NAME, L"");
  if (langIndex < NUM_LANGUAGES)
  {
    (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_TEST, L"Changing the language");
    (void)hmi_language_if_set_current_language(language_array[langIndex]);
  }
  else
  {
    (void)hmi_gfx_mgr02_if_set_text(GFX_TXT_SID_TEST, L"SID Automation completed");
  }
}

int IsLastSID()
{
  return (sidIndex == NUM_SIDS - 1) ? TRUE : FALSE;
}

int GetSIDIndex()
{
  return sidIndex;
}
const char* GetFolderName()
{
  char* folderName = "default";
  if (langIndex < NUM_LANGUAGES)
  {
    folderName = language_names[langIndex];
  }
  return folderName;
}

#endif


