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
 ** Name:           hmi_gfx_mgr02_ogllib.c
 **
 ** Description:    OpenGL library interface routines to perform drawing 
 **                 operations for graphics manager 02.
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
#define GUI_GFX_MANAGER_OGLLIB_C
#define HMI_GFX_MGR02_PRIV_C

/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "hmi_gfx_mgr02_layout.h"
#if defined(GFX_MGR02_OPEN_GL)
#include "hmi_gfx_mgr02_generic.h"
#include "hmi_gfx_mgr02_dirty_area.h"
#include "hmi_gfx_mgr02_ogllib.h"
#include "hmi_gfx_mgr02_context.h"
#include "hmi_gfx_mgr02_text.h"
#include "hmi_gfx_mgr02_cache.h"
#if defined(GFX_MGR02_USE_FILESYSTEM)
 #include <stdio.h>
#endif
#if defined(WIN32)
   #include <winuser.h>
   #include <windows.h>
   #include <WinDef.h>
#endif
#ifdef OGL_DIRECT_TEXTURE_RENDERING
typedef void(*PFN_GLTEXDIRECTVIVMAP_PROC)(GLenum p_target, GLsizei p_width, GLsizei p_height, GLenum p_format, GLvoid** p_logical, const GLuint* p_physical);
typedef void (*PFN_GLTEXDIRECTINVALIDATEVIV_PROC)(UINT32);
PFN_GLTEXDIRECTVIVMAP_PROC l_gl_TexDirectVIVMap_Fptr;
PFN_GLTEXDIRECTINVALIDATEVIV_PROC l_gl_TexDirectInvalidateVIV_Fptr;
BOOLEAN l_gl_TexDirectVIV_done;
#endif
#ifdef  __cplusplus
extern "C" {
#endif
/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/

#define GM2_GCFR(argb) (((GFX_FLOAT)(((argb) >> 16) & 0xFF))/255.0f)
#define GM2_GCFG(argb) (((GFX_FLOAT)(((argb) >>  8) & 0xFF))/255.0f)
#define GM2_GCFB(argb) (((GFX_FLOAT)(((argb) >>  0) & 0xFF))/255.0f)
#define GM2_GCFA(argb) (((GFX_FLOAT)(((argb) >> 24) & 0xFF))/255.0f)

#define GFX_MGR02_OGLLIB_FLUSH_PENDING  (0x01)
#define GFX_MGR02_OGLLIB_FB_UPDATED     (0x02)
#define GFX_MGR02_TEXTURE_ID_FREE       (0xFFFFFFFFu) 
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
 #define PRECISION 16
 #define ONE       (1 << PRECISION)
 #define ZERO      0
 #define N_ELEMENTS(_array) (sizeof(_array) / sizeof(_array[0]))
 #define INT2FIXED(value)   ((value) << PRECISION)
#endif

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/
static void hmi_gfx_mgr02_ogllib_util_matrix_operation(GFX_MGR02_CONTEXT_T const * p_cntx_SP);
static void hmi_gfx_mgr02_ogllib_util_matrix_mul(GFX_FLOAT const * m1, GFX_FLOAT * m2);
static void hmi_gfx_mgr02_ogllib_util_matrix_translate(GFX_FLOAT * m2, GFX_FLOAT tx, GFX_FLOAT ty);
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
static void hmi_gfx_mgr02_ogllib_create_img_for_string(UINT8 *p_str_img_SP, GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
                                                       GFX_MGR02_TEXT_INFO const * p_text_info_S,GFX_MGR02_FONT const * p_font_SP);
#endif
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
static UINT8 hmi_gfx_mgr02_ogllib_CheckFramebufferStatus();
#endif

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
static UINT8        l_ogllib_draw_sts;
static SINT32       l_ogllib_clip_rect[4];

/*
** TODO : EGL and init sequence to be moved to context.c later
*/
typedef struct
{
   EGLDisplay          Display;
   EGLConfig           Config;
   EGLSurface          Surface;
   EGLContext          Context;
   EGLNativeWindowType NativeWindow;
   NativeDisplayType   NativeDisplay;
   /*
   ** TODO : These needs to be moved to a shared context later
   */
   void const        * CurTexData;
   GLuint              CurTexId;
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
   GLuint              VxBuffObject;
   GLuint              fillProgramObject; 
   GLuint              ArgbimgProgramObject;
   GLuint              RgbimgProgramObject;
   GLuint              txtProgramObject;
   GLuint              blurProgramObject;
 #if defined(GFX_MGR02_DIRTY_REGION_REDRAW) && defined(GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND)
   GLuint              fboCopyProgramObject;
 #endif
#endif
}GFX_MGR02_OGL_CONTEXT;

static GFX_MGR02_OGL_CONTEXT l_ogl_egl_context_S;

#define VERTEX_ARRAY   0
#define TEXCOORD_ARRAY 1

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
static GFX_FLOAT ovg_idty_matrx[9] =
{
   1.0f, 0.0f,  0.0f,
   0.0f, 1.0f,  0.0f,
   0.0f, 0.0f,  1.0f
};
static GFX_FLOAT pfIdentity[16] =
{
   1.0f, 0.0f, 0.0f, 0.0f,
   0.0f, 1.0f, 0.0f, 0.0f,
   0.0f, 0.0f, 1.0f, 0.0f,
   0.0f, 0.0f, 0.0f, 1.0f
};
static GLshort l_texture_vertex[20] = 
{ 
   /* vertex      tex-coord*/
   -1, 1, 0,        0, 0,
    1, 1, 0,        1, 0,
   -1,-1, 0,        0, 1,
    1,-1, 0,        1, 1
};
#else
static GFX_FLOAT ovg_idty_matrx[9] =
{
   1.0f, 0.0f,  0.0f,
   0.0f, 0.0f,  0.0f,
  -1.0f, 1.0f,  1.0f
};

static GFX_FLOAT pfIdentity[16] =
{
   1.0f, 0.0f, 0.0f, 0.0f,
   0.0f, 0.0f, 0.0f, 0.0f,
   0.0f, 0.0f, 1.0f, 0.0f,
  -1.0f, 1.0f, 0.0f, 1.0f
};
static GFX_FLOAT l_texture_vertex[20] = 
{ 
   /* vertex      tex-coord*/
    0, 0, 0,        0, 0,
    0, 0, 0,        1, 0,
    0, 0, 0,        0, 1,
    0, 0, 0,        1, 1
};
#endif

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
/*
** Fragment and vertex shaders code for fill screen
*/
char const * const fillFragShaderCode =
"uniform highp  vec4  fillColor;"
"void main (void)"
"{"
"  gl_FragColor = fillColor;"
"}";

char const * const fillVertShaderCode =
"attribute highp vec4    inVertex;"
"uniform mediump mat4    MVPMatrix;"
"void main(void)"
"{"
"   gl_Position = MVPMatrix * inVertex;"
"}";

/*
** Fragment and vertex shaders code for image screen
*/
char const * const imgVertShaderCode =
"attribute vec4 a_position;"
"attribute vec4 tpos;"
"varying   vec2 v_texCoord;"
"uniform mediump mat4 MVPMatrix;"
"void main(void)"
"{"
"   gl_Position = MVPMatrix * a_position;"
"   v_texCoord  = tpos.st;"
"}";

/*
** The images are stored as ARGB where as OpenGL needs it as RGBA
** So conversion is in-corporated in shader
*/
char const * const ARGBimgFragShaderCode =
"precision mediump float;"
"varying vec2      v_texCoord;"
"uniform sampler2D s_texture;"
"uniform highp  float Alpha;"
"void main(void)"
"{"
"vec4  fragColor;"
"fragColor = texture2D(s_texture, v_texCoord);"
"gl_FragColor = vec4(fragColor.r,fragColor.g,fragColor.b,fragColor.a * Alpha);"
"}";

#if defined(GFX_MGR02_DIRTY_REGION_REDRAW) && defined(GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND)
/*
** In the freescale i.mx6 linux platform, the blending of planes is achived via
** color keying where every color with r=1, g=2, b = 3 is considered transparant
** This caused the video bleed through GUI layer if any of the GUI layer pixel
** value matches this color key value. This shader is to remove any color keys
** from GUI layer, so that there is no bleeding of video
*/
char const * const FboimgFragShaderCode =
"precision mediump float;"
"varying vec2      v_texCoord;"
"uniform sampler2D s_texture;"
"uniform highp  float Alpha;"
"void main(void)"
"{"
"gl_FragColor = texture2D(s_texture, v_texCoord);"
"if(gl_FragColor.r <= (1.5/255.0))"
"{"
"gl_FragColor.r = 0.0;"
"}"
"}";
#endif

char const * const RGBimgFragShaderCode =
"precision mediump float;"
"varying vec2      v_texCoord;"
"uniform sampler2D s_texture;"
"uniform highp  float Alpha;"
"void main(void)"
"{"
"gl_FragColor = texture2D(s_texture, v_texCoord);"
"gl_FragColor.a = (gl_FragColor.a * Alpha);"
"}";

/*
** Fragment and vertex shaders code for Text
*/
char const * const txtVertShaderCode =
"attribute vec4 a_position;"
"attribute vec4 tpos;"
"varying   vec2 v_texCoord;"
"uniform mediump mat4 MVPMatrix;"
"void main(void)"
"{"
"   gl_Position = MVPMatrix * a_position;"
"   v_texCoord  = tpos.st;"
"}";

char const * const txtFragShaderCode =
"precision mediump float;"
"varying vec2      v_texCoord;"
"uniform highp  vec4  fgColor;"
"uniform sampler2D s_texture;"
"uniform highp  float Alpha;"
"void main(void)"
"{"
"gl_FragColor = fgColor * texture2D(s_texture, v_texCoord).a;"
"gl_FragColor.a = (gl_FragColor.a * Alpha);"
"}";
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
char const * const blurVertShaderCode =
"attribute vec4 a_position;"
"attribute vec2 a_texCoord;"
"varying vec2 v_texCoord;"
"void main()"
"{"
"   gl_Position = a_position;"
"   v_texCoord = a_texCoord;"
"}";
char const * const blurFragShaderCode =
"precision mediump float;"
"uniform sampler2D texture;"  
"varying highp vec2 v_texCoord;"
"uniform vec2 textureSize;"
"uniform mat4 kernel_data[30];"
"uniform float kernel_radius;"
"vec4 clampedSample(vec2 coord)"
"{"
"   if(any(lessThan(coord, vec2(0.0))))"
"   {"
"       return vec4(0.0);"
"   }"
"   else if(any(greaterThan(coord, vec2(1.0))))"
"   {"
"       return vec4(0.0);"
"   }"
"   else"
"   {"
"       return texture2D(texture, coord);"
"   }"
"}"
"void main()" 
"{"
"    highp float xv = 1.0/textureSize.x;"
"    highp float yv = 1.0/textureSize.y;"
"    vec4 fontcolor = clampedSample(v_texCoord);"
"    highp vec4 glowvalue = vec4(0.0);"
"    float intensity = 1.7;"    
"    {"
"        float loopx =0.0;"
"        float loopy =0.0;"
"        float fullsize = kernel_radius*2.0-1.0;"
"        float offset = float(int(fullsize/2.0));"
"        highp float maxlength = length(vec2(fullsize*xv,fullsize*yv));"
"        float left_top_size = kernel_radius;"
"        for(loopx = 0.0; loopx < fullsize; loopx+=1.0)"
"        {"
"            for(loopy = 0.0; loopy < fullsize; loopy+=1.0)"
"            {"
"                float x = (left_top_size-1.0)-abs(loopx-(left_top_size-1.0));"
"                float y = (left_top_size-1.0)-abs(loopy-(left_top_size-1.0));"
"                highp vec2 samplecoord = vec2((loopx-offset)*xv, (loopy-offset)*yv);"
"                float maxv = max(x,y);"
"                float minv = min(x,y);"
"                int index = int( (maxv * (maxv+1.0) / 2.0) + minv );"
"               int matrix_index = index/16;"
"               int element_row_index = int(mod(float(index),16.0)/4.0);"
"               int element_column_index = int(mod(mod(float(index),16.0),4.0));"
"               mat4 matrix;"
"               matrix = kernel_data[matrix_index];"
"               float weight = 1.0;"
"               weight = matrix[element_row_index][element_column_index];"
"               glowvalue = glowvalue + weight * clampedSample(v_texCoord+samplecoord);"
"            }"
"        }"
"    }"   
"   gl_FragColor = vec4(fontcolor + glowvalue * intensity );"
"}";
#endif //#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
#endif

/*
** Specify the required configuration attributes.
** An EGL "configuration" describes the pixel format and type of
** surfaces that can be used for drawing.
** For now we just want to use the default Windows surface,
** i.e. it will be visible on screen. The list
** has to contain key/value pairs, terminated with EGL_NONE.
*/
EGLint const pi32ConfigAttribs[] =
{
    EGL_RED_SIZE,       8,
    EGL_GREEN_SIZE,     8,
    EGL_BLUE_SIZE,      8,
    EGL_ALPHA_SIZE,     EGL_DONT_CARE,
    EGL_DEPTH_SIZE,     16,
    EGL_STENCIL_SIZE,   EGL_DONT_CARE,
#ifdef EGL_VERSION_1_4
    EGL_SURFACE_TYPE,   (EGL_WINDOW_BIT|EGL_SWAP_BEHAVIOR_PRESERVED_BIT),
#else
    EGL_SURFACE_TYPE,   EGL_WINDOW_BIT,
#endif
    EGL_RENDERABLE_TYPE,EGL_OPENGL_ES_BIT,
    EGL_NONE
};

SINT32    iConfigs;
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
EGLint ai32ContextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
#elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
EGLint ai32ContextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 1, EGL_NONE };
#else
#endif
GLint  bShaderCompiled;
GLint  bLinked;

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
 typedef struct
 {
    GLint  ColorAttachmentId;
    GLuint width;
    GLuint height;
 }GFX_MGR02_FBO;
 typedef struct
 {
    GLuint    radius;
    GLfloat * kernel_data;
 }GFX_MGR02_BLUR;
#endif

#ifndef GFX_MGR02_MAX_IMG_TEXTURES
 #define GFX_MGR02_MAX_IMG_TEXTURES 1
#endif

#ifndef GFX_MGR02_MAX_TEXT_TEXTURES
 #define GFX_MGR02_MAX_TEXT_TEXTURES 1
#endif

#ifndef GFX_MGR02_MAX_CHAR_TEXTURES
 #define GFX_MGR02_MAX_CHAR_TEXTURES 1
#endif


#define GFX_MGR02_MAX_TEX_LIVE 254

GFX_MGR02_TEXTURE l_gees11_img_texture[GFX_MGR02_MAX_IMG_TEXTURES];
GFX_MGR02_TEXTURE l_gees11_text_texture[GFX_MGR02_MAX_TEXT_TEXTURES];
HMI_CHAR          l_gees11_text_cache_buffer[GFX_MGR02_MAX_TEXT_TEXTURES][GFX_MGR02_MAX_TEXT_LENGTH];

#if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
 #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
  /*
  ** Offscreen rendering with framebuffer object
  */
  GLuint l_offscr_framebuf;
 #ifdef GFX02_ENABLE_DEPTH_BUFFER
  GLuint l_offscr_depthrdrbuf;
 #endif
  GLuint l_offscr_texture;
  static GFX_FLOAT l_offscr_tex_vertex[20] = 
  { 
     /* vertex      tex-coord*/
      0, 0, 0,        0, 1,
      1, 0, 0,        1, 1,
      0,-1, 0,        0, 0,
      1,-1, 0,        1, 0
  };
 #endif
#endif

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/

#if defined(WIN32)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
#if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
   static UINT8 l_button_pressed = FALSE;
#endif
   switch (message)
   {
      case WM_CLOSE:
      {
         PostQuitMessage(0);
      }
      return 1;
   #if GFX_MGR02_TOUCH_SCREEN_ENABLED > 0
      case WM_MOUSEMOVE:
      {
         if(l_button_pressed != FALSE)
         {
            GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
            fl_touch_data_SP.x     = LOWORD(lParam);
            fl_touch_data_SP.y     = HIWORD(lParam);
            fl_touch_data_SP.event = GFX_MGR02_MOUSE_MOVE_EV;
            hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP,0);
         }
      }
      break;

      case WM_LBUTTONDOWN:
      {
         GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
         fl_touch_data_SP.x     = LOWORD(lParam);
         fl_touch_data_SP.y     = HIWORD(lParam);
         fl_touch_data_SP.event = GFX_MGR02_MOUSE_DOWN_EV;
         hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP,0);
         l_button_pressed = TRUE;
      }
      break;

      case WM_LBUTTONUP:
      {
         if(l_button_pressed != FALSE)
         {
            GFX_MGR02_TOUCH_QDATA fl_touch_data_SP;
            fl_touch_data_SP.x     = LOWORD(lParam);
            fl_touch_data_SP.y     = HIWORD(lParam);
            fl_touch_data_SP.event = GFX_MGR02_MOUSE_UP_EV;
            hmi_gfx_mgr02_layout_push_touch_event(&fl_touch_data_SP,0);
            l_button_pressed = FALSE;
         }
      }
      break;
   #endif
      default:
      {
    	  /*For MISRA warning fix.*/
      }
      break;
   }
   return DefWindowProc(hWnd, message, wParam, lParam);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
