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

#include "wallpaper_reference_img_72.h"
#include "gear_1_prnds_unselected_cold_img_dd.h"
#include "gear_1_prnds_unselected_warm_img_f2.h"
#include "gear_2_rnds_unselected_p_selected_cold_img_e5.h"
#include "gear_2_rnds_unselected_p_selected_warm_img_fa.h"
#include "gear_3_pnds_unselected_r_selected_cold_img_e6.h"
#include "gear_3_pnds_unselected_r_selected_warm_img_fb.h"
#include "gear_4_prds_unselected_n_selected_cold_img_e7.h"
#include "gear_4_prds_unselected_n_selected_warm_img_fc.h"
#include "gear_5_prns_unselected_d_selected_cold_img_e8.h"
#include "gear_5_prns_unselected_d_selected_warm_img_fd.h"
#include "gear_6_prnd_unselected_s_selected_cold_img_e9.h"
#include "gear_6_prnd_unselected_s_selected_warm_img_fe.h"
#include "gear_7_prnds_selected_cold_img_00.h"
#include "gear_7_prnds_selected_warm_img_15.h"
#include "gear_8_prndm_unselected_cold_img_de.h"
#include "gear_8_prndm_unselected_warm_img_f3.h"
#include "gear_9_rndm_unselected_p_selected_cold_img_e6.h"
#include "gear_9_rndm_unselected_p_selected_warm_img_fb.h"
#include "gear_10_pndm_unselected_r_selected_cold_img_0e.h"
#include "gear_10_pndm_unselected_r_selected_warm_img_23.h"
#include "gear_11_prdm_unselected_n_selected_cold_img_0f.h"
#include "gear_11_prdm_unselected_n_selected_warm_img_24.h"
#include "gear_12_prnm_unselected_d_selected_cold_img_10.h"
#include "gear_12_prnm_unselected_d_selected_warm_img_25.h"
#include "gear_13_prnd_unselected_m_selected_cold_img_11.h"
#include "gear_13_prnd_unselected_m_selected_warm_img_26.h"
#include "gear_14_prndm_selected_cold_img_28.h"
#include "gear_14_prndm_selected_warm_img_3d.h"
#include "gear_15_prndl_unselected_cold_img_0b.h"
#include "gear_15_prndl_unselected_warm_img_20.h"
#include "gear_15_rndl_unselected_p_selected_cold_img_12.h"
#include "gear_16_rndl_unselected_p_selected_warm_img_28.h"
#include "gear_17_pndl_unselected_r_selected_cold_img_14.h"
#include "gear_17_pndl_unselected_r_selected_warm_img_29.h"
#include "gear_18_prdl_unselected_n_selected_cold_img_15.h"
#include "gear_18_prdl_unselected_n_selected_warm_img_2a.h"
#include "gear_19_prnl_unselected_d_selected_cold_img_16.h"
#include "gear_19_prnl_unselected_d_selected_warm_img_2b.h"
#include "gear_20_prnd_unselected_l_selected_cold_img_0e.h"
#include "gear_20_prnd_unselected_l_selected_warm_img_23.h"
#include "gear_21_prndl_selected_cold_img_25.h"
#include "gear_21_prndl_selected_warm_img_3a.h"
#include "telltale_epb_row_img_40.h"
#include "telltale_epb_usa_img_31.h"
#include "telltale_brake_row_img_0e.h"
#include "telltale_brake_usa_img_ff.h"
#include "hazard_tt_c1.h"
#include "highbeam_tt_7c.h"
#include "lamp_icon_b2.h"
#include "lanedep_tt_20.h"
#include "lowbeam_tt_2e.h"
#include "lturn_tt_7c.h"


/*============================================================================
** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
**==========================================================================*/


#if UX_SHMI_MAX_DESIGN_DEPTH > UX_SHMI_MAX_SCENE_DEPTH
  #error "UX_SHMI_MAX_DESIGN_DEPTH should be <= UX_SHMI_MAX_SCENE_DEPTH"
#endif

