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
//  Name:           ux_safehmi_renderer.h
// 
//  Description:    safeHMI Renderer class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_RENDERER_H
#define UX_SAFEHMI_RENDERER_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================


#include <cmath>
#include <cfloat>
#include <cstring>
#include <string>
#include "ux_safehmi_types.h"
#include "ux_safehmi_item.h"
#include "ux_safehmi_image.h"
#include "ux_safehmi_context.h"
#include "ux_safehmi_rectangle.h"
#include "ux_safehmi_canvas.h"



// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================
namespace UX_SHMI_PLAYER
{
  /// <summary>
  /// Provides the generic framework to recursively process the converted safehmi layout
  /// tree and invoke render calls after loading the context information. 
  /// All generic processing is handled within the ux_safehmi_renderer.
  /// Provides virtual functions for rendering supported graphical elements and doesnot actually
  /// implement them.
  /// </summary>
  class ux_safehmi_renderer
  {
  private:
    /// <summary>
    /// Variable to hold the depth of the current rendering element
    /// </summary>
    uint32_t depth;
    /// <summary>
    /// Holds the status of initiaization. init_status - 0 indicates the successfull initialization
    /// </summary>
    int32_t init_status;
    uint8_t error_code;
  protected:
    /// <summary>
    /// Default constructor. Initialize the member variables with default values
    /// </summary>
      ux_safehmi_renderer(void);
  public:
    /// <summary>
    /// This is invoked by the safehmi player after RenderStart call. This function will update the
    /// context variable and pass the corresponding render funtion based on it's type
    /// </summary>
    /// <param name="p_elem">Element to be rendered</param>
    /// <param name="p_ctx">Pointer to the current element context properties</param>
    void RenderItem(ux_safehmi_item const* const p_elem, ux_safehmi_context& p_ctx);
    
    /// <summary>
    /// Initialize the renderer and update the init status. shmi_qnx_disp_info contains the info for qnx screen
    /// </summary>    
    /// <param name="p_ctx">Context properties which holds the width, height info for initialization</param>
    /// <param name="p_disp_info">Display properties for the QNX Screen</param>
    virtual int32_t RenderInit(ux_safehmi_context const& p_ctx, const shmi_qnx_disp_info& p_disp_info) = 0;
    /// <summary>
    /// This is invoked by the safehmi player before the renderpass is started. This is the virtual method.
    /// Actual implementation will be in the derived classes
    /// </summary>
    virtual void RenderStart(void) = 0;
    /// <summary>
    /// This is invoked by the safehmi player after the renderpass is completed. This is the virtual method.
    /// Actual implementation will be in the derived classes
    /// </summary>
    virtual void RenderEnd(void) = 0;

    /// <summary>
    /// Returns the error code. Error code will be reset to zero once this function is called
    /// </summary>
    uint8_t GetErrorCode(void);
    /// <summary>
    /// Returns the initiaization status.
    /// </summary>
    int32_t GetInitStatus(void) const;
    /// <summary>
    /// Sets the initiaization status.
    /// </summary>
    void SetInitStatus(const int32_t pInitStatus);
    /// <summary>
    /// Sets the error code.
    /// </summary>
    void SetErrorCode(const uint8_t pErrorCode);

  protected:
    /// <summary>
    /// This is invoked by the safehmi player to render image element during the renderpass
    /// </summary>
    /// <param name="p_elem">Image element to be rendered</param>
    /// <param name="p_ctx">Context properties for the image element</param>
    virtual void RenderImage(ux_safehmi_image const* const p_elem, ux_safehmi_context& p_ctx) = 0;
    /// <summary>
    /// This is invoked by the safehmi player to render rectangle element during the renderpass
    /// </summary>
    /// <param name="p_elem">Rectangle element to be rendered</param>
    /// <param name="p_ctx">Context properties for the Rectangle element</param>    
    virtual void RenderRectangle(ux_safehmi_rectangle const* const p_elem, const ux_safehmi_context& p_ctx) = 0;
    /// <summary>
    /// This is invoked by the safehmi player to render canvas element during the renderpass
    /// </summary>
    /// <param name="p_elem">Canvas element to be rendered</param>
    /// <param name="p_ctx">Context properties for the Canvas element</param>  
    virtual void RenderCanvas(ux_safehmi_canvas const* const p_elem, const ux_safehmi_context& p_ctx) = 0;
  };
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

//  end of file ===============================================================
#endif