EGLNativeWindowType CreateNativeWindow(SINT32 width, SINT32 height)
{
   // Register the windows class
   WNDCLASS     sWC;
   ATOM         registerClass;
   HWND         hWnd = 0;

   sWC.style         = CS_HREDRAW | CS_VREDRAW;
   sWC.lpfnWndProc   = WndProc;
   sWC.cbClsExtra    = 0;
   sWC.cbWndExtra    = 0;
   sWC.hInstance     = GetModuleHandle(NULL);
   sWC.hIcon         = 0;
   sWC.hCursor       = 0;
   sWC.lpszMenuName  = 0;
   sWC.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
   sWC.lpszClassName = _T("GDTSimWindowCN");
   registerClass     = RegisterClass(&sWC);
   if (registerClass)
   {
      RECT  sRect;
      // Create the eglWindow
      SetRect(&sRect, 0, 0, width, height);
      AdjustWindowRectEx(&sRect, WS_TILEDWINDOW, FALSE, 0);
	  hWnd = CreateWindow( _T("GDTSimWindowCN"), _T("GDT"), WS_VISIBLE|WS_SYSMENU|WS_MAXIMIZE|WS_TILEDWINDOW,
		  0, 0, (sRect.right-sRect.left), (sRect.bottom-sRect.top), NULL, NULL, GetModuleHandle(NULL), NULL);
   }
   return(hWnd);
}
#endif /* #if defined(WIN32) */

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_fbo_init
Description          : Initializes the off screen texture buffer
Invocation           : Invoked internally
Parameters           : height and width of the texture to be created for off
                       screen drawing
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_fbo_init(UINT32 p_twidth, UINT32 p_theight)
{
   GLint fl_max_rbuff_size;

   l_offscr_framebuf    = 0;
#ifdef GFX02_ENABLE_DEPTH_BUFFER
   l_offscr_depthrdrbuf = 0;
#endif
   l_offscr_texture     = 0;

#ifdef EGL_VERSION_1_4
   if(eglSurfaceAttrib(l_ogl_egl_context_S.Display, 
                       l_ogl_egl_context_S.Surface, 
                       EGL_SWAP_BEHAVIOR, 
                       EGL_BUFFER_PRESERVED) != EGL_TRUE)
#endif
   {
      /*
	  ** Create FBO only if the EGL doesnot support EGL_BUFFER_PRESERVED
	  */
      l_offscr_tex_vertex[5]  = (GFX_FLOAT)(p_twidth);
      l_offscr_tex_vertex[11] = (GFX_FLOAT)(p_theight);
      l_offscr_tex_vertex[15] = (GFX_FLOAT)(p_twidth);
      l_offscr_tex_vertex[16] = (GFX_FLOAT)(p_theight);

      glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &fl_max_rbuff_size);
      if((fl_max_rbuff_size >= (GLint)p_twidth) && (fl_max_rbuff_size >= (GLint)p_theight))
      {
         glGenFramebuffers(1, &l_offscr_framebuf);
      #ifdef GFX02_ENABLE_DEPTH_BUFFER
         glGenRenderbuffers(1, &l_offscr_depthrdrbuf);
      #endif
         glGenTextures(1, &l_offscr_texture);
         glBindTexture(GL_TEXTURE_2D, l_offscr_texture);
         glTexImage2D(GL_TEXTURE_2D, 
                      0, 
                      GL_RGBA, 
                      p_twidth, 
                      p_theight,
                      0, 
                      GL_RGBA, 
                      GL_UNSIGNED_BYTE, 
                      NULL);

         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      #ifdef GFX02_ENABLE_DEPTH_BUFFER
         glBindRenderbuffer(GL_RENDERBUFFER, l_offscr_depthrdrbuf);
         glRenderbufferStorage(GL_RENDERBUFFER, 
                               GL_DEPTH_COMPONENT16,
                               p_twidth, 
                               p_theight);
      #endif
      }
   }
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_fbo_shutdown
Description          : releases all resource created for off screen drawing
Invocation           : Invoked internally
Parameters           : None
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_fbo_shutdown(void)
{
#ifdef GFX02_ENABLE_DEPTH_BUFFER
   if(l_offscr_depthrdrbuf != 0)
   {
      glDeleteRenderbuffers(1, &l_offscr_depthrdrbuf);
   }
#endif
   if(l_offscr_framebuf != 0)
   {
      glDeleteFramebuffers(1, &l_offscr_framebuf);
   }
   if(l_offscr_texture != 0)
   {
      glDeleteTextures(1, &l_offscr_texture);
   }
   l_offscr_framebuf    = 0;
#ifdef GFX02_ENABLE_DEPTH_BUFFER
   l_offscr_depthrdrbuf = 0;
#endif
   l_offscr_texture     = 0;
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_fbo_start
Description          : Sets up the offscreen texture for drawing operation
Invocation           : Invoked internally
Parameters           : None
Return Value         : Returns GL_FRAMEBUFFER_COMPLETE on success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GLenum hmi_gfx_mgr02_ogllib_fbo_start(void)
{
   GLenum fl_status = GL_FRAMEBUFFER_UNSUPPORTED;
   if((l_offscr_framebuf    != 0) &&
    #ifdef GFX02_ENABLE_DEPTH_BUFFER
      (l_offscr_depthrdrbuf != 0) && 
    #endif
      (l_offscr_texture     != 0))
   {
      glBindFramebuffer(GL_FRAMEBUFFER, l_offscr_framebuf);
      glFramebufferTexture2D(GL_FRAMEBUFFER, 
                             GL_COLOR_ATTACHMENT0,
                             GL_TEXTURE_2D, 
                             l_offscr_texture, 
                             0);
   #ifdef GFX02_ENABLE_DEPTH_BUFFER
      glFramebufferRenderbuffer(GL_FRAMEBUFFER, 
                                GL_DEPTH_ATTACHMENT,
                                GL_RENDERBUFFER, 
                                l_offscr_depthrdrbuf);
   #endif
      /*
      ** fl_status = GL_FRAMEBUFFER_COMPLETE if success
      */
      fl_status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
   }
   return(fl_status);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_fbo_start
Description          : Maps the offscreen texture to window for display
Invocation           : Invoked internally
Parameters           : None
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_fbo_finish(void)
{
   if((l_offscr_framebuf    != 0) &&
    #ifdef GFX02_ENABLE_DEPTH_BUFFER 
      (l_offscr_depthrdrbuf != 0) && 
    #endif
      (l_offscr_texture     != 0))
   {
      GLuint fl_location;
      GLuint fl_program;
      
      glDisable(GL_BLEND);
      glDisable(GL_SCISSOR_TEST);
      glBindFramebuffer(GL_FRAMEBUFFER, 0);
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D, l_offscr_texture);

      pfIdentity[0]  = ovg_idty_matrx[0];
      pfIdentity[1]  = ovg_idty_matrx[1];
      pfIdentity[3]  = ovg_idty_matrx[2];
      pfIdentity[4]  = ovg_idty_matrx[3];
      pfIdentity[5]  = ovg_idty_matrx[4];
      pfIdentity[7]  = ovg_idty_matrx[5];
      pfIdentity[12] = ovg_idty_matrx[6];
      pfIdentity[13] = ovg_idty_matrx[7];
      pfIdentity[15] = ovg_idty_matrx[8];

   #if defined(GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND)
      fl_program = l_ogl_egl_context_S.fboCopyProgramObject;
   #else
      fl_program = l_ogl_egl_context_S.ArgbimgProgramObject;
   #endif

      glUseProgram(fl_program);

      fl_location = glGetUniformLocation(fl_program, "MVPMatrix");
      glUniformMatrix4fv(fl_location, 1, GL_FALSE, pfIdentity);

      fl_location = glGetUniformLocation(fl_program, "s_texture");
      glUniform1i(fl_location, 0);
   
      glBufferData(GL_ARRAY_BUFFER, 4*5*sizeof(GLfloat), l_offscr_tex_vertex, GL_STATIC_DRAW);
      fl_location = glGetAttribLocation(fl_program, "a_position");
      glEnableVertexAttribArray(fl_location);
      glVertexAttribPointer(fl_location, 
                            3, 
                            GL_FLOAT, 
                            GL_FALSE, 
                            (5 * sizeof(GLfloat)), 
                            0);
      fl_location = glGetAttribLocation(fl_program, "tpos");
      glEnableVertexAttribArray(fl_location);
      glVertexAttribPointer(fl_location, 
                            2, 
                            GL_FLOAT, 
                            GL_FALSE, 
                            (5 * sizeof(GLfloat)), 
                            (void*)(3 * sizeof(GLfloat)));
   #if !defined(GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND)
      fl_location = glGetUniformLocation(fl_program, "Alpha");
      glUniform1f(fl_location, 1.0f);
   #endif

      glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
      l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
   }
}
#endif /* #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && defined(GFX_MGR02_DIRTY_REGION_REDRAW) */

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_init(void)
{
   UINT32                i;
   UINT32             fl_width  = 64;
   UINT32             fl_height = 64;
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
   GLuint             FragShader;
   GLuint             VertShader;
   l_ogl_egl_context_S.CurTexData = 0;
#endif
//   memset(l_gees11_char_texture, 0, (sizeof(GFX_MGR02_TEXTURE)*GFX_MGR02_MAX_CHAR_TEXTURES));
   hmi_gfx_mgr02_cache_init();
   memset(l_gees11_img_texture, 0, (sizeof(GFX_MGR02_TEXTURE)*GFX_MGR02_MAX_IMG_TEXTURES));

   memset(l_gees11_text_texture, 0, (sizeof(GFX_MGR02_TEXTURE)*GFX_MGR02_MAX_TEXT_TEXTURES));
   memset(l_gees11_text_cache_buffer, 0, (sizeof(HMI_CHAR)*GFX_MGR02_MAX_TEXT_TEXTURES*30));

#ifdef OGL_DIRECT_TEXTURE_RENDERING
   l_gl_TexDirectVIVMap_Fptr           = NULL;
   l_gl_TexDirectInvalidateVIV_Fptr    = NULL;
   l_gl_TexDirectVIV_done              = FALSE;
#endif
   for(i=0; i < GFX_MGR02_MAX_IMG_TEXTURES; i++)
   {
      l_gees11_img_texture[i].id = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
   }

   for(i=0; i < GFX_MGR02_MAX_TEXT_TEXTURES; i++)
   {
      l_gees11_text_texture[i].id = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
   }

   for(i=0; i < GFX_MGR02_NUM_LAYERS; i++)
   {
      if(lc_layer_def_S[i].target == GFX_MGR02_TARGET_OPENGL)
      {
         fl_width  = lc_layer_def_S[i].area.width;
         fl_height = lc_layer_def_S[i].area.height;
      #if defined(WIN32)
         l_ogl_egl_context_S.NativeWindow  = CreateNativeWindow(fl_width, fl_height);
         l_ogl_egl_context_S.NativeDisplay = GetDC(l_ogl_egl_context_S.NativeWindow);
      #elif defined(MARCO2)
         l_ogl_egl_context_S.NativeDisplay = EGL_DEFAULT_DISPLAY;
         l_ogl_egl_context_S.NativeWindow  = 0;
      #elif defined(GENIVI_ILM)
         if(0 != hmi_gfx_lm_init())
         {
            return(FALSE);
         }
         l_ogl_egl_context_S.NativeDisplay = (NativeDisplayType)(hmi_gfx_lm_get_x11_display());
         l_ogl_egl_context_S.NativeWindow  = (EGLNativeWindowType)hmi_gfx_lm_get_x11_window();
      #else
         l_ogl_egl_context_S.NativeDisplay = fbGetDisplayByIndex(0);
         l_ogl_egl_context_S.NativeWindow  = fbCreateWindow(l_ogl_egl_context_S.NativeDisplay, 
                                                            0, 0, 
                                                            fl_width, 
                                                            fl_height);
      #endif
         break;
      }
   }
#if defined(MARCO2)
   if(i < GFX_MGR02_NUM_LAYERS)
#else
   if((l_ogl_egl_context_S.NativeDisplay != NULL) && (i < GFX_MGR02_NUM_LAYERS))
#endif
   {
      l_ogl_egl_context_S.Display = eglGetDisplay(l_ogl_egl_context_S.NativeDisplay);
      if(l_ogl_egl_context_S.Display == EGL_NO_DISPLAY)
      {
         l_ogl_egl_context_S.Display = eglGetDisplay((EGLNativeDisplayType) EGL_DEFAULT_DISPLAY);
      }
      if(eglInitialize(l_ogl_egl_context_S.Display, GFX_MGR02_NULL_PTR, GFX_MGR02_NULL_PTR))
      {
      #if defined(MARCO2)
         if(eglGetConfigs(l_ogl_egl_context_S.Display,
                          &l_ogl_egl_context_S.Config,
                          1,
                          &iConfigs) != 0)
         {
            l_ogl_egl_context_S.Surface = eglCreateWindowSurface(l_ogl_egl_context_S.Display,
                                                                 l_ogl_egl_context_S.Config,
                                                                 &l_ogl_egl_context_S.NativeWindow,
                                                                 NULL);
            l_ogl_egl_context_S.Context = eglCreateContext(l_ogl_egl_context_S.Display,
                                                           l_ogl_egl_context_S.Config,
                                                           EGL_NO_CONTEXT,
                                                           NULL);
            if(eglMakeCurrent(l_ogl_egl_context_S.Display,
                              l_ogl_egl_context_S.Surface,
                              l_ogl_egl_context_S.Surface,
                              l_ogl_egl_context_S.Context) == 0)
            {
               printf("EGL Make current failed\n");
            }
         }
         else
         {
            printf("eglGetConfigs failed\n");
         }
      #else
         if(eglChooseConfig(l_ogl_egl_context_S.Display, pi32ConfigAttribs, &l_ogl_egl_context_S.Config, 1, (EGLint *)&iConfigs))
         {
            eglBindAPI(EGL_OPENGL_ES_API);
            l_ogl_egl_context_S.Surface = eglCreateWindowSurface(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Config, l_ogl_egl_context_S.NativeWindow, NULL);
            l_ogl_egl_context_S.Context = eglCreateContext(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Config, EGL_NO_CONTEXT, ai32ContextAttribs);
            if(eglMakeCurrent(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Surface, l_ogl_egl_context_S.Surface, l_ogl_egl_context_S.Context) == 0)
            {
               printf("EGL Make current failed\n");
            }
          #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
           #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
            hmi_gfx_mgr02_ogllib_fbo_init(fl_width, fl_height);
           #endif
            /*
            ** Create the fragment shader object
            */
            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&fillFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            /*
            ** Loads the vertex shader in the same way
            */
            VertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(VertShader, 1, (const char**)&fillVertShaderCode, NULL);
            glCompileShader(VertShader);
            glGetShaderiv(VertShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if (!bShaderCompiled)
            {
               return(FALSE);
            }
            /*
            ** Create the shader program object
            */
            l_ogl_egl_context_S.fillProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.fillProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.fillProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.fillProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.fillProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);
            glDeleteShader(VertShader);
            if (!bLinked)
            {
               return(FALSE);
            }
            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&ARGBimgFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            VertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(VertShader, 1, (const char**)&imgVertShaderCode, NULL);
            glCompileShader(VertShader);
            glGetShaderiv(VertShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if (!bShaderCompiled)
            {
               return(FALSE);
            }
            l_ogl_egl_context_S.ArgbimgProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.ArgbimgProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.ArgbimgProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.ArgbimgProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.ArgbimgProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);

        #if defined(GFX_MGR02_DIRTY_REGION_REDRAW) && defined(GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND)
            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&FboimgFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            l_ogl_egl_context_S.fboCopyProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.fboCopyProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.fboCopyProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.fboCopyProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.fboCopyProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);
        #endif

            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&RGBimgFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            l_ogl_egl_context_S.RgbimgProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.RgbimgProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.RgbimgProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.RgbimgProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.RgbimgProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);
            glDeleteShader(VertShader);
            if (!bLinked)
            {
               return(FALSE);
            }

            // Create the fragment shader object for text
            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&txtFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            // Loads the vertex shader for text in the same way
            VertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(VertShader, 1, (const char**)&txtVertShaderCode, NULL);
            glCompileShader(VertShader);
            glGetShaderiv(VertShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if (!bShaderCompiled)
            {
               return(FALSE);
            }
            // Create the shader program for text
            l_ogl_egl_context_S.txtProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.txtProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.txtProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.txtProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.txtProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);
            glDeleteShader(VertShader);
            if (!bLinked)
            {
               return(FALSE);
            }
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
            FragShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(FragShader, 1, (const char**)&blurFragShaderCode, NULL);
            glCompileShader(FragShader);
            glGetShaderiv(FragShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if(!bShaderCompiled)
            {
               return(FALSE);
            }
            VertShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(VertShader, 1, (const char**)&blurVertShaderCode, NULL);
            glCompileShader(VertShader);
            glGetShaderiv(VertShader, GL_COMPILE_STATUS, &bShaderCompiled);
            if (!bShaderCompiled)
            {
               return(FALSE);
            }
            l_ogl_egl_context_S.blurProgramObject = glCreateProgram();
            glAttachShader(l_ogl_egl_context_S.blurProgramObject, FragShader);
            glAttachShader(l_ogl_egl_context_S.blurProgramObject, VertShader);
            glLinkProgram(l_ogl_egl_context_S.blurProgramObject);
            glGetProgramiv(l_ogl_egl_context_S.blurProgramObject, GL_LINK_STATUS, &bLinked);
            glDeleteShader(FragShader);
            glDeleteShader(VertShader);
            if (!bLinked)
            {
               return(FALSE);
            }
#endif
            l_ogllib_draw_sts = 0;
            glGenBuffers(1, &l_ogl_egl_context_S.VxBuffObject);
            glBindBuffer(GL_ARRAY_BUFFER, l_ogl_egl_context_S.VxBuffObject);
            /*
            ** Adjust the MVP matrix to accept the vertex co-ordinates
            ** in screen co-ordinate (top left is [0,0] AND bottom right is
            ** [width-1, height-1]
            */
            ovg_idty_matrx[0] = (2.0f/lc_layer_def_S[i].area.width);
            ovg_idty_matrx[4] = -(2.0f/lc_layer_def_S[i].area.height);
         #endif
            glViewport ( 0, 0, lc_layer_def_S[i].area.width, lc_layer_def_S[i].area.height);
            return(TRUE);
         }
         else
         {
            printf("EGL Choose Config failed\n");
         }
      #endif
      }
      else
      {
         printf("EGL init failed!\n");
      }
   }
   return(FALSE);
}

