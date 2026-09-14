/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2008. Visteon Corporation owns all rights to this work and
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
** Name:           hmi_simulation_tick.c
**
** Description:    This file is the main entry point for the kepler HMI simulation
**                 framework. This does the necessary initialization and creates
**                 threads to run application and display window.
**
** Organization:   Driver Information Software Section,
**                 DI Core Engineering Department
**
**============================================================================
**
**==========================================================================*/
#define HMI_SIMULATION_TICK_C

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <windows.h>
#include "hmi_simulation_tick.h"

/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define SWAP_MSB_AND_LSB

#define BLINK_ACTIVE_OFF  (0)
#define BLINK_ACTIVE_ON   (1)
#define BLINK_INACTIVE    (2)

#define GSIM_WINDOW_RESIZE_MSG_ID (0x5A)
#define GSIM_WINDOW_DATA_MSG_ID   (0xA5)

HWND     ghWnd=NULL;
HDC      ghDC;
HGLRC    ghRC;

LONG WINAPI MainWndProc (HWND, UINT, WPARAM, LPARAM);
BOOL bSetupPixelFormat(HDC);


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

/*============================================================================
** M E M O R Y   A L L O C A T I O N
**==========================================================================*/

UINT16 l_system_tick_U16 = 0;
static volatile UINT8 l_tick_flag_U8 = 0;
unsigned l_cur_x;
unsigned l_cur_y;
unsigned l_max_x;
unsigned l_max_y;

#define MAX_LAYERS_TO_SUPPORT   (4)

typedef struct
{
   lcdtype        layer_color_depth;
   unsigned char  zoom_factor;
   unsigned char  layer_alpha;
   unsigned short lx;
   unsigned short ly;
   unsigned short lw;
   unsigned short lh;
   unsigned *     fb;
   unsigned short datax;
   unsigned short datay;
}GlsLayer;

static unsigned char     num_layers   = 0;
static GlsLayer        * gls_layer[MAX_LAYERS_TO_SUPPORT] = {0,0,0,0};

/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** Function Name:       TimerProc
** Description:         Timer tick.
** Invocation:          Executed every HMI_SIMUL_TICK_MSEC mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
   l_system_tick_U16++;
   //call the vblank isr
}

/*============================================================================
** Function Name:       glsTimerProc
** Description:         Timer tick to periodically refresh TFT.
** Invocation:          Executed every HMI_SIMUL_TICK_MSEC mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
VOID CALLBACK glsTimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
   gls_update_lcd();
}

/*============================================================================
**
** Function Name:       gls_update_lcd
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
void gls_update_lcd(void)
{
   InvalidateRect(ghWnd, NULL, FALSE);
}

/*============================================================================
**
** Function Name:       DrawPixels
** Visibility:          global.
** Description:         Blends the framebuffer in to the simulation window
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             13/Jan/11 by EMANOJ1
** Updated:             13/Jan/11 by EMANOJ1
**==========================================================================*/
void DrawPixels(HWND hWnd, HDC hdcwnd)
{
    HDC           hdc;           // handle of the DC we will create
    BLENDFUNCTION bf;            // structure for alpha blending
    HBITMAP       hbitmap;       // bitmap handle
    BITMAPINFO    bmi;           // bitmap header
    VOID        * pvBits;        // pointer to DIB section
    ULONG         ulWindowWidth, ulWindowHeight;      // window width/height
    ULONG         ulBitmapWidth, ulBitmapHeight;      // bitmap width/height
    RECT          rt;            // used for getting window dimensions
    UINT32        x, y;          // stepping variables
    UCHAR         ubAlpha;       // used for doing transparent gradient
    UCHAR         ubRed;
    UCHAR         ubGreen;
    UCHAR         ubBlue;
    float         fAlphaFactor;  // used to do premultiply
    UINT32        color;
	int           i;

    if(num_layers <= 0)
	{
	   return;
	}

    // get window dimensions
    GetClientRect(hWnd, &rt);

    // calculate window width/height
    ulWindowWidth  = rt.right  - rt.left;
    ulWindowHeight = rt.bottom - rt.top;

    // make sure we have at least some window size
    if ((!ulWindowWidth) || (!ulWindowHeight))
    {
       return;
    }

    // create a DC for our bitmap -- the source DC for AlphaBlend
    hdc = CreateCompatibleDC(hdcwnd);

    // zero the memory for the bitmap info
    ZeroMemory(&bmi, sizeof(BITMAPINFO));

    // setup bitmap info
    ulBitmapWidth  = ulWindowWidth;
    ulBitmapHeight = ulWindowHeight;
    ulBitmapWidth  = gls_layer[0]->lw;
    ulBitmapHeight = gls_layer[0]->lh;
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = ulBitmapWidth;
    bmi.bmiHeader.biHeight      = ulBitmapHeight;
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;         // four 8-bit components
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage   = ulBitmapWidth * ulBitmapHeight * 4;

    // create our DIB section and select the bitmap into the dc
    hbitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, &pvBits, NULL, 0x0);
    SelectObject(hdc, hbitmap);

    for (y = 0; y < ulBitmapHeight; y++)
    {
       for (x = 0; x < ulBitmapWidth; x++)
       {
          color =  gls_layer[0]->fb[x + y * ulBitmapWidth];
          color = ((UINT8)(color >> 16))  | (((UINT8)color)<<16) | (color & 0x0000FF00);
          ((UINT32 *)pvBits)[x + y * ulBitmapWidth] = color|0xFF000000;
       }
    }

    bf.BlendOp             = AC_SRC_OVER;
    bf.BlendFlags          = 0;
    bf.SourceConstantAlpha = 0xFf;
    bf.AlphaFormat         = 0;

    AlphaBlend(hdcwnd,
               0,             0,
               ulBitmapWidth, ulBitmapHeight,
               hdc,
               0,             0,
               ulBitmapWidth, ulBitmapHeight,
               bf);

    DeleteObject(hbitmap);
    DeleteDC(hdc);
}

