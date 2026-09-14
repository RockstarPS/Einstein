#define WIN32

// L42P.cpp : Defines the entry point for the application.
//
#pragma comment (lib, "gdiplus.lib")
#include "stdafx.h"
#include "SimulMain.h"

#include <process.h>
#include <assert.h>
#include<stdio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
//#include <chrono>
//#include <thread>
#include <string>
#ifdef TEXT_AUTOMATION
#include <gdiplus.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

#endif
extern "C"
{
#include "iris_eng.h"
#include "stubfunctions.h"
#include "hmi_button.h"
#include "hmi_gfx_mgr02_cfg.h"
}

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

HANDLE WIN32_windowhandle;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

extern "C" void Simul_task(void);
extern "C" void Simul_taskGFX(void);

#ifdef TEXT_AUTOMATION

extern "C" int  IsLastSID();
extern "C" int  GetSIDIndex();
extern "C" const char* GetSIDName();
extern "C" const char* GetFolderName();
extern "C" void ChangeLanguage();
int currentSidIndex = 0;
int sidUpdateStarted = 0;
LPCSTR inputPath;
LPCSTR outputPath;

struct binary_data_t
{
  long size;
  void* data;
};

#endif


BOOL isRunning = 1;
HDC hDC;
HGLRC hGLRC;
HPALETTE hPalette;

void init(void)
{
}

extern "C" int GetEvent(int task, int* ev);

