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

File Name        :  hmi_gfx_driver.c
Module Short Name:  Driver
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
#define HMI_GFX_DRIVER_C

/*****************************************************************************
*                                 System Includes                            *
******************************************************************************/

#include "stdafx.h"
#include "system.h"
#include "hmi_gfx_driver.h"
#include "hmi_gfx_interface.h"

#ifdef WINCE
  #include <shellsdk.h>
#endif

#ifdef USE_DDRAW
  #include "hmi_gfx_ddraw.h"
  #include <ddraw.h>
#endif

/*****************************************************************************
*                                 Project Includes                           *
******************************************************************************/

/*****************************************************************************
*                                 Manifest Constants                         *
*----------------------------------------------------------------------------*
* Definition of constant shall be followed by a comment that explains the    *
* purpose of the constant.                                                   *
******************************************************************************/
#define GFX_DRV_FB_EMPTY   0
#define GFX_DRV_FB_LOCKED  1

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#if NB_LAYERS > 1
  #error "This driver Supports only one layer.."
#endif

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef struct
{
  UINT8    b_open          : 1;
  UINT8    b_active        : 1;
  UINT8    b_update        : 1;
  UINT8    b_fb_copied     : 1;
  UINT8    b_work_fb_index : 1;
}GFX_DRIVER_LAYER_DATA_T;

typedef struct
{
  GFX_COLOR_T       * frame_buff_P;
  GFX_COLOR_T const * bmp_data_P;
  GFX_ALPHA_T const * alpha_data_P;
  GFX_SIZE_X_T        x;
  GFX_SIZE_Y_T        y;
  GFX_SIZE_W_T        w;
  GFX_SIZE_H_T        h;
  GFX_SIZE_W_T        w_offset;
}CLIP_IMAGE_DATA;

typedef struct
{
  GFX_SIZE_X_T        x;
  GFX_SIZE_Y_T        y;
  GFX_SIZE_W_T        w;
  GFX_SIZE_H_T        h;
}CLIP_FILLSCREEN_DATA;

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

static GFX_DRIVER_LAYER_DATA_T * l_working_layer_data_SP;
static GFX_DRIVER_LAYER_DATA_T   l_layer_data_S[NB_LAYERS];
static RECTANGLE_DEF_T           l_clip_area_S[1];

static HWND         l_hWnd;
static HDC          l_hdc;

static HDC          l_hdcMem;
static HBITMAP      l_hbmMem;
static HBITMAP      l_hbmOld;
static BITMAPINFO   l_bmi;           // bitmap header
static VOID       * l_pvBits;        // pointer to DIB section
static HGDIOBJ      l_hbmGdiObj;

static UINT32       l_fb_state = GFX_DRV_FB_EMPTY;

static DWORD        l_GtThreadID;
static HANDLE       l_GtThreadHandle;
static DWORD        l_PtThreadID;
static HANDLE       l_PtThreadHandle;
static BOOL         l_app_exit = FALSE;
static BOOL         l_button_pressed = FALSE;
#ifdef DEBUG
static UINT32     l_run_app  = 0;
#endif

/*****************************************************************************
*                              File Scope Prototypes                         *
******************************************************************************/

/*****************************************************************************
*                   Functions                                                *
******************************************************************************/

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
LRESULT CALLBACK GfxDriverWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  int wmId;
  int wmEvent;
#ifndef USE_DDRAW
    PAINTSTRUCT ps;
  HDC hdc;
#endif

  switch (message)
  {
  case WM_COMMAND:
    {
      wmId    = LOWORD(wParam);
      wmEvent = HIWORD(wParam);
      switch (wmId)
      {
      default:
        {
          return DefWindowProc(hWnd, message, wParam, lParam);
        }
      }
    }
    break;

  case WM_ERASEBKGND:
    {
      return (LRESULT)1;
    }

       #ifndef USE_DDRAW
  case WM_PAINT:
    {
      hdc = BeginPaint(hWnd, &ps);
      GfxDriverVSyncISR(hWnd, &ps);
      EndPaint(hWnd, &ps);
    }
    break;
       #endif
#if 0        
  case WM_DESTROY:
    {
      l_app_exit = TRUE;
      PostQuitMessage(0);
       #ifdef USE_DDRAW
      hmi_gfx_ddraw_distroy();
       #else
      DeleteDC(l_hdc);
      DeleteDC(l_hdcMem);
       #endif
      GfxManagerExit();
    }
    break;
#endif

  case WM_MOUSEMOVE:
    {
      if(l_button_pressed != FALSE)
      {
        GFX_TOUCH_QDATA fl_touch_data_SP;
        fl_touch_data_SP.x     = LOWORD(lParam);
        fl_touch_data_SP.y     = HIWORD(lParam);
        fl_touch_data_SP.event = GFX_MOUSE_MOVE_EV;
        GfxManagerPushTouchEvent(&fl_touch_data_SP);
      }
       #ifdef DEBUG
      l_run_app++;
       #endif
    }
    break;

  case WM_LBUTTONDOWN:
    {
      GFX_TOUCH_QDATA fl_touch_data_SP;
      fl_touch_data_SP.x     = LOWORD(lParam);
      fl_touch_data_SP.y     = HIWORD(lParam);
      fl_touch_data_SP.event = GFX_MOUSE_DOWN_EV;
      GfxManagerPushTouchEvent(&fl_touch_data_SP);
      l_button_pressed = TRUE;
       #ifdef DEBUG
      l_run_app = 0;
       #endif
    }
    break;

  case WM_LBUTTONUP:
    {
      if(l_button_pressed != FALSE)
      {
        GFX_TOUCH_QDATA fl_touch_data_SP;
        fl_touch_data_SP.x     = LOWORD(lParam);
        fl_touch_data_SP.y     = HIWORD(lParam);
        fl_touch_data_SP.event = GFX_MOUSE_UP_EV;
        GfxManagerPushTouchEvent(&fl_touch_data_SP);
        l_button_pressed = FALSE;
      }
       #ifdef DEBUG
      if(l_run_app > 50)
      {
        DestroyWindow(hWnd);
      }
       #endif
    }
    break;

  default:
    {
      return DefWindowProc(hWnd, message, wParam, lParam);
    }
  }
  return 0;
}

