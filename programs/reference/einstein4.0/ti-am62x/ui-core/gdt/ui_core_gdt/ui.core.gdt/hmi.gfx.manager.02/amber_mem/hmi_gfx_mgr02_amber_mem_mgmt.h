/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2016. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_amber_mem_mgmt.h
 **
 ** Description:    
 **
 **
 **============================================================================
 **
 **==========================================================================*/
 #ifndef HMI_GFX_MGR02_AMBER_MEM_MGMT_H
 #define HMI_GFX_MGR02_AMBER_MEM_MGMT_H
 /*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
 #include "hmi_gfx_mgr02_layout.h"
 #if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)
 #include "mm_types.h"
  
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
typedef enum
{
	#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)
    IRIS_PE_INSTRUCTION_BUFFER,
	#endif
	#if defined(GFX_MGR02_TRAVEO2)
	IRIS_PE_IB_MEMTASK0,
	IRIS_PE_IB_MEMTASK1,
	IRIS_PE_IB_MEMTASK2,
	IRIS_PE_IB_WINTASK0,
	IRIS_PE_IB_WINTASK1,
	IRIS_PE_IB_WINTASK2,
	IRIS_PE_IB_WINTASK3,
	#endif
    IRIS_WIDGET_FRONT_RENDER_BUFFER,
    IRIS_WIDGET_BACK_RENDER_BUFFER,
    IRIS_DE_ALPHA_BUFFER,
    IRIS_DE_PATH_BUFFER,
    IRIS_TEXT_TEMP_BUFFER,
#ifdef GFX_STRING_CACHE_ENABLED
    IRIS_STRING_CACHE_BUFFER,
#endif
    IRIS_WDG_WARP_TEMP_BUFFER,
    IRIS_PIXENG_FRONT_RENDER_BUFFER,
    IRIS_PIXENG_BACK_RENDER_BUFFER,
    IRIS_VIDEO_BUFFER
}IRIS_MEM_CATEGORY;
typedef struct 
{
    IRIS_MEM_CATEGORY   MemCateg;
    MM_U32              WidgetClientId;    
    MM_U32              Alignment;
    MM_U32              Size;
    MM_U08              ExtMemory;
#if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    MM_U08              WidgetFBGroupId;
#endif
}IrisMemInfo;
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
extern MM_ERROR hmi_gfx_mgr02_amber_mem_mgmt_init(void); 
extern void* hmi_gfx_mgr02_amber_mem_mgmt_malloc(const IrisMemInfo *p_meminfo);
extern void hmi_gfx_mgr02_amber_mem_mgmt_free(void* pAddr);


#endif
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
 ** CMS Rev #        Date         By
 ** CMS Rev X.X      mm/dd/yy     CDSID
 **
 **============================================================================
 ** CMS Rev 1.2     21-Aug-2017    CSAKTHIV
 ** RTC 939063:
 ** GFX_MGR02_AMBER_IRIS support added for Hyundai BDC.
 **
 ** CMS Rev 1.1      16-Aug-2017    SSIGAMAN
 ** 908966: Static allocation of VRAM required.
 ** Modified the files inorder to support user to allocate the required memories
 ** widget rendering and memory required for Draw engine and widget warping.
 **
 ** CMS Rev 1.0      23-Nov-2016    SBOLLAM/APERUMAL
 ** This file is added to provide interfaces to allocate memory in VRAM / HRAM
 **==========================================================================*/

/* end of file =============================================================*/

