/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_language_interface.h
**
** Description:
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#ifndef HMI_LANGUAGE_INTERFACE_H
#define HMI_LANGUAGE_INTERFACE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "system.h"
#include "string.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

#ifdef LNG_UNICODE
  #define HMI_LNG_CMD_LENGTH_MASK             (0x1F)
  #define HMI_LNG_CMD_CPAGE_MASK              (0x60)
  #define HMI_LNG_CMD_EXT_ESID_BIT            (0x20)
  #define HMI_LNG_CMD_LINK_BIT                (0x80)
  #define HMI_LNG_CMD_GET_CPAGE(cmd)          ((cmd & HMI_LNG_CMD_CPAGE_MASK)  >> 5)
#else
  #define HMI_LNG_CMD_LENGTH_MASK             (0x3F)
  #define HMI_LNG_CMD_LINK_BIT                (0x80)
  #define HMI_LNG_CMD_EXT_ESID_BIT            (0x40)
#endif

#if HM_LANG_MAX_PAGE > 1
  #define HMI_LNG_SID_INDEX_MASK              (0x3FFF)
  #define HMI_LNG_SID_PAGE_MASK               (0xC000)
#endif

#if defined(WIN32) || defined(MATLAB_MEX_FILE)
     #define snprintf              _snprintf
#endif

#ifdef LNG_UNICODE
   #define HMI_STRCMP           wcscmp
   #define HMI_STRCPY           wcscpy
   #define HMI_STRCAT           wcscat
   #define HMI_STRNCAT          wcsncat
   #define HMI_STRNCMP          wcsncmp
   #define HMI_STRNCPY          wcsncpy
   #define HMI_STRLEN           wcslen
   #define HMI_STRTOD           wcstod
   #define HMI_STRTOL           wcstol
   #define HMI_SSCANF           swscanf
   #define HMI_TOUPPER          towupper
   #define HMI_TOLOWER          towlower
   #define HMI_ISUPPER          iswupper
   #define HMI_ISLOWER          iswlower
 #if defined(WIN32) || defined(MATLAB_MEX_FILE)
   #define HMI_SPRINTF          swprintf
   #define HMI_SNPRINTF         _snwprintf
 #else
   #define HMI_SPRINTF          swprintf
   #define HMI_SNPRINTF         swprintf
 #endif
   #define HMI_ISSPACE          iswspace
   #define HMI_ISPRINT          iswprint
   #define HMI_ISASCII          iswascii
   #define HMI_STRTOK           wcstok
   #define HMI_STRCHR           wcschr
   #define HMI_CHARMASK         (0xffff)
 #ifdef MATLAB_MEX_FILE
   #define HMI_WCTOB(value)     (value)
 #else
   #define HMI_WCTOB(value)     wctob(value)
 #endif
   #define HMI_TEXT(x)          (L(x))
   #define HMI_TEXT_CHAR(x)     ((wchar_t)(x))
   #define HMI_LANG_MAX_L_TEXT_LENGTH   (20)
#else
   #define HMI_STRCMP           strcmp
   #define HMI_STRCPY           strcpy
   #define HMI_STRCAT           strcat
   #define HMI_STRNCAT          strncat
   #define HMI_STRNCMP          strncmp
   #define HMI_STRNCPY          strncpy
   #define HMI_STRLEN           strlen
   #define HMI_STRTOD           strtod
   #define HMI_STRTOL           strtol
   #define HMI_SSCANF           sscanf
   #define HMI_SPRINTF          sprintf
 #if defined(WIN32) || defined(MATLAB_MEX_FILE)
   #define HMI_SNPRINTF         _snprintf
 #else
   #define HMI_SNPRINTF         snprintf
 #endif
   #define HMI_ISSPACE          isspace
   #define HMI_ISPRINT          isprint
   #define HMI_ISASCII          isascii
   #define HMI_STRTOK           strtok
   #define HMI_STRCHR           strchr
   #define HMI_CHARMASK         (0xff)
   #define HMI_TOUPPER          toupper
   #define HMI_TOLOWER          tolower
   #define HMI_ISUPPER          isupper
   #define HMI_ISLOWER          islower
   #define HMI_WCTOB(value)     (value)
   #define HMI_TEXT(x)          (x)
   #define HMI_TEXT_CHAR(x)     (x)
#endif

#define HMI_CHAR_PTR(x)         ((HMI_CHAR *)(x))

#ifdef LNG_UNICODE
     #define _HMI_CHAR_
     typedef wchar_t HMI_CHAR;
#else
     typedef char HMI_CHAR;
#endif

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

#ifdef HM_LANG_USE_INERNAL_STRING_BUFFER
HMI_CHAR * hmi_language_if_get_string_ptr(LANG_SID_T p_sid);
#else
void hmi_language_if_get_string_ptr(int p_sid, HMI_CHAR * p_string_buff_P, UINT8 p_req_length);
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
**
** Rev 1.1          03-Sep-2010 by EMANOJ1
** Updated interface to support application passing the buffer pointer rather
** language core having an internal buffer. The selection can be done in the
** tool itself. QAC 4.5.3 fixes
**
** Rev 1.0          16-Aug-2010 by EMANOJ1
** Initial revision.
**
**==========================================================================*/

/* end of file =============================================================*/
#endif

