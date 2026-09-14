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
//  Name:           ux_safehmi_utils.h
// 
//  Description:    safeHMI utility class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_UTILS_H
#define UX_SAFEHMI_UTILS_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================

#include "ux_safehmi_types.h"

// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================

namespace UX_SHMI_PLAYER
{
  typedef float float32_t;
  /// <summary>
  /// Implementation for unitlity functions used in safehmi component
  /// </summary>
  class ux_safehmi_utils
  {
  public:
    /// <summary>
    /// aligns the passed bytes to a multiple of 8 bytes
    /// </summary>
    static uint32_t align8(uint32_t p_alignbytes);
    /// <summary>
    /// Gets the alpha value of the given color within 0 to 1 range
    /// </summary>
    static float32_t getColorfA(uint32_t p_argb);
    /// <summary>
    /// Gets the alpha value of the given color within int value
    /// </summary>
    static uint32_t getColoriA(uint32_t p_argb);
    /// <summary>
    /// Gets the red value of the given color within 0 to 1 range
    /// </summary>
    static float32_t getColorfR(uint32_t p_argb);
    /// <summary>
    /// Gets the green value of the given color within 0 to 1 range
    /// </summary>
    static float32_t getColorfG(uint32_t p_argb);
    /// <summary>
    /// Gets the blue value of the given color within 0 to 1 range
    /// </summary>
    static float32_t getColorfB(uint32_t p_argb);
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

//  end of file ===============================================================
#endif
