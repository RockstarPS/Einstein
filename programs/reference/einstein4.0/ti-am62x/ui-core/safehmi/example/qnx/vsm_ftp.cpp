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
//  Name:           shmi_app.cpp
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

#include "vsm_ftp.h"

// ============================================================================
//  I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
// ============================================================================

// ============================================================================
//  I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
// ============================================================================

// ============================================================================
//  M E M O R Y   A L L O C A T I O N
// ============================================================================

// ============================================================================
//  E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
// ============================================================================

typedef double float64_t;
//#define DETAILED_LOG

void vsm_ftp::alloc_vsm_asset(HMI_VSM_ASSET_ID asset_id)
{
  fl_req_st = hmi_vsm_alloc_asset(0, asset_id);
#ifdef DETAILED_LOG
  printf("Allocate asset - %d, status -  %d\n", asset_id, fl_req_st);
#endif
}
void vsm_ftp::alloc_vsm_region(HMI_VSM_REGION_ID region_id)
{
  fl_req_st = hmi_vsm_alloc_region(0, region_id);
#ifdef DETAILED_LOG
  printf("Allocate region - %d, alloc status -  %d\n", region_id, fl_req_st);
#endif
}

void vsm_ftp::dealloc_vsm_asset(HMI_VSM_ASSET_ID asset_id)
{
  fl_req_st = hmi_vsm_dealloc_asset(0, asset_id);
#ifdef DETAILED_LOG
  printf("Deallocate asset - %d, status -  %d\n", asset_id, fl_req_st);
#endif
}

void vsm_ftp::dealloc_vsm_region(HMI_VSM_REGION_ID region_id)
{
  fl_req_st = hmi_vsm_dealloc_region(0, region_id);
#ifdef DETAILED_LOG
  printf("Deallocate region - %d, status -  %d\n", region_id, fl_req_st);
#endif
}