/*============================================================================
**
** Function Name:       MainWndProc
** Visibility:          global.
** Description:         main window procedure.
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
LONG WINAPI MainWndProc (HWND    hWnd, UINT    uMsg, WPARAM  wParam, LPARAM  lParam)
{
   LONG         lRet = 1;
   PAINTSTRUCT  ps;
   RECT         rect;

   switch (uMsg)
   {
   case WM_CREATE:
      {
         ghDC = GetDC(hWnd);
         if (!bSetupPixelFormat(ghDC))
         {
            PostQuitMessage (0);
         }
      }
      break;

   case WM_PAINT:
      {
         HDC hwndc = BeginPaint(hWnd, &ps);
         DrawPixels(hWnd, hwndc);
         EndPaint(hWnd, &ps);
         lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
      }
      break;

   case WM_SIZE:
      {
      }
      break;

   case WM_CLOSE:
      {
         if (ghDC)
         {
            ReleaseDC(ghWnd, ghDC);
            ghRC = 0;
            ghDC = 0;
         }
         DestroyWindow (ghWnd);
      }
      break;

   case WM_DESTROY:
      {
         if(ghDC)
         {
            ReleaseDC(ghWnd, ghDC);
         }
         PostQuitMessage (0);
      }
      break;

   default:
      {
         lRet = DefWindowProc (hWnd, uMsg, wParam, lParam);
      }
      break;
   }
   return lRet;
}

/*============================================================================
**
** Function Name:       bSetupPixelFormat
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
BOOL bSetupPixelFormat(HDC hdc)
{
   PIXELFORMATDESCRIPTOR pfd, *ppfd;
   int pixelformat;

   ppfd = &pfd;

   ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
   ppfd->nVersion = 1;
   ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
      PFD_DOUBLEBUFFER;
   ppfd->dwLayerMask = PFD_MAIN_PLANE;
   ppfd->iPixelType = PFD_TYPE_COLORINDEX;
   ppfd->cColorBits = 8;
   ppfd->cDepthBits = 16;
   ppfd->cAccumBits = 0;
   ppfd->cStencilBits = 0;

   pixelformat = ChoosePixelFormat(hdc, ppfd);

   if ( (pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0 )
   {
      MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
      return FALSE;
   }

   if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE)
   {
      MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
      return FALSE;
   }

   return TRUE;
}

/*============================================================================
**
** Function Name:       DestroyLcdWindow
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             26/Aug/10 by TVIJAYAS
** Updated:             26/Aug/10 by TVIJAYAS
**==========================================================================*/
void DestroyLcdWindow(void)
{
   int i;
   ghWnd = FindWindow("GDTSimWinClass", "GDTSimWindow");
   if(ghWnd != NULL)
   {
     DestroyWindow(ghWnd);
     UnregisterClass("GDTSimWinClass",GetModuleHandle(NULL));
   }
   for(i=0; i<MAX_LAYERS_TO_SUPPORT; i++)
   {
      if(gls_layer[i])
	  {
          free(gls_layer[i]->fb);
          free(gls_layer[i]);
	  }
   }
}
/*============================================================================
**
** Function Name:       gls_init
** Visibility:          global.
** Description:         .
** Invocation:          .
** Inputs/Outputs:      .
** Critical Section:
** Created:             11/Dec/09 by EMANOJ1
** Updated:             11/Dec/09 by EMANOJ1
**==========================================================================*/
static void gls_init(int zoom)
{
   RECT       rect;
   MSG        msg;
   WNDCLASS   wndclass;
   LPWNDCLASS wndclassinfo = NULL;

   ghWnd = FindWindow("GDTSimWinClass", "GDTSimWindow");
   if(ghWnd != NULL)
   {
       return;
   }

   /* Register the frame class */
   wndclass.style         = 0;
   wndclass.lpfnWndProc   = (WNDPROC)MainWndProc;
   wndclass.cbClsExtra    = 0;
   wndclass.cbWndExtra    = 0;
   wndclass.hInstance     = GetModuleHandle(NULL);
   wndclass.hIcon         = LoadIcon (GetModuleHandle(NULL), "GDTSimWinClass");
   wndclass.hCursor       = LoadCursor (NULL,IDC_ARROW);
   wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
   wndclass.lpszMenuName  = "GDTSimWinClass";
   wndclass.lpszClassName = "GDTSimWinClass";


   if(!GetClassInfo(GetModuleHandle(NULL),"GDTSimWinClass",wndclassinfo))
   {
      if (!RegisterClass (&wndclass) )
      {
        return FALSE;
      }
   }

   /* Create the frame */
   ghWnd = CreateWindow ("GDTSimWinClass",
                         "GDTSimWindow",
                         0,
                         CW_USEDEFAULT,
                         CW_USEDEFAULT,
						 gls_layer[0]->lw,
						 gls_layer[0]->lh,
                         NULL,
                         NULL,
                         GetModuleHandle(NULL),
                         NULL);
   /* make sure window was created */
   if (!ghWnd)
   {
      printf("Simulation window creation failed, exiting gls_init.\n");
      return;
   }
   GetClientRect(ghWnd, &rect);
   if(gls_layer[0]->lw > rect.right)
   {
      rect.right = (gls_layer[0]->lw-rect.right);
   }
   else
   {
      rect.right = 0;
   }
   rect.right += gls_layer[0]->lw;
   if(gls_layer[0]->lh > rect.bottom)
   {
      rect.bottom = (gls_layer[0]->lh-rect.bottom);
   }
   else
   {
      rect.bottom = 0;
   }
   rect.bottom += gls_layer[0]->lh;
   MoveWindow(ghWnd,rect.left, rect.top, rect.right, rect.bottom, TRUE);

   /* show and update main window */
   ShowWindow (ghWnd, 1);
   UpdateWindow (ghWnd);

   gls_update_lcd();
   /*Start the timer to schedule the DCU interrupt*/
   SetTimer(NULL, 0, HMI_SIMUL_TICK_MSEC, TimerProc);
 #ifdef HMI_SIM_UPDATE_LCD_PERIODIC
   SetTimer(NULL, 0, HMI_SIMUL_TICK_MSEC, glsTimerProc);
 #endif
}

