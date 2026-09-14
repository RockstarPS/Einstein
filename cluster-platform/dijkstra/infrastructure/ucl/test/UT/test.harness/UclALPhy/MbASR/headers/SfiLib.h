/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * PROPRIETARY/CONFIDENTIAL
 *
 * This software is the confidential and proprietary information of
 * SAMSUNG ELECTRONICS ("Confidential Information").
 *
 * You shall not disclose such Confidential Information and shall use it
 * only in accordance with the terms of the license agreement
 * you entered into with SAMSUNG ELECTRONICS.
 *
 * SAMSUNG make no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular
 * purpose, or non-infringement. SAMSUNG shall not be liable for any
 * damages suffered by licensee as a result of using, modifying or
 * distributing this software or its derivatives.
 */

/**
 * @file    SfiLib.h
 * @brief   header file for SfiLib
 * @ingroup SfiLib
 */

#ifndef SFILIB_H
#define SFILIB_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "sfilib_baaw.h"

/**********************************************************************************************************************
 * Defines / Macros
 **********************************************************************************************************************/
/*********************************
 *  SfiLib Error Code
 *********************************/
/** @brief no error */
#define SFILIB_E_OK                                 ((uint8)0x00u)
/** @brief error if parameter is invalid */
#define SFILIB_E_WRONG_PARAMETERS                   ((uint8)0x02u)
/** @brief error if parameter is null pointer */
#define SFILIB_E_PARAM_POINTER                      ((uint8)0x03u)
/** @brief error if DRAM is invalid */
#define SFILIB_E_DRAM_INVALID                       ((uint8)0x04u)
/** @brief error if SFR write fails */
#define SFILIB_E_SFR_WRITE_FAIL                     ((uint8)0x05u)


/**********************************************************************************************************************
 * Enumerations
 **********************************************************************************************************************/
/**
 * @brief enumeration of DRAM State
 */
typedef enum {
    SFILIB_DRAM_STATE_INVALID = 0uL,    /* DRAM content is not valid or unknown */
    SFILIB_DRAM_STATE_VALID = 1uL       /* DRAM content is valid */
} SfiLib_DramStateType;

/**
 * @brief enumeration of SFMPU state for SFASC SFR Protection
 */
typedef enum {
    SFILIB_SFMPU_SFASC_PROTECTION_STATE_DISABLED = 0uL,     /* SFASC SFR Protection is disabled */
    SFILIB_SFMPU_SFASC_PROTECTION_STATE_ENABLED = 1uL       /* SFASC SFR Protection is enabled */
} SfiLib_SfmpuSfascProtStateType;

/**
 * @brief enumeration of BAAW DRAM Region
 */
typedef enum {
    SFILIB_BAAW_DRAM_REGION_ID_0 = BAAW_DRAM_RGN_ID_0,      /* BAAW DRAM region id 0 : 0x00110000 - 0x05000000 */
    SFILIB_BAAW_DRAM_REGION_ID_1 = BAAW_DRAM_RGN_ID_1,      /* BAAW DRAM region id 1 : 0x05800000 - 0x30000000 */
    SFILIB_BAAW_DRAM_REGION_ID_2 = BAAW_DRAM_RGN_ID_2,      /* BAAW DRAM region id 2 : 0x80000000 - 0xC0000000 */
    SFILIB_BAAW_DRAM_REGION_ID_3 = BAAW_DRAM_RGN_ID_3,      /* BAAW DRAM region id 3 : 0xC4001000 - 0xEFA00000 */
} SfiLib_BaawDramRegionIdType;

/**
 * @brief enumeration of BAAW DRAM Remap State
 */
typedef enum {
    SFILIB_BAAW_DRAM_REGION_STATE_DISABLED = 0uL,    /* BAAW DRAM region is disabled */
    SFILIB_BAAW_DRAM_REGION_STATE_ENABLED = 1uL      /* BAAW DRAM region is enabled */
} SfiLib_BaawDramRegionStateType;

/**********************************************************************************************************************
 * Type Definitions
 **********************************************************************************************************************/
/**
 * @brief return type definition of SfiLib API
 */
typedef uint8       SfiLib_ErrorIdType;


/**********************************************************************************************************************
 * Extern Functions
 **********************************************************************************************************************/
/**
 * @fn SfiLib_DramStateType SfiLib_DramGetState(void)
 * @brief This function provides the current DRAM validation status.
 *        The SFI software should use DRAM after ensuring that DRAM is available through this API.
 * @param void
 * @return  The value of SfiLib_DramStateType is returned.
 *           - SFILIB_DRAM_STATE_INVALID is returned when DRAM is not ready to use or invalid.
 *           - SFILIB_DRAM_STATE_VALID is returned when DRAM is ready to use.
 */
extern FUNC(SfiLib_DramStateType, SFILIB_CODE) SfiLib_DramGetState(void);