bool vsm_ftp::print_region_crc_status(HMI_VSM_REGION_ID region_id)
{
  bool success = true;
  fl_req_st = hmi_vsm_get_region_crc_error_status(0, region_id, &fl_error_st);
  uint flip_index = GetItemFlipbookIndex(vsm_shmi_element_map[region_id]);
  HMI_VSM_ASSET_ID fl_vsm_asset_id = (HMI_VSM_ASSET_ID)flip_index;
  int region_st_index = -1;
  for (uint i = 0; i < NUM_MAX_ASSET_ID; i++)
  {
    if (region_id == lc_safe_hmi_asset_id_info[i].region_id)
    {
      if (region_st_index == -1)
        region_st_index = i;
      if (flip_index == (i - region_st_index))
      {
        fl_vsm_asset_id = (HMI_VSM_ASSET_ID)(i);
      }
    }
  }

#if QUALCOMM_MISR

  printf("Region id %d errst %d CRC 0x%XU\n", region_id, fl_error_st.err_status,
         fl_error_st.crc.rgb_crc_U32);

#ifdef DETAILED_LOG
  if (fl_req_st != 0)
  {
    printf("\n-----------CRC read error for region %d, VSM return status = %d error status %d-----------\n",
           region_id, fl_req_st, fl_error_st.err_status);
  }
#endif

  if (fl_error_st.crc.rgb_crc_U32 != lc_safe_hmi_asset_id_info[fl_vsm_asset_id].rgb_crc_U32)
  {
    success = false;
    if (print_error_failure)
    {
      printf("\n-----------CRC Mismatch for window id %d-----------\n", hmi_vsm_get_safe_window_id(0, region_id));
      printf("Expected CRC 0x%XU \n", lc_safe_hmi_asset_id_info[fl_vsm_asset_id].rgb_crc_U32);
      printf("Actual CRC 0x%XU\n\n", fl_error_st.crc.rgb_crc_U32);
    }
  }

#else

#ifdef DETAILED_LOG
  printf("Region id %d errst %d CRC 0x%XU 0x%XU 0x%XU \n", region_id, fl_error_st.err_status,
         fl_error_st.crc.red_crc, fl_error_st.crc.green_crc, fl_error_st.crc.blue_crc);

  if (fl_req_st != 0)
  {
    printf("\n-----------CRC read error for region %d, VSM return status = %d error status %d-----------\n",
           region_id, fl_req_st, fl_error_st.err_status);
  }
  printf("Region id %d errst %d CRC 0x%XU 0x%XU 0x%XU \n", region_id, fl_error_st.err_status,
         fl_error_st.crc.red_crc, fl_error_st.crc.green_crc, fl_error_st.crc.blue_crc);
#endif

  if ((fl_error_st.crc.red_crc != lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_r) ||
      (fl_error_st.crc.blue_crc != lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_b) ||
      (fl_error_st.crc.green_crc != lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_g))
  {
    success = false;
    if (print_error_failure)
    {
      printf("\n-----------CRC Mismatch for window id %d-----------\n", hmi_vsm_get_safe_window_id(0, region_id));
      printf("Expected CRC 0x%XU 0x%XU 0x%XU \n",
             lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_r,
             lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_g,
             lc_safe_hmi_asset_id_info[fl_vsm_asset_id].crc_ref_b);
      printf("Actual CRC 0x%XU 0x%XU 0x%XU \n\n", fl_error_st.crc.red_crc, fl_error_st.crc.green_crc, fl_error_st.crc.blue_crc);
    }
  }
#endif
  return success;
}
bool vsm_ftp::print_asset_crc_status(HMI_VSM_ASSET_ID asset_id)
{
  bool success = true;
  fl_req_st = hmi_vsm_get_asset_crc_error_status(0, asset_id, &fl_error_st);
#if QUALCOMM_MISR

  printf("Asset id %d errst %d CRC 0x%XU\n ", asset_id, fl_error_st.err_status,
         fl_error_st.crc.rgb_crc_U32);

#ifdef DETAILED_LOG
  if (fl_req_st != 0)
  {
    printf("-----------CRC read error for region %d, VSM return status = %d error status %d-----------\n", asset_id, fl_req_st, fl_error_st.err_status);
  }
#endif
  if ((fl_error_st.crc.rgb_crc_U32 != lc_safe_hmi_asset_id_info[asset_id].rgb_crc_U32))
  {
    if (print_error_failure)
    {
      printf("-----------CRC Mismatch for window %d-----------\n",
             hmi_vsm_get_safe_window_id(0, lc_safe_hmi_asset_id_info[asset_id].region_id));
      printf("Expected CRC 0x%XU \n", lc_safe_hmi_asset_id_info[asset_id].rgb_crc_U32);
      printf("Actual CRC 0x%XU\n\n", fl_error_st.crc.rgb_crc_U32);
    }
  }

#else

#ifdef DETAILED_LOG
  printf("Asset id %d errst %d CRC 0x%XU 0x%XU 0x%XU \n ", asset_id, fl_error_st.err_status,
         fl_error_st.crc.red_crc, fl_error_st.crc.green_crc, fl_error_st.crc.blue_crc);
  if (fl_req_st != 0)
  {
    printf("-----------CRC read error for region %d, VSM return status = %d error status %d-----------\n", asset_id, fl_req_st, fl_error_st.err_status);
  }
#endif

  if ((fl_error_st.crc.red_crc != lc_safe_hmi_asset_id_info[asset_id].crc_ref_r) ||
      (fl_error_st.crc.blue_crc != lc_safe_hmi_asset_id_info[asset_id].crc_ref_b) ||
      (fl_error_st.crc.green_crc != lc_safe_hmi_asset_id_info[asset_id].crc_ref_g))
  {
    success = false;
    if (print_error_failure)
    {
      printf("-----------CRC Mismatch for window %d-----------\n",
             hmi_vsm_get_safe_window_id(0, lc_safe_hmi_asset_id_info[asset_id].region_id));
      printf("Expected CRC 0x%XU 0x%XU 0x%XU \n", lc_safe_hmi_asset_id_info[asset_id].crc_ref_r,
             lc_safe_hmi_asset_id_info[asset_id].crc_ref_g,
             lc_safe_hmi_asset_id_info[asset_id].crc_ref_b);
      printf("Actual CRC 0x%XU 0x%XU 0x%XU \n\n", fl_error_st.crc.red_crc, fl_error_st.crc.green_crc, fl_error_st.crc.blue_crc);
    }
  }

#endif
  return success;
}

