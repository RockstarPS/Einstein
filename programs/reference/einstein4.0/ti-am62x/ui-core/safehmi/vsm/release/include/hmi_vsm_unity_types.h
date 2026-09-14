/* Used by both VSM and Application */
#ifndef VSM_UNITY_TYPES_H
#define VSM_UNITY_TYPES_H

#include "hmi_vsm_unity_asset_id.h"

/**
 * @file hmi_vsm_unity_types.h
 * @brief Data types/Structures used by VSM.
 */


/// <summary>
/// structure used by unity to generate configuration values common for single asset
/// </summary>

typedef struct
{
   HMI_VSM_REGION_ID region_id;         ///region id for asset   
   #ifdef QUALCOMM_MISR
   uint32_t rgb_crc_U32;
   #endif 
   uint32_t crc_ref_r;                  ///<Reference CRC for red channel
   uint32_t crc_ref_g;                  ///<Reference CRC for green channel
   uint32_t crc_ref_b;                  ///<Reference CRC for blue channel
   uint8_t  panic_mode;                 ///< 0- Disabled ; 1- Local ; 2- Global 
   uint8_t  alpha_mask;                 ///< 0- Disabled ; 1- Alpha mask normal ; 2- Alpha mask inverted
}VSM_UNITY_ASSET_CONFIG;

/// <summary>
/// structure used by unity to generate configuration values common for single region
/// </summary>
typedef struct
{
   uint16_t winsx;        ///<CRC window start x-14bits
   uint16_t winsy;        ///<CRC window start y-14bits
   uint16_t winex;		  ///<CRC window end x-14bits 
   uint16_t winey;		  ///<CRC window end y-14bits 
   uint8_t  alpha_mask;   ///< 0- Disabled ; 1- Alpha mask normal ; 2- Alpha mask inverted
}VSM_UNITY_REGION_CONFIG;

/// <summary>
/// structure used by unity to generate configuration values common for single display(all 8 windows)
/// </summary>
typedef struct
{
   uint32_t panic_color;                        ///< panic color in RGBA format
   uint8_t  err_threshold_value;                ///< error threshold value 
   uint8_t  err_reset_threshold_value;          ///< error threshold reset value
}VSM_UNITY_DISP_CONFIG;

#endif /* VSM_UNITY_TYPES_H */