namespace UX_SHMI_PLAYER
{
extern ux_safehmi_item const * lc_childlist_root[13];
extern ux_safehmi_item const * lc_childlist_gear_PRNDS_region_1[14];
extern ux_safehmi_item const * lc_childlist_gear_PRNDS_region_2[14];
extern ux_safehmi_item const * lc_childlist_gear_PRNDS_region_3[14];
extern ux_safehmi_item const * lc_childlist_epb_region[2];


/*============================================================================
** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
**==========================================================================*/


/*============================================================================
** M E M O R Y   A L L O C A T I O N
**===========================================================================*/
Canvasroot root(0, 0, 800, 480, true, 0xFFFFFFFFU, 13U, static_cast<const ux_safehmi_item **>(lc_childlist_root));
static Imagewallpaper_reference wallpaper_reference(0, 0, 800, 480, false, 0xFFFFFFFFU, 0U, nullptr, wallpaper_reference_img_72 );
static Itemgear_PRNDS_region_1 gear_PRNDS_region_1(0, 0, 1, 1, true, 0xFFFFFFFFU, 14U, static_cast<const ux_safehmi_item **>(lc_childlist_gear_PRNDS_region_1), sHMI_ObjType::eItem);
static Imagegear_1_PRNDS_unselected_cold gear_1_PRNDS_unselected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_1_prnds_unselected_cold_img_dd );
static Imagegear_1_PRNDS_unselected_warm gear_1_PRNDS_unselected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_1_prnds_unselected_warm_img_f2 );
static Imagegear_2_RNDS_unselected_P_selected_cold gear_2_RNDS_unselected_P_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_2_rnds_unselected_p_selected_cold_img_e5 );
static Imagegear_2_RNDS_unselected_P_selected_warm gear_2_RNDS_unselected_P_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_2_rnds_unselected_p_selected_warm_img_fa );
static Imagegear_3_PNDS_unselected_R_selected_cold gear_3_PNDS_unselected_R_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_3_pnds_unselected_r_selected_cold_img_e6 );
static Imagegear_3_PNDS_unselected_R_selected_warm gear_3_PNDS_unselected_R_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_3_pnds_unselected_r_selected_warm_img_fb );
static Imagegear_4_PRDS_unselected_N_selected_cold gear_4_PRDS_unselected_N_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_4_prds_unselected_n_selected_cold_img_e7 );
static Imagegear_4_PRDS_unselected_N_selected_warm gear_4_PRDS_unselected_N_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_4_prds_unselected_n_selected_warm_img_fc );
static Imagegear_5_PRNS_unselected_D_selected_cold gear_5_PRNS_unselected_D_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_5_prns_unselected_d_selected_cold_img_e8 );
static Imagegear_5_PRNS_unselected_D_selected_warm gear_5_PRNS_unselected_D_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_5_prns_unselected_d_selected_warm_img_fd );
static Imagegear_6_PRND_unselected_S_selected_cold gear_6_PRND_unselected_S_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_6_prnd_unselected_s_selected_cold_img_e9 );
static Imagegear_6_PRND_unselected_S_selected_warm gear_6_PRND_unselected_S_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_6_prnd_unselected_s_selected_warm_img_fe );
static Imagegear_7_PRNDS_selected_cold gear_7_PRNDS_selected_cold(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_7_prnds_selected_cold_img_00 );
static Imagegear_7_PRNDS_selected_warm gear_7_PRNDS_selected_warm(337, 434, 117, 32, true, 0xFFFFFFFFU, 0U, nullptr, gear_7_prnds_selected_warm_img_15 );
static Itemgear_PRNDS_region_2 gear_PRNDS_region_2(150, 0, 1, 1, true, 0xFFFFFFFFU, 14U, static_cast<const ux_safehmi_item **>(lc_childlist_gear_PRNDS_region_2), sHMI_ObjType::eItem);
static Imagegear_8_PRNDM_unselected_cold gear_8_PRNDM_unselected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_8_prndm_unselected_cold_img_de );
static Imagegear_8_PRNDM_unselected_warm gear_8_PRNDM_unselected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_8_prndm_unselected_warm_img_f3 );
static Imagegear_9_RNDM_unselected_P_selected_cold gear_9_RNDM_unselected_P_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_9_rndm_unselected_p_selected_cold_img_e6 );
static Imagegear_9_RNDM_unselected_P_selected_warm gear_9_RNDM_unselected_P_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_9_rndm_unselected_p_selected_warm_img_fb );
static Imagegear_10_PNDM_unselected_R_selected_cold gear_10_PNDM_unselected_R_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_10_pndm_unselected_r_selected_cold_img_0e );
static Imagegear_10_PNDM_unselected_R_selected_warm gear_10_PNDM_unselected_R_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_10_pndm_unselected_r_selected_warm_img_23 );
static Imagegear_11_PRDM_unselected_N_selected_cold gear_11_PRDM_unselected_N_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_11_prdm_unselected_n_selected_cold_img_0f );
static Imagegear_11_PRDM_unselected_N_selected_warm gear_11_PRDM_unselected_N_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_11_prdm_unselected_n_selected_warm_img_24 );
static Imagegear_12_PRNM_unselected_D_selected_cold gear_12_PRNM_unselected_D_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_12_prnm_unselected_d_selected_cold_img_10 );
static Imagegear_12_PRNM_unselected_D_selected_warm gear_12_PRNM_unselected_D_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_12_prnm_unselected_d_selected_warm_img_25 );
static Imagegear_13_PRND_unselected_M_selected_cold gear_13_PRND_unselected_M_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_13_prnd_unselected_m_selected_cold_img_11 );
static Imagegear_13_PRND_unselected_M_selected_warm gear_13_PRND_unselected_M_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_13_prnd_unselected_m_selected_warm_img_26 );
static Imagegear_14_PRNDM_selected_cold gear_14_PRNDM_selected_cold(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_14_prndm_selected_cold_img_28 );
static Imagegear_14_PRNDM_selected_warm gear_14_PRNDM_selected_warm(337, 435, 124, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_14_prndm_selected_warm_img_3d );
static Itemgear_PRNDS_region_3 gear_PRNDS_region_3(300, 0, 1, 1, true, 0xFFFFFFFFU, 14U, static_cast<const ux_safehmi_item **>(lc_childlist_gear_PRNDS_region_3), sHMI_ObjType::eItem);
static Imagegear_15_PRNDL_unselected_cold gear_15_PRNDL_unselected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_15_prndl_unselected_cold_img_0b );
static Imagegear_15_PRNDL_unselected_warm gear_15_PRNDL_unselected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_15_prndl_unselected_warm_img_20 );
static Imagegear_15_RNDL_unselected_P_selected_cold gear_15_RNDL_unselected_P_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_15_rndl_unselected_p_selected_cold_img_12 );
static Imagegear_16_RNDL_unselected_P_selected_warm gear_16_RNDL_unselected_P_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_16_rndl_unselected_p_selected_warm_img_28 );
static Imagegear_17_PNDL_unselected_R_selected_cold gear_17_PNDL_unselected_R_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_17_pndl_unselected_r_selected_cold_img_14 );
static Imagegear_17_PNDL_unselected_R_selected_warm gear_17_PNDL_unselected_R_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_17_pndl_unselected_r_selected_warm_img_29 );
static Imagegear_18_PRDL_unselected_N_selected_cold gear_18_PRDL_unselected_N_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_18_prdl_unselected_n_selected_cold_img_15 );
static Imagegear_18_PRDL_unselected_N_selected_warm gear_18_PRDL_unselected_N_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_18_prdl_unselected_n_selected_warm_img_2a );
static Imagegear_19_PRNL_unselected_D_selected_cold gear_19_PRNL_unselected_D_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_19_prnl_unselected_d_selected_cold_img_16 );
static Imagegear_19_PRNL_unselected_D_selected_warm gear_19_PRNL_unselected_D_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_19_prnl_unselected_d_selected_warm_img_2b );
static Imagegear_20_PRND_unselected_L_selected_cold gear_20_PRND_unselected_L_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_20_prnd_unselected_l_selected_cold_img_0e );
static Imagegear_20_PRND_unselected_L_selected_warm gear_20_PRND_unselected_L_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_20_prnd_unselected_l_selected_warm_img_23 );
static Imagegear_21_PRNDL_selected_cold gear_21_PRNDL_selected_cold(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_21_prndl_selected_cold_img_25 );
static Imagegear_21_PRNDL_selected_warm gear_21_PRNDL_selected_warm(337, 435, 116, 30, true, 0xFFFFFFFFU, 0U, nullptr, gear_21_prndl_selected_warm_img_3a );
static Itemepb_region epb_region(0, 0, 1, 1, true, 0xFFFFFFFFU, 2U, static_cast<const ux_safehmi_item **>(lc_childlist_epb_region), sHMI_ObjType::eItem);
static Imagetelltale_epb_row telltale_epb_row(683, 28, 41, 32, true, 0xFFFFFFFFU, 0U, nullptr, telltale_epb_row_img_40 );
static Imagetelltale_epb_usa telltale_epb_usa(683, 28, 41, 32, true, 0xFFFFFFFFU, 0U, nullptr, telltale_epb_usa_img_31 );
static Imagetelltale_brake_row telltale_brake_row(635, 85, 41, 32, true, 0xFFFFFFFFU, 0U, nullptr, telltale_brake_row_img_0e );
static Imagetelltale_brake_usa telltale_brake_usa(628, 41, 48, 15, true, 0xFFFFFFFFU, 0U, nullptr, telltale_brake_usa_img_ff );
static Imageimg_hazard_tt img_hazard_tt(100, 100, 25, 22, true, 0xFFFFFFFFU, 0U, nullptr, hazard_tt_c1 );
static Imageimg_highbeam_tt img_highbeam_tt(150, 100, 27, 19, true, 0xFFFFFFFFU, 0U, nullptr, highbeam_tt_7c );
static Imageimg_lamp_icon img_lamp_icon(200, 100, 28, 26, true, 0xFFFFFFFFU, 0U, nullptr, lamp_icon_b2 );
static Imageimg_lanedep_tt img_lanedep_tt(250, 100, 36, 17, true, 0xFFFFFFFFU, 0U, nullptr, lanedep_tt_20 );
static Imageimg_lowbeam_tt img_lowbeam_tt(300, 100, 30, 20, true, 0xFFFFFFFFU, 0U, nullptr, lowbeam_tt_2e );
static Imageimg_lturn_tt img_lturn_tt(350, 100, 27, 23, true, 0xFFFFFFFFU, 0U, nullptr, lturn_tt_7c );

