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

File Name        :  hmi_gfx_wince_driver.c
Module Short Name:  
VOBName          :  sw_hmi_ss
Author           :  abalaji
Description      :  Graphics Driver w/ OpenVG support for Windows CE 6.0 target

Organization     :  Visteon Corporation
List the compiler name with the ersion number
List the Target processor with the variant information
----------------------------------------------------------------------------
Compiler Name    :  
Target Processor :  
******************************************************************************/

#define HMI_GFX_WINCE_DRIVER_C

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "windows.h"
#include <winuser.h>
#include <strsafe.h>

#include "hmi_gfx_wince_driver.cfg"

#include "VG/openvg.h"
#include "VG/vgu.h"
#include "EGL/egl.h"

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

static EGLDisplay     egldisplay;
static EGLConfig      eglconfig;
static EGLSurface     eglsurface;
static EGLContext     eglcontext;
static VGubyte        vgInitialized, vgRefresh;
static HWND       window;

#ifdef TASKBAR_HIDE
static HWND taskBarHWnd;
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
static void GfxHandleEglError(const char *name)
{
  EGLint error_code;
  error_code=eglGetError();
  exit(EXIT_FAILURE);
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

void GfxOvgInit(NativeWindowType window)
{
  int errorcode=0;
  EGLint numconfigs;

  const EGLint s_configAttribsVG[] =
  {
    EGL_RED_SIZE,       GFX_VG_RED_SIZE,
    EGL_GREEN_SIZE,     GFX_VG_GREEN_SIZE,
    EGL_BLUE_SIZE,      GFX_VG_BLUE_SIZE,
    EGL_ALPHA_SIZE,     GFX_VG_ALPHA_SIZE,
    EGL_DEPTH_SIZE,     GFX_VG_COLOR_DEPTH,
    EGL_STENCIL_SIZE,   GFX_VG_STENCIL_SIZE,
    EGL_LUMINANCE_SIZE, GFX_VG_LUMINANCE_SIZE,
    EGL_SURFACE_TYPE,   GFX_VG_SURFACE_TYPE,
    EGL_NONE
  };

  egldisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
  eglInitialize(egldisplay, NULL, NULL);
  assert(eglGetError() == EGL_SUCCESS);
  eglBindAPI(EGL_OPENVG_API);

  eglChooseConfig(egldisplay, s_configAttribsVG, &eglconfig, 1, &numconfigs);
  assert(eglGetError() == EGL_SUCCESS);
  assert(numconfigs == 1);
  eglsurface = eglCreateWindowSurface(egldisplay, eglconfig, window , NULL);
  assert(eglGetError() == EGL_SUCCESS);

  eglcontext = eglCreateContext(egldisplay, eglconfig, NULL, NULL);
  assert(eglGetError() == EGL_SUCCESS);
  eglMakeCurrent(egldisplay, eglsurface, eglsurface, eglcontext);
  assert(eglGetError() == EGL_SUCCESS);
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
void GfxOvgDeinit(void)
{
  eglMakeCurrent(egldisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
  assert(eglGetError() == EGL_SUCCESS);
  eglTerminate(egldisplay);
  assert(eglGetError() == EGL_SUCCESS);
  eglReleaseThread();
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
void GfxOvgRefresh(void)
{
  vgRefresh = TRUE;
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

void GfxWinPaint(void)
{
  float clearColor[4] = {0,0,0,0};

  if(vgInitialized == FALSE)
  {
    vgSetfv(VG_CLEAR_COLOR, 4, clearColor);
    /* clear both the front and back buffers */
    vgClear(0, 0, GFX_VG_SCREEN_WIDTH, GFX_VG_SCREEN_HEIGHT);
    vgFinish();

    eglSwapBuffers(egldisplay, eglsurface);
    vgClear(0, 0, GFX_VG_SCREEN_WIDTH, GFX_VG_SCREEN_HEIGHT);
    vgFinish();
    vgInitialized = TRUE;
    GFX_VG_APP_INIT();
  }
  else if (vgRefresh == TRUE)
  {
    /* It seems to reduce performance*/
    vgFinish();
#ifdef VG_SURFACE_BG_COPY
    GFX_VG_REQ_FB_BG_COPY();
#endif
    eglSwapBuffers(egldisplay, eglsurface);
    vgRefresh = FALSE;
  }
  else
  {
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

static LONG WINAPI windowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  VGint WinX, WinY;

  switch (uMsg)
  {
  case WM_CLOSE:
  case WM_DESTROY:
    {
      PostQuitMessage(0);
      GfxOvgDeinit();
    }
    return 0;

  case WM_PAINT:
    {
      GFX_VG_APP_EXECUTE();
      GfxWinPaint();
    }
    return 0;

#ifdef MOUSE_SUPPORT
  case WM_LBUTTONDOWN:
    {
      SetCapture(hWnd);
      WinX = LOWORD(lParam);
      WinY = HIWORD(lParam);
      GFX_WIN_LMOUSE_DOWN(WinX, WinY);
    }
    return 0;

  case WM_LBUTTONUP:
    {
      ReleaseCapture();
      WinX = LOWORD(lParam);
      WinY = HIWORD(lParam);
      GFX_WIN_LMOUSE_UP(WinX, WinY);
    }
    return 0;

  case WM_MOUSEMOVE:
    {
      WinX = LOWORD(lParam);
      WinY = HIWORD(lParam);
      if (wParam & MK_LBUTTON)
      {
        GFX_WIN_MOUSE_MOVE(WinX, WinY);
      }
    }
    return 0;

  case WM_RBUTTONDOWN:
    return 0;

  case WM_RBUTTONUP:
    return 0;
#endif

  case WM_TIMER:
    return 0;

#ifdef KEYBOARD_SUPPORT
  case WM_KEYDOWN:
  case WM_KEYUP:
    return 0;
#endif

  default:
    break;
  }
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
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

void GfxErrorExit(LPTSTR lpszFunction)
{
  /* get last system error code/message */
  LPVOID lpMsgBuf;
  LPVOID lpDispBuf;
  DWORD dw = GetLastError();

  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    dw,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR) &lpMsgBuf,
    0, NULL );

  /* display error and exit the process */
  lpDispBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
    (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
  StringCchPrintf((LPTSTR)lpDispBuf, 
    LocalSize(lpDispBuf) / sizeof(TCHAR),
    TEXT("%s failed with error %d: %s"), 
    lpszFunction, dw, lpMsgBuf);
  MessageBox(NULL, (LPCTSTR)lpDispBuf, TEXT("Error"), MB_OK);

  LocalFree(lpMsgBuf);
  LocalFree(lpDispBuf);
  ExitProcess(dw);

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

int WINAPI WinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR     lpCmdLine,
  int       nCmdShow)
{
  BOOL bRet;
  MSG msg;

  vgInitialized = FALSE;
  vgRefresh     = FALSE;

  {
    WNDCLASS wndclass;
    wndclass.style       = 0;
    wndclass.lpfnWndProc   = windowProc;
    wndclass.cbClsExtra    = 0;
    wndclass.cbWndExtra    = 0;
    wndclass.hInstance     = (HINSTANCE)GetModuleHandle(NULL);
    wndclass.hIcon       = NULL;
    wndclass.hCursor     = NULL;
    wndclass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wndclass.lpszMenuName  = NULL;
    wndclass.lpszClassName = "hmi";
    RegisterClass(&wndclass);
  }

  window = CreateWindow(
    "hmi",
    TEXT("hmi"),
    WS_VISIBLE,
    CW_USEDEFAULT, CW_USEDEFAULT, GFX_VG_SCREEN_WIDTH, GFX_VG_SCREEN_HEIGHT,
    NULL,
    NULL,
    (HINSTANCE)GetModuleHandle(NULL),
    NULL);

  if (!window)
  {
    GfxErrorExit("GetProcessId");
    return -1;
  }

#ifdef TASKBAR_HIDE
  /* hide the task bar */
  taskBarHWnd = FindWindow(TEXT("HHTaskBar"), NULL);
  ShowWindow(taskBarHWnd, SW_HIDE);
#endif
  /* init openvg surface */
  GfxOvgInit((NativeWindowType)window);

  ShowWindow(window, SW_SHOW);
  EnableWindow(window, TRUE);

  /* application runs here */
  while (bRet = GetMessage(&msg, NULL, 0, 0))
  {
    if(bRet == -1)
    {
      break;
    }
    else
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  GfxOvgDeinit();
  DestroyWindow(window);
  return 0;
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
  Date              : 11/29/2010
  By                : abalaji
  Traceability      : Initial version
  Change Description: WinCE graphics driver with OpenVG support
  -----------------------------------------------------------------------------*/