#ifdef OGL_DIRECT_TEXTURE_RENDERING
BOOLEAN hmi_gfx_mgr02_SetupglTexDirectVIV()
{
  BOOLEAN fl_return = (BOOLEAN)FALSE;
  if (l_gl_TexDirectVIV_done == FALSE)
  {
    if (l_gl_TexDirectVIVMap_Fptr == NULL)
    {
      l_gl_TexDirectVIVMap_Fptr = (PFN_GLTEXDIRECTVIVMAP_PROC)(eglGetProcAddress("glTexDirectVIVMap"));
    }
    if (l_gl_TexDirectInvalidateVIV_Fptr == NULL)
    {
      l_gl_TexDirectInvalidateVIV_Fptr = (PFN_GLTEXDIRECTINVALIDATEVIV_PROC)(eglGetProcAddress("glTexDirectInvalidateVIV"));
    }
  }
  if ((l_gl_TexDirectVIVMap_Fptr != NULL) &&
    (l_gl_TexDirectInvalidateVIV_Fptr != NULL))
  {
    fl_return = (BOOLEAN)(TRUE);
    l_gl_TexDirectVIV_done = (BOOLEAN)(TRUE);
  }
  else
  {
    l_gl_TexDirectVIV_done = (BOOLEAN)(FALSE);
  }
  return fl_return;
}
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_init
Description          : Initializes the library internal variables
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_shutdown(void)
{
   UINT32 i;
   for(i=0; i < GFX_MGR02_MAX_IMG_TEXTURES; i++)
   {
      if(l_gees11_img_texture[i].texId != 0)
      {
         glDeleteTextures(1, &l_gees11_img_texture[i].texId);
         l_gees11_img_texture[i].data  = 0;
         l_gees11_img_texture[i].texId = 0;
         l_gees11_img_texture[i].id    = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
      }
   }
   for(i=0; i < GFX_MGR02_MAX_TEXT_TEXTURES; i++)
   {
      if(l_gees11_text_texture[i].texId != 0)
      {
         glDeleteTextures(1, &l_gees11_text_texture[i].texId);
         l_gees11_text_texture[i].data  = 0;
         l_gees11_text_texture[i].texId = 0;
         l_gees11_text_texture[i].id    = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
      }
   }
   hmi_gfx_mgr02_cache_shutdown();
   if(l_ogl_egl_context_S.Display != EGL_NO_DISPLAY)
   {
   #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
    #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
      hmi_gfx_mgr02_ogllib_fbo_shutdown();
    #endif
   #endif
      if(l_ogl_egl_context_S.Context != EGL_NO_CONTEXT)
      {
         eglDestroyContext(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Context);
      }
      if(l_ogl_egl_context_S.Context != EGL_NO_SURFACE)
      {
         eglDestroySurface(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Surface);
      }
      (void)eglMakeCurrent(l_ogl_egl_context_S.Display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
      eglTerminate(l_ogl_egl_context_S.Display);
      l_ogl_egl_context_S.Display = EGL_NO_DISPLAY;
      l_ogl_egl_context_S.Context = EGL_NO_CONTEXT;
      l_ogl_egl_context_S.Surface = EGL_NO_SURFACE;
   }
   return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_start
Description          : Function to be called before start of building operation
Invocation           : Invoked by manager
Parameters           : None
Return Value         : True if init success
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_start(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
 #if defined(GFX_MGR02_DIRTY_REGION_REDRAW)
   hmi_gfx_mgr02_ogllib_fbo_start();
 #else
   glClearColor(0, 0, 0, 0);
 #endif
#elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
   glClearColor(0, 0, 0, 0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrthox( INT2FIXED(0),
             INT2FIXED(p_cntx_SP->rprop.fb_w),
             INT2FIXED(p_cntx_SP->rprop.fb_h),
             INT2FIXED(0),
            -INT2FIXED(1),
             INT2FIXED(1));
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
#endif
   glEnable(GL_BLEND);
   glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   glEnable(GL_SCISSOR_TEST);
   glScissor(0, 0, p_cntx_SP->rprop.fb_w, p_cntx_SP->rprop.fb_h);
   l_ogllib_clip_rect[0] = 0;
   l_ogllib_clip_rect[1] = 0;
   l_ogllib_clip_rect[2] = (GLint)p_cntx_SP->rprop.fb_w;
   l_ogllib_clip_rect[3] = (GLint)p_cntx_SP->rprop.fb_h;
#endif
   return(TRUE);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_finish
Description          : Function to be called after all building operation are
                       completed. This will perform the VG flush to perform
                       any pending VG operations 
Invocation           : Invoked by manager
Parameters           : None
Return Value         : Non zero if any drawing operation performed, if no
                       drawing operations are performed returns FALSE
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_finish(void)
{
   UINT32 i;
   for(i=0; i < GFX_MGR02_MAX_IMG_TEXTURES; i++)
   {
      if(l_gees11_img_texture[i].live > 0)
      {
         l_gees11_img_texture[i].live--;
      }
   }
   for(i=0; i < GFX_MGR02_MAX_TEXT_TEXTURES; i++)
   {
      if(l_gees11_text_texture[i].live > 0)
      {
         l_gees11_text_texture[i].live--;
      }
   }
   hmi_gfx_mgr02_cache_update_live_count();
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && defined(GFX_MGR02_DIRTY_REGION_REDRAW)
   hmi_gfx_mgr02_ogllib_fbo_finish();
#endif

   if(l_ogllib_draw_sts != 0)
   {
      /*
      ** TODO : this has to be moved to context to handle it the same way as
      **        opennvg. right now there too many variations in context.c which is making it
      **        little complex so until we redesign that keep this here.
      */
      eglSwapBuffers(l_ogl_egl_context_S.Display, l_ogl_egl_context_S.Surface);
   }
   glBindTexture(GL_TEXTURE_2D, 0);
   return((s_gx_flocal)l_ogllib_draw_sts);
}

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_set_clip
Description          : Sets the clip area to the passed one if it is new area
Invocation           : Invoked internally
Parameters           : Clip area via context pointer
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_set_clip(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
   SINT32 fl_cw = p_cntx_SP->state.clip.ex;
   SINT32 fl_ch = p_cntx_SP->state.clip.ey;

   fl_cw -= p_cntx_SP->state.clip.sx;
   fl_ch -= p_cntx_SP->state.clip.sy;
   
   if((l_ogllib_clip_rect[0] != p_cntx_SP->state.clip.sx) ||
      (l_ogllib_clip_rect[1] != p_cntx_SP->state.clip.sy) ||
      (l_ogllib_clip_rect[2] != fl_cw) ||
      (l_ogllib_clip_rect[3] != fl_ch))
   {
      SINT32 clip_rect[4];

      clip_rect[0] = p_cntx_SP->state.clip.sx;
      clip_rect[1] = ((p_cntx_SP->rprop.fb_h-p_cntx_SP->state.clip.sy)-fl_ch);
      clip_rect[2] = fl_cw;
      clip_rect[3] = fl_ch;
      glScissor(clip_rect[0], clip_rect[1], clip_rect[2], clip_rect[3]);

      l_ogllib_clip_rect[0] = p_cntx_SP->state.clip.sx;
      l_ogllib_clip_rect[1] = p_cntx_SP->state.clip.sy;
      l_ogllib_clip_rect[2] = fl_cw;
      l_ogllib_clip_rect[3] = fl_ch;
   }
}
#endif

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
#if defined(GFX_MGR02_GLES_NPOT)
  #define PowerOfTwo(x) (x)
#else
/* 
** logic from http://stackoverflow.com/questions/1322510/given-an-integer-how-do-i-find-the-next-largest-power-of-two-using-bit-twiddlin
** to find next power of 2 value for the passed number
*/
GLuint PowerOfTwo(GLuint num)
{
   if(num != 0)
   {
      num--;
      num |= (num >> 1);
      num |= (num >> 2);
      num |= (num >> 4);
      num |= (num >> 8);
      num |= (num >> 16);
      num++;
   }
   return num;
}
#endif
#endif
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_get_tex
Description          : Returns the texture from the cache if present else
                       returns NULL
Invocation           : Invoked internally
Parameters           : Pointer to the image data
Return Value         : GFX_MGR02_TEXTURE pointer ot NULL
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_ogllib_get_image_tex(GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP, void const * p_img_id)
{
   BOOLEAN             fl_texture_found    = FALSE;
   UINT32              fl_cur_live_count   = GFX_MGR02_MAX_TEX_LIVE;
   UINT32              fl_least_used_index = GFX_MGR02_MAX_IMG_TEXTURES;
   UINT32 i;
   for(i=0; i < GFX_MGR02_MAX_IMG_TEXTURES; i++)
   {
      if(l_gees11_img_texture[i].id == p_img_id)
      {
         if((l_gees11_img_texture[i].texh == p_elem_def_SP->height) &&
            (l_gees11_img_texture[i].texw == p_elem_def_SP->width))
         {
            fl_texture_found = TRUE;

            glActiveTexture(GL_TEXTURE0);
          #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
            glEnable(GL_TEXTURE_2D);
          #endif
            glBindTexture(GL_TEXTURE_2D, l_gees11_img_texture[i].texId);
            /* keep the image id same so that new texture will not be created. china team keep p_img_id in ram */
            l_gees11_img_texture[i].id = p_img_id;
            l_gees11_img_texture[i].live = (GFX_MGR02_MAX_TEX_LIVE+1);
            fl_least_used_index = i;
            break;
         }
      }
      else if(l_gees11_img_texture[i].live < fl_cur_live_count)
      {
         fl_cur_live_count   = l_gees11_img_texture[i].live;
         fl_least_used_index = i;
         if(l_gees11_img_texture[fl_least_used_index].data == 0)
         {
            fl_texture_found = TRUE;
            break;
         }
      }
      else
      {
      }
   }
   if(fl_texture_found == FALSE)
   {
      if(fl_least_used_index == GFX_MGR02_MAX_IMG_TEXTURES)
      {
         fl_least_used_index = 0;
      }
      /* cleared so that texture will be deleted eventhough img id is same */
      l_gees11_img_texture[fl_least_used_index].id = 0;
   }

   return  fl_least_used_index;
}

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_get_tex
Description          : Returns the texture from the cache if present else
                       returns NULL
Invocation           : Invoked internally
Parameters           : Pointer to the image data
Return Value         : GFX_MGR02_TEXTURE pointer ot NULL
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT32 hmi_gfx_mgr02_ogllib_get_text_tex(GFX_MGR02_TEXT_DEF_T * p_img_id)
{
   /* Implement binary search here */
   HMI_CHAR *          p_string;
   UINT32              i;
   BOOLEAN             fl_texture_found = FALSE;
   UINT32              fl_cur_live_count   = GFX_MGR02_MAX_TEX_LIVE;
   UINT32              fl_least_used_index = GFX_MGR02_MAX_TEXT_TEXTURES;

   UINT32              fl_font_id = hmi_gfx_mgr02_get_font_id(p_img_id->font_id);

   if(p_img_id->dynamic != 0)
   {
   #if GFX_MGR02_NUM_OF_DTEXTS > 0
      GFX_MGR02_ANIM_DATA_T * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
      p_string = (void *)&fl_anim_prop_SP->dtext_str[p_img_id->string_index];
   #endif
   }
   else
   {
   #if GFX_MGR02_NUM_OF_STEXTS > 0
      p_string = (void *)&lc_static_text_buffer[p_img_id->string_index];
   #endif
   }
   for(i=0; i < GFX_MGR02_MAX_TEXT_TEXTURES; i++)
   {
      if(HMI_STRNCMP((const HMI_CHAR*)&l_gees11_text_cache_buffer[i], p_string, p_img_id->num_chars) == 0)
      {
         if(l_gees11_text_texture[i].font_id == fl_font_id)
         {
            fl_texture_found = TRUE;
            glActiveTexture(GL_TEXTURE0);
         #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
            glEnable(GL_TEXTURE_2D);
         #endif
            glBindTexture(GL_TEXTURE_2D, l_gees11_text_texture[i].texId);
            /* keep the image id same so that new texture will not be created. china team keep p_img_id in ram */
            l_gees11_text_texture[i].id = p_img_id;
            l_gees11_text_texture[i].live = (GFX_MGR02_MAX_TEX_LIVE+1);
            fl_least_used_index = i;
            break;
         }
      }
      else if(l_gees11_text_texture[i].live < fl_cur_live_count)
      {
         fl_cur_live_count   = l_gees11_text_texture[i].live;
         fl_least_used_index = i;
         if(l_gees11_text_cache_buffer[fl_least_used_index][0] == 0)
         {
            fl_texture_found = TRUE;
            l_gees11_text_texture[fl_least_used_index].id = 0;
            break;
         }
      }
      else
      {
      }
   }
   if(fl_texture_found == FALSE)
   {
      if(fl_least_used_index == GFX_MGR02_MAX_TEXT_TEXTURES)
      {
         fl_least_used_index = 0;
      }
      /* cleared so that texture will be deleted eventhough img id is same */
      l_gees11_text_texture[fl_least_used_index].id = 0;
   }

   return  fl_least_used_index;
}
#endif

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) || (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_remove_tex
Description          : Removes a texture from the tex cache
Invocation           : Invoked internally/application
Parameters           : Pointer to the image data
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ogllib_remove_tex(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP, void const* p_img_id)
{
   GFX_MGR02_TEXTURE * fl_texture = 0;

   if(p_img_id != 0)
   {
      UINT32 i;

      for(i=0; i < GFX_MGR02_MAX_IMG_TEXTURES; i++)
      {
         if(l_gees11_img_texture[i].id == p_img_id)
         {
            if(p_elem_def_SP == 0)
            {
            	fl_texture = &l_gees11_img_texture[i];
            	if(fl_texture->texId != 0)
                {
            	   glDeleteTextures(1, &fl_texture->texId);
                   fl_texture->texId = 0;
                   fl_texture->id    = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
                   fl_texture->live  = 0;
                }
            }
            else if((l_gees11_img_texture[i].texh == p_elem_def_SP->height) &&
               (l_gees11_img_texture[i].texw == p_elem_def_SP->width))
            {
               fl_texture = &l_gees11_img_texture[i];
               if(fl_texture->texId != 0)
               {
            	  glDeleteTextures(1, &fl_texture->texId);
                  fl_texture->texId = 0;
                  fl_texture->id    = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
                  fl_texture->live  = 0;
               }
               break;
            }
            else
            {

            }
         }    
      }
   }
}

#if defined(GFX_MGR02_GLES_NPOT) || (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_load_imagefile_to_mem
Description          : Reads the image file and loads it in to RAM. If the 
                       image is compressed then uncompress it.
Invocation           : Invoked internally
Parameters           : 
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 * hmi_gfx_mgr02_ogllib_load_imagefile_to_mem(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP,
                                                          UINT32                        p_byte_per_px)
{
   UINT8 * fl_tex        = 0;
   FILE  * fl_image_file = fopen(p_elem_def_SP->pixel_data, "rb");
   
   if(fl_image_file != 0)
   {
      UINT32  fl_blk_size;
      fl_blk_size  = p_byte_per_px;
      fl_blk_size *= p_elem_def_SP->width;
      fl_blk_size *= p_elem_def_SP->height;
      fl_tex       = malloc(fl_blk_size);

      if(fl_tex != 0)
      {
      #if defined(GFX_MGR02_COMPRESSION_ENABLED)
         if(p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
         {
            SINT32  fl_rle_size = (SINT32)(p_elem_def_SP->comp_size);
            UINT8   fl_cmd_byte;
            UINT8   fl_data[4];
            UINT8 * fl_dcomp_buffp    = fl_tex;
            UINT32  fl_dcomp_rem_size = fl_blk_size;
            while((fl_rle_size > 0) && (fl_dcomp_rem_size > 0))
            {
               fl_rle_size--;
               if(fread(&fl_cmd_byte, 1, 1, fl_image_file) != 1)
               {
                  free(fl_tex);
                  fl_tex      = 0;
                  fl_rle_size = 0;
               }
               else if((fl_cmd_byte & 0x80) != 0)
               {
                  fl_cmd_byte &= 0x7F;
                  if(fread(&fl_data, 1, p_byte_per_px, fl_image_file) != p_byte_per_px)
                  {
                     free(fl_tex);
                     fl_tex      = 0;
                     fl_rle_size = 0;
                  }
                  else
                  {
                     fl_rle_size -= p_byte_per_px;
                     fl_cmd_byte++;
                     while(fl_cmd_byte > 0)
                     {
                        fl_cmd_byte--;
                        if(fl_dcomp_rem_size < p_byte_per_px)
                        {
                           p_byte_per_px = fl_dcomp_rem_size;
                           fl_cmd_byte   = 0;
                        }
                        memcpy(fl_dcomp_buffp, fl_data, p_byte_per_px);
                        fl_dcomp_buffp    += p_byte_per_px;
                        fl_dcomp_rem_size -= p_byte_per_px;
                     }
                  }
               }
               else
               {
                  fl_cmd_byte++;
                  fl_blk_size = (p_byte_per_px*fl_cmd_byte);
                  if(fl_dcomp_rem_size < fl_blk_size)
                  {
                     fl_blk_size = fl_dcomp_rem_size;
                  }
                  if(fread(fl_dcomp_buffp, 1, fl_blk_size, fl_image_file) != fl_blk_size)
                  {
                     free(fl_tex);
                     fl_tex      = 0;
                     fl_rle_size = 0;
                  }
                  else
                  {
                     fl_dcomp_buffp    += fl_blk_size;
                     fl_rle_size       -= fl_blk_size;
                     fl_dcomp_rem_size -= fl_blk_size;
                  }
               }
            }
         }
         else if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
         {
            /* other compression types not supported currently */
            free(fl_tex);
            fl_tex = 0;
         }
         else
      #endif
         {
            if(fread(fl_tex, 1, fl_blk_size, fl_image_file) != fl_blk_size)
            {
               /* 
               ** error condition 
               */
               free(fl_tex);
               fl_tex = 0;
            }
         }
      }
      fclose(fl_image_file);
   }
   return(fl_tex);
}
#else
static UINT8 * hmi_gfx_mgr02_ogllib_load_imagefile_to_mem(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP,
                                                          UINT32                        p_byte_per_px,
                                                          UINT32                        p_tstride,
                                                          UINT32                        p_height)
{
   UINT8 * fl_tex        = 0;
   FILE  * fl_image_file = fopen(p_elem_def_SP->pixel_data, "rb");
   
   if(fl_image_file != 0)
   {
      UINT32  fl_istride  = (p_byte_per_px * p_elem_def_SP->width);
      UINT32  fl_blk_size = (fl_istride    * p_elem_def_SP->height);

      fl_tex = malloc(p_tstride * p_height);

      if(fl_tex != 0)
      {
      #if defined(GFX_MGR02_COMPRESSION_ENABLED)
         if(p_elem_def_SP->compression == GFX_MGR02_IMAGE_COMPRESSION_HWRLE)
         {
            SINT32  fl_rle_size = (SINT32)(p_elem_def_SP->comp_size);
            UINT8   fl_cmd_byte;
            UINT8   fl_data[4];
            UINT8 * fl_dcomp_buffp      = fl_tex;
            UINT32  fl_dcomp_rem_size   = fl_blk_size;
            SINT32  fl_image_horz_bytes = fl_istride;

            while((fl_rle_size > 0) && (fl_dcomp_rem_size > 0))
            {
               fl_rle_size--;
               if(fread(&fl_cmd_byte, 1, 1, fl_image_file) != 1)
               {
                  free(fl_tex);
                  fl_tex      = 0;
                  fl_rle_size = 0;
               }
               else if((fl_cmd_byte & 0x80) != 0)
               {
                  fl_cmd_byte &= 0x7F;
                  if(fread(&fl_data, 1, p_byte_per_px, fl_image_file) != p_byte_per_px)
                  {
                     free(fl_tex);
                     fl_tex      = 0;
                     fl_rle_size = 0;
                  }
                  else
                  {
                     fl_rle_size -= p_byte_per_px;
                     fl_cmd_byte++;
                     while(fl_cmd_byte > 0)
                     {
                        fl_cmd_byte--;
                        if(fl_dcomp_rem_size < p_byte_per_px)
                        {
                           p_byte_per_px = fl_dcomp_rem_size;
                           fl_cmd_byte   = 0;
                        }
                        memcpy(fl_dcomp_buffp, fl_data, p_byte_per_px);
                        fl_dcomp_buffp      += p_byte_per_px;
                        fl_dcomp_rem_size   -= p_byte_per_px;
                        fl_image_horz_bytes -= p_byte_per_px;
                        if(fl_image_horz_bytes <= 0)
                        {
                           fl_image_horz_bytes = fl_istride; 
                           fl_dcomp_buffp     += (p_tstride-fl_istride);
                        }
                     }
                  }
               }
               else
               {
                  fl_cmd_byte++;
                  while(fl_cmd_byte > 0)
                  {
                     if(fread(&fl_data, 1, p_byte_per_px, fl_image_file) != p_byte_per_px)
                     {
                        free(fl_tex);
                        fl_tex      = 0;
                        fl_rle_size = 0;
                        fl_cmd_byte = 0;
                     }
                     else
                     {
                        fl_cmd_byte--;
                        if(fl_dcomp_rem_size < p_byte_per_px)
                        {
                           p_byte_per_px = fl_dcomp_rem_size;
                           fl_cmd_byte   = 0;
                        }
                        memcpy(fl_dcomp_buffp, fl_data, p_byte_per_px);
                        fl_dcomp_buffp      += p_byte_per_px;
                        fl_dcomp_rem_size   -= p_byte_per_px;
                        fl_image_horz_bytes -= p_byte_per_px;
                        if(fl_image_horz_bytes <= 0)
                        {
                           fl_image_horz_bytes = fl_istride; 
                           fl_dcomp_buffp     += (p_tstride-fl_istride);
                        }
                     }
                  }
               }
            }
         }
         else if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
         {
            /* other compression types not supported currently */
            free(fl_tex);
            fl_tex = 0;
         }
         else
      #endif
         {
            UINT8 * fl_texture_ptr = fl_tex;
            UINT32  fl_iheight     = p_elem_def_SP->height;
            
            while(fl_iheight > 0)
            {
               if(fread(fl_texture_ptr, 1, fl_istride, fl_image_file) == fl_istride)
               {
                  fl_texture_ptr += p_tstride;
                  fl_iheight--;
               }
               else
               {
                  /* error condition */
                  fl_iheight = 0;
                  free(fl_tex);
                  fl_tex = 0;
               }
            }
         }
      }
      fclose(fl_image_file);
   }
   return(fl_tex);
}
#endif

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_create_tex
Description          : Creates a texture image buffer aligned with GL ES 1.1
                       width/height restriction and stores it in to a free slot
                       If slots are not available then frees the least used
                       slot.
Invocation           : Invoked internally
Parameters           : 
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_MGR02_TEXTURE * hmi_gfx_mgr02_ogllib_create_tex(GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP, 
                                                           UINT32                        p_wrap, 
                                                           UINT32                        p_raw_data,
                                                           void                  const * p_img_id,
                                                           GFX_MGR02_TEXTURE           * p_texture_array_ptr)
{
   GLuint fl_format;
   GLuint fl_type;

   glActiveTexture(GL_TEXTURE0);

   if(p_texture_array_ptr->texId != 0)
   {
      glDeleteTextures(1, &p_texture_array_ptr->texId);
      p_texture_array_ptr->texId = 0;
      p_texture_array_ptr->data  = 0;
      p_texture_array_ptr->id    = (void const*)GFX_MGR02_TEXTURE_ID_FREE;
      p_texture_array_ptr->live  = 0;
   }

   if(p_texture_array_ptr->id != p_img_id)
   {
      UINT32 fl_stride;
   #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
      GLint  fl_po;

      switch(p_elem_def_SP->format)
      {
         case VG_A_8:
         {
            fl_format = GL_ALPHA;
            fl_type   = GL_UNSIGNED_BYTE;
            fl_po     = l_ogl_egl_context_S.ArgbimgProgramObject;
            fl_stride = 1;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;

         case VG_sARGB_8888:
         {
            fl_format = GL_RGBA; 
            fl_type   = GL_UNSIGNED_BYTE;
            fl_po     = l_ogl_egl_context_S.ArgbimgProgramObject;
            fl_stride = 4;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;
         case VG_sRGBA_8888_VIV:
         {
           fl_format = GL_RGBA;
           fl_type   = GL_UNSIGNED_BYTE;
           fl_po     = l_ogl_egl_context_S.ArgbimgProgramObject;
           fl_stride = 4;
           glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;
         case VG_sXRGB_8888:
         {
            fl_format = GL_RGBA; 
            fl_type   = GL_UNSIGNED_BYTE;
            fl_po     = l_ogl_egl_context_S.RgbimgProgramObject;
            fl_stride = 4;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;
         case VG_sARGB_4444:
         {
            fl_format = GL_RGBA; 
            fl_type   = GL_UNSIGNED_SHORT_4_4_4_4;
            fl_po     = l_ogl_egl_context_S.ArgbimgProgramObject;
            fl_stride = 2;
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
         }
         break;
         case VG_sARGB_1555:
         {
            fl_format = GL_RGBA; 
            fl_type   = GL_UNSIGNED_SHORT_5_5_5_1;
            fl_po     = l_ogl_egl_context_S.ArgbimgProgramObject;
            fl_stride = 2;
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
         }
         break;
         case VG_sRGB_565:
         {
            fl_format = GL_RGB;
            fl_type   = GL_UNSIGNED_SHORT_5_6_5;
            fl_po     = l_ogl_egl_context_S.RgbimgProgramObject;
            fl_stride = 2;
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
         }
         break;
         case VG_RGB_888:
         {
             fl_format = GL_RGB;
             fl_type = GL_UNSIGNED_BYTE;
             fl_po = l_ogl_egl_context_S.RgbimgProgramObject;
             fl_stride = 3;
             glPixelStorei(GL_PACK_ALIGNMENT, 1);
         }
         break;
         default: 
         {
            fl_format = GL_FALSE;
            fl_type   = GL_FALSE;
            fl_stride = 0;
         }
         break;
      }
      if (fl_format != GL_FALSE)
      {
        UINT8* fl_tex = 0;
        if (p_raw_data == FALSE)
        {
          fl_tex = hmi_gfx_mgr02_ogllib_load_imagefile_to_mem(p_elem_def_SP, fl_stride);
        }
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
        else if (p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
        {
          /* RLE not supported currently without file system */
        }
#endif
        else
        {
          fl_tex = (void*)p_elem_def_SP->pixel_data;
        }

        if (fl_tex != 0)
        {

          p_texture_array_ptr->po = fl_po;
          p_texture_array_ptr->data = (void*)p_elem_def_SP->pixel_data;
          p_texture_array_ptr->id = (void*)p_img_id;
          p_texture_array_ptr->live = (GFX_MGR02_MAX_TEX_LIVE + 1);
          p_texture_array_ptr->texw = p_elem_def_SP->width;
          p_texture_array_ptr->texh = p_elem_def_SP->height;
          glGenTextures(1, &p_texture_array_ptr->texId);
#ifdef OGL_DIRECT_TEXTURE_RENDERING
          if (p_elem_def_SP->format == VG_sRGBA_8888_VIV)
          {
            GLuint physical = ~0U;
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, p_texture_array_ptr->texId);
            if (hmi_gfx_mgr02_SetupglTexDirectVIV())
            {
              l_gl_TexDirectVIVMap_Fptr(GL_TEXTURE_2D, p_elem_def_SP->width, p_elem_def_SP->height, fl_format, (void**)(&fl_tex), &physical);
            }
          }
          else
#endif
          {
            glBindTexture(GL_TEXTURE_2D, p_texture_array_ptr->texId);
            glTexImage2D(GL_TEXTURE_2D,
              0,
              fl_format,
              p_elem_def_SP->width,
              p_elem_def_SP->height,
              0,
              fl_format,
              fl_type,
              fl_tex);
          }
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, p_wrap);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, p_wrap);
          if (fl_tex != (void*)(p_elem_def_SP->pixel_data))
          {
            free(fl_tex);
          }
        }
        else
        {
          p_texture_array_ptr = 0;
        }
      }
   #else
      UINT32  fl_iheight = p_elem_def_SP->height;
      UINT32  fl_height  = PowerOfTwo(fl_iheight);
      UINT32  fl_width   = PowerOfTwo(p_elem_def_SP->width);
      UINT8 * fl_tex = 0;
      UINT8 * fl_img = 0;
      UINT32  fl_istride = 0;
      UINT32  fl_tstride = 0;


      switch(p_elem_def_SP->format)
      {
         case VG_A_8:
         {
            fl_istride = p_elem_def_SP->width;
            fl_tstride = fl_width;
            fl_format  = GL_ALPHA;
            fl_type    = GL_UNSIGNED_BYTE;
            fl_stride  = 1;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;
         case VG_sARGB_8888:
         case VG_sXRGB_8888:
         {
            fl_istride = (p_elem_def_SP->width << 2);
            fl_tstride = (fl_width<<2);
            fl_format  = GL_RGBA; 
            fl_type    = GL_UNSIGNED_BYTE;
            fl_stride  = 4;
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
         }
         break;
         case VG_sARGB_4444:
         case VG_sARGB_1555:
         case VG_sRGB_565:
         {
            fl_istride = (p_elem_def_SP->width << 1);
            fl_tstride = (fl_width<<1);
            if(p_elem_def_SP->format == VG_sARGB_4444)
            {
               fl_format = GL_RGBA; 
               fl_type   = GL_UNSIGNED_SHORT_4_4_4_4;
            }
            else if(p_elem_def_SP->format == VG_sARGB_1555)
            {
               fl_format = GL_RGBA; 
               fl_type   = GL_UNSIGNED_SHORT_5_5_5_1;
            }
            else
            {
               fl_format = GL_RGB; 
               fl_type   = GL_UNSIGNED_SHORT_5_6_5;
            }
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            fl_stride  = 2;
         }
         break;
         default: 
         {
            fl_format = GL_FALSE;
            fl_stride = 0;
         }
         break;
      }
      if(fl_format != GL_FALSE)
      {
         if(p_raw_data == FALSE)
         {
         #if defined(GFX_MGR02_GLES_NPOT)
            fl_tex = hmi_gfx_mgr02_ogllib_load_imagefile_to_mem(p_elem_def_SP, fl_stride);
         #else
            fl_tex = hmi_gfx_mgr02_ogllib_load_imagefile_to_mem(p_elem_def_SP, fl_stride, fl_tstride, fl_height);
         #endif

            if(fl_tex == 0)
            {
               p_texture_array_ptr = 0;
            }
            else
            {
               p_texture_array_ptr->data    = (void *)p_elem_def_SP->pixel_data;
               p_texture_array_ptr->id      = (void *)p_img_id;
               p_texture_array_ptr->live    = (GFX_MGR02_MAX_TEX_LIVE+1);
               p_texture_array_ptr->texw    = fl_width;
               p_texture_array_ptr->texh    = fl_height;
               glGenTextures(1, &p_texture_array_ptr->texId);
               glEnable(GL_TEXTURE_2D);
               glBindTexture(GL_TEXTURE_2D, p_texture_array_ptr->texId);
               glTexImage2D (GL_TEXTURE_2D, 
                             0, 
                             fl_format,
                             fl_width, 
                             fl_height,
                             0, 
                             fl_format, 
                             fl_type, 
                             fl_tex);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     p_wrap);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     p_wrap);
               glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    FALSE);
               free(fl_tex);
            }
         }
      #if defined(GFX_MGR02_COMPRESSION_ENABLED)
         else if(p_elem_def_SP->compression != GFX_MGR02_IMAGE_COMPRESSION_NONE)
         {
            /* RLE not supported currently without file system */
         }
      #endif
         else
         {
            fl_tex = malloc(fl_tstride * p_elem_def_SP->height);

            if(fl_tex != 0)
            {
               UINT8 * fl_texture_ptr = fl_tex;

               p_texture_array_ptr->data = (void *)p_elem_def_SP->pixel_data;
               p_texture_array_ptr->id   = (void *)p_img_id;
               p_texture_array_ptr->live = (GFX_MGR02_MAX_TEX_LIVE+1);
               p_texture_array_ptr->texw = fl_width;
               p_texture_array_ptr->texh = fl_height;
               fl_img    = (void *)p_elem_def_SP->pixel_data;

               while(fl_iheight > 0)
               {
                  memcpy(fl_texture_ptr, fl_img, fl_istride);
                  fl_img += fl_istride;
                  fl_texture_ptr += fl_tstride;
                  fl_iheight--;
               }

               glGenTextures(1, &p_texture_array_ptr->texId);
               glEnable(GL_TEXTURE_2D);
               glBindTexture(GL_TEXTURE_2D, p_texture_array_ptr->texId);
               glTexImage2D (GL_TEXTURE_2D,
                             0,
                             fl_format,
                             fl_width,
                             fl_height,
                             0,
                             fl_format,
                             fl_type,
                             fl_tex);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     p_wrap);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     p_wrap);
               glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP,    FALSE);
               free(fl_tex);
            }
         }
      }
      else
      {
         p_texture_array_ptr->data = 0;
         p_texture_array_ptr->id   = 0;
         p_texture_array_ptr->live = 0;
         p_texture_array_ptr       = 0;
         printf("Texture memory allocation failed1\n");
      }
   #endif
   }
   else
   {
   #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
      glEnable(GL_TEXTURE_2D);
   #endif
      glBindTexture(GL_TEXTURE_2D, p_texture_array_ptr->texId);
      p_texture_array_ptr->live = (GFX_MGR02_MAX_TEX_LIVE+1);
   }
   return(p_texture_array_ptr);
}
#endif

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
   /*
   ** TODO : Need to workout displaying A8 format
   **        Need to workout passing the alpha to shader.
   **        pivot and matrix needs to be taken care.
   */
    GFX_MGR02_TEXTURE * fl_textture;
    UINT32 fl_least_used_index;

#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
#endif
   hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);
   if(p_cntx_SP->state.invisible == 0)
   {
      GLuint fl_location;
      fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(p_elem_def_SP, p_elem_def_SP->pixel_data);
      fl_textture = &l_gees11_img_texture[fl_least_used_index];
      if(fl_textture->id != p_elem_def_SP->pixel_data)
      {
   #if defined(GFX_MGR02_USE_FILESYSTEM)
      fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, FALSE, (void *)p_elem_def_SP->pixel_data, fl_textture);
   #else
      fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, TRUE,  (void *)p_elem_def_SP->pixel_data, fl_textture);
   #endif
      }
      if(fl_textture != 0)
      {
         l_texture_vertex[0]  = 0;
         l_texture_vertex[1]  = 0;
         l_texture_vertex[5]  = (GFX_FLOAT)(p_elem_def_SP->width);
         l_texture_vertex[6]  = 0;
         l_texture_vertex[10] = 0;
         l_texture_vertex[11] = (GFX_FLOAT)(p_elem_def_SP->height);
         l_texture_vertex[15] = (GFX_FLOAT)(p_elem_def_SP->width);
         l_texture_vertex[16] = (GFX_FLOAT)(p_elem_def_SP->height);

         l_texture_vertex[8]  = 1.0f;
         l_texture_vertex[14] = 1.0f;
         l_texture_vertex[18] = 1.0f;
         l_texture_vertex[19] = 1.0f;

         glUseProgram(fl_textture->po);
         fl_location = glGetUniformLocation(fl_textture->po, "MVPMatrix");
         glUniformMatrix4fv(fl_location, 1, GL_FALSE, pfIdentity);
         fl_location = glGetUniformLocation(fl_textture->po, "s_texture");
         glUniform1i(fl_location, 0);
   
         glBufferData(GL_ARRAY_BUFFER, 4*5*sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
         fl_location = glGetAttribLocation(fl_textture->po, "a_position");
         glEnableVertexAttribArray(fl_location);
         glVertexAttribPointer(fl_location, 
                               3, 
                               GL_FLOAT, 
                               GL_FALSE, 
                               (5 * sizeof(GLfloat)), 
                               0);
         fl_location = glGetAttribLocation(fl_textture->po, "tpos");
         glEnableVertexAttribArray(fl_location);
         glVertexAttribPointer(fl_location, 
                               2, 
                               GL_FLOAT, 
                               GL_FALSE, 
                               (5 * sizeof(GLfloat)), 
                               (void*)(3 * sizeof(GLfloat)));

         fl_location = glGetUniformLocation(fl_textture->po, "Alpha");
         glUniform1f(fl_location, (p_cntx_SP->state.alpha/255.0f));
         
         glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
         l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
      }
   }
   return 0;
}
#if defined(GFX_MGR02_USE_FILESYSTEM)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_uimage
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_uimage(GFX_MGR02_CONTEXT_T   const * p_cntx_SP,
  GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP)
{
  /*
  ** TODO : Need to workout displaying A8 format
  **        Need to workout passing the alpha to shader.
  **        pivot and matrix needs to be taken care.
  */
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
#endif
  hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);
  if (p_cntx_SP->state.invisible == 0)
  {
    GLuint fl_location;
    GFX_MGR02_TEXTURE* fl_textture;
    UINT32              fl_least_used_index;
    fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(p_elem_def_SP, p_elem_def_SP->pixel_data);
    fl_textture = &l_gees11_img_texture[fl_least_used_index];
    if (fl_textture->id != p_elem_def_SP->pixel_data)
    {
      fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, TRUE, (void*)p_elem_def_SP->pixel_data, fl_textture);
    }
    if (fl_textture != 0)
    {
      l_texture_vertex[0] = 0;
      l_texture_vertex[1] = 0;
      l_texture_vertex[5] = (GFX_FLOAT)(p_elem_def_SP->width);
      l_texture_vertex[6] = 0;
      l_texture_vertex[10] = 0;
      l_texture_vertex[11] = (GFX_FLOAT)(p_elem_def_SP->height);
      l_texture_vertex[15] = (GFX_FLOAT)(p_elem_def_SP->width);
      l_texture_vertex[16] = (GFX_FLOAT)(p_elem_def_SP->height);

      l_texture_vertex[8] = 1.0f;
      l_texture_vertex[14] = 1.0f;
      l_texture_vertex[18] = 1.0f;
      l_texture_vertex[19] = 1.0f;

      glUseProgram(fl_textture->po);
      fl_location = glGetUniformLocation(fl_textture->po, "MVPMatrix");
      glUniformMatrix4fv(fl_location, 1, GL_FALSE, pfIdentity);
      fl_location = glGetUniformLocation(fl_textture->po, "s_texture");
      glUniform1i(fl_location, 0);

      glBufferData(GL_ARRAY_BUFFER, 4 * 5 * sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
      fl_location = glGetAttribLocation(fl_textture->po, "a_position");
      glEnableVertexAttribArray(fl_location);
      glVertexAttribPointer(fl_location,
        3,
        GL_FLOAT,
        GL_FALSE,
        (5 * sizeof(GLfloat)),
        0);
      fl_location = glGetAttribLocation(fl_textture->po, "tpos");
      glEnableVertexAttribArray(fl_location);
      glVertexAttribPointer(fl_location,
        2,
        GL_FLOAT,
        GL_FALSE,
        (5 * sizeof(GLfloat)),
        (void*)(3 * sizeof(GLfloat)));
      fl_location = glGetUniformLocation(fl_textture->po, "Alpha");
      glUniform1f(fl_location, (p_cntx_SP->state.alpha / 255.0f));
#ifdef OGL_DIRECT_TEXTURE_RENDERING
      if (p_elem_def_SP->format == VG_sRGBA_8888_VIV)
      {
        if (hmi_gfx_mgr02_SetupglTexDirectVIV())
        {
          glBindTexture(GL_TEXTURE_2D, fl_textture->texId);
          l_gl_TexDirectInvalidateVIV_Fptr(GL_TEXTURE_2D);
        }
      }
#endif
      glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
      l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING | GFX_MGR02_OGLLIB_FB_UPDATED);
    }
  }

  return 0;
}
#endif /* #if defined(GFX_MGR02_USE_FILESYSTEM) */
#else  /* #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) */
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_image
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_image(GFX_MGR02_CONTEXT_T   const * p_cntx_SP, 
                                             GFX_MGR02_IMAGE_DEF_T const * p_elem_def_SP)
{
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
#endif
   hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);
   if(p_cntx_SP->state.invisible == 0)
   {
      GFX_MGR02_TEXTURE * fl_textture;
      UINT32              fl_least_used_index;
      fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(p_elem_def_SP, p_elem_def_SP->pixel_data);
      fl_textture = &l_gees11_img_texture[fl_least_used_index];
      if(fl_textture->id != p_elem_def_SP->pixel_data)
      {

      #if defined(GFX_MGR02_USE_FILESYSTEM)
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, FALSE, (void *)p_elem_def_SP->pixel_data, fl_textture);
      #else
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, TRUE,  (void *)p_elem_def_SP->pixel_data, fl_textture);
      #endif
         if(fl_textture != 0)
         {
            if(fl_textture->id != 0)
            {
               GLshort afVertices[4*3];
               GLfloat afTxVertices[4*2];

               afVertices[0]  = 0;
               afVertices[1]  = 0;
               afVertices[2]  = 0;
               afVertices[3]  = p_elem_def_SP->width;
               afVertices[4]  = 0;
               afVertices[5]  = 0;
               afVertices[6]  = 0;
               afVertices[7]  = p_elem_def_SP->height;
               afVertices[8]  = 0;
               afVertices[9]  = p_elem_def_SP->width;
               afVertices[10] = p_elem_def_SP->height;
               afVertices[11] = 0;

               afTxVertices[0] = 0.0f;
               afTxVertices[1] = 0.0f;
               afTxVertices[2] = ((GFX_FLOAT)p_elem_def_SP->width/(GFX_FLOAT)fl_textture->texw);
               afTxVertices[3] = 0.0f;
               afTxVertices[4] = 0.0f;
               afTxVertices[5] = ((GFX_FLOAT)p_elem_def_SP->height/(GFX_FLOAT)fl_textture->texh);
               afTxVertices[6] = afTxVertices[2];
               afTxVertices[7] = afTxVertices[5];

               glDisableClientState(GL_COLOR_ARRAY);
               glEnableClientState(GL_VERTEX_ARRAY);
               glEnableClientState(GL_TEXTURE_COORD_ARRAY);
               glVertexPointer(3, GL_SHORT, 0, afVertices);
               glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
               glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
               l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
            }
         }
      }
   }
   return 0;
}
#if defined(GFX_MGR02_USE_FILESYSTEM)
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_uimage
Description          : Builds a image object
Invocation           : Invoked internally
Parameters           : element definition
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_uimage(GFX_MGR02_CONTEXT_T   const* p_cntx_SP,
  GFX_MGR02_IMAGE_DEF_T const* p_elem_def_SP)
{
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
  hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
#endif
  hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);
  if (p_cntx_SP->state.invisible == 0)
  {
    GFX_MGR02_TEXTURE* fl_textture;
    UINT32              fl_least_used_index;
    fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(p_elem_def_SP, p_elem_def_SP->pixel_data);
    fl_textture = &l_gees11_img_texture[fl_least_used_index];
    if (fl_textture->id != p_elem_def_SP->pixel_data)
    {
      fl_textture = hmi_gfx_mgr02_ogllib_create_tex(p_elem_def_SP, GL_CLAMP_TO_EDGE, TRUE, (void*)p_elem_def_SP->pixel_data, fl_textture);
    }
    if (fl_textture != 0)
    {
      if (fl_textture->id != 0)
      {
        GLshort afVertices[4 * 3];
        GLfloat afTxVertices[4 * 2];

        afVertices[0] = 0;
        afVertices[1] = 0;
        afVertices[2] = 0;
        afVertices[3] = p_elem_def_SP->width;
        afVertices[4] = 0;
        afVertices[5] = 0;
        afVertices[6] = 0;
        afVertices[7] = p_elem_def_SP->height;
        afVertices[8] = 0;
        afVertices[9] = p_elem_def_SP->width;
        afVertices[10] = p_elem_def_SP->height;
        afVertices[11] = 0;

        afTxVertices[0] = 0.0f;
        afTxVertices[1] = 0.0f;
        afTxVertices[2] = ((GFX_FLOAT)p_elem_def_SP->width / (GFX_FLOAT)fl_textture->texw);
        afTxVertices[3] = 0.0f;
        afTxVertices[4] = 0.0f;
        afTxVertices[5] = ((GFX_FLOAT)p_elem_def_SP->height / (GFX_FLOAT)fl_textture->texh);
        afTxVertices[6] = afTxVertices[2];
        afTxVertices[7] = afTxVertices[5];

        glDisableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_SHORT, 0, afVertices);
        glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
#ifdef OGL_DIRECT_TEXTURE_RENDERING
        if (p_elem_def_SP->format == VG_sRGBA_8888_VIV)
        {
          if (hmi_gfx_mgr02_SetupglTexDirectVIV())
          {
            glBindTexture(GL_TEXTURE_2D, fl_textture->texId);
            l_gl_TexDirectInvalidateVIV_Fptr(GL_TEXTURE_2D);
          }
        }
#endif
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING | GFX_MGR02_OGLLIB_FB_UPDATED);
      }
    }

  }
  return 0;
}
#endif /* #if defined(GFX_MGR02_USE_FILESYSTEM) */
#endif /* #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) */

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_clear_buffer
Description          : Clears the framebuffer with passed color
Invocation           : Invoked internally
Parameters           : fill color
Return Value         : 
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_clear_buffer(GFX_MGR02_CONTEXT_T const * p_cntx_SP, UINT32 p_clear_color)
{
   GLfloat fl_rgba[4];
   fl_rgba[0] = GM2_GCFR(p_clear_color);
   fl_rgba[1] = GM2_GCFG(p_clear_color);
   fl_rgba[2] = GM2_GCFB(p_clear_color);
   fl_rgba[3] = GM2_GCFA(p_clear_color);
   glClearColor(fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]);
   glClear(GL_COLOR_BUFFER_BIT);
   l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
   return(0);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_fill