void vsm_ftp::vsm_commit(int vSyncCount)
{
  printf("-----------vsm_commit, VSync Count - %d-----------\n", vSyncCount);
  fl_req_st = hmi_vsm_commit(0);
#ifdef DETAILED_LOG
  struct timespec fl_rstart;
  struct timespec fl_rend;
  float64_t fl_rsdiffms;
#endif
  for (int i = 0; i < vSyncCount; i++)
  {
#ifdef DETAILED_LOG
    (void)clock_gettime(CLOCK_REALTIME, &fl_rstart);
#endif
    gr->WaitVSync();
#ifdef DETAILED_LOG
    (void)clock_gettime(CLOCK_REALTIME, &fl_rend);

    fl_rsdiffms = (float64_t)(fl_rend.tv_sec - fl_rstart.tv_sec);
    fl_rsdiffms /= 1000.0f;
    fl_rsdiffms += (float64_t)(fl_rend.tv_nsec - fl_rstart.tv_nsec) / (float64_t)1000000L;
    printf("VSync Timing -  %f,\n", fl_rsdiffms);
    printf("Commit Status -  %d, vSyncCount - %d\n", fl_req_st, vSyncCount);
#endif
  }
}

void vsm_ftp::vsm_alloc_one_region(int vSyncCount)
{
  if (NUM_MAX_REGION_ID > 0)
  {
    HMI_VSM_REGION_ID fl_region_id = (HMI_VSM_REGION_ID)0;
    if (print_error_failure)
      printf("========= vsm_alloc_one_region - %d ===========\n", init_test);
    if (init_test++ == 0)
    {
      failureCount = 0;
      alloc_vsm_region(fl_region_id);
      vsm_commit(vSyncCount);
    }
    if (!print_region_crc_status(fl_region_id))
      failureCount++;
    if (init_test == max_run)
    {
      dealloc_vsm_region(fl_region_id);
      printf("\n========= vsm_alloc_one_region ===========\n");
      printf("Number of runs : %d\n", max_run);
      printf("Number of cases passed : %d\n", (max_run - failureCount));
      printf("Number of cases failed : %d\n", failureCount);
      gr->WaitVSync();
    }
  }
}

void vsm_ftp::vsm_alloc_one_asset(int vSyncCount)
{
  if (NUM_MAX_ASSET_ID > 0)
  {
    HMI_VSM_ASSET_ID fl_asset_id = (HMI_VSM_ASSET_ID)(NUM_MAX_ASSET_ID - 1); // Allocate last asset
    if (print_error_failure)
      printf("========= vsm_alloc_one_asset - %d ===========\n", init_test);
    if (init_test++ == 0)
    {
      failureCount = 0;
      alloc_vsm_asset(fl_asset_id);
      vsm_commit(vSyncCount);
    }
    if (!print_asset_crc_status(fl_asset_id))
      failureCount++;

    if (init_test == max_run)
    {
      dealloc_vsm_asset(fl_asset_id);
      printf("\n========= vsm_alloc_one_asset ===========\n");
      printf("Number of runs : %d\n", max_run);
      printf("Number of cases passed : %d\n", (max_run - failureCount));
      printf("Number of cases failed : %d\n", failureCount);
      gr->WaitVSync();
    }
  }
}

