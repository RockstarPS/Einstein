/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2021. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_gfx_mgr02_tv2_clut.c
 **
 ** Description:    
 **                 
 **
 ** Organization:   UE COC, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define HMI_GFX_MGR02_TV2_CLUT_C

#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_tv2_clut.h"
#if defined(GFX_MGR02_TRAVEO2) && (GFX_MGR02_NUM_OF_CLUTS > 0U)
#include "cygfx_basetypes.h"

#define MAX_NUM_OF_DISP_PALLETTES 64U
#define MAX_NUM_OF_BLIT_PALLETTES 128U

typedef struct GFX_MGR02_TV2_CLUT_T{
    struct GFX_MGR02_TV2_CLUT_T *Prev;    
    CYGFX_PALETTE palette;
    struct GFX_MGR02_TV2_CLUT_T *Next;
}GFX_MGR02_TV2_CLUT;

static const UINT16 lc_max_disp_clut_entries_u16 = 1024U;
static const UINT16 lc_max_blit_clut_entries_u16 = 2048U;

static CYGFX_PALETTE hmi_gfx_mgr02_tv2_update_dispclut_queue(CYGFX_ADDR p_clut_p);
static CYGFX_PALETTE hmi_gfx_mgr02_tv2_update_blitclut_queue(CYGFX_ADDR p_clut_p);

static UINT32 l_total_disp_clut_size_u32;
static UINT32 l_total_blit_clut_size_u32;
static UINT8  l_blit_palette_counter;
static UINT8  l_disp_palette_counter;

static GFX_MGR02_TV2_CLUT *dispRecentlyUsed;
static GFX_MGR02_TV2_CLUT *dispLeastUsed;

static GFX_MGR02_TV2_CLUT *blitRecentlyUsed;
static GFX_MGR02_TV2_CLUT *blitLeastUsed;


void hmi_gfx_mgr02_tv2_pallette_init(void)
{
    dispRecentlyUsed = NULL;
    dispLeastUsed    = NULL;
    blitRecentlyUsed = NULL;
    blitLeastUsed    = NULL;
    
    l_total_disp_clut_size_u32 = 0UL;
    l_total_blit_clut_size_u32 = 0UL;
    
    l_blit_palette_counter = 0U;
    l_disp_palette_counter = 0U;
}

void hmi_gfx_mgr02_tv2_free_blit_pallettes(void)
{
    CYGFX_ERROR ret = CYGFX_OK;
    GFX_MGR02_TV2_CLUT *temp = NULL;
    
    /* Free complete blit palette region */
    IRIS_API_CHECK(ret, CyGfx_PaletteFree(NULL, CYGFX_PALETTE_REGION_BLIT));
    
    while(blitRecentlyUsed != NULL)
    {
        temp = blitRecentlyUsed->Next;
        if (blitRecentlyUsed->palette != NULL)
        {
            free(blitRecentlyUsed->palette);
            blitRecentlyUsed->palette = NULL;
        }
        free(blitRecentlyUsed);
        blitRecentlyUsed=temp;
    }
    
    blitRecentlyUsed = NULL;
    blitLeastUsed = NULL;
    
    l_blit_palette_counter = 0U;
    l_total_blit_clut_size_u32 = 0U;
}

void hmi_gfx_mgr02_tv2_free_all_pallettes(void)
{
    CYGFX_ERROR ret = CYGFX_OK;
    GFX_MGR02_TV2_CLUT *temp=NULL;
    
    /* Free complete display palette region */
    IRIS_API_CHECK(ret, CyGfx_PaletteFree(NULL, CYGFX_PALETTE_REGION_DISPLAY));
    
    while(dispRecentlyUsed!=NULL)
    {
        temp=dispRecentlyUsed->Next;
        if (dispRecentlyUsed->palette != NULL)
        {
            free(dispRecentlyUsed->palette);
            dispRecentlyUsed->palette =NULL;
        }       
        free(dispRecentlyUsed);
        dispRecentlyUsed=temp;
    }
    
    /* Free complete blit palette region */
    IRIS_API_CHECK(ret, CyGfx_PaletteFree(NULL, CYGFX_PALETTE_REGION_BLIT));
    
    while(blitRecentlyUsed!=NULL)
    {
        temp=blitRecentlyUsed->Next;
        if (blitRecentlyUsed->palette != NULL)
        {
            free(blitRecentlyUsed->palette);
            blitRecentlyUsed->palette =NULL;
        }
        free(blitRecentlyUsed);
        blitRecentlyUsed=temp;
    }
    
    dispRecentlyUsed=NULL;
    dispLeastUsed=NULL;
    blitRecentlyUsed=NULL;
    blitLeastUsed=NULL;
    
    l_disp_palette_counter= 0U;
    l_blit_palette_counter = 0U;

    l_total_disp_clut_size_u32 = 0U;
    l_total_blit_clut_size_u32 = 0U;
    
}

