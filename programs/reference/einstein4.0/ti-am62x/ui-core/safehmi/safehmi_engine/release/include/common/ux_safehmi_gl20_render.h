// ============================================================================
// 
//                      CONFIDENTIAL VISTEON CORPORATION
// 
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2017. Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction,
//  to protect this work as an unpublished work, in the event of an
//  inadvertent or deliberate unauthorized publication. Visteon Corporation
//  also reserves its rights under all copyright laws to protect this work as
//  a published work, when appropriate. Those having access to this work may
//  not copy it, use it, modify it or disclose the information contained in
//  it without the written authorization of Visteon Corporation.
// 
// ============================================================================
// 
//  Name:           ux_safehmi_gl20_render.h
// 
//  Description:    QML renderer based on OpenGL ES 2.0 apis & QNX screen 
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_GL20_RENDER_H
#define UX_SAFEHMI_GL20_RENDER_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include <Windows.h>
#include <tchar.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "ux_safehmi_renderer.h"
#include "ux_safehmi_utils.h"


// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================
namespace UX_SHMI_PLAYER
{
#define VERTEX_ARRAY   0
#define TEXCOORD_ARRAY 1

#define I2D_FORMAT_R8G8B8A8	 (0)
#define I2D_FORMAT_A8B8G8R8	 (1)
#define I2D_FORMAT_A8R8G8B8	 (2)
#define I2D_FORMAT_B8G8R8A8	 (3)
#define I2D_FORMAT_R8G8B8X8	 (4)
#define I2D_FORMAT_X8B8G8R8	 (5)
#define I2D_FORMAT_X8R8G8B8	 (6)
#define I2D_FORMAT_R8G8B8  	 (7)
#define I2D_FORMAT_B8G8R8  	 (8)
#define I2D_FORMAT_R6G6B6  	 (9)
#define I2D_FORMAT_R4G4B4A4	 (10)
#define I2D_FORMAT_A4R4G4B4	 (11)
#define I2D_FORMAT_R5G5B5A1	 (12)
#define I2D_FORMAT_A1R5G5B5	 (13)
#define I2D_FORMAT_A1B5G5R5	 (14)
#define I2D_FORMAT_B5G5R5A1	 (15)
#define I2D_FORMAT_R5G6B5  	 (16)
#define I2D_FORMAT_A8RGB8  	 (17)
#define I2D_FORMAT_RGB8    	 (18)
#define I2D_FORMAT_A8      	 (19)
#define I2D_FORMAT_A4RGB4  	 (20)
#define I2D_FORMAT_A4      	 (21)
#define I2D_FORMAT_A2      	 (22)
#define I2D_FORMAT_A1      	 (23)
#define I2D_FORMAT_RGB1    	 (24)
#define I2D_FORMAT_YVYU422 	 (25)
#define I2D_FORMAT_VYUY422 	 (26)
#define I2D_FORMAT_TOTAL 	 (27)


#ifndef CACHE_SIZE
#define CACHE_SIZE (100)
#endif
  class ux_shmi_gl20context
  {
  public:
    ux_shmi_gl20context()
    {
      Display = EGL_NO_DISPLAY;
      Config = 0;
      Surface = EGL_NO_SURFACE;
      Context = EGL_NO_CONTEXT;
      NativeWindow = 0;
      NativeDisplay = 0;
      CurTexData = 0;
      CurTexId = 0;
      VxBuffObject = 0;
      fillProgramObject = 0;
      ArgbimgProgramObject = 0;
      RgbimgProgramObject = 0;
      txtProgramObject = 0;
    }
    EGLDisplay          Display;
    EGLConfig           Config;
    EGLSurface          Surface;
    EGLContext          Context;
    EGLNativeWindowType NativeWindow;
    NativeDisplayType   NativeDisplay;
    void const* CurTexData;
    GLuint              CurTexId;
    GLuint              VxBuffObject;
    GLuint              fillProgramObject;
    GLuint              ArgbimgProgramObject;
    GLuint              RgbimgProgramObject;
    GLuint              txtProgramObject;
  };

