/******************************************************************************
*                              Copyright Statement
*                        CONFIDENTIAL VISTEON CORPORATION
*
*  This is an unpublished work of authorship, which contains trade secrets,
*  created in 2016. Visteon Corporation owns all rights to this work and
*  intends to maintain it in confidence to preserve its trade secret status.
*  Visteon Corporation reserves the right, under the copyright laws of the
*  United States or those of any other country that may have  jurisdiction,
*  to protect this work as an unpublished work, in the event of an inadvertent
*  or deliberate unauthorized publication. Visteon Corporation also reserves
*  its rights under all copyright laws to protect this work as a published
*  work, when appropriate. Those having access to this work may not copy it,
*  use it, modify it or disclose the information contained in it without the
*  written authorization of Visteon Corporation.
*
*******************************************************************************
*
*  Module:      hmi_gfx_mgr02_fault.h
*  Description: Fault logging        
*  Author:             
*  Date:               
*
*******************************************************************************/

#ifndef HMI_GFX_MGR02_FAULT_H
#define HMI_GFX_MGR02_FAULT_H

/******************************************************************************
* Include files
******************************************************************************/
#include "VG/openvg.h"
#include "VG/vgu.h"

#if defined(GFX_OVG_FAULT_HANDLE)
#include "hmi_gfx_mgr02_ovgapp_fm_cfg.h"
#endif

/******************************************************************************
* Data types - Macros and typedefs
******************************************************************************/

#if defined(GFX_OVG_FAULT_HANDLE)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/

/******************************************************************************
* Data types - Macros and typedefs
******************************************************************************/
#define GETVALUE(x,y) (x##y)

#define GFX_MGR02_VG_NO_ERROR                                     (0U)

/* Start of init errors */
/* Context Initialization related errors treated as critical errors */
#define GFX_MGR02_GPU_INIT_FAULT                                  (GFX_BIT0)
#define GFX_MGR02_EGLBINDAPI_FAULT                                (GFX_BIT1)
#define GFX_MGR02_EGLINITIALIZE_FAULT                             (GFX_BIT2)
#define GFX_MGR02_EGLCHOOSECONFIG_FAULT                           (GFX_BIT3)
#define GFX_MGR02_CREATE_PBUFFERSURFACE_FAULT                     (GFX_BIT4)
#define GFX_MGR02_CREATENATIVEPIXMAP_FAULT                        (GFX_BIT5)
#define GFX_MGR02_CREATENATIVEWINDOW_FAULT                        (GFX_BIT6)
#define GFX_MGR02_EGLCREATEWINDOWSURFACE_FAULT                    (GFX_BIT7)
#define GFX_MGR02_EGLCREATECONTEXT_FAULT                          (GFX_BIT8)
#define GFX_MGR02_EGLMAKECURRENT_FAULT                            (GFX_BIT9)
/* Out of memory also should treat as critical errors */
#define GFX_MGR02_VG_OUT_OF_MEMORY_FAULT                          (GFX_BIT10)
/* End of the init errors */

/* Run related errors */
#define GFX_MGR02_VG_HANDLE_FAULT                                 (GFX_BIT11)
#define GFX_MGR02_VG_ILLEGAL_ARGUMENT_FAULT                       (GFX_BIT12)
#define GFX_MGR02_VG_PATH_CAPABILITY_FAULT                        (GFX_BIT13)
#define GFX_MGR02_VG_UNSUP_IMAGE_FAULT                            (GFX_BIT14)
#define GFX_MGR02_VG_UNSUP_PATH_FMT_FAULT                         (GFX_BIT15)
#define GFX_MGR02_VG_IMAGE_IN_USE_FAULT                           (GFX_BIT16)
#define GFX_MGR02_VG_NO_CONTEXT_FAULT                             (GFX_BIT17)

#define GFX_MGR02_EGLDESTROYCONTEXT_FAULT                         (GFX_BIT18)
#define GFX_MGR02_EGLDESTROYSURFACE_FAULT      					  (GFX_BIT19)
#define GFX_MGR02_EGLTERMINATE_FAULT           					  (GFX_BIT20)
#define GFX_MGR02_EGLGETDISPLAY_FAULT          					  (GFX_BIT21)
#define GFX_MGR02_MEMORY_ALLOC_FAULT           					  (GFX_BIT22)
#define GFX_MGR02_GPU_FINI_FAULT                                  (GFX_BIT23)
#define GFX_MGR02_EGLGETCONFIGATTRIB_FAULT                        (GFX_BIT24)

#ifdef GFX_MGR02_RENESAS_OPENVG_LIB	 