/*To bring the entry which is in the Queue to front.*/
static CYGFX_PALETTE hmi_gfx_mgr02_tv2_update_dispclut_queue(CYGFX_ADDR p_clut_p)
{
    CYGFX_PALETTE fl_ret_p =NULL;
    CYGFX_U32 fl_top_phyaddr_u32 = 0U;
    CYGFX_U32 fl_bottom_phyaddr_u32 = 0U;
    CYGFX_ERROR ret = CYGFX_OK;
    
    IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispRecentlyUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_top_phyaddr_u32));
    IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispLeastUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_bottom_phyaddr_u32));

    if(fl_top_phyaddr_u32== p_clut_p)
    {
        fl_ret_p = dispRecentlyUsed->palette;
        
    }
    else if(fl_bottom_phyaddr_u32 == p_clut_p)                          
    {
        dispLeastUsed->Next = dispRecentlyUsed;
        dispRecentlyUsed->Prev = dispLeastUsed;

        dispLeastUsed = dispLeastUsed->Prev;
        dispLeastUsed->Next =NULL;
        dispRecentlyUsed = dispRecentlyUsed->Prev;
        dispRecentlyUsed->Prev = NULL;
        
        fl_ret_p = dispRecentlyUsed->palette;
    }
    else
    {
        if(l_disp_palette_counter>2U)
        {
            UINT8 counter= l_disp_palette_counter-2u;
            struct GFX_MGR02_TV2_CLUT_T *cur;
            CYGFX_U32 fl_phyaddr_u32 = 0U;
            cur = dispRecentlyUsed->Next;
            for(;counter>0U;counter--)
            {
                IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(cur->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_phyaddr_u32));
                if(fl_phyaddr_u32 == p_clut_p)
                {
                    cur->Prev->Next=cur->Next;
                    cur->Next->Prev=cur->Prev;

                    cur->Prev = NULL;
                    cur->Next = dispRecentlyUsed;
                    dispRecentlyUsed->Prev= cur;
                    dispRecentlyUsed =cur;
                    fl_ret_p = dispRecentlyUsed->palette;
                    break;
                }
                else
                {
                    cur=cur->Next;
                }
            }
        }
    }
    return fl_ret_p;
}

static CYGFX_PALETTE hmi_gfx_mgr02_tv2_update_blitclut_queue(CYGFX_ADDR p_clut_p)
{
    CYGFX_PALETTE fl_ret_p =NULL;
    CYGFX_U32 fl_top_phyaddr_u32 = 0U;
    CYGFX_U32 fl_bottom_phyaddr_u32= 0U;
    CYGFX_ERROR ret = CYGFX_OK;
    
    IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(blitRecentlyUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_top_phyaddr_u32));
    IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(blitLeastUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_bottom_phyaddr_u32));
    if(fl_top_phyaddr_u32== p_clut_p)
    {
        fl_ret_p = blitRecentlyUsed->palette;
        
    }
    else if(fl_bottom_phyaddr_u32 == p_clut_p)                  
    {
        blitLeastUsed->Next = blitRecentlyUsed;
        blitRecentlyUsed->Prev = blitLeastUsed;

        blitLeastUsed = blitLeastUsed->Prev;
        blitLeastUsed->Next =NULL;
        blitRecentlyUsed = blitRecentlyUsed->Prev;
        blitRecentlyUsed->Prev = NULL;
        
        fl_ret_p = blitRecentlyUsed->palette;
    }
    else
    {
        if(l_blit_palette_counter>2U)
        {
            UINT8 counter= l_blit_palette_counter-2U;
            struct GFX_MGR02_TV2_CLUT_T *cur;
            CYGFX_U32 fl_phyaddr_u32 = 0U;
            cur = blitRecentlyUsed->Next;
            for(;counter>0U;counter--)
            {
                IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(cur->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_phyaddr_u32));
                if(fl_phyaddr_u32 == p_clut_p)
                {
                    cur->Prev->Next=cur->Next;
                    cur->Next->Prev=cur->Prev;

                    cur->Prev = NULL;
                    cur->Next = blitRecentlyUsed;
                    blitRecentlyUsed->Prev= cur;
                    blitRecentlyUsed =cur;
                    fl_ret_p = blitRecentlyUsed->palette;
                    break;
                }
                else
                {
                    cur=cur->Next;
                }
            }
        }
    }
    return fl_ret_p;
}