void redraw(void)
{
  ::SetWindowPos((HWND)WIN32_windowhandle, FALSE, 0, 0, GFX_MGR02_LAYERS_MAX_WIDTH, GFX_MGR02_LAYERS_MAX_HEIGHT,
    SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

  int ev;
  GetEvent(1, &ev);
  IrisEng_SetBrontesCtx();
  if (ev) Simul_taskGFX();

  try
  {
    IrisEng_DispCtrl_Draw();
  }
  catch (...)
  {
    assert("hoho");
  }

  SwapBuffers(hDC);
}

void setupPixelFormat(HDC hDC)
{
  PIXELFORMATDESCRIPTOR pfd = {
      sizeof(PIXELFORMATDESCRIPTOR),  /* size */
      1,                              /* version */
      PFD_SUPPORT_OPENGL |
      PFD_DRAW_TO_WINDOW |
      PFD_DOUBLEBUFFER,               /* support double-buffering */
      PFD_TYPE_RGBA,                  /* color type */
      16,                             /* prefered color depth */
      0, 0, 0, 0, 0, 0,               /* color bits (ignored) */
      0,                              /* no alpha buffer */
      0,                              /* alpha bits (ignored) */
      0,                              /* no accumulation buffer */
      0, 0, 0, 0,                     /* accum bits (ignored) */
      16,                             /* depth buffer */
      0,                              /* no stencil buffer */
      0,                              /* no auxiliary buffers */
      PFD_MAIN_PLANE,                 /* main layer */
      0,                              /* reserved */
      0, 0, 0,                        /* no layer, visible, damage masks */
  };
  int pixelFormat;

  pixelFormat = ChoosePixelFormat(hDC, &pfd);
  if (pixelFormat == 0) {
    MessageBox(WindowFromDC(hDC), "ChoosePixelFormat failed.", "Error",
      MB_ICONERROR | MB_OK);
    exit(1);
  }

  if (SetPixelFormat(hDC, pixelFormat, &pfd) != TRUE) {
    MessageBox(WindowFromDC(hDC), "SetPixelFormat failed.", "Error",
      MB_ICONERROR | MB_OK);
    exit(1);
  }
}

void setupPalette(HDC hDC)
{
  int pixelFormat = GetPixelFormat(hDC);
  PIXELFORMATDESCRIPTOR pfd;
  LOGPALETTE* pPal;
  int paletteSize;

  DescribePixelFormat(hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

  if (pfd.dwFlags & PFD_NEED_PALETTE) {
    paletteSize = 1 << pfd.cColorBits;
  }
  else {
    return;
  }

  pPal = (LOGPALETTE*)
    malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
  if (pPal != NULL)
  {
    pPal->palVersion = 0x300;
    pPal->palNumEntries = paletteSize;

    /* build a simple RGB color palette */
    int redMask = (1 << pfd.cRedBits) - 1;
    int greenMask = (1 << pfd.cGreenBits) - 1;
    int blueMask = (1 << pfd.cBlueBits) - 1;
    int i;

    for (i = 0; i < paletteSize; ++i) 
    {
      pPal->palPalEntry[i].peRed =
        (((i >> pfd.cRedShift) & redMask) * 255) / redMask;
      pPal->palPalEntry[i].peGreen =
        (((i >> pfd.cGreenShift) & greenMask) * 255) / greenMask;
      pPal->palPalEntry[i].peBlue =
        (((i >> pfd.cBlueShift) & blueMask) * 255) / blueMask;
      pPal->palPalEntry[i].peFlags = 0;
    }
    hPalette = CreatePalette(pPal);
    free(pPal);
  }

  if (hPalette)
  {
    SelectPalette(hDC, hPalette, FALSE);
    RealizePalette(hDC);
  }
}

#ifdef TEXT_AUTOMATION
/*!*********************************************************************************************************************
\return	binary_data_t	structure containing void* data of the file, and size of the data
\param	filename		name of the file to be loaded.
\brief	reads the binary file.
***********************************************************************************************************************/
binary_data_t* readBinaryFile(const char* filename)
{
  //Allocated our binary data structure
  binary_data_t* binary_data = (binary_data_t*)malloc(sizeof(binary_data_t));
  if (binary_data != NULL)
  {
    binary_data->size = 0;
    void* buffer = NULL;
    long position;
    //Open the file for reading in binary mode
    FILE* fIn = fopen(filename, "rb");

    if (fIn != NULL)
    {
      //Go to the end of the file
      const int fseek_end_value = fseek(fIn, 0, SEEK_END);
      if (fseek_end_value != -1)
      {
        //Get the current position in the file (in bytes)
        position = ftell(fIn);
        if (position != -1)
        {
          //Go back to the beginning of the file
          const int fseek_set_value = fseek(fIn, 0, SEEK_SET);
          if (fseek_set_value != -1)
          {
            //Allocate enough space to read the whole file
            buffer = malloc(position);
            if (buffer != NULL)
            {
              //Read the whole file to buffer
              const long size = fread(buffer, 1, position, fIn);

              if (size == position)
              {
                binary_data->size = position;
                binary_data->data = buffer;
                fclose(fIn);
                return binary_data;
              }
              free(buffer);
            }
          }
        }
      }
      fclose(fIn);
    }
    free(binary_data);
  }
  return NULL;
}


PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp)
{
  BITMAP bmp;
  PBITMAPINFO pbmi;
  WORD    cClrBits;

  // Retrieve the bitmap color format, width, and height.  
  if (!GetObject(hBmp, sizeof(BITMAP), (LPSTR)&bmp))
  {
    // errhandler("GetObject", hwnd);
  }

  // Convert the color format to a count of bits.  
  cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);
  if (cClrBits == 1)
    cClrBits = 1;
  else if (cClrBits <= 4)
    cClrBits = 4;
  else if (cClrBits <= 8)
    cClrBits = 8;
  else if (cClrBits <= 16)
    cClrBits = 16;
  else if (cClrBits <= 24)
    cClrBits = 24;
  else cClrBits = 32;

  // Allocate memory for the BITMAPINFO structure. (This structure  
  // contains a BITMAPINFOHEADER structure and an array of RGBQUAD  
  // data structures.)  

  if (cClrBits < 24)
    pbmi = (PBITMAPINFO)LocalAlloc(LPTR,
      sizeof(BITMAPINFOHEADER) +
      sizeof(RGBQUAD) * (1 << cClrBits));

  // There is no RGBQUAD array for these formats: 24-bit-per-pixel or 32-bit-per-pixel 

  else
    pbmi = (PBITMAPINFO)LocalAlloc(LPTR,
      sizeof(BITMAPINFOHEADER));

  // Initialize the fields in the BITMAPINFO structure.  
  if (pbmi != NULL)
  {
    pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pbmi->bmiHeader.biWidth = bmp.bmWidth;
    pbmi->bmiHeader.biHeight = bmp.bmHeight;
    pbmi->bmiHeader.biPlanes = bmp.bmPlanes;
    pbmi->bmiHeader.biBitCount = bmp.bmBitsPixel;
    if (cClrBits < 24)
      pbmi->bmiHeader.biClrUsed = (1 << cClrBits);

    // If the bitmap is not compressed, set the BI_RGB flag.  
    pbmi->bmiHeader.biCompression = BI_RGB;

    // Compute the number of bytes in the array of color  
    // indices and store the result in biSizeImage.  
    // The width must be DWORD aligned unless the bitmap is RLE 
    // compressed. 
    pbmi->bmiHeader.biSizeImage = ((pbmi->bmiHeader.biWidth * cClrBits + 31) & ~31) / 8
      * pbmi->bmiHeader.biHeight;
    // Set biClrImportant to 0, indicating that all of the  
    // device colors are important.  
    pbmi->bmiHeader.biClrImportant = 0;
  }
  return pbmi;
}

int CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi,
  HBITMAP hBMP, HDC hDC)
{
  HANDLE hf;                 // file handle  
  BITMAPFILEHEADER hdr;       // bitmap file-header  
  PBITMAPINFOHEADER pbih;     // bitmap info-header  
  LPBYTE lpBits;              // memory pointer  
  DWORD dwTotal;              // total count of bytes  
  DWORD cb;                   // incremental count of bytes  
  BYTE* hp;                   // byte pointer  
  DWORD dwTmp;

  pbih = (PBITMAPINFOHEADER)pbi;
  lpBits = (LPBYTE)GlobalAlloc(GMEM_FIXED, pbih->biSizeImage);


  // Retrieve the color table (RGBQUAD array) and the bits  
  // (array of palette indices) from the DIB.  
  if (!GetDIBits(hDC, hBMP, 0, (WORD)pbih->biHeight, lpBits, pbi,
    DIB_RGB_COLORS))
  {
    return -1;
  }

  // Create the .BMP file.  
  hf = CreateFile(pszFile,
    GENERIC_READ | GENERIC_WRITE,
    (DWORD)0,
    NULL,
    CREATE_ALWAYS,
    FILE_ATTRIBUTE_NORMAL,
    (HANDLE)NULL);
  if (hf == INVALID_HANDLE_VALUE)
  {
    return -1;
  }

  hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M"  
  // Compute the size of the entire file.  
  hdr.bfSize = (DWORD)(sizeof(BITMAPFILEHEADER) +
    pbih->biSize + pbih->biClrUsed
    * sizeof(RGBQUAD) + pbih->biSizeImage);
  hdr.bfReserved1 = 0;
  hdr.bfReserved2 = 0;

  // Compute the offset to the array of color indices.  
  hdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) +
    pbih->biSize + pbih->biClrUsed
    * sizeof(RGBQUAD);

  // Copy the BITMAPFILEHEADER into the .BMP file.  
  if (!WriteFile(hf, (LPVOID)&hdr, sizeof(BITMAPFILEHEADER),
    (LPDWORD)&dwTmp, NULL))
  {
    return -1;
  }

  // Copy the BITMAPINFOHEADER and RGBQUAD array into the file.  
  if (!WriteFile(hf, (LPVOID)pbih, sizeof(BITMAPINFOHEADER)
    + pbih->biClrUsed * sizeof(RGBQUAD),
    (LPDWORD)&dwTmp, (NULL)))
  {
    return -1;
  }

  // Copy the array of color indices into the .BMP file.  
  dwTotal = cb = pbih->biSizeImage;
  hp = lpBits;
  if (!WriteFile(hf, (LPSTR)hp, (int)cb, (LPDWORD)&dwTmp, NULL))
  {
    return -1;
  }

  // Close the .BMP file.  
  if (!CloseHandle(hf))
  {
    return -1;
  }

  // Free memory.  
  GlobalFree((HGLOBAL)lpBits);
  return 0;
}

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
  using namespace Gdiplus;
  UINT  num = 0;
  UINT  size = 0;

  ImageCodecInfo* pImageCodecInfo = NULL;

  GetImageEncodersSize(&num, &size);
  if (size == 0)
    return -1;

  pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
  if (pImageCodecInfo == NULL)
    return -1;

  GetImageEncoders(num, size, pImageCodecInfo);
  for (UINT j = 0; j < num; ++j)
  {
    if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
    {
      *pClsid = pImageCodecInfo[j].Clsid;
      free(pImageCodecInfo);
      return j;
    }
  }
  free(pImageCodecInfo);
  return 0;
}

