/*******************************************************************************
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

 **   file        hmi_gfx_mgr02_mem_mgmt.h
 **   
 **   brief       This file defines some interfaces for the memory management.
 **               to handle memory allocation and freeing.
*******************************************************************************/

#ifndef HMI_GFX_MGR02_MEM_MGMT_H
#define HMI_GFX_MGR02_MEM_MGMT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
                              Includes
*******************************************************************************/

#include "system.h"

/*******************************************************************************
                             Type Definitions
*******************************************************************************/

typedef enum
{
    GFX_OK                              = 0x0,       
    GFX_MM_ERR_INVALID_PARAMETER        = 0xE01,
    GFX_MM_ERR_NO_MEMORY                = 0xE02,
    GFX_MM_ERR_INVALID_MEMORY           = 0xE03,
    GFX_MM_ERR_CHECK_FAILED             = 0xE04,
    GFX_MM_ERR_MAX_HEAP_CREATED         = 0xE05
}GFX_ERROR;


/** Type definition for memory heap handle */
typedef void* GFX_MGR02_MEM_MGMT_HEAP_HANDLE;

/*******************************************************************************
                           Macro Definitions
*******************************************************************************/

#ifdef HMI_GFX_MGR02_MEM_MGMT_C
#define GFX_EXTERN
#else
#define GFX_EXTERN            extern   
#endif

/*******************************************************************************
                            Function Prototypes
*******************************************************************************/

GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_create_heap(GFX_MGR02_MEM_MGMT_HEAP_HANDLE *p_hdlmem,
                                                        UINT32                          p_size,
                                                        UINT32                          p_baseAddress);

GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_destroy_heap(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem);

GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_alloc(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem,
                                                       UINT32                          p_size,
                                                       UINT32                          p_alignment,
                                                       UINT32                         *p_addr);


GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_free(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem,
                                                      void                           *p_addr);

GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_heap_realloc(GFX_MGR02_MEM_MGMT_HEAP_HANDLE p_hdlmem,
                                                         UINT32                         p_size, 
                                                         UINT32                         p_alignment, 
                                                         UINT32                        *p_newaddr, 
                                                         UINT32                        *p_oldaddr);

GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_size(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem,
                                                     UINT32                         *p_size);


GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_free(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem,
                                                     UINT32                         *p_size);


GFX_EXTERN GFX_ERROR hmi_gfx_mgr02_mem_mgmt_get_largest(GFX_MGR02_MEM_MGMT_HEAP_HANDLE  p_hdlmem,
                                                        UINT32                         *p_size);

#ifdef __cplusplus
}
#endif
#endif /* GFX_MGR02_MEM_MGMT_H */
