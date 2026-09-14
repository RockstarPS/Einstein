/***************************************************************************
 * \copyright
 *       VISTEON CORPORATION CONFIDENTIAL
 *       ________________________________
 *       [2025] Visteon Corporation
 *       All Rights Reserved.
 *       NOTICE: This is an unpublished work of authorship, which contains trade
 *               secrets. Visteon Corporation owns all rights to this work and
 *               intends to maintain it in confidence to preserve its trade
 *               secret status. Visteon Corporation reserves the right, under
 *               the copyright laws of the United States or those of any other
 *               country that may have jurisdiction, to protect this work as an
 *               unpublished work, in the event of an inadvertent or deliberate
 *               unauthorized publication. Visteon Corporation also reserves
 *               its rights under all copyright laws to protect this work as a
 *               published work, when appropriate. Those having access to this
 *               work may not copy it, use it, modify it, or disclose the
 *               information contained in it without the written authorization
 *               of Visteon Corporation.
 *
 * \file vHsmMPU.h
 *
 * \brief
 * HSM MPU settings for AM62PX HSM M4F core source file
 *
 * \version 1.00.00
 * |Version | Date       | Author   | Task Id | Description                           |
 * |--------|------------|----------|---------|---------------------------------------|
 * |1.00.00 |            | kjohn    | xxxxxx  | Initial version                       |
 * \authors
 *          Name                     | CDSID     | Location
 *          ------------------------ | --------- | --------
 *          Akshay Krishna Upendran  | akrish10  | VTSC, Chennai, India
 *          Banumathi Jayaraman      | bjayara2  | VTSC, Chennai, India
 *          krithik B John           | kjohn     | VTSC, Bengaluru, India
 *          Shanmugam Karthik        | kshanmu4  | VTSC, Chennai, India
 ******************************************************************************/
#ifndef VHSMMPU_H
#define VHSMMPU_H
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "Std_Types.h"
#include "config.h"

#ifdef VHSMMPU_ENABLE

#define dsb()           __asm (" dsb")
#define isb()           __asm (" isb")


/**
 * \brief Enum's to represent different types of access permissions that are possible for a given MPU region
 */
typedef enum
{
    MPU_AP_ALL_BLOCK = (0x0u), /**< All accesses are blocked */
    MPU_AP_S_RW      = (0x1u), /**< Only RD+WR supervisor mode accesses are allowed  */
    MPU_AP_S_RW_U_R  = (0x2u), /**< RD+WR supervisor and RD only user mode accesses are allowed  */
    MPU_AP_ALL_RW    = (0x3u), /**< All RD+WR accesses are allowed */
    MPU_AP_S_R       = (0x5u), /**< Only RD supervisor mode accesses are allowed */
    MPU_AP_ALL_R     = (0x6u)  /**< All RD accesses are allowed */
} vHsmMPU_AccessPerm;

/**
 * \brief Enum's to represent different possible MPU region size
 */
typedef enum
{
    MPU_RegionSize_32 = 0x4,
    MPU_RegionSize_64,
    MPU_RegionSize_128,
    MPU_RegionSize_256,
    MPU_RegionSize_512,
    MPU_RegionSize_1K,
    MPU_RegionSize_2K,
    MPU_RegionSize_4K,
    MPU_RegionSize_8K,
    MPU_RegionSize_16K,
    MPU_RegionSize_32K,
    MPU_RegionSize_64K,
    MPU_RegionSize_128K,
    MPU_RegionSize_256K,
    MPU_RegionSize_512K,
    MPU_RegionSize_1M,
    MPU_RegionSize_2M,
    MPU_RegionSize_4M,
    MPU_RegionSize_8M,
    MPU_RegionSize_16M,
    MPU_RegionSize_32M,
    MPU_RegionSize_64M,
    MPU_RegionSize_128M,
    MPU_RegionSize_256M,
    MPU_RegionSize_512M,
    MPU_RegionSize_1G,
    MPU_RegionSize_2G,
    MPU_RegionSize_4G
} vHsmMPU_RegionSize;

/**
 * \brief Attribute's to apply for a MPU region
 *
 * \note Refer to ARMv7-R or ARMv7-M architecture manual for more details
 *
 * \note C, B, S, TEX[0:2] bits
 *   together control if a region should be fully cached or non-cached or marked as device memory
 */
