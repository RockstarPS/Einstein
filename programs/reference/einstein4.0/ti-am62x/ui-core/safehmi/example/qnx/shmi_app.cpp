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

#include <cstdlib>
#include <iostream>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#include "ux_shmi_uimain.h"
#include "ux_safehmi_player.h"
#include "ux_safehmi_qnxscr_render.h"

#ifdef USE_VMF
#include "vmf_com.h"
#endif
#ifdef USE_VSM
#include "vsm_ftp.h"
extern "C"
{
#include "hmi_vsm_unity_asset_id.h"
#include "hmi_visteon_safety_monitor.h"
}
#endif
using namespace UX_SHMI_PLAYER;

// ============================================================================
//  I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
// ============================================================================

#define EHMI_PROCESS_RATE_MS (16)

UX_SHMI_PLAYER::ux_safehmi_qnxscr_render gr;

// ============================================================================
//  I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
// ============================================================================

// ============================================================================
//  M E M O R Y   A L L O C A T I O N
// ============================================================================

// ============================================================================
//  E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
// ============================================================================

#ifdef USE_VMF
// ============================================================================
//  Function Name:    vmf_rx_thread
//  Visibility:       static
//  Description:      VMF RX message thread
//  Invocation:       QNX
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// ============================================================================
static void *vmf_rx_thread(void *arg)
{
  (void)UX_SHMI_PLAYER::vmf_receiver();
  SHMI_ERROR("vmf_rx_thread exited\n");
  return (0);
}
#endif

#ifdef SHMI_DEBUG
// Debug print function
static inline void tsprint(void)
{
  struct timespec start;
  (void)clock_gettime(CLOCK_REALTIME, &start);
  printf("TS :%ld.%06d\n", (long int)start.tv_sec, (int)(start.tv_nsec / 1000));
}
#endif

// ============================================================================
//  Function Name:    main
//  Visibility:       global
//  Description:      Application entry point
//  Invocation:       QNX
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// ============================================================================

typedef double float64_t;