ux_safehmi_item const * lc_childlist_root[13U] = 
{
 &wallpaper_reference,
 &gear_PRNDS_region_1,
 &gear_PRNDS_region_2,
 &gear_PRNDS_region_3,
 &epb_region,
 &telltale_brake_row,
 &telltale_brake_usa,
 &img_hazard_tt,
 &img_highbeam_tt,
 &img_lamp_icon,
 &img_lanedep_tt,
 &img_lowbeam_tt,
 &img_lturn_tt
 
};

ux_safehmi_item const * lc_childlist_gear_PRNDS_region_1[14U] = 
{
 &gear_1_PRNDS_unselected_cold,
 &gear_1_PRNDS_unselected_warm,
 &gear_2_RNDS_unselected_P_selected_cold,
 &gear_2_RNDS_unselected_P_selected_warm,
 &gear_3_PNDS_unselected_R_selected_cold,
 &gear_3_PNDS_unselected_R_selected_warm,
 &gear_4_PRDS_unselected_N_selected_cold,
 &gear_4_PRDS_unselected_N_selected_warm,
 &gear_5_PRNS_unselected_D_selected_cold,
 &gear_5_PRNS_unselected_D_selected_warm,
 &gear_6_PRND_unselected_S_selected_cold,
 &gear_6_PRND_unselected_S_selected_warm,
 &gear_7_PRNDS_selected_cold,
 &gear_7_PRNDS_selected_warm
 
};

