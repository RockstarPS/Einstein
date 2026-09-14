/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2004. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************

File Name        :  hmi_gfx_ddraw.cpp
Module Short Name:  DDRAW
VOBName          :  sw_hmi_ss
Author           :  emanoj1
Description      :  Graphics Driver

Organization     :  Driver Information Software Section,
                    Visteon Corporation
List the compiler name with the ersion number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :
Target Processor :
******************************************************************************/
#define HMI_GFX_DDRAW_CPP

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/
#include "stdafx.h"
#include <ddraw.h>
#include "hmi_gfx_ddraw.h"
#include "hmi_gfx_driver.h"

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#ifdef TRIPLE_BUFFERING
   #error "Triple buffering implementation is incomplete.\n"
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static LPDIRECTDRAW        g_pDD           = NULL; // DirectDraw object
static LPDIRECTDRAWSURFACE g_pDDSPrimary   = NULL; // DirectDraw primary surface
static LPDIRECTDRAWSURFACE g_pDDSBack1     = NULL; // DirectDraw back surface
#ifdef TRIPLE_BUFFERING
   static LPDIRECTDRAWSURFACE g_pDDSBack2  = NULL; // DirectDraw back surface
#endif
static DDSURFACEDESC       g_surfdesc;
static BOOL                g_surf_locked   = FALSE;
static DWORD               g_dwRGBBitCount = 0xFF; // Invalid RGB
static UINT32            * g_back_buffer_P  = 0;
static UINT32            * g_front_buffer_P = 0;

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