void gdiscreen(string filename) {
  using namespace Gdiplus;
  IStream* istream;
  HRESULT res = CreateStreamOnHGlobal(NULL, true, &istream);
  GdiplusStartupInput gdiplusStartupInput;
  ULONG_PTR gdiplusToken;
  GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
  {
    HDC scrdc, memdc;
    HBITMAP membit;
    //scrdc = ::GetDC(0);
    scrdc = ::GetDC((HWND)WIN32_windowhandle);
    /*HDC hScreenDC = GetDC((HWND)WIN32_windowhandle);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);*/
    int Width = GFX_MGR02_LAYERS_MAX_WIDTH;
    int Height = GFX_MGR02_LAYERS_MAX_HEIGHT;
    memdc = CreateCompatibleDC(scrdc);
    membit = CreateCompatibleBitmap(scrdc, Width, Height);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(memdc, membit);
    BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);

    Gdiplus::Bitmap bitmap(membit, NULL);
    CLSID clsid;
    GetEncoderClsid(L"image/jpeg", &clsid);

    std::wstring widestr = std::wstring(filename.begin(), filename.end());
    const wchar_t* widecstr = widestr.c_str();
   	bitmap.Save(widecstr, &clsid, NULL); // To save the jpeg to a file
   // bitmap.Save(istream, &clsid, NULL);

    // Create a bitmap from the stream and save it to make sure the stream has the image
//		Gdiplus::Bitmap bmp(istream, NULL);
//		bmp.Save(L"t1est.jpeg", &clsid, NULL);             
    // END

    //delete& clsid;
    DeleteObject(memdc);
    DeleteObject(membit);
    ::ReleaseDC(0, scrdc);
  }
  GdiplusShutdown(gdiplusToken);
  istream->Release();
}
void saveScreenshot(string filename)
{
#if 0
  HDC hScreenDC = GetDC((HWND)WIN32_windowhandle);
  HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
  int width = GFX_MGR02_LAYERS_MAX_WIDTH;
  int height = GFX_MGR02_LAYERS_MAX_HEIGHT;
  // create a bitmap
  HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
  // SAVE OLD BITMAP
  HBITMAP hOldBitmap = static_cast<HBITMAP>(SelectObject(hMemoryDC, hBitmap));
  BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY);
  hBitmap = static_cast<HBITMAP>(SelectObject(hMemoryDC, hOldBitmap));
  PBITMAPINFO bmapInfo = CreateBitmapInfoStruct((HWND)WIN32_windowhandle, hBitmap);
  LPSTR fileName = const_cast<char*>(filename.c_str());
  int ret = CreateBMPFile((HWND)WIN32_windowhandle, fileName, bmapInfo, hBitmap, hScreenDC);
  // RESTORE OLD BITMAP
  SelectObject(hMemoryDC, hOldBitmap);
  DeleteDC(hMemoryDC);
  DeleteObject(hBitmap);
  // RELEASE WINDOW DC
  ReleaseDC((HWND)WIN32_windowhandle, hScreenDC);
