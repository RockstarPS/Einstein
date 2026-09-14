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
 ** Name:           hmi_gfx_mgr02_imxrt_mem_mgmt.h
 **
 ** Description:    
 **
 **
 **============================================================================
 **
 **==========================================================================*/
 #ifndef HMI_GFX_MGR02_IMXRT_MEM_MGMT_H
 #define HMI_GFX_MGR02_IMXRT_MEM_MGMT_H
 /*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
 #include "hmi_gfx_mgr02_layout.h"
 #if defined(GFX_MGR02_IMXRT)||defined(GFX_MGR02_IMXRT_PXP)
 
  
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
typedef enum
{
    IMXRT_WIDGET_FRONT_RENDER_BUFFER,
    IMXRT_WIDGET_BACK_RENDER_BUFFER,
    IMXRT_FRONT_RENDER_BUFFER,
    IMXRT_BACK_RENDER_BUFFER,
    IMXRT_STRING_CACHE_BUFFER,
    IMXRT_VGLITE_PATH_CMD_BUFFER,
    IMXRT_VGLITE_DRIVER_HEAP_MEM
	IMXRT_SWRLE_DECOMPR_BUFFER
}IMXRT_MEM_CATEGORY;
typedef struct 
{
    IMXRT_MEM_CATEGORY   MemCateg;
    UINT32              WidgetClientId;
    UINT32              Alignment;
    UINT32              Size;
    UINT8               ExtMemory;
}PixEngMemInfo;
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
extern void hmi_gfx_mgr02_imxrt_mem_mgmt_init(void); 
extern void* hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(PixEngMemInfo *p_meminfo);
extern void hmi_gfx_mgr02_imxrt_mem_mgmt_free(void* pAddr);


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
 ** CMS Rev 1.0     21-May-2021    CSAKTHIV
 ** 
 ** Initial version for IMXRT 
 **
 **==========================================================================*/

/* end of file =============================================================*/