void vsm_ftp::vsm_alloc_all_regions(int vSyncCount)
{
  bool success = true;
  if (print_error_failure)
    printf("========= vsm_alloc_all_regions - %d ===========\n", init_test);
  std::map<HMI_VSM_REGION_ID, SHMI_ELEMENTS>::iterator it = vsm_shmi_element_map.begin();
  if (init_test++ == 0)
  {
    failureCount = 0;
    while (it != vsm_shmi_element_map.end())
    {
      alloc_vsm_region(it->first);
      it++;
    }
    vsm_commit(vSyncCount);
  }

  it = vsm_shmi_element_map.begin();
  while (it != vsm_shmi_element_map.end())
  {
    success &= print_region_crc_status(it->first);
    it++;
  }

  if (!success)
    failureCount++;
  if (init_test == max_run)
  {
    it = vsm_shmi_element_map.begin();
    while (it != vsm_shmi_element_map.end())
    {
      dealloc_vsm_region(it->first);
      it++;
    }
    printf("\n========= vsm_alloc_all_regions ===========\n");
    printf("Number of runs : %d\n", max_run);
    printf("Number of cases passed : %d\n", (max_run - failureCount));
    printf("Number of cases failed : %d\n", failureCount);
    gr->WaitVSync();
  }
}

void vsm_ftp::vsm_alloc_all_assets(int vSyncCount)
{
  bool success = true;
  if (print_error_failure)
    printf("========= vsm_alloc_all_assets - %d ===========\n", init_test);

  uint flMaxAsset = NUM_MAX_ASSET_ID - l_asset_st_index;
#ifdef QUALCOMM_MISR
  flMaxAsset = (flMaxAsset > 4) ? l_asset_st_index + 4 : l_asset_st_index + flMaxAsset;
#else
  flMaxAsset = (flMaxAsset > 8) ? l_asset_st_index + 8 : l_asset_st_index + flMaxAsset;
#endif
  if (init_test++ == 0)
  {
    failureCount = 0;
    for (uint i = l_asset_st_index; i < flMaxAsset; i++)
    {
      alloc_vsm_asset((HMI_VSM_ASSET_ID)(i));
    }
    vsm_commit(vSyncCount);
  }

  for (uint i = l_asset_st_index; i < flMaxAsset; i++)
  {
    success &= print_asset_crc_status((HMI_VSM_ASSET_ID)(i));
  }

  if (!success)
    failureCount++;

  if (init_test == max_run)
  {
    for (uint i = l_asset_st_index; i < flMaxAsset; i++)
    {
      dealloc_vsm_asset((HMI_VSM_ASSET_ID)(i));
    }
    printf("\n========= vsm_alloc_all_assets ===========\n");
    printf("Number of runs : %d\n", max_run);
    printf("Number of cases passed : %d\n", (max_run - failureCount));
    printf("Number of cases failed : %d\n", failureCount);
    gr->WaitVSync();
  }
}

void vsm_ftp::vsm_alloc_dealloc_region(int vSyncCount)
{
  if (NUM_MAX_REGION_ID > 1)
  {
    bool success = true;
    HMI_VSM_REGION_ID region1 = (HMI_VSM_REGION_ID)0;
    HMI_VSM_REGION_ID region2 = (HMI_VSM_REGION_ID)1;
    if (print_error_failure)
      printf("========= vsm_alloc_dealloc_region - %d ===========\n", init_test);
    if (init_test++ == 0)
    {
      failureCount = 0;
      alloc_vsm_region((region1));
      vsm_commit(vSyncCount);
    }
    if (init_test <= (max_run / 2))
      success &= print_region_crc_status(region1);
    if (init_test == (max_run / 2))
    {
      if (print_error_failure)
        printf("vsm_alloc_dealloc_region - Dealloc existing region and alloc new region\n");
      dealloc_vsm_region(region1);
      gr->WaitVSync();
      alloc_vsm_region(region2);
      vsm_commit(vSyncCount);
    }
    if (init_test >= (max_run / 2))
      success &= print_region_crc_status(region2);

    if (!success)
      failureCount++;
    if (init_test == max_run)
    {
      printf("\n========= vsm_alloc_dealloc_region ===========\n");
      printf("Number of runs : %d\n", max_run);
      printf("Number of cases passed : %d\n", (max_run - failureCount));
      printf("Number of cases failed : %d\n", failureCount);
      dealloc_vsm_region(region2);
      gr->WaitVSync();
    }
  }
}

