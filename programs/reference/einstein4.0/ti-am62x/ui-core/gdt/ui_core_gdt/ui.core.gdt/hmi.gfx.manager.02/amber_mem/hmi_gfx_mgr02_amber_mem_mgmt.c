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
 ** Name:           hmi_gfx_mgr02_amber_mem_mgmt.c
 **
 ** Description:    This module is used for memory allocation
 **
 **============================================================================
 **
 **==========================================================================*/
/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/

#define HMI_GFX_MGR02_AMBER_MEM_MGMT_C 
 
#include "hmi_gfx_mgr02_amber_mem_mgmt.h"
#if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)||defined(GFX_MGR02_TRAVEO2)

#ifdef GFX02_DEBUG_INFO
#include <stdio.h>
#include <stdlib.h>
#endif /* #ifdef GFX02_DEBUG_INFO */

#include <string.h>
#include "mml_gdc_driver_api.h"
#include "ut_memman.h"
#include "ut_compatibility.h"

#if defined(GFX_MGR02_TRAVEO2)
#include "ut_compat.h"
#endif

#ifdef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
#define FRAME_BUFFER_ALIGN 32
#include "hmi_gfx_mgr02_mem_mgmt.inc"
#endif
 
#if defined(GFX_MGR02_USER_DEFINED_MM)
#include "hmi_gfx_mgr02_mem_config.h"
#endif

#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
extern char __ghsbegin_gfx02_workbuff_start[];
extern char __ghsend_gfx02_workbuff_end[];
#endif

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
#ifdef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
static void * hmi_gfx_mgr02_amber_mem_mgmt_get_idle_fb_ptr(const IrisMemInfo * p_meminfo);
#endif 

#if defined (GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG) 
static MM_U32 hmi_gfx_mgr02_get_extram_size(void);
#endif
/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
#ifdef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
    /* It is expected that the Instruction Buffer must be allocated in VRAM 
    ** Application team must place memory section "GFX02_IB_RW_DATA" in VRAM */
    #ifndef GFX02_IB_RW_DATA_PREFIX
        #if defined(__GNUC__)
            #define GFX02_IB_RW_DATA_PREFIX __attribute__((section("GFX02_IB_RW_DATA")))    
        #elif defined(__ghs__)
            #pragma ghs section bss = "GFX02_IB_RW_DATA"
        #endif
    #endif
    #ifndef GFX02_IB_RW_DATA_PREFIX
        #define GFX02_IB_RW_DATA_PREFIX
    #endif

    #if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_instruction_buffer[GFX_MGR02_IRIS_INSTR_BUFF_SIZE];
    #endif
    #if defined(GFX_MGR02_TRAVEO2)
        #define IBUF_SIZE_MIN                               (1024)
        #define IBUF_SIZE_MAX                               (0x3FFC)
        #define IBUF_SIZE_ALIGN                             (4)
        
        #define GFX_MGR02_ALIGN(value)                     (((value)/(IBUF_SIZE_ALIGN)) * (IBUF_SIZE_ALIGN))
        #define GFX_MGR02_IS_IBUFF_SIZE_VALID(value)       (((GFX_MGR02_ALIGN(value)) >= (IBUF_SIZE_MIN)) && ((GFX_MGR02_ALIGN(value)) <= (IBUF_SIZE_MAX)))
        
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK0_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_memtask0_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_MEMTASK0_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK1_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_memtask1_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_MEMTASK1_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK2_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_memtask2_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_MEMTASK2_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK0_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_wintask0_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_WINTASK0_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK1_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_wintask1_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_WINTASK1_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK2_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_wintask2_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_WINTASK2_IBUFF_SIZE)];
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK3_IBUFF_SIZE))
        static GFX02_IB_RW_DATA_PREFIX uint8_t l_iris_pe_ib_wintask3_buffer[GFX_MGR02_ALIGN(GFX_MGR02_IRIS_WINTASK3_IBUFF_SIZE)];
        #endif
    #endif
    
    #if defined(__ghs__)
        #pragma ghs section bss = default
    #endif
#endif 

#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG) 
static MML_MMAN_HEAP_HANDLE g_heapHandle_HRAM = (MML_MMAN_HEAP_HANDLE)NULL;
#endif   
/*============================================================================
 ** F U N C T I O N   D E F I N I T I O N S
 **==========================================================================*/
     
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG) 
/****************************************************************************
Function Name        : hmi_gfx_mgr02_get_extram_size()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static MM_U32 hmi_gfx_mgr02_get_extram_size(void)
{
   return ((MM_U32)__ghsend_gfx02_workbuff_end - (MM_U32)__ghsbegin_gfx02_workbuff_start);
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_init()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
MM_ERROR hmi_gfx_mgr02_amber_mem_mgmt_init(void)
{
    MM_ERROR fl_ret;
    
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
    MM_U32 fl_dynamic_HRAM_Size_U32 = hmi_gfx_mgr02_get_extram_size();
    MM_U32 fl_dynamic_HRAM_baseAddress_U32 = (MM_U32)__ghsbegin_gfx02_workbuff_start;
#endif
    
    fl_ret = utMmanReset();    /*VRAM Initialization.*/
  