int gls_set_layer_alpha(int handle, unsigned char layer_alpha)
{
   if(handle < MAX_LAYERS_TO_SUPPORT)
   {
      gls_layer[num_layers]->layer_alpha = layer_alpha;
      return handle;
   }
   else
   {
      return -1;
   }
}

int gls_add_layer(unsigned char layer_alpha, unsigned int width, unsigned int height, unsigned char zoom)
{
   zoom = 1; // default to 1
   if(num_layers < MAX_LAYERS_TO_SUPPORT && zoom)
   {
      gls_layer[num_layers] = (void *)malloc(sizeof(GlsLayer));
      gls_layer[num_layers]->layer_color_depth = GLS_ARGB8888;
      gls_layer[num_layers]->layer_alpha       = layer_alpha;
      gls_layer[num_layers]->lx                = 0;
      gls_layer[num_layers]->ly                = 0;
      gls_layer[num_layers]->lw                = width;
      gls_layer[num_layers]->lh                = height;
      gls_layer[num_layers]->datax             = 0;
      gls_layer[num_layers]->datay             = 0;
      gls_layer[num_layers]->fb                = (unsigned *)malloc(width * height * zoom * zoom * sizeof(unsigned));
      gls_layer[num_layers]->zoom_factor       = zoom;
	  if(num_layers == 0)
	  {
	     gls_init(zoom);
	  }
      num_layers++;
      return(num_layers-1);
   }
   else
   {
      return -1;
   }
}

