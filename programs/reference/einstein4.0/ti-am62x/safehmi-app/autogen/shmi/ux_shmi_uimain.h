/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2013. Visteon Corporation owns all rights to this work and
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
** Name:           ux_shmi_uimain.h
**
** Description:    
**
** Organization:   UI Frameworks & Tools, Visteon
**
**============================================================================
**
**==========================================================================*/
#ifndef ux_shmi_uimain_h
#define ux_shmi_uimain_h

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "ux_safehmi_item.h"
#include "ux_safehmi_image.h"
#include "ux_safehmi_canvas.h"
#include "ux_safehmi_rectangle.h"


/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/

#define ui_main (UX_SHMI_PLAYER::root)
#define UX_SHMI_MAX_DESIGN_DEPTH (2)


namespace UX_SHMI_PLAYER
{
/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/

enum class SHMI_ELEMENTS
{
	SHMI_TT_LEFT,
	SHMI_TT_RIGHT,
	SHMI_TT_BATT,
	SHMI_TT_P_SBR,
	SHMI_TT_ABS,
	SHMI_TT_H_BEAM,
	SHMI_TT_ACC,
	SHMI_TT_AIRBAG,
	SHMI_TT_KEY,
	SHMI_TOTAL_ITEMS
};
extern int32_t GetItemX(const SHMI_ELEMENTS assetID);
extern int32_t GetItemY(const SHMI_ELEMENTS assetID);
extern bool GetItemVisibility(const SHMI_ELEMENTS assetID);
extern void SetItemVisibility(const SHMI_ELEMENTS assetID, const bool p_val);
extern void SetItemX(const SHMI_ELEMENTS assetID, const int32_t p_val);
extern void SetItemY(const SHMI_ELEMENTS assetID, const int32_t p_val);



class Canvasroot : public ux_safehmi_canvas
{
public:
    Canvasroot(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren) :ux_safehmi_canvas(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren)
    {
       
       
    }
    
};

extern class Canvasroot root;
class Imagett_left : public ux_safehmi_image
{
public:
    Imagett_left(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_right : public ux_safehmi_image
{
public:
    Imagett_right(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_batt : public ux_safehmi_image
{
public:
    Imagett_batt(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_p_sbr : public ux_safehmi_image
{
public:
    Imagett_p_sbr(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_abs : public ux_safehmi_image
{
public:
    Imagett_abs(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_h_beam : public ux_safehmi_image
{
public:
    Imagett_h_beam(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_acc : public ux_safehmi_image
{
public:
    Imagett_acc(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_airbag : public ux_safehmi_image
{
public:
    Imagett_airbag(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};

class Imagett_key : public ux_safehmi_image
{
public:
    Imagett_key(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, const uint8_t * const pImagePtr) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, pImagePtr)
    {
       
    }
    
};



}
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
**
** CMS Rev 1.0      16-Jan-2016  emanoj1
** Creation.
**
**==========================================================================*/
#endif

/* end of file =============================================================*/