#if defined(GFX_MGR02_USER_DEFINED_MM)
    if(fl_ret == MML_OK)
    {
      fl_ret = utMmanInit(); /*Partition in VRAM for Freetype2 ext font engine*/
    }
#endif
#if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
    if((fl_dynamic_HRAM_Size_U32>(MM_U32)0) &&(fl_ret == MML_OK))
    {
        if(g_heapHandle_HRAM != NULL)
        {
           (void)utMmanDestroyHeap(g_heapHandle_HRAM);
            g_heapHandle_HRAM = (MML_MMAN_HEAP_HANDLE)NULL;
        }
        fl_ret = utMmanCreateHeap(&g_heapHandle_HRAM, fl_dynamic_HRAM_Size_U32, fl_dynamic_HRAM_baseAddress_U32 );
        if (fl_ret != MML_OK)
        {
            #ifdef GFX02_DEBUG_INFO
               (void)printf("utMmanReset: utMmanCreateHeap failed to create HRAM heap(0x%08x)\n", fl_ret);
            #endif
        }
    }	
#endif  

    return fl_ret;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_malloc()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : void * on sucess and NULL if can't able to allocate requested memory.
Critical Section     : None
Parameters           : IrisMemInfo
******************************************************************************/
void* hmi_gfx_mgr02_amber_mem_mgmt_malloc(const IrisMemInfo *p_meminfo)
{
    MM_ADDR* fl_ret_ptr = (MM_ADDR*)0;

    if (p_meminfo != NULL)
    {
        switch(p_meminfo->MemCateg)
        {
#ifdef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
            /* Below Memory is allocated Statically at Compile time. 
            ** Below sample code is for HMI reference. Application
            ** team can allocates memory statically as per requirement and return its pointer value
            ** by checking p_meminfo->MemCateg (Refer enum IRIS_MEM_CATEGORY)
            */
    #if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)
            case IRIS_PE_INSTRUCTION_BUFFER:
            {
                fl_ret_ptr = (void *)&l_iris_pe_instruction_buffer;
            }
            break;
    #endif
    #if defined(GFX_MGR02_TRAVEO2)
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK0_IBUFF_SIZE))
            case IRIS_PE_IB_MEMTASK0:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_memtask0_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK1_IBUFF_SIZE))
            case IRIS_PE_IB_MEMTASK1:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_memtask1_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_MEMTASK2_IBUFF_SIZE))
            case IRIS_PE_IB_MEMTASK2:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_memtask2_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK0_IBUFF_SIZE))
            case IRIS_PE_IB_WINTASK0:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_wintask0_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK1_IBUFF_SIZE))
            case IRIS_PE_IB_WINTASK1:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_wintask1_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK2_IBUFF_SIZE))
            case IRIS_PE_IB_WINTASK2:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_wintask2_buffer;
            }
            break;
        #endif
        #if (GFX_MGR02_IS_IBUFF_SIZE_VALID(GFX_MGR02_IRIS_WINTASK3_IBUFF_SIZE))
            case IRIS_PE_IB_WINTASK3:
            {
                fl_ret_ptr = (void *)&l_iris_pe_ib_wintask3_buffer;
            }
            break;
        #endif
    #endif /* #if defined(GFX_MGR02_TRAVEO2) */
            case IRIS_WIDGET_FRONT_RENDER_BUFFER:
            case IRIS_WIDGET_BACK_RENDER_BUFFER:
            {
                /* If static FB allocation is selected, then the widget fb memory will always be allocated from VRAM. 
                ** Even if the memory location is configured as HRAM in GDT tool. This is because all the frame buffers
                ** are placed in same memory sections when generated from GDT tool, i.e., VRAM. This usecase needs to be
                ** handled if such requirements arises in future.
                */ 
                fl_ret_ptr = hmi_gfx_mgr02_amber_mem_mgmt_get_idle_fb_ptr(p_meminfo);
            }
            break;
#else      
            /* Below Memory is Allocated Dynamically at Runtime */
            case IRIS_WIDGET_FRONT_RENDER_BUFFER:
            case IRIS_WIDGET_BACK_RENDER_BUFFER:
    #if defined(GFX_MGR02_AMBER)||defined(GFX_MGR02_AMBER_IRIS)        
            case IRIS_PE_INSTRUCTION_BUFFER:
    #endif        
    #if defined(GFX_MGR02_TRAVEO2)        
            case IRIS_PE_IB_MEMTASK0:
            case IRIS_PE_IB_MEMTASK1:
            case IRIS_PE_IB_MEMTASK2:
            case IRIS_PE_IB_WINTASK0:
            case IRIS_PE_IB_WINTASK1:
            case IRIS_PE_IB_WINTASK2:
            case IRIS_PE_IB_WINTASK3:
    #endif        
