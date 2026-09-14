// =============================================================================
// 
//                      CONFIDENTIAL VISTEON CORPORATION
// 
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2012. Visteon Corporation owns all rights to this work and
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
//  Name:           vsm_ftp_sample.h
// 
//  Description:    
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================

// ============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#ifndef vsm_ftp_sample_h
#define vsm_ftp_sample_h

#include "ux_shmi_uimain.h"
#include "ux_safehmi_player.h"
#include "ux_safehmi_qnxscr_render.h"
#include "hmi_vsm_unity_asset_id.h"
#include "hmi_visteon_safety_monitor.h"
#include "hmi_vsm_unity_autogen.inc"

using namespace UX_SHMI_PLAYER;
using namespace std;
#include <map>
#if 0
typedef enum
{
  ASSET_ID_REG_0_IMG_ABS_TT_NOBG,
  ASSET_ID_REG_0_IMG_BRAKE_TT_NOBG,
  ASSET_ID_REG_0_XY_IMG_SHWHEEL_ICON_NOBG,
  ASSET_ID_IMG_LAMP_ICON_NOBG,
  ASSET_ID_REG_1_IMG_LOW_BEAM_NOBG,
  ASSET_ID_REG_1_IMG_HIGH_BEAM_NOBG,
  ASSET_ID_REG_1_IMG_LTURN_TT_NOBG,
  ASSET_ID_REG_1_IMG_RTURN_TT_NOBG,
  ASSET_ID_IMG_GAUGE_NOBG,
  ASSET_ID_IMG_HAZARD_NOBG,
  ASSET_ID_IMG_AIRBAG_NOBG,
  NUM_MAX_ASSET_ID
}HMI_VSM_ASSET_ID;

typedef enum
{
  REGION_ID_VSM_WINDOW1_SAME_XY,
  REGION_ID_IMG_LAMP_ICON,
  REGION_ID_VSM_WINDOW2_DIFF_XY,
  REGION_ID_IMG_GAUGE,
  REGION_ID_IMG_HAZARD,
  REGION_ID_IMG_AIRBAG,
  NUM_MAX_REGION_ID
}HMI_VSM_REGION_ID;
#endif
class vsm_ftp
{
public:
    vsm_ftp(UX_SHMI_PLAYER::ux_safehmi_qnxscr_render* gr)
    {
      this->gr = gr;
    }
    //Allocate, Check CRC and Dealloc one region
    void vsm_alloc_one_region(int vSyncCount);

    //Allocate, Check CRC and Dealloc one asset
    void vsm_alloc_one_asset(int vSyncCount);

    //Allocate, Check CRC and Dealloc All(8) regions(8)
    void vsm_alloc_all_regions(int vSyncCount);
    
    //Allocate, Check CRC and Dealloc All(8) Assets
    void vsm_alloc_all_assets(int vSyncCount);


    void vsm_alloc_region_asset_new(int vSyncCount);
    void vsm_alloc_asset_region(int vSyncCount);
    void vsm_alloc_region_new(int vSyncCount);

    void vsm_alloc_asset_r(int vSyncCount);

    //Allocate, Check CRC and Dealloc one region, and alloc other region, Check CRC
    void vsm_alloc_dealloc_region(int vSyncCount);
    //Allocate, Check CRC and Dealloc one asset, and alloc other asset, Check CRC
    void vsm_alloc_dealloc_assets(int vSyncCount);
    //Allocate 8 windows, Check CRC and Dealloc some window and allocate with other assets/region
    void vsm_update_assets_dynamic(int vSyncCount);
    //Allocate regions, Check CRC and update the image and check CRC again
    void vsm_update_flip_index_dynamic(int vSyncCount);
    int init_test = 0;
    int max_run = 0;
    bool print_error_failure = 0;
    
  private:
    VSM_REQ_ST fl_req_st;
    hmi_vsm_asset_crc_error_st fl_error_st;
    UX_SHMI_PLAYER::ux_safehmi_qnxscr_render *gr;
    void alloc_vsm_asset(HMI_VSM_ASSET_ID asset_id);
    void alloc_vsm_region(HMI_VSM_REGION_ID region_id);
    void dealloc_vsm_asset(HMI_VSM_ASSET_ID asset_id);
    void dealloc_vsm_region(HMI_VSM_REGION_ID region_id);
    bool print_region_crc_status(HMI_VSM_REGION_ID region_id);
    bool print_asset_crc_status(HMI_VSM_ASSET_ID asset_id);
    void vsm_commit(int vSyncCount);
    int flip_index = 0;
    int failureCount = 0;
    #ifdef QUALCOMM_MISR
      std::map<HMI_VSM_REGION_ID, SHMI_ELEMENTS> vsm_shmi_element_map {
       {REGION_ID_RIDE_MODES, SHMI_ELEMENTS::SHMI_RIDE_MODES},
       {REGION_ID_SHMI_REGION_1, SHMI_ELEMENTS::SHMI_SHMI_REGION_1} };
      int l_asset_st_index = 28;
    #else
    std::map<HMI_VSM_REGION_ID, SHMI_ELEMENTS> vsm_shmi_element_map 
    {
       {REGION_ID_GEAR_PRNDS_REGION_1, SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_1},
       {REGION_ID_GEAR_PRNDS_REGION_2, SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_2},
       {REGION_ID_GEAR_PRNDS_REGION_3, SHMI_ELEMENTS::SHMI_GEAR_PRNDS_REGION_3},
       {REGION_ID_EPB_REGION, SHMI_ELEMENTS::SHMI_EPB_REGION} 
   };
    int l_asset_st_index = 44;
    #endif
};

#endif
// ============================================================================
// 
// ============================================================================
//  C M S    R E V I S I O N    N O T E S
// ============================================================================
//  For each change to this file, be sure to record:
//  1.  Who made the change and when the change was made.
//  2.  Why the change was made and the intended result.
// 
//  CMS Rev #        Date            By
//  CMS Rev X.X      dd-mmm-yyyy     CDSID
// 
// ============================================================================
// 
//  CMS Rev 1.0      15-Jun-2017     EMANOJ1
//  Creation.
// 
// ============================================================================

// end of file ================================================================