void vsm_ftp::vsm_update_assets_dynamic(int vSyncCount)
{
#ifdef QUALCOMM_MISR
  bool success = true;
  if (print_error_failure)
    printf("========= vsm_update_assets_dynamic - %d ===========\n", init_test);
  if (init_test++ == 0)
  {
    failureCount = 0;
    alloc_vsm_region((HMI_VSM_REGION_ID)(0));
    alloc_vsm_region((HMI_VSM_REGION_ID)(1));
    alloc_vsm_region((HMI_VSM_REGION_ID)(2));
    alloc_vsm_asset(ASSET_ID_LEFT_TURN_INDICATOR_NOBG);
    vsm_commit(vSyncCount);
  }

  if (init_test <= (max_run / 2))
  {
    printf("************ vsm_update_assets_dynamic - %d ************\n", init_test);
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(0));
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(1));
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(2));
    success &= print_asset_crc_status(ASSET_ID_LEFT_TURN_INDICATOR_NOBG);
  }
  if (init_test == (max_run / 2))
  {
    dealloc_vsm_region((HMI_VSM_REGION_ID)(0));
    dealloc_vsm_region((HMI_VSM_REGION_ID)(1));
    dealloc_vsm_asset(ASSET_ID_LEFT_TURN_INDICATOR_NOBG);
    gr->WaitVSync();
    alloc_vsm_asset(ASSET_ID_RIGHT_TURN_INDICATOR_NOBG);
    vsm_commit(vSyncCount);
  }
  if (init_test >= (max_run / 2))
  {
    printf("************ vsm_update_assets_dynamic - %d ************\n", init_test);
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(0));
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(1));
    success &= print_region_crc_status((HMI_VSM_REGION_ID)(2));
    success &= print_asset_crc_status(ASSET_ID_LEFT_TURN_INDICATOR_NOBG);
    success &= print_asset_crc_status(ASSET_ID_RIGHT_TURN_INDICATOR_NOBG);
  }
  if (init_test == max_run)
  {
    printf("************ vsm_update_assets_dynamic - %d ************\n", init_test);
    dealloc_vsm_asset(ASSET_ID_RIGHT_TURN_INDICATOR_NOBG);
    printf("\n========= vsm_update_assets_dynamic ===========\n");
    printf("Number of runs : %d\n", max_run);
    printf("Number of cases passed : %d\n", (max_run - failureCount));
    printf("Number of cases failed : %d\n", failureCount);
    gr->WaitVSync();
  }
#else
  init_test++;
#endif
}

void vsm_ftp::vsm_update_flip_index_dynamic(int vSyncCount)
{
  if (NUM_MAX_REGION_ID > 1)
  {
    bool success = true;
    HMI_VSM_REGION_ID region1 = (HMI_VSM_REGION_ID)0;
    HMI_VSM_REGION_ID region2 = (HMI_VSM_REGION_ID)3;
    if (print_error_failure)
      printf("========= vsm_update_flip_index_dynamic - %d, Flip index - %d ===========\n", init_test, flip_index);
    if (init_test++ == 0)
    {
      failureCount = 0;
      alloc_vsm_region(region1);
      alloc_vsm_region(region2);
      vsm_commit(vSyncCount);
    }
    else
    {
      gr->WaitVSync();
      gr->WaitVSync();
    }

    if (flip_index == 0)
    {
      flip_index = 1;
    }
    else
    {
      flip_index = 0;
    }

    success &= print_region_crc_status(region1);
    success &= print_region_crc_status(region2);

    // Update image in the allocated region
    SetItemFlipbookIndex(vsm_shmi_element_map[region1], flip_index);
    SetItemFlipbookIndex(vsm_shmi_element_map[region2], flip_index);

    if (!success)
      failureCount++;
    if (init_test == max_run)
    {
      dealloc_vsm_region(region1);
      dealloc_vsm_region(region2);
      printf("\n========= vsm_update_flip_index_dynamic ===========\n");
      printf("Number of runs : %d\n", max_run);
      printf("Number of cases passed : %d\n", (max_run - failureCount));
      printf("Number of cases failed : %d\n", failureCount);
      gr->WaitVSync();
    }
  }
}