//-----------------------------------------------------------------------------
// Name: EnumFunction()
// Desc: Enumeration callback for surfaces in flipping chain. We expect this
//          function to be called once with the surface interface pointer of
//          our back buffer (we only ask for a single back buffer.)
//-----------------------------------------------------------------------------
HRESULT PASCAL EnumFunction(LPDIRECTDRAWSURFACE pSurface,
                            LPDDSURFACEDESC     lpSurfaceDesc,
                            LPVOID              lpContext)
{
    static int bCalled = 0;

    if (bCalled == 0)
    {
        g_pDDSBack1 = pSurface;
        bCalled++;
	#ifdef DEBUG
        printf("EnumFunction1 %d\n",g_pDDSBack1);
	#endif
        return DDENUMRET_OK;
    }
#ifdef TRIPLE_BUFFERING
	else if (bCalled == 1)
    {
        g_pDDSBack2 = pSurface;
        bCalled++;
	#ifdef DEBUG
        printf("EnumFunction2 %d\n",g_pDDSBack1);
	#endif
        return DDENUMRET_OK;
    }
#endif
	else
    {
	#ifdef DEBUG
        printf("Enumerated more than surface?\n");
        pSurface->Release();
	#endif
        return DDENUMRET_CANCEL;
    }
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
extern "C" HRESULT hmi_gfx_ddraw_init(HWND l_hWnd)
{
    DDSURFACEDESC ddsd;
    HRESULT       hRet;

    hRet = DirectDrawCreate(NULL, &g_pDD, NULL);

    if(hRet == DD_OK)
    {
       hRet = g_pDD->SetCooperativeLevel(l_hWnd, DDSCL_FULLSCREEN);
       if(hRet == DD_OK)
       {
          /*
          ** Create the primary surface with 1 back buffer
          */
          memset(&ddsd, 0, sizeof(ddsd));
          ddsd.dwSize            = sizeof(ddsd);
          ddsd.dwFlags           = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
          ddsd.ddsCaps.dwCaps    = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP;
          ddsd.dwBackBufferCount = 1;
          hRet = g_pDD->CreateSurface(&ddsd, &g_pDDSPrimary, NULL);

		  if(hRet == DD_OK)
		  {
             DDPIXELFORMAT DDPixelFormat;

             // Get a pointer to the back buffer
             hRet = g_pDDSPrimary->EnumAttachedSurfaces(&g_pDDSPrimary, EnumFunction);
		  #ifdef DEBUG
             if (hRet != DD_OK)
             {
                printf("EnumAttachedSurfaces FAILED\n");
             }
			 else
			 {
                printf("DDRAW init done\n");
			 }
		  #endif
			 DDPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
		     hRet = g_pDDSPrimary->GetPixelFormat(&DDPixelFormat);
             if (hRet == DD_OK)
			 {
				 switch(DDPixelFormat.dwRGBBitCount)
				 {
					case 16: g_dwRGBBitCount = GFX_RGB565;  break;
					case 32: g_dwRGBBitCount = GFX_ARGB8888;break;
					default: g_dwRGBBitCount = 0xFF;        break;
				 }
			 }
		  #ifdef DEBUG
			 else
             {
                printf("GetPixelFormat FAILED\n");
             }
          #endif
		  }
	   #ifdef DEBUG
          else
          {
             if (hRet == DDERR_NOFLIPHW)
             {
                printf("Display driver doesn't support flipping surfaces.\n");
             }
             printf("CreateSurface FAILED.\n");
          }
	   #endif
	   }
    #ifdef DEBUG
       else
       {
          printf("SetCooperativeLevel FAILED\n");
       }
    #endif
	}
#ifdef DEBUG
    else
    {
        printf("DirectDrawCreate FAILED\n");
    }
#endif
	return(hRet);
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
extern "C" DWORD hmi_gfx_ddraw_get_fb_pix_format(void)
{
   return(g_dwRGBBitCount);
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
extern "C" LPVOID hmi_gfx_ddraw_get_backbuffer(void)
{
   HRESULT  hRet;
   memset(&g_surfdesc, 0, sizeof(DDSURFACEDESC));
   g_surfdesc.dwSize = sizeof(g_surfdesc);
   hRet = g_pDDSBack1->Lock(NULL,&g_surfdesc, DDLOCK_WRITEONLY, NULL);

   if(hRet == DD_OK)
   {
      g_surf_locked   = TRUE;
	  g_back_buffer_P = (UINT32 *)g_surfdesc.lpSurface;
      return(g_surfdesc.lpSurface);
   }
   else
   {
   #ifdef DEBUG
	  printf("Surface Lock Failed\n");
   #endif
      g_surf_locked = FALSE;
      return(NULL);
   }
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
extern "C" void hmi_gfx_ddraw_flip(BOOL p_post_copy)
{
    HRESULT hRet;

#ifdef PRINT_METRICS
    DWORD   dwSTime;
    DWORD   dwETime;
    dwSTime = GetTickCount();
#endif

    if(g_surf_locked != FALSE)
    {
       g_surf_locked = FALSE;
       g_pDDSBack1->Unlock(NULL);
       if(p_post_copy != FALSE)
       {
           /*
           ** Bit from backbuffer2 to backbuffer1
           */
           DDBLTFX ddbltfx;
           memset(&ddbltfx, 0, sizeof(ddbltfx));
           ddbltfx.dwSize = sizeof(ddbltfx);
		   /*
		   ** Flip the back buffer with Front. Once the flip finishes
		   ** copy the front buffer again to the new backbuffer so that we
		   ** can rework on it later.
		   */
           hRet = g_pDDSPrimary->Flip(g_pDDSBack1, DDFLIP_WAITVSYNC);
		   while(g_pDDSPrimary->GetFlipStatus(DDGFS_ISFLIPDONE) == DDERR_WASSTILLDRAWING);

	   #ifdef PRE_COPY_USE_BLT
           g_pDDSBack1->Blt(NULL, g_pDDSPrimary, NULL, DDBLT_WAITNOTBUSY, &ddbltfx);
		   while(g_pDDSBack1->GetBltStatus(DDGBS_ISBLTDONE) == DDERR_WASSTILLDRAWING);
	   #else
		   g_front_buffer_P = g_back_buffer_P;
		   hmi_gfx_ddraw_get_backbuffer();
		   if(g_surf_locked != FALSE)
		   {
			  UINT32 * fl_src_P  = g_front_buffer_P;
			  UINT32 * fl_dest_P = g_back_buffer_P;
			  UINT32   fl_size   = (GFX_MAX_W_LENGTH*GFX_MAX_H_LENGTH);
			  g_pDDSBack1->Unlock(NULL);
			  while(fl_size)
			  {
				 *fl_dest_P++ = *fl_src_P++;
				 fl_size--;
			  }
		   }
		 #ifdef DEBUG
		   else
		   {
              g_pDDSBack1->Blt(NULL, g_pDDSPrimary, NULL, DDBLT_WAITNOTBUSY, &ddbltfx);
		      while(g_pDDSBack1->GetBltStatus(DDGBS_ISBLTDONE) == DDERR_WASSTILLDRAWING);
			  printf("Precopy Failed\n");
		   }
		 #endif
	   #endif

       }
       else
       {
          /*
          ** No post copy required, so Flip backbuffer and frontbuffer
		  ** Wait until the flip finishes.
          */
          hRet = g_pDDSPrimary->Flip(g_pDDSBack1, DDFLIP_WAITVSYNC);
		  while(g_pDDSPrimary->GetFlipStatus(DDGFS_ISFLIPDONE) == DDERR_WASSTILLDRAWING);
       }
    }
#ifdef PRINT_METRICS
    dwETime = GetTickCount();
    printf("Flip Time = %d\n", (dwETime-dwSTime));
#endif
}

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
extern "C" void hmi_gfx_ddraw_distroy(void)
{
    if (g_pDDSBack1 != NULL)
    {
        g_pDDSBack1->Release();
        g_pDDSBack1 = NULL;
    }
#ifdef TRIPLE_BUFFERING
    if (g_pDDSBack2 != NULL)
    {
        g_pDDSBack2->Release();
        g_pDDSBack2 = NULL;
    }
#endif
    if (g_pDDSPrimary != NULL)
    {
        g_pDDSPrimary->Release();
        g_pDDSPrimary = NULL;
    }
    if (g_pDD != NULL)
    {
        g_pDD->Release();
        g_pDD = NULL;
    }
}

/*End of File*/
/*****************************************************************************
*   for each change to this file, be sure to record:                         *
*      1.  who made the change and when the change was made                  *
*      2.  why the change was made and the intended result                   *
*   Following block needs to be repeated for each change
******************************************************************************
*   Note: In the traceability column we need to trace back to the Design Doc.*
*   For the initial version it is traced to the Design Document section.     *
*   For further changes it shall trace to the source of the change which may *
*   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  *
*   other reason                                                            *
******************************************************************************/
/*---------------------------------------------------------------------------
Date              :
By                :
Traceability      :
Change Description:
-----------------------------------------------------------------------------*/
