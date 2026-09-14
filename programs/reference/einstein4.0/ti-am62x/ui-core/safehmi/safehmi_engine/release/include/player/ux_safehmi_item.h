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
//  Name:           ux_safehmi_item.h
// 
//  Description:    safeHMI item(base element) class definitions
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#ifndef UX_SAFEHMI_ITEM_H
#define UX_SAFEHMI_ITEM_H

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================

#include "ux_safehmi_types.h"


// ============================================================================
//  T Y P E   D E F I N I T I O N S
// ============================================================================


namespace UX_SHMI_PLAYER
{
  /// <summary>
  /// Base class for all safehmi elements. Contains default implementation
  /// </summary>
  class ux_safehmi_item
  {
  public:
    /// <summary>
    /// Default constructor for safehmi item
    /// </summary>
    /// <param name="px"> x position of the item</param>
    /// <param name="py">Y position of the element</param>
    /// <param name="pwidth">Width of the element</param>
    /// <param name="pheight">Height of the element</param>
    /// <param name="pcolor">Color</param>
    /// <param name="pchildcount">Number of children</param>
    /// <param name="pchildren">Pointer to the children</param>
    /// <param name="ptype">Type of the graphical element</param>
    ux_safehmi_item(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
        const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item** const pchildren, const sHMI_ObjType ptype);
    /// <summary>
    /// Returns the color of the element
    /// </summary>
    uint32_t GetColor(void) const;
    /// <summary>
    /// Returns the x position of the element.
    /// </summary>
    int32_t GetX(void) const;
    /// <summary>
    /// Returns the y position of the element.
    /// </summary>
    int32_t GetY(void) const;
    /// <summary>
    /// Returns the width of the element
    /// </summary>
    int32_t GetWidth(void) const;
    /// <summary>
    /// Returns the height of the element
    /// </summary>
    int32_t GetHeight(void) const;
    /// <summary>
    /// Returns the index of the flipbook
    /// </summary>
    int32_t GetFlipbookIndex(void) const;
    /// <summary>
    /// Returns the visibility of the element.
    /// </summary>
    bool GetVisibility(void) const;
    /// <summary>
    bool IsItemDynamic(void) const;
    /// Returns the type of the element
    /// </summary>
    sHMI_ObjType GetObjectType(void) const;
    /// <summary>
    /// Returns the number of children
    /// </summary>
    uint32_t GetChildCount(void) const;
     // <summary>
    /// Returns the child elements of childred
    /// </summary>
    ux_safehmi_item const** GetChildren(void) const;
    /// <summary>
    /// Sets the visibility of the element.
    /// </summary>
    void SetVisibility(const bool pvisible);
    /// <summary>
    /// Sets the x position of the element.
    /// </summary>
    void SetX(const int32_t px);
    /// <summary>
    /// Sets the y position of the element.
    /// </summary>
    void SetY(const int32_t py);
    /// <summary>
    /// Sets the flipbook index of the element. If the index is -1, it render all the child elements
    /// Otherwise, it renders only the current index element
    /// </summary>
    void SetFlipbookIndex(const int32_t pindex);
  private:
    /// <summary>
    /// Holds the value of x position
    /// </summary>
    int32_t x;
    /// <summary>
    /// Holds the value of y position
    /// </summary>
    int32_t y;
    /// <summary>
    /// Holds the width of the current item
    /// </summary>
    int32_t width;
    /// <summary>
    /// Holds the height of the current item
    /// </summary>
    int32_t height;
    /// <summary>
    /// Variable to maintain the visibility of the current item
    /// </summary>
    bool visible;
    /// <summary>
    bool dynamic;
    /// Holds the color of the current item
    /// </summary>
    uint32_t color;
    /// <summary>
    /// Holds the element type of the current item
    /// </summary>
    sHMI_ObjType type;
    /// <summary>
    /// Holds the index of the flipbook
    /// </summary>
    int32_t flipbookIndex;
    /// <summary>
    /// Holds the children count
    /// </summary>
    uint32_t childcount;
    /// <summary>
    /// List to store the child elements
    /// </summary>
    ux_safehmi_item const** children;
    protected:
    virtual ~ux_safehmi_item(void)
    {
    }
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