/*
arg0 - exe name
arg1 - VSync Count
arg2 - Pipeline, default - 1
arg3 - Number of runs for the test case
arg4 - Print CRC failure case(0 or 1)
*/
int32_t main(int32_t argc, char *argv[])
{

  struct timespec fl_rstart;
#if 0
  struct timespec fl_rend;
  float64_t fl_rsdiffms;
  int32_t fl_timeout_ms = 0;
#endif
  int32_t fl_vSyncCount = 0;
  int32_t fl_pipeline = 1;
  int32_t fl_max_run = 50;
  int32_t fl_crc_error_print = 1;
  
#ifdef USE_VMF
  uint32_t fl_cur_tt_status;
  uint32_t fl_pre_tt_status = 0;

  int32_t fl_tt_proveout = (1000 / EHMI_PROCESS_RATE_MS);

#endif
  int32_t fl_return_status = EXIT_SUCCESS;
  bool fl_changed_flag = true;
  if ((argc == 2) && (strcmp(argv[1], "--help") == 0))
  {
    printf("\narg0 - exe name");
    printf("\narg1 - VSync Count used after vsm_commit");
    printf("\narg2 - Pipeline, default - 1");
    printf("\narg3 - Number of runs for the test case");
    printf("\narg4 - Print CRC failure(0 or 1)");
    return 0;
  }

  if (argc > 1)
  {
    fl_vSyncCount = std::stoi(argv[1]);
    //fl_timeout_ms = std::stoi(argv[1]);
  }
  if (argc > 2)
  {
    fl_pipeline = std::stoi(argv[2]);
  }
  if (argc > 3)
  {
    fl_max_run = std::stoi(argv[3]);
  }
  if (argc > 4)
  {
    fl_crc_error_print = std::stoi(argv[4]);
  }
#ifdef USE_VSM
  vsm_ftp ftp(&gr);
  VSM_REQ_ST req_st = hmi_vsm_init(0, NUM_MAX_ASSET_ID, NUM_MAX_REGION_ID, &lc_safe_hmi_disp_config[0], &lc_safe_hmi_asset_rigion_id_info[0], &lc_safe_hmi_asset_id_info[0]);
  printf("Init Status -  %d, pipeline - %d, VSync Count - %d\n", req_st, fl_pipeline, fl_vSyncCount);
#endif
  if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
  {
    SHMI_ERROR("ThreadCtl(_NTO_TCTL_IO, NULL) failed\n");
    fl_return_status = EXIT_FAILURE;
  }
  else if (procmgr_ability(0, (PROCMGR_AID_INTERRUPT | PROCMGR_AOP_ALLOW),
                           (PROCMGR_AID_MEM_PHYS | PROCMGR_AOP_ALLOW),
                           PROCMGR_AID_EOL) == -1)
  {
    SHMI_ERROR("ThreadCtl(_NTO_TCTL_IO, NULL) failed\n");
    fl_return_status = EXIT_FAILURE;
  }
  else
  {
#ifdef USE_VMF
    if (UX_SHMI_PLAYER::vmf_rx_open() >= 0)
    {
      pthread_attr_t attr;
      (void)pthread_attr_init(&attr);
      (void)pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
      if (pthread_create(NULL, &attr, &vmf_rx_thread, NULL) != EOK)
      {
        SHMI_ERROR("VMF thread creation failed\n");
        fl_return_status = EXIT_FAILURE;
      }
    }
    if (fl_return_status == EXIT_SUCCESS)
#endif
    {
#ifdef USE_VMF
      int32_t tt_status;
#endif
      shmi_qnx_disp_info disp_info;
#ifdef QUALCOMM_MISR
      disp_info.display_id = 2;
      disp_info.display_type = 0;
      disp_info.zorder = 2;
      disp_info.pipeline = 16;
#else
      disp_info.display_id = 1;
      disp_info.display_type = 0;
      disp_info.zorder = 1;
      disp_info.pipeline = fl_pipeline;
#endif
      UX_SHMI_PLAYER::ux_safehmi_player qp(&ui_main, static_cast<UX_SHMI_PLAYER::ux_safehmi_renderer *>(&gr), disp_info);
      qp.Render(fl_changed_flag);
      int test_case_id = 0;
      while (1)
      {
        (void)clock_gettime(CLOCK_REALTIME, &fl_rstart);
        qp.Render(fl_changed_flag);
        uint8_t errorCode = gr.GetErrorCode();
        SHMI_INFO("\nPipeline = %d\n", disp_info.pipeline);
        SHMI_INFO("\nError Code = %d\n", errorCode);
        if (errorCode != 0U)
        {
          if ((errorCode & SHMI_NOT_INITIALIZED) == SHMI_NOT_INITIALIZED)
          {
            SHMI_ERROR("Init failure");
          }
          if ((errorCode & SHMI_RENDER_FAILURE) == SHMI_RENDER_FAILURE)
          {
            SHMI_ERROR("Render failure");
          }
          if ((errorCode & SHMI_SWAP_FAILURE) == SHMI_SWAP_FAILURE)
          {
            SHMI_ERROR("Swap failure");
          }
          if ((errorCode & SHMI_DST_BUFFER_INVALID) == SHMI_DST_BUFFER_INVALID)
          {
            SHMI_ERROR("Dest buffer invalid");
          }
          if ((errorCode & SHMI_INVALID_IMG) == SHMI_INVALID_IMG)
          {
            SHMI_ERROR("Image is not valid");
          }
          if ((errorCode & SHMI_OUT_OF_BOUNDS) == SHMI_OUT_OF_BOUNDS)
          {
            SHMI_ERROR("Out of bounds");
          }
        }
#ifdef USE_VSM

        /*
        1. if content change or alloc , then two vsync before read
        2. if no content change and no alloc, then one vsync before read
        3. one vsync after all dealloc
        */
        ftp.max_run = fl_max_run;
        ftp.print_error_failure = fl_crc_error_print;
        if (ftp.init_test == 0)
        {
          printf("\n#########################################################################\n");
        }
        else
        {
          gr.WaitVSync();
        }
        if (test_case_id == 0)
        {
          ftp.vsm_alloc_one_region(fl_vSyncCount);
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 1)
        {
          ftp.vsm_alloc_one_asset(fl_vSyncCount); 
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 2)
        {
          ftp.vsm_alloc_all_regions(fl_vSyncCount); 
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 3)
        {
          ftp.vsm_alloc_dealloc_region(fl_vSyncCount);
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 4)
        {
          ftp.vsm_alloc_all_assets(fl_vSyncCount);
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 5)
        {
          ftp.vsm_update_assets_dynamic(fl_vSyncCount);
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
          }
        }
        else if (test_case_id == 6)
        {
          ftp.vsm_update_flip_index_dynamic(fl_vSyncCount);
          if (ftp.init_test == ftp.max_run)
          {
            ftp.init_test = 0;
            test_case_id++;
            exit(0);
          }
        }

        //ftp.vsm_alloc_region_asset_new(fl_vSyncCount);
        //ftp.vsm_alloc_asset_region(fl_vSyncCount);
        //ftp.vsm_alloc_asset_r(fl_vSyncCount);//working
        //ftp.vsm_alloc_region_new(fl_vSyncCount);
        //ftp.vsm_alloc_dealloc_region(fl_vSyncCount);
        // ftp.vsm_alloc_dealloc_assets();
        // ftp.vsm_update_assets_dynamic(fl_vSyncCount); //working
       // ftp.vsm_update_flip_index_dynamic(fl_vSyncCount);
#endif
        fl_changed_flag = true;
#if 0
        (void)clock_gettime(CLOCK_REALTIME, &fl_rend);
        fl_rsdiffms = (float64_t)(fl_rend.tv_sec - fl_rstart.tv_sec);
        fl_rsdiffms /= 1000.0f;
        fl_rsdiffms += (float64_t)(fl_rend.tv_nsec - fl_rstart.tv_nsec) / (float64_t)1000000L;

        if (fl_rsdiffms < (float64_t)EHMI_PROCESS_RATE_MS)
        {
          if (fl_rsdiffms <= 0.0)
          {
            (void)delay(EHMI_PROCESS_RATE_MS);
          }
          else
          {
            fl_rsdiffms = (EHMI_PROCESS_RATE_MS - (uint32_t)fl_rsdiffms);
            (void)delay(fl_rsdiffms);
          }
        }
        if (fl_timeout_ms >= EHMI_PROCESS_RATE_MS)
        {
          fl_timeout_ms -= EHMI_PROCESS_RATE_MS;
          if (fl_timeout_ms < EHMI_PROCESS_RATE_MS)
          {
            break;
          }
        }
#endif
      }
    }
  }
  (void)(argv);
  (void)(argc);
  return (fl_return_status);
}
#ifdef USE_VSM
extern "C"
{
  void hmi_application_crc_error_callback(uint8_t p_sig_id)
  {

    (void)(p_sig_id);
  }
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