ux_safehmi_item const * lc_childlist_gear_PRNDS_region_2[14U] = 
{
 &gear_8_PRNDM_unselected_cold,
 &gear_8_PRNDM_unselected_warm,
 &gear_9_RNDM_unselected_P_selected_cold,
 &gear_9_RNDM_unselected_P_selected_warm,
 &gear_10_PNDM_unselected_R_selected_cold,
 &gear_10_PNDM_unselected_R_selected_warm,
 &gear_11_PRDM_unselected_N_selected_cold,
 &gear_11_PRDM_unselected_N_selected_warm,
 &gear_12_PRNM_unselected_D_selected_cold,
 &gear_12_PRNM_unselected_D_selected_warm,
 &gear_13_PRND_unselected_M_selected_cold,
 &gear_13_PRND_unselected_M_selected_warm,
 &gear_14_PRNDM_selected_cold,
 &gear_14_PRNDM_selected_warm
 
};

ux_safehmi_item const * lc_childlist_gear_PRNDS_region_3[14U] = 
{
 &gear_15_PRNDL_unselected_cold,
 &gear_15_PRNDL_unselected_warm,
 &gear_15_RNDL_unselected_P_selected_cold,
 &gear_16_RNDL_unselected_P_selected_warm,
 &gear_17_PNDL_unselected_R_selected_cold,
 &gear_17_PNDL_unselected_R_selected_warm,
 &gear_18_PRDL_unselected_N_selected_cold,
 &gear_18_PRDL_unselected_N_selected_warm,
 &gear_19_PRNL_unselected_D_selected_cold,
 &gear_19_PRNL_unselected_D_selected_warm,
 &gear_20_PRND_unselected_L_selected_cold,
 &gear_20_PRND_unselected_L_selected_warm,
 &gear_21_PRNDL_selected_cold,
 &gear_21_PRNDL_selected_warm
 
};

