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
//  Name:           ux_safehmi_canvas.h
// 
//  Description:    safeHMI Canvas class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_CANVAS_H
#define UX_SAFEHMI_CANVAS_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================

#include "ux_safehmi_item.h"


// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================

namespace UX_SHMI_PLAYER
{
  /// <summary>
  /// Canvas is the top most element in the layout. Window is created for Canvas properties
  /// </summary>
  class ux_safehmi_canvas : public ux_safehmi_item
  {
  public:
    /// <summary>
    /// Overloaded constructor
    /// </summary>
    ux_safehmi_canvas(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
        const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item** const pchildren);
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
