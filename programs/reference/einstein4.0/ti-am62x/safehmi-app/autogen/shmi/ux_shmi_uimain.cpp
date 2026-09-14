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
** Name:           
**
** Description:    
**
** Organization:   UI Frameworks & Tools, Visteon
**
**============================================================================
**
**==========================================================================*/

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include "ux_shmi_uimain.h"

#include "tt_ico_a16_l_74.h"
#include "tt_ico_a16_r_7a.h"
#include "tt_ico_m01_af.h"
#include "tt_ico_k01_p_7c.h"
#include "tt_ico_b05_a8.h"
#include "tt_ico_a01_a3.h"
#include "tt_ico_pm_acc_44.h"
#include "tt_ico_k02_ae.h"
#include "tt_ico_l19_b7.h"


/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/


#if UX_SHMI_MAX_DESIGN_DEPTH > UX_SHMI_MAX_SCENE_DEPTH
  #error "UX_SHMI_MAX_DESIGN_DEPTH should be <= UX_SHMI_MAX_SCENE_DEPTH"
#endif

namespace UX_SHMI_PLAYER
{
extern ux_safehmi_item const * lc_childlist_root[9];


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/


/*============================================================================
** M E M O R Y   A L L O C A T I O N
**===========================================================================*/
Canvasroot root(0, 0, 1920, 720, true, 0xFFFFFFFFU, 9U, static_cast<const ux_safehmi_item **>(lc_childlist_root));
static Imagett_left tt_left(571, 46, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_a16_l_74 );
static Imagett_right tt_right(1307, 46, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_a16_r_7a );
static Imagett_batt tt_batt(678, 46, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_m01_af );
static Imagett_p_sbr tt_p_sbr(765, 46, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_k01_p_7c );
static Imagett_abs tt_abs(852, 45, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_b05_a8 );
static Imagett_h_beam tt_h_beam(939, 46, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_a01_a3 );
static Imagett_acc tt_acc(1026, 45, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_pm_acc_44 );
static Imagett_airbag tt_airbag(1113, 45, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_k02_ae );
static Imagett_key tt_key(1200, 45, 42, 42, true, 0xFFFFFFFFU, 0U, nullptr, tt_ico_l19_b7 );

ux_safehmi_item const * lc_childlist_root[9U] = 
{
 &tt_left,
 &tt_right,
 &tt_batt,
 &tt_p_sbr,
 &tt_abs,
 &tt_h_beam,
 &tt_acc,
 &tt_airbag,
 &tt_key
 
};



/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


int32_t GetItemX(const SHMI_ELEMENTS assetID)
{
	int32_t value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			value = tt_left.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			value = tt_right.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			value = tt_batt.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			value = tt_p_sbr.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			value = tt_abs.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			value = tt_h_beam.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			value = tt_acc.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			value = tt_airbag.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			value = tt_key.GetX();
			break;
		}
		default:{/*Do Nothing*/ value = 0; break;}
	}
	return value;
}

int32_t GetItemY(const SHMI_ELEMENTS assetID)
{
	int32_t value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			value = tt_left.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			value = tt_right.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			value = tt_batt.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			value = tt_p_sbr.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			value = tt_abs.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			value = tt_h_beam.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			value = tt_acc.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			value = tt_airbag.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			value = tt_key.GetY();
			break;
		}
		default:{/*Do Nothing*/ value = 0; break;}
	}
	return value;
}

bool GetItemVisibility(const SHMI_ELEMENTS assetID)
{
	bool value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			value = tt_left.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			value = tt_right.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			value = tt_batt.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			value = tt_p_sbr.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			value = tt_abs.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			value = tt_h_beam.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			value = tt_acc.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			value = tt_airbag.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			value = tt_key.GetVisibility();
			break;
		}
		default:{/*Do Nothing*/ value = false; break;}
	}
	return value;
}

void SetItemX(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			tt_left.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			tt_right.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			tt_batt.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			tt_p_sbr.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			tt_abs.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			tt_h_beam.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			tt_acc.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			tt_airbag.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			tt_key.SetX(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemY(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			tt_left.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			tt_right.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			tt_batt.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			tt_p_sbr.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			tt_abs.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			tt_h_beam.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			tt_acc.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			tt_airbag.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			tt_key.SetY(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemVisibility(const SHMI_ELEMENTS assetID, const bool p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_TT_LEFT:
		{
			tt_left.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_RIGHT:
		{
			tt_right.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_BATT:
		{
			tt_batt.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_P_SBR:
		{
			tt_p_sbr.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ABS:
		{
			tt_abs.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_H_BEAM:
		{
			tt_h_beam.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_ACC:
		{
			tt_acc.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_AIRBAG:
		{
			tt_airbag.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TT_KEY:
		{
			tt_key.SetVisibility(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}





}//namespace-UX_SHMI_PLAYER

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
** CMS Rev 1.0      04-Feb-2016  emanoj1
** Creation.
**
**==========================================================================*/

/* end of file =============================================================*/