#else
  gdiscreen(filename);
#endif
}
/*!*********************************************************************************************************************
\return	0 if images match
\brief	compares the latest saved screenshot with the reference sample screenshot and returns the result
***********************************************************************************************************************/
int compareScreenshots()
{
  binary_data_t* t1;
  binary_data_t* t2;

  string ip_path;
  string op_path;
  int index = 1;
  int counter = 0;
  int val = 0;
  string slash = "\\";
  string prefix = "file";
  std::ofstream outfile;
  const char* folderName = GetFolderName();
  outfile.open("TestingSIDSLog.txt", std::ofstream::out | std::ios_base::app);

  string ipfolder_path = inputPath + slash + folderName;
  for (const auto& entry : fs::directory_iterator(ipfolder_path))
  {
    counter++;
  }
  outfile << "\n  ================== COMPARING " << folderName << "=======================";
  for (index = 0; index < counter; index++)
  {

    ip_path = inputPath + slash + folderName + slash + prefix + std::to_string(index);
    ip_path.append(".png");
    op_path = outputPath + slash + folderName + slash + prefix + std::to_string(index);
    op_path.append(".png");

    t1 = readBinaryFile(ip_path.c_str());
    t2 = readBinaryFile(op_path.c_str());

    if (t1 == NULL || t2 == NULL)
    {
      outfile << "\nError message: Reference image not present\n";
      return -1;
    }

    val = memcmp(t1->data, t2->data, t1->size);
    if (val == 0)
    {
      outfile << "\nOutput message:" << index << "  " << ip_path << "  and  " << op_path << " images match\n";
    }
    else
    {
      outfile << "\nError  message:" << index << "  " << ip_path << "  and  " << op_path << " images do not match\n";
    }

    delete[](char*)(t1->data);
    delete[](char*)(t2->data);
  }

  outfile << "\n========================================================================================\n";
  return val;
}
#endif

int APIENTRY _tWinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR    lpCmdLine,
  int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);


#ifdef TEXT_AUTOMATION

  // Returns first token
  char* token = strtok(lpCmdLine, ",-");
  // Keep printing tokens while one of the
  // delimiters present in str[].
  int i = 0;
  while (token != NULL) {
    if (i == 0)
    {
      inputPath = token;
    }
    else
    {
      outputPath = token;
    }
    token = strtok(NULL, "-");
    i++;
  }
#endif

  // TODO: Place code here.
  MSG msg;
  HACCEL hAccelTable;

  // Initialize global strings
  LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
  LoadString(hInstance, IDC_L42P, szWindowClass, MAX_LOADSTRING);
  MyRegisterClass(hInstance);

  // Perform application initialization:
  if (!InitInstance(hInstance, nCmdShow))
  {
    return FALSE;
  }

  hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L42P));

  // Main message loop:
  while (isRunning)
  {
    while (PeekMessage(&msg, (HWND)WIN32_windowhandle, 0, 0, PM_REMOVE))
    {
      BOOL bGetResult = GetMessage(&msg, NULL, 0, 0);
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (bGetResult == 0)
        isRunning = false;
    }
    if (isRunning)
    {
      Simul_task();

      int ev;
      GetEvent(1, &ev);
      if (ev != 0) ::InvalidateRect((HWND)WIN32_windowhandle, 0, 0);

    }
  }

  return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
  WNDCLASSEX wcex;

  wcex.cbSize = sizeof(WNDCLASSEX);

  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L42P));
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = 0;
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

  return RegisterClassEx(&wcex);
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
  hInst = hInstance; // Store instance handle in our global variable

  WIN32_windowhandle = CreateWindow(szWindowClass, szTitle, WS_BORDER | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
    CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

  if (!WIN32_windowhandle)
  {
    return FALSE;
  }

  ShowWindow((HWND)WIN32_windowhandle, nCmdShow);
  UpdateWindow((HWND)WIN32_windowhandle);

  return TRUE;
}
extern "C"
{
#include "Rte_Type.h"
  extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State;
}
static char bButPressed = 0;
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
#ifdef TEXT_AUTOMATION
  string ip_path;
  string prefix = "file";
  string slash = "\\";
  int retVal = 1;
  if (sidUpdateStarted == 0)
  {
    ChangeLanguage();
    sidUpdateStarted = 1;
  }