/*============================================================================
** Function Name:       TimerProc
** Description:         Timer tick.
** Invocation:          Executed every 33 mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
DWORD WINAPI GfxDriverBuilderTask(LPVOID lpvParam)
{
  while(l_app_exit == FALSE)
  {
    if(hmi_gfx_if_get_update_pending() && (l_fb_state == GFX_DRV_FB_EMPTY))
    {
      #ifdef PRINT_METRICS
      DWORD dwSTime;
      DWORD dwETime;
      dwSTime = GetTickCount();
      #endif
      Graphics_Task();
      #ifdef PRINT_METRICS
      dwETime = GetTickCount();
      printf("BT=%d\n", (dwETime-dwSTime));
      #endif
    }
    GfxManagerProcessTouchEvents();
    Sleep(16);
  }
  return(0);
}
/*============================================================================
** Function Name:       TimerProc
** Description:         Timer tick.
** Invocation:          Executed every 33 mSec
** Inputs/Outputs:
** Critical Section:    None
** Created:             15-SEP-2009 by EMANOJ1
** Updated:             15-SEP-2009 by EMANOJ1
**==========================================================================*/
DWORD WINAPI GfxDriverPresentationTask(LPVOID lpvParam)
{
#ifdef PRINT_METRICS
  static DWORD dwOldTime;
  static BOOL  first = TRUE;
  DWORD dwExecutionTime;

  if(first)
  {
    dwOldTime= GetTickCount();
    first = FALSE;
  }
#endif

  while(l_app_exit == FALSE)
  {
   #ifdef PRINT_METRICS
    dwExecutionTime  = GetTickCount();
    dwExecutionTime -= dwOldTime;
    dwOldTime        = GetTickCount();
    printf("PR=%d\n", dwExecutionTime);
   #endif
    GfxPresentationTask();
    Sleep(33);
  }
  return(0);
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
void GfxDriverInitialize(void)
{
  RECT     rc;
  WNDCLASS wc;
  BOOL     init_ok = TRUE;

  wc.style         = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc   = GfxDriverWndProc;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = 0;
  wc.hInstance     = GetModuleHandle(NULL);
  wc.hIcon         = 0;
  wc.hCursor       = 0;
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
  wc.lpszMenuName  = 0;
  wc.lpszClassName = L"HMI";
  RegisterClass(&wc);

  l_hWnd = FindWindow(L"HMI", L"hmi");

  if(l_hWnd == NULL)
  {
    l_hWnd = CreateWindow(L"HMI",
      L"hmi",
      WS_VISIBLE,
      CW_USEDEFAULT,
      0,
      CW_USEDEFAULT,
      0,
      NULL,
      NULL,
      NULL,
      NULL);
  }

  if(l_hWnd)
  {
   #if defined(GFX_FULLSCREEN) && defined(WINCE)
    /*
    ** Activate fullscreen mode by default.
    */
    DWORD dwState;
    dwState = (SHFS_HIDETASKBAR | SHFS_HIDESTARTICON | SHFS_HIDESIPBUTTON);
    SHFullScreen(l_hWnd, dwState);
   #endif

    /*
    ** Resize the main window to the size of the screen.
    */
   #ifdef WINCE
    SetRect(&rc, 0, 0, GFX_MAX_W_LENGTH, GFX_MAX_H_LENGTH);
   #else
    SetRect(&rc, 0, 0, GFX_MAX_W_LENGTH+50, GFX_MAX_H_LENGTH+50);
   #endif
    MoveWindow(l_hWnd, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, TRUE);

   #ifndef USE_DDRAW
    l_hdc = GetDC(l_hWnd);
    GetClientRect(l_hWnd, &rc);

    ZeroMemory(&l_bmi, sizeof(BITMAPINFO));

    l_bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    l_bmi.bmiHeader.biWidth       = GFX_MAX_W_LENGTH;
    l_bmi.bmiHeader.biHeight      = GFX_MAX_H_LENGTH;
    l_bmi.bmiHeader.biPlanes      = 1;
    l_bmi.bmiHeader.biBitCount    = 32;  /* four 8-bit components */
    l_bmi.bmiHeader.biCompression = BI_RGB;
    l_bmi.bmiHeader.biSizeImage   = GFX_MAX_W_LENGTH * GFX_MAX_H_LENGTH * 4;
    l_hbmMem    = CreateDIBSection(l_hdc, &l_bmi, DIB_RGB_COLORS, &l_pvBits, NULL, 0x00);
    l_hdcMem    = CreateCompatibleDC(l_hdc);
    l_hbmGdiObj = SelectObject(l_hdcMem, l_hbmMem);
   #else
    if(hmi_gfx_ddraw_init(l_hWnd) != DD_OK)
    {
      init_ok = FALSE;
    }
   #endif
    ShowCursor(FALSE);
    ShowWindow(l_hWnd, SW_SHOWNORMAL);
    UpdateWindow(l_hWnd);

    if(init_ok != FALSE)
    {
      l_GtThreadHandle = CreateThread( NULL,                   // CE Security
        0,                      // Default Size
        GfxDriverBuilderTask,   // Thread Entry
        NULL,                   // No Parameters
        0,                      // No Flags
        &l_GtThreadID);         // Thread Id
      #ifdef WINCE
      CeSetThreadPriority(l_GtThreadHandle, 200);               // higher priority for rendering thread
      #endif

      l_PtThreadHandle = CreateThread( NULL,                        // CE Security
        0,                           // Default Size
        GfxDriverPresentationTask,   // Thread Entry
        NULL,                        // No Parameters
        0,                           // No Flags
        &l_PtThreadID);              // Thread Id
      #ifdef WINCE
      CeSetThreadPriority(l_PtThreadHandle, 210);
      #endif
    }
  }
}

/****************************************************************************
Function Name        : void GfxDriverBeginUpdate(UINT8 p_lid_U8){}
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverBeginUpdate(void)
{
  RECTANGLE_DEF_T  fl_clip_area_SP;
  GFX_DRV_ENV_INFO fl_drv_context_S;

  fl_drv_context_S.hdc       = l_hdcMem;
#ifdef USE_DDRAW
  fl_drv_context_S.fb_P      = hmi_gfx_ddraw_get_backbuffer();
  fl_drv_context_S.fb_format = (UINT8)hmi_gfx_ddraw_get_fb_pix_format();
#else
  fl_drv_context_S.fb_P      = l_pvBits;
  fl_drv_context_S.fb_format = GFX_ARGB8888;
#endif
  fl_drv_context_S.fb_w      = GFX_MAX_W_LENGTH;
  fl_drv_context_S.fb_h      = GFX_MAX_H_LENGTH;

  GfxDriverSetEnv(&fl_drv_context_S);

  fl_clip_area_SP.x = 0;
  fl_clip_area_SP.y = 0;
  fl_clip_area_SP.w = GFX_MAX_W_LENGTH;
  fl_clip_area_SP.h = GFX_MAX_H_LENGTH;
  GfxDriverSetClipArea(&fl_clip_area_SP);
}
/****************************************************************************
Function Name        : UINT8 GfxDriverCheckBusyStatus(UINT8 p_lid_U8){}
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
UINT8 GfxDriverCheckBusyStatus(void)
{
  if(l_hWnd == 0)
  {
    return(TRUE);
  }
  else
  {
    return(FALSE);
  }
}

/****************************************************************************
Function Name        : void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8){}
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverEndUpdate(UINT8 p_post_copy_flag_U8)
{
#ifdef USE_DDRAW
  hmi_gfx_ddraw_flip(p_post_copy_flag_U8);
#else
  l_fb_state = GFX_DRV_FB_LOCKED;
  if(l_hWnd != 0)
  {
    InvalidateRect(l_hWnd, NULL, FALSE);
  }
#endif
}

#ifndef USE_DDRAW
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Parameters           :
Return Value         :
Critical Section     :
External Interfaces  :
******************************************************************************/
void GfxDriverVSyncISR(HWND hWnd, LPPAINTSTRUCT lpPS)
{
  RECT    rc;
  if((l_hWnd != 0) && (l_hWnd == hWnd))
  {
    if(l_fb_state != GFX_DRV_FB_EMPTY)
    {
      DWORD dwSTime;
      DWORD dwETime;

      dwSTime = GetTickCount();
      GetClientRect(l_hWnd, &rc);
      BitBlt(lpPS->hdc,
        rc.left, rc.top,
        rc.right-rc.left, rc.bottom-rc.top,
        l_hdcMem,
        0, 0,
        SRCCOPY);
      l_fb_state = GFX_DRV_FB_EMPTY;
      dwETime = GetTickCount();
    #ifdef PRINT_METRICS
      printf("ST=%d\n", (dwETime-dwSTime));
    #endif
    }
  }
}
#endif

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