Description          : Builds a fill object
Invocation           : Invoked internally
Parameters           : element definition and dimention of fill area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_fill(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_FILL_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{
   if(p_cntx_SP->state.invisible == 0)
   {
   #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
      SINT32     fl_location;
   #endif   
      GLfloat fl_rgba[4];
      GLfloat afVertices[4 * 3];

   #if defined(GFX_MGR02_CLIPPED_WIDGETS)
      hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
   #endif
      if((p_elem_def_SP->dim.width  == p_cntx_SP->rprop.fb_w) && 
         (p_elem_def_SP->dim.height == p_cntx_SP->rprop.fb_h))
      {
         hmi_gfx_mgr02_ogllib_clear_buffer(p_cntx_SP, p_cntx_SP->rprop.fg_color);
      }
      else
      {
         hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);

         fl_rgba[3] = GM2_GCFA(p_cntx_SP->rprop.fg_color);
         if(p_cntx_SP->state.alpha < 255)
         {
            fl_rgba[3] *= ((GFX_FLOAT)p_cntx_SP->state.alpha);
            fl_rgba[3] /= 255.0f;
         }
         fl_rgba[0] = GM2_GCFR(p_cntx_SP->rprop.fg_color);
         fl_rgba[1] = GM2_GCFG(p_cntx_SP->rprop.fg_color);
         fl_rgba[2] = GM2_GCFB(p_cntx_SP->rprop.fg_color);
         if(fl_rgba[3] == 0)
         {
            /* if fill screen is transparent, then use below blend mode , otherwise below buffer wont change */
            glBlendFuncSeparate(GL_ONE, GL_ZERO, GL_ONE, GL_ZERO);
         }  

       #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         glColor4f(fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]);
       #endif

         afVertices[0]  = 0.0f;
         afVertices[1]  = 0.0f;
         afVertices[2]  = 0.0f; 
         afVertices[3]  = (GFX_FLOAT)(p_dim->width);
         afVertices[4]  = 0.0f;
         afVertices[5]  = 0.0f;
         afVertices[6]  = 0.0f;
         afVertices[7]  = (GFX_FLOAT)(p_dim->height);
         afVertices[8]  = 0.0f; 
         afVertices[9]  = (GFX_FLOAT)(p_dim->width);
         afVertices[10] = (GFX_FLOAT)(p_dim->height);
         afVertices[11] = 0.0f; 

      #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
         glUseProgram(l_ogl_egl_context_S.fillProgramObject);
         glBufferData(GL_ARRAY_BUFFER, sizeof(afVertices), afVertices, GL_STATIC_DRAW);
         fl_location = glGetUniformLocation(l_ogl_egl_context_S.fillProgramObject, "MVPMatrix");
         glUniformMatrix4fv( fl_location, 1, GL_FALSE, pfIdentity);
         fl_location = glGetUniformLocation(l_ogl_egl_context_S.fillProgramObject, "fillColor");
         glUniform4f(fl_location, fl_rgba[0], fl_rgba[1], fl_rgba[2], fl_rgba[3]);
         glBindAttribLocation(l_ogl_egl_context_S.fillProgramObject, VERTEX_ARRAY, "inVertex");
         glEnableVertexAttribArray(VERTEX_ARRAY);
         glVertexAttribPointer(VERTEX_ARRAY, 3, GL_FLOAT, GL_FALSE, 0, 0);
         glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
         glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
      #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         glDisable(GL_TEXTURE_2D);
         glEnableClientState(GL_VERTEX_ARRAY);
         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
         glDisableClientState(GL_COLOR_ARRAY);
         glVertexPointer(3, GL_FLOAT, 0, afVertices);
         glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
         glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
      #endif
         l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
      }
   }
   return 0;
}
#if ((GFX_MGR02_NUM_OF_TILES > 0) && (GFX_MGR02_NUM_OF_IMAGE_LAYERS > 0))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_tile
Description          : Builds a tile object
Invocation           : Invoked internally
Parameters           : element definition and dimention of tile area
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
s_gx_flocal hmi_gfx_mgr02_ogllib_build_tile(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TILE_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{
   GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP = &lc_image_layer_def_S[p_elem_def_SP->id];
   
#if defined(GFX_MGR02_CLIPPED_WIDGETS)
   hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
#endif
   hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);

   if(p_cntx_SP->state.invisible == 0)
   {
      GLuint              fl_location;
      GFX_MGR02_TEXTURE * fl_textture;
      UINT32              fl_least_used_index;

      fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(fl_element_def_SP, fl_element_def_SP->pixel_data);
      fl_textture = &l_gees11_img_texture[fl_least_used_index];
      if(fl_textture->id != fl_element_def_SP->pixel_data)
      {
      #if defined(GFX_MGR02_USE_FILESYSTEM)
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(fl_element_def_SP, GL_REPEAT, FALSE, (void *)fl_element_def_SP->pixel_data, fl_textture);
      #else
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(fl_element_def_SP, GL_REPEAT, TRUE,  (void *)fl_element_def_SP->pixel_data, fl_textture);
      #endif

         if(fl_textture != 0)
         {
            l_texture_vertex[0]  = 0.0f;
            l_texture_vertex[1]  = 0.0f;
            l_texture_vertex[5]  = (GFX_FLOAT)(p_dim->width);
            l_texture_vertex[6]  = 0.0f;
            l_texture_vertex[10] = 0.0f;
            l_texture_vertex[11] = (GFX_FLOAT)(p_dim->height);
            l_texture_vertex[15] = (GFX_FLOAT)(p_dim->width);
            l_texture_vertex[16] = (GFX_FLOAT)(p_dim->height);
      
            l_texture_vertex[8]   = (GFX_FLOAT)(p_dim->width);
            l_texture_vertex[8]  /= (GFX_FLOAT)(fl_element_def_SP->width);
            l_texture_vertex[14]  = (GFX_FLOAT)(p_dim->height);
            l_texture_vertex[14] /= (GFX_FLOAT)(fl_element_def_SP->height);
            l_texture_vertex[18]  = l_texture_vertex[8];
            l_texture_vertex[19]  = l_texture_vertex[14];

            glUseProgram(fl_textture->po);
            fl_location = glGetUniformLocation(fl_textture->po, "MVPMatrix");
            glUniformMatrix4fv( fl_location, 1, GL_FALSE, pfIdentity);

            fl_location = glGetUniformLocation(fl_textture->po, "s_texture");
            glUniform1i(fl_location, 0);

            glBufferData(GL_ARRAY_BUFFER, 4*5*sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
            fl_location = glGetAttribLocation(fl_textture->po, "a_position");
            glEnableVertexAttribArray(fl_location);
            glVertexAttribPointer(fl_location, 
                                  3, 
                                  GL_FLOAT, 
                                  GL_FALSE, 
                                  (5 * sizeof(GLfloat)), 
                                  0);
            fl_location = glGetAttribLocation(fl_textture->po, "tpos");
            glEnableVertexAttribArray(fl_location);
            glVertexAttribPointer(fl_location, 
                                  2, 
                                  GL_FLOAT, 
                                  GL_FALSE, 
                                  (5 * sizeof(GLfloat)), 
                                  (void*)(3 * sizeof(GLfloat)));
            fl_location = glGetUniformLocation(fl_textture->po, "Alpha");
            glUniform1f(fl_location, (p_cntx_SP->state.alpha/255.0f));
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
            l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
         }
      }
   }
   return 0;
}
 #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
s_gx_flocal hmi_gfx_mgr02_ogllib_build_tile(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TILE_DEF_T const * p_elem_def_SP, 
                                            GFX_MGR02_IDIM_DATA  const * p_dim)
{
   GFX_MGR02_IMAGE_DEF_T const * fl_element_def_SP = &lc_image_layer_def_S[p_elem_def_SP->id];
   
   hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);

   if(p_cntx_SP->state.invisible == 0)
   {
      GFX_MGR02_TEXTURE * fl_textture;
      UINT32              fl_least_used_index;
      GLshort afVertices[4*3];
      GLfloat afTxVertices[4*2];
      
      afVertices[2]   = 0; 
      afVertices[5]   = 0;
      afVertices[8]   = 0; 
      afVertices[11]  = 0; 
      afTxVertices[0] = 0.0f;
      afTxVertices[1] = 0.0f;
      afTxVertices[3] = 0.0f;
      afTxVertices[4] = 0.0f;



      fl_least_used_index = hmi_gfx_mgr02_ogllib_get_image_tex(fl_element_def_SP, fl_element_def_SP->pixel_data);
      fl_textture = &l_gees11_img_texture[fl_least_used_index];
      if(fl_textture->id != fl_element_def_SP->pixel_data)
      {

      #if defined(GFX_MGR02_USE_FILESYSTEM)
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(fl_element_def_SP, GL_REPEAT, FALSE, (void *)fl_element_def_SP->pixel_data, fl_textture);
      #else
         fl_textture = hmi_gfx_mgr02_ogllib_create_tex(fl_element_def_SP, GL_REPEAT, TRUE,  (void *)fl_element_def_SP->pixel_data, fl_textture);
      #endif

         if(fl_textture != 0)
         {
            if(fl_textture->id == 0)
            {
            }
            else if((fl_textture->texw == fl_element_def_SP->width) &&
                    (fl_textture->texh == fl_element_def_SP->height))
            {
               afVertices[0]  = 0;
               afVertices[1]  = 0;
               afVertices[3]  = p_dim->width;
               afVertices[4]  = 0;
               afVertices[6]  = 0;
               afVertices[7]  = p_dim->height;
               afVertices[9]  = p_dim->width;
               afVertices[10] = p_dim->height;

               afTxVertices[2]  = (GFX_FLOAT)(p_dim->width);
               afTxVertices[2] /= (GFX_FLOAT)fl_textture->texw;
               afTxVertices[5]  = (GFX_FLOAT)(p_dim->height);
               afTxVertices[5] /= (GFX_FLOAT)fl_textture->texh;
               afTxVertices[6]  = afTxVertices[2];
               afTxVertices[7]  = afTxVertices[5];

            #if defined(GFX_MGR02_CLIPPED_WIDGETS)
               hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
            #endif
               glDisableClientState(GL_COLOR_ARRAY);
               glEnableClientState(GL_VERTEX_ARRAY);
               glEnableClientState(GL_TEXTURE_COORD_ARRAY);
               glVertexPointer(3, GL_SHORT, 0, afVertices);
               glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
               glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
            }
            else
            {
               UINT32 fl_hloop = ((p_dim->width  + (fl_element_def_SP->width-1))/fl_element_def_SP->width);
               UINT32 fl_vloop = ((p_dim->height + (fl_element_def_SP->height-1))/fl_element_def_SP->height);
               UINT32 fl_hloop_cur;
               SINT32 fl_xoff = 0;
               SINT32 fl_yoff = 0;

            #if !defined(GFX_MGR02_CLIPPED_WIDGETS)
               SINT32 clip_rect[4];
               clip_rect[0] = p_cntx_SP->state.loc.x;
               clip_rect[1] = ((p_cntx_SP->rprop.fb_h-p_cntx_SP->state.loc.y)-p_dim->height);
               clip_rect[2] = p_dim->width;
               clip_rect[3] = p_dim->height;
               glEnable(GL_SCISSOR_TEST);
               glScissor(clip_rect[0], clip_rect[1], clip_rect[2], clip_rect[3]);
            #else
               GFX_MGR02_IAREA_DATA fl_clip;
               fl_clip.x      = p_cntx_SP->state.loc.x;
               fl_clip.y      = p_cntx_SP->state.loc.y;
               fl_clip.width  = p_dim->width;
               fl_clip.height = p_dim->height;
               hmi_gfx_mgr02_context_set_clip(&fl_clip);
               hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
            #endif

               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,  GL_CLAMP_TO_EDGE);
               glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,  GL_CLAMP_TO_EDGE);

               while(fl_vloop > 0)
               {
                  fl_vloop--;
                  fl_xoff      = 0;
                  fl_hloop_cur = fl_hloop;
                  while(fl_hloop_cur > 0)
                  {
                     fl_hloop_cur--;

                     afVertices[0]  = (GLshort)fl_xoff;
                     afVertices[1]  = (GLshort)fl_yoff;
                     afVertices[3]  = (GLshort)(fl_xoff+fl_element_def_SP->width);
                     afVertices[4]  = (GLshort)fl_yoff;
                     afVertices[6]  = (GLshort)fl_xoff;
                     afVertices[7]  = (GLshort)(fl_yoff+fl_element_def_SP->height);
                     afVertices[9]  = (GLshort)(fl_xoff+fl_element_def_SP->width);
                     afVertices[10] = (GLshort)(fl_yoff+fl_element_def_SP->height);

                     afTxVertices[2] = ((GFX_FLOAT)fl_element_def_SP->width/(GFX_FLOAT)fl_textture->texw);
                     afTxVertices[5] = ((GFX_FLOAT)fl_element_def_SP->height/(GFX_FLOAT)fl_textture->texh);
                     afTxVertices[6] = afTxVertices[2];
                     afTxVertices[7] = afTxVertices[5];

                     glDisableClientState(GL_COLOR_ARRAY);
                     glEnableClientState(GL_VERTEX_ARRAY);
                     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                     glVertexPointer(3, GL_SHORT, 0, afVertices);
                     glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
                     glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                     fl_xoff += fl_element_def_SP->width;
                  }
                  fl_yoff += fl_element_def_SP->height;
               }
            #if !defined(GFX_MGR02_CLIPPED_WIDGETS)
               glDisable(GL_SCISSOR_TEST);
            #endif
            }
            l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
         }
      }
   }
   return(0);
}
 #endif
