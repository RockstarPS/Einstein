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
//  Name:           ux_safehmi_player.h
// 
//  Description:    QML player class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SHMI_PLAYER_H
#define UX_SHMI_PLAYER_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include "ux_safehmi_renderer.h"

// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================
namespace UX_SHMI_PLAYER
{
  /// <summary>
  /// Contains higher level safeHMI player implementation, which provides api's load 
  /// the converted unity design and then execute/Render it. 
  /// </summary>
  class ux_safehmi_player
  {
  private:
    ux_safehmi_context    ctx;
    /// <summary>
    /// Holds the target specific renderer
    /// </summary>
    ux_safehmi_renderer * rendr;
    /// <summary>
    /// Holds the root canvas element
    /// </summary>
    ux_safehmi_canvas   * canvas;
    /// <summary>
    /// Holds the initialization status
    /// </summary>
    int32_t init_status;
    /// <summary>
    /// Variable to holds the property value changes.
    /// Rendering will be done only if there is a change in property
    /// </summary>
    bool prop_changed;

  public:
    /// <summary>
    /// safehmi player constructor - Inits the renderer with the given canvas properties.
    /// shmi_qnx_disp_info holds the display properties specific to QNX
    /// </summary
    ux_safehmi_player(ux_safehmi_canvas * const p_canvas, ux_safehmi_renderer * const p_renderer, const shmi_qnx_disp_info& p_disp_info);
    /// <summary>
    /// Start the render process. Render root and its child elements
    /// </summary>
    void Render(const bool pDataChanged);
  };
}
// ============================================================================
//  E N T R Y   P O I N T S
// ============================================================================

// ============================================================================
//  D A T A   A C C E S S   S E R V I C E S
// ============================================================================

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