int gls_set_layer_xy(int handle, unsigned int x, unsigned int y)
{
    if(handle < MAX_LAYERS_TO_SUPPORT)
    {
        gls_layer[handle]->lx = x;
        gls_layer[handle]->ly = y;
        return 0;
    }
    else
    {
        return -1;
    }
}
int gls_set_pixel_xy(int handle, unsigned int x, unsigned int y)
{
    if(handle < MAX_LAYERS_TO_SUPPORT)
    {
        gls_layer[handle]->datax = x;
        gls_layer[handle]->datay = y;
        return 0;
    }
    else
    {
        return -1;
    }
}

int gls_fb_write(int handle, unsigned color)
{
    if(handle < MAX_LAYERS_TO_SUPPORT)
    {
        gls_fb_write_xy(handle, gls_layer[handle]->datax, gls_layer[handle]->datay, color);
        gls_layer[handle]->datax++;
        if(gls_layer[handle]->datax >= gls_layer[handle]->lw)
        {
            gls_layer[handle]->datax = 0;
            gls_layer[handle]->datay++;
            if(gls_layer[handle]->datay >= gls_layer[handle]->lh)
            {
               gls_layer[handle]->datay = 0;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int gls_fb_write_xy(int handle, unsigned int x, unsigned int y, unsigned color)
{
   if(handle < MAX_LAYERS_TO_SUPPORT)
   {
      if(x < gls_layer[handle]->lw && y < gls_layer[handle]->lh)
	  {
		 y = gls_layer[handle]->lh-(y+1);
         gls_layer[handle]->fb[(y*gls_layer[handle]->lw)+x] = color;
		 return 0;
	  }
   }
   return -1;
}

void glib_Dmac_Trans(UINT8 ch, T_DMAC_TRANS *fl_dma_tfr_S)
{
   while(fl_dma_tfr_S->count)
   {
      *fl_dma_tfr_S->dst_adr++ = *fl_dma_tfr_S->src_adr++;
      fl_dma_tfr_S->count--;
   }
}

void glib_Dmac_Trans_FixedSource(UINT8 ch, T_DMAC_TRANS *fl_dma_tfr_S)
{
   while(fl_dma_tfr_S->count)
   {
      *fl_dma_tfr_S->dst_adr++ = *fl_dma_tfr_S->src_adr;
      fl_dma_tfr_S->count--;
   }
}

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
** Rev 1.0         15-SEP-2009   EMANOJ1
** Creation
**
** Rev 1.1         23-SEP-2009   EMANOJ1
** All the image copy functions updated to properly clip the off screen portion
** of the image and to coorrectly display the tiling.
** Implemented the Cursor display and Cursor Blinking
**
** Rev 1.2         14-JULY-2010   tvijayas
** Removed all thread implementation to avoid matlab crashing when stopped and
** started again. used seperate LCD app simulator.removed GLUT usage.
**

**==========================================================================*/

/*

This simulation Uses the GLUT Win32:-

COPYRIGHT:

The OpenGL Utility Toolkit distribution for Win32 (Windows NT &
Windows 95) contains source code modified from the original source
code for GLUT version 3.3 which was developed by Mark J. Kilgard.  The
original source code for GLUT is Copyright 1997 by Mark J. Kilgard.
GLUT for Win32 is Copyright 1997 by Nate Robins and is not in the
public domain, but it is freely distributable without licensing fees.
It is provided without guarantee or warrantee expressed or implied.
It was ported with the permission of Mark J. Kilgard by Nate Robins.

THIS SOURCE CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OR MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

OpenGL (R) is a registered trademark of Silicon Graphics, Inc.
*/

/* end of file =============================================================*/