#endif

#ifdef GFX_MGR02_TEXT_COLOR_CODE_PREFIX
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_set_text_color
Description          : Decodes embedded color information and sets the color
Invocation           : Invoked internally
Parameters           : pointer to string and its length
Return Value         : number of entries processed
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static s_gx_flocal hmi_gfx_mgr02_ogllib_set_text_color(UINT32 p_string_len, HMI_CHAR const * p_string_ptr)
{
   s_gx_flocal fl_length = 0;
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
   GLuint i32Location;
#endif
   if(p_string_ptr[0] == GFX_MGR02_TEXT_COLOR_CODE_PREFIX)
   {
   #if GFX_MGR02_UNICODE != 0
      if(p_string_len >= 2)
      {
      #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         UINT32 fl_r = (UINT8)(p_string_ptr[1]>>8);
         UINT32 fl_g = (UINT8)p_string_ptr[1];
         UINT32 fl_b = (UINT8)(p_string_ptr[2]>>8);
         UINT32 fl_a = (UINT8)p_string_ptr[2];
         glColor4ub(fl_r,fl_g,fl_b,fl_a);
      #else
         GLfloat fl_r = ((UINT8)(p_string_ptr[1]>>8))/255.0f;
         GLfloat fl_g = ((UINT8)p_string_ptr[1])/255.0f;
         GLfloat fl_b = ((UINT8)(p_string_ptr[2]>>8))/255.0f;
         GLfloat fl_a = ((UINT8)p_string_ptr[2])/255.0f;
         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "fgColor");
         glUniform4f(i32Location, fl_r, fl_g, fl_b, fl_a);
      #endif
         fl_length = 3;
      }
   #else
      if(p_string_len >= 4)
      {
      #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         UINT32 fl_r = p_string_ptr[1];
         UINT32 fl_g = p_string_ptr[2];
         UINT32 fl_b = p_string_ptr[3];
         UINT32 fl_a = p_string_ptr[4];
         glColor4ub(fl_r,fl_g,fl_b,fl_a);
      #else
         GLfloat fl_r = p_string_ptr[1];
         GLfloat fl_g = p_string_ptr[2];
         GLfloat fl_b = p_string_ptr[3];
         GLfloat fl_a = p_string_ptr[4];
         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "fgColor");
         glUniform4f(i32Location, fl_r, fl_g, fl_b, fl_a);
      #endif
         fl_length = 5;
      }
   #endif
   }
   return(fl_length);
}
#endif
#if (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_create_img_for_string
Description          : Creates an image for a given string
Invocation           : Invoked internally
Parameters           : --
Return Value         : --
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_create_img_for_string(UINT8 *p_str_img_SP,GFX_MGR02_CONTEXT_T  const * p_cntx_SP,
                                                       GFX_MGR02_TEXT_INFO const * p_text_info_S,GFX_MGR02_FONT const * p_font_SP)
{
  SINT32 fl_top_y_offset;
  GFX_FLOAT  fl_per;
  FT_Face      face;
  FT_GlyphSlot slot;
  UINT32       fl_font_id = hmi_gfx_mgr02_get_font_id(p_cntx_SP->rprop.font_id);
  SINT32       fl_top_y;
  FT_UInt      glyph_index;
  SINT32       fl_start_x = 0;
  UINT8        *table;
  UINT32       fl_str_length = p_text_info_S->print_length_U8;
  HMI_CHAR     const * fl_string_ptr = p_text_info_S->print_str_P;
  UINT8        *fl_bitmap_buffer;

  memset(p_str_img_SP, 0, (p_font_SP->p.height * p_text_info_S->print_width));
  face = p_cntx_SP->rprop.ft2_face[fl_font_id];
  slot = face->glyph;
  fl_per = ((GFX_FLOAT)face->descender)/(GFX_FLOAT)(face->ascender-face->descender);
  fl_top_y_offset = (SINT32)((GFX_FLOAT)p_font_SP->p.height * fl_per);
  while(fl_str_length > 0)
  {
    fl_str_length--;
    #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX) || defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
     switch(fl_string_ptr[0])
     {
      #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX)
       case GFX_MGR02_TEXT_COLOR_CODE_PREFIX:
       {
         UINT32 fl_plength;
         fl_plength     = hmi_gfx_mgr02_ogllib_set_text_color(fl_str_length, fl_string_ptr);
         fl_str_length -= fl_plength;
         fl_string_ptr += fl_plength;
       }
       break;
      #endif
      #if defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
       case GFX_MGR02_TEXT_SPACE_CODE_PREFIX:
       {
         fl_string_ptr++;
         fl_str_length--;
         if(fl_string_ptr[0] != 0)
         {
           fl_start_x += fl_string_ptr[0];
           fl_string_ptr++;
           fl_str_length--;
         }
       }
       break;
      #endif
     }
    #endif
    glyph_index = FT_Get_Char_Index(face, fl_string_ptr[0]);
    FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER|FT_LOAD_FORCE_AUTOHINT);
    if(slot->bitmap.buffer != 0)
    {
      SINT32 fl_sy;
      SINT32 fl_sx;
      fl_top_y  = fl_top_y_offset;
      fl_top_y += (p_font_SP->p.height-slot->bitmap_top);
      table = (UINT8 *) &p_str_img_SP[(fl_top_y * p_text_info_S->print_width) +(fl_start_x + slot->bitmap_left)];
      fl_bitmap_buffer = slot->bitmap.buffer;
      for(fl_sy=0; fl_sy<slot->bitmap.rows; fl_sy++)
      {
        for(fl_sx=0; fl_sx<slot->bitmap.width; fl_sx++)
        {
          *table++ = *fl_bitmap_buffer++;
        }
        table = (table + (p_text_info_S->print_width - slot->bitmap.width));
      }
      fl_start_x += (slot->advance.x>>6);
    }
    else
    {
      fl_start_x += (slot->advance.x>>6);
    }
    fl_string_ptr++;
  }
}
#endif
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_CheckFramebufferStatus
Description          : --
Invocation           : Invoked internally
Parameters           : --
Return Value         : --
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static UINT8 hmi_gfx_mgr02_ogllib_CheckFramebufferStatus()
{                                                         
  GLenum status;
  status = glCheckFramebufferStatus(GL_FRAMEBUFFER); 

  if(status == GL_FRAMEBUFFER_COMPLETE)
  {
    return 1;
  }
  else
  {
    fputs("Framebuffer status Error\n", stderr);
    return 0;
  }
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_generateBlur
Description          : Generate the blur for given radius/length
                     : and sigma/weight
Invocation           : Invoked internally
Parameters           : Glow effect parameters
Return Value         : Blur data
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_MGR02_BLUR* hmi_gfx_mgr02_ogllib_generateBlur(UINT8 p_radius, GFX_FLOAT p_sigma)
{
   SINT32 fl_length = 2 * p_radius - 1;
   GFX_FLOAT* fl_kernel = (GFX_FLOAT*) malloc(sizeof(GFX_FLOAT) * fl_length * fl_length); 
   GFX_FLOAT fl_sumTotal = 0; 
   SINT32 fl_kernelRadius = fl_length / 2; 
   GFX_FLOAT fl_distance = 0; 
   GFX_FLOAT fl_calculatedEuler = 1.0f /  (2.0f * 3.1415f * pow(p_sigma, 2)); 
   UINT32 fl_maxUniformVectors;
   UINT32 fl_array_size;
   GFX_FLOAT* fl_short_kernel;
   UINT32 fl_count = 0;
   GFX_MGR02_BLUR* fl_blur;
   SINT32 fl_y;
   SINT32 fl_x;

   glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, &fl_maxUniformVectors);
   printf("GL_MAX_FRAGMENT_UNIFORM_VECTORS=%d\n",fl_maxUniformVectors);
 
   for(fl_y = -fl_kernelRadius; fl_y <= fl_kernelRadius; fl_y++) 
   {
     for(fl_x = -fl_kernelRadius; fl_x <= fl_kernelRadius; fl_x++) 
     {
       fl_distance = ((fl_x * fl_x) +  (fl_y * fl_y)) /  (2 * (p_sigma * p_sigma)); 
       fl_kernel[(fl_y + fl_kernelRadius)*fl_length+(fl_x + fl_kernelRadius)] =  fl_calculatedEuler * exp(-fl_distance); 
       fl_sumTotal += fl_kernel[(fl_y + fl_kernelRadius)*fl_length+(fl_x + fl_kernelRadius)]; 
     } 
   } 
   for(fl_y = 0; fl_y < fl_length; fl_y++) 
   { 
     for(fl_x = 0; fl_x < fl_length; fl_x++) 
     { 
       fl_kernel[fl_y*fl_length+fl_x] = fl_kernel[fl_y*fl_length+fl_x] *  (1.0f / fl_sumTotal); 
     } 
   } 

   fl_array_size = p_radius * (p_radius+1) / 2;
   fl_array_size = ((fl_array_size/16)+1)*16;
   fl_short_kernel = (GFX_FLOAT*) malloc(sizeof(GFX_FLOAT) * fl_array_size );
   fl_count = 0;

   for(fl_y=0;fl_y<p_radius;fl_y++)
   {
     for(fl_x=0;fl_x<=fl_y;fl_x++)
     {
       fl_short_kernel[fl_count]=fl_kernel[fl_y*fl_length+fl_x];
       fl_count++;
     }
   }
   free(fl_kernel);
 
   fl_blur = (GFX_MGR02_BLUR*) malloc(sizeof(GFX_MGR02_BLUR));
   fl_blur->kernel_data = fl_short_kernel;
   fl_blur->radius = p_radius;
   return fl_blur;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_applyBlur
Description          : Apply a blur on a given texture
Invocation           : Invoked internally
Parameters           : Blur data,texture and shader id
Return Value         : FB data
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static GFX_MGR02_FBO* hmi_gfx_mgr02_ogllib_applyBlur(GLint p_shader_id, GFX_MGR02_TEXTURE* p_texture, GFX_MGR02_BLUR* p_blur)
{
   UINT32 fl_start_time = 0;
   UINT32 fl_end_time = 0;
   SINT32 fl_s;
   GFX_FLOAT fl_rectSize = 2.0f;
   GFX_FLOAT fl_xMin=-1.0f, fl_yMin=-1.0f;
   GFX_FLOAT fl_xMax=fl_xMin + fl_rectSize, fl_yMax= fl_yMin + fl_rectSize;

   GLint fl_positionLoc = -1, fl_texCoordLoc = -1, fl_loc = -1;
   GLint fl_fbo_width = p_texture->width + (p_blur->radius-1) * 2;
   GLint fl_fbo_height = p_texture->height + (p_blur->radius-1) * 2;

   GFX_FLOAT fl_blur_x_margin = (GFX_FLOAT)(p_blur->radius-1) / (GFX_FLOAT)p_texture->width;
   GFX_FLOAT fl_blur_y_margin = (GFX_FLOAT)(p_blur->radius-1) / (GFX_FLOAT)p_texture->height;

   /* blur passes */
   GLfloat fl_vVertices[] = {
                              fl_xMin,                  fl_yMax,                0.0f,   /* Position 0 */
                              0.0f-fl_blur_x_margin,    1.0f+fl_blur_y_margin,          /* TexCoord 1 */
                              fl_xMin,                  fl_yMin,                0.0f,   /* Position 1 */
                              0.0f-fl_blur_x_margin,    0.0f-fl_blur_y_margin,          /* TexCoord 0 */
                              fl_xMax,                  fl_yMin,                0.0f,   /* Position 2 */
                              1.0f+fl_blur_x_margin,    0.0f-fl_blur_y_margin,          /* TexCoord 3 */
                              fl_xMax,                  fl_yMax,                0.0f,   /* Position 3 */
                              1.0f+fl_blur_x_margin,    1.0f+fl_blur_y_margin,          /* TexCoord 2 */
                            };

   GLushort fl_indices[] = { 0, 1, 2, 0, 2, 3 };
   GFX_MGR02_FBO* fl_fbo = NULL;
   GLint current_framebuffer;
   GLint current_arraybuffer;
   GLint current_texture;
   GLint current_program;
   GLint viewport[4];
   GLfloat clear_color[4];
   GLboolean scissor_test_state;

   // take backup of the current state about to be modified
   glGetIntegerv(GL_TEXTURE_BINDING_2D, &current_texture);
   glGetIntegerv(GL_CURRENT_PROGRAM, &current_program);
   glGetIntegerv(GL_FRAMEBUFFER_BINDING, &current_framebuffer);
   glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &current_arraybuffer);
   glGetIntegerv(GL_VIEWPORT, viewport);
   glGetFloatv(GL_COLOR_CLEAR_VALUE, clear_color);
   scissor_test_state = glIsEnabled( GL_SCISSOR_TEST );

   /* Generate frame buffer object   */
   {

     GLuint framebuffer;
     GLuint colorbuffer;
     GLuint depthbuffer;

     glGenFramebuffers(1, &framebuffer);

     glGenTextures(1, &colorbuffer);

     glGenRenderbuffers(1, &depthbuffer);

     printf("Framebuffer=%d,ColoBuffer=%d,DepthBuffer=%d\n",framebuffer,colorbuffer,depthbuffer);

     glBindTexture(GL_TEXTURE_2D, colorbuffer);
     glTexImage2D(GL_TEXTURE_2D, 
                  0, 
                  GL_RGBA, 
                  fl_fbo_width, fl_fbo_height,
                  0, 
                  GL_RGBA, 
                  GL_UNSIGNED_BYTE, 
                  NULL);
    
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

     glBindRenderbuffer(GL_RENDERBUFFER, depthbuffer);
     glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, fl_fbo_width, fl_fbo_height);

     glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
     glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorbuffer, 0);
     glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthbuffer);

     if(hmi_gfx_mgr02_ogllib_CheckFramebufferStatus() == TRUE)
     {
       glBindBuffer(GL_ARRAY_BUFFER, 0);
       glUseProgram(p_shader_id);

       /* vertex */
       fl_positionLoc = glGetAttribLocation ( p_shader_id, "a_position" );
       if(fl_positionLoc != -1)
       {
            glVertexAttribPointer ( fl_positionLoc, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), fl_vVertices );
            glEnableVertexAttribArray ( fl_positionLoc );
       }

       /* tex coord */
       fl_texCoordLoc = glGetAttribLocation ( p_shader_id, "a_texCoord" );
       if(fl_texCoordLoc != -1)
       {
            glVertexAttribPointer ( fl_texCoordLoc, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), &fl_vVertices[3] );
            glEnableVertexAttribArray ( fl_texCoordLoc );
       }

       glActiveTexture ( GL_TEXTURE0 );
       glBindTexture ( GL_TEXTURE_2D, p_texture->texId);
       fl_loc = glGetUniformLocation(p_shader_id, "texture");
       if (fl_loc != -1)
       {
         glUniform1i(fl_loc, 0);
       }
       fl_loc = glGetUniformLocation(p_shader_id, "textureSize");
       if (fl_loc != -1)
       {
         glUniform2f(fl_loc, (GLfloat)p_texture->width, (GLfloat)p_texture->height);
       }
       fl_s = p_blur->radius*(p_blur->radius+1) / 2;
       fl_s = ((fl_s/16)+1)*16;
       fl_s = fl_s / 16;
       fl_loc = glGetUniformLocation(p_shader_id, "kernel_data");
       if (fl_loc != -1)
       {
         glUniformMatrix4fv(fl_loc, fl_s, GL_FALSE, p_blur->kernel_data);
       }
       fl_loc = glGetUniformLocation(p_shader_id, "kernel_radius");
       if (fl_loc != -1)
       {
         glUniform1f(fl_loc, (GLfloat)p_blur->radius);
       }

       printf("Rendering to frame buffer:\n");
  
       glViewport( 0, 0, fl_fbo_width, fl_fbo_height );
       glDisable(GL_SCISSOR_TEST);
       glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
       glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, fl_indices);
       glFinish();

       fl_fbo = (GFX_MGR02_FBO*) malloc(sizeof(GFX_MGR02_FBO));
       fl_fbo->height = fl_fbo_height;
       fl_fbo->width= fl_fbo_width;
       fl_fbo->ColorAttachmentId = colorbuffer;

       fl_end_time = 0;
       printf("Time to blur = %d ms\n",fl_end_time-fl_start_time);
     }
     else
     {
       printf("Unable to apply blur because of frame buffer error!\n");
     }
   }

   //restore the backed up state
   glBindTexture(GL_TEXTURE_2D, current_texture);
   glUseProgram(current_program);
   glBindBuffer(GL_ARRAY_BUFFER, current_arraybuffer);
   glBindFramebuffer(GL_FRAMEBUFFER, current_framebuffer);
   glViewport(viewport[0],viewport[1],viewport[2],viewport[3]);
   if(scissor_test_state)
   {
       glEnable(GL_SCISSOR_TEST);
   }
   glClearColor( clear_color[0],clear_color[1],clear_color[2],clear_color[3] );

   return fl_fbo;
}
#endif //#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_build_text
Description          : Builds a text object
Invocation           : Invoked internally
Parameters           : element definition and pointer to string
Return Value         : end x point
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_build_text(GFX_MGR02_CONTEXT_T  const * p_cntx_SP, 
                                            GFX_MGR02_TEXT_DEF_T const * p_elem_def_SP, 
                                            HMI_CHAR             const * p_string,
                                            u_gx_flocal                  p_text_actual_width
#if defined(GFX_MGR02_OPEN_GL) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
                                           ,u_gx_flocal                 p_is_multi_line_text
#endif
										   )
{
   GFX_MGR02_FONT const * fl_font_SP;
   UINT32                 fl_str_length;
   HMI_CHAR       const * fl_string_ptr;
   UINT32                 fl_text_width;
   

#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
   GLuint i32Location;
#elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
   GLfloat afTxVertices[4*2];
#endif
   GFX_MGR02_IMAGE_DEF_T fl_img_elem_def_S;
   GFX_MGR02_TEXTURE   * fl_textture;
#if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
   HMI_CHAR              fl_pstring[GFX_MGR02_MAX_TEXT_LENGTH+1];
#endif
#ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
   UINT32                 fl_least_used_index;
 #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
   UINT32       fl_font_id = hmi_gfx_mgr02_get_font_id(p_elem_def_SP->font_id);
 #endif
#endif
 #if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
 #if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
   SINT16 fl_glyph_advance_x = 0;
   SINT32 fl_str_index = (SINT32)0;
 #endif
 #endif
   GFX_MGR02_TEXT_INFO fl_text_info_S;
   UINT16  fl_glow_radius_w = 0;
   GLuint fl_location;

   if(p_cntx_SP->state.invisible == 0)
   {
      fl_font_SP = hmi_gfx_mgr02_get_font_pointer(p_elem_def_SP->font_id);

      if(fl_font_SP != GFX_MGR02_NULL_PTR)
      {
         fl_text_info_S.print_str_P         = (void *)p_string;
        #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20) && (defined(GFX_MGR02_USE_EXT_FONT_ENGINE) && (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE))
         /* if string "xy" has requires 20px width and font height has 10px and radius given as 2px  
         ** then glow effect will increases the string width and hight as
         **  
         **                * ]  2px
         **                * ]
         **        2x [**  xy  ** ] 2px
         **                * ]  
         **                * ]  2px
         **
         ** Hence avail width will bt w - (2*radius) 
         */
         if(p_elem_def_SP->glow_effect != 0)
         {
           fl_glow_radius_w += (2 * p_elem_def_SP->glow_radius);
         }
       #endif
         if(p_text_actual_width != 0)
         {
           fl_text_info_S.max_available_width = (UINT16)(p_text_actual_width-fl_glow_radius_w);
         }
         else
         {
           fl_text_info_S.max_available_width = (p_cntx_SP->rprop.text_width-fl_glow_radius_w);
         }
         fl_text_info_S.target              = GFX_MGR02_TARGET_OPENGL;

      #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
      #if defined(GFX_MGR02_OPEN_GL) && (GFX_MGR02_NUM_OF_MULTI_LINE_TEXTS >  0)
        if(p_is_multi_line_text != FALSE)
        {
          fl_text_info_S.append_str         = FALSE;
        }
        else
      #endif
        {
          fl_text_info_S.append_str         = TRUE;
        }
      #else
         fl_text_info_S.append_str          = FALSE;
      #endif
         #ifdef GFX_MGR_APPEND_BASEDON_APP_IP
         fl_text_info_S.get_dynamic_clipinfo = (UINT8)TRUE;
         #endif
         fl_text_info_S.num_chars_to_process = p_elem_def_SP->num_chars;
         hmi_gfx_mgr02_get_text_width(&fl_text_info_S,
                                      p_cntx_SP->rprop.font_id,
                                      p_cntx_SP->rprop.clip_mode,
                                      p_cntx_SP->rprop.alignment
                                   #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
                                     ,fl_pstring
                                   #endif
                                     );
         fl_text_width = fl_text_info_S.print_width;
     #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
         fl_string_ptr = fl_pstring;
     #else
         fl_string_ptr = fl_text_info_S.print_str_P;
     #endif
         fl_str_length = fl_text_info_S.print_length_U8;
      }
      else
      {
         fl_text_width = 0;
      }
      if(fl_text_width > 0)
      {
         GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
         GLfloat          afVertices[4 * 3];
         GLfloat          fl_draw_color[4];
         GLfloat          fl_back_color[4];
         SINT32           fl_start_x;
         SINT32           fl_pivot_offset;

         fl_draw_color[3] = GM2_GCFA(p_cntx_SP->rprop.fg_color);
         if(p_cntx_SP->state.alpha < 255)
         {
            fl_draw_color[3] *= ((GFX_FLOAT)p_cntx_SP->state.alpha);
            fl_draw_color[3] /= 255.0f;
         }
         fl_draw_color[0] = GM2_GCFR(p_cntx_SP->rprop.fg_color);
         fl_draw_color[1] = GM2_GCFG(p_cntx_SP->rprop.fg_color);
         fl_draw_color[2] = GM2_GCFB(p_cntx_SP->rprop.fg_color);
         if(fl_text_width > p_cntx_SP->rprop.text_width)
         {
            fl_text_width = p_cntx_SP->rprop.text_width;
         }
         if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_RIGHT)) != 0)
         {
             fl_pivot_offset = (p_cntx_SP->rprop.text_width- (fl_text_width+fl_glow_radius_w));
             fl_start_x      = (SINT32)((fl_text_width+fl_glow_radius_w) -1);
         }
         else if((p_cntx_SP->rprop.alignment & (GFX_MGR02_TP_ALIGN_CENTRE)) != 0)
         {
             fl_start_x      = (SINT32)((fl_text_width+fl_glow_radius_w) >> 1);
             fl_pivot_offset = ((p_cntx_SP->rprop.text_width- (fl_text_width+fl_glow_radius_w))/2);
         }
         else
         {
             fl_start_x      = 0;
             fl_pivot_offset = 0;
         }
      #if (GFX_MGR02_NUM_TEXT_ANIM_ELEMENTS > 0) || (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
         if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_CENTRE)
         {
            /* 
            ** handle case where the current alignment is different than default alignment 
            */
            if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
            {
               fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width>>1);
            }
            else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
               fl_start_x += (SINT16)(p_cntx_SP->rprop.text_width);
            }
            else
            {
            	/*For MISRA warning fix.*/
            }
         }
         else if(p_cntx_SP->rprop.alignment == GFX_MGR02_TP_ALIGN_RIGHT)
         {
            if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_LEFT)
            {
               fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width);
            }
            else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
               fl_start_x -= (SINT16)(p_cntx_SP->rprop.text_width >> 1);
            }
            else
            {
            	/*For MISRA warning fix*/
            }
         }
         else
         {
            if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_CENTRE)
            {
               fl_start_x += (SINT16)(p_cntx_SP->rprop.text_width>>1);
            }
            else if(p_elem_def_SP->alignment == GFX_MGR02_TP_ALIGN_RIGHT)
            {
               fl_start_x += p_cntx_SP->rprop.text_width;
            }
            else
            {
            	/*For MISRA warning fix.*/
            }
         }
      #endif

         fl_start_x = -(fl_start_x+fl_pivot_offset);
         ((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->rprop.pivot.x -= fl_pivot_offset;
         /* 
         ** TODO : if we donot add this here and keep a -ve value in fl_start_x, 
         ** something goes wrong 
         ** So making the fl_start_x = 0;
         */
         ((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->state.loc.x += (SINT16)fl_start_x;
         fl_start_x = 0;
         #if defined(GFX_MGR02_CLIPPED_WIDGETS)
          hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
         #endif

         hmi_gfx_mgr02_ogllib_util_matrix_operation(p_cntx_SP);
         /*
         ** draw the background
         */
         if(p_cntx_SP->rprop.draw_mode == 0x00)
         {
            fl_back_color[3] = GM2_GCFA(p_cntx_SP->rprop.bg_color);
            if(p_cntx_SP->state.alpha < 255)
            {
               fl_back_color[3] *= ((GFX_FLOAT)p_cntx_SP->state.alpha);
               fl_back_color[3] /= 255.0f;
            }
            fl_back_color[0] = GM2_GCFR(p_cntx_SP->rprop.bg_color);
            fl_back_color[1] = GM2_GCFG(p_cntx_SP->rprop.bg_color);
            fl_back_color[2] = GM2_GCFB(p_cntx_SP->rprop.bg_color);
            afVertices[0]  = 0;
            afVertices[1]  = 0;
            afVertices[2]  = 0; 
            afVertices[3]  = (GFX_FLOAT)(fl_text_width+fl_glow_radius_w);
            afVertices[4]  = 0;
            afVertices[5]  = 0;
            afVertices[6]  = 0;
            afVertices[7]  = (GFX_FLOAT)(fl_font_SP->p.height+fl_glow_radius_w);
            afVertices[8]  = 0; 
            afVertices[9]  = (GFX_FLOAT)(fl_text_width+fl_glow_radius_w);
            afVertices[10] = (GFX_FLOAT)(fl_font_SP->p.height+fl_glow_radius_w);
            afVertices[11] = 0.0f;
         #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
            glColor4f(fl_back_color[0], fl_back_color[1], fl_back_color[2], fl_back_color[3]);
            glDisableClientState(GL_COLOR_ARRAY);
            glEnableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glVertexPointer(3, GL_FLOAT, 0, afVertices);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
         #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
            glUseProgram(l_ogl_egl_context_S.fillProgramObject);
            glBufferData(GL_ARRAY_BUFFER, sizeof(afVertices), afVertices, GL_STATIC_DRAW);
            i32Location = glGetUniformLocation(l_ogl_egl_context_S.fillProgramObject, "MVPMatrix");
            glUniformMatrix4fv( i32Location, 1, GL_FALSE, pfIdentity);
            i32Location = glGetUniformLocation(l_ogl_egl_context_S.fillProgramObject, "fillColor");
            glUniform4f(i32Location, fl_back_color[0], fl_back_color[1], fl_back_color[2], fl_back_color[3]);
            glBindAttribLocation(l_ogl_egl_context_S.fillProgramObject, VERTEX_ARRAY, "inVertex");
            glEnableVertexAttribArray(VERTEX_ARRAY);
            glVertexAttribPointer(VERTEX_ARRAY, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
         #endif
         }

      #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
         glColor4f(fl_draw_color[0], fl_draw_color[1], fl_draw_color[2], fl_draw_color[3]);
      #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
         l_texture_vertex[8]  = 1;
         l_texture_vertex[14] = 1;
         l_texture_vertex[18] = 1;
         l_texture_vertex[19] = 1;
         glUseProgram(l_ogl_egl_context_S.txtProgramObject);
         glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "MVPMatrix");
         glUniformMatrix4fv( i32Location, 1, GL_FALSE, pfIdentity);

         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "fgColor");
         glUniform4f(i32Location, fl_draw_color[0], fl_draw_color[1], fl_draw_color[2], fl_draw_color[3]);

         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "s_texture");
         glUniform1i(i32Location, 0);
         i32Location = glGetAttribLocation(l_ogl_egl_context_S.txtProgramObject, "tpos");
         glEnableVertexAttribArray(i32Location);
         glVertexAttribPointer(i32Location, 
                               2, 
                               GL_FLOAT, 
                               GL_FALSE, 
                               (5 * sizeof(GLfloat)), 
                               (void*)(3 * sizeof(GLfloat)));
         i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "Alpha");
         glUniform1f(i32Location, (p_cntx_SP->state.alpha/255.0f));
      #endif

      #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE
         if(fl_font_SP->is_ffile != FALSE)
         {
         #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE)
            if(p_elem_def_SP->text_cache == GFX_MGR02_TEXT_CACHE_DISABLE)
            {
            FT_Face      face;
            FT_GlyphSlot slot;
            SINT32 fl_top_y_offset;
            GFX_FLOAT  fl_per;
            SINT32       fl_top_y;
            FT_UInt      glyph_index;
            GFX_MGR02_OGLIB_DYN_TEX_ID fl_dtex_code;

            face = p_cntx_SP->rprop.ft2_face[fl_font_id];
            slot = face->glyph;
            fl_per = ((GFX_FLOAT)face->descender)/(GFX_FLOAT)(face->ascender-face->descender);
            fl_top_y_offset = (SINT32)((GFX_FLOAT)fl_font_SP->p.height * fl_per);
            while(fl_str_length > 0)
            {
               fl_str_length--;

            #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX) || defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
               switch(fl_string_ptr[0])
               {
               #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX)
                  case GFX_MGR02_TEXT_COLOR_CODE_PREFIX:
                  {
                     UINT32 fl_plength;
                     fl_plength     = hmi_gfx_mgr02_ogllib_set_text_color(fl_str_length, fl_string_ptr);
                     fl_str_length -= fl_plength;
                     fl_string_ptr += fl_plength;
                  }
                  break;
               #endif
               #if defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
                  case GFX_MGR02_TEXT_SPACE_CODE_PREFIX:
                  {
                     fl_string_ptr++;
                     fl_str_length--;
                     if(fl_string_ptr[0] != 0)
                     {
                        fl_start_x += fl_string_ptr[0];
                        fl_string_ptr++;
                        fl_str_length--;
                     }
                  }
                  break;
               #endif
               }
            #endif
               fl_dtex_code.b.dyn_data = 1;
               fl_dtex_code.b.obj_id   = fl_font_id;
               fl_dtex_code.b.obj_code = fl_string_ptr[0];
               fl_textture             = hmi_gfx_mgr02_get_char_cache_ptr(fl_dtex_code.id);
               if(fl_textture->id != fl_dtex_code.id)
               {
                  glyph_index = FT_Get_Char_Index(face, fl_string_ptr[0]);
                  FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER|FT_LOAD_FORCE_AUTOHINT);
                  if(slot->bitmap.buffer != 0)
                  {
                     fl_img_elem_def_S.pixel_data = slot->bitmap.buffer;
                     fl_img_elem_def_S.width      = slot->bitmap.width;
                     fl_img_elem_def_S.height     = slot->bitmap.rows;
                     fl_img_elem_def_S.format     = VG_A_8;
                  #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                     fl_img_elem_def_S.compression= GFX_MGR02_IMAGE_COMPRESSION_NONE;
                  #endif
                     fl_textture = hmi_gfx_mgr02_ogllib_create_tex(&fl_img_elem_def_S,
                                                                GL_CLAMP_TO_EDGE, 
                                                                TRUE, 
                                                                fl_dtex_code.id,
                                                                fl_textture);
                     if(fl_textture != 0)
                     {
                        fl_textture->bitmap_left = slot->bitmap_left;
                        fl_textture->bitmap_top  = slot->bitmap_top;
                        fl_textture->width       = slot->bitmap.width;
                        fl_textture->height      = slot->bitmap.rows;
                        fl_textture->xadvance    = (slot->advance.x>>6);
                     }
                  }
                  else
                  {
                      fl_start_x += (slot->advance.x>>6);
                  }
               }
               if((fl_textture != 0) && (fl_textture->id != 0))
               {
                  fl_top_y  = fl_top_y_offset;
                  fl_top_y += (fl_font_SP->p.height-fl_textture->bitmap_top);
               #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
                  afVertices[0]  = (GFX_FLOAT)(fl_start_x + fl_textture->bitmap_left);
                  afVertices[1]  = (GFX_FLOAT)fl_top_y;
                  afVertices[2]  = 0; 
                  afVertices[3]  = (GFX_FLOAT)(afVertices[0]+fl_textture->width);
                  afVertices[4]  = (GFX_FLOAT)fl_top_y;
                  afVertices[5]  = 0;
                  afVertices[6]  = (GFX_FLOAT)(fl_start_x + fl_textture->bitmap_left);
                  afVertices[7]  = (GFX_FLOAT)(fl_top_y+(GLint)fl_textture->height);
                  afVertices[8]  = 0; 
                  afVertices[9]  = (GFX_FLOAT)(afVertices[0]+fl_textture->width);
                  afVertices[10] = (GFX_FLOAT)(fl_top_y+(GLint)fl_textture->height);
                  afVertices[11] = 0; 

                  afTxVertices[0] = 0.0f;
                  afTxVertices[1] = 0.0f;
                  afTxVertices[2] = ((GFX_FLOAT)fl_textture->width/(GFX_FLOAT)fl_textture->texw);
                  afTxVertices[3] = 0.0f;
                  afTxVertices[4] = 0.0f;
                  afTxVertices[5] = ((GFX_FLOAT)fl_textture->height/(GFX_FLOAT)fl_textture->texh);
                  afTxVertices[6] = afTxVertices[2];
                  afTxVertices[7] = afTxVertices[5];
                  glEnableClientState(GL_COLOR_ARRAY);
                  glEnableClientState(GL_VERTEX_ARRAY);
                  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                  glVertexPointer(3, GL_FLOAT, 0, afVertices);
                  glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
                  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
               #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
                  l_texture_vertex[0]  = (GFX_FLOAT)(fl_start_x + fl_textture->bitmap_left);
                  l_texture_vertex[1]  = (GFX_FLOAT)fl_top_y;
                  l_texture_vertex[5]  = (GFX_FLOAT)(l_texture_vertex[0]+fl_textture->width);
                  l_texture_vertex[6]  = (GFX_FLOAT)fl_top_y;
                  l_texture_vertex[10] = (GFX_FLOAT)(fl_start_x + fl_textture->bitmap_left);
                  l_texture_vertex[11] = (GFX_FLOAT)(fl_top_y+(GLint)fl_textture->height);
                  l_texture_vertex[15] = (GFX_FLOAT)(l_texture_vertex[0]+fl_textture->width);
                  l_texture_vertex[16] = (GFX_FLOAT)(fl_top_y+(GLint)fl_textture->height);
                  glBufferData(GL_ARRAY_BUFFER, 4*5*sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
                  i32Location = glGetAttribLocation(l_ogl_egl_context_S.txtProgramObject, "a_position");
                  glEnableVertexAttribArray(i32Location);
                  glVertexAttribPointer(i32Location, 
                                        3, 
                                        GL_FLOAT, 
                                        GL_FALSE, 
                                        (5 * sizeof(GLfloat)),
                                        0);
                  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
               #endif
                  l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
                  fl_start_x += fl_textture->xadvance;
               }
               fl_string_ptr++;
            }
         }
         else
         {
            
            UINT32 fl_texture_id;
            #if defined(GFX_MGR02_CLIP_TEXT_ENABLE)
              fl_text_info_S.print_str_P = fl_string_ptr;
            #endif
              

              fl_least_used_index = hmi_gfx_mgr02_ogllib_get_text_tex(p_elem_def_SP);
              fl_textture = &l_gees11_text_texture[fl_least_used_index];
              if(fl_textture->id != p_elem_def_SP)
              {
                  HMI_CHAR * p_string;
                  UINT8 * fl_str_img_data;
                  fl_str_img_data = (UINT8 *)malloc(fl_font_SP->p.height * fl_text_info_S.print_width);
                  if(fl_str_img_data != 0)
                  {

                     hmi_gfx_mgr02_ogllib_create_img_for_string(fl_str_img_data,p_cntx_SP,&fl_text_info_S,fl_font_SP);
                     fl_img_elem_def_S.pixel_data = fl_str_img_data;
                     fl_img_elem_def_S.width      = fl_text_info_S.print_width;
                     fl_img_elem_def_S.height     = fl_font_SP->p.height;
                     fl_img_elem_def_S.format     = VG_A_8;
                    #if defined(GFX_MGR02_COMPRESSION_ENABLED)
                     fl_img_elem_def_S.compression= GFX_MGR02_IMAGE_COMPRESSION_NONE;
                    #endif
                     l_gees11_text_cache_buffer[fl_least_used_index][0] = 0;

                     fl_textture = hmi_gfx_mgr02_ogllib_create_tex(&fl_img_elem_def_S,
                                                                     GL_CLAMP_TO_EDGE, 
                                                                     TRUE, 
                                                                     (void *)p_elem_def_SP,
                                                                     fl_textture);
                     free(fl_str_img_data);

                     fl_textture->width       = fl_img_elem_def_S.width;
                     fl_textture->height      = fl_img_elem_def_S.height;
                     fl_textture->font_id     = fl_font_id;
                     /* save the textured text string */
                     if(p_elem_def_SP->dynamic != 0)
                     {
                      #if GFX_MGR02_NUM_OF_DTEXTS > 0
                         GFX_MGR02_ANIM_DATA_T * fl_anim_prop_SP = hmi_gfx_mgr02_layout_get_anim_data();
                         p_string = (void *)&fl_anim_prop_SP->dtext_str[p_elem_def_SP->string_index];
                      #endif
                     }
                     else
                     {
                      #if GFX_MGR02_NUM_OF_STEXTS > 0
                         p_string = (void *)&lc_static_text_buffer[p_elem_def_SP->string_index];
                      #endif
                     }
                     (void)HMI_STRNCPY(&l_gees11_text_cache_buffer[fl_least_used_index], p_string, p_elem_def_SP->num_chars);
                  }

                  #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
                  if(p_elem_def_SP->glow_effect != 0)
                  {
                     UINT16 fl_ex,fl_ey;
                      GFX_MGR02_BLUR *fl_blur = hmi_gfx_mgr02_ogllib_generateBlur(p_elem_def_SP->glow_radius, p_elem_def_SP->glow_sigma);
                      GFX_MGR02_FBO  *fl_fbo = hmi_gfx_mgr02_ogllib_applyBlur(l_ogl_egl_context_S.blurProgramObject, fl_textture, fl_blur);
                      if(fl_fbo != 0)
                      {
                         /* if string "xy" has requires 20px width and font height has 10px and radius given as 2px  
                         ** then glow effect will increases the string width and hight as
                         **  
                         **                * ]  2px
                         **                * ]
                         **        2x [**  xy  ** ] 2px
                         **                * ]  
                         **                * ]  2px
                         **
                            ** Hence update texture size with new texture size after blur applied 
                         */
                          fl_textture->width = fl_fbo->width;
                          fl_textture->height = fl_fbo->height;
                          fl_textture->texId = fl_fbo->ColorAttachmentId;
                          #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                          ((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->state.clip.ey = fl_fbo->height+((GFX_MGR02_CONTEXT_T *)p_cntx_SP)->state.clip.sy;
                          #endif
                          #if defined(GFX_MGR02_CLIPPED_WIDGETS)
                          hmi_gfx_mgr02_ogllib_set_clip(p_cntx_SP);
                          #endif
                      }
                      glBindTexture(GL_TEXTURE_2D, fl_textture->texId);
                      i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "MVPMatrix");
                      glUniformMatrix4fv( i32Location, 1, GL_FALSE, pfIdentity);

                      i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "fgColor");
                      glUniform4f(i32Location, fl_draw_color[0], fl_draw_color[1], fl_draw_color[2], fl_draw_color[3]);

                      i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "s_texture");
                      glUniform1i(i32Location, 0);
                      i32Location = glGetAttribLocation(l_ogl_egl_context_S.txtProgramObject, "tpos");
                      glEnableVertexAttribArray(i32Location);
                      glVertexAttribPointer(i32Location, 
                                            2, 
                                            GL_FLOAT, 
                                            GL_FALSE, 
                                            (5 * sizeof(GLfloat)), 
                                            (void*)(3 * sizeof(GLfloat)));
                      i32Location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "Alpha");
                      glUniform1f(i32Location, (p_cntx_SP->state.alpha/255.0f));
                  }
                  #endif //(GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
              }
              if((fl_textture != 0) && (fl_textture->id != 0))
              {
                #if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
                 afVertices[0]  = 0;
                 afVertices[1]  = 0;
                 afVertices[2]  = 0; 
                 afVertices[3]  = (GFX_FLOAT)fl_textture->width;
                 afVertices[4]  = 0;
                 afVertices[5]  = 0;
                 afVertices[6]  = 0;
                 afVertices[7]  = (GFX_FLOAT)(fl_textture->height);
                 afVertices[8]  = 0; 
                 afVertices[9]  = (GFX_FLOAT)(fl_textture->width);
                 afVertices[10] = (GFX_FLOAT)(fl_textture->height);
                 afVertices[11] = 0; 

                 afTxVertices[0] = 0.0f;
                 afTxVertices[1] = 0.0f;
                 afTxVertices[2] = ((GFX_FLOAT)fl_textture->width/(GFX_FLOAT)fl_textture->texw);
                 afTxVertices[3] = 0.0f;
                 afTxVertices[4] = 0.0f;
                 afTxVertices[5] = ((GFX_FLOAT)fl_textture->height/(GFX_FLOAT)fl_textture->texh);
                 afTxVertices[6] = afTxVertices[2];
                 afTxVertices[7] = afTxVertices[5];
                 glEnableClientState(GL_COLOR_ARRAY);
                 glEnableClientState(GL_VERTEX_ARRAY);
                 glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                 glVertexPointer(3, GL_FLOAT, 0, afVertices);
                 glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
                 glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                #elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
                  l_texture_vertex[0]  = 0;
                  l_texture_vertex[1]  = 0;
                  l_texture_vertex[5]  = (GFX_FLOAT)(fl_textture->width);
                  l_texture_vertex[6]  = 0;
                  l_texture_vertex[10] = 0;
                  l_texture_vertex[11] = (GFX_FLOAT)(fl_textture->height);
                  l_texture_vertex[15] = (GFX_FLOAT)(fl_textture->width);
                  l_texture_vertex[16] = (GFX_FLOAT)(fl_textture->height);
                  l_texture_vertex[8]  = 1.0f;
                  l_texture_vertex[14] = 1.0f;
                  l_texture_vertex[18] = 1.0f;
                  l_texture_vertex[19] = 1.0f;

                  glBufferData(GL_ARRAY_BUFFER, 4*5*sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
                 i32Location = glGetAttribLocation(l_ogl_egl_context_S.txtProgramObject, "a_position");
                 glEnableVertexAttribArray(i32Location);
                 glVertexAttribPointer(i32Location, 
                                           3, 
                                           GL_FLOAT, 
                                           GL_FALSE, 
                                           (5 * sizeof(GLfloat)),
                                           0);
                 glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
               #endif
                l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
              }
            }
            #endif /* #if (GFX_MGR02_EXT_FONT_ENGINE == GFX_MGR02_FREETYPE) */
         }
         else
      #endif /* #ifdef GFX_MGR02_USE_EXT_FONT_ENGINE */
         {
		    
            while(fl_str_length > 0)
            {
               fl_str_length--;

            #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX) || defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
               switch(fl_string_ptr[0])
               {
               #if defined(GFX_MGR02_TEXT_COLOR_CODE_PREFIX)
                  case GFX_MGR02_TEXT_COLOR_CODE_PREFIX:
                  {
                     UINT32 fl_plength;
                     fl_plength     = hmi_gfx_mgr02_ogllib_set_text_color(fl_str_length, fl_string_ptr);
                     fl_str_length -= fl_plength;
                     fl_string_ptr += fl_plength;
                  }
                  break;
               #endif
               #if defined(GFX_MGR02_TEXT_SPACE_CODE_PREFIX)
                  case GFX_MGR02_TEXT_SPACE_CODE_PREFIX:
                  {
                     fl_string_ptr++;
                     fl_str_length--;
                     if(fl_string_ptr[0] != 0)
                     {
                        fl_start_x += fl_string_ptr[0];
                        fl_string_ptr++;
                        fl_str_length--;
                     }
                  }
                  break;
               #endif
               }
            #endif

               fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.lut_ptr, fl_font_SP->size_table, 
                                                    #if defined (GFX_MGR02_DEFAULT_FONT) && (GFX_MGR02_NUM_OF_FONT_GROUPS > 0)
                                                      p_elem_def_SP->font_id,
                                                    #endif
                                                      FALSE);
               if (fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
               {
                 if (fl_font_fcc_SP->fdata != 0)
                 {
                   GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0f, 0.0f };
                   fl_img_elem_def_S.pixel_data = (void*)fl_font_fcc_SP->fdata;
                   fl_img_elem_def_S.width = fl_font_fcc_SP->width;
                   fl_img_elem_def_S.height = fl_font_fcc_SP->height;
                   fl_img_elem_def_S.format = VG_A_8;
#if defined(GFX_MGR02_COMPRESSION_ENABLED)
                   fl_img_elem_def_S.compression = GFX_MGR02_IMAGE_COMPRESSION_NONE;
#endif

                   fl_textture = hmi_gfx_mgr02_get_char_cache_ptr(fl_img_elem_def_S.pixel_data);
                   if ((fl_textture != 0) && (fl_textture->id != fl_img_elem_def_S.pixel_data))
                   {
                     fl_textture = hmi_gfx_mgr02_ogllib_create_tex(&fl_img_elem_def_S,
                       GL_CLAMP_TO_EDGE,
                       TRUE,
                       fl_img_elem_def_S.pixel_data,
                       fl_textture);

                   }
                   if ((fl_textture != 0) && (fl_textture->id != 0))
                   {
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
                     GFX_MGR02_GPOS_DELTA fl_gpos_info = { 0.0f, 0.0f };
                     UINT8 fl_gpos_found = GFX_MGR02_GPOS_INVALID_TBL;
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
                     if ((GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U) || (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
                     if (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U)
#else
                     if (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U)
#endif
                     {
                       (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, (fl_string_ptr - 1), fl_str_index, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
                       /*X offset of the mark char should be positioned based on the previouse base char.
                       For LTR languages, mark char will come after the base char. While rendering base char
                       we are moving the x position based on owidth of the same. Hence the mark char
                       position is adjusted based on previous base char position.
                       Here fl_glyph_advance_x holds the owidth of the previous char*/
                       fl_delta_pixels.gpos_delta_pixels_x -= (GFX_FLOAT)(fl_glyph_advance_x);
                       /*This line is necessary to achieve the exact position required.Due to typecast,the value is floored up
                       but expectation is to floor down.*/
                       fl_delta_pixels.gpos_delta_pixels_x -= 0.5f;
                       fl_delta_pixels.gpos_delta_pixels_y -= 0.5f;
                     }
                     else
                     {
                       fl_glyph_advance_x = 0;
                     }
                     /*Store the owidth of the current char if is there any GPOS table found for the current and next char
                     combination*/
                     fl_gpos_found = hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_gpos_info, &fl_string_ptr[0], fl_str_index, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_LTR);
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) && defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
                     if (((fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U)) ||
                       ((fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U)))
#elif defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED)
                     if ((fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL) && (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[1]) == 1U))
#else
                     if ((fl_gpos_found != GFX_MGR02_GPOS_INVALID_TBL) && (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[1]) == 1U))
#endif
                     {
                       if (fl_gpos_found == GFX_MGR02_GPOS_M2M_TBL)
                       {
                         fl_glyph_advance_x = 0;
                       }
                       fl_glyph_advance_x += (SINT16)fl_font_fcc_SP->owidth;
                     }
#endif /* GFX_MGR02_THAI_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
                     if (GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U)
                     {
                       (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
                       /*This line is necessary to achieve the exact position required.Due to typecast,the value is floored up
                       but expectation is to floor down.*/
                       fl_delta_pixels.gpos_delta_pixels_x -= 0.5f;
                     }
#endif /* GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED */
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
                     if (GFX_MGR02_IS_HEBREW_VOWEL(fl_string_ptr[0]) == 1U)
                     {
                       (void)hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, fl_font_SP, p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
                       /*This line is necessary to achieve the exact position required.Due to typecast,the value is floored up
               but expectation is to floor down.*/
                       fl_delta_pixels.gpos_delta_pixels_x -= 0.5f;
                     }
#endif /* GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED */
#endif /* GFX_MGR02_FONT_GPOS_TABLE_ENABLED */
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
                     afVertices[0] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->x_soffset);
                     afVertices[1] = (GFX_FLOAT)fl_font_fcc_SP->y_soffset;
                     afVertices[2] = 0;
                     afVertices[3] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->width);
                     afVertices[4] = (GFX_FLOAT)fl_font_fcc_SP->y_soffset;
                     afVertices[5] = 0;
                     afVertices[6] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->x_soffset);
                     afVertices[7] = (GFX_FLOAT)(fl_font_fcc_SP->y_soffset + (GLint)fl_font_fcc_SP->height);
                     afVertices[8] = 0;
                     afVertices[9] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->width);
                     afVertices[10] = (GFX_FLOAT)(fl_font_fcc_SP->y_soffset + (GLint)fl_font_fcc_SP->height);
                     afVertices[11] = 0;

                     afTxVertices[0] = 0.0f;
                     afTxVertices[1] = 0.0f;
                     afTxVertices[2] = ((GFX_FLOAT)fl_font_fcc_SP->width / (GFX_FLOAT)fl_textture->texw);
                     afTxVertices[3] = 0.0f;
                     afTxVertices[4] = 0.0f;
                     afTxVertices[5] = ((GFX_FLOAT)fl_font_fcc_SP->height / (GFX_FLOAT)fl_textture->texh);
                     afTxVertices[6] = afTxVertices[2];
                     afTxVertices[7] = afTxVertices[5];
                     glEnableClientState(GL_COLOR_ARRAY);
                     glEnableClientState(GL_VERTEX_ARRAY);
                     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                     glVertexPointer(3, GL_FLOAT, 0, afVertices);
                     glTexCoordPointer(2, GL_FLOAT, 0, afTxVertices);
                     glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