typedef struct
{

    uint8 isEnable; /**< 1: enable this region, 0: disable this region */
    uint8 isCacheable; /**< 1: set C bit, 0: clear C bit */
    uint8 isBufferable; /**< 1: set B bit, 0: clear B bit */
    uint8 isSharable; /**< 1: set S bit, 0: clear S bit */
    uint8 isExecuteNever; /**< 1: set XN bit, 0: clear XN bit */
    uint8 tex; /**< set TEX[0:2] bits */
    uint8 accessPerm; /**< set AP[0:2] bits, see \ref vHsmMPU_AccessPerm */
    uint8 subregionDisableMask; /**< subregion disable mask, bitN = 1 means disable that subregion */
} vHsmMPU_RegionAttrs;

/**
 * \brief Region config structure, this used by SysConfig and not to be used by end-users directly
 */
typedef struct 
{
    uint32 baseAddr;  /**< region start address, MUST aligned to region size */
    uint32 size; /**< region size, see \ref MPU_RegionSize */
    vHsmMPU_RegionAttrs attrs; /** region attributes, see \ref MPU_RegionAttrs */

} vHsmMPU_RegionConfig;

/**
 * \brief MPU config structure, this used by SysConfig and not to be used by end-users directly
 */
typedef struct vHsmMPU_Config_ {

    uint32 numRegions;             /** Number of regions to configure */
    uint32 enableBackgroundRegion; /**< 0: disable backgroun region, 1: enable background region */
    uint32 enableMpu;              /**< 0: keep MPU disabled, 1: enable MPU */

} vHsmMPU_Config;

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_RegionAttrs_init
 **
 ** \brief     Set default values to MPU_RegionAttrs
 **
 ** \param[out] region parameter structure to set to default
 **
 ** \return    void
 **
 ** \note Strongly recommended to be called before seting values in MPU_RegionAttrs
 **
 *********************************************************************************************
 */
void vHsmMPU_RegionAttrs_init(vHsmMPU_RegionAttrs *region);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_setRegion
 **
 ** \brief     Setup a region in the MPU
 **
 ** \param[in] regionNum region to setup
 ** \param[in] addr region start address, MUST aligned to region size
 ** \param[in] size region size, see \ref MPU_RegionSize
 ** \param[in] attrs region attrs, see \ref MPU_RegionAttrs
 **
 ** \return    void
 **
 ** \note Recommended to disable MPU and disable cache before setting up MPU regions
 **
 *********************************************************************************************
 */
void vHsmMPU_setRegion(uint32 regionNum, void * addr, uint32 size, vHsmMPU_RegionAttrs *attrs);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_resetRegion
 **
 ** \brief     Reset a region in the MPU
 **
 ** \param regionNum [in] region to reset
 **
 ** \return    void
 **
 ** \note Refer to ARMv7-R or ARMv7-M architecture manual for more details
 **
 *********************************************************************************************
 */
void vHsmMPU_resetRegion(uint32 regionNum);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_enable
 **
 ** \brief     Enable MPU sub-system using the region that are setup using \ref vHsmMPU_setRegion
 **
 ** \param[in] void
 **
 ** \return    void
 **
 *********************************************************************************************
 */
void vHsmMPU_enable(void);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_disable
 **
 ** \brief     Disbale MPU sub-sytem
 **
 ** \param[in] void
 **
 ** \return    void
 **
 *********************************************************************************************
 */
void vHsmMPU_disable(void);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_isEnable
 **
 ** \brief     Check if MPU sub-system is enabled
 **
 ** \param[in] void
 **
 ** \return    0: MPU sub-system is disabled, 1: MPU sub-system is enabled
 **
 ** \note      This function is mandatory MPU.
 **
 *********************************************************************************************
 */
uint32 vHsmMPU_isEnable(void);

/**
 *********************************************************************************************
 ** \fn        vHsmMPU_init
 **
 ** \brief     Initialize MPU sub-system
 **
 ** \param[in] void
 **
 ** \return    void
 **
 ** \note      This function is mandatory MPU.
 **
 *********************************************************************************************
 */
void vHsmMPU_init(void);


#endif
#endif /*VHSMMPU_H*/
