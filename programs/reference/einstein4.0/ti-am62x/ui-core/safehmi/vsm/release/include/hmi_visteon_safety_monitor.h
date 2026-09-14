/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2018. Visteon Corporation owns all rights to this work and
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
 ** Name:           hmi_visteon_safety_monitor.h
 **
 ** Description:     VSM API for Safety HMI Application
 **
 ** Organization:   GUI Software Section, Visteon
 **
 **============================================================================
 **
 **==========================================================================*/
/**
 * @file hmi_visteon_safety_monitor.h
 * @brief visteon safety monitor provides API to enable/disable safety monitor for graphics assets.
 * Also provides API to get the error status.
 */

#ifndef HMI_VSM_H
#define HMI_VSM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "hmi_vsm_unity_types.h"

#ifdef HMI_VSM_C
  #define EXTERN_HMIVSM
#else
  #define EXTERN_HMIVSM extern
#endif

/// Functional interface
#define NUM_OF_MAX_DISP_ID     1U
#ifdef QUALCOMM_MISR
#define NUM_OF_SAFE_WINDOWS    4U
#else
#define NUM_OF_SAFE_WINDOWS    8U
#endif

/// <summary>
/// structure to hold crc value
/// </summary>
typedef struct 
{
#ifdef QUALCOMM_MISR
  uint32_t rgb_crc_U32;   ///< crc value of rgb color
#endif
  uint32_t red_crc;   ///< crc value of red color
  uint32_t green_crc; ///< crc value of green color
  uint32_t blue_crc;  ///< crc value of blue color
} hmi_vsm_asset_crc;

/// <summary>
/// structure for crc value and  error status
/// </summary>
typedef struct
{
  hmi_vsm_asset_crc crc;          ///< Calcuated CRC for RGB Channels
  uint32_t err_status;            ///< Error Status. 0 - No Error; 
} hmi_vsm_asset_crc_error_st;

/// <summary>
/// Holds the request status of vsm
/// </summary>
typedef enum
{
  VSM_REQ_SUCCESS,                  ///< VSM request success
  VSM_REQ_ASSET_REGION_ID_INVALID,  ///< VSM requested asset/window id is invalid
  VSM_REQ_OFF_ALREADY,              ///< VSM requested asset id is already off(VSM_OFF)   
  VSM_REQ_ON_ALREADY,               ///< VSM requested asset id is already on (VSM_ON)
  VSM_REQ_DISP_ID_INVALID,          ///< VSM requested display id is invalid
  VSM_REQ_SIG_UINT_DRV_ERROR,       ///< VSM sig unit driver error
  VSM_REQ_SIG_WIN_NOT_AVAILABLE,    ///< VSM all 8 sig windows are busy   
  VSM_REQ_SIG_WIN_ID_ERRROR         ///< VSM invalid window id stored in VSM
}VSM_REQ_ST;

/// <summary>
/// This is invoked by the safety application to init vsm component. This will 
/// init the window status and asset id in windows to default value
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_max_asset_id">Maximum number of assets</param>
/// <param name="p_max_region_id">Maximum number of region</param>
/// <param name="p_disp_config">Pointer to diplay configuration generated from Unity</param>
/// <param name="p_region_config">Pointer to region configuration generated from Unity</param>
/// <param name="p_asset_config">Pointer to asset configuration generated from Unity</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_init(const uint8_t p_disp_id, const uint32_t p_max_asset_id,
  const uint32_t p_max_region_id, const VSM_UNITY_DISP_CONFIG* p_disp_config,
  const VSM_UNITY_REGION_CONFIG* p_region_config, const VSM_UNITY_ASSET_CONFIG* p_asset_config);
/// <summary>
/// This is invoked by the safety application to allocate the evaluation window for given region id
/// if sig window available
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_region_id">Region id for which crc check has to be enabled</param>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_alloc_region(const uint8_t p_disp_id, HMI_VSM_REGION_ID p_region_id);
/// <summary>
/// This is invoked by the safety application to allocate the evaluation window for given asset id
/// if sig window available
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_asset_id">asset id for which crc check has to be enabled</param>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_alloc_asset(const uint8_t p_disp_id, HMI_VSM_ASSET_ID p_asset_id);
/// <summary>
/// This is invoked by the safety de allocate the evaluation window for given region id 
/// if already sig window id allocated
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_region_id">Region id for which crc check has to be disabled</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_dealloc_region(const uint8_t p_disp_id, HMI_VSM_REGION_ID p_region_id);
/// <summary>
/// This is invoked by the safety application to de allocate the evaluation window for given asset id 
/// if already sig window id allocated
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_asset_id">Asset id for which crc check has to be disabled</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_dealloc_asset(const uint8_t p_disp_id, HMI_VSM_ASSET_ID p_asset_id);

/// <summary>
/// This is invoked by the safety application to get the h/w evaluation window assigned for
/// the given region
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_region_id">Region id to get the evaluation window</param>
/// <returns>returns the evaluation window for the given region id</returns>
EXTERN_HMIVSM uint8_t hmi_vsm_get_safe_window_id(const uint8_t p_disp_id, HMI_VSM_REGION_ID p_region_id);

/// <summary>
/// This is invoked by the safety application to start CRC check for all the
/// allocated windows
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_commit(const uint8_t p_disp_id);

/// <summary>
/// This is invoked by the safety application to check CRC error status for given region id 
/// if already sig window id allocated
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_region_id">Region id for which crc check has to be enabled</param>
/// <param name="p_vsm_asset_crc_err_st">input pointer from app updated with error status</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_get_region_crc_error_status(const uint8_t p_disp_id, HMI_VSM_REGION_ID p_region_id,
 hmi_vsm_asset_crc_error_st * p_vsm_asset_crc_err_st);

/// <summary>
/// This is invoked by the safety application to check CRC error status for given asset id 
/// if already sig window id allocated
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <param name="p_asset_id">asset id for which crc check has to be enabled</param>
/// <param name="p_vsm_asset_crc_err_st">input pointer from app updated with error status</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_get_asset_crc_error_status(const uint8_t p_disp_id, HMI_VSM_ASSET_ID p_asset_id,
 hmi_vsm_asset_crc_error_st * p_vsm_asset_crc_err_st);
/// <summary>
/// This is invoked by the safety application to shutdown vsm component. This will 
/// shutdown the window status and asset id in windows to default value
/// </summary>
/// <param name="p_disp_id">Disp id or Sig id to be used</param>
/// <returns>returns status of the request </returns>
EXTERN_HMIVSM VSM_REQ_ST hmi_vsm_shutdown(const uint8_t p_disp_id);

#ifdef __cplusplus
}
#endif
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
// C M S    R E V I S I O N    N O T E S
//---------------------------------------------------------------------------------------------------------------------
//
// For each change to this file, be sure to record:
// 1.  Who made the change and when the change was made.
// 2.  Why the change was made and the intended result.
//
// CMS Rev #        Date            By
// CMS Rev X.X      dd-mmm-yyyy     CDSID
//
//---------------------------------------------------------------------------------------------------------------------
// 1.0   Initial Version           9/10/2020	csakthiv
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
#endif  //HMI_VSM_H