#elif (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20)
                     l_texture_vertex[0] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->x_soffset + fl_delta_pixels.gpos_delta_pixels_x);
                     l_texture_vertex[1] = (GFX_FLOAT)fl_font_fcc_SP->y_soffset - fl_delta_pixels.gpos_delta_pixels_y;
                     l_texture_vertex[5] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->width + fl_font_fcc_SP->x_soffset + fl_delta_pixels.gpos_delta_pixels_x);
                     l_texture_vertex[6] = (GFX_FLOAT)fl_font_fcc_SP->y_soffset - fl_delta_pixels.gpos_delta_pixels_y;
                     l_texture_vertex[10] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->x_soffset + fl_delta_pixels.gpos_delta_pixels_x);
                     l_texture_vertex[11] = (GFX_FLOAT)(fl_font_fcc_SP->y_soffset - fl_delta_pixels.gpos_delta_pixels_y + (GLint)fl_font_fcc_SP->height);
                     l_texture_vertex[15] = (GFX_FLOAT)(fl_start_x + fl_font_fcc_SP->width + fl_font_fcc_SP->x_soffset + fl_delta_pixels.gpos_delta_pixels_x);
                     l_texture_vertex[16] = (GFX_FLOAT)(fl_font_fcc_SP->y_soffset - fl_delta_pixels.gpos_delta_pixels_y + (GLint)fl_font_fcc_SP->height);

                     glBufferData(GL_ARRAY_BUFFER, 4 * 5 * sizeof(GLfloat), l_texture_vertex, GL_STATIC_DRAW);
                     i32Location = glGetAttribLocation(l_ogl_egl_context_S.txtProgramObject, "a_position");
                     glEnableVertexAttribArray(i32Location);
                     glVertexAttribPointer(i32Location,
                       3,
                       GL_FLOAT,
                       GL_FALSE,
                       (5 * sizeof(GLfloat)),
                       0);

                     fl_location = glGetUniformLocation(l_ogl_egl_context_S.txtProgramObject, "Alpha");
                     glUniform1f(fl_location, ((GLfloat)(p_cntx_SP->state.alpha) / 255.0f));
                     glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