CYGFX_PALETTE hmi_gfx_mgr02_tv2_is_clut_already_added(CYGFX_PALETTE_REGION p_palette_region, UINT8 const *p_clut_p)
{
    CYGFX_PALETTE fl_pal_p =NULL;

    if(p_palette_region == CYGFX_PALETTE_REGION_BLIT)
    {
        if((l_blit_palette_counter > 0U) && (l_blit_palette_counter <= MAX_NUM_OF_BLIT_PALLETTES))
        {
            fl_pal_p = hmi_gfx_mgr02_tv2_update_blitclut_queue((CYGFX_ADDR)p_clut_p);
        }

    }
    else if(p_palette_region == CYGFX_PALETTE_REGION_DISPLAY)
    {

        if((l_disp_palette_counter > 0U) && (l_disp_palette_counter <= MAX_NUM_OF_DISP_PALLETTES))
        {
            fl_pal_p = hmi_gfx_mgr02_tv2_update_dispclut_queue((CYGFX_ADDR)p_clut_p);
        }
    }
    else
    {
        fl_pal_p = NULL;
    }
    return fl_pal_p;
}

CYGFX_PALETTE hmi_gfx_mgr02_tv2_add_clut(CYGFX_PALETTE_REGION p_palette_region , const void * p_clut_p, UINT16 p_size_u16)
{
    CYGFX_PALETTE fl_pal_p = NULL;
    CYGFX_ERROR ret = CYGFX_OK;
    CYGFX_U16 fl_size_u16;
    
    if((p_size_u16 % 16U) != 0U)
    {
        fl_size_u16 = ((p_size_u16 / 16U) + 1U) * 16U;
    }
    else
    {
        fl_size_u16 = p_size_u16;
    }
    
    if(p_palette_region == CYGFX_PALETTE_REGION_DISPLAY)
    {
        if(( l_disp_palette_counter < MAX_NUM_OF_DISP_PALLETTES) && ((l_total_disp_clut_size_u32 + fl_size_u16) <= lc_max_disp_clut_entries_u16))
        {
            struct GFX_MGR02_TV2_CLUT_T *temp = (GFX_MGR02_TV2_CLUT *)malloc(sizeof(GFX_MGR02_TV2_CLUT));
            if(temp != NULL)
            {
                fl_pal_p = (CYGFX_PALETTE)malloc(sizeof(CYGFX_PALETTE_OBJECT_S));
                if(fl_pal_p != NULL)
                {                    
                    IRIS_API_CHECK(ret, CyGfx_PaletteReset(fl_pal_p));
                    IRIS_API_CHECK(ret, CyGfx_PaletteAssign (fl_pal_p, CYGFX_PALETTE_FORMAT_B8G8R8, fl_size_u16, p_clut_p ));
                    IRIS_API_CHECK(ret, CyGfx_PaletteAlloc(fl_pal_p, CYGFX_PALETTE_REGION_DISPLAY));
                    
                    if(ret == CYGFX_OK)
                    {
                        temp->palette       = fl_pal_p;
                        if(dispRecentlyUsed==NULL)
                        {
                            dispRecentlyUsed=temp;
                            dispRecentlyUsed->Prev = NULL;
                            dispRecentlyUsed->Next = NULL;
                            dispLeastUsed = dispRecentlyUsed;
                        }
                        else
                        {
                            /*add the new element in the front of the queue*/
                            temp->Prev = NULL;
                            temp->Next = dispRecentlyUsed;
                            dispRecentlyUsed->Prev = temp;
                            dispRecentlyUsed = temp;

                        }
                        l_disp_palette_counter++;
                        l_total_disp_clut_size_u32 = l_total_disp_clut_size_u32 + fl_size_u16;
                    }
                    else
                    {
                        #ifdef GFX02_DEBUG_INFO
                        printf("Display Pallete allocation failed because its memory is either full or fragmented. \n");
                        #endif
                        free(temp);
                        free(fl_pal_p);
                        fl_pal_p = NULL;
                    }
                }
                else
                {
                    #ifdef GFX02_DEBUG_INFO
                    printf("malloc failed. Try to increase the heap memory size.\n");
                    #endif
                    free(temp);
                }
            }
            #ifdef GFX02_DEBUG_INFO
            else
            {
                printf("malloc failed. Try to increase the heap memory size.\n");
            }
            #endif
        }
    }
    else if(p_palette_region == CYGFX_PALETTE_REGION_BLIT)
    {
        while(( l_blit_palette_counter >= MAX_NUM_OF_BLIT_PALLETTES) || ((l_total_blit_clut_size_u32 + fl_size_u16) > lc_max_blit_clut_entries_u16))
        {
            /* remove the least used from queue */ 
            struct GFX_MGR02_TV2_CLUT_T *temp;
            CYGFX_U32 fl_count_u32 = 0U;
            temp = blitLeastUsed;
            if(blitLeastUsed != NULL)
            {
                IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(blitLeastUsed->palette,CYGFX_PALETTE_ATTR_COUNT,&fl_count_u32));
                l_total_blit_clut_size_u32 = l_total_blit_clut_size_u32 - fl_count_u32;
                IRIS_API_CHECK(ret, CyGfx_PaletteFree(blitLeastUsed->palette, CYGFX_PALETTE_REGION_BLIT));
                free(blitLeastUsed->palette);
                blitLeastUsed->palette = NULL;

                if(blitLeastUsed->Prev == NULL)
                {
                    blitRecentlyUsed = NULL;
                    blitLeastUsed = NULL;
                }
                else
                {
                    blitLeastUsed = blitLeastUsed->Prev;
                    blitLeastUsed->Next = NULL;
                }
            }
            free(temp);
            l_blit_palette_counter--;
        }
        
        if(( l_blit_palette_counter < MAX_NUM_OF_BLIT_PALLETTES) && ((l_total_blit_clut_size_u32 + fl_size_u16) <= lc_max_blit_clut_entries_u16))
        {
            struct GFX_MGR02_TV2_CLUT_T *temp = (GFX_MGR02_TV2_CLUT *)malloc(sizeof(GFX_MGR02_TV2_CLUT));
            if(temp != NULL)
            {
                fl_pal_p = (CYGFX_PALETTE)malloc(sizeof(CYGFX_PALETTE_OBJECT_S));
                if(fl_pal_p != NULL)
                {                    
                    IRIS_API_CHECK(ret, CyGfx_PaletteReset(fl_pal_p));
                    IRIS_API_CHECK(ret, CyGfx_PaletteAssign (fl_pal_p,CYGFX_PALETTE_FORMAT_B8G8R8, fl_size_u16, p_clut_p ));
                    IRIS_API_CHECK(ret, CyGfx_PaletteAlloc(fl_pal_p,CYGFX_PALETTE_REGION_BLIT));   
                    
                    if(ret == CYGFX_OK)
                    {
                        temp->palette       = fl_pal_p;
                        if(blitRecentlyUsed==NULL)
                        {
                            blitRecentlyUsed=temp;
                            blitRecentlyUsed->Prev = NULL;
                            blitRecentlyUsed->Next = NULL;
                            blitLeastUsed = blitRecentlyUsed;
                        }
                        else
                        {
                            /*add the new element in the front of the queue*/
                            temp->Prev = NULL;
                            temp->Next = blitRecentlyUsed;
                            blitRecentlyUsed->Prev = temp;
                            blitRecentlyUsed = temp;

                        }
                        l_blit_palette_counter++;
                        l_total_blit_clut_size_u32 = l_total_blit_clut_size_u32 + fl_size_u16;
                    }
                    else
                    {
                        #ifdef GFX02_DEBUG_INFO
                        printf("Blit Pallete allocation failed because its memory is either full or fragmented\n");
                        #endif
                        free(temp);
                        free(fl_pal_p);
                        fl_pal_p = NULL;
                    }
                }
                else
                {
                    #ifdef GFX02_DEBUG_INFO
                    printf("malloc failed. Try to increase the heap memory size.\n");
                    #endif
                    free(temp);
                }
            }
            #ifdef GFX02_DEBUG_INFO
            else
            {
                printf("malloc failed. Try to increase the heap memory size.\n");
            }
            #endif
        }
    }
    else
    {
        /*The code execution will not reach here. Adding this else loop to avoid warning.*/
    }

    return(fl_pal_p);    
}