#define GFX_MGR02_EGLSTARTUP_FAULT                                (GFX_BIT25)
#define GFX_MGR02_NCGSYS_FRAMEMEMCREATE_FAULT                     (GFX_BIT26)
#define GFX_MGR02_VGSTARTUP_FAULT                                 (GFX_BIT27)
#define GFX_DESTROYNATIVEWINDOW_FAULT                             (GFX_BIT28)
#define GFX_DESTROYNATIVEPIXMAP_FAULT                             (GFX_BIT29)
#define GFX_MGR02_NUM_FAULTS                                      (30U)

#else
#define GFX_MGR02_NUM_FAULTS                                      (25U)
#endif

#if defined(GFX_OVG_LOG_PRINT_AVAILABLE)
void log_print(UINT32 rc, char const *function, char const*file, UINT32 line);
#define GFX_MGR02_OVG_PRINT_ERROR(rc)    log_print(rc, __FUNCTION__, __FILE__, __LINE__)
#else
#define GFX_MGR02_OVG_PRINT_ERROR(rc)
#endif

#define GFX_MGR02_OVG_LOG_ERROR(rc, error)  (rc) = error; hmi_gfx_mgr02_fault_set(error);GFX_MGR02_OVG_PRINT_ERROR(error);
#define GFX_MGR02_LOG_ERROR(error)  hmi_gfx_mgr02_fault_set(error);GFX_MGR02_OVG_PRINT_ERROR(error);

#define GFX_MGR02_OVG_GET_ACTUAL_ERROR(rc, vg_error)     ((rc) = hmi_gfx_mgr02_get_actual_error(rc,vg_error))

#define GFX_OVG_UTIL_SUCCESS(rc, api, execute)                         		         \
do{                                                                                  \
	if((rc) == GFX_MGR02_VG_NO_ERROR)                                                \
	{                                                                                \
	  (execute);                                                                     \
      if((GETVALUE(api,_ERROR_MASK) & GFX_CFG_MONITOR_CRITICAL_ERROR_MASK) != 0x0U)  \
	  {                                                                              \
		VGErrorCode error;                                                           \
		error = vgGetError();                                                        \
		(rc) = hmi_gfx_mgr02_fault_convert_error_code(error);                        \
		hmi_gfx_mgr02_fault_set(rc);                                                 \
		GFX_MGR02_OVG_PRINT_ERROR(rc);                                               \
	  }                                                                              \
	}                                                                                \
}while(0)

#define GFX_OVG_UTIL_VG_DESTROY(rc, api, execute)                         		     \
do{                                                                                  \
	  (execute);                                                                     \
      if((GETVALUE(api,_ERROR_MASK) & GFX_CFG_MONITOR_CRITICAL_ERROR_MASK) != 0x0U)  \
	  {                                                                              \
		VGErrorCode error;                                                           \
		error = vgGetError();                                                        \
		(rc) = hmi_gfx_mgr02_fault_convert_error_code(error);                        \
		hmi_gfx_mgr02_fault_set(rc);                                                 \
		GFX_MGR02_OVG_PRINT_ERROR(rc);                                               \
	  }                                                                              \
}while(0)

/******************************************************************************
* Data types - enums
******************************************************************************/
/******************************************************************************
* function prototypes
******************************************************************************/

extern void hmi_gfx_mgr02_fault_cold_init(void);
extern void hmi_gfx_mgr02_fault_set(const UINT32 p_fault_id_32);
extern UINT32 hmi_gfx_mgr02_fault_get(void);
extern UINT8 hmi_gfx_mgr02_fault_check_critical_error(void);
extern UINT32 hmi_gfx_mgr02_fault_convert_error_code(UINT16 p_vg_error_code);
extern void hmi_gfx_mgr02_fault_clearall(void);


#else	  /* #if defined(GFX_OVG_FAULT_HANDLE) */
#define GFX_OVG_UTIL_SUCCESS(rc, api, execute)       \
do{                                                  \
	(execute);                                       \
}while(0)

#define GFX_OVG_UTIL_VG_DESTROY(rc, api, execute)    \
do{                                                  \
	(execute);                                       \
}while(0)
#define GFX_MGR02_OVG_LOG_ERROR(rc, error)
#define GFX_MGR02_LOG_ERROR(error)
#endif /* #if defined(GFX_OVG_FAULT_HANDLE) */

#endif 

/*REVISION HISTORY*/
/*---------------------------------------------------------------------------
** Release Label     :  Fault handling
** Date              :  10-27-2016
** cdsid             :  ashekhar
** Traceability      : Initial version - Fault handing - Task 
** Change Description: 731511: Add temporary error logging capability to Ui Core.
 ---------------------------------------------------------------------------*/
/*============================================================================
** Date              :  07/02/2016
** Traceability      :  RTC ID: 750237
** cdsId             :  sbollam
** Change Description:  Updated error logging capability and added
**                      OVG software recovery capability                         
**==========================================================================*/