/**
 * @fn SfiLib_ErrorIdType SfiLib_SfmpuEnableSfascProt(void)
 * @brief This function enables the protection of SFASC SFR using SFMPU_BUSMC.
 *        This function should be called after ensuring that DRAM is available through SfiLib_DramGetState API.
 *        If this function is called when DRAM is not available, SFILIB_E_DRAM_INVALID error code is returned.
 * @param void
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern FUNC(SfiLib_ErrorIdType, SFILIB_CODE) SfiLib_SfmpuEnableSfascProt(void);

/**
 * @fn SfiLib_ErrorIdType  SfiLib_SfmpuDisableSfascProt(void)
 * @brief This function disables the protection of SFASC SFR using SFMPU_BUSMC.
 * @param void
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern FUNC(SfiLib_ErrorIdType, SFILIB_CODE) SfiLib_SfmpuDisableSfascProt(void);

/**
 * @fn SfiLib_SfmpuSfascProtStateType  SfiLib_SfmpuGetSfascProtState(void)
 * @brief This function provides the enabled or disabled state of SFMPU for SFASC SFR protection.
 * @param void
 * @return When SFMPU for SFASC SFR protection is enabled, SFILIB_SFMPU_SFASC_PROTECTION_STATE_ENABLED is returned.
 *         When SFMPU for SFASC SFR protection is disabled, SFILIB_SFMPU_SFASC_PROTECTION_STATE_DISABLED is returned.
 */
extern FUNC(SfiLib_SfmpuSfascProtStateType, SFILIB_CODE) SfiLib_SfmpuGetSfascProtState(void);

/**
 * @fn SfiLib_ErrorIdType SfiLib_BaawEnableDramRegion(
 *          SfiLib_BaawDramRegionIdType DramRegionId, uint32 SysBaseAddr, uint32 Size)
 * @brief This function maps SFI's DRAM region to DRAM's system address and enables the corresponding BAAW window.
 * @param [in] DramRegionId ID of DRAM region
 * @param [in] SysBaseAddr 4K-aligned base address of the DRAM region in systen view
 * @param [in] Size size of the DRAM region
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern FUNC(SfiLib_ErrorIdType, SFILIB_CODE) SfiLib_BaawEnableDramRegion(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId,
    VAR(uint32, AUTOMATIC) SysBaseAddr,
    VAR(uint32, AUTOMATIC) Size);

/**
 * @fn SfiLib_ErrorIdType SfiLib_BaawDisableDramRegion(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function disables the BAAW window for the specified DRAM region.
 * @param [in] DramRegionId ID of DRAM region
 * @return On success, SFILIB_E_OK is returned. On failure, a non-zero error value is returned.
 */
extern FUNC(SfiLib_ErrorIdType, SFILIB_CODE) SfiLib_BaawDisableDramRegion(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn uint32 SfiLib_BaawGetDramSysBaseAddr(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function provides the base address of the specified DRAM region in system view.
 * @param [in] DramRegionId ID of DRAM region
 * @return On success, the system view base address of the specified DRAM regions is returned.
 *         On failure, 0 is returned.
 */
extern FUNC(uint32, SFILIB_CODE) SfiLib_BaawGetDramSysBaseAddr(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn uint32 SfiLib_BaawGetDramSysLimitAddr(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function provides the limit address of the specified DRAM region in system view.
 * @param [in] DramRegionId ID of DRAM region
 * @return On success, the system view limit address of the specified DRAM regions is returned.
 *         On failure, 0 is returned.
 */
extern FUNC(uint32, SFILIB_CODE) SfiLib_BaawGetDramSysLimitAddr(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn uint32 SfiLib_BaawGetDramSfiBaseAddr(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function provides the base address of the specified DRAM region in SFI view.
 * @param [in] DramRegionId ID of DRAM region
 * @return On success, the SFI view base address of the specified DRAM regions is returned.
 *         On failure, 0 is returned.
 */
extern FUNC(uint32, SFILIB_CODE) SfiLib_BaawGetDramSfiBaseAddr(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn uint32 SfiLib_BaawGetDramSfiLimitAddr(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function provides the limit address of the specified DRAM region in SFI view.
 * @param [in] DramRegionId ID of DRAM region
 * @return On success, the SFI view limit address of the specified DRAM regions is returned.
 *         On failure, 0 is returned.
 */
extern FUNC(uint32, SFILIB_CODE) SfiLib_BaawGetDramSfiLimitAddr(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn SfiLib_BaawDramRegionStateType SfiLib_BaawGetDramRegionState(SfiLib_BaawDramRegionIdType DramRegionId)
 * @brief This function provides the enabled or disabled status of the specified DRAM region.
 * @param [in] DramRegionId ID of DRAM region
 * @return When the BAAW window for the DRAM region is enabled, SFILIB_BAAW_DRAM_REGION_STATE_ENABLED is returned.
 *         When the BAAW window for the DRAM region is disabled, SFILIB_BAAW_DRAM_REGION_STATE_DISABLED is returned.
 */
extern FUNC(SfiLib_BaawDramRegionStateType, SFILIB_CODE) SfiLib_BaawGetDramRegionState(
    VAR(SfiLib_BaawDramRegionIdType, AUTOMATIC) DramRegionId);

/**
 * @fn uint32 SfiLib_BaawConvertToDramSysAddr(uint32 SfiAddr)
 * @brief This function provides the converted DRAM system address from SFI's DRAM address.
 * @param [in] SfiAddr SFI's DRAM address to convert
 * @return On success, the converted DRAM system address is returned.
 *         On failure, 0 is returned.
 */
extern FUNC(uint32, SFILIB_CODE) SfiLib_BaawConvertToDramSysAddr(
    VAR(uint32, AUTOMATIC) SfiAddr);

#endif /* SFILIB_H */