void hmi_gfx_mgr02_tv2_remove_clut(CYGFX_PALETTE_REGION p_palette_region , const void * p_clut_p)
{
    struct GFX_MGR02_TV2_CLUT_T *temp =NULL;
    CYGFX_ERROR ret = CYGFX_OK;
    CYGFX_U32 fl_count_u32 = 0U;

    if((p_palette_region == CYGFX_PALETTE_REGION_DISPLAY) && (l_disp_palette_counter >0u))
    {
        CYGFX_U32 fl_top_phyaddr_u32 = 0U;
        CYGFX_U32 fl_bottom_phyaddr_u32 = 0U;
        
        IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispRecentlyUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_top_phyaddr_u32));
        IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispLeastUsed->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_bottom_phyaddr_u32));

        if(fl_top_phyaddr_u32 == (CYGFX_ADDR)p_clut_p)
        {
            temp = dispRecentlyUsed;
            IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispRecentlyUsed->palette,CYGFX_PALETTE_ATTR_COUNT,&fl_count_u32));
            l_total_disp_clut_size_u32 = l_total_disp_clut_size_u32 - fl_count_u32;
            IRIS_API_CHECK(ret, CyGfx_PaletteFree(dispRecentlyUsed->palette, CYGFX_PALETTE_REGION_DISPLAY));
            free(dispRecentlyUsed->palette);
            dispRecentlyUsed->palette = NULL;
            dispRecentlyUsed = dispRecentlyUsed->Next;
            dispRecentlyUsed->Prev = NULL;
            free(temp);
            l_disp_palette_counter--;
        }
        else if(fl_bottom_phyaddr_u32 == (CYGFX_ADDR)p_clut_p)
        {
            temp = dispLeastUsed;
            IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(dispLeastUsed->palette,CYGFX_PALETTE_ATTR_COUNT,&fl_count_u32));
            l_total_disp_clut_size_u32 = l_total_disp_clut_size_u32 - fl_count_u32;
            IRIS_API_CHECK(ret, CyGfx_PaletteFree(dispLeastUsed->palette, CYGFX_PALETTE_REGION_DISPLAY));
            free(dispLeastUsed->palette);
            dispLeastUsed->palette = NULL;
            dispLeastUsed = dispLeastUsed->Prev;
            dispLeastUsed->Next = NULL;
            free(temp);
            l_disp_palette_counter--;
        }
        else
        {
            if(l_disp_palette_counter>2U)
            {
                UINT8 counter= l_disp_palette_counter-2U;
                struct GFX_MGR02_TV2_CLUT_T *cur;
                CYGFX_U32 fl_phyaddr_u32 = 0U;
                cur = dispRecentlyUsed->Next;
                for(;counter>0U;counter--)
                {
                    IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(cur->palette,CYGFX_PALETTE_ATTR_PHYS_ADDRESS,&fl_phyaddr_u32));
                    if(fl_phyaddr_u32 == (CYGFX_ADDR)p_clut_p) 
                    {
                        temp = cur; 
                        cur->Prev->Next=cur->Next;
                        cur->Next->Prev=cur->Prev;

                        temp->Prev = NULL;
                        temp->Next = NULL;
                        IRIS_API_CHECK(ret,CyGfx_PaletteGetAttribute(temp->palette,CYGFX_PALETTE_ATTR_COUNT,&fl_count_u32));
                        l_total_disp_clut_size_u32 = l_total_disp_clut_size_u32 - fl_count_u32;
                        IRIS_API_CHECK(ret, CyGfx_PaletteFree(temp->palette, CYGFX_PALETTE_REGION_DISPLAY));
                        free(temp->palette);
                        temp->palette = NULL;
                        free(temp);
                        l_disp_palette_counter--;

                        break;
                    }
                    else
                    {
                        cur=cur->Next;
                    }
                }
            }
        }
            
    }
}

UINT32 hmi_gfx_mgr02_tv2_get_clut_index_width(UINT16 p_clut_count_u16)
{
    UINT32 fl_clut_index_width_u32 =0U;
    if(p_clut_count_u16 >128U)
    {
        fl_clut_index_width_u32 = 8U;
    }
    else if(p_clut_count_u16> 64U)
    {
        fl_clut_index_width_u32 = 7U;
    }
    else if(p_clut_count_u16 >32U)
    {
        fl_clut_index_width_u32 = 6U;
    }
    else if(p_clut_count_u16 >16U)
    {
        fl_clut_index_width_u32 = 5U;
    }
    else if(p_clut_count_u16 >8U)
    {
        fl_clut_index_width_u32 = 4U;
    }
    else if(p_clut_count_u16 >4U)
    {
        fl_clut_index_width_u32 = 3U;
    }
    else if(p_clut_count_u16 >2U)
    {
        fl_clut_index_width_u32 = 2U;
    }
    else
    {
        fl_clut_index_width_u32 =1U;
    }
    
    return (fl_clut_index_width_u32);
}
#endif

