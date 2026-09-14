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
//  Name:           ux_safehmi_context.h
// 
//  Description:    safeHMI Contex class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_CONTEXT_H
#define UX_SAFEHMI_CONTEXT_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include "ux_safehmi_types.h"
#include <string>
#include <cmath>
#include <cfloat>

// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================


namespace UX_SHMI_PLAYER
{
  /// <summary>
  /// Provides the render context storage such as x, y, width, height and 
  /// as well utility functions to manipulate transformation matrix
  /// </summary>
  class ux_safehmi_context
  {
  public:
      /// Copies the value from src to the current object
      /// </summary>
      void Copy(ux_safehmi_context const& src);
      /// <summary>
      /// Default constructor
      /// </summary>
      ux_safehmi_context(void);
      /// <summary>
      /// Returns the x position of the context.
      /// </summary>
      int32_t GetX(void) const;
      /// <summary>
      /// Returns the y position of the context.
      /// </summary>
      int32_t GetY(void) const;
      /// <summary>
      /// Returns the width of the context.
      /// </summary>
      uint32_t GetWidth(void) const;
      /// <summary>
      /// Returns the height of the context.
      /// </summary>
      uint32_t GetHeight(void) const;
      /// <summary>
      /// Returns the visibility of the context.
      /// </summary>
      bool GetVisibility(void) const;
      /// <summary>
    /// Sets the visibility of the context.
    /// </summary>
      void SetVisibility(const bool pvisible);
      /// <summary>
      /// Sets the x position of the context.
      /// </summary>
      void SetX(const int32_t px);
      /// <summary>
      /// Sets the y position of the context.
      /// </summary>
      void SetY(const int32_t py);
      /// <summary>
      /// Sets the width of the context.
      /// </summary>
      void SetWidth(const uint32_t pw);
      /// <summary>
      /// Sets the height of the context.
      /// </summary>
      void SetHeight(const uint32_t ph);
  private:
    /// <summary>
    /// Holds x position of the current rendering item
    /// </summary>
    int32_t x;
    /// <summary>
    /// Holds y position of the current rendering item
    /// </summary>
    int32_t y;
    /// <summary>
    /// Holds width of the current rendering item
    /// </summary>
    uint32_t width;
    /// <summary>
    /// Holds height of the current rendering item
    /// </summary>
    uint32_t height;
    /// <summary>
    /// Holds opacity of the current rendering item
    /// </summary>
    bool visible;
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
