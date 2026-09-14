// HMI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HMI.h"
#include <windows.h>
#include <commctrl.h>
#include <shellsdk.h>
#include "hmi_gfx_driver.h"
#include "hmi_gfx_interface.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE			g_hInst;			// current instance
HWND				g_hWndCommandBar;	// command bar handle

static HDC     l_hdcMem;
static HBITMAP l_hbmMem;
static HBITMAP l_hbmOld;

// Forward declarations of functions included in this code module:
ATOM			MyRegisterClass(HINSTANCE, LPTSTR);
BOOL			InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
static void Paint(HWND hWnd, LPPAINTSTRUCT lpPS);

extern "C" void process_task(void);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPTSTR    lpCmdLine,
                   int       nCmdShow)
{
	MSG msg;

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable;
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HMI));

	while(GetMessage(&msg, NULL, 0, 0))
	{
	    // Main message loop:
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
ATOM MyRegisterClass(HINSTANCE hInstance, LPTSTR szWindowClass)
{
	WNDCLASS wc;
	wc.style         = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = GetModuleHandle(NULL);//hInstance;
	wc.hIcon         = 0;//LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HMI));
	wc.hCursor       = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);//(HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = 0;
	wc.lpszClassName = L"HMI";
	return RegisterClass(&wc);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd;
    TCHAR szTitle[MAX_LOADSTRING];		// title bar text
    TCHAR szWindowClass[MAX_LOADSTRING];	// main window class name
    DWORD dwState;
    RECT  rc;
	HDC   hDC;
	BITMAPINFO   l_bmi;
	VOID * l_pvBits;

    g_hInst = hInstance; // Store instance handle in our global variable

#if 1
   GfxManagerInitialize();
   //GfxPresentationTask();
   //GfxManagerSendEvent(GFX_SCR_WELCOME, 1);
   //GfxManagerSendEvent(GFX_IMG_ANIM, 0);
   //GfxManagerBuildScreen(0);
#else

    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_HMI, szWindowClass, MAX_LOADSTRING);


    if (!MyRegisterClass(hInstance, L"HMI"/*szWindowClass*/))
    {
    	return FALSE;
    }

    hWnd = CreateWindow(L"HMI"/*szWindowClass*/, L"hmi"/*szTitle*/, WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    if (!hWnd)
    {
        return FALSE;
    }

   hDC = GetDC(hWnd);
   // Get the size of the client rectangle.
   GetClientRect(hWnd, &rc);
   // Create a bitmap big enough for our client rectangle.
#if 1
   ZeroMemory(&l_bmi, sizeof(BITMAPINFO));
   l_bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
   l_bmi.bmiHeader.biWidth       = GFX_MAX_W_LENGTH;
   l_bmi.bmiHeader.biHeight      = GFX_MAX_H_LENGTH;
   l_bmi.bmiHeader.biPlanes      = 1;
   l_bmi.bmiHeader.biBitCount    = 32;  /* four 8-bit components */
   l_bmi.bmiHeader.biCompression = BI_RGB;
   l_bmi.bmiHeader.biSizeImage   = GFX_MAX_W_LENGTH * GFX_MAX_H_LENGTH * 4;
   l_hbmMem    = CreateDIBSection(hDC, &l_bmi, DIB_RGB_COLORS, &l_pvBits, NULL, 0x00);
#else
   l_hbmMem = CreateCompatibleBitmap(hDC,
                                   rc.right-rc.left,
                                   rc.bottom-rc.top);
#endif
	dwState = (SHFS_HIDETASKBAR | SHFS_HIDESTARTICON | SHFS_HIDESIPBUTTON);
    SHFullScreen(hWnd, dwState);
    // Next resize the main window to the size of the screen.
    SetRect(&rc, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
    MoveWindow(hWnd, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, TRUE);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    if (g_hWndCommandBar)
    {
        CommandBar_Show(g_hWndCommandBar, TRUE);
    }
#endif

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
        case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
                case IDM_HELP_ABOUT:
                    DialogBox(g_hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, About);
                    break;
                case IDM_FILE_EXIT:
                    DestroyWindow(hWnd);
                    break;
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
        case WM_CREATE:
            g_hWndCommandBar = CommandBar_Create(g_hInst, hWnd, 1);
            CommandBar_InsertMenubar(g_hWndCommandBar, g_hInst, IDR_MENU, 0);
            CommandBar_AddAdornments(g_hWndCommandBar, 0, 0);
            break;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            Paint(hWnd, &ps);
            EndPaint(hWnd, &ps);
            break;
        case WM_DESTROY:
            CommandBar_Destroy(g_hWndCommandBar);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_INITDIALOG:
            RECT rectChild, rectParent;
            int DlgWidth, DlgHeight;	// dialog width and height in pixel units
            int NewPosX, NewPosY;

            // trying to center the About dialog
            if (GetWindowRect(hDlg, &rectChild))
            {
                GetClientRect(GetParent(hDlg), &rectParent);
                DlgWidth	= rectChild.right - rectChild.left;
                DlgHeight	= rectChild.bottom - rectChild.top ;
                NewPosX		= (rectParent.right - rectParent.left - DlgWidth) / 2;
                NewPosY		= (rectParent.bottom - rectParent.top - DlgHeight) / 2;

                // if the About box is larger than the physical screen
                if (NewPosX < 0) NewPosX = 0;
                if (NewPosY < 0) NewPosY = 0;
                SetWindowPos(hDlg, 0, NewPosX, NewPosY,
                    0, 0, SWP_NOZORDER | SWP_NOSIZE);
            }
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
            {
                EndDialog(hDlg, LOWORD(wParam));
                return TRUE;
            }
            break;

        case WM_CLOSE:
            EndDialog(hDlg, message);
            return TRUE;

    }
    return (INT_PTR)FALSE;
}

static void Paint(HWND hWnd, LPPAINTSTRUCT lpPS)
{
    RECT    rc;
    HBRUSH  hbrBkGnd;
    HDC     hdcMem;
    HBITMAP hbmOld;

    GetClientRect(hWnd, &rc);
	hdcMem = CreateCompatibleDC(lpPS->hdc);
    hbmOld = (HBITMAP)SelectObject(hdcMem, l_hbmMem);

    //
    // Erase the background.
    //
    hbrBkGnd = CreateSolidBrush(0xFF0000FF);//GetSysColor(COLOR_WINDOW));
    FillRect(hdcMem, &rc, hbrBkGnd);
    DeleteObject(hbrBkGnd);

    SetBkMode(hdcMem, TRANSPARENT);
    SetTextColor(hdcMem, GetSysColor(COLOR_WINDOWTEXT));
    DrawText(hdcMem,
             L"Test String",
             -1,
             &rc,
             DT_CENTER);


    BitBlt(lpPS->hdc,
           rc.left, rc.top,
           rc.right-rc.left, rc.bottom-rc.top,
           hdcMem,
           0, 0,
           SRCCOPY);
    SelectObject(hdcMem, hbmOld);
    DeleteDC(hdcMem);
}