ux_safehmi_item const * lc_childlist_epb_region[2U] = 
{
 &telltale_epb_row,
 &telltale_epb_usa
 
};



/*============================================================================
** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/


int32_t GetItemX(const SHMI_ELEMENTS assetID)
{
	int32_t value;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			value = wallpaper_reference.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			value = gear_PRNDS_region_1.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			value = gear_1_PRNDS_unselected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			value = gear_1_PRNDS_unselected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_2_RNDS_unselected_P_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_2_RNDS_unselected_P_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_3_PNDS_unselected_R_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_3_PNDS_unselected_R_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_4_PRDS_unselected_N_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_4_PRDS_unselected_N_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_5_PRNS_unselected_D_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_5_PRNS_unselected_D_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			value = gear_6_PRND_unselected_S_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			value = gear_6_PRND_unselected_S_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			value = gear_7_PRNDS_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			value = gear_7_PRNDS_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			value = gear_PRNDS_region_2.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			value = gear_8_PRNDM_unselected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			value = gear_8_PRNDM_unselected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_9_RNDM_unselected_P_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_9_RNDM_unselected_P_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_10_PNDM_unselected_R_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_10_PNDM_unselected_R_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_11_PRDM_unselected_N_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_11_PRDM_unselected_N_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_12_PRNM_unselected_D_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_12_PRNM_unselected_D_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			value = gear_13_PRND_unselected_M_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			value = gear_13_PRND_unselected_M_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			value = gear_14_PRNDM_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			value = gear_14_PRNDM_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			value = gear_PRNDS_region_3.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			value = gear_15_PRNDL_unselected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			value = gear_15_PRNDL_unselected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_15_RNDL_unselected_P_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_16_RNDL_unselected_P_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_17_PNDL_unselected_R_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_17_PNDL_unselected_R_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_18_PRDL_unselected_N_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_18_PRDL_unselected_N_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_19_PRNL_unselected_D_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_19_PRNL_unselected_D_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			value = gear_20_PRND_unselected_L_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			value = gear_20_PRND_unselected_L_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			value = gear_21_PRNDL_selected_cold.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			value = gear_21_PRNDL_selected_warm.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			value = epb_region.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			value = telltale_epb_row.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			value = telltale_epb_usa.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			value = telltale_brake_row.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			value = telltale_brake_usa.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			value = img_hazard_tt.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			value = img_highbeam_tt.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			value = img_lamp_icon.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			value = img_lanedep_tt.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			value = img_lowbeam_tt.GetX();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			value = img_lturn_tt.GetX();
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
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			value = wallpaper_reference.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			value = gear_PRNDS_region_1.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			value = gear_1_PRNDS_unselected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			value = gear_1_PRNDS_unselected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_2_RNDS_unselected_P_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_2_RNDS_unselected_P_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_3_PNDS_unselected_R_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_3_PNDS_unselected_R_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_4_PRDS_unselected_N_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_4_PRDS_unselected_N_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_5_PRNS_unselected_D_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_5_PRNS_unselected_D_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			value = gear_6_PRND_unselected_S_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			value = gear_6_PRND_unselected_S_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			value = gear_7_PRNDS_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			value = gear_7_PRNDS_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			value = gear_PRNDS_region_2.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			value = gear_8_PRNDM_unselected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			value = gear_8_PRNDM_unselected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_9_RNDM_unselected_P_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_9_RNDM_unselected_P_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_10_PNDM_unselected_R_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_10_PNDM_unselected_R_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_11_PRDM_unselected_N_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_11_PRDM_unselected_N_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_12_PRNM_unselected_D_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_12_PRNM_unselected_D_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			value = gear_13_PRND_unselected_M_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			value = gear_13_PRND_unselected_M_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			value = gear_14_PRNDM_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			value = gear_14_PRNDM_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			value = gear_PRNDS_region_3.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			value = gear_15_PRNDL_unselected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			value = gear_15_PRNDL_unselected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_15_RNDL_unselected_P_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_16_RNDL_unselected_P_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_17_PNDL_unselected_R_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_17_PNDL_unselected_R_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_18_PRDL_unselected_N_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_18_PRDL_unselected_N_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_19_PRNL_unselected_D_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_19_PRNL_unselected_D_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			value = gear_20_PRND_unselected_L_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			value = gear_20_PRND_unselected_L_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			value = gear_21_PRNDL_selected_cold.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			value = gear_21_PRNDL_selected_warm.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			value = epb_region.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			value = telltale_epb_row.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			value = telltale_epb_usa.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			value = telltale_brake_row.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			value = telltale_brake_usa.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			value = img_hazard_tt.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			value = img_highbeam_tt.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			value = img_lamp_icon.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			value = img_lanedep_tt.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			value = img_lowbeam_tt.GetY();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			value = img_lturn_tt.GetY();
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
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			value = wallpaper_reference.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			value = gear_PRNDS_region_1.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			value = gear_1_PRNDS_unselected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			value = gear_1_PRNDS_unselected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_2_RNDS_unselected_P_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_2_RNDS_unselected_P_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_3_PNDS_unselected_R_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_3_PNDS_unselected_R_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_4_PRDS_unselected_N_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_4_PRDS_unselected_N_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_5_PRNS_unselected_D_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_5_PRNS_unselected_D_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			value = gear_6_PRND_unselected_S_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			value = gear_6_PRND_unselected_S_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			value = gear_7_PRNDS_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			value = gear_7_PRNDS_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			value = gear_PRNDS_region_2.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			value = gear_8_PRNDM_unselected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			value = gear_8_PRNDM_unselected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_9_RNDM_unselected_P_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_9_RNDM_unselected_P_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_10_PNDM_unselected_R_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_10_PNDM_unselected_R_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_11_PRDM_unselected_N_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_11_PRDM_unselected_N_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_12_PRNM_unselected_D_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_12_PRNM_unselected_D_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			value = gear_13_PRND_unselected_M_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			value = gear_13_PRND_unselected_M_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			value = gear_14_PRNDM_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			value = gear_14_PRNDM_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			value = gear_PRNDS_region_3.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			value = gear_15_PRNDL_unselected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			value = gear_15_PRNDL_unselected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			value = gear_15_RNDL_unselected_P_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			value = gear_16_RNDL_unselected_P_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			value = gear_17_PNDL_unselected_R_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			value = gear_17_PNDL_unselected_R_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			value = gear_18_PRDL_unselected_N_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			value = gear_18_PRDL_unselected_N_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			value = gear_19_PRNL_unselected_D_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			value = gear_19_PRNL_unselected_D_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			value = gear_20_PRND_unselected_L_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			value = gear_20_PRND_unselected_L_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			value = gear_21_PRNDL_selected_cold.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			value = gear_21_PRNDL_selected_warm.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			value = epb_region.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			value = telltale_epb_row.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			value = telltale_epb_usa.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			value = telltale_brake_row.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			value = telltale_brake_usa.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			value = img_hazard_tt.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			value = img_highbeam_tt.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			value = img_lamp_icon.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			value = img_lanedep_tt.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			value = img_lowbeam_tt.GetVisibility();
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			value = img_lturn_tt.GetVisibility();
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
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			wallpaper_reference.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			gear_PRNDS_region_1.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			gear_1_PRNDS_unselected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			gear_1_PRNDS_unselected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			gear_2_RNDS_unselected_P_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			gear_2_RNDS_unselected_P_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			gear_3_PNDS_unselected_R_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			gear_3_PNDS_unselected_R_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			gear_4_PRDS_unselected_N_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			gear_4_PRDS_unselected_N_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			gear_5_PRNS_unselected_D_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			gear_5_PRNS_unselected_D_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			gear_6_PRND_unselected_S_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			gear_6_PRND_unselected_S_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			gear_7_PRNDS_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			gear_7_PRNDS_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			gear_PRNDS_region_2.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			gear_8_PRNDM_unselected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			gear_8_PRNDM_unselected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			gear_9_RNDM_unselected_P_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			gear_9_RNDM_unselected_P_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			gear_10_PNDM_unselected_R_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			gear_10_PNDM_unselected_R_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			gear_11_PRDM_unselected_N_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			gear_11_PRDM_unselected_N_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			gear_12_PRNM_unselected_D_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			gear_12_PRNM_unselected_D_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			gear_13_PRND_unselected_M_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			gear_13_PRND_unselected_M_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			gear_14_PRNDM_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			gear_14_PRNDM_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			gear_PRNDS_region_3.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			gear_15_PRNDL_unselected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			gear_15_PRNDL_unselected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			gear_15_RNDL_unselected_P_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			gear_16_RNDL_unselected_P_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			gear_17_PNDL_unselected_R_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			gear_17_PNDL_unselected_R_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			gear_18_PRDL_unselected_N_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			gear_18_PRDL_unselected_N_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			gear_19_PRNL_unselected_D_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			gear_19_PRNL_unselected_D_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			gear_20_PRND_unselected_L_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			gear_20_PRND_unselected_L_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			gear_21_PRNDL_selected_cold.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			gear_21_PRNDL_selected_warm.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			epb_region.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			telltale_epb_row.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			telltale_epb_usa.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			telltale_brake_row.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			telltale_brake_usa.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			img_hazard_tt.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			img_highbeam_tt.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			img_lamp_icon.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			img_lanedep_tt.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			img_lowbeam_tt.SetX(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			img_lturn_tt.SetX(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemY(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			wallpaper_reference.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			gear_PRNDS_region_1.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			gear_1_PRNDS_unselected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			gear_1_PRNDS_unselected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			gear_2_RNDS_unselected_P_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			gear_2_RNDS_unselected_P_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			gear_3_PNDS_unselected_R_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			gear_3_PNDS_unselected_R_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			gear_4_PRDS_unselected_N_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			gear_4_PRDS_unselected_N_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			gear_5_PRNS_unselected_D_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			gear_5_PRNS_unselected_D_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			gear_6_PRND_unselected_S_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			gear_6_PRND_unselected_S_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			gear_7_PRNDS_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			gear_7_PRNDS_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			gear_PRNDS_region_2.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			gear_8_PRNDM_unselected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			gear_8_PRNDM_unselected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			gear_9_RNDM_unselected_P_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			gear_9_RNDM_unselected_P_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			gear_10_PNDM_unselected_R_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			gear_10_PNDM_unselected_R_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			gear_11_PRDM_unselected_N_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			gear_11_PRDM_unselected_N_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			gear_12_PRNM_unselected_D_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			gear_12_PRNM_unselected_D_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			gear_13_PRND_unselected_M_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			gear_13_PRND_unselected_M_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			gear_14_PRNDM_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			gear_14_PRNDM_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			gear_PRNDS_region_3.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			gear_15_PRNDL_unselected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			gear_15_PRNDL_unselected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			gear_15_RNDL_unselected_P_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			gear_16_RNDL_unselected_P_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			gear_17_PNDL_unselected_R_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			gear_17_PNDL_unselected_R_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			gear_18_PRDL_unselected_N_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			gear_18_PRDL_unselected_N_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			gear_19_PRNL_unselected_D_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			gear_19_PRNL_unselected_D_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			gear_20_PRND_unselected_L_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			gear_20_PRND_unselected_L_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			gear_21_PRNDL_selected_cold.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			gear_21_PRNDL_selected_warm.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			epb_region.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			telltale_epb_row.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			telltale_epb_usa.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			telltale_brake_row.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			telltale_brake_usa.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			img_hazard_tt.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			img_highbeam_tt.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			img_lamp_icon.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			img_lanedep_tt.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			img_lowbeam_tt.SetY(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			img_lturn_tt.SetY(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemVisibility(const SHMI_ELEMENTS assetID, const bool p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_WALLPAPER_REFERENCE:
		{
			wallpaper_reference.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			gear_PRNDS_region_1.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_COLD:
		{
			gear_1_PRNDS_unselected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_1_PRNDS_UNSELECTED_WARM:
		{
			gear_1_PRNDS_unselected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_COLD:
		{
			gear_2_RNDS_unselected_P_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_2_RNDS_UNSELECTED_P_SELECTED_WARM:
		{
			gear_2_RNDS_unselected_P_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_COLD:
		{
			gear_3_PNDS_unselected_R_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_3_PNDS_UNSELECTED_R_SELECTED_WARM:
		{
			gear_3_PNDS_unselected_R_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_COLD:
		{
			gear_4_PRDS_unselected_N_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_4_PRDS_UNSELECTED_N_SELECTED_WARM:
		{
			gear_4_PRDS_unselected_N_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_COLD:
		{
			gear_5_PRNS_unselected_D_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_5_PRNS_UNSELECTED_D_SELECTED_WARM:
		{
			gear_5_PRNS_unselected_D_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_COLD:
		{
			gear_6_PRND_unselected_S_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_6_PRND_UNSELECTED_S_SELECTED_WARM:
		{
			gear_6_PRND_unselected_S_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_COLD:
		{
			gear_7_PRNDS_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_7_PRNDS_SELECTED_WARM:
		{
			gear_7_PRNDS_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			gear_PRNDS_region_2.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_COLD:
		{
			gear_8_PRNDM_unselected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_8_PRNDM_UNSELECTED_WARM:
		{
			gear_8_PRNDM_unselected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_COLD:
		{
			gear_9_RNDM_unselected_P_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_9_RNDM_UNSELECTED_P_SELECTED_WARM:
		{
			gear_9_RNDM_unselected_P_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_COLD:
		{
			gear_10_PNDM_unselected_R_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_10_PNDM_UNSELECTED_R_SELECTED_WARM:
		{
			gear_10_PNDM_unselected_R_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_COLD:
		{
			gear_11_PRDM_unselected_N_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_11_PRDM_UNSELECTED_N_SELECTED_WARM:
		{
			gear_11_PRDM_unselected_N_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_COLD:
		{
			gear_12_PRNM_unselected_D_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_12_PRNM_UNSELECTED_D_SELECTED_WARM:
		{
			gear_12_PRNM_unselected_D_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_COLD:
		{
			gear_13_PRND_unselected_M_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_13_PRND_UNSELECTED_M_SELECTED_WARM:
		{
			gear_13_PRND_unselected_M_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_COLD:
		{
			gear_14_PRNDM_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_14_PRNDM_SELECTED_WARM:
		{
			gear_14_PRNDM_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			gear_PRNDS_region_3.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_COLD:
		{
			gear_15_PRNDL_unselected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_PRNDL_UNSELECTED_WARM:
		{
			gear_15_PRNDL_unselected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_15_RNDL_UNSELECTED_P_SELECTED_COLD:
		{
			gear_15_RNDL_unselected_P_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_16_RNDL_UNSELECTED_P_SELECTED_WARM:
		{
			gear_16_RNDL_unselected_P_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_COLD:
		{
			gear_17_PNDL_unselected_R_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_17_PNDL_UNSELECTED_R_SELECTED_WARM:
		{
			gear_17_PNDL_unselected_R_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_COLD:
		{
			gear_18_PRDL_unselected_N_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_18_PRDL_UNSELECTED_N_SELECTED_WARM:
		{
			gear_18_PRDL_unselected_N_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_COLD:
		{
			gear_19_PRNL_unselected_D_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_19_PRNL_UNSELECTED_D_SELECTED_WARM:
		{
			gear_19_PRNL_unselected_D_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_COLD:
		{
			gear_20_PRND_unselected_L_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_20_PRND_UNSELECTED_L_SELECTED_WARM:
		{
			gear_20_PRND_unselected_L_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_COLD:
		{
			gear_21_PRNDL_selected_cold.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_21_PRNDL_SELECTED_WARM:
		{
			gear_21_PRNDL_selected_warm.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			epb_region.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_ROW:
		{
			telltale_epb_row.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_EPB_USA:
		{
			telltale_epb_usa.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_ROW:
		{
			telltale_brake_row.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_TELLTALE_BRAKE_USA:
		{
			telltale_brake_usa.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HAZARD_TT:
		{
			img_hazard_tt.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_HIGHBEAM_TT:
		{
			img_highbeam_tt.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LAMP_ICON:
		{
			img_lamp_icon.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LANEDEP_TT:
		{
			img_lanedep_tt.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LOWBEAM_TT:
		{
			img_lowbeam_tt.SetVisibility(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_IMG_LTURN_TT:
		{
			img_lturn_tt.SetVisibility(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}

void SetItemFlipbookIndex(const SHMI_ELEMENTS assetID, const int32_t p_val)
{
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			gear_PRNDS_region_1.SetFlipbookIndex(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			gear_PRNDS_region_2.SetFlipbookIndex(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			gear_PRNDS_region_3.SetFlipbookIndex(p_val);
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			epb_region.SetFlipbookIndex(p_val);
			break;
		}
		default:{/*Do Nothing*/break;}
	}
}
int32_t GetItemFlipbookIndex(const SHMI_ELEMENTS assetID)
{
	int32_t value = -1;
	switch(assetID)
	{
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1:
		{
			value = gear_PRNDS_region_1.GetFlipbookIndex();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2:
		{
			value = gear_PRNDS_region_2.GetFlipbookIndex();
			break;
		}
		case SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3:
		{
			value = gear_PRNDS_region_3.GetFlipbookIndex();
			break;
		}
		case SHMI_ELEMENTS::SHMI_EPB_REGION:
		{
			value = epb_region.GetFlipbookIndex();
			break;
		}
		default:{/*Do Nothing*/break;}
	}
	return value;
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