#ifndef QUALCOMM_MISR
void vsm_ftp::vsm_alloc_region_asset_new(int vSyncCount)
{
  printf("\n========= vsm_alloc_region_asset_new - %d ===========\n", init_test);
  if (init_test++ == 0)
  {
    alloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_1);
    alloc_vsm_region(REGION_ID_TELLTALE_BRAKE_ROW);
    alloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_2);

    vsm_commit(vSyncCount);
  }

  print_region_crc_status(REGION_ID_GEAR_PRNDS_REGION_1);
  print_region_crc_status(REGION_ID_TELLTALE_BRAKE_ROW);
  print_region_crc_status(REGION_ID_GEAR_PRNDS_REGION_2);

  // dealloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_1);
  // dealloc_vsm_region(REGION_ID_TELLTALE_BRAKE_ROW);
  // dealloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_2);
}
void vsm_ftp::vsm_alloc_asset_region(int vSyncCount)
{
  if (init_test == 0)
  {
    printf("\n========= vsm_alloc_asset_region ===========\n");
    alloc_vsm_region(REGION_ID_IMG_LOWBEAM_TT);
    vsm_commit(vSyncCount);
    init_test = 1;
  }
  print_region_crc_status(REGION_ID_IMG_LOWBEAM_TT);
  // dealloc_vsm_region(REGION_ID_IMG_LOWBEAM_TT);
}
void vsm_ftp::vsm_alloc_region_new(int vSyncCount)
{
  if (init_test == 0)
  {
    printf("\n========= vsm_alloc_region new===========\n");
    alloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_3);
    vsm_commit(vSyncCount);
    init_test = 0;
  }
  print_region_crc_status(REGION_ID_GEAR_PRNDS_REGION_3);
  // dealloc_vsm_region(REGION_ID_GEAR_PRNDS_REGION_3);
  // gr.WaitVSync();
}
void vsm_ftp::vsm_alloc_asset_r(int vSyncCount)
{
  if (init_test == 0)
  {
    printf("========== vsm_alloc_asset_r ===========\n");
    alloc_vsm_asset(ASSET_ID_GEAR_1_PRNDS_UNSELECTED_WARM_NOBG_GEAR_PRNDS_REGION_1);
    vsm_commit(vSyncCount);
    init_test = 1;
  }
  print_asset_crc_status(ASSET_ID_GEAR_1_PRNDS_UNSELECTED_WARM_NOBG_GEAR_PRNDS_REGION_1);
  // dealloc_vsm_asset(ASSET_ID_IMG_HAZARD_TT_NOBG);
}
void vsm_ftp::vsm_alloc_dealloc_assets(int vSyncCount)
{
  printf("========== vsm_alloc_dealloc_asset ===========\n");
  alloc_vsm_asset(ASSET_ID_TELLTALE_EPB_USA_NOBG_EPB_REGION);
  vsm_commit(vSyncCount);

  print_asset_crc_status(ASSET_ID_TELLTALE_EPB_USA_NOBG_EPB_REGION);

  printf("Dealloc existing region and alloc new asset\n");
  dealloc_vsm_asset(ASSET_ID_TELLTALE_EPB_USA_NOBG_EPB_REGION);
  gr->WaitVSync();

  alloc_vsm_asset(ASSET_ID_IMG_HAZARD_TT_NOBG);
  vsm_commit(vSyncCount);

  printf("After VSync 1 Wait\n");
  print_asset_crc_status(ASSET_ID_IMG_HAZARD_TT_NOBG);

  gr->WaitVSync();

  printf("After VSync 2 Wait\n");
  print_asset_crc_status(ASSET_ID_IMG_HAZARD_TT_NOBG);
}
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