#endif
                     l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING | GFX_MGR02_OGLLIB_FB_UPDATED);
                   }
                 }
                 fl_start_x += fl_font_fcc_SP->owidth;
               }
               fl_string_ptr++;

#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) || defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED)
               fl_str_index++;
#endif
#endif
            }
         }
      }
   }

   return 0;
}
/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_fb_updated
Description          : Sets the flag to indicate that a ovg command was issued
                       and the framebuffer will change. This can be used by 
                       application to force an update when they perform
                       any openVG sequences with in a user image handler.
Invocation           : Invoked by generic manager
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
void hmi_gfx_mgr02_ogllib_fb_updated(void)
{
   l_ogllib_draw_sts = (GFX_MGR02_OGLLIB_FLUSH_PENDING|GFX_MGR02_OGLLIB_FB_UPDATED);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_util_matrix_operation
Description          : internal matrix operation function.
Invocation           : Invoked by hmi_gfx_mgr02_ogllib_build_xx() routines
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_util_matrix_operation(GFX_MGR02_CONTEXT_T const * p_cntx_SP)
{
   GFX_FLOAT fl_matrix[9];

   fl_matrix[0] = ovg_idty_matrx[0];
   fl_matrix[1] = ovg_idty_matrx[1];
   fl_matrix[2] = ovg_idty_matrx[2];
   fl_matrix[3] = ovg_idty_matrx[3];
   fl_matrix[4] = ovg_idty_matrx[4];
   fl_matrix[5] = ovg_idty_matrx[5];
   fl_matrix[6] = ovg_idty_matrx[6];
   fl_matrix[7] = ovg_idty_matrx[7];
   fl_matrix[8] = ovg_idty_matrx[8];
   hmi_gfx_mgr02_ogllib_util_matrix_translate(fl_matrix, (GFX_FLOAT)p_cntx_SP->state.loc.x,(GFX_FLOAT)p_cntx_SP->state.loc.y);
   hmi_gfx_mgr02_ogllib_util_matrix_mul(p_cntx_SP->state.matrix, fl_matrix);
   hmi_gfx_mgr02_ogllib_util_matrix_translate(fl_matrix, -p_cntx_SP->rprop.pivot.x, -p_cntx_SP->rprop.pivot.y);
   /*
   ** Convert 3x3 matrix to 4x4
   */
   pfIdentity[0] = fl_matrix[0];
   pfIdentity[1] = fl_matrix[1];
   pfIdentity[3] = fl_matrix[2];
   pfIdentity[4] = fl_matrix[3];
   pfIdentity[5] = fl_matrix[4];
   pfIdentity[7] = fl_matrix[5];
   pfIdentity[12] = fl_matrix[6];
   pfIdentity[13] = fl_matrix[7];
   pfIdentity[15] = fl_matrix[8];
#if (GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_11)
   glMatrixMode(GL_MODELVIEW);
   glLoadMatrixf(pfIdentity);
#endif
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_util_matrix_translate
Description          : internal matrix translation function.
Invocation           : Invoked by hmi_gfx_mgr02_ogllib_get_bound()
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_util_matrix_translate(GFX_FLOAT * m2, GFX_FLOAT tx, GFX_FLOAT ty)
{
   GFX_FLOAT fl_m2[3];

   fl_m2[0] = m2[6];
   fl_m2[1] = m2[7];
   fl_m2[2] = m2[8];

   m2[6]  = (m2[0] * tx);
   m2[6] += (m2[3] * ty);
   m2[6] += (fl_m2[0]);
   m2[7]  = (m2[1] * tx);
   m2[7] += (m2[4] * ty);
   m2[7] += (fl_m2[1]);
   m2[8]  = (m2[2] * tx);
   m2[8] += (m2[5] * ty);
   m2[8] += (fl_m2[2]);
}

/****************************************************************************
Function Name        : _ovglig_util_matrix_translate
Description          : internal matrix translation function.
Invocation           : Invoked by hmi_gfx_mgr02_ogllib_get_bound()
Parameters           : None.
Return Value         : None
Critical Section     : None
External Interfaces  : None
******************************************************************************/
static void hmi_gfx_mgr02_ogllib_util_matrix_mul(GFX_FLOAT const * m1, GFX_FLOAT * m2)
{
   GFX_FLOAT fl_m2[9];

   fl_m2[0] = m2[0];
   fl_m2[1] = m2[1];
   fl_m2[2] = m2[2];
   fl_m2[3] = m2[3];
   fl_m2[4] = m2[4];
   fl_m2[5] = m2[5];
   fl_m2[6] = m2[6];
   fl_m2[7] = m2[7];
   fl_m2[8] = m2[8];

   m2[0]  = (fl_m2[0] * m1[0]);
   m2[0] += (fl_m2[3] * m1[1]);
   m2[0] += (fl_m2[6] * m1[2]);
   m2[1]  = (fl_m2[1] * m1[0]);
   m2[1] += (fl_m2[4] * m1[1]);
   m2[1] += (fl_m2[7] * m1[2]);
   m2[2]  = (fl_m2[2] * m1[0]);
   m2[2] += (fl_m2[5] * m1[1]);
   m2[2] += (fl_m2[8] * m1[2]);

   m2[3]  = (fl_m2[0] * m1[3]);
   m2[3] += (fl_m2[3] * m1[4]);
   m2[3] += (fl_m2[6] * m1[5]);
   m2[4]  = (fl_m2[1] * m1[3]);
   m2[4] += (fl_m2[4] * m1[4]);
   m2[4] += (fl_m2[7] * m1[5]);
   m2[5]  = (fl_m2[2] * m1[3]);
   m2[5] += (fl_m2[5] * m1[4]);
   m2[5] += (fl_m2[8] * m1[5]);

   m2[6]  = (fl_m2[0] * m1[6]);
   m2[6] += (fl_m2[3] * m1[7]);
   m2[6] += (fl_m2[6] * m1[8]);
   m2[7]  = (fl_m2[1] * m1[6]);
   m2[7] += (fl_m2[4] * m1[7]);
   m2[7] += (fl_m2[7] * m1[8]);
   m2[8]  = (fl_m2[2] * m1[6]);
   m2[8] += (fl_m2[5] * m1[7]);
   m2[8] += (fl_m2[8] * m1[8]);
}

/****************************************************************************
Function Name        : hmi_gfx_mgr02_ogllib_get_bound
Description          : Calculates the transformed bounds of an elements passed
                       boundary
Invocation           : Invoked by generic manager
Parameters           : context, element def and elements bounds (un transformed).
                       p_bounds index 0,1 (x,y) 2,3 (width,height)
Return Value         : Updates transformed bounds in to p_bound_SP
Critical Section     : None
External Interfaces  : None
******************************************************************************/
s_gx_flocal hmi_gfx_mgr02_ogllib_get_bound(UINT32                p_obj_type,
                                           GFX_MGR02_CONTEXT_T const * p_cntx_SP,
                                           GFX_FLOAT               * p_bounds)
{
   GFX_FLOAT fl_cur_matrix[9];
   GFX_FLOAT x1;
   GFX_FLOAT y1;
   GFX_FLOAT x2;
   GFX_FLOAT y2;
   GFX_FLOAT x3;
   GFX_FLOAT y3;
   GFX_FLOAT x4;
   GFX_FLOAT y4;
   GFX_FLOAT minx;
   GFX_FLOAT miny;
   GFX_FLOAT maxx;
   GFX_FLOAT maxy;

   fl_cur_matrix[0]  = (p_cntx_SP->state.matrix[0]);
   fl_cur_matrix[0] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[2]);
   fl_cur_matrix[1]  = (p_cntx_SP->state.matrix[1]);
   fl_cur_matrix[1] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[2]);
   fl_cur_matrix[2]  = (p_cntx_SP->state.matrix[2]);

   fl_cur_matrix[3]  = (p_cntx_SP->state.matrix[3]);
   fl_cur_matrix[3] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[5]);
   fl_cur_matrix[4]  = (p_cntx_SP->state.matrix[4]);
   fl_cur_matrix[4] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[5]);
   fl_cur_matrix[5]  = (p_cntx_SP->state.matrix[5]);

   fl_cur_matrix[6]  = (p_cntx_SP->state.matrix[6]);
   fl_cur_matrix[6] += (p_cntx_SP->state.loc.x * p_cntx_SP->state.matrix[8]);
   fl_cur_matrix[7]  = (p_cntx_SP->state.matrix[7]);
   fl_cur_matrix[7] += (p_cntx_SP->state.loc.y * p_cntx_SP->state.matrix[8]);
   fl_cur_matrix[8]  = (p_cntx_SP->state.matrix[8]);

   if(p_obj_type == GFX_MGR02_TYPE_SVG)
   {
      hmi_gfx_mgr02_ogllib_util_matrix_translate(fl_cur_matrix, p_bounds[0], p_bounds[1]);
   }
   hmi_gfx_mgr02_ogllib_util_matrix_translate(fl_cur_matrix, -p_cntx_SP->rprop.pivot.x, -p_cntx_SP->rprop.pivot.y);
   
   if(p_obj_type == GFX_MGR02_TYPE_SIMAGE)
   {
      x1 = (fl_cur_matrix[6]/fl_cur_matrix[8]);
      y1 = (fl_cur_matrix[7]/fl_cur_matrix[8]);
      x2 = ((p_bounds[2]*fl_cur_matrix[0]) + fl_cur_matrix[6])/((p_bounds[2]*fl_cur_matrix[2])+ fl_cur_matrix[8]);
      y2 = ((p_bounds[2]*fl_cur_matrix[1]) + fl_cur_matrix[7])/((p_bounds[2]*fl_cur_matrix[2])+ fl_cur_matrix[8]);
      x3 = ((p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6])/((p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
      y3 = ((p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7])/((p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
      x4 = ((p_bounds[2]*fl_cur_matrix[0]) + (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6])/((p_bounds[2]*fl_cur_matrix[2])+ (p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
      y4 = ((p_bounds[2]*fl_cur_matrix[1]) + (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7])/((p_bounds[2]*fl_cur_matrix[2])+ (p_bounds[3]*fl_cur_matrix[5])+fl_cur_matrix[8]);
   }
   else
   {
#if defined(GFX_MGR02_DYNAMIC_BOUNDS_SUPPORT_NEEDED)	   
#if defined(GFX_MGR02_FONT_GPOS_TABLE_ENABLED)
	   if(p_obj_type == GFX_MGR02_TYPE_DTEXT)
	   {		   
		 GFX_MGR02_FONT const * fl_font_SP;		 
         GFX_MGR02_FONT_CHAR_CONFIG const * fl_font_fcc_SP;
         HMI_CHAR       const * fl_string_ptr;		
         GFX_FLOAT              fl_glyph_height;
         GFX_FLOAT              fl_miny;
         fl_string_ptr = p_cntx_SP->rprop.gl_string_ptr;	
         fl_font_SP = hmi_gfx_mgr02_get_font_pointer(p_cntx_SP->rprop.font_id);
	     if(fl_font_SP != GFX_MGR02_NULL_PTR)
         {
		    while(fl_string_ptr[0] != '\0')
            { 
#if defined(GFX_MGR02_ARABIC_LANG_SUPPORT_NEEDED)
               if ((GFX_MGR02_IS_ARABIC_VOWEL(fl_string_ptr[0]) == 1U) 
#if defined(GFX_MGR02_THAI_LANG_SUPPORT_NEEDED) 
               || (GFX_MGR02_IS_THAI_JOIN_CHAR(fl_string_ptr[0]) == 1U) 
#endif 
#if defined(GFX_MGR02_HEBREW_LANG_SUPPORT_NEEDED)
               || (GFX_MGR02_IS_HEBREW_VOWEL(fl_string_ptr[0]) == 1U)
#endif
#if defined(GFX_MGR02_DEVANAGARI_LANG_SUPPORT_NEEDED) 
               || (GFX_MGR02_DEVA_ZW_CHAR(fl_string_ptr[0]) == 1U)
#endif
               )
              {			 
		         GFX_MGR02_GPOS_DELTA fl_delta_pixels = { 0.0f, 0.0f };
		         fl_font_fcc_SP = hmi_gfx_mgr02_get_fcc(fl_string_ptr[0], fl_font_SP->f.lut_ptr, fl_font_SP->size_table,FALSE);
				 if(fl_font_fcc_SP != GFX_MGR02_NULL_PTR)
                 {
                    if(fl_font_fcc_SP->fdata != 0)
                    {
					   hmi_gfx_mgr02_get_gpos_delta_pixels(&fl_delta_pixels, &fl_string_ptr[0], 0, fl_font_SP ,p_cntx_SP, GFX_MGR02_LANG_READ_DIR_RTL);
			           fl_glyph_height = (GFX_FLOAT)(fl_font_fcc_SP->y_soffset  - fl_delta_pixels.gpos_delta_pixels_y +(GLint)fl_font_fcc_SP->height);				
				       fl_miny = (GFX_FLOAT)fl_font_fcc_SP->y_soffset  - fl_delta_pixels.gpos_delta_pixels_y;
				       if(fl_miny < p_bounds[1])
				       {					 
				          p_bounds[1] = fl_miny;
				       }
				       if(( fl_glyph_height - p_bounds[1]) > p_bounds[3])
				       {
				          p_bounds[3] =  fl_glyph_height - p_bounds[1];
				       }
				    }
				 }                 
              }
 #endif 
               fl_string_ptr++;
		    }
		  }
	   }	   
 #endif 
 #endif 
      x1 = fl_cur_matrix[6];
      y1 = fl_cur_matrix[7];
      x2 = (p_bounds[2]*fl_cur_matrix[0]) + fl_cur_matrix[6];
      y2 = (p_bounds[2]*fl_cur_matrix[1]) + fl_cur_matrix[7];
      x3 = (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6];
      y3 = (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7];
      x4 = (p_bounds[2]*fl_cur_matrix[0]) + (p_bounds[3]*fl_cur_matrix[3]) + fl_cur_matrix[6];
      y4 = (p_bounds[2]*fl_cur_matrix[1]) + (p_bounds[3]*fl_cur_matrix[4]) + fl_cur_matrix[7];
   }
   if(x1 < x2)
   {
      minx = x1;
      maxx = x2;
   }
   else
   {
      minx = x2;
      maxx = x1;
   }
   if(x3 < minx)
   {
      minx = x3;
   }
   if(x4 < minx)
   {
      minx = x4;
   }
   if(x3 > maxx)
   {
      maxx = x3;
   }
   if(x4 > maxx)
   {
      maxx = x4;
   }

   if(y1 < y2)
   {
      miny = y1;
      maxy = y2;
   }
   else
   {
      miny = y2;
      maxy = y1;
   }
   if(y3 < miny)
   {
      miny = y3;
   }
   if(y4 < miny)
   {
      miny = y4;
   }
   if(y3 > maxy)
   {
      maxy = y3;
   }
   if(y4 > maxy)
   {
      maxy = y4;
   }

   p_bounds[0] = minx;
   p_bounds[1] = miny;
   p_bounds[2] = (maxx-minx);
   p_bounds[3] = (maxy-miny);

   return 0;
}
#endif /* #if defined(GFX_MGR02_OPEN_GL) */

#ifdef  __cplusplus
}
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
 ** CMS Rev 1.26     23-Aug-2017    ADEVI
 ** 929657: Dynamic Text Width Change
 ** 
 ** CMS Rev 1.25     17-Jul-2017    ARAJASE2
 ** 911991: CI for opengl simulation
 ** Removed duplicate structure definitions to resolve compilation error in opengl.
 **
 ** CMS Rev 1.24     24-Oct-2016    csakthiv
 ** Memory Leak issue in W207. Refer RTC 730317 
 ** 
 **
 ** CMS Rev 1.24     28-Jan-2016    emanoj1
 ** Added code in hmi_gfx_mgr02_ogllib_fbo_init() to set EGL_SWAP_BEHAVIOR to 
 ** EGL_BUFFER_PRESERVED and if it succeeds then FBO creation is skipped. 
 ** Since the EGL surface will be preserved, we donot need a FBO to realize the 
 ** dirty area redraw.
 **
 ** CMS Rev 1.23     27-Jan-2016    emanoj1
 ** Removed glEnable(GL_TEXTURE_2D); call from GLES 2.0 version code as it is
 ** not supported. 
 ** glBindTexture(GL_TEXTURE_2D, 0); - texture is unbinded at end of ogllib_finish()
 ** to fix a scramble issue observed in W207. The reason for it is still unknown, 
 ** but this change has healed the scramble issue.
 ** 
 ** CMS Rev 1.22     25-Sep-2015    csakthiv
 ** 400575: Alpha value changed based on china team feedback. Changed 255 to 1.0f
 ** 
 ** CMS Rev 1.21     21-Sep-2015    csakthiv
 ** 400575: Binary search for texture.
 ** 
 ** CMS Rev 1.20     07-Sep-2015    SBOLLAM
 ** 404998: Text glow feature implementation, OpenGL library should be
 ** GFX_MGR02_GLES_VERSION == GFX_MGR02_GLES_20
 **
 ** CMS Rev 1.19.2   23-Jul-2015    EMANOJ1
 ** Rtc : 413566
 ** Added GFX_MGR02_FSL_CHROMA_KEY_WORKAROUND configuration
 ** In the freescale i.mx6 linux platform, the blending of planes is achieved via
 ** color keying where every color with r=1, g=2, b = 3 is considered transparent
 ** This caused the video bleed through GUI layer if any of the GUI layer pixel
 ** value matches this color key value. This shader is to remove any color keys
 ** from GUI layer, so that there is no bleeding of video. This temporary fix 
 ** will be retained until the plane blending via alpha channel is made to work.
 **
 ** CMS Rev 1.19     23-Jul-2015    ARAJASE2
 ** 380645: W207 Compiler warnings
 ** Changes for compiler warning fix for W207
 **
 ** CMS Rev 1.19     28-Jul-2015    EMANOJ1
 ** Ref RTC# 388968
 ** l_offscr_tex_vertex updated to fix a one pixel error in scaling of the 
 ** fb image to the window surface (identified by STD+).
 **
 ** CMS Rev 1.18     20-May-2015    EMANOJ1
 ** Rtc #382706 - Updated to support alpha channel functionality in dirty area
 ** redraw case. With dirty area enabled, the alpha channel contents were not 
 ** what was intened and expected. It contained arbitory alpha and prevented 
 ** from bottom window contents (video, navigation etc) to show up. In order to 
 ** fix this, hmi_gfx_mgr02_ogllib_fbo_finish() updated to disable GL_BLEND to 
 ** allow the framebuffer contents to be written as is to the window rather 
 ** than blend with it. This is done to support proper alpha channel support as 
 ** blending with window content which is unknown will generate random behaviour. 
 **
 ** CMS Rev 1.17     15-May-2015    EMANOJ1
 ** Rtc #311398 - Updated hmi_gfx_mgr02_ogllib_create_tex to prevent distroy 
 ** and creation of the same texture. Since igdt is optimizing images, many 
 ** image objects are getting mapped to same image file but with only difference 
 ** to their width & height. This is causing the texture lookup to match the 
 ** text file name first and then the location is cleared due to mismatch in 
 ** width & height. In order to fix this function is modified to compare 
 ** width & height along with file name.
 ** 
 ** CMS Rev 1.16     20-Feb-2015    EMANOJ1
 ** hmi_gfx_mgr02_ogllib_start updated to fix a blanding issue with background 
 ** window. The issue was that when ever we draw something with an alpha < 255(1.0)
 ** the framebuffer alpha was getting modified to < 255(1.0) causing the background
 ** window information to be partially visible. To fix the alpha channel blend
 ** equation was changed so that, once the alpha becomes 255(1.0), its not become 
 ** < 255 (1.0)
 **
 ** CMS Rev 1.15     23-Oct-2014    EMANOJ1
 ** RTC #227329 : Added support for VG_sXRGB_8888
 **
 ** CMS Rev 1.14     10-Oct-2014    EMANOJ1
 ** RTC #205473 : Added support for inserting blank pixels in text string
 **
 ** CMS Rev 1.13     20-Aug-2014    EMANOJ1
 ** RTC Task#197302
 ** hmi_gfx_mgr02_ogllib_create_tex updated to detect image width/height changes
 ** incase user image type is used.
 **
 ** CMS Rev 1.12     01-Apr-2014    EMANOJ1
 ** hmi_gfx_mgr02_ogllib_build_text updated to support append property of text
 ** 
 ** CMS Rev 1.11     21-Mar-2014    EMANOJ1
 ** Rtc 121266 - Added GFX_MGR02_DIRTY_REGION_REDRAW support for GL ES 2.0
 ** Support for GL ES 1.1 is pending
 ** The BGRA to RGBA conversion performed in fragment shader ARGBimgFragShaderCode
 ** removed since GDT data is now generated as RGBA and there fore no conversion
 ** necessary.
 **
 ** CMS Rev 1.10     17-Mar-2014    EMANOJ1
 ** RTC : Defect 133048, 133052
 ** Character positioning issue with freetype fixed by correctly considering the
 ** decender offset value.
 ** Fixed RLE decompression buffer overwrite issue due to bitmap data optimization
 ** by code generation where a bigger image gets assigned to a small image if there
 ** is a data match. This will result in buffer overwrite when the decompression
 ** happens for the smaller image. The fix is to stop the decompression when
 ** the target buffer size is reached.
 ** Moved all image file reading and decompression to seperate function.
 ** 
 ** CMS Rev 1.9      10-Mar-2014    EMANOJ1
 ** Updated hmi_gfx_mgr02_ogllib_create_tex to implement RLE compression for 
 ** OpenGL ES 2.0
 ** Fixed text rendering issue
 **
 ** CMS Rev 1.8      07-Mar-2014    EMANOJ1
 ** Fixed nul pointer issue with freetype hmi_gfx_mgr02_ogllib_build_text()
 **
 ** CMS Rev 1.7      04-Mar-2014    EMANOJ1
 ** Autohinting enabled to fix character missing issue (thin characters were
 ** missing from the rendering).
 ** FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT|FT_LOAD_FORCE_AUTOHINT);
 **
 ** CMS Rev 1.6      28-Feb-2014    EMANOJ1
 ** Alpha control of elements - support for ES2.0 added.
 **
 ** CMS Rev 1.5      25-Feb-2014    EMANOJ1
 ** Fixed issue with freetype configuration with multi color implementation
 ** Fixed issue with freetype text positioning, where the text appeared little lower 
 ** than the text appearing in GDT.
 **
 ** CMS Rev 1.4      20-Feb-2014    EMANOJ1
 ** Updated to support multiple color for a single text - RTC 121263
 **
 ** CMS Rev 1.3      28-Jan-2014    EMANOJ1
 ** Updated to support user image type to load image from a RAM buffer even in the
 ** case of GFX_MGR02_USE_FILESYSTEM defined (RTC Task 116960).
 **
 ** CMS Rev 1.2      07-Sep-2013    EMANOJ1
 ** Support for 
 **  1. text
 **  2. ARGB4444, ARGB1555 and RGB565 images
 ** Color conversion from ARGB to RGBA added in shader for ARGB images
 **
 ** CMS Rev 1.1      04-Sep-2013    EMANOJ1
 ** Added support clipping and 2D transformations. Initialization sequence updated
 ** based on i.mx6 target sequece.
 **
 ** CMS Rev 1.0      25-Aug-2013    EMANOJ1
 ** Creation.
 **==========================================================================*/


/* end of file =============================================================*/
