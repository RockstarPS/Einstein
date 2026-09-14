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
 ** Name:          hmi_main.c
 **
 ** Description:   Implements the default init and schedular functionality
 **                for the simulation. Also  implements the default button
 **                handler
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/


/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr02_cfg.h"
#include "ut_compatibility.h"
#include "Rte_Type.h"


extern UINT32 GddCddTick(void);

void lodepng_free(void* ptr);
void* lodepng_malloc(size_t size);
void* lodepng_realloc(void* ptr, size_t new_size);

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
/*
typedef struct {
    unsigned char* pImage;
    unsigned int width;
    unsigned int height;    
} tPngDecode;
*/

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/

 /*
static tPngDecode pngImage;
*/

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void ScrMainInit()
{

}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void ScrMainDeinit()
{
    /*
    if (pngImage.pImage)
    {
        lodepng_free(pngImage.pImage);
        pngImage.pImage = 0;
    }
    */
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
UINT32 hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{
    return 0;
}
void lodepng_free(void* ptr)
{
    /*
    utVideoFree(ptr);
    */
}

void* lodepng_malloc(size_t size)
{
    /*
    return utVideoAlloc(size, 4, 0);
    */
}

void* lodepng_realloc(void* ptr, size_t new_size)
{
    /*
    void* pNew = lodepng_malloc(new_size);
    
    if ((pNew)&&(ptr))
    {
        memcpy(pNew, ptr, new_size);
        utVideoFree(ptr);
    }
    
    return pNew;
    */
}