  typedef struct
  {
    uint32_t bpp;
    uint32_t rgba_bits;
    uint32_t rgba_shift;
  }format_t;

  /// <summary>
  /// Implements a renderer for windows using OpenGL ES 2.0 apis
  /// </summary>
  class ux_safehmi_gl20_render : public ux_safehmi_renderer
  {
  public:
    ux_shmi_gl20context glctx;
    static float32_t pfIdentity[16];
    static float32_t l_texture_vertex[20];
    const static EGLint pi32ConfigAttribs[17];
    int32_t    iConfigs;
    static EGLint const ai32ContextAttribs[3];
    static format_t const format_cfg[I2D_FORMAT_TOTAL];
    /*
    ** Fragment and vertex shaders code for fill screen
    */
    static char const* const fillFragShaderCode;
    static char const* const fillVertShaderCode;
    /*
    ** Fragment and vertex shaders code for image screen
    */
    static char const* const imgVertShaderCode;
    /*
    ** The images are stored as ARGB where as OpenGL needs it as RGBA
    ** So conversion is in-corporated in shader
    */
    static char const* const ARGBimgFragShaderCode;
    static char const* const RGBimgFragShaderCode;
    /*
    ** Fragment and vertex shaders code for Text
    */
    static char const* const txtVertShaderCode;
    static char const* const txtFragShaderCode;
    ux_safehmi_gl20_render();
    ~ux_safehmi_gl20_render();
    virtual int32_t RenderInit(ux_safehmi_context const& p_ctx, const shmi_qnx_disp_info& p_disp_info) override;
  private:
    HWND l_hwnd = NULL;
    static LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    /// <summary>
    /// Implements a cache with a key-value pair storage
    /// Not intended for large cache as it uses a linear loop search.
    /// </summary>
    void* lcache[CACHE_SIZE][2];
    /// <summary>
    /// Holds transformation matrix of the current rendering item
    /// </summary>
    float32_t matrix[9];
    /// <summary>
    /// Holds identity matrix
    /// </summary>
    float32_t identity_matrix[9];
    void mx_ldidentity(void);
    void mx_translate(float32_t p_tx, float32_t p_ty);
    void mx_multiply(float32_t const *p_src_matrix);

    /// <summary>
    /// Gets the object from cache for the given id
    /// </summary>
    void *cache_get_object(void const *p_id) const;
    /// <summary>
    /// Add the object into cache for the given id
    /// </summary>
    int32_t cache_set_object(void *p_id, void *p_obj);
    /// <summary>
    /// Removes the object from cache at the given index
    /// </summary>
    void *cache_rem_object(int32_t p_index);

  protected:
    virtual void RenderStart(void) override;
    virtual void RenderEnd(void) override;
    virtual void RenderImage(ux_safehmi_image const* const p_elem, ux_safehmi_context& p_ctx) override;
    virtual void RenderRectangle(ux_safehmi_rectangle const* const p_elem, const ux_safehmi_context& p_ctx) override;
    virtual void RenderCanvas(ux_safehmi_canvas const* const p_elem, const ux_safehmi_context& p_ctx) override;
  };

  // ============================================================================
  //  E N T R Y   P O I N T S
  // ============================================================================

  // ============================================================================
  //  D A T A   A C C E S S   S E R V I C E S
  // ============================================================================
}
// ============================================================================
// 
// ============================================================================
//  C M S    R E V I S I O N    N O T E S
// ============================================================================
// 
//  For each change to this file, be sure to record:
//  1.  Who made the change and when the change was made.
//  2.  Why the change was made and the intended result.
// 
//  CMS Rev #        Date         By
//  CMS Rev X.X      mm/dd/yy     CDSID
// 
// ============================================================================
// 
//  CMS Rev 1.0      20-Jun-2020  arajase2
//  Source code is leveraged from QMLPlayer. QMLPlayer RTC baseline - ss-UI-CORE-EARLY-HMI-1.3.1
// 
// ============================================================================

// end of file ================================================================
#endif