#endif        
            case IRIS_DE_ALPHA_BUFFER:
            case IRIS_DE_PATH_BUFFER:
            #ifdef GFX_STRING_CACHE_ENABLED
            case IRIS_STRING_CACHE_BUFFER:
            #endif
            default:
            {
                if(p_meminfo->ExtMemory == (UINT8)0)
                {
                    #ifndef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
                    fl_ret_ptr = mmlGdcVideoAlloc(p_meminfo->Size, p_meminfo->Alignment, NULL);
                    #endif
                }  
                #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)
                else
                {
                    MM_ADDR ulRet = (MM_ADDR)0;
                    if (MML_OK != utMmanHeapAlloc(g_heapHandle_HRAM, p_meminfo->Size, p_meminfo->Alignment, &ulRet))
                    {
                        #ifdef GFX02_DEBUG_INFO
                        (void)printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_malloc: failed to allocate %d bytes\n", p_meminfo->Size);
                        #endif
                        ulRet = (MM_ADDR)0;
                    }
                    fl_ret_ptr = (MM_ADDR*)ulRet;
                }
                #endif
            }
            break;
        }
    }    
    return fl_ret_ptr;
}

/****************************************************************************
Function Name        : void hmi_gfx_mgr02_amber_mem_mgmt_free()
Description          : Initializes internal data for first tme use
Invocation           : When ever generic context needs to be initialized
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
void hmi_gfx_mgr02_amber_mem_mgmt_free(void* pAddr)
{
    if(pAddr != NULL)
    {
        #if defined(GFX_MGR02_SPANSION_EXTRAM_USAGE_CFG)    
        MM_U32 fl_start_addr = (MM_U32)__ghsbegin_gfx02_workbuff_start;
        MM_U32 fl_end_addr   = (MM_U32)__ghsend_gfx02_workbuff_end;
        if(((MM_U32)((MM_ADDR*)pAddr) >= fl_start_addr) && ((MM_U32)((MM_ADDR*)pAddr) <= fl_end_addr))
        {
            MM_ERROR ret;
            ret = utMmanHeapFree(g_heapHandle_HRAM, pAddr);
            if (ret != MML_OK)
            {
                  #ifdef GFX02_DEBUG_INFO
                    (void)printf("[ERROR] hmi_gfx_mgr02_mem_mgmt_free: failed to free memory at %p!\n", pAddr);
                  #endif 
            }
        }
        else    
        #endif  
        {
            #ifndef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
            mmlGdcVideoFree(pAddr);
            #endif
        }
    }
}

#ifdef GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION
/****************************************************************************
Function Name        : hmi_gfx_mgr02_amber_mem_mgmt_get_idle_fb_ptr
Description          : 
Invocation           : 
Return Value         : None
Critical Section     : None
Parameters           : None
******************************************************************************/
static void * hmi_gfx_mgr02_amber_mem_mgmt_get_idle_fb_ptr(const IrisMemInfo * p_meminfo)
{
    void *   fl_ret_ptr = NULL;
    uint8_t  fl_fb_group_id = p_meminfo->WidgetFBGroupId;

    if (fl_fb_group_id < GFX_NUM_OF_FB_GROUPS) 
    {
        uint16_t fl_last_used_client_id = l_fb_groups_SA[fl_fb_group_id].lastUsedClientID;
            
        if (fl_last_used_client_id != GFX_MGR02_INVALID_CLIENT_ID)
        {
            void * fl_alloc_fb_ptr = hmi_gfx_mgr02_layout_get_front_fb(fl_last_used_client_id);
            if (fl_alloc_fb_ptr != NULL)
            {   
                if (fl_alloc_fb_ptr == l_fb_groups_SA[fl_fb_group_id].fb[1])
                {
                    fl_ret_ptr = (void*)l_fb_groups_SA[fl_fb_group_id].fb[0];
                }
                else if (fl_alloc_fb_ptr == l_fb_groups_SA[fl_fb_group_id].fb[0])
                {
                    fl_ret_ptr = (void*)l_fb_groups_SA[fl_fb_group_id].fb[1];
                }
                else
                {
                    /* To Avoid MISRA Warning */
                }
            }
        }
        
        if (fl_ret_ptr == NULL)
        {
            if (p_meminfo->MemCateg == IRIS_WIDGET_FRONT_RENDER_BUFFER)
            {
                fl_ret_ptr = (void*)l_fb_groups_SA[fl_fb_group_id].fb[1];
            }
            else /* (p_meminfo->MemCateg == IRIS_WIDGET_BACK_RENDER_BUFFER) */
            {
                fl_ret_ptr = (void*)l_fb_groups_SA[fl_fb_group_id].fb[0];
            }
        }
        
        if (fl_ret_ptr != NULL)
        {
            l_fb_groups_SA[fl_fb_group_id].lastUsedClientID = (uint16_t)p_meminfo->WidgetClientId;
        }
    }
    return fl_ret_ptr;
}
#endif

#ifdef  __cplusplus
}
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
 ** 
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

