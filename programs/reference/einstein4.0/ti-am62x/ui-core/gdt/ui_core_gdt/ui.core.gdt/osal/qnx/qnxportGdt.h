/*=============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2019. Visteon Corporation owns all rights to this work and
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
 ** Name:           qnxportGdt.h
 **
 ** Description:    This module is created to use GDT using OpenGL in QNX.
 **                 It actually makes use of Screen library in QNX for creating 
 **                 the window and passing that to the OpenGL.
 **
 ** Organization:   UE COC, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#ifdef QNXPORTGDT_C
	#define EXTERN
#else
	#define EXTERN extern
#endif
#ifdef  __cplusplus
extern "C" {
#endif

EXTERN void cleanup(void);
EXTERN int is_screenlib_initialized(void);
EXTERN void handle_screen_event(void);
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
 ** CMS Rev 1.0      Initial version
 ** Creation.
 ** 
 **==========================================================================*/

#ifdef  __cplusplus
}
#endif