#endif
  switch (message) {
  case WM_CREATE:
    /* initialize OpenGL rendering */
    hDC = GetDC(hWnd);
    setupPixelFormat(hDC);
    setupPalette(hDC);
    hGLRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hGLRC);
    IrisEng_Init();
    init();
    return 0;
  case WM_DESTROY:
    /* finish OpenGL rendering */
    if (hGLRC) {
      wglMakeCurrent(NULL, NULL);
      wglDeleteContext(hGLRC);
    }
    if (hPalette) {
      DeleteObject(hPalette);
    }
    ReleaseDC(hWnd, hDC);
    PostQuitMessage(0);
    isRunning = 0;
    return 0;
  case WM_PALETTECHANGED:
    /* realize palette if this is *not* the current window */
    if (hGLRC && hPalette && (HWND)wParam != hWnd) {
      UnrealizeObject(hPalette);
      SelectPalette(hDC, hPalette, FALSE);
      RealizePalette(hDC);
      //redraw();
      break;
    }
    break;
  case WM_QUERYNEWPALETTE:
    /* realize palette if this is the current window */
    if (hGLRC && hPalette) {
      UnrealizeObject(hPalette);
      SelectPalette(hDC, hPalette, FALSE);
      RealizePalette(hDC);
      //redraw();
      return TRUE;
    }
    break;
  case WM_PAINT:
  {
    PAINTSTRUCT ps;
    BeginPaint(hWnd, &ps);
    if (hGLRC) {
      redraw();
    }
    EndPaint(hWnd, &ps);
#ifdef TEXT_AUTOMATION
    if (sidUpdateStarted == 1)
    {
      int canChangeLanguage = IsLastSID();
      const char* folderName = GetFolderName();
      string input_str = std::string(inputPath);
      input_str.append(slash);
      input_str.append(folderName);
      CreateDirectory(input_str.c_str(), NULL);
#if 1
	    const char* sidName = GetSIDName();
      input_str.append(slash);
      input_str.append(sidName);
      ip_path = input_str;
      ip_path.append(".jpeg");
#else
      currentSidIndex = GetSIDIndex() - 1;
      ip_path = inputPath + slash + folderName + slash + prefix + std::to_string(sidIndex);
      ip_path.append(".png");
#endif
      saveScreenshot(ip_path);
      if (canChangeLanguage == TRUE)
      {
        retVal = compareScreenshots();
        ChangeLanguage();
      }
    }
#endif
    return 0;
  }
  break;
  case WM_KEYDOWN:
    switch ((int)wParam) {
    case 0x57: /*Key W*/
      hmi_close_menu();
      hmi_set_warning();
      break;
    case 0x43: /*Key C*/
      hmi_clear_warning();
      break;
    case 0x4D: /*Key M*/
      hmi_clear_warning();
      hmi_add_menu();
      break;
    case 0x4E: /*Key N*/
      hmi_close_menu();
      break;
    case 0x44: /*Key N*/
      hmi_toggle_mode();
      break;
    default:
      break;
    }
    break;
  case WM_KEYUP:
    break;
  case WM_CHAR:
    /* handle keyboard input */
    switch ((int)wParam) {
    case VK_ESCAPE:
      DestroyWindow(hWnd);
      return 0;
    default:
      break;
    }
    break;
  default:
    break;
  }
  return DefWindowProc(hWnd, message, wParam, lParam);
}

